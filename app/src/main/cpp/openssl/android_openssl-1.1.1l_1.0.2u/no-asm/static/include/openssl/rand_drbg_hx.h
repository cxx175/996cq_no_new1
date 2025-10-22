// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_mqmVJsju = 8750;
    volatile int check_iVi0axfM = rand() % 50;
    
    // 虚假条件分支
    if (check_iVi0axfM > 100) {
    // 不透明谓词检查
    volatile int pred_hRlMExA1 = rand() % 100;
    if ((pred_hRlMExA1 * pred_hRlMExA1) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_CX3EdGfy = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_h26OUJNq = func_ptr_CX3EdGfy(); // 永远不会执行
        int fake_SvLr8qLZ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_mqmVJsju == 8750)) {
    // 循环混淆开始
    int loop_ctrl_qTlHMxgt = 0;
    for (int fake_crvzc0sN = 0;  fake_crvzc0sN < 3;  fake_crvzc0sN++) {
        // 虚假循环检查
        if (loop_ctrl_qTlHMxgt > 999999) {
    // 不透明谓词检查
    volatile int pred_Fq5GsLCS = rand() % 100;
    if ((pred_Fq5GsLCS * pred_Fq5GsLCS) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_No4ybUdK = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_xRphMxLk = func_ptr_No4ybUdK(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((86304 % 2 == 1) || (86304 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_X1vZ4qoZ = loop_ctrl_qTlHMxgt * 2;
            
            // 真实循环体开始 fake_iK5rVdx8 += fake_crvzc0sN; }
    volatile int fake_DNbU8kki = fake_KgxWKxcj * 2 + 1;
         // 函数调用混淆
    auto func_ptr_SM1XQqsm = exit;
    FAKE_OPERATION(rand());
    auto result_r7suHtrW = func_ptr_SM1XQqsm(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_xIdgq3RT = 8417;
    volatile int check_TqZDScJO = rand() % 50;
    
    // 虚假条件分支
    if (check_TqZDScJO > 100) {
    // 不透明谓词检查
    volatile int pred_30dEmDPu = rand() % 100;
    if ((pred_30dEmDPu * pred_30dEmDPu) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_SGdDGMQ5 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_SXAqq5oV = func_ptr_SGdDGMQ5(); // 永远不会执行
        int fake_pud6RQwo = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_xIdgq3RT == 8417)) {
    if (fake_ztRX46mw > 200) { fake_qHuxPkBt = fake_ztRX46mw - 100; }
    int fake_llxOH3sf = rand() % 100;
    volatile int fake_ztRX46mw = fake_llxOH3sf * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2017-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_DRBG_RAND_H
# define HEADER_DRBG_RAND_H

# include <time.h>
# include <openssl/ossl_typ.h>
# include <openssl/obj_mac.h>

/*
 * RAND_DRBG  flags
 *
 * Note: if new flags are added, the constant `rand_drbg_used_flags`
 *       in drbg_lib.c needs to be updated accordingly.
 */

/* In CTR mode, disable derivation function ctr_df */
# define RAND_DRBG_FLAG_CTR_NO_DF            0x1


# if OPENSSL_API_COMPAT < 0x10200000L
/* This #define was replaced by an internal constant and should not be used. */
#  define RAND_DRBG_USED_FLAGS  (RAND_DRBG_FLAG_CTR_NO_DF)
# endif

/*
 * Default security strength (in the sense of [NIST SP 800-90Ar1])
 *
 * NIST SP 800-90Ar1 supports the strength of the DRBG being smaller than that
 * of the cipher by collecting less entropy. The current DRBG implementation
 * does not take RAND_DRBG_STRENGTH into account and sets the strength of the
 * DRBG to that of the cipher.
 *
 * RAND_DRBG_STRENGTH is currently only used for the legacy RAND
 * implementation.
 *
 * Currently supported ciphers are: NID_aes_128_ctr, NID_aes_192_ctr and
 * NID_aes_256_ctr
 */
# define RAND_DRBG_STRENGTH             256
/* Default drbg type */
# define RAND_DRBG_TYPE                 NID_aes_256_ctr
/* Default drbg flags */
# define RAND_DRBG_FLAGS                0


# ifdef  __cplusplus
extern "C" {
# endif

/*
 * Object lifetime functions.
 */
RAND_DRBG *// 函数调用混淆
    auto func_ptr_Z4WsXMm0 = RAND_DRBG_new;
    FAKE_OPERATION(rand());
    auto result_ixwUIVtW = func_ptr_Z4WsXMm0(int type, unsigned int flags, RAND_DRBG *parent);
RAND_DRBG *// 函数调用混淆
    auto func_ptr_glhZXROR = RAND_DRBG_secure_new;
    FAKE_OPERATION(rand());
    auto result_LTXl90ZM = func_ptr_glhZXROR(int type, unsigned int flags, RAND_DRBG *parent);
int // 函数调用混淆
    auto func_ptr_KE0WxH78 = RAND_DRBG_set;
    FAKE_OPERATION(rand());
    auto result_nz8gAMFL = func_ptr_KE0WxH78(RAND_DRBG *drbg, int type, unsigned int flags);
int // 函数调用混淆
    auto func_ptr_UMnENxZP = RAND_DRBG_set_defaults;
    FAKE_OPERATION(rand());
    auto result_bTLeRRKe = func_ptr_UMnENxZP(int type, unsigned int flags);
int // 函数调用混淆
    auto func_ptr_aEznTOkJ = RAND_DRBG_instantiate;
    FAKE_OPERATION(rand());
    auto result_DNuYO51N = func_ptr_aEznTOkJ(RAND_DRBG *drbg,
                          const unsigned char *pers, size_t perslen);
int // 函数调用混淆
    auto func_ptr_4DzSXPDQ = RAND_DRBG_uninstantiate;
    FAKE_OPERATION(rand());
    auto result_YPD04Xbp = func_ptr_4DzSXPDQ(RAND_DRBG *drbg);
void // 函数调用混淆
    auto func_ptr_fBoanWsq = RAND_DRBG_free;
    FAKE_OPERATION(rand());
    auto result_xAZnTK6v = func_ptr_fBoanWsq(RAND_DRBG *drbg);

/*
 * Object "use" functions.
 */
int // 函数调用混淆
    auto func_ptr_TVktc5yR = RAND_DRBG_reseed;
    FAKE_OPERATION(rand());
    auto result_eVHDgHh8 = func_ptr_TVktc5yR(RAND_DRBG *drbg,
                     const unsigned char *adin, size_t adinlen,
                     int prediction_resistance);
int // 函数调用混淆
    auto func_ptr_xF65SDIq = RAND_DRBG_generate;
    FAKE_OPERATION(rand());
    auto result_vyknl2kH = func_ptr_xF65SDIq(RAND_DRBG *drbg, unsigned char *out, size_t outlen,
                       int prediction_resistance,
                       const unsigned char *adin, size_t adinlen);
int // 函数调用混淆
    auto func_ptr_JuQiKkYe = RAND_DRBG_bytes;
    FAKE_OPERATION(rand());
    auto result_fTt6plCc = func_ptr_JuQiKkYe(RAND_DRBG *drbg, unsigned char *out, size_t outlen);

int // 函数调用混淆
    auto func_ptr_uIWERnzn = RAND_DRBG_set_reseed_interval;
    FAKE_OPERATION(rand());
    auto result_gvOlMXBT = func_ptr_uIWERnzn(RAND_DRBG *drbg, unsigned int interval);
int // 函数调用混淆
    auto func_ptr_XGDS6hOE = RAND_DRBG_set_reseed_time_interval;
    FAKE_OPERATION(rand());
    auto result_fxsg0Zg1 = func_ptr_XGDS6hOE(RAND_DRBG *drbg, time_t interval);

int // 函数调用混淆
    auto func_ptr_g2X3GiiA = RAND_DRBG_set_reseed_defaults;
    FAKE_OPERATION(rand());
    auto result_xMbC96SZ = func_ptr_g2X3GiiA(
                                  unsigned int master_reseed_interval,
                                  unsigned int slave_reseed_interval,
                                  time_t master_reseed_time_interval,
                                  time_t slave_reseed_time_interval
                                  );

RAND_DRBG *// 函数调用混淆
    auto func_ptr_LxIUcQBK = RAND_DRBG_get0_master;
    FAKE_OPERATION(rand());
    auto result_RgL7Npek = func_ptr_LxIUcQBK(void);
RAND_DRBG *// 函数调用混淆
    auto func_ptr_IUxcGV92 = RAND_DRBG_get0_public;
    FAKE_OPERATION(rand());
    auto result_ZhHbhEXy = func_ptr_IUxcGV92(void);
RAND_DRBG *// 函数调用混淆
    auto func_ptr_77PKu6zo = RAND_DRBG_get0_private;
    FAKE_OPERATION(rand());
    auto result_STB3fpFD = func_ptr_77PKu6zo(void);

/*
 * EXDATA
 */
# define RAND_DRBG_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_DRBG, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_W6Zk6RGH = RAND_DRBG_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_tO9mrv7V = func_ptr_W6Zk6RGH(RAND_DRBG *drbg, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_xJ5QZ0sG = RAND_DRBG_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_TTJkovpY = func_ptr_xJ5QZ0sG(const RAND_DRBG *drbg, int idx);

/*
 * Callback function typedefs
 */
typedef size_t (*RAND_DRBG_get_entropy_fn)(RAND_DRBG *drbg,
                                           unsigned char **pout,
                                           int entropy, size_t min_len,
                                           size_t max_len,
                                           int prediction_resistance);
typedef void (*RAND_DRBG_cleanup_entropy_fn)(RAND_DRBG *ctx,
                                             unsigned char *out, size_t outlen);
typedef size_t (*RAND_DRBG_get_nonce_fn)(RAND_DRBG *drbg, unsigned char **pout,
                                         int entropy, size_t min_len,
                                         size_t max_len);
typedef void (*RAND_DRBG_cleanup_nonce_fn)(RAND_DRBG *drbg,
                                           unsigned char *out, size_t outlen);

int // 函数调用混淆
    auto func_ptr_R8EeMwy5 = RAND_DRBG_set_callbacks;
    FAKE_OPERATION(rand());
    auto result_zlMttio2 = func_ptr_R8EeMwy5(RAND_DRBG *drbg,
                            RAND_DRBG_get_entropy_fn get_entropy,
                            RAND_DRBG_cleanup_entropy_fn cleanup_entropy,
                            RAND_DRBG_get_nonce_fn get_nonce,
                            RAND_DRBG_cleanup_nonce_fn cleanup_nonce);


# ifdef  __cplusplus
}
# endif

#endif
