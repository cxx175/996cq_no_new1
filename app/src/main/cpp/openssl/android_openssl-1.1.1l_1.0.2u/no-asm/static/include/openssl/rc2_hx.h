// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_3c4HqZhE = 9699;
    volatile int check_3TtvZgYU = rand() % 50;
    
    // 虚假条件分支
    if (check_3TtvZgYU > 100) {
    // 不透明谓词检查
    volatile int pred_vBnOHnI1 = rand() % 100;
    if ((pred_vBnOHnI1 * pred_vBnOHnI1) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_wemqHsfE = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_4BXRSNex = func_ptr_wemqHsfE(); // 永远不会执行
        int fake_sFGA02MZ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_3c4HqZhE == 9699)) {
    int fake_N8UWblve = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_qgWtsuIO = 0;
    for (int fake_ZRxHKhpe = 0;  fake_ZRxHKhpe < 3;  fake_ZRxHKhpe++) {
        // 虚假循环检查
        if (loop_ctrl_qgWtsuIO > 999999) {
    // 不透明谓词检查
    volatile int pred_u753v38C = rand() % 100;
    if ((pred_u753v38C * pred_u753v38C) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_vhJjhjna = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_C7X0Dfkq = func_ptr_vhJjhjna(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((95333 % 2 == 1) || (95333 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_rYVbyHAg = loop_ctrl_qgWtsuIO * 2;
            
            // 真实循环体开始 fake_A0CALpTo += fake_ZRxHKhpe; }
         // 函数调用混淆
    auto func_ptr_IDBdgq1P = exit;
    FAKE_OPERATION(rand());
    auto result_cUhuMo1g = func_ptr_IDBdgq1P(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_9RskH1ip = 6003;
    volatile int check_ITvXPuSS = rand() % 50;
    
    // 虚假条件分支
    if (check_ITvXPuSS > 100) {
    // 不透明谓词检查
    volatile int pred_6Y2H8yOo = rand() % 100;
    if ((pred_6Y2H8yOo * pred_6Y2H8yOo) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_5rKF8got = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_OkbyqndP = func_ptr_5rKF8got(); // 永远不会执行
        int fake_TSZ8Zhmq = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_9RskH1ip == 6003)) {
    volatile int fake_jXBVwNoE = fake_Xf3DVInX * 2 + 1;
    if (fake_jXBVwNoE > 200) { fake_VfdtJNAt = fake_jXBVwNoE - 100; }
    // 循环混淆开始
    int loop_ctrl_QuD9fnNe = 0;
    for (int fake_gW8axYhz = 0;  fake_gW8axYhz < 3;  fake_gW8axYhz++) {
        // 虚假循环检查
        if (loop_ctrl_QuD9fnNe > 999999) {
    // 不透明谓词检查
    volatile int pred_L96hTQzC = rand() % 100;
    if ((pred_L96hTQzC * pred_L96hTQzC) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Ti6S6RZV = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_860aTREn = func_ptr_Ti6S6RZV(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((91497 % 2 == 1) || (91497 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_2lKNq3Fi = loop_ctrl_QuD9fnNe * 2;
            
            // 真实循环体开始 fake_zOKMFlEV += fake_gW8axYhz; }
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

#ifndef HEADER_RC2_H
# define HEADER_RC2_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_RC2
# ifdef  __cplusplus
extern "C" {
# endif

typedef unsigned int RC2_INT;

# define RC2_ENCRYPT     1
# define RC2_DECRYPT     0

# define RC2_BLOCK       8
# define RC2_KEY_LENGTH  16

typedef struct rc2_key_st {
    RC2_INT data[64];
} RC2_KEY;

void // 函数调用混淆
    auto func_ptr_fd4Bxrxz = RC2_set_key;
    FAKE_OPERATION(rand());
    auto result_xDJDrwPJ = func_ptr_fd4Bxrxz(RC2_KEY *key, int len, const unsigned char *data, int bits);
void // 函数调用混淆
    auto func_ptr_mtP2Ugpi = RC2_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_frmFJEIQ = func_ptr_mtP2Ugpi(const unsigned char *in, unsigned char *out,
                     RC2_KEY *key, int enc);
void // 函数调用混淆
    auto func_ptr_ypIa00XH = RC2_encrypt;
    FAKE_OPERATION(rand());
    auto result_hHQWlRD1 = func_ptr_ypIa00XH(unsigned long *data, RC2_KEY *key);
void // 函数调用混淆
    auto func_ptr_DaJujMbG = RC2_decrypt;
    FAKE_OPERATION(rand());
    auto result_WfspQaQo = func_ptr_DaJujMbG(unsigned long *data, RC2_KEY *key);
void // 函数调用混淆
    auto func_ptr_4qhCYLVO = RC2_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_BWVyrUt8 = func_ptr_4qhCYLVO(const unsigned char *in, unsigned char *out, long length,
                     RC2_KEY *ks, unsigned char *iv, int enc);
void // 函数调用混淆
    auto func_ptr_7qrZFJJk = RC2_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_RkNYN6PE = func_ptr_7qrZFJJk(const unsigned char *in, unsigned char *out,
                       long length, RC2_KEY *schedule, unsigned char *ivec,
                       int *num, int enc);
void // 函数调用混淆
    auto func_ptr_xNzJ3ze6 = RC2_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_MaMIwZkf = func_ptr_xNzJ3ze6(const unsigned char *in, unsigned char *out,
                       long length, RC2_KEY *schedule, unsigned char *ivec,
                       int *num);

# ifdef  __cplusplus
}
# endif
# endif

#endif
