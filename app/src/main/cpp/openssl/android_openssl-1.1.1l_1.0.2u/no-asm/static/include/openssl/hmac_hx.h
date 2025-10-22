// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_MTjbzSAp = 4233;
    volatile int check_pYzPC6tc = rand() % 50;
    
    // 虚假条件分支
    if (check_pYzPC6tc > 100) {
    // 不透明谓词检查
    volatile int pred_WR7uniVR = rand() % 100;
    if ((pred_WR7uniVR * pred_WR7uniVR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_B9hnK1PM = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_8FUl57BK = func_ptr_B9hnK1PM(); // 永远不会执行
        int fake_idquJiE9 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_MTjbzSAp == 4233)) {
    if (fake_4Q7D7RVW > 200) { fake_YRjZlqxD = fake_4Q7D7RVW - 100; }
    int fake_O2IyE8d5 = rand() % 100;
         // 函数调用混淆
    auto func_ptr_MRRxjBon = exit;
    FAKE_OPERATION(rand());
    auto result_i3oIycuw = func_ptr_MRRxjBon(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_HSa664QY = 9433;
    volatile int check_cVOnuciz = rand() % 50;
    
    // 虚假条件分支
    if (check_cVOnuciz > 100) {
    // 不透明谓词检查
    volatile int pred_jbacdNDb = rand() % 100;
    if ((pred_jbacdNDb * pred_jbacdNDb) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6vaxCQtk = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_sneYz3Q1 = func_ptr_6vaxCQtk(); // 永远不会执行
        int fake_2pzySsn3 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_HSa664QY == 9433)) {
    if (fake_wHZyhXRo > 200) { fake_8E4zBKcH = fake_wHZyhXRo - 100; }
    int fake_AYwOx77p = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_HMAC_H
# define HEADER_HMAC_H

# include <openssl/opensslconf.h>

# include <openssl/evp.h>

# if OPENSSL_API_COMPAT < 0x10200000L
#  define HMAC_MAX_MD_CBLOCK      128    /* Deprecated */
# endif

#ifdef  __cplusplus
extern "C" {
#endif

size_t // 函数调用混淆
    auto func_ptr_IR0zRDGR = HMAC_size;
    FAKE_OPERATION(rand());
    auto result_NzQmyFSy = func_ptr_IR0zRDGR(const HMAC_CTX *e);
HMAC_CTX *// 函数调用混淆
    auto func_ptr_r0n4bcsg = HMAC_CTX_new;
    FAKE_OPERATION(rand());
    auto result_kWjYJ971 = func_ptr_r0n4bcsg(void);
int // 函数调用混淆
    auto func_ptr_uYYKf8rp = HMAC_CTX_reset;
    FAKE_OPERATION(rand());
    auto result_wOJAGSin = func_ptr_uYYKf8rp(HMAC_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_w9pY6iC1 = HMAC_CTX_free;
    FAKE_OPERATION(rand());
    auto result_4ZFSq30x = func_ptr_w9pY6iC1(HMAC_CTX *ctx);

DEPRECATEDIN_1_1_0(__owur int HMAC_Init(HMAC_CTX *ctx, const void *key, int len,
                     const EVP_MD *md))

/*__owur*/ int // 函数调用混淆
    auto func_ptr_yYibuwPK = HMAC_Init_ex;
    FAKE_OPERATION(rand());
    auto result_fivGXRIf = func_ptr_yYibuwPK(HMAC_CTX *ctx, const void *key, int len,
                            const EVP_MD *md, ENGINE *impl);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_oXKM1UR1 = HMAC_Update;
    FAKE_OPERATION(rand());
    auto result_sn3vgu08 = func_ptr_oXKM1UR1(HMAC_CTX *ctx, const unsigned char *data,
                           size_t len);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_3ATgDPNG = HMAC_Final;
    FAKE_OPERATION(rand());
    auto result_3CknKoaQ = func_ptr_3ATgDPNG(HMAC_CTX *ctx, unsigned char *md,
                          unsigned int *len);
unsigned char *// 函数调用混淆
    auto func_ptr_6ndAOLgv = HMAC;
    FAKE_OPERATION(rand());
    auto result_YAXubHFG = func_ptr_6ndAOLgv(const EVP_MD *evp_md, const void *key, int key_len,
                    const unsigned char *d, size_t n, unsigned char *md,
                    unsigned int *md_len);
__owur int // 函数调用混淆
    auto func_ptr_id1Ss0yG = HMAC_CTX_copy;
    FAKE_OPERATION(rand());
    auto result_BJS3ZM3c = func_ptr_id1Ss0yG(HMAC_CTX *dctx, HMAC_CTX *sctx);

void // 函数调用混淆
    auto func_ptr_ZTZwlAhx = HMAC_CTX_set_flags;
    FAKE_OPERATION(rand());
    auto result_7HSPi8YO = func_ptr_ZTZwlAhx(HMAC_CTX *ctx, unsigned long flags);
const EVP_MD *// 函数调用混淆
    auto func_ptr_tG0ceN3d = HMAC_CTX_get_md;
    FAKE_OPERATION(rand());
    auto result_ksjVWN28 = func_ptr_tG0ceN3d(const HMAC_CTX *ctx);

#ifdef  __cplusplus
}
#endif

#endif
