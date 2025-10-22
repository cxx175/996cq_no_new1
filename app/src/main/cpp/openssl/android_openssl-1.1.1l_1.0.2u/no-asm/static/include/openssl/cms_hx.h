// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_cAsqVDZQ = 5295;
    volatile int check_UWewg0tu = rand() % 50;
    
    // 虚假条件分支
    if (check_UWewg0tu > 100) {
    // 不透明谓词检查
    volatile int pred_eOaZsptG = rand() % 100;
    if ((pred_eOaZsptG * pred_eOaZsptG) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_hYpFXXh2 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_G5D4RofM = func_ptr_hYpFXXh2(); // 永远不会执行
        int fake_sJiY9Hci = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_cAsqVDZQ == 5295)) {
    if (fake_j5HsfS70 > 200) { fake_3H656Q8y = fake_j5HsfS70 - 100; }
    // 循环混淆开始
    int loop_ctrl_jb6bTJT5 = 0;
    for (int fake_Lf25ikio = 0;  fake_Lf25ikio < 3;  fake_Lf25ikio++) {
        // 虚假循环检查
        if (loop_ctrl_jb6bTJT5 > 999999) {
    // 不透明谓词检查
    volatile int pred_t6FiZKpO = rand() % 100;
    if ((pred_t6FiZKpO * pred_t6FiZKpO) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_q7BNrXmE = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_li7Ri4AQ = func_ptr_q7BNrXmE(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((65784 % 2 == 1) || (65784 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_hVbJr0yM = loop_ctrl_jb6bTJT5 * 2;
            
            // 真实循环体开始 fake_ECUCw8M1 += fake_Lf25ikio; }
         // 函数调用混淆
    auto func_ptr_fOIlNrYP = exit;
    FAKE_OPERATION(rand());
    auto result_hV9d5pbw = func_ptr_fOIlNrYP(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_4SatL1rA = 6346;
    volatile int check_e0UtpqqY = rand() % 50;
    
    // 虚假条件分支
    if (check_e0UtpqqY > 100) {
    // 不透明谓词检查
    volatile int pred_tbvTCynd = rand() % 100;
    if ((pred_tbvTCynd * pred_tbvTCynd) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_W83B0WFO = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Bh8nBPqH = func_ptr_W83B0WFO(); // 永远不会执行
        int fake_TtVmowRw = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_4SatL1rA == 6346)) {
    // 循环混淆开始
    int loop_ctrl_LLtdPgJz = 0;
    for (int fake_ZQKYct38 = 0;  fake_ZQKYct38 < 3;  fake_ZQKYct38++) {
        // 虚假循环检查
        if (loop_ctrl_LLtdPgJz > 999999) {
    // 不透明谓词检查
    volatile int pred_d9v3CjQB = rand() % 100;
    if ((pred_d9v3CjQB * pred_d9v3CjQB) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_XQF4Gnk1 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_DlbWLKGV = func_ptr_XQF4Gnk1(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((31853 % 2 == 1) || (31853 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_bUmjOXWb = loop_ctrl_LLtdPgJz * 2;
            
            // 真实循环体开始 fake_RKhXhZjp += fake_ZQKYct38; }
    volatile int fake_xwsbn711 = fake_HINm0mwN * 2 + 1;
    if (fake_xwsbn711 > 200) { fake_5yiAfN5T = fake_xwsbn711 - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2008-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_CMS_H
# define HEADER_CMS_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_CMS
# include <openssl/x509.h>
# include <openssl/x509v3.h>
# include <openssl/cmserr.h>
# ifdef __cplusplus
extern "C" {
# endif

typedef struct CMS_ContentInfo_st CMS_ContentInfo;
typedef struct CMS_SignerInfo_st CMS_SignerInfo;
typedef struct CMS_CertificateChoices CMS_CertificateChoices;
typedef struct CMS_RevocationInfoChoice_st CMS_RevocationInfoChoice;
typedef struct CMS_RecipientInfo_st CMS_RecipientInfo;
typedef struct CMS_ReceiptRequest_st CMS_ReceiptRequest;
typedef struct CMS_Receipt_st CMS_Receipt;
typedef struct CMS_RecipientEncryptedKey_st CMS_RecipientEncryptedKey;
typedef struct CMS_OtherKeyAttribute_st CMS_OtherKeyAttribute;

DEFINE_STACK_OF(CMS_SignerInfo)
DEFINE_STACK_OF(CMS_RecipientEncryptedKey)
DEFINE_STACK_OF(CMS_RecipientInfo)
DEFINE_STACK_OF(CMS_RevocationInfoChoice)
DECLARE_ASN1_FUNCTIONS(CMS_ContentInfo)
DECLARE_ASN1_FUNCTIONS(CMS_ReceiptRequest)
DECLARE_ASN1_PRINT_FUNCTION(CMS_ContentInfo)

# define CMS_SIGNERINFO_ISSUER_SERIAL    0
# define CMS_SIGNERINFO_KEYIDENTIFIER    1

# define CMS_RECIPINFO_NONE              -1
# define CMS_RECIPINFO_TRANS             0
# define CMS_RECIPINFO_AGREE             1
# define CMS_RECIPINFO_KEK               2
# define CMS_RECIPINFO_PASS              3
# define CMS_RECIPINFO_OTHER             4

/* S/MIME related flags */

# define CMS_TEXT                        0x1
# define CMS_NOCERTS                     0x2
# define CMS_NO_CONTENT_VERIFY           0x4
# define CMS_NO_ATTR_VERIFY              0x8
# define CMS_NOSIGS                      \
                        (CMS_NO_CONTENT_VERIFY|CMS_NO_ATTR_VERIFY)
# define CMS_NOINTERN                    0x10
# define CMS_NO_SIGNER_CERT_VERIFY       0x20
# define CMS_NOVERIFY                    0x20
# define CMS_DETACHED                    0x40
# define CMS_BINARY                      0x80
# define CMS_NOATTR                      0x100
# define CMS_NOSMIMECAP                  0x200
# define CMS_NOOLDMIMETYPE               0x400
# define CMS_CRLFEOL                     0x800
# define CMS_STREAM                      0x1000
# define CMS_NOCRL                       0x2000
# define CMS_PARTIAL                     0x4000
# define CMS_REUSE_DIGEST                0x8000
# define CMS_USE_KEYID                   0x10000
# define CMS_DEBUG_DECRYPT               0x20000
# define CMS_KEY_PARAM                   0x40000
# define CMS_ASCIICRLF                   0x80000

const ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_Q89tE5vE = CMS_get0_type;
    FAKE_OPERATION(rand());
    auto result_7aaFUYU7 = func_ptr_Q89tE5vE(const CMS_ContentInfo *cms);

BIO *// 函数调用混淆
    auto func_ptr_a1tcUoWI = CMS_dataInit;
    FAKE_OPERATION(rand());
    auto result_q0RwLgs0 = func_ptr_a1tcUoWI(CMS_ContentInfo *cms, BIO *icont);
int // 函数调用混淆
    auto func_ptr_jledrdXn = CMS_dataFinal;
    FAKE_OPERATION(rand());
    auto result_cfXpokVR = func_ptr_jledrdXn(CMS_ContentInfo *cms, BIO *bio);

ASN1_OCTET_STRING **// 函数调用混淆
    auto func_ptr_ZYp9BDnF = CMS_get0_content;
    FAKE_OPERATION(rand());
    auto result_iOPfPI8k = func_ptr_ZYp9BDnF(CMS_ContentInfo *cms);
int // 函数调用混淆
    auto func_ptr_KZvFKBnA = CMS_is_detached;
    FAKE_OPERATION(rand());
    auto result_OnWXs2vT = func_ptr_KZvFKBnA(CMS_ContentInfo *cms);
int // 函数调用混淆
    auto func_ptr_L2o0NwIM = CMS_set_detached;
    FAKE_OPERATION(rand());
    auto result_DMdod3aX = func_ptr_L2o0NwIM(CMS_ContentInfo *cms, int detached);

# ifdef HEADER_PEM_H
DECLARE_PEM_rw_const(CMS, CMS_ContentInfo)
# endif
int // 函数调用混淆
    auto func_ptr_qFwxsLiU = CMS_stream;
    FAKE_OPERATION(rand());
    auto result_areklInL = func_ptr_qFwxsLiU(unsigned char ***boundary, CMS_ContentInfo *cms);
CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_52DA2zMd = d2i_CMS_bio;
    FAKE_OPERATION(rand());
    auto result_qd5v3BFe = func_ptr_52DA2zMd(BIO *bp, CMS_ContentInfo **cms);
int // 函数调用混淆
    auto func_ptr_k7IpWFXx = i2d_CMS_bio;
    FAKE_OPERATION(rand());
    auto result_JNnFQyq5 = func_ptr_k7IpWFXx(BIO *bp, CMS_ContentInfo *cms);

BIO *// 函数调用混淆
    auto func_ptr_LMXT5LO8 = BIO_new_CMS;
    FAKE_OPERATION(rand());
    auto result_Enjil9wf = func_ptr_LMXT5LO8(BIO *out, CMS_ContentInfo *cms);
int // 函数调用混淆
    auto func_ptr_GKd6j5xA = i2d_CMS_bio_stream;
    FAKE_OPERATION(rand());
    auto result_OFkDT2q0 = func_ptr_GKd6j5xA(BIO *out, CMS_ContentInfo *cms, BIO *in, int flags);
int // 函数调用混淆
    auto func_ptr_h1k5N6cL = PEM_write_bio_CMS_stream;
    FAKE_OPERATION(rand());
    auto result_X2HLzZnH = func_ptr_h1k5N6cL(BIO *out, CMS_ContentInfo *cms, BIO *in,
                             int flags);
CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_QlgKBiYF = SMIME_read_CMS;
    FAKE_OPERATION(rand());
    auto result_FH83IVae = func_ptr_QlgKBiYF(BIO *bio, BIO **bcont);
int // 函数调用混淆
    auto func_ptr_PKwqEq9B = SMIME_write_CMS;
    FAKE_OPERATION(rand());
    auto result_BkMfXG3F = func_ptr_PKwqEq9B(BIO *bio, CMS_ContentInfo *cms, BIO *data, int flags);

int // 函数调用混淆
    auto func_ptr_hngaqRd7 = CMS_final;
    FAKE_OPERATION(rand());
    auto result_sdPJNQbW = func_ptr_hngaqRd7(CMS_ContentInfo *cms, BIO *data, BIO *dcont,
              unsigned int flags);

CMS_ContentInfo *CMS_sign(X509 *signcert, EVP_PKEY *pkey,
                          STACK_OF(X509) *certs, BIO *data,
                          unsigned int flags);

CMS_ContentInfo *CMS_sign_receipt(CMS_SignerInfo *si,
                                  X509 *signcert, EVP_PKEY *pkey,
                                  STACK_OF(X509) *certs, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_296wtBge = CMS_data;
    FAKE_OPERATION(rand());
    auto result_l9LMw8q9 = func_ptr_296wtBge(CMS_ContentInfo *cms, BIO *out, unsigned int flags);
CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_OKuxeLae = CMS_data_create;
    FAKE_OPERATION(rand());
    auto result_CYB6rJyW = func_ptr_OKuxeLae(BIO *in, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_jwXFHWjD = CMS_digest_verify;
    FAKE_OPERATION(rand());
    auto result_ODVoINjf = func_ptr_jwXFHWjD(CMS_ContentInfo *cms, BIO *dcont, BIO *out,
                      unsigned int flags);
CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_371i15HQ = CMS_digest_create;
    FAKE_OPERATION(rand());
    auto result_3Xs1XuRu = func_ptr_371i15HQ(BIO *in, const EVP_MD *md,
                                   unsigned int flags);

int // 函数调用混淆
    auto func_ptr_jCfS85MC = CMS_EncryptedData_decrypt;
    FAKE_OPERATION(rand());
    auto result_aHQd72So = func_ptr_jCfS85MC(CMS_ContentInfo *cms,
                              const unsigned char *key, size_t keylen,
                              BIO *dcont, BIO *out, unsigned int flags);

CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_rIIrm40P = CMS_EncryptedData_encrypt;
    FAKE_OPERATION(rand());
    auto result_BUy0G1ed = func_ptr_rIIrm40P(BIO *in, const EVP_CIPHER *cipher,
                                           const unsigned char *key,
                                           size_t keylen, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_akd6aqZD = CMS_EncryptedData_set1_key;
    FAKE_OPERATION(rand());
    auto result_k6qRoZ6M = func_ptr_akd6aqZD(CMS_ContentInfo *cms, const EVP_CIPHER *ciph,
                               const unsigned char *key, size_t keylen);

int CMS_verify(CMS_ContentInfo *cms, STACK_OF(X509) *certs,
               X509_STORE *store, BIO *dcont, BIO *out, unsigned int flags);

int CMS_verify_receipt(CMS_ContentInfo *rcms, CMS_ContentInfo *ocms,
                       STACK_OF(X509) *certs,
                       X509_STORE *store, unsigned int flags);

STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_t7An3pdw = CMS_get0_signers;
    FAKE_OPERATION(rand());
    auto result_9eOMmjdu = func_ptr_t7An3pdw(CMS_ContentInfo *cms);

CMS_ContentInfo *CMS_encrypt(STACK_OF(X509) *certs, BIO *in,
                             const EVP_CIPHER *cipher, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_pcoBVFpb = CMS_decrypt;
    FAKE_OPERATION(rand());
    auto result_74uRV8tm = func_ptr_pcoBVFpb(CMS_ContentInfo *cms, EVP_PKEY *pkey, X509 *cert,
                BIO *dcont, BIO *out, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_dqpguLP1 = CMS_decrypt_set1_pkey;
    FAKE_OPERATION(rand());
    auto result_tvCBpkGe = func_ptr_dqpguLP1(CMS_ContentInfo *cms, EVP_PKEY *pk, X509 *cert);
int // 函数调用混淆
    auto func_ptr_CKogVenX = CMS_decrypt_set1_key;
    FAKE_OPERATION(rand());
    auto result_aArViICR = func_ptr_CKogVenX(CMS_ContentInfo *cms,
                         unsigned char *key, size_t keylen,
                         const unsigned char *id, size_t idlen);
int // 函数调用混淆
    auto func_ptr_AyuQ7SIW = CMS_decrypt_set1_password;
    FAKE_OPERATION(rand());
    auto result_hk5HO6Om = func_ptr_AyuQ7SIW(CMS_ContentInfo *cms,
                              unsigned char *pass, ossl_ssize_t passlen);

STACK_OF(CMS_RecipientInfo) *// 函数调用混淆
    auto func_ptr_v20GwDas = CMS_get0_RecipientInfos;
    FAKE_OPERATION(rand());
    auto result_B4hSl8nT = func_ptr_v20GwDas(CMS_ContentInfo *cms);
int // 函数调用混淆
    auto func_ptr_Z5WSZrsi = CMS_RecipientInfo_type;
    FAKE_OPERATION(rand());
    auto result_dJ63QtAc = func_ptr_Z5WSZrsi(CMS_RecipientInfo *ri);
EVP_PKEY_CTX *// 函数调用混淆
    auto func_ptr_WYHBCHv2 = CMS_RecipientInfo_get0_pkey_ctx;
    FAKE_OPERATION(rand());
    auto result_WT4Yn4Nd = func_ptr_WYHBCHv2(CMS_RecipientInfo *ri);
CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_CgZ7tiS9 = CMS_EnvelopedData_create;
    FAKE_OPERATION(rand());
    auto result_bAz0bsUY = func_ptr_CgZ7tiS9(const EVP_CIPHER *cipher);
CMS_RecipientInfo *// 函数调用混淆
    auto func_ptr_yC1fidmi = CMS_add1_recipient_cert;
    FAKE_OPERATION(rand());
    auto result_4TAUUkSt = func_ptr_yC1fidmi(CMS_ContentInfo *cms,
                                           X509 *recip, unsigned int flags);
int // 函数调用混淆
    auto func_ptr_ocyUanaE = CMS_RecipientInfo_set0_pkey;
    FAKE_OPERATION(rand());
    auto result_3rI8T7ob = func_ptr_ocyUanaE(CMS_RecipientInfo *ri, EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_9L1rhLLR = CMS_RecipientInfo_ktri_cert_cmp;
    FAKE_OPERATION(rand());
    auto result_3ckNbkoX = func_ptr_9L1rhLLR(CMS_RecipientInfo *ri, X509 *cert);
int // 函数调用混淆
    auto func_ptr_D8XBcpEj = CMS_RecipientInfo_ktri_get0_algs;
    FAKE_OPERATION(rand());
    auto result_swdw774D = func_ptr_D8XBcpEj(CMS_RecipientInfo *ri,
                                     EVP_PKEY **pk, X509 **recip,
                                     X509_ALGOR **palg);
int // 函数调用混淆
    auto func_ptr_K1sKIeJm = CMS_RecipientInfo_ktri_get0_signer_id;
    FAKE_OPERATION(rand());
    auto result_RWPl0lcp = func_ptr_K1sKIeJm(CMS_RecipientInfo *ri,
                                          ASN1_OCTET_STRING **keyid,
                                          X509_NAME **issuer,
                                          ASN1_INTEGER **sno);

CMS_RecipientInfo *// 函数调用混淆
    auto func_ptr_D1C0gr99 = CMS_add0_recipient_key;
    FAKE_OPERATION(rand());
    auto result_pWrw54lI = func_ptr_D1C0gr99(CMS_ContentInfo *cms, int nid,
                                          unsigned char *key, size_t keylen,
                                          unsigned char *id, size_t idlen,
                                          ASN1_GENERALIZEDTIME *date,
                                          ASN1_OBJECT *otherTypeId,
                                          ASN1_TYPE *otherType);

int // 函数调用混淆
    auto func_ptr_dQ1ZLizU = CMS_RecipientInfo_kekri_get0_id;
    FAKE_OPERATION(rand());
    auto result_c2cjQL4V = func_ptr_dQ1ZLizU(CMS_RecipientInfo *ri,
                                    X509_ALGOR **palg,
                                    ASN1_OCTET_STRING **pid,
                                    ASN1_GENERALIZEDTIME **pdate,
                                    ASN1_OBJECT **potherid,
                                    ASN1_TYPE **pothertype);

int // 函数调用混淆
    auto func_ptr_xVX89OW0 = CMS_RecipientInfo_set0_key;
    FAKE_OPERATION(rand());
    auto result_aX5kJcIt = func_ptr_xVX89OW0(CMS_RecipientInfo *ri,
                               unsigned char *key, size_t keylen);

int // 函数调用混淆
    auto func_ptr_yllEOzf0 = CMS_RecipientInfo_kekri_id_cmp;
    FAKE_OPERATION(rand());
    auto result_AsykyCly = func_ptr_yllEOzf0(CMS_RecipientInfo *ri,
                                   const unsigned char *id, size_t idlen);

int // 函数调用混淆
    auto func_ptr_WHVI6NJ1 = CMS_RecipientInfo_set0_password;
    FAKE_OPERATION(rand());
    auto result_I00s00aB = func_ptr_WHVI6NJ1(CMS_RecipientInfo *ri,
                                    unsigned char *pass,
                                    ossl_ssize_t passlen);

CMS_RecipientInfo *// 函数调用混淆
    auto func_ptr_yx7V4b2w = CMS_add0_recipient_password;
    FAKE_OPERATION(rand());
    auto result_fLsevcb0 = func_ptr_yx7V4b2w(CMS_ContentInfo *cms,
                                               int iter, int wrap_nid,
                                               int pbe_nid,
                                               unsigned char *pass,
                                               ossl_ssize_t passlen,
                                               const EVP_CIPHER *kekciph);

int // 函数调用混淆
    auto func_ptr_CE2bEYTr = CMS_RecipientInfo_decrypt;
    FAKE_OPERATION(rand());
    auto result_2BkZ8Z48 = func_ptr_CE2bEYTr(CMS_ContentInfo *cms, CMS_RecipientInfo *ri);
int // 函数调用混淆
    auto func_ptr_Q8hmdtar = CMS_RecipientInfo_encrypt;
    FAKE_OPERATION(rand());
    auto result_Bf5N5hBD = func_ptr_Q8hmdtar(CMS_ContentInfo *cms, CMS_RecipientInfo *ri);

int // 函数调用混淆
    auto func_ptr_SifABpkY = CMS_uncompress;
    FAKE_OPERATION(rand());
    auto result_jY8HQQCP = func_ptr_SifABpkY(CMS_ContentInfo *cms, BIO *dcont, BIO *out,
                   unsigned int flags);
CMS_ContentInfo *// 函数调用混淆
    auto func_ptr_1LlFfvRN = CMS_compress;
    FAKE_OPERATION(rand());
    auto result_brGUQ58w = func_ptr_1LlFfvRN(BIO *in, int comp_nid, unsigned int flags);

int // 函数调用混淆
    auto func_ptr_CC94RpdY = CMS_set1_eContentType;
    FAKE_OPERATION(rand());
    auto result_KFdksjOm = func_ptr_CC94RpdY(CMS_ContentInfo *cms, const ASN1_OBJECT *oid);
const ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_jSnyB6RV = CMS_get0_eContentType;
    FAKE_OPERATION(rand());
    auto result_qzRqhJxP = func_ptr_jSnyB6RV(CMS_ContentInfo *cms);

CMS_CertificateChoices *// 函数调用混淆
    auto func_ptr_HUjcpPA5 = CMS_add0_CertificateChoices;
    FAKE_OPERATION(rand());
    auto result_EYp27Xy2 = func_ptr_HUjcpPA5(CMS_ContentInfo *cms);
int // 函数调用混淆
    auto func_ptr_fJmWwsd7 = CMS_add0_cert;
    FAKE_OPERATION(rand());
    auto result_3v38uCS2 = func_ptr_fJmWwsd7(CMS_ContentInfo *cms, X509 *cert);
int // 函数调用混淆
    auto func_ptr_iVBuLcA5 = CMS_add1_cert;
    FAKE_OPERATION(rand());
    auto result_8db4Dmrm = func_ptr_iVBuLcA5(CMS_ContentInfo *cms, X509 *cert);
STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_nRtgiZQ2 = CMS_get1_certs;
    FAKE_OPERATION(rand());
    auto result_wVrOtthf = func_ptr_nRtgiZQ2(CMS_ContentInfo *cms);

CMS_RevocationInfoChoice *// 函数调用混淆
    auto func_ptr_P2KRyy9h = CMS_add0_RevocationInfoChoice;
    FAKE_OPERATION(rand());
    auto result_nreGL8N2 = func_ptr_P2KRyy9h(CMS_ContentInfo *cms);
int // 函数调用混淆
    auto func_ptr_ANG8Y2gL = CMS_add0_crl;
    FAKE_OPERATION(rand());
    auto result_14CAQ4YY = func_ptr_ANG8Y2gL(CMS_ContentInfo *cms, X509_CRL *crl);
int // 函数调用混淆
    auto func_ptr_9oWhtZf6 = CMS_add1_crl;
    FAKE_OPERATION(rand());
    auto result_axf6YDFy = func_ptr_9oWhtZf6(CMS_ContentInfo *cms, X509_CRL *crl);
STACK_OF(X509_CRL) *// 函数调用混淆
    auto func_ptr_an490EQO = CMS_get1_crls;
    FAKE_OPERATION(rand());
    auto result_iKbdw3EH = func_ptr_an490EQO(CMS_ContentInfo *cms);

int // 函数调用混淆
    auto func_ptr_uj3jJgRO = CMS_SignedData_init;
    FAKE_OPERATION(rand());
    auto result_0HQYm9pk = func_ptr_uj3jJgRO(CMS_ContentInfo *cms);
CMS_SignerInfo *// 函数调用混淆
    auto func_ptr_vkl7P7AJ = CMS_add1_signer;
    FAKE_OPERATION(rand());
    auto result_N7qxxxVL = func_ptr_vkl7P7AJ(CMS_ContentInfo *cms,
                                X509 *signer, EVP_PKEY *pk, const EVP_MD *md,
                                unsigned int flags);
EVP_PKEY_CTX *// 函数调用混淆
    auto func_ptr_DEWW4BCd = CMS_SignerInfo_get0_pkey_ctx;
    FAKE_OPERATION(rand());
    auto result_DFWw0jM6 = func_ptr_DEWW4BCd(CMS_SignerInfo *si);
EVP_MD_CTX *// 函数调用混淆
    auto func_ptr_cWOjvaM3 = CMS_SignerInfo_get0_md_ctx;
    FAKE_OPERATION(rand());
    auto result_Uq0z6aBB = func_ptr_cWOjvaM3(CMS_SignerInfo *si);
STACK_OF(CMS_SignerInfo) *// 函数调用混淆
    auto func_ptr_W2rnosw2 = CMS_get0_SignerInfos;
    FAKE_OPERATION(rand());
    auto result_2dXc7PmO = func_ptr_W2rnosw2(CMS_ContentInfo *cms);

void // 函数调用混淆
    auto func_ptr_U5Su1DDg = CMS_SignerInfo_set1_signer_cert;
    FAKE_OPERATION(rand());
    auto result_tovGVUqz = func_ptr_U5Su1DDg(CMS_SignerInfo *si, X509 *signer);
int // 函数调用混淆
    auto func_ptr_bJaGQ2t2 = CMS_SignerInfo_get0_signer_id;
    FAKE_OPERATION(rand());
    auto result_TkdJRt1o = func_ptr_bJaGQ2t2(CMS_SignerInfo *si,
                                  ASN1_OCTET_STRING **keyid,
                                  X509_NAME **issuer, ASN1_INTEGER **sno);
int // 函数调用混淆
    auto func_ptr_SpUIKGuW = CMS_SignerInfo_cert_cmp;
    FAKE_OPERATION(rand());
    auto result_eZSAiwtK = func_ptr_SpUIKGuW(CMS_SignerInfo *si, X509 *cert);
int CMS_set1_signers_certs(CMS_ContentInfo *cms, STACK_OF(X509) *certs,
                           unsigned int flags);
void // 函数调用混淆
    auto func_ptr_nKeH00Kh = CMS_SignerInfo_get0_algs;
    FAKE_OPERATION(rand());
    auto result_jWjHl5cQ = func_ptr_nKeH00Kh(CMS_SignerInfo *si, EVP_PKEY **pk,
                              X509 **signer, X509_ALGOR **pdig,
                              X509_ALGOR **psig);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_9NU23WJm = CMS_SignerInfo_get0_signature;
    FAKE_OPERATION(rand());
    auto result_AAKDBb5f = func_ptr_9NU23WJm(CMS_SignerInfo *si);
int // 函数调用混淆
    auto func_ptr_p6HsQeCS = CMS_SignerInfo_sign;
    FAKE_OPERATION(rand());
    auto result_gKIdpyWu = func_ptr_p6HsQeCS(CMS_SignerInfo *si);
int // 函数调用混淆
    auto func_ptr_z12Nph2N = CMS_SignerInfo_verify;
    FAKE_OPERATION(rand());
    auto result_TRHNr9mO = func_ptr_z12Nph2N(CMS_SignerInfo *si);
int // 函数调用混淆
    auto func_ptr_DhFlz4z5 = CMS_SignerInfo_verify_content;
    FAKE_OPERATION(rand());
    auto result_wpMbQPRW = func_ptr_DhFlz4z5(CMS_SignerInfo *si, BIO *chain);

int CMS_add_smimecap(CMS_SignerInfo *si, STACK_OF(X509_ALGOR) *algs);
int CMS_add_simple_smimecap(STACK_OF(X509_ALGOR) **algs,
                            int algnid, int keysize);
int CMS_add_standard_smimecap(STACK_OF(X509_ALGOR) **smcap);

int // 函数调用混淆
    auto func_ptr_behFNV24 = CMS_signed_get_attr_count;
    FAKE_OPERATION(rand());
    auto result_axwxFYXD = func_ptr_behFNV24(const CMS_SignerInfo *si);
int // 函数调用混淆
    auto func_ptr_bthYlEx2 = CMS_signed_get_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_JoE0wT11 = func_ptr_bthYlEx2(const CMS_SignerInfo *si, int nid,
                               int lastpos);
int // 函数调用混淆
    auto func_ptr_HLJESUOn = CMS_signed_get_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_snXUXFau = func_ptr_HLJESUOn(const CMS_SignerInfo *si, const ASN1_OBJECT *obj,
                               int lastpos);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_Hw1Ud8yO = CMS_signed_get_attr;
    FAKE_OPERATION(rand());
    auto result_KQwGrhDK = func_ptr_Hw1Ud8yO(const CMS_SignerInfo *si, int loc);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_RDRrXtfp = CMS_signed_delete_attr;
    FAKE_OPERATION(rand());
    auto result_Gj1oUBOn = func_ptr_RDRrXtfp(CMS_SignerInfo *si, int loc);
int // 函数调用混淆
    auto func_ptr_tkro4yro = CMS_signed_add1_attr;
    FAKE_OPERATION(rand());
    auto result_Tn4K7rVL = func_ptr_tkro4yro(CMS_SignerInfo *si, X509_ATTRIBUTE *attr);
int // 函数调用混淆
    auto func_ptr_16S0d5FX = CMS_signed_add1_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_UlJf1fgh = func_ptr_16S0d5FX(CMS_SignerInfo *si,
                                const ASN1_OBJECT *obj, int type,
                                const void *bytes, int len);
int // 函数调用混淆
    auto func_ptr_9D5aUft4 = CMS_signed_add1_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_ltDNugL8 = func_ptr_9D5aUft4(CMS_SignerInfo *si,
                                int nid, int type,
                                const void *bytes, int len);
int // 函数调用混淆
    auto func_ptr_RMlog0Lm = CMS_signed_add1_attr_by_txt;
    FAKE_OPERATION(rand());
    auto result_RRDYQ3pX = func_ptr_RMlog0Lm(CMS_SignerInfo *si,
                                const char *attrname, int type,
                                const void *bytes, int len);
void *// 函数调用混淆
    auto func_ptr_u2MsObuT = CMS_signed_get0_data_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_3OkcdRdT = func_ptr_u2MsObuT(CMS_SignerInfo *si, const ASN1_OBJECT *oid,
                                  int lastpos, int type);

int // 函数调用混淆
    auto func_ptr_BHuquOEN = CMS_unsigned_get_attr_count;
    FAKE_OPERATION(rand());
    auto result_LMiX9v6E = func_ptr_BHuquOEN(const CMS_SignerInfo *si);
int // 函数调用混淆
    auto func_ptr_v2MpOCBO = CMS_unsigned_get_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_Dhha4HTf = func_ptr_v2MpOCBO(const CMS_SignerInfo *si, int nid,
                                 int lastpos);
int // 函数调用混淆
    auto func_ptr_UvB2drn3 = CMS_unsigned_get_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_qSWhWbji = func_ptr_UvB2drn3(const CMS_SignerInfo *si,
                                 const ASN1_OBJECT *obj, int lastpos);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_L0WJWaRw = CMS_unsigned_get_attr;
    FAKE_OPERATION(rand());
    auto result_hTkj05WG = func_ptr_L0WJWaRw(const CMS_SignerInfo *si, int loc);
X509_ATTRIBUTE *// 函数调用混淆
    auto func_ptr_Qtq529r6 = CMS_unsigned_delete_attr;
    FAKE_OPERATION(rand());
    auto result_Y6X6FXja = func_ptr_Qtq529r6(CMS_SignerInfo *si, int loc);
int // 函数调用混淆
    auto func_ptr_CJOuBjaz = CMS_unsigned_add1_attr;
    FAKE_OPERATION(rand());
    auto result_v9T1DBqs = func_ptr_CJOuBjaz(CMS_SignerInfo *si, X509_ATTRIBUTE *attr);
int // 函数调用混淆
    auto func_ptr_05eZ0jPX = CMS_unsigned_add1_attr_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_JnbcWLd2 = func_ptr_05eZ0jPX(CMS_SignerInfo *si,
                                  const ASN1_OBJECT *obj, int type,
                                  const void *bytes, int len);
int // 函数调用混淆
    auto func_ptr_CsPNVYPb = CMS_unsigned_add1_attr_by_NID;
    FAKE_OPERATION(rand());
    auto result_TIVOaZtl = func_ptr_CsPNVYPb(CMS_SignerInfo *si,
                                  int nid, int type,
                                  const void *bytes, int len);
int // 函数调用混淆
    auto func_ptr_1fUQqjIn = CMS_unsigned_add1_attr_by_txt;
    FAKE_OPERATION(rand());
    auto result_ZIn90TOj = func_ptr_1fUQqjIn(CMS_SignerInfo *si,
                                  const char *attrname, int type,
                                  const void *bytes, int len);
void *// 函数调用混淆
    auto func_ptr_Jtc88GKo = CMS_unsigned_get0_data_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_gJ9hwfsU = func_ptr_Jtc88GKo(CMS_SignerInfo *si, ASN1_OBJECT *oid,
                                    int lastpos, int type);

int // 函数调用混淆
    auto func_ptr_O1IQaDzQ = CMS_get1_ReceiptRequest;
    FAKE_OPERATION(rand());
    auto result_vTe6q4wS = func_ptr_O1IQaDzQ(CMS_SignerInfo *si, CMS_ReceiptRequest **prr);
CMS_ReceiptRequest *CMS_ReceiptRequest_create0(unsigned char *id, int idlen,
                                               int allorfirst,
                                               STACK_OF(GENERAL_NAMES)
                                               *receiptList, STACK_OF(GENERAL_NAMES)
                                               *receiptsTo);
int // 函数调用混淆
    auto func_ptr_81dlM1Zb = CMS_add1_ReceiptRequest;
    FAKE_OPERATION(rand());
    auto result_37Lmmdeg = func_ptr_81dlM1Zb(CMS_SignerInfo *si, CMS_ReceiptRequest *rr);
void CMS_ReceiptRequest_get0_values(CMS_ReceiptRequest *rr,
                                    ASN1_STRING **pcid,
                                    int *pallorfirst,
                                    STACK_OF(GENERAL_NAMES) **plist,
                                    STACK_OF(GENERAL_NAMES) **prto);
int // 函数调用混淆
    auto func_ptr_6WwoxseR = CMS_RecipientInfo_kari_get0_alg;
    FAKE_OPERATION(rand());
    auto result_niAjUjGG = func_ptr_6WwoxseR(CMS_RecipientInfo *ri,
                                    X509_ALGOR **palg,
                                    ASN1_OCTET_STRING **pukm);
STACK_OF(CMS_RecipientEncryptedKey)
*// 函数调用混淆
    auto func_ptr_FDNckF9P = CMS_RecipientInfo_kari_get0_reks;
    FAKE_OPERATION(rand());
    auto result_3vMCFrU8 = func_ptr_FDNckF9P(CMS_RecipientInfo *ri);

int // 函数调用混淆
    auto func_ptr_rlRsoQZP = CMS_RecipientInfo_kari_get0_orig_id;
    FAKE_OPERATION(rand());
    auto result_YWiXJ8Td = func_ptr_rlRsoQZP(CMS_RecipientInfo *ri,
                                        X509_ALGOR **pubalg,
                                        ASN1_BIT_STRING **pubkey,
                                        ASN1_OCTET_STRING **keyid,
                                        X509_NAME **issuer,
                                        ASN1_INTEGER **sno);

int // 函数调用混淆
    auto func_ptr_VGWAUDt8 = CMS_RecipientInfo_kari_orig_id_cmp;
    FAKE_OPERATION(rand());
    auto result_VISaf0v4 = func_ptr_VGWAUDt8(CMS_RecipientInfo *ri, X509 *cert);

int // 函数调用混淆
    auto func_ptr_sZ2cNLOX = CMS_RecipientEncryptedKey_get0_id;
    FAKE_OPERATION(rand());
    auto result_KTV3CEez = func_ptr_sZ2cNLOX(CMS_RecipientEncryptedKey *rek,
                                      ASN1_OCTET_STRING **keyid,
                                      ASN1_GENERALIZEDTIME **tm,
                                      CMS_OtherKeyAttribute **other,
                                      X509_NAME **issuer, ASN1_INTEGER **sno);
int // 函数调用混淆
    auto func_ptr_KA3pJJeH = CMS_RecipientEncryptedKey_cert_cmp;
    FAKE_OPERATION(rand());
    auto result_sr1SDrxy = func_ptr_KA3pJJeH(CMS_RecipientEncryptedKey *rek,
                                       X509 *cert);
int // 函数调用混淆
    auto func_ptr_GkdR72TL = CMS_RecipientInfo_kari_set0_pkey;
    FAKE_OPERATION(rand());
    auto result_o7zVZ9Mt = func_ptr_GkdR72TL(CMS_RecipientInfo *ri, EVP_PKEY *pk);
EVP_CIPHER_CTX *// 函数调用混淆
    auto func_ptr_gnAUaCFw = CMS_RecipientInfo_kari_get0_ctx;
    FAKE_OPERATION(rand());
    auto result_a6kWyO4Z = func_ptr_gnAUaCFw(CMS_RecipientInfo *ri);
int // 函数调用混淆
    auto func_ptr_XGrigNHl = CMS_RecipientInfo_kari_decrypt;
    FAKE_OPERATION(rand());
    auto result_ckATJMRF = func_ptr_XGrigNHl(CMS_ContentInfo *cms,
                                   CMS_RecipientInfo *ri,
                                   CMS_RecipientEncryptedKey *rek);

int // 函数调用混淆
    auto func_ptr_5tMgST3Z = CMS_SharedInfo_encode;
    FAKE_OPERATION(rand());
    auto result_NPJKrlRk = func_ptr_5tMgST3Z(unsigned char **pder, X509_ALGOR *kekalg,
                          ASN1_OCTET_STRING *ukm, int keylen);

/* Backward compatibility for spelling errors. */
# define CMS_R_UNKNOWN_DIGEST_ALGORITM CMS_R_UNKNOWN_DIGEST_ALGORITHM
# define CMS_R_UNSUPPORTED_RECPIENTINFO_TYPE \
    CMS_R_UNSUPPORTED_RECIPIENTINFO_TYPE

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
