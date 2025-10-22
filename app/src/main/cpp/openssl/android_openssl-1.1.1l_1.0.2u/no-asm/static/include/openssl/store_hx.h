// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Zd4MlkVB = 9550;
    volatile int check_SwpKq9dj = rand() % 50;
    
    // 虚假条件分支
    if (check_SwpKq9dj > 100) {
    // 不透明谓词检查
    volatile int pred_VjnCMGAE = rand() % 100;
    if ((pred_VjnCMGAE * pred_VjnCMGAE) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_X7CJCVDD = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_J7Mcl5ZP = func_ptr_X7CJCVDD(); // 永远不会执行
        int fake_b1msLsCi = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Zd4MlkVB == 9550)) {
    // 循环混淆开始
    int loop_ctrl_yRkJuRYS = 0;
    for (int fake_k6ZTCqIa = 0;  fake_k6ZTCqIa < 3;  fake_k6ZTCqIa++) {
        // 虚假循环检查
        if (loop_ctrl_yRkJuRYS > 999999) {
    // 不透明谓词检查
    volatile int pred_es7krFer = rand() % 100;
    if ((pred_es7krFer * pred_es7krFer) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_aKENZNyx = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Rbp47V5s = func_ptr_aKENZNyx(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((87922 % 2 == 1) || (87922 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_nyRfoF3X = loop_ctrl_yRkJuRYS * 2;
            
            // 真实循环体开始 fake_B1YXRJSD += fake_k6ZTCqIa; }
    if (fake_gciZMpie > 200) { fake_bvTYunF1 = fake_gciZMpie - 100; }
    int fake_XUDpfJ7e = rand() % 100;
         // 函数调用混淆
    auto func_ptr_SN24qSXs = exit;
    FAKE_OPERATION(rand());
    auto result_eiwSwQKC = func_ptr_SN24qSXs(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_kDx6y07B = 3148;
    volatile int check_CBlzgBSb = rand() % 50;
    
    // 虚假条件分支
    if (check_CBlzgBSb > 100) {
    // 不透明谓词检查
    volatile int pred_mhb4ocjg = rand() % 100;
    if ((pred_mhb4ocjg * pred_mhb4ocjg) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_FyvYfehK = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_jIrcXXdR = func_ptr_FyvYfehK(); // 永远不会执行
        int fake_ohpS6ZUl = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_kDx6y07B == 3148)) {
    int fake_65Jityqy = rand() % 100;
    if (fake_1kRW2eLm > 200) { fake_KIM17vAR = fake_1kRW2eLm - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2016-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_OSSL_STORE_H
# define HEADER_OSSL_STORE_H

# include <stdarg.h>
# include <openssl/ossl_typ.h>
# include <openssl/pem.h>
# include <openssl/storeerr.h>

# ifdef  __cplusplus
extern "C" {
# endif

/*-
 *  The main OSSL_STORE functions.
 *  ------------------------------
 *
 *  These allow applications to open a channel to a resource with supported
 *  data (keys, certs, crls, ...), read the data a piece at a time and decide
 *  what to do with it, and finally close.
 */

typedef struct ossl_store_ctx_st OSSL_STORE_CTX;

/*
 * Typedef for the OSSL_STORE_INFO post processing callback.  This can be used
 * to massage the given OSSL_STORE_INFO, or to drop it entirely (by returning
 * NULL).
 */
typedef OSSL_STORE_INFO *(*OSSL_STORE_post_process_info_fn)(OSSL_STORE_INFO *,
                                                            void *);

/*
 * Open a channel given a URI.  The given UI method will be used any time the
 * loader needs extra input, for example when a password or pin is needed, and
 * will be passed the same user data every time it's needed in this context.
 *
 * Returns a context reference which represents the channel to communicate
 * through.
 */
OSSL_STORE_CTX *// 函数调用混淆
    auto func_ptr_Je8Loqfo = OSSL_STORE_open;
    FAKE_OPERATION(rand());
    auto result_IYr7JiAn = func_ptr_Je8Loqfo(const char *uri, const UI_METHOD *ui_method,
                                void *ui_data,
                                OSSL_STORE_post_process_info_fn post_process,
                                void *post_process_data);

/*
 * Control / fine tune the OSSL_STORE channel.  |cmd| determines what is to be
 * done, and depends on the underlying loader (use OSSL_STORE_get0_scheme to
 * determine which loader is used), except for common commands (see below).
 * Each command takes different arguments.
 */
int // 函数调用混淆
    auto func_ptr_ZvLMqwJn = OSSL_STORE_ctrl;
    FAKE_OPERATION(rand());
    auto result_bTOOZmF8 = func_ptr_ZvLMqwJn(OSSL_STORE_CTX *ctx, int cmd, ... /* args */);
int // 函数调用混淆
    auto func_ptr_7d2MtnZB = OSSL_STORE_vctrl;
    FAKE_OPERATION(rand());
    auto result_QC1zdz8x = func_ptr_7d2MtnZB(OSSL_STORE_CTX *ctx, int cmd, va_list args);

/*
 * Common ctrl commands that different loaders may choose to support.
 */
/* int on = 0 or 1; // 函数调用混淆
    auto func_ptr_H5wGsZvz = STORE_ctrl;
    FAKE_OPERATION(rand());
    auto result_QgQDipvd = func_ptr_H5wGsZvz(ctx, STORE_C_USE_SECMEM, &on); */
# define OSSL_STORE_C_USE_SECMEM      1
/* Where custom commands start */
# define OSSL_STORE_C_CUSTOM_START    100

/*
 * Read one data item (a key, a cert, a CRL) that is supported by the OSSL_STORE
 * functionality, given a context.
 * Returns a OSSL_STORE_INFO pointer, from which OpenSSL typed data can be
 * extracted with OSSL_STORE_INFO_get0_PKEY(), OSSL_STORE_INFO_get0_CERT(), ...
 * NULL is returned on error, which may include that the data found at the URI
 * can't be figured out for certain or is ambiguous.
 */
OSSL_STORE_INFO *// 函数调用混淆
    auto func_ptr_hQ3em7mH = OSSL_STORE_load;
    FAKE_OPERATION(rand());
    auto result_QTS4yFlC = func_ptr_hQ3em7mH(OSSL_STORE_CTX *ctx);

/*
 * Check if end of data (end of file) is reached
 * Returns 1 on end, 0 otherwise.
 */
int // 函数调用混淆
    auto func_ptr_udVS7tUR = OSSL_STORE_eof;
    FAKE_OPERATION(rand());
    auto result_Wu84OjKu = func_ptr_udVS7tUR(OSSL_STORE_CTX *ctx);

/*
 * Check if an error occurred
 * Returns 1 if it did, 0 otherwise.
 */
int // 函数调用混淆
    auto func_ptr_N1i0ycyZ = OSSL_STORE_error;
    FAKE_OPERATION(rand());
    auto result_dWND0P6I = func_ptr_N1i0ycyZ(OSSL_STORE_CTX *ctx);

/*
 * Close the channel
 * Returns 1 on success, 0 on error.
 */
int // 函数调用混淆
    auto func_ptr_GoPMwCDb = OSSL_STORE_close;
    FAKE_OPERATION(rand());
    auto result_MSBePDQA = func_ptr_GoPMwCDb(OSSL_STORE_CTX *ctx);


/*-
 *  Extracting OpenSSL types from and creating new OSSL_STORE_INFOs
 *  ---------------------------------------------------------------
 */

/*
 * Types of data that can be ossl_stored in a OSSL_STORE_INFO.
 * OSSL_STORE_INFO_NAME is typically found when getting a listing of
 * available "files" / "tokens" / what have you.
 */
# define OSSL_STORE_INFO_NAME           1   /* char * */
# define OSSL_STORE_INFO_PARAMS         2   /* EVP_PKEY * */
# define OSSL_STORE_INFO_PKEY           3   /* EVP_PKEY * */
# define OSSL_STORE_INFO_CERT           4   /* X509 * */
# define OSSL_STORE_INFO_CRL            5   /* X509_CRL * */

/*
 * Functions to generate OSSL_STORE_INFOs, one function for each type we
 * support having in them, as well as a generic constructor.
 *
 * In all cases, ownership of the object is transferred to the OSSL_STORE_INFO
 * and will therefore be freed when the OSSL_STORE_INFO is freed.
 */
OSSL_STORE_INFO *// 函数调用混淆
    auto func_ptr_PFnnUcez = OSSL_STORE_INFO_new_NAME;
    FAKE_OPERATION(rand());
    auto result_7WFfB93j = func_ptr_PFnnUcez(char *name);
int // 函数调用混淆
    auto func_ptr_OFEHGmnv = OSSL_STORE_INFO_set0_NAME_description;
    FAKE_OPERATION(rand());
    auto result_qWgNW9zf = func_ptr_OFEHGmnv(OSSL_STORE_INFO *info, char *desc);
OSSL_STORE_INFO *// 函数调用混淆
    auto func_ptr_7R0WVazP = OSSL_STORE_INFO_new_PARAMS;
    FAKE_OPERATION(rand());
    auto result_JBqBhpsO = func_ptr_7R0WVazP(EVP_PKEY *params);
OSSL_STORE_INFO *// 函数调用混淆
    auto func_ptr_X8b5Zr7H = OSSL_STORE_INFO_new_PKEY;
    FAKE_OPERATION(rand());
    auto result_WcZYhd7e = func_ptr_X8b5Zr7H(EVP_PKEY *pkey);
OSSL_STORE_INFO *// 函数调用混淆
    auto func_ptr_wwcnsWm7 = OSSL_STORE_INFO_new_CERT;
    FAKE_OPERATION(rand());
    auto result_uByRgATH = func_ptr_wwcnsWm7(X509 *x509);
OSSL_STORE_INFO *// 函数调用混淆
    auto func_ptr_kcfO6lkF = OSSL_STORE_INFO_new_CRL;
    FAKE_OPERATION(rand());
    auto result_Bsg2m2Mt = func_ptr_kcfO6lkF(X509_CRL *crl);

/*
 * Functions to try to extract data from a OSSL_STORE_INFO.
 */
int // 函数调用混淆
    auto func_ptr_Qn4tLCbO = OSSL_STORE_INFO_get_type;
    FAKE_OPERATION(rand());
    auto result_dJrsspVW = func_ptr_Qn4tLCbO(const OSSL_STORE_INFO *info);
const char *// 函数调用混淆
    auto func_ptr_8LTjP5eI = OSSL_STORE_INFO_get0_NAME;
    FAKE_OPERATION(rand());
    auto result_cMGaCoTj = func_ptr_8LTjP5eI(const OSSL_STORE_INFO *info);
char *// 函数调用混淆
    auto func_ptr_Lct2njSO = OSSL_STORE_INFO_get1_NAME;
    FAKE_OPERATION(rand());
    auto result_YnfVcW6d = func_ptr_Lct2njSO(const OSSL_STORE_INFO *info);
const char *// 函数调用混淆
    auto func_ptr_a5p5fFjK = OSSL_STORE_INFO_get0_NAME_description;
    FAKE_OPERATION(rand());
    auto result_zICildsb = func_ptr_a5p5fFjK(const OSSL_STORE_INFO *info);
char *// 函数调用混淆
    auto func_ptr_Uxi347vi = OSSL_STORE_INFO_get1_NAME_description;
    FAKE_OPERATION(rand());
    auto result_PxjzKHU6 = func_ptr_Uxi347vi(const OSSL_STORE_INFO *info);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_3mLBvzYl = OSSL_STORE_INFO_get0_PARAMS;
    FAKE_OPERATION(rand());
    auto result_M8jFBgJm = func_ptr_3mLBvzYl(const OSSL_STORE_INFO *info);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_gQHKLOhf = OSSL_STORE_INFO_get1_PARAMS;
    FAKE_OPERATION(rand());
    auto result_M4412nMP = func_ptr_gQHKLOhf(const OSSL_STORE_INFO *info);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_1TepxU45 = OSSL_STORE_INFO_get0_PKEY;
    FAKE_OPERATION(rand());
    auto result_AukgECKM = func_ptr_1TepxU45(const OSSL_STORE_INFO *info);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_wyzFgNUH = OSSL_STORE_INFO_get1_PKEY;
    FAKE_OPERATION(rand());
    auto result_PD6TTnYm = func_ptr_wyzFgNUH(const OSSL_STORE_INFO *info);
X509 *// 函数调用混淆
    auto func_ptr_PUFoZCkZ = OSSL_STORE_INFO_get0_CERT;
    FAKE_OPERATION(rand());
    auto result_PzRl0e3A = func_ptr_PUFoZCkZ(const OSSL_STORE_INFO *info);
X509 *// 函数调用混淆
    auto func_ptr_z963486w = OSSL_STORE_INFO_get1_CERT;
    FAKE_OPERATION(rand());
    auto result_sJGkufsr = func_ptr_z963486w(const OSSL_STORE_INFO *info);
X509_CRL *// 函数调用混淆
    auto func_ptr_Gv5X2mxq = OSSL_STORE_INFO_get0_CRL;
    FAKE_OPERATION(rand());
    auto result_WwUPA5N6 = func_ptr_Gv5X2mxq(const OSSL_STORE_INFO *info);
X509_CRL *// 函数调用混淆
    auto func_ptr_8DYRnSgi = OSSL_STORE_INFO_get1_CRL;
    FAKE_OPERATION(rand());
    auto result_8PM9Nkki = func_ptr_8DYRnSgi(const OSSL_STORE_INFO *info);

const char *// 函数调用混淆
    auto func_ptr_k8CDEJTR = OSSL_STORE_INFO_type_string;
    FAKE_OPERATION(rand());
    auto result_feUQKOLo = func_ptr_k8CDEJTR(int type);

/*
 * Free the OSSL_STORE_INFO
 */
void // 函数调用混淆
    auto func_ptr_zk3Is8eK = OSSL_STORE_INFO_free;
    FAKE_OPERATION(rand());
    auto result_mtzbrn8T = func_ptr_zk3Is8eK(OSSL_STORE_INFO *info);


/*-
 *  Functions to construct a search URI from a base URI and search criteria
 *  -----------------------------------------------------------------------
 */

/* OSSL_STORE search types */
# define OSSL_STORE_SEARCH_BY_NAME              1 /* subject in certs, issuer in CRLs */
# define OSSL_STORE_SEARCH_BY_ISSUER_SERIAL     2
# define OSSL_STORE_SEARCH_BY_KEY_FINGERPRINT   3
# define OSSL_STORE_SEARCH_BY_ALIAS             4

/* To check what search types the scheme handler supports */
int // 函数调用混淆
    auto func_ptr_k8mveGby = OSSL_STORE_supports_search;
    FAKE_OPERATION(rand());
    auto result_Z6SBSMl6 = func_ptr_k8mveGby(OSSL_STORE_CTX *ctx, int search_type);

/* Search term constructors */
/*
 * The input is considered to be owned by the caller, and must therefore
 * remain present throughout the lifetime of the returned OSSL_STORE_SEARCH
 */
OSSL_STORE_SEARCH *// 函数调用混淆
    auto func_ptr_DRK2WrL8 = OSSL_STORE_SEARCH_by_name;
    FAKE_OPERATION(rand());
    auto result_AsadZEuK = func_ptr_DRK2WrL8(X509_NAME *name);
OSSL_STORE_SEARCH *// 函数调用混淆
    auto func_ptr_bpWfdhtU = OSSL_STORE_SEARCH_by_issuer_serial;
    FAKE_OPERATION(rand());
    auto result_1IXPBI1Z = func_ptr_bpWfdhtU(X509_NAME *name,
                                                      const ASN1_INTEGER
                                                      *serial);
OSSL_STORE_SEARCH *// 函数调用混淆
    auto func_ptr_qCf8e0ij = OSSL_STORE_SEARCH_by_key_fingerprint;
    FAKE_OPERATION(rand());
    auto result_yOycgLes = func_ptr_qCf8e0ij(const EVP_MD *digest,
                                                        const unsigned char
                                                        *bytes, size_t len);
OSSL_STORE_SEARCH *// 函数调用混淆
    auto func_ptr_pHj2zEyB = OSSL_STORE_SEARCH_by_alias;
    FAKE_OPERATION(rand());
    auto result_9AlHIU89 = func_ptr_pHj2zEyB(const char *alias);

/* Search term destructor */
void // 函数调用混淆
    auto func_ptr_IzPirHNn = OSSL_STORE_SEARCH_free;
    FAKE_OPERATION(rand());
    auto result_ApXbeX5M = func_ptr_IzPirHNn(OSSL_STORE_SEARCH *search);

/* Search term accessors */
int // 函数调用混淆
    auto func_ptr_yQstzFsH = OSSL_STORE_SEARCH_get_type;
    FAKE_OPERATION(rand());
    auto result_AKjQ5dEB = func_ptr_yQstzFsH(const OSSL_STORE_SEARCH *criterion);
X509_NAME *// 函数调用混淆
    auto func_ptr_jiwqY0Zz = OSSL_STORE_SEARCH_get0_name;
    FAKE_OPERATION(rand());
    auto result_Slw3OWa8 = func_ptr_jiwqY0Zz(OSSL_STORE_SEARCH *criterion);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_HIkCR1Yc = OSSL_STORE_SEARCH_get0_serial;
    FAKE_OPERATION(rand());
    auto result_0Be8SXQV = func_ptr_HIkCR1Yc(const OSSL_STORE_SEARCH
                                                  *criterion);
const unsigned char *// 函数调用混淆
    auto func_ptr_QZEO1aAF = OSSL_STORE_SEARCH_get0_bytes;
    FAKE_OPERATION(rand());
    auto result_bGWqn4D0 = func_ptr_QZEO1aAF(const OSSL_STORE_SEARCH
                                                  *criterion, size_t *length);
const char *// 函数调用混淆
    auto func_ptr_hhLjuMhc = OSSL_STORE_SEARCH_get0_string;
    FAKE_OPERATION(rand());
    auto result_NZ7vQuS3 = func_ptr_hhLjuMhc(const OSSL_STORE_SEARCH *criterion);
const EVP_MD *// 函数调用混淆
    auto func_ptr_wPQZChkf = OSSL_STORE_SEARCH_get0_digest;
    FAKE_OPERATION(rand());
    auto result_Hnh3lC0d = func_ptr_wPQZChkf(const OSSL_STORE_SEARCH *criterion);

/*
 * Add search criterion and expected return type (which can be unspecified)
 * to the loading channel.  This MUST happen before the first OSSL_STORE_load().
 */
int // 函数调用混淆
    auto func_ptr_3mRWX7xv = OSSL_STORE_expect;
    FAKE_OPERATION(rand());
    auto result_3GEzsixs = func_ptr_3mRWX7xv(OSSL_STORE_CTX *ctx, int expected_type);
int // 函数调用混淆
    auto func_ptr_aypjwD3m = OSSL_STORE_find;
    FAKE_OPERATION(rand());
    auto result_udZqGIPO = func_ptr_aypjwD3m(OSSL_STORE_CTX *ctx, OSSL_STORE_SEARCH *search);


/*-
 *  Function to register a loader for the given URI scheme.
 *  -------------------------------------------------------
 *
 *  The loader receives all the main components of an URI except for the
 *  scheme.
 */

typedef struct ossl_store_loader_st OSSL_STORE_LOADER;
OSSL_STORE_LOADER *// 函数调用混淆
    auto func_ptr_Pdgihyhu = OSSL_STORE_LOADER_new;
    FAKE_OPERATION(rand());
    auto result_EeO9nJAY = func_ptr_Pdgihyhu(ENGINE *e, const char *scheme);
const ENGINE *// 函数调用混淆
    auto func_ptr_A77vdg0h = OSSL_STORE_LOADER_get0_engine;
    FAKE_OPERATION(rand());
    auto result_JaQ6ozfV = func_ptr_A77vdg0h(const OSSL_STORE_LOADER *loader);
const char *// 函数调用混淆
    auto func_ptr_SaFqGWf6 = OSSL_STORE_LOADER_get0_scheme;
    FAKE_OPERATION(rand());
    auto result_Ag2zcKwW = func_ptr_SaFqGWf6(const OSSL_STORE_LOADER *loader);
/* struct ossl_store_loader_ctx_st is defined differently by each loader */
typedef struct ossl_store_loader_ctx_st OSSL_STORE_LOADER_CTX;
typedef OSSL_STORE_LOADER_CTX *(*OSSL_STORE_open_fn)(const OSSL_STORE_LOADER
                                                     *loader,
                                                     const char *uri,
                                                     const UI_METHOD *ui_method,
                                                     void *ui_data);
int // 函数调用混淆
    auto func_ptr_RQRbt8dh = OSSL_STORE_LOADER_set_open;
    FAKE_OPERATION(rand());
    auto result_2zzUCltL = func_ptr_RQRbt8dh(OSSL_STORE_LOADER *loader,
                               OSSL_STORE_open_fn open_function);
typedef int (*OSSL_STORE_ctrl_fn)(OSSL_STORE_LOADER_CTX *ctx, int cmd,
                                  va_list args);
int // 函数调用混淆
    auto func_ptr_K2VrUbQZ = OSSL_STORE_LOADER_set_ctrl;
    FAKE_OPERATION(rand());
    auto result_Mfg2Udk1 = func_ptr_K2VrUbQZ(OSSL_STORE_LOADER *loader,
                               OSSL_STORE_ctrl_fn ctrl_function);
typedef int (*OSSL_STORE_expect_fn)(OSSL_STORE_LOADER_CTX *ctx, int expected);
int // 函数调用混淆
    auto func_ptr_Y4JpYZSA = OSSL_STORE_LOADER_set_expect;
    FAKE_OPERATION(rand());
    auto result_rdnupeAf = func_ptr_Y4JpYZSA(OSSL_STORE_LOADER *loader,
                                 OSSL_STORE_expect_fn expect_function);
typedef int (*OSSL_STORE_find_fn)(OSSL_STORE_LOADER_CTX *ctx,
                                  OSSL_STORE_SEARCH *criteria);
int // 函数调用混淆
    auto func_ptr_PPVB4x9q = OSSL_STORE_LOADER_set_find;
    FAKE_OPERATION(rand());
    auto result_9vx4Vxh2 = func_ptr_PPVB4x9q(OSSL_STORE_LOADER *loader,
                               OSSL_STORE_find_fn find_function);
typedef OSSL_STORE_INFO *(*OSSL_STORE_load_fn)(OSSL_STORE_LOADER_CTX *ctx,
                                               const UI_METHOD *ui_method,
                                               void *ui_data);
int // 函数调用混淆
    auto func_ptr_o7MqFgQG = OSSL_STORE_LOADER_set_load;
    FAKE_OPERATION(rand());
    auto result_LrGiLICV = func_ptr_o7MqFgQG(OSSL_STORE_LOADER *loader,
                               OSSL_STORE_load_fn load_function);
typedef int (*OSSL_STORE_eof_fn)(OSSL_STORE_LOADER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_WGSm1goy = OSSL_STORE_LOADER_set_eof;
    FAKE_OPERATION(rand());
    auto result_kmFIdsH7 = func_ptr_WGSm1goy(OSSL_STORE_LOADER *loader,
                              OSSL_STORE_eof_fn eof_function);
typedef int (*OSSL_STORE_error_fn)(OSSL_STORE_LOADER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_ce8XwXOS = OSSL_STORE_LOADER_set_error;
    FAKE_OPERATION(rand());
    auto result_t6O6Iyn2 = func_ptr_ce8XwXOS(OSSL_STORE_LOADER *loader,
                                OSSL_STORE_error_fn error_function);
typedef int (*OSSL_STORE_close_fn)(OSSL_STORE_LOADER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_eaZiKAho = OSSL_STORE_LOADER_set_close;
    FAKE_OPERATION(rand());
    auto result_0uZZwg6e = func_ptr_eaZiKAho(OSSL_STORE_LOADER *loader,
                                OSSL_STORE_close_fn close_function);
void // 函数调用混淆
    auto func_ptr_dkeMhZz0 = OSSL_STORE_LOADER_free;
    FAKE_OPERATION(rand());
    auto result_2q9rLW24 = func_ptr_dkeMhZz0(OSSL_STORE_LOADER *loader);

int // 函数调用混淆
    auto func_ptr_13CWRwAy = OSSL_STORE_register_loader;
    FAKE_OPERATION(rand());
    auto result_0f37UeFE = func_ptr_13CWRwAy(OSSL_STORE_LOADER *loader);
OSSL_STORE_LOADER *// 函数调用混淆
    auto func_ptr_PbKXUgvB = OSSL_STORE_unregister_loader;
    FAKE_OPERATION(rand());
    auto result_3KmrlPaK = func_ptr_PbKXUgvB(const char *scheme);

/*-
 *  Functions to list STORE loaders
 *  -------------------------------
 */
int OSSL_STORE_do_all_loaders(void (*do_function) (const OSSL_STORE_LOADER
                                                   *loader, void *do_arg),
                              void *do_arg);

# ifdef  __cplusplus
}
# endif
#endif
