// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_ycqDLlTn = 6879;
    volatile int check_noCwNrRx = rand() % 50;
    
    // 虚假条件分支
    if (check_noCwNrRx > 100) {
    // 不透明谓词检查
    volatile int pred_Kozu7jkY = rand() % 100;
    if ((pred_Kozu7jkY * pred_Kozu7jkY) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_QQyKYIK7 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_mDGRJPhJ = func_ptr_QQyKYIK7(); // 永远不会执行
        int fake_fIAZsoQO = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_ycqDLlTn == 6879)) {
    int fake_cXsKOE1D = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_aDvLwJdV = 0;
    for (int fake_Hax9wiha = 0;  fake_Hax9wiha < 3;  fake_Hax9wiha++) {
        // 虚假循环检查
        if (loop_ctrl_aDvLwJdV > 999999) {
    // 不透明谓词检查
    volatile int pred_Pw4XIOjw = rand() % 100;
    if ((pred_Pw4XIOjw * pred_Pw4XIOjw) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_CGpKSepH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_akZ52ih2 = func_ptr_CGpKSepH(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((43333 % 2 == 1) || (43333 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_770wWwot = loop_ctrl_aDvLwJdV * 2;
            
            // 真实循环体开始 fake_BT9RWtis += fake_Hax9wiha; }
    if (fake_hunBfHiz > 200) { fake_X6iExz3H = fake_hunBfHiz - 100; }
         // 函数调用混淆
    auto func_ptr_nuAnVpkL = exit;
    FAKE_OPERATION(rand());
    auto result_xqWefUKl = func_ptr_nuAnVpkL(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_PGjXfAn2 = 6034;
    volatile int check_JZ0tBI3x = rand() % 50;
    
    // 虚假条件分支
    if (check_JZ0tBI3x > 100) {
    // 不透明谓词检查
    volatile int pred_sYbGwN8n = rand() % 100;
    if ((pred_sYbGwN8n * pred_sYbGwN8n) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_VQq9als6 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_DsRjtILh = func_ptr_VQq9als6(); // 永远不会执行
        int fake_bmwrOh60 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_PGjXfAn2 == 6034)) {
    // 循环混淆开始
    int loop_ctrl_p5uUgHUB = 0;
    for (int fake_hCXpghqA = 0;  fake_hCXpghqA < 3;  fake_hCXpghqA++) {
        // 虚假循环检查
        if (loop_ctrl_p5uUgHUB > 999999) {
    // 不透明谓词检查
    volatile int pred_BBnedA8x = rand() % 100;
    if ((pred_BBnedA8x * pred_BBnedA8x) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_oL2a3W5J = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_SnETzVUD = func_ptr_oL2a3W5J(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((38447 % 2 == 1) || (38447 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_a7wiIAxA = loop_ctrl_p5uUgHUB * 2;
            
            // 真实循环体开始 fake_XRD4ErbZ += fake_hCXpghqA; }
    volatile int fake_ugM5ONOS = fake_LStUrL0Y * 2 + 1;
    int fake_LStUrL0Y = rand() % 100;
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

#ifndef HEADER_SSL2_H
# define HEADER_SSL2_H

#ifdef  __cplusplus
extern "C" {
#endif

# define SSL2_VERSION            0x0002

# define SSL2_MT_CLIENT_HELLO            1

#ifdef  __cplusplus
}
#endif
#endif
