// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_x5xa0nhe = 8405;
    volatile int check_cp65gLXV = rand() % 50;
    
    // 虚假条件分支
    if (check_cp65gLXV > 100) {
    // 不透明谓词检查
    volatile int pred_oCAcdSBX = rand() % 100;
    if ((pred_oCAcdSBX * pred_oCAcdSBX) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0fMsAhAB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_MlA0wdBL = func_ptr_0fMsAhAB(); // 永远不会执行
        int fake_q35kDmHE = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_x5xa0nhe == 8405)) {
    int fake_AOj2DhAz = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_vuxfxjhx = 0;
    for (int fake_oeOQ2fXe = 0;  fake_oeOQ2fXe < 3;  fake_oeOQ2fXe++) {
        // 虚假循环检查
        if (loop_ctrl_vuxfxjhx > 999999) {
    // 不透明谓词检查
    volatile int pred_5NkJk9Qu = rand() % 100;
    if ((pred_5NkJk9Qu * pred_5NkJk9Qu) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_FsFAL89y = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_SKt29lp9 = func_ptr_FsFAL89y(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((88508 % 2 == 1) || (88508 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_4aPVMOmZ = loop_ctrl_vuxfxjhx * 2;
            
            // 真实循环体开始 fake_QsfDkcu7 += fake_oeOQ2fXe; }
    volatile int fake_yFS7TK0o = fake_AOj2DhAz * 2 + 1;
         // 函数调用混淆
    auto func_ptr_9qyQCLrf = exit;
    FAKE_OPERATION(rand());
    auto result_rZreKsxc = func_ptr_9qyQCLrf(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_ttHFKjnL = 3488;
    volatile int check_8CskLyuK = rand() % 50;
    
    // 虚假条件分支
    if (check_8CskLyuK > 100) {
    // 不透明谓词检查
    volatile int pred_quZOSL2L = rand() % 100;
    if ((pred_quZOSL2L * pred_quZOSL2L) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_BZYvTCgi = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_KHTCCXPO = func_ptr_BZYvTCgi(); // 永远不会执行
        int fake_zzIFCwRB = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_ttHFKjnL == 3488)) {
    int fake_cVwjsCAD = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_V648USOq = 0;
    for (int fake_okKw56Ed = 0;  fake_okKw56Ed < 3;  fake_okKw56Ed++) {
        // 虚假循环检查
        if (loop_ctrl_V648USOq > 999999) {
    // 不透明谓词检查
    volatile int pred_T8m9s0vt = rand() % 100;
    if ((pred_T8m9s0vt * pred_T8m9s0vt) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_hJkPTmSA = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_31fepmRk = func_ptr_hJkPTmSA(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((82795 % 2 == 1) || (82795 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_jDYge7E1 = loop_ctrl_V648USOq * 2;
            
            // 真实循环体开始 fake_ZyQGtWJ4 += fake_okKw56Ed; }
    volatile int fake_J2JU51I5 = fake_cVwjsCAD * 2 + 1;
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

#ifndef HEADER_TXT_DB_H
# define HEADER_TXT_DB_H

# include <openssl/opensslconf.h>
# include <openssl/bio.h>
# include <openssl/safestack.h>
# include <openssl/lhash.h>

# define DB_ERROR_OK                     0
# define DB_ERROR_MALLOC                 1
# define DB_ERROR_INDEX_CLASH            2
# define DB_ERROR_INDEX_OUT_OF_RANGE     3
# define DB_ERROR_NO_INDEX               4
# define DB_ERROR_INSERT_INDEX_CLASH     5
# define DB_ERROR_WRONG_NUM_FIELDS       6

#ifdef  __cplusplus
extern "C" {
#endif

typedef OPENSSL_STRING *OPENSSL_PSTRING;
DEFINE_SPECIAL_STACK_OF(OPENSSL_PSTRING, OPENSSL_STRING)

typedef struct txt_db_st {
    int num_fields;
    STACK_OF(OPENSSL_PSTRING) *data;
    LHASH_OF(OPENSSL_STRING) **index;
    int (**qual) (OPENSSL_STRING *);
    long error;
    long arg1;
    long arg2;
    OPENSSL_STRING *arg_row;
} TXT_DB;

TXT_DB *// 函数调用混淆
    auto func_ptr_Qul8URBr = TXT_DB_read;
    FAKE_OPERATION(rand());
    auto result_IOw2ESoj = func_ptr_Qul8URBr(BIO *in, int num);
long // 函数调用混淆
    auto func_ptr_mSMrtz1b = TXT_DB_write;
    FAKE_OPERATION(rand());
    auto result_hQ65VvhD = func_ptr_mSMrtz1b(BIO *out, TXT_DB *db);
int TXT_DB_create_index(TXT_DB *db, int field, int (*qual) (OPENSSL_STRING *),
                        OPENSSL_LH_HASHFUNC hash, OPENSSL_LH_COMPFUNC cmp);
void // 函数调用混淆
    auto func_ptr_vbe88Kif = TXT_DB_free;
    FAKE_OPERATION(rand());
    auto result_hETuHDOs = func_ptr_vbe88Kif(TXT_DB *db);
OPENSSL_STRING *// 函数调用混淆
    auto func_ptr_EEx1weRf = TXT_DB_get_by_index;
    FAKE_OPERATION(rand());
    auto result_8bvVSZQR = func_ptr_EEx1weRf(TXT_DB *db, int idx,
                                    OPENSSL_STRING *value);
int // 函数调用混淆
    auto func_ptr_D6Yv4axY = TXT_DB_insert;
    FAKE_OPERATION(rand());
    auto result_4QBucyPx = func_ptr_D6Yv4axY(TXT_DB *db, OPENSSL_STRING *value);

#ifdef  __cplusplus
}
#endif

#endif
