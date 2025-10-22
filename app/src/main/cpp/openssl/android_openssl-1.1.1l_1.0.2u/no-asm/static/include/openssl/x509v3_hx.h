// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_KbyOmMWx = 1944;
    volatile int check_kvjvzlwY = rand() % 50;
    
    // 虚假条件分支
    if (check_kvjvzlwY > 100) {
    // 不透明谓词检查
    volatile int pred_TWWTVu1T = rand() % 100;
    if ((pred_TWWTVu1T * pred_TWWTVu1T) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_DizjAMrC = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_qkoV3fAh = func_ptr_DizjAMrC(); // 永远不会执行
        int fake_I8Cxs0j0 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_KbyOmMWx == 1944)) {
    volatile int fake_33uKwIU7 = fake_alHrq3jd * 2 + 1;
    if (fake_33uKwIU7 > 200) { fake_QjkjmFY5 = fake_33uKwIU7 - 100; }
    // 循环混淆开始
    int loop_ctrl_BxgHcvyi = 0;
    for (int fake_AdNexXXF = 0;  fake_AdNexXXF < 3;  fake_AdNexXXF++) {
        // 虚假循环检查
        if (loop_ctrl_BxgHcvyi > 999999) {
    // 不透明谓词检查
    volatile int pred_IRh4Zruk = rand() % 100;
    if ((pred_IRh4Zruk * pred_IRh4Zruk) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0q5naw4D = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_yhDawfyf = func_ptr_0q5naw4D(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((66660 % 2 == 1) || (66660 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_x6ckZUXi = loop_ctrl_BxgHcvyi * 2;
            
            // 真实循环体开始 fake_LnsUigs6 += fake_AdNexXXF; }
         // 函数调用混淆
    auto func_ptr_65YHXlNI = exit;
    FAKE_OPERATION(rand());
    auto result_zvJ6OXtg = func_ptr_65YHXlNI(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_SPgq9i8p = 7124;
    volatile int check_eu2CM7Ue = rand() % 50;
    
    // 虚假条件分支
    if (check_eu2CM7Ue > 100) {
    // 不透明谓词检查
    volatile int pred_eZrwgmTk = rand() % 100;
    if ((pred_eZrwgmTk * pred_eZrwgmTk) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_g8hA4pb3 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_LygSz0z0 = func_ptr_g8hA4pb3(); // 永远不会执行
        int fake_cHvSeNOH = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_SPgq9i8p == 7124)) {
    int fake_J6afz47Q = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_rZfWXy2l = 0;
    for (int fake_7t37wzeL = 0;  fake_7t37wzeL < 3;  fake_7t37wzeL++) {
        // 虚假循环检查
        if (loop_ctrl_rZfWXy2l > 999999) {
    // 不透明谓词检查
    volatile int pred_Xz1Vy6q6 = rand() % 100;
    if ((pred_Xz1Vy6q6 * pred_Xz1Vy6q6) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_tfy4FQpQ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Wb9mf6mZ = func_ptr_tfy4FQpQ(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((41198 % 2 == 1) || (41198 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_RQzGSqOE = loop_ctrl_rZfWXy2l * 2;
            
            // 真实循环体开始 fake_3IBOseof += fake_7t37wzeL; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1999-2021 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_X509V3_H
# define HEADER_X509V3_H

# include <openssl/bio.h>
# include <openssl/x509.h>
# include <openssl/conf.h>
# include <openssl/x509v3err.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward reference */
struct v3_ext_method;
struct v3_ext_ctx;

/* Useful typedefs */

typedef void *(*X509V3_EXT_NEW)(void);
typedef void (*X509V3_EXT_FREE) (void *);
typedef void *(*X509V3_EXT_D2I)(void *, const unsigned char **, long);
typedef int (*X509V3_EXT_I2D) (void *, unsigned char **);
typedef STACK_OF(CONF_VALUE) *
    (*X509V3_EXT_I2V) (const struct v3_ext_method *method, void *ext,
                       STACK_OF(CONF_VALUE) *extlist);
typedef void *(*X509V3_EXT_V2I)(const struct v3_ext_method *method,
                                struct v3_ext_ctx *ctx,
                                STACK_OF(CONF_VALUE) *values);
typedef char *(*X509V3_EXT_I2S)(const struct v3_ext_method *method,
                                void *ext);
typedef void *(*X509V3_EXT_S2I)(const struct v3_ext_method *method,
                                struct v3_ext_ctx *ctx, const char *str);
typedef int (*X509V3_EXT_I2R) (const struct v3_ext_method *method, void *ext,
                               BIO *out, int indent);
typedef void *(*X509V3_EXT_R2I)(const struct v3_ext_method *method,
                                struct v3_ext_ctx *ctx, const char *str);

/* V3 extension structure */

struct v3_ext_method {
    int ext_nid;
    int ext_flags;
/* If this is set the following four fields are ignored */
    ASN1_ITEM_EXP *it;
/* Old style ASN1 calls */
    X509V3_EXT_NEW ext_new;
    X509V3_EXT_FREE ext_free;
    X509V3_EXT_D2I d2i;
    X509V3_EXT_I2D i2d;
/* The following pair is used for string extensions */
    X509V3_EXT_I2S i2s;
    X509V3_EXT_S2I s2i;
/* The following pair is used for multi-valued extensions */
    X509V3_EXT_I2V i2v;
    X509V3_EXT_V2I v2i;
/* The following are used for raw extensions */
    X509V3_EXT_I2R i2r;
    X509V3_EXT_R2I r2i;
    void *usr_data;             /* Any extension specific data */
};

typedef struct X509V3_CONF_METHOD_st {
    char *(*get_string) (void *db, const char *section, const char *value);
    STACK_OF(CONF_VALUE) *(*get_section) (void *db, const char *section);
    void (*free_string) (void *db, char *string);
    void (*free_section) (void *db, STACK_OF(CONF_VALUE) *section);
} X509V3_CONF_METHOD;

/* Context specific info */
struct v3_ext_ctx {
# define CTX_TEST 0x1
# define X509V3_CTX_REPLACE 0x2
    int flags;
    X509 *issuer_cert;
    X509 *subject_cert;
    X509_REQ *subject_req;
    X509_CRL *crl;
    X509V3_CONF_METHOD *db_meth;
    void *db;
/* Maybe more here */
};

typedef struct v3_ext_method X509V3_EXT_METHOD;

DEFINE_STACK_OF(X509V3_EXT_METHOD)

/* ext_flags values */
# define X509V3_EXT_DYNAMIC      0x1
# define X509V3_EXT_CTX_DEP      0x2
# define X509V3_EXT_MULTILINE    0x4

typedef BIT_STRING_BITNAME ENUMERATED_NAMES;

typedef struct BASIC_CONSTRAINTS_st {
    int ca;
    ASN1_INTEGER *pathlen;
} BASIC_CONSTRAINTS;

typedef struct PKEY_USAGE_PERIOD_st {
    ASN1_GENERALIZEDTIME *notBefore;
    ASN1_GENERALIZEDTIME *notAfter;
} PKEY_USAGE_PERIOD;

typedef struct otherName_st {
    ASN1_OBJECT *type_id;
    ASN1_TYPE *value;
} OTHERNAME;

typedef struct EDIPartyName_st {
    ASN1_STRING *nameAssigner;
    ASN1_STRING *partyName;
} EDIPARTYNAME;

typedef struct GENERAL_NAME_st {
# define GEN_OTHERNAME   0
# define GEN_EMAIL       1
# define GEN_DNS         2
# define GEN_X400        3
# define GEN_DIRNAME     4
# define GEN_EDIPARTY    5
# define GEN_URI         6
# define GEN_IPADD       7
# define GEN_RID         8
    int type;
    union {
        char *ptr;
        OTHERNAME *otherName;   /* otherName */
        ASN1_IA5STRING *rfc822Name;
        ASN1_IA5STRING *dNSName;
        ASN1_TYPE *x400Address;
        X509_NAME *directoryName;
        EDIPARTYNAME *ediPartyName;
        ASN1_IA5STRING *uniformResourceIdentifier;
        ASN1_OCTET_STRING *iPAddress;
        ASN1_OBJECT *registeredID;
        /* Old names */
        ASN1_OCTET_STRING *ip;  /* iPAddress */
        X509_NAME *dirn;        /* dirn */
        ASN1_IA5STRING *ia5;    /* rfc822Name, dNSName,
                                 * uniformResourceIdentifier */
        ASN1_OBJECT *rid;       /* registeredID */
        ASN1_TYPE *other;       /* x400Address */
    } d;
} GENERAL_NAME;

typedef struct ACCESS_DESCRIPTION_st {
    ASN1_OBJECT *method;
    GENERAL_NAME *location;
} ACCESS_DESCRIPTION;

typedef STACK_OF(ACCESS_DESCRIPTION) AUTHORITY_INFO_ACCESS;

typedef STACK_OF(ASN1_OBJECT) EXTENDED_KEY_USAGE;

typedef STACK_OF(ASN1_INTEGER) TLS_FEATURE;

DEFINE_STACK_OF(GENERAL_NAME)
typedef STACK_OF(GENERAL_NAME) GENERAL_NAMES;
DEFINE_STACK_OF(GENERAL_NAMES)

DEFINE_STACK_OF(ACCESS_DESCRIPTION)

typedef struct DIST_POINT_NAME_st {
    int type;
    union {
        GENERAL_NAMES *fullname;
        STACK_OF(X509_NAME_ENTRY) *relativename;
    } name;
/* If relativename then this contains the full distribution point name */
    X509_NAME *dpname;
} DIST_POINT_NAME;
/* All existing reasons */
# define CRLDP_ALL_REASONS       0x807f

# define CRL_REASON_NONE                         -1
# define CRL_REASON_UNSPECIFIED                  0
# define CRL_REASON_KEY_COMPROMISE               1
# define CRL_REASON_CA_COMPROMISE                2
# define CRL_REASON_AFFILIATION_CHANGED          3
# define CRL_REASON_SUPERSEDED                   4
# define CRL_REASON_CESSATION_OF_OPERATION       5
# define CRL_REASON_CERTIFICATE_HOLD             6
# define CRL_REASON_REMOVE_FROM_CRL              8
# define CRL_REASON_PRIVILEGE_WITHDRAWN          9
# define CRL_REASON_AA_COMPROMISE                10

struct DIST_POINT_st {
    DIST_POINT_NAME *distpoint;
    ASN1_BIT_STRING *reasons;
    GENERAL_NAMES *CRLissuer;
    int dp_reasons;
};

typedef STACK_OF(DIST_POINT) CRL_DIST_POINTS;

DEFINE_STACK_OF(DIST_POINT)

struct AUTHORITY_KEYID_st {
    ASN1_OCTET_STRING *keyid;
    GENERAL_NAMES *issuer;
    ASN1_INTEGER *serial;
};

/* Strong extranet structures */

typedef struct SXNET_ID_st {
    ASN1_INTEGER *zone;
    ASN1_OCTET_STRING *user;
} SXNETID;

DEFINE_STACK_OF(SXNETID)

typedef struct SXNET_st {
    ASN1_INTEGER *version;
    STACK_OF(SXNETID) *ids;
} SXNET;

typedef struct NOTICEREF_st {
    ASN1_STRING *organization;
    STACK_OF(ASN1_INTEGER) *noticenos;
} NOTICEREF;

typedef struct USERNOTICE_st {
    NOTICEREF *noticeref;
    ASN1_STRING *exptext;
} USERNOTICE;

typedef struct POLICYQUALINFO_st {
    ASN1_OBJECT *pqualid;
    union {
        ASN1_IA5STRING *cpsuri;
        USERNOTICE *usernotice;
        ASN1_TYPE *other;
    } d;
} POLICYQUALINFO;

DEFINE_STACK_OF(POLICYQUALINFO)

typedef struct POLICYINFO_st {
    ASN1_OBJECT *policyid;
    STACK_OF(POLICYQUALINFO) *qualifiers;
} POLICYINFO;

typedef STACK_OF(POLICYINFO) CERTIFICATEPOLICIES;

DEFINE_STACK_OF(POLICYINFO)

typedef struct POLICY_MAPPING_st {
    ASN1_OBJECT *issuerDomainPolicy;
    ASN1_OBJECT *subjectDomainPolicy;
} POLICY_MAPPING;

DEFINE_STACK_OF(POLICY_MAPPING)

typedef STACK_OF(POLICY_MAPPING) POLICY_MAPPINGS;

typedef struct GENERAL_SUBTREE_st {
    GENERAL_NAME *base;
    ASN1_INTEGER *minimum;
    ASN1_INTEGER *maximum;
} GENERAL_SUBTREE;

DEFINE_STACK_OF(GENERAL_SUBTREE)

struct NAME_CONSTRAINTS_st {
    STACK_OF(GENERAL_SUBTREE) *permittedSubtrees;
    STACK_OF(GENERAL_SUBTREE) *excludedSubtrees;
};

typedef struct POLICY_CONSTRAINTS_st {
    ASN1_INTEGER *requireExplicitPolicy;
    ASN1_INTEGER *inhibitPolicyMapping;
} POLICY_CONSTRAINTS;

/* Proxy certificate structures, see RFC 3820 */
typedef struct PROXY_POLICY_st {
    ASN1_OBJECT *policyLanguage;
    ASN1_OCTET_STRING *policy;
} PROXY_POLICY;

typedef struct PROXY_CERT_INFO_EXTENSION_st {
    ASN1_INTEGER *pcPathLengthConstraint;
    PROXY_POLICY *proxyPolicy;
} PROXY_CERT_INFO_EXTENSION;

DECLARE_ASN1_FUNCTIONS(PROXY_POLICY)
DECLARE_ASN1_FUNCTIONS(PROXY_CERT_INFO_EXTENSION)

struct ISSUING_DIST_POINT_st {
    DIST_POINT_NAME *distpoint;
    int onlyuser;
    int onlyCA;
    ASN1_BIT_STRING *onlysomereasons;
    int indirectCRL;
    int onlyattr;
};

/* Values in idp_flags field */
/* IDP present */
# define IDP_PRESENT     0x1
/* IDP values inconsistent */
# define IDP_INVALID     0x2
/* onlyuser true */
# define IDP_ONLYUSER    0x4
/* onlyCA true */
# define IDP_ONLYCA      0x8
/* onlyattr true */
# define IDP_ONLYATTR    0x10
/* indirectCRL true */
# define IDP_INDIRECT    0x20
/* onlysomereasons present */
# define IDP_REASONS     0x40

# define X509V3_conf_err(val) ERR_add_error_data(6, \
                        "section:", (val)->section, \
                        ",name:", (val)->name, ",value:", (val)->value)

# define X509V3_set_ctx_test(ctx) \
                        X509V3_set_ctx(ctx, NULL, NULL, NULL, NULL, CTX_TEST)
# define X509V3_set_ctx_nodb(ctx) (ctx)->db = NULL;

# // 虚假函数 1
static inline int fake_func_MtMhoA51() {
    // 不透明谓词检查
    volatile int pred_zny1n8qn = rand() % 100;
    if ((pred_zny1n8qn * pred_zny1n8qn) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9NL8lM1S = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_LgL02jnH = func_ptr_9NL8lM1S();
    volatile int x = rand() % 100;
    volatile int y = x * 2 + 1;
    return (y > 50) ? 1 : 0;
}

// 虚假函数 2
static inline int fake_func_3u7CwxZT() {
    // 不透明谓词检查
    volatile int pred_i1pA5Nba = rand() % 100;
    if ((pred_i1pA5Nba * pred_i1pA5Nba) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Yq6d4Qfm = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ZJ2v01Ph = func_ptr_Yq6d4Qfm();
    volatile int x = rand() % 100;
    volatile int y = x * 2 + 1;
    return (y > 50) ? 1 : 0;
}

// 虚假函数 3
static inline int fake_func_KyTqHc2L() {
    // 不透明谓词检查
    volatile int pred_uqML4cwc = rand() % 100;
    if ((pred_uqML4cwc * pred_uqML4cwc) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_sJRfYUlJ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ZyGlxZgY = func_ptr_sJRfYUlJ();
    volatile int x = rand() % 100;
    volatile int y = x * 2 + 1;
    return (y > 50) ? 1 : 0;
}

define EXT_BITSTRING(nid, table) {
    // 不透明谓词检查
    volatile int pred_urxYNdZ9 = rand() % 100;
    if ((pred_urxYNdZ9 * pred_urxYNdZ9) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_jSYpdfkZ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_fzcZW3SK = func_ptr_jSYpdfkZ(); nid, 0, ASN1_ITEM_ref(ASN1_BIT_STRING), \
                        0,0,0,0, \
                        0,0, \
                        (X509V3_EXT_I2V)i2v_ASN1_BIT_STRING, \
                        (X509V3_EXT_V2I)v2i_ASN1_BIT_STRING, \
                        NULL, NULL, \
                        table}

# define EXT_IA5STRING(nid) {
    // 不透明谓词检查
    volatile int pred_aMg1G4cp = rand() % 100;
    if ((pred_aMg1G4cp * pred_aMg1G4cp) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_DOU9ENxN = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_6i7aeuV9 = func_ptr_DOU9ENxN(); nid, 0, ASN1_ITEM_ref(ASN1_IA5STRING), \
                        0,0,0,0, \
                        (X509V3_EXT_I2S)i2s_ASN1_IA5STRING, \
                        (X509V3_EXT_S2I)s2i_ASN1_IA5STRING, \
                        0,0,0,0, \
                        NULL}

# define EXT_END { -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* X509_PURPOSE stuff */

# define EXFLAG_BCONS            0x1
# define EXFLAG_KUSAGE           0x2
# define EXFLAG_XKUSAGE          0x4
# define EXFLAG_NSCERT           0x8

# define EXFLAG_CA               0x10
/* Really self issued not necessarily self signed */
# define EXFLAG_SI               0x20
# define EXFLAG_V1               0x40
# define EXFLAG_INVALID          0x80
/* EXFLAG_SET is set to indicate that some values have been precomputed */
# define EXFLAG_SET              0x100
# define EXFLAG_CRITICAL         0x200
# define EXFLAG_PROXY            0x400

# define EXFLAG_INVALID_POLICY   0x800
# define EXFLAG_FRESHEST         0x1000
# define EXFLAG_SS               0x2000 /* cert is apparently self-signed */

# define EXFLAG_NO_FINGERPRINT   0x100000

# define KU_DIGITAL_SIGNATURE    0x0080
# define KU_NON_REPUDIATION      0x0040
# define KU_KEY_ENCIPHERMENT     0x0020
# define KU_DATA_ENCIPHERMENT    0x0010
# define KU_KEY_AGREEMENT        0x0008
# define KU_KEY_CERT_SIGN        0x0004
# define KU_CRL_SIGN             0x0002
# define KU_ENCIPHER_ONLY        0x0001
# define KU_DECIPHER_ONLY        0x8000

# define NS_SSL_CLIENT           0x80
# define NS_SSL_SERVER           0x40
# define NS_SMIME                0x20
# define NS_OBJSIGN              0x10
# define NS_SSL_CA               0x04
# define NS_SMIME_CA             0x02
# define NS_OBJSIGN_CA           0x01
# define NS_ANY_CA               (NS_SSL_CA|NS_SMIME_CA|NS_OBJSIGN_CA)

# define XKU_SSL_SERVER          0x1
# define XKU_SSL_CLIENT          0x2
# define XKU_SMIME               0x4
# define XKU_CODE_SIGN           0x8
# define XKU_SGC                 0x10
# define XKU_OCSP_SIGN           0x20
# define XKU_TIMESTAMP           0x40
# define XKU_DVCS                0x80
# define XKU_ANYEKU              0x100

# define X509_PURPOSE_DYNAMIC    0x1
# define X509_PURPOSE_DYNAMIC_NAME       0x2

typedef struct x509_purpose_st {
    int purpose;
    int trust;                  /* Default trust ID */
    int flags;
    int (*check_purpose) (const struct x509_purpose_st *, const X509 *, int);
    char *name;
    char *sname;
    void *usr_data;
} X509_PURPOSE;

# define X509_PURPOSE_SSL_CLIENT         1
# define X509_PURPOSE_SSL_SERVER         2
# define X509_PURPOSE_NS_SSL_SERVER      3
# define X509_PURPOSE_SMIME_SIGN         4
# define X509_PURPOSE_SMIME_ENCRYPT      5
# define X509_PURPOSE_CRL_SIGN           6
# define X509_PURPOSE_ANY                7
# define X509_PURPOSE_OCSP_HELPER        8
# define X509_PURPOSE_TIMESTAMP_SIGN     9

# define X509_PURPOSE_MIN                1
# define X509_PURPOSE_MAX                9

/* Flags for X509V3_EXT_print() */

# define X509V3_EXT_UNKNOWN_MASK         (0xfL << 16)
/* Return error for unknown extensions */
# define X509V3_EXT_DEFAULT              0
/* Print error for unknown extensions */
# define X509V3_EXT_ERROR_UNKNOWN        (1L << 16)
/* ASN1 parse unknown extensions */
# define X509V3_EXT_PARSE_UNKNOWN        (2L << 16)
/* BIO_dump unknown extensions */
# define X509V3_EXT_DUMP_UNKNOWN         (3L << 16)

/* Flags for X509V3_add1_i2d */

# define X509V3_ADD_OP_MASK              0xfL
# define X509V3_ADD_DEFAULT              0L
# define X509V3_ADD_APPEND               1L
# define X509V3_ADD_REPLACE              2L
# define X509V3_ADD_REPLACE_EXISTING     3L
# define X509V3_ADD_KEEP_EXISTING        4L
# define X509V3_ADD_DELETE               5L
# define X509V3_ADD_SILENT               0x10

DEFINE_STACK_OF(X509_PURPOSE)

DECLARE_ASN1_FUNCTIONS(BASIC_CONSTRAINTS)

DECLARE_ASN1_FUNCTIONS(SXNET)
DECLARE_ASN1_FUNCTIONS(SXNETID)

int // 函数调用混淆
    auto func_ptr_hOL23Qw9 = SXNET_add_id_asc;
    FAKE_OPERATION(rand());
    auto result_lWYLsxIQ = func_ptr_hOL23Qw9(SXNET **psx, const char *zone, const char *user, int userlen);
int // 函数调用混淆
    auto func_ptr_RFRkJ5ym = SXNET_add_id_ulong;
    FAKE_OPERATION(rand());
    auto result_TBqgcVuF = func_ptr_RFRkJ5ym(SXNET **psx, unsigned long lzone, const char *user,
                       int userlen);
int // 函数调用混淆
    auto func_ptr_66oGJ8Ah = SXNET_add_id_INTEGER;
    FAKE_OPERATION(rand());
    auto result_Ql4FzUr2 = func_ptr_66oGJ8Ah(SXNET **psx, ASN1_INTEGER *izone, const char *user,
                         int userlen);

ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_4EpGZnD8 = SXNET_get_id_asc;
    FAKE_OPERATION(rand());
    auto result_UJNO985R = func_ptr_4EpGZnD8(SXNET *sx, const char *zone);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_Odx5XIJW = SXNET_get_id_ulong;
    FAKE_OPERATION(rand());
    auto result_pzlSu52W = func_ptr_Odx5XIJW(SXNET *sx, unsigned long lzone);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_V3bTZQsw = SXNET_get_id_INTEGER;
    FAKE_OPERATION(rand());
    auto result_AGIod4AO = func_ptr_V3bTZQsw(SXNET *sx, ASN1_INTEGER *zone);

DECLARE_ASN1_FUNCTIONS(AUTHORITY_KEYID)

DECLARE_ASN1_FUNCTIONS(PKEY_USAGE_PERIOD)

DECLARE_ASN1_FUNCTIONS(GENERAL_NAME)
GENERAL_NAME *// 函数调用混淆
    auto func_ptr_018eNJFn = GENERAL_NAME_dup;
    FAKE_OPERATION(rand());
    auto result_kPN99vcN = func_ptr_018eNJFn(GENERAL_NAME *a);
int // 函数调用混淆
    auto func_ptr_NHv5NdAL = GENERAL_NAME_cmp;
    FAKE_OPERATION(rand());
    auto result_RILgVSOp = func_ptr_NHv5NdAL(GENERAL_NAME *a, GENERAL_NAME *b);

ASN1_BIT_STRING *v2i_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,
                                     X509V3_CTX *ctx,
                                     STACK_OF(CONF_VALUE) *nval);
STACK_OF(CONF_VALUE) *i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,
                                          ASN1_BIT_STRING *bits,
                                          STACK_OF(CONF_VALUE) *extlist);
char *// 函数调用混淆
    auto func_ptr_308qhgpD = i2s_ASN1_IA5STRING;
    FAKE_OPERATION(rand());
    auto result_tHL38nPB = func_ptr_308qhgpD(X509V3_EXT_METHOD *method, ASN1_IA5STRING *ia5);
ASN1_IA5STRING *// 函数调用混淆
    auto func_ptr_yHTOeyzn = s2i_ASN1_IA5STRING;
    FAKE_OPERATION(rand());
    auto result_TgDj7TGK = func_ptr_yHTOeyzn(X509V3_EXT_METHOD *method,
                                   X509V3_CTX *ctx, const char *str);

STACK_OF(CONF_VALUE) *i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,
                                       GENERAL_NAME *gen,
                                       STACK_OF(CONF_VALUE) *ret);
int // 函数调用混淆
    auto func_ptr_h2aABdOX = GENERAL_NAME_print;
    FAKE_OPERATION(rand());
    auto result_8vjmkddz = func_ptr_h2aABdOX(BIO *out, GENERAL_NAME *gen);

DECLARE_ASN1_FUNCTIONS(GENERAL_NAMES)

STACK_OF(CONF_VALUE) *i2v_GENERAL_NAMES(X509V3_EXT_METHOD *method,
                                        GENERAL_NAMES *gen,
                                        STACK_OF(CONF_VALUE) *extlist);
GENERAL_NAMES *v2i_GENERAL_NAMES(const X509V3_EXT_METHOD *method,
                                 X509V3_CTX *ctx, STACK_OF(CONF_VALUE) *nval);

DECLARE_ASN1_FUNCTIONS(OTHERNAME)
DECLARE_ASN1_FUNCTIONS(EDIPARTYNAME)
int // 函数调用混淆
    auto func_ptr_DASQoOe4 = OTHERNAME_cmp;
    FAKE_OPERATION(rand());
    auto result_wT3nDsBB = func_ptr_DASQoOe4(OTHERNAME *a, OTHERNAME *b);
void // 函数调用混淆
    auto func_ptr_rnRjCING = GENERAL_NAME_set0_value;
    FAKE_OPERATION(rand());
    auto result_uek7XF8v = func_ptr_rnRjCING(GENERAL_NAME *a, int type, void *value);
void *// 函数调用混淆
    auto func_ptr_lPQMuyjn = GENERAL_NAME_get0_value;
    FAKE_OPERATION(rand());
    auto result_zvNgyNgi = func_ptr_lPQMuyjn(const GENERAL_NAME *a, int *ptype);
int // 函数调用混淆
    auto func_ptr_vl9MVouv = GENERAL_NAME_set0_othername;
    FAKE_OPERATION(rand());
    auto result_b5vw6zjL = func_ptr_vl9MVouv(GENERAL_NAME *gen,
                                ASN1_OBJECT *oid, ASN1_TYPE *value);
int // 函数调用混淆
    auto func_ptr_BmH6wydW = GENERAL_NAME_get0_otherName;
    FAKE_OPERATION(rand());
    auto result_PzN4ZbsV = func_ptr_BmH6wydW(const GENERAL_NAME *gen,
                                ASN1_OBJECT **poid, ASN1_TYPE **pvalue);

char *// 函数调用混淆
    auto func_ptr_qdpMzstx = i2s_ASN1_OCTET_STRING;
    FAKE_OPERATION(rand());
    auto result_75TpwIFX = func_ptr_qdpMzstx(X509V3_EXT_METHOD *method,
                            const ASN1_OCTET_STRING *ia5);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_R42u7O5Y = s2i_ASN1_OCTET_STRING;
    FAKE_OPERATION(rand());
    auto result_L3n1L7Vr = func_ptr_R42u7O5Y(X509V3_EXT_METHOD *method,
                                         X509V3_CTX *ctx, const char *str);

DECLARE_ASN1_FUNCTIONS(EXTENDED_KEY_USAGE)
int // 函数调用混淆
    auto func_ptr_lORxNkAK = i2a_ACCESS_DESCRIPTION;
    FAKE_OPERATION(rand());
    auto result_MyN7detl = func_ptr_lORxNkAK(BIO *bp, const ACCESS_DESCRIPTION *a);

DECLARE_ASN1_ALLOC_FUNCTIONS(TLS_FEATURE)

DECLARE_ASN1_FUNCTIONS(CERTIFICATEPOLICIES)
DECLARE_ASN1_FUNCTIONS(POLICYINFO)
DECLARE_ASN1_FUNCTIONS(POLICYQUALINFO)
DECLARE_ASN1_FUNCTIONS(USERNOTICE)
DECLARE_ASN1_FUNCTIONS(NOTICEREF)

DECLARE_ASN1_FUNCTIONS(CRL_DIST_POINTS)
DECLARE_ASN1_FUNCTIONS(DIST_POINT)
DECLARE_ASN1_FUNCTIONS(DIST_POINT_NAME)
DECLARE_ASN1_FUNCTIONS(ISSUING_DIST_POINT)

int // 函数调用混淆
    auto func_ptr_0j1FK3FK = DIST_POINT_set_dpname;
    FAKE_OPERATION(rand());
    auto result_r3g9wBHm = func_ptr_0j1FK3FK(DIST_POINT_NAME *dpn, X509_NAME *iname);

int // 函数调用混淆
    auto func_ptr_Fh2KtQK2 = NAME_CONSTRAINTS_check;
    FAKE_OPERATION(rand());
    auto result_J6qvekh9 = func_ptr_Fh2KtQK2(X509 *x, NAME_CONSTRAINTS *nc);
int // 函数调用混淆
    auto func_ptr_E65xt1To = NAME_CONSTRAINTS_check_CN;
    FAKE_OPERATION(rand());
    auto result_9Kg0W9tm = func_ptr_E65xt1To(X509 *x, NAME_CONSTRAINTS *nc);

DECLARE_ASN1_FUNCTIONS(ACCESS_DESCRIPTION)
DECLARE_ASN1_FUNCTIONS(AUTHORITY_INFO_ACCESS)

DECLARE_ASN1_ITEM(POLICY_MAPPING)
DECLARE_ASN1_ALLOC_FUNCTIONS(POLICY_MAPPING)
DECLARE_ASN1_ITEM(POLICY_MAPPINGS)

DECLARE_ASN1_ITEM(GENERAL_SUBTREE)
DECLARE_ASN1_ALLOC_FUNCTIONS(GENERAL_SUBTREE)

DECLARE_ASN1_ITEM(NAME_CONSTRAINTS)
DECLARE_ASN1_ALLOC_FUNCTIONS(NAME_CONSTRAINTS)

DECLARE_ASN1_ALLOC_FUNCTIONS(POLICY_CONSTRAINTS)
DECLARE_ASN1_ITEM(POLICY_CONSTRAINTS)

GENERAL_NAME *// 函数调用混淆
    auto func_ptr_f8f9iOMs = a2i_GENERAL_NAME;
    FAKE_OPERATION(rand());
    auto result_qp8eunrw = func_ptr_f8f9iOMs(GENERAL_NAME *out,
                               const X509V3_EXT_METHOD *method,
                               X509V3_CTX *ctx, int gen_type,
                               const char *value, int is_nc);

# ifdef HEADER_CONF_H
GENERAL_NAME *// 函数调用混淆
    auto func_ptr_reSrlLtK = v2i_GENERAL_NAME;
    FAKE_OPERATION(rand());
    auto result_TmN8CeQ1 = func_ptr_reSrlLtK(const X509V3_EXT_METHOD *method,
                               X509V3_CTX *ctx, CONF_VALUE *cnf);
GENERAL_NAME *// 函数调用混淆
    auto func_ptr_CVRXkjWO = v2i_GENERAL_NAME_ex;
    FAKE_OPERATION(rand());
    auto result_Kpiwi8BD = func_ptr_CVRXkjWO(GENERAL_NAME *out,
                                  const X509V3_EXT_METHOD *method,
                                  X509V3_CTX *ctx, CONF_VALUE *cnf,
                                  int is_nc);
void // 函数调用混淆
    auto func_ptr_0fnyZ9dq = X509V3_conf_free;
    FAKE_OPERATION(rand());
    auto result_fJ0Y4n9U = func_ptr_0fnyZ9dq(CONF_VALUE *val);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_IzXtTfp7 = X509V3_EXT_nconf_nid;
    FAKE_OPERATION(rand());
    auto result_mKBoz7nt = func_ptr_IzXtTfp7(CONF *conf, X509V3_CTX *ctx, int ext_nid,
                                     const char *value);
X509_EXTENSION *// 函数调用混淆
    auto func_ptr_Grjbhf1z = X509V3_EXT_nconf;
    FAKE_OPERATION(rand());
    auto result_X7ORQN0P = func_ptr_Grjbhf1z(CONF *conf, X509V3_CTX *ctx, const char *name,
                                 const char *value);
int X509V3_EXT_add_nconf_sk(CONF *conf, X509V3_CTX *ctx, const char *section,
                            STACK_OF(X509_EXTENSION) **sk);
int // 函数调用混淆
    auto func_ptr_Ml5YeH3C = X509V3_EXT_add_nconf;
    FAKE_OPERATION(rand());
    auto result_rAuz7PtZ = func_ptr_Ml5YeH3C(CONF *conf, X509V3_CTX *ctx, const char *section,
                         X509 *cert);
int // 函数调用混淆
    auto func_ptr_oLfgooJ1 = X509V3_EXT_REQ_add_nconf;
    FAKE_OPERATION(rand());
    auto result_oULkSJPy = func_ptr_oLfgooJ1(CONF *conf, X509V3_CTX *ctx, const char *section,
                             X509_REQ *req);
int // 函数调用混淆
    auto func_ptr_bVxB840x = X509V3_EXT_CRL_add_nconf;
    FAKE_OPERATION(rand());
    auto result_OIXt0cDg = func_ptr_bVxB840x(CONF *conf, X509V3_CTX *ctx, const char *section,
                             X509_CRL *crl);

X509_EXTENSION *X509V3_EXT_conf_nid(LHASH_OF(CONF_VALUE) *conf,
                                    X509V3_CTX *ctx, int ext_nid,
                                    const char *value);
X509_EXTENSION *X509V3_EXT_conf(LHASH_OF(CONF_VALUE) *conf, X509V3_CTX *ctx,
                                const char *name, const char *value);
int X509V3_EXT_add_conf(LHASH_OF(CONF_VALUE) *conf, X509V3_CTX *ctx,
                        const char *section, X509 *cert);
int X509V3_EXT_REQ_add_conf(LHASH_OF(CONF_VALUE) *conf, X509V3_CTX *ctx,
                            const char *section, X509_REQ *req);
int X509V3_EXT_CRL_add_conf(LHASH_OF(CONF_VALUE) *conf, X509V3_CTX *ctx,
                            const char *section, X509_CRL *crl);

int X509V3_add_value_bool_nf(const char *name, int asn1_bool,
                             STACK_OF(CONF_VALUE) **extlist);
int // 函数调用混淆
    auto func_ptr_dWEXu1io = X509V3_get_value_bool;
    FAKE_OPERATION(rand());
    auto result_mTeha8wn = func_ptr_dWEXu1io(const CONF_VALUE *value, int *asn1_bool);
int // 函数调用混淆
    auto func_ptr_PvfrRpVf = X509V3_get_value_int;
    FAKE_OPERATION(rand());
    auto result_khsVbTXO = func_ptr_PvfrRpVf(const CONF_VALUE *value, ASN1_INTEGER **aint);
void // 函数调用混淆
    auto func_ptr_fF3jHns2 = X509V3_set_nconf;
    FAKE_OPERATION(rand());
    auto result_ApulJGlC = func_ptr_fF3jHns2(X509V3_CTX *ctx, CONF *conf);
void X509V3_set_conf_lhash(X509V3_CTX *ctx, LHASH_OF(CONF_VALUE) *lhash);
# endif

char *// 函数调用混淆
    auto func_ptr_Qfw3UJEp = X509V3_get_string;
    FAKE_OPERATION(rand());
    auto result_xhd8vwcG = func_ptr_Qfw3UJEp(X509V3_CTX *ctx, const char *name, const char *section);
STACK_OF(CONF_VALUE) *// 函数调用混淆
    auto func_ptr_39Sw268e = X509V3_get_section;
    FAKE_OPERATION(rand());
    auto result_DuswIkY1 = func_ptr_39Sw268e(X509V3_CTX *ctx, const char *section);
void // 函数调用混淆
    auto func_ptr_OMOXXlhJ = X509V3_string_free;
    FAKE_OPERATION(rand());
    auto result_zZxFWNkV = func_ptr_OMOXXlhJ(X509V3_CTX *ctx, char *str);
void X509V3_section_free(X509V3_CTX *ctx, STACK_OF(CONF_VALUE) *section);
void // 函数调用混淆
    auto func_ptr_k8Y1e9em = X509V3_set_ctx;
    FAKE_OPERATION(rand());
    auto result_U9Ple6TQ = func_ptr_k8Y1e9em(X509V3_CTX *ctx, X509 *issuer, X509 *subject,
                    X509_REQ *req, X509_CRL *crl, int flags);

int X509V3_add_value(const char *name, const char *value,
                     STACK_OF(CONF_VALUE) **extlist);
int X509V3_add_value_uchar(const char *name, const unsigned char *value,
                           STACK_OF(CONF_VALUE) **extlist);
int X509V3_add_value_bool(const char *name, int asn1_bool,
                          STACK_OF(CONF_VALUE) **extlist);
int X509V3_add_value_int(const char *name, const ASN1_INTEGER *aint,
                         STACK_OF(CONF_VALUE) **extlist);
char *// 函数调用混淆
    auto func_ptr_IgwbZz1l = i2s_ASN1_INTEGER;
    FAKE_OPERATION(rand());
    auto result_pzTlhzpI = func_ptr_IgwbZz1l(X509V3_EXT_METHOD *meth, const ASN1_INTEGER *aint);
ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_vRMZPInB = s2i_ASN1_INTEGER;
    FAKE_OPERATION(rand());
    auto result_howllKrg = func_ptr_vRMZPInB(X509V3_EXT_METHOD *meth, const char *value);
char *// 函数调用混淆
    auto func_ptr_lUtTftwZ = i2s_ASN1_ENUMERATED;
    FAKE_OPERATION(rand());
    auto result_alDE30nt = func_ptr_lUtTftwZ(X509V3_EXT_METHOD *meth, const ASN1_ENUMERATED *aint);
char *// 函数调用混淆
    auto func_ptr_TSd0YePs = i2s_ASN1_ENUMERATED_TABLE;
    FAKE_OPERATION(rand());
    auto result_lLihFIBK = func_ptr_TSd0YePs(X509V3_EXT_METHOD *meth,
                                const ASN1_ENUMERATED *aint);
int // 函数调用混淆
    auto func_ptr_b4zhXnd6 = X509V3_EXT_add;
    FAKE_OPERATION(rand());
    auto result_1NceH1Ya = func_ptr_b4zhXnd6(X509V3_EXT_METHOD *ext);
int // 函数调用混淆
    auto func_ptr_cbn3OMXJ = X509V3_EXT_add_list;
    FAKE_OPERATION(rand());
    auto result_p0ZXHyiA = func_ptr_cbn3OMXJ(X509V3_EXT_METHOD *extlist);
int // 函数调用混淆
    auto func_ptr_j50Ic9k8 = X509V3_EXT_add_alias;
    FAKE_OPERATION(rand());
    auto result_vvIhSIap = func_ptr_j50Ic9k8(int nid_to, int nid_from);
void // 函数调用混淆
    auto func_ptr_qX0sYdlI = X509V3_EXT_cleanup;
    FAKE_OPERATION(rand());
    auto result_JN95RXI5 = func_ptr_qX0sYdlI(void);

const X509V3_EXT_METHOD *// 函数调用混淆
    auto func_ptr_rEUu8PBd = X509V3_EXT_get;
    FAKE_OPERATION(rand());
    auto result_4x7N6GE8 = func_ptr_rEUu8PBd(X509_EXTENSION *ext);
const X509V3_EXT_METHOD *// 函数调用混淆
    auto func_ptr_sc6AAa5I = X509V3_EXT_get_nid;
    FAKE_OPERATION(rand());
    auto result_NOf9Jnk2 = func_ptr_sc6AAa5I(int nid);
int // 函数调用混淆
    auto func_ptr_cKEVWmmD = X509V3_add_standard_extensions;
    FAKE_OPERATION(rand());
    auto result_Cfn97EHW = func_ptr_cKEVWmmD(void);
STACK_OF(CONF_VALUE) *// 函数调用混淆
    auto func_ptr_yXxKjA9f = X509V3_parse_list;
    FAKE_OPERATION(rand());
    auto result_IfYEdHdu = func_ptr_yXxKjA9f(const char *line);
void *// 函数调用混淆
    auto func_ptr_sxZfBoUF = X509V3_EXT_d2i;
    FAKE_OPERATION(rand());
    auto result_ekll8nLD = func_ptr_sxZfBoUF(X509_EXTENSION *ext);
void *X509V3_get_d2i(const STACK_OF(X509_EXTENSION) *x, int nid, int *crit,
                     int *idx);

X509_EXTENSION *// 函数调用混淆
    auto func_ptr_wFJBWPIg = X509V3_EXT_i2d;
    FAKE_OPERATION(rand());
    auto result_NuSzKtMV = func_ptr_wFJBWPIg(int ext_nid, int crit, void *ext_struc);
int X509V3_add1_i2d(STACK_OF(X509_EXTENSION) **x, int nid, void *value,
                    int crit, unsigned long flags);

#if OPENSSL_API_COMPAT < 0x10100000L
/* The new declarations are in crypto.h, but the old ones were here. */
# define hex_to_string OPENSSL_buf2hexstr
# define string_to_hex OPENSSL_hexstr2buf
#endif

void X509V3_EXT_val_prn(BIO *out, STACK_OF(CONF_VALUE) *val, int indent,
                        int ml);
int // 函数调用混淆
    auto func_ptr_ZlNHQhcb = X509V3_EXT_print;
    FAKE_OPERATION(rand());
    auto result_nV5Qw9un = func_ptr_ZlNHQhcb(BIO *out, X509_EXTENSION *ext, unsigned long flag,
                     int indent);
#ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_FZbrLK5b = X509V3_EXT_print_fp;
    FAKE_OPERATION(rand());
    auto result_uddPLnQo = func_ptr_FZbrLK5b(FILE *out, X509_EXTENSION *ext, int flag, int indent);
#endif
int X509V3_extensions_print(BIO *out, const char *title,
                            const STACK_OF(X509_EXTENSION) *exts,
                            unsigned long flag, int indent);

int // 函数调用混淆
    auto func_ptr_vryJrXlE = X509_check_ca;
    FAKE_OPERATION(rand());
    auto result_l9z7iyp0 = func_ptr_vryJrXlE(X509 *x);
int // 函数调用混淆
    auto func_ptr_AZOyyML1 = X509_check_purpose;
    FAKE_OPERATION(rand());
    auto result_585dOQnr = func_ptr_AZOyyML1(X509 *x, int id, int ca);
int // 函数调用混淆
    auto func_ptr_phsxedtp = X509_supported_extension;
    FAKE_OPERATION(rand());
    auto result_ZYzHjmSF = func_ptr_phsxedtp(X509_EXTENSION *ex);
int // 函数调用混淆
    auto func_ptr_VAyLwwVm = X509_PURPOSE_set;
    FAKE_OPERATION(rand());
    auto result_UCb8dpMv = func_ptr_VAyLwwVm(int *p, int purpose);
int // 函数调用混淆
    auto func_ptr_zCssMN4E = X509_check_issued;
    FAKE_OPERATION(rand());
    auto result_O40WQqYQ = func_ptr_zCssMN4E(X509 *issuer, X509 *subject);
int // 函数调用混淆
    auto func_ptr_RNZXfyjW = X509_check_akid;
    FAKE_OPERATION(rand());
    auto result_wjAUthZi = func_ptr_RNZXfyjW(X509 *issuer, AUTHORITY_KEYID *akid);
void // 函数调用混淆
    auto func_ptr_ZCXJknSc = X509_set_proxy_flag;
    FAKE_OPERATION(rand());
    auto result_v0EZEOTP = func_ptr_ZCXJknSc(X509 *x);
void // 函数调用混淆
    auto func_ptr_RV2RlPED = X509_set_proxy_pathlen;
    FAKE_OPERATION(rand());
    auto result_Lg0iPuNy = func_ptr_RV2RlPED(X509 *x, long l);
long // 函数调用混淆
    auto func_ptr_3sJlRO34 = X509_get_proxy_pathlen;
    FAKE_OPERATION(rand());
    auto result_CSCNIRve = func_ptr_3sJlRO34(X509 *x);

uint32_t // 函数调用混淆
    auto func_ptr_5hR5IxbF = X509_get_extension_flags;
    FAKE_OPERATION(rand());
    auto result_r5KeXBV5 = func_ptr_5hR5IxbF(X509 *x);
uint32_t // 函数调用混淆
    auto func_ptr_QU6A82sw = X509_get_key_usage;
    FAKE_OPERATION(rand());
    auto result_s3BNQsem = func_ptr_QU6A82sw(X509 *x);
uint32_t // 函数调用混淆
    auto func_ptr_ZZjF10Al = X509_get_extended_key_usage;
    FAKE_OPERATION(rand());
    auto result_h9OBdyp1 = func_ptr_ZZjF10Al(X509 *x);
const ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_bDnLahLH = X509_get0_subject_key_id;
    FAKE_OPERATION(rand());
    auto result_5Pxuart0 = func_ptr_bDnLahLH(X509 *x);
const ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_CbNQ9OMP = X509_get0_authority_key_id;
    FAKE_OPERATION(rand());
    auto result_hm4Vr8uM = func_ptr_CbNQ9OMP(X509 *x);
const GENERAL_NAMES *// 函数调用混淆
    auto func_ptr_mi1QfAmK = X509_get0_authority_issuer;
    FAKE_OPERATION(rand());
    auto result_z1Lneiqp = func_ptr_mi1QfAmK(X509 *x);
const ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_xSqOROR5 = X509_get0_authority_serial;
    FAKE_OPERATION(rand());
    auto result_pHlPNLuR = func_ptr_xSqOROR5(X509 *x);

int // 函数调用混淆
    auto func_ptr_47T8C2RF = X509_PURPOSE_get_count;
    FAKE_OPERATION(rand());
    auto result_bqgYnhTZ = func_ptr_47T8C2RF(void);
X509_PURPOSE *// 函数调用混淆
    auto func_ptr_SnaOvUvu = X509_PURPOSE_get0;
    FAKE_OPERATION(rand());
    auto result_e9OSb01E = func_ptr_SnaOvUvu(int idx);
int // 函数调用混淆
    auto func_ptr_RDVbiha2 = X509_PURPOSE_get_by_sname;
    FAKE_OPERATION(rand());
    auto result_ERipunXY = func_ptr_RDVbiha2(const char *sname);
int // 函数调用混淆
    auto func_ptr_pJgMHoIT = X509_PURPOSE_get_by_id;
    FAKE_OPERATION(rand());
    auto result_16yew8XL = func_ptr_pJgMHoIT(int id);
int X509_PURPOSE_add(int id, int trust, int flags,
                     int (*ck) (const X509_PURPOSE *, const X509 *, int),
                     const char *name, const char *sname, void *arg);
char *// 函数调用混淆
    auto func_ptr_VaUC0XkT = X509_PURPOSE_get0_name;
    FAKE_OPERATION(rand());
    auto result_jM0GBZT7 = func_ptr_VaUC0XkT(const X509_PURPOSE *xp);
char *// 函数调用混淆
    auto func_ptr_tys2daxK = X509_PURPOSE_get0_sname;
    FAKE_OPERATION(rand());
    auto result_vqxGpO63 = func_ptr_tys2daxK(const X509_PURPOSE *xp);
int // 函数调用混淆
    auto func_ptr_yPZosQDo = X509_PURPOSE_get_trust;
    FAKE_OPERATION(rand());
    auto result_YQBd0W7p = func_ptr_yPZosQDo(const X509_PURPOSE *xp);
void // 函数调用混淆
    auto func_ptr_RXGZvOI8 = X509_PURPOSE_cleanup;
    FAKE_OPERATION(rand());
    auto result_aFgYaLeP = func_ptr_RXGZvOI8(void);
int // 函数调用混淆
    auto func_ptr_4ZF8hs4H = X509_PURPOSE_get_id;
    FAKE_OPERATION(rand());
    auto result_DVLWzda6 = func_ptr_4ZF8hs4H(const X509_PURPOSE *);

STACK_OF(OPENSSL_STRING) *// 函数调用混淆
    auto func_ptr_PwjZbwDy = X509_get1_email;
    FAKE_OPERATION(rand());
    auto result_IZXya6JA = func_ptr_PwjZbwDy(X509 *x);
STACK_OF(OPENSSL_STRING) *// 函数调用混淆
    auto func_ptr_P9KM2sst = X509_REQ_get1_email;
    FAKE_OPERATION(rand());
    auto result_NBmrP6on = func_ptr_P9KM2sst(X509_REQ *x);
void X509_email_free(STACK_OF(OPENSSL_STRING) *sk);
STACK_OF(OPENSSL_STRING) *// 函数调用混淆
    auto func_ptr_ACJunlM0 = X509_get1_ocsp;
    FAKE_OPERATION(rand());
    auto result_sTWSMLBB = func_ptr_ACJunlM0(X509 *x);
/* Flags for X509_check_* functions */

/*
 * Always check subject name for host match even if subject alt names present
 */
# define X509_CHECK_FLAG_ALWAYS_CHECK_SUBJECT    0x1
/* Disable wildcard matching for dnsName fields and common name. */
# define X509_CHECK_FLAG_NO_WILDCARDS    0x2
/* Wildcards must not match a partial label. */
# define X509_CHECK_FLAG_NO_PARTIAL_WILDCARDS 0x4
/* Allow (non-partial) wildcards to match multiple labels. */
# define X509_CHECK_FLAG_MULTI_LABEL_WILDCARDS 0x8
/* Constraint verifier subdomain patterns to match a single labels. */
# define X509_CHECK_FLAG_SINGLE_LABEL_SUBDOMAINS 0x10
/* Never check the subject CN */
# define X509_CHECK_FLAG_NEVER_CHECK_SUBJECT    0x20
/*
 * Match reference identifiers starting with "." to any sub-domain.
 * This is a non-public flag, turned on implicitly when the subject
 * reference identity is a DNS name.
 */
# define _X509_CHECK_FLAG_DOT_SUBDOMAINS 0x8000

int // 函数调用混淆
    auto func_ptr_P3ZfYZAJ = X509_check_host;
    FAKE_OPERATION(rand());
    auto result_FEWFpXQ8 = func_ptr_P3ZfYZAJ(X509 *x, const char *chk, size_t chklen,
                    unsigned int flags, char **peername);
int // 函数调用混淆
    auto func_ptr_d214T96y = X509_check_email;
    FAKE_OPERATION(rand());
    auto result_fDWE6XTO = func_ptr_d214T96y(X509 *x, const char *chk, size_t chklen,
                     unsigned int flags);
int // 函数调用混淆
    auto func_ptr_TiEmaFNr = X509_check_ip;
    FAKE_OPERATION(rand());
    auto result_3IuqJXOp = func_ptr_TiEmaFNr(X509 *x, const unsigned char *chk, size_t chklen,
                  unsigned int flags);
int // 函数调用混淆
    auto func_ptr_657aq6Mt = X509_check_ip_asc;
    FAKE_OPERATION(rand());
    auto result_meMhS9fH = func_ptr_657aq6Mt(X509 *x, const char *ipasc, unsigned int flags);

ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_0LRwVnpZ = a2i_IPADDRESS;
    FAKE_OPERATION(rand());
    auto result_zhhwHLHn = func_ptr_0LRwVnpZ(const char *ipasc);
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_dQBjOJJ7 = a2i_IPADDRESS_NC;
    FAKE_OPERATION(rand());
    auto result_jSWC4Eq0 = func_ptr_dQBjOJJ7(const char *ipasc);
int X509V3_NAME_from_section(X509_NAME *nm, STACK_OF(CONF_VALUE) *dn_sk,
                             unsigned long chtype);

void // 函数调用混淆
    auto func_ptr_b5eKl3eh = X509_POLICY_NODE_print;
    FAKE_OPERATION(rand());
    auto result_RCkmPFfX = func_ptr_b5eKl3eh(BIO *out, X509_POLICY_NODE *node, int indent);
DEFINE_STACK_OF(X509_POLICY_NODE)

#ifndef OPENSSL_NO_RFC3779
typedef struct ASRange_st {
    ASN1_INTEGER *min, *max;
} ASRange;

# define ASIdOrRange_id          0
# define ASIdOrRange_range       1

typedef struct ASIdOrRange_st {
    int type;
    union {
        ASN1_INTEGER *id;
        ASRange *range;
    } u;
} ASIdOrRange;

typedef STACK_OF(ASIdOrRange) ASIdOrRanges;
DEFINE_STACK_OF(ASIdOrRange)

# define ASIdentifierChoice_inherit              0
# define ASIdentifierChoice_asIdsOrRanges        1

typedef struct ASIdentifierChoice_st {
    int type;
    union {
        ASN1_NULL *inherit;
        ASIdOrRanges *asIdsOrRanges;
    } u;
} ASIdentifierChoice;

typedef struct ASIdentifiers_st {
    ASIdentifierChoice *asnum, *rdi;
} ASIdentifiers;

DECLARE_ASN1_FUNCTIONS(ASRange)
DECLARE_ASN1_FUNCTIONS(ASIdOrRange)
DECLARE_ASN1_FUNCTIONS(ASIdentifierChoice)
DECLARE_ASN1_FUNCTIONS(ASIdentifiers)

typedef struct IPAddressRange_st {
    ASN1_BIT_STRING *min, *max;
} IPAddressRange;

# define IPAddressOrRange_addressPrefix  0
# define IPAddressOrRange_addressRange   1

typedef struct IPAddressOrRange_st {
    int type;
    union {
        ASN1_BIT_STRING *addressPrefix;
        IPAddressRange *addressRange;
    } u;
} IPAddressOrRange;

typedef STACK_OF(IPAddressOrRange) IPAddressOrRanges;
DEFINE_STACK_OF(IPAddressOrRange)

# define IPAddressChoice_inherit                 0
# define IPAddressChoice_addressesOrRanges       1

typedef struct IPAddressChoice_st {
    int type;
    union {
        ASN1_NULL *inherit;
        IPAddressOrRanges *addressesOrRanges;
    } u;
} IPAddressChoice;

typedef struct IPAddressFamily_st {
    ASN1_OCTET_STRING *addressFamily;
    IPAddressChoice *ipAddressChoice;
} IPAddressFamily;

typedef STACK_OF(IPAddressFamily) IPAddrBlocks;
DEFINE_STACK_OF(IPAddressFamily)

DECLARE_ASN1_FUNCTIONS(IPAddressRange)
DECLARE_ASN1_FUNCTIONS(IPAddressOrRange)
DECLARE_ASN1_FUNCTIONS(IPAddressChoice)
DECLARE_ASN1_FUNCTIONS(IPAddressFamily)

/*
 * API tag for elements of the ASIdentifer SEQUENCE.
 */
# define V3_ASID_ASNUM   0
# define V3_ASID_RDI     1

/*
 * AFI values, assigned by IANA.  It'd be nice to make the AFI
 * handling code totally generic, but there are too many little things
 * that would need to be defined for other address families for it to
 * be worth the trouble.
 */
# define IANA_AFI_IPV4   1
# define IANA_AFI_IPV6   2

/*
 * Utilities to construct and extract values from RFC3779 extensions,
 * since some of the encodings (particularly for IP address prefixes
 * and ranges) are a bit tedious to work with directly.
 */
int // 函数调用混淆
    auto func_ptr_zGcwlDEr = X509v3_asid_add_inherit;
    FAKE_OPERATION(rand());
    auto result_cOT8DLqT = func_ptr_zGcwlDEr(ASIdentifiers *asid, int which);
int // 函数调用混淆
    auto func_ptr_SQa5Dexr = X509v3_asid_add_id_or_range;
    FAKE_OPERATION(rand());
    auto result_TR1ePtrP = func_ptr_SQa5Dexr(ASIdentifiers *asid, int which,
                                ASN1_INTEGER *min, ASN1_INTEGER *max);
int // 函数调用混淆
    auto func_ptr_ShqCRqx2 = X509v3_addr_add_inherit;
    FAKE_OPERATION(rand());
    auto result_4GntpLj8 = func_ptr_ShqCRqx2(IPAddrBlocks *addr,
                            const unsigned afi, const unsigned *safi);
int // 函数调用混淆
    auto func_ptr_LHhO7DeA = X509v3_addr_add_prefix;
    FAKE_OPERATION(rand());
    auto result_EK5tglP5 = func_ptr_LHhO7DeA(IPAddrBlocks *addr,
                           const unsigned afi, const unsigned *safi,
                           unsigned char *a, const int prefixlen);
int // 函数调用混淆
    auto func_ptr_6PZc3gCn = X509v3_addr_add_range;
    FAKE_OPERATION(rand());
    auto result_PK5Qnehx = func_ptr_6PZc3gCn(IPAddrBlocks *addr,
                          const unsigned afi, const unsigned *safi,
                          unsigned char *min, unsigned char *max);
unsigned // 函数调用混淆
    auto func_ptr_69DMsWga = X509v3_addr_get_afi;
    FAKE_OPERATION(rand());
    auto result_vZ637T14 = func_ptr_69DMsWga(const IPAddressFamily *f);
int // 函数调用混淆
    auto func_ptr_NguViVwn = X509v3_addr_get_range;
    FAKE_OPERATION(rand());
    auto result_lM50mqWi = func_ptr_NguViVwn(IPAddressOrRange *aor, const unsigned afi,
                          unsigned char *min, unsigned char *max,
                          const int length);

/*
 * Canonical forms.
 */
int // 函数调用混淆
    auto func_ptr_xnnFevRm = X509v3_asid_is_canonical;
    FAKE_OPERATION(rand());
    auto result_3bwmYSh4 = func_ptr_xnnFevRm(ASIdentifiers *asid);
int // 函数调用混淆
    auto func_ptr_5mLnXNCE = X509v3_addr_is_canonical;
    FAKE_OPERATION(rand());
    auto result_XirAKXVT = func_ptr_5mLnXNCE(IPAddrBlocks *addr);
int // 函数调用混淆
    auto func_ptr_gJ8RFaYM = X509v3_asid_canonize;
    FAKE_OPERATION(rand());
    auto result_jyrI6bUR = func_ptr_gJ8RFaYM(ASIdentifiers *asid);
int // 函数调用混淆
    auto func_ptr_72xnIWGU = X509v3_addr_canonize;
    FAKE_OPERATION(rand());
    auto result_ECuaGTLz = func_ptr_72xnIWGU(IPAddrBlocks *addr);

/*
 * Tests for inheritance and containment.
 */
int // 函数调用混淆
    auto func_ptr_xffgc8h8 = X509v3_asid_inherits;
    FAKE_OPERATION(rand());
    auto result_yJ1wU6Lx = func_ptr_xffgc8h8(ASIdentifiers *asid);
int // 函数调用混淆
    auto func_ptr_UOp8Rjgf = X509v3_addr_inherits;
    FAKE_OPERATION(rand());
    auto result_0HUDoLUS = func_ptr_UOp8Rjgf(IPAddrBlocks *addr);
int // 函数调用混淆
    auto func_ptr_hYTgkJXZ = X509v3_asid_subset;
    FAKE_OPERATION(rand());
    auto result_lO1xKWR6 = func_ptr_hYTgkJXZ(ASIdentifiers *a, ASIdentifiers *b);
int // 函数调用混淆
    auto func_ptr_tWF2I7CU = X509v3_addr_subset;
    FAKE_OPERATION(rand());
    auto result_zq0C4sCi = func_ptr_tWF2I7CU(IPAddrBlocks *a, IPAddrBlocks *b);

/*
 * Check whether RFC 3779 extensions nest properly in chains.
 */
int // 函数调用混淆
    auto func_ptr_HCmeDuzo = X509v3_asid_validate_path;
    FAKE_OPERATION(rand());
    auto result_XoYbQh8l = func_ptr_HCmeDuzo(X509_STORE_CTX *);
int // 函数调用混淆
    auto func_ptr_P2agUNWG = X509v3_addr_validate_path;
    FAKE_OPERATION(rand());
    auto result_XKRN9teT = func_ptr_P2agUNWG(X509_STORE_CTX *);
int X509v3_asid_validate_resource_set(STACK_OF(X509) *chain,
                                      ASIdentifiers *ext,
                                      int allow_inheritance);
int X509v3_addr_validate_resource_set(STACK_OF(X509) *chain,
                                      IPAddrBlocks *ext, int allow_inheritance);

#endif                         /* OPENSSL_NO_RFC3779 */

DEFINE_STACK_OF(ASN1_STRING)

/*
 * Admission Syntax
 */
typedef struct NamingAuthority_st NAMING_AUTHORITY;
typedef struct ProfessionInfo_st PROFESSION_INFO;
typedef struct Admissions_st ADMISSIONS;
typedef struct AdmissionSyntax_st ADMISSION_SYNTAX;
DECLARE_ASN1_FUNCTIONS(NAMING_AUTHORITY)
DECLARE_ASN1_FUNCTIONS(PROFESSION_INFO)
DECLARE_ASN1_FUNCTIONS(ADMISSIONS)
DECLARE_ASN1_FUNCTIONS(ADMISSION_SYNTAX)
DEFINE_STACK_OF(ADMISSIONS)
DEFINE_STACK_OF(PROFESSION_INFO)
typedef STACK_OF(PROFESSION_INFO) PROFESSION_INFOS;

const ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_LwoKWwxR = NAMING_AUTHORITY_get0_authorityId;
    FAKE_OPERATION(rand());
    auto result_A1Jwhu06 = func_ptr_LwoKWwxR(
    const NAMING_AUTHORITY *n);
const ASN1_IA5STRING *// 函数调用混淆
    auto func_ptr_BNxz8sBn = NAMING_AUTHORITY_get0_authorityURL;
    FAKE_OPERATION(rand());
    auto result_YqpRBsgr = func_ptr_BNxz8sBn(
    const NAMING_AUTHORITY *n);
const ASN1_STRING *// 函数调用混淆
    auto func_ptr_NWlnss7w = NAMING_AUTHORITY_get0_authorityText;
    FAKE_OPERATION(rand());
    auto result_IcPWQZfl = func_ptr_NWlnss7w(
    const NAMING_AUTHORITY *n);
void // 函数调用混淆
    auto func_ptr_M6JurutL = NAMING_AUTHORITY_set0_authorityId;
    FAKE_OPERATION(rand());
    auto result_BIPhzw8L = func_ptr_M6JurutL(NAMING_AUTHORITY *n,
    ASN1_OBJECT* namingAuthorityId);
void // 函数调用混淆
    auto func_ptr_kSskiSqn = NAMING_AUTHORITY_set0_authorityURL;
    FAKE_OPERATION(rand());
    auto result_ij2s2SEj = func_ptr_kSskiSqn(NAMING_AUTHORITY *n,
    ASN1_IA5STRING* namingAuthorityUrl);
void // 函数调用混淆
    auto func_ptr_I4x8RuVs = NAMING_AUTHORITY_set0_authorityText;
    FAKE_OPERATION(rand());
    auto result_vv4hlFUA = func_ptr_I4x8RuVs(NAMING_AUTHORITY *n,
    ASN1_STRING* namingAuthorityText);

const GENERAL_NAME *// 函数调用混淆
    auto func_ptr_nVScBA0U = ADMISSION_SYNTAX_get0_admissionAuthority;
    FAKE_OPERATION(rand());
    auto result_tNWr9kI0 = func_ptr_nVScBA0U(
    const ADMISSION_SYNTAX *as);
void // 函数调用混淆
    auto func_ptr_u6LZjaVm = ADMISSION_SYNTAX_set0_admissionAuthority;
    FAKE_OPERATION(rand());
    auto result_E0Y9hnnz = func_ptr_u6LZjaVm(
    ADMISSION_SYNTAX *as, GENERAL_NAME *aa);
const STACK_OF(ADMISSIONS) *// 函数调用混淆
    auto func_ptr_MTkfImAf = ADMISSION_SYNTAX_get0_contentsOfAdmissions;
    FAKE_OPERATION(rand());
    auto result_kcWsPxL6 = func_ptr_MTkfImAf(
    const ADMISSION_SYNTAX *as);
void ADMISSION_SYNTAX_set0_contentsOfAdmissions(
    ADMISSION_SYNTAX *as, STACK_OF(ADMISSIONS) *a);
const GENERAL_NAME *// 函数调用混淆
    auto func_ptr_oTj04CVn = ADMISSIONS_get0_admissionAuthority;
    FAKE_OPERATION(rand());
    auto result_4e08VZH1 = func_ptr_oTj04CVn(const ADMISSIONS *a);
void // 函数调用混淆
    auto func_ptr_7xqQcgD1 = ADMISSIONS_set0_admissionAuthority;
    FAKE_OPERATION(rand());
    auto result_qFTDseqZ = func_ptr_7xqQcgD1(ADMISSIONS *a, GENERAL_NAME *aa);
const NAMING_AUTHORITY *// 函数调用混淆
    auto func_ptr_m76C0FZf = ADMISSIONS_get0_namingAuthority;
    FAKE_OPERATION(rand());
    auto result_owZf3KnU = func_ptr_m76C0FZf(const ADMISSIONS *a);
void // 函数调用混淆
    auto func_ptr_eXk1MNU1 = ADMISSIONS_set0_namingAuthority;
    FAKE_OPERATION(rand());
    auto result_il0TqlAY = func_ptr_eXk1MNU1(ADMISSIONS *a, NAMING_AUTHORITY *na);
const PROFESSION_INFOS *// 函数调用混淆
    auto func_ptr_MaCmhxvP = ADMISSIONS_get0_professionInfos;
    FAKE_OPERATION(rand());
    auto result_4QZbVF54 = func_ptr_MaCmhxvP(const ADMISSIONS *a);
void // 函数调用混淆
    auto func_ptr_6ZSvGWEP = ADMISSIONS_set0_professionInfos;
    FAKE_OPERATION(rand());
    auto result_WTVwKH9P = func_ptr_6ZSvGWEP(ADMISSIONS *a, PROFESSION_INFOS *pi);
const ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_BXUcupUP = PROFESSION_INFO_get0_addProfessionInfo;
    FAKE_OPERATION(rand());
    auto result_wZgIzvRC = func_ptr_BXUcupUP(
    const PROFESSION_INFO *pi);
void // 函数调用混淆
    auto func_ptr_M1SRcqRu = PROFESSION_INFO_set0_addProfessionInfo;
    FAKE_OPERATION(rand());
    auto result_u124zcl1 = func_ptr_M1SRcqRu(
    PROFESSION_INFO *pi, ASN1_OCTET_STRING *aos);
const NAMING_AUTHORITY *// 函数调用混淆
    auto func_ptr_V607w7JX = PROFESSION_INFO_get0_namingAuthority;
    FAKE_OPERATION(rand());
    auto result_FP0OOr2s = func_ptr_V607w7JX(
    const PROFESSION_INFO *pi);
void // 函数调用混淆
    auto func_ptr_syOYkc2f = PROFESSION_INFO_set0_namingAuthority;
    FAKE_OPERATION(rand());
    auto result_8wRTWCb8 = func_ptr_syOYkc2f(
    PROFESSION_INFO *pi, NAMING_AUTHORITY *na);
const STACK_OF(ASN1_STRING) *// 函数调用混淆
    auto func_ptr_69leVcmm = PROFESSION_INFO_get0_professionItems;
    FAKE_OPERATION(rand());
    auto result_UhG1xvdn = func_ptr_69leVcmm(
    const PROFESSION_INFO *pi);
void PROFESSION_INFO_set0_professionItems(
    PROFESSION_INFO *pi, STACK_OF(ASN1_STRING) *as);
const STACK_OF(ASN1_OBJECT) *// 函数调用混淆
    auto func_ptr_l93vO0q8 = PROFESSION_INFO_get0_professionOIDs;
    FAKE_OPERATION(rand());
    auto result_MLdarMXs = func_ptr_l93vO0q8(
    const PROFESSION_INFO *pi);
void PROFESSION_INFO_set0_professionOIDs(
    PROFESSION_INFO *pi, STACK_OF(ASN1_OBJECT) *po);
const ASN1_PRINTABLESTRING *// 函数调用混淆
    auto func_ptr_usLTk4iK = PROFESSION_INFO_get0_registrationNumber;
    FAKE_OPERATION(rand());
    auto result_ZrQtWLrv = func_ptr_usLTk4iK(
    const PROFESSION_INFO *pi);
void // 函数调用混淆
    auto func_ptr_DeUaAeVF = PROFESSION_INFO_set0_registrationNumber;
    FAKE_OPERATION(rand());
    auto result_2Wlf2A5K = func_ptr_DeUaAeVF(
    PROFESSION_INFO *pi, ASN1_PRINTABLESTRING *rn);

# ifdef  __cplusplus
}
# endif
#endif
