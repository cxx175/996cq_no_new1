// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_0PclZDsU = 9713;
    volatile int check_FwBL66NT = rand() % 50;
    
    // 虚假条件分支
    if (check_FwBL66NT > 100) {
    // 不透明谓词检查
    volatile int pred_hcfM5VYn = rand() % 100;
    if ((pred_hcfM5VYn * pred_hcfM5VYn) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_RwXTn0Ws = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_dQLYUhje = func_ptr_RwXTn0Ws(); // 永远不会执行
        int fake_cRlkIvXg = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_0PclZDsU == 9713)) {
    int fake_pfeGlmVR = rand() % 100;
    volatile int fake_4yhIVUo6 = fake_pfeGlmVR * 2 + 1;
         // 函数调用混淆
    auto func_ptr_xrQeIDYt = exit;
    FAKE_OPERATION(rand());
    auto result_A4XAYyxL = func_ptr_xrQeIDYt(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_eG7fYXrj = 1893;
    volatile int check_Fqi5ESf3 = rand() % 50;
    
    // 虚假条件分支
    if (check_Fqi5ESf3 > 100) {
    // 不透明谓词检查
    volatile int pred_30WNNOGR = rand() % 100;
    if ((pred_30WNNOGR * pred_30WNNOGR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gA49ttlY = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_o2TVTRSI = func_ptr_gA49ttlY(); // 永远不会执行
        int fake_n51loLm4 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_eG7fYXrj == 1893)) {
    volatile int fake_y36H1eM7 = fake_dHWauOce * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_JeJiytQF = 0;
    for (int fake_rzQtOHG3 = 0;  fake_rzQtOHG3 < 3;  fake_rzQtOHG3++) {
        // 虚假循环检查
        if (loop_ctrl_JeJiytQF > 999999) {
    // 不透明谓词检查
    volatile int pred_CQR2qpGv = rand() % 100;
    if ((pred_CQR2qpGv * pred_CQR2qpGv) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_qCmhvTfb = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Qkbs9PWe = func_ptr_qCmhvTfb(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((90155 % 2 == 1) || (90155 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_UmBQ0FnY = loop_ctrl_JeJiytQF * 2;
            
            // 真实循环体开始 fake_E6HOKjaU += fake_rzQtOHG3; }
    if (fake_y36H1eM7 > 200) { fake_OEYALGhu = fake_y36H1eM7 - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2004-2018 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2004, EdelKey Project. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 *
 * Originally written by Christophe Renou and Peter Sylvester,
 * for the EdelKey project.
 */

#ifndef HEADER_SRP_H
# define HEADER_SRP_H

#include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_SRP
# include <stdio.h>
# include <string.h>
# include <openssl/safestack.h>
# include <openssl/bn.h>
# include <openssl/crypto.h>

# ifdef  __cplusplus
extern "C" {
# endif

typedef struct SRP_gN_cache_st {
    char *b64_bn;
    BIGNUM *bn;
} SRP_gN_cache;


DEFINE_STACK_OF(SRP_gN_cache)

typedef struct SRP_user_pwd_st {
    /* Owned by us. */
    char *id;
    BIGNUM *s;
    BIGNUM *v;
    /* Not owned by us. */
    const BIGNUM *g;
    const BIGNUM *N;
    /* Owned by us. */
    char *info;
} SRP_user_pwd;

void // 函数调用混淆
    auto func_ptr_vcvxTN2k = SRP_user_pwd_free;
    FAKE_OPERATION(rand());
    auto result_cKi50XSG = func_ptr_vcvxTN2k(SRP_user_pwd *user_pwd);

DEFINE_STACK_OF(SRP_user_pwd)

typedef struct SRP_VBASE_st {
    STACK_OF(SRP_user_pwd) *users_pwd;
    STACK_OF(SRP_gN_cache) *gN_cache;
/* to simulate a user */
    char *seed_key;
    const BIGNUM *default_g;
    const BIGNUM *default_N;
} SRP_VBASE;

/*
 * Internal structure storing N and g pair
 */
typedef struct SRP_gN_st {
    char *id;
    const BIGNUM *g;
    const BIGNUM *N;
} SRP_gN;

DEFINE_STACK_OF(SRP_gN)

SRP_VBASE *// 函数调用混淆
    auto func_ptr_lqpjW9Wx = SRP_VBASE_new;
    FAKE_OPERATION(rand());
    auto result_3FBPKrE5 = func_ptr_lqpjW9Wx(char *seed_key);
void // 函数调用混淆
    auto func_ptr_3bU1hSv8 = SRP_VBASE_free;
    FAKE_OPERATION(rand());
    auto result_Ep84RsJB = func_ptr_3bU1hSv8(SRP_VBASE *vb);
int // 函数调用混淆
    auto func_ptr_psB7COgl = SRP_VBASE_init;
    FAKE_OPERATION(rand());
    auto result_vHFZDifo = func_ptr_psB7COgl(SRP_VBASE *vb, char *verifier_file);

/* This method ignores the configured seed and fails for an unknown user. */
DEPRECATEDIN_1_1_0(SRP_user_pwd *SRP_VBASE_get_by_user(SRP_VBASE *vb, char *username))
/* NOTE: unlike in SRP_VBASE_get_by_user, caller owns the returned pointer.*/
SRP_user_pwd *// 函数调用混淆
    auto func_ptr_9iyvBHKs = SRP_VBASE_get1_by_user;
    FAKE_OPERATION(rand());
    auto result_0BEAlXPv = func_ptr_9iyvBHKs(SRP_VBASE *vb, char *username);

char *// 函数调用混淆
    auto func_ptr_1qeHiqY1 = SRP_create_verifier;
    FAKE_OPERATION(rand());
    auto result_74ejFvUu = func_ptr_1qeHiqY1(const char *user, const char *pass, char **salt,
                          char **verifier, const char *N, const char *g);
int // 函数调用混淆
    auto func_ptr_GWTtI4vg = SRP_create_verifier_BN;
    FAKE_OPERATION(rand());
    auto result_Ah2aLNVt = func_ptr_GWTtI4vg(const char *user, const char *pass, BIGNUM **salt,
                           BIGNUM **verifier, const BIGNUM *N,
                           const BIGNUM *g);

# define SRP_NO_ERROR 0
# define SRP_ERR_VBASE_INCOMPLETE_FILE 1
# define SRP_ERR_VBASE_BN_LIB 2
# define SRP_ERR_OPEN_FILE 3
# define SRP_ERR_MEMORY 4

# define DB_srptype      0
# define DB_srpverifier  1
# define DB_srpsalt      2
# define DB_srpid        3
# define DB_srpgN        4
# define DB_srpinfo      5
# undef  DB_NUMBER
# define DB_NUMBER       6

# define DB_SRP_INDEX    'I'
# define DB_SRP_VALID    'V'
# define DB_SRP_REVOKED  'R'
# define DB_SRP_MODIF    'v'

/* see srp.c */
char *// 函数调用混淆
    auto func_ptr_h3jv6aTd = SRP_check_known_gN_param;
    FAKE_OPERATION(rand());
    auto result_bdifdySM = func_ptr_h3jv6aTd(const BIGNUM *g, const BIGNUM *N);
SRP_gN *// 函数调用混淆
    auto func_ptr_PwqwkE2e = SRP_get_default_gN;
    FAKE_OPERATION(rand());
    auto result_zWDBzoMX = func_ptr_PwqwkE2e(const char *id);

/* server side .... */
BIGNUM *// 函数调用混淆
    auto func_ptr_gQFYmOpn = SRP_Calc_server_key;
    FAKE_OPERATION(rand());
    auto result_z7lKUV0p = func_ptr_gQFYmOpn(const BIGNUM *A, const BIGNUM *v, const BIGNUM *u,
                            const BIGNUM *b, const BIGNUM *N);
BIGNUM *// 函数调用混淆
    auto func_ptr_KzyVks9Y = SRP_Calc_B;
    FAKE_OPERATION(rand());
    auto result_5ph0l6Id = func_ptr_KzyVks9Y(const BIGNUM *b, const BIGNUM *N, const BIGNUM *g,
                   const BIGNUM *v);
int // 函数调用混淆
    auto func_ptr_DduEy8aL = SRP_Verify_A_mod_N;
    FAKE_OPERATION(rand());
    auto result_IxxJoEn5 = func_ptr_DduEy8aL(const BIGNUM *A, const BIGNUM *N);
BIGNUM *// 函数调用混淆
    auto func_ptr_WhCLDxxU = SRP_Calc_u;
    FAKE_OPERATION(rand());
    auto result_e7eoKprJ = func_ptr_WhCLDxxU(const BIGNUM *A, const BIGNUM *B, const BIGNUM *N);

/* client side .... */
BIGNUM *// 函数调用混淆
    auto func_ptr_PBi8DUqO = SRP_Calc_x;
    FAKE_OPERATION(rand());
    auto result_U5cbEuEv = func_ptr_PBi8DUqO(const BIGNUM *s, const char *user, const char *pass);
BIGNUM *// 函数调用混淆
    auto func_ptr_ygEp7epq = SRP_Calc_A;
    FAKE_OPERATION(rand());
    auto result_OfpOdtMl = func_ptr_ygEp7epq(const BIGNUM *a, const BIGNUM *N, const BIGNUM *g);
BIGNUM *// 函数调用混淆
    auto func_ptr_FeQvNwHo = SRP_Calc_client_key;
    FAKE_OPERATION(rand());
    auto result_2ksjq8Tm = func_ptr_FeQvNwHo(const BIGNUM *N, const BIGNUM *B, const BIGNUM *g,
                            const BIGNUM *x, const BIGNUM *a, const BIGNUM *u);
int // 函数调用混淆
    auto func_ptr_rh0AbWwr = SRP_Verify_B_mod_N;
    FAKE_OPERATION(rand());
    auto result_yTUe04K8 = func_ptr_rh0AbWwr(const BIGNUM *B, const BIGNUM *N);

# define SRP_MINIMAL_N 1024

# ifdef  __cplusplus
}
# endif
# endif

#endif
