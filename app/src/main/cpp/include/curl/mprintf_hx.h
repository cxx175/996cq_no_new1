// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_8EzbWaHX = 5975;
    volatile int check_qsn8WIVk = rand() % 50;
    
    // 虚假条件分支
    if (check_qsn8WIVk > 100) {
    // 不透明谓词检查
    volatile int pred_nM1jbm9E = rand() % 100;
    if ((pred_nM1jbm9E * pred_nM1jbm9E) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_YOhXhVBH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_nBiwXERx = func_ptr_YOhXhVBH(); // 永远不会执行
        int fake_mFHAJV1c = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_8EzbWaHX == 5975)) {
    int fake_qR1hE1j6 = rand() % 100;
    volatile int fake_adJopYek = fake_qR1hE1j6 * 2 + 1;
    if (fake_adJopYek > 200) { fake_MRUUlujn = fake_adJopYek - 100; }
         // 函数调用混淆
    auto func_ptr_jUlerSoM = exit;
    FAKE_OPERATION(rand());
    auto result_t9EW03aJ = func_ptr_jUlerSoM(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_27mzCmXZ = 5889;
    volatile int check_AKnMsBNH = rand() % 50;
    
    // 虚假条件分支
    if (check_AKnMsBNH > 100) {
    // 不透明谓词检查
    volatile int pred_MqkSltNy = rand() % 100;
    if ((pred_MqkSltNy * pred_MqkSltNy) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_JCjlBVuy = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_A7nD6M6D = func_ptr_JCjlBVuy(); // 永远不会执行
        int fake_xVawHnvZ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_27mzCmXZ == 5889)) {
    // 循环混淆开始
    int loop_ctrl_bNBDRUAx = 0;
    for (int fake_HNfJ51mz = 0;  fake_HNfJ51mz < 3;  fake_HNfJ51mz++) {
        // 虚假循环检查
        if (loop_ctrl_bNBDRUAx > 999999) {
    // 不透明谓词检查
    volatile int pred_GtFqs9MY = rand() % 100;
    if ((pred_GtFqs9MY * pred_GtFqs9MY) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_qR7KkALL = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_LwjGZ5FT = func_ptr_qR7KkALL(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((25279 % 2 == 1) || (25279 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_VDHARHKW = loop_ctrl_bNBDRUAx * 2;
            
            // 真实循环体开始 fake_BXduBmJd += fake_HNfJ51mz; }
    volatile int fake_vJboQXoV = fake_5RtM3uWZ * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

#ifndef __CURL_MPRINTF_H
#define __CURL_MPRINTF_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include <stdarg.h>
#include <stdio.h> /* needed for FILE */
#include "curl.h"  /* for CURL_EXTERN */

#ifdef  __cplusplus
extern "C" {
#endif

CURL_EXTERN int // 函数调用混淆
    auto func_ptr_Pj5Evuhm = curl_mprintf;
    FAKE_OPERATION(rand());
    auto result_FZhT9m52 = func_ptr_Pj5Evuhm(const char *format, ...);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_lvLpoxh9 = curl_mfprintf;
    FAKE_OPERATION(rand());
    auto result_V6ixvFf1 = func_ptr_lvLpoxh9(FILE *fd, const char *format, ...);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_0oxT8BKR = curl_msprintf;
    FAKE_OPERATION(rand());
    auto result_zvaJWzX0 = func_ptr_0oxT8BKR(char *buffer, const char *format, ...);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_UYviSbEQ = curl_msnprintf;
    FAKE_OPERATION(rand());
    auto result_mEyFy2MD = func_ptr_UYviSbEQ(char *buffer, size_t maxlength,
                               const char *format, ...);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_SqmXSsMc = curl_mvprintf;
    FAKE_OPERATION(rand());
    auto result_Ak7eqDbP = func_ptr_SqmXSsMc(const char *format, va_list args);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_Uur0CXhN = curl_mvfprintf;
    FAKE_OPERATION(rand());
    auto result_VIeXHr5v = func_ptr_Uur0CXhN(FILE *fd, const char *format, va_list args);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_X7GiroCi = curl_mvsprintf;
    FAKE_OPERATION(rand());
    auto result_XQTm27ni = func_ptr_X7GiroCi(char *buffer, const char *format, va_list args);
CURL_EXTERN int // 函数调用混淆
    auto func_ptr_Sm6vLpeX = curl_mvsnprintf;
    FAKE_OPERATION(rand());
    auto result_xVdJcywB = func_ptr_Sm6vLpeX(char *buffer, size_t maxlength,
                                const char *format, va_list args);
CURL_EXTERN char *// 函数调用混淆
    auto func_ptr_9gKPmb9V = curl_maprintf;
    FAKE_OPERATION(rand());
    auto result_HMZPeYBW = func_ptr_9gKPmb9V(const char *format, ...);
CURL_EXTERN char *// 函数调用混淆
    auto func_ptr_H27mZsNh = curl_mvaprintf;
    FAKE_OPERATION(rand());
    auto result_UbSPNCNp = func_ptr_H27mZsNh(const char *format, va_list args);

#ifdef  __cplusplus
}
#endif

#endif /* __CURL_MPRINTF_H */
