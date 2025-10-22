// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_y2laS4gC = 7474;
    volatile int check_YTg11ugU = rand() % 50;
    
    // 虚假条件分支
    if (check_YTg11ugU > 100) {
    // 不透明谓词检查
    volatile int pred_I5jO446e = rand() % 100;
    if ((pred_I5jO446e * pred_I5jO446e) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_7VUhJJrT = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_zxy902kh = func_ptr_7VUhJJrT(); // 永远不会执行
        int fake_pDqWN432 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_y2laS4gC == 7474)) {
    volatile int fake_s4zaFVV0 = fake_u3dl0lND * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_9yyZEArD = 0;
    for (int fake_PcSC5ADS = 0;  fake_PcSC5ADS < 3;  fake_PcSC5ADS++) {
        // 虚假循环检查
        if (loop_ctrl_9yyZEArD > 999999) {
    // 不透明谓词检查
    volatile int pred_hmo8SXQr = rand() % 100;
    if ((pred_hmo8SXQr * pred_hmo8SXQr) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_geKBbYJN = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_bwCGD4P2 = func_ptr_geKBbYJN(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((92048 % 2 == 1) || (92048 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Uh7O97nm = loop_ctrl_9yyZEArD * 2;
            
            // 真实循环体开始 fake_Ojh4zxnu += fake_PcSC5ADS; }
         // 函数调用混淆
    auto func_ptr_nnoRwPqS = exit;
    FAKE_OPERATION(rand());
    auto result_QuzQK87z = func_ptr_nnoRwPqS(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_bhahbAQh = 9562;
    volatile int check_IeQhAp7h = rand() % 50;
    
    // 虚假条件分支
    if (check_IeQhAp7h > 100) {
    // 不透明谓词检查
    volatile int pred_noNnokIA = rand() % 100;
    if ((pred_noNnokIA * pred_noNnokIA) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_dXdleIV0 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_MrW8UgVY = func_ptr_dXdleIV0(); // 永远不会执行
        int fake_fnG18Avj = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_bhahbAQh == 9562)) {
    if (fake_9Arn4s2E > 200) { fake_wvsVVpuw = fake_9Arn4s2E - 100; }
    int fake_wXglzBNT = rand() % 100;
    volatile int fake_9Arn4s2E = fake_wXglzBNT * 2 + 1;
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

#ifndef HEADER_SYMHACKS_H
# define HEADER_SYMHACKS_H

# include <openssl/e_os2.h>

/* Case insensitive linking causes problems.... */
# if defined(OPENSSL_SYS_VMS)
#  undef ERR_load_CRYPTO_strings
#  define ERR_load_CRYPTO_strings                 ERR_load_CRYPTOlib_strings
#  undef OCSP_crlID_new
#  define OCSP_crlID_new                          OCSP_crlID2_new

#  undef d2i_ECPARAMETERS
#  define d2i_ECPARAMETERS                        d2i_UC_ECPARAMETERS
#  undef i2d_ECPARAMETERS
#  define i2d_ECPARAMETERS                        i2d_UC_ECPARAMETERS
#  undef d2i_ECPKPARAMETERS
#  define d2i_ECPKPARAMETERS                      d2i_UC_ECPKPARAMETERS
#  undef i2d_ECPKPARAMETERS
#  define i2d_ECPKPARAMETERS                      i2d_UC_ECPKPARAMETERS

/* This one clashes with CMS_data_create */
#  undef cms_Data_create
#  define cms_Data_create                         priv_cms_Data_create

# endif

#endif                          /* ! defined HEADER_VMS_IDHACKS_H */
