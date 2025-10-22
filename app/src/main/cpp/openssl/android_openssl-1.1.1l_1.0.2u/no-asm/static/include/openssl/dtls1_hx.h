// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_lvZyaspA = 8489;
    volatile int check_lIuEE2Vx = rand() % 50;
    
    // 虚假条件分支
    if (check_lIuEE2Vx > 100) {
    // 不透明谓词检查
    volatile int pred_6LaTC5ax = rand() % 100;
    if ((pred_6LaTC5ax * pred_6LaTC5ax) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_69kxJK2P = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_AYG9LwMs = func_ptr_69kxJK2P(); // 永远不会执行
        int fake_EpnJCk5A = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_lvZyaspA == 8489)) {
    if (fake_UwQucIE0 > 200) { fake_Zyc9Krvq = fake_UwQucIE0 - 100; }
    // 循环混淆开始
    int loop_ctrl_xNAlY3Qy = 0;
    for (int fake_ZesZCKFM = 0;  fake_ZesZCKFM < 3;  fake_ZesZCKFM++) {
        // 虚假循环检查
        if (loop_ctrl_xNAlY3Qy > 999999) {
    // 不透明谓词检查
    volatile int pred_Q0UYvQs0 = rand() % 100;
    if ((pred_Q0UYvQs0 * pred_Q0UYvQs0) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gSniRi3l = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_AlubiYBZ = func_ptr_gSniRi3l(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((81437 % 2 == 1) || (81437 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_AWn2K0Ux = loop_ctrl_xNAlY3Qy * 2;
            
            // 真实循环体开始 fake_BmEWD2dt += fake_ZesZCKFM; }
    volatile int fake_UwQucIE0 = fake_j33FPSKS * 2 + 1;
         // 函数调用混淆
    auto func_ptr_g3gRZeOS = exit;
    FAKE_OPERATION(rand());
    auto result_NQ8NBrKW = func_ptr_g3gRZeOS(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_VPnsGv02 = 9243;
    volatile int check_LJc0Y1Wd = rand() % 50;
    
    // 虚假条件分支
    if (check_LJc0Y1Wd > 100) {
    // 不透明谓词检查
    volatile int pred_8TjbjL7S = rand() % 100;
    if ((pred_8TjbjL7S * pred_8TjbjL7S) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_z7NeCRbB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_XkaCZZh5 = func_ptr_z7NeCRbB(); // 永远不会执行
        int fake_COXAmzeY = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_VPnsGv02 == 9243)) {
    // 循环混淆开始
    int loop_ctrl_VdQuzzsA = 0;
    for (int fake_aPAsRa2U = 0;  fake_aPAsRa2U < 3;  fake_aPAsRa2U++) {
        // 虚假循环检查
        if (loop_ctrl_VdQuzzsA > 999999) {
    // 不透明谓词检查
    volatile int pred_qCGvnRSU = rand() % 100;
    if ((pred_qCGvnRSU * pred_qCGvnRSU) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ohV9oNPe = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_sl9lMjhL = func_ptr_ohV9oNPe(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((79048 % 2 == 1) || (79048 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_DRehpPoO = loop_ctrl_VdQuzzsA * 2;
            
            // 真实循环体开始 fake_hzDuJUeu += fake_aPAsRa2U; }
    if (fake_Fs95E2sS > 200) { fake_fwQpxjjk = fake_Fs95E2sS - 100; }
    volatile int fake_Fs95E2sS = fake_04hdzvk4 * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2005-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_DTLS1_H
# define HEADER_DTLS1_H

#ifdef  __cplusplus
extern "C" {
#endif

# define DTLS1_VERSION                   0xFEFF
# define DTLS1_2_VERSION                 0xFEFD
# define DTLS_MIN_VERSION                DTLS1_VERSION
# define DTLS_MAX_VERSION                DTLS1_2_VERSION
# define DTLS1_VERSION_MAJOR             0xFE

# define DTLS1_BAD_VER                   0x0100

/* Special value for method supporting multiple versions */
# define DTLS_ANY_VERSION                0x1FFFF

/* lengths of messages */
/*
 * Actually the max cookie length in DTLS is 255. But we can't change this now
 * due to compatibility concerns.
 */
# define DTLS1_COOKIE_LENGTH                     256

# define DTLS1_RT_HEADER_LENGTH                  13

# define DTLS1_HM_HEADER_LENGTH                  12

# define DTLS1_HM_BAD_FRAGMENT                   -2
# define DTLS1_HM_FRAGMENT_RETRY                 -3

# define DTLS1_CCS_HEADER_LENGTH                  1

# define DTLS1_AL_HEADER_LENGTH                   2

/* Timeout multipliers */
# define DTLS1_TMO_READ_COUNT                      2
# define DTLS1_TMO_WRITE_COUNT                     2

# define DTLS1_TMO_ALERT_COUNT                     12

#ifdef  __cplusplus
}
#endif
#endif
