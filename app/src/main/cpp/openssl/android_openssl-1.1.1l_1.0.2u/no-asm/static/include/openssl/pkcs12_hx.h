// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_NbYlYlyW = 9836;
    volatile int check_R2BFiWLc = rand() % 50;
    
    // 虚假条件分支
    if (check_R2BFiWLc > 100) {
    // 不透明谓词检查
    volatile int pred_g88uhTLt = rand() % 100;
    if ((pred_g88uhTLt * pred_g88uhTLt) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_TqjDwcin = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_pjlTnIe9 = func_ptr_TqjDwcin(); // 永远不会执行
        int fake_H8FgPmaG = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_NbYlYlyW == 9836)) {
    if (fake_C8rxsiAX > 200) { fake_9DxCH55z = fake_C8rxsiAX - 100; }
    int fake_SqdR7Rok = rand() % 100;
    volatile int fake_C8rxsiAX = fake_SqdR7Rok * 2 + 1;
         // 函数调用混淆
    auto func_ptr_30qBg52U = exit;
    FAKE_OPERATION(rand());
    auto result_3HUpdtYI = func_ptr_30qBg52U(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_zqH6Qvmf = 9060;
    volatile int check_rOZVGJdP = rand() % 50;
    
    // 虚假条件分支
    if (check_rOZVGJdP > 100) {
    // 不透明谓词检查
    volatile int pred_re2IALVr = rand() % 100;
    if ((pred_re2IALVr * pred_re2IALVr) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_rpQpy8bi = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ZALBz4yt = func_ptr_rpQpy8bi(); // 永远不会执行
        int fake_taduC4kn = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_zqH6Qvmf == 9060)) {
    // 循环混淆开始
    int loop_ctrl_eWgKpS7C = 0;
    for (int fake_MzFd6IFx = 0;  fake_MzFd6IFx < 3;  fake_MzFd6IFx++) {
        // 虚假循环检查
        if (loop_ctrl_eWgKpS7C > 999999) {
    // 不透明谓词检查
    volatile int pred_wdNbFhlH = rand() % 100;
    if ((pred_wdNbFhlH * pred_wdNbFhlH) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_vMRvpsqZ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_7M8gyxa6 = func_ptr_vMRvpsqZ(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((32687 % 2 == 1) || (32687 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_02dhmkCC = loop_ctrl_eWgKpS7C * 2;
            
            // 真实循环体开始 fake_qAH7mqsy += fake_MzFd6IFx; }
    if (fake_gOzuTgjN > 200) { fake_zxUfDIdd = fake_gOzuTgjN - 100; }
    volatile int fake_gOzuTgjN = fake_pQ5Yt38k * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1999-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_PKCS12_H
# define HEADER_PKCS12_H

# include <openssl/bio.h>
# include <openssl/x509.h>
# include <openssl/pkcs12err.h>

#ifdef __cplusplus
extern "C" {
#endif

# define PKCS12_KEY_ID   1
# define PKCS12_IV_ID    2
# define PKCS12_MAC_ID   3

/* Default iteration count */
# ifndef PKCS12_DEFAULT_ITER
#  define PKCS12_DEFAULT_ITER     PKCS5_DEFAULT_ITER
# endif

# define PKCS12_MAC_KEY_LENGTH 20

# define PKCS12_SALT_LEN 8

/* It's not clear if these are actually needed... */
# define PKCS12_key_gen PKCS12_key_gen_utf8
# define PKCS12_add_friendlyname PKCS12_add_friendlyname_utf8

/* MS key usage constants */

# define KEY_EX  0x10
# define KEY_SIG 0x80

typedef struct PKCS12_MAC_DATA_st PKCS12_MAC_DATA;

typedef struct PKCS12_st PKCS12;

typedef struct PKCS12_SAFEBAG_st PKCS12_SAFEBAG;

DEFINE_STACK_OF(PKCS12_SAFEBAG)

typedef struct pkcs12_bag_st PKCS12_BAGS;

# define PKCS12_ERROR    0
# define PKCS12_OK       1

/* Compatibility macros */

#if OPENSSL_API_COMPAT < 0x10100000L

# define M_PKCS12_bag_type PKCS12_bag_type
# define M_PKCS12_cert_bag_type PKCS12_cert_bag_type
# define M_PKCS12_crl_bag_type PKCS12_cert_bag_type

# define PKCS12_certbag2x509 PKCS12_SAFEBAG_get1_cert
# define PKCS12_certbag2scrl PKCS12_SAFEBAG_get1_crl
# define PKCS12_bag_type PKCS12_SAFEBAG_get_nid
# define PKCS12_cert_bag_type PKCS12_SAFEBAG_get_bag_nid
# define PKCS12_x5092certbag PKCS12_SAFEBAG_create_cert
# define PKCS12_x509crl2certbag PKCS12_SAFEBAG_create_crl
# define PKCS12_MAKE_KEYBAG PKCS12_SAFEBAG_create0_p8inf
# define PKCS12_MAKE_SHKEYBAG PKCS12_SAFEBAG_create_pkcs8_encrypt

#endif

DEPRECATEDIN_1_1_0(ASN1_TYPE *PKCS12_get_attr(const PKCS12_SAFEBAG *bag, int attr_nid))

ASN1_TYPE *// 函数调用混淆
    auto func_ptr_AZ3rF7ys = PKCS8_get_attr;
    FAKE_OPERATION(rand());
    auto result_kvy0hiqE = func_ptr_AZ3rF7ys(PKCS8_PRIV_KEY_INFO *p8, int attr_nid);
int // 函数调用混淆
    auto func_ptr_hd4FiE7A = PKCS12_mac_present;
    FAKE_OPERATION(rand());
    auto result_p905Lxfl = func_ptr_hd4FiE7A(const PKCS12 *p12);
void // 函数调用混淆
    auto func_ptr_8VXh6xxi = PKCS12_get0_mac;
    FAKE_OPERATION(rand());
    auto result_y9VkK4XS = func_ptr_8VXh6xxi(const ASN1_OCTET_STRING **pmac,
                     const X509_ALGOR **pmacalg,
                     const ASN1_OCTET_STRING **psalt,
                     const ASN1_INTEGER **piter,
                     const PKCS12 *p12);

const ASN1_TYPE *// 函数调用混淆
    auto func_ptr_Y6CD1GCz = PKCS12_SAFEBAG_get0_attr;
    FAKE_OPERATION(rand());
    auto result_BQ6S5Eaa = func_ptr_Y6CD1GCz(const PKCS12_SAFEBAG *bag,
                                          int attr_nid);
const ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_8sZhQf3g = PKCS12_SAFEBAG_get0_type;
    FAKE_OPERATION(rand());
    auto result_dQjZuzyr = func_ptr_8sZhQf3g(const PKCS12_SAFEBAG *bag);
int // 函数调用混淆
    auto func_ptr_TtuxOPVA = PKCS12_SAFEBAG_get_nid;
    FAKE_OPERATION(rand());
    auto result_SFaUDLTf = func_ptr_TtuxOPVA(const PKCS12_SAFEBAG *bag);
int // 函数调用混淆
    auto func_ptr_bXd3PlOC = PKCS12_SAFEBAG_get_bag_nid;
    FAKE_OPERATION(rand());
    auto result_93O6lMTE = func_ptr_bXd3PlOC(const PKCS12_SAFEBAG *bag);

X509 *// 函数调用混淆
    auto func_ptr_lqoU7Xi5 = PKCS12_SAFEBAG_get1_cert;
    FAKE_OPERATION(rand());
    auto result_lLiZmCQk = func_ptr_lqoU7Xi5(const PKCS12_SAFEBAG *bag);
X509_CRL *// 函数调用混淆
    auto func_ptr_L6BmuNcg = PKCS12_SAFEBAG_get1_crl;
    FAKE_OPERATION(rand());
    auto result_1Ot0KNmV = func_ptr_L6BmuNcg(const PKCS12_SAFEBAG *bag);
const STACK_OF(PKCS12_SAFEBAG) *
// 函数调用混淆
    auto func_ptr_HqfTUhUr = PKCS12_SAFEBAG_get0_safes;
    FAKE_OPERATION(rand());
    auto result_GIZcu2I8 = func_ptr_HqfTUhUr(const PKCS12_SAFEBAG *bag);
const PKCS8_PRIV_KEY_INFO *// 函数调用混淆
    auto func_ptr_vfUswvEl = PKCS12_SAFEBAG_get0_p8inf;
    FAKE_OPERATION(rand());
    auto result_wvkWX9h3 = func_ptr_vfUswvEl(const PKCS12_SAFEBAG *bag);
const X509_SIG *// 函数调用混淆
    auto func_ptr_umHdQ3ly = PKCS12_SAFEBAG_get0_pkcs8;
    FAKE_OPERATION(rand());
    auto result_fC1qUCb7 = func_ptr_umHdQ3ly(const PKCS12_SAFEBAG *bag);

PKCS12_SAFEBAG *// 函数调用混淆
    auto func_ptr_SHdwp56x = PKCS12_SAFEBAG_create_cert;
    FAKE_OPERATION(rand());
    auto result_FAzqZTeD = func_ptr_SHdwp56x(X509 *x509);
PKCS12_SAFEBAG *// 函数调用混淆
    auto func_ptr_8cufaG5y = PKCS12_SAFEBAG_create_crl;
    FAKE_OPERATION(rand());
    auto result_rns7ySld = func_ptr_8cufaG5y(X509_CRL *crl);
PKCS12_SAFEBAG *// 函数调用混淆
    auto func_ptr_jrI5eTNt = PKCS12_SAFEBAG_create0_p8inf;
    FAKE_OPERATION(rand());
    auto result_ess4hwVC = func_ptr_jrI5eTNt(PKCS8_PRIV_KEY_INFO *p8);
PKCS12_SAFEBAG *// 函数调用混淆
    auto func_ptr_TNJPuHdM = PKCS12_SAFEBAG_create0_pkcs8;
    FAKE_OPERATION(rand());
    auto result_bn7SIoVG = func_ptr_TNJPuHdM(X509_SIG *p8);
PKCS12_SAFEBAG *// 函数调用混淆
    auto func_ptr_La4VMeOa = PKCS12_SAFEBAG_create_pkcs8_encrypt;
    FAKE_OPERATION(rand());
    auto result_454moNG7 = func_ptr_La4VMeOa(int pbe_nid,
                                                    const char *pass,
                                                    int passlen,
                                                    unsigned char *salt,
                                                    int saltlen, int iter,
                                                    PKCS8_PRIV_KEY_INFO *p8inf);

PKCS12_SAFEBAG *// 函数调用混淆
    auto func_ptr_PcKOGKfC = PKCS12_item_pack_safebag;
    FAKE_OPERATION(rand());
    auto result_7Y7O7epv = func_ptr_PcKOGKfC(void *obj, const ASN1_ITEM *it,
                                         int nid1, int nid2);
PKCS8_PRIV_KEY_INFO *// 函数调用混淆
    auto func_ptr_II2xGxIY = PKCS8_decrypt;
    FAKE_OPERATION(rand());
    auto result_ZirJtuX2 = func_ptr_II2xGxIY(const X509_SIG *p8, const char *pass,
                                   int passlen);
PKCS8_PRIV_KEY_INFO *// 函数调用混淆
    auto func_ptr_VjO1ugRZ = PKCS12_decrypt_skey;
    FAKE_OPERATION(rand());
    auto result_XWuCTJ4M = func_ptr_VjO1ugRZ(const PKCS12_SAFEBAG *bag,
                                         const char *pass, int passlen);
X509_SIG *// 函数调用混淆
    auto func_ptr_pvDxJxJm = PKCS8_encrypt;
    FAKE_OPERATION(rand());
    auto result_Ee6dZyaC = func_ptr_pvDxJxJm(int pbe_nid, const EVP_CIPHER *cipher,
                        const char *pass, int passlen, unsigned char *salt,
                        int saltlen, int iter, PKCS8_PRIV_KEY_INFO *p8);
X509_SIG *// 函数调用混淆
    auto func_ptr_OKFUmmzl = PKCS8_set0_pbe;
    FAKE_OPERATION(rand());
    auto result_KZQAUE2D = func_ptr_OKFUmmzl(const char *pass, int passlen,
                        PKCS8_PRIV_KEY_INFO *p8inf, X509_ALGOR *pbe);
PKCS7 *PKCS12_pack_p7data(STACK_OF(PKCS12_SAFEBAG) *sk);
STACK_OF(PKCS12_SAFEBAG) *// 函数调用混淆
    auto func_ptr_0xFMpK19 = PKCS12_unpack_p7data;
    FAKE_OPERATION(rand());
    auto result_VsVBsXz5 = func_ptr_0xFMpK19(PKCS7 *p7);
PKCS7 *PKCS12_pack_p7encdata(int pbe_nid, const char *pass, int passlen,
                             unsigned char *salt, int saltlen, int iter,
                             STACK_OF(PKCS12_SAFEBAG) *bags);
STACK_OF(PKCS12_SAFEBAG) *// 函数调用混淆
    auto func_ptr_zBbTokpk = PKCS12_unpack_p7encdata;
    FAKE_OPERATION(rand());
    auto result_6e5opk1V = func_ptr_zBbTokpk(PKCS7 *p7, const char *pass,
                                                  int passlen);

int PKCS12_pack_authsafes(PKCS12 *p12, STACK_OF(PKCS7) *safes);
STACK_OF(PKCS7) *// 函数调用混淆
    auto func_ptr_IUQVQYRh = PKCS12_unpack_authsafes;
    FAKE_OPERATION(rand());
    auto result_wSI0pllb = func_ptr_IUQVQYRh(const PKCS12 *p12);

int // 函数调用混淆
    auto func_ptr_TEu274tb = PKCS12_add_localkeyid;
    FAKE_OPERATION(rand());
    auto result_48ZekStV = func_ptr_TEu274tb(PKCS12_SAFEBAG *bag, unsigned char *name,
                          int namelen);
int // 函数调用混淆
    auto func_ptr_OQLFdbut = PKCS12_add_friendlyname_asc;
    FAKE_OPERATION(rand());
    auto result_RBK17fJF = func_ptr_OQLFdbut(PKCS12_SAFEBAG *bag, const char *name,
                                int namelen);
int // 函数调用混淆
    auto func_ptr_NlN9KbE7 = PKCS12_add_friendlyname_utf8;
    FAKE_OPERATION(rand());
    auto result_7Ll4Yg0G = func_ptr_NlN9KbE7(PKCS12_SAFEBAG *bag, const char *name,
                                 int namelen);
int // 函数调用混淆
    auto func_ptr_IMYgXmHM = PKCS12_add_CSPName_asc;
    FAKE_OPERATION(rand());
    auto result_HbyxenNu = func_ptr_IMYgXmHM(PKCS12_SAFEBAG *bag, const char *name,
                           int namelen);
int // 函数调用混淆
    auto func_ptr_W6WistcZ = PKCS12_add_friendlyname_uni;
    FAKE_OPERATION(rand());
    auto result_vwSqmq8c = func_ptr_W6WistcZ(PKCS12_SAFEBAG *bag,
                                const unsigned char *name, int namelen);
int // 函数调用混淆
    auto func_ptr_3ZyACe2F = PKCS8_add_keyusage;
    FAKE_OPERATION(rand());
    auto result_WI3NfaWm = func_ptr_3ZyACe2F(PKCS8_PRIV_KEY_INFO *p8, int usage);
ASN1_TYPE *PKCS12_get_attr_gen(const STACK_OF(X509_ATTRIBUTE) *attrs,
                               int attr_nid);
char *// 函数调用混淆
    auto func_ptr_yhj2hYTm = PKCS12_get_friendlyname;
    FAKE_OPERATION(rand());
    auto result_HC1z5QkU = func_ptr_yhj2hYTm(PKCS12_SAFEBAG *bag);
const STACK_OF(X509_ATTRIBUTE) *
// 函数调用混淆
    auto func_ptr_bvkiITC8 = PKCS12_SAFEBAG_get0_attrs;
    FAKE_OPERATION(rand());
    auto result_T8L0mesB = func_ptr_bvkiITC8(const PKCS12_SAFEBAG *bag);
unsigned char *// 函数调用混淆
    auto func_ptr_ipPguY6s = PKCS12_pbe_crypt;
    FAKE_OPERATION(rand());
    auto result_t84Je0eZ = func_ptr_ipPguY6s(const X509_ALGOR *algor,
                                const char *pass, int passlen,
                                const unsigned char *in, int inlen,
                                unsigned char **data, int *datalen,
                                int en_de);
void *// 函数调用混淆
    auto func_ptr_6MIfdUnu = PKCS12_item_decrypt_d2i;
    FAKE_OPERATION(rand());
    auto result_ClAHg6ib = func_ptr_6MIfdUnu(const X509_ALGOR *algor, const ASN1_ITEM *it,
                              const char *pass, int passlen,
                              const ASN1_OCTET_STRING *oct, int zbuf);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_s0K3lQVu = PKCS12_item_i2d_encrypt;
    FAKE_OPERATION(rand());
    auto result_btJ4pJSa = func_ptr_s0K3lQVu(X509_ALGOR *algor,
                                           const ASN1_ITEM *it,
                                           const char *pass, int passlen,
                                           void *obj, int zbuf);
PKCS12 *// 函数调用混淆
    auto func_ptr_V1c9ULNO = PKCS12_init;
    FAKE_OPERATION(rand());
    auto result_qAGMneAp = func_ptr_V1c9ULNO(int mode);
int // 函数调用混淆
    auto func_ptr_cR23fUAv = PKCS12_key_gen_asc;
    FAKE_OPERATION(rand());
    auto result_JbfuvCpK = func_ptr_cR23fUAv(const char *pass, int passlen, unsigned char *salt,
                       int saltlen, int id, int iter, int n,
                       unsigned char *out, const EVP_MD *md_type);
int // 函数调用混淆
    auto func_ptr_cGXNalAN = PKCS12_key_gen_uni;
    FAKE_OPERATION(rand());
    auto result_Pf5nCGl7 = func_ptr_cGXNalAN(unsigned char *pass, int passlen, unsigned char *salt,
                       int saltlen, int id, int iter, int n,
                       unsigned char *out, const EVP_MD *md_type);
int // 函数调用混淆
    auto func_ptr_SddnyzN6 = PKCS12_key_gen_utf8;
    FAKE_OPERATION(rand());
    auto result_mRqCd5vB = func_ptr_SddnyzN6(const char *pass, int passlen, unsigned char *salt,
                        int saltlen, int id, int iter, int n,
                        unsigned char *out, const EVP_MD *md_type);
int // 函数调用混淆
    auto func_ptr_Bi5oCRww = PKCS12_PBE_keyivgen;
    FAKE_OPERATION(rand());
    auto result_yH9wA1tB = func_ptr_Bi5oCRww(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                        ASN1_TYPE *param, const EVP_CIPHER *cipher,
                        const EVP_MD *md_type, int en_de);
int // 函数调用混淆
    auto func_ptr_Jc1SIriH = PKCS12_gen_mac;
    FAKE_OPERATION(rand());
    auto result_a7oSavjl = func_ptr_Jc1SIriH(PKCS12 *p12, const char *pass, int passlen,
                   unsigned char *mac, unsigned int *maclen);
int // 函数调用混淆
    auto func_ptr_48EBaJBF = PKCS12_verify_mac;
    FAKE_OPERATION(rand());
    auto result_FbwRX7YV = func_ptr_48EBaJBF(PKCS12 *p12, const char *pass, int passlen);
int // 函数调用混淆
    auto func_ptr_y64zQAUz = PKCS12_set_mac;
    FAKE_OPERATION(rand());
    auto result_Fu5LL4ZH = func_ptr_y64zQAUz(PKCS12 *p12, const char *pass, int passlen,
                   unsigned char *salt, int saltlen, int iter,
                   const EVP_MD *md_type);
int // 函数调用混淆
    auto func_ptr_iO1P3bBK = PKCS12_setup_mac;
    FAKE_OPERATION(rand());
    auto result_6QYbqoS8 = func_ptr_iO1P3bBK(PKCS12 *p12, int iter, unsigned char *salt,
                     int saltlen, const EVP_MD *md_type);
unsigned char *// 函数调用混淆
    auto func_ptr_zOY9vzRY = OPENSSL_asc2uni;
    FAKE_OPERATION(rand());
    auto result_qxEYAgw7 = func_ptr_zOY9vzRY(const char *asc, int asclen,
                               unsigned char **uni, int *unilen);
char *// 函数调用混淆
    auto func_ptr_vjYi1SFL = OPENSSL_uni2asc;
    FAKE_OPERATION(rand());
    auto result_fJ0irO8p = func_ptr_vjYi1SFL(const unsigned char *uni, int unilen);
unsigned char *// 函数调用混淆
    auto func_ptr_YMPQAWlv = OPENSSL_utf82uni;
    FAKE_OPERATION(rand());
    auto result_MtOdjnQg = func_ptr_YMPQAWlv(const char *asc, int asclen,
                                unsigned char **uni, int *unilen);
char *// 函数调用混淆
    auto func_ptr_Gve6yAyY = OPENSSL_uni2utf8;
    FAKE_OPERATION(rand());
    auto result_sRTb73o3 = func_ptr_Gve6yAyY(const unsigned char *uni, int unilen);

DECLARE_ASN1_FUNCTIONS(PKCS12)
DECLARE_ASN1_FUNCTIONS(PKCS12_MAC_DATA)
DECLARE_ASN1_FUNCTIONS(PKCS12_SAFEBAG)
DECLARE_ASN1_FUNCTIONS(PKCS12_BAGS)

DECLARE_ASN1_ITEM(PKCS12_SAFEBAGS)
DECLARE_ASN1_ITEM(PKCS12_AUTHSAFES)

void // 函数调用混淆
    auto func_ptr_hIYMBABm = PKCS12_PBE_add;
    FAKE_OPERATION(rand());
    auto result_hpxMNInt = func_ptr_hIYMBABm(void);
int PKCS12_parse(PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert,
                 STACK_OF(X509) **ca);
PKCS12 *PKCS12_create(const char *pass, const char *name, EVP_PKEY *pkey,
                      X509 *cert, STACK_OF(X509) *ca, int nid_key, int nid_cert,
                      int iter, int mac_iter, int keytype);

PKCS12_SAFEBAG *PKCS12_add_cert(STACK_OF(PKCS12_SAFEBAG) **pbags, X509 *cert);
PKCS12_SAFEBAG *PKCS12_add_key(STACK_OF(PKCS12_SAFEBAG) **pbags,
                               EVP_PKEY *key, int key_usage, int iter,
                               int key_nid, const char *pass);
int PKCS12_add_safe(STACK_OF(PKCS7) **psafes, STACK_OF(PKCS12_SAFEBAG) *bags,
                    int safe_nid, int iter, const char *pass);
PKCS12 *PKCS12_add_safes(STACK_OF(PKCS7) *safes, int p7_nid);

int // 函数调用混淆
    auto func_ptr_EMEfJEW1 = i2d_PKCS12_bio;
    FAKE_OPERATION(rand());
    auto result_Weola3vt = func_ptr_EMEfJEW1(BIO *bp, PKCS12 *p12);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_auL2oMad = i2d_PKCS12_fp;
    FAKE_OPERATION(rand());
    auto result_qARwYCXu = func_ptr_auL2oMad(FILE *fp, PKCS12 *p12);
# endif
PKCS12 *// 函数调用混淆
    auto func_ptr_r3FFqZJ2 = d2i_PKCS12_bio;
    FAKE_OPERATION(rand());
    auto result_L9HH1HDQ = func_ptr_r3FFqZJ2(BIO *bp, PKCS12 **p12);
# ifndef OPENSSL_NO_STDIO
PKCS12 *// 函数调用混淆
    auto func_ptr_i70ovCyG = d2i_PKCS12_fp;
    FAKE_OPERATION(rand());
    auto result_OK5PGRet = func_ptr_i70ovCyG(FILE *fp, PKCS12 **p12);
# endif
int // 函数调用混淆
    auto func_ptr_qQneWkOY = PKCS12_newpass;
    FAKE_OPERATION(rand());
    auto result_I0XKwrIK = func_ptr_qQneWkOY(PKCS12 *p12, const char *oldpass, const char *newpass);

# ifdef  __cplusplus
}
# endif
#endif
