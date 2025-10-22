#ifndef LUA_DECRYPT_HOOK_H
#define LUA_DECRYPT_HOOK_H

#include <jni.h>
#include <android/log.h>
#include <dlfcn.h>
#include <string>
#include <stdexcept>

// 日志宏定义 - 支持灵活的日志控制
#define TAG "LUA-print"

#if defined(DEBUG_MODE) || defined(RELEASE_MODE)
    // Debug模式或Release模式（启用日志） - 启用日志
    #define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
    #define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
    #define LOGW(...)  __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
    #define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#elif defined(NDEBUG)
    // Release模式（NDEBUG定义）- 禁用所有日志
    #define LOGD(...)  ((void)0)
    #define LOGI(...)  ((void)0)
    #define LOGW(...)  ((void)0)
    #define LOGE(...)  ((void)0)
#else
    // 默认情况（开发环境） - 启用日志
    #define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
    #define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
    #define LOGW(...)  __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
    #define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#endif

// Lua函数原型定义
typedef int (*luaL_loadbuffer_t)(void* L, const char* buff, size_t size, const char* name);

// 🛡️ 内存安全检查函数
bool is_memory_readable(const void* ptr, size_t size);
bool is_valid_lua_state(void* L);
bool is_valid_buffer_pointer(const char* buff, size_t size);

// Hook函数声明
extern "C" {
    // Hook初始化和清理
    bool lua_decrypt_hook_init();
    void lua_decrypt_hook_cleanup();
    // 只保留loadbuffer hook
    bool install_luaL_loadbuffer_hook();
    // 解密函数
    char* decrypt_lua_script(const char* encrypted_buff, size_t size, const char* script_name);
}

// 🎯 增强的Hook管理器类
class LuaHookManager {
private:
    static LuaHookManager* instance;
    bool hooks_initialized;
    bool luaL_loadbuffer_hooked;
    
    LuaHookManager() : hooks_initialized(false), luaL_loadbuffer_hooked(false) {}

public:
    static LuaHookManager& getInstance();
    
    bool initHooks();
    void cleanupHooks();
    bool isHookActive(const std::string& functionName);
    bool installSafeHook(const std::string& functionName);
    void setHookStatus(const std::string& functionName, bool status);
    // 安全性检查
    bool performSafetyChecks();
    void logHookStatus();
};

#endif // LUA_DECRYPT_HOOK_H 