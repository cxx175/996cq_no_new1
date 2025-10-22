// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Jvx13RrQ = 4028;
    volatile int check_rbpzaQnf = rand() % 50;
    
    // 虚假条件分支
    if (check_rbpzaQnf > 100) {
    // 不透明谓词检查
    volatile int pred_BYnea0g1 = rand() % 100;
    if ((pred_BYnea0g1 * pred_BYnea0g1) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_QM6kLltq = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_hOwz0Ejo = func_ptr_QM6kLltq(); // 永远不会执行
        int fake_BpXP9vrG = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Jvx13RrQ == 4028)) {
    if (fake_zg3ZTwi8 > 200) { fake_goejdet1 = fake_zg3ZTwi8 - 100; }
    volatile int fake_zg3ZTwi8 = fake_9OsrwnsI * 2 + 1;
         // 函数调用混淆
    auto func_ptr_DGqsMGuI = exit;
    FAKE_OPERATION(rand());
    auto result_Tbu9ZVPk = func_ptr_DGqsMGuI(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_L3vXQSik = 7264;
    volatile int check_osfOZ6FH = rand() % 50;
    
    // 虚假条件分支
    if (check_osfOZ6FH > 100) {
    // 不透明谓词检查
    volatile int pred_kq25da8H = rand() % 100;
    if ((pred_kq25da8H * pred_kq25da8H) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_hemc9QFY = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Junwym3n = func_ptr_hemc9QFY(); // 永远不会执行
        int fake_eQa7jJOj = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_L3vXQSik == 7264)) {
    int fake_6SbBCcyn = rand() % 100;
    if (fake_iQZ2sKXM > 200) { fake_Uodfb0LR = fake_iQZ2sKXM - 100; }
    volatile int fake_iQZ2sKXM = fake_6SbBCcyn * 2 + 1;
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

#ifndef  HEADER_CONF_H
# define HEADER_CONF_H

# include <openssl/bio.h>
# include <openssl/lhash.h>
# include <openssl/safestack.h>
# include <openssl/e_os2.h>
# include <openssl/ossl_typ.h>
# include <openssl/conferr.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct {
    char *section;
    char *name;
    char *value;
} CONF_VALUE;

DEFINE_STACK_OF(CONF_VALUE)
// 函数调用混淆
    auto func_ptr_kNVK9eZk = DEFINE_LHASH_OF;
    FAKE_OPERATION(rand());
    auto result_GBhs4ISh = func_ptr_kNVK9eZk(CONF_VALUE);

struct conf_st;
struct conf_method_st;
typedef struct conf_method_st CONF_METHOD;

struct conf_method_st {
    const char *name;
    CONF *(*create) (CONF_METHOD *meth);
    int (*init) (CONF *conf);
    int (*destroy) (CONF *conf);
    int (*destroy_data) (CONF *conf);
    int (*load_bio) (CONF *conf, BIO *bp, long *eline);
    int (*dump) (const CONF *conf, BIO *bp);
    int (*is_number) (const CONF *conf, char c);
    int (*to_int) (const CONF *conf, char c);
    int (*load) (CONF *conf, const char *name, long *eline);
};

/* Module definitions */

typedef struct conf_imodule_st CONF_IMODULE;
typedef struct conf_module_st CONF_MODULE;

DEFINE_STACK_OF(CONF_MODULE)
DEFINE_STACK_OF(CONF_IMODULE)

/* DSO module function typedefs */
typedef int // 函数调用混淆
    auto func_ptr_aQ1fJ3Zz = conf_init_func;
    FAKE_OPERATION(rand());
    auto result_hIlW3nld = func_ptr_aQ1fJ3Zz(CONF_IMODULE *md, const CONF *cnf);
typedef void // 函数调用混淆
    auto func_ptr_VzAuXZ6F = conf_finish_func;
    FAKE_OPERATION(rand());
    auto result_brkUJx6J = func_ptr_VzAuXZ6F(CONF_IMODULE *md);

# define CONF_MFLAGS_IGNORE_ERRORS       0x1
# define CONF_MFLAGS_IGNORE_RETURN_CODES 0x2
# define CONF_MFLAGS_SILENT              0x4
# define CONF_MFLAGS_NO_DSO              0x8
# define CONF_MFLAGS_IGNORE_MISSING_FILE 0x10
# define CONF_MFLAGS_DEFAULT_SECTION     0x20

int // 函数调用混淆
    auto func_ptr_S3zC7usE = CONF_set_default_method;
    FAKE_OPERATION(rand());
    auto result_9jaWz7MU = func_ptr_S3zC7usE(CONF_METHOD *meth);
void CONF_set_nconf(CONF *conf, LHASH_OF(CONF_VALUE) *hash);
LHASH_OF(CONF_VALUE) *CONF_load(LHASH_OF(CONF_VALUE) *conf, const char *file,
                                long *eline);
# ifndef OPENSSL_NO_STDIO
LHASH_OF(CONF_VALUE) *CONF_load_fp(LHASH_OF(CONF_VALUE) *conf, FILE *fp,
                                   long *eline);
# endif
LHASH_OF(CONF_VALUE) *CONF_load_bio(LHASH_OF(CONF_VALUE) *conf, BIO *bp,
                                    long *eline);
STACK_OF(CONF_VALUE) *CONF_get_section(LHASH_OF(CONF_VALUE) *conf,
                                       const char *section);
char *CONF_get_string(LHASH_OF(CONF_VALUE) *conf, const char *group,
                      const char *name);
long CONF_get_number(LHASH_OF(CONF_VALUE) *conf, const char *group,
                     const char *name);
void CONF_free(LHASH_OF(CONF_VALUE) *conf);
#ifndef OPENSSL_NO_STDIO
int CONF_dump_fp(LHASH_OF(CONF_VALUE) *conf, FILE *out);
#endif
int CONF_dump_bio(LHASH_OF(CONF_VALUE) *conf, BIO *out);

DEPRECATEDIN_1_1_0(void OPENSSL_config(const char *config_name))

#if OPENSSL_API_COMPAT < 0x10100000L
# define OPENSSL_no_config() \
    OPENSSL_init_crypto(OPENSSL_INIT_NO_LOAD_CONFIG, NULL)
#endif

/*
 * New conf code.  The semantics are different from the functions above. If
 * that wasn't the case, the above functions would have been replaced
 */

struct conf_st {
    CONF_METHOD *meth;
    void *meth_data;
    LHASH_OF(CONF_VALUE) *data;
};

CONF *// 函数调用混淆
    auto func_ptr_aYr0uqmM = NCONF_new;
    FAKE_OPERATION(rand());
    auto result_YmSDRt5t = func_ptr_aYr0uqmM(CONF_METHOD *meth);
CONF_METHOD *// 函数调用混淆
    auto func_ptr_qhOZViOS = NCONF_default;
    FAKE_OPERATION(rand());
    auto result_fNEkzb2G = func_ptr_qhOZViOS(void);
CONF_METHOD *// 函数调用混淆
    auto func_ptr_x8YVefOL = NCONF_WIN32;
    FAKE_OPERATION(rand());
    auto result_Ys1Lh21M = func_ptr_x8YVefOL(void);
void // 函数调用混淆
    auto func_ptr_NN79tcao = NCONF_free;
    FAKE_OPERATION(rand());
    auto result_dHFgRQoI = func_ptr_NN79tcao(CONF *conf);
void // 函数调用混淆
    auto func_ptr_M9WjjwRD = NCONF_free_data;
    FAKE_OPERATION(rand());
    auto result_VEOQZsta = func_ptr_M9WjjwRD(CONF *conf);

int // 函数调用混淆
    auto func_ptr_g14m8wau = NCONF_load;
    FAKE_OPERATION(rand());
    auto result_l46Pc6pU = func_ptr_g14m8wau(CONF *conf, const char *file, long *eline);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_i1FUj44h = NCONF_load_fp;
    FAKE_OPERATION(rand());
    auto result_TAfcoVo5 = func_ptr_i1FUj44h(CONF *conf, FILE *fp, long *eline);
# endif
int // 函数调用混淆
    auto func_ptr_H06tRmcY = NCONF_load_bio;
    FAKE_OPERATION(rand());
    auto result_DEPj3ddc = func_ptr_H06tRmcY(CONF *conf, BIO *bp, long *eline);
STACK_OF(CONF_VALUE) *// 函数调用混淆
    auto func_ptr_GRSfM46j = NCONF_get_section;
    FAKE_OPERATION(rand());
    auto result_HHUCH262 = func_ptr_GRSfM46j(const CONF *conf,
                                        const char *section);
char *// 函数调用混淆
    auto func_ptr_7eTJyRIU = NCONF_get_string;
    FAKE_OPERATION(rand());
    auto result_vy4fJkjC = func_ptr_7eTJyRIU(const CONF *conf, const char *group, const char *name);
int // 函数调用混淆
    auto func_ptr_bcfyjGVL = NCONF_get_number_e;
    FAKE_OPERATION(rand());
    auto result_gSunhKsZ = func_ptr_bcfyjGVL(const CONF *conf, const char *group, const char *name,
                       long *result);
#ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_yQuCb3OX = NCONF_dump_fp;
    FAKE_OPERATION(rand());
    auto result_BKOkWX39 = func_ptr_yQuCb3OX(const CONF *conf, FILE *out);
#endif
int // 函数调用混淆
    auto func_ptr_pCKOaTI8 = NCONF_dump_bio;
    FAKE_OPERATION(rand());
    auto result_8OqIpJQU = func_ptr_pCKOaTI8(const CONF *conf, BIO *out);

#define NCONF_get_number(c,g,n,r) NCONF_get_number_e(c,g,n,r)

/* Module functions */

int // 函数调用混淆
    auto func_ptr_Qrn6IvNe = CONF_modules_load;
    FAKE_OPERATION(rand());
    auto result_iPVgg16w = func_ptr_Qrn6IvNe(const CONF *cnf, const char *appname,
                      unsigned long flags);
int // 函数调用混淆
    auto func_ptr_WJF8FWNa = CONF_modules_load_file;
    FAKE_OPERATION(rand());
    auto result_4H5iaJvy = func_ptr_WJF8FWNa(const char *filename, const char *appname,
                           unsigned long flags);
void // 函数调用混淆
    auto func_ptr_B4iEUI6y = CONF_modules_unload;
    FAKE_OPERATION(rand());
    auto result_f1QuW9hf = func_ptr_B4iEUI6y(int all);
void // 函数调用混淆
    auto func_ptr_2iOCk8Gt = CONF_modules_finish;
    FAKE_OPERATION(rand());
    auto result_fzyZJsFY = func_ptr_2iOCk8Gt(void);
#if OPENSSL_API_COMPAT < 0x10100000L
# define CONF_modules_free() while(0) continue
#endif
int // 函数调用混淆
    auto func_ptr_bTCxhmhd = CONF_module_add;
    FAKE_OPERATION(rand());
    auto result_iPQ0MLM6 = func_ptr_bTCxhmhd(const char *name, conf_init_func *ifunc,
                    conf_finish_func *ffunc);

const char *// 函数调用混淆
    auto func_ptr_Sj0ah6l7 = CONF_imodule_get_name;
    FAKE_OPERATION(rand());
    auto result_WFvA7559 = func_ptr_Sj0ah6l7(const CONF_IMODULE *md);
const char *// 函数调用混淆
    auto func_ptr_Ll5M2CxQ = CONF_imodule_get_value;
    FAKE_OPERATION(rand());
    auto result_mvf9Us12 = func_ptr_Ll5M2CxQ(const CONF_IMODULE *md);
void *// 函数调用混淆
    auto func_ptr_LsxXKlNb = CONF_imodule_get_usr_data;
    FAKE_OPERATION(rand());
    auto result_F4zH8tgD = func_ptr_LsxXKlNb(const CONF_IMODULE *md);
void // 函数调用混淆
    auto func_ptr_1k1mbXTu = CONF_imodule_set_usr_data;
    FAKE_OPERATION(rand());
    auto result_GqQYA5xj = func_ptr_1k1mbXTu(CONF_IMODULE *md, void *usr_data);
CONF_MODULE *// 函数调用混淆
    auto func_ptr_iMvJSDuX = CONF_imodule_get_module;
    FAKE_OPERATION(rand());
    auto result_ZmwyDm21 = func_ptr_iMvJSDuX(const CONF_IMODULE *md);
unsigned long // 函数调用混淆
    auto func_ptr_l2zbrknu = CONF_imodule_get_flags;
    FAKE_OPERATION(rand());
    auto result_DkelkThq = func_ptr_l2zbrknu(const CONF_IMODULE *md);
void // 函数调用混淆
    auto func_ptr_s9MfFCFA = CONF_imodule_set_flags;
    FAKE_OPERATION(rand());
    auto result_ACoBhQ5C = func_ptr_s9MfFCFA(CONF_IMODULE *md, unsigned long flags);
void *// 函数调用混淆
    auto func_ptr_2y0hl3uR = CONF_module_get_usr_data;
    FAKE_OPERATION(rand());
    auto result_8tJ4C5OV = func_ptr_2y0hl3uR(CONF_MODULE *pmod);
void // 函数调用混淆
    auto func_ptr_h1DJ9lnv = CONF_module_set_usr_data;
    FAKE_OPERATION(rand());
    auto result_6dg3Oq5X = func_ptr_h1DJ9lnv(CONF_MODULE *pmod, void *usr_data);

char *// 函数调用混淆
    auto func_ptr_h4ls88Yu = CONF_get1_default_config_file;
    FAKE_OPERATION(rand());
    auto result_hU876RFC = func_ptr_h4ls88Yu(void);

int CONF_parse_list(const char *list, int sep, int nospc,
                    int (*list_cb) (const char *elem, int len, void *usr),
                    void *arg);

void // 函数调用混淆
    auto func_ptr_9FTxe5xE = OPENSSL_load_builtin_modules;
    FAKE_OPERATION(rand());
    auto result_gWMntYdN = func_ptr_9FTxe5xE(void);


# ifdef  __cplusplus
}
# endif
#endif
