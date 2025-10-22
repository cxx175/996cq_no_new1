// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_ROOmm5Rj = 6845;
    volatile int check_vnlbFbYR = rand() % 50;
    
    // 虚假条件分支
    if (check_vnlbFbYR > 100) {
    // 不透明谓词检查
    volatile int pred_sUXlEtlg = rand() % 100;
    if ((pred_sUXlEtlg * pred_sUXlEtlg) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_aCrz4NOX = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_uAjvjSdT = func_ptr_aCrz4NOX(); // 永远不会执行
        int fake_yzexqJep = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_ROOmm5Rj == 6845)) {
    int fake_9vZQa9rt = rand() % 100;
    volatile int fake_fsKJbpsz = fake_9vZQa9rt * 2 + 1;
         // 函数调用混淆
    auto func_ptr_goG8WSvb = exit;
    FAKE_OPERATION(rand());
    auto result_c2A2yIjv = func_ptr_goG8WSvb(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_m5ZyRgRT = 5098;
    volatile int check_QeS1Ye3e = rand() % 50;
    
    // 虚假条件分支
    if (check_QeS1Ye3e > 100) {
    // 不透明谓词检查
    volatile int pred_PiXlpojc = rand() % 100;
    if ((pred_PiXlpojc * pred_PiXlpojc) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Vr37t7fk = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_46gFitJ5 = func_ptr_Vr37t7fk(); // 永远不会执行
        int fake_KEgFQbnh = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_m5ZyRgRT == 5098)) {
    if (fake_QP7DeyHI > 200) { fake_ONW9327G = fake_QP7DeyHI - 100; }
    int fake_Axxf2wKc = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_9FeJP7ZT = 0;
    for (int fake_XZTSTThp = 0;  fake_XZTSTThp < 3;  fake_XZTSTThp++) {
        // 虚假循环检查
        if (loop_ctrl_9FeJP7ZT > 999999) {
    // 不透明谓词检查
    volatile int pred_OXkZJRVU = rand() % 100;
    if ((pred_OXkZJRVU * pred_OXkZJRVU) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gp6a3xQr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_S26FOgqV = func_ptr_gp6a3xQr(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((43817 % 2 == 1) || (43817 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_uA0VQ3m1 = loop_ctrl_9FeJP7ZT * 2;
            
            // 真实循环体开始 fake_zKUqMIBW += fake_XZTSTThp; }
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

#ifndef HEADER_RSA_H
# define HEADER_RSA_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_RSA
# include <openssl/asn1.h>
# include <openssl/bio.h>
# include <openssl/crypto.h>
# include <openssl/ossl_typ.h>
# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/bn.h>
# endif
# include <openssl/rsaerr.h>
# ifdef  __cplusplus
extern "C" {
# endif

/* The types RSA and RSA_METHOD are defined in ossl_typ.h */

# ifndef OPENSSL_RSA_MAX_MODULUS_BITS
#  define OPENSSL_RSA_MAX_MODULUS_BITS   16384
# endif

# define OPENSSL_RSA_FIPS_MIN_MODULUS_BITS 1024

# ifndef OPENSSL_RSA_SMALL_MODULUS_BITS
#  define OPENSSL_RSA_SMALL_MODULUS_BITS 3072
# endif
# ifndef OPENSSL_RSA_MAX_PUBEXP_BITS

/* exponent limit enforced for "large" modulus only */
#  define OPENSSL_RSA_MAX_PUBEXP_BITS    64
# endif

# define RSA_3   0x3L
# define RSA_F4  0x10001L

/* based on RFC 8017 appendix A.1.2 */
# define RSA_ASN1_VERSION_DEFAULT        0
# define RSA_ASN1_VERSION_MULTI          1

# define RSA_DEFAULT_PRIME_NUM           2

# define RSA_METHOD_FLAG_NO_CHECK        0x0001/* don't check pub/private
                                                * match */

# define RSA_FLAG_CACHE_PUBLIC           0x0002
# define RSA_FLAG_CACHE_PRIVATE          0x0004
# define RSA_FLAG_BLINDING               0x0008
# define RSA_FLAG_THREAD_SAFE            0x0010
/*
 * This flag means the private key operations will be handled by rsa_mod_exp
 * and that they do not depend on the private key components being present:
 * for example a key stored in external hardware. Without this flag
 * bn_mod_exp gets called when private key components are absent.
 */
# define RSA_FLAG_EXT_PKEY               0x0020

/*
 * new with 0.9.6j and 0.9.7b; the built-in
 * RSA implementation now uses blinding by
 * default (ignoring RSA_FLAG_BLINDING),
 * but other engines might not need it
 */
# define RSA_FLAG_NO_BLINDING            0x0080
# if OPENSSL_API_COMPAT < 0x10100000L
/*
 * Does nothing. Previously this switched off constant time behaviour.
 */
#  define RSA_FLAG_NO_CONSTTIME           0x0000
# endif
# if OPENSSL_API_COMPAT < 0x00908000L
/* deprecated name for the flag*/
/*
 * new with 0.9.7h; the built-in RSA
 * implementation now uses constant time
 * modular exponentiation for secret exponents
 * by default. This flag causes the
 * faster variable sliding window method to
 * be used for all exponents.
 */
#  define RSA_FLAG_NO_EXP_CONSTTIME RSA_FLAG_NO_CONSTTIME
# endif

# define EVP_PKEY_CTX_set_rsa_padding(ctx, pad) \
        RSA_pkey_ctx_ctrl(ctx, -1, EVP_PKEY_CTRL_RSA_PADDING, pad, NULL)

# define EVP_PKEY_CTX_get_rsa_padding(ctx, ppad) \
        RSA_pkey_ctx_ctrl(ctx, -1, EVP_PKEY_CTRL_GET_RSA_PADDING, 0, ppad)

# define EVP_PKEY_CTX_set_rsa_pss_saltlen(ctx, len) \
        RSA_pkey_ctx_ctrl(ctx, (EVP_PKEY_OP_SIGN|EVP_PKEY_OP_VERIFY), \
                          EVP_PKEY_CTRL_RSA_PSS_SALTLEN, len, NULL)
/* Salt length matches digest */
# define RSA_PSS_SALTLEN_DIGEST -1
/* Verify only: auto detect salt length */
# define RSA_PSS_SALTLEN_AUTO   -2
/* Set salt length to maximum possible */
# define RSA_PSS_SALTLEN_MAX    -3
/* Old compatible max salt length for sign only */
# define RSA_PSS_SALTLEN_MAX_SIGN    -2

# define EVP_PKEY_CTX_set_rsa_pss_keygen_saltlen(ctx, len) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA_PSS, EVP_PKEY_OP_KEYGEN, \
                          EVP_PKEY_CTRL_RSA_PSS_SALTLEN, len, NULL)

# define EVP_PKEY_CTX_get_rsa_pss_saltlen(ctx, plen) \
        RSA_pkey_ctx_ctrl(ctx, (EVP_PKEY_OP_SIGN|EVP_PKEY_OP_VERIFY), \
                          EVP_PKEY_CTRL_GET_RSA_PSS_SALTLEN, 0, plen)

# define EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, bits) \
        RSA_pkey_ctx_ctrl(ctx, EVP_PKEY_OP_KEYGEN, \
                          EVP_PKEY_CTRL_RSA_KEYGEN_BITS, bits, NULL)

# define EVP_PKEY_CTX_set_rsa_keygen_pubexp(ctx, pubexp) \
        RSA_pkey_ctx_ctrl(ctx, EVP_PKEY_OP_KEYGEN, \
                          EVP_PKEY_CTRL_RSA_KEYGEN_PUBEXP, 0, pubexp)

# define EVP_PKEY_CTX_set_rsa_keygen_primes(ctx, primes) \
        RSA_pkey_ctx_ctrl(ctx, EVP_PKEY_OP_KEYGEN, \
                          EVP_PKEY_CTRL_RSA_KEYGEN_PRIMES, primes, NULL)

# define  EVP_PKEY_CTX_set_rsa_mgf1_md(ctx, md) \
        RSA_pkey_ctx_ctrl(ctx, EVP_PKEY_OP_TYPE_SIG | EVP_PKEY_OP_TYPE_CRYPT, \
                          EVP_PKEY_CTRL_RSA_MGF1_MD, 0, (void *)(md))

# define  EVP_PKEY_CTX_set_rsa_pss_keygen_mgf1_md(ctx, md) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA_PSS, EVP_PKEY_OP_KEYGEN, \
                          EVP_PKEY_CTRL_RSA_MGF1_MD, 0, (void *)(md))

# define  EVP_PKEY_CTX_set_rsa_oaep_md(ctx, md) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA, EVP_PKEY_OP_TYPE_CRYPT,  \
                          EVP_PKEY_CTRL_RSA_OAEP_MD, 0, (void *)(md))

# define  EVP_PKEY_CTX_get_rsa_mgf1_md(ctx, pmd) \
        RSA_pkey_ctx_ctrl(ctx, EVP_PKEY_OP_TYPE_SIG | EVP_PKEY_OP_TYPE_CRYPT, \
                          EVP_PKEY_CTRL_GET_RSA_MGF1_MD, 0, (void *)(pmd))

# define  EVP_PKEY_CTX_get_rsa_oaep_md(ctx, pmd) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA, EVP_PKEY_OP_TYPE_CRYPT,  \
                          EVP_PKEY_CTRL_GET_RSA_OAEP_MD, 0, (void *)(pmd))

# define  EVP_PKEY_CTX_set0_rsa_oaep_label(ctx, l, llen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA, EVP_PKEY_OP_TYPE_CRYPT,  \
                          EVP_PKEY_CTRL_RSA_OAEP_LABEL, llen, (void *)(l))

# define  EVP_PKEY_CTX_get0_rsa_oaep_label(ctx, l) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA, EVP_PKEY_OP_TYPE_CRYPT,  \
                          EVP_PKEY_CTRL_GET_RSA_OAEP_LABEL, 0, (void *)(l))

# define  EVP_PKEY_CTX_set_rsa_pss_keygen_md(ctx, md) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_RSA_PSS,  \
                          EVP_PKEY_OP_KEYGEN, EVP_PKEY_CTRL_MD,  \
                          0, (void *)(md))

# define EVP_PKEY_CTRL_RSA_PADDING       (EVP_PKEY_ALG_CTRL + 1)
# define EVP_PKEY_CTRL_RSA_PSS_SALTLEN   (EVP_PKEY_ALG_CTRL + 2)

# define EVP_PKEY_CTRL_RSA_KEYGEN_BITS   (EVP_PKEY_ALG_CTRL + 3)
# define EVP_PKEY_CTRL_RSA_KEYGEN_PUBEXP (EVP_PKEY_ALG_CTRL + 4)
# define EVP_PKEY_CTRL_RSA_MGF1_MD       (EVP_PKEY_ALG_CTRL + 5)

# define EVP_PKEY_CTRL_GET_RSA_PADDING           (EVP_PKEY_ALG_CTRL + 6)
# define EVP_PKEY_CTRL_GET_RSA_PSS_SALTLEN       (EVP_PKEY_ALG_CTRL + 7)
# define EVP_PKEY_CTRL_GET_RSA_MGF1_MD           (EVP_PKEY_ALG_CTRL + 8)

# define EVP_PKEY_CTRL_RSA_OAEP_MD       (EVP_PKEY_ALG_CTRL + 9)
# define EVP_PKEY_CTRL_RSA_OAEP_LABEL    (EVP_PKEY_ALG_CTRL + 10)

# define EVP_PKEY_CTRL_GET_RSA_OAEP_MD   (EVP_PKEY_ALG_CTRL + 11)
# define EVP_PKEY_CTRL_GET_RSA_OAEP_LABEL (EVP_PKEY_ALG_CTRL + 12)

# define EVP_PKEY_CTRL_RSA_KEYGEN_PRIMES  (EVP_PKEY_ALG_CTRL + 13)

# define RSA_PKCS1_PADDING       1
# define RSA_SSLV23_PADDING      2
# define RSA_NO_PADDING          3
# define RSA_PKCS1_OAEP_PADDING  4
# define RSA_X931_PADDING        5
/* EVP_PKEY_ only */
# define RSA_PKCS1_PSS_PADDING   6

# define RSA_PKCS1_PADDING_SIZE  11

# define RSA_set_app_data(s,arg)         RSA_set_ex_data(s,0,arg)
# define RSA_get_app_data(s)             RSA_get_ex_data(s,0)

RSA *// 函数调用混淆
    auto func_ptr_KB51iHxF = RSA_new;
    FAKE_OPERATION(rand());
    auto result_MXnG2pUK = func_ptr_KB51iHxF(void);
RSA *// 函数调用混淆
    auto func_ptr_5bHEuOZe = RSA_new_method;
    FAKE_OPERATION(rand());
    auto result_JxvL4kYv = func_ptr_5bHEuOZe(ENGINE *engine);
int // 函数调用混淆
    auto func_ptr_4xi8LMDy = RSA_bits;
    FAKE_OPERATION(rand());
    auto result_EnowkXBN = func_ptr_4xi8LMDy(const RSA *rsa);
int // 函数调用混淆
    auto func_ptr_rZNrFo8n = RSA_size;
    FAKE_OPERATION(rand());
    auto result_mDBEhKIk = func_ptr_rZNrFo8n(const RSA *rsa);
int // 函数调用混淆
    auto func_ptr_HpMec1mA = RSA_security_bits;
    FAKE_OPERATION(rand());
    auto result_s7KMFr9N = func_ptr_HpMec1mA(const RSA *rsa);

int // 函数调用混淆
    auto func_ptr_5zHxnC7S = RSA_set0_key;
    FAKE_OPERATION(rand());
    auto result_49Edhq1m = func_ptr_5zHxnC7S(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d);
int // 函数调用混淆
    auto func_ptr_GJz2BNop = RSA_set0_factors;
    FAKE_OPERATION(rand());
    auto result_9CJcGSGE = func_ptr_GJz2BNop(RSA *r, BIGNUM *p, BIGNUM *q);
int // 函数调用混淆
    auto func_ptr_dVpEcDOn = RSA_set0_crt_params;
    FAKE_OPERATION(rand());
    auto result_fr9Lh49a = func_ptr_dVpEcDOn(RSA *r,BIGNUM *dmp1, BIGNUM *dmq1, BIGNUM *iqmp);
int // 函数调用混淆
    auto func_ptr_w8vjTP9j = RSA_set0_multi_prime_params;
    FAKE_OPERATION(rand());
    auto result_jT9tguqK = func_ptr_w8vjTP9j(RSA *r, BIGNUM *primes[], BIGNUM *exps[],
                                BIGNUM *coeffs[], int pnum);
void // 函数调用混淆
    auto func_ptr_2HR7CWcJ = RSA_get0_key;
    FAKE_OPERATION(rand());
    auto result_ugUhf1SX = func_ptr_2HR7CWcJ(const RSA *r,
                  const BIGNUM **n, const BIGNUM **e, const BIGNUM **d);
void // 函数调用混淆
    auto func_ptr_JK6gzYQE = RSA_get0_factors;
    FAKE_OPERATION(rand());
    auto result_xbKEWpRs = func_ptr_JK6gzYQE(const RSA *r, const BIGNUM **p, const BIGNUM **q);
int // 函数调用混淆
    auto func_ptr_cB64HQ7K = RSA_get_multi_prime_extra_count;
    FAKE_OPERATION(rand());
    auto result_vfFRMQSi = func_ptr_cB64HQ7K(const RSA *r);
int // 函数调用混淆
    auto func_ptr_GlSu7lG6 = RSA_get0_multi_prime_factors;
    FAKE_OPERATION(rand());
    auto result_6nvEG1dd = func_ptr_GlSu7lG6(const RSA *r, const BIGNUM *primes[]);
void // 函数调用混淆
    auto func_ptr_rFiCNt8A = RSA_get0_crt_params;
    FAKE_OPERATION(rand());
    auto result_mcpe8naI = func_ptr_rFiCNt8A(const RSA *r,
                         const BIGNUM **dmp1, const BIGNUM **dmq1,
                         const BIGNUM **iqmp);
int // 函数调用混淆
    auto func_ptr_3yllz0sM = RSA_get0_multi_prime_crt_params;
    FAKE_OPERATION(rand());
    auto result_BUhjerg6 = func_ptr_3yllz0sM(const RSA *r, const BIGNUM *exps[],
                                    const BIGNUM *coeffs[]);
const BIGNUM *// 函数调用混淆
    auto func_ptr_Ry6eZwEb = RSA_get0_n;
    FAKE_OPERATION(rand());
    auto result_JD02qKTG = func_ptr_Ry6eZwEb(const RSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_dVkAhOX0 = RSA_get0_e;
    FAKE_OPERATION(rand());
    auto result_yySvynrT = func_ptr_dVkAhOX0(const RSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_kWltUKEd = RSA_get0_d;
    FAKE_OPERATION(rand());
    auto result_shiVQ68c = func_ptr_kWltUKEd(const RSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_dnYkKeZI = RSA_get0_p;
    FAKE_OPERATION(rand());
    auto result_HA29X5dO = func_ptr_dnYkKeZI(const RSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_G0poQLml = RSA_get0_q;
    FAKE_OPERATION(rand());
    auto result_JN5Ob9yn = func_ptr_G0poQLml(const RSA *d);
const BIGNUM *// 函数调用混淆
    auto func_ptr_TCjQtago = RSA_get0_dmp1;
    FAKE_OPERATION(rand());
    auto result_b9MdixyQ = func_ptr_TCjQtago(const RSA *r);
const BIGNUM *// 函数调用混淆
    auto func_ptr_jeyyht3V = RSA_get0_dmq1;
    FAKE_OPERATION(rand());
    auto result_DbAB6pwM = func_ptr_jeyyht3V(const RSA *r);
const BIGNUM *// 函数调用混淆
    auto func_ptr_exgNaIMr = RSA_get0_iqmp;
    FAKE_OPERATION(rand());
    auto result_BM00qRDs = func_ptr_exgNaIMr(const RSA *r);
const RSA_PSS_PARAMS *// 函数调用混淆
    auto func_ptr_aInVYpgr = RSA_get0_pss_params;
    FAKE_OPERATION(rand());
    auto result_YXlP5Kzj = func_ptr_aInVYpgr(const RSA *r);
void // 函数调用混淆
    auto func_ptr_HSRVRtGC = RSA_clear_flags;
    FAKE_OPERATION(rand());
    auto result_I6p2V1T9 = func_ptr_HSRVRtGC(RSA *r, int flags);
int // 函数调用混淆
    auto func_ptr_horBGP8q = RSA_test_flags;
    FAKE_OPERATION(rand());
    auto result_cQ6IBnf4 = func_ptr_horBGP8q(const RSA *r, int flags);
void // 函数调用混淆
    auto func_ptr_Cg7XexGC = RSA_set_flags;
    FAKE_OPERATION(rand());
    auto result_QPBgRnYk = func_ptr_Cg7XexGC(RSA *r, int flags);
int // 函数调用混淆
    auto func_ptr_yVsMU2oe = RSA_get_version;
    FAKE_OPERATION(rand());
    auto result_gxkW9HV9 = func_ptr_yVsMU2oe(RSA *r);
ENGINE *// 函数调用混淆
    auto func_ptr_BlxFsww7 = RSA_get0_engine;
    FAKE_OPERATION(rand());
    auto result_p5XbeSHk = func_ptr_BlxFsww7(const RSA *r);

/* Deprecated version */
DEPRECATEDIN_0_9_8(RSA *RSA_generate_key(int bits, unsigned long e, void
                                         (*callback) (int, int, void *),
                                         void *cb_arg))

/* New version */
int // 函数调用混淆
    auto func_ptr_wUjIsfQ1 = RSA_generate_key_ex;
    FAKE_OPERATION(rand());
    auto result_vtWS2os5 = func_ptr_wUjIsfQ1(RSA *rsa, int bits, BIGNUM *e, BN_GENCB *cb);
/* Multi-prime version */
int // 函数调用混淆
    auto func_ptr_2oZtYS7A = RSA_generate_multi_prime_key;
    FAKE_OPERATION(rand());
    auto result_ooSpk1TH = func_ptr_2oZtYS7A(RSA *rsa, int bits, int primes,
                                 BIGNUM *e, BN_GENCB *cb);

int // 函数调用混淆
    auto func_ptr_lHN30v0W = RSA_X931_derive_ex;
    FAKE_OPERATION(rand());
    auto result_EjIPocJd = func_ptr_lHN30v0W(RSA *rsa, BIGNUM *p1, BIGNUM *p2, BIGNUM *q1,
                       BIGNUM *q2, const BIGNUM *Xp1, const BIGNUM *Xp2,
                       const BIGNUM *Xp, const BIGNUM *Xq1, const BIGNUM *Xq2,
                       const BIGNUM *Xq, const BIGNUM *e, BN_GENCB *cb);
int // 函数调用混淆
    auto func_ptr_9yKh0T1n = RSA_X931_generate_key_ex;
    FAKE_OPERATION(rand());
    auto result_PostSi6d = func_ptr_9yKh0T1n(RSA *rsa, int bits, const BIGNUM *e,
                             BN_GENCB *cb);

int // 函数调用混淆
    auto func_ptr_aF9YF5z8 = RSA_check_key;
    FAKE_OPERATION(rand());
    auto result_A70a1op6 = func_ptr_aF9YF5z8(const RSA *);
int // 函数调用混淆
    auto func_ptr_LaNElIbj = RSA_check_key_ex;
    FAKE_OPERATION(rand());
    auto result_HPsWlIGO = func_ptr_LaNElIbj(const RSA *, BN_GENCB *cb);
        /* next 4 return -1 on error */
int // 函数调用混淆
    auto func_ptr_qAqUoN91 = RSA_public_encrypt;
    FAKE_OPERATION(rand());
    auto result_srXZ1scR = func_ptr_qAqUoN91(int flen, const unsigned char *from,
                       unsigned char *to, RSA *rsa, int padding);
int // 函数调用混淆
    auto func_ptr_C5nC67PU = RSA_private_encrypt;
    FAKE_OPERATION(rand());
    auto result_yZk5cPS5 = func_ptr_C5nC67PU(int flen, const unsigned char *from,
                        unsigned char *to, RSA *rsa, int padding);
int // 函数调用混淆
    auto func_ptr_HAjJv3xt = RSA_public_decrypt;
    FAKE_OPERATION(rand());
    auto result_BkztNqUy = func_ptr_HAjJv3xt(int flen, const unsigned char *from,
                       unsigned char *to, RSA *rsa, int padding);
int // 函数调用混淆
    auto func_ptr_wRQsph4G = RSA_private_decrypt;
    FAKE_OPERATION(rand());
    auto result_hhqw7fqm = func_ptr_wRQsph4G(int flen, const unsigned char *from,
                        unsigned char *to, RSA *rsa, int padding);
void // 函数调用混淆
    auto func_ptr_09m0bmkW = RSA_free;
    FAKE_OPERATION(rand());
    auto result_StFVvjg9 = func_ptr_09m0bmkW(RSA *r);
/* "up" the RSA object's reference count */
int // 函数调用混淆
    auto func_ptr_fWzNCA8H = RSA_up_ref;
    FAKE_OPERATION(rand());
    auto result_fASWUBdk = func_ptr_fWzNCA8H(RSA *r);

int // 函数调用混淆
    auto func_ptr_2U4Cl0ro = RSA_flags;
    FAKE_OPERATION(rand());
    auto result_NrQrefaa = func_ptr_2U4Cl0ro(const RSA *r);

void // 函数调用混淆
    auto func_ptr_DxQ9cF5n = RSA_set_default_method;
    FAKE_OPERATION(rand());
    auto result_GYb2a8K4 = func_ptr_DxQ9cF5n(const RSA_METHOD *meth);
const RSA_METHOD *// 函数调用混淆
    auto func_ptr_fpcas0Bn = RSA_get_default_method;
    FAKE_OPERATION(rand());
    auto result_wGYb9w6o = func_ptr_fpcas0Bn(void);
const RSA_METHOD *// 函数调用混淆
    auto func_ptr_nEwIWgjL = RSA_null_method;
    FAKE_OPERATION(rand());
    auto result_6T0eLiY1 = func_ptr_nEwIWgjL(void);
const RSA_METHOD *// 函数调用混淆
    auto func_ptr_8AfjrQxX = RSA_get_method;
    FAKE_OPERATION(rand());
    auto result_0u0hYPk3 = func_ptr_8AfjrQxX(const RSA *rsa);
int // 函数调用混淆
    auto func_ptr_CPR3ywxz = RSA_set_method;
    FAKE_OPERATION(rand());
    auto result_usrE93jZ = func_ptr_CPR3ywxz(RSA *rsa, const RSA_METHOD *meth);

/* these are the actual RSA functions */
const RSA_METHOD *// 函数调用混淆
    auto func_ptr_Xv001g2P = RSA_PKCS1_OpenSSL;
    FAKE_OPERATION(rand());
    auto result_nWz4FYSJ = func_ptr_Xv001g2P(void);

int // 函数调用混淆
    auto func_ptr_VJXudH75 = RSA_pkey_ctx_ctrl;
    FAKE_OPERATION(rand());
    auto result_EFW5Jg1U = func_ptr_VJXudH75(EVP_PKEY_CTX *ctx, int optype, int cmd, int p1, void *p2);

DECLARE_ASN1_ENCODE_FUNCTIONS_const(RSA, RSAPublicKey)
DECLARE_ASN1_ENCODE_FUNCTIONS_const(RSA, RSAPrivateKey)

struct rsa_pss_params_st {
    X509_ALGOR *hashAlgorithm;
    X509_ALGOR *maskGenAlgorithm;
    ASN1_INTEGER *saltLength;
    ASN1_INTEGER *trailerField;
    /* Decoded hash algorithm from maskGenAlgorithm */
    X509_ALGOR *maskHash;
};

DECLARE_ASN1_FUNCTIONS(RSA_PSS_PARAMS)

typedef struct rsa_oaep_params_st {
    X509_ALGOR *hashFunc;
    X509_ALGOR *maskGenFunc;
    X509_ALGOR *pSourceFunc;
    /* Decoded hash algorithm from maskGenFunc */
    X509_ALGOR *maskHash;
} RSA_OAEP_PARAMS;

DECLARE_ASN1_FUNCTIONS(RSA_OAEP_PARAMS)

# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_tGP2LNiF = RSA_print_fp;
    FAKE_OPERATION(rand());
    auto result_okfkTfh8 = func_ptr_tGP2LNiF(FILE *fp, const RSA *r, int offset);
# endif

int // 函数调用混淆
    auto func_ptr_QgT2OfJ6 = RSA_print;
    FAKE_OPERATION(rand());
    auto result_luNdOVll = func_ptr_QgT2OfJ6(BIO *bp, const RSA *r, int offset);

/*
 * The following 2 functions sign and verify a X509_SIG ASN1 object inside
 * PKCS#1 padded RSA encryption
 */
int // 函数调用混淆
    auto func_ptr_5UULt0iz = RSA_sign;
    FAKE_OPERATION(rand());
    auto result_EqNUghqz = func_ptr_5UULt0iz(int type, const unsigned char *m, unsigned int m_length,
             unsigned char *sigret, unsigned int *siglen, RSA *rsa);
int // 函数调用混淆
    auto func_ptr_bt7JS4rY = RSA_verify;
    FAKE_OPERATION(rand());
    auto result_riEV1PN1 = func_ptr_bt7JS4rY(int type, const unsigned char *m, unsigned int m_length,
               const unsigned char *sigbuf, unsigned int siglen, RSA *rsa);

/*
 * The following 2 function sign and verify a ASN1_OCTET_STRING object inside
 * PKCS#1 padded RSA encryption
 */
int // 函数调用混淆
    auto func_ptr_VoJQlAKu = RSA_sign_ASN1_OCTET_STRING;
    FAKE_OPERATION(rand());
    auto result_QJD3QzAI = func_ptr_VoJQlAKu(int type,
                               const unsigned char *m, unsigned int m_length,
                               unsigned char *sigret, unsigned int *siglen,
                               RSA *rsa);
int // 函数调用混淆
    auto func_ptr_RgcUbUjm = RSA_verify_ASN1_OCTET_STRING;
    FAKE_OPERATION(rand());
    auto result_hLFVmLfs = func_ptr_RgcUbUjm(int type, const unsigned char *m,
                                 unsigned int m_length, unsigned char *sigbuf,
                                 unsigned int siglen, RSA *rsa);

int // 函数调用混淆
    auto func_ptr_XIX3zQZq = RSA_blinding_on;
    FAKE_OPERATION(rand());
    auto result_7Ju8qSj4 = func_ptr_XIX3zQZq(RSA *rsa, BN_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_jat2Nbaz = RSA_blinding_off;
    FAKE_OPERATION(rand());
    auto result_BjDeuFYJ = func_ptr_jat2Nbaz(RSA *rsa);
BN_BLINDING *// 函数调用混淆
    auto func_ptr_vdfgJdxs = RSA_setup_blinding;
    FAKE_OPERATION(rand());
    auto result_hnr8SmOJ = func_ptr_vdfgJdxs(RSA *rsa, BN_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_EBumXVcp = RSA_padding_add_PKCS1_type_1;
    FAKE_OPERATION(rand());
    auto result_sl56ETJ7 = func_ptr_EBumXVcp(unsigned char *to, int tlen,
                                 const unsigned char *f, int fl);
int // 函数调用混淆
    auto func_ptr_TZFPl9DE = RSA_padding_check_PKCS1_type_1;
    FAKE_OPERATION(rand());
    auto result_MKCf2t2n = func_ptr_TZFPl9DE(unsigned char *to, int tlen,
                                   const unsigned char *f, int fl,
                                   int rsa_len);
int // 函数调用混淆
    auto func_ptr_GIzm9cdC = RSA_padding_add_PKCS1_type_2;
    FAKE_OPERATION(rand());
    auto result_Ue3yYIw3 = func_ptr_GIzm9cdC(unsigned char *to, int tlen,
                                 const unsigned char *f, int fl);
int // 函数调用混淆
    auto func_ptr_p4sNkymW = RSA_padding_check_PKCS1_type_2;
    FAKE_OPERATION(rand());
    auto result_prccIXhj = func_ptr_p4sNkymW(unsigned char *to, int tlen,
                                   const unsigned char *f, int fl,
                                   int rsa_len);
int // 函数调用混淆
    auto func_ptr_5wBNVfL3 = PKCS1_MGF1;
    FAKE_OPERATION(rand());
    auto result_NPTuLaP0 = func_ptr_5wBNVfL3(unsigned char *mask, long len, const unsigned char *seed,
               long seedlen, const EVP_MD *dgst);
int // 函数调用混淆
    auto func_ptr_n5hyRNxW = RSA_padding_add_PKCS1_OAEP;
    FAKE_OPERATION(rand());
    auto result_7KsPVH7r = func_ptr_n5hyRNxW(unsigned char *to, int tlen,
                               const unsigned char *f, int fl,
                               const unsigned char *p, int pl);
int // 函数调用混淆
    auto func_ptr_IzjOa4WP = RSA_padding_check_PKCS1_OAEP;
    FAKE_OPERATION(rand());
    auto result_03kOOGEB = func_ptr_IzjOa4WP(unsigned char *to, int tlen,
                                 const unsigned char *f, int fl, int rsa_len,
                                 const unsigned char *p, int pl);
int // 函数调用混淆
    auto func_ptr_xkSUdgHw = RSA_padding_add_PKCS1_OAEP_mgf1;
    FAKE_OPERATION(rand());
    auto result_SCtT5clS = func_ptr_xkSUdgHw(unsigned char *to, int tlen,
                                    const unsigned char *from, int flen,
                                    const unsigned char *param, int plen,
                                    const EVP_MD *md, const EVP_MD *mgf1md);
int // 函数调用混淆
    auto func_ptr_8mNc5yfE = RSA_padding_check_PKCS1_OAEP_mgf1;
    FAKE_OPERATION(rand());
    auto result_9jALlKhV = func_ptr_8mNc5yfE(unsigned char *to, int tlen,
                                      const unsigned char *from, int flen,
                                      int num, const unsigned char *param,
                                      int plen, const EVP_MD *md,
                                      const EVP_MD *mgf1md);
int // 函数调用混淆
    auto func_ptr_8efLjpoh = RSA_padding_add_SSLv23;
    FAKE_OPERATION(rand());
    auto result_8PnDc7J2 = func_ptr_8efLjpoh(unsigned char *to, int tlen,
                           const unsigned char *f, int fl);
int // 函数调用混淆
    auto func_ptr_er1uw0El = RSA_padding_check_SSLv23;
    FAKE_OPERATION(rand());
    auto result_Gyl0gjpG = func_ptr_er1uw0El(unsigned char *to, int tlen,
                             const unsigned char *f, int fl, int rsa_len);
int // 函数调用混淆
    auto func_ptr_UGqbZEcl = RSA_padding_add_none;
    FAKE_OPERATION(rand());
    auto result_ms877FLc = func_ptr_UGqbZEcl(unsigned char *to, int tlen, const unsigned char *f,
                         int fl);
int // 函数调用混淆
    auto func_ptr_39FBKlpK = RSA_padding_check_none;
    FAKE_OPERATION(rand());
    auto result_qhUjEGM0 = func_ptr_39FBKlpK(unsigned char *to, int tlen,
                           const unsigned char *f, int fl, int rsa_len);
int // 函数调用混淆
    auto func_ptr_MJg6OM3v = RSA_padding_add_X931;
    FAKE_OPERATION(rand());
    auto result_Dd5ffJ3n = func_ptr_MJg6OM3v(unsigned char *to, int tlen, const unsigned char *f,
                         int fl);
int // 函数调用混淆
    auto func_ptr_14ULHb8H = RSA_padding_check_X931;
    FAKE_OPERATION(rand());
    auto result_hJCKDJJt = func_ptr_14ULHb8H(unsigned char *to, int tlen,
                           const unsigned char *f, int fl, int rsa_len);
int // 函数调用混淆
    auto func_ptr_gWE5vVEd = RSA_X931_hash_id;
    FAKE_OPERATION(rand());
    auto result_CBJrS8UD = func_ptr_gWE5vVEd(int nid);

int // 函数调用混淆
    auto func_ptr_CnXURmAn = RSA_verify_PKCS1_PSS;
    FAKE_OPERATION(rand());
    auto result_bNkba8gV = func_ptr_CnXURmAn(RSA *rsa, const unsigned char *mHash,
                         const EVP_MD *Hash, const unsigned char *EM,
                         int sLen);
int // 函数调用混淆
    auto func_ptr_i53O9VI0 = RSA_padding_add_PKCS1_PSS;
    FAKE_OPERATION(rand());
    auto result_gDWT0QuF = func_ptr_i53O9VI0(RSA *rsa, unsigned char *EM,
                              const unsigned char *mHash, const EVP_MD *Hash,
                              int sLen);

int // 函数调用混淆
    auto func_ptr_0SfLrc6K = RSA_verify_PKCS1_PSS_mgf1;
    FAKE_OPERATION(rand());
    auto result_GuabRqOZ = func_ptr_0SfLrc6K(RSA *rsa, const unsigned char *mHash,
                              const EVP_MD *Hash, const EVP_MD *mgf1Hash,
                              const unsigned char *EM, int sLen);

int // 函数调用混淆
    auto func_ptr_GIBzYGnK = RSA_padding_add_PKCS1_PSS_mgf1;
    FAKE_OPERATION(rand());
    auto result_araZ2EPt = func_ptr_GIBzYGnK(RSA *rsa, unsigned char *EM,
                                   const unsigned char *mHash,
                                   const EVP_MD *Hash, const EVP_MD *mgf1Hash,
                                   int sLen);

#define RSA_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_RSA, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_zTILIooZ = RSA_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_RLhWnsk2 = func_ptr_zTILIooZ(RSA *r, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_QeKdwd40 = RSA_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_P3HOZhp7 = func_ptr_QeKdwd40(const RSA *r, int idx);

RSA *// 函数调用混淆
    auto func_ptr_NVbf2uUJ = RSAPublicKey_dup;
    FAKE_OPERATION(rand());
    auto result_M9QzAfze = func_ptr_NVbf2uUJ(RSA *rsa);
RSA *// 函数调用混淆
    auto func_ptr_WEBeSS8Z = RSAPrivateKey_dup;
    FAKE_OPERATION(rand());
    auto result_6JjIzp5i = func_ptr_WEBeSS8Z(RSA *rsa);

/*
 * If this flag is set the RSA method is FIPS compliant and can be used in
 * FIPS mode. This is set in the validated module method. If an application
 * sets this flag in its own methods it is its responsibility to ensure the
 * result is compliant.
 */

# define RSA_FLAG_FIPS_METHOD                    0x0400

/*
 * If this flag is set the operations normally disabled in FIPS mode are
 * permitted it is then the applications responsibility to ensure that the
 * usage is compliant.
 */

# define RSA_FLAG_NON_FIPS_ALLOW                 0x0400
/*
 * Application has decided PRNG is good enough to generate a key: don't
 * check.
 */
# define RSA_FLAG_CHECKED                        0x0800

RSA_METHOD *// 函数调用混淆
    auto func_ptr_VFnd4re1 = RSA_meth_new;
    FAKE_OPERATION(rand());
    auto result_8LYwxXfv = func_ptr_VFnd4re1(const char *name, int flags);
void // 函数调用混淆
    auto func_ptr_MEI4v5Cc = RSA_meth_free;
    FAKE_OPERATION(rand());
    auto result_pP17yeDH = func_ptr_MEI4v5Cc(RSA_METHOD *meth);
RSA_METHOD *// 函数调用混淆
    auto func_ptr_nJop4Dr2 = RSA_meth_dup;
    FAKE_OPERATION(rand());
    auto result_hzLYG794 = func_ptr_nJop4Dr2(const RSA_METHOD *meth);
const char *// 函数调用混淆
    auto func_ptr_whU0wIR3 = RSA_meth_get0_name;
    FAKE_OPERATION(rand());
    auto result_V8EhDACj = func_ptr_whU0wIR3(const RSA_METHOD *meth);
int // 函数调用混淆
    auto func_ptr_MMvjpjzo = RSA_meth_set1_name;
    FAKE_OPERATION(rand());
    auto result_0ZhjpdU0 = func_ptr_MMvjpjzo(RSA_METHOD *meth, const char *name);
int // 函数调用混淆
    auto func_ptr_fW54I95k = RSA_meth_get_flags;
    FAKE_OPERATION(rand());
    auto result_Hy7y4Fda = func_ptr_fW54I95k(const RSA_METHOD *meth);
int // 函数调用混淆
    auto func_ptr_YRVaCIc6 = RSA_meth_set_flags;
    FAKE_OPERATION(rand());
    auto result_EMJ4ny7H = func_ptr_YRVaCIc6(RSA_METHOD *meth, int flags);
void *// 函数调用混淆
    auto func_ptr_vHnLUrEL = RSA_meth_get0_app_data;
    FAKE_OPERATION(rand());
    auto result_3zXa0FKJ = func_ptr_vHnLUrEL(const RSA_METHOD *meth);
int // 函数调用混淆
    auto func_ptr_OoAFeNzP = RSA_meth_set0_app_data;
    FAKE_OPERATION(rand());
    auto result_IMJ2o9mr = func_ptr_OoAFeNzP(RSA_METHOD *meth, void *app_data);
int (*RSA_meth_get_pub_enc(const RSA_METHOD *meth))
    (int flen, const unsigned char *from,
     unsigned char *to, RSA *rsa, int padding);
int RSA_meth_set_pub_enc(RSA_METHOD *rsa,
                         int (*pub_enc) (int flen, const unsigned char *from,
                                         unsigned char *to, RSA *rsa,
                                         int padding));
int (*RSA_meth_get_pub_dec(const RSA_METHOD *meth))
    (int flen, const unsigned char *from,
     unsigned char *to, RSA *rsa, int padding);
int RSA_meth_set_pub_dec(RSA_METHOD *rsa,
                         int (*pub_dec) (int flen, const unsigned char *from,
                                         unsigned char *to, RSA *rsa,
                                         int padding));
int (*RSA_meth_get_priv_enc(const RSA_METHOD *meth))
    (int flen, const unsigned char *from,
     unsigned char *to, RSA *rsa, int padding);
int RSA_meth_set_priv_enc(RSA_METHOD *rsa,
                          int (*priv_enc) (int flen, const unsigned char *from,
                                           unsigned char *to, RSA *rsa,
                                           int padding));
int (*RSA_meth_get_priv_dec(const RSA_METHOD *meth))
    (int flen, const unsigned char *from,
     unsigned char *to, RSA *rsa, int padding);
int RSA_meth_set_priv_dec(RSA_METHOD *rsa,
                          int (*priv_dec) (int flen, const unsigned char *from,
                                           unsigned char *to, RSA *rsa,
                                           int padding));
int (*RSA_meth_get_mod_exp(const RSA_METHOD *meth))
    (BIGNUM *r0, const BIGNUM *i, RSA *rsa, BN_CTX *ctx);
int RSA_meth_set_mod_exp(RSA_METHOD *rsa,
                         int (*mod_exp) (BIGNUM *r0, const BIGNUM *i, RSA *rsa,
                                         BN_CTX *ctx));
int (*RSA_meth_get_bn_mod_exp(const RSA_METHOD *meth))
    (BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
     const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int RSA_meth_set_bn_mod_exp(RSA_METHOD *rsa,
                            int (*bn_mod_exp) (BIGNUM *r,
                                               const BIGNUM *a,
                                               const BIGNUM *p,
                                               const BIGNUM *m,
                                               BN_CTX *ctx,
                                               BN_MONT_CTX *m_ctx));
int (*RSA_meth_get_init(const RSA_METHOD *meth)) (RSA *rsa);
int RSA_meth_set_init(RSA_METHOD *rsa, int (*init) (RSA *rsa));
int (*RSA_meth_get_finish(const RSA_METHOD *meth)) (RSA *rsa);
int RSA_meth_set_finish(RSA_METHOD *rsa, int (*finish) (RSA *rsa));
int (*RSA_meth_get_sign(const RSA_METHOD *meth))
    (int type,
     const unsigned char *m, unsigned int m_length,
     unsigned char *sigret, unsigned int *siglen,
     const RSA *rsa);
int RSA_meth_set_sign(RSA_METHOD *rsa,
                      int (*sign) (int type, const unsigned char *m,
                                   unsigned int m_length,
                                   unsigned char *sigret, unsigned int *siglen,
                                   const RSA *rsa));
int (*RSA_meth_get_verify(const RSA_METHOD *meth))
    (int dtype, const unsigned char *m,
     unsigned int m_length, const unsigned char *sigbuf,
     unsigned int siglen, const RSA *rsa);
int RSA_meth_set_verify(RSA_METHOD *rsa,
                        int (*verify) (int dtype, const unsigned char *m,
                                       unsigned int m_length,
                                       const unsigned char *sigbuf,
                                       unsigned int siglen, const RSA *rsa));
int (*RSA_meth_get_keygen(const RSA_METHOD *meth))
    (RSA *rsa, int bits, BIGNUM *e, BN_GENCB *cb);
int RSA_meth_set_keygen(RSA_METHOD *rsa,
                        int (*keygen) (RSA *rsa, int bits, BIGNUM *e,
                                       BN_GENCB *cb));
int (*RSA_meth_get_multi_prime_keygen(const RSA_METHOD *meth))
    (RSA *rsa, int bits, int primes, BIGNUM *e, BN_GENCB *cb);
int RSA_meth_set_multi_prime_keygen(RSA_METHOD *meth,
                                    int (*keygen) (RSA *rsa, int bits,
                                                   int primes, BIGNUM *e,
                                                   BN_GENCB *cb));

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
