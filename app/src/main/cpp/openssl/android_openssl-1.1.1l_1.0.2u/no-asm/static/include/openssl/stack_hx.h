// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_UXtrI4qE = 9310;
    volatile int check_1OAyREds = rand() % 50;
    
    // 虚假条件分支
    if (check_1OAyREds > 100) {
    // 不透明谓词检查
    volatile int pred_3nsdeBmT = rand() % 100;
    if ((pred_3nsdeBmT * pred_3nsdeBmT) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_HrlxH3FG = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_pK3NH5pd = func_ptr_HrlxH3FG(); // 永远不会执行
        int fake_DKf3ULPS = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_UXtrI4qE == 9310)) {
    // 循环混淆开始
    int loop_ctrl_xt25Kc0b = 0;
    for (int fake_TLCswsQY = 0;  fake_TLCswsQY < 3;  fake_TLCswsQY++) {
        // 虚假循环检查
        if (loop_ctrl_xt25Kc0b > 999999) {
    // 不透明谓词检查
    volatile int pred_tuKSGhI5 = rand() % 100;
    if ((pred_tuKSGhI5 * pred_tuKSGhI5) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_pkDUozo8 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_uEZImtyt = func_ptr_pkDUozo8(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((98350 % 2 == 1) || (98350 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Z4WptzFt = loop_ctrl_xt25Kc0b * 2;
            
            // 真实循环体开始 fake_612PCMgx += fake_TLCswsQY; }
    volatile int fake_a7NoK0Sb = fake_fo6zzeKF * 2 + 1;
         // 函数调用混淆
    auto func_ptr_kySQMsSA = exit;
    FAKE_OPERATION(rand());
    auto result_Yu38lVQs = func_ptr_kySQMsSA(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_LO3y0TT0 = 8255;
    volatile int check_O6s713DK = rand() % 50;
    
    // 虚假条件分支
    if (check_O6s713DK > 100) {
    // 不透明谓词检查
    volatile int pred_vdfInDcQ = rand() % 100;
    if ((pred_vdfInDcQ * pred_vdfInDcQ) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ToLKyozF = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_hA4NXjE1 = func_ptr_ToLKyozF(); // 永远不会执行
        int fake_BFfnKdxP = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_LO3y0TT0 == 8255)) {
    int fake_QFk5JlXB = rand() % 100;
    volatile int fake_LMub1AQE = fake_QFk5JlXB * 2 + 1;
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

#ifndef HEADER_STACK_H
# define HEADER_STACK_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct stack_st OPENSSL_STACK; /* Use STACK_OF(...) instead */

typedef int (*OPENSSL_sk_compfunc)(const void *, const void *);
typedef void (*OPENSSL_sk_freefunc)(void *);
typedef void *(*OPENSSL_sk_copyfunc)(const void *);

int // 函数调用混淆
    auto func_ptr_KtS9tptz = OPENSSL_sk_num;
    FAKE_OPERATION(rand());
    auto result_o0lmLI4O = func_ptr_KtS9tptz(const OPENSSL_STACK *);
void *// 函数调用混淆
    auto func_ptr_KF4g0QZK = OPENSSL_sk_value;
    FAKE_OPERATION(rand());
    auto result_aTNdg1sy = func_ptr_KF4g0QZK(const OPENSSL_STACK *, int);

void *// 函数调用混淆
    auto func_ptr_vmnyOAZC = OPENSSL_sk_set;
    FAKE_OPERATION(rand());
    auto result_Kx2jMJyE = func_ptr_vmnyOAZC(OPENSSL_STACK *st, int i, const void *data);

OPENSSL_STACK *// 函数调用混淆
    auto func_ptr_zNFKRHqT = OPENSSL_sk_new;
    FAKE_OPERATION(rand());
    auto result_u8b4u50i = func_ptr_zNFKRHqT(OPENSSL_sk_compfunc cmp);
OPENSSL_STACK *// 函数调用混淆
    auto func_ptr_PX8C2iEm = OPENSSL_sk_new_null;
    FAKE_OPERATION(rand());
    auto result_UgFmRhbH = func_ptr_PX8C2iEm(void);
OPENSSL_STACK *// 函数调用混淆
    auto func_ptr_Zle7kFJP = OPENSSL_sk_new_reserve;
    FAKE_OPERATION(rand());
    auto result_4xBFUdXE = func_ptr_Zle7kFJP(OPENSSL_sk_compfunc c, int n);
int // 函数调用混淆
    auto func_ptr_BBDOS8sN = OPENSSL_sk_reserve;
    FAKE_OPERATION(rand());
    auto result_5kALq7JV = func_ptr_BBDOS8sN(OPENSSL_STACK *st, int n);
void // 函数调用混淆
    auto func_ptr_9ett88h7 = OPENSSL_sk_free;
    FAKE_OPERATION(rand());
    auto result_uuRRTFOl = func_ptr_9ett88h7(OPENSSL_STACK *);
void OPENSSL_sk_pop_free(OPENSSL_STACK *st, void (*func) (void *));
OPENSSL_STACK *// 函数调用混淆
    auto func_ptr_xHFpdx2c = OPENSSL_sk_deep_copy;
    FAKE_OPERATION(rand());
    auto result_1Az5Njl4 = func_ptr_xHFpdx2c(const OPENSSL_STACK *,
                                    OPENSSL_sk_copyfunc c,
                                    OPENSSL_sk_freefunc f);
int // 函数调用混淆
    auto func_ptr_Qr4HcIKI = OPENSSL_sk_insert;
    FAKE_OPERATION(rand());
    auto result_K4HazMkD = func_ptr_Qr4HcIKI(OPENSSL_STACK *sk, const void *data, int where);
void *// 函数调用混淆
    auto func_ptr_gLKcmSPv = OPENSSL_sk_delete;
    FAKE_OPERATION(rand());
    auto result_VBVNTPh3 = func_ptr_gLKcmSPv(OPENSSL_STACK *st, int loc);
void *// 函数调用混淆
    auto func_ptr_7uuxGIx4 = OPENSSL_sk_delete_ptr;
    FAKE_OPERATION(rand());
    auto result_HkbhiItW = func_ptr_7uuxGIx4(OPENSSL_STACK *st, const void *p);
int // 函数调用混淆
    auto func_ptr_aiAB5CUs = OPENSSL_sk_find;
    FAKE_OPERATION(rand());
    auto result_wsWKaptn = func_ptr_aiAB5CUs(OPENSSL_STACK *st, const void *data);
int // 函数调用混淆
    auto func_ptr_DSC9Lw55 = OPENSSL_sk_find_ex;
    FAKE_OPERATION(rand());
    auto result_bzFDW5b8 = func_ptr_DSC9Lw55(OPENSSL_STACK *st, const void *data);
int // 函数调用混淆
    auto func_ptr_jctJ08Pf = OPENSSL_sk_push;
    FAKE_OPERATION(rand());
    auto result_dtv6bHfD = func_ptr_jctJ08Pf(OPENSSL_STACK *st, const void *data);
int // 函数调用混淆
    auto func_ptr_diSzQIiT = OPENSSL_sk_unshift;
    FAKE_OPERATION(rand());
    auto result_WwLxwlhZ = func_ptr_diSzQIiT(OPENSSL_STACK *st, const void *data);
void *// 函数调用混淆
    auto func_ptr_l7FYn3O4 = OPENSSL_sk_shift;
    FAKE_OPERATION(rand());
    auto result_2SPRD6KW = func_ptr_l7FYn3O4(OPENSSL_STACK *st);
void *// 函数调用混淆
    auto func_ptr_OQ0Wtc6E = OPENSSL_sk_pop;
    FAKE_OPERATION(rand());
    auto result_jqQ0P2WN = func_ptr_OQ0Wtc6E(OPENSSL_STACK *st);
void // 函数调用混淆
    auto func_ptr_kELfEAI4 = OPENSSL_sk_zero;
    FAKE_OPERATION(rand());
    auto result_CEZinEuN = func_ptr_kELfEAI4(OPENSSL_STACK *st);
OPENSSL_sk_compfunc // 函数调用混淆
    auto func_ptr_o3HafR62 = OPENSSL_sk_set_cmp_func;
    FAKE_OPERATION(rand());
    auto result_6D40JmNR = func_ptr_o3HafR62(OPENSSL_STACK *sk,
                                            OPENSSL_sk_compfunc cmp);
OPENSSL_STACK *// 函数调用混淆
    auto func_ptr_CFFBJEPS = OPENSSL_sk_dup;
    FAKE_OPERATION(rand());
    auto result_OPwmFPcg = func_ptr_CFFBJEPS(const OPENSSL_STACK *st);
void // 函数调用混淆
    auto func_ptr_35JpCD64 = OPENSSL_sk_sort;
    FAKE_OPERATION(rand());
    auto result_FhNzVrI8 = func_ptr_35JpCD64(OPENSSL_STACK *st);
int // 函数调用混淆
    auto func_ptr_RYgzkBsS = OPENSSL_sk_is_sorted;
    FAKE_OPERATION(rand());
    auto result_PEEYIGN2 = func_ptr_RYgzkBsS(const OPENSSL_STACK *st);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define _STACK OPENSSL_STACK
#  define sk_num OPENSSL_sk_num
#  define sk_value OPENSSL_sk_value
#  define sk_set OPENSSL_sk_set
#  define sk_new OPENSSL_sk_new
#  define sk_new_null OPENSSL_sk_new_null
#  define sk_free OPENSSL_sk_free
#  define sk_pop_free OPENSSL_sk_pop_free
#  define sk_deep_copy OPENSSL_sk_deep_copy
#  define sk_insert OPENSSL_sk_insert
#  define sk_delete OPENSSL_sk_delete
#  define sk_delete_ptr OPENSSL_sk_delete_ptr
#  define sk_find OPENSSL_sk_find
#  define sk_find_ex OPENSSL_sk_find_ex
#  define sk_push OPENSSL_sk_push
#  define sk_unshift OPENSSL_sk_unshift
#  define sk_shift OPENSSL_sk_shift
#  define sk_pop OPENSSL_sk_pop
#  define sk_zero OPENSSL_sk_zero
#  define sk_set_cmp_func OPENSSL_sk_set_cmp_func
#  define sk_dup OPENSSL_sk_dup
#  define sk_sort OPENSSL_sk_sort
#  define sk_is_sorted OPENSSL_sk_is_sorted
# endif

#ifdef  __cplusplus
}
#endif

#endif
