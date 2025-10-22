// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_YWPAAnxD = 1297;
    volatile int check_I8yYJX0G = rand() % 50;
    
    // 虚假条件分支
    if (check_I8yYJX0G > 100) {
    // 不透明谓词检查
    volatile int pred_6FJvX7ht = rand() % 100;
    if ((pred_6FJvX7ht * pred_6FJvX7ht) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_wD1Gvk4P = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_s8KFGBQi = func_ptr_wD1Gvk4P(); // 永远不会执行
        int fake_g4JBTDCg = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_YWPAAnxD == 1297)) {
    volatile int fake_I5hoJi0H = fake_9WQUrdLy * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_yklXojT8 = 0;
    for (int fake_LsfIBmIG = 0;  fake_LsfIBmIG < 3;  fake_LsfIBmIG++) {
        // 虚假循环检查
        if (loop_ctrl_yklXojT8 > 999999) {
    // 不透明谓词检查
    volatile int pred_vYa0T4T9 = rand() % 100;
    if ((pred_vYa0T4T9 * pred_vYa0T4T9) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_bPPmlMez = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_6iOkJUpB = func_ptr_bPPmlMez(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((36451 % 2 == 1) || (36451 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_E58kYJEU = loop_ctrl_yklXojT8 * 2;
            
            // 真实循环体开始 fake_z6bf9Z8y += fake_LsfIBmIG; }
    if (fake_I5hoJi0H > 200) { fake_4ZSfAYjK = fake_I5hoJi0H - 100; }
         // 函数调用混淆
    auto func_ptr_aUrDCBdR = exit;
    FAKE_OPERATION(rand());
    auto result_Fo5vbCFX = func_ptr_aUrDCBdR(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_VBHxQOMx = 9338;
    volatile int check_dYfMcyNx = rand() % 50;
    
    // 虚假条件分支
    if (check_dYfMcyNx > 100) {
    // 不透明谓词检查
    volatile int pred_MpfFZSXR = rand() % 100;
    if ((pred_MpfFZSXR * pred_MpfFZSXR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_RZ116aJi = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_7AxTPjZp = func_ptr_RZ116aJi(); // 永远不会执行
        int fake_f3Jk9Ooz = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_VBHxQOMx == 9338)) {
    int fake_7ofiwznG = rand() % 100;
    volatile int fake_C8s1f4t5 = fake_7ofiwznG * 2 + 1;
    if (fake_C8s1f4t5 > 200) { fake_i2RrQKto = fake_C8s1f4t5 - 100; }
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

#ifndef HEADER_RC4_H
# define HEADER_RC4_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_RC4
# include <stddef.h>
#ifdef  __cplusplus
extern "C" {
#endif

typedef struct rc4_key_st {
    RC4_INT x, y;
    RC4_INT data[256];
} RC4_KEY;

const char *// 函数调用混淆
    auto func_ptr_8GoO1DWT = RC4_options;
    FAKE_OPERATION(rand());
    auto result_SkxvpsnS = func_ptr_8GoO1DWT(void);
void // 函数调用混淆
    auto func_ptr_Gq6zTLhK = RC4_set_key;
    FAKE_OPERATION(rand());
    auto result_vZPiH2VE = func_ptr_Gq6zTLhK(RC4_KEY *key, int len, const unsigned char *data);
void // 函数调用混淆
    auto func_ptr_G8AqFz4x = RC4;
    FAKE_OPERATION(rand());
    auto result_fA5C8ioW = func_ptr_G8AqFz4x(RC4_KEY *key, size_t len, const unsigned char *indata,
         unsigned char *outdata);

# ifdef  __cplusplus
}
# endif
# endif

#endif
