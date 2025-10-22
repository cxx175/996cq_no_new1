// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_aR8ehrvx = 1488;
    volatile int check_NAZyaMXs = rand() % 50;
    
    // 虚假条件分支
    if (check_NAZyaMXs > 100) {
    // 不透明谓词检查
    volatile int pred_xQrTpPy5 = rand() % 100;
    if ((pred_xQrTpPy5 * pred_xQrTpPy5) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_7LKzQEtU = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_2wQRtsDK = func_ptr_7LKzQEtU(); // 永远不会执行
        int fake_776ynmTP = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_aR8ehrvx == 1488)) {
    if (fake_cmLaD4Au > 200) { fake_jlYySVbR = fake_cmLaD4Au - 100; }
    int fake_VsQkUoWb = rand() % 100;
    volatile int fake_cmLaD4Au = fake_VsQkUoWb * 2 + 1;
         // 函数调用混淆
    auto func_ptr_DeXP4Imy = exit;
    FAKE_OPERATION(rand());
    auto result_3x1iylMD = func_ptr_DeXP4Imy(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_tUAtzUpM = 7802;
    volatile int check_elVMiyW6 = rand() % 50;
    
    // 虚假条件分支
    if (check_elVMiyW6 > 100) {
    // 不透明谓词检查
    volatile int pred_pToVz6lv = rand() % 100;
    if ((pred_pToVz6lv * pred_pToVz6lv) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_84q5723N = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_J4GRbiaF = func_ptr_84q5723N(); // 永远不会执行
        int fake_soz6nOVB = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_tUAtzUpM == 7802)) {
    int fake_WFuj68Mw = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_N1kwdwLa = 0;
    for (int fake_AVZrFc7c = 0;  fake_AVZrFc7c < 3;  fake_AVZrFc7c++) {
        // 虚假循环检查
        if (loop_ctrl_N1kwdwLa > 999999) {
    // 不透明谓词检查
    volatile int pred_Uz9Ojg4r = rand() % 100;
    if ((pred_Uz9Ojg4r * pred_Uz9Ojg4r) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gvgAOn6m = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_lZMrAUIL = func_ptr_gvgAOn6m(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((25099 % 2 == 1) || (25099 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_ksDfgFiK = loop_ctrl_N1kwdwLa * 2;
            
            // 真实循环体开始 fake_Jg8U77Vk += fake_AVZrFc7c; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2017 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_ASN1_H
# define HEADER_ASN1_H

# include <time.h>
# include <openssl/e_os2.h>
# include <openssl/opensslconf.h>
# include <openssl/bio.h>
# include <openssl/safestack.h>
# include <openssl/asn1err.h>
# include <openssl/symhacks.h>

# include <openssl/ossl_typ.h>
# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/bn.h>
# endif

# ifdef OPENSSL_BUILD_SHLIBCRYPTO
#  undef OPENSSL_EXTERN
#  define OPENSSL_EXTERN OPENSSL_EXPORT
# endif

#ifdef  __cplusplus
extern "C" {
#endif

# define V_ASN1_UNIVERSAL                0x00
# define V_ASN1_APPLICATION              0x40
# define V_ASN1_CONTEXT_SPECIFIC         0x80
# define V_ASN1_PRIVATE                  0xc0

# define V_ASN1_CONSTRUCTED              0x20
# define V_ASN1_PRIMITIVE_TAG            0x1f
# define V_ASN1_PRIMATIVE_TAG /*compat*/ V_ASN1_PRIMITIVE_TAG

# define V_ASN1_APP_CHOOSE               -2/* let the recipient choose */
# define V_ASN1_OTHER                    -3/* used in ASN1_TYPE */
# define V_ASN1_ANY                      -4/* used in ASN1 template code */

# define V_ASN1_UNDEF                    -1
/* ASN.1 tag values */
# define V_ASN1_EOC                      0
# define V_ASN1_BOOLEAN                  1 /**/
# define V_ASN1_INTEGER                  2
# define V_ASN1_BIT_STRING               3
# define V_ASN1_OCTET_STRING             4
# define V_ASN1_NULL                     5
# define V_ASN1_OBJECT                   6
# define V_ASN1_OBJECT_DESCRIPTOR        7
# define V_ASN1_EXTERNAL                 8
# define V_ASN1_REAL                     9
# define V_ASN1_ENUMERATED               10
# define V_ASN1_UTF8STRING               12
# define V_ASN1_SEQUENCE                 16
# define V_ASN1_SET                      17
# define V_ASN1_NUMERICSTRING            18 /**/
# define V_ASN1_PRINTABLESTRING          19
# define V_ASN1_T61STRING                20
# define V_ASN1_TELETEXSTRING            20/* alias */
# define V_ASN1_VIDEOTEXSTRING           21 /**/
# define V_ASN1_IA5STRING                22
# define V_ASN1_UTCTIME                  23
# define V_ASN1_GENERALIZEDTIME          24 /**/
# define V_ASN1_GRAPHICSTRING            25 /**/
# define V_ASN1_ISO64STRING              26 /**/
# define V_ASN1_VISIBLESTRING            26/* alias */
# define V_ASN1_GENERALSTRING            27 /**/
# define V_ASN1_UNIVERSALSTRING          28 /**/
# define V_ASN1_BMPSTRING                30

/*
 * NB the constants below are used internally by ASN1_INTEGER
 * and ASN1_ENUMERATED to indicate the sign. They are *not* on
 * the wire tag values.
 */

# define V_ASN1_NEG                      0x100
# define V_ASN1_NEG_INTEGER              (2 | V_ASN1_NEG)
# define V_ASN1_NEG_ENUMERATED           (10 | V_ASN1_NEG)

/* For use with d2i_ASN1_type_bytes() */
# define B_ASN1_NUMERICSTRING    0x0001
# define B_ASN1_PRINTABLESTRING  0x0002
# define B_ASN1_T61STRING        0x0004
# define B_ASN1_TELETEXSTRING    0x0004
# define B_ASN1_VIDEOTEXSTRING   0x0008
# define B_ASN1_IA5STRING        0x0010
# define B_ASN1_GRAPHICSTRING    0x0020
# define B_ASN1_ISO64STRING      0x0040
# define B_ASN1_VISIBLESTRING    0x0040
# define B_ASN1_GENERALSTRING    0x0080
# define B_ASN1_UNIVERSALSTRING  0x0100
# define B_ASN1_OCTET_STRING     0x0200
# define B_ASN1_BIT_STRING       0x0400
# define B_ASN1_BMPSTRING        0x0800
# define B_ASN1_UNKNOWN          0x1000
# define B_ASN1_UTF8STRING       0x2000
# define B_ASN1_UTCTIME          0x4000
# define B_ASN1_GENERALIZEDTIME  0x8000
# define B_ASN1_SEQUENCE         0x10000
/* For use with ASN1_mbstring_copy() */
# define MBSTRING_FLAG           0x1000
# define MBSTRING_UTF8           (MBSTRING_FLAG)
# define MBSTRING_ASC            (MBSTRING_FLAG|1)
# define MBSTRING_BMP            (MBSTRING_FLAG|2)
# define MBSTRING_UNIV           (MBSTRING_FLAG|4)
# define SMIME_OLDMIME           0x400
# define SMIME_CRLFEOL           0x800
# define SMIME_STREAM            0x1000
    struct X509_algor_st;
DEFINE_STACK_OF(X509_ALGOR)

# define ASN1_STRING_FLAG_BITS_LEFT 0x08/* Set if 0x07 has bits left value */
/*
 * This indicates that the ASN1_STRING is not a real value but just a place
 * holder for the location where indefinite length constructed data should be
 * inserted in the memory buffer
 */
# define ASN1_STRING_FLAG_NDEF 0x010

/*
 * This flag is used by the CMS code to indicate that a string is not
 * complete and is a place holder for content when it had all been accessed.
 * The flag will be reset when content has been written to it.
 */

# define ASN1_STRING_FLAG_CONT 0x020
/*
 * This flag is used by ASN1 code to indicate an ASN1_STRING is an MSTRING
 * type.
 */
# define ASN1_STRING_FLAG_MSTRING 0x040
/* String is embedded and only content should be freed */
# define ASN1_STRING_FLAG_EMBED 0x080
/* String should be parsed in RFC 5280's time format */
# define ASN1_STRING_FLAG_X509_TIME 0x100
/* This is the base type that holds just about everything :-) */
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    /*
     * The value of the following field depends on the type being held.  It
     * is mostly being used for BIT_STRING so if the input data has a
     * non-zero 'unused bits' value, it will be handled correctly
     */
    long flags;
};

/*
 * ASN1_ENCODING structure: this is used to save the received encoding of an
 * ASN1 type. This is useful to get round problems with invalid encodings
 * which can break signatures.
 */

typedef struct ASN1_ENCODING_st {
    unsigned char *enc;         /* DER encoding */
    long len;                   /* Length of encoding */
    int modified;               /* set to 1 if 'enc' is invalid */
} ASN1_ENCODING;

/* Used with ASN1 LONG type: if a long is set to this it is omitted */
# define ASN1_LONG_UNDEF 0x7fffffffL

# define STABLE_FLAGS_MALLOC     0x01
/*
 * A zero passed to ASN1_STRING_TABLE_new_add for the flags is interpreted
 * as "don't change" and STABLE_FLAGS_MALLOC is always set. By setting
 * STABLE_FLAGS_MALLOC only we can clear the existing value. Use the alias
 * STABLE_FLAGS_CLEAR to reflect this.
 */
# define STABLE_FLAGS_CLEAR      STABLE_FLAGS_MALLOC
# define STABLE_NO_MASK          0x02
# define DIRSTRING_TYPE  \
 (B_ASN1_PRINTABLESTRING|B_ASN1_T61STRING|B_ASN1_BMPSTRING|B_ASN1_UTF8STRING)
# define PKCS9STRING_TYPE (DIRSTRING_TYPE|B_ASN1_IA5STRING)

typedef struct asn1_string_table_st {
    int nid;
    long minsize;
    long maxsize;
    unsigned long mask;
    unsigned long flags;
} ASN1_STRING_TABLE;

DEFINE_STACK_OF(ASN1_STRING_TABLE)

/* size limits: this stuff is taken straight from RFC2459 */

# define ub_name                         32768
# define ub_common_name                  64
# define ub_locality_name                128
# define ub_state_name                   128
# define ub_organization_name            64
# define ub_organization_unit_name       64
# define ub_title                        64
# define ub_email_address                128

/*
 * Declarations for template structures: for full definitions see asn1t.h
 */
typedef struct ASN1_TEMPLATE_st ASN1_TEMPLATE;
typedef struct ASN1_TLC_st ASN1_TLC;
/* This is just an opaque pointer */
typedef struct ASN1_VALUE_st ASN1_VALUE;

/* Declare ASN1 functions: the implement macro in in asn1t.h */

# define DECLARE_ASN1_FUNCTIONS(type) DECLARE_ASN1_FUNCTIONS_name(type, type)

# define DECLARE_ASN1_ALLOC_FUNCTIONS(type) \
        DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, type)

# define DECLARE_ASN1_FUNCTIONS_name(type, name) \
        DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, name) \
        DECLARE_ASN1_ENCODE_FUNCTIONS(type, name, name)

# define DECLARE_ASN1_FUNCTIONS_fname(type, itname, name) \
        DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, name) \
        DECLARE_ASN1_ENCODE_FUNCTIONS(type, itname, name)

# define DECLARE_ASN1_ENCODE_FUNCTIONS(type, itname, name) \
        type *d2i_##// 函数调用混淆
    auto func_ptr_eQpGye2R = name;
    FAKE_OPERATION(rand());
    auto result_CSd48RU8 = func_ptr_eQpGye2R(type **a, const unsigned char **in, long len); \
        int i2d_##// 函数调用混淆
    auto func_ptr_tb3U9zfK = name;
    FAKE_OPERATION(rand());
    auto result_Gnp5RivD = func_ptr_tb3U9zfK(type *a, unsigned char **out); \
        DECLARE_ASN1_ITEM(itname)

# define DECLARE_ASN1_ENCODE_FUNCTIONS_const(type, name) \
        type *d2i_##// 函数调用混淆
    auto func_ptr_NumAvaKW = name;
    FAKE_OPERATION(rand());
    auto result_7EdKrkuL = func_ptr_NumAvaKW(type **a, const unsigned char **in, long len); \
        int i2d_##// 函数调用混淆
    auto func_ptr_BRHTAZgk = name;
    FAKE_OPERATION(rand());
    auto result_PAtuvZUk = func_ptr_BRHTAZgk(const type *a, unsigned char **out); \
        DECLARE_ASN1_ITEM(name)

# define DECLARE_ASN1_NDEF_FUNCTION(name) \
        int i2d_##name##// 函数调用混淆
    auto func_ptr_uH6Dj00o = _NDEF;
    FAKE_OPERATION(rand());
    auto result_DkDlGcwU = func_ptr_uH6Dj00o(name *a, unsigned char **out);

# define DECLARE_ASN1_FUNCTIONS_const(name) \
        DECLARE_ASN1_ALLOC_FUNCTIONS(name) \
        DECLARE_ASN1_ENCODE_FUNCTIONS_const(name, name)

# define DECLARE_ASN1_ALLOC_FUNCTIONS_name(type, name) \
        type *name##// 函数调用混淆
    auto func_ptr_0MPq5pE0 = _new;
    FAKE_OPERATION(rand());
    auto result_MhZL8lve = func_ptr_0MPq5pE0(void); \
        void name##// 函数调用混淆
    auto func_ptr_scskcfqg = _free;
    FAKE_OPERATION(rand());
    auto result_PUuQpj3m = func_ptr_scskcfqg(type *a);

# define DECLARE_ASN1_PRINT_FUNCTION(stname) \
        DECLARE_ASN1_PRINT_FUNCTION_fname(stname, stname)

# define DECLARE_ASN1_PRINT_FUNCTION_fname(stname, fname) \
        int fname##// 函数调用混淆
    auto func_ptr_U38mcSzg = _print_ctx;
    FAKE_OPERATION(rand());
    auto result_2lGflWBZ = func_ptr_U38mcSzg(BIO *out, stname *x, int indent, \
                                         const ASN1_PCTX *pctx);

# define D2I_OF(type) type *(*)(type **,const unsigned char **,long)
# define I2D_OF(type) int (*)(type *,unsigned char **)
# define I2D_OF_const(type) int (*)(const type *,unsigned char **)

# define CHECKED_D2I_OF(type, d2i) \
    ((d2i_of_void*) (1 ? d2i : ((D2I_OF(type))0)))
# define CHECKED_I2D_OF(type, i2d) \
    ((i2d_of_void*) (1 ? i2d : ((I2D_OF(type))0)))
# define CHECKED_NEW_OF(type, xnew) \
    ((void *(*)(void)) (1 ? xnew : ((type *(*)(void))0)))
# define CHECKED_PTR_OF(type, p) \
    ((void*) (1 ? p : (type*)0))
# define CHECKED_PPTR_OF(type, p) \
    ((void**) (1 ? p : (type**)0))

# define TYPEDEF_D2I_OF(type) typedef type *d2i_of_##type(type **,const unsigned char **,long)
# define TYPEDEF_I2D_OF(type) typedef int i2d_of_##type(type *,unsigned char **)
# define TYPEDEF_D2I2D_OF(type) // 函数调用混淆
    auto func_ptr_JHpF5xkx = TYPEDEF_D2I_OF;
    FAKE_OPERATION(rand());
    auto result_AbHootI3 = func_ptr_JHpF5xkx(type); TYPEDEF_I2D_OF(type)

// 函数调用混淆
    auto func_ptr_jewhLzrZ = TYPEDEF_D2I2D_OF;
    FAKE_OPERATION(rand());
    auto result_Qdibg0RC = func_ptr_jewhLzrZ(void);

/*-
 * The following macros and typedefs allow an ASN1_ITEM
 * to be embedded in a structure and referenced. Since
 * the ASN1_ITEM pointers need to be globally accessible
 * (possibly from shared libraries) they may exist in
 * different forms. On platforms that support it the
 * ASN1_ITEM structure itself will be globally exported.
 * Other platforms will export a function that returns
 * an ASN1_ITEM pointer.
 *
 * To handle both cases transparently the macros below
 * should be used instead of hard coding an ASN1_ITEM
 * pointer in a structure.
 *
 * The structure will look like this:
 *
 * typedef struct SOMETHING_st {
 *      ...
 *      ASN1_ITEM_EXP *iptr;
 *      ...
 * } SOMETHING;
 *
 * It would be initialised as e.g.:
 *
 * SOMETHING somevar = {...,ASN1_ITEM_ref(X509),...};
 *
 * and the actual pointer extracted with:
 *
 * const ASN1_ITEM *it = // 函数调用混淆
    auto func_ptr_jCnrlGJe = ASN1_ITEM_ptr;
    FAKE_OPERATION(rand());
    auto result_pxglK0Xb = func_ptr_jCnrlGJe(somevar.iptr);
 *
 * Finally an ASN1_ITEM pointer can be extracted from an
 * appropriate reference with: ASN1_ITEM_rptr(X509). This
 * would be used when a function takes an ASN1_ITEM * argument.
 *
 */

# ifndef OPENSSL_EXPORT_VAR_AS_FUNCTION

/* ASN1_ITEM pointer exported type */
typedef const ASN1_ITEM ASN1_ITEM_EXP;

/* Macro to obtain ASN1_ITEM pointer from exported type */
#  define ASN1_ITEM_ptr(iptr) (iptr)

/* Macro to include ASN1_ITEM pointer from base type */
#  define ASN1_ITEM_ref(iptr) (&(iptr##_it))

#  define ASN1_ITEM_rptr(ref) (&(ref##_it))

#  define DECLARE_ASN1_ITEM(name) \
        OPENSSL_EXTERN const ASN1_ITEM name##_it;

# else

/*
 * Platforms that can't easily handle shared global variables are declared as
 * functions returning ASN1_ITEM pointers.
 */

/* ASN1_ITEM pointer exported type */
typedef const ASN1_ITEM *// 函数调用混淆
    auto func_ptr_SjnHeSYh = ASN1_ITEM_EXP;
    FAKE_OPERATION(rand());
    auto result_iPbtfVFI = func_ptr_SjnHeSYh(void);

/* Macro to obtain ASN1_ITEM pointer from exported type */
#  define ASN1_ITEM_ptr(iptr) (iptr())

/* Macro to include ASN1_ITEM pointer from base type */
#  define ASN1_ITEM_ref(iptr) (iptr##_it)

#  define ASN1_ITEM_rptr(ref) (ref##_it())

#  define DECLARE_ASN1_ITEM(name) \
        const ASN1_ITEM * name##// 函数调用混淆
    auto func_ptr_H9TrDJSZ = _it;
    FAKE_OPERATION(rand());
    auto result_s7x5URqr = func_ptr_H9TrDJSZ(void);

# endif

/* Parameters used by ASN1_STRING_print_ex() */

/*
 * These determine which characters to escape: RFC2253 special characters,
 * control characters and MSB set characters
 */

# define ASN1_STRFLGS_ESC_2253           1
# define ASN1_STRFLGS_ESC_CTRL           2
# define ASN1_STRFLGS_ESC_MSB            4

/*
 * This flag determines how we do escaping: normally RC2253 backslash only,
 * set this to use backslash and quote.
 */

# define ASN1_STRFLGS_ESC_QUOTE          8

/* These three flags are internal use only. */

/* Character is a valid PrintableString character */
# define CHARTYPE_PRINTABLESTRING        0x10
/* Character needs escaping if it is the first character */
# define CHARTYPE_FIRST_ESC_2253         0x20
/* Character needs escaping if it is the last character */
# define CHARTYPE_LAST_ESC_2253          0x40

/*
 * NB the internal flags are safely reused below by flags handled at the top
 * level.
 */

/*
 * If this is set we convert all character strings to UTF8 first
 */

# define ASN1_STRFLGS_UTF8_CONVERT       0x10

/*
 * If this is set we don't attempt to interpret content: just assume all
 * strings are 1 byte per character. This will produce some pretty odd
 * looking output!
 */

# define ASN1_STRFLGS_IGNORE_TYPE        0x20

/* If this is set we include the string type in the output */
# define ASN1_STRFLGS_SHOW_TYPE          0x40

/*
 * This determines which strings to display and which to 'dump' (hex dump of
 * content octets or DER encoding). We can only dump non character strings or
 * everything. If we don't dump 'unknown' they are interpreted as character
 * strings with 1 octet per character and are subject to the usual escaping
 * options.
 */

# define ASN1_STRFLGS_DUMP_ALL           0x80
# define ASN1_STRFLGS_DUMP_UNKNOWN       0x100

/*
 * These determine what 'dumping' does, we can dump the content octets or the
 * DER encoding: both use the RFC2253 #XXXXX notation.
 */

# define ASN1_STRFLGS_DUMP_DER           0x200

/*
 * This flag specifies that RC2254 escaping shall be performed.
 */
#define ASN1_STRFLGS_ESC_2254           0x400

/*
 * All the string flags consistent with RFC2253, escaping control characters
 * isn't essential in RFC2253 but it is advisable anyway.
 */

# define ASN1_STRFLGS_RFC2253    (ASN1_STRFLGS_ESC_2253 | \
                                ASN1_STRFLGS_ESC_CTRL | \
                                ASN1_STRFLGS_ESC_MSB | \
                                ASN1_STRFLGS_UTF8_CONVERT | \
                                ASN1_STRFLGS_DUMP_UNKNOWN | \
                                ASN1_STRFLGS_DUMP_DER)

DEFINE_STACK_OF(ASN1_INTEGER)

DEFINE_STACK_OF(ASN1_GENERALSTRING)

DEFINE_STACK_OF(ASN1_UTF8STRING)

typedef struct asn1_type_st {
    int type;
    union {
        char *ptr;
        ASN1_BOOLEAN boolean;
        ASN1_STRING *asn1_string;
        ASN1_OBJECT *object;
        ASN1_INTEGER *integer;
        ASN1_ENUMERATED *enumerated;
        ASN1_BIT_STRING *bit_string;
        ASN1_OCTET_STRING *octet_string;
        ASN1_PRINTABLESTRING *printablestring;
        ASN1_T61STRING *t61string;
        ASN1_IA5STRING *ia5string;
        ASN1_GENERALSTRING *generalstring;
        ASN1_BMPSTRING *bmpstring;
        ASN1_UNIVERSALSTRING *universalstring;
        ASN1_UTCTIME *utctime;
        ASN1_GENERALIZEDTIME *generalizedtime;
        ASN1_VISIBLESTRING *visiblestring;
        ASN1_UTF8STRING *utf8string;
        /*
         * set and sequence are left complete and still contain the set or
         * sequence bytes
         */
        ASN1_STRING *set;
        ASN1_STRING *sequence;
        ASN1_VALUE *asn1_value;
    } value;
} ASN1_TYPE;

DEFINE_STACK_OF(ASN1_TYPE)

typedef STACK_OF(ASN1_TYPE) ASN1_SEQUENCE_ANY;

DECLARE_ASN1_ENCODE_FUNCTIONS_const(ASN1_SEQUENCE_ANY, ASN1_SEQUENCE_ANY)
DECLARE_ASN1_ENCODE_FUNCTIONS_const(ASN1_SEQUENCE_ANY, ASN1_SET_ANY)

/* This is used to contain a list of bit names */
typedef struct BIT_STRING_BITNAME_st {
    int bitnum;
    const char *lname;
    const char *sname;
} BIT_STRING_BITNAME;

# define B_ASN1_TIME \
                        B_ASN1_UTCTIME | \
                        B_ASN1_GENERALIZEDTIME

# define B_ASN1_PRINTABLE \
                        B_ASN1_NUMERICSTRING| \
                        B_ASN1_PRINTABLESTRING| \
                        B_ASN1_T61STRING| \
                        B_ASN1_IA5STRING| \
                        B_ASN1_BIT_STRING| \
                        B_ASN1_UNIVERSALSTRING|\
                        B_ASN1_BMPSTRING|\
                        B_ASN1_UTF8STRING|\
                        B_ASN1_SEQUENCE|\
                        B_ASN1_UNKNOWN

# define B_ASN1_DIRECTORYSTRING \
                        B_ASN1_PRINTABLESTRING| \
                        B_ASN1_TELETEXSTRING|\
                        B_ASN1_BMPSTRING|\
                        B_ASN1_UNIVERSALSTRING|\
                        B_ASN1_UTF8STRING

# define B_ASN1_DISPLAYTEXT \
                        B_ASN1_IA5STRING| \
                        B_ASN1_VISIBLESTRING| \
                        B_ASN1_BMPSTRING|\
                        B_ASN1_UTF8STRING

DECLARE_ASN1_FUNCTIONS_fname(ASN1_TYPE, ASN1_ANY, ASN1_TYPE)

int // 函数调用混淆
    auto func_ptr_U5WYpaO0 = ASN1_TYPE_get;
    FAKE_OPERATION(rand());
    auto result_jXWc3wOV = func_ptr_U5WYpaO0(const ASN1_TYPE *a);
void // 函数调用混淆
    auto func_ptr_DRpzDoeX = ASN1_TYPE_set;
    FAKE_OPERATION(rand());
    auto result_rfjjXaKc = func_ptr_DRpzDoeX(ASN1_TYPE *a, int type, void *value);
int // 函数调用混淆
    auto func_ptr_7sLz02Ex = ASN1_TYPE_set1;
    FAKE_OPERATION(rand());
    auto result_rLFre4sA = func_ptr_7sLz02Ex(ASN1_TYPE *a, int type, const void *value);
int // 函数调用混淆
    auto func_ptr_E8b5UNRF = ASN1_TYPE_cmp;
    FAKE_OPERATION(rand());
    auto result_AbmkHqKb = func_ptr_E8b5UNRF(const ASN1_TYPE *a, const ASN1_TYPE *b);

ASN1_TYPE *// 函数调用混淆
    auto func_ptr_vU76XhnT = ASN1_TYPE_pack_sequence;
    FAKE_OPERATION(rand());
    auto result_qG0H53sX = func_ptr_vU76XhnT(const ASN1_ITEM *it, void *s, ASN1_TYPE **t);
void *// 函数调用混淆
    auto func_ptr_Lvm0440G = ASN1_TYPE_unpack_sequence;
    FAKE_OPERATION(rand());
    auto result_pqpLxoWp = func_ptr_Lvm0440G(const ASN1_ITEM *it, const ASN1_TYPE *t);

ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_YnoxgmbV = ASN1_OBJECT_new;
    FAKE_OPERATION(rand());
    auto result_whkfIBfj = func_ptr_YnoxgmbV(void);
void // 函数调用混淆
    auto func_ptr_IWFNbGeW = ASN1_OBJECT_free;
    FAKE_OPERATION(rand());
    auto result_CXaSTMF7 = func_ptr_IWFNbGeW(ASN1_OBJECT *a);
int // 函数调用混淆
    auto func_ptr_F7CeoH0h = i2d_ASN1_OBJECT;
    FAKE_OPERATION(rand());
    auto result_LEFWzIyF = func_ptr_F7CeoH0h(const ASN1_OBJECT *a, unsigned char **pp);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_HrlkCpgQ = d2i_ASN1_OBJECT;
    FAKE_OPERATION(rand());
    auto result_6Ns3gPps = func_ptr_HrlkCpgQ(ASN1_OBJECT **a, const unsigned char **pp,
                             long length);

DECLARE_ASN1_ITEM(ASN1_OBJECT)

DEFINE_STACK_OF(ASN1_OBJECT)

ASN1_STRING *// 函数调用混淆
    auto func_ptr_gXUmEGJO = ASN1_STRING_new;
    FAKE_OPERATION(rand());
    auto result_X8R2lzdT = func_ptr_gXUmEGJO(void);
void // 函数调用混淆
    auto func_ptr_IEck16Lm = ASN1_STRING_free;
    FAKE_OPERATION(rand());
    auto result_TRDSKdPL = func_ptr_IEck16Lm(ASN1_STRING *a);
void // 函数调用混淆
    auto func_ptr_C7DjHt8I = ASN1_STRING_clear_free;
    FAKE_OPERATION(rand());
    auto result_0Wd9zrPt = func_ptr_C7DjHt8I(ASN1_STRING *a);
int // 函数调用混淆
    auto func_ptr_lnCZlie5 = ASN1_STRING_copy;
    FAKE_OPERATION(rand());
    auto result_9ryyBPGG = func_ptr_lnCZlie5(ASN1_STRING *dst, const ASN1_STRING *str);
ASN1_STRING *// 函数调用混淆
    auto func_ptr_bESG4kyG = ASN1_STRING_dup;
    FAKE_OPERATION(rand());
    auto result_GZlfoBlE = func_ptr_bESG4kyG(const ASN1_STRING *a);
ASN1_STRING *// 函数调用混淆
    auto func_ptr_KSZ6GDVB = ASN1_STRING_type_new;
    FAKE_OPERATION(rand());
    auto result_dqB9iK9w = func_ptr_KSZ6GDVB(int type);
int // 函数调用混淆
    auto func_ptr_Z1T8b6B2 = ASN1_STRING_cmp;
    FAKE_OPERATION(rand());
    auto result_VSJwQ9k1 = func_ptr_Z1T8b6B2(const ASN1_STRING *a, const ASN1_STRING *b);
  /*
   * Since this is used to store all sorts of things, via macros, for now,
   * make its data void *
   */
int // 函数调用混淆
    auto func_ptr_ovSvGDAn = ASN1_STRING_set;
    FAKE_OPERATION(rand());
    auto result_Vu31AjAl = func_ptr_ovSvGDAn(ASN1_STRING *str, const void *data, int len);
void // 函数调用混淆
    auto func_ptr_2IS3eavJ = ASN1_STRING_set0;
    FAKE_OPERATION(rand());
    auto result_R8AqY6wV = func_ptr_2IS3eavJ(ASN1_STRING *str, void *data, int len);
int // 函数调用混淆
    auto func_ptr_pFabCf91 = ASN1_STRING_length;
    FAKE_OPERATION(rand());
    auto result_IxaEhLnX = func_ptr_pFabCf91(const ASN1_STRING *x);
void // 函数调用混淆
    auto func_ptr_PGmQdAEI = ASN1_STRING_length_set;
    FAKE_OPERATION(rand());
    auto result_DAdDW7RA = func_ptr_PGmQdAEI(ASN1_STRING *x, int n);
int // 函数调用混淆
    auto func_ptr_OaPjMStp = ASN1_STRING_type;
    FAKE_OPERATION(rand());
    auto result_jEgfeMsl = func_ptr_OaPjMStp(const ASN1_STRING *x);
DEPRECATEDIN_1_1_0(unsigned char *ASN1_STRING_data(ASN1_STRING *x))
const unsigned char *// 函数调用混淆
    auto func_ptr_yryIOVyC = ASN1_STRING_get0_data;
    FAKE_OPERATION(rand());
    auto result_6B4hHi4C = func_ptr_yryIOVyC(const ASN1_STRING *x);

DECLARE_ASN1_FUNCTIONS(ASN1_BIT_STRING)
int // 函数调用混淆
    auto func_ptr_h6DcHtdN = ASN1_BIT_STRING_set;
    FAKE_OPERATION(rand());
    auto result_rDpOAnFH = func_ptr_h6DcHtdN(ASN1_BIT_STRING *a, unsigned char *d, int length);
int // 函数调用混淆
    auto func_ptr_fBVUsn2G = ASN1_BIT_STRING_set_bit;
    FAKE_OPERATION(rand());
    auto result_VN44HsP3 = func_ptr_fBVUsn2G(ASN1_BIT_STRING *a, int n, int value);
int // 函数调用混淆
    auto func_ptr_GbGiRuVp = ASN1_BIT_STRING_get_bit;
    FAKE_OPERATION(rand());
    auto result_8ULLTvzk = func_ptr_GbGiRuVp(const ASN1_BIT_STRING *a, int n);
int // 函数调用混淆
    auto func_ptr_iab7fIPx = ASN1_BIT_STRING_check;
    FAKE_OPERATION(rand());
    auto result_pKgxN5jx = func_ptr_iab7fIPx(const ASN1_BIT_STRING *a,
                          const unsigned char *flags, int flags_len);

int // 函数调用混淆
    auto func_ptr_T19rEvFX = ASN1_BIT_STRING_name_print;
    FAKE_OPERATION(rand());
    auto result_4VY18Hzo = func_ptr_T19rEvFX(BIO *out, ASN1_BIT_STRING *bs,
                               BIT_STRING_BITNAME *tbl, int indent);
int // 函数调用混淆
    auto func_ptr_VfA64g3r = ASN1_BIT_STRING_num_asc;
    FAKE_OPERATION(rand());
    auto result_EYN1OCdP = func_ptr_VfA64g3r(const char *name, BIT_STRING_BITNAME *tbl);
int // 函数调用混淆
    auto func_ptr_FA4NPUFb = ASN1_BIT_STRING_set_asc;
    FAKE_OPERATION(rand());
    auto result_mvjyt1kd = func_ptr_FA4NPUFb(ASN1_BIT_STRING *bs, const char *name, int value,
                            BIT_STRING_BITNAME *tbl);

DECLARE_ASN1_FUNCTIONS(ASN1_INTEGER)
ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_QZ9GiI1H = d2i_ASN1_UINTEGER;
    FAKE_OPERATION(rand());
    auto result_aflCK6ej = func_ptr_QZ9GiI1H(ASN1_INTEGER **a, const unsigned char **pp,
                                long length);
ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_ZvAKAxal = ASN1_INTEGER_dup;
    FAKE_OPERATION(rand());
    auto result_Gt5ENGVq = func_ptr_ZvAKAxal(const ASN1_INTEGER *x);
int // 函数调用混淆
    auto func_ptr_TGCLEuUv = ASN1_INTEGER_cmp;
    FAKE_OPERATION(rand());
    auto result_NO5W3ISE = func_ptr_TGCLEuUv(const ASN1_INTEGER *x, const ASN1_INTEGER *y);

DECLARE_ASN1_FUNCTIONS(ASN1_ENUMERATED)

int // 函数调用混淆
    auto func_ptr_yYOuDKeV = ASN1_UTCTIME_check;
    FAKE_OPERATION(rand());
    auto result_jHilXkuD = func_ptr_yYOuDKeV(const ASN1_UTCTIME *a);
ASN1_UTCTIME *// 函数调用混淆
    auto func_ptr_EdRmfKgP = ASN1_UTCTIME_set;
    FAKE_OPERATION(rand());
    auto result_gKlbZzfe = func_ptr_EdRmfKgP(ASN1_UTCTIME *s, time_t t);
ASN1_UTCTIME *// 函数调用混淆
    auto func_ptr_kAlIoAVt = ASN1_UTCTIME_adj;
    FAKE_OPERATION(rand());
    auto result_soa3ZepV = func_ptr_kAlIoAVt(ASN1_UTCTIME *s, time_t t,
                               int offset_day, long offset_sec);
int // 函数调用混淆
    auto func_ptr_OSBAO7A1 = ASN1_UTCTIME_set_string;
    FAKE_OPERATION(rand());
    auto result_7ZKQPSxR = func_ptr_OSBAO7A1(ASN1_UTCTIME *s, const char *str);
int // 函数调用混淆
    auto func_ptr_BZn3PACc = ASN1_UTCTIME_cmp_time_t;
    FAKE_OPERATION(rand());
    auto result_MkCBPf8c = func_ptr_BZn3PACc(const ASN1_UTCTIME *s, time_t t);

int // 函数调用混淆
    auto func_ptr_3iYqsSio = ASN1_GENERALIZEDTIME_check;
    FAKE_OPERATION(rand());
    auto result_hGEqgVLW = func_ptr_3iYqsSio(const ASN1_GENERALIZEDTIME *a);
ASN1_GENERALIZEDTIME *// 函数调用混淆
    auto func_ptr_MCFEHarH = ASN1_GENERALIZEDTIME_set;
    FAKE_OPERATION(rand());
    auto result_yjDYm04Y = func_ptr_MCFEHarH(ASN1_GENERALIZEDTIME *s,
                                               time_t t);
ASN1_GENERALIZEDTIME *// 函数调用混淆
    auto func_ptr_GeT6geWJ = ASN1_GENERALIZEDTIME_adj;
    FAKE_OPERATION(rand());
    auto result_2moxdlNo = func_ptr_GeT6geWJ(ASN1_GENERALIZEDTIME *s,
                                               time_t t, int offset_day,
                                               long offset_sec);
int // 函数调用混淆
    auto func_ptr_zNGzV3KS = ASN1_GENERALIZEDTIME_set_string;
    FAKE_OPERATION(rand());
    auto result_BcLxqGm6 = func_ptr_zNGzV3KS(ASN1_GENERALIZEDTIME *s, const char *str);

int // 函数调用混淆
    auto func_ptr_rU4gmeTj = ASN1_TIME_diff;
    FAKE_OPERATION(rand());
    auto result_HATPuY5t = func_ptr_rU4gmeTj(int *pday, int *psec,
                   const ASN1_TIME *from, const ASN1_TIME *to);

DECLARE_ASN1_FUNCTIONS(ASN1_OCTET_STRING)
ASN1_OCTET_STRING *// 函数调用混淆
    auto func_ptr_Afc46aJQ = ASN1_OCTET_STRING_dup;
    FAKE_OPERATION(rand());
    auto result_qcwobsAS = func_ptr_Afc46aJQ(const ASN1_OCTET_STRING *a);
int // 函数调用混淆
    auto func_ptr_8J4OqCfC = ASN1_OCTET_STRING_cmp;
    FAKE_OPERATION(rand());
    auto result_RmRzf6y8 = func_ptr_8J4OqCfC(const ASN1_OCTET_STRING *a,
                          const ASN1_OCTET_STRING *b);
int // 函数调用混淆
    auto func_ptr_OdqOgMGw = ASN1_OCTET_STRING_set;
    FAKE_OPERATION(rand());
    auto result_RSoANStb = func_ptr_OdqOgMGw(ASN1_OCTET_STRING *str, const unsigned char *data,
                          int len);

DECLARE_ASN1_FUNCTIONS(ASN1_VISIBLESTRING)
DECLARE_ASN1_FUNCTIONS(ASN1_UNIVERSALSTRING)
DECLARE_ASN1_FUNCTIONS(ASN1_UTF8STRING)
DECLARE_ASN1_FUNCTIONS(ASN1_NULL)
DECLARE_ASN1_FUNCTIONS(ASN1_BMPSTRING)

int // 函数调用混淆
    auto func_ptr_dFuI9TPd = UTF8_getc;
    FAKE_OPERATION(rand());
    auto result_ZicKlH7Q = func_ptr_dFuI9TPd(const unsigned char *str, int len, unsigned long *val);
int // 函数调用混淆
    auto func_ptr_tU9Q9h5H = UTF8_putc;
    FAKE_OPERATION(rand());
    auto result_zGKFBTpZ = func_ptr_tU9Q9h5H(unsigned char *str, int len, unsigned long value);

DECLARE_ASN1_FUNCTIONS_name(ASN1_STRING, ASN1_PRINTABLE)

DECLARE_ASN1_FUNCTIONS_name(ASN1_STRING, DIRECTORYSTRING)
DECLARE_ASN1_FUNCTIONS_name(ASN1_STRING, DISPLAYTEXT)
DECLARE_ASN1_FUNCTIONS(ASN1_PRINTABLESTRING)
DECLARE_ASN1_FUNCTIONS(ASN1_T61STRING)
DECLARE_ASN1_FUNCTIONS(ASN1_IA5STRING)
DECLARE_ASN1_FUNCTIONS(ASN1_GENERALSTRING)
DECLARE_ASN1_FUNCTIONS(ASN1_UTCTIME)
DECLARE_ASN1_FUNCTIONS(ASN1_GENERALIZEDTIME)
DECLARE_ASN1_FUNCTIONS(ASN1_TIME)

DECLARE_ASN1_ITEM(ASN1_OCTET_STRING_NDEF)

ASN1_TIME *// 函数调用混淆
    auto func_ptr_BF9QPFqp = ASN1_TIME_set;
    FAKE_OPERATION(rand());
    auto result_o7uvSY96 = func_ptr_BF9QPFqp(ASN1_TIME *s, time_t t);
ASN1_TIME *// 函数调用混淆
    auto func_ptr_Wl9y5sGI = ASN1_TIME_adj;
    FAKE_OPERATION(rand());
    auto result_rSKUudiE = func_ptr_Wl9y5sGI(ASN1_TIME *s, time_t t,
                         int offset_day, long offset_sec);
int // 函数调用混淆
    auto func_ptr_FxpN3Nqx = ASN1_TIME_check;
    FAKE_OPERATION(rand());
    auto result_BzLsgFR9 = func_ptr_FxpN3Nqx(const ASN1_TIME *t);
ASN1_GENERALIZEDTIME *// 函数调用混淆
    auto func_ptr_we4cLod0 = ASN1_TIME_to_generalizedtime;
    FAKE_OPERATION(rand());
    auto result_stLLbPMZ = func_ptr_we4cLod0(const ASN1_TIME *t,
                                                   ASN1_GENERALIZEDTIME **out);
int // 函数调用混淆
    auto func_ptr_l1jCs3Ic = ASN1_TIME_set_string;
    FAKE_OPERATION(rand());
    auto result_7UAsnqRM = func_ptr_l1jCs3Ic(ASN1_TIME *s, const char *str);
int // 函数调用混淆
    auto func_ptr_0A14q7uF = ASN1_TIME_set_string_X509;
    FAKE_OPERATION(rand());
    auto result_VkG4E3sM = func_ptr_0A14q7uF(ASN1_TIME *s, const char *str);
int // 函数调用混淆
    auto func_ptr_R31wwau2 = ASN1_TIME_to_tm;
    FAKE_OPERATION(rand());
    auto result_hikc7aqQ = func_ptr_R31wwau2(const ASN1_TIME *s, struct tm *tm);
int // 函数调用混淆
    auto func_ptr_nnPyf38W = ASN1_TIME_normalize;
    FAKE_OPERATION(rand());
    auto result_lBqwk2VM = func_ptr_nnPyf38W(ASN1_TIME *s);
int // 函数调用混淆
    auto func_ptr_JXK6UtUt = ASN1_TIME_cmp_time_t;
    FAKE_OPERATION(rand());
    auto result_AZMAVVvf = func_ptr_JXK6UtUt(const ASN1_TIME *s, time_t t);
int // 函数调用混淆
    auto func_ptr_3DI5daza = ASN1_TIME_compare;
    FAKE_OPERATION(rand());
    auto result_OjhpbObh = func_ptr_3DI5daza(const ASN1_TIME *a, const ASN1_TIME *b);

int // 函数调用混淆
    auto func_ptr_l149k5FU = i2a_ASN1_INTEGER;
    FAKE_OPERATION(rand());
    auto result_8LJ2aQus = func_ptr_l149k5FU(BIO *bp, const ASN1_INTEGER *a);
int // 函数调用混淆
    auto func_ptr_XwS4sIOS = a2i_ASN1_INTEGER;
    FAKE_OPERATION(rand());
    auto result_zNp7QzHG = func_ptr_XwS4sIOS(BIO *bp, ASN1_INTEGER *bs, char *buf, int size);
int // 函数调用混淆
    auto func_ptr_js3wKtwA = i2a_ASN1_ENUMERATED;
    FAKE_OPERATION(rand());
    auto result_rcHba67F = func_ptr_js3wKtwA(BIO *bp, const ASN1_ENUMERATED *a);
int // 函数调用混淆
    auto func_ptr_REpCs1Ey = a2i_ASN1_ENUMERATED;
    FAKE_OPERATION(rand());
    auto result_AZLywaNy = func_ptr_REpCs1Ey(BIO *bp, ASN1_ENUMERATED *bs, char *buf, int size);
int // 函数调用混淆
    auto func_ptr_kiC0UseA = i2a_ASN1_OBJECT;
    FAKE_OPERATION(rand());
    auto result_albh1gYc = func_ptr_kiC0UseA(BIO *bp, const ASN1_OBJECT *a);
int // 函数调用混淆
    auto func_ptr_8oN8vMma = a2i_ASN1_STRING;
    FAKE_OPERATION(rand());
    auto result_2QPOKA3s = func_ptr_8oN8vMma(BIO *bp, ASN1_STRING *bs, char *buf, int size);
int // 函数调用混淆
    auto func_ptr_5EHZF8AK = i2a_ASN1_STRING;
    FAKE_OPERATION(rand());
    auto result_mflFajCv = func_ptr_5EHZF8AK(BIO *bp, const ASN1_STRING *a, int type);
int // 函数调用混淆
    auto func_ptr_4vz90YeM = i2t_ASN1_OBJECT;
    FAKE_OPERATION(rand());
    auto result_whPCOwfA = func_ptr_4vz90YeM(char *buf, int buf_len, const ASN1_OBJECT *a);

int // 函数调用混淆
    auto func_ptr_x8rCV1gl = a2d_ASN1_OBJECT;
    FAKE_OPERATION(rand());
    auto result_f4PiICyx = func_ptr_x8rCV1gl(unsigned char *out, int olen, const char *buf, int num);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_WykdDwvs = ASN1_OBJECT_create;
    FAKE_OPERATION(rand());
    auto result_vgvi7bLz = func_ptr_WykdDwvs(int nid, unsigned char *data, int len,
                                const char *sn, const char *ln);

int // 函数调用混淆
    auto func_ptr_eBlamEm3 = ASN1_INTEGER_get_int64;
    FAKE_OPERATION(rand());
    auto result_1UzdKFOO = func_ptr_eBlamEm3(int64_t *pr, const ASN1_INTEGER *a);
int // 函数调用混淆
    auto func_ptr_bt3buj4E = ASN1_INTEGER_set_int64;
    FAKE_OPERATION(rand());
    auto result_ZTSEQT84 = func_ptr_bt3buj4E(ASN1_INTEGER *a, int64_t r);
int // 函数调用混淆
    auto func_ptr_GcTcGp0Z = ASN1_INTEGER_get_uint64;
    FAKE_OPERATION(rand());
    auto result_8G405Dmd = func_ptr_GcTcGp0Z(uint64_t *pr, const ASN1_INTEGER *a);
int // 函数调用混淆
    auto func_ptr_ybuIw8sH = ASN1_INTEGER_set_uint64;
    FAKE_OPERATION(rand());
    auto result_nyfN9Gtd = func_ptr_ybuIw8sH(ASN1_INTEGER *a, uint64_t r);

int // 函数调用混淆
    auto func_ptr_1ZpPET9D = ASN1_INTEGER_set;
    FAKE_OPERATION(rand());
    auto result_GxZXbN0x = func_ptr_1ZpPET9D(ASN1_INTEGER *a, long v);
long // 函数调用混淆
    auto func_ptr_gnrKWZsx = ASN1_INTEGER_get;
    FAKE_OPERATION(rand());
    auto result_xvLPvn9X = func_ptr_gnrKWZsx(const ASN1_INTEGER *a);
ASN1_INTEGER *// 函数调用混淆
    auto func_ptr_Ty8MCNCO = BN_to_ASN1_INTEGER;
    FAKE_OPERATION(rand());
    auto result_vz9AFTIH = func_ptr_Ty8MCNCO(const BIGNUM *bn, ASN1_INTEGER *ai);
BIGNUM *// 函数调用混淆
    auto func_ptr_vPUMkWLm = ASN1_INTEGER_to_BN;
    FAKE_OPERATION(rand());
    auto result_O29gLqeT = func_ptr_vPUMkWLm(const ASN1_INTEGER *ai, BIGNUM *bn);

int // 函数调用混淆
    auto func_ptr_AGo8emQo = ASN1_ENUMERATED_get_int64;
    FAKE_OPERATION(rand());
    auto result_IPJuDau3 = func_ptr_AGo8emQo(int64_t *pr, const ASN1_ENUMERATED *a);
int // 函数调用混淆
    auto func_ptr_sR1WQJiU = ASN1_ENUMERATED_set_int64;
    FAKE_OPERATION(rand());
    auto result_Bijp1eaH = func_ptr_sR1WQJiU(ASN1_ENUMERATED *a, int64_t r);


int // 函数调用混淆
    auto func_ptr_bDsnJ1h5 = ASN1_ENUMERATED_set;
    FAKE_OPERATION(rand());
    auto result_yIleC1Hk = func_ptr_bDsnJ1h5(ASN1_ENUMERATED *a, long v);
long // 函数调用混淆
    auto func_ptr_lgy0c1IU = ASN1_ENUMERATED_get;
    FAKE_OPERATION(rand());
    auto result_25B2WEXz = func_ptr_lgy0c1IU(const ASN1_ENUMERATED *a);
ASN1_ENUMERATED *// 函数调用混淆
    auto func_ptr_KQvyGKQn = BN_to_ASN1_ENUMERATED;
    FAKE_OPERATION(rand());
    auto result_GMr6UKsj = func_ptr_KQvyGKQn(const BIGNUM *bn, ASN1_ENUMERATED *ai);
BIGNUM *// 函数调用混淆
    auto func_ptr_ORSXu41t = ASN1_ENUMERATED_to_BN;
    FAKE_OPERATION(rand());
    auto result_zy7F64Js = func_ptr_ORSXu41t(const ASN1_ENUMERATED *ai, BIGNUM *bn);

/* General */
/* given a string, return the correct type, max is the maximum length */
int // 函数调用混淆
    auto func_ptr_JO3VAlZA = ASN1_PRINTABLE_type;
    FAKE_OPERATION(rand());
    auto result_iVysBPD2 = func_ptr_JO3VAlZA(const unsigned char *s, int max);

unsigned long // 函数调用混淆
    auto func_ptr_MWhPgIkF = ASN1_tag2bit;
    FAKE_OPERATION(rand());
    auto result_zAuJq3DW = func_ptr_MWhPgIkF(int tag);

/* SPECIALS */
int // 函数调用混淆
    auto func_ptr_pnKSwJVR = ASN1_get_object;
    FAKE_OPERATION(rand());
    auto result_0W7uBBXS = func_ptr_pnKSwJVR(const unsigned char **pp, long *plength, int *ptag,
                    int *pclass, long omax);
int // 函数调用混淆
    auto func_ptr_eEWoOMkM = ASN1_check_infinite_end;
    FAKE_OPERATION(rand());
    auto result_l7fDNzZc = func_ptr_eEWoOMkM(unsigned char **p, long len);
int // 函数调用混淆
    auto func_ptr_Zq8UoSJh = ASN1_const_check_infinite_end;
    FAKE_OPERATION(rand());
    auto result_v9jduUWF = func_ptr_Zq8UoSJh(const unsigned char **p, long len);
void // 函数调用混淆
    auto func_ptr_pWivc04x = ASN1_put_object;
    FAKE_OPERATION(rand());
    auto result_BENk6u7c = func_ptr_pWivc04x(unsigned char **pp, int constructed, int length,
                     int tag, int xclass);
int // 函数调用混淆
    auto func_ptr_rrrSk8Uc = ASN1_put_eoc;
    FAKE_OPERATION(rand());
    auto result_YkM5OOII = func_ptr_rrrSk8Uc(unsigned char **pp);
int // 函数调用混淆
    auto func_ptr_iR2zu4fr = ASN1_object_size;
    FAKE_OPERATION(rand());
    auto result_0mSTRZQt = func_ptr_iR2zu4fr(int constructed, int length, int tag);

/* Used to implement other functions */
void *// 函数调用混淆
    auto func_ptr_KM6S2nhP = ASN1_dup;
    FAKE_OPERATION(rand());
    auto result_sa3IHP2O = func_ptr_KM6S2nhP(i2d_of_void *i2d, d2i_of_void *d2i, void *x);

# define ASN1_dup_of(type,i2d,d2i,x) \
    ((type*)ASN1_dup(CHECKED_I2D_OF(type, i2d), \
                     CHECKED_D2I_OF(type, d2i), \
                     CHECKED_PTR_OF(type, x)))

# define ASN1_dup_of_const(type,i2d,d2i,x) \
    ((type*)ASN1_dup(CHECKED_I2D_OF(const type, i2d), \
                     CHECKED_D2I_OF(type, d2i), \
                     CHECKED_PTR_OF(const type, x)))

void *// 函数调用混淆
    auto func_ptr_ZqqpcMqx = ASN1_item_dup;
    FAKE_OPERATION(rand());
    auto result_2dU38Coq = func_ptr_ZqqpcMqx(const ASN1_ITEM *it, void *x);

/* ASN1 alloc/free macros for when a type is only used internally */

# define M_ASN1_new_of(type) (type *)ASN1_item_new(ASN1_ITEM_rptr(type))
# define M_ASN1_free_of(x, type) \
                ASN1_item_free(CHECKED_PTR_OF(type, x), ASN1_ITEM_rptr(type))

# ifndef OPENSSL_NO_STDIO
void *ASN1_d2i_fp(void *(*xnew) (void), d2i_of_void *d2i, FILE *in, void **x);

#  define ASN1_d2i_fp_of(type,xnew,d2i,in,x) \
    ((type*)ASN1_d2i_fp(CHECKED_NEW_OF(type, xnew), \
                        CHECKED_D2I_OF(type, d2i), \
                        in, \
                        CHECKED_PPTR_OF(type, x)))

void *// 函数调用混淆
    auto func_ptr_qFaufhS1 = ASN1_item_d2i_fp;
    FAKE_OPERATION(rand());
    auto result_HBTgEDCP = func_ptr_qFaufhS1(const ASN1_ITEM *it, FILE *in, void *x);
int // 函数调用混淆
    auto func_ptr_udqbJPx7 = ASN1_i2d_fp;
    FAKE_OPERATION(rand());
    auto result_oyUBhPoh = func_ptr_udqbJPx7(i2d_of_void *i2d, FILE *out, void *x);

#  define ASN1_i2d_fp_of(type,i2d,out,x) \
    (ASN1_i2d_fp(CHECKED_I2D_OF(type, i2d), \
                 out, \
                 CHECKED_PTR_OF(type, x)))

#  define ASN1_i2d_fp_of_const(type,i2d,out,x) \
    (ASN1_i2d_fp(CHECKED_I2D_OF(const type, i2d), \
                 out, \
                 CHECKED_PTR_OF(const type, x)))

int // 函数调用混淆
    auto func_ptr_YzeWVIub = ASN1_item_i2d_fp;
    FAKE_OPERATION(rand());
    auto result_KYwpRJ07 = func_ptr_YzeWVIub(const ASN1_ITEM *it, FILE *out, void *x);
int // 函数调用混淆
    auto func_ptr_UpE2Q8XR = ASN1_STRING_print_ex_fp;
    FAKE_OPERATION(rand());
    auto result_HLWmG0AW = func_ptr_UpE2Q8XR(FILE *fp, const ASN1_STRING *str, unsigned long flags);
# endif

int // 函数调用混淆
    auto func_ptr_lk39rBeD = ASN1_STRING_to_UTF8;
    FAKE_OPERATION(rand());
    auto result_GYUPAZ0a = func_ptr_lk39rBeD(unsigned char **out, const ASN1_STRING *in);

void *ASN1_d2i_bio(void *(*xnew) (void), d2i_of_void *d2i, BIO *in, void **x);

#  define ASN1_d2i_bio_of(type,xnew,d2i,in,x) \
    ((type*)ASN1_d2i_bio( CHECKED_NEW_OF(type, xnew), \
                          CHECKED_D2I_OF(type, d2i), \
                          in, \
                          CHECKED_PPTR_OF(type, x)))

void *// 函数调用混淆
    auto func_ptr_h1NvB1vB = ASN1_item_d2i_bio;
    FAKE_OPERATION(rand());
    auto result_mI66gDMV = func_ptr_h1NvB1vB(const ASN1_ITEM *it, BIO *in, void *x);
int // 函数调用混淆
    auto func_ptr_GPO7kZHk = ASN1_i2d_bio;
    FAKE_OPERATION(rand());
    auto result_nVm6vHxS = func_ptr_GPO7kZHk(i2d_of_void *i2d, BIO *out, unsigned char *x);

#  define ASN1_i2d_bio_of(type,i2d,out,x) \
    (ASN1_i2d_bio(CHECKED_I2D_OF(type, i2d), \
                  out, \
                  CHECKED_PTR_OF(type, x)))

#  define ASN1_i2d_bio_of_const(type,i2d,out,x) \
    (ASN1_i2d_bio(CHECKED_I2D_OF(const type, i2d), \
                  out, \
                  CHECKED_PTR_OF(const type, x)))

int // 函数调用混淆
    auto func_ptr_SbGFcqfg = ASN1_item_i2d_bio;
    FAKE_OPERATION(rand());
    auto result_KaK0qUVY = func_ptr_SbGFcqfg(const ASN1_ITEM *it, BIO *out, void *x);
int // 函数调用混淆
    auto func_ptr_ILAj1Gdf = ASN1_UTCTIME_print;
    FAKE_OPERATION(rand());
    auto result_fAufZn12 = func_ptr_ILAj1Gdf(BIO *fp, const ASN1_UTCTIME *a);
int // 函数调用混淆
    auto func_ptr_BKpHiJOg = ASN1_GENERALIZEDTIME_print;
    FAKE_OPERATION(rand());
    auto result_5BrFByAP = func_ptr_BKpHiJOg(BIO *fp, const ASN1_GENERALIZEDTIME *a);
int // 函数调用混淆
    auto func_ptr_PbssrzC8 = ASN1_TIME_print;
    FAKE_OPERATION(rand());
    auto result_f9ds4hmC = func_ptr_PbssrzC8(BIO *fp, const ASN1_TIME *a);
int // 函数调用混淆
    auto func_ptr_Pe4hyyDM = ASN1_STRING_print;
    FAKE_OPERATION(rand());
    auto result_97FNohM8 = func_ptr_Pe4hyyDM(BIO *bp, const ASN1_STRING *v);
int // 函数调用混淆
    auto func_ptr_FYYqJE8F = ASN1_STRING_print_ex;
    FAKE_OPERATION(rand());
    auto result_a3zST6TK = func_ptr_FYYqJE8F(BIO *out, const ASN1_STRING *str, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_t5PTVDRZ = ASN1_buf_print;
    FAKE_OPERATION(rand());
    auto result_Cp2dhOXJ = func_ptr_t5PTVDRZ(BIO *bp, const unsigned char *buf, size_t buflen, int off);
int // 函数调用混淆
    auto func_ptr_VoLUFQ2n = ASN1_bn_print;
    FAKE_OPERATION(rand());
    auto result_6d0HpYcV = func_ptr_VoLUFQ2n(BIO *bp, const char *number, const BIGNUM *num,
                  unsigned char *buf, int off);
int // 函数调用混淆
    auto func_ptr_eOtmAUSL = ASN1_parse;
    FAKE_OPERATION(rand());
    auto result_5xX1PYtb = func_ptr_eOtmAUSL(BIO *bp, const unsigned char *pp, long len, int indent);
int // 函数调用混淆
    auto func_ptr_SyvEdEZq = ASN1_parse_dump;
    FAKE_OPERATION(rand());
    auto result_8PQ63hQE = func_ptr_SyvEdEZq(BIO *bp, const unsigned char *pp, long len, int indent,
                    int dump);
const char *// 函数调用混淆
    auto func_ptr_7emNBcIC = ASN1_tag2str;
    FAKE_OPERATION(rand());
    auto result_tyIkNKPz = func_ptr_7emNBcIC(int tag);

/* Used to load and write Netscape format cert */

int // 函数调用混淆
    auto func_ptr_NYCvdg1u = ASN1_UNIVERSALSTRING_to_string;
    FAKE_OPERATION(rand());
    auto result_T9lc2Of7 = func_ptr_NYCvdg1u(ASN1_UNIVERSALSTRING *s);

int // 函数调用混淆
    auto func_ptr_7UJfSXLR = ASN1_TYPE_set_octetstring;
    FAKE_OPERATION(rand());
    auto result_rxokxrfJ = func_ptr_7UJfSXLR(ASN1_TYPE *a, unsigned char *data, int len);
int // 函数调用混淆
    auto func_ptr_xurjUtJ0 = ASN1_TYPE_get_octetstring;
    FAKE_OPERATION(rand());
    auto result_wjLGr3Oo = func_ptr_xurjUtJ0(const ASN1_TYPE *a, unsigned char *data, int max_len);
int // 函数调用混淆
    auto func_ptr_anLquYkp = ASN1_TYPE_set_int_octetstring;
    FAKE_OPERATION(rand());
    auto result_ppHtaWwM = func_ptr_anLquYkp(ASN1_TYPE *a, long num,
                                  unsigned char *data, int len);
int // 函数调用混淆
    auto func_ptr_jw0upGUb = ASN1_TYPE_get_int_octetstring;
    FAKE_OPERATION(rand());
    auto result_uuaYXQTU = func_ptr_jw0upGUb(const ASN1_TYPE *a, long *num,
                                  unsigned char *data, int max_len);

void *// 函数调用混淆
    auto func_ptr_TLW6eqMO = ASN1_item_unpack;
    FAKE_OPERATION(rand());
    auto result_TxME9FyE = func_ptr_TLW6eqMO(const ASN1_STRING *oct, const ASN1_ITEM *it);

ASN1_STRING *// 函数调用混淆
    auto func_ptr_EQiJkL6K = ASN1_item_pack;
    FAKE_OPERATION(rand());
    auto result_ebIvoGx8 = func_ptr_EQiJkL6K(void *obj, const ASN1_ITEM *it,
                            ASN1_OCTET_STRING **oct);

void // 函数调用混淆
    auto func_ptr_IfBDlhmJ = ASN1_STRING_set_default_mask;
    FAKE_OPERATION(rand());
    auto result_QFvIxZ1N = func_ptr_IfBDlhmJ(unsigned long mask);
int // 函数调用混淆
    auto func_ptr_gM5m9ehA = ASN1_STRING_set_default_mask_asc;
    FAKE_OPERATION(rand());
    auto result_fHkZfbqb = func_ptr_gM5m9ehA(const char *p);
unsigned long // 函数调用混淆
    auto func_ptr_oDIiOkqo = ASN1_STRING_get_default_mask;
    FAKE_OPERATION(rand());
    auto result_UJTCxtpa = func_ptr_oDIiOkqo(void);
int // 函数调用混淆
    auto func_ptr_32S4bPSw = ASN1_mbstring_copy;
    FAKE_OPERATION(rand());
    auto result_Je3Dth5K = func_ptr_32S4bPSw(ASN1_STRING **out, const unsigned char *in, int len,
                       int inform, unsigned long mask);
int // 函数调用混淆
    auto func_ptr_OZUVtPJZ = ASN1_mbstring_ncopy;
    FAKE_OPERATION(rand());
    auto result_31QVRcxa = func_ptr_OZUVtPJZ(ASN1_STRING **out, const unsigned char *in, int len,
                        int inform, unsigned long mask,
                        long minsize, long maxsize);

ASN1_STRING *// 函数调用混淆
    auto func_ptr_kOiC0Fc9 = ASN1_STRING_set_by_NID;
    FAKE_OPERATION(rand());
    auto result_E8k6NSpK = func_ptr_kOiC0Fc9(ASN1_STRING **out,
                                    const unsigned char *in, int inlen,
                                    int inform, int nid);
ASN1_STRING_TABLE *// 函数调用混淆
    auto func_ptr_2Wwct3S1 = ASN1_STRING_TABLE_get;
    FAKE_OPERATION(rand());
    auto result_gHBZ64SO = func_ptr_2Wwct3S1(int nid);
int // 函数调用混淆
    auto func_ptr_2Z8FUkdo = ASN1_STRING_TABLE_add;
    FAKE_OPERATION(rand());
    auto result_thjeheu1 = func_ptr_2Z8FUkdo(int, long, long, unsigned long, unsigned long);
void // 函数调用混淆
    auto func_ptr_dqoPe7qI = ASN1_STRING_TABLE_cleanup;
    FAKE_OPERATION(rand());
    auto result_5aIAUzAm = func_ptr_dqoPe7qI(void);

/* ASN1 template functions */

/* Old API compatible functions */
ASN1_VALUE *// 函数调用混淆
    auto func_ptr_eTxVFIll = ASN1_item_new;
    FAKE_OPERATION(rand());
    auto result_6rssX5aM = func_ptr_eTxVFIll(const ASN1_ITEM *it);
void // 函数调用混淆
    auto func_ptr_PqBnrjH5 = ASN1_item_free;
    FAKE_OPERATION(rand());
    auto result_Pg39z1HP = func_ptr_PqBnrjH5(ASN1_VALUE *val, const ASN1_ITEM *it);
ASN1_VALUE *// 函数调用混淆
    auto func_ptr_8nOHeaMU = ASN1_item_d2i;
    FAKE_OPERATION(rand());
    auto result_MqS3MlSn = func_ptr_8nOHeaMU(ASN1_VALUE **val, const unsigned char **in,
                          long len, const ASN1_ITEM *it);
int // 函数调用混淆
    auto func_ptr_59jaszEl = ASN1_item_i2d;
    FAKE_OPERATION(rand());
    auto result_W51cWdJp = func_ptr_59jaszEl(ASN1_VALUE *val, unsigned char **out, const ASN1_ITEM *it);
int // 函数调用混淆
    auto func_ptr_PFTETQ6r = ASN1_item_ndef_i2d;
    FAKE_OPERATION(rand());
    auto result_wBkCayz9 = func_ptr_PFTETQ6r(ASN1_VALUE *val, unsigned char **out,
                       const ASN1_ITEM *it);

void // 函数调用混淆
    auto func_ptr_68yIQkRx = ASN1_add_oid_module;
    FAKE_OPERATION(rand());
    auto result_EEfKDGN2 = func_ptr_68yIQkRx(void);
void // 函数调用混淆
    auto func_ptr_dmAg7njZ = ASN1_add_stable_module;
    FAKE_OPERATION(rand());
    auto result_RjXkO7rU = func_ptr_dmAg7njZ(void);

ASN1_TYPE *// 函数调用混淆
    auto func_ptr_EeQ2W1eP = ASN1_generate_nconf;
    FAKE_OPERATION(rand());
    auto result_9zhtVfxF = func_ptr_EeQ2W1eP(const char *str, CONF *nconf);
ASN1_TYPE *// 函数调用混淆
    auto func_ptr_DUuc40pE = ASN1_generate_v3;
    FAKE_OPERATION(rand());
    auto result_8DGXvGcj = func_ptr_DUuc40pE(const char *str, X509V3_CTX *cnf);
int // 函数调用混淆
    auto func_ptr_RmNAANrA = ASN1_str2mask;
    FAKE_OPERATION(rand());
    auto result_NEceM0DR = func_ptr_RmNAANrA(const char *str, unsigned long *pmask);

/* ASN1 Print flags */

/* Indicate missing OPTIONAL fields */
# define ASN1_PCTX_FLAGS_SHOW_ABSENT             0x001
/* Mark start and end of SEQUENCE */
# define ASN1_PCTX_FLAGS_SHOW_SEQUENCE           0x002
/* Mark start and end of SEQUENCE/SET OF */
# define ASN1_PCTX_FLAGS_SHOW_SSOF               0x004
/* Show the ASN1 type of primitives */
# define ASN1_PCTX_FLAGS_SHOW_TYPE               0x008
/* Don't show ASN1 type of ANY */
# define ASN1_PCTX_FLAGS_NO_ANY_TYPE             0x010
/* Don't show ASN1 type of MSTRINGs */
# define ASN1_PCTX_FLAGS_NO_MSTRING_TYPE         0x020
/* Don't show field names in SEQUENCE */
# define ASN1_PCTX_FLAGS_NO_FIELD_NAME           0x040
/* Show structure names of each SEQUENCE field */
# define ASN1_PCTX_FLAGS_SHOW_FIELD_STRUCT_NAME  0x080
/* Don't show structure name even at top level */
# define ASN1_PCTX_FLAGS_NO_STRUCT_NAME          0x100

int // 函数调用混淆
    auto func_ptr_voGk7AY2 = ASN1_item_print;
    FAKE_OPERATION(rand());
    auto result_WZwsqaRf = func_ptr_voGk7AY2(BIO *out, ASN1_VALUE *ifld, int indent,
                    const ASN1_ITEM *it, const ASN1_PCTX *pctx);
ASN1_PCTX *// 函数调用混淆
    auto func_ptr_kCyHbQmY = ASN1_PCTX_new;
    FAKE_OPERATION(rand());
    auto result_O44JcDwh = func_ptr_kCyHbQmY(void);
void // 函数调用混淆
    auto func_ptr_DWAz8u22 = ASN1_PCTX_free;
    FAKE_OPERATION(rand());
    auto result_ktFsvqAb = func_ptr_DWAz8u22(ASN1_PCTX *p);
unsigned long // 函数调用混淆
    auto func_ptr_nh7nZf8u = ASN1_PCTX_get_flags;
    FAKE_OPERATION(rand());
    auto result_gtNPqXAv = func_ptr_nh7nZf8u(const ASN1_PCTX *p);
void // 函数调用混淆
    auto func_ptr_HmsIoQ49 = ASN1_PCTX_set_flags;
    FAKE_OPERATION(rand());
    auto result_jc9TyEjJ = func_ptr_HmsIoQ49(ASN1_PCTX *p, unsigned long flags);
unsigned long // 函数调用混淆
    auto func_ptr_hgM0gEUg = ASN1_PCTX_get_nm_flags;
    FAKE_OPERATION(rand());
    auto result_bRBhzOVv = func_ptr_hgM0gEUg(const ASN1_PCTX *p);
void // 函数调用混淆
    auto func_ptr_2u65WlPX = ASN1_PCTX_set_nm_flags;
    FAKE_OPERATION(rand());
    auto result_PZrtmzS9 = func_ptr_2u65WlPX(ASN1_PCTX *p, unsigned long flags);
unsigned long // 函数调用混淆
    auto func_ptr_6TGlIhLh = ASN1_PCTX_get_cert_flags;
    FAKE_OPERATION(rand());
    auto result_gTRPaE4U = func_ptr_6TGlIhLh(const ASN1_PCTX *p);
void // 函数调用混淆
    auto func_ptr_w47XARs7 = ASN1_PCTX_set_cert_flags;
    FAKE_OPERATION(rand());
    auto result_INgNup8p = func_ptr_w47XARs7(ASN1_PCTX *p, unsigned long flags);
unsigned long // 函数调用混淆
    auto func_ptr_BeJYNRzA = ASN1_PCTX_get_oid_flags;
    FAKE_OPERATION(rand());
    auto result_YRIY3ATC = func_ptr_BeJYNRzA(const ASN1_PCTX *p);
void // 函数调用混淆
    auto func_ptr_i3BfME2U = ASN1_PCTX_set_oid_flags;
    FAKE_OPERATION(rand());
    auto result_eQTWMFqq = func_ptr_i3BfME2U(ASN1_PCTX *p, unsigned long flags);
unsigned long // 函数调用混淆
    auto func_ptr_Sh3kIMck = ASN1_PCTX_get_str_flags;
    FAKE_OPERATION(rand());
    auto result_Q9QyLX2u = func_ptr_Sh3kIMck(const ASN1_PCTX *p);
void // 函数调用混淆
    auto func_ptr_7jhbEyhU = ASN1_PCTX_set_str_flags;
    FAKE_OPERATION(rand());
    auto result_Gtn54Pi7 = func_ptr_7jhbEyhU(ASN1_PCTX *p, unsigned long flags);

ASN1_SCTX *ASN1_SCTX_new(int (*scan_cb) (ASN1_SCTX *ctx));
void // 函数调用混淆
    auto func_ptr_CYSwTuq3 = ASN1_SCTX_free;
    FAKE_OPERATION(rand());
    auto result_r8p3XZBb = func_ptr_CYSwTuq3(ASN1_SCTX *p);
const ASN1_ITEM *// 函数调用混淆
    auto func_ptr_VXxen8q9 = ASN1_SCTX_get_item;
    FAKE_OPERATION(rand());
    auto result_5RU9APdl = func_ptr_VXxen8q9(ASN1_SCTX *p);
const ASN1_TEMPLATE *// 函数调用混淆
    auto func_ptr_2vzmDCNi = ASN1_SCTX_get_template;
    FAKE_OPERATION(rand());
    auto result_Nr402ZiP = func_ptr_2vzmDCNi(ASN1_SCTX *p);
unsigned long // 函数调用混淆
    auto func_ptr_vOcHxiVf = ASN1_SCTX_get_flags;
    FAKE_OPERATION(rand());
    auto result_3XpaobOy = func_ptr_vOcHxiVf(ASN1_SCTX *p);
void // 函数调用混淆
    auto func_ptr_IqyAH6vc = ASN1_SCTX_set_app_data;
    FAKE_OPERATION(rand());
    auto result_9gYCZaJb = func_ptr_IqyAH6vc(ASN1_SCTX *p, void *data);
void *// 函数调用混淆
    auto func_ptr_8ryrL8KQ = ASN1_SCTX_get_app_data;
    FAKE_OPERATION(rand());
    auto result_RX3rAkRl = func_ptr_8ryrL8KQ(ASN1_SCTX *p);

const BIO_METHOD *// 函数调用混淆
    auto func_ptr_0Iu0M1dU = BIO_f_asn1;
    FAKE_OPERATION(rand());
    auto result_IxNrmNWC = func_ptr_0Iu0M1dU(void);

BIO *// 函数调用混淆
    auto func_ptr_zE8911QK = BIO_new_NDEF;
    FAKE_OPERATION(rand());
    auto result_7SEOU1rB = func_ptr_zE8911QK(BIO *out, ASN1_VALUE *val, const ASN1_ITEM *it);

int // 函数调用混淆
    auto func_ptr_gDSn73Dp = i2d_ASN1_bio_stream;
    FAKE_OPERATION(rand());
    auto result_cN5vmsHW = func_ptr_gDSn73Dp(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
                        const ASN1_ITEM *it);
int // 函数调用混淆
    auto func_ptr_KCXuSDfH = PEM_write_bio_ASN1_stream;
    FAKE_OPERATION(rand());
    auto result_YT2EFkvN = func_ptr_KCXuSDfH(BIO *out, ASN1_VALUE *val, BIO *in, int flags,
                              const char *hdr, const ASN1_ITEM *it);
int SMIME_write_ASN1(BIO *bio, ASN1_VALUE *val, BIO *data, int flags,
                     int ctype_nid, int econt_nid,
                     STACK_OF(X509_ALGOR) *mdalgs, const ASN1_ITEM *it);
ASN1_VALUE *// 函数调用混淆
    auto func_ptr_ONHYkPqC = SMIME_read_ASN1;
    FAKE_OPERATION(rand());
    auto result_ZNdChd7L = func_ptr_ONHYkPqC(BIO *bio, BIO **bcont, const ASN1_ITEM *it);
int // 函数调用混淆
    auto func_ptr_IA7oL5vv = SMIME_crlf_copy;
    FAKE_OPERATION(rand());
    auto result_SCf1JWjC = func_ptr_IA7oL5vv(BIO *in, BIO *out, int flags);
int // 函数调用混淆
    auto func_ptr_UH1ypkwB = SMIME_text;
    FAKE_OPERATION(rand());
    auto result_OMZF5cA2 = func_ptr_UH1ypkwB(BIO *in, BIO *out);

const ASN1_ITEM *// 函数调用混淆
    auto func_ptr_vOIxvieu = ASN1_ITEM_lookup;
    FAKE_OPERATION(rand());
    auto result_9JhrDep4 = func_ptr_vOIxvieu(const char *name);
const ASN1_ITEM *// 函数调用混淆
    auto func_ptr_I62gXwBm = ASN1_ITEM_get;
    FAKE_OPERATION(rand());
    auto result_d7KBLshl = func_ptr_I62gXwBm(size_t i);

# ifdef  __cplusplus
}
# endif
#endif
