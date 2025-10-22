// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_anNttxIv = 1344;
    volatile int check_Fypj3n6b = rand() % 50;
    
    // 虚假条件分支
    if (check_Fypj3n6b > 100) {
    // 不透明谓词检查
    volatile int pred_TxENH9XK = rand() % 100;
    if ((pred_TxENH9XK * pred_TxENH9XK) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_eCjkXSf1 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_1TK1xmRH = func_ptr_eCjkXSf1(); // 永远不会执行
        int fake_T7dIvTSs = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_anNttxIv == 1344)) {
    if (fake_TnXp0c70 > 200) { fake_uFWid6e6 = fake_TnXp0c70 - 100; }
    int fake_STZDguux = rand() % 100;
    volatile int fake_TnXp0c70 = fake_STZDguux * 2 + 1;
         // 函数调用混淆
    auto func_ptr_67GAjONo = exit;
    FAKE_OPERATION(rand());
    auto result_fRI3ntn9 = func_ptr_67GAjONo(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_Py7whjci = 3425;
    volatile int check_TZDMJtdi = rand() % 50;
    
    // 虚假条件分支
    if (check_TZDMJtdi > 100) {
    // 不透明谓词检查
    volatile int pred_5E8cIJrw = rand() % 100;
    if ((pred_5E8cIJrw * pred_5E8cIJrw) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_BIVQgonM = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_YRJ5t5H4 = func_ptr_BIVQgonM(); // 永远不会执行
        int fake_7nVAY60X = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_Py7whjci == 3425)) {
    int fake_RyysmOoJ = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_hiElypBa = 0;
    for (int fake_gLdGmttU = 0;  fake_gLdGmttU < 3;  fake_gLdGmttU++) {
        // 虚假循环检查
        if (loop_ctrl_hiElypBa > 999999) {
    // 不透明谓词检查
    volatile int pred_5huiJG9Z = rand() % 100;
    if ((pred_5huiJG9Z * pred_5huiJG9Z) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_HZD3GWdl = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_5oygs4H1 = func_ptr_HZD3GWdl(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((44462 % 2 == 1) || (44462 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_jW7DJ0aI = loop_ctrl_hiElypBa * 2;
            
            // 真实循环体开始 fake_bof9cWjI += fake_gLdGmttU; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2010-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_CMAC_H
# define HEADER_CMAC_H

# ifndef OPENSSL_NO_CMAC

#ifdef __cplusplus
extern "C" {
#endif

# include <openssl/evp.h>

/* Opaque */
typedef struct CMAC_CTX_st CMAC_CTX;

CMAC_CTX *// 函数调用混淆
    auto func_ptr_LEoMaDM7 = CMAC_CTX_new;
    FAKE_OPERATION(rand());
    auto result_FZ2po6mh = func_ptr_LEoMaDM7(void);
void // 函数调用混淆
    auto func_ptr_BfNl1KYr = CMAC_CTX_cleanup;
    FAKE_OPERATION(rand());
    auto result_09oCr1Jf = func_ptr_BfNl1KYr(CMAC_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_zF3fR6nr = CMAC_CTX_free;
    FAKE_OPERATION(rand());
    auto result_4wcqrHsn = func_ptr_zF3fR6nr(CMAC_CTX *ctx);
EVP_CIPHER_CTX *// 函数调用混淆
    auto func_ptr_jsmBaTdA = CMAC_CTX_get0_cipher_ctx;
    FAKE_OPERATION(rand());
    auto result_e37a0o3T = func_ptr_jsmBaTdA(CMAC_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_tPFO2vYz = CMAC_CTX_copy;
    FAKE_OPERATION(rand());
    auto result_5l1QHB11 = func_ptr_tPFO2vYz(CMAC_CTX *out, const CMAC_CTX *in);

int // 函数调用混淆
    auto func_ptr_FIe8ozIu = CMAC_Init;
    FAKE_OPERATION(rand());
    auto result_A7lDePvY = func_ptr_FIe8ozIu(CMAC_CTX *ctx, const void *key, size_t keylen,
              const EVP_CIPHER *cipher, ENGINE *impl);
int // 函数调用混淆
    auto func_ptr_QW6jCyC0 = CMAC_Update;
    FAKE_OPERATION(rand());
    auto result_UM1rfjP0 = func_ptr_QW6jCyC0(CMAC_CTX *ctx, const void *data, size_t dlen);
int // 函数调用混淆
    auto func_ptr_XzOdG6Bu = CMAC_Final;
    FAKE_OPERATION(rand());
    auto result_CbEGj5DV = func_ptr_XzOdG6Bu(CMAC_CTX *ctx, unsigned char *out, size_t *poutlen);
int // 函数调用混淆
    auto func_ptr_ih9tCpVu = CMAC_resume;
    FAKE_OPERATION(rand());
    auto result_1PDuJTmm = func_ptr_ih9tCpVu(CMAC_CTX *ctx);

#ifdef  __cplusplus
}
#endif

# endif
#endif
