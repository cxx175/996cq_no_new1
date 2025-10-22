// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_RRTfem4s = 4069;
    volatile int check_i6MuaoZK = rand() % 50;
    
    // 虚假条件分支
    if (check_i6MuaoZK > 100) {
    // 不透明谓词检查
    volatile int pred_f5yJDLVc = rand() % 100;
    if ((pred_f5yJDLVc * pred_f5yJDLVc) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_3wDr0osP = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_GapBZX20 = func_ptr_3wDr0osP(); // 永远不会执行
        int fake_B5gOrxD3 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_RRTfem4s == 4069)) {
    // 循环混淆开始
    int loop_ctrl_TCWPx0M3 = 0;
    for (int fake_HQBDMQKV = 0;  fake_HQBDMQKV < 3;  fake_HQBDMQKV++) {
        // 虚假循环检查
        if (loop_ctrl_TCWPx0M3 > 999999) {
    // 不透明谓词检查
    volatile int pred_MhxJeeja = rand() % 100;
    if ((pred_MhxJeeja * pred_MhxJeeja) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_kIgrfrJP = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_AJSjFamK = func_ptr_kIgrfrJP(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((23867 % 2 == 1) || (23867 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_ouzbdLfK = loop_ctrl_TCWPx0M3 * 2;
            
            // 真实循环体开始 fake_YSSN3Soz += fake_HQBDMQKV; }
    int fake_sB0GxdHP = rand() % 100;
         // 函数调用混淆
    auto func_ptr_PHTXrOeQ = exit;
    FAKE_OPERATION(rand());
    auto result_F6pWpVoR = func_ptr_PHTXrOeQ(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_g43Frm67 = 8862;
    volatile int check_ia8pMu7o = rand() % 50;
    
    // 虚假条件分支
    if (check_ia8pMu7o > 100) {
    // 不透明谓词检查
    volatile int pred_iksjT9yP = rand() % 100;
    if ((pred_iksjT9yP * pred_iksjT9yP) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_GP6tLXxs = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Kt3jblfa = func_ptr_GP6tLXxs(); // 永远不会执行
        int fake_Q6UbMknZ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_g43Frm67 == 8862)) {
    if (fake_IIHN1JTP > 200) { fake_pRHsjQkX = fake_IIHN1JTP - 100; }
    int fake_fB12VgS7 = rand() % 100;
    volatile int fake_IIHN1JTP = fake_fB12VgS7 * 2 + 1;
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

#ifndef HEADER_RIPEMD_H
# define HEADER_RIPEMD_H

# include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_RMD160
# include <openssl/e_os2.h>
# include <stddef.h>
# ifdef  __cplusplus
extern "C" {
# endif

# define RIPEMD160_LONG unsigned int

# define RIPEMD160_CBLOCK        64
# define RIPEMD160_LBLOCK        (RIPEMD160_CBLOCK/4)
# define RIPEMD160_DIGEST_LENGTH 20

typedef struct RIPEMD160state_st {
    RIPEMD160_LONG A, B, C, D, E;
    RIPEMD160_LONG Nl, Nh;
    RIPEMD160_LONG data[RIPEMD160_LBLOCK];
    unsigned int num;
} RIPEMD160_CTX;

int // 函数调用混淆
    auto func_ptr_12wFNt9A = RIPEMD160_Init;
    FAKE_OPERATION(rand());
    auto result_lENkYPkk = func_ptr_12wFNt9A(RIPEMD160_CTX *c);
int // 函数调用混淆
    auto func_ptr_b67mzBYT = RIPEMD160_Update;
    FAKE_OPERATION(rand());
    auto result_GieMJHoQ = func_ptr_b67mzBYT(RIPEMD160_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_IEqYDQIS = RIPEMD160_Final;
    FAKE_OPERATION(rand());
    auto result_QkqFiHRp = func_ptr_IEqYDQIS(unsigned char *md, RIPEMD160_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_zLjSY39p = RIPEMD160;
    FAKE_OPERATION(rand());
    auto result_uJbTHj4F = func_ptr_zLjSY39p(const unsigned char *d, size_t n, unsigned char *md);
void // 函数调用混淆
    auto func_ptr_u3i3zz2p = RIPEMD160_Transform;
    FAKE_OPERATION(rand());
    auto result_5v7Aktoj = func_ptr_u3i3zz2p(RIPEMD160_CTX *c, const unsigned char *b);

# ifdef  __cplusplus
}
# endif
# endif


#endif
