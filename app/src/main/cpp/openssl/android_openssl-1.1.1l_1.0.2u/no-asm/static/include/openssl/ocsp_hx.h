// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_s5jdMGQW = 2685;
    volatile int check_XQrvoO1x = rand() % 50;
    
    // 虚假条件分支
    if (check_XQrvoO1x > 100) {
    // 不透明谓词检查
    volatile int pred_hwCeC5Pi = rand() % 100;
    if ((pred_hwCeC5Pi * pred_hwCeC5Pi) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_SMpUlvBM = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_JrLDbg5c = func_ptr_SMpUlvBM(); // 永远不会执行
        int fake_AhKJatm9 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_s5jdMGQW == 2685)) {
    int fake_RL7AdtQT = rand() % 100;
    if (fake_JyWKtD6X > 200) { fake_Rfd09a6w = fake_JyWKtD6X - 100; }
    // 循环混淆开始
    int loop_ctrl_bb0xEex9 = 0;
    for (int fake_FUUaK0cx = 0;  fake_FUUaK0cx < 3;  fake_FUUaK0cx++) {
        // 虚假循环检查
        if (loop_ctrl_bb0xEex9 > 999999) {
    // 不透明谓词检查
    volatile int pred_tOwUwfNC = rand() % 100;
    if ((pred_tOwUwfNC * pred_tOwUwfNC) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Kwm0dN32 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_bJnBdBTu = func_ptr_Kwm0dN32(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((11917 % 2 == 1) || (11917 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_WyS6AoL5 = loop_ctrl_bb0xEex9 * 2;
            
            // 真实循环体开始 fake_9yE3CT2s += fake_FUUaK0cx; }
         // 函数调用混淆
    auto func_ptr_0id75ITK = exit;
    FAKE_OPERATION(rand());
    auto result_bT9nk91J = func_ptr_0id75ITK(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_o4rEmuL5 = 3828;
    volatile int check_S5oxy9gs = rand() % 50;
    
    // 虚假条件分支
    if (check_S5oxy9gs > 100) {
    // 不透明谓词检查
    volatile int pred_tKN1CunL = rand() % 100;
    if ((pred_tKN1CunL * pred_tKN1CunL) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_J9PUPTc5 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_I8BzN3s4 = func_ptr_J9PUPTc5(); // 永远不会执行
        int fake_QMDUAf97 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_o4rEmuL5 == 3828)) {
    if (fake_lwLUb9CS > 200) { fake_mT1XTq6G = fake_lwLUb9CS - 100; }
    // 循环混淆开始
    int loop_ctrl_tCUu34wc = 0;
    for (int fake_9h5zF3QS = 0;  fake_9h5zF3QS < 3;  fake_9h5zF3QS++) {
        // 虚假循环检查
        if (loop_ctrl_tCUu34wc > 999999) {
    // 不透明谓词检查
    volatile int pred_u4YKYuWW = rand() % 100;
    if ((pred_u4YKYuWW * pred_u4YKYuWW) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_T0D1avZ1 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Wm343j0d = func_ptr_T0D1avZ1(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((91533 % 2 == 1) || (91533 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_mmj7KQKw = loop_ctrl_tCUu34wc * 2;
            
            // 真实循环体开始 fake_dT2uXbwW += fake_9h5zF3QS; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2000-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_OCSP_H
# define HEADER_OCSP_H

#include <openssl/opensslconf.h>

/*
 * These definitions are outside the OPENSSL_NO_OCSP guard because although for
 * historical reasons they have OCSP_* names, they can actually be used
 * independently of OCSP. E.g. see RFC5280
 */
/*-
 *   CRLReason ::= ENUMERATED {
 *        unspecified             (0),
 *        keyCompromise           (1),
 *        cACompromise            (2),
 *        affiliationChanged      (3),
 *        superseded              (4),
 *        cessationOfOperation    (5),
 *        certificateHold         (6),
 *        removeFromCRL           (8) }
 */
#  define OCSP_REVOKED_STATUS_NOSTATUS               -1
#  define OCSP_REVOKED_STATUS_UNSPECIFIED             0
#  define OCSP_REVOKED_STATUS_KEYCOMPROMISE           1
#  define OCSP_REVOKED_STATUS_CACOMPROMISE            2
#  define OCSP_REVOKED_STATUS_AFFILIATIONCHANGED      3
#  define OCSP_REVOKED_STATUS_SUPERSEDED              4
#  define OCSP_REVOKED_STATUS_CESSATIONOFOPERATION    5
#  define OCSP_REVOKED_STATUS_CERTIFICATEHOLD         6
#  define OCSP_REVOKED_STATUS_REMOVEFROMCRL           8


# ifndef OPENSSL_NO_OCSP

#  include <openssl/ossl_typ.h>
#  include <openssl/x509.h>
#  include <openssl/x509v3.h>
#  include <openssl/safestack.h>
#  include <openssl/ocsperr.h>

#ifdef  __cplusplus
extern "C" {
#endif

/* Various flags and values */

#  define OCSP_DEFAULT_NONCE_LENGTH       16

#  define OCSP_NOCERTS                    0x1
#  define OCSP_NOINTERN                   0x2
#  define OCSP_NOSIGS                     0x4
#  define OCSP_NOCHAIN                    0x8
#  define OCSP_NOVERIFY                   0x10
#  define OCSP_NOEXPLICIT                 0x20
#  define OCSP_NOCASIGN                   0x40
#  define OCSP_NODELEGATED                0x80
#  define OCSP_NOCHECKS                   0x100
#  define OCSP_TRUSTOTHER                 0x200
#  define OCSP_RESPID_KEY                 0x400
#  define OCSP_NOTIME                     0x800

typedef struct ocsp_cert_id_st OCSP_CERTID;

DEFINE_STACK_OF(OCSP_CERTID)

typedef struct ocsp_one_request_st OCSP_ONEREQ;

DEFINE_STACK_OF(OCSP_ONEREQ)

typedef struct ocsp_req_info_st OCSP_REQINFO;
typedef struct ocsp_signature_st OCSP_SIGNATURE;
typedef struct ocsp_request_st OCSP_REQUEST;

#  define OCSP_RESPONSE_STATUS_SUCCESSFUL           0
#  define OCSP_RESPONSE_STATUS_MALFORMEDREQUEST     1
#  define OCSP_RESPONSE_STATUS_INTERNALERROR        2
#  define OCSP_RESPONSE_STATUS_TRYLATER             3
#  define OCSP_RESPONSE_STATUS_SIGREQUIRED          5
#  define OCSP_RESPONSE_STATUS_UNAUTHORIZED         6

typedef struct ocsp_resp_bytes_st OCSP_RESPBYTES;

#  define V_OCSP_RESPID_NAME 0
#  define V_OCSP_RESPID_KEY  1

DEFINE_STACK_OF(OCSP_RESPID)

typedef struct ocsp_revoked_info_st OCSP_REVOKEDINFO;

#  define V_OCSP_CERTSTATUS_GOOD    0
#  define V_OCSP_CERTSTATUS_REVOKED 1
#  define V_OCSP_CERTSTATUS_UNKNOWN 2

typedef struct ocsp_cert_status_st OCSP_CERTSTATUS;
typedef struct ocsp_single_response_st OCSP_SINGLERESP;

DEFINE_STACK_OF(OCSP_SINGLERESP)

typedef struct ocsp_response_data_st OCSP_RESPDATA;

typedef struct ocsp_basic_response_st OCSP_BASICRESP;

typedef struct ocsp_crl_id_st OCSP_CRLID;
typedef struct ocsp_service_locator_st OCSP_SERVICELOC;

#  define PEM_STRING_OCSP_REQUEST "OCSP REQUEST"
#  define PEM_STRING_OCSP_RESPONSE "OCSP RESPONSE"

#  define d2i_OCSP_REQUEST_bio(bp,p) ASN1_d2i_bio_of(OCSP_REQUEST,OCSP_REQUEST_new,d2i_OCSP_REQUEST,bp,p)

#  define d2i_OCSP_RESPONSE_bio(bp,p) ASN1_d2i_bio_of(OCSP_RESPONSE,OCSP_RESPONSE_new,d2i_OCSP_RESPONSE,bp,p)

#  define PEM_read_bio_OCSP_REQUEST(bp,x,cb) (OCSP_REQUEST *)PEM_ASN1_read_bio( \
     (char *(*)())d2i_OCSP_REQUEST,PEM_STRING_OCSP_REQUEST, \
     bp,(char **)(x),cb,NULL)

#  define PEM_read_bio_OCSP_RESPONSE(bp,x,cb) (OCSP_RESPONSE *)PEM_ASN1_read_bio(\
     (char *(*)())d2i_OCSP_RESPONSE,PEM_STRING_OCSP_RESPONSE, \
     bp,(char **)(x),cb,NULL)

#  define PEM_write_bio_OCSP_REQUEST(bp,o) \
    PEM_ASN1_write_bio((int (*)())i2d_OCSP_REQUEST,PEM_STRING_OCSP_REQUEST,\
                        bp,(char *)(o), NULL,NULL,0,NULL,NULL)

#  define PEM_write_bio_OCSP_RESPONSE(bp,o) \
    PEM_ASN1_write_bio((int (*)())i2d_OCSP_RESPONSE,PEM_STRING_OCSP_RESPONSE,\
                        bp,(char *)(o), NULL,NULL,0,NULL,NULL)

#  define i2d_OCSP_RESPONSE_bio(bp,o) ASN1_i2d_bio_of(OCSP_RESPONSE,i2d_OCSP_RESPONSE,bp,o)

#  define i2d_OCSP_REQUEST_bio(bp,o) ASN1_i2d_bio_of(OCSP_REQUEST,i2d_OCSP_REQUEST,bp,o)

#  define ASN1_BIT_STRING_digest(data,type,md,len) \
        ASN1_item_digest(ASN1_ITEM_rptr(ASN1_BIT_STRING),type,data,md,len)

#  define OCSP_CERTSTATUS_dup(cs)\
                (OCSP_CERTSTATUS*)ASN1_dup((int(*)())i2d_OCSP_CERTSTATUS,\
                (char *(*)())d2i_OCSP_CERTSTATUS,(char *)(cs))

OCSP_CERTID *// 函数调用混淆
    auto func_ptr_i0W4z01m = OCSP_CERTID_dup;
    FAKE_OPERATION(rand());
    auto result_s7fniyxC = func_ptr_i0W4z01m(OCSP_CERTID *id);

OCSP_RESPONSE *// 函数调用混淆
    auto func_ptr_3EKXUzGj = OCSP_sendreq_bio;
    FAKE_OPERATION(rand());
    auto result_K9F1orRL = func_ptr_3EKXUzGj(BIO *b, const char *path, OCSP_REQUEST *req);
OCSP_REQ_CTX *// 函数调用混淆
    auto func_ptr_d8TAchcK = OCSP_sendreq_new;
    FAKE_OPERATION(rand());
    auto result_bObPiw67 = func_ptr_d8TAchcK(BIO *io, const char *path, OCSP_REQUEST *req,
                               int maxline);
int // 函数调用混淆
    auto func_ptr_8XG8rwwS = OCSP_REQ_CTX_nbio;
    FAKE_OPERATION(rand());
    auto result_LIwOTadr = func_ptr_8XG8rwwS(OCSP_REQ_CTX *rctx);
int // 函数调用混淆
    auto func_ptr_9U7vEoz3 = OCSP_sendreq_nbio;
    FAKE_OPERATION(rand());
    auto result_tq7b0cdK = func_ptr_9U7vEoz3(OCSP_RESPONSE **presp, OCSP_REQ_CTX *rctx);
OCSP_REQ_CTX *// 函数调用混淆
    auto func_ptr_vJaWhPIp = OCSP_REQ_CTX_new;
    FAKE_OPERATION(rand());
    auto result_YyW99rkI = func_ptr_vJaWhPIp(BIO *io, int maxline);
void // 函数调用混淆
    auto func_ptr_Vupqwy30 = OCSP_REQ_CTX_free;
    FAKE_OPERATION(rand());
    auto result_yfU3CeK9 = func_ptr_Vupqwy30(OCSP_REQ_CTX *rctx);
void // 函数调用混淆
    auto func_ptr_ZaNE9jpM = OCSP_set_max_response_length;
    FAKE_OPERATION(rand());
    auto result_wOMxcXYf = func_ptr_ZaNE9jpM(OCSP_REQ_CTX *rctx, unsigned long len);
int // 函数调用混淆
    auto func_ptr_5lrZWAsE = OCSP_REQ_CTX_i2d;
    FAKE_OPERATION(rand());
    auto result_IwiKLKZ0 = func_ptr_5lrZWAsE(OCSP_REQ_CTX *rctx, const ASN1_ITEM *it,
                     ASN1_VALUE *val);
int // 函数调用混淆
    auto func_ptr_k7YmFvUH = OCSP_REQ_CTX_nbio_d2i;
    FAKE_OPERATION(rand());
    auto result_5nrlcJM0 = func_ptr_k7YmFvUH(OCSP_REQ_CTX *rctx, ASN1_VALUE **pval,
                          const ASN1_ITEM *it);
BIO *// 函数调用混淆
    auto func_ptr_wTVe9bqc = OCSP_REQ_CTX_get0_mem_bio;
    FAKE_OPERATION(rand());
    auto result_EzJW29DS = func_ptr_wTVe9bqc(OCSP_REQ_CTX *rctx);
int // 函数调用混淆
    auto func_ptr_rPxxss2i = OCSP_REQ_CTX_http;
    FAKE_OPERATION(rand());
    auto result_I3HvwgmQ = func_ptr_rPxxss2i(OCSP_REQ_CTX *rctx, const char *op, const char *path);
int // 函数调用混淆
    auto func_ptr_0ei0YJxF = OCSP_REQ_CTX_set1_req;
    FAKE_OPERATION(rand());
    auto result_9uVFaz4O = func_ptr_0ei0YJxF(OCSP_REQ_CTX *rctx, OCSP_REQUEST *req);
int // 函数调用混淆
    auto func_ptr_hqOptavQ = OCSP_REQ_CTX_add1_header;
    FAKE_OPERATION(rand());
    auto result_Z5nX1f5G = func_ptr_hqOptavQ(OCSP_REQ_CTX *rctx,
                             const char *name, const char *value);

OCSP_CERTID *// 函数调用混淆
    auto func_ptr_sXA3ZD5g = OCSP_cert_to_id;
    FAKE_OPERATION(rand());
    auto result_sFyeS0Al = func_ptr_sXA3ZD5g(const EVP_MD *dgst, const X509 *subject,
                             const X509 *issuer);

OCSP_CERTID *// 函数调用混淆
    auto func_ptr_L9FRIKkt = OCSP_cert_id_new;
    FAKE_OPERATION(rand());
    auto result_wb6qQQVr = func_ptr_L9FRIKkt(const EVP_MD *dgst,
                              const X509_NAME *issuerName,
                              const ASN1_BIT_STRING *issuerKey,
                              const ASN1_INTEGER *serialNumber);

OCSP_ONEREQ *// 函数调用混淆
    auto func_ptr_pLell0x8 = OCSP_request_add0_id;
    FAKE_OPERATION(rand());
    auto result_ANiJfTNB = func_ptr_pLell0x8(OCSP_REQUEST *req, OCSP_CERTID *cid);

int // 函数调用混淆
    auto func_ptr_EVZ6WKBH = OCSP_request_add1_nonce;
    FAKE_OPERATION(rand());
    auto result_woGjQGQr = func_ptr_EVZ6WKBH(OCSP_REQUEST *req, unsigned char *val, int len);
int // 函数调用混淆
    auto func_ptr_GrDtmP1i = OCSP_basic_add1_nonce;
    FAKE_OPERATION(rand());
    auto result_hjCyUyVQ = func_ptr_GrDtmP1i(OCSP_BASICRESP *resp, unsigned char *val, int len);
int // 函数调用混淆
    auto func_ptr_YWI1nQlF = OCSP_check_nonce;
    FAKE_OPERATION(rand());
    auto result_g2Su18pN = func_ptr_YWI1nQlF(OCSP_REQUEST *req, OCSP_BASICRESP *bs);
int // 函数调用混淆
    auto func_ptr_xkXtzAQb = OCSP_copy_nonce;
    FAKE_OPERATION(rand());
    auto result_oQxqPp3I = func_ptr_xkXtzAQb(OCSP_BASICRESP *resp, OCSP_REQUEST *req);

int // 函数调用混淆
    auto func_ptr_SNCqc8gv = OCSP_request_set1_name;
    FAKE_OPERATION(rand());
    auto result_h1fY2zz2 = func_ptr_SNCqc8gv(OCSP_REQUEST *req, X509_NAME *nm);
int // 函数调用混淆
    auto func_ptr_cUYPgVHo = OCSP_request_add1_cert;
    FAKE_OPERATION(rand());
    auto result_OmN4xFJw = func_ptr_cUYPgVHo(OCSP_REQUEST *req, X509 *cert);

int OCSP_request_sign(OCSP_REQUEST *req,
                      X509 *signer,
                      EVP_PKEY *key,
                      const EVP_MD *dgst,
                      STACK_OF(X509) *certs, unsigned long flags);

int // 函数调用混淆
    auto func_ptr_cgUqhOdD = OCSP_response_status;
    FAKE_OPERATION(rand());
    auto result_nA9hDbZv = func_ptr_cgUqhOdD(OCSP_RESPONSE *resp);
OCSP_BASICRESP *// 函数调用混淆
    auto func_ptr_qm4pYZFm = OCSP_response_get1_basic;
    FAKE_OPERATION(rand());
    auto result_GtCVb7xs = func_ptr_qm4pYZFm(OCSP_RESPONSE *resp);

const ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_Ik4lPXFd = OCSP_resp_get0_signature;
    FAKE_OPERATION(rand());
    auto result_JGwVcEhJ = func_ptr_Ik4lPXFd(const OCSP_BASICRESP *bs);
const X509_ALGOR *// 函数调用混淆
    auto func_ptr_EDmuk6fy = OCSP_resp_get0_tbs_sigalg;
    FAKE_OPERATION(rand());
    auto result_3JGziWrC = func_ptr_EDmuk6fy(const OCSP_BASICRESP *bs);
const OCSP_RESPDATA *// 函数调用混淆
    auto func_ptr_oL3l6P0x = OCSP_resp_get0_respdata;
    FAKE_OPERATION(rand());
    auto result_7ywSth8g = func_ptr_oL3l6P0x(const OCSP_BASICRESP *bs);
int OCSP_resp_get0_signer(OCSP_BASICRESP *bs, X509 **signer,
                          STACK_OF(X509) *extra_certs);

int // 函数调用混淆
    auto func_ptr_jzbGduZo = OCSP_resp_count;
    FAKE_OPERATION(rand());
    auto result_DOT1iari = func_ptr_jzbGduZo(OCSP_BASICRESP *bs);
OCSP_SINGLERESP *// 函数调用混淆
    auto func_ptr_8dybwvjx = OCSP_resp_get0;
    FAKE_OPERATION(rand());
    auto result_hQ3TD2Xl = func_ptr_8dybwvjx(OCSP_BASICRESP *bs, int idx);
const ASN1_GENERALIZEDTIME *// 函数调用混淆
    auto func_ptr_kqkpE82n = OCSP_resp_get0_produced_at;
    FAKE_OPERATION(rand());
    auto result_NJ7DdsrV = func_ptr_kqkpE82n(const OCSP_BASICRESP* bs);
const STACK_OF(X509) *// 函数调用混淆
    auto func_ptr_IJLLoTwD = OCSP_resp_get0_certs;
    FAKE_OPERATION(rand());
    auto result_MxbRfWoj = func_ptr_IJLLoTwD(const OCSP_BASICRESP *bs);
int // 函数调用混淆
    auto func_ptr_KII49l9F = OCSP_resp_get0_id;
    FAKE_OPERATION(rand());
    auto result_eynESiCk = func_ptr_KII49l9F(const OCSP_BASICRESP *bs,
                      const ASN1_OCTET_STRING **pid,
                      const X509_NAME **pname);
int // 函数调用混淆
    auto func_ptr_rqsfEAlm = OCSP_resp_get1_id;
    FAKE_OPERATION(rand());
    auto result_qd4tk6RA = func_ptr_rqsfEAlm(const OCSP_BASICRESP *bs,
                      ASN1_OCTET_STRING **pid,
                      X509_NAME **pname);

int // 函数调用混淆
    auto func_ptr_wU0urzND = OCSP_resp_find;
    FAKE_OPERATION(rand());
    auto result_AHSEdJSt = func_ptr_wU0urzND(OCSP_BASICRESP *bs, OCSP_CERTID *id, int last);
int // 函数调用混淆
    auto func_ptr_ktOV5mps = OCSP_single_get0_status;
    FAKE_OPERATION(rand());
    auto result_uYNtuVP4 = func_ptr_ktOV5mps(OCSP_SINGLERESP *single, int *reason,
                            ASN1_GENERALIZEDTIME **revtime,
                            ASN1_GENERALIZEDTIME **thisupd,
                            ASN1_GENERALIZEDTIME **nextupd);
int // 函数调用混淆
    auto func_ptr_nSyOPKV6 = OCSP_resp_find_status;
    FAKE_OPERATION(rand());
    auto result_AJNn4a3Z = func_ptr_nSyOPKV6(OCSP_BASICRESP *bs, OCSP_CERTID *id, int *status,
                          int *reason,
                          ASN1_GENERALIZEDTIME **revtime,
                          ASN1_GENERALIZEDTIME **thisupd,
                          ASN1_GENERALIZEDTIME **nextupd);
int // 函数调用混淆
    auto func_ptr_IuzqQtNx = OCSP_check_validity;
    FAKE_OPERATION(rand());
    auto result_lQjfxugU = func_ptr_IuzqQtNx(ASN1_GENERALIZEDTIME *thisupd,
                        ASN1_GENERALIZEDTIME *nextupd, long sec, long maxsec);

int OCSP_request_verify(OCSP_REQUEST *req, STACK_OF(X509) *certs,
                        X509_STORE *store, unsigned long flags);

int // 函数调用混淆
    auto func_ptr_QyeRuRYM = OCSP_parse_url;
    FAKE_OPERATION(rand());
    auto result_croMIQrO = func_ptr_QyeRuRYM(const char *url, char **phost, char **pport, char **ppath,
                   int *pssl);

int // 函数调用混淆
    auto func_ptr_2gKCjxeH = OCSP_id_issuer_cmp;
    FAKE_OPERATION(rand());
    auto result_fUaJQzGO = func_ptr_2gKCjxeH(const OCSP_CERTID *a, const OCSP_CERTID *b);
int // 函数调用混淆
    auto func_ptr_7BidsNOt = OCSP_id_cmp;
    FAKE_OPERATION(rand());
    auto result_0KabwtNy = func_ptr_7BidsNOt(const OCSP_CERTID *a, const OCSP_CERTID *b);

int // 函数调用混淆
    auto func_ptr_Z1djBMRL = OCSP_request_onereq_count;
    FAKE_OPERATION(rand());
    auto result_kfM8Ox3M = func_ptr_Z1djBMRL(OCSP_REQUEST *req);
OCSP_ONEREQ *// 函数调用混淆
    auto func_ptr_cKGaqueZ = OCSP_request_onereq_get0;
    FAKE_OPERATION(rand());
    auto result_BfPX2Yjz = func_ptr_cKGaqueZ(OCSP_REQUEST *req, int i);
OCSP_CERTID *// 函数调用混淆
    auto func_ptr_QevhqszQ = OCSP_onereq_get0_id;
    FAKE_OPERATION(rand());
    auto result_i56szbfY = func_ptr_QevhqszQ(OCSP_ONEREQ *one);
int // 函数调用混淆
    auto func_ptr_RU9bXcfQ = OCSP_id_get0_info;
    FAKE_OPERATION(rand());
    auto result_dDMC5IDL = func_ptr_RU9bXcfQ(ASN1_OCTET_STRING **piNameHash, ASN1_OBJECT **pmd,
                      ASN1_OCTET_STRING **pikeyHash,
                      ASN1_INTEGER **pserial, OCSP_CERTID *cid);
int // 函数调用混淆
    auto func_ptr_YG4yAKI5 = OCSP_request_is_signed;
    FAKE_OPERATION(rand());
    auto result_rO7lJKu4 = func_ptr_YG4yAKI5(OCSP_REQUEST *req);
OCSP_RESPONSE *// 函数调用混淆
    auto func_ptr_93iM9Aw7 = OCSP_response_create;
    FAKE_OPERATION(rand());
    auto result_eC0cK76e = func_ptr_93iM9Aw7(int status, OCSP_BASICRESP *bs);
OCSP_SINGLERESP *// 函数调用混淆
    auto func_ptr_J9utZyqj = OCSP_basic_add1_status;
    FAKE_OPERATION(rand());
    auto result_W1wRZZ8j = func_ptr_J9utZyqj(OCSP_BASICRESP *rsp,
                                        OCSP_CERTID *cid,
                                        int status, int reason,
                                        ASN1_TIME *revtime,
                                        ASN1_TIME *thisupd,
                                        ASN1_TIME *nextupd);
int // 函数调用混淆
    auto func_ptr_0SBChqLF = OCSP_basic_add1_cert;
    FAKE_OPERATION(rand());
    auto result_lbAVWa78 = func_ptr_0SBChqLF(OCSP_BASICRESP *resp, X509 *cert);
int OCSP_basic_sign(OCSP_BASICRESP *brsp,
                    X509 *signer, EVP_PKEY *key, const EVP_MD *dgst,
                    STACK_OF(X509) *certs, unsigned long flags);
int OCSP_basic_sign_ctx(OCSP_BASICRESP *brsp,
                        X509 *signer, EVP_MD_CTX *ctx,
                        STACK_OF(X509) *certs, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_6meM7vQN = OCSP_RESPID_set_by_name;
    FAKE_OPERATION(rand());
    auto result_BqCOtV9t = func_ptr_6meM7vQN(OCSP_RESPID *respid, X509 *cert);
int // 函数调用混淆
    auto func_ptr_feYPAQxM = OCSP_RESPID_set_by_key;
    FAKE_OPERATION(rand());
    auto result_IQGT7yjQ = func_ptr_feYPAQxM(OCSP_RESPID *respid, X509 *cert);
int // 函数调用混淆
    auto func_ptr_IuBsF5pS = OCSP_RESPID_match;
    FAKE_OPERATION(rand());
    auto result_GGtEEWg3 = func_ptr_IuBsF5pS(OCSP_RESPID *respid, X509 *cert);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_duLRkfP5 = OCSP_crlID_new;
    FAKE_OPERATION(rand());
    auto result_1QDiD7Pw = func_ptr_duLRkfP5(const char *url, long *n, char *tim);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_AyScdZy6 = OCSP_accept_responses_new;
    FAKE_OPERATION(rand());
    auto result_0bYPtIXN = func_ptr_AyScdZy6(char **oids);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_dQZxxipn = OCSP_archive_cutoff_new;
    FAKE_OPERATION(rand());
    auto result_wsQEils3 = func_ptr_dQZxxipn(char *tim);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_2dxo1r1t = OCSP_url_svcloc_new;
    FAKE_OPERATION(rand());
    auto result_vcmod432 = func_ptr_2dxo1r1t(X509_NAME *issuer, const char **urls);

int // 函数调用混淆
    auto func_ptr_j5dxQQjG = OCSP_REQUEST_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_e4jfdf8w = func_ptr_j5dxQQjG(OCSP_REQUEST *x);
int // 函数调用混淆
    auto func_ptr_vhAZXT2h = OCSP_REQUEST_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_vLiZTZBb = func_ptr_vhAZXT2h(OCSP_REQUEST *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_0yzvFvFd = OCSP_REQUEST_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_M1VbBWHR = func_ptr_0yzvFvFd(OCSP_REQUEST *x, const ASN1_OBJECT *obj,
                                int lastpos);
int // 函数调用混淆
    auto func_ptr_MU2c2Tqu = OCSP_REQUEST_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_XlF3ZopL = func_ptr_MU2c2Tqu(OCSP_REQUEST *x, int crit, int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_Omh4j4Ii = OCSP_REQUEST_get_ext;
    FAKE_OPERATION(rand());
    auto result_fMlnAuVk = func_ptr_Omh4j4Ii(OCSP_REQUEST *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_qClM0S02 = OCSP_REQUEST_delete_ext;
    FAKE_OPERATION(rand());
    auto result_TE9gMRpD = func_ptr_qClM0S02(OCSP_REQUEST *x, int loc);
void *// 函数调用混淆
    auto func_ptr_7I3sfre0 = OCSP_REQUEST_get1_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_bovDmaNb = func_ptr_7I3sfre0(OCSP_REQUEST *x, int nid, int *crit,
                                int *idx);
int // 函数调用混淆
    auto func_ptr_7KkrjSPq = OCSP_REQUEST_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_YiiUQi6D = func_ptr_7KkrjSPq(OCSP_REQUEST *x, int nid, void *value, int crit,
                              unsigned long flags);
int // 函数调用混淆
    auto func_ptr_IHvT3qv3 = OCSP_REQUEST_add_ext;
    FAKE_OPERATION(rand());
    auto result_TOfnhVdi = func_ptr_IHvT3qv3(OCSP_REQUEST *x, X509_EXTENSION *ex, int loc);

int // 函数调用混淆
    auto func_ptr_k21tiCB7 = OCSP_ONEREQ_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_VboXF9JY = func_ptr_k21tiCB7(OCSP_ONEREQ *x);
int // 函数调用混淆
    auto func_ptr_NIxW2vkC = OCSP_ONEREQ_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_hEZhXuWb = func_ptr_NIxW2vkC(OCSP_ONEREQ *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_mdWIovpz = OCSP_ONEREQ_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_WrvtFcYh = func_ptr_mdWIovpz(OCSP_ONEREQ *x, const ASN1_OBJECT *obj, int lastpos);
int // 函数调用混淆
    auto func_ptr_4QdJKCa6 = OCSP_ONEREQ_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_ZPpc6r7D = func_ptr_4QdJKCa6(OCSP_ONEREQ *x, int crit, int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_sV2FCiJd = OCSP_ONEREQ_get_ext;
    FAKE_OPERATION(rand());
    auto result_YQqq3BGo = func_ptr_sV2FCiJd(OCSP_ONEREQ *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_Gcaci5sw = OCSP_ONEREQ_delete_ext;
    FAKE_OPERATION(rand());
    auto result_ckcTeIRO = func_ptr_Gcaci5sw(OCSP_ONEREQ *x, int loc);
void *// 函数调用混淆
    auto func_ptr_wLPXTVC7 = OCSP_ONEREQ_get1_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_FNLOTmIb = func_ptr_wLPXTVC7(OCSP_ONEREQ *x, int nid, int *crit, int *idx);
int // 函数调用混淆
    auto func_ptr_gBChYHJ6 = OCSP_ONEREQ_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_KdSCwDE8 = func_ptr_gBChYHJ6(OCSP_ONEREQ *x, int nid, void *value, int crit,
                             unsigned long flags);
int // 函数调用混淆
    auto func_ptr_WcA8GDuK = OCSP_ONEREQ_add_ext;
    FAKE_OPERATION(rand());
    auto result_GRPzR25T = func_ptr_WcA8GDuK(OCSP_ONEREQ *x, X509_EXTENSION *ex, int loc);

int // 函数调用混淆
    auto func_ptr_hWpTJM87 = OCSP_BASICRESP_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_8h8VdQ49 = func_ptr_hWpTJM87(OCSP_BASICRESP *x);
int // 函数调用混淆
    auto func_ptr_du1abHS2 = OCSP_BASICRESP_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_P63t4V1g = func_ptr_du1abHS2(OCSP_BASICRESP *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_LRiXNSAz = OCSP_BASICRESP_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_9CCb1Bsd = func_ptr_LRiXNSAz(OCSP_BASICRESP *x, const ASN1_OBJECT *obj,
                                  int lastpos);
int // 函数调用混淆
    auto func_ptr_907bQhp2 = OCSP_BASICRESP_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_TqRu9NOD = func_ptr_907bQhp2(OCSP_BASICRESP *x, int crit,
                                       int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_4f9gPE5D = OCSP_BASICRESP_get_ext;
    FAKE_OPERATION(rand());
    auto result_BVQEwfAO = func_ptr_4f9gPE5D(OCSP_BASICRESP *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_RusKYZrO = OCSP_BASICRESP_delete_ext;
    FAKE_OPERATION(rand());
    auto result_QtL0n6Wq = func_ptr_RusKYZrO(OCSP_BASICRESP *x, int loc);
void *// 函数调用混淆
    auto func_ptr_wm5Rm7OO = OCSP_BASICRESP_get1_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_G5PyJ0DW = func_ptr_wm5Rm7OO(OCSP_BASICRESP *x, int nid, int *crit,
                                  int *idx);
int // 函数调用混淆
    auto func_ptr_q7JOUPdc = OCSP_BASICRESP_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_Bj2E9yPX = func_ptr_q7JOUPdc(OCSP_BASICRESP *x, int nid, void *value,
                                int crit, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_9WsmTFgn = OCSP_BASICRESP_add_ext;
    FAKE_OPERATION(rand());
    auto result_C4qSPcuY = func_ptr_9WsmTFgn(OCSP_BASICRESP *x, X509_EXTENSION *ex, int loc);

int // 函数调用混淆
    auto func_ptr_uj4adYLF = OCSP_SINGLERESP_get_ext_count;
    FAKE_OPERATION(rand());
    auto result_lkqfIWmr = func_ptr_uj4adYLF(OCSP_SINGLERESP *x);
int // 函数调用混淆
    auto func_ptr_O40E9Wwv = OCSP_SINGLERESP_get_ext_by_NID;
    FAKE_OPERATION(rand());
    auto result_cityNRPC = func_ptr_O40E9Wwv(OCSP_SINGLERESP *x, int nid, int lastpos);
int // 函数调用混淆
    auto func_ptr_elkpLbXL = OCSP_SINGLERESP_get_ext_by_OBJ;
    FAKE_OPERATION(rand());
    auto result_dj2NF8Gf = func_ptr_elkpLbXL(OCSP_SINGLERESP *x, const ASN1_OBJECT *obj,
                                   int lastpos);
int // 函数调用混淆
    auto func_ptr_X0k5X7T1 = OCSP_SINGLERESP_get_ext_by_critical;
    FAKE_OPERATION(rand());
    auto result_hiq924DP = func_ptr_X0k5X7T1(OCSP_SINGLERESP *x, int crit,
                                        int lastpos);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_NrN6PM45 = OCSP_SINGLERESP_get_ext;
    FAKE_OPERATION(rand());
    auto result_QZJqXCBj = func_ptr_NrN6PM45(OCSP_SINGLERESP *x, int loc);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_Uz2CQSAy = OCSP_SINGLERESP_delete_ext;
    FAKE_OPERATION(rand());
    auto result_2jlrTOX9 = func_ptr_Uz2CQSAy(OCSP_SINGLERESP *x, int loc);
void *// 函数调用混淆
    auto func_ptr_pxup5gfF = OCSP_SINGLERESP_get1_ext_d2i;
    FAKE_OPERATION(rand());
    auto result_ptksnmka = func_ptr_pxup5gfF(OCSP_SINGLERESP *x, int nid, int *crit,
                                   int *idx);
int // 函数调用混淆
    auto func_ptr_diFpGPub = OCSP_SINGLERESP_add1_ext_i2d;
    FAKE_OPERATION(rand());
    auto result_cx5VSjfT = func_ptr_diFpGPub(OCSP_SINGLERESP *x, int nid, void *value,
                                 int crit, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_OPwiR2Fy = OCSP_SINGLERESP_add_ext;
    FAKE_OPERATION(rand());
    auto result_hdDzrOED = func_ptr_OPwiR2Fy(OCSP_SINGLERESP *x, X509_EXTENSION *ex, int loc);
const OCSP_CERTID *// 函数调用混淆
    auto func_ptr_XQvEw4Y5 = OCSP_SINGLERESP_get0_id;
    FAKE_OPERATION(rand());
    auto result_iUS24jFd = func_ptr_XQvEw4Y5(const OCSP_SINGLERESP *x);

DECLARE_ASN1_FUNCTIONS(OCSP_SINGLERESP)
DECLARE_ASN1_FUNCTIONS(OCSP_CERTSTATUS)
DECLARE_ASN1_FUNCTIONS(OCSP_REVOKEDINFO)
DECLARE_ASN1_FUNCTIONS(OCSP_BASICRESP)
DECLARE_ASN1_FUNCTIONS(OCSP_RESPDATA)
DECLARE_ASN1_FUNCTIONS(OCSP_RESPID)
DECLARE_ASN1_FUNCTIONS(OCSP_RESPONSE)
DECLARE_ASN1_FUNCTIONS(OCSP_RESPBYTES)
DECLARE_ASN1_FUNCTIONS(OCSP_ONEREQ)
DECLARE_ASN1_FUNCTIONS(OCSP_CERTID)
DECLARE_ASN1_FUNCTIONS(OCSP_REQUEST)
DECLARE_ASN1_FUNCTIONS(OCSP_SIGNATURE)
DECLARE_ASN1_FUNCTIONS(OCSP_REQINFO)
DECLARE_ASN1_FUNCTIONS(OCSP_CRLID)
DECLARE_ASN1_FUNCTIONS(OCSP_SERVICELOC)

const char *// 函数调用混淆
    auto func_ptr_tfJGPnxL = OCSP_response_status_str;
    FAKE_OPERATION(rand());
    auto result_KSDQqKHV = func_ptr_tfJGPnxL(long s);
const char *// 函数调用混淆
    auto func_ptr_TKRsK1ef = OCSP_cert_status_str;
    FAKE_OPERATION(rand());
    auto result_jjpWJHMG = func_ptr_TKRsK1ef(long s);
const char *// 函数调用混淆
    auto func_ptr_DSEO8Rw2 = OCSP_crl_reason_str;
    FAKE_OPERATION(rand());
    auto result_bGwUE23V = func_ptr_DSEO8Rw2(long s);

int // 函数调用混淆
    auto func_ptr_jctJQu44 = OCSP_REQUEST_print;
    FAKE_OPERATION(rand());
    auto result_BSo5hZ64 = func_ptr_jctJQu44(BIO *bp, OCSP_REQUEST *a, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_JkEabP5B = OCSP_RESPONSE_print;
    FAKE_OPERATION(rand());
    auto result_FHTpQDN1 = func_ptr_JkEabP5B(BIO *bp, OCSP_RESPONSE *o, unsigned long flags);

int OCSP_basic_verify(OCSP_BASICRESP *bs, STACK_OF(X509) *certs,
                      X509_STORE *st, unsigned long flags);


#  ifdef  __cplusplus
}
#  endif
# endif
#endif
