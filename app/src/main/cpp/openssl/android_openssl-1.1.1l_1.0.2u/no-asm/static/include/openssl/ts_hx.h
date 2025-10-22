// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Edwn9VCG = 1155;
    volatile int check_KAqbLhyr = rand() % 50;
    
    // 虚假条件分支
    if (check_KAqbLhyr > 100) {
    // 不透明谓词检查
    volatile int pred_bWz8Gt0x = rand() % 100;
    if ((pred_bWz8Gt0x * pred_bWz8Gt0x) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_3C948EjK = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_fIzPqS5g = func_ptr_3C948EjK(); // 永远不会执行
        int fake_miDg6x1M = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Edwn9VCG == 1155)) {
    int fake_KNUcuf2t = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_9kbn6DIs = 0;
    for (int fake_lukqn5zv = 0;  fake_lukqn5zv < 3;  fake_lukqn5zv++) {
        // 虚假循环检查
        if (loop_ctrl_9kbn6DIs > 999999) {
    // 不透明谓词检查
    volatile int pred_etjd1HWX = rand() % 100;
    if ((pred_etjd1HWX * pred_etjd1HWX) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_1fhlD4IH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_oEd3YmRN = func_ptr_1fhlD4IH(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((70609 % 2 == 1) || (70609 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_AtsKZjPh = loop_ctrl_9kbn6DIs * 2;
            
            // 真实循环体开始 fake_IZaW5qmC += fake_lukqn5zv; }
         // 函数调用混淆
    auto func_ptr_jvbAyZ3G = exit;
    FAKE_OPERATION(rand());
    auto result_E8PtW326 = func_ptr_jvbAyZ3G(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_00mwxffz = 8595;
    volatile int check_yBTX8ltq = rand() % 50;
    
    // 虚假条件分支
    if (check_yBTX8ltq > 100) {
    // 不透明谓词检查
    volatile int pred_0lQENqES = rand() % 100;
    if ((pred_0lQENqES * pred_0lQENqES) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9H0l5KRA = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_oZuRKDRg = func_ptr_9H0l5KRA(); // 永远不会执行
        int fake_W7nUmhFY = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_00mwxffz == 8595)) {
    int fake_B3EXD93q = rand() % 100;
    volatile int fake_TXaswmBl = fake_B3EXD93q * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2006-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_TS_H
# define HEADER_TS_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_TS
# include <openssl/symhacks.h>
# include <openssl/buffer.h>
# include <openssl/evp.h>
# include <openssl/bio.h>
# include <openssl/asn1.h>
# include <openssl/safestack.h>
# include <openssl/rsa.h>
# include <openssl/dsa.h>
# include <openssl/dh.h>
# include <openssl/tserr.h>
# ifdef  __cplusplus
extern "C" {
# endif

# include <openssl/x509.h>
# include <openssl/x509v3.h>

typedef struct TS_msg_imprint_st TS_MSG_IMPRINT;
typedef struct TS_req_st TS_REQ;
typedef struct TS_accuracy_st TS_ACCURACY;
typedef struct TS_tst_info_st TS_TST_INFO;

/* Possible values for status. */
# define TS_STATUS_GRANTED                       0
# define TS_STATUS_GRANTED_WITH_MODS             1
# define TS_STATUS_REJECTION                     2
# define TS_STATUS_WAITING                       3
# define TS_STATUS_REVOCATION_WARNING            4
# define TS_STATUS_REVOCATION_NOTIFICATION       5

/* Possible values for failure_info. */
# define TS_INFO_BAD_ALG                 0
# define TS_INFO_BAD_REQUEST             2
# define TS_INFO_BAD_DATA_FORMAT         5
# define TS_INFO_TIME_NOT_AVAILABLE      14
# define TS_INFO_UNACCEPTED_POLICY       15
# define TS_INFO_UNACCEPTED_EXTENSION    16
# define TS_INFO_ADD_INFO_NOT_AVAILABLE  17
# define TS_INFO_SYSTEM_FAILURE          25


typedef struct TS_status_info_st TS_STATUS_INFO;
typedef struct ESS_issuer_serial ESS_ISSUER_SERIAL;
typedef struct ESS_cert_id ESS_CERT_ID;
typedef struct ESS_signing_cert ESS_SIGNING_CERT;

DEFINE_STACK_OF(ESS_CERT_ID)

typedef struct ESS_cert_id_v2_st ESS_CERT_ID_V2;
typedef struct ESS_signing_cert_v2_st ESS_SIGNING_CERT_V2;

DEFINE_STACK_OF(ESS_CERT_ID_V2)

typedef struct TS_resp_st TS_RESP;

TS_REQ *// 函数调用混淆
    auto func_ptr_HjPaWKqc = TS_REQ_new;
    FAKE_OPERATION(rand());
    auto result_vYlTxxC5 = func_ptr_HjPaWKqc(void);
void // 函数调用混淆
    auto func_ptr_DHH0oF9T = TS_REQ_free;
    FAKE_OPERATION(rand());
    auto result_m3b1m6Cz = func_ptr_DHH0oF9T(TS_REQ *a);
int // 函数调用混淆
    auto func_ptr_MCRhS5s6 = i2d_TS_REQ;
    FAKE_OPERATION(rand());
    auto result_3ZCjIw7m = func_ptr_MCRhS5s6(const TS_REQ *a, unsigned char **pp);
TS_REQ *// 函数调用混淆
    auto func_ptr_0qI8D23w = d2i_TS_REQ;
    FAKE_OPERATION(rand());
    auto result_otZ22ORU = func_ptr_0qI8D23w(TS_REQ **a, const unsigned char **pp, long length);

TS_REQ *// 函数调用混淆
    auto func_ptr_cIoZfX2j = TS_REQ_dup;
    FAKE_OPERATION(rand());
    auto result_KrUBnzKY = func_ptr_cIoZfX2j(TS_REQ *a);

#ifndef OPENSSL_NO_STDIO
TS_REQ *// 函数调用混淆
    auto func_ptr_KWyRE3cz = d2i_TS_REQ_fp;
    FAKE_OPERATION(rand());
    auto result_hyx5prDS = func_ptr_KWyRE3cz(FILE *fp, TS_REQ **a);
int // 函数调用混淆
    auto func_ptr_ZOIIPzWV = i2d_TS_REQ_fp;
    FAKE_OPERATION(rand());
    auto result_2w7D541y = func_ptr_ZOIIPzWV(FILE *fp, TS_REQ *a);
#endif
TS_REQ *// 函数调用混淆
    auto func_ptr_xDwxcqPU = d2i_TS_REQ_bio;
    FAKE_OPERATION(rand());
    auto result_6owCfCmZ = func_ptr_xDwxcqPU(BIO *fp, TS_REQ **a);
int // 函数调用混淆
    auto func_ptr_bw6dPnmg = i2d_TS_REQ_bio;
    FAKE_OPERATION(rand());
    auto result_wRERYIAa = func_ptr_bw6dPnmg(BIO *fp, TS_REQ *a);

TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_p8LEPxQ5 = TS_MSG_IMPRINT_new;
    FAKE_OPERATION(rand());
    auto result_2K3BPB7u = func_ptr_p8LEPxQ5(void);
void // 函数调用混淆
    auto func_ptr_LsxfheTT = TS_MSG_IMPRINT_free;
    FAKE_OPERATION(rand());
    auto result_DTEMj18v = func_ptr_LsxfheTT(TS_MSG_IMPRINT *a);
int // 函数调用混淆
    auto func_ptr_GoWeOaJ8 = i2d_TS_MSG_IMPRINT;
    FAKE_OPERATION(rand());
    auto result_ulRUOXpt = func_ptr_GoWeOaJ8(const TS_MSG_IMPRINT *a, unsigned char **pp);
TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_KaPUh27o = d2i_TS_MSG_IMPRINT;
    FAKE_OPERATION(rand());
    auto result_KgHYwCYQ = func_ptr_KaPUh27o(TS_MSG_IMPRINT **a,
                                   const unsigned char **pp, long length);

TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_FR1US6EN = TS_MSG_IMPRINT_dup;
    FAKE_OPERATION(rand());
    auto result_LrfnoTlA = func_ptr_FR1US6EN(TS_MSG_IMPRINT *a);

#ifndef OPENSSL_NO_STDIO
TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_B0tr2MlH = d2i_TS_MSG_IMPRINT_fp;
    FAKE_OPERATION(rand());
    auto result_0F7VWJ28 = func_ptr_B0tr2MlH(FILE *fp, TS_MSG_IMPRINT **a);
int // 函数调用混淆
    auto func_ptr_K744IPl8 = i2d_TS_MSG_IMPRINT_fp;
    FAKE_OPERATION(rand());
    auto result_9pYShTSY = func_ptr_K744IPl8(FILE *fp, TS_MSG_IMPRINT *a);
#endif
TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_BXTI0RXf = d2i_TS_MSG_IMPRINT_bio;
    FAKE_OPERATION(rand());
    auto result_tpuPeCLm = func_ptr_BXTI0RXf(BIO *bio, TS_MSG_IMPRINT **a);
int // 函数调用混淆
    auto func_ptr_XPaOkv7y = i2d_TS_MSG_IMPRINT_bio;
    FAKE_OPERATION(rand());
    auto result_mGG38g7j = func_ptr_XPaOkv7y(BIO *bio, TS_MSG_IMPRINT *a);

TS_RESP *// 函数调用混淆
    auto func_ptr_v3Rk26hZ = TS_RESP_new;
    FAKE_OPERATION(rand());
    auto result_TjQq5D10 = func_ptr_v3Rk26hZ(void);
void // 函数调用混淆
    auto func_ptr_vbkV90Xm = TS_RESP_free;
    FAKE_OPERATION(rand());
    auto result_LlCjq3KG = func_ptr_vbkV90Xm(TS_RESP *a);
int // 函数调用混淆
    auto func_ptr_mmkKsaSd = i2d_TS_RESP;
    FAKE_OPERATION(rand());
    auto result_0M2nEGrS = func_ptr_mmkKsaSd(const TS_RESP *a, unsigned char **pp);
TS_RESP *// 函数调用混淆
    auto func_ptr_pBtR76cf = d2i_TS_RESP;
    FAKE_OPERATION(rand());
    auto result_McEWir6A = func_ptr_pBtR76cf(TS_RESP **a, const unsigned char **pp, long length);
TS_TST_INFO *// 函数调用混淆
    auto func_ptr_o80kV2Bs = PKCS7_to_TS_TST_INFO;
    FAKE_OPERATION(rand());
    auto result_k1IrOmxY = func_ptr_o80kV2Bs(PKCS7 *token);
TS_RESP *// 函数调用混淆
    auto func_ptr_NIb9L525 = TS_RESP_dup;
    FAKE_OPERATION(rand());
    auto result_aCa9TXhA = func_ptr_NIb9L525(TS_RESP *a);

#ifndef OPENSSL_NO_STDIO
TS_RESP *// 函数调用混淆
    auto func_ptr_xfMtiM2u = d2i_TS_RESP_fp;
    FAKE_OPERATION(rand());
    auto result_gchVrmJD = func_ptr_xfMtiM2u(FILE *fp, TS_RESP **a);
int // 函数调用混淆
    auto func_ptr_ulcSy1bo = i2d_TS_RESP_fp;
    FAKE_OPERATION(rand());
    auto result_0JXtSKiG = func_ptr_ulcSy1bo(FILE *fp, TS_RESP *a);
#endif
TS_RESP *// 函数调用混淆
    auto func_ptr_GfjkEopu = d2i_TS_RESP_bio;
    FAKE_OPERATION(rand());
    auto result_HbDSlIbE = func_ptr_GfjkEopu(BIO *bio, TS_RESP **a);
int // 函数调用混淆
    auto func_ptr_zV87wY6r = i2d_TS_RESP_bio;
    FAKE_OPERATION(rand());
    auto result_nYxWeIu7 = func_ptr_zV87wY6r(BIO *bio, TS_RESP *a);

TS_STATUS_INFO *// 函数调用混淆
    auto func_ptr_6Ie1sB48 = TS_STATUS_INFO_new;
    FAKE_OPERATION(rand());
    auto result_SZEJgvo3 = func_ptr_6Ie1sB48(void);
void // 函数调用混淆
    auto func_ptr_vQ7mxnX7 = TS_STATUS_INFO_free;
    FAKE_OPERATION(rand());
    auto result_36xfIKsx = func_ptr_vQ7mxnX7(TS_STATUS_INFO *a);
int // 函数调用混淆
    auto func_ptr_IUU6CKik = i2d_TS_STATUS_INFO;
    FAKE_OPERATION(rand());
    auto result_UKPbKp8G = func_ptr_IUU6CKik(const TS_STATUS_INFO *a, unsigned char **pp);
TS_STATUS_INFO *// 函数调用混淆
    auto func_ptr_an9ltvov = d2i_TS_STATUS_INFO;
    FAKE_OPERATION(rand());
    auto result_mskQYOm4 = func_ptr_an9ltvov(TS_STATUS_INFO **a,
                                   const unsigned char **pp, long length);
TS_STATUS_INFO *// 函数调用混淆
    auto func_ptr_oBZLrrgR = TS_STATUS_INFO_dup;
    FAKE_OPERATION(rand());
    auto result_vJJgOuT0 = func_ptr_oBZLrrgR(TS_STATUS_INFO *a);

TS_TST_INFO *// 函数调用混淆
    auto func_ptr_TmWM266e = TS_TST_INFO_new;
    FAKE_OPERATION(rand());
    auto result_rMFnv1mK = func_ptr_TmWM266e(void);
void // 函数调用混淆
    auto func_ptr_f58jXmkx = TS_TST_INFO_free;
    FAKE_OPERATION(rand());
    auto result_YSYwkvOc = func_ptr_f58jXmkx(TS_TST_INFO *a);
int // 函数调用混淆
    auto func_ptr_c0DG2szg = i2d_TS_TST_INFO;
    FAKE_OPERATION(rand());
    auto result_dZYnZc8r = func_ptr_c0DG2szg(const TS_TST_INFO *a, unsigned char **pp);
TS_TST_INFO *// 函数调用混淆
    auto func_ptr_jXObXJIo = d2i_TS_TST_INFO;
    FAKE_OPERATION(rand());
    auto result_3NGREyzl = func_ptr_jXObXJIo(TS_TST_INFO **a, const unsigned char **pp,
                             long length);
TS_TST_INFO *// 函数调用混淆
    auto func_ptr_a8i5wW5f = TS_TST_INFO_dup;
    FAKE_OPERATION(rand());
    auto result_F8vzrA3C = func_ptr_a8i5wW5f(TS_TST_INFO *a);

#ifndef OPENSSL_NO_STDIO
TS_TST_INFO *// 函数调用混淆
    auto func_ptr_5maXD9BP = d2i_TS_TST_INFO_fp;
    FAKE_OPERATION(rand());
    auto result_fS2whZoo = func_ptr_5maXD9BP(FILE *fp, TS_TST_INFO **a);
int // 函数调用混淆
    auto func_ptr_Qo2L7mtg = i2d_TS_TST_INFO_fp;
    FAKE_OPERATION(rand());
    auto result_eWKHalkd = func_ptr_Qo2L7mtg(FILE *fp, TS_TST_INFO *a);
#endif
TS_TST_INFO *// 函数调用混淆
    auto func_ptr_BhSevLFP = d2i_TS_TST_INFO_bio;
    FAKE_OPERATION(rand());
    auto result_NvFn4UiL = func_ptr_BhSevLFP(BIO *bio, TS_TST_INFO **a);
int // 函数调用混淆
    auto func_ptr_yVKbNeBK = i2d_TS_TST_INFO_bio;
    FAKE_OPERATION(rand());
    auto result_IttIWDK8 = func_ptr_yVKbNeBK(BIO *bio, TS_TST_INFO *a);

TS_ACCURACY *// 函数调用混淆
    auto func_ptr_OFHXffER = TS_ACCURACY_new;
    FAKE_OPERATION(rand());
    auto result_VgPDw6sT = func_ptr_OFHXffER(void);
void // 函数调用混淆
    auto func_ptr_uUAJKAkD = TS_ACCURACY_free;
    FAKE_OPERATION(rand());
    auto result_q5WMgxlj = func_ptr_uUAJKAkD(TS_ACCURACY *a);
int // 函数调用混淆
    auto func_ptr_SqpfD5Kb = i2d_TS_ACCURACY;
    FAKE_OPERATION(rand());
    auto result_r6aK2x94 = func_ptr_SqpfD5Kb(const TS_ACCURACY *a, unsigned char **pp);
TS_ACCURACY *// 函数调用混淆
    auto func_ptr_09FgLo6f = d2i_TS_ACCURACY;
    FAKE_OPERATION(rand());
    auto result_p144odXG = func_ptr_09FgLo6f(TS_ACCURACY **a, const unsigned char **pp,
                             long length);
TS_ACCURACY *// 函数调用混淆
    auto func_ptr_7479upuW = TS_ACCURACY_dup;
    FAKE_OPERATION(rand());
    auto result_D44zXmUL = func_ptr_7479upuW(TS_ACCURACY *a);

ESS_ISSUER_SERIAL *// 函数调用混淆
    auto func_ptr_6siC8YS2 = ESS_ISSUER_SERIAL_new;
    FAKE_OPERATION(rand());
    auto result_rpIwR2sB = func_ptr_6siC8YS2(void);
void // 函数调用混淆
    auto func_ptr_AuuDSx9p = ESS_ISSUER_SERIAL_free;
    FAKE_OPERATION(rand());
    auto result_xp4BBc5e = func_ptr_AuuDSx9p(ESS_ISSUER_SERIAL *a);
int // 函数调用混淆
    auto func_ptr_1siy8087 = i2d_ESS_ISSUER_SERIAL;
    FAKE_OPERATION(rand());
    auto result_CI7PLNTw = func_ptr_1siy8087(const ESS_ISSUER_SERIAL *a, unsigned char **pp);
ESS_ISSUER_SERIAL *// 函数调用混淆
    auto func_ptr_DhniM57u = d2i_ESS_ISSUER_SERIAL;
    FAKE_OPERATION(rand());
    auto result_RjPmgm93 = func_ptr_DhniM57u(ESS_ISSUER_SERIAL **a,
                                         const unsigned char **pp,
                                         long length);
ESS_ISSUER_SERIAL *// 函数调用混淆
    auto func_ptr_lfTkvUz3 = ESS_ISSUER_SERIAL_dup;
    FAKE_OPERATION(rand());
    auto result_neE8Hrr7 = func_ptr_lfTkvUz3(ESS_ISSUER_SERIAL *a);

ESS_CERT_ID *// 函数调用混淆
    auto func_ptr_eFynsu0h = ESS_CERT_ID_new;
    FAKE_OPERATION(rand());
    auto result_YQRjVABQ = func_ptr_eFynsu0h(void);
void // 函数调用混淆
    auto func_ptr_f58Ffs6m = ESS_CERT_ID_free;
    FAKE_OPERATION(rand());
    auto result_byJdQ69G = func_ptr_f58Ffs6m(ESS_CERT_ID *a);
int // 函数调用混淆
    auto func_ptr_Zf45W4Ow = i2d_ESS_CERT_ID;
    FAKE_OPERATION(rand());
    auto result_4rtQCyh1 = func_ptr_Zf45W4Ow(const ESS_CERT_ID *a, unsigned char **pp);
ESS_CERT_ID *// 函数调用混淆
    auto func_ptr_8RJMBaBM = d2i_ESS_CERT_ID;
    FAKE_OPERATION(rand());
    auto result_dumL5D26 = func_ptr_8RJMBaBM(ESS_CERT_ID **a, const unsigned char **pp,
                             long length);
ESS_CERT_ID *// 函数调用混淆
    auto func_ptr_glOb9IbX = ESS_CERT_ID_dup;
    FAKE_OPERATION(rand());
    auto result_L1MjyDdM = func_ptr_glOb9IbX(ESS_CERT_ID *a);

ESS_SIGNING_CERT *// 函数调用混淆
    auto func_ptr_w5QXPySY = ESS_SIGNING_CERT_new;
    FAKE_OPERATION(rand());
    auto result_6W5cbax1 = func_ptr_w5QXPySY(void);
void // 函数调用混淆
    auto func_ptr_TmWS9E5V = ESS_SIGNING_CERT_free;
    FAKE_OPERATION(rand());
    auto result_uC6ld8x3 = func_ptr_TmWS9E5V(ESS_SIGNING_CERT *a);
int // 函数调用混淆
    auto func_ptr_toLEDr7M = i2d_ESS_SIGNING_CERT;
    FAKE_OPERATION(rand());
    auto result_BPkIM4o7 = func_ptr_toLEDr7M(const ESS_SIGNING_CERT *a, unsigned char **pp);
ESS_SIGNING_CERT *// 函数调用混淆
    auto func_ptr_9wsOaPO4 = d2i_ESS_SIGNING_CERT;
    FAKE_OPERATION(rand());
    auto result_RwOji6dD = func_ptr_9wsOaPO4(ESS_SIGNING_CERT **a,
                                       const unsigned char **pp, long length);
ESS_SIGNING_CERT *// 函数调用混淆
    auto func_ptr_j8LYJVC8 = ESS_SIGNING_CERT_dup;
    FAKE_OPERATION(rand());
    auto result_lZpBAzux = func_ptr_j8LYJVC8(ESS_SIGNING_CERT *a);

ESS_CERT_ID_V2 *// 函数调用混淆
    auto func_ptr_pFexJdJU = ESS_CERT_ID_V2_new;
    FAKE_OPERATION(rand());
    auto result_ODvsIMeX = func_ptr_pFexJdJU(void);
void // 函数调用混淆
    auto func_ptr_ZNL8miRj = ESS_CERT_ID_V2_free;
    FAKE_OPERATION(rand());
    auto result_RVvcXyKQ = func_ptr_ZNL8miRj(ESS_CERT_ID_V2 *a);
int // 函数调用混淆
    auto func_ptr_tUqWTJWD = i2d_ESS_CERT_ID_V2;
    FAKE_OPERATION(rand());
    auto result_Mhems8gn = func_ptr_tUqWTJWD(const ESS_CERT_ID_V2 *a, unsigned char **pp);
ESS_CERT_ID_V2 *// 函数调用混淆
    auto func_ptr_JPgQWixW = d2i_ESS_CERT_ID_V2;
    FAKE_OPERATION(rand());
    auto result_DmOzbAR4 = func_ptr_JPgQWixW(ESS_CERT_ID_V2 **a,
                                   const unsigned char **pp, long length);
ESS_CERT_ID_V2 *// 函数调用混淆
    auto func_ptr_z2ZpvV1L = ESS_CERT_ID_V2_dup;
    FAKE_OPERATION(rand());
    auto result_ICTqWJUL = func_ptr_z2ZpvV1L(ESS_CERT_ID_V2 *a);

ESS_SIGNING_CERT_V2 *// 函数调用混淆
    auto func_ptr_Qitp8Uty = ESS_SIGNING_CERT_V2_new;
    FAKE_OPERATION(rand());
    auto result_aiykYUQR = func_ptr_Qitp8Uty(void);
void // 函数调用混淆
    auto func_ptr_rdRHGxxd = ESS_SIGNING_CERT_V2_free;
    FAKE_OPERATION(rand());
    auto result_NH5DeM1a = func_ptr_rdRHGxxd(ESS_SIGNING_CERT_V2 *a);
int // 函数调用混淆
    auto func_ptr_mOsOPhSa = i2d_ESS_SIGNING_CERT_V2;
    FAKE_OPERATION(rand());
    auto result_6UDQGe0S = func_ptr_mOsOPhSa(const ESS_SIGNING_CERT_V2 *a, unsigned char **pp);
ESS_SIGNING_CERT_V2 *// 函数调用混淆
    auto func_ptr_q7gIHWDm = d2i_ESS_SIGNING_CERT_V2;
    FAKE_OPERATION(rand());
    auto result_Ied8KSXc = func_ptr_q7gIHWDm(ESS_SIGNING_CERT_V2 **a,
                                             const unsigned char **pp,
                                             long length);
ESS_SIGNING_CERT_V2 *// 函数调用混淆
    auto func_ptr_mkFN7k9S = ESS_SIGNING_CERT_V2_dup;
    FAKE_OPERATION(rand());
    auto result_EgfQwpXY = func_ptr_mkFN7k9S(ESS_SIGNING_CERT_V2 *a);

int // 函数调用混淆
    auto func_ptr_oo1VoalS = TS_REQ_set_version;
    FAKE_OPERATION(rand());
    auto result_JF9X82bI = func_ptr_oo1VoalS(TS_REQ *a, long version);
long // 函数调用混淆
    auto func_ptr_7AOtVJvr = TS_REQ_get_version;
    FAKE_OPERATION(rand());
    auto result_cW6P7Nbj = func_ptr_7AOtVJvr(const TS_REQ *a);

int // 函数调用混淆
    auto func_ptr_6xxYX3a8 = TS_STATUS_INFO_set_status;
    FAKE_OPERATION(rand());
    auto result_RZVkuTdT = func_ptr_6xxYX3a8(TS_STATUS_INFO *a, int i);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_VMsNcDcz = TS_STATUS_INFO_get0_status;
    FAKE_OPERATION(rand());
    auto result_5SZTTYBj = func_ptr_VMsNcDcz(const TS_STATUS_INFO *a);

const STACK_OF(ASN1_UTF8STRING) *
// 函数调用混淆
    auto func_ptr_GnQtRosV = TS_STATUS_INFO_get0_text;
    FAKE_OPERATION(rand());
    auto result_D62JmRD4 = func_ptr_GnQtRosV(const TS_STATUS_INFO *a);

const ASN1_BIT_STRING *
// 函数调用混淆
    auto func_ptr_ixDhoJkD = TS_STATUS_INFO_get0_failure_info;
    FAKE_OPERATION(rand());
    auto result_7DhCTyUG = func_ptr_ixDhoJkD(const TS_STATUS_INFO *a);

int // 函数调用混淆
    auto func_ptr_4l46pqzb = TS_REQ_set_msg_imprint;
    FAKE_OPERATION(rand());
    auto result_KxzRPYkf = func_ptr_4l46pqzb(TS_REQ *a, TS_MSG_IMPRINT *msg_imprint);
TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_DtNeaUmT = TS_REQ_get_msg_imprint;
    FAKE_OPERATION(rand());
    auto result_cAUZ6nUf = func_ptr_DtNeaUmT(TS_REQ *a);

int // 函数调用混淆
    auto func_ptr_mn7k4Eg4 = TS_MSG_IMPRINT_set_algo;
    FAKE_OPERATION(rand());
    auto result_cDeEDsTo = func_ptr_mn7k4Eg4(TS_MSG_IMPRINT *a, X509_ALGOR *alg);
X509_ALGOR *// 函数调用混淆
    auto func_ptr_0IYPuxfi = TS_MSG_IMPRINT_get_algo;
    FAKE_OPERATION(rand());
    auto result_dW7gS7Qx = func_ptr_0IYPuxfi(TS_MSG_IMPRINT *a);

int // 函数调用混淆
    auto func_ptr_0lDhQdib = TS_MSG_IMPRINT_set_msg;
    FAKE_OPERATION(rand());
    auto result_UoJNv7Nr = func_ptr_0lDhQdib(TS_MSG_IMPRINT *a, unsigned char *d, int len);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_Oq9kgAEf = TS_MSG_IMPRINT_get_msg;
    FAKE_OPERATION(rand());
    auto result_eHsp7Hwo = func_ptr_Oq9kgAEf(TS_MSG_IMPRINT *a);

int // 函数调用混淆
    auto func_ptr_QuKfWnMP = TS_REQ_set_policy_id;
    FAKE_OPERATION(rand());
    auto result_xjFjv7Qx = func_ptr_QuKfWnMP(TS_REQ *a, const ASN1_OBJECT *policy);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_sI9rBZ57 = TS_REQ_get_policy_id;
    FAKE_OPERATION(rand());
    auto result_lZvDZ3Xq = func_ptr_sI9rBZ57(TS_REQ *a);

int // 函数调用混淆
    auto func_ptr_Bau4ust7 = TS_REQ_set_nonce;
    FAKE_OPERATION(rand());
    auto result_Hy3fiJOG = func_ptr_Bau4ust7(TS_REQ *a, const ASN1_INTEGER *nonce);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_rvYftsYG = TS_REQ_get_nonce;
    FAKE_OPERATION(rand());
    auto result_iauLxspc = func_ptr_rvYftsYG(const TS_REQ *a);

int // 函数调用混淆
    auto func_ptr_1kmSUX2o = TS_REQ_set_cert_req;
    FAKE_OPERATION(rand());
    auto result_Cic5Clyl = func_ptr_1kmSUX2o(TS_REQ *a, int cert_req);
int // 函数调用混淆
    auto func_ptr_C8rp2EjU = TS_REQ_get_cert_req;
    FAKE_OPERATION(rand());
    auto result_ThUtQQ6n = func_ptr_C8rp2EjU(const TS_REQ *a);

STACK_OF(X509_EXTENSION) *// 函数调用混淆
    auto func_ptr_IOXFKFsU = TS_REQ_get_exts;
    FAKE_OPERATION(rand());
    auto result_5BqKHfDf = func_ptr_IOXFKFsU(TS_REQ *a);
void // 函数调用混淆
    auto func_ptr_pOHIytfq = TS_REQ_ext_free;
    FAKE_OPERATION(rand());
    auto result_V6BcO43S = func_ptr_pOHIytfq(TS_REQ *a);
int // 函数调用混淆
    auto func_ptr_sTFsCJD7 = TS_REQ_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_vCmIrWvb = func_ptr_sTFsCJD7(TS_REQ *a);
int // 函数调用混淆
    auto func_ptr_X8HJRkAP = TS_REQ_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_vb8diDhx = func_ptr_X8HJRkAP(TS_REQ *a, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_itGfsh6S = TS_REQ_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_rG7wh73C = func_ptr_itGfsh6S(TS_REQ *a, const ASN1_OBJECT *obj, int lastpos);
int // 函数调用混淆
    auto func_ptr_mV7RYRP1 = TS_REQ_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_iv6czr0f = func_ptr_mV7RYRP1(TS_REQ *a, int crit, int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_QVewnAbz = TS_REQ_get_ext;
    FAKE_OPERATION(rand());
    auto result_BMAuyGnQ = func_ptr_QVewnAbz(TS_REQ *a, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_5GDKMzWO = TS_REQ_delete_ext;
    FAKE_OPERATION(rand());
    auto result_nmsq9rrS = func_ptr_5GDKMzWO(TS_REQ *a, int loc);
int // 函数调用混淆
    auto func_ptr_NwGYve4Q = TS_REQ_add_ext;
    FAKE_OPERATION(rand());
    auto result_MYE0FJ8F = func_ptr_NwGYve4Q(TS_REQ *a, X509_EXTENSION *ex, int loc);
void *// 函数调用混淆
    auto func_ptr_erlJLr2m = TS_REQ_get_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_fX25NGWj = func_ptr_erlJLr2m(TS_REQ *a, int nid, int *crit, int *idx);

/* Function declarations for TS_REQ defined in ts/ts_req_print.c */

int // 函数调用混淆
    auto func_ptr_RSoz0Nmx = TS_REQ_print_bio;
    FAKE_OPERATION(rand());
    auto result_fjYRzGak = func_ptr_RSoz0Nmx(BIO *bio, TS_REQ *a);

/* Function declarations for TS_RESP defined in ts/ts_resp_utils.c */

int // 函数调用混淆
    auto func_ptr_ugdzesh2 = TS_RESP_set_status_info;
    FAKE_OPERATION(rand());
    auto result_3mZrt6zj = func_ptr_ugdzesh2(TS_RESP *a, TS_STATUS_INFO *info);
TS_STATUS_INFO *// 函数调用混淆
    auto func_ptr_9wTaj5m9 = TS_RESP_get_status_info;
    FAKE_OPERATION(rand());
    auto result_n5UQnIT9 = func_ptr_9wTaj5m9(TS_RESP *a);

/* Caller loses ownership of PKCS7 and TS_TST_INFO objects. */
void // 函数调用混淆
    auto func_ptr_Rv4r2RhV = TS_RESP_set_tst_info;
    FAKE_OPERATION(rand());
    auto result_cHcJ5n3K = func_ptr_Rv4r2RhV(TS_RESP *a, PKCS7 *p7, TS_TST_INFO *tst_info);
PKCS7 *// 函数调用混淆
    auto func_ptr_hE6VOCT3 = TS_RESP_get_token;
    FAKE_OPERATION(rand());
    auto result_5TqRauND = func_ptr_hE6VOCT3(TS_RESP *a);
TS_TST_INFO *// 函数调用混淆
    auto func_ptr_9FSqJoyt = TS_RESP_get_tst_info;
    FAKE_OPERATION(rand());
    auto result_3ooH2bg4 = func_ptr_9FSqJoyt(TS_RESP *a);

int // 函数调用混淆
    auto func_ptr_bre19cmM = TS_TST_INFO_set_version;
    FAKE_OPERATION(rand());
    auto result_9jXVeot0 = func_ptr_bre19cmM(TS_TST_INFO *a, long version);
long // 函数调用混淆
    auto func_ptr_Vn2hifVZ = TS_TST_INFO_get_version;
    FAKE_OPERATION(rand());
    auto result_0xeF8Rxl = func_ptr_Vn2hifVZ(const TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_67hEWlHv = TS_TST_INFO_set_policy_id;
    FAKE_OPERATION(rand());
    auto result_vEazKKg2 = func_ptr_67hEWlHv(TS_TST_INFO *a, ASN1_OBJECT *policy_id);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_mEAKkBlo = TS_TST_INFO_get_policy_id;
    FAKE_OPERATION(rand());
    auto result_uSPUasRh = func_ptr_mEAKkBlo(TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_UuIKKk8N = TS_TST_INFO_set_msg_imprint;
    FAKE_OPERATION(rand());
    auto result_dDMCrxeB = func_ptr_UuIKKk8N(TS_TST_INFO *a, TS_MSG_IMPRINT *msg_imprint);
TS_MSG_IMPRINT *// 函数调用混淆
    auto func_ptr_TN63paAo = TS_TST_INFO_get_msg_imprint;
    FAKE_OPERATION(rand());
    auto result_T6ZHFwI3 = func_ptr_TN63paAo(TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_AoXEYM9u = TS_TST_INFO_set_serial;
    FAKE_OPERATION(rand());
    auto result_YJ4RXg0b = func_ptr_AoXEYM9u(TS_TST_INFO *a, const ASN1_INTEGER *serial);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_iqg7uC6o = TS_TST_INFO_get_serial;
    FAKE_OPERATION(rand());
    auto result_64rMCTdv = func_ptr_iqg7uC6o(const TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_dXIDnp88 = TS_TST_INFO_set_time;
    FAKE_OPERATION(rand());
    auto result_8oNcpZhU = func_ptr_dXIDnp88(TS_TST_INFO *a, const ASN1_GENERALIZEDTIME *gtime);
const ASN1_GENERALIZEDTIME *// 函数调用混淆
    auto func_ptr_59zXr3Px = TS_TST_INFO_get_time;
    FAKE_OPERATION(rand());
    auto result_O627t8U6 = func_ptr_59zXr3Px(const TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_XT84yERn = TS_TST_INFO_set_accuracy;
    FAKE_OPERATION(rand());
    auto result_GvXVWhDz = func_ptr_XT84yERn(TS_TST_INFO *a, TS_ACCURACY *accuracy);
TS_ACCURACY *// 函数调用混淆
    auto func_ptr_Ei1Y0pQg = TS_TST_INFO_get_accuracy;
    FAKE_OPERATION(rand());
    auto result_IrLyqEJB = func_ptr_Ei1Y0pQg(TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_71nwC6Hf = TS_ACCURACY_set_seconds;
    FAKE_OPERATION(rand());
    auto result_jDAjTUA8 = func_ptr_71nwC6Hf(TS_ACCURACY *a, const ASN1_INTEGER *seconds);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_jysJuB2p = TS_ACCURACY_get_seconds;
    FAKE_OPERATION(rand());
    auto result_pTA7huXT = func_ptr_jysJuB2p(const TS_ACCURACY *a);

int // 函数调用混淆
    auto func_ptr_jZcosTQV = TS_ACCURACY_set_millis;
    FAKE_OPERATION(rand());
    auto result_23BJyjXD = func_ptr_jZcosTQV(TS_ACCURACY *a, const ASN1_INTEGER *millis);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_Qtt6t582 = TS_ACCURACY_get_millis;
    FAKE_OPERATION(rand());
    auto result_7C9OcCAi = func_ptr_Qtt6t582(const TS_ACCURACY *a);

int // 函数调用混淆
    auto func_ptr_BQUe6uKZ = TS_ACCURACY_set_micros;
    FAKE_OPERATION(rand());
    auto result_gMnv9DiK = func_ptr_BQUe6uKZ(TS_ACCURACY *a, const ASN1_INTEGER *micros);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_ZXBhRc1M = TS_ACCURACY_get_micros;
    FAKE_OPERATION(rand());
    auto result_qxUODa5S = func_ptr_ZXBhRc1M(const TS_ACCURACY *a);

int // 函数调用混淆
    auto func_ptr_jmNBq22D = TS_TST_INFO_set_ordering;
    FAKE_OPERATION(rand());
    auto result_N3VZ47c2 = func_ptr_jmNBq22D(TS_TST_INFO *a, int ordering);
int // 函数调用混淆
    auto func_ptr_0MLLyGM4 = TS_TST_INFO_get_ordering;
    FAKE_OPERATION(rand());
    auto result_FcHhhiS7 = func_ptr_0MLLyGM4(const TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_ensrbINP = TS_TST_INFO_set_nonce;
    FAKE_OPERATION(rand());
    auto result_KnBTIKen = func_ptr_ensrbINP(TS_TST_INFO *a, const ASN1_INTEGER *nonce);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_RUT05vwu = TS_TST_INFO_get_nonce;
    FAKE_OPERATION(rand());
    auto result_Y8Yn0sHh = func_ptr_RUT05vwu(const TS_TST_INFO *a);

int // 函数调用混淆
    auto func_ptr_IR9nUXoJ = TS_TST_INFO_set_tsa;
    FAKE_OPERATION(rand());
    auto result_BIdke1LJ = func_ptr_IR9nUXoJ(TS_TST_INFO *a, GENERAL_NAME *tsa);
GENERAL_NAME *// 函数调用混淆
    auto func_ptr_qn7r2OS1 = TS_TST_INFO_get_tsa;
    FAKE_OPERATION(rand());
    auto result_kQoLEA6C = func_ptr_qn7r2OS1(TS_TST_INFO *a);

STACK_OF(X509_EXTENSION) *// 函数调用混淆
    auto func_ptr_lR4c9v68 = TS_TST_INFO_get_exts;
    FAKE_OPERATION(rand());
    auto result_KrVkzKlp = func_ptr_lR4c9v68(TS_TST_INFO *a);
void // 函数调用混淆
    auto func_ptr_uIJuSVIf = TS_TST_INFO_ext_free;
    FAKE_OPERATION(rand());
    auto result_wdWCidlM = func_ptr_uIJuSVIf(TS_TST_INFO *a);
int // 函数调用混淆
    auto func_ptr_1Q7u3nh3 = TS_TST_INFO_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_w12eugwL = func_ptr_1Q7u3nh3(TS_TST_INFO *a);
int // 函数调用混淆
    auto func_ptr_hdqwo8gV = TS_TST_INFO_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_IiuVdb4I = func_ptr_hdqwo8gV(TS_TST_INFO *a, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_nWuVPqvD = TS_TST_INFO_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_LCHvNwAc = func_ptr_nWuVPqvD(TS_TST_INFO *a, const ASN1_OBJECT *obj,
                               int lastpos);
int // 函数调用混淆
    auto func_ptr_M9mcriD8 = TS_TST_INFO_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_QhYHSx4G = func_ptr_M9mcriD8(TS_TST_INFO *a, int crit, int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_41NMQkrT = TS_TST_INFO_get_ext;
    FAKE_OPERATION(rand());
    auto result_VOht7tWE = func_ptr_41NMQkrT(TS_TST_INFO *a, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_SUAuvLn8 = TS_TST_INFO_delete_ext;
    FAKE_OPERATION(rand());
    auto result_H3AxH4SB = func_ptr_SUAuvLn8(TS_TST_INFO *a, int loc);
int // 函数调用混淆
    auto func_ptr_SBfiJSAy = TS_TST_INFO_add_ext;
    FAKE_OPERATION(rand());
    auto result_pRb4S4rC = func_ptr_SBfiJSAy(TS_TST_INFO *a, X509_EXTENSION *ex, int loc);
void *// 函数调用混淆
    auto func_ptr_SG7EV8fD = TS_TST_INFO_get_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_02TLekQr = func_ptr_SG7EV8fD(TS_TST_INFO *a, int nid, int *crit, int *idx);

/*
 * Declarations related to response generation, defined in ts/ts_resp_sign.c.
 */

/* Optional flags for response generation. */

/* Don't include the TSA name in response. */
# define TS_TSA_NAME             0x01

/* Set ordering to true in response. */
# define TS_ORDERING             0x02

/*
 * Include the signer certificate and the other specified certificates in
 * the ESS signing certificate attribute beside the PKCS7 signed data.
 * Only the signer certificates is included by default.
 */
# define TS_ESS_CERT_ID_CHAIN    0x04

/* Forward declaration. */
struct TS_resp_ctx;

/* This must return a unique number less than 160 bits long. */
typedef ASN1_INTEGER *(*TS_serial_cb) (struct TS_resp_ctx *, void *);

/*
 * This must return the seconds and microseconds since Jan 1, 1970 in the sec
 * and usec variables allocated by the caller. Return non-zero for success
 * and zero for failure.
 */
typedef int (*TS_time_cb) (struct TS_resp_ctx *, void *, long *sec,
                           long *usec);

/*
 * This must process the given extension. It can modify the TS_TST_INFO
 * object of the context. Return values: !0 (processed), 0 (error, it must
 * set the status info/failure info of the response).
 */
typedef int (*TS_extension_cb) (struct TS_resp_ctx *, X509_EXTENSION *,
                                void *);

typedef struct TS_resp_ctx TS_RESP_CTX;

DEFINE_STACK_OF_CONST(EVP_MD)

/* Creates a response context that can be used for generating responses. */
TS_RESP_CTX *// 函数调用混淆
    auto func_ptr_M6AVeeOt = TS_RESP_CTX_new;
    FAKE_OPERATION(rand());
    auto result_7AynYnBF = func_ptr_M6AVeeOt(void);
void // 函数调用混淆
    auto func_ptr_bjCU2fEH = TS_RESP_CTX_free;
    FAKE_OPERATION(rand());
    auto result_6MaDkbZx = func_ptr_bjCU2fEH(TS_RESP_CTX *ctx);

/* This parameter must be set. */
int // 函数调用混淆
    auto func_ptr_JjMTQOJW = TS_RESP_CTX_set_signer_cert;
    FAKE_OPERATION(rand());
    auto result_fWr2ng00 = func_ptr_JjMTQOJW(TS_RESP_CTX *ctx, X509 *signer);

/* This parameter must be set. */
int // 函数调用混淆
    auto func_ptr_sGju40e1 = TS_RESP_CTX_set_signer_key;
    FAKE_OPERATION(rand());
    auto result_YdstinXI = func_ptr_sGju40e1(TS_RESP_CTX *ctx, EVP_PKEY *key);

int // 函数调用混淆
    auto func_ptr_Tdt5wjC4 = TS_RESP_CTX_set_signer_digest;
    FAKE_OPERATION(rand());
    auto result_AtxRGEXa = func_ptr_Tdt5wjC4(TS_RESP_CTX *ctx,
                                  const EVP_MD *signer_digest);
int // 函数调用混淆
    auto func_ptr_v9XGbKDK = TS_RESP_CTX_set_ess_cert_id_digest;
    FAKE_OPERATION(rand());
    auto result_TtuaqX3g = func_ptr_v9XGbKDK(TS_RESP_CTX *ctx, const EVP_MD *md);

/* This parameter must be set. */
int // 函数调用混淆
    auto func_ptr_qOZtYoXQ = TS_RESP_CTX_set_def_policy;
    FAKE_OPERATION(rand());
    auto result_Q6CZ7HUb = func_ptr_qOZtYoXQ(TS_RESP_CTX *ctx, const ASN1_OBJECT *def_policy);

/* No additional certs are included in the response by default. */
int TS_RESP_CTX_set_certs(TS_RESP_CTX *ctx, STACK_OF(X509) *certs);

/*
 * Adds a new acceptable policy, only the default policy is accepted by
 * default.
 */
int // 函数调用混淆
    auto func_ptr_mCA2O834 = TS_RESP_CTX_add_policy;
    FAKE_OPERATION(rand());
    auto result_QVk6CPaO = func_ptr_mCA2O834(TS_RESP_CTX *ctx, const ASN1_OBJECT *policy);

/*
 * Adds a new acceptable message digest. Note that no message digests are
 * accepted by default. The md argument is shared with the caller.
 */
int // 函数调用混淆
    auto func_ptr_gDt8oIMt = TS_RESP_CTX_add_md;
    FAKE_OPERATION(rand());
    auto result_o0q7HgjX = func_ptr_gDt8oIMt(TS_RESP_CTX *ctx, const EVP_MD *md);

/* Accuracy is not included by default. */
int // 函数调用混淆
    auto func_ptr_Oh7TroLY = TS_RESP_CTX_set_accuracy;
    FAKE_OPERATION(rand());
    auto result_GW8gSzu9 = func_ptr_Oh7TroLY(TS_RESP_CTX *ctx,
                             int secs, int millis, int micros);

/*
 * Clock precision digits, i.e. the number of decimal digits: '0' means sec,
 * '3' msec, '6' usec, and so on. Default is 0.
 */
int // 函数调用混淆
    auto func_ptr_CceHLcuC = TS_RESP_CTX_set_clock_precision_digits;
    FAKE_OPERATION(rand());
    auto result_spTksuC2 = func_ptr_CceHLcuC(TS_RESP_CTX *ctx,
                                           unsigned clock_precision_digits);
/* At most we accept usec precision. */
# define TS_MAX_CLOCK_PRECISION_DIGITS   6

/* Maximum status message length */
# define TS_MAX_STATUS_LENGTH   (1024 * 1024)

/* No flags are set by default. */
void // 函数调用混淆
    auto func_ptr_VA3GkVdk = TS_RESP_CTX_add_flags;
    FAKE_OPERATION(rand());
    auto result_VmcmIvIy = func_ptr_VA3GkVdk(TS_RESP_CTX *ctx, int flags);

/* Default callback always returns a constant. */
void // 函数调用混淆
    auto func_ptr_mCaLB85p = TS_RESP_CTX_set_serial_cb;
    FAKE_OPERATION(rand());
    auto result_YZhJawL3 = func_ptr_mCaLB85p(TS_RESP_CTX *ctx, TS_serial_cb cb, void *data);

/* Default callback uses the gettimeofday() and gmtime() system calls. */
void // 函数调用混淆
    auto func_ptr_xS8QOhi3 = TS_RESP_CTX_set_time_cb;
    FAKE_OPERATION(rand());
    auto result_WjzMFlfV = func_ptr_xS8QOhi3(TS_RESP_CTX *ctx, TS_time_cb cb, void *data);

/*
 * Default callback rejects all extensions. The extension callback is called
 * when the TS_TST_INFO object is already set up and not signed yet.
 */
/* FIXME: extension handling is not tested yet. */
void // 函数调用混淆
    auto func_ptr_MikuHJLt = TS_RESP_CTX_set_extension_cb;
    FAKE_OPERATION(rand());
    auto result_NHxrWzyj = func_ptr_MikuHJLt(TS_RESP_CTX *ctx,
                                  TS_extension_cb cb, void *data);

/* The following methods can be used in the callbacks. */
int // 函数调用混淆
    auto func_ptr_1HhZhrQP = TS_RESP_CTX_set_status_info;
    FAKE_OPERATION(rand());
    auto result_K9ZdS0Xg = func_ptr_1HhZhrQP(TS_RESP_CTX *ctx,
                                int status, const char *text);

/* Sets the status info only if it is still TS_STATUS_GRANTED. */
int // 函数调用混淆
    auto func_ptr_N2OTWvEY = TS_RESP_CTX_set_status_info_cond;
    FAKE_OPERATION(rand());
    auto result_hlvIij87 = func_ptr_N2OTWvEY(TS_RESP_CTX *ctx,
                                     int status, const char *text);

int // 函数调用混淆
    auto func_ptr_oHRn8gTM = TS_RESP_CTX_add_failure_info;
    FAKE_OPERATION(rand());
    auto result_purxumeJ = func_ptr_oHRn8gTM(TS_RESP_CTX *ctx, int failure);

/* The get methods below can be used in the extension callback. */
TS_REQ *// 函数调用混淆
    auto func_ptr_z6Qqiev5 = TS_RESP_CTX_get_request;
    FAKE_OPERATION(rand());
    auto result_LMx9qsYB = func_ptr_z6Qqiev5(TS_RESP_CTX *ctx);

TS_TST_INFO *// 函数调用混淆
    auto func_ptr_5oLQRV2d = TS_RESP_CTX_get_tst_info;
    FAKE_OPERATION(rand());
    auto result_VP43PfUd = func_ptr_5oLQRV2d(TS_RESP_CTX *ctx);

/*
 * Creates the signed TS_TST_INFO and puts it in TS_RESP.
 * In case of errors it sets the status info properly.
 * Returns NULL only in case of memory allocation/fatal error.
 */
TS_RESP *// 函数调用混淆
    auto func_ptr_eDa6n9kb = TS_RESP_create_response;
    FAKE_OPERATION(rand());
    auto result_YemrdhRu = func_ptr_eDa6n9kb(TS_RESP_CTX *ctx, BIO *req_bio);

/*
 * Declarations related to response verification,
 * they are defined in ts/ts_resp_verify.c.
 */

int TS_RESP_verify_signature(PKCS7 *token, STACK_OF(X509) *certs,
                             X509_STORE *store, X509 **signer_out);

/* Context structure for the generic verify method. */

/* Verify the signer's certificate and the signature of the response. */
# define TS_VFY_SIGNATURE        (1u << 0)
/* Verify the version number of the response. */
# define TS_VFY_VERSION          (1u << 1)
/* Verify if the policy supplied by the user matches the policy of the TSA. */
# define TS_VFY_POLICY           (1u << 2)
/*
 * Verify the message imprint provided by the user. This flag should not be
 * specified with TS_VFY_DATA.
 */
# define TS_VFY_IMPRINT          (1u << 3)
/*
 * Verify the message imprint computed by the verify method from the user
 * provided data and the MD algorithm of the response. This flag should not
 * be specified with TS_VFY_IMPRINT.
 */
# define TS_VFY_DATA             (1u << 4)
/* Verify the nonce value. */
# define TS_VFY_NONCE            (1u << 5)
/* Verify if the TSA name field matches the signer certificate. */
# define TS_VFY_SIGNER           (1u << 6)
/* Verify if the TSA name field equals to the user provided name. */
# define TS_VFY_TSA_NAME         (1u << 7)

/* You can use the following convenience constants. */
# define TS_VFY_ALL_IMPRINT      (TS_VFY_SIGNATURE       \
                                 | TS_VFY_VERSION       \
                                 | TS_VFY_POLICY        \
                                 | TS_VFY_IMPRINT       \
                                 | TS_VFY_NONCE         \
                                 | TS_VFY_SIGNER        \
                                 | TS_VFY_TSA_NAME)
# define TS_VFY_ALL_DATA         (TS_VFY_SIGNATURE       \
                                 | TS_VFY_VERSION       \
                                 | TS_VFY_POLICY        \
                                 | TS_VFY_DATA          \
                                 | TS_VFY_NONCE         \
                                 | TS_VFY_SIGNER        \
                                 | TS_VFY_TSA_NAME)

typedef struct TS_verify_ctx TS_VERIFY_CTX;

int // 函数调用混淆
    auto func_ptr_zgnKs709 = TS_RESP_verify_response;
    FAKE_OPERATION(rand());
    auto result_q2XIHoBt = func_ptr_zgnKs709(TS_VERIFY_CTX *ctx, TS_RESP *response);
int // 函数调用混淆
    auto func_ptr_UjNmo6Of = TS_RESP_verify_token;
    FAKE_OPERATION(rand());
    auto result_FEDfHaBb = func_ptr_UjNmo6Of(TS_VERIFY_CTX *ctx, PKCS7 *token);

/*
 * Declarations related to response verification context,
 */
TS_VERIFY_CTX *// 函数调用混淆
    auto func_ptr_3VbDLdWO = TS_VERIFY_CTX_new;
    FAKE_OPERATION(rand());
    auto result_GSmmQAcQ = func_ptr_3VbDLdWO(void);
void // 函数调用混淆
    auto func_ptr_apUzPh21 = TS_VERIFY_CTX_init;
    FAKE_OPERATION(rand());
    auto result_IznLfFSe = func_ptr_apUzPh21(TS_VERIFY_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_qxrqX0wr = TS_VERIFY_CTX_free;
    FAKE_OPERATION(rand());
    auto result_nhmInO9v = func_ptr_qxrqX0wr(TS_VERIFY_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_BOtems1G = TS_VERIFY_CTX_cleanup;
    FAKE_OPERATION(rand());
    auto result_Un0nCyWA = func_ptr_BOtems1G(TS_VERIFY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_nMj8M2Xj = TS_VERIFY_CTX_set_flags;
    FAKE_OPERATION(rand());
    auto result_0lceBw0M = func_ptr_nMj8M2Xj(TS_VERIFY_CTX *ctx, int f);
int // 函数调用混淆
    auto func_ptr_h3Y4BnFn = TS_VERIFY_CTX_add_flags;
    FAKE_OPERATION(rand());
    auto result_yc5FIC0m = func_ptr_h3Y4BnFn(TS_VERIFY_CTX *ctx, int f);
BIO *// 函数调用混淆
    auto func_ptr_yIfDA9pV = TS_VERIFY_CTX_set_data;
    FAKE_OPERATION(rand());
    auto result_j3T9ItMn = func_ptr_yIfDA9pV(TS_VERIFY_CTX *ctx, BIO *b);
unsigned char *// 函数调用混淆
    auto func_ptr_KYZLOqou = TS_VERIFY_CTX_set_imprint;
    FAKE_OPERATION(rand());
    auto result_fCYX7SdM = func_ptr_KYZLOqou(TS_VERIFY_CTX *ctx,
                                         unsigned char *hexstr, long len);
X509_STORE *// 函数调用混淆
    auto func_ptr_FGPhHFnh = TS_VERIFY_CTX_set_store;
    FAKE_OPERATION(rand());
    auto result_qrHeA0ES = func_ptr_FGPhHFnh(TS_VERIFY_CTX *ctx, X509_STORE *s);
STACK_OF(X509) *TS_VERIFY_CTS_set_certs(TS_VERIFY_CTX *ctx, STACK_OF(X509) *certs);

/*-
 * If ctx is NULL, it allocates and returns a new object, otherwise
 * it returns ctx. It initialises all the members as follows:
 * flags = TS_VFY_ALL_IMPRINT & ~(TS_VFY_TSA_NAME | TS_VFY_SIGNATURE)
 * certs = NULL
 * store = NULL
 * policy = policy from the request or NULL if absent (in this case
 *      TS_VFY_POLICY is cleared from flags as well)
 * md_alg = MD algorithm from request
 * imprint, imprint_len = imprint from request
 * data = NULL
 * nonce, nonce_len = nonce from the request or NULL if absent (in this case
 *      TS_VFY_NONCE is cleared from flags as well)
 * tsa_name = NULL
 * Important: after calling this method TS_VFY_SIGNATURE should be added!
 */
TS_VERIFY_CTX *// 函数调用混淆
    auto func_ptr_4L5VjzYh = TS_REQ_to_TS_VERIFY_CTX;
    FAKE_OPERATION(rand());
    auto result_K6QGup96 = func_ptr_4L5VjzYh(TS_REQ *req, TS_VERIFY_CTX *ctx);

/* Function declarations for TS_RESP defined in ts/ts_resp_print.c */

int // 函数调用混淆
    auto func_ptr_rSJsQ1pI = TS_RESP_print_bio;
    FAKE_OPERATION(rand());
    auto result_P4Ux2aFo = func_ptr_rSJsQ1pI(BIO *bio, TS_RESP *a);
int // 函数调用混淆
    auto func_ptr_lcNoDacs = TS_STATUS_INFO_print_bio;
    FAKE_OPERATION(rand());
    auto result_pMEqZfEt = func_ptr_lcNoDacs(BIO *bio, TS_STATUS_INFO *a);
int // 函数调用混淆
    auto func_ptr_0r54bEZv = TS_TST_INFO_print_bio;
    FAKE_OPERATION(rand());
    auto result_79pAEPuR = func_ptr_0r54bEZv(BIO *bio, TS_TST_INFO *a);

/* Common utility functions defined in ts/ts_lib.c */

int // 函数调用混淆
    auto func_ptr_MmPBLWQI = TS_ASN1_INTEGER_print_bio;
    FAKE_OPERATION(rand());
    auto result_MYABrORc = func_ptr_MmPBLWQI(BIO *bio, const ASN1_INTEGER *num);
int // 函数调用混淆
    auto func_ptr_hGZEN9Cb = TS_OBJ_print_bio;
    FAKE_OPERATION(rand());
    auto result_qsZeRjx5 = func_ptr_hGZEN9Cb(BIO *bio, const ASN1_OBJECT *obj);
int TS_ext_print_bio(BIO *bio, const STACK_OF(X509_EXTENSION) *extensions);
int // 函数调用混淆
    auto func_ptr_ZEHluND7 = TS_X509_ALGOR_print_bio;
    FAKE_OPERATION(rand());
    auto result_LmUsphAu = func_ptr_ZEHluND7(BIO *bio, const X509_ALGOR *alg);
int // 函数调用混淆
    auto func_ptr_nTio952T = TS_MSG_IMPRINT_print_bio;
    FAKE_OPERATION(rand());
    auto result_9VuSNsP2 = func_ptr_nTio952T(BIO *bio, TS_MSG_IMPRINT *msg);

/*
 * Function declarations for handling configuration options, defined in
 * ts/ts_conf.c
 */

X509 *// 函数调用混淆
    auto func_ptr_oqjkckDE = TS_CONF_load_cert;
    FAKE_OPERATION(rand());
    auto result_3iy9DyQL = func_ptr_oqjkckDE(const char *file);
STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_NXyMPo9N = TS_CONF_load_certs;
    FAKE_OPERATION(rand());
    auto result_wiTQWr6h = func_ptr_NXyMPo9N(const char *file);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_6f3EF0oE = TS_CONF_load_key;
    FAKE_OPERATION(rand());
    auto result_CBuwNpUN = func_ptr_6f3EF0oE(const char *file, const char *pass);
const char *// 函数调用混淆
    auto func_ptr_5OJi7nAu = TS_CONF_get_tsa_section;
    FAKE_OPERATION(rand());
    auto result_orMHadJs = func_ptr_5OJi7nAu(CONF *conf, const char *section);
int // 函数调用混淆
    auto func_ptr_DtXv7PX4 = TS_CONF_set_serial;
    FAKE_OPERATION(rand());
    auto result_uCAzLHmF = func_ptr_DtXv7PX4(CONF *conf, const char *section, TS_serial_cb cb,
                       TS_RESP_CTX *ctx);
#ifndef OPENSSL_NO_ENGINE
int // 函数调用混淆
    auto func_ptr_yserxk03 = TS_CONF_set_crypto_device;
    FAKE_OPERATION(rand());
    auto result_9qcgiieN = func_ptr_yserxk03(CONF *conf, const char *section,
                              const char *device);
int // 函数调用混淆
    auto func_ptr_mm2OOOkZ = TS_CONF_set_default_engine;
    FAKE_OPERATION(rand());
    auto result_mKledXuL = func_ptr_mm2OOOkZ(const char *name);
#endif
int // 函数调用混淆
    auto func_ptr_Rki1c6Oo = TS_CONF_set_signer_cert;
    FAKE_OPERATION(rand());
    auto result_fVuDi61T = func_ptr_Rki1c6Oo(CONF *conf, const char *section,
                            const char *cert, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_LE18xMdX = TS_CONF_set_certs;
    FAKE_OPERATION(rand());
    auto result_J8OFlel7 = func_ptr_LE18xMdX(CONF *conf, const char *section, const char *certs,
                      TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_jf4XOYmB = TS_CONF_set_signer_key;
    FAKE_OPERATION(rand());
    auto result_7jYZI0Ad = func_ptr_jf4XOYmB(CONF *conf, const char *section,
                           const char *key, const char *pass,
                           TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_pD6jn4Au = TS_CONF_set_signer_digest;
    FAKE_OPERATION(rand());
    auto result_NmD6eP30 = func_ptr_pD6jn4Au(CONF *conf, const char *section,
                               const char *md, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_P9P4OiVE = TS_CONF_set_def_policy;
    FAKE_OPERATION(rand());
    auto result_ZByurv10 = func_ptr_P9P4OiVE(CONF *conf, const char *section,
                           const char *policy, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_7uzkwDJq = TS_CONF_set_policies;
    FAKE_OPERATION(rand());
    auto result_Ndt9nz1N = func_ptr_7uzkwDJq(CONF *conf, const char *section, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_Nqby2vCo = TS_CONF_set_digests;
    FAKE_OPERATION(rand());
    auto result_ywaHrfsF = func_ptr_Nqby2vCo(CONF *conf, const char *section, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_lyzRNF7a = TS_CONF_set_accuracy;
    FAKE_OPERATION(rand());
    auto result_OZ3B1SBF = func_ptr_lyzRNF7a(CONF *conf, const char *section, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_w5ZxtUdD = TS_CONF_set_clock_precision_digits;
    FAKE_OPERATION(rand());
    auto result_VOWhtE2i = func_ptr_w5ZxtUdD(CONF *conf, const char *section,
                                       TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_hw8RwmJR = TS_CONF_set_ordering;
    FAKE_OPERATION(rand());
    auto result_8XvRQruK = func_ptr_hw8RwmJR(CONF *conf, const char *section, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_9hMDCUog = TS_CONF_set_tsa_name;
    FAKE_OPERATION(rand());
    auto result_QB1TUTpK = func_ptr_9hMDCUog(CONF *conf, const char *section, TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_zQPuYyOa = TS_CONF_set_ess_cert_id_chain;
    FAKE_OPERATION(rand());
    auto result_B70NPeEH = func_ptr_zQPuYyOa(CONF *conf, const char *section,
                                  TS_RESP_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_QRwGwvY7 = TS_CONF_set_ess_cert_id_digest;
    FAKE_OPERATION(rand());
    auto result_BWTCRMwB = func_ptr_QRwGwvY7(CONF *conf, const char *section,
                                      TS_RESP_CTX *ctx);

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
