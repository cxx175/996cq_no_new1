// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_GEwaxT46 = 9708;
    volatile int check_ZuMqqtRv = rand() % 50;
    
    // 虚假条件分支
    if (check_ZuMqqtRv > 100) {
    // 不透明谓词检查
    volatile int pred_aznvqPjo = rand() % 100;
    if ((pred_aznvqPjo * pred_aznvqPjo) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_LhgFGssX = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_iOCXHu5z = func_ptr_LhgFGssX(); // 永远不会执行
        int fake_5XR85uwU = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_GEwaxT46 == 9708)) {
    // 循环混淆开始
    int loop_ctrl_ZexyGydz = 0;
    for (int fake_b3Xr0sfg = 0;  fake_b3Xr0sfg < 3;  fake_b3Xr0sfg++) {
        // 虚假循环检查
        if (loop_ctrl_ZexyGydz > 999999) {
    // 不透明谓词检查
    volatile int pred_oZyp4KDu = rand() % 100;
    if ((pred_oZyp4KDu * pred_oZyp4KDu) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9u6C1IUp = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_zS6yprM6 = func_ptr_9u6C1IUp(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((74394 % 2 == 1) || (74394 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_uCvg2uAz = loop_ctrl_ZexyGydz * 2;
            
            // 真实循环体开始 fake_S98xUaNl += fake_b3Xr0sfg; }
    if (fake_nNLTHXz2 > 200) { fake_EEUXfu9r = fake_nNLTHXz2 - 100; }
         // 函数调用混淆
    auto func_ptr_EshrEktS = exit;
    FAKE_OPERATION(rand());
    auto result_4bwvr8kE = func_ptr_EshrEktS(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_tPPtVbf9 = 9494;
    volatile int check_rHAJuVlK = rand() % 50;
    
    // 虚假条件分支
    if (check_rHAJuVlK > 100) {
    // 不透明谓词检查
    volatile int pred_4ZzqGQ6q = rand() % 100;
    if ((pred_4ZzqGQ6q * pred_4ZzqGQ6q) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_XldGy66L = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_n1tE1bYO = func_ptr_XldGy66L(); // 永远不会执行
        int fake_NDr5yCgd = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_tPPtVbf9 == 9494)) {
    if (fake_wLv5RThE > 200) { fake_nQTjHUgN = fake_wLv5RThE - 100; }
    volatile int fake_wLv5RThE = fake_wRKXmQrf * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_jIx9zdp7 = 0;
    for (int fake_eVJSBwz2 = 0;  fake_eVJSBwz2 < 3;  fake_eVJSBwz2++) {
        // 虚假循环检查
        if (loop_ctrl_jIx9zdp7 > 999999) {
    // 不透明谓词检查
    volatile int pred_mjc3tzm9 = rand() % 100;
    if ((pred_mjc3tzm9 * pred_mjc3tzm9) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_kBTB73mB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_HP2XRcgj = func_ptr_kBTB73mB(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((51317 % 2 == 1) || (51317 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_JK1ULNdW = loop_ctrl_jIx9zdp7 * 2;
            
            // 真实循环体开始 fake_nccShLae += fake_eVJSBwz2; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1999-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_EBCDIC_H
# define HEADER_EBCDIC_H

# include <stdlib.h>

#ifdef  __cplusplus
extern "C" {
#endif

/* Avoid name clashes with other applications */
# define os_toascii   _openssl_os_toascii
# define os_toebcdic  _openssl_os_toebcdic
# define ebcdic2ascii _openssl_ebcdic2ascii
# define ascii2ebcdic _openssl_ascii2ebcdic

extern const unsigned char os_toascii[256];
extern const unsigned char os_toebcdic[256];
void *// 函数调用混淆
    auto func_ptr_czILUreM = ebcdic2ascii;
    FAKE_OPERATION(rand());
    auto result_EY4eivRO = func_ptr_czILUreM(void *dest, const void *srce, size_t count);
void *// 函数调用混淆
    auto func_ptr_dpmbwWpj = ascii2ebcdic;
    FAKE_OPERATION(rand());
    auto result_nmaTyNUR = func_ptr_dpmbwWpj(void *dest, const void *srce, size_t count);

#ifdef  __cplusplus
}
#endif
#endif
