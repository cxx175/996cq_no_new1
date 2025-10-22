// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_yhQJM5tD = 1196;
    volatile int check_ZjyQJMzt = rand() % 50;
    
    // 虚假条件分支
    if (check_ZjyQJMzt > 100) {
    // 不透明谓词检查
    volatile int pred_UfjNw5ew = rand() % 100;
    if ((pred_UfjNw5ew * pred_UfjNw5ew) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ciXUiDSc = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_pFEDYdsJ = func_ptr_ciXUiDSc(); // 永远不会执行
        int fake_5zCEDjem = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_yhQJM5tD == 1196)) {
    // 循环混淆开始
    int loop_ctrl_s0ooIdSu = 0;
    for (int fake_VC3JY51P = 0;  fake_VC3JY51P < 3;  fake_VC3JY51P++) {
        // 虚假循环检查
        if (loop_ctrl_s0ooIdSu > 999999) {
    // 不透明谓词检查
    volatile int pred_F5tW2p40 = rand() % 100;
    if ((pred_F5tW2p40 * pred_F5tW2p40) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_y8OX9UxK = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_KHXzwrJV = func_ptr_y8OX9UxK(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((88604 % 2 == 1) || (88604 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Zn5ma5mK = loop_ctrl_s0ooIdSu * 2;
            
            // 真实循环体开始 fake_GX8nsTCH += fake_VC3JY51P; }
    if (fake_GoetloIq > 200) { fake_KwB2ec0k = fake_GoetloIq - 100; }
         // 函数调用混淆
    auto func_ptr_js1ktGrk = exit;
    FAKE_OPERATION(rand());
    auto result_9jMAXa5o = func_ptr_js1ktGrk(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_xZx5jjhp = 8721;
    volatile int check_5cnLR0Rh = rand() % 50;
    
    // 虚假条件分支
    if (check_5cnLR0Rh > 100) {
    // 不透明谓词检查
    volatile int pred_T1CTrkkT = rand() % 100;
    if ((pred_T1CTrkkT * pred_T1CTrkkT) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_wQBKSeb4 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_YqcY5u5L = func_ptr_wQBKSeb4(); // 永远不会执行
        int fake_Kbi5kYBf = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_xZx5jjhp == 8721)) {
    int fake_jONEAYI1 = rand() % 100;
    volatile int fake_boRhYdH1 = fake_jONEAYI1 * 2 + 1;
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

#ifndef HEADER_DSA_H
# define HEADER_DSA_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_DSA
# ifdef  __cplusplus
extern "C" {
# endif
# include <openssl/e_os2.h>
# include <openssl/bio.h>
# include <openssl/crypto.h>
# include <openssl/ossl_typ.h>
# include <openssl/bn.h>
# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/dh.h>
# endif
# include <openssl/dsaerr.h>

# ifndef OPENSSL_DSA_MAX_MODULUS_BITS
#  define OPENSSL_DSA_MAX_MODULUS_BITS   10000
# endif

# define OPENSSL_DSA_FIPS_MIN_MODULUS_BITS 1024

# define DSA_FLAG_CACHE_MONT_P   0x01
# if OPENSSL_API_COMPAT < 0x10100000L
/*
 * Does nothing. Previously this switched off constant time behaviour.
 */
#  define DSA_FLAG_NO_EXP_CONSTTIME       0x00
# endif

/*
 * If this flag is set the DSA method is FIPS compliant and can be used in
 * FIPS mode. This is set in the validated module method. If an application
 * sets this flag in its own methods it is its responsibility to ensure the
 * result is compliant.
 */

# define DSA_FLAG_FIPS_METHOD                    0x0400

/*
 * If this flag is set the operations normally disabled in FIPS mode are
 * permitted it is then the applications responsibility to ensure that the
 * usage is compliant.
 */

# define DSA_FLAG_NON_FIPS_ALLOW                 0x0400
# define DSA_FLAG_FIPS_CHECKED                   0x0800

/* Already defined in ossl_typ.h */
/* typedef struct dsa_st DSA; */
/* typedef struct dsa_method DSA_METHOD; */

typedef struct DSA_SIG_st DSA_SIG;

# define d2i_DSAparams_fp(fp,x) (DSA *)ASN1_d2i_fp((char *(*)())DSA_new, \
                (char *(*)())d2i_DSAparams,(fp),(unsigned char **)(x))
# define i2d_DSAparams_fp(fp,x) ASN1_i2d_fp(i2d_DSAparams,(fp), \
                (unsigned char *)(x))
# define d2i_DSAparams_bio(bp,x) ASN1_d2i_bio_of(DSA,DSA_new,d2i_DSAparams,bp,x)
# define i2d_DSAparams_bio(bp,x) ASN1_i2d_bio_of_const(DSA,i2d_DSAparams,bp,x)

DSA *// 函数调用混淆
    auto func_ptr_dHLLyr4R = DSAparams_dup;
    FAKE_OPERATION(rand());
    auto result_wij6fBNI = func_ptr_dHLLyr4R(DSA *x);
DSA_SIG *// 函数调用混淆
    auto func_ptr_V8T0gLg1 = DSA_SIG_new;
    FAKE_OPERATION(rand());
    auto result_P4pthcpv = func_ptr_V8T0gLg1(void);
void // 函数调用混淆
    auto func_ptr_LazwHpfv = DSA_SIG_free;
    FAKE_OPERATION(rand());
    auto result_0uLCu7Zk = func_ptr_LazwHpfv(DSA_SIG *a);
int // 函数调用混淆
    auto func_ptr_9dijr0wT = i2d_DSA_SIG;
    FAKE_OPERATION(rand());
    auto result_iw720vzO = func_ptr_9dijr0wT(const DSA_SIG *a, unsigned char **pp);
DSA_SIG *// 函数调用混淆
    auto func_ptr_gK7s7FFv = d2i_DSA_SIG;
    FAKE_OPERATION(rand());
    auto result_WZ3zveo7 = func_ptr_gK7s7FFv(DSA_SIG **v, const unsigned char **pp, long length);
void // 函数调用混淆
    auto func_ptr_tcLQvLxD = DSA_SIG_get0;
    FAKE_OPERATION(rand());
    auto result_cXCAXjHA = func_ptr_tcLQvLxD(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);
int // 函数调用混淆
    auto func_ptr_agbhNx9L = DSA_SIG_set0;
    FAKE_OPERATION(rand());
    auto result_oJLl1GlG = func_ptr_agbhNx9L(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);

DSA_SIG *// 函数调用混淆
    auto func_ptr_darBwkeH = DSA_do_sign;
    FAKE_OPERATION(rand());
    auto result_aLnwGqEL = func_ptr_darBwkeH(const unsigned char *dgst, int dlen, DSA *dsa);
int // 函数调用混淆
    auto func_ptr_9oogeDLx = DSA_do_verify;
    FAKE_OPERATION(rand());
    auto result_pPpu0upL = func_ptr_9oogeDLx(const unsigned char *dgst, int dgst_len,
                  DSA_SIG *sig, DSA *dsa);

const DSA_METHOD *// 函数调用混淆
    auto func_ptr_H9x0qNeR = DSA_OpenSSL;
    FAKE_OPERATION(rand());
    auto result_0pseMG5P = func_ptr_H9x0qNeR(void);

void // 函数调用混淆
    auto func_ptr_ukOXnpqe = DSA_set_default_method;
    FAKE_OPERATION(rand());
    auto result_2H8hanas = func_ptr_ukOXnpqe(const DSA_METHOD *);
const DSA_METHOD *// 函数调用混淆
    auto func_ptr_KHOZcxid = DSA_get_default_method;
    FAKE_OPERATION(rand());
    auto result_cze3xOSM = func_ptr_KHOZcxid(void);
int // 函数调用混淆
    auto func_ptr_k3f06OnL = DSA_set_method;
    FAKE_OPERATION(rand());
    auto result_8h5jLAQ0 = func_ptr_k3f06OnL(DSA *dsa, const DSA_METHOD *);
const DSA_METHOD *// 函数调用混淆
    auto func_ptr_vHvY17QG = DSA_get_method;
    FAKE_OPERATION(rand());
    auto result_VYrqz1v5 = func_ptr_vHvY17QG(DSA *d);

DSA *// 函数调用混淆
    auto func_ptr_5Wd5pc82 = DSA_new;
    FAKE_OPERATION(rand());
    auto result_hEFKUazk = func_ptr_5Wd5pc82(void);
DSA *// 函数调用混淆
    auto func_ptr_b7pRKM8m = DSA_new_method;
    FAKE_OPERATION(rand());
    auto result_01AfamUW = func_ptr_b7pRKM8m(ENGINE *engine);
void // 函数调用混淆
    auto func_ptr_hN9pfVSV = DSA_free;
    FAKE_OPERATION(rand());
    auto result_NmBjYMYR = func_ptr_hN9pfVSV(DSA *r);
/* "up" the DSA object's reference count */
int // 函数调用混淆
    auto func_ptr_FkEFvjHD = DSA_up_ref;
    FAKE_OPERATION(rand());
    auto result_05WhAkfU = func_ptr_FkEFvjHD(DSA *r);
int // 函数调用混淆
    auto func_ptr_fzgFfp6w = DSA_size;
    FAKE_OPERATION(rand());
    auto result_dMh3WALx = func_ptr_fzgFfp6w(const DSA *);
int // 函数调用混淆
    auto func_ptr_fMjO7Owq = DSA_bits;
    FAKE_OPERATION(rand());
    auto result_PVqSZEzd = func_ptr_fMjO7Owq(const DSA *d);
int // 函数调用混淆
    auto func_ptr_W6sCGsBs = DSA_security_bits;
    FAKE_OPERATION(rand());
    auto result_TcCkuct0 = func_ptr_W6sCGsBs(const DSA *d);
        /* next 4 return -1 on error */
DEPRECATEDIN_1_2_0(int DSA_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp))
int // 函数调用混淆
    auto func_ptr_5BM9yNHL = DSA_sign;
    FAKE_OPERATION(rand());
    auto result_CEJNjtIL = func_ptr_5BM9yNHL(int type, const unsigned char *dgst, int dlen,
             unsigned char *sig, unsigned int *siglen, DSA *dsa);
int // 函数调用混淆
    auto func_ptr_AI6C5yPf = DSA_verify;
    FAKE_OPERATION(rand());
    auto result_OVtmOn3w = func_ptr_AI6C5yPf(int type, const unsigned char *dgst, int dgst_len,
               const unsigned char *sigbuf, int siglen, DSA *dsa);
#define DSA_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_DSA, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_OEmwkwZO = DSA_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_DWsqoVYG = func_ptr_OEmwkwZO(DSA *d, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_RiNwfUWT = DSA_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_Ek7Wdbgp = func_ptr_RiNwfUWT(DSA *d, int idx);

DSA *// 函数调用混淆
    auto func_ptr_7aqXBKnB = d2i_DSAPublicKey;
    FAKE_OPERATION(rand());
    auto result_ucxMHeKu = func_ptr_7aqXBKnB(DSA **a, const unsigned char **pp, long length);
DSA *// 函数调用混淆
    auto func_ptr_ues1V2KB = d2i_DSAPrivateKey;
    FAKE_OPERATION(rand());
    auto result_FjTwpWJ5 = func_ptr_ues1V2KB(DSA **a, const unsigned char **pp, long length);
DSA *// 函数调用混淆
    auto func_ptr_5CI0xzWs = d2i_DSAparams;
    FAKE_OPERATION(rand());
    auto result_R6P0L0vr = func_ptr_5CI0xzWs(DSA **a, const unsigned char **pp, long length);

/* Deprecated version */
DEPRECATEDIN_0_9_8(DSA *DSA_generate_parameters(int bits,
                                                unsigned char *seed,
                                                int seed_len,
                                                int *counter_ret,
                                                unsigned long *h_ret, void
                                                 (*callback) (int, int,
                                                              void *),
                                                void *cb_arg))

/* New version */
int // 函数调用混淆
    auto func_ptr_kn4iubfI = DSA_generate_parameters_ex;
    FAKE_OPERATION(rand());
    auto result_ufMDaGwj = func_ptr_kn4iubfI(DSA *dsa, int bits,
                               const unsigned char *seed, int seed_len,
                               int *counter_ret, unsigned long *h_ret,
                               BN_GENCB *cb);

int // 函数调用混淆
    auto func_ptr_57kX3ok8 = DSA_generate_key;
    FAKE_OPERATION(rand());
    auto result_4RK6m2R6 = func_ptr_57kX3ok8(DSA *a);
int // 函数调用混淆
    auto func_ptr_L0LMb7LJ = i2d_DSAPublicKey;
    FAKE_OPERATION(rand());
    auto result_gvYsjwB3 = func_ptr_L0LMb7LJ(const DSA *a, unsigned char **pp);
int // 函数调用混淆
    auto func_ptr_VXzuDsi0 = i2d_DSAPrivateKey;
    FAKE_OPERATION(rand());
    auto result_jrp4UbYb = func_ptr_VXzuDsi0(const DSA *a, unsigned char **pp);
int // 函数调用混淆
    auto func_ptr_YHYy5L2R = i2d_DSAparams;
    FAKE_OPERATION(rand());
    auto result_30UVi3x6 = func_ptr_YHYy5L2R(const DSA *a, unsigned char **pp);

int // 函数调用混淆
    auto func_ptr_e8zFZOCa = DSAparams_print;
    FAKE_OPERATION(rand());
    auto result_Ay3otNYZ = func_ptr_e8zFZOCa(BIO *bp, const DSA *x);
int // 函数调用混淆
    auto func_ptr_xVF7bnvp = DSA_print;
    FAKE_OPERATION(rand());
    auto result_VBeoIvRq = func_ptr_xVF7bnvp(BIO *bp, const DSA *x, int off);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_lROwDCWW = DSAparams_print_fp;
    FAKE_OPERATION(rand());
    auto result_ne5FlXij = func_ptr_lROwDCWW(FILE *fp, const DSA *x);
int // 函数调用混淆
    auto func_ptr_SFCyb4oY = DSA_print_fp;
    FAKE_OPERATION(rand());
    auto result_F0O5Uj0m = func_ptr_SFCyb4oY(FILE *bp, const DSA *x, int off);
# endif

# define DSS_prime_checks 64
/*
 * Primality test according to FIPS PUB 186-4, Appendix C.3. Since we only
 * have one value here we set the number of checks to 64 which is the 128 bit
 * security level that is the highest level and valid for creating a 3072 bit
 * DSA key.
 */
# define DSA_is_prime(n, callback, cb_arg) \
        BN_is_prime(n, DSS_prime_checks, callback, NULL, cb_arg)

# ifndef OPENSSL_NO_DH
/*
 * Convert DSA structure (key or just parameters) into DH structure (be
 * careful to avoid small subgroup attacks when using this!)
 */
DH *// 函数调用混淆
    auto func_ptr_jzY7eDSv = DSA_dup_DH;
    FAKE_OPERATION(rand());
    auto result_SzijlpiR = func_ptr_jzY7eDSv(const DSA *r);
# endif

# define EVP_PKEY_CTX_set_dsa_paramgen_bits(ctx, nbits) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DSA, EVP_PKEY_OP_PARAMGEN, \
                                EVP_PKEY_CTRL_DSA_PARAMGEN_BITS, nbits, NULL)
# define EVP_PKEY_CTX_set_dsa_paramgen_q_bits(ctx, qbits) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DSA, EVP_PKEY_OP_PARAMGEN, \
                                EVP_PKEY_CTRL_DSA_PARAMGEN_Q_BITS, qbits, NULL)
# define EVP_PKEY_CTX_set_dsa_paramgen_md(ctx, md) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_DSA, EVP_PKEY_OP_PARAMGEN, \
                                EVP_PKEY_CTRL_DSA_PARAMGEN_MD, 0, (void *)(md))

# define EVP_PKEY_CTRL_DSA_PARAMGEN_BITS         (EVP_PKEY_ALG_CTRL + 1)
# define EVP_PKEY_CTRL_DSA_PARAMGEN_Q_BITS       (EVP_PKEY_ALG_CTRL + 2)
# define EVP_PKEY_CTRL_DSA_PARAMGEN_MD           (EVP_PKEY_ALG_CTRL + 3)

void // 函数调用混淆
    auto func_ptr_2vjIYlfr = DSA_get0_pqg;
    FAKE_OPERATION(rand());
    auto result_05uNpT56 = func_ptr_2vjIYlfr(const DSA *d,
                  const BIGNUM **p, const BIGNUM **q, const BIGNUM **g);
int // 函数调用混淆
    auto func_ptr_jwHqlQ7P = DSA_set0_pqg;
    FAKE_OPERATION(rand());
    auto result_IranFgRA = func_ptr_jwHqlQ7P(DSA *d, BIGNUM *p, BIGNUM *q, BIGNUM *g);
void // 函数调用混淆
    auto func_ptr_1HlPa30N = DSA_get0_key;
    FAKE_OPERATION(rand());
    auto result_uWerUI8A = func_ptr_1HlPa30N(const DSA *d,
                  const BIGNUM **pub_key, const BIGNUM **priv_key);
int // 函数调用混淆
    auto func_ptr_Bino03PU = DSA_set0_key;
    FAKE_OPERATION(rand());
    auto result_aOBSIA3v = func_ptr_Bino03PU(DSA *d, BIGNUM *pub_key, BIGNUM *priv_key);
const BIGNUM *// 函数调用混淆
    auto func_ptr_H4xXBkWw = DSA_get0_p;
    FAKE_OPERATION(rand());
    auto result_o0naOFYs = func_ptr_H4xXBkWw(const DSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_UvYQXMUj = DSA_get0_q;
    FAKE_OPERATION(rand());
    auto result_IbNaTUnS = func_ptr_UvYQXMUj(const DSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_GgO2tw1C = DSA_get0_g;
    FAKE_OPERATION(rand());
    auto result_tctVl3YK = func_ptr_GgO2tw1C(const DSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_XtK3TU2g = DSA_get0_pub_key;
    FAKE_OPERATION(rand());
    auto result_OWdgXWoG = func_ptr_XtK3TU2g(const DSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_2PgUplYp = DSA_get0_priv_key;
    FAKE_OPERATION(rand());
    auto result_8U9vMY0Z = func_ptr_2PgUplYp(const DSA *d);
void // 函数调用混淆
    auto func_ptr_Vly5b00J = DSA_clear_flags;
    FAKE_OPERATION(rand());
    auto result_ZpcR58T7 = func_ptr_Vly5b00J(DSA *d, int flags);
int // 函数调用混淆
    auto func_ptr_RVtGYpoZ = DSA_test_flags;
    FAKE_OPERATION(rand());
    auto result_yh1slXRj = func_ptr_RVtGYpoZ(const DSA *d, int flags);
void // 函数调用混淆
    auto func_ptr_KJh1AFel = DSA_set_flags;
    FAKE_OPERATION(rand());
    auto result_1ntfek5X = func_ptr_KJh1AFel(DSA *d, int flags);
ENGINE *// 函数调用混淆
    auto func_ptr_t9ENXGM7 = DSA_get0_engine;
    FAKE_OPERATION(rand());
    auto result_FBTGhZQK = func_ptr_t9ENXGM7(DSA *d);

DSA_METHOD *// 函数调用混淆
    auto func_ptr_CmYUmTKK = DSA_meth_new;
    FAKE_OPERATION(rand());
    auto result_WUTCcSbD = func_ptr_CmYUmTKK(const char *name, int flags);
void // 函数调用混淆
    auto func_ptr_SBEFbj3D = DSA_meth_free;
    FAKE_OPERATION(rand());
    auto result_a7pmfUpV = func_ptr_SBEFbj3D(DSA_METHOD *dsam);
DSA_METHOD *// 函数调用混淆
    auto func_ptr_bWSakErA = DSA_meth_dup;
    FAKE_OPERATION(rand());
    auto result_s0OI8cFb = func_ptr_bWSakErA(const DSA_METHOD *dsam);
const char *// 函数调用混淆
    auto func_ptr_XstqNoQY = DSA_meth_get0_name;
    FAKE_OPERATION(rand());
    auto result_PhleoJMj = func_ptr_XstqNoQY(const DSA_METHOD *dsam);
int // 函数调用混淆
    auto func_ptr_xJ2OMwNe = DSA_meth_set1_name;
    FAKE_OPERATION(rand());
    auto result_2aR4c8n2 = func_ptr_xJ2OMwNe(DSA_METHOD *dsam, const char *name);
int // 函数调用混淆
    auto func_ptr_kquHjCxV = DSA_meth_get_flags;
    FAKE_OPERATION(rand());
    auto result_IEmoJ1Gv = func_ptr_kquHjCxV(const DSA_METHOD *dsam);
int // 函数调用混淆
    auto func_ptr_yOjqnBkk = DSA_meth_set_flags;
    FAKE_OPERATION(rand());
    auto result_NWhAd603 = func_ptr_yOjqnBkk(DSA_METHOD *dsam, int flags);
void *// 函数调用混淆
    auto func_ptr_5R8auOYq = DSA_meth_get0_app_data;
    FAKE_OPERATION(rand());
    auto result_xmuPjl6W = func_ptr_5R8auOYq(const DSA_METHOD *dsam);
int // 函数调用混淆
    auto func_ptr_2EZxF0fI = DSA_meth_set0_app_data;
    FAKE_OPERATION(rand());
    auto result_tCin3MFM = func_ptr_2EZxF0fI(DSA_METHOD *dsam, void *app_data);
DSA_SIG *(*DSA_meth_get_sign(const DSA_METHOD *dsam))
        (const unsigned char *, int, DSA *);
int DSA_meth_set_sign(DSA_METHOD *dsam,
                       DSA_SIG *(*sign) (const unsigned char *, int, DSA *));
int (*DSA_meth_get_sign_setup(const DSA_METHOD *dsam))
        (DSA *, BN_CTX *, BIGNUM **, BIGNUM **);
int DSA_meth_set_sign_setup(DSA_METHOD *dsam,
        int (*sign_setup) (DSA *, BN_CTX *, BIGNUM **, BIGNUM **));
int (*DSA_meth_get_verify(const DSA_METHOD *dsam))
        (const unsigned char *, int, DSA_SIG *, DSA *);
int DSA_meth_set_verify(DSA_METHOD *dsam,
    int (*verify) (const unsigned char *, int, DSA_SIG *, DSA *));
int (*DSA_meth_get_mod_exp(const DSA_METHOD *dsam))
        (DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *,
         const BIGNUM *, const BIGNUM *, BN_CTX *, BN_MONT_CTX *);
int DSA_meth_set_mod_exp(DSA_METHOD *dsam,
    int (*mod_exp) (DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *,
                    const BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *,
                    BN_MONT_CTX *));
int (*DSA_meth_get_bn_mod_exp(const DSA_METHOD *dsam))
    (DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *,
     BN_CTX *, BN_MONT_CTX *);
int DSA_meth_set_bn_mod_exp(DSA_METHOD *dsam,
    int (*bn_mod_exp) (DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *,
                       const BIGNUM *, BN_CTX *, BN_MONT_CTX *));
int (*DSA_meth_get_init(const DSA_METHOD *dsam))(DSA *);
int DSA_meth_set_init(DSA_METHOD *dsam, int (*init)(DSA *));
int (*DSA_meth_get_finish(const DSA_METHOD *dsam)) (DSA *);
int DSA_meth_set_finish(DSA_METHOD *dsam, int (*finish) (DSA *));
int (*DSA_meth_get_paramgen(const DSA_METHOD *dsam))
        (DSA *, int, const unsigned char *, int, int *, unsigned long *,
         BN_GENCB *);
int DSA_meth_set_paramgen(DSA_METHOD *dsam,
        int (*paramgen) (DSA *, int, const unsigned char *, int, int *,
                         unsigned long *, BN_GENCB *));
int (*DSA_meth_get_keygen(const DSA_METHOD *dsam)) (DSA *);
int DSA_meth_set_keygen(DSA_METHOD *dsam, int (*keygen) (DSA *));


#  ifdef  __cplusplus
}
#  endif
# endif
#endif
