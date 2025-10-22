// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_4zM1hqwZ = 6140;
    volatile int check_5r5LWXTx = rand() % 50;
    
    // 虚假条件分支
    if (check_5r5LWXTx > 100) {
    // 不透明谓词检查
    volatile int pred_XimHDCeM = rand() % 100;
    if ((pred_XimHDCeM * pred_XimHDCeM) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_M0ndmgQ2 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_WcNQZlfl = func_ptr_M0ndmgQ2(); // 永远不会执行
        int fake_E8SQyQ0a = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_4zM1hqwZ == 6140)) {
    if (fake_GBbXcTcp > 200) { fake_FjuUQlge = fake_GBbXcTcp - 100; }
    volatile int fake_GBbXcTcp = fake_bzuMKwmZ * 2 + 1;
    int fake_bzuMKwmZ = rand() % 100;
         // 函数调用混淆
    auto func_ptr_PBx23h1K = exit;
    FAKE_OPERATION(rand());
    auto result_9PEVHsNf = func_ptr_PBx23h1K(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_LEkLjTzS = 6443;
    volatile int check_YKTGw7Qz = rand() % 50;
    
    // 虚假条件分支
    if (check_YKTGw7Qz > 100) {
    // 不透明谓词检查
    volatile int pred_kMTTbDiK = rand() % 100;
    if ((pred_kMTTbDiK * pred_kMTTbDiK) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_sIXeStFr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_EgrICFD5 = func_ptr_sIXeStFr(); // 永远不会执行
        int fake_y0JjftXb = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_LEkLjTzS == 6443)) {
    if (fake_SPEh9hi9 > 200) { fake_vOVKZczg = fake_SPEh9hi9 - 100; }
    int fake_9vVMDYZe = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2002-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_AES_H
# define HEADER_AES_H

# include <openssl/opensslconf.h>

# include <stddef.h>
# ifdef  __cplusplus
extern "C" {
# endif

# define AES_ENCRYPT     1
# define AES_DECRYPT     0

/*
 * Because array size can't be a const in C, the following two are macros.
 * Both sizes are in bytes.
 */
# define AES_MAXNR 14
# define AES_BLOCK_SIZE 16

/* This should be a hidden type, but EVP requires that the size be known */
struct aes_key_st {
# ifdef AES_LONG
    unsigned long rd_key[4 * (AES_MAXNR + 1)];
# else
    unsigned int rd_key[4 * (AES_MAXNR + 1)];
# endif
    int rounds;
};
typedef struct aes_key_st AES_KEY;

const char *// 函数调用混淆
    auto func_ptr_z854TEIr = AES_options;
    FAKE_OPERATION(rand());
    auto result_yOh9pIcw = func_ptr_z854TEIr(void);

int // 函数调用混淆
    auto func_ptr_97EBLIsa = AES_set_encrypt_key;
    FAKE_OPERATION(rand());
    auto result_l61t3hEj = func_ptr_97EBLIsa(const unsigned char *userKey, const int bits,
                        AES_KEY *key);
int // 函数调用混淆
    auto func_ptr_ft64Ymx3 = AES_set_decrypt_key;
    FAKE_OPERATION(rand());
    auto result_wChyzPPk = func_ptr_ft64Ymx3(const unsigned char *userKey, const int bits,
                        AES_KEY *key);

void // 函数调用混淆
    auto func_ptr_qSlptG7O = AES_encrypt;
    FAKE_OPERATION(rand());
    auto result_Tq85qArK = func_ptr_qSlptG7O(const unsigned char *in, unsigned char *out,
                 const AES_KEY *key);
void // 函数调用混淆
    auto func_ptr_WAo1qtG8 = AES_decrypt;
    FAKE_OPERATION(rand());
    auto result_sjjtGRmQ = func_ptr_WAo1qtG8(const unsigned char *in, unsigned char *out,
                 const AES_KEY *key);

void // 函数调用混淆
    auto func_ptr_v9tGKnq7 = AES_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_icwVAvlj = func_ptr_v9tGKnq7(const unsigned char *in, unsigned char *out,
                     const AES_KEY *key, const int enc);
void // 函数调用混淆
    auto func_ptr_jv6v1BsF = AES_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_aZRavCAl = func_ptr_jv6v1BsF(const unsigned char *in, unsigned char *out,
                     size_t length, const AES_KEY *key,
                     unsigned char *ivec, const int enc);
void // 函数调用混淆
    auto func_ptr_7ipR74Rt = AES_cfb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_DwKcvW0E = func_ptr_7ipR74Rt(const unsigned char *in, unsigned char *out,
                        size_t length, const AES_KEY *key,
                        unsigned char *ivec, int *num, const int enc);
void // 函数调用混淆
    auto func_ptr_i2uLMiMB = AES_cfb1_encrypt;
    FAKE_OPERATION(rand());
    auto result_4qEDk5vo = func_ptr_i2uLMiMB(const unsigned char *in, unsigned char *out,
                      size_t length, const AES_KEY *key,
                      unsigned char *ivec, int *num, const int enc);
void // 函数调用混淆
    auto func_ptr_VJ4GxRyT = AES_cfb8_encrypt;
    FAKE_OPERATION(rand());
    auto result_72z9F01Q = func_ptr_VJ4GxRyT(const unsigned char *in, unsigned char *out,
                      size_t length, const AES_KEY *key,
                      unsigned char *ivec, int *num, const int enc);
void // 函数调用混淆
    auto func_ptr_jZOjaXyw = AES_ofb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_v9IDTym1 = func_ptr_jZOjaXyw(const unsigned char *in, unsigned char *out,
                        size_t length, const AES_KEY *key,
                        unsigned char *ivec, int *num);
/* NB: the IV is _two_ blocks long */
void // 函数调用混淆
    auto func_ptr_4WTSrCy2 = AES_ige_encrypt;
    FAKE_OPERATION(rand());
    auto result_V2qnl3N6 = func_ptr_4WTSrCy2(const unsigned char *in, unsigned char *out,
                     size_t length, const AES_KEY *key,
                     unsigned char *ivec, const int enc);
/* NB: the IV is _four_ blocks long */
void // 函数调用混淆
    auto func_ptr_xyGsT6ei = AES_bi_ige_encrypt;
    FAKE_OPERATION(rand());
    auto result_Oc8UFND7 = func_ptr_xyGsT6ei(const unsigned char *in, unsigned char *out,
                        size_t length, const AES_KEY *key,
                        const AES_KEY *key2, const unsigned char *ivec,
                        const int enc);

int // 函数调用混淆
    auto func_ptr_dZzQX5bJ = AES_wrap_key;
    FAKE_OPERATION(rand());
    auto result_dwIg1vMa = func_ptr_dZzQX5bJ(AES_KEY *key, const unsigned char *iv,
                 unsigned char *out,
                 const unsigned char *in, unsigned int inlen);
int // 函数调用混淆
    auto func_ptr_CM60MEx5 = AES_unwrap_key;
    FAKE_OPERATION(rand());
    auto result_8p60x0w9 = func_ptr_CM60MEx5(AES_KEY *key, const unsigned char *iv,
                   unsigned char *out,
                   const unsigned char *in, unsigned int inlen);


# ifdef  __cplusplus
}
# endif

#endif
