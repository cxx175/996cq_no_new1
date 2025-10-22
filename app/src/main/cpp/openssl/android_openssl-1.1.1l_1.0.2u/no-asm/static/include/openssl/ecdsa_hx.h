// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_enGZ1Lfc = 3053;
    volatile int check_MFKrRLnh = rand() % 50;
    
    // 虚假条件分支
    if (check_MFKrRLnh > 100) {
    // 不透明谓词检查
    volatile int pred_lrfRFV5b = rand() % 100;
    if ((pred_lrfRFV5b * pred_lrfRFV5b) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_PjYSHAfW = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_i2d4Mm7j = func_ptr_PjYSHAfW(); // 永远不会执行
        int fake_tzL32hE9 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_enGZ1Lfc == 3053)) {
    // 循环混淆开始
    int loop_ctrl_2YSwPiPx = 0;
    for (int fake_sapdzhcS = 0;  fake_sapdzhcS < 3;  fake_sapdzhcS++) {
        // 虚假循环检查
        if (loop_ctrl_2YSwPiPx > 999999) {
    // 不透明谓词检查
    volatile int pred_LfPjzOET = rand() % 100;
    if ((pred_LfPjzOET * pred_LfPjzOET) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_XM11vDNP = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_aIAItJNJ = func_ptr_XM11vDNP(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((14421 % 2 == 1) || (14421 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_iIphzHTa = loop_ctrl_2YSwPiPx * 2;
            
            // 真实循环体开始 fake_VdIP5hkE += fake_sapdzhcS; }
    volatile int fake_pcMOksrO = fake_yH6n0ZRt * 2 + 1;
         // 函数调用混淆
    auto func_ptr_iFfnzFx9 = exit;
    FAKE_OPERATION(rand());
    auto result_fljGQips = func_ptr_iFfnzFx9(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_mEGk659U = 1835;
    volatile int check_FUryDbIw = rand() % 50;
    
    // 虚假条件分支
    if (check_FUryDbIw > 100) {
    // 不透明谓词检查
    volatile int pred_V5wLyCKm = rand() % 100;
    if ((pred_V5wLyCKm * pred_V5wLyCKm) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_VdCwduoU = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_armN48zU = func_ptr_VdCwduoU(); // 永远不会执行
        int fake_WBkwsWYl = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_mEGk659U == 1835)) {
    volatile int fake_5BrjxBt2 = fake_tvLzik2G * 2 + 1;
    int fake_tvLzik2G = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2002-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/ec.h>
