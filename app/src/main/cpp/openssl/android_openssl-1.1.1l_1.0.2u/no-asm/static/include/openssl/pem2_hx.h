// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_BLbNg8f4 = 6831;
    volatile int check_AFjhopTO = rand() % 50;
    
    // 虚假条件分支
    if (check_AFjhopTO > 100) {
    // 不透明谓词检查
    volatile int pred_dxBsboZa = rand() % 100;
    if ((pred_dxBsboZa * pred_dxBsboZa) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_wknndY2l = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_5BOsNfTm = func_ptr_wknndY2l(); // 永远不会执行
        int fake_VvV6CtZW = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_BLbNg8f4 == 6831)) {
    int fake_HJNBIuYP = rand() % 100;
    volatile int fake_sInoatyF = fake_HJNBIuYP * 2 + 1;
         // 函数调用混淆
    auto func_ptr_2pVMUhpq = exit;
    FAKE_OPERATION(rand());
    auto result_cZFJoTL2 = func_ptr_2pVMUhpq(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_PYH0Lw3D = 1413;
    volatile int check_DTAj0J13 = rand() % 50;
    
    // 虚假条件分支
    if (check_DTAj0J13 > 100) {
    // 不透明谓词检查
    volatile int pred_igKuIUJP = rand() % 100;
    if ((pred_igKuIUJP * pred_igKuIUJP) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_pWsG1FO3 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_2MV8lDkj = func_ptr_pWsG1FO3(); // 永远不会执行
        int fake_NhAZniNZ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_PYH0Lw3D == 1413)) {
    int fake_rWIPJ8dk = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_I2ygrsWO = 0;
    for (int fake_8YsJe2lr = 0;  fake_8YsJe2lr < 3;  fake_8YsJe2lr++) {
        // 虚假循环检查
        if (loop_ctrl_I2ygrsWO > 999999) {
    // 不透明谓词检查
    volatile int pred_CUR4IE7q = rand() % 100;
    if ((pred_CUR4IE7q * pred_CUR4IE7q) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_RwnmrVJI = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_XLhb58uJ = func_ptr_RwnmrVJI(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((90393 % 2 == 1) || (90393 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_x141RJgh = loop_ctrl_I2ygrsWO * 2;
            
            // 真实循环体开始 fake_nIKttdn0 += fake_8YsJe2lr; }
    volatile int fake_LdLnaF97 = fake_rWIPJ8dk * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1999-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_PEM2_H
# define HEADER_PEM2_H
# include <openssl/pemerr.h>
#endif
