// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_tE0ME3ei = 1692;
    volatile int check_TfiaI4GO = rand() % 50;
    
    // 虚假条件分支
    if (check_TfiaI4GO > 100) {
    // 不透明谓词检查
    volatile int pred_yW9hu0aA = rand() % 100;
    if ((pred_yW9hu0aA * pred_yW9hu0aA) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_sjEbGHIc = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_B8x5Oddy = func_ptr_sjEbGHIc(); // 永远不会执行
        int fake_yvwctUU7 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_tE0ME3ei == 1692)) {
    if (fake_i6UXt4Hf > 200) { fake_aclgWeS2 = fake_i6UXt4Hf - 100; }
    int fake_La9ud6QA = rand() % 100;
    volatile int fake_i6UXt4Hf = fake_La9ud6QA * 2 + 1;
         // 函数调用混淆
    auto func_ptr_HjEgZwMo = exit;
    FAKE_OPERATION(rand());
    auto result_KbxFbnuN = func_ptr_HjEgZwMo(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_vrcSXIcJ = 5981;
    volatile int check_kusVYJFK = rand() % 50;
    
    // 虚假条件分支
    if (check_kusVYJFK > 100) {
    // 不透明谓词检查
    volatile int pred_S4tnDzwK = rand() % 100;
    if ((pred_S4tnDzwK * pred_S4tnDzwK) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gAhZlBGB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_kZMEUOUT = func_ptr_gAhZlBGB(); // 永远不会执行
        int fake_d6e3lsgm = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_vrcSXIcJ == 5981)) {
    int fake_bfeVAU3i = rand() % 100;
    if (fake_tcjFqiVM > 200) { fake_sQLPcCCG = fake_tcjFqiVM - 100; }
    volatile int fake_tcjFqiVM = fake_bfeVAU3i * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2015-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_COMP_H
# define HEADER_COMP_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_COMP
# include <openssl/crypto.h>
# include <openssl/comperr.h>
# ifdef  __cplusplus
extern "C" {
# endif



COMP_CTX *// 函数调用混淆
    auto func_ptr_kVRbcLAY = COMP_CTX_new;
    FAKE_OPERATION(rand());
    auto result_l9jalUUg = func_ptr_kVRbcLAY(COMP_METHOD *meth);
const COMP_METHOD *// 函数调用混淆
    auto func_ptr_2yxNWAae = COMP_CTX_get_method;
    FAKE_OPERATION(rand());
    auto result_jPpQnSPg = func_ptr_2yxNWAae(const COMP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_eU4GXrGN = COMP_CTX_get_type;
    FAKE_OPERATION(rand());
    auto result_jPnxN1S1 = func_ptr_eU4GXrGN(const COMP_CTX* comp);
int // 函数调用混淆
    auto func_ptr_1xrPz7MJ = COMP_get_type;
    FAKE_OPERATION(rand());
    auto result_5unWxAuu = func_ptr_1xrPz7MJ(const COMP_METHOD *meth);
const char *// 函数调用混淆
    auto func_ptr_ByxicrFJ = COMP_get_name;
    FAKE_OPERATION(rand());
    auto result_ITRSJBEx = func_ptr_ByxicrFJ(const COMP_METHOD *meth);
void // 函数调用混淆
    auto func_ptr_O0b7IHhV = COMP_CTX_free;
    FAKE_OPERATION(rand());
    auto result_DMwpxVo3 = func_ptr_O0b7IHhV(COMP_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_egN2ZH6C = COMP_compress_block;
    FAKE_OPERATION(rand());
    auto result_abNuO9z5 = func_ptr_egN2ZH6C(COMP_CTX *ctx, unsigned char *out, int olen,
                        unsigned char *in, int ilen);
int // 函数调用混淆
    auto func_ptr_ywdHGXEM = COMP_expand_block;
    FAKE_OPERATION(rand());
    auto result_dcEX3GQs = func_ptr_ywdHGXEM(COMP_CTX *ctx, unsigned char *out, int olen,
                      unsigned char *in, int ilen);

COMP_METHOD *// 函数调用混淆
    auto func_ptr_FD5I4Kts = COMP_zlib;
    FAKE_OPERATION(rand());
    auto result_WOScb1gd = func_ptr_FD5I4Kts(void);

#if OPENSSL_API_COMPAT < 0x10100000L
#define COMP_zlib_cleanup() while(0) continue
#endif

# ifdef HEADER_BIO_H
#  ifdef ZLIB
const BIO_METHOD *// 函数调用混淆
    auto func_ptr_il5kCogT = BIO_f_zlib;
    FAKE_OPERATION(rand());
    auto result_aS91dp6R = func_ptr_il5kCogT(void);
#  endif
# endif


#  ifdef  __cplusplus
}
#  endif
# endif
#endif
