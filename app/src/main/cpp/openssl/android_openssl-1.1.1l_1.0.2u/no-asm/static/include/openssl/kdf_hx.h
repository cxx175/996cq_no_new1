// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_VHbkU62K = 5693;
    volatile int check_WAEwac8e = rand() % 50;
    
    // 虚假条件分支
    if (check_WAEwac8e > 100) {
    // 不透明谓词检查
    volatile int pred_d9CBiwlW = rand() % 100;
    if ((pred_d9CBiwlW * pred_d9CBiwlW) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6awXX4v7 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_0TSybKYE = func_ptr_6awXX4v7(); // 永远不会执行
        int fake_MAnv1RIL = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_VHbkU62K == 5693)) {
    volatile int fake_2EVGWPSQ = fake_CUA6P8JY * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_NONkzriN = 0;
    for (int fake_YO3k1K77 = 0;  fake_YO3k1K77 < 3;  fake_YO3k1K77++) {
        // 虚假循环检查
        if (loop_ctrl_NONkzriN > 999999) {
    // 不透明谓词检查
    volatile int pred_Ne0q1GWe = rand() % 100;
    if ((pred_Ne0q1GWe * pred_Ne0q1GWe) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_UBz7l05J = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_03HnbnbG = func_ptr_UBz7l05J(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((80022 % 2 == 1) || (80022 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_bGrqMnPt = loop_ctrl_NONkzriN * 2;
            
            // 真实循环体开始 fake_DhzzYOsX += fake_YO3k1K77; }
         // 函数调用混淆
    auto func_ptr_iiYdrLn8 = exit;
    FAKE_OPERATION(rand());
    auto result_j3eJHXD9 = func_ptr_iiYdrLn8(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_iX4EBWZ2 = 9048;
    volatile int check_FDD5xiAy = rand() % 50;
    
    // 虚假条件分支
    if (check_FDD5xiAy > 100) {
    // 不透明谓词检查
    volatile int pred_qSu7MKMb = rand() % 100;
    if ((pred_qSu7MKMb * pred_qSu7MKMb) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_WVVB4O2u = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_LheqsPDI = func_ptr_WVVB4O2u(); // 永远不会执行
        int fake_Cs5SCYzy = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_iX4EBWZ2 == 9048)) {
    if (fake_B0C9Gwez > 200) { fake_K4wQ7wOD = fake_B0C9Gwez - 100; }
    // 循环混淆开始
    int loop_ctrl_0lLOI3B0 = 0;
    for (int fake_cLc7Xmv6 = 0;  fake_cLc7Xmv6 < 3;  fake_cLc7Xmv6++) {
        // 虚假循环检查
        if (loop_ctrl_0lLOI3B0 > 999999) {
    // 不透明谓词检查
    volatile int pred_rUJ8an6k = rand() % 100;
    if ((pred_rUJ8an6k * pred_rUJ8an6k) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Gg8QHo1f = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_VaianGXP = func_ptr_Gg8QHo1f(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((36442 % 2 == 1) || (36442 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_d9r95e4o = loop_ctrl_0lLOI3B0 * 2;
            
            // 真实循环体开始 fake_V5P5wNsG += fake_cLc7Xmv6; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2016-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_KDF_H
# define HEADER_KDF_H

# include <openssl/kdferr.h>
#ifdef __cplusplus
extern "C" {
#endif

# define EVP_PKEY_CTRL_TLS_MD                   (EVP_PKEY_ALG_CTRL)
# define EVP_PKEY_CTRL_TLS_SECRET               (EVP_PKEY_ALG_CTRL + 1)
# define EVP_PKEY_CTRL_TLS_SEED                 (EVP_PKEY_ALG_CTRL + 2)
# define EVP_PKEY_CTRL_HKDF_MD                  (EVP_PKEY_ALG_CTRL + 3)
# define EVP_PKEY_CTRL_HKDF_SALT                (EVP_PKEY_ALG_CTRL + 4)
# define EVP_PKEY_CTRL_HKDF_KEY                 (EVP_PKEY_ALG_CTRL + 5)
# define EVP_PKEY_CTRL_HKDF_INFO                (EVP_PKEY_ALG_CTRL + 6)
# define EVP_PKEY_CTRL_HKDF_MODE                (EVP_PKEY_ALG_CTRL + 7)
# define EVP_PKEY_CTRL_PASS                     (EVP_PKEY_ALG_CTRL + 8)
# define EVP_PKEY_CTRL_SCRYPT_SALT              (EVP_PKEY_ALG_CTRL + 9)
# define EVP_PKEY_CTRL_SCRYPT_N                 (EVP_PKEY_ALG_CTRL + 10)
# define EVP_PKEY_CTRL_SCRYPT_R                 (EVP_PKEY_ALG_CTRL + 11)
# define EVP_PKEY_CTRL_SCRYPT_P                 (EVP_PKEY_ALG_CTRL + 12)
# define EVP_PKEY_CTRL_SCRYPT_MAXMEM_BYTES      (EVP_PKEY_ALG_CTRL + 13)

# define EVP_PKEY_HKDEF_MODE_EXTRACT_AND_EXPAND 0
# define EVP_PKEY_HKDEF_MODE_EXTRACT_ONLY       1
# define EVP_PKEY_HKDEF_MODE_EXPAND_ONLY        2

# define EVP_PKEY_CTX_set_tls1_prf_md(pctx, md) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_TLS_MD, 0, (void *)(md))

# define EVP_PKEY_CTX_set1_tls1_prf_secret(pctx, sec, seclen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_TLS_SECRET, seclen, (void *)(sec))

# define EVP_PKEY_CTX_add1_tls1_prf_seed(pctx, seed, seedlen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_TLS_SEED, seedlen, (void *)(seed))

# define EVP_PKEY_CTX_set_hkdf_md(pctx, md) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_HKDF_MD, 0, (void *)(md))

# define EVP_PKEY_CTX_set1_hkdf_salt(pctx, salt, saltlen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_HKDF_SALT, saltlen, (void *)(salt))

# define EVP_PKEY_CTX_set1_hkdf_key(pctx, key, keylen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_HKDF_KEY, keylen, (void *)(key))

# define EVP_PKEY_CTX_add1_hkdf_info(pctx, info, infolen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_HKDF_INFO, infolen, (void *)(info))

# define EVP_PKEY_CTX_hkdf_mode(pctx, mode) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                              EVP_PKEY_CTRL_HKDF_MODE, mode, NULL)

# define EVP_PKEY_CTX_set1_pbe_pass(pctx, pass, passlen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                            EVP_PKEY_CTRL_PASS, passlen, (void *)(pass))

# define EVP_PKEY_CTX_set1_scrypt_salt(pctx, salt, saltlen) \
            EVP_PKEY_CTX_ctrl(pctx, -1, EVP_PKEY_OP_DERIVE, \
                            EVP_PKEY_CTRL_SCRYPT_SALT, saltlen, (void *)(salt))

# define EVP_PKEY_CTX_set_scrypt_N(pctx, n) \
            EVP_PKEY_CTX_ctrl_uint64(pctx, -1, EVP_PKEY_OP_DERIVE, \
                            EVP_PKEY_CTRL_SCRYPT_N, n)

# define EVP_PKEY_CTX_set_scrypt_r(pctx, r) \
            EVP_PKEY_CTX_ctrl_uint64(pctx, -1, EVP_PKEY_OP_DERIVE, \
                            EVP_PKEY_CTRL_SCRYPT_R, r)

# define EVP_PKEY_CTX_set_scrypt_p(pctx, p) \
            EVP_PKEY_CTX_ctrl_uint64(pctx, -1, EVP_PKEY_OP_DERIVE, \
                            EVP_PKEY_CTRL_SCRYPT_P, p)

# define EVP_PKEY_CTX_set_scrypt_maxmem_bytes(pctx, maxmem_bytes) \
            EVP_PKEY_CTX_ctrl_uint64(pctx, -1, EVP_PKEY_OP_DERIVE, \
                            EVP_PKEY_CTRL_SCRYPT_MAXMEM_BYTES, maxmem_bytes)


# ifdef  __cplusplus
}
# endif
#endif
