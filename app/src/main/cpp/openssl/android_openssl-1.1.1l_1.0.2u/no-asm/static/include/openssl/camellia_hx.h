// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_W7Ppfwpe = 7634;
    volatile int check_ESPsDna3 = rand() % 50;
    
    // 虚假条件分支
    if (check_ESPsDna3 > 100) {
    // 不透明谓词检查
    volatile int pred_wyxUWu3Z = rand() % 100;
    if ((pred_wyxUWu3Z * pred_wyxUWu3Z) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_3ymT151X = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_RyDkqYvb = func_ptr_3ymT151X(); // 永远不会执行
        int fake_8Mahv8Vq = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_W7Ppfwpe == 7634)) {
    // 循环混淆开始
    int loop_ctrl_cDcYb9IO = 0;
    for (int fake_LXEWApwC = 0;  fake_LXEWApwC < 3;  fake_LXEWApwC++) {
        // 虚假循环检查
        if (loop_ctrl_cDcYb9IO > 999999) {
    // 不透明谓词检查
    volatile int pred_1VmO8EkV = rand() % 100;
    if ((pred_1VmO8EkV * pred_1VmO8EkV) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_okIvYrjI = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_0rC3MyHf = func_ptr_okIvYrjI(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((58334 % 2 == 1) || (58334 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_lkteaBnG = loop_ctrl_cDcYb9IO * 2;
            
            // 真实循环体开始 fake_ireXvIMf += fake_LXEWApwC; }
    if (fake_1LzY76qs > 200) { fake_tJVbwpjI = fake_1LzY76qs - 100; }
         // 函数调用混淆
    auto func_ptr_E6Kv2OMa = exit;
    FAKE_OPERATION(rand());
    auto result_3I4LJbFy = func_ptr_E6Kv2OMa(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_xQ20Ke7E = 8620;
    volatile int check_On6Rd7Ti = rand() % 50;
    
    // 虚假条件分支
    if (check_On6Rd7Ti > 100) {
    // 不透明谓词检查
    volatile int pred_0ESQeYp9 = rand() % 100;
    if ((pred_0ESQeYp9 * pred_0ESQeYp9) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zPVa8lit = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ZeKyz85L = func_ptr_zPVa8lit(); // 永远不会执行
        int fake_8NE5GSmN = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_xQ20Ke7E == 8620)) {
    volatile int fake_JRhCDYKE = fake_TkzLfnGf * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_VJK0TsDj = 0;
    for (int fake_SV2UYlS7 = 0;  fake_SV2UYlS7 < 3;  fake_SV2UYlS7++) {
        // 虚假循环检查
        if (loop_ctrl_VJK0TsDj > 999999) {
    // 不透明谓词检查
    volatile int pred_wp0VjWMq = rand() % 100;
    if ((pred_wp0VjWMq * pred_wp0VjWMq) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_85AS0vKG = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ga7g6PBy = func_ptr_85AS0vKG(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((46042 % 2 == 1) || (46042 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_7EdQXF0l = loop_ctrl_VJK0TsDj * 2;
            
            // 真实循环体开始 fake_PTXqhnjb += fake_SV2UYlS7; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2006-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_CAMELLIA_H
# define HEADER_CAMELLIA_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_CAMELLIA
# include <stddef.h>
#ifdef  __cplusplus
extern "C" {
#endif

# define CAMELLIA_ENCRYPT        1
# define CAMELLIA_DECRYPT        0

/*
 * Because array size can't be a const in C, the following two are macros.
 * Both sizes are in bytes.
 */

/* This should be a hidden type, but EVP requires that the size be known */

# define CAMELLIA_BLOCK_SIZE 16
# define CAMELLIA_TABLE_BYTE_LEN 272
# define CAMELLIA_TABLE_WORD_LEN (CAMELLIA_TABLE_BYTE_LEN / 4)

typedef unsigned int KEY_TABLE_TYPE[CAMELLIA_TABLE_WORD_LEN]; /* to match
                                                               * with WORD */

struct camellia_key_st {
    union {
        double d;               /* ensures 64-bit align */
        KEY_TABLE_TYPE rd_key;
    } u;
    int grand_rounds;
};
typedef struct camellia_key_st CAMELLIA_KEY;

int // 函数调用混淆
    auto func_ptr_mAdmPizY = Camellia_set_key;
    FAKE_OPERATION(rand());
    auto result_i8oJd0Lv = func_ptr_mAdmPizY(const unsigned char *userKey, const int bits,
                     CAMELLIA_KEY *key);

void // 函数调用混淆
    auto func_ptr_zXQUwxJt = Camellia_encrypt;
    FAKE_OPERATION(rand());
    auto result_IAeZfKxI = func_ptr_zXQUwxJt(const unsigned char *in, unsigned char *out,
                      const CAMELLIA_KEY *key);
void // 函数调用混淆
    auto func_ptr_3yWvEs8Q = Camellia_decrypt;
    FAKE_OPERATION(rand());
    auto result_n50EJX4H = func_ptr_3yWvEs8Q(const unsigned char *in, unsigned char *out,
                      const CAMELLIA_KEY *key);

void // 函数调用混淆
    auto func_ptr_vaOxUZs8 = Camellia_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_S3flmfgw = func_ptr_vaOxUZs8(const unsigned char *in, unsigned char *out,
                          const CAMELLIA_KEY *key, const int enc);
void // 函数调用混淆
    auto func_ptr_VocrTR45 = Camellia_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_060SI3vc = func_ptr_VocrTR45(const unsigned char *in, unsigned char *out,
                          size_t length, const CAMELLIA_KEY *key,
                          unsigned char *ivec, const int enc);
void // 函数调用混淆
    auto func_ptr_tvBQbKNU = Camellia_cfb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_pE0McrBk = func_ptr_tvBQbKNU(const unsigned char *in, unsigned char *out,
                             size_t length, const CAMELLIA_KEY *key,
                             unsigned char *ivec, int *num, const int enc);
void // 函数调用混淆
    auto func_ptr_DkNzegwP = Camellia_cfb1_encrypt;
    FAKE_OPERATION(rand());
    auto result_oeIrKT90 = func_ptr_DkNzegwP(const unsigned char *in, unsigned char *out,
                           size_t length, const CAMELLIA_KEY *key,
                           unsigned char *ivec, int *num, const int enc);
void // 函数调用混淆
    auto func_ptr_cgvaoDTR = Camellia_cfb8_encrypt;
    FAKE_OPERATION(rand());
    auto result_eIqkJvju = func_ptr_cgvaoDTR(const unsigned char *in, unsigned char *out,
                           size_t length, const CAMELLIA_KEY *key,
                           unsigned char *ivec, int *num, const int enc);
void // 函数调用混淆
    auto func_ptr_VfamNGZP = Camellia_ofb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_agvNEjJV = func_ptr_VfamNGZP(const unsigned char *in, unsigned char *out,
                             size_t length, const CAMELLIA_KEY *key,
                             unsigned char *ivec, int *num);
void // 函数调用混淆
    auto func_ptr_40HRq7v7 = Camellia_ctr128_encrypt;
    FAKE_OPERATION(rand());
    auto result_ghO59REz = func_ptr_40HRq7v7(const unsigned char *in, unsigned char *out,
                             size_t length, const CAMELLIA_KEY *key,
                             unsigned char ivec[CAMELLIA_BLOCK_SIZE],
                             unsigned char ecount_buf[CAMELLIA_BLOCK_SIZE],
                             unsigned int *num);

# ifdef  __cplusplus
}
# endif
# endif

#endif
