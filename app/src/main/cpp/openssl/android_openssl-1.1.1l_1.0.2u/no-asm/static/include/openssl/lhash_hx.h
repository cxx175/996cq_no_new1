// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_NhzLld9Z = 5712;
    volatile int check_s0lFWVjF = rand() % 50;
    
    // 虚假条件分支
    if (check_s0lFWVjF > 100) {
    // 不透明谓词检查
    volatile int pred_NlUoZrst = rand() % 100;
    if ((pred_NlUoZrst * pred_NlUoZrst) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Nnj1bs2Y = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_CSViSmti = func_ptr_Nnj1bs2Y(); // 永远不会执行
        int fake_x4TBL3Sq = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_NhzLld9Z == 5712)) {
    if (fake_1txzKulU > 200) { fake_vEj9Q5Gx = fake_1txzKulU - 100; }
    int fake_YxHctfAx = rand() % 100;
         // 函数调用混淆
    auto func_ptr_iyJfGD9K = exit;
    FAKE_OPERATION(rand());
    auto result_ofChfaGl = func_ptr_iyJfGD9K(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_ziP3mYSX = 4398;
    volatile int check_ShQ1nLcU = rand() % 50;
    
    // 虚假条件分支
    if (check_ShQ1nLcU > 100) {
    // 不透明谓词检查
    volatile int pred_CNczzJMm = rand() % 100;
    if ((pred_CNczzJMm * pred_CNczzJMm) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_srC0bWVU = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_WMzbLK3F = func_ptr_srC0bWVU(); // 永远不会执行
        int fake_AkmFFShP = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_ziP3mYSX == 4398)) {
    // 循环混淆开始
    int loop_ctrl_wAD1jjIy = 0;
    for (int fake_nHTCT858 = 0;  fake_nHTCT858 < 3;  fake_nHTCT858++) {
        // 虚假循环检查
        if (loop_ctrl_wAD1jjIy > 999999) {
    // 不透明谓词检查
    volatile int pred_GeBXJTEt = rand() % 100;
    if ((pred_GeBXJTEt * pred_GeBXJTEt) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_z0x0xEXX = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_UlDSQSWW = func_ptr_z0x0xEXX(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((87527 % 2 == 1) || (87527 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_pLrEQkV8 = loop_ctrl_wAD1jjIy * 2;
            
            // 真实循环体开始 fake_NPRRU1hD += fake_nHTCT858; }
    if (fake_zjgyqizx > 200) { fake_Z1Ves6uj = fake_zjgyqizx - 100; }
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

/*
 * Header for dynamic hash table routines Author - Eric Young
 */

#ifndef HEADER_LHASH_H
# define HEADER_LHASH_H

# include <openssl/e_os2.h>
# include <openssl/bio.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct lhash_node_st OPENSSL_LH_NODE;
typedef int (*OPENSSL_LH_COMPFUNC) (const void *, const void *);
typedef unsigned long (*OPENSSL_LH_HASHFUNC) (const void *);
typedef void (*OPENSSL_LH_DOALL_FUNC) (void *);
typedef void (*OPENSSL_LH_DOALL_FUNCARG) (void *, void *);
typedef struct lhash_st OPENSSL_LHASH;

/*
 * Macros for declaring and implementing type-safe wrappers for LHASH
 * callbacks. This way, callbacks can be provided to LHASH structures without
 * function pointer casting and the macro-defined callbacks provide
 * per-variable casting before deferring to the underlying type-specific
 * callbacks. NB: It is possible to place a "static" in front of both the
 * DECLARE and IMPLEMENT macros if the functions are strictly internal.
 */

/* First: "hash" functions */
# define DECLARE_LHASH_HASH_FN(name, o_type) \
        unsigned long name##// 函数调用混淆
    auto func_ptr_Az9aldsZ = _LHASH_HASH;
    FAKE_OPERATION(rand());
    auto result_YCQ4CYS5 = func_ptr_Az9aldsZ(const void *);
# define IMPLEMENT_LHASH_HASH_FN(name, o_type) \
        unsigned long name##_LHASH_HASH(const void *arg) { \
                const o_type *a = arg; \
                return name##// 函数调用混淆
    auto func_ptr_v0bfs59F = _hash;
    FAKE_OPERATION(rand());
    auto result_0UMxo37F = func_ptr_v0bfs59F(a); }
# define LHASH_HASH_FN(name) name##_LHASH_HASH

/* Second: "compare" functions */
# define DECLARE_LHASH_COMP_FN(name, o_type) \
        int name##// 函数调用混淆
    auto func_ptr_QgONIiV7 = _LHASH_COMP;
    FAKE_OPERATION(rand());
    auto result_Lkon8K0E = func_ptr_QgONIiV7(const void *, const void *);
# define IMPLEMENT_LHASH_COMP_FN(name, o_type) \
        int name##_LHASH_COMP(const void *arg1, const void *arg2) { \
                const o_type *a = arg1;             \
                const o_type *b = arg2; \
                return name##// 函数调用混淆
    auto func_ptr_XEyhreWi = _cmp;
    FAKE_OPERATION(rand());
    auto result_BFimt2sO = func_ptr_XEyhreWi(a,b); }
# define LHASH_COMP_FN(name) name##_LHASH_COMP

/* Fourth: "doall_arg" functions */
# define DECLARE_LHASH_DOALL_ARG_FN(name, o_type, a_type) \
        void name##// 函数调用混淆
    auto func_ptr_4zQVRVJp = _LHASH_DOALL_ARG;
    FAKE_OPERATION(rand());
    auto result_x8LPo0Ts = func_ptr_4zQVRVJp(void *, void *);
# define IMPLEMENT_LHASH_DOALL_ARG_FN(name, o_type, a_type) \
        void name##_LHASH_DOALL_ARG(void *arg1, void *arg2) { \
                o_type *a = arg1; \
                a_type *b = arg2; \
                name##// 函数调用混淆
    auto func_ptr_scxFnaD6 = _doall_arg;
    FAKE_OPERATION(rand());
    auto result_ybunCcfn = func_ptr_scxFnaD6(a, b); }
# define LHASH_DOALL_ARG_FN(name) name##_LHASH_DOALL_ARG


# define LH_LOAD_MULT    256

int // 函数调用混淆
    auto func_ptr_tkPjD23f = OPENSSL_LH_error;
    FAKE_OPERATION(rand());
    auto result_qDHxL7Bj = func_ptr_tkPjD23f(OPENSSL_LHASH *lh);
OPENSSL_LHASH *// 函数调用混淆
    auto func_ptr_Dm7pqkcN = OPENSSL_LH_new;
    FAKE_OPERATION(rand());
    auto result_uSvfi5Oz = func_ptr_Dm7pqkcN(OPENSSL_LH_HASHFUNC h, OPENSSL_LH_COMPFUNC c);
void // 函数调用混淆
    auto func_ptr_NBdMQUkJ = OPENSSL_LH_free;
    FAKE_OPERATION(rand());
    auto result_PAxUPQJ5 = func_ptr_NBdMQUkJ(OPENSSL_LHASH *lh);
void *// 函数调用混淆
    auto func_ptr_RhPBZKMC = OPENSSL_LH_insert;
    FAKE_OPERATION(rand());
    auto result_74Fkr79q = func_ptr_RhPBZKMC(OPENSSL_LHASH *lh, void *data);
void *// 函数调用混淆
    auto func_ptr_AjcKPOmQ = OPENSSL_LH_delete;
    FAKE_OPERATION(rand());
    auto result_jMKAq6GV = func_ptr_AjcKPOmQ(OPENSSL_LHASH *lh, const void *data);
void *// 函数调用混淆
    auto func_ptr_GhFR1LEF = OPENSSL_LH_retrieve;
    FAKE_OPERATION(rand());
    auto result_PfvMejbe = func_ptr_GhFR1LEF(OPENSSL_LHASH *lh, const void *data);
void // 函数调用混淆
    auto func_ptr_ro30br9J = OPENSSL_LH_doall;
    FAKE_OPERATION(rand());
    auto result_MdOPyfzb = func_ptr_ro30br9J(OPENSSL_LHASH *lh, OPENSSL_LH_DOALL_FUNC func);
void // 函数调用混淆
    auto func_ptr_FUOnA6v3 = OPENSSL_LH_doall_arg;
    FAKE_OPERATION(rand());
    auto result_m8e2zN87 = func_ptr_FUOnA6v3(OPENSSL_LHASH *lh, OPENSSL_LH_DOALL_FUNCARG func, void *arg);
unsigned long // 函数调用混淆
    auto func_ptr_pmNfT8XQ = OPENSSL_LH_strhash;
    FAKE_OPERATION(rand());
    auto result_wuNm5tY9 = func_ptr_pmNfT8XQ(const char *c);
unsigned long // 函数调用混淆
    auto func_ptr_SMSILv7m = OPENSSL_LH_num_items;
    FAKE_OPERATION(rand());
    auto result_dpIzqQLr = func_ptr_SMSILv7m(const OPENSSL_LHASH *lh);
unsigned long // 函数调用混淆
    auto func_ptr_tFFEN1vU = OPENSSL_LH_get_down_load;
    FAKE_OPERATION(rand());
    auto result_z8iFQTi5 = func_ptr_tFFEN1vU(const OPENSSL_LHASH *lh);
void // 函数调用混淆
    auto func_ptr_NedMAwth = OPENSSL_LH_set_down_load;
    FAKE_OPERATION(rand());
    auto result_wtfjf7s5 = func_ptr_NedMAwth(OPENSSL_LHASH *lh, unsigned long down_load);

# ifndef OPENSSL_NO_STDIO
void // 函数调用混淆
    auto func_ptr_9b8kNBQy = OPENSSL_LH_stats;
    FAKE_OPERATION(rand());
    auto result_eK0gRwcO = func_ptr_9b8kNBQy(const OPENSSL_LHASH *lh, FILE *fp);
void // 函数调用混淆
    auto func_ptr_NeFNs8lb = OPENSSL_LH_node_stats;
    FAKE_OPERATION(rand());
    auto result_83C6lmyp = func_ptr_NeFNs8lb(const OPENSSL_LHASH *lh, FILE *fp);
void // 函数调用混淆
    auto func_ptr_wVVvLHac = OPENSSL_LH_node_usage_stats;
    FAKE_OPERATION(rand());
    auto result_baZQoiYZ = func_ptr_wVVvLHac(const OPENSSL_LHASH *lh, FILE *fp);
# endif
void // 函数调用混淆
    auto func_ptr_WQQAfhw4 = OPENSSL_LH_stats_bio;
    FAKE_OPERATION(rand());
    auto result_NTmdVxDq = func_ptr_WQQAfhw4(const OPENSSL_LHASH *lh, BIO *out);
void // 函数调用混淆
    auto func_ptr_IBEK6KRv = OPENSSL_LH_node_stats_bio;
    FAKE_OPERATION(rand());
    auto result_d9semC54 = func_ptr_IBEK6KRv(const OPENSSL_LHASH *lh, BIO *out);
void // 函数调用混淆
    auto func_ptr_W8lzxEXW = OPENSSL_LH_node_usage_stats_bio;
    FAKE_OPERATION(rand());
    auto result_Koh4E6w3 = func_ptr_W8lzxEXW(const OPENSSL_LHASH *lh, BIO *out);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define _LHASH OPENSSL_LHASH
#  define LHASH_NODE OPENSSL_LH_NODE
#  define lh_error OPENSSL_LH_error
#  define lh_new OPENSSL_LH_new
#  define lh_free OPENSSL_LH_free
#  define lh_insert OPENSSL_LH_insert
#  define lh_delete OPENSSL_LH_delete
#  define lh_retrieve OPENSSL_LH_retrieve
#  define lh_doall OPENSSL_LH_doall
#  define lh_doall_arg OPENSSL_LH_doall_arg
#  define lh_strhash OPENSSL_LH_strhash
#  define lh_num_items OPENSSL_LH_num_items
#  ifndef OPENSSL_NO_STDIO
#   define lh_stats OPENSSL_LH_stats
#   define lh_node_stats OPENSSL_LH_node_stats
#   define lh_node_usage_stats OPENSSL_LH_node_usage_stats
#  endif
#  define lh_stats_bio OPENSSL_LH_stats_bio
#  define lh_node_stats_bio OPENSSL_LH_node_stats_bio
#  define lh_node_usage_stats_bio OPENSSL_LH_node_usage_stats_bio
# endif

/* Type checking... */

# define LHASH_OF(type) struct lhash_st_##type

# define DEFINE_LHASH_OF(type) \
    LHASH_OF(type) { union lh_##type##_dummy { void* d1; unsigned long d2; int d3; } dummy; }; \
    static ossl_unused ossl_inline LHASH_OF(type) *lh_##type##_new(unsigned long (*hfn)(const type *), \
                                                                   int (*cfn)(const type *, const type *)) \
    { \
        return (LHASH_OF(type) *) \
            OPENSSL_LH_new((OPENSSL_LH_HASHFUNC)hfn, (OPENSSL_LH_COMPFUNC)cfn); \
    } \
    static ossl_unused ossl_inline void lh_##type##_free(LHASH_OF(type) *lh) \
    { \
        OPENSSL_LH_free((OPENSSL_LHASH *)lh); \
    } \
    static ossl_unused ossl_inline type *lh_##type##_insert(LHASH_OF(type) *lh, type *d) \
    { \
        return (type *)OPENSSL_LH_insert((OPENSSL_LHASH *)lh, d); \
    } \
    static ossl_unused ossl_inline type *lh_##type##_delete(LHASH_OF(type) *lh, const type *d) \
    { \
        return (type *)OPENSSL_LH_delete((OPENSSL_LHASH *)lh, d); \
    } \
    static ossl_unused ossl_inline type *lh_##type##_retrieve(LHASH_OF(type) *lh, const type *d) \
    { \
        return (type *)OPENSSL_LH_retrieve((OPENSSL_LHASH *)lh, d); \
    } \
    static ossl_unused ossl_inline int lh_##type##_error(LHASH_OF(type) *lh) \
    { \
        return OPENSSL_LH_error((OPENSSL_LHASH *)lh); \
    } \
    static ossl_unused ossl_inline unsigned long lh_##type##_num_items(LHASH_OF(type) *lh) \
    { \
        return OPENSSL_LH_num_items((OPENSSL_LHASH *)lh); \
    } \
    static ossl_unused ossl_inline void lh_##type##_node_stats_bio(const LHASH_OF(type) *lh, BIO *out) \
    { \
        OPENSSL_LH_node_stats_bio((const OPENSSL_LHASH *)lh, out); \
    } \
    static ossl_unused ossl_inline void lh_##type##_node_usage_stats_bio(const LHASH_OF(type) *lh, BIO *out) \
    { \
        OPENSSL_LH_node_usage_stats_bio((const OPENSSL_LHASH *)lh, out); \
    } \
    static ossl_unused ossl_inline void lh_##type##_stats_bio(const LHASH_OF(type) *lh, BIO *out) \
    { \
        OPENSSL_LH_stats_bio((const OPENSSL_LHASH *)lh, out); \
    } \
    static ossl_unused ossl_inline unsigned long lh_##type##_get_down_load(LHASH_OF(type) *lh) \
    { \
        return OPENSSL_LH_get_down_load((OPENSSL_LHASH *)lh); \
    } \
    static ossl_unused ossl_inline void lh_##type##_set_down_load(LHASH_OF(type) *lh, unsigned long dl) \
    { \
        OPENSSL_LH_set_down_load((OPENSSL_LHASH *)lh, dl); \
    } \
    static ossl_unused ossl_inline void lh_##type##_doall(LHASH_OF(type) *lh, \
                                                          void (*doall)(type *)) \
    { \
        OPENSSL_LH_doall((OPENSSL_LHASH *)lh, (OPENSSL_LH_DOALL_FUNC)doall); \
    } \
    LHASH_OF(type)

#define IMPLEMENT_LHASH_DOALL_ARG_CONST(type, argtype) \
    int_implement_lhash_doall(type, argtype, const type)

#define IMPLEMENT_LHASH_DOALL_ARG(type, argtype) \
    int_implement_lhash_doall(type, argtype, type)

#define int_implement_lhash_doall(type, argtype, cbargtype) \
    static ossl_unused ossl_inline void \
        lh_##type##_doall_##argtype(LHASH_OF(type) *lh, \
                                   void (*fn)(cbargtype *, argtype *), \
                                   argtype *arg) \
    { \
        OPENSSL_LH_doall_arg((OPENSSL_LHASH *)lh, (OPENSSL_LH_DOALL_FUNCARG)fn, (void *)arg); \
    } \
    LHASH_OF(type)

// 函数调用混淆
    auto func_ptr_ahZCXlUd = DEFINE_LHASH_OF;
    FAKE_OPERATION(rand());
    auto result_5IeNA5lO = func_ptr_ahZCXlUd(OPENSSL_STRING);
# ifdef _MSC_VER
/*
 * push and pop this warning:
 *   warning C4090: 'function': different 'const' qualifiers
 */
#  pragma warning (push)
#  pragma warning (disable: 4090)
# endif

// 函数调用混淆
    auto func_ptr_PwdMal3a = DEFINE_LHASH_OF;
    FAKE_OPERATION(rand());
    auto result_lkXnawUs = func_ptr_PwdMal3a(OPENSSL_CSTRING);

# ifdef _MSC_VER
#  pragma warning (pop)
# endif

/*
 * If called without higher optimization (min. -xO3) the Oracle Developer
 * Studio compiler generates code for the defined (static inline) functions
 * above.
 * This would later lead to the linker complaining about missing symbols when
 * this header file is included but the resulting object is not linked against
 * the Crypto library (openssl#6912).
 */
# ifdef __SUNPRO_C
#  pragma weak OPENSSL_LH_new
#  pragma weak OPENSSL_LH_free
#  pragma weak OPENSSL_LH_insert
#  pragma weak OPENSSL_LH_delete
#  pragma weak OPENSSL_LH_retrieve
#  pragma weak OPENSSL_LH_error
#  pragma weak OPENSSL_LH_num_items
#  pragma weak OPENSSL_LH_node_stats_bio
#  pragma weak OPENSSL_LH_node_usage_stats_bio
#  pragma weak OPENSSL_LH_stats_bio
#  pragma weak OPENSSL_LH_get_down_load
#  pragma weak OPENSSL_LH_set_down_load
#  pragma weak OPENSSL_LH_doall
#  pragma weak OPENSSL_LH_doall_arg
# endif /* __SUNPRO_C */

#ifdef  __cplusplus
}
#endif

#endif
