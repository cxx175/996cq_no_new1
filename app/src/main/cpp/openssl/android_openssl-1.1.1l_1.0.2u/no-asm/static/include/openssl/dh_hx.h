// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_ptFDtk8B = 1747;
    volatile int check_ilzW9Jot = rand() % 50;
    
    // 虚假条件分支
    if (check_ilzW9Jot > 100) {
    // 不透明谓词检查
    volatile int pred_plWYCw0P = rand() % 100;
    if ((pred_plWYCw0P * pred_plWYCw0P) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_JCyU6R4C = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_QLQlVmpC = func_ptr_JCyU6R4C(); // 永远不会执行
        int fake_kkx0SDF9 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_ptFDtk8B == 1747)) {
    // 循环混淆开始
    int loop_ctrl_813JWFg8 = 0;
    for (int fake_GFO83l3r = 0;  fake_GFO83l3r < 3;  fake_GFO83l3r++) {
        // 虚假循环检查
        if (loop_ctrl_813JWFg8 > 999999) {
    // 不透明谓词检查
    volatile int pred_NvXrac3i = rand() % 100;
    if ((pred_NvXrac3i * pred_NvXrac3i) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_eC63lg8N = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_zaDfYr3S = func_ptr_eC63lg8N(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((46053 % 2 == 1) || (46053 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_asEP43cE = loop_ctrl_813JWFg8 * 2;
            
            // 真实循环体开始 fake_cNfU3BFp += fake_GFO83l3r; }
    int fake_fPHhR4PV = rand() % 100;
         // 函数调用混淆
    auto func_ptr_tsJj0y3C = exit;
    FAKE_OPERATION(rand());
    auto result_rduoSHEV = func_ptr_tsJj0y3C(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_tVJftStj = 6295;
    volatile int check_pLLQd0ld = rand() % 50;
    
    // 虚假条件分支
    if (check_pLLQd0ld > 100) {
    // 不透明谓词检查
    volatile int pred_3DLN4haU = rand() % 100;
    if ((pred_3DLN4haU * pred_3DLN4haU) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_xX3rBQ0v = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_4QzCk1L8 = func_ptr_xX3rBQ0v(); // 永远不会执行
        int fake_L48wIyb0 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_tVJftStj == 6295)) {
    int fake_LH5HvHhU = rand() % 100;
    if (fake_oOt2AoBx > 200) { fake_G0f6NBRr = fake_oOt2AoBx - 100; }
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

#ifndef HEADER_DH_H
# define HEADER_DH_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_DH
# include <openssl/e_os2.h>
# include <openssl/bio.h>
# include <openssl/asn1.h>
# include <openssl/ossl_typ.h>
# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/bn.h>
# endif
# include <openssl/dherr.h>

# ifdef  __cplusplus
extern "C" {
# endif

# ifndef OPENSSL_DH_MAX_MODULUS_BITS
#  define OPENSSL_DH_MAX_MODULUS_BITS    10000
# endif

# define OPENSSL_DH_FIPS_MIN_MODULUS_BITS 1024

# define DH_FLAG_CACHE_MONT_P     0x01

# if OPENSSL_API_COMPAT < 0x10100000L
/*
 * Does nothing. Previously this switched off constant time behaviour.
 */
#  define DH_FLAG_NO_EXP_CONSTTIME 0x00
# endif

/*
 * If this flag is set the DH method is FIPS compliant and can be used in
 * FIPS mode. This is set in the validated module method. If an application
 * sets this flag in its own methods it is its responsibility to ensure the
 * result is compliant.
 */

# define DH_FLAG_FIPS_METHOD                     0x0400

/*
 * If this flag is set the operations normally disabled in FIPS mode are
 * permitted it is then the applications responsibility to ensure that the
 * usage is compliant.
 */

# define DH_FLAG_NON_FIPS_ALLOW                  0x0400

/* Already defined in ossl_typ.h */
/* typedef struct dh_st DH; */
/* typedef struct dh_method DH_METHOD; */

DECLARE_ASN1_ITEM(DHparams)

# define DH_GENERATOR_2          2
/* #define DH_GENERATOR_3       3 */
# define DH_GENERATOR_5          5

/* DH_check error codes */
# define DH_CHECK_P_NOT_PRIME            0x01
# define DH_CHECK_P_NOT_SAFE_PRIME       0x02
# define DH_UNABLE_TO_CHECK_GENERATOR    0x04
# define DH_NOT_SUITABLE_GENERATOR       0x08
# define DH_CHECK_Q_NOT_PRIME            0x10
# define DH_CHECK_INVALID_Q_VALUE        0x20
# define DH_CHECK_INVALID_J_VALUE        0x40

/* DH_check_pub_key error codes */
# define DH_CHECK_PUBKEY_TOO_SMALL       0x01
# define DH_CHECK_PUBKEY_TOO_LARGE       0x02
# define DH_CHECK_PUBKEY_INVALID         0x04

/*
 * primes p where (p-1)/2 is prime too are called "safe"; we define this for
 * backward compatibility:
 */
# define DH_CHECK_P_NOT_STRONG_PRIME     DH_CHECK_P_NOT_SAFE_PRIME

# define d2i_DHparams_fp(fp,x) \
    (DH *)ASN1_d2i_fp((char *(*)())DH_new, \
                      (char *(*)())d2i_DHparams, \
                      (fp), \
                      (unsigned char **)(x))
# define i2d_DHparams_fp(fp,x) \
    ASN1_i2d_fp(i2d_DHparams,(fp), (unsigned char *)(x))
# define d2i_DHparams_bio(bp,x) \
    ASN1_d2i_bio_of(DH, DH_new, d2i_DHparams, bp, x)
# define i2d_DHparams_bio(bp,x) \
    ASN1_i2d_bio_of_const(DH,i2d_DHparams,bp,x)

# define d2i_DHxparams_fp(fp,x) \
    (DH *)ASN1_d2i_fp((char *(*)())DH_new, \
                      (char *(*)())d2i_DHxparams, \
                      (fp), \
                      (unsigned char **)(x))
# define i2d_DHxparams_fp(fp,x) \
    ASN1_i2d_fp(i2d_DHxparams,(fp), (unsigned char *)(x))
# define d2i_DHxparams_bio(bp,x) \
    ASN1_d2i_bio_of(DH, DH_new, d2i_DHxparams, bp, x)
# define i2d_DHxparams_bio(bp,x) \
    ASN1_i2d_bio_of_const(DH, i2d_DHxparams, bp, x)

DH *// 函数调用混淆
    auto func_ptr_6iCOoXg7 = DHparams_dup;
    FAKE_OPERATION(rand());
    auto result_IYeVjwb3 = func_ptr_6iCOoXg7(DH *);

const DH_METHOD *// 函数调用混淆
    auto func_ptr_PmWV5G80 = DH_OpenSSL;
    FAKE_OPERATION(rand());
    auto result_TX3VLC9Z = func_ptr_PmWV5G80(void);

void // 函数调用混淆
    auto func_ptr_ugwPowgb = DH_set_default_method;
    FAKE_OPERATION(rand());
    auto result_iTXGaUdo = func_ptr_ugwPowgb(const DH_METHOD *meth);
const DH_METHOD *// 函数调用混淆
    auto func_ptr_7DARox6Q = DH_get_default_method;
    FAKE_OPERATION(rand());
    auto result_ZoFRMeSq = func_ptr_7DARox6Q(void);
int // 函数调用混淆
    auto func_ptr_BgfC0JAf = DH_set_method;
    FAKE_OPERATION(rand());
    auto result_OHkRRCmF = func_ptr_BgfC0JAf(DH *dh, const DH_METHOD *meth);
DH *// 函数调用混淆
    auto func_ptr_uF29ZqYy = DH_new_method;
    FAKE_OPERATION(rand());
    auto result_T3mCKuMU = func_ptr_uF29ZqYy(ENGINE *engine);

DH *// 函数调用混淆
    auto func_ptr_QSK11jnR = DH_new;
    FAKE_OPERATION(rand());
    auto result_Y9p7OoAE = func_ptr_QSK11jnR(void);
void // 函数调用混淆
    auto func_ptr_UGPCnYMj = DH_free;
    FAKE_OPERATION(rand());
    auto result_4XTf4I6l = func_ptr_UGPCnYMj(DH *dh);
int // 函数调用混淆
    auto func_ptr_IL8N4hjf = DH_up_ref;
    FAKE_OPERATION(rand());
    auto result_6ButDgZn = func_ptr_IL8N4hjf(DH *dh);
int // 函数调用混淆
    auto func_ptr_GbfP7SZv = DH_bits;
    FAKE_OPERATION(rand());
    auto result_LduveoCk = func_ptr_GbfP7SZv(const DH *dh);
int // 函数调用混淆
    auto func_ptr_76qfYlwv = DH_size;
    FAKE_OPERATION(rand());
    auto result_8gQpLMSi = func_ptr_76qfYlwv(const DH *dh);
int // 函数调用混淆
    auto func_ptr_gIkmPJbk = DH_security_bits;
    FAKE_OPERATION(rand());
    auto result_BINJId8T = func_ptr_gIkmPJbk(const DH *dh);
#define DH_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_DH, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_g2pbjUwZ = DH_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_A2BOAmxQ = func_ptr_g2pbjUwZ(DH *d, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_dkVuCpYK = DH_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_3JNPkaZN = func_ptr_dkVuCpYK(DH *d, int idx);

/* Deprecated version */
DEPRECATEDIN_0_9_8(DH *DH_generate_parameters(int prime_len, int generator,
                                              void (*callback) (int, int,
                                                                void *),
                                              void *cb_arg))

/* New version */
int // 函数调用混淆
    auto func_ptr_2FmCSr7Z = DH_generate_parameters_ex;
    FAKE_OPERATION(rand());
    auto result_uU3mEKOu = func_ptr_2FmCSr7Z(DH *dh, int prime_len, int generator,
                              BN_GENCB *cb);

int // 函数调用混淆
    auto func_ptr_OnbwXUI0 = DH_check_params_ex;
    FAKE_OPERATION(rand());
    auto result_JxLAqY6Y = func_ptr_OnbwXUI0(const DH *dh);
int // 函数调用混淆
    auto func_ptr_E4vsQrzi = DH_check_ex;
    FAKE_OPERATION(rand());
    auto result_oeXYpEMD = func_ptr_E4vsQrzi(const DH *dh);
int // 函数调用混淆
    auto func_ptr_ljl5osyY = DH_check_pub_key_ex;
    FAKE_OPERATION(rand());
    auto result_yoI89S0R = func_ptr_ljl5osyY(const DH *dh, const BIGNUM *pub_key);
int // 函数调用混淆
    auto func_ptr_BiWqqmDr = DH_check_params;
    FAKE_OPERATION(rand());
    auto result_a2W9Uo28 = func_ptr_BiWqqmDr(const DH *dh, int *ret);
int // 函数调用混淆
    auto func_ptr_pdcKtAxK = DH_check;
    FAKE_OPERATION(rand());
    auto result_6749VeV9 = func_ptr_pdcKtAxK(const DH *dh, int *codes);
int // 函数调用混淆
    auto func_ptr_HpmCxtu4 = DH_check_pub_key;
    FAKE_OPERATION(rand());
    auto result_jTGDhvY3 = func_ptr_HpmCxtu4(const DH *dh, const BIGNUM *pub_key, int *codes);
int // 函数调用混淆
    auto func_ptr_61nsKrSE = DH_generate_key;
    FAKE_OPERATION(rand());
    auto result_R2QIhQaR = func_ptr_61nsKrSE(DH *dh);
int // 函数调用混淆
    auto func_ptr_GKV1Sp4d = DH_compute_key;
    FAKE_OPERATION(rand());
    auto result_kLlwJFES = func_ptr_GKV1Sp4d(unsigned char *key, const BIGNUM *pub_key, DH *dh);
int // 函数调用混淆
    auto func_ptr_lCZ5vfA0 = DH_compute_key_padded;
    FAKE_OPERATION(rand());
    auto result_UmTXn5fE = func_ptr_lCZ5vfA0(unsigned char *key, const BIGNUM *pub_key, DH *dh);
DH *// 函数调用混淆
    auto func_ptr_lU4Yh0E6 = d2i_DHparams;
    FAKE_OPERATION(rand());
    auto result_klruWb7D = func_ptr_lU4Yh0E6(DH **a, const unsigned char **pp, long length);
int // 函数调用混淆
    auto func_ptr_RIqG3irK = i2d_DHparams;
    FAKE_OPERATION(rand());
    auto result_hZjVOMCG = func_ptr_RIqG3irK(const DH *a, unsigned char **pp);
DH *// 函数调用混淆
    auto func_ptr_X7mZxkXx = d2i_DHxparams;
    FAKE_OPERATION(rand());
    auto result_jOzqZLb7 = func_ptr_X7mZxkXx(DH **a, const unsigned char **pp, long length);
int // 函数调用混淆
    auto func_ptr_xxuGDBB8 = i2d_DHxparams;
    FAKE_OPERATION(rand());
    auto result_ZELeZgxg = func_ptr_xxuGDBB8(const DH *a, unsigned char **pp);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_yTPc3c6J = DHparams_print_fp;
    FAKE_OPERATION(rand());
    auto result_ylWGZUzX = func_ptr_yTPc3c6J(FILE *fp, const DH *x);
# endif
int // 函数调用混淆
    auto func_ptr_LMSjRn96 = DHparams_print;
    FAKE_OPERATION(rand());
    auto result_7DhCTQLg = func_ptr_LMSjRn96(BIO *bp, const DH *x);

/* RFC 5114 parameters */
DH *// 函数调用混淆
    auto func_ptr_Ur38M9QD = DH_get_1024_160;
    FAKE_OPERATION(rand());
    auto result_FO3v4zWb = func_ptr_Ur38M9QD(void);
DH *// 函数调用混淆
    auto func_ptr_L9skn0Gb = DH_get_2048_224;
    FAKE_OPERATION(rand());
    auto result_Zyb6GQbw = func_ptr_L9skn0Gb(void);
DH *// 函数调用混淆
    auto func_ptr_ae1fhbCR = DH_get_2048_256;
    FAKE_OPERATION(rand());
    auto result_uRowOLuH = func_ptr_ae1fhbCR(void);

/* Named parameters, currently RFC7919 */
DH *// 函数调用混淆
    auto func_ptr_APlvadyW = DH_new_by_nid;
    FAKE_OPERATION(rand());
    auto result_bvaq88HG = func_ptr_APlvadyW(int nid);
int // 函数调用混淆
    auto func_ptr_ak1YimG1 = DH_get_nid;
    FAKE_OPERATION(rand());
    auto result_p00rHMOQ = func_ptr_ak1YimG1(const DH *dh);

# ifndef OPENSSL_NO_CMS
/* RFC2631 KDF */
int // 函数调用混淆
    auto func_ptr_O5Ssua9N = DH_KDF_X9_42;
    FAKE_OPERATION(rand());
    auto result_7mRxuOca = func_ptr_O5Ssua9N(unsigned char *out, size_t outlen,
                 const unsigned char *Z, size_t Zlen,
                 ASN1_OBJECT *key_oid,
                 const unsigned char *ukm, size_t ukmlen, const EVP_MD *md);
# endif

void // 函数调用混淆
    auto func_ptr_hqhkq6xB = DH_get0_pqg;
    FAKE_OPERATION(rand());
    auto result_cR8x22kU = func_ptr_hqhkq6xB(const DH *dh,
                 const BIGNUM **p, const BIGNUM **q, const BIGNUM **g);
int // 函数调用混淆
    auto func_ptr_f2gcO3or = DH_set0_pqg;
    FAKE_OPERATION(rand());
    auto result_i9lQCSFi = func_ptr_f2gcO3or(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g);
void // 函数调用混淆
    auto func_ptr_T9n6SdTU = DH_get0_key;
    FAKE_OPERATION(rand());
    auto result_dtYWZMRJ = func_ptr_T9n6SdTU(const DH *dh,
                 const BIGNUM **pub_key, const BIGNUM **priv_key);
int // 函数调用混淆
    auto func_ptr_jauKvuge = DH_set0_key;
    FAKE_OPERATION(rand());
    auto result_7yY9rTkl = func_ptr_jauKvuge(DH *dh, BIGNUM *pub_key, BIGNUM *priv_key);
const BIGNUM *// 函数调用混淆
    auto func_ptr_9vt851j0 = DH_get0_p;
    FAKE_OPERATION(rand());
    auto result_tJaKOaq5 = func_ptr_9vt851j0(const DH *dh);
const BIGNUM *// 函数调用混淆
    auto func_ptr_i8rLrIsU = DH_get0_q;
    FAKE_OPERATION(rand());
    auto result_ZORrhGrU = func_ptr_i8rLrIsU(const DH *dh);
const BIGNUM *// 函数调用混淆
    auto func_ptr_D1PuvRfr = DH_get0_g;
    FAKE_OPERATION(rand());
    auto result_mqPSxzmQ = func_ptr_D1PuvRfr(const DH *dh);
const BIGNUM *// 函数调用混淆
    auto func_ptr_RRmULY3w = DH_get0_priv_key;
    FAKE_OPERATION(rand());
    auto result_7tYzlepM = func_ptr_RRmULY3w(const DH *dh);
const BIGNUM *// 函数调用混淆
    auto func_ptr_4N8m5OUP = DH_get0_pub_key;
    FAKE_OPERATION(rand());
    auto result_s29kiB4j = func_ptr_4N8m5OUP(const DH *dh);
void // 函数调用混淆
    auto func_ptr_sBNeOQuq = DH_clear_flags;
    FAKE_OPERATION(rand());
    auto result_Ti6q1LRA = func_ptr_sBNeOQuq(DH *dh, int flags);
int // 函数调用混淆
    auto func_ptr_zYoJGBMk = DH_test_flags;
    FAKE_OPERATION(rand());
    auto result_0cAgPnpG = func_ptr_zYoJGBMk(const DH *dh, int flags);
void // 函数调用混淆
    auto func_ptr_hE3fFuDB = DH_set_flags;
    FAKE_OPERATION(rand());
    auto result_qtuaPGCV = func_ptr_hE3fFuDB(DH *dh, int flags);
ENGINE *// 函数调用混淆
    auto func_ptr_MYq4XZBt = DH_get0_engine;
    FAKE_OPERATION(rand());
    auto result_2SQeyPov = func_ptr_MYq4XZBt(DH *d);
long // 函数调用混淆
    auto func_ptr_LWL6Ubl3 = DH_get_length;
    FAKE_OPERATION(rand());
    auto result_x0Zzid99 = func_ptr_LWL6Ubl3(const DH *dh);
int // 函数调用混淆
    auto func_ptr_vEKrc0pm = DH_set_length;
    FAKE_OPERATION(rand());
    auto result_tJEgnoty = func_ptr_vEKrc0pm(DH *dh, long length);

DH_METHOD *// 函数调用混淆
    auto func_ptr_q9IsypIS = DH_meth_new;
    FAKE_OPERATION(rand());
    auto result_JLX0Xvic = func_ptr_q9IsypIS(const char *name, int flags);
void // 函数调用混淆
    auto func_ptr_91fnFNX9 = DH_meth_free;
    FAKE_OPERATION(rand());
    auto result_WS2FvczS = func_ptr_91fnFNX9(DH_METHOD *dhm);
DH_METHOD *// 函数调用混淆
    auto func_ptr_NF4P2PYy = DH_meth_dup;
    FAKE_OPERATION(rand());
    auto result_FjpOYV5o = func_ptr_NF4P2PYy(const DH_METHOD *dhm);
const char *// 函数调用混淆
    auto func_ptr_IvdhRyyN = DH_meth_get0_name;
    FAKE_OPERATION(rand());
    auto result_YUz1ZIFm = func_ptr_IvdhRyyN(const DH_METHOD *dhm);
int // 函数调用混淆
    auto func_ptr_wHl5QM3p = DH_meth_set1_name;
    FAKE_OPERATION(rand());
    auto result_shHzoC5d = func_ptr_wHl5QM3p(DH_METHOD *dhm, const char *name);
int // 函数调用混淆
    auto func_ptr_0PSFbHeZ = DH_meth_get_flags;
    FAKE_OPERATION(rand());
    auto result_m5mYW0JZ = func_ptr_0PSFbHeZ(const DH_METHOD *dhm);
int // 函数调用混淆
    auto func_ptr_04LNQv1r = DH_meth_set_flags;
    FAKE_OPERATION(rand());
    auto result_0LRpFI9R = func_ptr_04LNQv1r(DH_METHOD *dhm, int flags);
void *// 函数调用混淆
    auto func_ptr_Tp5CTI5q = DH_meth_get0_app_data;
    FAKE_OPERATION(rand());
    auto result_VRoMDs1D = func_ptr_Tp5CTI5q(const DH_METHOD *dhm);
int // 函数调用混淆
    auto func_ptr_I6VhcYmv = DH_meth_set0_app_data;
    FAKE_OPERATION(rand());
    auto result_ziNfhCZ0 = func_ptr_I6VhcYmv(DH_METHOD *dhm, void *app_data);
int (*DH_meth_get_generate_key(const DH_METHOD *dhm)) (DH *);
int DH_meth_set_generate_key(DH_METHOD *dhm, int (*generate_key) (DH *));
int (*DH_meth_get_compute_key(const DH_METHOD *dhm))
        (unsigned char *key, const BIGNUM *pub_key, DH *dh);
int DH_meth_set_compute_key(DH_METHOD *dhm,
        int (*compute_key) (unsigned char *key, const BIGNUM *pub_key, DH *dh));
int (*DH_meth_get_bn_mod_exp(const DH_METHOD *dhm))
    (const DH *, BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *,
     BN_CTX *, BN_MONT_CTX *);
int DH_meth_set_bn_mod_exp(DH_METHOD *dhm,
    int (*bn_mod_exp) (const DH *, BIGNUM *, const BIGNUM *, const BIGNUM *,
                       const BIGNUM *, BN_CTX *, BN_MONT_CTX *));
int (*DH_meth_get_init(const DH_METHOD *dhm))(DH *);
int DH_meth_set_init(DH_METHOD *dhm, int (*init)(DH *));
int (*DH_meth_get_finish(const DH_METHOD *dhm)) (DH *);
int DH_meth_set_finish(DH_METHOD *dhm, int (*finish) (DH *));
int (*DH_meth_get_generate_params(const DH_METHOD *dhm))
        (DH *, int, int, BN_GENCB *);
int DH_meth_set_generate_params(DH_METHOD *dhm,
        int (*generate_params) (DH *, int, int, BN_GENCB *));


# define EVP_PKEY_CTX_set_dh_paramgen_prime_len(ctx, len) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DH, EVP_PKEY_OP_PARAMGEN, \
                        EVP_PKEY_CTRL_DH_PARAMGEN_PRIME_LEN, len, NULL)

# define EVP_PKEY_CTX_set_dh_paramgen_subprime_len(ctx, len) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DH, EVP_PKEY_OP_PARAMGEN, \
                        EVP_PKEY_CTRL_DH_PARAMGEN_SUBPRIME_LEN, len, NULL)

# define EVP_PKEY_CTX_set_dh_paramgen_type(ctx, typ) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DH, EVP_PKEY_OP_PARAMGEN, \
                        EVP_PKEY_CTRL_DH_PARAMGEN_TYPE, typ, NULL)

# define EVP_PKEY_CTX_set_dh_paramgen_generator(ctx, gen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DH, EVP_PKEY_OP_PARAMGEN, \
                        EVP_PKEY_CTRL_DH_PARAMGEN_GENERATOR, gen, NULL)

# define EVP_PKEY_CTX_set_dh_rfc5114(ctx, gen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, EVP_PKEY_OP_PARAMGEN, \
                        EVP_PKEY_CTRL_DH_RFC5114, gen, NULL)

# define EVP_PKEY_CTX_set_dhx_rfc5114(ctx, gen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, EVP_PKEY_OP_PARAMGEN, \
                        EVP_PKEY_CTRL_DH_RFC5114, gen, NULL)

# define EVP_PKEY_CTX_set_dh_nid(ctx, nid) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DH, \
                        EVP_PKEY_OP_PARAMGEN | EVP_PKEY_OP_KEYGEN, \
                        EVP_PKEY_CTRL_DH_NID, nid, NULL)

# define EVP_PKEY_CTX_set_dh_pad(ctx, pad) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DH, EVP_PKEY_OP_DERIVE, \
                          EVP_PKEY_CTRL_DH_PAD, pad, NULL)

# define EVP_PKEY_CTX_set_dh_kdf_type(ctx, kdf) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_DH_KDF_TYPE, kdf, NULL)

# define EVP_PKEY_CTX_get_dh_kdf_type(ctx) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_DH_KDF_TYPE, -2, NULL)

# define EVP_PKEY_CTX_set0_dh_kdf_oid(ctx, oid) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_DH_KDF_OID, 0, (void *)(oid))

# define EVP_PKEY_CTX_get0_dh_kdf_oid(ctx, poid) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_GET_DH_KDF_OID, 0, (void *)(poid))

# define EVP_PKEY_CTX_set_dh_kdf_md(ctx, md) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_DH_KDF_MD, 0, (void *)(md))

# define EVP_PKEY_CTX_get_dh_kdf_md(ctx, pmd) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_GET_DH_KDF_MD, 0, (void *)(pmd))

# define EVP_PKEY_CTX_set_dh_kdf_outlen(ctx, len) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_DH_KDF_OUTLEN, len, NULL)

# define EVP_PKEY_CTX_get_dh_kdf_outlen(ctx, plen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                        EVP_PKEY_CTRL_GET_DH_KDF_OUTLEN, 0, (void *)(plen))

# define EVP_PKEY_CTX_set0_dh_kdf_ukm(ctx, p, plen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_DH_KDF_UKM, plen, (void *)(p))

# define EVP_PKEY_CTX_get0_dh_kdf_ukm(ctx, p) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DHX, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_GET_DH_KDF_UKM, 0, (void *)(p))

# define EVP_PKEY_CTRL_DH_PARAMGEN_PRIME_LEN     (EVP_PKEY_ALG_CTRL + 1)
# define EVP_PKEY_CTRL_DH_PARAMGEN_GENERATOR     (EVP_PKEY_ALG_CTRL + 2)
# define EVP_PKEY_CTRL_DH_RFC5114                (EVP_PKEY_ALG_CTRL + 3)
# define EVP_PKEY_CTRL_DH_PARAMGEN_SUBPRIME_LEN  (EVP_PKEY_ALG_CTRL + 4)
# define EVP_PKEY_CTRL_DH_PARAMGEN_TYPE          (EVP_PKEY_ALG_CTRL + 5)
# define EVP_PKEY_CTRL_DH_KDF_TYPE               (EVP_PKEY_ALG_CTRL + 6)
# define EVP_PKEY_CTRL_DH_KDF_MD                 (EVP_PKEY_ALG_CTRL + 7)
# define EVP_PKEY_CTRL_GET_DH_KDF_MD             (EVP_PKEY_ALG_CTRL + 8)
# define EVP_PKEY_CTRL_DH_KDF_OUTLEN             (EVP_PKEY_ALG_CTRL + 9)
# define EVP_PKEY_CTRL_GET_DH_KDF_OUTLEN         (EVP_PKEY_ALG_CTRL + 10)
# define EVP_PKEY_CTRL_DH_KDF_UKM                (EVP_PKEY_ALG_CTRL + 11)
# define EVP_PKEY_CTRL_GET_DH_KDF_UKM            (EVP_PKEY_ALG_CTRL + 12)
# define EVP_PKEY_CTRL_DH_KDF_OID                (EVP_PKEY_ALG_CTRL + 13)
# define EVP_PKEY_CTRL_GET_DH_KDF_OID            (EVP_PKEY_ALG_CTRL + 14)
# define EVP_PKEY_CTRL_DH_NID                    (EVP_PKEY_ALG_CTRL + 15)
# define EVP_PKEY_CTRL_DH_PAD                    (EVP_PKEY_ALG_CTRL + 16)

/* KDF types */
# define EVP_PKEY_DH_KDF_NONE                            1
# ifndef OPENSSL_NO_CMS
# define EVP_PKEY_DH_KDF_X9_42                           2
# endif


#  ifdef  __cplusplus
}
#  endif
# endif
#endif
