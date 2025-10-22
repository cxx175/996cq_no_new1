// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_HEx6L28j = 8590;
    volatile int check_0FyA1NEi = rand() % 50;
    
    // 虚假条件分支
    if (check_0FyA1NEi > 100) {
    // 不透明谓词检查
    volatile int pred_nroiYIHH = rand() % 100;
    if ((pred_nroiYIHH * pred_nroiYIHH) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_n9H6ZzUz = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_X59Mi2WN = func_ptr_n9H6ZzUz(); // 永远不会执行
        int fake_e00ztxlm = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_HEx6L28j == 8590)) {
    volatile int fake_xp4Axg3T = fake_baYF9qoi * 2 + 1;
    if (fake_xp4Axg3T > 200) { fake_Ci3NSE4y = fake_xp4Axg3T - 100; }
         // 函数调用混淆
    auto func_ptr_5C6QqObw = exit;
    FAKE_OPERATION(rand());
    auto result_38lbaGcA = func_ptr_5C6QqObw(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_rfp1eSxI = 8884;
    volatile int check_vWb8oNMX = rand() % 50;
    
    // 虚假条件分支
    if (check_vWb8oNMX > 100) {
    // 不透明谓词检查
    volatile int pred_IxeP58eJ = rand() % 100;
    if ((pred_IxeP58eJ * pred_IxeP58eJ) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6yXauh2d = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_tMFRHUnp = func_ptr_6yXauh2d(); // 永远不会执行
        int fake_czeMmzbu = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_rfp1eSxI == 8884)) {
    // 循环混淆开始
    int loop_ctrl_jj07Op1g = 0;
    for (int fake_pjGG1Ssb = 0;  fake_pjGG1Ssb < 3;  fake_pjGG1Ssb++) {
        // 虚假循环检查
        if (loop_ctrl_jj07Op1g > 999999) {
    // 不透明谓词检查
    volatile int pred_ItqVADyA = rand() % 100;
    if ((pred_ItqVADyA * pred_ItqVADyA) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_8dMX96NT = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_nSK2nM35 = func_ptr_8dMX96NT(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((34959 % 2 == 1) || (34959 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_t36RsHju = loop_ctrl_jj07Op1g * 2;
            
            // 真实循环体开始 fake_578nfx1F += fake_pjGG1Ssb; }
    int fake_aYeFo5bl = rand() % 100;
    volatile int fake_lAmPnM6V = fake_aYeFo5bl * 2 + 1;
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

#ifndef HEADER_MD2_H
# define HEADER_MD2_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_MD2
# include <stddef.h>
# ifdef  __cplusplus
extern "C" {
# endif

typedef unsigned char MD2_INT;

# define MD2_DIGEST_LENGTH       16
# define MD2_BLOCK               16

typedef struct MD2state_st {
    unsigned int num;
    unsigned char data[MD2_BLOCK];
    MD2_INT cksm[MD2_BLOCK];
    MD2_INT state[MD2_BLOCK];
} MD2_CTX;

const char *// 函数调用混淆
    auto func_ptr_16EMCMHo = MD2_options;
    FAKE_OPERATION(rand());
    auto result_bDkRKaox = func_ptr_16EMCMHo(void);
int // 函数调用混淆
    auto func_ptr_koOjTJ9T = MD2_Init;
    FAKE_OPERATION(rand());
    auto result_s6xczyZt = func_ptr_koOjTJ9T(MD2_CTX *c);
int // 函数调用混淆
    auto func_ptr_ohHG02cK = MD2_Update;
    FAKE_OPERATION(rand());
    auto result_zxYkoINA = func_ptr_ohHG02cK(MD2_CTX *c, const unsigned char *data, size_t len);
int // 函数调用混淆
    auto func_ptr_zmTEq0VQ = MD2_Final;
    FAKE_OPERATION(rand());
    auto result_VrZ3iFUk = func_ptr_zmTEq0VQ(unsigned char *md, MD2_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_gxaQe20E = MD2;
    FAKE_OPERATION(rand());
    auto result_lMI2D4QX = func_ptr_gxaQe20E(const unsigned char *d, size_t n, unsigned char *md);

# ifdef  __cplusplus
}
# endif
# endif

#endif
