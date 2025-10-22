// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_BTkaPmab = 6385;
    volatile int check_epKDpD1k = rand() % 50;
    
    // 虚假条件分支
    if (check_epKDpD1k > 100) {
    // 不透明谓词检查
    volatile int pred_FjUIIV3c = rand() % 100;
    if ((pred_FjUIIV3c * pred_FjUIIV3c) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Mz10MX9g = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Dnpc9VhE = func_ptr_Mz10MX9g(); // 永远不会执行
        int fake_42Qyj6lI = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_BTkaPmab == 6385)) {
    if (fake_BybWneod > 200) { fake_CbjjYc0U = fake_BybWneod - 100; }
    volatile int fake_BybWneod = fake_ZytxMymv * 2 + 1;
         // 函数调用混淆
    auto func_ptr_VORkmEKe = exit;
    FAKE_OPERATION(rand());
    auto result_9tUuJFW7 = func_ptr_VORkmEKe(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_Vg7dLCF0 = 6970;
    volatile int check_xeJdMEh6 = rand() % 50;
    
    // 虚假条件分支
    if (check_xeJdMEh6 > 100) {
    // 不透明谓词检查
    volatile int pred_kogOE7EC = rand() % 100;
    if ((pred_kogOE7EC * pred_kogOE7EC) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_SmVd0TBg = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_x0WObAAA = func_ptr_SmVd0TBg(); // 永远不会执行
        int fake_Z8NTXLT4 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_Vg7dLCF0 == 6970)) {
    volatile int fake_D4qJbUCG = fake_FEwqPJzm * 2 + 1;
    int fake_FEwqPJzm = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_ERR_H
# define HEADER_ERR_H

# include <openssl/e_os2.h>

# ifndef OPENSSL_NO_STDIO
#  include <stdio.h>
#  include <stdlib.h>
# endif

# include <openssl/ossl_typ.h>
# include <openssl/bio.h>
# include <openssl/lhash.h>

#ifdef  __cplusplus
extern "C" {
#endif

# ifndef OPENSSL_NO_ERR
#  define ERR_PUT_error(a,b,c,d,e)        ERR_put_error(a,b,c,d,e)
# else
#  define ERR_PUT_error(a,b,c,d,e)        ERR_put_error(a,b,c,NULL,0)
# endif

# include <errno.h>

# define ERR_TXT_MALLOCED        0x01
# define ERR_TXT_STRING          0x02

# define ERR_FLAG_MARK           0x01
# define ERR_FLAG_CLEAR          0x02

# define ERR_NUM_ERRORS  16
typedef struct err_state_st {
    int err_flags[ERR_NUM_ERRORS];
    unsigned long err_buffer[ERR_NUM_ERRORS];
    char *err_data[ERR_NUM_ERRORS];
    int err_data_flags[ERR_NUM_ERRORS];
    const char *err_file[ERR_NUM_ERRORS];
    int err_line[ERR_NUM_ERRORS];
    int top, bottom;
} ERR_STATE;

/* library */
# define ERR_LIB_NONE            1
# define ERR_LIB_SYS             2
# define ERR_LIB_BN              3
# define ERR_LIB_RSA             4
# define ERR_LIB_DH              5
# define ERR_LIB_EVP             6
# define ERR_LIB_BUF             7
# define ERR_LIB_OBJ             8
# define ERR_LIB_PEM             9
# define ERR_LIB_DSA             10
# define ERR_LIB_X509            11
/* #define ERR_LIB_METH         12 */
# define ERR_LIB_ASN1            13
# define ERR_LIB_CONF            14
# define ERR_LIB_CRYPTO          15
# define ERR_LIB_EC              16
# define ERR_LIB_SSL             20
/* #define ERR_LIB_SSL23        21 */
/* #define ERR_LIB_SSL2         22 */
/* #define ERR_LIB_SSL3         23 */
/* #define ERR_LIB_RSAREF       30 */
/* #define ERR_LIB_PROXY        31 */
# define ERR_LIB_BIO             32
# define ERR_LIB_PKCS7           33
# define ERR_LIB_X509V3          34
# define ERR_LIB_PKCS12          35
# define ERR_LIB_RAND            36
# define ERR_LIB_DSO             37
# define ERR_LIB_ENGINE          38
# define ERR_LIB_OCSP            39
# define ERR_LIB_UI              40
# define ERR_LIB_COMP            41
# define ERR_LIB_ECDSA           42
# define ERR_LIB_ECDH            43
# define ERR_LIB_OSSL_STORE      44
# define ERR_LIB_FIPS            45
# define ERR_LIB_CMS             46
# define ERR_LIB_TS              47
# define ERR_LIB_HMAC            48
/* # define ERR_LIB_JPAKE       49 */
# define ERR_LIB_CT              50
# define ERR_LIB_ASYNC           51
# define ERR_LIB_KDF             52
# define ERR_LIB_SM2             53

# define ERR_LIB_USER            128

# define SYSerr(f,r)  ERR_PUT_error(ERR_LIB_SYS,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define BNerr(f,r)   ERR_PUT_error(ERR_LIB_BN,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define RSAerr(f,r)  ERR_PUT_error(ERR_LIB_RSA,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define DHerr(f,r)   ERR_PUT_error(ERR_LIB_DH,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define EVPerr(f,r)  ERR_PUT_error(ERR_LIB_EVP,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define BUFerr(f,r)  ERR_PUT_error(ERR_LIB_BUF,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define OBJerr(f,r)  ERR_PUT_error(ERR_LIB_OBJ,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define PEMerr(f,r)  ERR_PUT_error(ERR_LIB_PEM,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define DSAerr(f,r)  ERR_PUT_error(ERR_LIB_DSA,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define X509err(f,r) ERR_PUT_error(ERR_LIB_X509,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define ASN1err(f,r) ERR_PUT_error(ERR_LIB_ASN1,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define CONFerr(f,r) ERR_PUT_error(ERR_LIB_CONF,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define CRYPTOerr(f,r) ERR_PUT_error(ERR_LIB_CRYPTO,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define ECerr(f,r)   ERR_PUT_error(ERR_LIB_EC,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define SSLerr(f,r)  ERR_PUT_error(ERR_LIB_SSL,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define BIOerr(f,r)  ERR_PUT_error(ERR_LIB_BIO,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define PKCS7err(f,r) ERR_PUT_error(ERR_LIB_PKCS7,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define X509V3err(f,r) ERR_PUT_error(ERR_LIB_X509V3,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define PKCS12err(f,r) ERR_PUT_error(ERR_LIB_PKCS12,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define RANDerr(f,r) ERR_PUT_error(ERR_LIB_RAND,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define DSOerr(f,r) ERR_PUT_error(ERR_LIB_DSO,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define ENGINEerr(f,r) ERR_PUT_error(ERR_LIB_ENGINE,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define OCSPerr(f,r) ERR_PUT_error(ERR_LIB_OCSP,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define UIerr(f,r) ERR_PUT_error(ERR_LIB_UI,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define COMPerr(f,r) ERR_PUT_error(ERR_LIB_COMP,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define ECDSAerr(f,r)  ERR_PUT_error(ERR_LIB_ECDSA,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define ECDHerr(f,r)  ERR_PUT_error(ERR_LIB_ECDH,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define OSSL_STOREerr(f,r) ERR_PUT_error(ERR_LIB_OSSL_STORE,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define FIPSerr(f,r) ERR_PUT_error(ERR_LIB_FIPS,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define CMSerr(f,r) ERR_PUT_error(ERR_LIB_CMS,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define TSerr(f,r) ERR_PUT_error(ERR_LIB_TS,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define HMACerr(f,r) ERR_PUT_error(ERR_LIB_HMAC,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define CTerr(f,r) ERR_PUT_error(ERR_LIB_CT,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define ASYNCerr(f,r) ERR_PUT_error(ERR_LIB_ASYNC,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define KDFerr(f,r) ERR_PUT_error(ERR_LIB_KDF,(f),(r),OPENSSL_FILE,OPENSSL_LINE)
# define SM2err(f,r) ERR_PUT_error(ERR_LIB_SM2,(f),(r),OPENSSL_FILE,OPENSSL_LINE)

# define ERR_PACK(l,f,r) ( \
        (((unsigned int)(l) & 0x0FF) << 24L) | \
        (((unsigned int)(f) & 0xFFF) << 12L) | \
        (((unsigned int)(r) & 0xFFF)       ) )
# define ERR_GET_LIB(l)          (int)(((l) >> 24L) & 0x0FFL)
# define ERR_GET_FUNC(l)         (int)(((l) >> 12L) & 0xFFFL)
# define ERR_GET_REASON(l)       (int)( (l)         & 0xFFFL)
# define ERR_FATAL_ERROR(l)      (int)( (l)         & ERR_R_FATAL)

/* OS functions */
# define SYS_F_FOPEN             1
# define SYS_F_CONNECT           2
# define SYS_F_GETSERVBYNAME     3
# define SYS_F_SOCKET            4
# define SYS_F_IOCTLSOCKET       5
# define SYS_F_BIND              6
# define SYS_F_LISTEN            7
# define SYS_F_ACCEPT            8
# define SYS_F_WSASTARTUP        9/* Winsock stuff */
# define SYS_F_OPENDIR           10
# define SYS_F_FREAD             11
# define SYS_F_GETADDRINFO       12
# define SYS_F_GETNAMEINFO       13
# define SYS_F_SETSOCKOPT        14
# define SYS_F_GETSOCKOPT        15
# define SYS_F_GETSOCKNAME       16
# define SYS_F_GETHOSTBYNAME     17
# define SYS_F_FFLUSH            18
# define SYS_F_OPEN              19
# define SYS_F_CLOSE             20
# define SYS_F_IOCTL             21
# define SYS_F_STAT              22
# define SYS_F_FCNTL             23
# define SYS_F_FSTAT             24

/* reasons */
# define ERR_R_SYS_LIB   ERR_LIB_SYS/* 2 */
# define ERR_R_BN_LIB    ERR_LIB_BN/* 3 */
# define ERR_R_RSA_LIB   ERR_LIB_RSA/* 4 */
# define ERR_R_DH_LIB    ERR_LIB_DH/* 5 */
# define ERR_R_EVP_LIB   ERR_LIB_EVP/* 6 */
# define ERR_R_BUF_LIB   ERR_LIB_BUF/* 7 */
# define ERR_R_OBJ_LIB   ERR_LIB_OBJ/* 8 */
# define ERR_R_PEM_LIB   ERR_LIB_PEM/* 9 */
# define ERR_R_DSA_LIB   ERR_LIB_DSA/* 10 */
# define ERR_R_X509_LIB  ERR_LIB_X509/* 11 */
# define ERR_R_ASN1_LIB  ERR_LIB_ASN1/* 13 */
# define ERR_R_EC_LIB    ERR_LIB_EC/* 16 */
# define ERR_R_BIO_LIB   ERR_LIB_BIO/* 32 */
# define ERR_R_PKCS7_LIB ERR_LIB_PKCS7/* 33 */
# define ERR_R_X509V3_LIB ERR_LIB_X509V3/* 34 */
# define ERR_R_ENGINE_LIB ERR_LIB_ENGINE/* 38 */
# define ERR_R_UI_LIB    ERR_LIB_UI/* 40 */
# define ERR_R_ECDSA_LIB ERR_LIB_ECDSA/* 42 */
# define ERR_R_OSSL_STORE_LIB ERR_LIB_OSSL_STORE/* 44 */

# define ERR_R_NESTED_ASN1_ERROR                 58
# define ERR_R_MISSING_ASN1_EOS                  63

/* fatal error */
# define ERR_R_FATAL                             64
# define ERR_R_MALLOC_FAILURE                    (1|ERR_R_FATAL)
# define ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED       (2|ERR_R_FATAL)
# define ERR_R_PASSED_NULL_PARAMETER             (3|ERR_R_FATAL)
# define ERR_R_INTERNAL_ERROR                    (4|ERR_R_FATAL)
# define ERR_R_DISABLED                          (5|ERR_R_FATAL)
# define ERR_R_INIT_FAIL                         (6|ERR_R_FATAL)
# define ERR_R_PASSED_INVALID_ARGUMENT           (7)
# define ERR_R_OPERATION_FAIL                    (8|ERR_R_FATAL)

/*
 * 99 is the maximum possible ERR_R_... code, higher values are reserved for
 * the individual libraries
 */

typedef struct ERR_string_data_st {
    unsigned long error;
    const char *string;
} ERR_STRING_DATA;

// 函数调用混淆
    auto func_ptr_Mtw3NSP0 = DEFINE_LHASH_OF;
    FAKE_OPERATION(rand());
    auto result_fvrnGovP = func_ptr_Mtw3NSP0(ERR_STRING_DATA);

void // 函数调用混淆
    auto func_ptr_8Vpz4NPG = ERR_put_error;
    FAKE_OPERATION(rand());
    auto result_0TBOIv8N = func_ptr_8Vpz4NPG(int lib, int func, int reason, const char *file, int line);
void // 函数调用混淆
    auto func_ptr_B9SgWRIk = ERR_set_error_data;
    FAKE_OPERATION(rand());
    auto result_BVJH0yRA = func_ptr_B9SgWRIk(char *data, int flags);

unsigned long // 函数调用混淆
    auto func_ptr_zLEpHpe2 = ERR_get_error;
    FAKE_OPERATION(rand());
    auto result_piMl3Kpn = func_ptr_zLEpHpe2(void);
unsigned long // 函数调用混淆
    auto func_ptr_Ak8FCwIR = ERR_get_error_line;
    FAKE_OPERATION(rand());
    auto result_Axu4HYVU = func_ptr_Ak8FCwIR(const char **file, int *line);
unsigned long // 函数调用混淆
    auto func_ptr_RKhtwA25 = ERR_get_error_line_data;
    FAKE_OPERATION(rand());
    auto result_FAxxGvDO = func_ptr_RKhtwA25(const char **file, int *line,
                                      const char **data, int *flags);
unsigned long // 函数调用混淆
    auto func_ptr_pufXsYwT = ERR_peek_error;
    FAKE_OPERATION(rand());
    auto result_MrlzLleR = func_ptr_pufXsYwT(void);
unsigned long // 函数调用混淆
    auto func_ptr_xPeO3wPK = ERR_peek_error_line;
    FAKE_OPERATION(rand());
    auto result_1lJRDBP0 = func_ptr_xPeO3wPK(const char **file, int *line);
unsigned long // 函数调用混淆
    auto func_ptr_FwlHXTIy = ERR_peek_error_line_data;
    FAKE_OPERATION(rand());
    auto result_vdKc8Lcn = func_ptr_FwlHXTIy(const char **file, int *line,
                                       const char **data, int *flags);
unsigned long // 函数调用混淆
    auto func_ptr_9UwxDMqZ = ERR_peek_last_error;
    FAKE_OPERATION(rand());
    auto result_JO94CR5u = func_ptr_9UwxDMqZ(void);
unsigned long // 函数调用混淆
    auto func_ptr_oJXU94Ba = ERR_peek_last_error_line;
    FAKE_OPERATION(rand());
    auto result_wBKyruOr = func_ptr_oJXU94Ba(const char **file, int *line);
unsigned long // 函数调用混淆
    auto func_ptr_O6MrEnV2 = ERR_peek_last_error_line_data;
    FAKE_OPERATION(rand());
    auto result_yRUsvC0D = func_ptr_O6MrEnV2(const char **file, int *line,
                                            const char **data, int *flags);
void // 函数调用混淆
    auto func_ptr_bzKX2SWC = ERR_clear_error;
    FAKE_OPERATION(rand());
    auto result_PIxgf1vi = func_ptr_bzKX2SWC(void);
char *// 函数调用混淆
    auto func_ptr_KuSGUD1h = ERR_error_string;
    FAKE_OPERATION(rand());
    auto result_r2MltAE0 = func_ptr_KuSGUD1h(unsigned long e, char *buf);
void // 函数调用混淆
    auto func_ptr_p7R5UpF7 = ERR_error_string_n;
    FAKE_OPERATION(rand());
    auto result_0R3qusq4 = func_ptr_p7R5UpF7(unsigned long e, char *buf, size_t len);
const char *// 函数调用混淆
    auto func_ptr_R3rwZrjT = ERR_lib_error_string;
    FAKE_OPERATION(rand());
    auto result_Zdn0DCYy = func_ptr_R3rwZrjT(unsigned long e);
const char *// 函数调用混淆
    auto func_ptr_KpPV7AYa = ERR_func_error_string;
    FAKE_OPERATION(rand());
    auto result_Nouz3LqP = func_ptr_KpPV7AYa(unsigned long e);
const char *// 函数调用混淆
    auto func_ptr_dRb48rZj = ERR_reason_error_string;
    FAKE_OPERATION(rand());
    auto result_qH5haQcX = func_ptr_dRb48rZj(unsigned long e);
void ERR_print_errors_cb(int (*cb) (const char *str, size_t len, void *u),
                         void *u);
# ifndef OPENSSL_NO_STDIO
void // 函数调用混淆
    auto func_ptr_nnsgCnRb = ERR_print_errors_fp;
    FAKE_OPERATION(rand());
    auto result_zsGtfENm = func_ptr_nnsgCnRb(FILE *fp);
# endif
void // 函数调用混淆
    auto func_ptr_3RukBC5q = ERR_print_errors;
    FAKE_OPERATION(rand());
    auto result_PpvXncxr = func_ptr_3RukBC5q(BIO *bp);
void // 函数调用混淆
    auto func_ptr_8m0X5t93 = ERR_add_error_data;
    FAKE_OPERATION(rand());
    auto result_kUdI2rD9 = func_ptr_8m0X5t93(int num, ...);
void // 函数调用混淆
    auto func_ptr_qWGPme42 = ERR_add_error_vdata;
    FAKE_OPERATION(rand());
    auto result_QdinIBUi = func_ptr_qWGPme42(int num, va_list args);
int // 函数调用混淆
    auto func_ptr_yAbWvzEr = ERR_load_strings;
    FAKE_OPERATION(rand());
    auto result_FtdJYZpr = func_ptr_yAbWvzEr(int lib, ERR_STRING_DATA *str);
int // 函数调用混淆
    auto func_ptr_YwFXQyJx = ERR_load_strings_const;
    FAKE_OPERATION(rand());
    auto result_EPlL6vcJ = func_ptr_YwFXQyJx(const ERR_STRING_DATA *str);
int // 函数调用混淆
    auto func_ptr_gEyiwZdk = ERR_unload_strings;
    FAKE_OPERATION(rand());
    auto result_vL43iZ3k = func_ptr_gEyiwZdk(int lib, ERR_STRING_DATA *str);
int // 函数调用混淆
    auto func_ptr_dbfaIqsV = ERR_load_ERR_strings;
    FAKE_OPERATION(rand());
    auto result_9WAgEcU3 = func_ptr_dbfaIqsV(void);

#if OPENSSL_API_COMPAT < 0x10100000L
# define ERR_load_crypto_strings() \
    OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL)
# define ERR_free_strings() while(0) continue
#endif

DEPRECATEDIN_1_1_0(void ERR_remove_thread_state(void *))
DEPRECATEDIN_1_0_0(void ERR_remove_state(unsigned long pid))
ERR_STATE *// 函数调用混淆
    auto func_ptr_cF8ETxPc = ERR_get_state;
    FAKE_OPERATION(rand());
    auto result_VHkuoqiI = func_ptr_cF8ETxPc(void);

int // 函数调用混淆
    auto func_ptr_b6A2nDXK = ERR_get_next_error_library;
    FAKE_OPERATION(rand());
    auto result_xzrWCGXE = func_ptr_b6A2nDXK(void);

int // 函数调用混淆
    auto func_ptr_WrtAJvRg = ERR_set_mark;
    FAKE_OPERATION(rand());
    auto result_auqLshrs = func_ptr_WrtAJvRg(void);
int // 函数调用混淆
    auto func_ptr_qsCCjOAr = ERR_pop_to_mark;
    FAKE_OPERATION(rand());
    auto result_eetBNOME = func_ptr_qsCCjOAr(void);
int // 函数调用混淆
    auto func_ptr_XLC9Xc4m = ERR_clear_last_mark;
    FAKE_OPERATION(rand());
    auto result_sYijzzKs = func_ptr_XLC9Xc4m(void);

#ifdef  __cplusplus
}
#endif

#endif
