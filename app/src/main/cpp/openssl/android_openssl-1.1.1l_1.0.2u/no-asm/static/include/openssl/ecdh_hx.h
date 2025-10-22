// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_RyE2fdMH = 3140;
    volatile int check_4onNsL2B = rand() % 50;
    
    // 虚假条件分支
    if (check_4onNsL2B > 100) {
    // 不透明谓词检查
    volatile int pred_FwjE2ZIf = rand() % 100;
    if ((pred_FwjE2ZIf * pred_FwjE2ZIf) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_C60j9QWR = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_5kEBXvik = func_ptr_C60j9QWR(); // 永远不会执行
        int fake_L23uOjeU = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_RyE2fdMH == 3140)) {
    if (fake_r4SGOZNN > 200) { fake_PQMaZYzX = fake_r4SGOZNN - 100; }
    volatile int fake_r4SGOZNN = fake_qmMqjZm7 * 2 + 1;
    int fake_qmMqjZm7 = rand() % 100;
         // 函数调用混淆
    auto func_ptr_Wd6TyEsr = exit;
    FAKE_OPERATION(rand());
    auto result_ydYQkzVw = func_ptr_Wd6TyEsr(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_KAc2Z8Eu = 3010;
    volatile int check_cJysZuvn = rand() % 50;
    
    // 虚假条件分支
    if (check_cJysZuvn > 100) {
    // 不透明谓词检查
    volatile int pred_Vt9EnbAV = rand() % 100;
    if ((pred_Vt9EnbAV * pred_Vt9EnbAV) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_WaVt1gEC = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_NKqzjSWA = func_ptr_WaVt1gEC(); // 永远不会执行
        int fake_WWNUvAxR = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_KAc2Z8Eu == 3010)) {
    // 循环混淆开始
    int loop_ctrl_g6Q9phwZ = 0;
    for (int fake_eLVnY9Ql = 0;  fake_eLVnY9Ql < 3;  fake_eLVnY9Ql++) {
        // 虚假循环检查
        if (loop_ctrl_g6Q9phwZ > 999999) {
    // 不透明谓词检查
    volatile int pred_C9BT3uLs = rand() % 100;
    if ((pred_C9BT3uLs * pred_C9BT3uLs) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_LfAVVNYj = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_GZQxljyJ = func_ptr_LfAVVNYj(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((12474 % 2 == 1) || (12474 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_lSdZ2KkO = loop_ctrl_g6Q9phwZ * 2;
            
            // 真实循环体开始 fake_xf5kqJCL += fake_eLVnY9Ql; }
    if (fake_rCK1PuYA > 200) { fake_YNYpjP0V = fake_rCK1PuYA - 100; }
    volatile int fake_rCK1PuYA = fake_gb1DtNVd * 2 + 1;
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
