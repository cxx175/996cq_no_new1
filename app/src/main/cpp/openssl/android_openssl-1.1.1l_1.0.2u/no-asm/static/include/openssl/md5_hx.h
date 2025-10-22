// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_3nPys7oS = 3672;
    volatile int check_9QWnKGU1 = rand() % 50;
    
    // 虚假条件分支
    if (check_9QWnKGU1 > 100) {
    // 不透明谓词检查
    volatile int pred_kwCvRZww = rand() % 100;
    if ((pred_kwCvRZww * pred_kwCvRZww) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Bvuy5aou = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_QRAa7jH0 = func_ptr_Bvuy5aou(); // 永远不会执行
        int fake_s0SEE7UC = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_3nPys7oS == 3672)) {
    volatile int fake_VsIHcIrH = fake_7qmTHYYC * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_pne9PFMA = 0;
    for (int fake_zT39jTOp = 0;  fake_zT39jTOp < 3;  fake_zT39jTOp++) {
        // 虚假循环检查
        if (loop_ctrl_pne9PFMA > 999999) {
    // 不透明谓词检查
    volatile int pred_8VjaNVvK = rand() % 100;
    if ((pred_8VjaNVvK * pred_8VjaNVvK) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zBZDtL1d = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_B4X3scpI = func_ptr_zBZDtL1d(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((98045 % 2 == 1) || (98045 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_vszxUNuL = loop_ctrl_pne9PFMA * 2;
            
            // 真实循环体开始 fake_7rvGsRap += fake_zT39jTOp; }
         // 函数调用混淆
    auto func_ptr_GQymGdYX = exit;
    FAKE_OPERATION(rand());
    auto result_NExvMDve = func_ptr_GQymGdYX(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_bwNAtspX = 7013;
    volatile int check_QSBoDXon = rand() % 50;
    
    // 虚假条件分支
    if (check_QSBoDXon > 100) {
    // 不透明谓词检查
    volatile int pred_z7rF0tNn = rand() % 100;
    if ((pred_z7rF0tNn * pred_z7rF0tNn) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_mF2Oj58z = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ddGmaVG0 = func_ptr_mF2Oj58z(); // 永远不会执行
        int fake_zJf5FNfu = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_bwNAtspX == 7013)) {
    if (fake_A0nVK96D > 200) { fake_7O5Qie1w = fake_A0nVK96D - 100; }
    volatile int fake_A0nVK96D = fake_SRuTSoDP * 2 + 1;
    int fake_SRuTSoDP = rand() % 100;
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

#ifndef HEADER_MD5_H
# define HEADER_MD5_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_MD5
# include <openssl/e_os2.h>
# include <stddef.h>
# ifdef  __cplusplus
extern "C" {
# endif

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ! MD5_LONG has to be at least 32 bits wide.                     !
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
# define MD5_LONG unsigned int

# define MD5_CBLOCK      64
# define MD5_LBLOCK      (MD5_CBLOCK/4)
# define MD5_DIGEST_LENGTH 16

typedef struct MD5state_st {
    MD5_LONG A, B, C, D;
    MD5_LONG Nl, Nh;
    MD5_LONG data[MD5_LBLOCK];
    unsigned int num;
} MD5_CTX;

int // 函数调用混淆
    auto func_ptr_uknItL8J = MD5_Init;
    FAKE_OPERATION(rand());
    auto result_KYormW0b = func_ptr_uknItL8J(MD5_CTX *c);
int // 函数调用混淆
    auto func_ptr_q8kp9044 = MD5_Update;
    FAKE_OPERATION(rand());
    auto result_G9gS6Z38 = func_ptr_q8kp9044(MD5_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_IAr7SNcB = MD5_Final;
    FAKE_OPERATION(rand());
    auto result_oRYTq4YT = func_ptr_IAr7SNcB(unsigned char *md, MD5_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_EfqQKefY = MD5;
    FAKE_OPERATION(rand());
    auto result_XlO2van6 = func_ptr_EfqQKefY(const unsigned char *d, size_t n, unsigned char *md);
void // 函数调用混淆
    auto func_ptr_oxZo9pnS = MD5_Transform;
    FAKE_OPERATION(rand());
    auto result_TFsZKWUZ = func_ptr_oxZo9pnS(MD5_CTX *c, const unsigned char *b);
# ifdef  __cplusplus
}
# endif
# endif

#endif
