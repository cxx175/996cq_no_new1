// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_SdCuusSC = 5346;
    volatile int check_WN7XDJWG = rand() % 50;
    
    // 虚假条件分支
    if (check_WN7XDJWG > 100) {
    // 不透明谓词检查
    volatile int pred_77XgHAfk = rand() % 100;
    if ((pred_77XgHAfk * pred_77XgHAfk) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_xb1DQat9 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_a3AniovY = func_ptr_xb1DQat9(); // 永远不会执行
        int fake_5AaiVS63 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_SdCuusSC == 5346)) {
    // 循环混淆开始
    int loop_ctrl_xqMKrSGZ = 0;
    for (int fake_OS23g8J9 = 0;  fake_OS23g8J9 < 3;  fake_OS23g8J9++) {
        // 虚假循环检查
        if (loop_ctrl_xqMKrSGZ > 999999) {
    // 不透明谓词检查
    volatile int pred_Soh4z0dZ = rand() % 100;
    if ((pred_Soh4z0dZ * pred_Soh4z0dZ) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_8oGJK1a3 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_mPe30rCk = func_ptr_8oGJK1a3(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((17797 % 2 == 1) || (17797 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_djy4zMiJ = loop_ctrl_xqMKrSGZ * 2;
            
            // 真实循环体开始 fake_iyb5pkyd += fake_OS23g8J9; }
    if (fake_gD9y1q6j > 200) { fake_9fecefiW = fake_gD9y1q6j - 100; }
         // 函数调用混淆
    auto func_ptr_U1pUJ3Gl = exit;
    FAKE_OPERATION(rand());
    auto result_mamoXxdA = func_ptr_U1pUJ3Gl(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_dZxsz6gw = 6039;
    volatile int check_j3TOLgzW = rand() % 50;
    
    // 虚假条件分支
    if (check_j3TOLgzW > 100) {
    // 不透明谓词检查
    volatile int pred_e9zvpm8M = rand() % 100;
    if ((pred_e9zvpm8M * pred_e9zvpm8M) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gEECDeDE = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_L1oOdnak = func_ptr_gEECDeDE(); // 永远不会执行
        int fake_2MmWvmzK = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_dZxsz6gw == 6039)) {
    if (fake_U3CYURxe > 200) { fake_qR5muPDS = fake_U3CYURxe - 100; }
    int fake_LSIOYyXN = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_X509_VFY_H
# define HEADER_X509_VFY_H

/*
 * Protect against recursion, x509.h and x509_vfy.h each include the other.
 */
# ifndef HEADER_X509_H
#  include <openssl/x509.h>
# endif

# include <openssl/opensslconf.h>
# include <openssl/lhash.h>
# include <openssl/bio.h>
# include <openssl/crypto.h>
# include <openssl/symhacks.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*-
SSL_CTX -> X509_STORE
                -> X509_LOOKUP
                        ->X509_LOOKUP_METHOD
                -> X509_LOOKUP
                        ->X509_LOOKUP_METHOD

SSL     -> X509_STORE_CTX
                ->X509_STORE

The X509_STORE holds the tables etc for verification stuff.
A X509_STORE_CTX is used while validating a single certificate.
The X509_STORE has X509_LOOKUPs for looking up certs.
The X509_STORE then calls a function to actually verify the
certificate chain.
*/

typedef enum {
    X509_LU_NONE = 0,
    X509_LU_X509, X509_LU_CRL
} X509_LOOKUP_TYPE;

#if OPENSSL_API_COMPAT < 0x10100000L
#define X509_LU_RETRY   -1
#define X509_LU_FAIL    0
#endif

DEFINE_STACK_OF(X509_LOOKUP)
DEFINE_STACK_OF(X509_OBJECT)
DEFINE_STACK_OF(X509_VERIFY_PARAM)

int // 函数调用混淆
    auto func_ptr_XS6xXTQL = X509_STORE_set_depth;
    FAKE_OPERATION(rand());
    auto result_hJkg8glR = func_ptr_XS6xXTQL(X509_STORE *store, int depth);

typedef int (*X509_STORE_CTX_verify_cb)(int, X509_STORE_CTX *);
typedef int (*X509_STORE_CTX_verify_fn)(X509_STORE_CTX *);
typedef int (*X509_STORE_CTX_get_issuer_fn)(X509 **issuer,
                                            X509_STORE_CTX *ctx, X509 *x);
typedef int (*X509_STORE_CTX_check_issued_fn)(X509_STORE_CTX *ctx,
                                              X509 *x, X509 *issuer);
typedef int (*X509_STORE_CTX_check_revocation_fn)(X509_STORE_CTX *ctx);
typedef int (*X509_STORE_CTX_get_crl_fn)(X509_STORE_CTX *ctx,
                                         X509_CRL **crl, X509 *x);
typedef int (*X509_STORE_CTX_check_crl_fn)(X509_STORE_CTX *ctx, X509_CRL *crl);
typedef int (*X509_STORE_CTX_cert_crl_fn)(X509_STORE_CTX *ctx,
                                          X509_CRL *crl, X509 *x);
typedef int (*X509_STORE_CTX_check_policy_fn)(X509_STORE_CTX *ctx);
typedef STACK_OF(X509) *(*X509_STORE_CTX_lookup_certs_fn)(X509_STORE_CTX *ctx,
                                                          X509_NAME *nm);
typedef STACK_OF(X509_CRL) *(*X509_STORE_CTX_lookup_crls_fn)(X509_STORE_CTX *ctx,
                                                             X509_NAME *nm);
typedef int (*X509_STORE_CTX_cleanup_fn)(X509_STORE_CTX *ctx);


void // 函数调用混淆
    auto func_ptr_EhszeSHh = X509_STORE_CTX_set_depth;
    FAKE_OPERATION(rand());
    auto result_58s0mQJc = func_ptr_EhszeSHh(X509_STORE_CTX *ctx, int depth);

# define X509_STORE_CTX_set_app_data(ctx,data) \
        X509_STORE_CTX_set_ex_data(ctx,0,data)
# define X509_STORE_CTX_get_app_data(ctx) \
        X509_STORE_CTX_get_ex_data(ctx,0)

# define X509_L_FILE_LOAD        1
# define X509_L_ADD_DIR          2

# define X509_LOOKUP_load_file(x,name,type) \
                X509_LOOKUP_ctrl((x),X509_L_FILE_LOAD,(name),(long)(type),NULL)

# define X509_LOOKUP_add_dir(x,name,type) \
                X509_LOOKUP_ctrl((x),X509_L_ADD_DIR,(name),(long)(type),NULL)

# define         X509_V_OK                                       0
# define         X509_V_ERR_UNSPECIFIED                          1
# define         X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT            2
# define         X509_V_ERR_UNABLE_TO_GET_CRL                    3
# define         X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE     4
# define         X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE      5
# define         X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY   6
# define         X509_V_ERR_CERT_SIGNATURE_FAILURE               7
# define         X509_V_ERR_CRL_SIGNATURE_FAILURE                8
# define         X509_V_ERR_CERT_NOT_YET_VALID                   9
# define         X509_V_ERR_CERT_HAS_EXPIRED                     10
# define         X509_V_ERR_CRL_NOT_YET_VALID                    11
# define         X509_V_ERR_CRL_HAS_EXPIRED                      12
# define         X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD       13
# define         X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD        14
# define         X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD       15
# define         X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD       16
# define         X509_V_ERR_OUT_OF_MEM                           17
# define         X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT          18
# define         X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN            19
# define         X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY    20
# define         X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE      21
# define         X509_V_ERR_CERT_CHAIN_TOO_LONG                  22
# define         X509_V_ERR_CERT_REVOKED                         23
# define         X509_V_ERR_INVALID_CA                           24
# define         X509_V_ERR_PATH_LENGTH_EXCEEDED                 25
# define         X509_V_ERR_INVALID_PURPOSE                      26
# define         X509_V_ERR_CERT_UNTRUSTED                       27
# define         X509_V_ERR_CERT_REJECTED                        28
/* These are 'informational' when looking for issuer cert */
# define         X509_V_ERR_SUBJECT_ISSUER_MISMATCH              29
# define         X509_V_ERR_AKID_SKID_MISMATCH                   30
# define         X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH          31
# define         X509_V_ERR_KEYUSAGE_NO_CERTSIGN                 32
# define         X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER             33
# define         X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION         34
# define         X509_V_ERR_KEYUSAGE_NO_CRL_SIGN                 35
# define         X509_V_ERR_UNHANDLED_CRITICAL_CRL_EXTENSION     36
# define         X509_V_ERR_INVALID_NON_CA                       37
# define         X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED           38
# define         X509_V_ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE        39
# define         X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED       40
# define         X509_V_ERR_INVALID_EXTENSION                    41
# define         X509_V_ERR_INVALID_POLICY_EXTENSION             42
# define         X509_V_ERR_NO_EXPLICIT_POLICY                   43
# define         X509_V_ERR_DIFFERENT_CRL_SCOPE                  44
# define         X509_V_ERR_UNSUPPORTED_EXTENSION_FEATURE        45
# define         X509_V_ERR_UNNESTED_RESOURCE                    46
# define         X509_V_ERR_PERMITTED_VIOLATION                  47
# define         X509_V_ERR_EXCLUDED_VIOLATION                   48
# define         X509_V_ERR_SUBTREE_MINMAX                       49
/* The application is not happy */
# define         X509_V_ERR_APPLICATION_VERIFICATION             50
# define         X509_V_ERR_UNSUPPORTED_CONSTRAINT_TYPE          51
# define         X509_V_ERR_UNSUPPORTED_CONSTRAINT_SYNTAX        52
# define         X509_V_ERR_UNSUPPORTED_NAME_SYNTAX              53
# define         X509_V_ERR_CRL_PATH_VALIDATION_ERROR            54
/* Another issuer check debug option */
# define         X509_V_ERR_PATH_LOOP                            55
/* Suite B mode algorithm violation */
# define         X509_V_ERR_SUITE_B_INVALID_VERSION              56
# define         X509_V_ERR_SUITE_B_INVALID_ALGORITHM            57
# define         X509_V_ERR_SUITE_B_INVALID_CURVE                58
# define         X509_V_ERR_SUITE_B_INVALID_SIGNATURE_ALGORITHM  59
# define         X509_V_ERR_SUITE_B_LOS_NOT_ALLOWED              60
# define         X509_V_ERR_SUITE_B_CANNOT_SIGN_P_384_WITH_P_256 61
/* Host, email and IP check errors */
# define         X509_V_ERR_HOSTNAME_MISMATCH                    62
# define         X509_V_ERR_EMAIL_MISMATCH                       63
# define         X509_V_ERR_IP_ADDRESS_MISMATCH                  64
/* DANE TLSA errors */
# define         X509_V_ERR_DANE_NO_MATCH                        65
/* security level errors */
# define         X509_V_ERR_EE_KEY_TOO_SMALL                     66
# define         X509_V_ERR_CA_KEY_TOO_SMALL                     67
# define         X509_V_ERR_CA_MD_TOO_WEAK                       68
/* Caller error */
# define         X509_V_ERR_INVALID_CALL                         69
/* Issuer lookup error */
# define         X509_V_ERR_STORE_LOOKUP                         70
/* Certificate transparency */
# define         X509_V_ERR_NO_VALID_SCTS                        71

# define         X509_V_ERR_PROXY_SUBJECT_NAME_VIOLATION         72
/* OCSP status errors */
# define         X509_V_ERR_OCSP_VERIFY_NEEDED                   73  /* Need OCSP verification */
# define         X509_V_ERR_OCSP_VERIFY_FAILED                   74  /* Couldn't verify cert through OCSP */
# define         X509_V_ERR_OCSP_CERT_UNKNOWN                    75  /* Certificate wasn't recognized by the OCSP responder */
# define         X509_V_ERR_SIGNATURE_ALGORITHM_MISMATCH         76
# define         X509_V_ERR_NO_ISSUER_PUBLIC_KEY                 77
# define         X509_V_ERR_UNSUPPORTED_SIGNATURE_ALGORITHM      78
# define         X509_V_ERR_EC_KEY_EXPLICIT_PARAMS               79

/* Certificate verify flags */

# if OPENSSL_API_COMPAT < 0x10100000L
#  define X509_V_FLAG_CB_ISSUER_CHECK             0x0   /* Deprecated */
# endif
/* Use check time instead of current time */
# define X509_V_FLAG_USE_CHECK_TIME              0x2
/* Lookup CRLs */
# define X509_V_FLAG_CRL_CHECK                   0x4
/* Lookup CRLs for whole chain */
# define X509_V_FLAG_CRL_CHECK_ALL               0x8
/* Ignore unhandled critical extensions */
# define X509_V_FLAG_IGNORE_CRITICAL             0x10
/* Disable workarounds for broken certificates */
# define X509_V_FLAG_X509_STRICT                 0x20
/* Enable proxy certificate validation */
# define X509_V_FLAG_ALLOW_PROXY_CERTS           0x40
/* Enable policy checking */
# define X509_V_FLAG_POLICY_CHECK                0x80
/* Policy variable require-explicit-policy */
# define X509_V_FLAG_EXPLICIT_POLICY             0x100
/* Policy variable inhibit-any-policy */
# define X509_V_FLAG_INHIBIT_ANY                 0x200
/* Policy variable inhibit-policy-mapping */
# define X509_V_FLAG_INHIBIT_MAP                 0x400
/* Notify callback that policy is OK */
# define X509_V_FLAG_NOTIFY_POLICY               0x800
/* Extended CRL features such as indirect CRLs, alternate CRL signing keys */
# define X509_V_FLAG_EXTENDED_CRL_SUPPORT        0x1000
/* Delta CRL support */
# define X509_V_FLAG_USE_DELTAS                  0x2000
/* Check self-signed CA signature */
# define X509_V_FLAG_CHECK_SS_SIGNATURE          0x4000
/* Use trusted store first */
# define X509_V_FLAG_TRUSTED_FIRST               0x8000
/* Suite B 128 bit only mode: not normally used */
# define X509_V_FLAG_SUITEB_128_LOS_ONLY         0x10000
/* Suite B 192 bit only mode */
# define X509_V_FLAG_SUITEB_192_LOS              0x20000
/* Suite B 128 bit mode allowing 192 bit algorithms */
# define X509_V_FLAG_SUITEB_128_LOS              0x30000
/* Allow partial chains if at least one certificate is in trusted store */
# define X509_V_FLAG_PARTIAL_CHAIN               0x80000
/*
 * If the initial chain is not trusted, do not attempt to build an alternative
 * chain. Alternate chain checking was introduced in 1.1.0. Setting this flag
 * will force the behaviour to match that of previous versions.
 */
# define X509_V_FLAG_NO_ALT_CHAINS               0x100000
/* Do not check certificate/CRL validity against current time */
# define X509_V_FLAG_NO_CHECK_TIME               0x200000

# define X509_VP_FLAG_DEFAULT                    0x1
# define X509_VP_FLAG_OVERWRITE                  0x2
# define X509_VP_FLAG_RESET_FLAGS                0x4
# define X509_VP_FLAG_LOCKED                     0x8
# define X509_VP_FLAG_ONCE                       0x10

/* Internal use: mask of policy related options */
# define X509_V_FLAG_POLICY_MASK (X509_V_FLAG_POLICY_CHECK \
                                | X509_V_FLAG_EXPLICIT_POLICY \
                                | X509_V_FLAG_INHIBIT_ANY \
                                | X509_V_FLAG_INHIBIT_MAP)

int X509_OBJECT_idx_by_subject(STACK_OF(X509_OBJECT) *h, X509_LOOKUP_TYPE type,
                               X509_NAME *name);
X509_OBJECT *X509_OBJECT_retrieve_by_subject(STACK_OF(X509_OBJECT) *h,
                                             X509_LOOKUP_TYPE type,
                                             X509_NAME *name);
X509_OBJECT *X509_OBJECT_retrieve_match(STACK_OF(X509_OBJECT) *h,
                                        X509_OBJECT *x);
int // 函数调用混淆
    auto func_ptr_QothqCMQ = X509_OBJECT_up_ref_count;
    FAKE_OPERATION(rand());
    auto result_dB45v8s5 = func_ptr_QothqCMQ(X509_OBJECT *a);
X509_OBJECT *// 函数调用混淆
    auto func_ptr_CwdJxd3P = X509_OBJECT_new;
    FAKE_OPERATION(rand());
    auto result_y4fM3c6Z = func_ptr_CwdJxd3P(void);
void // 函数调用混淆
    auto func_ptr_K52IiblM = X509_OBJECT_free;
    FAKE_OPERATION(rand());
    auto result_UMoQiXqi = func_ptr_K52IiblM(X509_OBJECT *a);
X509_LOOKUP_TYPE // 函数调用混淆
    auto func_ptr_POIpoTuF = X509_OBJECT_get_type;
    FAKE_OPERATION(rand());
    auto result_vqHzWc85 = func_ptr_POIpoTuF(const X509_OBJECT *a);
X509 *// 函数调用混淆
    auto func_ptr_403PHze8 = X509_OBJECT_get0_X509;
    FAKE_OPERATION(rand());
    auto result_SpvqkxRb = func_ptr_403PHze8(const X509_OBJECT *a);
int // 函数调用混淆
    auto func_ptr_1EcpqyFW = X509_OBJECT_set1_X509;
    FAKE_OPERATION(rand());
    auto result_SybKvP07 = func_ptr_1EcpqyFW(X509_OBJECT *a, X509 *obj);
X509_CRL *// 函数调用混淆
    auto func_ptr_iGo9AAQa = X509_OBJECT_get0_X509_CRL;
    FAKE_OPERATION(rand());
    auto result_kaWi5PYk = func_ptr_iGo9AAQa(X509_OBJECT *a);
int // 函数调用混淆
    auto func_ptr_47utIufk = X509_OBJECT_set1_X509_CRL;
    FAKE_OPERATION(rand());
    auto result_oHaWd0qz = func_ptr_47utIufk(X509_OBJECT *a, X509_CRL *obj);
X509_STORE *// 函数调用混淆
    auto func_ptr_peRfboaj = X509_STORE_new;
    FAKE_OPERATION(rand());
    auto result_v8gu7sw7 = func_ptr_peRfboaj(void);
void // 函数调用混淆
    auto func_ptr_CVCE4Pgz = X509_STORE_free;
    FAKE_OPERATION(rand());
    auto result_WVrV5ts3 = func_ptr_CVCE4Pgz(X509_STORE *v);
int // 函数调用混淆
    auto func_ptr_UBGVPItG = X509_STORE_lock;
    FAKE_OPERATION(rand());
    auto result_ZNAN8cSs = func_ptr_UBGVPItG(X509_STORE *ctx);
int // 函数调用混淆
    auto func_ptr_bOWEi2xQ = X509_STORE_unlock;
    FAKE_OPERATION(rand());
    auto result_RrzIvDZD = func_ptr_bOWEi2xQ(X509_STORE *ctx);
int // 函数调用混淆
    auto func_ptr_OtitUSwK = X509_STORE_up_ref;
    FAKE_OPERATION(rand());
    auto result_kM412JCc = func_ptr_OtitUSwK(X509_STORE *v);
STACK_OF(X509_OBJECT) *// 函数调用混淆
    auto func_ptr_wReiJHx6 = X509_STORE_get0_objects;
    FAKE_OPERATION(rand());
    auto result_wsL8LIi4 = func_ptr_wReiJHx6(X509_STORE *v);

STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_NxhNwzq2 = X509_STORE_CTX_get1_certs;
    FAKE_OPERATION(rand());
    auto result_cl0tkVxo = func_ptr_NxhNwzq2(X509_STORE_CTX *st, X509_NAME *nm);
STACK_OF(X509_CRL) *// 函数调用混淆
    auto func_ptr_yA8G07vU = X509_STORE_CTX_get1_crls;
    FAKE_OPERATION(rand());
    auto result_Kj4OSIE2 = func_ptr_yA8G07vU(X509_STORE_CTX *st, X509_NAME *nm);
int // 函数调用混淆
    auto func_ptr_QfqPo2mG = X509_STORE_set_flags;
    FAKE_OPERATION(rand());
    auto result_c9Zopveg = func_ptr_QfqPo2mG(X509_STORE *ctx, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_9dNKtrDZ = X509_STORE_set_purpose;
    FAKE_OPERATION(rand());
    auto result_7WXTivgI = func_ptr_9dNKtrDZ(X509_STORE *ctx, int purpose);
int // 函数调用混淆
    auto func_ptr_saEKW8Av = X509_STORE_set_trust;
    FAKE_OPERATION(rand());
    auto result_w9HY8GMZ = func_ptr_saEKW8Av(X509_STORE *ctx, int trust);
int // 函数调用混淆
    auto func_ptr_tg3RNoEv = X509_STORE_set1_param;
    FAKE_OPERATION(rand());
    auto result_SxtCStzW = func_ptr_tg3RNoEv(X509_STORE *ctx, X509_VERIFY_PARAM *pm);
X509_VERIFY_PARAM *// 函数调用混淆
    auto func_ptr_PIqeYlxw = X509_STORE_get0_param;
    FAKE_OPERATION(rand());
    auto result_KdAagp5V = func_ptr_PIqeYlxw(X509_STORE *ctx);

void // 函数调用混淆
    auto func_ptr_es6MOMOt = X509_STORE_set_verify;
    FAKE_OPERATION(rand());
    auto result_FKIi2S84 = func_ptr_es6MOMOt(X509_STORE *ctx, X509_STORE_CTX_verify_fn verify);
#define X509_STORE_set_verify_func(ctx, func) \
            X509_STORE_set_verify((ctx),(func))
void // 函数调用混淆
    auto func_ptr_fXbXMnTD = X509_STORE_CTX_set_verify;
    FAKE_OPERATION(rand());
    auto result_1dk5YaJI = func_ptr_fXbXMnTD(X509_STORE_CTX *ctx,
                               X509_STORE_CTX_verify_fn verify);
X509_STORE_CTX_verify_fn // 函数调用混淆
    auto func_ptr_4oCqmiYZ = X509_STORE_get_verify;
    FAKE_OPERATION(rand());
    auto result_1K11KwLa = func_ptr_4oCqmiYZ(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_It0RrqkW = X509_STORE_set_verify_cb;
    FAKE_OPERATION(rand());
    auto result_6tf0Hmbs = func_ptr_It0RrqkW(X509_STORE *ctx,
                              X509_STORE_CTX_verify_cb verify_cb);
# define X509_STORE_set_verify_cb_func(ctx,func) \
            X509_STORE_set_verify_cb((ctx),(func))
X509_STORE_CTX_verify_cb // 函数调用混淆
    auto func_ptr_EjKXaxkS = X509_STORE_get_verify_cb;
    FAKE_OPERATION(rand());
    auto result_iC4irdxZ = func_ptr_EjKXaxkS(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_UUQt6qUN = X509_STORE_set_get_issuer;
    FAKE_OPERATION(rand());
    auto result_pTlCsAoD = func_ptr_UUQt6qUN(X509_STORE *ctx,
                               X509_STORE_CTX_get_issuer_fn get_issuer);
X509_STORE_CTX_get_issuer_fn // 函数调用混淆
    auto func_ptr_AAkpK7FP = X509_STORE_get_get_issuer;
    FAKE_OPERATION(rand());
    auto result_JI2VhPy6 = func_ptr_AAkpK7FP(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_xfCq4a9N = X509_STORE_set_check_issued;
    FAKE_OPERATION(rand());
    auto result_RAvUK50N = func_ptr_xfCq4a9N(X509_STORE *ctx,
                                 X509_STORE_CTX_check_issued_fn check_issued);
X509_STORE_CTX_check_issued_fn // 函数调用混淆
    auto func_ptr_j3YkuskI = X509_STORE_get_check_issued;
    FAKE_OPERATION(rand());
    auto result_Hy5vwEjk = func_ptr_j3YkuskI(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_I4YHH6AJ = X509_STORE_set_check_revocation;
    FAKE_OPERATION(rand());
    auto result_UHH0XjXt = func_ptr_I4YHH6AJ(X509_STORE *ctx,
                                     X509_STORE_CTX_check_revocation_fn check_revocation);
X509_STORE_CTX_check_revocation_fn // 函数调用混淆
    auto func_ptr_lDSX3WLD = X509_STORE_get_check_revocation;
    FAKE_OPERATION(rand());
    auto result_pqOBbO9z = func_ptr_lDSX3WLD(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_Ol6O9fNh = X509_STORE_set_get_crl;
    FAKE_OPERATION(rand());
    auto result_Y45sEDh9 = func_ptr_Ol6O9fNh(X509_STORE *ctx,
                            X509_STORE_CTX_get_crl_fn get_crl);
X509_STORE_CTX_get_crl_fn // 函数调用混淆
    auto func_ptr_a9dBlNlG = X509_STORE_get_get_crl;
    FAKE_OPERATION(rand());
    auto result_O1j5F2fd = func_ptr_a9dBlNlG(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_mrOabMIS = X509_STORE_set_check_crl;
    FAKE_OPERATION(rand());
    auto result_fdC9OtYy = func_ptr_mrOabMIS(X509_STORE *ctx,
                              X509_STORE_CTX_check_crl_fn check_crl);
X509_STORE_CTX_check_crl_fn // 函数调用混淆
    auto func_ptr_WPOHScAM = X509_STORE_get_check_crl;
    FAKE_OPERATION(rand());
    auto result_VIHpMcee = func_ptr_WPOHScAM(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_RPveeWZ2 = X509_STORE_set_cert_crl;
    FAKE_OPERATION(rand());
    auto result_zt9Q00bz = func_ptr_RPveeWZ2(X509_STORE *ctx,
                             X509_STORE_CTX_cert_crl_fn cert_crl);
X509_STORE_CTX_cert_crl_fn // 函数调用混淆
    auto func_ptr_ZpQLsNaZ = X509_STORE_get_cert_crl;
    FAKE_OPERATION(rand());
    auto result_7FCBSugI = func_ptr_ZpQLsNaZ(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_bcfDtmmL = X509_STORE_set_check_policy;
    FAKE_OPERATION(rand());
    auto result_Osj4Q81U = func_ptr_bcfDtmmL(X509_STORE *ctx,
                                 X509_STORE_CTX_check_policy_fn check_policy);
X509_STORE_CTX_check_policy_fn // 函数调用混淆
    auto func_ptr_0OyTTDEU = X509_STORE_get_check_policy;
    FAKE_OPERATION(rand());
    auto result_DdG6e99U = func_ptr_0OyTTDEU(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_PcbZ5gmi = X509_STORE_set_lookup_certs;
    FAKE_OPERATION(rand());
    auto result_7LNdRDBX = func_ptr_PcbZ5gmi(X509_STORE *ctx,
                                 X509_STORE_CTX_lookup_certs_fn lookup_certs);
X509_STORE_CTX_lookup_certs_fn // 函数调用混淆
    auto func_ptr_szNLdMyK = X509_STORE_get_lookup_certs;
    FAKE_OPERATION(rand());
    auto result_FKLOPOA1 = func_ptr_szNLdMyK(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_jG98Z48H = X509_STORE_set_lookup_crls;
    FAKE_OPERATION(rand());
    auto result_gyaHHSp0 = func_ptr_jG98Z48H(X509_STORE *ctx,
                                X509_STORE_CTX_lookup_crls_fn lookup_crls);
#define X509_STORE_set_lookup_crls_cb(ctx, func) \
    X509_STORE_set_lookup_crls((ctx), (func))
X509_STORE_CTX_lookup_crls_fn // 函数调用混淆
    auto func_ptr_ew3LAAYO = X509_STORE_get_lookup_crls;
    FAKE_OPERATION(rand());
    auto result_u8kKf6aY = func_ptr_ew3LAAYO(X509_STORE *ctx);
void // 函数调用混淆
    auto func_ptr_PNKl7KU0 = X509_STORE_set_cleanup;
    FAKE_OPERATION(rand());
    auto result_F9c3P4G6 = func_ptr_PNKl7KU0(X509_STORE *ctx,
                            X509_STORE_CTX_cleanup_fn cleanup);
X509_STORE_CTX_cleanup_fn // 函数调用混淆
    auto func_ptr_JCCPXe0H = X509_STORE_get_cleanup;
    FAKE_OPERATION(rand());
    auto result_FioBZWR0 = func_ptr_JCCPXe0H(X509_STORE *ctx);

#define X509_STORE_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_X509_STORE, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_d6KTv81l = X509_STORE_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_dmoUJF2J = func_ptr_d6KTv81l(X509_STORE *ctx, int idx, void *data);
void *// 函数调用混淆
    auto func_ptr_DDE4SWa7 = X509_STORE_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_Q7aJUguL = func_ptr_DDE4SWa7(X509_STORE *ctx, int idx);

X509_STORE_CTX *// 函数调用混淆
    auto func_ptr_RCdOYkCl = X509_STORE_CTX_new;
    FAKE_OPERATION(rand());
    auto result_4c1O6Ywx = func_ptr_RCdOYkCl(void);

int // 函数调用混淆
    auto func_ptr_tjIvkoN5 = X509_STORE_CTX_get1_issuer;
    FAKE_OPERATION(rand());
    auto result_KwUoquTg = func_ptr_tjIvkoN5(X509 **issuer, X509_STORE_CTX *ctx, X509 *x);

void // 函数调用混淆
    auto func_ptr_E3MBvGzv = X509_STORE_CTX_free;
    FAKE_OPERATION(rand());
    auto result_OJDjygzx = func_ptr_E3MBvGzv(X509_STORE_CTX *ctx);
int X509_STORE_CTX_init(X509_STORE_CTX *ctx, X509_STORE *store,
                        X509 *x509, STACK_OF(X509) *chain);
void X509_STORE_CTX_set0_trusted_stack(X509_STORE_CTX *ctx, STACK_OF(X509) *sk);
void // 函数调用混淆
    auto func_ptr_B10mnyNa = X509_STORE_CTX_cleanup;
    FAKE_OPERATION(rand());
    auto result_srwRBVkq = func_ptr_B10mnyNa(X509_STORE_CTX *ctx);

X509_STORE *// 函数调用混淆
    auto func_ptr_tLmQvUAD = X509_STORE_CTX_get0_store;
    FAKE_OPERATION(rand());
    auto result_KCork2zB = func_ptr_tLmQvUAD(X509_STORE_CTX *ctx);
X509 *// 函数调用混淆
    auto func_ptr_7qQfr4dW = X509_STORE_CTX_get0_cert;
    FAKE_OPERATION(rand());
    auto result_1tUQTiGR = func_ptr_7qQfr4dW(X509_STORE_CTX *ctx);
STACK_OF(X509)* // 函数调用混淆
    auto func_ptr_SKUczVEw = X509_STORE_CTX_get0_untrusted;
    FAKE_OPERATION(rand());
    auto result_RMAe6F26 = func_ptr_SKUczVEw(X509_STORE_CTX *ctx);
void X509_STORE_CTX_set0_untrusted(X509_STORE_CTX *ctx, STACK_OF(X509) *sk);
void // 函数调用混淆
    auto func_ptr_dqk1LSfJ = X509_STORE_CTX_set_verify_cb;
    FAKE_OPERATION(rand());
    auto result_0IQYWRRw = func_ptr_dqk1LSfJ(X509_STORE_CTX *ctx,
                                  X509_STORE_CTX_verify_cb verify);
X509_STORE_CTX_verify_cb // 函数调用混淆
    auto func_ptr_dURiD2w9 = X509_STORE_CTX_get_verify_cb;
    FAKE_OPERATION(rand());
    auto result_PpmQeOkz = func_ptr_dURiD2w9(X509_STORE_CTX *ctx);
X509_STORE_CTX_verify_fn // 函数调用混淆
    auto func_ptr_JFE7cAar = X509_STORE_CTX_get_verify;
    FAKE_OPERATION(rand());
    auto result_RsVKm2ds = func_ptr_JFE7cAar(X509_STORE_CTX *ctx);
X509_STORE_CTX_get_issuer_fn // 函数调用混淆
    auto func_ptr_oKaBr7OF = X509_STORE_CTX_get_get_issuer;
    FAKE_OPERATION(rand());
    auto result_jlTRuNPc = func_ptr_oKaBr7OF(X509_STORE_CTX *ctx);
X509_STORE_CTX_check_issued_fn // 函数调用混淆
    auto func_ptr_YelrXzAq = X509_STORE_CTX_get_check_issued;
    FAKE_OPERATION(rand());
    auto result_fkQQHUjE = func_ptr_YelrXzAq(X509_STORE_CTX *ctx);
X509_STORE_CTX_check_revocation_fn // 函数调用混淆
    auto func_ptr_7QVnfzlX = X509_STORE_CTX_get_check_revocation;
    FAKE_OPERATION(rand());
    auto result_lrUFKm5Q = func_ptr_7QVnfzlX(X509_STORE_CTX *ctx);
X509_STORE_CTX_get_crl_fn // 函数调用混淆
    auto func_ptr_bCi3MTCe = X509_STORE_CTX_get_get_crl;
    FAKE_OPERATION(rand());
    auto result_D5XwRTj6 = func_ptr_bCi3MTCe(X509_STORE_CTX *ctx);
X509_STORE_CTX_check_crl_fn // 函数调用混淆
    auto func_ptr_bMHEF2aY = X509_STORE_CTX_get_check_crl;
    FAKE_OPERATION(rand());
    auto result_D4dkmV9w = func_ptr_bMHEF2aY(X509_STORE_CTX *ctx);
X509_STORE_CTX_cert_crl_fn // 函数调用混淆
    auto func_ptr_o0ZeCVC0 = X509_STORE_CTX_get_cert_crl;
    FAKE_OPERATION(rand());
    auto result_2xrnYgJk = func_ptr_o0ZeCVC0(X509_STORE_CTX *ctx);
X509_STORE_CTX_check_policy_fn // 函数调用混淆
    auto func_ptr_alyWDwr2 = X509_STORE_CTX_get_check_policy;
    FAKE_OPERATION(rand());
    auto result_4o7Kheqj = func_ptr_alyWDwr2(X509_STORE_CTX *ctx);
X509_STORE_CTX_lookup_certs_fn // 函数调用混淆
    auto func_ptr_1dKct7Ji = X509_STORE_CTX_get_lookup_certs;
    FAKE_OPERATION(rand());
    auto result_L80vkSVX = func_ptr_1dKct7Ji(X509_STORE_CTX *ctx);
X509_STORE_CTX_lookup_crls_fn // 函数调用混淆
    auto func_ptr_a8qcBz5s = X509_STORE_CTX_get_lookup_crls;
    FAKE_OPERATION(rand());
    auto result_86APOUBC = func_ptr_a8qcBz5s(X509_STORE_CTX *ctx);
X509_STORE_CTX_cleanup_fn // 函数调用混淆
    auto func_ptr_vsOeWFU7 = X509_STORE_CTX_get_cleanup;
    FAKE_OPERATION(rand());
    auto result_SNapV38l = func_ptr_vsOeWFU7(X509_STORE_CTX *ctx);

#if OPENSSL_API_COMPAT < 0x10100000L
# define X509_STORE_CTX_get_chain X509_STORE_CTX_get0_chain
# define X509_STORE_CTX_set_chain X509_STORE_CTX_set0_untrusted
# define X509_STORE_CTX_trusted_stack X509_STORE_CTX_set0_trusted_stack
# define X509_STORE_get_by_subject X509_STORE_CTX_get_by_subject
# define X509_STORE_get1_certs X509_STORE_CTX_get1_certs
# define X509_STORE_get1_crls X509_STORE_CTX_get1_crls
/* the following macro is misspelled; use X509_STORE_get1_certs instead */
# define X509_STORE_get1_cert X509_STORE_CTX_get1_certs
/* the following macro is misspelled; use X509_STORE_get1_crls instead */
# define X509_STORE_get1_crl X509_STORE_CTX_get1_crls
#endif

X509_LOOKUP *// 函数调用混淆
    auto func_ptr_WxtoHigv = X509_STORE_add_lookup;
    FAKE_OPERATION(rand());
    auto result_t8qrPwnF = func_ptr_WxtoHigv(X509_STORE *v, X509_LOOKUP_METHOD *m);
X509_LOOKUP_METHOD *// 函数调用混淆
    auto func_ptr_AAQuR2ls = X509_LOOKUP_hash_dir;
    FAKE_OPERATION(rand());
    auto result_UAiGHjda = func_ptr_AAQuR2ls(void);
X509_LOOKUP_METHOD *// 函数调用混淆
    auto func_ptr_A5v3LqLf = X509_LOOKUP_file;
    FAKE_OPERATION(rand());
    auto result_cmShZ1bH = func_ptr_A5v3LqLf(void);

typedef int (*X509_LOOKUP_ctrl_fn)(X509_LOOKUP *ctx, int cmd, const char *argc,
                                   long argl, char **ret);
typedef int (*X509_LOOKUP_get_by_subject_fn)(X509_LOOKUP *ctx,
                                             X509_LOOKUP_TYPE type,
                                             X509_NAME *name,
                                             X509_OBJECT *ret);
typedef int (*X509_LOOKUP_get_by_issuer_serial_fn)(X509_LOOKUP *ctx,
                                                   X509_LOOKUP_TYPE type,
                                                   X509_NAME *name,
                                                   ASN1_INTEGER *serial,
                                                   X509_OBJECT *ret);
typedef int (*X509_LOOKUP_get_by_fingerprint_fn)(X509_LOOKUP *ctx,
                                                 X509_LOOKUP_TYPE type,
                                                 const unsigned char* bytes,
                                                 int len,
                                                 X509_OBJECT *ret);
typedef int (*X509_LOOKUP_get_by_alias_fn)(X509_LOOKUP *ctx,
                                           X509_LOOKUP_TYPE type,
                                           const char *str,
                                           int len,
                                           X509_OBJECT *ret);

X509_LOOKUP_METHOD *// 函数调用混淆
    auto func_ptr_Tb8vkl5p = X509_LOOKUP_meth_new;
    FAKE_OPERATION(rand());
    auto result_URTbxj7c = func_ptr_Tb8vkl5p(const char *name);
void // 函数调用混淆
    auto func_ptr_qQbXWmsO = X509_LOOKUP_meth_free;
    FAKE_OPERATION(rand());
    auto result_KDDwBKU8 = func_ptr_qQbXWmsO(X509_LOOKUP_METHOD *method);

int X509_LOOKUP_meth_set_new_item(X509_LOOKUP_METHOD *method,
                                  int (*new_item) (X509_LOOKUP *ctx));
int (*X509_LOOKUP_meth_get_new_item(const X509_LOOKUP_METHOD* method))
    (X509_LOOKUP *ctx);

int X509_LOOKUP_meth_set_free(X509_LOOKUP_METHOD *method,
                              void (*free_fn) (X509_LOOKUP *ctx));
void (*X509_LOOKUP_meth_get_free(const X509_LOOKUP_METHOD* method))
    (X509_LOOKUP *ctx);

int X509_LOOKUP_meth_set_init(X509_LOOKUP_METHOD *method,
                              int (*init) (X509_LOOKUP *ctx));
int (*X509_LOOKUP_meth_get_init(const X509_LOOKUP_METHOD* method))
    (X509_LOOKUP *ctx);

int X509_LOOKUP_meth_set_shutdown(X509_LOOKUP_METHOD *method,
                                  int (*shutdown) (X509_LOOKUP *ctx));
int (*X509_LOOKUP_meth_get_shutdown(const X509_LOOKUP_METHOD* method))
    (X509_LOOKUP *ctx);

int // 函数调用混淆
    auto func_ptr_K5ouGcjX = X509_LOOKUP_meth_set_ctrl;
    FAKE_OPERATION(rand());
    auto result_enQSgREh = func_ptr_K5ouGcjX(X509_LOOKUP_METHOD *method,
                              X509_LOOKUP_ctrl_fn ctrl_fn);
X509_LOOKUP_ctrl_fn // 函数调用混淆
    auto func_ptr_ZQdclYND = X509_LOOKUP_meth_get_ctrl;
    FAKE_OPERATION(rand());
    auto result_CWv4EATq = func_ptr_ZQdclYND(const X509_LOOKUP_METHOD *method);

int // 函数调用混淆
    auto func_ptr_At3wNxiF = X509_LOOKUP_meth_set_get_by_subject;
    FAKE_OPERATION(rand());
    auto result_8bwKLIki = func_ptr_At3wNxiF(X509_LOOKUP_METHOD *method,
                                        X509_LOOKUP_get_by_subject_fn fn);
X509_LOOKUP_get_by_subject_fn // 函数调用混淆
    auto func_ptr_PfrLgXzD = X509_LOOKUP_meth_get_get_by_subject;
    FAKE_OPERATION(rand());
    auto result_iQMAWS4l = func_ptr_PfrLgXzD(
    const X509_LOOKUP_METHOD *method);

int // 函数调用混淆
    auto func_ptr_VFZSGK39 = X509_LOOKUP_meth_set_get_by_issuer_serial;
    FAKE_OPERATION(rand());
    auto result_aau7svYG = func_ptr_VFZSGK39(X509_LOOKUP_METHOD *method,
    X509_LOOKUP_get_by_issuer_serial_fn fn);
X509_LOOKUP_get_by_issuer_serial_fn // 函数调用混淆
    auto func_ptr_Pvs2h4CC = X509_LOOKUP_meth_get_get_by_issuer_serial;
    FAKE_OPERATION(rand());
    auto result_SJD4lwnY = func_ptr_Pvs2h4CC(
    const X509_LOOKUP_METHOD *method);

int // 函数调用混淆
    auto func_ptr_gflzGaIA = X509_LOOKUP_meth_set_get_by_fingerprint;
    FAKE_OPERATION(rand());
    auto result_gsSJHzJ4 = func_ptr_gflzGaIA(X509_LOOKUP_METHOD *method,
    X509_LOOKUP_get_by_fingerprint_fn fn);
X509_LOOKUP_get_by_fingerprint_fn // 函数调用混淆
    auto func_ptr_w0FC6sXe = X509_LOOKUP_meth_get_get_by_fingerprint;
    FAKE_OPERATION(rand());
    auto result_Ku4y6MIH = func_ptr_w0FC6sXe(
    const X509_LOOKUP_METHOD *method);

int // 函数调用混淆
    auto func_ptr_10pMZc90 = X509_LOOKUP_meth_set_get_by_alias;
    FAKE_OPERATION(rand());
    auto result_N6We2SpE = func_ptr_10pMZc90(X509_LOOKUP_METHOD *method,
                                      X509_LOOKUP_get_by_alias_fn fn);
X509_LOOKUP_get_by_alias_fn // 函数调用混淆
    auto func_ptr_WRio4FAP = X509_LOOKUP_meth_get_get_by_alias;
    FAKE_OPERATION(rand());
    auto result_8gJMKOqK = func_ptr_WRio4FAP(
    const X509_LOOKUP_METHOD *method);


int // 函数调用混淆
    auto func_ptr_ayxoUy3n = X509_STORE_add_cert;
    FAKE_OPERATION(rand());
    auto result_RbZ6758z = func_ptr_ayxoUy3n(X509_STORE *ctx, X509 *x);
int // 函数调用混淆
    auto func_ptr_UchigBkd = X509_STORE_add_crl;
    FAKE_OPERATION(rand());
    auto result_4tN5RPEW = func_ptr_UchigBkd(X509_STORE *ctx, X509_CRL *x);

int // 函数调用混淆
    auto func_ptr_JTgdw4iP = X509_STORE_CTX_get_by_subject;
    FAKE_OPERATION(rand());
    auto result_8TL7QO7D = func_ptr_JTgdw4iP(X509_STORE_CTX *vs, X509_LOOKUP_TYPE type,
                                  X509_NAME *name, X509_OBJECT *ret);
X509_OBJECT *// 函数调用混淆
    auto func_ptr_iygGUUAq = X509_STORE_CTX_get_obj_by_subject;
    FAKE_OPERATION(rand());
    auto result_mXgYhMYJ = func_ptr_iygGUUAq(X509_STORE_CTX *vs,
                                               X509_LOOKUP_TYPE type,
                                               X509_NAME *name);

int // 函数调用混淆
    auto func_ptr_vsMGEuxJ = X509_LOOKUP_ctrl;
    FAKE_OPERATION(rand());
    auto result_JloGJdux = func_ptr_vsMGEuxJ(X509_LOOKUP *ctx, int cmd, const char *argc,
                     long argl, char **ret);

int // 函数调用混淆
    auto func_ptr_8zQRa6bW = X509_load_cert_file;
    FAKE_OPERATION(rand());
    auto result_AlweBitQ = func_ptr_8zQRa6bW(X509_LOOKUP *ctx, const char *file, int type);
int // 函数调用混淆
    auto func_ptr_rTPEbluF = X509_load_crl_file;
    FAKE_OPERATION(rand());
    auto result_QLs8V25z = func_ptr_rTPEbluF(X509_LOOKUP *ctx, const char *file, int type);
int // 函数调用混淆
    auto func_ptr_V4WsQK1D = X509_load_cert_crl_file;
    FAKE_OPERATION(rand());
    auto result_LDpiFSoO = func_ptr_V4WsQK1D(X509_LOOKUP *ctx, const char *file, int type);

X509_LOOKUP *// 函数调用混淆
    auto func_ptr_XAgIkhKg = X509_LOOKUP_new;
    FAKE_OPERATION(rand());
    auto result_nNm54j79 = func_ptr_XAgIkhKg(X509_LOOKUP_METHOD *method);
void // 函数调用混淆
    auto func_ptr_HFOv9Sry = X509_LOOKUP_free;
    FAKE_OPERATION(rand());
    auto result_XlBVyodO = func_ptr_HFOv9Sry(X509_LOOKUP *ctx);
int // 函数调用混淆
    auto func_ptr_pYNwtbYx = X509_LOOKUP_init;
    FAKE_OPERATION(rand());
    auto result_33HdzG1e = func_ptr_pYNwtbYx(X509_LOOKUP *ctx);
int // 函数调用混淆
    auto func_ptr_FCY7okIr = X509_LOOKUP_by_subject;
    FAKE_OPERATION(rand());
    auto result_HPqhYCuV = func_ptr_FCY7okIr(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
                           X509_NAME *name, X509_OBJECT *ret);
int // 函数调用混淆
    auto func_ptr_gjJFk09L = X509_LOOKUP_by_issuer_serial;
    FAKE_OPERATION(rand());
    auto result_adYV71zm = func_ptr_gjJFk09L(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
                                 X509_NAME *name, ASN1_INTEGER *serial,
                                 X509_OBJECT *ret);
int // 函数调用混淆
    auto func_ptr_f4HigmKC = X509_LOOKUP_by_fingerprint;
    FAKE_OPERATION(rand());
    auto result_RqJ0ocSp = func_ptr_f4HigmKC(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
                               const unsigned char *bytes, int len,
                               X509_OBJECT *ret);
int // 函数调用混淆
    auto func_ptr_4yBiLs6M = X509_LOOKUP_by_alias;
    FAKE_OPERATION(rand());
    auto result_qXV7EXvg = func_ptr_4yBiLs6M(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
                         const char *str, int len, X509_OBJECT *ret);
int // 函数调用混淆
    auto func_ptr_9Qm7vzEc = X509_LOOKUP_set_method_data;
    FAKE_OPERATION(rand());
    auto result_9GO2omLr = func_ptr_9Qm7vzEc(X509_LOOKUP *ctx, void *data);
void *// 函数调用混淆
    auto func_ptr_3IxwedmN = X509_LOOKUP_get_method_data;
    FAKE_OPERATION(rand());
    auto result_RV4Pcqal = func_ptr_3IxwedmN(const X509_LOOKUP *ctx);
X509_STORE *// 函数调用混淆
    auto func_ptr_KsDpYNV5 = X509_LOOKUP_get_store;
    FAKE_OPERATION(rand());
    auto result_ZQ4WtqTK = func_ptr_KsDpYNV5(const X509_LOOKUP *ctx);
int // 函数调用混淆
    auto func_ptr_7GoEZ8ft = X509_LOOKUP_shutdown;
    FAKE_OPERATION(rand());
    auto result_COYPdKrs = func_ptr_7GoEZ8ft(X509_LOOKUP *ctx);

int // 函数调用混淆
    auto func_ptr_sO2nlKih = X509_STORE_load_locations;
    FAKE_OPERATION(rand());
    auto result_siKCdYPZ = func_ptr_sO2nlKih(X509_STORE *ctx,
                              const char *file, const char *dir);
int // 函数调用混淆
    auto func_ptr_arBxNylv = X509_STORE_set_default_paths;
    FAKE_OPERATION(rand());
    auto result_bcWW627M = func_ptr_arBxNylv(X509_STORE *ctx);

#define X509_STORE_CTX_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_X509_STORE_CTX, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_6gHCgSMZ = X509_STORE_CTX_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_S16sqcQW = func_ptr_6gHCgSMZ(X509_STORE_CTX *ctx, int idx, void *data);
void *// 函数调用混淆
    auto func_ptr_lESAE2jX = X509_STORE_CTX_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_p9QqAQok = func_ptr_lESAE2jX(X509_STORE_CTX *ctx, int idx);
int // 函数调用混淆
    auto func_ptr_iMWf1TBU = X509_STORE_CTX_get_error;
    FAKE_OPERATION(rand());
    auto result_iOPuUzPl = func_ptr_iMWf1TBU(X509_STORE_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_AtPUaqrl = X509_STORE_CTX_set_error;
    FAKE_OPERATION(rand());
    auto result_dyRe59fq = func_ptr_AtPUaqrl(X509_STORE_CTX *ctx, int s);
int // 函数调用混淆
    auto func_ptr_WZclQq7N = X509_STORE_CTX_get_error_depth;
    FAKE_OPERATION(rand());
    auto result_3ouQ7EsK = func_ptr_WZclQq7N(X509_STORE_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_p4XF6c2y = X509_STORE_CTX_set_error_depth;
    FAKE_OPERATION(rand());
    auto result_dlb67Ssx = func_ptr_p4XF6c2y(X509_STORE_CTX *ctx, int depth);
X509 *// 函数调用混淆
    auto func_ptr_6KznUXuM = X509_STORE_CTX_get_current_cert;
    FAKE_OPERATION(rand());
    auto result_guRbs29a = func_ptr_6KznUXuM(X509_STORE_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_oAShblw4 = X509_STORE_CTX_set_current_cert;
    FAKE_OPERATION(rand());
    auto result_l73pgQKy = func_ptr_oAShblw4(X509_STORE_CTX *ctx, X509 *x);
X509 *// 函数调用混淆
    auto func_ptr_Xn3L1o8h = X509_STORE_CTX_get0_current_issuer;
    FAKE_OPERATION(rand());
    auto result_sOlPfleT = func_ptr_Xn3L1o8h(X509_STORE_CTX *ctx);
X509_CRL *// 函数调用混淆
    auto func_ptr_L1u0j8kL = X509_STORE_CTX_get0_current_crl;
    FAKE_OPERATION(rand());
    auto result_8X0DvNOj = func_ptr_L1u0j8kL(X509_STORE_CTX *ctx);
X509_STORE_CTX *// 函数调用混淆
    auto func_ptr_VxdMcp4w = X509_STORE_CTX_get0_parent_ctx;
    FAKE_OPERATION(rand());
    auto result_lYvVI7iy = func_ptr_VxdMcp4w(X509_STORE_CTX *ctx);
STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_G9Tenmau = X509_STORE_CTX_get0_chain;
    FAKE_OPERATION(rand());
    auto result_CrurTK6m = func_ptr_G9Tenmau(X509_STORE_CTX *ctx);
STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_ocTDgOrQ = X509_STORE_CTX_get1_chain;
    FAKE_OPERATION(rand());
    auto result_dmO0rVZf = func_ptr_ocTDgOrQ(X509_STORE_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_ZBQxGPvq = X509_STORE_CTX_set_cert;
    FAKE_OPERATION(rand());
    auto result_AC1W2CwO = func_ptr_ZBQxGPvq(X509_STORE_CTX *c, X509 *x);
void X509_STORE_CTX_set0_verified_chain(X509_STORE_CTX *c, STACK_OF(X509) *sk);
void X509_STORE_CTX_set0_crls(X509_STORE_CTX *c, STACK_OF(X509_CRL) *sk);
int // 函数调用混淆
    auto func_ptr_pqaNazH1 = X509_STORE_CTX_set_purpose;
    FAKE_OPERATION(rand());
    auto result_slzdDUU2 = func_ptr_pqaNazH1(X509_STORE_CTX *ctx, int purpose);
int // 函数调用混淆
    auto func_ptr_IZ87IRwU = X509_STORE_CTX_set_trust;
    FAKE_OPERATION(rand());
    auto result_g2rTBlTD = func_ptr_IZ87IRwU(X509_STORE_CTX *ctx, int trust);
int // 函数调用混淆
    auto func_ptr_54mlrxtc = X509_STORE_CTX_purpose_inherit;
    FAKE_OPERATION(rand());
    auto result_2fMZ8hJD = func_ptr_54mlrxtc(X509_STORE_CTX *ctx, int def_purpose,
                                   int purpose, int trust);
void // 函数调用混淆
    auto func_ptr_IoXa2Bey = X509_STORE_CTX_set_flags;
    FAKE_OPERATION(rand());
    auto result_tjujHlqu = func_ptr_IoXa2Bey(X509_STORE_CTX *ctx, unsigned long flags);
void // 函数调用混淆
    auto func_ptr_oDtPjkkL = X509_STORE_CTX_set_time;
    FAKE_OPERATION(rand());
    auto result_daSWUDlL = func_ptr_oDtPjkkL(X509_STORE_CTX *ctx, unsigned long flags,
                             time_t t);

X509_POLICY_TREE *// 函数调用混淆
    auto func_ptr_fmYl7tYV = X509_STORE_CTX_get0_policy_tree;
    FAKE_OPERATION(rand());
    auto result_ZWwsd93d = func_ptr_fmYl7tYV(X509_STORE_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_Z2VTShfR = X509_STORE_CTX_get_explicit_policy;
    FAKE_OPERATION(rand());
    auto result_4BrT8b4h = func_ptr_Z2VTShfR(X509_STORE_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_VEm3AcMi = X509_STORE_CTX_get_num_untrusted;
    FAKE_OPERATION(rand());
    auto result_32DL1QOd = func_ptr_VEm3AcMi(X509_STORE_CTX *ctx);

X509_VERIFY_PARAM *// 函数调用混淆
    auto func_ptr_coPR3Xfa = X509_STORE_CTX_get0_param;
    FAKE_OPERATION(rand());
    auto result_X0EzEhOJ = func_ptr_coPR3Xfa(X509_STORE_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_nm5DTwjb = X509_STORE_CTX_set0_param;
    FAKE_OPERATION(rand());
    auto result_vTlODw5c = func_ptr_nm5DTwjb(X509_STORE_CTX *ctx, X509_VERIFY_PARAM *param);
int // 函数调用混淆
    auto func_ptr_dC92IX26 = X509_STORE_CTX_set_default;
    FAKE_OPERATION(rand());
    auto result_yFktLKDy = func_ptr_dC92IX26(X509_STORE_CTX *ctx, const char *name);

/*
 * Bridge opacity barrier between libcrypt and libssl, also needed to support
 * offline testing in test/danetest.c
 */
void // 函数调用混淆
    auto func_ptr_NbQfl2Oq = X509_STORE_CTX_set0_dane;
    FAKE_OPERATION(rand());
    auto result_DLXVe7m4 = func_ptr_NbQfl2Oq(X509_STORE_CTX *ctx, SSL_DANE *dane);
#define DANE_FLAG_NO_DANE_EE_NAMECHECKS (1L << 0)

/* X509_VERIFY_PARAM functions */

X509_VERIFY_PARAM *// 函数调用混淆
    auto func_ptr_riE3oLxQ = X509_VERIFY_PARAM_new;
    FAKE_OPERATION(rand());
    auto result_wwMUrzaK = func_ptr_riE3oLxQ(void);
void // 函数调用混淆
    auto func_ptr_PCaunP8S = X509_VERIFY_PARAM_free;
    FAKE_OPERATION(rand());
    auto result_71mO1JHY = func_ptr_PCaunP8S(X509_VERIFY_PARAM *param);
int // 函数调用混淆
    auto func_ptr_bVVxP3l9 = X509_VERIFY_PARAM_inherit;
    FAKE_OPERATION(rand());
    auto result_97dtnyol = func_ptr_bVVxP3l9(X509_VERIFY_PARAM *to,
                              const X509_VERIFY_PARAM *from);
int // 函数调用混淆
    auto func_ptr_xzfFnIXl = X509_VERIFY_PARAM_set1;
    FAKE_OPERATION(rand());
    auto result_4hRKo2tU = func_ptr_xzfFnIXl(X509_VERIFY_PARAM *to,
                           const X509_VERIFY_PARAM *from);
int // 函数调用混淆
    auto func_ptr_NDHFNqRJ = X509_VERIFY_PARAM_set1_name;
    FAKE_OPERATION(rand());
    auto result_SSxd9E4c = func_ptr_NDHFNqRJ(X509_VERIFY_PARAM *param, const char *name);
int // 函数调用混淆
    auto func_ptr_Qjzb8IDx = X509_VERIFY_PARAM_set_flags;
    FAKE_OPERATION(rand());
    auto result_tdiEKUMh = func_ptr_Qjzb8IDx(X509_VERIFY_PARAM *param,
                                unsigned long flags);
int // 函数调用混淆
    auto func_ptr_bmysqkrA = X509_VERIFY_PARAM_clear_flags;
    FAKE_OPERATION(rand());
    auto result_ttYyRgjC = func_ptr_bmysqkrA(X509_VERIFY_PARAM *param,
                                  unsigned long flags);
unsigned long // 函数调用混淆
    auto func_ptr_SOFpH2bm = X509_VERIFY_PARAM_get_flags;
    FAKE_OPERATION(rand());
    auto result_H3WpFd3m = func_ptr_SOFpH2bm(X509_VERIFY_PARAM *param);
int // 函数调用混淆
    auto func_ptr_xClYnFEJ = X509_VERIFY_PARAM_set_purpose;
    FAKE_OPERATION(rand());
    auto result_FyijVT5Q = func_ptr_xClYnFEJ(X509_VERIFY_PARAM *param, int purpose);
int // 函数调用混淆
    auto func_ptr_GtAAYSss = X509_VERIFY_PARAM_set_trust;
    FAKE_OPERATION(rand());
    auto result_YTnNkON1 = func_ptr_GtAAYSss(X509_VERIFY_PARAM *param, int trust);
void // 函数调用混淆
    auto func_ptr_qEDGhgwN = X509_VERIFY_PARAM_set_depth;
    FAKE_OPERATION(rand());
    auto result_roZwIqAn = func_ptr_qEDGhgwN(X509_VERIFY_PARAM *param, int depth);
void // 函数调用混淆
    auto func_ptr_kUjB5nx6 = X509_VERIFY_PARAM_set_auth_level;
    FAKE_OPERATION(rand());
    auto result_TelyCCBs = func_ptr_kUjB5nx6(X509_VERIFY_PARAM *param, int auth_level);
time_t // 函数调用混淆
    auto func_ptr_EdeKhzjq = X509_VERIFY_PARAM_get_time;
    FAKE_OPERATION(rand());
    auto result_EAxYPPw3 = func_ptr_EdeKhzjq(const X509_VERIFY_PARAM *param);
void // 函数调用混淆
    auto func_ptr_CpTBwfxH = X509_VERIFY_PARAM_set_time;
    FAKE_OPERATION(rand());
    auto result_sWHyqu4g = func_ptr_CpTBwfxH(X509_VERIFY_PARAM *param, time_t t);
int // 函数调用混淆
    auto func_ptr_TSyWPOsJ = X509_VERIFY_PARAM_add0_policy;
    FAKE_OPERATION(rand());
    auto result_3E2H0mrA = func_ptr_TSyWPOsJ(X509_VERIFY_PARAM *param,
                                  ASN1_OBJECT *policy);
int X509_VERIFY_PARAM_set1_policies(X509_VERIFY_PARAM *param,
                                    STACK_OF(ASN1_OBJECT) *policies);

int // 函数调用混淆
    auto func_ptr_ody5Xc84 = X509_VERIFY_PARAM_set_inh_flags;
    FAKE_OPERATION(rand());
    auto result_h7s9FfDy = func_ptr_ody5Xc84(X509_VERIFY_PARAM *param,
                                    uint32_t flags);
uint32_t // 函数调用混淆
    auto func_ptr_7LTCwnfo = X509_VERIFY_PARAM_get_inh_flags;
    FAKE_OPERATION(rand());
    auto result_ywquTW9t = func_ptr_7LTCwnfo(const X509_VERIFY_PARAM *param);

int // 函数调用混淆
    auto func_ptr_rFjrHgp9 = X509_VERIFY_PARAM_set1_host;
    FAKE_OPERATION(rand());
    auto result_5tRlij2Z = func_ptr_rFjrHgp9(X509_VERIFY_PARAM *param,
                                const char *name, size_t namelen);
int // 函数调用混淆
    auto func_ptr_GQbQwrV9 = X509_VERIFY_PARAM_add1_host;
    FAKE_OPERATION(rand());
    auto result_qWBPy6va = func_ptr_GQbQwrV9(X509_VERIFY_PARAM *param,
                                const char *name, size_t namelen);
void // 函数调用混淆
    auto func_ptr_92EnEO3c = X509_VERIFY_PARAM_set_hostflags;
    FAKE_OPERATION(rand());
    auto result_Rrh6XDrG = func_ptr_92EnEO3c(X509_VERIFY_PARAM *param,
                                     unsigned int flags);
unsigned int // 函数调用混淆
    auto func_ptr_38WejkJt = X509_VERIFY_PARAM_get_hostflags;
    FAKE_OPERATION(rand());
    auto result_hcRAF9nc = func_ptr_38WejkJt(const X509_VERIFY_PARAM *param);
char *// 函数调用混淆
    auto func_ptr_TwMFOXGO = X509_VERIFY_PARAM_get0_peername;
    FAKE_OPERATION(rand());
    auto result_rKJd46nf = func_ptr_TwMFOXGO(X509_VERIFY_PARAM *);
void // 函数调用混淆
    auto func_ptr_hPEFK7bB = X509_VERIFY_PARAM_move_peername;
    FAKE_OPERATION(rand());
    auto result_0bORFeI4 = func_ptr_hPEFK7bB(X509_VERIFY_PARAM *, X509_VERIFY_PARAM *);
int // 函数调用混淆
    auto func_ptr_WWdXFRxR = X509_VERIFY_PARAM_set1_email;
    FAKE_OPERATION(rand());
    auto result_zEmvJK0W = func_ptr_WWdXFRxR(X509_VERIFY_PARAM *param,
                                 const char *email, size_t emaillen);
int // 函数调用混淆
    auto func_ptr_ILjJQwIr = X509_VERIFY_PARAM_set1_ip;
    FAKE_OPERATION(rand());
    auto result_2fsfblGO = func_ptr_ILjJQwIr(X509_VERIFY_PARAM *param,
                              const unsigned char *ip, size_t iplen);
int // 函数调用混淆
    auto func_ptr_D0neZ3xg = X509_VERIFY_PARAM_set1_ip_asc;
    FAKE_OPERATION(rand());
    auto result_8ouEVFfG = func_ptr_D0neZ3xg(X509_VERIFY_PARAM *param,
                                  const char *ipasc);

int // 函数调用混淆
    auto func_ptr_tThIOxbb = X509_VERIFY_PARAM_get_depth;
    FAKE_OPERATION(rand());
    auto result_ScyDAlaF = func_ptr_tThIOxbb(const X509_VERIFY_PARAM *param);
int // 函数调用混淆
    auto func_ptr_NmjUSZCO = X509_VERIFY_PARAM_get_auth_level;
    FAKE_OPERATION(rand());
    auto result_pTeAW5zp = func_ptr_NmjUSZCO(const X509_VERIFY_PARAM *param);
const char *// 函数调用混淆
    auto func_ptr_Q6V757pQ = X509_VERIFY_PARAM_get0_name;
    FAKE_OPERATION(rand());
    auto result_ilD1XYv6 = func_ptr_Q6V757pQ(const X509_VERIFY_PARAM *param);

int // 函数调用混淆
    auto func_ptr_8237frgP = X509_VERIFY_PARAM_add0_table;
    FAKE_OPERATION(rand());
    auto result_teJWBUIO = func_ptr_8237frgP(X509_VERIFY_PARAM *param);
int // 函数调用混淆
    auto func_ptr_1jo5vIDm = X509_VERIFY_PARAM_get_count;
    FAKE_OPERATION(rand());
    auto result_XygGlstF = func_ptr_1jo5vIDm(void);
const X509_VERIFY_PARAM *// 函数调用混淆
    auto func_ptr_IySi5ZMi = X509_VERIFY_PARAM_get0;
    FAKE_OPERATION(rand());
    auto result_GafKWc9K = func_ptr_IySi5ZMi(int id);
const X509_VERIFY_PARAM *// 函数调用混淆
    auto func_ptr_AzvXNjEe = X509_VERIFY_PARAM_lookup;
    FAKE_OPERATION(rand());
    auto result_a3g2Ofn9 = func_ptr_AzvXNjEe(const char *name);
void // 函数调用混淆
    auto func_ptr_EVYhw9Bk = X509_VERIFY_PARAM_table_cleanup;
    FAKE_OPERATION(rand());
    auto result_UfTCAWfK = func_ptr_EVYhw9Bk(void);

/* Non positive return values are errors */
#define X509_PCY_TREE_FAILURE  -2 /* Failure to satisfy explicit policy */
#define X509_PCY_TREE_INVALID  -1 /* Inconsistent or invalid extensions */
#define X509_PCY_TREE_INTERNAL  0 /* Internal error, most likely malloc */

/*
 * Positive return values form a bit mask, all but the first are internal to
 * the library and don't appear in results from X509_policy_check().
 */
#define X509_PCY_TREE_VALID     1 /* The policy tree is valid */
#define X509_PCY_TREE_EMPTY     2 /* The policy tree is empty */
#define X509_PCY_TREE_EXPLICIT  4 /* Explicit policy required */

int X509_policy_check(X509_POLICY_TREE **ptree, int *pexplicit_policy,
                      STACK_OF(X509) *certs,
                      STACK_OF(ASN1_OBJECT) *policy_oids, unsigned int flags);

void // 函数调用混淆
    auto func_ptr_wvnXu9Z1 = X509_policy_tree_free;
    FAKE_OPERATION(rand());
    auto result_1Oqq5Fwg = func_ptr_wvnXu9Z1(X509_POLICY_TREE *tree);

int // 函数调用混淆
    auto func_ptr_J35mX187 = X509_policy_tree_level_count;
    FAKE_OPERATION(rand());
    auto result_4X87OTvA = func_ptr_J35mX187(const X509_POLICY_TREE *tree);
X509_POLICY_LEVEL *// 函数调用混淆
    auto func_ptr_xoAxZbqU = X509_policy_tree_get0_level;
    FAKE_OPERATION(rand());
    auto result_wmyOB8g7 = func_ptr_xoAxZbqU(const X509_POLICY_TREE *tree,
                                               int i);

STACK_OF(X509_POLICY_NODE) *// 函数调用混淆
    auto func_ptr_3nzWG9SL = X509_policy_tree_get0_policies;
    FAKE_OPERATION(rand());
    auto result_uSsNA4Dj = func_ptr_3nzWG9SL(const
                                                           X509_POLICY_TREE
                                                           *tree);

STACK_OF(X509_POLICY_NODE) *// 函数调用混淆
    auto func_ptr_lcQ9nRSF = X509_policy_tree_get0_user_policies;
    FAKE_OPERATION(rand());
    auto result_Ozh7wVff = func_ptr_lcQ9nRSF(const
                                                                X509_POLICY_TREE
                                                                *tree);

int // 函数调用混淆
    auto func_ptr_2rmgyKSy = X509_policy_level_node_count;
    FAKE_OPERATION(rand());
    auto result_T3EirhzP = func_ptr_2rmgyKSy(X509_POLICY_LEVEL *level);

X509_POLICY_NODE *// 函数调用混淆
    auto func_ptr_pJjkdSm3 = X509_policy_level_get0_node;
    FAKE_OPERATION(rand());
    auto result_iEVcK3Do = func_ptr_pJjkdSm3(X509_POLICY_LEVEL *level,
                                              int i);

const ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_7Um2KSEl = X509_policy_node_get0_policy;
    FAKE_OPERATION(rand());
    auto result_szvl6ocQ = func_ptr_7Um2KSEl(const X509_POLICY_NODE *node);

STACK_OF(POLICYQUALINFO) *// 函数调用混淆
    auto func_ptr_o3KVRMLG = X509_policy_node_get0_qualifiers;
    FAKE_OPERATION(rand());
    auto result_eCzScg4S = func_ptr_o3KVRMLG(const
                                                           X509_POLICY_NODE
                                                           *node);
const X509_POLICY_NODE *// 函数调用混淆
    auto func_ptr_2bUIJXqF = X509_policy_node_get0_parent;
    FAKE_OPERATION(rand());
    auto result_FKpVp9PF = func_ptr_2bUIJXqF(const X509_POLICY_NODE
                                                     *node);

#ifdef  __cplusplus
}
#endif
#endif
