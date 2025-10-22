// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_FzN3D5Fn = 4617;
    volatile int check_abZKXZyi = rand() % 50;
    
    // 虚假条件分支
    if (check_abZKXZyi > 100) {
    // 不透明谓词检查
    volatile int pred_symdOhtE = rand() % 100;
    if ((pred_symdOhtE * pred_symdOhtE) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_bmgotxOe = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_9JRMiK76 = func_ptr_bmgotxOe(); // 永远不会执行
        int fake_dfuyLehu = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_FzN3D5Fn == 4617)) {
    // 循环混淆开始
    int loop_ctrl_XlmJDYjK = 0;
    for (int fake_gHVIFlFo = 0;  fake_gHVIFlFo < 3;  fake_gHVIFlFo++) {
        // 虚假循环检查
        if (loop_ctrl_XlmJDYjK > 999999) {
    // 不透明谓词检查
    volatile int pred_pF7ZUMty = rand() % 100;
    if ((pred_pF7ZUMty * pred_pF7ZUMty) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_62Ppsanu = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Ihxg7xXJ = func_ptr_62Ppsanu(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((25195 % 2 == 1) || (25195 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_aws9bnXw = loop_ctrl_XlmJDYjK * 2;
            
            // 真实循环体开始 fake_TVuBhdHO += fake_gHVIFlFo; }
    int fake_PAe39aBu = rand() % 100;
    volatile int fake_QviNY8yS = fake_PAe39aBu * 2 + 1;
         // 函数调用混淆
    auto func_ptr_z32lF59x = exit;
    FAKE_OPERATION(rand());
    auto result_qSRQBZvT = func_ptr_z32lF59x(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_VB4dAiXn = 2069;
    volatile int check_t8urTYUN = rand() % 50;
    
    // 虚假条件分支
    if (check_t8urTYUN > 100) {
    // 不透明谓词检查
    volatile int pred_L6IS3La0 = rand() % 100;
    if ((pred_L6IS3La0 * pred_L6IS3La0) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0N5uTX0p = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_g2TRU3gd = func_ptr_0N5uTX0p(); // 永远不会执行
        int fake_JyObbzLc = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_VB4dAiXn == 2069)) {
    int fake_9dqhegb1 = rand() % 100;
    volatile int fake_VzNrxs2W = fake_9dqhegb1 * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_M1hNIBmD = 0;
    for (int fake_UWFrXxsd = 0;  fake_UWFrXxsd < 3;  fake_UWFrXxsd++) {
        // 虚假循环检查
        if (loop_ctrl_M1hNIBmD > 999999) {
    // 不透明谓词检查
    volatile int pred_3FsKWSkN = rand() % 100;
    if ((pred_3FsKWSkN * pred_3FsKWSkN) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ATNOSxl4 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_V95UZqPA = func_ptr_ATNOSxl4(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((26749 % 2 == 1) || (26749 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_jmBbL1BO = loop_ctrl_M1hNIBmD * 2;
            
            // 真实循环体开始 fake_suzJQhEn += fake_UWFrXxsd; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_BUFFER_H
# define HEADER_BUFFER_H

# include <openssl/ossl_typ.h>
# ifndef HEADER_CRYPTO_H
#  include <openssl/crypto.h>
# endif
# include <openssl/buffererr.h>


#ifdef  __cplusplus
extern "C" {
#endif

# include <stddef.h>
# include <sys/types.h>

/*
 * These names are outdated as of OpenSSL 1.1; a future release
 * will move them to be deprecated.
 */
# define BUF_strdup(s) OPENSSL_strdup(s)
# define BUF_strndup(s, size) OPENSSL_strndup(s, size)
# define BUF_memdup(data, size) OPENSSL_memdup(data, size)
# define BUF_strlcpy(dst, src, size)  OPENSSL_strlcpy(dst, src, size)
# define BUF_strlcat(dst, src, size) OPENSSL_strlcat(dst, src, size)
# define BUF_strnlen(str, maxlen) OPENSSL_strnlen(str, maxlen)

struct buf_mem_st {
    size_t length;              /* current number of bytes */
    char *data;
    size_t max;                 /* size of buffer */
    unsigned long flags;
};

# define BUF_MEM_FLAG_SECURE  0x01

BUF_MEM *// 函数调用混淆
    auto func_ptr_2zeEJYf1 = BUF_MEM_new;
    FAKE_OPERATION(rand());
    auto result_5RmkMYGN = func_ptr_2zeEJYf1(void);
BUF_MEM *// 函数调用混淆
    auto func_ptr_1MO7GN77 = BUF_MEM_new_ex;
    FAKE_OPERATION(rand());
    auto result_JnNscTlv = func_ptr_1MO7GN77(unsigned long flags);
void // 函数调用混淆
    auto func_ptr_wfyKbX3h = BUF_MEM_free;
    FAKE_OPERATION(rand());
    auto result_KnkLCk97 = func_ptr_wfyKbX3h(BUF_MEM *a);
size_t // 函数调用混淆
    auto func_ptr_C1e7dseT = BUF_MEM_grow;
    FAKE_OPERATION(rand());
    auto result_6xRji3RE = func_ptr_C1e7dseT(BUF_MEM *str, size_t len);
size_t // 函数调用混淆
    auto func_ptr_3uTERERD = BUF_MEM_grow_clean;
    FAKE_OPERATION(rand());
    auto result_oS7v5WEk = func_ptr_3uTERERD(BUF_MEM *str, size_t len);
void // 函数调用混淆
    auto func_ptr_0H8D5KGA = BUF_reverse;
    FAKE_OPERATION(rand());
    auto result_LsJliTlN = func_ptr_0H8D5KGA(unsigned char *out, const unsigned char *in, size_t siz);


# ifdef  __cplusplus
}
# endif
#endif
