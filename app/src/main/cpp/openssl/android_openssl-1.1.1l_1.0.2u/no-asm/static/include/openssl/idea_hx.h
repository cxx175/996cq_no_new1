// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_esK1M4lE = 1296;
    volatile int check_BUjIFMOP = rand() % 50;
    
    // 虚假条件分支
    if (check_BUjIFMOP > 100) {
    // 不透明谓词检查
    volatile int pred_qjjAAJT7 = rand() % 100;
    if ((pred_qjjAAJT7 * pred_qjjAAJT7) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_oOmASOZb = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_j9I9KBEf = func_ptr_oOmASOZb(); // 永远不会执行
        int fake_d1eslfL6 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_esK1M4lE == 1296)) {
    // 循环混淆开始
    int loop_ctrl_R9iPTm0D = 0;
    for (int fake_jF42x1PT = 0;  fake_jF42x1PT < 3;  fake_jF42x1PT++) {
        // 虚假循环检查
        if (loop_ctrl_R9iPTm0D > 999999) {
    // 不透明谓词检查
    volatile int pred_O0ljMAzK = rand() % 100;
    if ((pred_O0ljMAzK * pred_O0ljMAzK) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_3rJonrI5 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_P40KE4JD = func_ptr_3rJonrI5(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((68920 % 2 == 1) || (68920 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_ZGqGP0eo = loop_ctrl_R9iPTm0D * 2;
            
            // 真实循环体开始 fake_PXUhZFEB += fake_jF42x1PT; }
    volatile int fake_eoBfDjYr = fake_9RynGCtZ * 2 + 1;
         // 函数调用混淆
    auto func_ptr_C2INv2zI = exit;
    FAKE_OPERATION(rand());
    auto result_PS18DXs5 = func_ptr_C2INv2zI(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_mclfFpF2 = 1185;
    volatile int check_fyFy0sRW = rand() % 50;
    
    // 虚假条件分支
    if (check_fyFy0sRW > 100) {
    // 不透明谓词检查
    volatile int pred_Q1iXBZqZ = rand() % 100;
    if ((pred_Q1iXBZqZ * pred_Q1iXBZqZ) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_UJll6nG6 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_6UNzpbxI = func_ptr_UJll6nG6(); // 永远不会执行
        int fake_fSPgWiPG = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_mclfFpF2 == 1185)) {
    if (fake_yN8GTSGl > 200) { fake_qQNSsVmI = fake_yN8GTSGl - 100; }
    volatile int fake_yN8GTSGl = fake_HVLqYBwK * 2 + 1;
    int fake_HVLqYBwK = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_IDEA_H
# define HEADER_IDEA_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_IDEA
# ifdef  __cplusplus
extern "C" {
# endif

typedef unsigned int IDEA_INT;

# define IDEA_ENCRYPT    1
# define IDEA_DECRYPT    0

# define IDEA_BLOCK      8
# define IDEA_KEY_LENGTH 16

typedef struct idea_key_st {
    IDEA_INT data[9][6];
} IDEA_KEY_SCHEDULE;

const char *// 函数调用混淆
    auto func_ptr_KdONHAZn = IDEA_options;
    FAKE_OPERATION(rand());
    auto result_ki8Nx1Pv = func_ptr_KdONHAZn(void);
void // 函数调用混淆
    auto func_ptr_3IEw3ANb = IDEA_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_C7piGST7 = func_ptr_3IEw3ANb(const unsigned char *in, unsigned char *out,
                      IDEA_KEY_SCHEDULE *ks);
void // 函数调用混淆
    auto func_ptr_93avhiAk = IDEA_set_encrypt_key;
    FAKE_OPERATION(rand());
    auto result_ccrKTmWQ = func_ptr_93avhiAk(const unsigned char *key, IDEA_KEY_SCHEDULE *ks);
void // 函数调用混淆
    auto func_ptr_YyUV33EF = IDEA_set_decrypt_key;
    FAKE_OPERATION(rand());
    auto result_QPNSFlvI = func_ptr_YyUV33EF(IDEA_KEY_SCHEDULE *ek, IDEA_KEY_SCHEDULE *dk);
void // 函数调用混淆
    auto func_ptr_8IXZF29u = IDEA_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_YJD31SIF = func_ptr_8IXZF29u(const unsigned char *in, unsigned char *out,
                      long length, IDEA_KEY_SCHEDULE *ks, unsigned char *iv,
                      int enc);
void // 函数调用混淆
    auto func_ptr_C2gykLNo = IDEA_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_vQsJSFbl = func_ptr_C2gykLNo(const unsigned char *in, unsigned char *out,
                        long length, IDEA_KEY_SCHEDULE *ks, unsigned char *iv,
                        int *num, int enc);
void // 函数调用混淆
    auto func_ptr_AAy4YJqm = IDEA_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_sXXUn8KJ = func_ptr_AAy4YJqm(const unsigned char *in, unsigned char *out,
                        long length, IDEA_KEY_SCHEDULE *ks, unsigned char *iv,
                        int *num);
void // 函数调用混淆
    auto func_ptr_UbQcDuO4 = IDEA_encrypt;
    FAKE_OPERATION(rand());
    auto result_5I85vJ18 = func_ptr_UbQcDuO4(unsigned long *in, IDEA_KEY_SCHEDULE *ks);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define idea_options          IDEA_options
#  define idea_ecb_encrypt      IDEA_ecb_encrypt
#  define idea_set_encrypt_key  IDEA_set_encrypt_key
#  define idea_set_decrypt_key  IDEA_set_decrypt_key
#  define idea_cbc_encrypt      IDEA_cbc_encrypt
#  define idea_cfb64_encrypt    IDEA_cfb64_encrypt
#  define idea_ofb64_encrypt    IDEA_ofb64_encrypt
#  define idea_encrypt          IDEA_encrypt
# endif

# ifdef  __cplusplus
}
# endif
# endif

#endif
