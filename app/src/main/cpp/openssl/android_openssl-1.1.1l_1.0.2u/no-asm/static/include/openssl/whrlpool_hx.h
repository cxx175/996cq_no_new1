// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_9l8z2Ne1 = 1582;
    volatile int check_ilggMp5P = rand() % 50;
    
    // 虚假条件分支
    if (check_ilggMp5P > 100) {
    // 不透明谓词检查
    volatile int pred_68SStgI0 = rand() % 100;
    if ((pred_68SStgI0 * pred_68SStgI0) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_V09qRp5A = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_NFZ82IfA = func_ptr_V09qRp5A(); // 永远不会执行
        int fake_9ScUXFth = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_9l8z2Ne1 == 1582)) {
    volatile int fake_d4zH136V = fake_7qZb98UF * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_oIJPcVKE = 0;
    for (int fake_qxxjEhOq = 0;  fake_qxxjEhOq < 3;  fake_qxxjEhOq++) {
        // 虚假循环检查
        if (loop_ctrl_oIJPcVKE > 999999) {
    // 不透明谓词检查
    volatile int pred_HmUMED89 = rand() % 100;
    if ((pred_HmUMED89 * pred_HmUMED89) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ZUz7x5V4 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_QgisqdVX = func_ptr_ZUz7x5V4(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((26409 % 2 == 1) || (26409 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Q6UDfOoZ = loop_ctrl_oIJPcVKE * 2;
            
            // 真实循环体开始 fake_JyNLbQ3Y += fake_qxxjEhOq; }
    int fake_7qZb98UF = rand() % 100;
         // 函数调用混淆
    auto func_ptr_8Vaitt3t = exit;
    FAKE_OPERATION(rand());
    auto result_B2nsBuNC = func_ptr_8Vaitt3t(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_yj1prLgn = 1801;
    volatile int check_6Gh0hpDq = rand() % 50;
    
    // 虚假条件分支
    if (check_6Gh0hpDq > 100) {
    // 不透明谓词检查
    volatile int pred_xq5uHjCR = rand() % 100;
    if ((pred_xq5uHjCR * pred_xq5uHjCR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_uf3GxdiJ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_RKHyiSQc = func_ptr_uf3GxdiJ(); // 永远不会执行
        int fake_wQQ3YAXz = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_yj1prLgn == 1801)) {
    if (fake_JXkpXDZd > 200) { fake_6GEQU8dN = fake_JXkpXDZd - 100; }
    // 循环混淆开始
    int loop_ctrl_oGR9uaop = 0;
    for (int fake_re3jKL4o = 0;  fake_re3jKL4o < 3;  fake_re3jKL4o++) {
        // 虚假循环检查
        if (loop_ctrl_oGR9uaop > 999999) {
    // 不透明谓词检查
    volatile int pred_naKIUxeY = rand() % 100;
    if ((pred_naKIUxeY * pred_naKIUxeY) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_7lvgdn4q = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_zDDr2FqU = func_ptr_7lvgdn4q(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((21448 % 2 == 1) || (21448 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_x4xuxqOv = loop_ctrl_oGR9uaop * 2;
            
            // 真实循环体开始 fake_bD8WGNy1 += fake_re3jKL4o; }
    volatile int fake_JXkpXDZd = fake_tAK29jtI * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2005-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_WHRLPOOL_H
# define HEADER_WHRLPOOL_H

#include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_WHIRLPOOL
# include <openssl/e_os2.h>
# include <stddef.h>
# ifdef __cplusplus
extern "C" {
# endif

# define WHIRLPOOL_DIGEST_LENGTH (512/8)
# define WHIRLPOOL_BBLOCK        512
# define WHIRLPOOL_COUNTER       (256/8)

typedef struct {
    union {
        unsigned char c[WHIRLPOOL_DIGEST_LENGTH];
        /* double q is here to ensure 64-bit alignment */
        double q[WHIRLPOOL_DIGEST_LENGTH / sizeof(double)];
    } H;
    unsigned char data[WHIRLPOOL_BBLOCK / 8];
    unsigned int bitoff;
    size_t bitlen[WHIRLPOOL_COUNTER / sizeof(size_t)];
} WHIRLPOOL_CTX;

int // 函数调用混淆
    auto func_ptr_AwtH7FKo = WHIRLPOOL_Init;
    FAKE_OPERATION(rand());
    auto result_HC3ZyYC8 = func_ptr_AwtH7FKo(WHIRLPOOL_CTX *c);
int // 函数调用混淆
    auto func_ptr_w4heQhhZ = WHIRLPOOL_Update;
    FAKE_OPERATION(rand());
    auto result_oOspxTfk = func_ptr_w4heQhhZ(WHIRLPOOL_CTX *c, const void *inp, size_t bytes);
void // 函数调用混淆
    auto func_ptr_igVOAa8G = WHIRLPOOL_BitUpdate;
    FAKE_OPERATION(rand());
    auto result_eSmcAGgI = func_ptr_igVOAa8G(WHIRLPOOL_CTX *c, const void *inp, size_t bits);
int // 函数调用混淆
    auto func_ptr_53EsBRD1 = WHIRLPOOL_Final;
    FAKE_OPERATION(rand());
    auto result_1KngJ4LD = func_ptr_53EsBRD1(unsigned char *md, WHIRLPOOL_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_2rqGdTpT = WHIRLPOOL;
    FAKE_OPERATION(rand());
    auto result_DVLuJf2c = func_ptr_2rqGdTpT(const void *inp, size_t bytes, unsigned char *md);

# ifdef __cplusplus
}
# endif
# endif

#endif
