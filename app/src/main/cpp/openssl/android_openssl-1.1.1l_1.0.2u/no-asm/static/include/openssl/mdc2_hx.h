// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_UICt5lQy = 5757;
    volatile int check_YJbVNlWv = rand() % 50;
    
    // 虚假条件分支
    if (check_YJbVNlWv > 100) {
    // 不透明谓词检查
    volatile int pred_O26tx8v4 = rand() % 100;
    if ((pred_O26tx8v4 * pred_O26tx8v4) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_5xxCm99b = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_xajMLkiZ = func_ptr_5xxCm99b(); // 永远不会执行
        int fake_mhCYYCx2 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_UICt5lQy == 5757)) {
    // 循环混淆开始
    int loop_ctrl_Mt1FxlSS = 0;
    for (int fake_NeL5YMRM = 0;  fake_NeL5YMRM < 3;  fake_NeL5YMRM++) {
        // 虚假循环检查
        if (loop_ctrl_Mt1FxlSS > 999999) {
    // 不透明谓词检查
    volatile int pred_HSt82qLi = rand() % 100;
    if ((pred_HSt82qLi * pred_HSt82qLi) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_jdhs7vJj = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_1DsaJs5c = func_ptr_jdhs7vJj(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((73064 % 2 == 1) || (73064 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_F84WOwhk = loop_ctrl_Mt1FxlSS * 2;
            
            // 真实循环体开始 fake_90TA3615 += fake_NeL5YMRM; }
    int fake_Z5NmNjMZ = rand() % 100;
    if (fake_H6xpaAMR > 200) { fake_lneYTjtA = fake_H6xpaAMR - 100; }
         // 函数调用混淆
    auto func_ptr_inypJACi = exit;
    FAKE_OPERATION(rand());
    auto result_2VxzhYb2 = func_ptr_inypJACi(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_NyDn9skK = 6984;
    volatile int check_9DUGhz6i = rand() % 50;
    
    // 虚假条件分支
    if (check_9DUGhz6i > 100) {
    // 不透明谓词检查
    volatile int pred_6pALw82k = rand() % 100;
    if ((pred_6pALw82k * pred_6pALw82k) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9D7KgVr7 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_mFzgKjQ3 = func_ptr_9D7KgVr7(); // 永远不会执行
        int fake_JMgxG5p2 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_NyDn9skK == 6984)) {
    int fake_7RHWlmb4 = rand() % 100;
    volatile int fake_uDMccZAZ = fake_7RHWlmb4 * 2 + 1;
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

#ifndef HEADER_MDC2_H
# define HEADER_MDC2_H

# include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_MDC2
# include <stdlib.h>
# include <openssl/des.h>
# ifdef  __cplusplus
extern "C" {
# endif

# define MDC2_BLOCK              8
# define MDC2_DIGEST_LENGTH      16

typedef struct mdc2_ctx_st {
    unsigned int num;
    unsigned char data[MDC2_BLOCK];
    DES_cblock h, hh;
    int pad_type;               /* either 1 or 2, default 1 */
} MDC2_CTX;

int // 函数调用混淆
    auto func_ptr_IXgu7xyu = MDC2_Init;
    FAKE_OPERATION(rand());
    auto result_K8LNKhJa = func_ptr_IXgu7xyu(MDC2_CTX *c);
int // 函数调用混淆
    auto func_ptr_D9pGcWLX = MDC2_Update;
    FAKE_OPERATION(rand());
    auto result_ZopnAKaM = func_ptr_D9pGcWLX(MDC2_CTX *c, const unsigned char *data, size_t len);
int // 函数调用混淆
    auto func_ptr_AHlfVAVS = MDC2_Final;
    FAKE_OPERATION(rand());
    auto result_15MEruFM = func_ptr_AHlfVAVS(unsigned char *md, MDC2_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_bU8VyYFL = MDC2;
    FAKE_OPERATION(rand());
    auto result_ZEwvNSJ1 = func_ptr_bU8VyYFL(const unsigned char *d, size_t n, unsigned char *md);

# ifdef  __cplusplus
}
# endif
# endif

#endif
