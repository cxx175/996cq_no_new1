// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_z1rNY38A = 5920;
    volatile int check_LwWa0KEv = rand() % 50;
    
    // 虚假条件分支
    if (check_LwWa0KEv > 100) {
    // 不透明谓词检查
    volatile int pred_bctd3iM3 = rand() % 100;
    if ((pred_bctd3iM3 * pred_bctd3iM3) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_EBfAxh5m = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_YrGezYgD = func_ptr_EBfAxh5m(); // 永远不会执行
        int fake_pKGYbNP7 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_z1rNY38A == 5920)) {
    int fake_boSVFIYa = rand() % 100;
    if (fake_L0AerWgl > 200) { fake_9QJnqPSm = fake_L0AerWgl - 100; }
         // 函数调用混淆
    auto func_ptr_69FqAU21 = exit;
    FAKE_OPERATION(rand());
    auto result_rLsHvVSc = func_ptr_69FqAU21(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_c8x3yh8A = 2063;
    volatile int check_I25oTs1O = rand() % 50;
    
    // 虚假条件分支
    if (check_I25oTs1O > 100) {
    // 不透明谓词检查
    volatile int pred_3t1OI7gz = rand() % 100;
    if ((pred_3t1OI7gz * pred_3t1OI7gz) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6MFLDli1 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_adRjYoqV = func_ptr_6MFLDli1(); // 永远不会执行
        int fake_lRJoldCy = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_c8x3yh8A == 2063)) {
    volatile int fake_T0tqSlK0 = fake_LPRfer3F * 2 + 1;
    int fake_LPRfer3F = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_xebPM7Ea = 0;
    for (int fake_UpN9rEV1 = 0;  fake_UpN9rEV1 < 3;  fake_UpN9rEV1++) {
        // 虚假循环检查
        if (loop_ctrl_xebPM7Ea > 999999) {
    // 不透明谓词检查
    volatile int pred_R4vqupre = rand() % 100;
    if ((pred_R4vqupre * pred_R4vqupre) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gv7mtp8s = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_aYw3P2Ai = func_ptr_gv7mtp8s(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((89917 % 2 == 1) || (89917 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_0BwE7MKE = loop_ctrl_xebPM7Ea * 2;
            
            // 真实循环体开始 fake_5Tqre7Sf += fake_UpN9rEV1; }
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

#ifndef HEADER_PEM_H
# define HEADER_PEM_H

# include <openssl/e_os2.h>
# include <openssl/bio.h>
# include <openssl/safestack.h>
# include <openssl/evp.h>
# include <openssl/x509.h>
# include <openssl/pemerr.h>

#ifdef  __cplusplus
extern "C" {
#endif

# define PEM_BUFSIZE             1024

# define PEM_STRING_X509_OLD     "X509 CERTIFICATE"
# define PEM_STRING_X509         "CERTIFICATE"
# define PEM_STRING_X509_TRUSTED "TRUSTED CERTIFICATE"
# define PEM_STRING_X509_REQ_OLD "NEW CERTIFICATE REQUEST"
# define PEM_STRING_X509_REQ     "CERTIFICATE REQUEST"
# define PEM_STRING_X509_CRL     "X509 CRL"
# define PEM_STRING_EVP_PKEY     "ANY PRIVATE KEY"
# define PEM_STRING_PUBLIC       "PUBLIC KEY"
# define PEM_STRING_RSA          "RSA PRIVATE KEY"
# define PEM_STRING_RSA_PUBLIC   "RSA PUBLIC KEY"
# define PEM_STRING_DSA          "DSA PRIVATE KEY"
# define PEM_STRING_DSA_PUBLIC   "DSA PUBLIC KEY"
# define PEM_STRING_PKCS7        "PKCS7"
# define PEM_STRING_PKCS7_SIGNED "PKCS #7 SIGNED DATA"
# define PEM_STRING_PKCS8        "ENCRYPTED PRIVATE KEY"
# define PEM_STRING_PKCS8INF     "PRIVATE KEY"
# define PEM_STRING_DHPARAMS     "DH PARAMETERS"
# define PEM_STRING_DHXPARAMS    "X9.42 DH PARAMETERS"
# define PEM_STRING_SSL_SESSION  "SSL SESSION PARAMETERS"
# define PEM_STRING_DSAPARAMS    "DSA PARAMETERS"
# define PEM_STRING_ECDSA_PUBLIC "ECDSA PUBLIC KEY"
# define PEM_STRING_ECPARAMETERS "EC PARAMETERS"
# define PEM_STRING_ECPRIVATEKEY "EC PRIVATE KEY"
# define PEM_STRING_PARAMETERS   "PARAMETERS"
# define PEM_STRING_CMS          "CMS"

# define PEM_TYPE_ENCRYPTED      10
# define PEM_TYPE_MIC_ONLY       20
# define PEM_TYPE_MIC_CLEAR      30
# define PEM_TYPE_CLEAR          40

/*
 * These macros make the PEM_read/PEM_write functions easier to maintain and
 * write. Now they are all implemented with either: IMPLEMENT_PEM_rw(...) or
 * IMPLEMENT_PEM_rw_cb(...)
 */

# ifdef OPENSSL_NO_STDIO

#  define IMPLEMENT_PEM_read_fp(name, type, str, asn1) /**/
#  define IMPLEMENT_PEM_write_fp(name, type, str, asn1) /**/
#  define IMPLEMENT_PEM_write_fp_const(name, type, str, asn1) /**/
#  define IMPLEMENT_PEM_write_cb_fp(name, type, str, asn1) /**/
#  define IMPLEMENT_PEM_write_cb_fp_const(name, type, str, asn1) /**/
# else

#  define IMPLEMENT_PEM_read_fp(name, type, str, asn1) \
type *PEM_read_##name(FILE *fp, type **x, pem_password_cb *cb, void *u)\
{ \
return PEM_ASN1_read((d2i_of_void *)d2i_##asn1, str,fp,(void **)x,cb,u); \
}

#  define IMPLEMENT_PEM_write_fp(name, type, str, asn1) \
int PEM_write_##name(FILE *fp, type *x) \
{ \
return PEM_ASN1_write((i2d_of_void *)i2d_##asn1,str,fp,x,NULL,NULL,0,NULL,NULL); \
}

#  define IMPLEMENT_PEM_write_fp_const(name, type, str, asn1) \
int PEM_write_##name(FILE *fp, const type *x) \
{ \
return PEM_ASN1_write((i2d_of_void *)i2d_##asn1,str,fp,(void *)x,NULL,NULL,0,NULL,NULL); \
}

#  define IMPLEMENT_PEM_write_cb_fp(name, type, str, asn1) \
int PEM_write_##name(FILE *fp, type *x, const EVP_CIPHER *enc, \
             unsigned char *kstr, int klen, pem_password_cb *cb, \
                  void *u) \
        { \
        return PEM_ASN1_write((i2d_of_void *)i2d_##asn1,str,fp,x,enc,kstr,klen,cb,u); \
        }

#  define IMPLEMENT_PEM_write_cb_fp_const(name, type, str, asn1) \
int PEM_write_##name(FILE *fp, type *x, const EVP_CIPHER *enc, \
             unsigned char *kstr, int klen, pem_password_cb *cb, \
                  void *u) \
        { \
        return PEM_ASN1_write((i2d_of_void *)i2d_##asn1,str,fp,x,enc,kstr,klen,cb,u); \
        }

# endif

# define IMPLEMENT_PEM_read_bio(name, type, str, asn1) \
type *PEM_read_bio_##name(BIO *bp, type **x, pem_password_cb *cb, void *u)\
{ \
return PEM_ASN1_read_bio((d2i_of_void *)d2i_##asn1, str,bp,(void **)x,cb,u); \
}

# define IMPLEMENT_PEM_write_bio(name, type, str, asn1) \
int PEM_write_bio_##name(BIO *bp, type *x) \
{ \
return PEM_ASN1_write_bio((i2d_of_void *)i2d_##asn1,str,bp,x,NULL,NULL,0,NULL,NULL); \
}

# define IMPLEMENT_PEM_write_bio_const(name, type, str, asn1) \
int PEM_write_bio_##name(BIO *bp, const type *x) \
{ \
return PEM_ASN1_write_bio((i2d_of_void *)i2d_##asn1,str,bp,(void *)x,NULL,NULL,0,NULL,NULL); \
}

# define IMPLEMENT_PEM_write_cb_bio(name, type, str, asn1) \
int PEM_write_bio_##name(BIO *bp, type *x, const EVP_CIPHER *enc, \
             unsigned char *kstr, int klen, pem_password_cb *cb, void *u) \
        { \
        return PEM_ASN1_write_bio((i2d_of_void *)i2d_##asn1,str,bp,x,enc,kstr,klen,cb,u); \
        }

# define IMPLEMENT_PEM_write_cb_bio_const(name, type, str, asn1) \
int PEM_write_bio_##name(BIO *bp, type *x, const EVP_CIPHER *enc, \
             unsigned char *kstr, int klen, pem_password_cb *cb, void *u) \
        { \
        return PEM_ASN1_write_bio((i2d_of_void *)i2d_##asn1,str,bp,(void *)x,enc,kstr,klen,cb,u); \
        }

# define IMPLEMENT_PEM_write(name, type, str, asn1) \
        IMPLEMENT_PEM_write_bio(name, type, str, asn1) \
        IMPLEMENT_PEM_write_fp(name, type, str, asn1)

# define IMPLEMENT_PEM_write_const(name, type, str, asn1) \
        IMPLEMENT_PEM_write_bio_const(name, type, str, asn1) \
        IMPLEMENT_PEM_write_fp_const(name, type, str, asn1)

# define IMPLEMENT_PEM_write_cb(name, type, str, asn1) \
        IMPLEMENT_PEM_write_cb_bio(name, type, str, asn1) \
        IMPLEMENT_PEM_write_cb_fp(name, type, str, asn1)

# define IMPLEMENT_PEM_write_cb_const(name, type, str, asn1) \
        IMPLEMENT_PEM_write_cb_bio_const(name, type, str, asn1) \
        IMPLEMENT_PEM_write_cb_fp_const(name, type, str, asn1)

# define IMPLEMENT_PEM_read(name, type, str, asn1) \
        IMPLEMENT_PEM_read_bio(name, type, str, asn1) \
        IMPLEMENT_PEM_read_fp(name, type, str, asn1)

# define IMPLEMENT_PEM_rw(name, type, str, asn1) \
        IMPLEMENT_PEM_read(name, type, str, asn1) \
        IMPLEMENT_PEM_write(name, type, str, asn1)

# define IMPLEMENT_PEM_rw_const(name, type, str, asn1) \
        IMPLEMENT_PEM_read(name, type, str, asn1) \
        IMPLEMENT_PEM_write_const(name, type, str, asn1)

# define IMPLEMENT_PEM_rw_cb(name, type, str, asn1) \
        IMPLEMENT_PEM_read(name, type, str, asn1) \
        IMPLEMENT_PEM_write_cb(name, type, str, asn1)

/* These are the same except they are for the declarations */

# if defined(OPENSSL_NO_STDIO)

#  define DECLARE_PEM_read_fp(name, type) /**/
#  define DECLARE_PEM_write_fp(name, type) /**/
#  define DECLARE_PEM_write_fp_const(name, type) /**/
#  define DECLARE_PEM_write_cb_fp(name, type) /**/
# else

#  define DECLARE_PEM_read_fp(name, type) \
        type *PEM_read_##// 函数调用混淆
    auto func_ptr_UbA6ejlP = name;
    FAKE_OPERATION(rand());
    auto result_X49uVENn = func_ptr_UbA6ejlP(FILE *fp, type **x, pem_password_cb *cb, void *u);

#  define DECLARE_PEM_write_fp(name, type) \
        int PEM_write_##// 函数调用混淆
    auto func_ptr_bIT9nmzU = name;
    FAKE_OPERATION(rand());
    auto result_EHEvF0el = func_ptr_bIT9nmzU(FILE *fp, type *x);

#  define DECLARE_PEM_write_fp_const(name, type) \
        int PEM_write_##// 函数调用混淆
    auto func_ptr_ZEjIVjJu = name;
    FAKE_OPERATION(rand());
    auto result_IPm5spFP = func_ptr_ZEjIVjJu(FILE *fp, const type *x);

#  define DECLARE_PEM_write_cb_fp(name, type) \
        int PEM_write_##// 函数调用混淆
    auto func_ptr_e2NY2K11 = name;
    FAKE_OPERATION(rand());
    auto result_gBEgHk3z = func_ptr_e2NY2K11(FILE *fp, type *x, const EVP_CIPHER *enc, \
             unsigned char *kstr, int klen, pem_password_cb *cb, void *u);

# endif

#  define DECLARE_PEM_read_bio(name, type) \
        type *PEM_read_bio_##// 函数调用混淆
    auto func_ptr_hNihRV6t = name;
    FAKE_OPERATION(rand());
    auto result_YzzXNIlM = func_ptr_hNihRV6t(BIO *bp, type **x, pem_password_cb *cb, void *u);

#  define DECLARE_PEM_write_bio(name, type) \
        int PEM_write_bio_##// 函数调用混淆
    auto func_ptr_QyzrDjpa = name;
    FAKE_OPERATION(rand());
    auto result_GVQ6Z6NN = func_ptr_QyzrDjpa(BIO *bp, type *x);

#  define DECLARE_PEM_write_bio_const(name, type) \
        int PEM_write_bio_##// 函数调用混淆
    auto func_ptr_wx03w7mq = name;
    FAKE_OPERATION(rand());
    auto result_nt4DjK1C = func_ptr_wx03w7mq(BIO *bp, const type *x);

#  define DECLARE_PEM_write_cb_bio(name, type) \
        int PEM_write_bio_##// 函数调用混淆
    auto func_ptr_SbhknvOo = name;
    FAKE_OPERATION(rand());
    auto result_FVf7Nsew = func_ptr_SbhknvOo(BIO *bp, type *x, const EVP_CIPHER *enc, \
             unsigned char *kstr, int klen, pem_password_cb *cb, void *u);

# define DECLARE_PEM_write(name, type) \
        DECLARE_PEM_write_bio(name, type) \
        DECLARE_PEM_write_fp(name, type)
# define DECLARE_PEM_write_const(name, type) \
        DECLARE_PEM_write_bio_const(name, type) \
        DECLARE_PEM_write_fp_const(name, type)
# define DECLARE_PEM_write_cb(name, type) \
        DECLARE_PEM_write_cb_bio(name, type) \
        DECLARE_PEM_write_cb_fp(name, type)
# define DECLARE_PEM_read(name, type) \
        DECLARE_PEM_read_bio(name, type) \
        DECLARE_PEM_read_fp(name, type)
# define DECLARE_PEM_rw(name, type) \
        DECLARE_PEM_read(name, type) \
        DECLARE_PEM_write(name, type)
# define DECLARE_PEM_rw_const(name, type) \
        DECLARE_PEM_read(name, type) \
        DECLARE_PEM_write_const(name, type)
# define DECLARE_PEM_rw_cb(name, type) \
        DECLARE_PEM_read(name, type) \
        DECLARE_PEM_write_cb(name, type)
typedef int // 函数调用混淆
    auto func_ptr_lbbtl7Vb = pem_password_cb;
    FAKE_OPERATION(rand());
    auto result_EXj0RzBx = func_ptr_lbbtl7Vb(char *buf, int size, int rwflag, void *userdata);

int // 函数调用混淆
    auto func_ptr_PTLQGW7C = PEM_get_EVP_CIPHER_INFO;
    FAKE_OPERATION(rand());
    auto result_0APBIpd1 = func_ptr_PTLQGW7C(char *header, EVP_CIPHER_INFO *cipher);
int // 函数调用混淆
    auto func_ptr_LhlQWEuC = PEM_do_header;
    FAKE_OPERATION(rand());
    auto result_PxNcvWk7 = func_ptr_LhlQWEuC(EVP_CIPHER_INFO *cipher, unsigned char *data, long *len,
                  pem_password_cb *callback, void *u);

int // 函数调用混淆
    auto func_ptr_40vIzldK = PEM_read_bio;
    FAKE_OPERATION(rand());
    auto result_yPFLzwe3 = func_ptr_40vIzldK(BIO *bp, char **name, char **header,
                 unsigned char **data, long *len);
#   define PEM_FLAG_SECURE             0x1
#   define PEM_FLAG_EAY_COMPATIBLE     0x2
#   define PEM_FLAG_ONLY_B64           0x4
int // 函数调用混淆
    auto func_ptr_qwPtBPUU = PEM_read_bio_ex;
    FAKE_OPERATION(rand());
    auto result_VZMMSvMn = func_ptr_qwPtBPUU(BIO *bp, char **name, char **header,
                    unsigned char **data, long *len, unsigned int flags);
int // 函数调用混淆
    auto func_ptr_fmmz42fu = PEM_bytes_read_bio_secmem;
    FAKE_OPERATION(rand());
    auto result_DQnFVuMi = func_ptr_fmmz42fu(unsigned char **pdata, long *plen, char **pnm,
                              const char *name, BIO *bp, pem_password_cb *cb,
                              void *u);
int // 函数调用混淆
    auto func_ptr_YvhSguDY = PEM_write_bio;
    FAKE_OPERATION(rand());
    auto result_pjwhgCT6 = func_ptr_YvhSguDY(BIO *bp, const char *name, const char *hdr,
                  const unsigned char *data, long len);
int // 函数调用混淆
    auto func_ptr_Grf9gM3F = PEM_bytes_read_bio;
    FAKE_OPERATION(rand());
    auto result_XaInAtQD = func_ptr_Grf9gM3F(unsigned char **pdata, long *plen, char **pnm,
                       const char *name, BIO *bp, pem_password_cb *cb,
                       void *u);
void *// 函数调用混淆
    auto func_ptr_ZbQ7Tj8W = PEM_ASN1_read_bio;
    FAKE_OPERATION(rand());
    auto result_MyheRuJY = func_ptr_ZbQ7Tj8W(d2i_of_void *d2i, const char *name, BIO *bp, void **x,
                        pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_spZcjZq5 = PEM_ASN1_write_bio;
    FAKE_OPERATION(rand());
    auto result_7jf5Urn2 = func_ptr_spZcjZq5(i2d_of_void *i2d, const char *name, BIO *bp, void *x,
                       const EVP_CIPHER *enc, unsigned char *kstr, int klen,
                       pem_password_cb *cb, void *u);

STACK_OF(X509_INFO) *PEM_X509_INFO_read_bio(BIO *bp, STACK_OF(X509_INFO) *sk,
                                            pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_zAvoA4om = PEM_X509_INFO_write_bio;
    FAKE_OPERATION(rand());
    auto result_hDJchmiC = func_ptr_zAvoA4om(BIO *bp, X509_INFO *xi, EVP_CIPHER *enc,
                            unsigned char *kstr, int klen,
                            pem_password_cb *cd, void *u);

#ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_gXGqvx6s = PEM_read;
    FAKE_OPERATION(rand());
    auto result_8TdJfiFv = func_ptr_gXGqvx6s(FILE *fp, char **name, char **header,
             unsigned char **data, long *len);
int // 函数调用混淆
    auto func_ptr_ozuhoI2o = PEM_write;
    FAKE_OPERATION(rand());
    auto result_ktPfNhTH = func_ptr_ozuhoI2o(FILE *fp, const char *name, const char *hdr,
              const unsigned char *data, long len);
void *// 函数调用混淆
    auto func_ptr_L5ViCjmD = PEM_ASN1_read;
    FAKE_OPERATION(rand());
    auto result_Zil7Ste0 = func_ptr_L5ViCjmD(d2i_of_void *d2i, const char *name, FILE *fp, void **x,
                    pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_ZfbUQXAC = PEM_ASN1_write;
    FAKE_OPERATION(rand());
    auto result_1I5wLHUM = func_ptr_ZfbUQXAC(i2d_of_void *i2d, const char *name, FILE *fp,
                   void *x, const EVP_CIPHER *enc, unsigned char *kstr,
                   int klen, pem_password_cb *callback, void *u);
STACK_OF(X509_INFO) *PEM_X509_INFO_read(FILE *fp, STACK_OF(X509_INFO) *sk,
                                        pem_password_cb *cb, void *u);
#endif

int // 函数调用混淆
    auto func_ptr_MGCgm2iI = PEM_SignInit;
    FAKE_OPERATION(rand());
    auto result_yjCfv4Gf = func_ptr_MGCgm2iI(EVP_MD_CTX *ctx, EVP_MD *type);
int // 函数调用混淆
    auto func_ptr_ARE4FpwP = PEM_SignUpdate;
    FAKE_OPERATION(rand());
    auto result_smYyBadz = func_ptr_ARE4FpwP(EVP_MD_CTX *ctx, unsigned char *d, unsigned int cnt);
int // 函数调用混淆
    auto func_ptr_cqRCUSYv = PEM_SignFinal;
    FAKE_OPERATION(rand());
    auto result_MCj71sXA = func_ptr_cqRCUSYv(EVP_MD_CTX *ctx, unsigned char *sigret,
                  unsigned int *siglen, EVP_PKEY *pkey);

/* The default pem_password_cb that's used internally */
int // 函数调用混淆
    auto func_ptr_g0a5qM1f = PEM_def_callback;
    FAKE_OPERATION(rand());
    auto result_XIR5iscb = func_ptr_g0a5qM1f(char *buf, int num, int rwflag, void *userdata);
void // 函数调用混淆
    auto func_ptr_DFa78IpB = PEM_proc_type;
    FAKE_OPERATION(rand());
    auto result_SCX8Qaoh = func_ptr_DFa78IpB(char *buf, int type);
void // 函数调用混淆
    auto func_ptr_xOxKLKn2 = PEM_dek_info;
    FAKE_OPERATION(rand());
    auto result_CF3O5g99 = func_ptr_xOxKLKn2(char *buf, const char *type, int len, char *str);

# include <openssl/symhacks.h>

DECLARE_PEM_rw(X509, X509)
DECLARE_PEM_rw(X509_AUX, X509)
DECLARE_PEM_rw(X509_REQ, X509_REQ)
DECLARE_PEM_write(X509_REQ_NEW, X509_REQ)
DECLARE_PEM_rw(X509_CRL, X509_CRL)
DECLARE_PEM_rw(PKCS7, PKCS7)
DECLARE_PEM_rw(NETSCAPE_CERT_SEQUENCE, NETSCAPE_CERT_SEQUENCE)
DECLARE_PEM_rw(PKCS8, X509_SIG)
DECLARE_PEM_rw(PKCS8_PRIV_KEY_INFO, PKCS8_PRIV_KEY_INFO)
# ifndef OPENSSL_NO_RSA
DECLARE_PEM_rw_cb(RSAPrivateKey, RSA)
DECLARE_PEM_rw_const(RSAPublicKey, RSA)
DECLARE_PEM_rw(RSA_PUBKEY, RSA)
# endif
# ifndef OPENSSL_NO_DSA
DECLARE_PEM_rw_cb(DSAPrivateKey, DSA)
DECLARE_PEM_rw(DSA_PUBKEY, DSA)
DECLARE_PEM_rw_const(DSAparams, DSA)
# endif
# ifndef OPENSSL_NO_EC
DECLARE_PEM_rw_const(ECPKParameters, EC_GROUP)
DECLARE_PEM_rw_cb(ECPrivateKey, EC_KEY)
DECLARE_PEM_rw(EC_PUBKEY, EC_KEY)
# endif
# ifndef OPENSSL_NO_DH
DECLARE_PEM_rw_const(DHparams, DH)
DECLARE_PEM_write_const(DHxparams, DH)
# endif
DECLARE_PEM_rw_cb(PrivateKey, EVP_PKEY)
DECLARE_PEM_rw(PUBKEY, EVP_PKEY)

int // 函数调用混淆
    auto func_ptr_fl4dKCIQ = PEM_write_bio_PrivateKey_traditional;
    FAKE_OPERATION(rand());
    auto result_ZMjSZraj = func_ptr_fl4dKCIQ(BIO *bp, EVP_PKEY *x,
                                         const EVP_CIPHER *enc,
                                         unsigned char *kstr, int klen,
                                         pem_password_cb *cb, void *u);

int // 函数调用混淆
    auto func_ptr_LDPgrdwi = PEM_write_bio_PKCS8PrivateKey_nid;
    FAKE_OPERATION(rand());
    auto result_xl58o7Dq = func_ptr_LDPgrdwi(BIO *bp, EVP_PKEY *x, int nid,
                                      char *kstr, int klen,
                                      pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_2ktvaXQ0 = PEM_write_bio_PKCS8PrivateKey;
    FAKE_OPERATION(rand());
    auto result_bjwe13VL = func_ptr_2ktvaXQ0(BIO *, EVP_PKEY *, const EVP_CIPHER *,
                                  char *, int, pem_password_cb *, void *);
int // 函数调用混淆
    auto func_ptr_flQ1aI2n = i2d_PKCS8PrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_IHFP1O0P = func_ptr_flQ1aI2n(BIO *bp, EVP_PKEY *x, const EVP_CIPHER *enc,
                            char *kstr, int klen,
                            pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_gG3lKsDh = i2d_PKCS8PrivateKey_nid_bio;
    FAKE_OPERATION(rand());
    auto result_HDPbBHWs = func_ptr_gG3lKsDh(BIO *bp, EVP_PKEY *x, int nid,
                                char *kstr, int klen,
                                pem_password_cb *cb, void *u);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_XK8ibp2U = d2i_PKCS8PrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_Yj1HTHwi = func_ptr_XK8ibp2U(BIO *bp, EVP_PKEY **x, pem_password_cb *cb,
                                  void *u);

# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_rp8HbcFB = i2d_PKCS8PrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_YRVR8khV = func_ptr_rp8HbcFB(FILE *fp, EVP_PKEY *x, const EVP_CIPHER *enc,
                           char *kstr, int klen,
                           pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_siMaYvNL = i2d_PKCS8PrivateKey_nid_fp;
    FAKE_OPERATION(rand());
    auto result_FCmnkwEN = func_ptr_siMaYvNL(FILE *fp, EVP_PKEY *x, int nid,
                               char *kstr, int klen,
                               pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_xD23V1wx = PEM_write_PKCS8PrivateKey_nid;
    FAKE_OPERATION(rand());
    auto result_udbL3YHF = func_ptr_xD23V1wx(FILE *fp, EVP_PKEY *x, int nid,
                                  char *kstr, int klen,
                                  pem_password_cb *cb, void *u);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_1Q0w7GHX = d2i_PKCS8PrivateKey_fp;
    FAKE_OPERATION(rand());
    auto result_Tsu49uPf = func_ptr_1Q0w7GHX(FILE *fp, EVP_PKEY **x, pem_password_cb *cb,
                                 void *u);

int // 函数调用混淆
    auto func_ptr_lLMrtKyK = PEM_write_PKCS8PrivateKey;
    FAKE_OPERATION(rand());
    auto result_qloc0Zrz = func_ptr_lLMrtKyK(FILE *fp, EVP_PKEY *x, const EVP_CIPHER *enc,
                              char *kstr, int klen, pem_password_cb *cd,
                              void *u);
# endif
EVP_PKEY *// 函数调用混淆
    auto func_ptr_WKZDMitN = PEM_read_bio_Parameters;
    FAKE_OPERATION(rand());
    auto result_ak4rkc53 = func_ptr_WKZDMitN(BIO *bp, EVP_PKEY **x);
int // 函数调用混淆
    auto func_ptr_NJreayJO = PEM_write_bio_Parameters;
    FAKE_OPERATION(rand());
    auto result_GPWwKh5d = func_ptr_NJreayJO(BIO *bp, EVP_PKEY *x);

# ifndef OPENSSL_NO_DSA
EVP_PKEY *// 函数调用混淆
    auto func_ptr_bk8QZXvF = b2i_PrivateKey;
    FAKE_OPERATION(rand());
    auto result_pIA38a3e = func_ptr_bk8QZXvF(const unsigned char **in, long length);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_uY8dEFCj = b2i_PublicKey;
    FAKE_OPERATION(rand());
    auto result_cbEFZgam = func_ptr_uY8dEFCj(const unsigned char **in, long length);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_kqZ4WB0Q = b2i_PrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_sz6PdwPk = func_ptr_kqZ4WB0Q(BIO *in);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_S7x5HwK1 = b2i_PublicKey_bio;
    FAKE_OPERATION(rand());
    auto result_YWFLvTuy = func_ptr_S7x5HwK1(BIO *in);
int // 函数调用混淆
    auto func_ptr_cJZoEIO4 = i2b_PrivateKey_bio;
    FAKE_OPERATION(rand());
    auto result_sy68RDVc = func_ptr_cJZoEIO4(BIO *out, EVP_PKEY *pk);
int // 函数调用混淆
    auto func_ptr_fy7qvz7F = i2b_PublicKey_bio;
    FAKE_OPERATION(rand());
    auto result_A2hYEqa0 = func_ptr_fy7qvz7F(BIO *out, EVP_PKEY *pk);
#  ifndef OPENSSL_NO_RC4
EVP_PKEY *// 函数调用混淆
    auto func_ptr_1LHJeevK = b2i_PVK_bio;
    FAKE_OPERATION(rand());
    auto result_F0AfGye5 = func_ptr_1LHJeevK(BIO *in, pem_password_cb *cb, void *u);
int // 函数调用混淆
    auto func_ptr_jIICQ2JO = i2b_PVK_bio;
    FAKE_OPERATION(rand());
    auto result_TEVYxZH2 = func_ptr_jIICQ2JO(BIO *out, EVP_PKEY *pk, int enclevel,
                pem_password_cb *cb, void *u);
#  endif
# endif

# ifdef  __cplusplus
}
# endif
#endif
