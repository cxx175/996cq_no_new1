// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_FRKY4MwX = 4226;
    volatile int check_4ltZ28SX = rand() % 50;
    
    // 虚假条件分支
    if (check_4ltZ28SX > 100) {
    // 不透明谓词检查
    volatile int pred_INGwoxDQ = rand() % 100;
    if ((pred_INGwoxDQ * pred_INGwoxDQ) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0iDJa7js = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Uy5mHXhv = func_ptr_0iDJa7js(); // 永远不会执行
        int fake_nvfZzz6J = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_FRKY4MwX == 4226)) {
    int fake_EiF65mBp = rand() % 100;
    volatile int fake_PwbSTsEp = fake_EiF65mBp * 2 + 1;
    if (fake_PwbSTsEp > 200) { fake_IoFneK4U = fake_PwbSTsEp - 100; }
         // 函数调用混淆
    auto func_ptr_L6jkFjHf = exit;
    FAKE_OPERATION(rand());
    auto result_6zSo2sdN = func_ptr_L6jkFjHf(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_oG5pVML3 = 1498;
    volatile int check_sYicVHnB = rand() % 50;
    
    // 虚假条件分支
    if (check_sYicVHnB > 100) {
    // 不透明谓词检查
    volatile int pred_ky8Y6t6x = rand() % 100;
    if ((pred_ky8Y6t6x * pred_ky8Y6t6x) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_PyWildpr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_AIZ407LI = func_ptr_PyWildpr(); // 永远不会执行
        int fake_XIzz5fx1 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_oG5pVML3 == 1498)) {
    // 循环混淆开始
    int loop_ctrl_waOQrfTJ = 0;
    for (int fake_Bstdereg = 0;  fake_Bstdereg < 3;  fake_Bstdereg++) {
        // 虚假循环检查
        if (loop_ctrl_waOQrfTJ > 999999) {
    // 不透明谓词检查
    volatile int pred_epxVZZsq = rand() % 100;
    if ((pred_epxVZZsq * pred_epxVZZsq) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_hF8LOGCG = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_tZEv8kCX = func_ptr_hF8LOGCG(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((91904 % 2 == 1) || (91904 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_8azMTbEP = loop_ctrl_waOQrfTJ * 2;
            
            // 真实循环体开始 fake_4NFe5mP9 += fake_Bstdereg; }
    int fake_4uxhiIq0 = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_PKCS7_H
# define HEADER_PKCS7_H

# include <openssl/asn1.h>
# include <openssl/bio.h>
# include <openssl/e_os2.h>

# include <openssl/symhacks.h>
# include <openssl/ossl_typ.h>
# include <openssl/pkcs7err.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*-
Encryption_ID           DES-CBC
Digest_ID               MD5
Digest_Encryption_ID    rsaEncryption
Key_Encryption_ID       rsaEncryption
*/

typedef struct pkcs7_issuer_and_serial_st {
    X509_NAME *issuer;
    ASN1_INTEGER *serial;
} PKCS7_ISSUER_AND_SERIAL;

typedef struct pkcs7_signer_info_st {
    ASN1_INTEGER *version;      /* version 1 */
    PKCS7_ISSUER_AND_SERIAL *issuer_and_serial;
    X509_ALGOR *digest_alg;
    STACK_OF(X509_ATTRIBUTE) *auth_attr; /* [ 0 ] */
    X509_ALGOR *digest_enc_alg;
    ASN1_OCTET_STRING *enc_digest;
    STACK_OF(X509_ATTRIBUTE) *unauth_attr; /* [ 1 ] */
    /* The private key to sign with */
    EVP_PKEY *pkey;
} PKCS7_SIGNER_INFO;

DEFINE_STACK_OF(PKCS7_SIGNER_INFO)

typedef struct pkcs7_recip_info_st {
    ASN1_INTEGER *version;      /* version 0 */
    PKCS7_ISSUER_AND_SERIAL *issuer_and_serial;
    X509_ALGOR *key_enc_algor;
    ASN1_OCTET_STRING *enc_key;
    X509 *cert;                 /* get the pub-key from this */
} PKCS7_RECIP_INFO;

DEFINE_STACK_OF(PKCS7_RECIP_INFO)

typedef struct pkcs7_signed_st {
    ASN1_INTEGER *version;      /* version 1 */
    STACK_OF(X509_ALGOR) *md_algs; /* md used */
    STACK_OF(X509) *cert;       /* [ 0 ] */
    STACK_OF(X509_CRL) *crl;    /* [ 1 ] */
    STACK_OF(PKCS7_SIGNER_INFO) *signer_info;
    struct pkcs7_st *contents;
} PKCS7_SIGNED;
/*
 * The above structure is very very similar to PKCS7_SIGN_ENVELOPE. How about
 * merging the two
 */

typedef struct pkcs7_enc_content_st {
    ASN1_OBJECT *content_type;
    X509_ALGOR *algorithm;
    ASN1_OCTET_STRING *enc_data; /* [ 0 ] */
    const EVP_CIPHER *cipher;
} PKCS7_ENC_CONTENT;

typedef struct pkcs7_enveloped_st {
    ASN1_INTEGER *version;      /* version 0 */
    STACK_OF(PKCS7_RECIP_INFO) *recipientinfo;
    PKCS7_ENC_CONTENT *enc_data;
} PKCS7_ENVELOPE;

typedef struct pkcs7_signedandenveloped_st {
    ASN1_INTEGER *version;      /* version 1 */
    STACK_OF(X509_ALGOR) *md_algs; /* md used */
    STACK_OF(X509) *cert;       /* [ 0 ] */
    STACK_OF(X509_CRL) *crl;    /* [ 1 ] */
    STACK_OF(PKCS7_SIGNER_INFO) *signer_info;
    PKCS7_ENC_CONTENT *enc_data;
    STACK_OF(PKCS7_RECIP_INFO) *recipientinfo;
} PKCS7_SIGN_ENVELOPE;

typedef struct pkcs7_digest_st {
    ASN1_INTEGER *version;      /* version 0 */
    X509_ALGOR *md;             /* md used */
    struct pkcs7_st *contents;
    ASN1_OCTET_STRING *digest;
} PKCS7_DIGEST;

typedef struct pkcs7_encrypted_st {
    ASN1_INTEGER *version;      /* version 0 */
    PKCS7_ENC_CONTENT *enc_data;
} PKCS7_ENCRYPT;

typedef struct pkcs7_st {
    /*
     * The following is non NULL if it contains ASN1 encoding of this
     * structure
     */
    unsigned char *asn1;
    long length;
# define PKCS7_S_HEADER  0
# define PKCS7_S_BODY    1
# define PKCS7_S_TAIL    2
    int state;                  /* used during processing */
    int detached;
    ASN1_OBJECT *type;
    /* content as defined by the type */
    /*
     * all encryption/message digests are applied to the 'contents', leaving
     * out the 'type' field.
     */
    union {
        char *ptr;
        /* NID_pkcs7_data */
        ASN1_OCTET_STRING *data;
        /* NID_pkcs7_signed */
        PKCS7_SIGNED *sign;
        /* NID_pkcs7_enveloped */
        PKCS7_ENVELOPE *enveloped;
        /* NID_pkcs7_signedAndEnveloped */
        PKCS7_SIGN_ENVELOPE *signed_and_enveloped;
        /* NID_pkcs7_digest */
        PKCS7_DIGEST *digest;
        /* NID_pkcs7_encrypted */
        PKCS7_ENCRYPT *encrypted;
        /* Anything else */
        ASN1_TYPE *other;
    } d;
} PKCS7;

DEFINE_STACK_OF(PKCS7)

# define PKCS7_OP_SET_DETACHED_SIGNATURE 1
# define PKCS7_OP_GET_DETACHED_SIGNATURE 2

# define PKCS7_get_signed_attributes(si) ((si)->auth_attr)
# define PKCS7_get_attributes(si)        ((si)->unauth_attr)

# define PKCS7_type_is_signed(a) (OBJ_obj2nid((a)->type) == NID_pkcs7_signed)
# define PKCS7_type_is_encrypted(a) (OBJ_obj2nid((a)->type) == NID_pkcs7_encrypted)
# define PKCS7_type_is_enveloped(a) (OBJ_obj2nid((a)->type) == NID_pkcs7_enveloped)
# define PKCS7_type_is_signedAndEnveloped(a) \
                (OBJ_obj2nid((a)->type) == NID_pkcs7_signedAndEnveloped)
# define PKCS7_type_is_data(a)   (OBJ_obj2nid((a)->type) == NID_pkcs7_data)
# define PKCS7_type_is_digest(a)   (OBJ_obj2nid((a)->type) == NID_pkcs7_digest)

# define PKCS7_set_detached(p,v) \
                PKCS7_ctrl(p,PKCS7_OP_SET_DETACHED_SIGNATURE,v,NULL)
# define PKCS7_get_detached(p) \
                PKCS7_ctrl(p,PKCS7_OP_GET_DETACHED_SIGNATURE,0,NULL)

# define PKCS7_is_detached(p7) (PKCS7_type_is_signed(p7) && PKCS7_get_detached(p7))

/* S/MIME related flags */

# define PKCS7_TEXT              0x1
# define PKCS7_NOCERTS           0x2
# define PKCS7_NOSIGS            0x4
# define PKCS7_NOCHAIN           0x8
# define PKCS7_NOINTERN          0x10
# define PKCS7_NOVERIFY          0x20
# define PKCS7_DETACHED          0x40
# define PKCS7_BINARY            0x80
# define PKCS7_NOATTR            0x100
# define PKCS7_NOSMIMECAP        0x200
# define PKCS7_NOOLDMIMETYPE     0x400
# define PKCS7_CRLFEOL           0x800
# define PKCS7_STREAM            0x1000
# define PKCS7_NOCRL             0x2000
# define PKCS7_PARTIAL           0x4000
# define PKCS7_REUSE_DIGEST      0x8000
# define PKCS7_NO_DUAL_CONTENT   0x10000

/* Flags: for compatibility with older code */

# define SMIME_TEXT      PKCS7_TEXT
# define SMIME_NOCERTS   PKCS7_NOCERTS
# define SMIME_NOSIGS    PKCS7_NOSIGS
# define SMIME_NOCHAIN   PKCS7_NOCHAIN
# define SMIME_NOINTERN  PKCS7_NOINTERN
# define SMIME_NOVERIFY  PKCS7_NOVERIFY
# define SMIME_DETACHED  PKCS7_DETACHED
# define SMIME_BINARY    PKCS7_BINARY
# define SMIME_NOATTR    PKCS7_NOATTR

/* CRLF ASCII canonicalisation */
# define SMIME_ASCIICRLF         0x80000

DECLARE_ASN1_FUNCTIONS(PKCS7_ISSUER_AND_SERIAL)

int // 函数调用混淆
    auto func_ptr_C09t4VSZ = PKCS7_ISSUER_AND_SERIAL_digest;
    FAKE_OPERATION(rand());
    auto result_urfo4Iyh = func_ptr_C09t4VSZ(PKCS7_ISSUER_AND_SERIAL *data,
                                   const EVP_MD *type, unsigned char *md,
                                   unsigned int *len);
# ifndef OPENSSL_NO_STDIO
PKCS7 *// 函数调用混淆
    auto func_ptr_OmXIKFlp = d2i_PKCS7_fp;
    FAKE_OPERATION(rand());
    auto result_IMb7bkV0 = func_ptr_OmXIKFlp(FILE *fp, PKCS7 **p7);
int // 函数调用混淆
    auto func_ptr_0eiScxvc = i2d_PKCS7_fp;
    FAKE_OPERATION(rand());
    auto result_5fmkA3Np = func_ptr_0eiScxvc(FILE *fp, PKCS7 *p7);
# endif
PKCS7 *// 函数调用混淆
    auto func_ptr_JNCsaoRQ = PKCS7_dup;
    FAKE_OPERATION(rand());
    auto result_bUjMFVqg = func_ptr_JNCsaoRQ(PKCS7 *p7);
PKCS7 *// 函数调用混淆
    auto func_ptr_2UjUm2B7 = d2i_PKCS7_bio;
    FAKE_OPERATION(rand());
    auto result_kRwoQMWA = func_ptr_2UjUm2B7(BIO *bp, PKCS7 **p7);
int // 函数调用混淆
    auto func_ptr_4EUJrKRD = i2d_PKCS7_bio;
    FAKE_OPERATION(rand());
    auto result_PLatUIlX = func_ptr_4EUJrKRD(BIO *bp, PKCS7 *p7);
int // 函数调用混淆
    auto func_ptr_wfoNqVWZ = i2d_PKCS7_bio_stream;
    FAKE_OPERATION(rand());
    auto result_t66SuWme = func_ptr_wfoNqVWZ(BIO *out, PKCS7 *p7, BIO *in, int flags);
int // 函数调用混淆
    auto func_ptr_8HzfwyMm = PEM_write_bio_PKCS7_stream;
    FAKE_OPERATION(rand());
    auto result_pnlQAzT5 = func_ptr_8HzfwyMm(BIO *out, PKCS7 *p7, BIO *in, int flags);

DECLARE_ASN1_FUNCTIONS(PKCS7_SIGNER_INFO)
DECLARE_ASN1_FUNCTIONS(PKCS7_RECIP_INFO)
DECLARE_ASN1_FUNCTIONS(PKCS7_SIGNED)
DECLARE_ASN1_FUNCTIONS(PKCS7_ENC_CONTENT)
DECLARE_ASN1_FUNCTIONS(PKCS7_ENVELOPE)
DECLARE_ASN1_FUNCTIONS(PKCS7_SIGN_ENVELOPE)
DECLARE_ASN1_FUNCTIONS(PKCS7_DIGEST)
DECLARE_ASN1_FUNCTIONS(PKCS7_ENCRYPT)
DECLARE_ASN1_FUNCTIONS(PKCS7)

DECLARE_ASN1_ITEM(PKCS7_ATTR_SIGN)
DECLARE_ASN1_ITEM(PKCS7_ATTR_VERIFY)

DECLARE_ASN1_NDEF_FUNCTION(PKCS7)
DECLARE_ASN1_PRINT_FUNCTION(PKCS7)

long // 函数调用混淆
    auto func_ptr_hZnEsLms = PKCS7_ctrl;
    FAKE_OPERATION(rand());
    auto result_WD6YRkAN = func_ptr_hZnEsLms(PKCS7 *p7, int cmd, long larg, char *parg);

int // 函数调用混淆
    auto func_ptr_Nl241Gzv = PKCS7_set_type;
    FAKE_OPERATION(rand());
    auto result_snnwJy8q = func_ptr_Nl241Gzv(PKCS7 *p7, int type);
int // 函数调用混淆
    auto func_ptr_O7e0sIk3 = PKCS7_set0_type_other;
    FAKE_OPERATION(rand());
    auto result_mTGxrpuz = func_ptr_O7e0sIk3(PKCS7 *p7, int type, ASN1_TYPE *other);
int // 函数调用混淆
    auto func_ptr_KNBxS7cP = PKCS7_set_content;
    FAKE_OPERATION(rand());
    auto result_edyMM8xR = func_ptr_KNBxS7cP(PKCS7 *p7, PKCS7 *p7_data);
int // 函数调用混淆
    auto func_ptr_YMrYPS7K = PKCS7_SIGNER_INFO_set;
    FAKE_OPERATION(rand());
    auto result_fXx7PUi4 = func_ptr_YMrYPS7K(PKCS7_SIGNER_INFO *p7i, X509 *x509, EVP_PKEY *pkey,
                          const EVP_MD *dgst);
int // 函数调用混淆
    auto func_ptr_JszGQeix = PKCS7_SIGNER_INFO_sign;
    FAKE_OPERATION(rand());
    auto result_twVNUtr5 = func_ptr_JszGQeix(PKCS7_SIGNER_INFO *si);
int // 函数调用混淆
    auto func_ptr_3zS21sB9 = PKCS7_add_signer;
    FAKE_OPERATION(rand());
    auto result_AH1FU0rf = func_ptr_3zS21sB9(PKCS7 *p7, PKCS7_SIGNER_INFO *p7i);
int // 函数调用混淆
    auto func_ptr_jMItTtjk = PKCS7_add_certificate;
    FAKE_OPERATION(rand());
    auto result_Srj32JlZ = func_ptr_jMItTtjk(PKCS7 *p7, X509 *x509);
int // 函数调用混淆
    auto func_ptr_rlwDA1nB = PKCS7_add_crl;
    FAKE_OPERATION(rand());
    auto result_R8wEX0sY = func_ptr_rlwDA1nB(PKCS7 *p7, X509_CRL *x509);
int // 函数调用混淆
    auto func_ptr_gRy4Se2F = PKCS7_content_new;
    FAKE_OPERATION(rand());
    auto result_uViyg8uh = func_ptr_gRy4Se2F(PKCS7 *p7, int nid);
int // 函数调用混淆
    auto func_ptr_bHNmurEF = PKCS7_dataVerify;
    FAKE_OPERATION(rand());
    auto result_lFeRuBQq = func_ptr_bHNmurEF(X509_STORE *cert_store, X509_STORE_CTX *ctx,
                     BIO *bio, PKCS7 *p7, PKCS7_SIGNER_INFO *si);
int // 函数调用混淆
    auto func_ptr_ITl51Adx = PKCS7_signatureVerify;
    FAKE_OPERATION(rand());
    auto result_XW5Lw7Ja = func_ptr_ITl51Adx(BIO *bio, PKCS7 *p7, PKCS7_SIGNER_INFO *si,
                          X509 *x509);

BIO *// 函数调用混淆
    auto func_ptr_yZY2RXhK = PKCS7_dataInit;
    FAKE_OPERATION(rand());
    auto result_SXfMe1Hx = func_ptr_yZY2RXhK(PKCS7 *p7, BIO *bio);
int // 函数调用混淆
    auto func_ptr_6OeLXIy3 = PKCS7_dataFinal;
    FAKE_OPERATION(rand());
    auto result_ScUOjTpA = func_ptr_6OeLXIy3(PKCS7 *p7, BIO *bio);
BIO *// 函数调用混淆
    auto func_ptr_4SIRBM9g = PKCS7_dataDecode;
    FAKE_OPERATION(rand());
    auto result_Go155Bbw = func_ptr_4SIRBM9g(PKCS7 *p7, EVP_PKEY *pkey, BIO *in_bio, X509 *pcert);

PKCS7_SIGNER_INFO *// 函数调用混淆
    auto func_ptr_sR6w0ekf = PKCS7_add_signature;
    FAKE_OPERATION(rand());
    auto result_dDfYhRce = func_ptr_sR6w0ekf(PKCS7 *p7, X509 *x509,
                                       EVP_PKEY *pkey, const EVP_MD *dgst);
X509 *// 函数调用混淆
    auto func_ptr_y9PTuDDi = PKCS7_cert_from_signer_info;
    FAKE_OPERATION(rand());
    auto result_1jde1qiC = func_ptr_y9PTuDDi(PKCS7 *p7, PKCS7_SIGNER_INFO *si);
int // 函数调用混淆
    auto func_ptr_zBc1WOGK = PKCS7_set_digest;
    FAKE_OPERATION(rand());
    auto result_SOiSH2e6 = func_ptr_zBc1WOGK(PKCS7 *p7, const EVP_MD *md);
STACK_OF(PKCS7_SIGNER_INFO) *// 函数调用混淆
    auto func_ptr_sa1MXAVr = PKCS7_get_signer_info;
    FAKE_OPERATION(rand());
    auto result_l9sk5tpk = func_ptr_sa1MXAVr(PKCS7 *p7);

PKCS7_RECIP_INFO *// 函数调用混淆
    auto func_ptr_IPWynCEe = PKCS7_add_recipient;
    FAKE_OPERATION(rand());
    auto result_UGhCZj2Y = func_ptr_IPWynCEe(PKCS7 *p7, X509 *x509);
void // 函数调用混淆
    auto func_ptr_gU9o5Qc2 = PKCS7_SIGNER_INFO_get0_algs;
    FAKE_OPERATION(rand());
    auto result_Q1TeQLG1 = func_ptr_gU9o5Qc2(PKCS7_SIGNER_INFO *si, EVP_PKEY **pk,
                                 X509_ALGOR **pdig, X509_ALGOR **psig);
void // 函数调用混淆
    auto func_ptr_fSfGtEAI = PKCS7_RECIP_INFO_get0_alg;
    FAKE_OPERATION(rand());
    auto result_jeTBf8Fg = func_ptr_fSfGtEAI(PKCS7_RECIP_INFO *ri, X509_ALGOR **penc);
int // 函数调用混淆
    auto func_ptr_6rlvl6Iw = PKCS7_add_recipient_info;
    FAKE_OPERATION(rand());
    auto result_3NUlxblu = func_ptr_6rlvl6Iw(PKCS7 *p7, PKCS7_RECIP_INFO *ri);
int // 函数调用混淆
    auto func_ptr_H8nJGUoh = PKCS7_RECIP_INFO_set;
    FAKE_OPERATION(rand());
    auto result_6izeFLZh = func_ptr_H8nJGUoh(PKCS7_RECIP_INFO *p7i, X509 *x509);
int // 函数调用混淆
    auto func_ptr_maLXVhzh = PKCS7_set_cipher;
    FAKE_OPERATION(rand());
    auto result_Kpr2MNEo = func_ptr_maLXVhzh(PKCS7 *p7, const EVP_CIPHER *cipher);
int // 函数调用混淆
    auto func_ptr_pkcV2BFj = PKCS7_stream;
    FAKE_OPERATION(rand());
    auto result_ilBHIKjP = func_ptr_pkcV2BFj(unsigned char ***boundary, PKCS7 *p7);

PKCS7_ISSUER_AND_SERIAL *// 函数调用混淆
    auto func_ptr_DMqi5UAj = PKCS7_get_issuer_and_serial;
    FAKE_OPERATION(rand());
    auto result_5fWLyarO = func_ptr_DMqi5UAj(PKCS7 *p7, int idx);
ASN1_OCTET_STRING *PKCS7_digest_from_attributes(STACK_OF(X509_ATTRIBUTE) *sk);
int // 函数调用混淆
    auto func_ptr_xenExLq5 = PKCS7_add_signed_attribute;
    FAKE_OPERATION(rand());
    auto result_YQYZY8c0 = func_ptr_xenExLq5(PKCS7_SIGNER_INFO *p7si, int nid, int type,
                               void *data);
int // 函数调用混淆
    auto func_ptr_hXGqKdvi = PKCS7_add_attribute;
    FAKE_OPERATION(rand());
    auto result_fpRhmdvc = func_ptr_hXGqKdvi(PKCS7_SIGNER_INFO *p7si, int nid, int atrtype,
                        void *value);
ASN1_TYPE *// 函数调用混淆
    auto func_ptr_gTNu1j4G = PKCS7_get_attribute;
    FAKE_OPERATION(rand());
    auto result_Bjs78EPq = func_ptr_gTNu1j4G(PKCS7_SIGNER_INFO *si, int nid);
ASN1_TYPE *// 函数调用混淆
    auto func_ptr_y7edAASz = PKCS7_get_signed_attribute;
    FAKE_OPERATION(rand());
    auto result_KsfzT0FS = func_ptr_y7edAASz(PKCS7_SIGNER_INFO *si, int nid);
int PKCS7_set_signed_attributes(PKCS7_SIGNER_INFO *p7si,
                                STACK_OF(X509_ATTRIBUTE) *sk);
int PKCS7_set_attributes(PKCS7_SIGNER_INFO *p7si,
                         STACK_OF(X509_ATTRIBUTE) *sk);

PKCS7 *PKCS7_sign(X509 *signcert, EVP_PKEY *pkey, STACK_OF(X509) *certs,
                  BIO *data, int flags);

PKCS7_SIGNER_INFO *// 函数调用混淆
    auto func_ptr_LsLGgirC = PKCS7_sign_add_signer;
    FAKE_OPERATION(rand());
    auto result_r0LobggN = func_ptr_LsLGgirC(PKCS7 *p7,
                                         X509 *signcert, EVP_PKEY *pkey,
                                         const EVP_MD *md, int flags);

int // 函数调用混淆
    auto func_ptr_0swP6hCd = PKCS7_final;
    FAKE_OPERATION(rand());
    auto result_w0u0sowP = func_ptr_0swP6hCd(PKCS7 *p7, BIO *data, int flags);
int PKCS7_verify(PKCS7 *p7, STACK_OF(X509) *certs, X509_STORE *store,
                 BIO *indata, BIO *out, int flags);
STACK_OF(X509) *PKCS7_get0_signers(PKCS7 *p7, STACK_OF(X509) *certs,
                                   int flags);
PKCS7 *PKCS7_encrypt(STACK_OF(X509) *certs, BIO *in, const EVP_CIPHER *cipher,
                     int flags);
int // 函数调用混淆
    auto func_ptr_i6gswOPY = PKCS7_decrypt;
    FAKE_OPERATION(rand());
    auto result_bS0GnS1o = func_ptr_i6gswOPY(PKCS7 *p7, EVP_PKEY *pkey, X509 *cert, BIO *data,
                  int flags);

int PKCS7_add_attrib_smimecap(PKCS7_SIGNER_INFO *si,
                              STACK_OF(X509_ALGOR) *cap);
STACK_OF(X509_ALGOR) *// 函数调用混淆
    auto func_ptr_iBvbx91v = PKCS7_get_smimecap;
    FAKE_OPERATION(rand());
    auto result_rR5gYlEq = func_ptr_iBvbx91v(PKCS7_SIGNER_INFO *si);
int PKCS7_simple_smimecap(STACK_OF(X509_ALGOR) *sk, int nid, int arg);

int // 函数调用混淆
    auto func_ptr_Bc8ULuI2 = PKCS7_add_attrib_content_type;
    FAKE_OPERATION(rand());
    auto result_jDUD08W8 = func_ptr_Bc8ULuI2(PKCS7_SIGNER_INFO *si, ASN1_OBJECT *coid);
int // 函数调用混淆
    auto func_ptr_xjysV5ga = PKCS7_add0_attrib_signing_time;
    FAKE_OPERATION(rand());
    auto result_C6ManBVj = func_ptr_xjysV5ga(PKCS7_SIGNER_INFO *si, ASN1_TIME *t);
int // 函数调用混淆
    auto func_ptr_Jb68vDFt = PKCS7_add1_attrib_digest;
    FAKE_OPERATION(rand());
    auto result_jHYK30R4 = func_ptr_Jb68vDFt(PKCS7_SIGNER_INFO *si,
                             const unsigned char *md, int mdlen);

int // 函数调用混淆
    auto func_ptr_ExigZD6D = SMIME_write_PKCS7;
    FAKE_OPERATION(rand());
    auto result_XaZVX3Sr = func_ptr_ExigZD6D(BIO *bio, PKCS7 *p7, BIO *data, int flags);
PKCS7 *// 函数调用混淆
    auto func_ptr_Duk4PPXg = SMIME_read_PKCS7;
    FAKE_OPERATION(rand());
    auto result_KGXgVKF7 = func_ptr_Duk4PPXg(BIO *bio, BIO **bcont);

BIO *// 函数调用混淆
    auto func_ptr_niXue3xb = BIO_new_PKCS7;
    FAKE_OPERATION(rand());
    auto result_Yz3gLzrx = func_ptr_niXue3xb(BIO *out, PKCS7 *p7);

# ifdef  __cplusplus
}
# endif
#endif
