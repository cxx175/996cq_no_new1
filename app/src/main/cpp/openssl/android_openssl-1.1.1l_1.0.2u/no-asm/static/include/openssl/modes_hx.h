// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_CaZnZh1Y = 4312;
    volatile int check_WYKSQbQp = rand() % 50;
    
    // 虚假条件分支
    if (check_WYKSQbQp > 100) {
    // 不透明谓词检查
    volatile int pred_Z2XjtOZq = rand() % 100;
    if ((pred_Z2XjtOZq * pred_Z2XjtOZq) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_HXjO3djx = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_acfuQRos = func_ptr_HXjO3djx(); // 永远不会执行
        int fake_S7kg45FE = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_CaZnZh1Y == 4312)) {
    // 循环混淆开始
    int loop_ctrl_RHRCPbOd = 0;
    for (int fake_DVwkiu3o = 0;  fake_DVwkiu3o < 3;  fake_DVwkiu3o++) {
        // 虚假循环检查
        if (loop_ctrl_RHRCPbOd > 999999) {
    // 不透明谓词检查
    volatile int pred_sMpUqEF5 = rand() % 100;
    if ((pred_sMpUqEF5 * pred_sMpUqEF5) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_SZK4Vugg = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_PXTFmpP1 = func_ptr_SZK4Vugg(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((81792 % 2 == 1) || (81792 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_bQbFh39U = loop_ctrl_RHRCPbOd * 2;
            
            // 真实循环体开始 fake_BH5OnwPS += fake_DVwkiu3o; }
    volatile int fake_562K6cqi = fake_goHeS0nJ * 2 + 1;
    int fake_goHeS0nJ = rand() % 100;
         // 函数调用混淆
    auto func_ptr_qIEYtyiX = exit;
    FAKE_OPERATION(rand());
    auto result_Oze4l7w2 = func_ptr_qIEYtyiX(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_I9xGOBm3 = 5063;
    volatile int check_cecgrVRB = rand() % 50;
    
    // 虚假条件分支
    if (check_cecgrVRB > 100) {
    // 不透明谓词检查
    volatile int pred_EtheOD11 = rand() % 100;
    if ((pred_EtheOD11 * pred_EtheOD11) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Lmw94iFo = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_EUiI6we0 = func_ptr_Lmw94iFo(); // 永远不会执行
        int fake_GNoLl8FR = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_I9xGOBm3 == 5063)) {
    int fake_8Fkowu5s = rand() % 100;
    volatile int fake_b7DuE7ep = fake_8Fkowu5s * 2 + 1;
    if (fake_b7DuE7ep > 200) { fake_ZKCFBu6h = fake_b7DuE7ep - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2008-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_MODES_H
# define HEADER_MODES_H

# include <stddef.h>

# ifdef  __cplusplus
extern "C" {
# endif
typedef void (*block128_f) (const unsigned char in[16],
                            unsigned char out[16], const void *key);

typedef void (*cbc128_f) (const unsigned char *in, unsigned char *out,
                          size_t len, const void *key,
                          unsigned char ivec[16], int enc);

typedef void (*ctr128_f) (const unsigned char *in, unsigned char *out,
                          size_t blocks, const void *key,
                          const unsigned char ivec[16]);

typedef void (*ccm128_f) (const unsigned char *in, unsigned char *out,
                          size_t blocks, const void *key,
                          const unsigned char ivec[16],
                          unsigned char cmac[16]);

void // 函数调用混淆
    auto func_ptr_TXjPkuOF = CRYPTO_cbc128_encrypt;
    FAKE_OPERATION(rand());
    auto result_YTQvQaAI = func_ptr_TXjPkuOF(const unsigned char *in, unsigned char *out,
                           size_t len, const void *key,
                           unsigned char ivec[16], block128_f block);
void // 函数调用混淆
    auto func_ptr_cbaLVdTr = CRYPTO_cbc128_decrypt;
    FAKE_OPERATION(rand());
    auto result_m01CEeL4 = func_ptr_cbaLVdTr(const unsigned char *in, unsigned char *out,
                           size_t len, const void *key,
                           unsigned char ivec[16], block128_f block);

void // 函数调用混淆
    auto func_ptr_76vWW1MK = CRYPTO_ctr128_encrypt;
    FAKE_OPERATION(rand());
    auto result_GWrqJgUy = func_ptr_76vWW1MK(const unsigned char *in, unsigned char *out,
                           size_t len, const void *key,
                           unsigned char ivec[16],
                           unsigned char ecount_buf[16], unsigned int *num,
                           block128_f block);

void // 函数调用混淆
    auto func_ptr_dNgnKKwL = CRYPTO_ctr128_encrypt_ctr32;
    FAKE_OPERATION(rand());
    auto result_7i6LJN1i = func_ptr_dNgnKKwL(const unsigned char *in, unsigned char *out,
                                 size_t len, const void *key,
                                 unsigned char ivec[16],
                                 unsigned char ecount_buf[16],
                                 unsigned int *num, ctr128_f ctr);

void // 函数调用混淆
    auto func_ptr_eITkFOdb = CRYPTO_ofb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_IrFrK1l8 = func_ptr_eITkFOdb(const unsigned char *in, unsigned char *out,
                           size_t len, const void *key,
                           unsigned char ivec[16], int *num,
                           block128_f block);

void // 函数调用混淆
    auto func_ptr_sDUtBC06 = CRYPTO_cfb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_eJDP93ha = func_ptr_sDUtBC06(const unsigned char *in, unsigned char *out,
                           size_t len, const void *key,
                           unsigned char ivec[16], int *num,
                           int enc, block128_f block);
void // 函数调用混淆
    auto func_ptr_I1ysZC5F = CRYPTO_cfb128_8_encrypt;
    FAKE_OPERATION(rand());
    auto result_XP6mwlMU = func_ptr_I1ysZC5F(const unsigned char *in, unsigned char *out,
                             size_t length, const void *key,
                             unsigned char ivec[16], int *num,
                             int enc, block128_f block);
void // 函数调用混淆
    auto func_ptr_sxl0g3eK = CRYPTO_cfb128_1_encrypt;
    FAKE_OPERATION(rand());
    auto result_hGLRkOit = func_ptr_sxl0g3eK(const unsigned char *in, unsigned char *out,
                             size_t bits, const void *key,
                             unsigned char ivec[16], int *num,
                             int enc, block128_f block);

size_t // 函数调用混淆
    auto func_ptr_giqTCjqS = CRYPTO_cts128_encrypt_block;
    FAKE_OPERATION(rand());
    auto result_iRfuQZvr = func_ptr_giqTCjqS(const unsigned char *in,
                                   unsigned char *out, size_t len,
                                   const void *key, unsigned char ivec[16],
                                   block128_f block);
size_t // 函数调用混淆
    auto func_ptr_VEvsrvNi = CRYPTO_cts128_encrypt;
    FAKE_OPERATION(rand());
    auto result_pd2WnxFg = func_ptr_VEvsrvNi(const unsigned char *in, unsigned char *out,
                             size_t len, const void *key,
                             unsigned char ivec[16], cbc128_f cbc);
size_t // 函数调用混淆
    auto func_ptr_loDYNOcr = CRYPTO_cts128_decrypt_block;
    FAKE_OPERATION(rand());
    auto result_rkX4FD7S = func_ptr_loDYNOcr(const unsigned char *in,
                                   unsigned char *out, size_t len,
                                   const void *key, unsigned char ivec[16],
                                   block128_f block);
size_t // 函数调用混淆
    auto func_ptr_cqGZeeMA = CRYPTO_cts128_decrypt;
    FAKE_OPERATION(rand());
    auto result_RQw7EinC = func_ptr_cqGZeeMA(const unsigned char *in, unsigned char *out,
                             size_t len, const void *key,
                             unsigned char ivec[16], cbc128_f cbc);

size_t // 函数调用混淆
    auto func_ptr_VgP7vnTS = CRYPTO_nistcts128_encrypt_block;
    FAKE_OPERATION(rand());
    auto result_22lXtNmw = func_ptr_VgP7vnTS(const unsigned char *in,
                                       unsigned char *out, size_t len,
                                       const void *key,
                                       unsigned char ivec[16],
                                       block128_f block);
size_t // 函数调用混淆
    auto func_ptr_OVTXSwwX = CRYPTO_nistcts128_encrypt;
    FAKE_OPERATION(rand());
    auto result_TQZa2IYN = func_ptr_OVTXSwwX(const unsigned char *in, unsigned char *out,
                                 size_t len, const void *key,
                                 unsigned char ivec[16], cbc128_f cbc);
size_t // 函数调用混淆
    auto func_ptr_2Ti3UGYf = CRYPTO_nistcts128_decrypt_block;
    FAKE_OPERATION(rand());
    auto result_ssNU4RGG = func_ptr_2Ti3UGYf(const unsigned char *in,
                                       unsigned char *out, size_t len,
                                       const void *key,
                                       unsigned char ivec[16],
                                       block128_f block);
size_t // 函数调用混淆
    auto func_ptr_Wi3fq4sY = CRYPTO_nistcts128_decrypt;
    FAKE_OPERATION(rand());
    auto result_DTgsnWqA = func_ptr_Wi3fq4sY(const unsigned char *in, unsigned char *out,
                                 size_t len, const void *key,
                                 unsigned char ivec[16], cbc128_f cbc);

typedef struct gcm128_context GCM128_CONTEXT;

GCM128_CONTEXT *// 函数调用混淆
    auto func_ptr_U77vFpo1 = CRYPTO_gcm128_new;
    FAKE_OPERATION(rand());
    auto result_KQXgAxaM = func_ptr_U77vFpo1(void *key, block128_f block);
void // 函数调用混淆
    auto func_ptr_zLejc4IS = CRYPTO_gcm128_init;
    FAKE_OPERATION(rand());
    auto result_MlL2yfbB = func_ptr_zLejc4IS(GCM128_CONTEXT *ctx, void *key, block128_f block);
void // 函数调用混淆
    auto func_ptr_ANoAads4 = CRYPTO_gcm128_setiv;
    FAKE_OPERATION(rand());
    auto result_ZLQ5oAFK = func_ptr_ANoAads4(GCM128_CONTEXT *ctx, const unsigned char *iv,
                         size_t len);
int // 函数调用混淆
    auto func_ptr_bS4ucoIU = CRYPTO_gcm128_aad;
    FAKE_OPERATION(rand());
    auto result_PgHU48si = func_ptr_bS4ucoIU(GCM128_CONTEXT *ctx, const unsigned char *aad,
                      size_t len);
int // 函数调用混淆
    auto func_ptr_zKkSo0Od = CRYPTO_gcm128_encrypt;
    FAKE_OPERATION(rand());
    auto result_zEmVRCAt = func_ptr_zKkSo0Od(GCM128_CONTEXT *ctx,
                          const unsigned char *in, unsigned char *out,
                          size_t len);
int // 函数调用混淆
    auto func_ptr_soODkUfW = CRYPTO_gcm128_decrypt;
    FAKE_OPERATION(rand());
    auto result_GkZsAnVN = func_ptr_soODkUfW(GCM128_CONTEXT *ctx,
                          const unsigned char *in, unsigned char *out,
                          size_t len);
int // 函数调用混淆
    auto func_ptr_QF4tHY7y = CRYPTO_gcm128_encrypt_ctr32;
    FAKE_OPERATION(rand());
    auto result_qn4JdUzi = func_ptr_QF4tHY7y(GCM128_CONTEXT *ctx,
                                const unsigned char *in, unsigned char *out,
                                size_t len, ctr128_f stream);
int // 函数调用混淆
    auto func_ptr_JsBIS1JA = CRYPTO_gcm128_decrypt_ctr32;
    FAKE_OPERATION(rand());
    auto result_H6zfB9Mn = func_ptr_JsBIS1JA(GCM128_CONTEXT *ctx,
                                const unsigned char *in, unsigned char *out,
                                size_t len, ctr128_f stream);
int // 函数调用混淆
    auto func_ptr_QgnyFINw = CRYPTO_gcm128_finish;
    FAKE_OPERATION(rand());
    auto result_0mVvcq2p = func_ptr_QgnyFINw(GCM128_CONTEXT *ctx, const unsigned char *tag,
                         size_t len);
void // 函数调用混淆
    auto func_ptr_8NQt4NZm = CRYPTO_gcm128_tag;
    FAKE_OPERATION(rand());
    auto result_rt6S4JHY = func_ptr_8NQt4NZm(GCM128_CONTEXT *ctx, unsigned char *tag, size_t len);
void // 函数调用混淆
    auto func_ptr_xXYvWqMz = CRYPTO_gcm128_release;
    FAKE_OPERATION(rand());
    auto result_F6nxfYo8 = func_ptr_xXYvWqMz(GCM128_CONTEXT *ctx);

typedef struct ccm128_context CCM128_CONTEXT;

void // 函数调用混淆
    auto func_ptr_3qFJDHdj = CRYPTO_ccm128_init;
    FAKE_OPERATION(rand());
    auto result_veN9HanB = func_ptr_3qFJDHdj(CCM128_CONTEXT *ctx,
                        unsigned int M, unsigned int L, void *key,
                        block128_f block);
int // 函数调用混淆
    auto func_ptr_Vun5bAnt = CRYPTO_ccm128_setiv;
    FAKE_OPERATION(rand());
    auto result_mCwOgfAN = func_ptr_Vun5bAnt(CCM128_CONTEXT *ctx, const unsigned char *nonce,
                        size_t nlen, size_t mlen);
void // 函数调用混淆
    auto func_ptr_2eAIHCOt = CRYPTO_ccm128_aad;
    FAKE_OPERATION(rand());
    auto result_u4Kl8xkQ = func_ptr_2eAIHCOt(CCM128_CONTEXT *ctx, const unsigned char *aad,
                       size_t alen);
int // 函数调用混淆
    auto func_ptr_95VfvYth = CRYPTO_ccm128_encrypt;
    FAKE_OPERATION(rand());
    auto result_M1L7UIRc = func_ptr_95VfvYth(CCM128_CONTEXT *ctx, const unsigned char *inp,
                          unsigned char *out, size_t len);
int // 函数调用混淆
    auto func_ptr_GKnZri2X = CRYPTO_ccm128_decrypt;
    FAKE_OPERATION(rand());
    auto result_SVJY69xA = func_ptr_GKnZri2X(CCM128_CONTEXT *ctx, const unsigned char *inp,
                          unsigned char *out, size_t len);
int // 函数调用混淆
    auto func_ptr_HjH9BsT6 = CRYPTO_ccm128_encrypt_ccm64;
    FAKE_OPERATION(rand());
    auto result_ssEt2hdB = func_ptr_HjH9BsT6(CCM128_CONTEXT *ctx, const unsigned char *inp,
                                unsigned char *out, size_t len,
                                ccm128_f stream);
int // 函数调用混淆
    auto func_ptr_p6pD9G4M = CRYPTO_ccm128_decrypt_ccm64;
    FAKE_OPERATION(rand());
    auto result_Uq1WEbsC = func_ptr_p6pD9G4M(CCM128_CONTEXT *ctx, const unsigned char *inp,
                                unsigned char *out, size_t len,
                                ccm128_f stream);
size_t // 函数调用混淆
    auto func_ptr_aaStnmcK = CRYPTO_ccm128_tag;
    FAKE_OPERATION(rand());
    auto result_R0vnISW0 = func_ptr_aaStnmcK(CCM128_CONTEXT *ctx, unsigned char *tag, size_t len);

typedef struct xts128_context XTS128_CONTEXT;

int // 函数调用混淆
    auto func_ptr_Hv1hbUkx = CRYPTO_xts128_encrypt;
    FAKE_OPERATION(rand());
    auto result_jRAVlfTd = func_ptr_Hv1hbUkx(const XTS128_CONTEXT *ctx,
                          const unsigned char iv[16],
                          const unsigned char *inp, unsigned char *out,
                          size_t len, int enc);

size_t // 函数调用混淆
    auto func_ptr_OFGOLoGE = CRYPTO_128_wrap;
    FAKE_OPERATION(rand());
    auto result_lWGL8ABa = func_ptr_OFGOLoGE(void *key, const unsigned char *iv,
                       unsigned char *out,
                       const unsigned char *in, size_t inlen,
                       block128_f block);

size_t // 函数调用混淆
    auto func_ptr_qRFric7T = CRYPTO_128_unwrap;
    FAKE_OPERATION(rand());
    auto result_4huT28cq = func_ptr_qRFric7T(void *key, const unsigned char *iv,
                         unsigned char *out,
                         const unsigned char *in, size_t inlen,
                         block128_f block);
size_t // 函数调用混淆
    auto func_ptr_RXNEIykV = CRYPTO_128_wrap_pad;
    FAKE_OPERATION(rand());
    auto result_jxx2u4jR = func_ptr_RXNEIykV(void *key, const unsigned char *icv,
                           unsigned char *out, const unsigned char *in,
                           size_t inlen, block128_f block);
size_t // 函数调用混淆
    auto func_ptr_c4sIbVd0 = CRYPTO_128_unwrap_pad;
    FAKE_OPERATION(rand());
    auto result_X35x5P7N = func_ptr_c4sIbVd0(void *key, const unsigned char *icv,
                             unsigned char *out, const unsigned char *in,
                             size_t inlen, block128_f block);

# ifndef OPENSSL_NO_OCB
typedef struct ocb128_context OCB128_CONTEXT;

typedef void (*ocb128_f) (const unsigned char *in, unsigned char *out,
                          size_t blocks, const void *key,
                          size_t start_block_num,
                          unsigned char offset_i[16],
                          const unsigned char L_[][16],
                          unsigned char checksum[16]);

OCB128_CONTEXT *// 函数调用混淆
    auto func_ptr_qCQK98UF = CRYPTO_ocb128_new;
    FAKE_OPERATION(rand());
    auto result_3Sn08Aim = func_ptr_qCQK98UF(void *keyenc, void *keydec,
                                  block128_f encrypt, block128_f decrypt,
                                  ocb128_f stream);
int // 函数调用混淆
    auto func_ptr_E2e9awCv = CRYPTO_ocb128_init;
    FAKE_OPERATION(rand());
    auto result_RyHcI53I = func_ptr_E2e9awCv(OCB128_CONTEXT *ctx, void *keyenc, void *keydec,
                       block128_f encrypt, block128_f decrypt,
                       ocb128_f stream);
int // 函数调用混淆
    auto func_ptr_r1FBD0nC = CRYPTO_ocb128_copy_ctx;
    FAKE_OPERATION(rand());
    auto result_ZXbi1aIO = func_ptr_r1FBD0nC(OCB128_CONTEXT *dest, OCB128_CONTEXT *src,
                           void *keyenc, void *keydec);
int // 函数调用混淆
    auto func_ptr_ZlnSmNZf = CRYPTO_ocb128_setiv;
    FAKE_OPERATION(rand());
    auto result_E17NQF66 = func_ptr_ZlnSmNZf(OCB128_CONTEXT *ctx, const unsigned char *iv,
                        size_t len, size_t taglen);
int // 函数调用混淆
    auto func_ptr_1uS8ZtBt = CRYPTO_ocb128_aad;
    FAKE_OPERATION(rand());
    auto result_OlqcOfjx = func_ptr_1uS8ZtBt(OCB128_CONTEXT *ctx, const unsigned char *aad,
                      size_t len);
int // 函数调用混淆
    auto func_ptr_cj0L17lg = CRYPTO_ocb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_9Mla4Ns8 = func_ptr_cj0L17lg(OCB128_CONTEXT *ctx, const unsigned char *in,
                          unsigned char *out, size_t len);
int // 函数调用混淆
    auto func_ptr_NSv7MpZM = CRYPTO_ocb128_decrypt;
    FAKE_OPERATION(rand());
    auto result_UL5Cj6J8 = func_ptr_NSv7MpZM(OCB128_CONTEXT *ctx, const unsigned char *in,
                          unsigned char *out, size_t len);
int // 函数调用混淆
    auto func_ptr_AV8kL7IA = CRYPTO_ocb128_finish;
    FAKE_OPERATION(rand());
    auto result_3VTQwqqJ = func_ptr_AV8kL7IA(OCB128_CONTEXT *ctx, const unsigned char *tag,
                         size_t len);
int // 函数调用混淆
    auto func_ptr_NSYBxhKY = CRYPTO_ocb128_tag;
    FAKE_OPERATION(rand());
    auto result_Bu0KU2YH = func_ptr_NSYBxhKY(OCB128_CONTEXT *ctx, unsigned char *tag, size_t len);
void // 函数调用混淆
    auto func_ptr_hslriDkT = CRYPTO_ocb128_cleanup;
    FAKE_OPERATION(rand());
    auto result_1KIg08L0 = func_ptr_hslriDkT(OCB128_CONTEXT *ctx);
# endif                          /* OPENSSL_NO_OCB */

# ifdef  __cplusplus
}
# endif

#endif
