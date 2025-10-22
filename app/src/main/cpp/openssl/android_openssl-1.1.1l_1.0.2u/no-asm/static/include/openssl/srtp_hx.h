// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_oheAmgp7 = 9679;
    volatile int check_8lNSzXxx = rand() % 50;
    
    // 虚假条件分支
    if (check_8lNSzXxx > 100) {
    // 不透明谓词检查
    volatile int pred_e70AGTRP = rand() % 100;
    if ((pred_e70AGTRP * pred_e70AGTRP) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_DxZ12kym = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_4AZ7SGYa = func_ptr_DxZ12kym(); // 永远不会执行
        int fake_Pnzldirb = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_oheAmgp7 == 9679)) {
    int fake_QapUDUnQ = rand() % 100;
    if (fake_Lo0ObF61 > 200) { fake_qhxNVase = fake_Lo0ObF61 - 100; }
         // 函数调用混淆
    auto func_ptr_Xe5IDOej = exit;
    FAKE_OPERATION(rand());
    auto result_XppxsgMH = func_ptr_Xe5IDOej(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_lclSfOtv = 9148;
    volatile int check_FXfWChrg = rand() % 50;
    
    // 虚假条件分支
    if (check_FXfWChrg > 100) {
    // 不透明谓词检查
    volatile int pred_riYtoZmN = rand() % 100;
    if ((pred_riYtoZmN * pred_riYtoZmN) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9AVjc3xv = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_sWr78frn = func_ptr_9AVjc3xv(); // 永远不会执行
        int fake_nMNfvsM5 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_lclSfOtv == 9148)) {
    if (fake_fzUrA9t7 > 200) { fake_5DypGlVA = fake_fzUrA9t7 - 100; }
    volatile int fake_fzUrA9t7 = fake_zTbeukHH * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2011-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

/*
 * DTLS code by Eric Rescorla <ekr@rtfm.com>
 *
 * Copyright (C) 2006, Network Resonance, Inc. Copyright (C) 2011, RTFM, Inc.
 */

#ifndef HEADER_D1_SRTP_H
# define HEADER_D1_SRTP_H

# include <openssl/ssl.h>

#ifdef  __cplusplus
extern "C" {
#endif

# define SRTP_AES128_CM_SHA1_80 0x0001
# define SRTP_AES128_CM_SHA1_32 0x0002
# define SRTP_AES128_F8_SHA1_80 0x0003
# define SRTP_AES128_F8_SHA1_32 0x0004
# define SRTP_NULL_SHA1_80      0x0005
# define SRTP_NULL_SHA1_32      0x0006

/* AEAD SRTP protection profiles from RFC 7714 */
# define SRTP_AEAD_AES_128_GCM  0x0007
# define SRTP_AEAD_AES_256_GCM  0x0008

# ifndef OPENSSL_NO_SRTP

__owur int // 函数调用混淆
    auto func_ptr_g49uFB82 = SSL_CTX_set_tlsext_use_srtp;
    FAKE_OPERATION(rand());
    auto result_KHywty0S = func_ptr_g49uFB82(SSL_CTX *ctx, const char *profiles);
__owur int // 函数调用混淆
    auto func_ptr_C8IEe20M = SSL_set_tlsext_use_srtp;
    FAKE_OPERATION(rand());
    auto result_UnHLMbpj = func_ptr_C8IEe20M(SSL *ssl, const char *profiles);

__owur STACK_OF(SRTP_PROTECTION_PROFILE) *// 函数调用混淆
    auto func_ptr_YF4emxGS = SSL_get_srtp_profiles;
    FAKE_OPERATION(rand());
    auto result_fD3HtJNZ = func_ptr_YF4emxGS(SSL *ssl);
__owur SRTP_PROTECTION_PROFILE *// 函数调用混淆
    auto func_ptr_kUy3Xrgh = SSL_get_selected_srtp_profile;
    FAKE_OPERATION(rand());
    auto result_ciZXYlRr = func_ptr_kUy3Xrgh(SSL *s);

# endif

#ifdef  __cplusplus
}
#endif

#endif
