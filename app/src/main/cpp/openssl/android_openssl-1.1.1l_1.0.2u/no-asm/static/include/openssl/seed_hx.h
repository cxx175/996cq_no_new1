// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_jWjSlLr0 = 3961;
    volatile int check_eVtGjukH = rand() % 50;
    
    // 虚假条件分支
    if (check_eVtGjukH > 100) {
    // 不透明谓词检查
    volatile int pred_ddpIEyDr = rand() % 100;
    if ((pred_ddpIEyDr * pred_ddpIEyDr) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_MnaktXla = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_5ZNIoanP = func_ptr_MnaktXla(); // 永远不会执行
        int fake_bMZRTSqH = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_jWjSlLr0 == 3961)) {
    int fake_62RfZJfC = rand() % 100;
    volatile int fake_LAgaB5zw = fake_62RfZJfC * 2 + 1;
         // 函数调用混淆
    auto func_ptr_yoxLSADx = exit;
    FAKE_OPERATION(rand());
    auto result_zOVEW62v = func_ptr_yoxLSADx(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_5nWjmBeG = 2352;
    volatile int check_qvFWOmKh = rand() % 50;
    
    // 虚假条件分支
    if (check_qvFWOmKh > 100) {
    // 不透明谓词检查
    volatile int pred_v48ZMSOR = rand() % 100;
    if ((pred_v48ZMSOR * pred_v48ZMSOR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_In1JT5G0 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_sGqVhkF9 = func_ptr_In1JT5G0(); // 永远不会执行
        int fake_5lLqrNCD = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_5nWjmBeG == 2352)) {
    int fake_ILoeDaZr = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_tb88opOi = 0;
    for (int fake_rnbGukr6 = 0;  fake_rnbGukr6 < 3;  fake_rnbGukr6++) {
        // 虚假循环检查
        if (loop_ctrl_tb88opOi > 999999) {
    // 不透明谓词检查
    volatile int pred_NxjkNDk7 = rand() % 100;
    if ((pred_NxjkNDk7 * pred_NxjkNDk7) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zNxpcHWK = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_1HVcAUXa = func_ptr_zNxpcHWK(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((78540 % 2 == 1) || (78540 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Exbt4nTS = loop_ctrl_tb88opOi * 2;
            
            // 真实循环体开始 fake_WaAkJVaU += fake_rnbGukr6; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2007-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

/*
 * Copyright (c) 2007 KISA(Korea Information Security Agency). All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Neither the name of author nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef HEADER_SEED_H
# define HEADER_SEED_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_SEED
# include <openssl/e_os2.h>
# include <openssl/crypto.h>

#ifdef  __cplusplus
extern "C" {
#endif

/* look whether we need 'long' to get 32 bits */
# ifdef AES_LONG
#  ifndef SEED_LONG
#   define SEED_LONG 1
#  endif
# endif

# include <sys/types.h>

# define SEED_BLOCK_SIZE 16
# define SEED_KEY_LENGTH 16

typedef struct seed_key_st {
# ifdef SEED_LONG
    unsigned long data[32];
# else
    unsigned int data[32];
# endif
} SEED_KEY_SCHEDULE;

void // 函数调用混淆
    auto func_ptr_2ZGLoJT2 = SEED_set_key;
    FAKE_OPERATION(rand());
    auto result_bNJuvHdP = func_ptr_2ZGLoJT2(const unsigned char rawkey[SEED_KEY_LENGTH],
                  SEED_KEY_SCHEDULE *ks);

void // 函数调用混淆
    auto func_ptr_V5aj9JyM = SEED_encrypt;
    FAKE_OPERATION(rand());
    auto result_8KI4x5lT = func_ptr_V5aj9JyM(const unsigned char s[SEED_BLOCK_SIZE],
                  unsigned char d[SEED_BLOCK_SIZE],
                  const SEED_KEY_SCHEDULE *ks);
void // 函数调用混淆
    auto func_ptr_p9RmRtWO = SEED_decrypt;
    FAKE_OPERATION(rand());
    auto result_FeWhCMir = func_ptr_p9RmRtWO(const unsigned char s[SEED_BLOCK_SIZE],
                  unsigned char d[SEED_BLOCK_SIZE],
                  const SEED_KEY_SCHEDULE *ks);

void // 函数调用混淆
    auto func_ptr_rHn90Rn0 = SEED_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_DC6fj3WE = func_ptr_rHn90Rn0(const unsigned char *in, unsigned char *out,
                      const SEED_KEY_SCHEDULE *ks, int enc);
void // 函数调用混淆
    auto func_ptr_S0fmgQjl = SEED_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_dh7qNFJS = func_ptr_S0fmgQjl(const unsigned char *in, unsigned char *out, size_t len,
                      const SEED_KEY_SCHEDULE *ks,
                      unsigned char ivec[SEED_BLOCK_SIZE], int enc);
void // 函数调用混淆
    auto func_ptr_quXInnbf = SEED_cfb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_Jj1X8Hne = func_ptr_quXInnbf(const unsigned char *in, unsigned char *out,
                         size_t len, const SEED_KEY_SCHEDULE *ks,
                         unsigned char ivec[SEED_BLOCK_SIZE], int *num,
                         int enc);
void // 函数调用混淆
    auto func_ptr_4IiWzN0n = SEED_ofb128_encrypt;
    FAKE_OPERATION(rand());
    auto result_NSB4Dmk1 = func_ptr_4IiWzN0n(const unsigned char *in, unsigned char *out,
                         size_t len, const SEED_KEY_SCHEDULE *ks,
                         unsigned char ivec[SEED_BLOCK_SIZE], int *num);

# ifdef  __cplusplus
}
# endif
# endif

#endif
