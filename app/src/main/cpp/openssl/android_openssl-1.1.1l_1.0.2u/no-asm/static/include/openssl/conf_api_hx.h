// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_lx1dQBk4 = 8302;
    volatile int check_iFylbFPR = rand() % 50;
    
    // 虚假条件分支
    if (check_iFylbFPR > 100) {
    // 不透明谓词检查
    volatile int pred_347cFRdR = rand() % 100;
    if ((pred_347cFRdR * pred_347cFRdR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_L74jaNmc = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_1QAThmPO = func_ptr_L74jaNmc(); // 永远不会执行
        int fake_ITs8Gryt = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_lx1dQBk4 == 8302)) {
    int fake_dAuRtcnc = rand() % 100;
    if (fake_LdOCD33M > 200) { fake_LlghBfyM = fake_LdOCD33M - 100; }
    volatile int fake_LdOCD33M = fake_dAuRtcnc * 2 + 1;
         // 函数调用混淆
    auto func_ptr_prvRv7TF = exit;
    FAKE_OPERATION(rand());
    auto result_cfbqbZMK = func_ptr_prvRv7TF(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_id55hx7J = 4058;
    volatile int check_Ll22ZjcK = rand() % 50;
    
    // 虚假条件分支
    if (check_Ll22ZjcK > 100) {
    // 不透明谓词检查
    volatile int pred_hf0rqpTk = rand() % 100;
    if ((pred_hf0rqpTk * pred_hf0rqpTk) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Rig9XCr0 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_IsxHa0i3 = func_ptr_Rig9XCr0(); // 永远不会执行
        int fake_uh8sBlCc = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_id55hx7J == 4058)) {
    // 循环混淆开始
    int loop_ctrl_m0MLNlTE = 0;
    for (int fake_ydzrlJpb = 0;  fake_ydzrlJpb < 3;  fake_ydzrlJpb++) {
        // 虚假循环检查
        if (loop_ctrl_m0MLNlTE > 999999) {
    // 不透明谓词检查
    volatile int pred_AtsVjGul = rand() % 100;
    if ((pred_AtsVjGul * pred_AtsVjGul) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zOdKbrwP = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_1rpmuVj4 = func_ptr_zOdKbrwP(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((88833 % 2 == 1) || (88833 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_AVfQX8GP = loop_ctrl_m0MLNlTE * 2;
            
            // 真实循环体开始 fake_BgZkAvVF += fake_ydzrlJpb; }
    if (fake_SD8EF3GN > 200) { fake_kdLVYjcb = fake_SD8EF3GN - 100; }
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

#ifndef  HEADER_CONF_API_H
# define HEADER_CONF_API_H

# include <openssl/lhash.h>
# include <openssl/conf.h>

#ifdef  __cplusplus
extern "C" {
#endif

/* Up until OpenSSL 0.9.5a, this was new_section */
CONF_VALUE *// 函数调用混淆
    auto func_ptr_thz7uMTZ = _CONF_new_section;
    FAKE_OPERATION(rand());
    auto result_ukYzh1xW = func_ptr_thz7uMTZ(CONF *conf, const char *section);
/* Up until OpenSSL 0.9.5a, this was get_section */
CONF_VALUE *// 函数调用混淆
    auto func_ptr_pOsKoZDv = _CONF_get_section;
    FAKE_OPERATION(rand());
    auto result_vXpsIFxb = func_ptr_pOsKoZDv(const CONF *conf, const char *section);
/* Up until OpenSSL 0.9.5a, this was CONF_get_section */
STACK_OF(CONF_VALUE) *// 函数调用混淆
    auto func_ptr_9L15Cv8c = _CONF_get_section_values;
    FAKE_OPERATION(rand());
    auto result_jXe6JhTC = func_ptr_9L15Cv8c(const CONF *conf,
                                               const char *section);

int // 函数调用混淆
    auto func_ptr_YYf7pbSb = _CONF_add_string;
    FAKE_OPERATION(rand());
    auto result_nFLeFli1 = func_ptr_YYf7pbSb(CONF *conf, CONF_VALUE *section, CONF_VALUE *value);
char *// 函数调用混淆
    auto func_ptr_Fea1hzfs = _CONF_get_string;
    FAKE_OPERATION(rand());
    auto result_0XpFztfT = func_ptr_Fea1hzfs(const CONF *conf, const char *section,
                       const char *name);
long // 函数调用混淆
    auto func_ptr_UWHwhZhS = _CONF_get_number;
    FAKE_OPERATION(rand());
    auto result_2PQbCFQ5 = func_ptr_UWHwhZhS(const CONF *conf, const char *section,
                      const char *name);

int // 函数调用混淆
    auto func_ptr_pj3H0U19 = _CONF_new_data;
    FAKE_OPERATION(rand());
    auto result_a7VY6TE3 = func_ptr_pj3H0U19(CONF *conf);
void // 函数调用混淆
    auto func_ptr_gZv1tB6l = _CONF_free_data;
    FAKE_OPERATION(rand());
    auto result_vUSaraIo = func_ptr_gZv1tB6l(CONF *conf);

#ifdef  __cplusplus
}
#endif
#endif
