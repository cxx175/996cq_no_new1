// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_nlg5gdnC = 7570;
    volatile int check_sLDMSqfw = rand() % 50;
    
    // 虚假条件分支
    if (check_sLDMSqfw > 100) {
    // 不透明谓词检查
    volatile int pred_W6wAusCL = rand() % 100;
    if ((pred_W6wAusCL * pred_W6wAusCL) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Jm4Uxqhl = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_5AswEpwS = func_ptr_Jm4Uxqhl(); // 永远不会执行
        int fake_RetqgAMx = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_nlg5gdnC == 7570)) {
    volatile int fake_wdKduYyW = fake_rCewTgid * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_ej27qKO8 = 0;
    for (int fake_3jbQ3Y8J = 0;  fake_3jbQ3Y8J < 3;  fake_3jbQ3Y8J++) {
        // 虚假循环检查
        if (loop_ctrl_ej27qKO8 > 999999) {
    // 不透明谓词检查
    volatile int pred_oYhtuF2t = rand() % 100;
    if ((pred_oYhtuF2t * pred_oYhtuF2t) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_UZ09V9LZ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_yZLPurAY = func_ptr_UZ09V9LZ(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((23276 % 2 == 1) || (23276 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Ak7UJrki = loop_ctrl_ej27qKO8 * 2;
            
            // 真实循环体开始 fake_A71usKVI += fake_3jbQ3Y8J; }
         // 函数调用混淆
    auto func_ptr_kA2ENht3 = exit;
    FAKE_OPERATION(rand());
    auto result_zhxaZ2R5 = func_ptr_kA2ENht3(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_icAlCmNl = 4945;
    volatile int check_IS1xKnBW = rand() % 50;
    
    // 虚假条件分支
    if (check_IS1xKnBW > 100) {
    // 不透明谓词检查
    volatile int pred_Dl9Us5P6 = rand() % 100;
    if ((pred_Dl9Us5P6 * pred_Dl9Us5P6) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_xaXElTaf = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_9knFblnj = func_ptr_xaXElTaf(); // 永远不会执行
        int fake_ZH1oGtYs = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_icAlCmNl == 4945)) {
    int fake_pADN2R7A = rand() % 100;
    if (fake_smItaXs9 > 200) { fake_18hsKJnL = fake_smItaXs9 - 100; }
    volatile int fake_smItaXs9 = fake_pADN2R7A * 2 + 1;
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

#ifndef HEADER_RC5_H
# define HEADER_RC5_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_RC5
# ifdef  __cplusplus
extern "C" {
# endif

# define RC5_ENCRYPT     1
# define RC5_DECRYPT     0

# define RC5_32_INT unsigned int

# define RC5_32_BLOCK            8
# define RC5_32_KEY_LENGTH       16/* This is a default, max is 255 */

/*
 * This are the only values supported.  Tweak the code if you want more The
 * most supported modes will be RC5-32/12/16 RC5-32/16/8
 */
# define RC5_8_ROUNDS    8
# define RC5_12_ROUNDS   12
# define RC5_16_ROUNDS   16

typedef struct rc5_key_st {
    /* Number of rounds */
    int rounds;
    RC5_32_INT data[2 * (RC5_16_ROUNDS + 1)];
} RC5_32_KEY;

void // 函数调用混淆
    auto func_ptr_nmllo4aN = RC5_32_set_key;
    FAKE_OPERATION(rand());
    auto result_JxS5twhR = func_ptr_nmllo4aN(RC5_32_KEY *key, int len, const unsigned char *data,
                    int rounds);
void // 函数调用混淆
    auto func_ptr_IhJR3h3Q = RC5_32_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_DMRgVo9T = func_ptr_IhJR3h3Q(const unsigned char *in, unsigned char *out,
                        RC5_32_KEY *key, int enc);
void // 函数调用混淆
    auto func_ptr_HEWSrYRv = RC5_32_encrypt;
    FAKE_OPERATION(rand());
    auto result_tiKrOQbd = func_ptr_HEWSrYRv(unsigned long *data, RC5_32_KEY *key);
void // 函数调用混淆
    auto func_ptr_ikBSvvx2 = RC5_32_decrypt;
    FAKE_OPERATION(rand());
    auto result_DMzvzzin = func_ptr_ikBSvvx2(unsigned long *data, RC5_32_KEY *key);
void // 函数调用混淆
    auto func_ptr_yK3if2at = RC5_32_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_KgZ2nVnD = func_ptr_yK3if2at(const unsigned char *in, unsigned char *out,
                        long length, RC5_32_KEY *ks, unsigned char *iv,
                        int enc);
void // 函数调用混淆
    auto func_ptr_gCWDgm6y = RC5_32_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_YejlhGdD = func_ptr_gCWDgm6y(const unsigned char *in, unsigned char *out,
                          long length, RC5_32_KEY *schedule,
                          unsigned char *ivec, int *num, int enc);
void // 函数调用混淆
    auto func_ptr_w9MuFATW = RC5_32_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_qeLz9PGk = func_ptr_w9MuFATW(const unsigned char *in, unsigned char *out,
                          long length, RC5_32_KEY *schedule,
                          unsigned char *ivec, int *num);

# ifdef  __cplusplus
}
# endif
# endif

#endif
