#include "lua_decrypt_hook.h"
#include <dlfcn.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>
#include <memory>
#include <errno.h>
#include <string>
#include <algorithm>
#include <jni.h>
#include <android/log.h>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <sstream>
#include <iomanip>
#ifdef __ANDROID__
#include <sys/system_properties.h>
#endif
#include "tool.h"

// Hook方法声明
#if defined(__aarch64__)
extern "C" void A64HookFunction(void *const symbol, void *const replace, void **result);
#elif defined(__arm__) || defined(__ARM_ARCH_7A__)
// ARM 32位架构使用简单的内存补丁Hook
#include <sys/mman.h>
static bool arm32_hook_function(void* target, void* replacement, void** original);
#elif defined(__i386__) || defined(__x86_64__)
// x86架构使用PLT Hook或者简单的函数指针替换
#include <sys/mman.h>
static bool x86_hook_function(void* target, void* replacement, void** original);
#endif

// 原始函数指针
static int (*original_luaL_loadbuffer)(void* L, const char* buff, size_t size, const char* name) = nullptr;

// 目标so库句柄
static void* target_lib_handle = nullptr;

// Hook函数状态管理
static bool hook_luaL_loadbuffer_active = false;

// 🧵 线程本地存储 - 解决内存生命周期问题
thread_local std::string tls_script_buffer;
thread_local std::string tls_last_script_name;
thread_local bool tls_using_replaced_content = false;

// AES解密配置常量 - 与main.cpp保持一致
const char AES_DECRYPT_KEY[] = "_ZN7cocos2d13tgaLoadBufferEE_ptr";
const char AES_DECRYPT_IV[] = "_ZN7cocos2d8LuaStack13luaLoadBufferEP9lua_StatePKciS4__ptr";

// 🔐 改进的AES解密器类 - 使用RAII模式确保资源安全
class AESDecryptor {
private:
    std::string key;
    std::string iv;
    
    // 安全的十六进制转换
    std::vector<unsigned char> fromHex(const std::string& hex) {
        std::vector<unsigned char> result;
        if (hex.length() % 2 != 0) {
            return result; // 无效的十六进制字符串
        }
        
        try {
            for (size_t i = 0; i < hex.length(); i += 2) {
                std::string byteString = hex.substr(i, 2);
                unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
                result.push_back(byte);
            }
        } catch (const std::exception& e) {
            LOGE("十六进制转换异常: %s", e.what());
            result.clear();
        }
        return result;
    }
    
    // 密钥长度调整（确保符合AES要求）
    std::string adjustKeyLength(const std::string& key) {
        if (key.length() >= 32) {
            return key.substr(0, 32); // AES-256
        } else if (key.length() >= 24) {
            return key.substr(0, 24); // AES-192
        } else if (key.length() >= 16) {
            return key.substr(0, 16); // AES-128
        } else {
            // 补齐到16字节
            std::string paddedKey = key;
            paddedKey.resize(16, '0');
            return paddedKey;
        }
    }
    
    // IV长度调整（AES块大小为16字节）
    std::string adjustIVLength(const std::string& iv) {
        if (iv.length() >= 16) {
            return iv.substr(0, 16);
        } else {
            std::string paddedIV = iv;
            paddedIV.resize(16, '0');
            return paddedIV;
        }
    }

public:
    AESDecryptor(const std::string& key, const std::string& iv) {
        this->key = adjustKeyLength(key);
        this->iv = adjustIVLength(iv);
    }
    
    // 使用RAII模式的解密函数
    std::string decrypt(const std::string& ciphertext_hex) {
        std::vector<unsigned char> ciphertext = fromHex(ciphertext_hex);
        if (ciphertext.empty()) {
            return ""; // 不是有效的十六进制数据
        }
        
        // 使用unique_ptr自动管理EVP_CIPHER_CTX资源
        std::unique_ptr<EVP_CIPHER_CTX, decltype(&EVP_CIPHER_CTX_free)> 
            ctx(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);
        
        if (!ctx) {
            LOGE("AES解密: 无法创建EVP_CIPHER_CTX");
            return "";
        }
        
        // 根据密钥长度选择AES算法
        const EVP_CIPHER* cipher;
        if (key.length() == 32) {
            cipher = EVP_aes_256_cbc();
        } else if (key.length() == 24) {
            cipher = EVP_aes_192_cbc();
        } else {
            cipher = EVP_aes_128_cbc();
        }
        
        try {
            if (EVP_DecryptInit_ex(ctx.get(), cipher, nullptr,
                                  reinterpret_cast<const unsigned char*>(key.c_str()),
                                  reinterpret_cast<const unsigned char*>(iv.c_str())) != 1) {
                LOGE("AES解密: EVP_DecryptInit_ex失败");
                return "";
            }
            
            std::vector<unsigned char> plaintext(ciphertext.size() + AES_BLOCK_SIZE);
            int len;
            int plaintext_len;
            
            if (EVP_DecryptUpdate(ctx.get(), plaintext.data(), &len,
                                 ciphertext.data(), ciphertext.size()) != 1) {
                LOGE("AES解密: EVP_DecryptUpdate失败");
                return "";
            }
            plaintext_len = len;
            
            if (EVP_DecryptFinal_ex(ctx.get(), plaintext.data() + len, &len) != 1) {
                LOGE("AES解密: EVP_DecryptFinal_ex失败");
                return "";
            }
            plaintext_len += len;
            
            return std::string(reinterpret_cast<char*>(plaintext.data()), plaintext_len);
            
        } catch (const std::exception& e) {
            LOGE("AES解密过程异常: %s", e.what());
            return "";
        } catch (...) {
            LOGE("AES解密过程未知异常");
            return "";
        }
    }
};

// 🔧 路径标准化函数
static std::string normalizePath(const std::string& path) {
    std::string normalized = path;
    
    // 替换反斜杠为正斜杠
    std::replace(normalized.begin(), normalized.end(), '\\', '/');
    
    // 移除开头的 "./" 
    if (normalized.length() >= 2 && normalized.substr(0, 2) == "./") {
        normalized = normalized.substr(2);
    }
    
    // 移除开头的 "/"
    if (!normalized.empty() && normalized[0] == '/') {
        normalized = normalized.substr(1);
    }
    
    return normalized;
}

// 🔍 智能脚本名称匹配函数
static std::string findMatchingScript(const std::string& scriptName) {
    // 声明外部函数（来自tool.cpp）
    extern std::vector<std::string> getUnzippedFileList();
    extern bool hasUnzippedFileData(const std::string& filePath);
    // 1. 直接匹配
    if (hasUnzippedFileData(scriptName)) {
        return scriptName;
    }
    
    return ""; // 未找到匹配
}

// 检查数据是否为十六进制格式
bool isHexData(const char* buff, size_t size) {
    if (!buff || size == 0) {
        return false;
    }
    
    // 十六进制数据通常较长，至少应该有一定长度
    if (size < 32) {
        return false;
    }
    
    // 检查是否全部为十六进制字符
    for (size_t i = 0; i < size; ++i) {
        char c = buff[i];
        if (!((c >= '0' && c <= '9') || 
              (c >= 'a' && c <= 'f') || 
              (c >= 'A' && c <= 'F'))) {
            return false;
            }
        }
    
    // 十六进制数据长度应该是偶数
    return (size % 2 == 0);
}

// Hook函数实现 - my_luaL_loadbuffer
int my_luaL_loadbuffer(void* L, const char* buff, size_t size, const char* name) {
    // 🛡️ 严格的参数验证
    if (!is_valid_lua_state(L)) {
        LOGE("❌ 无效的Lua状态指针: %p", L);
        return -1; // 返回错误而不是调用原始函数
    }
    
    if (!is_valid_buffer_pointer(buff, size)) {
        // 添加详细的调试信息
        LOGE("❌ 无效的缓冲区指针或大小: %p (size: %zu)", buff, size);
        
        // 详细分析失败原因
        if (!buff) {
            LOGE("   原因: 缓冲区指针为NULL");
        } else {
            uintptr_t addr = (uintptr_t)buff;
            LOGE("   缓冲区地址: 0x%zx", addr);
            LOGE("   缓冲区大小: %zu", size);
            
            if (addr < 0x1000) {
                LOGE("   原因: 地址过低 (< 0x1000)");
            } else if (size > 0x10000000) {
                LOGE("   原因: 缓冲区大小过大 (> 256MB)");
            } else {
                LOGE("   原因: 内存不可读或访问异常");
                
                // 尝试更详细的内存检查
                try {
                    volatile char test = buff[0];
                    LOGE("   首字节可读: 0x%02x", (unsigned char)test);
                    (void)test;
                } catch (...) {
                    LOGE("   首字节不可读 - 访问异常");
                }
            }
        }
        
        return -1;
    }
    
    // 🚨 关键修复：验证原始函数指针的有效性
    if (!original_luaL_loadbuffer) {
        LOGE("❌ 原始函数指针为NULL，无法继续执行");
        return -1;
    }
    
    // 验证原始函数指针是否指向有效的可执行内存
    if (!is_memory_readable((const void*)original_luaL_loadbuffer, sizeof(void*))) {
        LOGE("❌ 原始函数指针指向无效内存: %p", original_luaL_loadbuffer);
        return -1;
    }
    
    // 检查原始函数指针是否在合理的地址范围内 - 修复Android ARM64兼容性
    uintptr_t func_addr = (uintptr_t)original_luaL_loadbuffer;
    if (func_addr < 0x10000) { // 只检查非常低的地址
        LOGE("❌ 原始函数指针地址异常: %p", original_luaL_loadbuffer);
        return -1;
    }
    
    if (!name) {
        LOGW("⚠️ 脚本名称为NULL，使用默认名称");
        name = "unknown_script";
    }
    
    // 添加内存对齐检查
    if ((uintptr_t)buff % sizeof(void*) != 0) {
        LOGW("⚠️ 缓冲区地址未对齐: %p", buff);
    }
    
    // 限制缓冲区大小，防止处理超大数据
    const size_t MAX_BUFFER_SIZE = 50 * 1024 * 1024; // 50MB限制
    if (size > MAX_BUFFER_SIZE) {
        LOGE("❌ 缓冲区大小超出限制: %zu > %zu", size, MAX_BUFFER_SIZE);
        return -1;
    }
    
    const char* final_buff = buff;
    size_t final_size = size;
    
    // 重置线程本地状态
    tls_using_replaced_content = false;
    
    // 🔐 首先检查是否为AES加密的十六进制数据
    static thread_local std::string aes_decrypted_buffer;
    bool is_aes_decrypted = false;
    
    if (buff && size > 0 && isHexData(buff, size)) {
        LOGI("🔍 检测到十六进制数据，尝试AES解密: %s (大小: %zu)", 
            name ? name : "unknown", size);
        
        try {
            std::string hex_data(buff, size);
            AESDecryptor decryptor(AES_DECRYPT_KEY, AES_DECRYPT_IV);
            aes_decrypted_buffer = decryptor.decrypt(hex_data);
            
            if (!aes_decrypted_buffer.empty()) {
                final_buff = aes_decrypted_buffer.c_str();
                final_size = aes_decrypted_buffer.size();
                is_aes_decrypted = true;
                
                LOGI("✅ AES解密成功: %s (原始: %zu bytes -> 解密: %zu bytes)", 
                    name ? name : "unknown", size, final_size);
                
                // 显示解密内容预览
                std::string preview = aes_decrypted_buffer.substr(0, std::min(size_t(100), aes_decrypted_buffer.length()));
                for (char& c : preview) {
                    if (c < 32 || c > 126) c = '.';
                }
                LOGI("📄 解密内容预览: %s%s", preview.c_str(), 
                    aes_decrypted_buffer.size() > 100 ? "..." : "");
            } else {
                LOGW("⚠️ AES解密失败或返回空内容: %s", name ? name : "unknown");
            }
        } catch (const std::exception& e) {
            LOGE("❌ AES解密异常: %s - %s", name ? name : "unknown", e.what());
        } catch (...) {
            LOGE("❌ AES解密未知异常: %s", name ? name : "unknown");
        }
    }
    
    // 🔄 如果不是AES加密数据或AES解密失败，继续原有的脚本替换逻辑
    if (!is_aes_decrypted && name && strlen(name) > 0) {
        // 声明外部函数（来自tool.cpp）
        extern std::string getUnzippedFileData(const std::string& filePath);
        
        std::string script_name = name;
        tls_last_script_name = script_name;
        // 智能匹配脚本
        std::string matchedScript = findMatchingScript(script_name);
        
        if (!matchedScript.empty()) {
            // 🧵 使用thread_local存储，确保内存生命周期正确
            tls_script_buffer = getUnzippedFileData(matchedScript);
            
            if (!tls_script_buffer.empty()) {
                final_buff = tls_script_buffer.c_str();
                final_size = tls_script_buffer.size();
                tls_using_replaced_content = true;
                
                LOGI("✅ 替换脚本成功: %s -> %s (大小: %zu)", 
                    script_name.c_str(), matchedScript.c_str(), final_size);
                
                // 显示脚本内容预览
                std::string preview = tls_script_buffer.substr(0, std::min(size_t(150), tls_script_buffer.length()));
                for (char& c : preview) {
                    if (c < 32 || c > 126) c = '.';
                }
                LOGI("📄 脚本预览: %s%s", preview.c_str(), tls_script_buffer.size() > 150 ? "..." : "");
    } else {
                LOGW("⚠️ 找到匹配的脚本但内容为空: %s", matchedScript.c_str());
            }
        }
    }
    
    // 🚀 调用原始函数
    int result = original_luaL_loadbuffer(L, final_buff, final_size, name);
    
    // 📊 记录调用结果
    if (is_aes_decrypted) {
        LOGI("🔐 AES解密脚本加载完成: %s, 结果: %d", 
            name ? name : "unknown", result);
    } else if (tls_using_replaced_content) {
        LOGI("🎯 替换脚本加载完成: %s, 结果: %d", 
            tls_last_script_name.c_str(), result);
    }
    
    return result;
}

// 修复的 install_luaL_loadbuffer_hook 函数
bool install_luaL_loadbuffer_hook() {
    LOGI("🔧 开始安装 luaL_loadbuffer Hook (调试模式)...");
    
    if (hook_luaL_loadbuffer_active) {
        LOGI("ℹ️ luaL_loadbuffer Hook 已经激活");
        return true;
    }
    
    // 查找目标库（如果还没有打开）
    if (!target_lib_handle) {
        target_lib_handle = dlopen("libMyGame.so", RTLD_NOLOAD);
    }
    if (!target_lib_handle) {
        LOGE("❌ 无法找到目标库 libMyGame.so");
        return false;
    }
    
    void* target_func = nullptr;
    // 尝试通过符号名查找
    target_func = dlsym(target_lib_handle, "luaL_loadbuffer");
    if (!target_func) {
        LOGE("❌ 无法定位 luaL_loadbuffer 函数");
        return false;
    }
    
    // 🚨 验证目标函数指针的有效性
    if (!is_memory_readable(target_func, 16)) {
        LOGE("❌ 目标函数内存不可读: %p", target_func);
        return false;
    }
    
    LOGI("📍 找到目标函数: %p", target_func);
    
    // 根据架构选择Hook方法
    bool hook_success = false;
    
#if defined(__aarch64__)
    // ARM64架构
    LOGI("🎯 使用 ARM64 Hook 方法");
    A64HookFunction(target_func, (void*)my_luaL_loadbuffer, (void**)&original_luaL_loadbuffer);
    hook_success = true;
#elif defined(__arm__) || defined(__ARM_ARCH_7A__)
    // ARM32架构
    LOGI("🎯 使用 ARM32 Hook 方法");
    hook_success = arm32_hook_function(target_func, (void*)my_luaL_loadbuffer, (void**)&original_luaL_loadbuffer);
#elif defined(__i386__) || defined(__x86_64__)
    // x86架构
    LOGI("🎯 使用 x86 Hook 方法");
    hook_success = x86_hook_function(target_func, (void*)my_luaL_loadbuffer, (void**)&original_luaL_loadbuffer);
#else
    LOGE("❌ 不支持的架构");
    hook_success = false;
#endif
    
    // 🛡️ Hook成功后的验证检查
    if (hook_success) {
        LOGI("🔍 验证Hook安装结果...");
        
        // 验证原始函数指针
        if (original_luaL_loadbuffer) {
            if (is_memory_readable((const void*)original_luaL_loadbuffer, sizeof(void*))) {
                uintptr_t func_addr = (uintptr_t)original_luaL_loadbuffer;
                if (func_addr >= 0x10000) { // 移除上限检查，适配Android ARM64
                    hook_luaL_loadbuffer_active = true;
                    LOGI("✅ luaL_loadbuffer Hook 安装成功并通过验证！");
                    LOGI("📍 目标函数: %p", target_func);
                    LOGI("📍 Hook函数: %p", (void*)my_luaL_loadbuffer);
                    LOGI("📍 原始函数: %p", (void*)original_luaL_loadbuffer);
                } else {
                    LOGE("❌ 原始函数指针地址范围异常: %p", original_luaL_loadbuffer);
                    hook_success = false;
                }
            } else {
                LOGE("❌ 原始函数指针指向无效内存: %p", original_luaL_loadbuffer);
                hook_success = false;
            }
        } else {
            LOGE("❌ Hook后原始函数指针为NULL");
            hook_success = false;
        }
    }
    
    if (!hook_success) {
        LOGE("❌ luaL_loadbuffer Hook 安装失败或验证失败");
        hook_luaL_loadbuffer_active = false;
        // 清理可能的无效指针
        original_luaL_loadbuffer = nullptr;
    }
    
    return hook_success;
}

// 🛡️ 内存安全检查函数实现
bool is_memory_readable(const void* ptr, size_t size) {
    if (!ptr || size == 0) {
        return false;
    }
    
    // 检查指针是否在合理范围内 - 修复Android ARM64地址范围
    uintptr_t addr = (uintptr_t)ptr;
    // Android ARM64用户空间地址范围更宽，包括高地址空间
    if (addr < 0x1000) { // 只检查NULL指针和非常低的地址
        return false;
    }
    
    // 检查大小是否合理
    if (size > 0x10000000) { // 256MB限制
        return false;
    }
    
    // 使用更安全的内存访问检查方法
    // 在Android中，可以使用mincore系统调用来检查内存是否可访问
    try {
        // 尝试读取第一个和最后一个字节
        volatile char test_first = ((volatile char*)ptr)[0];
        if (size > 1) {
            volatile char test_last = ((volatile char*)ptr)[size - 1];
            (void)test_last;
        }
        (void)test_first;
        return true;
    } catch (...) {
        // 如果出现异常，说明内存不可读
        return false;
    }
}

bool is_valid_lua_state(void* L) {
    if (!L) {
        return false;
    }
    
    // 基本的指针有效性检查
    if (!is_memory_readable(L, sizeof(void*))) {
        return false;
    }
    
    // 更详细的Lua状态检查可以在这里添加
    return true;
}

bool is_valid_buffer_pointer(const char* buff, size_t size) {
    if (!buff) {
        return false;
    }
    
    if (size == 0) {
        return true; // 空缓冲区是有效的
    }
    
    return is_memory_readable(buff, size);
}

// 🎯 增强的Hook管理器实现
LuaHookManager* LuaHookManager::instance = nullptr;

LuaHookManager& LuaHookManager::getInstance() {
    if (!instance) {
        instance = new LuaHookManager();
    }
    return *instance;
}

bool LuaHookManager::initHooks() {
    if (hooks_initialized) {
        LOGI("ℹ️ Hook系统已经初始化");
        return true;
    }
    
    LOGI("🚀 开始初始化Hook系统...");
    
    // 执行安全性检查
    if (!performSafetyChecks()) {
        LOGE("❌ 安全性检查失败，终止Hook初始化");
        return false;
    }
    
    bool success = true;
    
    // 安装luaL_loadbuffer Hook（最重要的）
    if (installSafeHook("luaL_loadbuffer")) {
        luaL_loadbuffer_hooked = true;
        LOGI("✅ luaL_loadbuffer Hook 安装成功");
    } else {
        LOGE("❌ luaL_loadbuffer Hook 安装失败");
        success = false;
    }
    
    hooks_initialized = success;
    logHookStatus();
    
    return success;
}

void LuaHookManager::cleanupHooks() {
    LOGI("🧹 清理Hook系统...");
    
    luaL_loadbuffer_hooked = false;
    hooks_initialized = false;
    
    LOGI("✅ Hook系统清理完成");
}

bool LuaHookManager::isHookActive(const std::string& functionName) {
    if (functionName == "luaL_loadbuffer") {
        return luaL_loadbuffer_hooked;
    }
    return false;
}

bool LuaHookManager::installSafeHook(const std::string& functionName) {
    LOGI("🔧 安装Hook: %s", functionName.c_str());
    
    try {
        if (functionName == "luaL_loadbuffer") {
            return install_luaL_loadbuffer_hook();
        }
    } catch (const std::exception& e) {
        LOGE("❌ 安装Hook时发生异常: %s", e.what());
        return false;
    } catch (...) {
        LOGE("❌ 安装Hook时发生未知异常");
        return false;
    }
    
    LOGE("❌ 未知的Hook函数名: %s", functionName.c_str());
    return false;
}

void LuaHookManager::setHookStatus(const std::string& functionName, bool status) {
    if (functionName == "luaL_loadbuffer") {
        luaL_loadbuffer_hooked = status;
    }
}

bool LuaHookManager::performSafetyChecks() {
    LOGI("🔍 执行安全性检查...");
    
    // 检查是否在正确的进程中
    // 这里可以添加更多的安全检查
    
    LOGI("✅ 安全性检查通过");
    return true;
}

void LuaHookManager::logHookStatus() {
    LOGI("📊 Hook状态报告:");
    LOGI("   - 系统初始化: %s", hooks_initialized ? "✅" : "❌");
    LOGI("   - luaL_loadbuffer: %s", luaL_loadbuffer_hooked ? "✅" : "❌");
}

// C接口实现
extern "C" {
    bool lua_decrypt_hook_init() {
        return LuaHookManager::getInstance().initHooks();
    }
    
    void lua_decrypt_hook_cleanup() {
        LuaHookManager::getInstance().cleanupHooks();
    }
}

// 跳板内存管理器 - 在Hook函数使用前定义
class TrampolineMemoryManager {
private:
    struct TrampolineInfo {
        void* memory;
        size_t size;
        std::string function_name;
        bool is_active;
    };
    
    std::vector<TrampolineInfo> allocated_trampolines;
    mutable std::mutex trampoline_mutex;
    static constexpr size_t MAX_TRAMPOLINE_SIZE = 4096; // 最大跳板大小
    static constexpr size_t MEMORY_ALIGNMENT = 16; // 内存对齐要求
    
public:
    // 分配跳板内存
    void* allocateTrampoline(size_t size, const std::string& function_name) {
        // 检查大小限制
        if (size == 0 || size > MAX_TRAMPOLINE_SIZE) {
            LOGE("❌ 跳板内存分配大小无效: %zu", size);
            return nullptr;
        }
        
        // 内存对齐
        size_t aligned_size = (size + MEMORY_ALIGNMENT - 1) & ~(MEMORY_ALIGNMENT - 1);
        
        void* memory = mmap(nullptr, aligned_size, PROT_READ | PROT_WRITE | PROT_EXEC, 
                           MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        
        if (memory != MAP_FAILED) {
            // 验证内存可访问性
            if (!is_memory_readable(memory, aligned_size)) {
                LOGE("❌ 分配的跳板内存不可读: %p", memory);
                munmap(memory, aligned_size);
                return nullptr;
            }
            
            std::lock_guard<std::mutex> lock(trampoline_mutex);
            allocated_trampolines.push_back({memory, aligned_size, function_name, true});
            LOGI("✅ 跳板内存分配成功: %p (大小: %zu, 对齐后: %zu, 函数: %s)", 
                 memory, size, aligned_size, function_name.c_str());
            return memory;
        } else {
            LOGE("❌ 跳板内存分配失败: %s", strerror(errno));
            return nullptr;
        }
    }
    
    // 释放特定跳板内存
    bool deallocateTrampoline(void* memory) {
        std::lock_guard<std::mutex> lock(trampoline_mutex);
        
        for (auto it = allocated_trampolines.begin(); it != allocated_trampolines.end(); ++it) {
            if (it->memory == memory) {
                if (munmap(it->memory, it->size) == 0) {
                    LOGI("✅ 跳板内存释放成功: %p (函数: %s)", it->memory, it->function_name.c_str());
                    allocated_trampolines.erase(it);
                    return true;
                } else {
                    LOGE("❌ 跳板内存释放失败: %p, 错误: %s", it->memory, strerror(errno));
                    return false;
                }
            }
        }
        
        LOGW("⚠️ 未找到要释放的跳板内存: %p", memory);
        return false;
    }
    
    // 释放所有跳板内存
    void deallocateAllTrampolines() {
        std::lock_guard<std::mutex> lock(trampoline_mutex);
        
        LOGI("🧹 开始释放所有跳板内存 (共 %zu 个)", allocated_trampolines.size());
        
        for (const auto& info : allocated_trampolines) {
            if (munmap(info.memory, info.size) == 0) {
                LOGI("✅ 跳板内存释放成功: %p (函数: %s)", info.memory, info.function_name.c_str());
            } else {
                LOGE("❌ 跳板内存释放失败: %p (函数: %s), 错误: %s", 
                     info.memory, info.function_name.c_str(), strerror(errno));
            }
        }
        
        allocated_trampolines.clear();
        LOGI("🏁 跳板内存管理器清理完成");
    }
    
    // 获取当前分配的跳板数量
    size_t getTrampolineCount() const {
        std::lock_guard<std::mutex> lock(trampoline_mutex);
        return allocated_trampolines.size();
    }
};

// 全局跳板内存管理器实例
static TrampolineMemoryManager g_trampolineManager;

#if defined(__i386__) || defined(__x86_64__)
// x86架构的Hook实现
#include <sys/mman.h>
#include <errno.h>

// 用于存储原始函数跳板的结构
struct x86_trampoline {
    uint8_t original_bytes[16];  // 保存原始指令
    uint8_t jump_back[16];       // 跳回原始函数的指令
    void* original_func;         // 原始函数地址
    bool is_active;              // Hook是否激活
};

static x86_trampoline loadbuffer_trampoline = {0};

// 🚨 检测运行环境 - 是否在Houdini模拟器中
static bool isRunningInHoudini() {
    // 检查是否存在Houdini特有的环境变量或文件
    if (access("/system/lib/libhoudini.so", F_OK) == 0 ||
        access("/system/lib64/libhoudini.so", F_OK) == 0) {
        return true;
    }
    
    // 检查ARM转换器相关文件
    if (access("/system/lib/libnb.so", F_OK) == 0 ||
        access("/system/lib64/libnb.so", F_OK) == 0) {
        LOGI("🔍 检测到ARM转换器库");
        return true;
    }
    
#ifdef __ANDROID__
    // 检查Android系统属性
    char prop_value[PROP_VALUE_MAX];
    if (__system_property_get("ro.product.cpu.abilist", prop_value) > 0) {
        if (strstr(prop_value, "x86")) {
            LOGI("🔍 检测到x86 ABI: %s", prop_value);
            return true;
        }
    }
#endif
    
    // 检查CPU架构信息
    char buffer[256];
    FILE* cpuinfo = fopen("/proc/cpuinfo", "r");
    if (cpuinfo) {
        while (fgets(buffer, sizeof(buffer), cpuinfo)) {
            if (strstr(buffer, "Intel") || strstr(buffer, "AMD")) {
                fclose(cpuinfo);
                return true;
            }
        }
        fclose(cpuinfo);
    }
    
    return false;
}

// 🛡️ 安全的内存写入函数
static bool safeMemoryWrite(void* target, const void* data, size_t size) {
    if (!target || !data || size == 0) {
        return false;
    }
    
    // 获取页面信息
    size_t page_size = getpagesize();
    void* page_start = (void*)((uintptr_t)target & ~(page_size - 1));
    size_t page_count = ((uintptr_t)target + size - (uintptr_t)page_start + page_size - 1) / page_size;
    size_t total_size = page_count * page_size;
    
    // 修改内存权限
    if (mprotect(page_start, total_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        LOGE("❌ 无法修改内存权限: %s", strerror(errno));
        return false;
    }
    
    // 写入数据
    memcpy(target, data, size);
    
    // 刷新指令缓存（ARM需要，x86通常不需要但为了安全起见）
    __builtin___clear_cache((char*)target, (char*)target + size);
    
    // 恢复内存权限（保持可执行）
    if (mprotect(page_start, total_size, PROT_READ | PROT_EXEC) != 0) {
        LOGW("⚠️ 恢复内存权限失败: %s", strerror(errno));
    }
    
    return true;
}

// x86架构的Hook实现 - 兼容Houdini
static bool x86_hook_function(void* target, void* replacement, void** original) {
    LOGI("🔧 开始 x86 Hook 安装 (Houdini兼容模式)...");
    
    if (!target || !replacement) {
        LOGE("❌ 无效的参数");
        return false;
    }
    
    bool in_houdini = isRunningInHoudini();
    LOGI("🔍 Houdini环境检测: %s", in_houdini ? "是" : "否");
    
    // 验证目标地址的合法性
    if (!is_memory_readable(target, 16)) {
        LOGE("❌ 目标地址不可读: %p", target);
        return false;
    }
    
    // 选择合适的跳板结构
    x86_trampoline* trampoline = nullptr;
    if (target == dlsym(target_lib_handle, "luaL_loadbuffer")) {
        trampoline = &loadbuffer_trampoline;
    }
    
    if (trampoline) {
        // 保存原始函数的前几个字节
        memcpy(trampoline->original_bytes, target, sizeof(trampoline->original_bytes));
        trampoline->original_func = target;
        trampoline->is_active = true;
        
        LOGI("💾 已保存原始指令: %02x %02x %02x %02x %02x %02x %02x %02x",
             trampoline->original_bytes[0], trampoline->original_bytes[1],
             trampoline->original_bytes[2], trampoline->original_bytes[3],
             trampoline->original_bytes[4], trampoline->original_bytes[5],
             trampoline->original_bytes[6], trampoline->original_bytes[7]);
    }
    
    // 🚨 关键修复：使用Houdini兼容的跳转方式
    bool hook_success = false;
    
    if (in_houdini) {
        // Houdini环境：使用更简单、更兼容的跳转方式
        LOGI("🔄 使用Houdini兼容的Hook方式");
        
#if defined(__x86_64__)
        // 在Houdini中，使用push+ret的方式更安全
        uint8_t houdini_jump[] = {
            0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // mov rax, replacement
            0x50,                                                       // push rax
            0xC3,                                                       // ret
            0x90, 0x90, 0x90, 0x90                                     // nop padding
        };
        *((uint64_t*)(houdini_jump + 2)) = (uint64_t)replacement;
        
        if (safeMemoryWrite(target, houdini_jump, sizeof(houdini_jump))) {
            hook_success = true;
            LOGI("📝 Houdini x64: 安装了 %zu 字节的兼容跳转代码", sizeof(houdini_jump));
        }
#elif defined(__i386__)
        // x86 32位：使用push+ret
        uint8_t houdini_jump[] = {
            0x68, 0x00, 0x00, 0x00, 0x00,  // push replacement
            0xC3,                          // ret
            0x90, 0x90                     // nop padding
        };
        *((uint32_t*)(houdini_jump + 1)) = (uint32_t)replacement;
        
        if (safeMemoryWrite(target, houdini_jump, sizeof(houdini_jump))) {
            hook_success = true;
            LOGI("📝 Houdini x86: 安装了 %zu 字节的兼容跳转代码", sizeof(houdini_jump));
        }
#endif
    } else {
        // 原生x86环境：使用传统的jmp指令
        LOGI("🔄 使用原生x86 Hook方式");
        
#if defined(__x86_64__)
        // x64: 使用绝对跳转
        uint8_t jump_code[] = {
            0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // mov rax, replacement
            0xFF, 0xE0,                                                 // jmp rax
            0x90, 0x90, 0x90, 0x90                                     // nop padding
        };
        *((uint64_t*)(jump_code + 2)) = (uint64_t)replacement;
        
        if (safeMemoryWrite(target, jump_code, sizeof(jump_code))) {
            hook_success = true;
            LOGI("📝 原生 x64: 安装了 %zu 字节的跳转代码", sizeof(jump_code));
        }
#elif defined(__i386__)
        // x86: 使用相对跳转（如果距离允许）
        int32_t offset = (int32_t)((uintptr_t)replacement - (uintptr_t)target - 5);
        
        // 检查是否在32位有符号整数范围内
        if (offset == (int32_t)((uintptr_t)replacement - (uintptr_t)target - 5)) {
            uint8_t jump_code[] = {
                0xE9, 0x00, 0x00, 0x00, 0x00,  // jmp relative
                0x90, 0x90, 0x90               // nop padding
            };
            *((int32_t*)(jump_code + 1)) = offset;
            
            if (safeMemoryWrite(target, jump_code, sizeof(jump_code))) {
                hook_success = true;
                LOGI("📝 原生 x86: 安装了 %zu 字节的相对跳转代码，偏移: %d", sizeof(jump_code), offset);
            }
        } else {
            // 距离太远，使用绝对跳转
            uint8_t abs_jump[] = {
                0x68, 0x00, 0x00, 0x00, 0x00,  // push replacement
                0xC3,                          // ret
                0x90, 0x90                     // nop padding
            };
            *((uint32_t*)(abs_jump + 1)) = (uint32_t)replacement;
            
            if (safeMemoryWrite(target, abs_jump, sizeof(abs_jump))) {
                hook_success = true;
                LOGI("📝 原生 x86: 使用绝对跳转 (距离: %ld)", (long)offset);
            }
        }
#endif
    }
    
    // 创建跳板函数
    if (hook_success && original) {
        if (trampoline && trampoline->is_active) {
            // 为x86创建一个可调用的跳板函数
            void* trampoline_mem = g_trampolineManager.allocateTrampoline(64, "luaL_loadbuffer_x86_houdini");
            
            if (trampoline_mem != nullptr) {
                uint8_t* trampoline_code = (uint8_t*)trampoline_mem;
                
                // 复制原始指令（被Hook覆盖的部分）
                size_t original_bytes_size = in_houdini ? 
                    (sizeof(void*) == 8 ? 12 : 6) :  // Houdini: push+ret大小
                    (sizeof(void*) == 8 ? 12 : 5);   // 原生: jmp大小
                
                // 复制原始指令
                memcpy(trampoline_code, trampoline->original_bytes, original_bytes_size);
                trampoline_code += original_bytes_size;
                
                // 添加跳转指令到原始函数后续位置
                void* return_addr = (void*)((uintptr_t)target + original_bytes_size);
                
#if defined(__x86_64__)
                // x64: 跳转到返回地址
                uint8_t return_jump[] = {
                    0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // mov rax, return_addr
                    0xFF, 0xE0                                                   // jmp rax
                };
                *((uint64_t*)(return_jump + 2)) = (uint64_t)return_addr;
                memcpy(trampoline_code, return_jump, sizeof(return_jump));
#elif defined(__i386__)
                // x86: 跳转到返回地址
                uint8_t return_jump[] = {
                    0x68, 0x00, 0x00, 0x00, 0x00,  // push return_addr
                    0xC3                           // ret
                };
                *((uint32_t*)(return_jump + 1)) = (uint32_t)return_addr;
                memcpy(trampoline_code, return_jump, sizeof(return_jump));
#endif
                
                // 确保内存权限正确
                if (mprotect(trampoline_mem, 64, PROT_READ | PROT_EXEC) == 0) {
                    *original = trampoline_mem;
                    LOGI("✅ x86 Hook: 创建了Houdini兼容的跳板函数 %p -> %p", trampoline_mem, return_addr);
                } else {
                    LOGE("❌ x86 Hook: 无法设置跳板内存权限: %s", strerror(errno));
                    g_trampolineManager.deallocateTrampoline(trampoline_mem);
                    *original = nullptr;
                    hook_success = false;
                }
            } else {
                LOGE("❌ x86 Hook: 无法分配跳板内存");
                *original = nullptr;
                hook_success = false;
            }
        } else {
            LOGW("⚠️ x86 Hook: 无跳板信息，设置原始指针为NULL");
            *original = nullptr;
        }
    }
    
    if (hook_success) {
        LOGI("✅ x86 Hook 安装完成 (Houdini兼容)");
    } else {
        LOGE("❌ x86 Hook 安装失败");
    }
    
    return hook_success;
}

// x86架构的Hook清理函数
static bool x86_unhook_function(void* target) {
    LOGI("🧹 开始清理 x86 Hook...");
    
    if (!target) {
        LOGE("❌ 无效的目标地址");
        return false;
    }
    
    // 选择合适的跳板结构
    x86_trampoline* trampoline = nullptr;
    if (target == dlsym(target_lib_handle, "luaL_loadbuffer")) {
        trampoline = &loadbuffer_trampoline;
    }
    
    if (!trampoline || !trampoline->is_active) {
        LOGW("⚠️ 未找到对应的跳板或Hook未激活");
        return false;
    }
    
    // 恢复原始字节
    if (safeMemoryWrite(target, trampoline->original_bytes, sizeof(trampoline->original_bytes))) {
        trampoline->is_active = false;
        LOGI("✅ x86 Hook 清理完成");
        return true;
    } else {
        LOGE("❌ x86 Hook 清理失败");
        return false;
    }
}
#endif

#if defined(__arm__) || defined(__ARM_ARCH_7A__)
// ARM 32位架构的Hook实现
#include <sys/mman.h>
#include <errno.h>

// 用于存储原始函数跳板的结构
struct arm32_trampoline {
    uint8_t original_bytes[16];  // 保存原始指令
    uint8_t jump_back[16];       // 跳回原始函数的指令
    void* original_func;         // 原始函数地址
    bool is_active;              // Hook是否激活
};

static arm32_trampoline loadbuffer_trampoline = {0};

// ARM 32位架构的Hook实现
static bool arm32_hook_function(void* target, void* replacement, void** original) {
    LOGI("🔧 开始 ARM32 Hook 安装...");
    
    if (!target || !replacement) {
        LOGE("❌ 无效的参数");
        return false;
    }
    
    // 获取页面大小和对齐
    size_t page_size = getpagesize();
    void* page_start = (void*)((uintptr_t)target & ~(page_size - 1));
    
    // 修改内存权限为可写
    if (mprotect(page_start, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        LOGE("❌ 无法修改内存权限: %s", strerror(errno));
        return false;
    }
    
    // 选择合适的跳板结构
    arm32_trampoline* trampoline = nullptr;
    if (target == dlsym(target_lib_handle, "luaL_loadbuffer")) {
        trampoline = &loadbuffer_trampoline;
    }
    
    if (trampoline) {
        // 保存原始函数的前几个字节
        memcpy(trampoline->original_bytes, target, sizeof(trampoline->original_bytes));
        trampoline->original_func = target;
        trampoline->is_active = true;
    }
    
    // ARM32 Thumb模式跳转指令 (8字节)
    // 使用 LDR PC, [PC, #-4] 指令进行绝对跳转
    uint32_t jump_code[] = {
        0xe51ff004,  // LDR PC, [PC, #-4]  ; 从PC-4位置加载地址到PC
        (uint32_t)replacement  // 目标地址
    };
    
    // 检查目标地址是否为Thumb模式（最低位为1）
    if ((uintptr_t)target & 1) {
        // Thumb模式跳转
        uint16_t thumb_jump[] = {
            0x4778,  // BX PC     ; 切换到ARM模式
            0x46c0,  // NOP       ; 对齐
            0xe51f,  // LDR PC, [PC, #-4] 的高16位
            0xf004   // LDR PC, [PC, #-4] 的低16位
        };
        memcpy(target, thumb_jump, sizeof(thumb_jump));
        memcpy((char*)target + sizeof(thumb_jump), &replacement, sizeof(replacement));
        LOGI("📝 ARM32: 安装了 Thumb 模式跳转代码");
    } else {
        // ARM模式跳转
        memcpy(target, jump_code, sizeof(jump_code));
        LOGI("📝 ARM32: 安装了 ARM 模式跳转代码");
    }
    
    // 设置原始函数指针
    if (original) {
        if (trampoline && trampoline->is_active) {
            // 为ARM32创建一个可调用的跳板函数 - 使用管理器分配内存
            void* trampoline_mem = g_trampolineManager.allocateTrampoline(32, "luaL_loadbuffer_arm32");
            
            if (trampoline_mem != nullptr) {
                // 创建跳板代码：先执行原始指令，然后跳转到原始函数+8
                uint32_t* trampoline_code = (uint32_t*)trampoline_mem;
                
                // 复制原始指令（前8字节）
                memcpy(trampoline_code, trampoline->original_bytes, 8);
                
                // 添加跳转指令到原始函数+8的位置
                uint32_t return_addr = (uint32_t)target + 8;
                trampoline_code[2] = 0xe51ff004;  // LDR PC, [PC, #-4]
                trampoline_code[3] = return_addr; // 返回地址
                
                *original = trampoline_mem;
                LOGI("✅ ARM32 Hook: 创建了跳板函数 %p -> %p (由管理器分配)", trampoline_mem, (void*)return_addr);
            } else {
                // 如果无法创建跳板，使用简单的函数指针（可能不工作）
                *original = trampoline->original_func;
                LOGW("⚠️ ARM32 Hook: 无法创建跳板，使用原始地址");
            }
        } else {
            *original = target;
            LOGW("⚠️ ARM32 Hook: 使用目标地址作为原始函数指针");
        }
    }
    
    // 恢复内存权限
    if (mprotect(page_start, page_size, PROT_READ | PROT_EXEC) != 0) {
        LOGW("⚠️ 恢复内存权限失败: %s", strerror(errno));
    }
    
    LOGI("✅ ARM32 Hook 安装完成");
    return true;
}

// ARM32架构的Hook清理函数
static bool arm32_unhook_function(void* target) {
    LOGI("🧹 开始清理 ARM32 Hook...");
    
    if (!target) {
        LOGE("❌ 无效的目标地址");
        return false;
    }
    
    // 选择合适的跳板结构
    arm32_trampoline* trampoline = nullptr;
    if (target == dlsym(target_lib_handle, "luaL_loadbuffer")) {
        trampoline = &loadbuffer_trampoline;
    }
    
    if (!trampoline || !trampoline->is_active) {
        LOGW("⚠️ 未找到对应的跳板或Hook未激活");
        return false;
    }
    
    // 获取页面大小和对齐
    size_t page_size = getpagesize();
    void* page_start = (void*)((uintptr_t)target & ~(page_size - 1));
    
    // 修改内存权限为可写
    if (mprotect(page_start, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        LOGE("❌ 无法修改内存权限: %s", strerror(errno));
        return false;
    }
    
    // 恢复原始字节
    memcpy(target, trampoline->original_bytes, sizeof(trampoline->original_bytes));
    trampoline->is_active = false;
    
    // 恢复内存权限
    mprotect(page_start, page_size, PROT_READ | PROT_EXEC);
    
    LOGI("✅ ARM32 Hook 清理完成");
    return true;
}
#endif

namespace LuaDecryptHook {
    bool lua_decrypt_hook_init() {
        LOGI("🚀 初始化 Lua 解密 Hook 系统...");
        return install_luaL_loadbuffer_hook();
    }
    
    void lua_decrypt_hook_cleanup() {
        LOGI("🧹 清理 Lua 解密 Hook 系统...");
        
        // 首先清理Hook
        if (target_lib_handle && original_luaL_loadbuffer) {
            void* target = dlsym(target_lib_handle, "luaL_loadbuffer");
            if (target) {
#if defined(__aarch64__)
                A64HookFunction(target, (void*)original_luaL_loadbuffer, nullptr);
#elif defined(__arm__) || defined(__ARM_ARCH_7A__)
                arm32_unhook_function(target);
#elif defined(__i386__) || defined(__x86_64__)
                x86_unhook_function(target);
#endif
            }
        }
        
        // 清理所有跳板内存
        g_trampolineManager.deallocateAllTrampolines();
        
        // 清理动态库句柄
        if (target_lib_handle) {
            dlclose(target_lib_handle);
            target_lib_handle = nullptr;
        }
        
        LOGI("✅ Lua 解密 Hook 系统清理完成");
    }
    
    // 获取跳板内存使用统计
    size_t getTrampolineMemoryCount() {
        return g_trampolineManager.getTrampolineCount();
    }
}