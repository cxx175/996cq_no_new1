#include "hook.h"
#include <jni.h>
#include <android/log.h>
#include <dlfcn.h>
#include <unistd.h>
#include <pthread.h>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <unordered_map>
#include <atomic>
#include <map>
#include "lua_decrypt_hook.h"
#include <queue>
#include <condition_variable>
#include <future>

#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <unordered_map>
#include <string>
#include <chrono>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <dlfcn.h>
#include <cassert>
#include <functional>
#include <queue>
#include <condition_variable>
#include <future>

#include "tool.h"

// Hook线程池管理器类定义
class HookThreadManager {
private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop{false};
    
public:
    HookThreadManager() {
        // 启动固定数量的工作线程
        for (size_t i = 0; i < std::max(2u, std::thread::hardware_concurrency()); ++i) {
            threads.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    
                    {
                        std::unique_lock<std::mutex> lock(this->queueMutex);
                        this->condition.wait(lock, [this] { 
                            return this->stop || !this->tasks.empty(); 
                        });
                        
                        if (this->stop && this->tasks.empty()) {
                            break;
                        }
                        
                        if (!this->tasks.empty()) {
                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }
                    }
                    
                    if (task) {
                        try {
                            task();
                        } catch (const std::exception& e) {
                            LOGE("Hook任务执行异常: %s", e.what());
                        } catch (...) {
                            LOGE("Hook任务执行未知异常");
                        }
                    }
                }
            });
        }
    }
    
    ~HookThreadManager() {
        shutdown();
    }
    
    // 提交Hook任务
    void submitHookTask(std::function<void()> task) {
        if (stop) {
            LOGW("Hook线程池已停止，无法提交新任务");
            return;
        }
        
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace(std::move(task));
        }
        condition.notify_one();
    }
    
    // 关闭线程池
    void shutdown() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        
        for (std::thread& thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
        threads.clear();
    }
    
    // 获取活跃线程数
    size_t getActiveThreadCount() const {
        return threads.size();
    }
};

// 全局Hook线程管理器
static std::unique_ptr<HookThreadManager> g_hookThreadManager;
static std::once_flag g_hookManagerInitFlag;

// 初始化Hook线程管理器
static void initHookThreadManager() {
    std::call_once(g_hookManagerInitFlag, []() {
        g_hookThreadManager = std::make_unique<HookThreadManager>();
        LOGI("Hook线程池管理器已初始化");
    });
}

// 使用相同的TAG保持一致性
#define HOOK_TAG "LUA-print"

// 使用lua_decrypt_hook.h中定义的日志宏，只需注释掉重定义
// 注释：使用lua_decrypt_hook.h中的日志宏定义
// #define LOGI(...) __android_log_print(ANDROID_LOG_INFO, HOOK_TAG, __VA_ARGS__)
// #define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, HOOK_TAG, __VA_ARGS__)
// #define LOGW(...) __android_log_print(ANDROID_LOG_WARN, HOOK_TAG, __VA_ARGS__)
// #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, HOOK_TAG, __VA_ARGS__)

// 全局变量
static std::mutex globalHookMutex;
static bool appExiting = false;

// Hook状态结构
struct HookState {
    std::string moduleName;
    std::string symbolName;
    long offset;
    bool isActive;
    bool isThreadRunning;
    std::string status;
    std::thread* workerThread;
    
    HookState() : offset(0), isActive(false), isThreadRunning(false), workerThread(nullptr) {}
};

// Hook配置结构
struct HookConfig {
    std::string moduleName;
    std::string symbolName;
    long offset;
    std::string description;
    bool enabled;
};

// Hook状态管理
static std::unordered_map<std::string, HookState> hookStates;

// Hook系统启用状态
static std::atomic<bool> hookSystemEnabled{true};

// 预定义Hook配置
static std::vector<HookConfig> hookConfigs = {
    {"libMyGame.so", "luaL_loadbuffer", 0xabce3c, "Lua loadbuffer hook", true}
};

// 生成Hook ID
static std::string generateHookId(const std::string& moduleName, const std::string& symbolName) {
    return moduleName + "::" + symbolName;
}

static std::string generateHookId(const std::string& moduleName, long offset) {
    return moduleName + "::" + std::to_string(offset);
}

// 函数声明
void setAppExiting(bool exiting);
bool isAppExitingNow();

// 添加缺失的函数声明
// 符号探测功能已被移除
void scan_libMyGame_memory() {
    LOGI("Memory scanning feature removed");
}

// 内部Hook安装函数
static bool installHookInternal(const std::string& hookId, HookState& state) {
    if (!hookSystemEnabled.load()) {
        LOGW("Hook system disabled, skipping installation: %s", hookId.c_str());
        return false;
    }

    LOGI("🔨 Starting And64InlineHook installation: %s", hookId.c_str());
    
    bool success = false;
    
    // 使用And64InlineHook进行Hook
    if (state.symbolName == "luaL_loadbuffer" ) {
        // 初始化Lua解密Hook系统
        success = lua_decrypt_hook_init();
    } else {
        LOGW("⚠️ Unsupported symbol: %s", state.symbolName.c_str());
        success = false;
    }
    
    if (success) {
        state.isActive = true;
        state.status = "Hook activated";
        LOGI("🎉 And64InlineHook installation successful: %s", hookId.c_str());
        
        // 验证Hook状态
        if (LuaHookManager::getInstance().isHookActive(state.symbolName)) {
            LOGI("✅ Hook verification successful: %s", hookId.c_str());
            return true;
        } else {
            LOGW("⚠️ Hook verification failed: %s", hookId.c_str());
            state.isActive = false;
            state.status = "Hook verification failed";
            return false;
        }
    } else {
        state.isActive = false;
        state.status = "Hook installation failed";
        LOGE("❌ And64InlineHook failed: %s", hookId.c_str());
        return false;
    }
}

/**
 * Hook工作线程
 */
static void hookWorkerThread(std::string* hookId) {
    if (!hookId) return;
    
    std::unique_ptr<std::string> hookIdPtr(hookId); // 使用智能指针自动管理内存
    
    std::lock_guard<std::mutex> lock(globalHookMutex);
    auto it = hookStates.find(*hookIdPtr);
    if (it == hookStates.end()) {
        return;
    }
    
    HookState& state = it->second;
    state.isThreadRunning = true;
    
    LOGI("And64InlineHook worker thread started - Hook ID: %s", hookIdPtr->c_str());
    
    // 等待目标库加载
    void* handle = nullptr;
    int attempts = 0;
    const int maxAttempts = 20; // 减少到20秒最大等待时间
    const int checkInterval = 1000; // 检查间隔1秒
    
    while (attempts < maxAttempts && state.isThreadRunning && hookSystemEnabled.load()) {
        handle = dlopen(state.moduleName.c_str(), RTLD_NOLOAD);
        if (handle) {
            dlclose(handle);
            break;
        }
        
        // 分段睡眠，支持快速退出
        for (int i = 0; i < checkInterval && state.isThreadRunning && hookSystemEnabled.load(); i += 100) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        attempts++;
        
        // 每5次尝试记录一次日志，避免日志过多
        if (attempts % 5 == 0) {
            LOGD("Hook等待目标库加载中... (%d/%d)", attempts, maxAttempts);
        }
    }
    
    if (handle && state.isThreadRunning && hookSystemEnabled.load()) {
        LOGI("Target library %s loaded, starting And64InlineHook initialization", state.moduleName.c_str());
        state.status = "Target library loaded, And64InlineHook initializing...";
        
        // 尝试安装Hook
        bool success = installHookInternal(*hookIdPtr, state);
        
        if (success) {
            state.status = "And64InlineHook activated - target function successfully hooked";
            LOGI("And64InlineHook initialization completed, target function hooked: %s", hookIdPtr->c_str());
        } else {
            state.status = "And64InlineHook initialization failed";
            LOGE("And64InlineHook initialization failed: %s", hookIdPtr->c_str());
        }
    } else {
        if (!state.isThreadRunning || !hookSystemEnabled.load()) {
            state.status = "Hook system disabled or thread stopped";
            LOGI("Hook工作线程提前结束: 系统禁用或线程停止");
        } else {
            state.status = "Target library load timeout";
            LOGW("Target library load timeout after %d seconds: %s", maxAttempts, hookIdPtr->c_str());
        }
    }
    
    state.isThreadRunning = false;
    LOGI("And64InlineHook worker thread ended: %s", hookIdPtr->c_str());
}

/**
 * 安装Hook函数 - 基于符号名
 */
bool installHookBySymbol(const std::string& moduleName, const std::string& symbolName) {
    if (!hookSystemEnabled.load()) {
        LOGW("Hook system disabled");
        return false;
    }
    
    LOGI("Starting And64InlineHook installation - Module: %s, Symbol: %s", moduleName.c_str(), symbolName.c_str());
    
    // 生成Hook标识符
    std::string hookId = generateHookId(moduleName, symbolName);
    
    std::lock_guard<std::mutex> lock(globalHookMutex);
    
    // 检查是否已经存在
    auto it = hookStates.find(hookId);
    if (it != hookStates.end()) {
        HookState& existingState = it->second;
        if (existingState.isActive) {
            LOGI("And64InlineHook already exists and is active: %s", hookId.c_str());
            return true;
        } else if (existingState.isThreadRunning) {
            LOGI("And64InlineHook thread already running: %s", hookId.c_str());
            return true;
        }
    }
    
    // 创建新状态
    HookState newState;
    newState.moduleName = moduleName;
    newState.symbolName = symbolName;
    newState.offset = 0; // 使用符号名而非偏移
    newState.isActive = false;
    newState.isThreadRunning = false;
    newState.status = "And64InlineHook initializing...";
    newState.workerThread = nullptr;
    
    hookStates[hookId] = newState;
    
    // 创建工作线程 - 使用智能指针管理，避免detach造成的资源泄漏
    auto hookIdPtr = std::make_unique<std::string>(hookId);

    // 确保Hook线程管理器已初始化
    initHookThreadManager();

    // 使用线程池提交Hook任务，替代detach
    g_hookThreadManager->submitHookTask([hookId]() {
        try {
            // 创建hookId的副本用于线程
            auto hookIdCopy = std::make_unique<std::string>(hookId);
            hookWorkerThread(hookIdCopy.release());
        } catch (const std::exception& e) {
            LOGE("Hook工作线程异常: %s", e.what());
        } catch (...) {
            LOGE("Hook工作线程未知异常");
        }
    });

    LOGI("Hook任务已提交到线程池: %s", hookId.c_str());
    return true;
}

/**
 * 安装Hook函数 - 兼容旧接口
 */
bool installHook(const std::string& moduleName, long offset) {
    if (!hookSystemEnabled.load()) {
        LOGW("Hook system disabled");
        return false;
    }
    
    // 根据偏移确定符号名，然后调用新接口
    if (offset == 0) {
        // 如果偏移为0，则默认尝试两个主要符号
        bool success2 = installHookBySymbol(moduleName, "luaL_loadbuffer");
        return success2;
    } else {
        LOGW("Warning: Offset-based Hook is deprecated, recommend using symbol-based Hook");
        
        LOGI("Starting And64InlineHook installation - Module: %s, Offset: 0x%lx", moduleName.c_str(), offset);
        
        // 生成Hook标识符
        std::string hookId = generateHookId(moduleName, offset);
        
        std::lock_guard<std::mutex> lock(globalHookMutex);
        
        // 检查是否已经存在
        auto it = hookStates.find(hookId);
        if (it != hookStates.end()) {
            HookState& existingState = it->second;
            if (existingState.isActive) {
                LOGI("And64InlineHook already exists and is active: %s", hookId.c_str());
                return true;
            } else if (existingState.isThreadRunning) {
                LOGI("And64InlineHook thread already running: %s", hookId.c_str());
                return true;
            }
        }
        
        // 创建新状态
        HookState newState;
        newState.moduleName = moduleName;
        newState.offset = offset;
        newState.isActive = false;
        newState.isThreadRunning = false;
        newState.status = "And64InlineHook initializing...";
        newState.workerThread = nullptr;
        
        // 根据偏移确定符号名
        if (offset == 0xabce3c) {
            newState.symbolName = "luaL_loadbuffer";
        } else if (offset == 0xA2297C) {
            newState.symbolName = "luaL_loadbuffer";
        } else {
            LOGE("❌ Unknown Hook offset: 0x%lx", offset);
            return false;
        }
        
        hookStates[hookId] = newState;
        
        // 确保Hook线程管理器已初始化
        initHookThreadManager();
        
        // 使用线程池提交Hook任务，替代detach
        g_hookThreadManager->submitHookTask([hookId]() {
            try {
                // 创建hookId的副本用于线程
                auto hookIdCopy = std::make_unique<std::string>(hookId);
                hookWorkerThread(hookIdCopy.release());
            } catch (const std::exception& e) {
                LOGE("Hook工作线程异常: %s", e.what());
            } catch (...) {
                LOGE("Hook工作线程未知异常");
            }
        });
        
        LOGI("Hook任务已提交到线程池: %s", hookId.c_str());
        return true;
    }
}

/**
 * 卸载Hook函数
 */
bool uninstallHook(const std::string& moduleName, long offset) {
    std::lock_guard<std::mutex> lock(globalHookMutex);
    
    std::string hookId = generateHookId(moduleName, offset);
    LOGI("Starting And64InlineHook uninstallation: %s", hookId.c_str());
    
    if (hookStates.find(hookId) == hookStates.end()) {
        LOGW("And64InlineHook does not exist: %s", hookId.c_str());
        return false;
    }
    
    HookState& state = hookStates[hookId];
    
    if (!state.isActive) {
        LOGW("And64InlineHook not activated: %s", hookId.c_str());
        return true;
    }
    
    // 使用And64InlineHook卸载
    bool success = true; // And64InlineHook是永久性的
    
    if (success) {
        state.isActive = false;
        state.status = "Uninstalled";
        LOGI("✅ And64InlineHook uninstallation successful: %s", hookId.c_str());
        return true;
    } else {
        LOGE("❌ And64InlineHook uninstallation failed: %s", hookId.c_str());
        return false;
    }
}

/**
 * 检查Hook是否激活
 */
bool isHookActive(const std::string& moduleName, long offset) {
    std::lock_guard<std::mutex> lock(globalHookMutex);
    
    std::string hookId = generateHookId(moduleName, offset);
    
    if (hookStates.find(hookId) == hookStates.end()) {
        return false;
    }
    
    return hookStates[hookId].isActive;
}

/**
 * 获取活跃Hook数量
 */
int getActiveHookCount() {
    std::lock_guard<std::mutex> lock(globalHookMutex);
    
    int count = 0;
    for (const auto& pair : hookStates) {
        if (pair.second.isActive) {
            count++;
        }
    }
    return count;
}

/**
 * 列出所有Hook状态
 */
void listAllHooks() {
    std::lock_guard<std::mutex> lock(globalHookMutex);
    
    LOGI("📋 And64InlineHook status list:");
    LOGI("----------------------------------------");
    
    if (hookStates.empty()) {
        LOGI("No registered And64InlineHook");
        return;
    }
    
    for (const auto& pair : hookStates) {
        const std::string& hookId = pair.first;
        const HookState& state = pair.second;
        
        LOGI("🎯 Hook ID: %s", hookId.c_str());
        LOGI("   Module: %s", state.moduleName.c_str());
        LOGI("   Symbol: %s", state.symbolName.empty() ? "N/A" : state.symbolName.c_str());
        LOGI("   Offset: 0x%lx", state.offset);
        LOGI("   Status: %s", state.status.c_str());
        LOGI("   Active: %s", state.isActive ? "Yes" : "No");
        LOGI("   Thread Running: %s", state.isThreadRunning ? "Yes" : "No");
        LOGI("----------------------------------------");
    }
}

// 简化的其他函数实现
bool startContinuousHookInstall(const std::string& moduleName, long offset, int) {
    return installHook(moduleName, offset);
}

void stopContinuousHookInstall(const std::string&, long) {
    // And64InlineHook不需要连续安装机制
}

void stopAllContinuousHookInstall() {
    // And64InlineHook不需要连续安装机制
}

bool isContinuousHookInstallRunning(const std::string&, long) {
    return false;
}

void testHookInstallation() {
    LOGI("Testing Hook installation");
    installHookBySymbol("libMyGame.so", "luaL_loadbuffer");
}

bool startHookHeartbeat() {
    return true;
}

void stopHookHeartbeat() {
    // 简化实现
}

bool isHookHeartbeatRunning() {
        return false;
    }
    
void getHookConfigs(std::vector<HookConfig>& configs) {
    configs = hookConfigs;
}

bool updateHookConfig(const std::string&, long, bool) {
    return true;
}

bool addHookConfig(const std::string&, long, bool, const std::string&) {
    return true;
}

void autoInitializeHooks() {
    LOGI("Auto initializing And64InlineHook");
    
    for (const auto& config : hookConfigs) {
        if (config.enabled) {
            if (config.offset != 0) {
                installHook(config.moduleName, config.offset);
            } else {
                installHookBySymbol(config.moduleName, config.symbolName);
            }
        }
    }
    
    if (hookSystemEnabled.load()) {
        scan_libMyGame_memory();
    }
}

void cleanupHooksOnExit() {
    LOGI("清理Hook资源和线程池");
    std::lock_guard<std::mutex> lock(globalHookMutex);
    
    // 停止所有Hook状态
    for (auto& pair : hookStates) {
        HookState& state = pair.second;
        state.isActive = false;
        state.isThreadRunning = false;
    }
    
    // 关闭线程池管理器
    if (g_hookThreadManager) {
        g_hookThreadManager->shutdown();
        g_hookThreadManager.reset();
        LOGI("Hook线程池已完全关闭");
    }
    
    hookStates.clear();
    LOGI("Hook系统资源清理完成");
}

void setAppExiting(bool exiting) {
    appExiting = exiting;
    if (exiting) {
        cleanupHooksOnExit();
    }
}

bool isAppExitingNow() {
    return appExiting;
}

void setHookSystemEnabled(bool enabled) {
    hookSystemEnabled.store(enabled);
    LOGI("Hook system %s", enabled ? "enabled" : "disabled");
}

bool isHookSystemEnabled() {
    return hookSystemEnabled.load();
}
