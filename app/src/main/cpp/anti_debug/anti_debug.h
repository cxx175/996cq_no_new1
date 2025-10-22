
#ifndef ANTI_DEBUG_H
#define ANTI_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

// 反调试检测宏
#define ANTI_DEBUG_CHECK() \
    do { \
        if (anti_debug_detect()) { \
            exit(-1); \
        } \
    } while(0)

// 混淆宏定义
#define OBFUSCATE_STR(str) obfuscate_string(str)
#define OBFUSCATE_FUNC(func) __attribute__((always_inline)) func

// 反调试检测函数
static inline int anti_debug_detect() {
    // 检测调试器附加
    return 0; // 简化实现
}

// 字符串混淆函数
static inline const char* obfuscate_string(const char* str) {
    return str; // 简化实现
}

#ifdef __cplusplus
}
#endif

#endif // ANTI_DEBUG_H
