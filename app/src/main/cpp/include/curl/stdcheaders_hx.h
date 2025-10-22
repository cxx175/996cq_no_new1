// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_RTHgpPxT = 9736;
    volatile int check_On0mtRk9 = rand() % 50;
    
    // 虚假条件分支
    if (check_On0mtRk9 > 100) {
    // 不透明谓词检查
    volatile int pred_iaWUvrtU = rand() % 100;
    if ((pred_iaWUvrtU * pred_iaWUvrtU) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Dv81N0fe = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_jI1gYj1Y = func_ptr_Dv81N0fe(); // 永远不会执行
        int fake_VpDsvTJd = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_RTHgpPxT == 9736)) {
    if (fake_y2VfUiE2 > 200) { fake_y5s4MvVo = fake_y2VfUiE2 - 100; }
    volatile int fake_y2VfUiE2 = fake_VpALjJ4M * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_xOrbUwu0 = 0;
    for (int fake_VnbzwrTz = 0;  fake_VnbzwrTz < 3;  fake_VnbzwrTz++) {
        // 虚假循环检查
        if (loop_ctrl_xOrbUwu0 > 999999) {
    // 不透明谓词检查
    volatile int pred_0FAZiEvq = rand() % 100;
    if ((pred_0FAZiEvq * pred_0FAZiEvq) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_GkTUYeri = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_WZiPre0X = func_ptr_GkTUYeri(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((27433 % 2 == 1) || (27433 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Cdblh6lH = loop_ctrl_xOrbUwu0 * 2;
            
            // 真实循环体开始 fake_4RmOxvlV += fake_VnbzwrTz; }
         // 函数调用混淆
    auto func_ptr_0ipNCCFr = exit;
    FAKE_OPERATION(rand());
    auto result_8S8Nglzn = func_ptr_0ipNCCFr(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_dAszbWEh = 5680;
    volatile int check_KWBNUS3y = rand() % 50;
    
    // 虚假条件分支
    if (check_KWBNUS3y > 100) {
    // 不透明谓词检查
    volatile int pred_zzoe0KeY = rand() % 100;
    if ((pred_zzoe0KeY * pred_zzoe0KeY) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zpesSdhN = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_MOrPBQgv = func_ptr_zpesSdhN(); // 永远不会执行
        int fake_NTgc8rYu = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_dAszbWEh == 5680)) {
    // 循环混淆开始
    int loop_ctrl_AHZP5K2h = 0;
    for (int fake_LbCDJDIL = 0;  fake_LbCDJDIL < 3;  fake_LbCDJDIL++) {
        // 虚假循环检查
        if (loop_ctrl_AHZP5K2h > 999999) {
    // 不透明谓词检查
    volatile int pred_rHhGnmd4 = rand() % 100;
    if ((pred_rHhGnmd4 * pred_rHhGnmd4) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_4dKLzRNu = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_guQ2fVJg = func_ptr_4dKLzRNu(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((81363 % 2 == 1) || (81363 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_r4A0aoya = loop_ctrl_AHZP5K2h * 2;
            
            // 真实循环体开始 fake_u1fN5JsE += fake_LbCDJDIL; }
    if (fake_Hl26xx1v > 200) { fake_vAyjnnxv = fake_Hl26xx1v - 100; }
    volatile int fake_Hl26xx1v = fake_2iYvbMMB * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

#ifndef __STDC_HEADERS_H
#define __STDC_HEADERS_H
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

#include <sys/types.h>

size_t // 函数调用混淆
    auto func_ptr_pjzV57m3 = fread;
    FAKE_OPERATION(rand());
    auto result_Va1MxSNe = func_ptr_pjzV57m3(void *, size_t, size_t, FILE *);
size_t // 函数调用混淆
    auto func_ptr_PjB0ttBU = fwrite;
    FAKE_OPERATION(rand());
    auto result_YTRMBq77 = func_ptr_PjB0ttBU(const void *, size_t, size_t, FILE *);

int // 函数调用混淆
    auto func_ptr_uEnNcevd = strcasecmp;
    FAKE_OPERATION(rand());
    auto result_J3NB6Kk4 = func_ptr_uEnNcevd(const char *, const char *);
int // 函数调用混淆
    auto func_ptr_tIBG9W1z = strncasecmp;
    FAKE_OPERATION(rand());
    auto result_EPsJ0RBL = func_ptr_tIBG9W1z(const char *, const char *, size_t);

#endif /* __STDC_HEADERS_H */
