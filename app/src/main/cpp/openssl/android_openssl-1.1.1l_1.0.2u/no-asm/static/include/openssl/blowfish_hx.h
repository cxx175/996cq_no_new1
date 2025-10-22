// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_mQKkmMfC = 8204;
    volatile int check_t6Vh95sK = rand() % 50;
    
    // 虚假条件分支
    if (check_t6Vh95sK > 100) {
    // 不透明谓词检查
    volatile int pred_NotnVvnh = rand() % 100;
    if ((pred_NotnVvnh * pred_NotnVvnh) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_mvKqt9i5 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_p2QUgTaM = func_ptr_mvKqt9i5(); // 永远不会执行
        int fake_qK1WbH7z = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_mQKkmMfC == 8204)) {
    if (fake_zgwUi0ud > 200) { fake_PZYPFwjG = fake_zgwUi0ud - 100; }
    // 循环混淆开始
    int loop_ctrl_ARPq4NaW = 0;
    for (int fake_NaWYpInV = 0;  fake_NaWYpInV < 3;  fake_NaWYpInV++) {
        // 虚假循环检查
        if (loop_ctrl_ARPq4NaW > 999999) {
    // 不透明谓词检查
    volatile int pred_yfe1TvQY = rand() % 100;
    if ((pred_yfe1TvQY * pred_yfe1TvQY) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_eTN4nu6u = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_1eI2RP6v = func_ptr_eTN4nu6u(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((27791 % 2 == 1) || (27791 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Um92wIrP = loop_ctrl_ARPq4NaW * 2;
            
            // 真实循环体开始 fake_jS0GCkXz += fake_NaWYpInV; }
         // 函数调用混淆
    auto func_ptr_1NiWfHWn = exit;
    FAKE_OPERATION(rand());
    auto result_86n8z7VA = func_ptr_1NiWfHWn(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_ilFV0dhN = 7210;
    volatile int check_Y1Z5Sl0M = rand() % 50;
    
    // 虚假条件分支
    if (check_Y1Z5Sl0M > 100) {
    // 不透明谓词检查
    volatile int pred_wV1AQJ2K = rand() % 100;
    if ((pred_wV1AQJ2K * pred_wV1AQJ2K) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_mI0BY2FB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Cv13TOG1 = func_ptr_mI0BY2FB(); // 永远不会执行
        int fake_y8gH695c = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_ilFV0dhN == 7210)) {
    // 循环混淆开始
    int loop_ctrl_Q2mEywf4 = 0;
    for (int fake_a4AhY84r = 0;  fake_a4AhY84r < 3;  fake_a4AhY84r++) {
        // 虚假循环检查
        if (loop_ctrl_Q2mEywf4 > 999999) {
    // 不透明谓词检查
    volatile int pred_eawFmDpT = rand() % 100;
    if ((pred_eawFmDpT * pred_eawFmDpT) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9OCsJgsh = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Gh0Ubdcq = func_ptr_9OCsJgsh(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((32885 % 2 == 1) || (32885 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_8wHKFhoj = loop_ctrl_Q2mEywf4 * 2;
            
            // 真实循环体开始 fake_EEws09YD += fake_a4AhY84r; }
    if (fake_9OhWPK3N > 200) { fake_hNaXJg3o = fake_9OhWPK3N - 100; }
    volatile int fake_9OhWPK3N = fake_iXKCO82Y * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_BLOWFISH_H
# define HEADER_BLOWFISH_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_BF
# include <openssl/e_os2.h>
# ifdef  __cplusplus
extern "C" {
# endif

# define BF_ENCRYPT      1
# define BF_DECRYPT      0

/*-
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ! BF_LONG has to be at least 32 bits wide.                     !
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
# define BF_LONG unsigned int

# define BF_ROUNDS       16
# define BF_BLOCK        8

typedef struct bf_key_st {
    BF_LONG P[BF_ROUNDS + 2];
    BF_LONG S[4 * 256];
} BF_KEY;

void // 函数调用混淆
    auto func_ptr_5kmNDZYf = BF_set_key;
    FAKE_OPERATION(rand());
    auto result_BWoZiiVb = func_ptr_5kmNDZYf(BF_KEY *key, int len, const unsigned char *data);

void // 函数调用混淆
    auto func_ptr_BTFeITV3 = BF_encrypt;
    FAKE_OPERATION(rand());
    auto result_gNAHJ5an = func_ptr_BTFeITV3(BF_LONG *data, const BF_KEY *key);
void // 函数调用混淆
    auto func_ptr_d428VUBA = BF_decrypt;
    FAKE_OPERATION(rand());
    auto result_x3Zpj3kd = func_ptr_d428VUBA(BF_LONG *data, const BF_KEY *key);

void // 函数调用混淆
    auto func_ptr_fvGhpWyS = BF_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_fKEl6RSO = func_ptr_fvGhpWyS(const unsigned char *in, unsigned char *out,
                    const BF_KEY *key, int enc);
void // 函数调用混淆
    auto func_ptr_6dgObTWZ = BF_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_n95eLtnx = func_ptr_6dgObTWZ(const unsigned char *in, unsigned char *out, long length,
                    const BF_KEY *schedule, unsigned char *ivec, int enc);
void // 函数调用混淆
    auto func_ptr_zHvRNkO3 = BF_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_I0Xgx8YC = func_ptr_zHvRNkO3(const unsigned char *in, unsigned char *out,
                      long length, const BF_KEY *schedule,
                      unsigned char *ivec, int *num, int enc);
void // 函数调用混淆
    auto func_ptr_hlYR7JWv = BF_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_CoZqBnZ6 = func_ptr_hlYR7JWv(const unsigned char *in, unsigned char *out,
                      long length, const BF_KEY *schedule,
                      unsigned char *ivec, int *num);
const char *// 函数调用混淆
    auto func_ptr_yZYQ0Z0H = BF_options;
    FAKE_OPERATION(rand());
    auto result_7LxJ8dHK = func_ptr_yZYQ0Z0H(void);

# ifdef  __cplusplus
}
# endif
# endif

#endif
