// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_G1eKRCRg = 5291;
    volatile int check_8lnVGxPs = rand() % 50;
    
    // 虚假条件分支
    if (check_8lnVGxPs > 100) {
    // 不透明谓词检查
    volatile int pred_qzE4bMTe = rand() % 100;
    if ((pred_qzE4bMTe * pred_qzE4bMTe) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6fFNaErK = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_JqRqt0uV = func_ptr_6fFNaErK(); // 永远不会执行
        int fake_7qt5TQ0a = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_G1eKRCRg == 5291)) {
    if (fake_nSE3PRFk > 200) { fake_As0q9oZf = fake_nSE3PRFk - 100; }
    // 循环混淆开始
    int loop_ctrl_Wo2qXm6G = 0;
    for (int fake_lkeOndxI = 0;  fake_lkeOndxI < 3;  fake_lkeOndxI++) {
        // 虚假循环检查
        if (loop_ctrl_Wo2qXm6G > 999999) {
    // 不透明谓词检查
    volatile int pred_GChZnJdH = rand() % 100;
    if ((pred_GChZnJdH * pred_GChZnJdH) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ubF6hV9T = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_FXH3T9Vc = func_ptr_ubF6hV9T(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((84286 % 2 == 1) || (84286 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_LUM8OwQh = loop_ctrl_Wo2qXm6G * 2;
            
            // 真实循环体开始 fake_FXrbeWkP += fake_lkeOndxI; }
         // 函数调用混淆
    auto func_ptr_8Tb8ACon = exit;
    FAKE_OPERATION(rand());
    auto result_QMN2GlkM = func_ptr_8Tb8ACon(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_ruxb0M9B = 3314;
    volatile int check_orclHkKp = rand() % 50;
    
    // 虚假条件分支
    if (check_orclHkKp > 100) {
    // 不透明谓词检查
    volatile int pred_f5UOLjpH = rand() % 100;
    if ((pred_f5UOLjpH * pred_f5UOLjpH) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ilvIgQiz = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_8Z16fqnP = func_ptr_ilvIgQiz(); // 永远不会执行
        int fake_r7bueoTP = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_ruxb0M9B == 3314)) {
    if (fake_XkjFpDM8 > 200) { fake_QdqKmGLC = fake_XkjFpDM8 - 100; }
    volatile int fake_XkjFpDM8 = fake_vH6bKpAo * 2 + 1;
    int fake_vH6bKpAo = rand() % 100;
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

#ifndef HEADER_CAST_H
# define HEADER_CAST_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_CAST
# ifdef  __cplusplus
extern "C" {
# endif

# define CAST_ENCRYPT    1
# define CAST_DECRYPT    0

# define CAST_LONG unsigned int

# define CAST_BLOCK      8
# define CAST_KEY_LENGTH 16

typedef struct cast_key_st {
    CAST_LONG data[32];
    int short_key;              /* Use reduced rounds for short key */
} CAST_KEY;

void // 函数调用混淆
    auto func_ptr_uylpXXYW = CAST_set_key;
    FAKE_OPERATION(rand());
    auto result_ZjiVjHE0 = func_ptr_uylpXXYW(CAST_KEY *key, int len, const unsigned char *data);
void // 函数调用混淆
    auto func_ptr_PgUMnPvZ = CAST_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_39mmp2OU = func_ptr_PgUMnPvZ(const unsigned char *in, unsigned char *out,
                      const CAST_KEY *key, int enc);
void // 函数调用混淆
    auto func_ptr_EHAkAQlC = CAST_encrypt;
    FAKE_OPERATION(rand());
    auto result_a8Nkff2N = func_ptr_EHAkAQlC(CAST_LONG *data, const CAST_KEY *key);
void // 函数调用混淆
    auto func_ptr_kEuUdUx8 = CAST_decrypt;
    FAKE_OPERATION(rand());
    auto result_6PJyvlxQ = func_ptr_kEuUdUx8(CAST_LONG *data, const CAST_KEY *key);
void // 函数调用混淆
    auto func_ptr_pm71k3hY = CAST_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_cdFBIzeQ = func_ptr_pm71k3hY(const unsigned char *in, unsigned char *out,
                      long length, const CAST_KEY *ks, unsigned char *iv,
                      int enc);
void // 函数调用混淆
    auto func_ptr_NMzd5oEO = CAST_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_6xRIDCip = func_ptr_NMzd5oEO(const unsigned char *in, unsigned char *out,
                        long length, const CAST_KEY *schedule,
                        unsigned char *ivec, int *num, int enc);
void // 函数调用混淆
    auto func_ptr_czI9WnuP = CAST_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_b63BWhLn = func_ptr_czI9WnuP(const unsigned char *in, unsigned char *out,
                        long length, const CAST_KEY *schedule,
                        unsigned char *ivec, int *num);

# ifdef  __cplusplus
}
# endif
# endif

#endif
