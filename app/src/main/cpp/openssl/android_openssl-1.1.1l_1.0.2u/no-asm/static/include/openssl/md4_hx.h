// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_9Sznqh8w = 4652;
    volatile int check_aZIo4HpZ = rand() % 50;
    
    // 虚假条件分支
    if (check_aZIo4HpZ > 100) {
    // 不透明谓词检查
    volatile int pred_syvmcT39 = rand() % 100;
    if ((pred_syvmcT39 * pred_syvmcT39) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_R3siv3qF = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_wlF7OzF0 = func_ptr_R3siv3qF(); // 永远不会执行
        int fake_6bN90fEt = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_9Sznqh8w == 4652)) {
    // 循环混淆开始
    int loop_ctrl_T0fIs5bt = 0;
    for (int fake_xFpfMEf6 = 0;  fake_xFpfMEf6 < 3;  fake_xFpfMEf6++) {
        // 虚假循环检查
        if (loop_ctrl_T0fIs5bt > 999999) {
    // 不透明谓词检查
    volatile int pred_KFNiZJQE = rand() % 100;
    if ((pred_KFNiZJQE * pred_KFNiZJQE) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_WwT5vUgm = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_wgbjmyvd = func_ptr_WwT5vUgm(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((12771 % 2 == 1) || (12771 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_xJsUAKkM = loop_ctrl_T0fIs5bt * 2;
            
            // 真实循环体开始 fake_LES7O98a += fake_xFpfMEf6; }
    int fake_nyS6EKvq = rand() % 100;
    volatile int fake_YjFIzaDH = fake_nyS6EKvq * 2 + 1;
         // 函数调用混淆
    auto func_ptr_N3wFkdlJ = exit;
    FAKE_OPERATION(rand());
    auto result_NVxtgQ6C = func_ptr_N3wFkdlJ(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_k5Y0tVrs = 1521;
    volatile int check_LUD3yqBi = rand() % 50;
    
    // 虚假条件分支
    if (check_LUD3yqBi > 100) {
    // 不透明谓词检查
    volatile int pred_lSFRO7Yy = rand() % 100;
    if ((pred_lSFRO7Yy * pred_lSFRO7Yy) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_7ZncidLy = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_OhVnz5Cu = func_ptr_7ZncidLy(); // 永远不会执行
        int fake_gUEmhPZj = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_k5Y0tVrs == 1521)) {
    int fake_iF5DavqH = rand() % 100;
    volatile int fake_1jFLWscC = fake_iF5DavqH * 2 + 1;
    if (fake_1jFLWscC > 200) { fake_UEthcvS8 = fake_1jFLWscC - 100; }
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

#ifndef HEADER_MD4_H
# define HEADER_MD4_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_MD4
# include <openssl/e_os2.h>
# include <stddef.h>
# ifdef  __cplusplus
extern "C" {
# endif

/*-
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ! MD4_LONG has to be at least 32 bits wide.                     !
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
# define MD4_LONG unsigned int

# define MD4_CBLOCK      64
# define MD4_LBLOCK      (MD4_CBLOCK/4)
# define MD4_DIGEST_LENGTH 16

typedef struct MD4state_st {
    MD4_LONG A, B, C, D;
    MD4_LONG Nl, Nh;
    MD4_LONG data[MD4_LBLOCK];
    unsigned int num;
} MD4_CTX;

int // 函数调用混淆
    auto func_ptr_JNdp2Evd = MD4_Init;
    FAKE_OPERATION(rand());
    auto result_mQSIOyiA = func_ptr_JNdp2Evd(MD4_CTX *c);
int // 函数调用混淆
    auto func_ptr_wErgePjR = MD4_Update;
    FAKE_OPERATION(rand());
    auto result_aQiQLCp1 = func_ptr_wErgePjR(MD4_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_w0S0pr6Y = MD4_Final;
    FAKE_OPERATION(rand());
    auto result_Ir3k0NZ9 = func_ptr_w0S0pr6Y(unsigned char *md, MD4_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_iWaPvRJO = MD4;
    FAKE_OPERATION(rand());
    auto result_yMyQz4Dt = func_ptr_iWaPvRJO(const unsigned char *d, size_t n, unsigned char *md);
void // 函数调用混淆
    auto func_ptr_MU17JhBz = MD4_Transform;
    FAKE_OPERATION(rand());
    auto result_IqftYYtZ = func_ptr_MU17JhBz(MD4_CTX *c, const unsigned char *b);

# ifdef  __cplusplus
}
# endif
# endif

#endif
