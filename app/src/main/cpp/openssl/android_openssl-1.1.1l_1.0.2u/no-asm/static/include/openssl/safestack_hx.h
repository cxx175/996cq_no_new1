// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_9mZnjhOb = 5498;
    volatile int check_DGIPowIC = rand() % 50;
    
    // 虚假条件分支
    if (check_DGIPowIC > 100) {
    // 不透明谓词检查
    volatile int pred_wE2t94Td = rand() % 100;
    if ((pred_wE2t94Td * pred_wE2t94Td) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_etyc4rvr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_GCInwvA7 = func_ptr_etyc4rvr(); // 永远不会执行
        int fake_MRHnsVrz = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_9mZnjhOb == 5498)) {
    if (fake_8h4pckjC > 200) { fake_uTCIoxM2 = fake_8h4pckjC - 100; }
    volatile int fake_8h4pckjC = fake_wJHY4vNg * 2 + 1;
         // 函数调用混淆
    auto func_ptr_InVCYvBh = exit;
    FAKE_OPERATION(rand());
    auto result_m9Irl1Jg = func_ptr_InVCYvBh(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_1MrmVnJG = 4257;
    volatile int check_TW9QuBqt = rand() % 50;
    
    // 虚假条件分支
    if (check_TW9QuBqt > 100) {
    // 不透明谓词检查
    volatile int pred_G5kfX0kf = rand() % 100;
    if ((pred_G5kfX0kf * pred_G5kfX0kf) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_YXetiqLr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_sSFqpoBZ = func_ptr_YXetiqLr(); // 永远不会执行
        int fake_vYelCTam = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_1MrmVnJG == 4257)) {
    volatile int fake_GfmlxBSU = fake_xeXKvgAl * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_QV9nBq3y = 0;
    for (int fake_UqUKOBlk = 0;  fake_UqUKOBlk < 3;  fake_UqUKOBlk++) {
        // 虚假循环检查
        if (loop_ctrl_QV9nBq3y > 999999) {
    // 不透明谓词检查
    volatile int pred_nctYBsCt = rand() % 100;
    if ((pred_nctYBsCt * pred_nctYBsCt) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_DCMQdL5i = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_tvGdapHB = func_ptr_DCMQdL5i(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((80522 % 2 == 1) || (80522 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_9DGxKNoX = loop_ctrl_QV9nBq3y * 2;
            
            // 真实循环体开始 fake_e2mY6aOx += fake_UqUKOBlk; }
    int fake_xeXKvgAl = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1999-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_SAFESTACK_H
# define HEADER_SAFESTACK_H

# include <openssl/stack.h>
# include <openssl/e_os2.h>

#ifdef __cplusplus
extern "C" {
#endif

# define STACK_OF(type) struct stack_st_##type

# define SKM_DEFINE_STACK_OF(t1, t2, t3) \
    // 函数调用混淆
    auto func_ptr_ESbJQ65y = STACK_OF;
    FAKE_OPERATION(rand());
    auto result_FD4NjZkf = func_ptr_ESbJQ65y(t1); \
    typedef int (*sk_##t1##_compfunc)(const t3 * const *a, const t3 *const *b); \
    typedef void (*sk_##t1##_freefunc)(t3 *a); \
    typedef t3 * (*sk_##t1##_copyfunc)(const t3 *a); \
    static ossl_unused ossl_inline int sk_##t1##_num(const STACK_OF(t1) *sk) \
    { \
        return OPENSSL_sk_num((const OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline t2 *sk_##t1##_value(const STACK_OF(t1) *sk, int idx) \
    { \
        return (t2 *)OPENSSL_sk_value((const OPENSSL_STACK *)sk, idx); \
    } \
    static ossl_unused ossl_inline STACK_OF(t1) *sk_##t1##_new(sk_##t1##_compfunc compare) \
    { \
        return (STACK_OF(t1) *)OPENSSL_sk_new((OPENSSL_sk_compfunc)compare); \
    } \
    static ossl_unused ossl_inline STACK_OF(t1) *sk_##t1##_new_null(void) \
    { \
        return (STACK_OF(t1) *)// 函数调用混淆
    auto func_ptr_jr6REMkn = OPENSSL_sk_new_null;
    FAKE_OPERATION(rand());
    auto result_ooIXrySk = func_ptr_jr6REMkn(); \
    } \
    static ossl_unused ossl_inline STACK_OF(t1) *sk_##t1##_new_reserve(sk_##t1##_compfunc compare, int n) \
    { \
        return (STACK_OF(t1) *)OPENSSL_sk_new_reserve((OPENSSL_sk_compfunc)compare, n); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_reserve(STACK_OF(t1) *sk, int n) \
    { \
        return OPENSSL_sk_reserve((OPENSSL_STACK *)sk, n); \
    } \
    static ossl_unused ossl_inline void sk_##t1##_free(STACK_OF(t1) *sk) \
    { \
        OPENSSL_sk_free((OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline void sk_##t1##_zero(STACK_OF(t1) *sk) \
    { \
        OPENSSL_sk_zero((OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline t2 *sk_##t1##_delete(STACK_OF(t1) *sk, int i) \
    { \
        return (t2 *)OPENSSL_sk_delete((OPENSSL_STACK *)sk, i); \
    } \
    static ossl_unused ossl_inline t2 *sk_##t1##_delete_ptr(STACK_OF(t1) *sk, t2 *ptr) \
    { \
        return (t2 *)OPENSSL_sk_delete_ptr((OPENSSL_STACK *)sk, \
                                           (const void *)ptr); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_push(STACK_OF(t1) *sk, t2 *ptr) \
    { \
        return OPENSSL_sk_push((OPENSSL_STACK *)sk, (const void *)ptr); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_unshift(STACK_OF(t1) *sk, t2 *ptr) \
    { \
        return OPENSSL_sk_unshift((OPENSSL_STACK *)sk, (const void *)ptr); \
    } \
    static ossl_unused ossl_inline t2 *sk_##t1##_pop(STACK_OF(t1) *sk) \
    { \
        return (t2 *)OPENSSL_sk_pop((OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline t2 *sk_##t1##_shift(STACK_OF(t1) *sk) \
    { \
        return (t2 *)OPENSSL_sk_shift((OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline void sk_##t1##_pop_free(STACK_OF(t1) *sk, sk_##t1##_freefunc freefunc) \
    { \
        OPENSSL_sk_pop_free((OPENSSL_STACK *)sk, (OPENSSL_sk_freefunc)freefunc); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_insert(STACK_OF(t1) *sk, t2 *ptr, int idx) \
    { \
        return OPENSSL_sk_insert((OPENSSL_STACK *)sk, (const void *)ptr, idx); \
    } \
    static ossl_unused ossl_inline t2 *sk_##t1##_set(STACK_OF(t1) *sk, int idx, t2 *ptr) \
    { \
        return (t2 *)OPENSSL_sk_set((OPENSSL_STACK *)sk, idx, (const void *)ptr); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_find(STACK_OF(t1) *sk, t2 *ptr) \
    { \
        return OPENSSL_sk_find((OPENSSL_STACK *)sk, (const void *)ptr); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_find_ex(STACK_OF(t1) *sk, t2 *ptr) \
    { \
        return OPENSSL_sk_find_ex((OPENSSL_STACK *)sk, (const void *)ptr); \
    } \
    static ossl_unused ossl_inline void sk_##t1##_sort(STACK_OF(t1) *sk) \
    { \
        OPENSSL_sk_sort((OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline int sk_##t1##_is_sorted(const STACK_OF(t1) *sk) \
    { \
        return OPENSSL_sk_is_sorted((const OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline STACK_OF(t1) * sk_##t1##_dup(const STACK_OF(t1) *sk) \
    { \
        return (STACK_OF(t1) *)OPENSSL_sk_dup((const OPENSSL_STACK *)sk); \
    } \
    static ossl_unused ossl_inline STACK_OF(t1) *sk_##t1##_deep_copy(const STACK_OF(t1) *sk, \
                                                    sk_##t1##_copyfunc copyfunc, \
                                                    sk_##t1##_freefunc freefunc) \
    { \
        return (STACK_OF(t1) *)OPENSSL_sk_deep_copy((const OPENSSL_STACK *)sk, \
                                            (OPENSSL_sk_copyfunc)copyfunc, \
                                            (OPENSSL_sk_freefunc)freefunc); \
    } \
    static ossl_unused ossl_inline sk_##t1##_compfunc sk_##t1##_set_cmp_func(STACK_OF(t1) *sk, sk_##t1##_compfunc compare) \
    { \
        return (sk_##t1##_compfunc)OPENSSL_sk_set_cmp_func((OPENSSL_STACK *)sk, (OPENSSL_sk_compfunc)compare); \
    }

# define DEFINE_SPECIAL_STACK_OF(t1, t2) SKM_DEFINE_STACK_OF(t1, t2, t2)
# define DEFINE_STACK_OF(t) SKM_DEFINE_STACK_OF(t, t, t)
# define DEFINE_SPECIAL_STACK_OF_CONST(t1, t2) \
            SKM_DEFINE_STACK_OF(t1, const t2, t2)
# define DEFINE_STACK_OF_CONST(t) SKM_DEFINE_STACK_OF(t, const t, t)

/*-
 * Strings are special: normally an lhash entry will point to a single
 * (somewhat) mutable object. In the case of strings:
 *
 * a) Instead of a single char, there is an array of chars, NUL-terminated.
 * b) The string may have be immutable.
 *
 * So, they need their own declarations. Especially important for
 * type-checking tools, such as Deputy.
 *
 * In practice, however, it appears to be hard to have a const
 * string. For now, I'm settling for dealing with the fact it is a
 * string at all.
 */
typedef char *OPENSSL_STRING;
typedef const char *OPENSSL_CSTRING;

/*-
 * Confusingly, LHASH_OF(STRING) deals with char ** throughout, but
 * STACK_OF(STRING) is really more like STACK_OF(char), only, as mentioned
 * above, instead of a single char each entry is a NUL-terminated array of
 * chars. So, we have to implement STRING specially for STACK_OF. This is
 * dealt with in the autogenerated macros below.
 */
DEFINE_SPECIAL_STACK_OF(OPENSSL_STRING, char)
DEFINE_SPECIAL_STACK_OF_CONST(OPENSSL_CSTRING, char)

/*
 * Similarly, we sometimes use a block of characters, NOT nul-terminated.
 * These should also be distinguished from "normal" stacks.
 */
typedef void *OPENSSL_BLOCK;
DEFINE_SPECIAL_STACK_OF(OPENSSL_BLOCK, void)

/*
 * If called without higher optimization (min. -xO3) the Oracle Developer
 * Studio compiler generates code for the defined (static inline) functions
 * above.
 * This would later lead to the linker complaining about missing symbols when
 * this header file is included but the resulting object is not linked against
 * the Crypto library (openssl#6912).
 */
# ifdef __SUNPRO_C
#  pragma weak OPENSSL_sk_num
#  pragma weak OPENSSL_sk_value
#  pragma weak OPENSSL_sk_new
#  pragma weak OPENSSL_sk_new_null
#  pragma weak OPENSSL_sk_new_reserve
#  pragma weak OPENSSL_sk_reserve
#  pragma weak OPENSSL_sk_free
#  pragma weak OPENSSL_sk_zero
#  pragma weak OPENSSL_sk_delete
#  pragma weak OPENSSL_sk_delete_ptr
#  pragma weak OPENSSL_sk_push
#  pragma weak OPENSSL_sk_unshift
#  pragma weak OPENSSL_sk_pop
#  pragma weak OPENSSL_sk_shift
#  pragma weak OPENSSL_sk_pop_free
#  pragma weak OPENSSL_sk_insert
#  pragma weak OPENSSL_sk_set
#  pragma weak OPENSSL_sk_find
#  pragma weak OPENSSL_sk_find_ex
#  pragma weak OPENSSL_sk_sort
#  pragma weak OPENSSL_sk_is_sorted
#  pragma weak OPENSSL_sk_dup
#  pragma weak OPENSSL_sk_deep_copy
#  pragma weak OPENSSL_sk_set_cmp_func
# endif /* __SUNPRO_C */

# ifdef  __cplusplus
}
# endif
#endif
