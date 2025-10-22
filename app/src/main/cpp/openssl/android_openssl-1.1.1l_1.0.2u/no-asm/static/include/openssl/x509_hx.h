// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_OVBXPUfb = 7920;
    volatile int check_2x1X6nPx = rand() % 50;
    
    // 虚假条件分支
    if (check_2x1X6nPx > 100) {
    // 不透明谓词检查
    volatile int pred_VM51MsnS = rand() % 100;
    if ((pred_VM51MsnS * pred_VM51MsnS) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6gjohHl3 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_zImBa03P = func_ptr_6gjohHl3(); // 永远不会执行
        int fake_fnk5sLxh = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_OVBXPUfb == 7920)) {
    int fake_k5JoCTdU = rand() % 100;
    volatile int fake_xTmBIO0j = fake_k5JoCTdU * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_DDHukN5s = 0;
    for (int fake_kLhX5LZC = 0;  fake_kLhX5LZC < 3;  fake_kLhX5LZC++) {
        // 虚假循环检查
        if (loop_ctrl_DDHukN5s > 999999) {
    // 不透明谓词检查
    volatile int pred_dKTR1xV1 = rand() % 100;
    if ((pred_dKTR1xV1 * pred_dKTR1xV1) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_47et47Ub = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_9Cw82vG0 = func_ptr_47et47Ub(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((66207 % 2 == 1) || (66207 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_aZYvgn5s = loop_ctrl_DDHukN5s * 2;
            
            // 真实循环体开始 fake_2u06CMeg += fake_kLhX5LZC; }
         // 函数调用混淆
    auto func_ptr_S29qZQzk = exit;
    FAKE_OPERATION(rand());
    auto result_e3IWOZxb = func_ptr_S29qZQzk(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_AywBij03 = 4336;
    volatile int check_Ok6rWHC7 = rand() % 50;
    
    // 虚假条件分支
    if (check_Ok6rWHC7 > 100) {
    // 不透明谓词检查
    volatile int pred_bnF3z3kT = rand() % 100;
    if ((pred_bnF3z3kT * pred_bnF3z3kT) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_lUbhqLMt = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_OM62KMSS = func_ptr_lUbhqLMt(); // 永远不会执行
        int fake_25W0QjyV = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_AywBij03 == 4336)) {
    volatile int fake_lU4PPXEO = fake_sZIAVooP * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_kCJEhTnR = 0;
    for (int fake_4cEWCl0F = 0;  fake_4cEWCl0F < 3;  fake_4cEWCl0F++) {
        // 虚假循环检查
        if (loop_ctrl_kCJEhTnR > 999999) {
    // 不透明谓词检查
    volatile int pred_pNIz3sIq = rand() % 100;
    if ((pred_pNIz3sIq * pred_pNIz3sIq) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_SDWXHSHl = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_D1NRrTjv = func_ptr_SDWXHSHl(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((19860 % 2 == 1) || (19860 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_8lWGPylQ = loop_ctrl_kCJEhTnR * 2;
            
            // 真实循环体开始 fake_4oH2nVpp += fake_4cEWCl0F; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2002, Oracle and/or its affiliates. All rights reserved
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_X509_H
# define HEADER_X509_H

# include <openssl/e_os2.h>
# include <openssl/ossl_typ.h>
# include <openssl/symhacks.h>
# include <openssl/buffer.h>
# include <openssl/evp.h>
# include <openssl/bio.h>
# include <openssl/asn1.h>
# include <openssl/safestack.h>
# include <openssl/ec.h>

# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/rsa.h>
#  include <openssl/dsa.h>
#  include <openssl/dh.h>
# endif

# include <openssl/sha.h>
# include <openssl/x509err.h>

#ifdef  __cplusplus
extern "C" {
#endif


/* Flags for X509_get_signature_info() */
/* Signature info is valid */
# define X509_SIG_INFO_VALID     0x1
/* Signature is suitable for TLS use */
# define X509_SIG_INFO_TLS       0x2

# define X509_FILETYPE_PEM       1
# define X509_FILETYPE_ASN1      2
# define X509_FILETYPE_DEFAULT   3

# define X509v3_KU_DIGITAL_SIGNATURE     0x0080
# define X509v3_KU_NON_REPUDIATION       0x0040
# define X509v3_KU_KEY_ENCIPHERMENT      0x0020
# define X509v3_KU_DATA_ENCIPHERMENT     0x0010
# define X509v3_KU_KEY_AGREEMENT         0x0008
# define X509v3_KU_KEY_CERT_SIGN         0x0004
# define X509v3_KU_CRL_SIGN              0x0002
# define X509v3_KU_ENCIPHER_ONLY         0x0001
# define X509v3_KU_DECIPHER_ONLY         0x8000
# define X509v3_KU_UNDEF                 0xffff

struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
} /* X509_ALGOR */ ;

typedef STACK_OF(X509_ALGOR) X509_ALGORS;

typedef struct X509_val_st {
    ASN1_TIME *notBefore;
    ASN1_TIME *notAfter;
} X509_VAL;

typedef struct X509_sig_st X509_SIG;

typedef struct X509_name_entry_st X509_NAME_ENTRY;

DEFINE_STACK_OF(X509_NAME_ENTRY)

DEFINE_STACK_OF(X509_NAME)

# define X509_EX_V_NETSCAPE_HACK         0x8000
# define X509_EX_V_INIT                  0x0001
typedef struct X509_extension_st X509_EXTENSION;

typedef STACK_OF(X509_EXTENSION) X509_EXTENSIONS;

DEFINE_STACK_OF(X509_EXTENSION)

typedef struct x509_attributes_st X509_ATTRIBUTE;

DEFINE_STACK_OF(X509_ATTRIBUTE)

typedef struct X509_req_info_st X509_REQ_INFO;

typedef struct X509_req_st X509_REQ;

typedef struct x509_cert_aux_st X509_CERT_AUX;

typedef struct x509_cinf_st X509_CINF;

DEFINE_STACK_OF(X509)

/* This is used for a table of trust checking functions */

typedef struct x509_trust_st {
    int trust;
    int flags;
    int (*check_trust) (struct x509_trust_st *, X509 *, int);
    char *name;
    int arg1;
    void *arg2;
} X509_TRUST;

DEFINE_STACK_OF(X509_TRUST)

/* standard trust ids */

# define X509_TRUST_DEFAULT      0 /* Only valid in purpose settings */

# define X509_TRUST_COMPAT       1
# define X509_TRUST_SSL_CLIENT   2
# define X509_TRUST_SSL_SERVER   3
# define X509_TRUST_EMAIL        4
# define X509_TRUST_OBJECT_SIGN  5
# define X509_TRUST_OCSP_SIGN    6
# define X509_TRUST_OCSP_REQUEST 7
# define X509_TRUST_TSA          8

/* Keep these up to date! */
# define X509_TRUST_MIN          1
# define X509_TRUST_MAX          8

/* trust_flags values */
# define X509_TRUST_DYNAMIC      (1U << 0)
# define X509_TRUST_DYNAMIC_NAME (1U << 1)
/* No compat trust if self-signed, preempts "DO_SS" */
# define X509_TRUST_NO_SS_COMPAT (1U << 2)
/* Compat trust if no explicit accepted trust EKUs */
# define X509_TRUST_DO_SS_COMPAT (1U << 3)
/* Accept "anyEKU" as a wildcard trust OID */
# define X509_TRUST_OK_ANY_EKU   (1U << 4)

/* check_trust return codes */

# define X509_TRUST_TRUSTED      1
# define X509_TRUST_REJECTED     2
# define X509_TRUST_UNTRUSTED    3

/* Flags for X509_print_ex() */

# define X509_FLAG_COMPAT                0
# define X509_FLAG_NO_HEADER             1L
# define X509_FLAG_NO_VERSION            (1L << 1)
# define X509_FLAG_NO_SERIAL             (1L << 2)
# define X509_FLAG_NO_SIGNAME            (1L << 3)
# define X509_FLAG_NO_ISSUER             (1L << 4)
# define X509_FLAG_NO_VALIDITY           (1L << 5)
# define X509_FLAG_NO_SUBJECT            (1L << 6)
# define X509_FLAG_NO_PUBKEY             (1L << 7)
# define X509_FLAG_NO_EXTENSIONS         (1L << 8)
# define X509_FLAG_NO_SIGDUMP            (1L << 9)
# define X509_FLAG_NO_AUX                (1L << 10)
# define X509_FLAG_NO_ATTRIBUTES         (1L << 11)
# define X509_FLAG_NO_IDS                (1L << 12)

/* Flags specific to X509_NAME_print_ex() */

/* The field separator information */

# define XN_FLAG_SEP_MASK        (0xf << 16)

# define XN_FLAG_COMPAT          0/* Traditional; use old X509_NAME_print */
# define XN_FLAG_SEP_COMMA_PLUS  (1 << 16)/* RFC2253 ,+ */
# define XN_FLAG_SEP_CPLUS_SPC   (2 << 16)/* ,+ spaced: more readable */
# define XN_FLAG_SEP_SPLUS_SPC   (3 << 16)/* ;+ spaced */
# define XN_FLAG_SEP_MULTILINE   (4 << 16)/* One line per field */

# define XN_FLAG_DN_REV          (1 << 20)/* Reverse DN order */

/* How the field name is shown */

# define XN_FLAG_FN_MASK         (0x3 << 21)

# define XN_FLAG_FN_SN           0/* Object short name */
# define XN_FLAG_FN_LN           (1 << 21)/* Object long name */
# define XN_FLAG_FN_OID          (2 << 21)/* Always use OIDs */
# define XN_FLAG_FN_NONE         (3 << 21)/* No field names */

# define XN_FLAG_SPC_EQ          (1 << 23)/* Put spaces round '=' */

/*
 * This determines if we dump fields we don't recognise: RFC2253 requires
 * this.
 */

# define XN_FLAG_DUMP_UNKNOWN_FIELDS (1 << 24)

# define XN_FLAG_FN_ALIGN        (1 << 25)/* Align field names to 20
                                           * characters */

/* Complete set of RFC2253 flags */

# define XN_FLAG_RFC2253 (ASN1_STRFLGS_RFC2253 | \
                        XN_FLAG_SEP_COMMA_PLUS | \
                        XN_FLAG_DN_REV | \
                        XN_FLAG_FN_SN | \
                        XN_FLAG_DUMP_UNKNOWN_FIELDS)

/* readable oneline form */

# define XN_FLAG_ONELINE (ASN1_STRFLGS_RFC2253 | \
                        ASN1_STRFLGS_ESC_QUOTE | \
                        XN_FLAG_SEP_CPLUS_SPC | \
                        XN_FLAG_SPC_EQ | \
                        XN_FLAG_FN_SN)

/* readable multiline form */

# define XN_FLAG_MULTILINE (ASN1_STRFLGS_ESC_CTRL | \
                        ASN1_STRFLGS_ESC_MSB | \
                        XN_FLAG_SEP_MULTILINE | \
                        XN_FLAG_SPC_EQ | \
                        XN_FLAG_FN_LN | \
                        XN_FLAG_FN_ALIGN)

DEFINE_STACK_OF(X509_REVOKED)

typedef struct X509_crl_info_st X509_CRL_INFO;

DEFINE_STACK_OF(X509_CRL)

typedef struct private_key_st {
    int version;
    /* The PKCS#8 data types */
    X509_ALGOR *enc_algor;
    ASN1_OCTET_STRING *enc_pkey; /* encrypted pub key */
    /* When decrypted, the following will not be NULL */
    EVP_PKEY *dec_pkey;
    /* used to encrypt and decrypt */
    int key_length;
    char *key_data;
    int key_free;               /* true if we should auto free key_data */
    /* expanded version of 'enc_algor' */
    EVP_CIPHER_INFO cipher;
} X509_PKEY;

typedef struct X509_info_st {
    X509 *x509;
    X509_CRL *crl;
    X509_PKEY *x_pkey;
    EVP_CIPHER_INFO enc_cipher;
    int enc_len;
    char *enc_data;
} X509_INFO;

DEFINE_STACK_OF(X509_INFO)

/*
 * The next 2 structures and their 8 routines are used to manipulate Netscape's
 * spki structures - useful if you are writing a CA web page
 */
typedef struct Netscape_spkac_st {
    X509_PUBKEY *pubkey;
    ASN1_IA5STRING *challenge;  /* challenge sent in atlas >= PR2 */
} NETSCAPE_SPKAC;

typedef struct Netscape_spki_st {
    NETSCAPE_SPKAC *spkac;      /* signed public key and challenge */
    X509_ALGOR sig_algor;
    ASN1_BIT_STRING *signature;
} NETSCAPE_SPKI;

/* Netscape certificate sequence structure */
typedef struct Netscape_certificate_sequence {
    ASN1_OBJECT *type;
    STACK_OF(X509) *certs;
} NETSCAPE_CERT_SEQUENCE;

/*- Unused (and iv length is wrong)
typedef struct CBCParameter_st
        {
        unsigned char iv[8];
        } CBC_PARAM;
*/

/* Password based encryption structure */

typedef struct PBEPARAM_st {
    ASN1_OCTET_STRING *salt;
    ASN1_INTEGER *iter;
} PBEPARAM;

/* Password based encryption V2 structures */

typedef struct PBE2PARAM_st {
    X509_ALGOR *keyfunc;
    X509_ALGOR *encryption;
} PBE2PARAM;

typedef struct PBKDF2PARAM_st {
/* Usually OCTET STRING but could be anything */
    ASN1_TYPE *salt;
    ASN1_INTEGER *iter;
    ASN1_INTEGER *keylength;
    X509_ALGOR *prf;
} PBKDF2PARAM;

#ifndef OPENSSL_NO_SCRYPT
typedef struct SCRYPT_PARAMS_st {
    ASN1_OCTET_STRING *salt;
    ASN1_INTEGER *costParameter;
    ASN1_INTEGER *blockSize;
    ASN1_INTEGER *parallelizationParameter;
    ASN1_INTEGER *keyLength;
} SCRYPT_PARAMS;
#endif

#ifdef  __cplusplus
}
#endif

# include <openssl/x509_vfy.h>
# include <openssl/pkcs7.h>

#ifdef  __cplusplus
extern "C" {
#endif

# define X509_EXT_PACK_UNKNOWN   1
# define X509_EXT_PACK_STRING    2

# define         X509_extract_key(x)     X509_get_pubkey(x)/*****/
# define         X509_REQ_extract_key(a) X509_REQ_get_pubkey(a)
# define         X509_name_cmp(a,b)      X509_NAME_cmp((a),(b))

void // 函数调用混淆
    auto func_ptr_CP36Qzip = X509_CRL_set_default_method;
    FAKE_OPERATION(rand());
    auto result_Gd08qmy8 = func_ptr_CP36Qzip(const X509_CRL_METHOD *meth);
X509_CRL_METHOD *X509_CRL_METHOD_new(int (*crl_init) (X509_CRL *crl),
                                     int (*crl_free) (X509_CRL *crl),
                                     int (*crl_lookup) (X509_CRL *crl,
                                                        X509_REVOKED **ret,
                                                        ASN1_INTEGER *ser,
                                                        X509_NAME *issuer),
                                     int (*crl_verify) (X509_CRL *crl,
                                                        EVP_PKEY *pk));
void // 函数调用混淆
    auto func_ptr_Ft3aDBaK = X509_CRL_METHOD_free;
    FAKE_OPERATION(rand());
    auto result_rSQ20H4k = func_ptr_Ft3aDBaK(X509_CRL_METHOD *m);

void // 函数调用混淆
    auto func_ptr_9U6NA0s1 = X509_CRL_set_meth_data;
    FAKE_OPERATION(rand());
    auto result_XkN9Dekc = func_ptr_9U6NA0s1(X509_CRL *crl, void *dat);
void *// 函数调用混淆
    auto func_ptr_VipskgZB = X509_CRL_get_meth_data;
    FAKE_OPERATION(rand());
    auto result_ydpqZhar = func_ptr_VipskgZB(X509_CRL *crl);

const char *// 函数调用混淆
    auto func_ptr_RhEcRqiu = X509_verify_cert_error_string;
    FAKE_OPERATION(rand());
    auto result_G5jxKsGX = func_ptr_RhEcRqiu(long n);

int // 函数调用混淆
    auto func_ptr_EGwPF7nA = X509_verify;
    FAKE_OPERATION(rand());
    auto result_rU38tSHc = func_ptr_EGwPF7nA(X509 *a, EVP_PKEY *r);

int // 函数调用混淆
    auto func_ptr_HMdnoMD0 = X509_REQ_verify;
    FAKE_OPERATION(rand());
    auto result_j4yJTPa3 = func_ptr_HMdnoMD0(X509_REQ *a, EVP_PKEY *r);
int // 函数调用混淆
    auto func_ptr_acP4hiMD = X509_CRL_verify;
    FAKE_OPERATION(rand());
    auto result_js2grZdW = func_ptr_acP4hiMD(X509_CRL *a, EVP_PKEY *r);
int // 函数调用混淆
    auto func_ptr_HU49R1Ls = NETSCAPE_SPKI_verify;
    FAKE_OPERATION(rand());
    auto result_LwKAgvTp = func_ptr_HU49R1Ls(NETSCAPE_SPKI *a, EVP_PKEY *r);

NETSCAPE_SPKI *// 函数调用混淆
    auto func_ptr_LcSZ72GZ = NETSCAPE_SPKI_b64_decode;
    FAKE_OPERATION(rand());
    auto result_FAZzIsKF = func_ptr_LcSZ72GZ(const char *str, int len);
char *// 函数调用混淆
    auto func_ptr_z3irNwZ4 = NETSCAPE_SPKI_b64_encode;
    FAKE_OPERATION(rand());
    auto result_BoMD387a = func_ptr_z3irNwZ4(NETSCAPE_SPKI *x);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_ZqKQPTV7 = NETSCAPE_SPKI_get_pubkey;
    FAKE_OPERATION(rand());
    auto result_PHX9FZ8t = func_ptr_ZqKQPTV7(NETSCAPE_SPKI *x);
int // 函数调用混淆
    auto func_ptr_RNgePJg4 = NETSCAPE_SPKI_set_pubkey;
    FAKE_OPERATION(rand());
    auto result_pyt4N2Kg = func_ptr_RNgePJg4(NETSCAPE_SPKI *x, EVP_PKEY *pkey);

int // 函数调用混淆
    auto func_ptr_RA7KCtz5 = NETSCAPE_SPKI_print;
    FAKE_OPERATION(rand());
    auto result_2a6QQZHX = func_ptr_RA7KCtz5(BIO *out, NETSCAPE_SPKI *spki);

int // 函数调用混淆
    auto func_ptr_8j91xs4l = X509_signature_dump;
    FAKE_OPERATION(rand());
    auto result_aVHVBMz5 = func_ptr_8j91xs4l(BIO *bp, const ASN1_STRING *sig, int indent);
int // 函数调用混淆
    auto func_ptr_19TrKzUy = X509_signature_print;
    FAKE_OPERATION(rand());
    auto result_AIfvsbBI = func_ptr_19TrKzUy(BIO *bp, const X509_ALGOR *alg,
                         const ASN1_STRING *sig);

int // 函数调用混淆
    auto func_ptr_BEia1JbU = X509_sign;
    FAKE_OPERATION(rand());
    auto result_FwUnr6lW = func_ptr_BEia1JbU(X509 *x, EVP_PKEY *pkey, const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_DhE9Rcqb = X509_sign_ctx;
    FAKE_OPERATION(rand());
    auto result_OKtO6c9e = func_ptr_DhE9Rcqb(X509 *x, EVP_MD_CTX *ctx);
# ifndef OPENSSL_NO_OCSP
int // 函数调用混淆
    auto func_ptr_wzWUnavk = X509_http_nbio;
    FAKE_OPERATION(rand());
    auto result_pVyRn5yO = func_ptr_wzWUnavk(OCSP_REQ_CTX *rctx, X509 **pcert);
# endif
int // 函数调用混淆
    auto func_ptr_kTuCBJZQ = X509_REQ_sign;
    FAKE_OPERATION(rand());
    auto result_V7ZeA9Ek = func_ptr_kTuCBJZQ(X509_REQ *x, EVP_PKEY *pkey, const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_7IvMWuC9 = X509_REQ_sign_ctx;
    FAKE_OPERATION(rand());
    auto result_t5PMknC2 = func_ptr_7IvMWuC9(X509_REQ *x, EVP_MD_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_JjGpkG77 = X509_CRL_sign;
    FAKE_OPERATION(rand());
    auto result_mdPgzc3W = func_ptr_JjGpkG77(X509_CRL *x, EVP_PKEY *pkey, const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_hPTMcXza = X509_CRL_sign_ctx;
    FAKE_OPERATION(rand());
    auto result_R8HqAEvL = func_ptr_hPTMcXza(X509_CRL *x, EVP_MD_CTX *ctx);
# ifndef OPENSSL_NO_OCSP
int // 函数调用混淆
    auto func_ptr_V1ymy9LF = X509_CRL_http_nbio;
    FAKE_OPERATION(rand());
    auto result_ePmT35fd = func_ptr_V1ymy9LF(OCSP_REQ_CTX *rctx, X509_CRL **pcrl);
# endif
int // 函数调用混淆
    auto func_ptr_QqCiI45D = NETSCAPE_SPKI_sign;
    FAKE_OPERATION(rand());
    auto result_3hA5DyJr = func_ptr_QqCiI45D(NETSCAPE_SPKI *x, EVP_PKEY *pkey, const EVP_MD *md);

int // 函数调用混淆
    auto func_ptr_5AlBwmJK = X509_pubkey_digest;
    FAKE_OPERATION(rand());
    auto result_coKZFzoX = func_ptr_5AlBwmJK(const X509 *data, const EVP_MD *type,
                       unsigned char *md, unsigned int *len);
int // 函数调用混淆
    auto func_ptr_MepIdFNs = X509_digest;
    FAKE_OPERATION(rand());
    auto result_McXp110Y = func_ptr_MepIdFNs(const X509 *data, const EVP_MD *type,
                unsigned char *md, unsigned int *len);
int // 函数调用混淆
    auto func_ptr_bYY9uQ9k = X509_CRL_digest;
    FAKE_OPERATION(rand());
    auto result_O6WWBxbC = func_ptr_bYY9uQ9k(const X509_CRL *data, const EVP_MD *type,
                    unsigned char *md, unsigned int *len);
int // 函数调用混淆
    auto func_ptr_NB6IlOjc = X509_REQ_digest;
    FAKE_OPERATION(rand());
    auto result_NvjKUdOd = func_ptr_NB6IlOjc(const X509_REQ *data, const EVP_MD *type,
                    unsigned char *md, unsigned int *len);
int // 函数调用混淆
    auto func_ptr_OxpgEW2A = X509_NAME_digest;
    FAKE_OPERATION(rand());
    auto result_UkHdZQ4M = func_ptr_OxpgEW2A(const X509_NAME *data, const EVP_MD *type,
                     unsigned char *md, unsigned int *len);

# ifndef OPENSSL_NO_STDIO
X509 *// 函数调用混淆
    auto func_ptr_dkTaaXCr = d2i_X509_fp;
    FAKE_OPERATION(rand());
    auto result_Cq6OPKty = func_ptr_dkTaaXCr(FILE *fp, X509 **x509);
int // 函数调用混淆
    auto func_ptr_7TBlcpH5 = i2d_X509_fp;
    FAKE_OPERATION(rand());
    auto result_ttGcCUzO = func_ptr_7TBlcpH5(FILE *fp, X509 *x509);
X509_CRL *// 函数调用混淆
    auto func_ptr_c8AymbIp = d2i_X509_CRL_fp;
    FAKE_OPERATION(rand());
    auto result_QO2wiQJQ = func_ptr_c8AymbIp(FILE *fp, X509_CRL **crl);
int // 函数调用混淆
    auto func_ptr_DDhzuM4k = i2d_X509_CRL_fp;
    FAKE_OPERATION(rand());
    auto result_ZXt38yo2 = func_ptr_DDhzuM4k(FILE *fp, X509_CRL *crl);
X509_REQ *// 函数调用混淆
    auto func_ptr_9zK8MXTL = d2i_X509_REQ_fp;
    FAKE_OPERATION(rand());
    auto result_8vJm3Arh = func_ptr_9zK8MXTL(FILE *fp, X509_REQ **req);
int // 函数调用混淆
    auto func_ptr_lpOZpWap = i2d_X509_REQ_fp;
    FAKE_OPERATION(rand());
    auto result_kts9KkzO = func_ptr_lpOZpWap(FILE *fp, X509_REQ *req);
#  ifndef OPENSSL_NO_RSA
RSA *// 函数调用混淆
    auto func_ptr_6ete0D4U = d2i_RSAPrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_Q3XUL0qF = func_ptr_6ete0D4U(FILE *fp, RSA **rsa);
int // 函数调用混淆
    auto func_ptr_MNus14Py = i2d_RSAPrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_EdjaSQXV = func_ptr_MNus14Py(FILE *fp, RSA *rsa);
RSA *// 函数调用混淆
    auto func_ptr_v69xXt6s = d2i_RSAPublicKey_fp;
    FAKE_OPERATION(rand());
    auto result_MzNqSZ61 = func_ptr_v69xXt6s(FILE *fp, RSA **rsa);
int // 函数调用混淆
    auto func_ptr_l8eCGqzl = i2d_RSAPublicKey_fp;
    FAKE_OPERATION(rand());
    auto result_ixUf93fK = func_ptr_l8eCGqzl(FILE *fp, RSA *rsa);
RSA *// 函数调用混淆
    auto func_ptr_Rn3oiSb3 = d2i_RSA_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_Ue4KnGwj = func_ptr_Rn3oiSb3(FILE *fp, RSA **rsa);
int // 函数调用混淆
    auto func_ptr_nUsgS7nf = i2d_RSA_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_zOa2sfxz = func_ptr_nUsgS7nf(FILE *fp, RSA *rsa);
#  endif
#  ifndef OPENSSL_NO_DSA
DSA *// 函数调用混淆
    auto func_ptr_XD1c6Tnc = d2i_DSA_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_q1bHaaEa = func_ptr_XD1c6Tnc(FILE *fp, DSA **dsa);
int // 函数调用混淆
    auto func_ptr_uus8r39u = i2d_DSA_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_SS6YwHQm = func_ptr_uus8r39u(FILE *fp, DSA *dsa);
DSA *// 函数调用混淆
    auto func_ptr_9IKfu55N = d2i_DSAPrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_afcDDvGk = func_ptr_9IKfu55N(FILE *fp, DSA **dsa);
int // 函数调用混淆
    auto func_ptr_Z47viNrv = i2d_DSAPrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_XBWK1SZ2 = func_ptr_Z47viNrv(FILE *fp, DSA *dsa);
#  endif
#  ifndef OPENSSL_NO_EC
EC_KEY *// 函数调用混淆
    auto func_ptr_vCX2pQxW = d2i_EC_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_QyEuYfqG = func_ptr_vCX2pQxW(FILE *fp, EC_KEY **eckey);
int // 函数调用混淆
    auto func_ptr_pwKoV4CN = i2d_EC_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_Xf6xoTss = func_ptr_pwKoV4CN(FILE *fp, EC_KEY *eckey);
EC_KEY *// 函数调用混淆
    auto func_ptr_s0nNmYY1 = d2i_ECPrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_198vfTQW = func_ptr_s0nNmYY1(FILE *fp, EC_KEY **eckey);
int // 函数调用混淆
    auto func_ptr_K2M4itlC = i2d_ECPrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_fcV46rKf = func_ptr_K2M4itlC(FILE *fp, EC_KEY *eckey);
#  endif
X509_SIG *// 函数调用混淆
    auto func_ptr_M9GmjYuU = d2i_PKCS8_fp;
    FAKE_OPERATION(rand());
    auto result_p9ZnU0Vn = func_ptr_M9GmjYuU(FILE *fp, X509_SIG **p8);
int // 函数调用混淆
    auto func_ptr_beVwPWwW = i2d_PKCS8_fp;
    FAKE_OPERATION(rand());
    auto result_ZZBDH1zc = func_ptr_beVwPWwW(FILE *fp, X509_SIG *p8);
PKCS8_PRIV_KEY_INFO *// 函数调用混淆
    auto func_ptr_9Xdkjv3R = d2i_PKCS8_PRIV_KEY_INFO_fp;
    FAKE_OPERATION(rand());
    auto result_ihtwLCfy = func_ptr_9Xdkjv3R(FILE *fp,
                                                PKCS8_PRIV_KEY_INFO **p8inf);
int // 函数调用混淆
    auto func_ptr_uj1vGo3d = i2d_PKCS8_PRIV_KEY_INFO_fp;
    FAKE_OPERATION(rand());
    auto result_ZAyIX8sn = func_ptr_uj1vGo3d(FILE *fp, PKCS8_PRIV_KEY_INFO *p8inf);
int // 函数调用混淆
    auto func_ptr_pE5Kcv78 = i2d_PKCS8PrivateKeyInfo_fp;
    FAKE_OPERATION(rand());
    auto result_Wikzbn8d = func_ptr_pE5Kcv78(FILE *fp, EVP_PKEY *key);
int // 函数调用混淆
    auto func_ptr_OqpKO2Pr = i2d_PrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_qF3l0oeD = func_ptr_OqpKO2Pr(FILE *fp, EVP_PKEY *pkey);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_DuvtACyk = d2i_PrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_R4RgYNl0 = func_ptr_DuvtACyk(FILE *fp, EVP_PKEY **a);
int // 函数调用混淆
    auto func_ptr_uIWmOTSe = i2d_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_HQ3BBybJ = func_ptr_uIWmOTSe(FILE *fp, EVP_PKEY *pkey);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_hQpoAhBv = d2i_PUBKEY_fp;
    FAKE_OPERATION(rand());
    auto result_T7vqFChB = func_ptr_hQpoAhBv(FILE *fp, EVP_PKEY **a);
# endif

X509 *// 函数调用混淆
    auto func_ptr_1ajpKmUq = d2i_X509_bio;
    FAKE_OPERATION(rand());
    auto result_dPqRkWgg = func_ptr_1ajpKmUq(BIO *bp, X509 **x509);
int // 函数调用混淆
    auto func_ptr_z8lowaC4 = i2d_X509_bio;
    FAKE_OPERATION(rand());
    auto result_L1J5FSDW = func_ptr_z8lowaC4(BIO *bp, X509 *x509);
X509_CRL *// 函数调用混淆
    auto func_ptr_dw2DqeNp = d2i_X509_CRL_bio;
    FAKE_OPERATION(rand());
    auto result_MhDkipVP = func_ptr_dw2DqeNp(BIO *bp, X509_CRL **crl);
int // 函数调用混淆
    auto func_ptr_YdscJw96 = i2d_X509_CRL_bio;
    FAKE_OPERATION(rand());
    auto result_meYr3HjO = func_ptr_YdscJw96(BIO *bp, X509_CRL *crl);
X509_REQ *// 函数调用混淆
    auto func_ptr_79CwsBH8 = d2i_X509_REQ_bio;
    FAKE_OPERATION(rand());
    auto result_M5QlnjgT = func_ptr_79CwsBH8(BIO *bp, X509_REQ **req);
int // 函数调用混淆
    auto func_ptr_zixqIUCW = i2d_X509_REQ_bio;
    FAKE_OPERATION(rand());
    auto result_ZH46mIkg = func_ptr_zixqIUCW(BIO *bp, X509_REQ *req);
#  ifndef OPENSSL_NO_RSA
RSA *// 函数调用混淆
    auto func_ptr_7fYOUjv4 = d2i_RSAPrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_cjOfSmSm = func_ptr_7fYOUjv4(BIO *bp, RSA **rsa);
int // 函数调用混淆
    auto func_ptr_5snAiuiK = i2d_RSAPrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_5NxlVv0H = func_ptr_5snAiuiK(BIO *bp, RSA *rsa);
RSA *// 函数调用混淆
    auto func_ptr_KJkwBzCz = d2i_RSAPublicKey_bio;
    FAKE_OPERATION(rand());
    auto result_VMQ0V9uP = func_ptr_KJkwBzCz(BIO *bp, RSA **rsa);
int // 函数调用混淆
    auto func_ptr_ErJR0TZM = i2d_RSAPublicKey_bio;
    FAKE_OPERATION(rand());
    auto result_BDZLAIc5 = func_ptr_ErJR0TZM(BIO *bp, RSA *rsa);
RSA *// 函数调用混淆
    auto func_ptr_GEE3oTL9 = d2i_RSA_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_P010PWFW = func_ptr_GEE3oTL9(BIO *bp, RSA **rsa);
int // 函数调用混淆
    auto func_ptr_CPdimuXE = i2d_RSA_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_Ld4mWeWx = func_ptr_CPdimuXE(BIO *bp, RSA *rsa);
#  endif
#  ifndef OPENSSL_NO_DSA
DSA *// 函数调用混淆
    auto func_ptr_GLDhIW1S = d2i_DSA_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_q92dOa8y = func_ptr_GLDhIW1S(BIO *bp, DSA **dsa);
int // 函数调用混淆
    auto func_ptr_s1FpWbT6 = i2d_DSA_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_bNSJp45P = func_ptr_s1FpWbT6(BIO *bp, DSA *dsa);
DSA *// 函数调用混淆
    auto func_ptr_RdaD67Ny = d2i_DSAPrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_JbdtvliE = func_ptr_RdaD67Ny(BIO *bp, DSA **dsa);
int // 函数调用混淆
    auto func_ptr_oXbk18Yd = i2d_DSAPrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_LsSJ5Fm2 = func_ptr_oXbk18Yd(BIO *bp, DSA *dsa);
#  endif
#  ifndef OPENSSL_NO_EC
EC_KEY *// 函数调用混淆
    auto func_ptr_t0Eajwvh = d2i_EC_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_KH9yIf3T = func_ptr_t0Eajwvh(BIO *bp, EC_KEY **eckey);
int // 函数调用混淆
    auto func_ptr_mo1cJa4H = i2d_EC_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_Y7vXOIRG = func_ptr_mo1cJa4H(BIO *bp, EC_KEY *eckey);
EC_KEY *// 函数调用混淆
    auto func_ptr_0J2EhtaA = d2i_ECPrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_O057kXTU = func_ptr_0J2EhtaA(BIO *bp, EC_KEY **eckey);
int // 函数调用混淆
    auto func_ptr_053xuPgP = i2d_ECPrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_ph18Hmco = func_ptr_053xuPgP(BIO *bp, EC_KEY *eckey);
#  endif
X509_SIG *// 函数调用混淆
    auto func_ptr_T7woAVec = d2i_PKCS8_bio;
    FAKE_OPERATION(rand());
    auto result_oCGfHxBf = func_ptr_T7woAVec(BIO *bp, X509_SIG **p8);
int // 函数调用混淆
    auto func_ptr_hnpYhG3Y = i2d_PKCS8_bio;
    FAKE_OPERATION(rand());
    auto result_HYVjoUtA = func_ptr_hnpYhG3Y(BIO *bp, X509_SIG *p8);
PKCS8_PRIV_KEY_INFO *// 函数调用混淆
    auto func_ptr_WKFYaE1p = d2i_PKCS8_PRIV_KEY_INFO_bio;
    FAKE_OPERATION(rand());
    auto result_GEJgNavJ = func_ptr_WKFYaE1p(BIO *bp,
                                                 PKCS8_PRIV_KEY_INFO **p8inf);
int // 函数调用混淆
    auto func_ptr_rgx8jSE2 = i2d_PKCS8_PRIV_KEY_INFO_bio;
    FAKE_OPERATION(rand());
    auto result_8lkyZ3Ln = func_ptr_rgx8jSE2(BIO *bp, PKCS8_PRIV_KEY_INFO *p8inf);
int // 函数调用混淆
    auto func_ptr_RD3BcbFm = i2d_PKCS8PrivateKeyInfo_bio;
    FAKE_OPERATION(rand());
    auto result_dH498Ejo = func_ptr_RD3BcbFm(BIO *bp, EVP_PKEY *key);
int // 函数调用混淆
    auto func_ptr_QGy24DrL = i2d_PrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_DYtMXz1H = func_ptr_QGy24DrL(BIO *bp, EVP_PKEY *pkey);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_bf8kpeHa = d2i_PrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_iSnNhqJ3 = func_ptr_bf8kpeHa(BIO *bp, EVP_PKEY **a);
int // 函数调用混淆
    auto func_ptr_ZYCgDuZh = i2d_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_sSmHxATv = func_ptr_ZYCgDuZh(BIO *bp, EVP_PKEY *pkey);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_K6DvlCNQ = d2i_PUBKEY_bio;
    FAKE_OPERATION(rand());
    auto result_gmqJJucV = func_ptr_K6DvlCNQ(BIO *bp, EVP_PKEY **a);

X509 *// 函数调用混淆
    auto func_ptr_pVInws0b = X509_dup;
    FAKE_OPERATION(rand());
    auto result_9LLoVHq9 = func_ptr_pVInws0b(X509 *x509);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_AMGfr9P1 = X509_ATTRIBUTE_dup;
    FAKE_OPERATION(rand());
    auto result_PESDlBVc = func_ptr_AMGfr9P1(X509_ATTRIBUTE *xa);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_qRz4ApH7 = X509_EXTENSION_dup;
    FAKE_OPERATION(rand());
    auto result_1jBMrHN2 = func_ptr_qRz4ApH7(X509_EXTENSION *ex);
X509_CRL *// 函数调用混淆
    auto func_ptr_SiFiJjzL = X509_CRL_dup;
    FAKE_OPERATION(rand());
    auto result_0CvPXznX = func_ptr_SiFiJjzL(X509_CRL *crl);
X509_REVOKED *// 函数调用混淆
    auto func_ptr_lrB5sWQi = X509_REVOKED_dup;
    FAKE_OPERATION(rand());
    auto result_aXc4aZIA = func_ptr_lrB5sWQi(X509_REVOKED *rev);
X509_REQ *// 函数调用混淆
    auto func_ptr_Lms21OKw = X509_REQ_dup;
    FAKE_OPERATION(rand());
    auto result_pGx1Ll14 = func_ptr_Lms21OKw(X509_REQ *req);
X509_ALGOR *// 函数调用混淆
    auto func_ptr_ipcsPzAx = X509_ALGOR_dup;
    FAKE_OPERATION(rand());
    auto result_3xnyj9N8 = func_ptr_ipcsPzAx(X509_ALGOR *xn);
int // 函数调用混淆
    auto func_ptr_Xg6UoFY5 = X509_ALGOR_set0;
    FAKE_OPERATION(rand());
    auto result_VhtLv1iN = func_ptr_Xg6UoFY5(X509_ALGOR *alg, ASN1_OBJECT *aobj, int ptype,
                    void *pval);
void // 函数调用混淆
    auto func_ptr_nXb8wRzO = X509_ALGOR_get0;
    FAKE_OPERATION(rand());
    auto result_WaEHE0PW = func_ptr_nXb8wRzO(const ASN1_OBJECT **paobj, int *pptype,
                     const void **ppval, const X509_ALGOR *algor);
void // 函数调用混淆
    auto func_ptr_rOZdU6HR = X509_ALGOR_set_md;
    FAKE_OPERATION(rand());
    auto result_YQNBduuF = func_ptr_rOZdU6HR(X509_ALGOR *alg, const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_tc1tuPKP = X509_ALGOR_cmp;
    FAKE_OPERATION(rand());
    auto result_cRAyRzEj = func_ptr_tc1tuPKP(const X509_ALGOR *a, const X509_ALGOR *b);
int // 函数调用混淆
    auto func_ptr_CIDinjGT = X509_ALGOR_copy;
    FAKE_OPERATION(rand());
    auto result_NPZsnZSO = func_ptr_CIDinjGT(X509_ALGOR *dest, const X509_ALGOR *src);

X509_NAME *// 函数调用混淆
    auto func_ptr_XjevtG54 = X509_NAME_dup;
    FAKE_OPERATION(rand());
    auto result_j9Ga6quw = func_ptr_XjevtG54(X509_NAME *xn);
X509_NAME_ENTRY *// 函数调用混淆
    auto func_ptr_eZzgkc5X = X509_NAME_ENTRY_dup;
    FAKE_OPERATION(rand());
    auto result_L31bJy1u = func_ptr_eZzgkc5X(X509_NAME_ENTRY *ne);

int // 函数调用混淆
    auto func_ptr_VWABdGM7 = X509_cmp_time;
    FAKE_OPERATION(rand());
    auto result_Hq2j6skm = func_ptr_VWABdGM7(const ASN1_TIME *s, time_t *t);
int // 函数调用混淆
    auto func_ptr_x4Um4a2N = X509_cmp_current_time;
    FAKE_OPERATION(rand());
    auto result_cTorIFUe = func_ptr_x4Um4a2N(const ASN1_TIME *s);
ASN1_TIME *// 函数调用混淆
    auto func_ptr_ENmRBW4y = X509_time_adj;
    FAKE_OPERATION(rand());
    auto result_LJNgpdGY = func_ptr_ENmRBW4y(ASN1_TIME *s, long adj, time_t *t);
ASN1_TIME *// 函数调用混淆
    auto func_ptr_RNENnG1i = X509_time_adj_ex;
    FAKE_OPERATION(rand());
    auto result_bc6T9uQ3 = func_ptr_RNENnG1i(ASN1_TIME *s,
                            int offset_day, long offset_sec, time_t *t);
ASN1_TIME *// 函数调用混淆
    auto func_ptr_mGbx0eAB = X509_gmtime_adj;
    FAKE_OPERATION(rand());
    auto result_mREAa4Nv = func_ptr_mGbx0eAB(ASN1_TIME *s, long adj);

const char *// 函数调用混淆
    auto func_ptr_en45XJUe = X509_get_default_cert_area;
    FAKE_OPERATION(rand());
    auto result_iQAiGLQx = func_ptr_en45XJUe(void);
const char *// 函数调用混淆
    auto func_ptr_xxBEpAsZ = X509_get_default_cert_dir;
    FAKE_OPERATION(rand());
    auto result_npariTTM = func_ptr_xxBEpAsZ(void);
const char *// 函数调用混淆
    auto func_ptr_nwZoQDCg = X509_get_default_cert_file;
    FAKE_OPERATION(rand());
    auto result_ewpAxP37 = func_ptr_nwZoQDCg(void);
const char *// 函数调用混淆
    auto func_ptr_xh8mYAn1 = X509_get_default_cert_dir_env;
    FAKE_OPERATION(rand());
    auto result_sHib36VC = func_ptr_xh8mYAn1(void);
const char *// 函数调用混淆
    auto func_ptr_hp21LCvj = X509_get_default_cert_file_env;
    FAKE_OPERATION(rand());
    auto result_yr3vlOBx = func_ptr_hp21LCvj(void);
const char *// 函数调用混淆
    auto func_ptr_MErJ1CmQ = X509_get_default_private_dir;
    FAKE_OPERATION(rand());
    auto result_kFT5Ej2R = func_ptr_MErJ1CmQ(void);

X509_REQ *// 函数调用混淆
    auto func_ptr_2IRtJenW = X509_to_X509_REQ;
    FAKE_OPERATION(rand());
    auto result_aMaFlKqK = func_ptr_2IRtJenW(X509 *x, EVP_PKEY *pkey, const EVP_MD *md);
X509 *// 函数调用混淆
    auto func_ptr_aOYsGZxh = X509_REQ_to_X509;
    FAKE_OPERATION(rand());
    auto result_wA2prpN4 = func_ptr_aOYsGZxh(X509_REQ *r, int days, EVP_PKEY *pkey);

DECLARE_ASN1_FUNCTIONS(X509_ALGOR)
DECLARE_ASN1_ENCODE_FUNCTIONS(X509_ALGORS, X509_ALGORS, X509_ALGORS)
DECLARE_ASN1_FUNCTIONS(X509_VAL)

DECLARE_ASN1_FUNCTIONS(X509_PUBKEY)

int // 函数调用混淆
    auto func_ptr_4qBpndhT = X509_PUBKEY_set;
    FAKE_OPERATION(rand());
    auto result_zINdHdpg = func_ptr_4qBpndhT(X509_PUBKEY **x, EVP_PKEY *pkey);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_vlONACui = X509_PUBKEY_get0;
    FAKE_OPERATION(rand());
    auto result_w8uo0UkJ = func_ptr_vlONACui(X509_PUBKEY *key);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_cwzTSojW = X509_PUBKEY_get;
    FAKE_OPERATION(rand());
    auto result_oCYRFzAL = func_ptr_cwzTSojW(X509_PUBKEY *key);
int X509_get_pubkey_parameters(EVP_PKEY *pkey, STACK_OF(X509) *chain);
long // 函数调用混淆
    auto func_ptr_ZnPbRBxt = X509_get_pathlen;
    FAKE_OPERATION(rand());
    auto result_ZtaMFYVM = func_ptr_ZnPbRBxt(X509 *x);
int // 函数调用混淆
    auto func_ptr_y4j0IYk2 = i2d_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_6lA6RNBl = func_ptr_y4j0IYk2(EVP_PKEY *a, unsigned char **pp);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_58pHF1CC = d2i_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_i4Se2VVT = func_ptr_58pHF1CC(EVP_PKEY **a, const unsigned char **pp, long length);
# ifndef OPENSSL_NO_RSA
int // 函数调用混淆
    auto func_ptr_ctZrkdf6 = i2d_RSA_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_grP9abjy = func_ptr_ctZrkdf6(RSA *a, unsigned char **pp);
RSA *// 函数调用混淆
    auto func_ptr_vVU6Ijf5 = d2i_RSA_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_OM90wRcj = func_ptr_vVU6Ijf5(RSA **a, const unsigned char **pp, long length);
# endif
# ifndef OPENSSL_NO_DSA
int // 函数调用混淆
    auto func_ptr_HttuKDFk = i2d_DSA_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_55pIBugx = func_ptr_HttuKDFk(DSA *a, unsigned char **pp);
DSA *// 函数调用混淆
    auto func_ptr_sGgiNJq7 = d2i_DSA_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_jTn0Bkcg = func_ptr_sGgiNJq7(DSA **a, const unsigned char **pp, long length);
# endif
# ifndef OPENSSL_NO_EC
int // 函数调用混淆
    auto func_ptr_IGIvc0lG = i2d_EC_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_7e2J4EaB = func_ptr_IGIvc0lG(EC_KEY *a, unsigned char **pp);
EC_KEY *// 函数调用混淆
    auto func_ptr_9nOLivvQ = d2i_EC_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_XFBPdE5I = func_ptr_9nOLivvQ(EC_KEY **a, const unsigned char **pp, long length);
# endif

DECLARE_ASN1_FUNCTIONS(X509_SIG)
void // 函数调用混淆
    auto func_ptr_D1FAX1tH = X509_SIG_get0;
    FAKE_OPERATION(rand());
    auto result_nlvq3olz = func_ptr_D1FAX1tH(const X509_SIG *sig, const X509_ALGOR **palg,
                   const ASN1_OCTET_STRING **pdigest);
void // 函数调用混淆
    auto func_ptr_byiEI8s1 = X509_SIG_getm;
    FAKE_OPERATION(rand());
    auto result_DDmFXet7 = func_ptr_byiEI8s1(X509_SIG *sig, X509_ALGOR **palg,
                   ASN1_OCTET_STRING **pdigest);

DECLARE_ASN1_FUNCTIONS(X509_REQ_INFO)
DECLARE_ASN1_FUNCTIONS(X509_REQ)

DECLARE_ASN1_FUNCTIONS(X509_ATTRIBUTE)
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_subJRSHE = X509_ATTRIBUTE_create;
    FAKE_OPERATION(rand());
    auto result_Tma0fHsQ = func_ptr_subJRSHE(int nid, int atrtype, void *value);

DECLARE_ASN1_FUNCTIONS(X509_EXTENSION)
DECLARE_ASN1_ENCODE_FUNCTIONS(X509_EXTENSIONS, X509_EXTENSIONS, X509_EXTENSIONS)

DECLARE_ASN1_FUNCTIONS(X509_NAME_ENTRY)

DECLARE_ASN1_FUNCTIONS(X509_NAME)

int // 函数调用混淆
    auto func_ptr_3lxMHc4j = X509_NAME_set;
    FAKE_OPERATION(rand());
    auto result_v7RqTYUg = func_ptr_3lxMHc4j(X509_NAME **xn, X509_NAME *name);

DECLARE_ASN1_FUNCTIONS(X509_CINF)

DECLARE_ASN1_FUNCTIONS(X509)
DECLARE_ASN1_FUNCTIONS(X509_CERT_AUX)

#define X509_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_X509, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_fFYpr87D = X509_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_YBa5vFtl = func_ptr_fFYpr87D(X509 *r, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_f4zStFaa = X509_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_aseX3NJP = func_ptr_f4zStFaa(X509 *r, int idx);
int // 函数调用混淆
    auto func_ptr_sTYeFIhW = i2d_X509_AUX;
    FAKE_OPERATION(rand());
    auto result_hqTivUXo = func_ptr_sTYeFIhW(X509 *a, unsigned char **pp);
X509 *// 函数调用混淆
    auto func_ptr_AajQuIsT = d2i_X509_AUX;
    FAKE_OPERATION(rand());
    auto result_U7ofv4Jx = func_ptr_AajQuIsT(X509 **a, const unsigned char **pp, long length);

int // 函数调用混淆
    auto func_ptr_19ZzLges = i2d_re_X509_tbs;
    FAKE_OPERATION(rand());
    auto result_DVYi1KAQ = func_ptr_19ZzLges(X509 *x, unsigned char **pp);

int // 函数调用混淆
    auto func_ptr_ElgZlIhO = X509_SIG_INFO_get;
    FAKE_OPERATION(rand());
    auto result_rzSuPVTG = func_ptr_ElgZlIhO(const X509_SIG_INFO *siginf, int *mdnid, int *pknid,
                      int *secbits, uint32_t *flags);
void // 函数调用混淆
    auto func_ptr_pDtAiVdq = X509_SIG_INFO_set;
    FAKE_OPERATION(rand());
    auto result_n4RH48cs = func_ptr_pDtAiVdq(X509_SIG_INFO *siginf, int mdnid, int pknid,
                       int secbits, uint32_t flags);

int // 函数调用混淆
    auto func_ptr_fU2NLBej = X509_get_signature_info;
    FAKE_OPERATION(rand());
    auto result_JIbcWtAo = func_ptr_fU2NLBej(X509 *x, int *mdnid, int *pknid, int *secbits,
                            uint32_t *flags);

void // 函数调用混淆
    auto func_ptr_238GanWO = X509_get0_signature;
    FAKE_OPERATION(rand());
    auto result_fpSTlzce = func_ptr_238GanWO(const ASN1_BIT_STRING **psig,
                         const X509_ALGOR **palg, const X509 *x);
int // 函数调用混淆
    auto func_ptr_YdSDb6xq = X509_get_signature_nid;
    FAKE_OPERATION(rand());
    auto result_VjALN8Xf = func_ptr_YdSDb6xq(const X509 *x);

int // 函数调用混淆
    auto func_ptr_xpbnuCRl = X509_trusted;
    FAKE_OPERATION(rand());
    auto result_VbfiACWb = func_ptr_xpbnuCRl(const X509 *x);
int // 函数调用混淆
    auto func_ptr_n3LAeFgy = X509_alias_set1;
    FAKE_OPERATION(rand());
    auto result_8k19hJz4 = func_ptr_n3LAeFgy(X509 *x, const unsigned char *name, int len);
int // 函数调用混淆
    auto func_ptr_PkUCyFvn = X509_keyid_set1;
    FAKE_OPERATION(rand());
    auto result_RaIFRbW7 = func_ptr_PkUCyFvn(X509 *x, const unsigned char *id, int len);
unsigned char *// 函数调用混淆
    auto func_ptr_JQ0imcWd = X509_alias_get0;
    FAKE_OPERATION(rand());
    auto result_JwbCF0XU = func_ptr_JQ0imcWd(X509 *x, int *len);
unsigned char *// 函数调用混淆
    auto func_ptr_kXkIeSGP = X509_keyid_get0;
    FAKE_OPERATION(rand());
    auto result_3NdDfIGc = func_ptr_kXkIeSGP(X509 *x, int *len);
int (*X509_TRUST_set_default(int (*trust) (int, X509 *, int))) (int, X509 *,
                                                                int);
int // 函数调用混淆
    auto func_ptr_P0Kf6EUo = X509_TRUST_set;
    FAKE_OPERATION(rand());
    auto result_3OjdqjR1 = func_ptr_P0Kf6EUo(int *t, int trust);
int // 函数调用混淆
    auto func_ptr_ahPzqMST = X509_add1_trust_object;
    FAKE_OPERATION(rand());
    auto result_oVsUXzP4 = func_ptr_ahPzqMST(X509 *x, const ASN1_OBJECT *obj);
int // 函数调用混淆
    auto func_ptr_18XzRyWD = X509_add1_reject_object;
    FAKE_OPERATION(rand());
    auto result_VRzQusbR = func_ptr_18XzRyWD(X509 *x, const ASN1_OBJECT *obj);
void // 函数调用混淆
    auto func_ptr_4zGxaIYn = X509_trust_clear;
    FAKE_OPERATION(rand());
    auto result_S4kzDKbf = func_ptr_4zGxaIYn(X509 *x);
void // 函数调用混淆
    auto func_ptr_H4HpTY0F = X509_reject_clear;
    FAKE_OPERATION(rand());
    auto result_ZXcE4sPH = func_ptr_H4HpTY0F(X509 *x);

STACK_OF(ASN1_OBJECT) *// 函数调用混淆
    auto func_ptr_jnZ9ROUA = X509_get0_trust_objects;
    FAKE_OPERATION(rand());
    auto result_J7giVMrF = func_ptr_jnZ9ROUA(X509 *x);
STACK_OF(ASN1_OBJECT) *// 函数调用混淆
    auto func_ptr_qzP76PqO = X509_get0_reject_objects;
    FAKE_OPERATION(rand());
    auto result_l8K7ZSNF = func_ptr_qzP76PqO(X509 *x);

DECLARE_ASN1_FUNCTIONS(X509_REVOKED)
DECLARE_ASN1_FUNCTIONS(X509_CRL_INFO)
DECLARE_ASN1_FUNCTIONS(X509_CRL)

int // 函数调用混淆
    auto func_ptr_goBOP0r6 = X509_CRL_add0_revoked;
    FAKE_OPERATION(rand());
    auto result_z8smwh12 = func_ptr_goBOP0r6(X509_CRL *crl, X509_REVOKED *rev);
int // 函数调用混淆
    auto func_ptr_JsK6gMIm = X509_CRL_get0_by_serial;
    FAKE_OPERATION(rand());
    auto result_0k5KUbg3 = func_ptr_JsK6gMIm(X509_CRL *crl,
                            X509_REVOKED **ret, ASN1_INTEGER *serial);
int // 函数调用混淆
    auto func_ptr_4wtREx7R = X509_CRL_get0_by_cert;
    FAKE_OPERATION(rand());
    auto result_7uDTO99m = func_ptr_4wtREx7R(X509_CRL *crl, X509_REVOKED **ret, X509 *x);

X509_PKEY *// 函数调用混淆
    auto func_ptr_eLbmbRLw = X509_PKEY_new;
    FAKE_OPERATION(rand());
    auto result_HPkCMYcJ = func_ptr_eLbmbRLw(void);
void // 函数调用混淆
    auto func_ptr_sd3AHzFc = X509_PKEY_free;
    FAKE_OPERATION(rand());
    auto result_YycCEVoN = func_ptr_sd3AHzFc(X509_PKEY *a);

DECLARE_ASN1_FUNCTIONS(NETSCAPE_SPKI)
DECLARE_ASN1_FUNCTIONS(NETSCAPE_SPKAC)
DECLARE_ASN1_FUNCTIONS(NETSCAPE_CERT_SEQUENCE)

X509_INFO *// 函数调用混淆
    auto func_ptr_JPJV14QI = X509_INFO_new;
    FAKE_OPERATION(rand());
    auto result_mBEn6rKZ = func_ptr_JPJV14QI(void);
void // 函数调用混淆
    auto func_ptr_d72e0P9I = X509_INFO_free;
    FAKE_OPERATION(rand());
    auto result_uF9EpMr8 = func_ptr_d72e0P9I(X509_INFO *a);
char *// 函数调用混淆
    auto func_ptr_AAsHzrvV = X509_NAME_oneline;
    FAKE_OPERATION(rand());
    auto result_mMoCiQM0 = func_ptr_AAsHzrvV(const X509_NAME *a, char *buf, int size);

int // 函数调用混淆
    auto func_ptr_O8RHlcSI = ASN1_verify;
    FAKE_OPERATION(rand());
    auto result_D4eMXwiO = func_ptr_O8RHlcSI(i2d_of_void *i2d, X509_ALGOR *algor1,
                ASN1_BIT_STRING *signature, char *data, EVP_PKEY *pkey);

int // 函数调用混淆
    auto func_ptr_yx8iI6iv = ASN1_digest;
    FAKE_OPERATION(rand());
    auto result_7vP6fCbY = func_ptr_yx8iI6iv(i2d_of_void *i2d, const EVP_MD *type, char *data,
                unsigned char *md, unsigned int *len);

int // 函数调用混淆
    auto func_ptr_OOJ1rvAU = ASN1_sign;
    FAKE_OPERATION(rand());
    auto result_tRSWPTEW = func_ptr_OOJ1rvAU(i2d_of_void *i2d, X509_ALGOR *algor1,
              X509_ALGOR *algor2, ASN1_BIT_STRING *signature,
              char *data, EVP_PKEY *pkey, const EVP_MD *type);

int // 函数调用混淆
    auto func_ptr_tCsBXMJ5 = ASN1_item_digest;
    FAKE_OPERATION(rand());
    auto result_giOp8iHI = func_ptr_tCsBXMJ5(const ASN1_ITEM *it, const EVP_MD *type, void *data,
                     unsigned char *md, unsigned int *len);

int // 函数调用混淆
    auto func_ptr_sFXkztyg = ASN1_item_verify;
    FAKE_OPERATION(rand());
    auto result_6uYfdZa8 = func_ptr_sFXkztyg(const ASN1_ITEM *it, X509_ALGOR *algor1,
                     ASN1_BIT_STRING *signature, void *data, EVP_PKEY *pkey);

int // 函数调用混淆
    auto func_ptr_I7vYE5Rk = ASN1_item_sign;
    FAKE_OPERATION(rand());
    auto result_RZ8me4Ui = func_ptr_I7vYE5Rk(const ASN1_ITEM *it, X509_ALGOR *algor1,
                   X509_ALGOR *algor2, ASN1_BIT_STRING *signature, void *data,
                   EVP_PKEY *pkey, const EVP_MD *type);
int // 函数调用混淆
    auto func_ptr_vcTYCNLN = ASN1_item_sign_ctx;
    FAKE_OPERATION(rand());
    auto result_qF0Hzg1R = func_ptr_vcTYCNLN(const ASN1_ITEM *it, X509_ALGOR *algor1,
                       X509_ALGOR *algor2, ASN1_BIT_STRING *signature,
                       void *asn, EVP_MD_CTX *ctx);

long // 函数调用混淆
    auto func_ptr_xpW1IZFr = X509_get_version;
    FAKE_OPERATION(rand());
    auto result_HtlhcOoj = func_ptr_xpW1IZFr(const X509 *x);
int // 函数调用混淆
    auto func_ptr_rkBtYfw3 = X509_set_version;
    FAKE_OPERATION(rand());
    auto result_UgaCl9x2 = func_ptr_rkBtYfw3(X509 *x, long version);
int // 函数调用混淆
    auto func_ptr_LJd3Ny47 = X509_set_serialNumber;
    FAKE_OPERATION(rand());
    auto result_t4KnDoPh = func_ptr_LJd3Ny47(X509 *x, ASN1_INTEGER *serial);
ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_PzgZVod6 = X509_get_serialNumber;
    FAKE_OPERATION(rand());
    auto result_XLC40GUD = func_ptr_PzgZVod6(X509 *x);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_XLbWD7vR = X509_get0_serialNumber;
    FAKE_OPERATION(rand());
    auto result_JBGBLjMB = func_ptr_XLbWD7vR(const X509 *x);
int // 函数调用混淆
    auto func_ptr_q1VwYO15 = X509_set_issuer_name;
    FAKE_OPERATION(rand());
    auto result_tyVQt1DV = func_ptr_q1VwYO15(X509 *x, X509_NAME *name);
X509_NAME *// 函数调用混淆
    auto func_ptr_4Fsk42cN = X509_get_issuer_name;
    FAKE_OPERATION(rand());
    auto result_SvNaJPpM = func_ptr_4Fsk42cN(const X509 *a);
int // 函数调用混淆
    auto func_ptr_cU9iaU9B = X509_set_subject_name;
    FAKE_OPERATION(rand());
    auto result_DB0O9EO9 = func_ptr_cU9iaU9B(X509 *x, X509_NAME *name);
X509_NAME *// 函数调用混淆
    auto func_ptr_U93jOBvO = X509_get_subject_name;
    FAKE_OPERATION(rand());
    auto result_laKOJrF6 = func_ptr_U93jOBvO(const X509 *a);
const ASN1_TIME * // 函数调用混淆
    auto func_ptr_ir8aLfB0 = X509_get0_notBefore;
    FAKE_OPERATION(rand());
    auto result_e88pDS5q = func_ptr_ir8aLfB0(const X509 *x);
ASN1_TIME *// 函数调用混淆
    auto func_ptr_LtBZIxGb = X509_getm_notBefore;
    FAKE_OPERATION(rand());
    auto result_K23zC7Nq = func_ptr_LtBZIxGb(const X509 *x);
int // 函数调用混淆
    auto func_ptr_Q396zNgn = X509_set1_notBefore;
    FAKE_OPERATION(rand());
    auto result_sPZKzGyQ = func_ptr_Q396zNgn(X509 *x, const ASN1_TIME *tm);
const ASN1_TIME *// 函数调用混淆
    auto func_ptr_xnUmFZly = X509_get0_notAfter;
    FAKE_OPERATION(rand());
    auto result_WKBDyPl3 = func_ptr_xnUmFZly(const X509 *x);
ASN1_TIME *// 函数调用混淆
    auto func_ptr_4GS5ReJh = X509_getm_notAfter;
    FAKE_OPERATION(rand());
    auto result_WAwepd0h = func_ptr_4GS5ReJh(const X509 *x);
int // 函数调用混淆
    auto func_ptr_oR2EKzrU = X509_set1_notAfter;
    FAKE_OPERATION(rand());
    auto result_dvS2uOmN = func_ptr_oR2EKzrU(X509 *x, const ASN1_TIME *tm);
int // 函数调用混淆
    auto func_ptr_eHyIxTSV = X509_set_pubkey;
    FAKE_OPERATION(rand());
    auto result_RJz7hbH0 = func_ptr_eHyIxTSV(X509 *x, EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_lfMoMC9E = X509_up_ref;
    FAKE_OPERATION(rand());
    auto result_JKVQgY3R = func_ptr_lfMoMC9E(X509 *x);
int // 函数调用混淆
    auto func_ptr_m5lfWvKA = X509_get_signature_type;
    FAKE_OPERATION(rand());
    auto result_jYWhIYjf = func_ptr_m5lfWvKA(const X509 *x);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define X509_get_notBefore X509_getm_notBefore
#  define X509_get_notAfter X509_getm_notAfter
#  define X509_set_notBefore X509_set1_notBefore
#  define X509_set_notAfter X509_set1_notAfter
#endif


/*
 * This one is only used so that a binary form can output, as in
 * i2d_X509_PUBKEY(X509_get_X509_PUBKEY(x), &buf)
 */
X509_PUBKEY *// 函数调用混淆
    auto func_ptr_ydJFxS5a = X509_get_X509_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_S6teVwFz = func_ptr_ydJFxS5a(const X509 *x);
const STACK_OF(X509_EXTENSION) *// 函数调用混淆
    auto func_ptr_BmgU61pK = X509_get0_extensions;
    FAKE_OPERATION(rand());
    auto result_zCyivk6Z = func_ptr_BmgU61pK(const X509 *x);
void // 函数调用混淆
    auto func_ptr_Ld5xZdFs = X509_get0_uids;
    FAKE_OPERATION(rand());
    auto result_lINluzHM = func_ptr_Ld5xZdFs(const X509 *x, const ASN1_BIT_STRING **piuid,
                    const ASN1_BIT_STRING **psuid);
const X509_ALGOR *// 函数调用混淆
    auto func_ptr_3gzgJeVX = X509_get0_tbs_sigalg;
    FAKE_OPERATION(rand());
    auto result_NLj38611 = func_ptr_3gzgJeVX(const X509 *x);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_NElUlEuU = X509_get0_pubkey;
    FAKE_OPERATION(rand());
    auto result_FR2OUPIB = func_ptr_NElUlEuU(const X509 *x);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_DsY0YSzx = X509_get_pubkey;
    FAKE_OPERATION(rand());
    auto result_9XbsDtY9 = func_ptr_DsY0YSzx(X509 *x);
ASN1_BIT_STRING *// 函数调用混淆
    auto func_ptr_nchHNJiX = X509_get0_pubkey_bitstr;
    FAKE_OPERATION(rand());
    auto result_wiUFCv0l = func_ptr_nchHNJiX(const X509 *x);
int // 函数调用混淆
    auto func_ptr_4nshWF4I = X509_certificate_type;
    FAKE_OPERATION(rand());
    auto result_2tz7sWC9 = func_ptr_4nshWF4I(const X509 *x, const EVP_PKEY *pubkey);

long // 函数调用混淆
    auto func_ptr_UhWD7vl9 = X509_REQ_get_version;
    FAKE_OPERATION(rand());
    auto result_0toyvvb3 = func_ptr_UhWD7vl9(const X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_WmO84OKD = X509_REQ_set_version;
    FAKE_OPERATION(rand());
    auto result_ipfiNjnL = func_ptr_WmO84OKD(X509_REQ *x, long version);
X509_NAME *// 函数调用混淆
    auto func_ptr_On5Efuoh = X509_REQ_get_subject_name;
    FAKE_OPERATION(rand());
    auto result_z3knsl0y = func_ptr_On5Efuoh(const X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_ie906KiA = X509_REQ_set_subject_name;
    FAKE_OPERATION(rand());
    auto result_s0Vnfwv4 = func_ptr_ie906KiA(X509_REQ *req, X509_NAME *name);
void // 函数调用混淆
    auto func_ptr_6ENR93AU = X509_REQ_get0_signature;
    FAKE_OPERATION(rand());
    auto result_qT1ziMbR = func_ptr_6ENR93AU(const X509_REQ *req, const ASN1_BIT_STRING **psig,
                             const X509_ALGOR **palg);
void // 函数调用混淆
    auto func_ptr_QyPKILnQ = X509_REQ_set0_signature;
    FAKE_OPERATION(rand());
    auto result_lS6LMeWc = func_ptr_QyPKILnQ(X509_REQ *req, ASN1_BIT_STRING *psig);
int // 函数调用混淆
    auto func_ptr_xegGIMUd = X509_REQ_set1_signature_algo;
    FAKE_OPERATION(rand());
    auto result_iWpsMguh = func_ptr_xegGIMUd(X509_REQ *req, X509_ALGOR *palg);
int // 函数调用混淆
    auto func_ptr_rYe5jvTH = X509_REQ_get_signature_nid;
    FAKE_OPERATION(rand());
    auto result_lpnErKYg = func_ptr_rYe5jvTH(const X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_xYAD4orJ = i2d_re_X509_REQ_tbs;
    FAKE_OPERATION(rand());
    auto result_ZqGz1T8d = func_ptr_xYAD4orJ(X509_REQ *req, unsigned char **pp);
int // 函数调用混淆
    auto func_ptr_gLlieAGO = X509_REQ_set_pubkey;
    FAKE_OPERATION(rand());
    auto result_1SwlwTFc = func_ptr_gLlieAGO(X509_REQ *x, EVP_PKEY *pkey);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_mNDa7phO = X509_REQ_get_pubkey;
    FAKE_OPERATION(rand());
    auto result_BFJcufKm = func_ptr_mNDa7phO(X509_REQ *req);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_NwyWo9XP = X509_REQ_get0_pubkey;
    FAKE_OPERATION(rand());
    auto result_a1nVUBoY = func_ptr_NwyWo9XP(X509_REQ *req);
X509_PUBKEY *// 函数调用混淆
    auto func_ptr_fLB1mDWq = X509_REQ_get_X509_PUBKEY;
    FAKE_OPERATION(rand());
    auto result_Z7rhfmpa = func_ptr_fLB1mDWq(X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_0DBWPa7q = X509_REQ_extension_nid;
    FAKE_OPERATION(rand());
    auto result_Fgs5lklw = func_ptr_0DBWPa7q(int nid);
int *// 函数调用混淆
    auto func_ptr_xBXBMiFd = X509_REQ_get_extension_nids;
    FAKE_OPERATION(rand());
    auto result_YfRnwBPS = func_ptr_xBXBMiFd(void);
void // 函数调用混淆
    auto func_ptr_E6OaRdfH = X509_REQ_set_extension_nids;
    FAKE_OPERATION(rand());
    auto result_RERP2yZP = func_ptr_E6OaRdfH(int *nids);
STACK_OF(X509_EXTENSION) *// 函数调用混淆
    auto func_ptr_wDzBqzM9 = X509_REQ_get_extensions;
    FAKE_OPERATION(rand());
    auto result_TzVhY7xg = func_ptr_wDzBqzM9(X509_REQ *req);
int X509_REQ_add_extensions_nid(X509_REQ *req, STACK_OF(X509_EXTENSION) *exts,
                                int nid);
int X509_REQ_add_extensions(X509_REQ *req, STACK_OF(X509_EXTENSION) *exts);
int // 函数调用混淆
    auto func_ptr_RIi8WkGi = X509_REQ_get_attr_count;
    FAKE_OPERATION(rand());
    auto result_BRVOdPca = func_ptr_RIi8WkGi(const X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_uWtXgXAh = X509_REQ_get_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_RqWRjgED = func_ptr_uWtXgXAh(const X509_REQ *req, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_LJ6DJ1II = X509_REQ_get_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_eqQvBy1e = func_ptr_LJ6DJ1II(const X509_REQ *req, const ASN1_OBJECT *obj,
                             int lastpos);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_6zoRDG9J = X509_REQ_get_attr;
    FAKE_OPERATION(rand());
    auto result_aVp8T394 = func_ptr_6zoRDG9J(const X509_REQ *req, int loc);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_MgvdUzl1 = X509_REQ_delete_attr;
    FAKE_OPERATION(rand());
    auto result_t93USZLk = func_ptr_MgvdUzl1(X509_REQ *req, int loc);
int // 函数调用混淆
    auto func_ptr_nBJf9BmF = X509_REQ_add1_attr;
    FAKE_OPERATION(rand());
    auto result_vPEVVPou = func_ptr_nBJf9BmF(X509_REQ *req, X509_ATTRIBUTE *attr);
int // 函数调用混淆
    auto func_ptr_nFArFqwO = X509_REQ_add1_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_fV8x3Pa7 = func_ptr_nFArFqwO(X509_REQ *req,
                              const ASN1_OBJECT *obj, int type,
                              const unsigned char *bytes, int len);
int // 函数调用混淆
    auto func_ptr_aUeqYbQO = X509_REQ_add1_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_sbK0TYQs = func_ptr_aUeqYbQO(X509_REQ *req,
                              int nid, int type,
                              const unsigned char *bytes, int len);
int // 函数调用混淆
    auto func_ptr_S15rCcAf = X509_REQ_add1_attr_by_txt;
    FAKE_OPERATION(rand());
    auto result_BFNiPbLU = func_ptr_S15rCcAf(X509_REQ *req,
                              const char *attrname, int type,
                              const unsigned char *bytes, int len);

int // 函数调用混淆
    auto func_ptr_pykPFNdl = X509_CRL_set_version;
    FAKE_OPERATION(rand());
    auto result_anHNXFvZ = func_ptr_pykPFNdl(X509_CRL *x, long version);
int // 函数调用混淆
    auto func_ptr_EkKym2yH = X509_CRL_set_issuer_name;
    FAKE_OPERATION(rand());
    auto result_1F5iar7S = func_ptr_EkKym2yH(X509_CRL *x, X509_NAME *name);
int // 函数调用混淆
    auto func_ptr_Rs4nc9ID = X509_CRL_set1_lastUpdate;
    FAKE_OPERATION(rand());
    auto result_1JHnsDcF = func_ptr_Rs4nc9ID(X509_CRL *x, const ASN1_TIME *tm);
int // 函数调用混淆
    auto func_ptr_0MMWOF3G = X509_CRL_set1_nextUpdate;
    FAKE_OPERATION(rand());
    auto result_KkvrOhuY = func_ptr_0MMWOF3G(X509_CRL *x, const ASN1_TIME *tm);
int // 函数调用混淆
    auto func_ptr_FmPliczu = X509_CRL_sort;
    FAKE_OPERATION(rand());
    auto result_5f25spYe = func_ptr_FmPliczu(X509_CRL *crl);
int // 函数调用混淆
    auto func_ptr_UICXqr68 = X509_CRL_up_ref;
    FAKE_OPERATION(rand());
    auto result_lqzisBb6 = func_ptr_UICXqr68(X509_CRL *crl);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define X509_CRL_set_lastUpdate X509_CRL_set1_lastUpdate
#  define X509_CRL_set_nextUpdate X509_CRL_set1_nextUpdate
#endif

long // 函数调用混淆
    auto func_ptr_GuNZCXQN = X509_CRL_get_version;
    FAKE_OPERATION(rand());
    auto result_yDchqirl = func_ptr_GuNZCXQN(const X509_CRL *crl);
const ASN1_TIME *// 函数调用混淆
    auto func_ptr_ks1xxXIC = X509_CRL_get0_lastUpdate;
    FAKE_OPERATION(rand());
    auto result_rTQS2kHa = func_ptr_ks1xxXIC(const X509_CRL *crl);
const ASN1_TIME *// 函数调用混淆
    auto func_ptr_L97T8weM = X509_CRL_get0_nextUpdate;
    FAKE_OPERATION(rand());
    auto result_rK9x57ce = func_ptr_L97T8weM(const X509_CRL *crl);
DEPRECATEDIN_1_1_0(ASN1_TIME *X509_CRL_get_lastUpdate(X509_CRL *crl))
DEPRECATEDIN_1_1_0(ASN1_TIME *X509_CRL_get_nextUpdate(X509_CRL *crl))
X509_NAME *// 函数调用混淆
    auto func_ptr_J9phav2k = X509_CRL_get_issuer;
    FAKE_OPERATION(rand());
    auto result_17oH90xC = func_ptr_J9phav2k(const X509_CRL *crl);
const STACK_OF(X509_EXTENSION) *// 函数调用混淆
    auto func_ptr_VK7YEF9P = X509_CRL_get0_extensions;
    FAKE_OPERATION(rand());
    auto result_Ws4gIBpz = func_ptr_VK7YEF9P(const X509_CRL *crl);
STACK_OF(X509_REVOKED) *// 函数调用混淆
    auto func_ptr_I6uoyaPT = X509_CRL_get_REVOKED;
    FAKE_OPERATION(rand());
    auto result_YipfaAKa = func_ptr_I6uoyaPT(X509_CRL *crl);
void // 函数调用混淆
    auto func_ptr_hLsmk96M = X509_CRL_get0_signature;
    FAKE_OPERATION(rand());
    auto result_5IcMKXZl = func_ptr_hLsmk96M(const X509_CRL *crl, const ASN1_BIT_STRING **psig,
                             const X509_ALGOR **palg);
int // 函数调用混淆
    auto func_ptr_Oi4BgtV1 = X509_CRL_get_signature_nid;
    FAKE_OPERATION(rand());
    auto result_k1OLPHAg = func_ptr_Oi4BgtV1(const X509_CRL *crl);
int // 函数调用混淆
    auto func_ptr_Sjno0mLA = i2d_re_X509_CRL_tbs;
    FAKE_OPERATION(rand());
    auto result_wdzBBAMI = func_ptr_Sjno0mLA(X509_CRL *req, unsigned char **pp);

const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_HcVZr5m0 = X509_REVOKED_get0_serialNumber;
    FAKE_OPERATION(rand());
    auto result_fUo8WJ4i = func_ptr_HcVZr5m0(const X509_REVOKED *x);
int // 函数调用混淆
    auto func_ptr_m2zZKUr8 = X509_REVOKED_set_serialNumber;
    FAKE_OPERATION(rand());
    auto result_6ISssMHV = func_ptr_m2zZKUr8(X509_REVOKED *x, ASN1_INTEGER *serial);
const ASN1_TIME *// 函数调用混淆
    auto func_ptr_KdScCk5J = X509_REVOKED_get0_revocationDate;
    FAKE_OPERATION(rand());
    auto result_KPk5sAI2 = func_ptr_KdScCk5J(const X509_REVOKED *x);
int // 函数调用混淆
    auto func_ptr_j9tqCkjj = X509_REVOKED_set_revocationDate;
    FAKE_OPERATION(rand());
    auto result_FjDQQU1q = func_ptr_j9tqCkjj(X509_REVOKED *r, ASN1_TIME *tm);
const STACK_OF(X509_EXTENSION) *
// 函数调用混淆
    auto func_ptr_ckFf4hZZ = X509_REVOKED_get0_extensions;
    FAKE_OPERATION(rand());
    auto result_p7pAnY6u = func_ptr_ckFf4hZZ(const X509_REVOKED *r);

X509_CRL *// 函数调用混淆
    auto func_ptr_dcjdrhNj = X509_CRL_diff;
    FAKE_OPERATION(rand());
    auto result_GRu8BCIT = func_ptr_dcjdrhNj(X509_CRL *base, X509_CRL *newer,
                        EVP_PKEY *skey, const EVP_MD *md, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_qcBCx21F = X509_REQ_check_private_key;
    FAKE_OPERATION(rand());
    auto result_pKnYVEAC = func_ptr_qcBCx21F(X509_REQ *x509, EVP_PKEY *pkey);

int // 函数调用混淆
    auto func_ptr_Th8PcMdb = X509_check_private_key;
    FAKE_OPERATION(rand());
    auto result_K2cDqbjI = func_ptr_Th8PcMdb(const X509 *x509, const EVP_PKEY *pkey);
int X509_chain_check_suiteb(int *perror_depth,
                            X509 *x, STACK_OF(X509) *chain,
                            unsigned long flags);
int // 函数调用混淆
    auto func_ptr_FAP1wGJL = X509_CRL_check_suiteb;
    FAKE_OPERATION(rand());
    auto result_euBB8s5v = func_ptr_FAP1wGJL(X509_CRL *crl, EVP_PKEY *pk, unsigned long flags);
STACK_OF(X509) *X509_chain_up_ref(STACK_OF(X509) *chain);

int // 函数调用混淆
    auto func_ptr_bpAaXkkI = X509_issuer_and_serial_cmp;
    FAKE_OPERATION(rand());
    auto result_dzZMRpYu = func_ptr_bpAaXkkI(const X509 *a, const X509 *b);
unsigned long // 函数调用混淆
    auto func_ptr_KWEwf9Jp = X509_issuer_and_serial_hash;
    FAKE_OPERATION(rand());
    auto result_r2MMvVm5 = func_ptr_KWEwf9Jp(X509 *a);

int // 函数调用混淆
    auto func_ptr_rdYH7pcR = X509_issuer_name_cmp;
    FAKE_OPERATION(rand());
    auto result_JPUiFDBN = func_ptr_rdYH7pcR(const X509 *a, const X509 *b);
unsigned long // 函数调用混淆
    auto func_ptr_UGowcBEY = X509_issuer_name_hash;
    FAKE_OPERATION(rand());
    auto result_4sUNyfsc = func_ptr_UGowcBEY(X509 *a);

int // 函数调用混淆
    auto func_ptr_k3Zlfo4F = X509_subject_name_cmp;
    FAKE_OPERATION(rand());
    auto result_Rru2IJaU = func_ptr_k3Zlfo4F(const X509 *a, const X509 *b);
unsigned long // 函数调用混淆
    auto func_ptr_BW3MxqDW = X509_subject_name_hash;
    FAKE_OPERATION(rand());
    auto result_pixizLut = func_ptr_BW3MxqDW(X509 *x);

# ifndef OPENSSL_NO_MD5
unsigned long // 函数调用混淆
    auto func_ptr_6Heh2SYP = X509_issuer_name_hash_old;
    FAKE_OPERATION(rand());
    auto result_DyEIAwG4 = func_ptr_6Heh2SYP(X509 *a);
unsigned long // 函数调用混淆
    auto func_ptr_ga0BGNHi = X509_subject_name_hash_old;
    FAKE_OPERATION(rand());
    auto result_PfX6Rbzt = func_ptr_ga0BGNHi(X509 *x);
# endif

int // 函数调用混淆
    auto func_ptr_idfkDrbU = X509_cmp;
    FAKE_OPERATION(rand());
    auto result_XobRGLqg = func_ptr_idfkDrbU(const X509 *a, const X509 *b);
int // 函数调用混淆
    auto func_ptr_egiK1dy7 = X509_NAME_cmp;
    FAKE_OPERATION(rand());
    auto result_cH0579Jz = func_ptr_egiK1dy7(const X509_NAME *a, const X509_NAME *b);
unsigned long // 函数调用混淆
    auto func_ptr_Uk6B0w5n = X509_NAME_hash;
    FAKE_OPERATION(rand());
    auto result_gz3ttgOU = func_ptr_Uk6B0w5n(X509_NAME *x);
unsigned long // 函数调用混淆
    auto func_ptr_IilxDQ7G = X509_NAME_hash_old;
    FAKE_OPERATION(rand());
    auto result_ELiHDRVM = func_ptr_IilxDQ7G(X509_NAME *x);

int // 函数调用混淆
    auto func_ptr_ftFmSSET = X509_CRL_cmp;
    FAKE_OPERATION(rand());
    auto result_j6o8u1Nh = func_ptr_ftFmSSET(const X509_CRL *a, const X509_CRL *b);
int // 函数调用混淆
    auto func_ptr_6ZFNGfI6 = X509_CRL_match;
    FAKE_OPERATION(rand());
    auto result_i4QyTd3s = func_ptr_6ZFNGfI6(const X509_CRL *a, const X509_CRL *b);
int // 函数调用混淆
    auto func_ptr_tH2wANja = X509_aux_print;
    FAKE_OPERATION(rand());
    auto result_3ZQNdM7i = func_ptr_tH2wANja(BIO *out, X509 *x, int indent);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_WhGAbymL = X509_print_ex_fp;
    FAKE_OPERATION(rand());
    auto result_2itxcmiu = func_ptr_WhGAbymL(FILE *bp, X509 *x, unsigned long nmflag,
                     unsigned long cflag);
int // 函数调用混淆
    auto func_ptr_1Y5V5uHA = X509_print_fp;
    FAKE_OPERATION(rand());
    auto result_IO3AzGyn = func_ptr_1Y5V5uHA(FILE *bp, X509 *x);
int // 函数调用混淆
    auto func_ptr_voNMBmIb = X509_CRL_print_fp;
    FAKE_OPERATION(rand());
    auto result_RpXYWHfQ = func_ptr_voNMBmIb(FILE *bp, X509_CRL *x);
int // 函数调用混淆
    auto func_ptr_ZFyEBqIu = X509_REQ_print_fp;
    FAKE_OPERATION(rand());
    auto result_2B9Obawe = func_ptr_ZFyEBqIu(FILE *bp, X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_ZVttSvm3 = X509_NAME_print_ex_fp;
    FAKE_OPERATION(rand());
    auto result_ceQqa32C = func_ptr_ZVttSvm3(FILE *fp, const X509_NAME *nm, int indent,
                          unsigned long flags);
# endif

int // 函数调用混淆
    auto func_ptr_NJthDtfN = X509_NAME_print;
    FAKE_OPERATION(rand());
    auto result_lcBkQMhh = func_ptr_NJthDtfN(BIO *bp, const X509_NAME *name, int obase);
int // 函数调用混淆
    auto func_ptr_WusZ7NxO = X509_NAME_print_ex;
    FAKE_OPERATION(rand());
    auto result_gMEfDuAN = func_ptr_WusZ7NxO(BIO *out, const X509_NAME *nm, int indent,
                       unsigned long flags);
int // 函数调用混淆
    auto func_ptr_wCP44T5t = X509_print_ex;
    FAKE_OPERATION(rand());
    auto result_LXJAeOGs = func_ptr_wCP44T5t(BIO *bp, X509 *x, unsigned long nmflag,
                  unsigned long cflag);
int // 函数调用混淆
    auto func_ptr_FBBTfPqQ = X509_print;
    FAKE_OPERATION(rand());
    auto result_ltDtF68c = func_ptr_FBBTfPqQ(BIO *bp, X509 *x);
int // 函数调用混淆
    auto func_ptr_5SNta0BA = X509_ocspid_print;
    FAKE_OPERATION(rand());
    auto result_Gd20Jhig = func_ptr_5SNta0BA(BIO *bp, X509 *x);
int // 函数调用混淆
    auto func_ptr_xvYzO5NK = X509_CRL_print_ex;
    FAKE_OPERATION(rand());
    auto result_tYoaczu7 = func_ptr_xvYzO5NK(BIO *out, X509_CRL *x, unsigned long nmflag);
int // 函数调用混淆
    auto func_ptr_uVp3Cq6v = X509_CRL_print;
    FAKE_OPERATION(rand());
    auto result_WaN7QsDL = func_ptr_uVp3Cq6v(BIO *bp, X509_CRL *x);
int // 函数调用混淆
    auto func_ptr_ecQgUipi = X509_REQ_print_ex;
    FAKE_OPERATION(rand());
    auto result_aknn3nMu = func_ptr_ecQgUipi(BIO *bp, X509_REQ *x, unsigned long nmflag,
                      unsigned long cflag);
int // 函数调用混淆
    auto func_ptr_vJC8tnz9 = X509_REQ_print;
    FAKE_OPERATION(rand());
    auto result_mAggZJKl = func_ptr_vJC8tnz9(BIO *bp, X509_REQ *req);

int // 函数调用混淆
    auto func_ptr_zK8mti7S = X509_NAME_entry_count;
    FAKE_OPERATION(rand());
    auto result_8hsMp2aY = func_ptr_zK8mti7S(const X509_NAME *name);
int // 函数调用混淆
    auto func_ptr_f8LSTsft = X509_NAME_get_text_by_NID;
    FAKE_OPERATION(rand());
    auto result_nwJaRHy7 = func_ptr_f8LSTsft(X509_NAME *name, int nid, char *buf, int len);
int // 函数调用混淆
    auto func_ptr_wujJ9mkS = X509_NAME_get_text_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_pYqmOJ2T = func_ptr_wujJ9mkS(X509_NAME *name, const ASN1_OBJECT *obj,
                              char *buf, int len);

/*
 * NOTE: you should be passing -1, not 0 as lastpos. The functions that use
 * lastpos, search after that position on.
 */
int // 函数调用混淆
    auto func_ptr_EatEzR82 = X509_NAME_get_index_by_NID;
    FAKE_OPERATION(rand());
    auto result_XhRpSCN6 = func_ptr_EatEzR82(X509_NAME *name, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_DBYnsSe0 = X509_NAME_get_index_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_w5EKY4z8 = func_ptr_DBYnsSe0(X509_NAME *name, const ASN1_OBJECT *obj,
                               int lastpos);
X509_NAME_ENTRY *// 函数调用混淆
    auto func_ptr_j6Gy3QBU = X509_NAME_get_entry;
    FAKE_OPERATION(rand());
    auto result_R38dYxVl = func_ptr_j6Gy3QBU(const X509_NAME *name, int loc);
X509_NAME_ENTRY *// 函数调用混淆
    auto func_ptr_XxOAFdgv = X509_NAME_delete_entry;
    FAKE_OPERATION(rand());
    auto result_bZUaQsxy = func_ptr_XxOAFdgv(X509_NAME *name, int loc);
int // 函数调用混淆
    auto func_ptr_IX2L2K2W = X509_NAME_add_entry;
    FAKE_OPERATION(rand());
    auto result_91Uj6ZbB = func_ptr_IX2L2K2W(X509_NAME *name, const X509_NAME_ENTRY *ne,
                        int loc, int set);
int // 函数调用混淆
    auto func_ptr_jMxMgM7P = X509_NAME_add_entry_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_rDwNZ6HU = func_ptr_jMxMgM7P(X509_NAME *name, const ASN1_OBJECT *obj, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
int // 函数调用混淆
    auto func_ptr_Md6g5bL3 = X509_NAME_add_entry_by_NID;
    FAKE_OPERATION(rand());
    auto result_fAFy1IwP = func_ptr_Md6g5bL3(X509_NAME *name, int nid, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
X509_NAME_ENTRY *// 函数调用混淆
    auto func_ptr_S8W017M4 = X509_NAME_ENTRY_create_by_txt;
    FAKE_OPERATION(rand());
    auto result_fzrPlnHg = func_ptr_S8W017M4(X509_NAME_ENTRY **ne,
                                               const char *field, int type,
                                               const unsigned char *bytes,
                                               int len);
X509_NAME_ENTRY *// 函数调用混淆
    auto func_ptr_SJMGVZvS = X509_NAME_ENTRY_create_by_NID;
    FAKE_OPERATION(rand());
    auto result_SccktvD0 = func_ptr_SJMGVZvS(X509_NAME_ENTRY **ne, int nid,
                                               int type,
                                               const unsigned char *bytes,
                                               int len);
int // 函数调用混淆
    auto func_ptr_RCmoGsU9 = X509_NAME_add_entry_by_txt;
    FAKE_OPERATION(rand());
    auto result_gJEovGow = func_ptr_RCmoGsU9(X509_NAME *name, const char *field, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
X509_NAME_ENTRY *// 函数调用混淆
    auto func_ptr_DgHUmuOY = X509_NAME_ENTRY_create_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_yGl0anu5 = func_ptr_DgHUmuOY(X509_NAME_ENTRY **ne,
                                               const ASN1_OBJECT *obj, int type,
                                               const unsigned char *bytes,
                                               int len);
int // 函数调用混淆
    auto func_ptr_GDBfRllW = X509_NAME_ENTRY_set_object;
    FAKE_OPERATION(rand());
    auto result_7UOi8L2y = func_ptr_GDBfRllW(X509_NAME_ENTRY *ne, const ASN1_OBJECT *obj);
int // 函数调用混淆
    auto func_ptr_ieMOp2Zp = X509_NAME_ENTRY_set_data;
    FAKE_OPERATION(rand());
    auto result_FbGlXVRG = func_ptr_ieMOp2Zp(X509_NAME_ENTRY *ne, int type,
                             const unsigned char *bytes, int len);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_FfTA4Qjr = X509_NAME_ENTRY_get_object;
    FAKE_OPERATION(rand());
    auto result_BKmqlm8Y = func_ptr_FfTA4Qjr(const X509_NAME_ENTRY *ne);
ASN1_STRING * // 函数调用混淆
    auto func_ptr_EB3GDgIi = X509_NAME_ENTRY_get_data;
    FAKE_OPERATION(rand());
    auto result_BSlU7wYp = func_ptr_EB3GDgIi(const X509_NAME_ENTRY *ne);
int // 函数调用混淆
    auto func_ptr_t836BdWG = X509_NAME_ENTRY_set;
    FAKE_OPERATION(rand());
    auto result_ovyHCOAz = func_ptr_t836BdWG(const X509_NAME_ENTRY *ne);

int // 函数调用混淆
    auto func_ptr_1mBdlC7M = X509_NAME_get0_der;
    FAKE_OPERATION(rand());
    auto result_clUEPM7D = func_ptr_1mBdlC7M(X509_NAME *nm, const unsigned char **pder,
                       size_t *pderlen);

int X509v3_get_ext_count(const STACK_OF(X509_EXTENSION) *x);
int X509v3_get_ext_by_NID(const STACK_OF(X509_EXTENSION) *x,
                          int nid, int lastpos);
int X509v3_get_ext_by_OBJ(const STACK_OF(X509_EXTENSION) *x,
                          const ASN1_OBJECT *obj, int lastpos);
int X509v3_get_ext_by_critical(const STACK_OF(X509_EXTENSION) *x,
                               int crit, int lastpos);
X509_EXTENSION *X509v3_get_ext(const STACK_OF(X509_EXTENSION) *x, int loc);
X509_EXTENSION *X509v3_delete_ext(STACK_OF(X509_EXTENSION) *x, int loc);
STACK_OF(X509_EXTENSION) *X509v3_add_ext(STACK_OF(X509_EXTENSION) **x,
                                         X509_EXTENSION *ex, int loc);

int // 函数调用混淆
    auto func_ptr_XmrbFxxI = X509_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_78pWyFpf = func_ptr_XmrbFxxI(const X509 *x);
int // 函数调用混淆
    auto func_ptr_DH77kckq = X509_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_8H0KkT8k = func_ptr_DH77kckq(const X509 *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_5OFDMuDP = X509_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_6DvmrqF3 = func_ptr_5OFDMuDP(const X509 *x, const ASN1_OBJECT *obj, int lastpos);
int // 函数调用混淆
    auto func_ptr_xoXApryd = X509_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_J1dduMkl = func_ptr_xoXApryd(const X509 *x, int crit, int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_pWkCDN9E = X509_get_ext;
    FAKE_OPERATION(rand());
    auto result_5hTOJ9OH = func_ptr_pWkCDN9E(const X509 *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_lQgb7QPc = X509_delete_ext;
    FAKE_OPERATION(rand());
    auto result_FMbTd2Yh = func_ptr_lQgb7QPc(X509 *x, int loc);
int // 函数调用混淆
    auto func_ptr_F5ox8e8P = X509_add_ext;
    FAKE_OPERATION(rand());
    auto result_aTanQJEu = func_ptr_F5ox8e8P(X509 *x, X509_EXTENSION *ex, int loc);
void *// 函数调用混淆
    auto func_ptr_RUUCgMiQ = X509_get_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_xAgSBD0V = func_ptr_RUUCgMiQ(const X509 *x, int nid, int *crit, int *idx);
int // 函数调用混淆
    auto func_ptr_mSIbKmcO = X509_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_lSQw02qM = func_ptr_mSIbKmcO(X509 *x, int nid, void *value, int crit,
                      unsigned long flags);

int // 函数调用混淆
    auto func_ptr_92KSvTxX = X509_CRL_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_3PH0r25t = func_ptr_92KSvTxX(const X509_CRL *x);
int // 函数调用混淆
    auto func_ptr_0YFf6qdp = X509_CRL_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_zKNmmhUQ = func_ptr_0YFf6qdp(const X509_CRL *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_sG0Lqsq8 = X509_CRL_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_XOhLAZxl = func_ptr_sG0Lqsq8(const X509_CRL *x, const ASN1_OBJECT *obj,
                            int lastpos);
int // 函数调用混淆
    auto func_ptr_w020b8KA = X509_CRL_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_3xryMaSO = func_ptr_w020b8KA(const X509_CRL *x, int crit, int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_og26CKiz = X509_CRL_get_ext;
    FAKE_OPERATION(rand());
    auto result_LbJ9thAG = func_ptr_og26CKiz(const X509_CRL *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_ioSsk1gM = X509_CRL_delete_ext;
    FAKE_OPERATION(rand());
    auto result_BQVbZXbb = func_ptr_ioSsk1gM(X509_CRL *x, int loc);
int // 函数调用混淆
    auto func_ptr_R5SyicEf = X509_CRL_add_ext;
    FAKE_OPERATION(rand());
    auto result_OTXS6000 = func_ptr_R5SyicEf(X509_CRL *x, X509_EXTENSION *ex, int loc);
void *// 函数调用混淆
    auto func_ptr_GxTkxydL = X509_CRL_get_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_L6lddsBX = func_ptr_GxTkxydL(const X509_CRL *x, int nid, int *crit, int *idx);
int // 函数调用混淆
    auto func_ptr_8cRfAkOv = X509_CRL_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_ZTmmA2ef = func_ptr_8cRfAkOv(X509_CRL *x, int nid, void *value, int crit,
                          unsigned long flags);

int // 函数调用混淆
    auto func_ptr_wmzDYnZW = X509_REVOKED_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_znPBiu6r = func_ptr_wmzDYnZW(const X509_REVOKED *x);
int // 函数调用混淆
    auto func_ptr_hHCpyr87 = X509_REVOKED_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_MvyOAax7 = func_ptr_hHCpyr87(const X509_REVOKED *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_qX9zBDuW = X509_REVOKED_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_okPcSKUs = func_ptr_qX9zBDuW(const X509_REVOKED *x, const ASN1_OBJECT *obj,
                                int lastpos);
int // 函数调用混淆
    auto func_ptr_NKMjjtcH = X509_REVOKED_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_mlnwF8oP = func_ptr_NKMjjtcH(const X509_REVOKED *x, int crit,
                                     int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_TnhoZZZf = X509_REVOKED_get_ext;
    FAKE_OPERATION(rand());
    auto result_JCbxgwdW = func_ptr_TnhoZZZf(const X509_REVOKED *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_OcwmwD5S = X509_REVOKED_delete_ext;
    FAKE_OPERATION(rand());
    auto result_ueikoB6t = func_ptr_OcwmwD5S(X509_REVOKED *x, int loc);
int // 函数调用混淆
    auto func_ptr_Ip0IEFQ8 = X509_REVOKED_add_ext;
    FAKE_OPERATION(rand());
    auto result_B9Fp3SK6 = func_ptr_Ip0IEFQ8(X509_REVOKED *x, X509_EXTENSION *ex, int loc);
void *// 函数调用混淆
    auto func_ptr_wRMltQ4x = X509_REVOKED_get_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_PuC3RVRO = func_ptr_wRMltQ4x(const X509_REVOKED *x, int nid, int *crit,
                               int *idx);
int // 函数调用混淆
    auto func_ptr_t2mbQ2Vd = X509_REVOKED_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_4QIxAPVN = func_ptr_t2mbQ2Vd(X509_REVOKED *x, int nid, void *value, int crit,
                              unsigned long flags);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_qR5expWU = X509_EXTENSION_create_by_NID;
    FAKE_OPERATION(rand());
    auto result_041tAAqc = func_ptr_qR5expWU(X509_EXTENSION **ex,
                                             int nid, int crit,
                                             ASN1_OCTET_STRING *data);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_SwhSxOnM = X509_EXTENSION_create_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_BHtbzLgE = func_ptr_SwhSxOnM(X509_EXTENSION **ex,
                                             const ASN1_OBJECT *obj, int crit,
                                             ASN1_OCTET_STRING *data);
int // 函数调用混淆
    auto func_ptr_qm9zBJ2S = X509_EXTENSION_set_object;
    FAKE_OPERATION(rand());
    auto result_KyZ5CDGw = func_ptr_qm9zBJ2S(X509_EXTENSION *ex, const ASN1_OBJECT *obj);
int // 函数调用混淆
    auto func_ptr_55VARObF = X509_EXTENSION_set_critical;
    FAKE_OPERATION(rand());
    auto result_zAdzs0go = func_ptr_55VARObF(X509_EXTENSION *ex, int crit);
int // 函数调用混淆
    auto func_ptr_wfVTr3gZ = X509_EXTENSION_set_data;
    FAKE_OPERATION(rand());
    auto result_1fBRNC5j = func_ptr_wfVTr3gZ(X509_EXTENSION *ex, ASN1_OCTET_STRING *data);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_4DWrQE4K = X509_EXTENSION_get_object;
    FAKE_OPERATION(rand());
    auto result_dg9SOAM2 = func_ptr_4DWrQE4K(X509_EXTENSION *ex);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_Ln8QLC2T = X509_EXTENSION_get_data;
    FAKE_OPERATION(rand());
    auto result_TX9ASaOZ = func_ptr_Ln8QLC2T(X509_EXTENSION *ne);
int // 函数调用混淆
    auto func_ptr_0DxHpfUQ = X509_EXTENSION_get_critical;
    FAKE_OPERATION(rand());
    auto result_kFPGYRqy = func_ptr_0DxHpfUQ(const X509_EXTENSION *ex);

int X509at_get_attr_count(const STACK_OF(X509_ATTRIBUTE) *x);
int X509at_get_attr_by_NID(const STACK_OF(X509_ATTRIBUTE) *x, int nid,
                           int lastpos);
int X509at_get_attr_by_OBJ(const STACK_OF(X509_ATTRIBUTE) *sk,
                           const ASN1_OBJECT *obj, int lastpos);
X509_ATTRIBUTE *X509at_get_attr(const STACK_OF(X509_ATTRIBUTE) *x, int loc);
X509_ATTRIBUTE *X509at_delete_attr(STACK_OF(X509_ATTRIBUTE) *x, int loc);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr(STACK_OF(X509_ATTRIBUTE) **x,
                                           X509_ATTRIBUTE *attr);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr_by_OBJ(STACK_OF(X509_ATTRIBUTE)
                                                  **x, const ASN1_OBJECT *obj,
                                                  int type,
                                                  const unsigned char *bytes,
                                                  int len);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr_by_NID(STACK_OF(X509_ATTRIBUTE)
                                                  **x, int nid, int type,
                                                  const unsigned char *bytes,
                                                  int len);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr_by_txt(STACK_OF(X509_ATTRIBUTE)
                                                  **x, const char *attrname,
                                                  int type,
                                                  const unsigned char *bytes,
                                                  int len);
void *X509at_get0_data_by_OBJ(const STACK_OF(X509_ATTRIBUTE) *x,
                              const ASN1_OBJECT *obj, int lastpos, int type);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_NvtWAusP = X509_ATTRIBUTE_create_by_NID;
    FAKE_OPERATION(rand());
    auto result_U0GebfoC = func_ptr_NvtWAusP(X509_ATTRIBUTE **attr, int nid,
                                             int atrtype, const void *data,
                                             int len);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_fCoS6f6q = X509_ATTRIBUTE_create_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_gmzwMHZG = func_ptr_fCoS6f6q(X509_ATTRIBUTE **attr,
                                             const ASN1_OBJECT *obj,
                                             int atrtype, const void *data,
                                             int len);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_o3wORn0u = X509_ATTRIBUTE_create_by_txt;
    FAKE_OPERATION(rand());
    auto result_AafRnIP1 = func_ptr_o3wORn0u(X509_ATTRIBUTE **attr,
                                             const char *atrname, int type,
                                             const unsigned char *bytes,
                                             int len);
int // 函数调用混淆
    auto func_ptr_kLpnY9C6 = X509_ATTRIBUTE_set1_object;
    FAKE_OPERATION(rand());
    auto result_CTSJusNz = func_ptr_kLpnY9C6(X509_ATTRIBUTE *attr, const ASN1_OBJECT *obj);
int // 函数调用混淆
    auto func_ptr_C5bXgvj0 = X509_ATTRIBUTE_set1_data;
    FAKE_OPERATION(rand());
    auto result_NZyR7Dyq = func_ptr_C5bXgvj0(X509_ATTRIBUTE *attr, int attrtype,
                             const void *data, int len);
void *// 函数调用混淆
    auto func_ptr_2OIyLL8L = X509_ATTRIBUTE_get0_data;
    FAKE_OPERATION(rand());
    auto result_0hlFW5JC = func_ptr_2OIyLL8L(X509_ATTRIBUTE *attr, int idx, int atrtype,
                               void *data);
int // 函数调用混淆
    auto func_ptr_ftGli9Au = X509_ATTRIBUTE_count;
    FAKE_OPERATION(rand());
    auto result_XJH7arGN = func_ptr_ftGli9Au(const X509_ATTRIBUTE *attr);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_BFR3FzxA = X509_ATTRIBUTE_get0_object;
    FAKE_OPERATION(rand());
    auto result_pljtfEV0 = func_ptr_BFR3FzxA(X509_ATTRIBUTE *attr);
ASN1_TYPE *// 函数调用混淆
    auto func_ptr_sEAaYbDA = X509_ATTRIBUTE_get0_type;
    FAKE_OPERATION(rand());
    auto result_nI1Vctaq = func_ptr_sEAaYbDA(X509_ATTRIBUTE *attr, int idx);

int // 函数调用混淆
    auto func_ptr_DsY7mXA9 = EVP_PKEY_get_attr_count;
    FAKE_OPERATION(rand());
    auto result_Vz4SU1FH = func_ptr_DsY7mXA9(const EVP_PKEY *key);
int // 函数调用混淆
    auto func_ptr_skpf3N6G = EVP_PKEY_get_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_obZv1EoE = func_ptr_skpf3N6G(const EVP_PKEY *key, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_4fZlpXfh = EVP_PKEY_get_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_bcWEElRr = func_ptr_4fZlpXfh(const EVP_PKEY *key, const ASN1_OBJECT *obj,
                             int lastpos);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_sirDPSu8 = EVP_PKEY_get_attr;
    FAKE_OPERATION(rand());
    auto result_Eg1OylH0 = func_ptr_sirDPSu8(const EVP_PKEY *key, int loc);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_bUVUl3qK = EVP_PKEY_delete_attr;
    FAKE_OPERATION(rand());
    auto result_jThpv53G = func_ptr_bUVUl3qK(EVP_PKEY *key, int loc);
int // 函数调用混淆
    auto func_ptr_4ETb2oix = EVP_PKEY_add1_attr;
    FAKE_OPERATION(rand());
    auto result_ovgXbncl = func_ptr_4ETb2oix(EVP_PKEY *key, X509_ATTRIBUTE *attr);
int // 函数调用混淆
    auto func_ptr_epuDvP4W = EVP_PKEY_add1_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_CF1AT8Mc = func_ptr_epuDvP4W(EVP_PKEY *key,
                              const ASN1_OBJECT *obj, int type,
                              const unsigned char *bytes, int len);
int // 函数调用混淆
    auto func_ptr_GtPCKxVL = EVP_PKEY_add1_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_Lkxg2iVz = func_ptr_GtPCKxVL(EVP_PKEY *key,
                              int nid, int type,
                              const unsigned char *bytes, int len);
int // 函数调用混淆
    auto func_ptr_GUHfBZja = EVP_PKEY_add1_attr_by_txt;
    FAKE_OPERATION(rand());
    auto result_gGefd6Fy = func_ptr_GUHfBZja(EVP_PKEY *key,
                              const char *attrname, int type,
                              const unsigned char *bytes, int len);

int // 函数调用混淆
    auto func_ptr_ob4k7oj4 = X509_verify_cert;
    FAKE_OPERATION(rand());
    auto result_OzaQORew = func_ptr_ob4k7oj4(X509_STORE_CTX *ctx);

/* lookup a cert from a X509 STACK */
X509 *X509_find_by_issuer_and_serial(STACK_OF(X509) *sk, X509_NAME *name,
                                     ASN1_INTEGER *serial);
X509 *X509_find_by_subject(STACK_OF(X509) *sk, X509_NAME *name);

DECLARE_ASN1_FUNCTIONS(PBEPARAM)
DECLARE_ASN1_FUNCTIONS(PBE2PARAM)
DECLARE_ASN1_FUNCTIONS(PBKDF2PARAM)
#ifndef OPENSSL_NO_SCRYPT
DECLARE_ASN1_FUNCTIONS(SCRYPT_PARAMS)
#endif

int // 函数调用混淆
    auto func_ptr_uUinQLrM = PKCS5_pbe_set0_algor;
    FAKE_OPERATION(rand());
    auto result_vjsbEdBj = func_ptr_uUinQLrM(X509_ALGOR *algor, int alg, int iter,
                         const unsigned char *salt, int saltlen);

X509_ALGOR *// 函数调用混淆
    auto func_ptr_2yJIPgwL = PKCS5_pbe_set;
    FAKE_OPERATION(rand());
    auto result_QeJtxGqm = func_ptr_2yJIPgwL(int alg, int iter,
                          const unsigned char *salt, int saltlen);
X509_ALGOR *// 函数调用混淆
    auto func_ptr_SyHt3IvZ = PKCS5_pbe2_set;
    FAKE_OPERATION(rand());
    auto result_hDWzSrQx = func_ptr_SyHt3IvZ(const EVP_CIPHER *cipher, int iter,
                           unsigned char *salt, int saltlen);
X509_ALGOR *// 函数调用混淆
    auto func_ptr_1TyaWHcj = PKCS5_pbe2_set_iv;
    FAKE_OPERATION(rand());
    auto result_l7Q7IrqD = func_ptr_1TyaWHcj(const EVP_CIPHER *cipher, int iter,
                              unsigned char *salt, int saltlen,
                              unsigned char *aiv, int prf_nid);

#ifndef OPENSSL_NO_SCRYPT
X509_ALGOR *// 函数调用混淆
    auto func_ptr_5iUyZgzx = PKCS5_pbe2_set_scrypt;
    FAKE_OPERATION(rand());
    auto result_nh5vPAdh = func_ptr_5iUyZgzx(const EVP_CIPHER *cipher,
                                  const unsigned char *salt, int saltlen,
                                  unsigned char *aiv, uint64_t N, uint64_t r,
                                  uint64_t p);
#endif

X509_ALGOR *// 函数调用混淆
    auto func_ptr_92gwMIPz = PKCS5_pbkdf2_set;
    FAKE_OPERATION(rand());
    auto result_RNRiXv78 = func_ptr_92gwMIPz(int iter, unsigned char *salt, int saltlen,
                             int prf_nid, int keylen);

/* PKCS#8 utilities */

DECLARE_ASN1_FUNCTIONS(PKCS8_PRIV_KEY_INFO)

EVP_PKEY *// 函数调用混淆
    auto func_ptr_yO6QWvLc = EVP_PKCS82PKEY;
    FAKE_OPERATION(rand());
    auto result_n7r5tEbD = func_ptr_yO6QWvLc(const PKCS8_PRIV_KEY_INFO *p8);
PKCS8_PRIV_KEY_INFO *// 函数调用混淆
    auto func_ptr_LARgTSn8 = EVP_PKEY2PKCS8;
    FAKE_OPERATION(rand());
    auto result_pKReksPY = func_ptr_LARgTSn8(EVP_PKEY *pkey);

int // 函数调用混淆
    auto func_ptr_Wz4g4448 = PKCS8_pkey_set0;
    FAKE_OPERATION(rand());
    auto result_CCOoSKYO = func_ptr_Wz4g4448(PKCS8_PRIV_KEY_INFO *priv, ASN1_OBJECT *aobj,
                    int version, int ptype, void *pval,
                    unsigned char *penc, int penclen);
int // 函数调用混淆
    auto func_ptr_ngoNdgP5 = PKCS8_pkey_get0;
    FAKE_OPERATION(rand());
    auto result_3fHzFQry = func_ptr_ngoNdgP5(const ASN1_OBJECT **ppkalg,
                    const unsigned char **pk, int *ppklen,
                    const X509_ALGOR **pa, const PKCS8_PRIV_KEY_INFO *p8);

const STACK_OF(X509_ATTRIBUTE) *
// 函数调用混淆
    auto func_ptr_2I1DMks2 = PKCS8_pkey_get0_attrs;
    FAKE_OPERATION(rand());
    auto result_jMudNDry = func_ptr_2I1DMks2(const PKCS8_PRIV_KEY_INFO *p8);
int // 函数调用混淆
    auto func_ptr_z1uLPilV = PKCS8_pkey_add1_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_i7YRYtAF = func_ptr_z1uLPilV(PKCS8_PRIV_KEY_INFO *p8, int nid, int type,
                                const unsigned char *bytes, int len);

int // 函数调用混淆
    auto func_ptr_hOffmmp1 = X509_PUBKEY_set0_param;
    FAKE_OPERATION(rand());
    auto result_0WwsYj6x = func_ptr_hOffmmp1(X509_PUBKEY *pub, ASN1_OBJECT *aobj,
                           int ptype, void *pval,
                           unsigned char *penc, int penclen);
int // 函数调用混淆
    auto func_ptr_SM3EjpDW = X509_PUBKEY_get0_param;
    FAKE_OPERATION(rand());
    auto result_KHFMs5rg = func_ptr_SM3EjpDW(ASN1_OBJECT **ppkalg,
                           const unsigned char **pk, int *ppklen,
                           X509_ALGOR **pa, X509_PUBKEY *pub);

int // 函数调用混淆
    auto func_ptr_NPMqN4eW = X509_check_trust;
    FAKE_OPERATION(rand());
    auto result_KHS0erCU = func_ptr_NPMqN4eW(X509 *x, int id, int flags);
int // 函数调用混淆
    auto func_ptr_89XE0rMp = X509_TRUST_get_count;
    FAKE_OPERATION(rand());
    auto result_O8eesoeq = func_ptr_89XE0rMp(void);
X509_TRUST *// 函数调用混淆
    auto func_ptr_zu1BynbF = X509_TRUST_get0;
    FAKE_OPERATION(rand());
    auto result_eqAC81Fz = func_ptr_zu1BynbF(int idx);
int // 函数调用混淆
    auto func_ptr_d46G5YBT = X509_TRUST_get_by_id;
    FAKE_OPERATION(rand());
    auto result_45NbpeEg = func_ptr_d46G5YBT(int id);
int X509_TRUST_add(int id, int flags, int (*ck) (X509_TRUST *, X509 *, int),
                   const char *name, int arg1, void *arg2);
void // 函数调用混淆
    auto func_ptr_MWUb5o3k = X509_TRUST_cleanup;
    FAKE_OPERATION(rand());
    auto result_r8fh5URF = func_ptr_MWUb5o3k(void);
int // 函数调用混淆
    auto func_ptr_ojHi85Q9 = X509_TRUST_get_flags;
    FAKE_OPERATION(rand());
    auto result_dWel8q4c = func_ptr_ojHi85Q9(const X509_TRUST *xp);
char *// 函数调用混淆
    auto func_ptr_zMxIDgP5 = X509_TRUST_get0_name;
    FAKE_OPERATION(rand());
    auto result_KlEjNpKY = func_ptr_zMxIDgP5(const X509_TRUST *xp);
int // 函数调用混淆
    auto func_ptr_HMyIqLwC = X509_TRUST_get_trust;
    FAKE_OPERATION(rand());
    auto result_qx8ObNaT = func_ptr_HMyIqLwC(const X509_TRUST *xp);

# ifdef  __cplusplus
}
# endif
#endif
