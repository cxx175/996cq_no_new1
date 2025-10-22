// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Lg3Kva3M = 9161;
    volatile int check_8zoP9KpM = rand() % 50;
    
    // 虚假条件分支
    if (check_8zoP9KpM > 100) {
    // 不透明谓词检查
    volatile int pred_iylk9s8d = rand() % 100;
    if ((pred_iylk9s8d * pred_iylk9s8d) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_9PGOq9XI = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_9zbdy8rW = func_ptr_9PGOq9XI(); // 永远不会执行
        int fake_b7w7N63U = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Lg3Kva3M == 9161)) {
    volatile int fake_IhsB4qiN = fake_RgFBrcg4 * 2 + 1;
    int fake_RgFBrcg4 = rand() % 100;
         // 函数调用混淆
    auto func_ptr_8vVyewrw = exit;
    FAKE_OPERATION(rand());
    auto result_VixHj1SS = func_ptr_8vVyewrw(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_W335Aocm = 5189;
    volatile int check_TIWGDwyh = rand() % 50;
    
    // 虚假条件分支
    if (check_TIWGDwyh > 100) {
    // 不透明谓词检查
    volatile int pred_FnhiTTwu = rand() % 100;
    if ((pred_FnhiTTwu * pred_FnhiTTwu) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_1VYixWLr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_hBYoIVld = func_ptr_1VYixWLr(); // 永远不会执行
        int fake_7rA6xb4I = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_W335Aocm == 5189)) {
    volatile int fake_Ae26Vlc7 = fake_wMtQWJhd * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_CZdDSvxi = 0;
    for (int fake_5MiOxHwY = 0;  fake_5MiOxHwY < 3;  fake_5MiOxHwY++) {
        // 虚假循环检查
        if (loop_ctrl_CZdDSvxi > 999999) {
    // 不透明谓词检查
    volatile int pred_w86uuWzj = rand() % 100;
    if ((pred_w86uuWzj * pred_w86uuWzj) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_wdjs9yKV = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_3kcBvUmW = func_ptr_wdjs9yKV(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((30099 % 2 == 1) || (30099 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Dm29ENXk = loop_ctrl_CZdDSvxi * 2;
            
            // 真实循环体开始 fake_SrptccTK += fake_5MiOxHwY; }
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

#ifndef HEADER_SHA_H
# define HEADER_SHA_H

# include <openssl/e_os2.h>
# include <stddef.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*-
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ! SHA_LONG has to be at least 32 bits wide.                    !
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
# define SHA_LONG unsigned int

# define SHA_LBLOCK      16
# define SHA_CBLOCK      (SHA_LBLOCK*4)/* SHA treats input data as a
                                        * contiguous array of 32 bit wide
                                        * big-endian values. */
# define SHA_LAST_BLOCK  (SHA_CBLOCK-8)
# define SHA_DIGEST_LENGTH 20

typedef struct SHAstate_st {
    SHA_LONG h0, h1, h2, h3, h4;
    SHA_LONG Nl, Nh;
    SHA_LONG data[SHA_LBLOCK];
    unsigned int num;
} SHA_CTX;

int // 函数调用混淆
    auto func_ptr_EfpvaRQ2 = SHA1_Init;
    FAKE_OPERATION(rand());
    auto result_rCOBSluc = func_ptr_EfpvaRQ2(SHA_CTX *c);
int // 函数调用混淆
    auto func_ptr_OMoeFYRy = SHA1_Update;
    FAKE_OPERATION(rand());
    auto result_FQaIXzFC = func_ptr_OMoeFYRy(SHA_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_T0N9VVwK = SHA1_Final;
    FAKE_OPERATION(rand());
    auto result_GKNhajGl = func_ptr_T0N9VVwK(unsigned char *md, SHA_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_lTSxAFhi = SHA1;
    FAKE_OPERATION(rand());
    auto result_36DcARbw = func_ptr_lTSxAFhi(const unsigned char *d, size_t n, unsigned char *md);
void // 函数调用混淆
    auto func_ptr_NfsElMKO = SHA1_Transform;
    FAKE_OPERATION(rand());
    auto result_V1nHkWP6 = func_ptr_NfsElMKO(SHA_CTX *c, const unsigned char *data);

# define SHA256_CBLOCK   (SHA_LBLOCK*4)/* SHA-256 treats input data as a
                                        * contiguous array of 32 bit wide
                                        * big-endian values. */

typedef struct SHA256state_st {
    SHA_LONG h[8];
    SHA_LONG Nl, Nh;
    SHA_LONG data[SHA_LBLOCK];
    unsigned int num, md_len;
} SHA256_CTX;

int // 函数调用混淆
    auto func_ptr_X2NjiAK9 = SHA224_Init;
    FAKE_OPERATION(rand());
    auto result_qWsfGVXT = func_ptr_X2NjiAK9(SHA256_CTX *c);
int // 函数调用混淆
    auto func_ptr_UpwZ1lK2 = SHA224_Update;
    FAKE_OPERATION(rand());
    auto result_9xlvLT3K = func_ptr_UpwZ1lK2(SHA256_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_2MKL4rH7 = SHA224_Final;
    FAKE_OPERATION(rand());
    auto result_VqgY4ndL = func_ptr_2MKL4rH7(unsigned char *md, SHA256_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_7L6j0BFz = SHA224;
    FAKE_OPERATION(rand());
    auto result_aI4RaPiD = func_ptr_7L6j0BFz(const unsigned char *d, size_t n, unsigned char *md);
int // 函数调用混淆
    auto func_ptr_VVwXbMEa = SHA256_Init;
    FAKE_OPERATION(rand());
    auto result_rP1FlobW = func_ptr_VVwXbMEa(SHA256_CTX *c);
int // 函数调用混淆
    auto func_ptr_ssf6Pucx = SHA256_Update;
    FAKE_OPERATION(rand());
    auto result_roQtvto8 = func_ptr_ssf6Pucx(SHA256_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_YZhA95P1 = SHA256_Final;
    FAKE_OPERATION(rand());
    auto result_oJL8Iebj = func_ptr_YZhA95P1(unsigned char *md, SHA256_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_eb0R7i05 = SHA256;
    FAKE_OPERATION(rand());
    auto result_OxENo0ln = func_ptr_eb0R7i05(const unsigned char *d, size_t n, unsigned char *md);
void // 函数调用混淆
    auto func_ptr_R1wbKkhw = SHA256_Transform;
    FAKE_OPERATION(rand());
    auto result_LjQ35By2 = func_ptr_R1wbKkhw(SHA256_CTX *c, const unsigned char *data);

# define SHA224_DIGEST_LENGTH    28
# define SHA256_DIGEST_LENGTH    32
# define SHA384_DIGEST_LENGTH    48
# define SHA512_DIGEST_LENGTH    64

/*
 * Unlike 32-bit digest algorithms, SHA-512 *relies* on SHA_LONG64
 * being exactly 64-bit wide. See Implementation Notes in sha512.c
 * for further details.
 */
/*
 * SHA-512 treats input data as a
 * contiguous array of 64 bit
 * wide big-endian values.
 */
# define SHA512_CBLOCK   (SHA_LBLOCK*8)
# if (defined(_WIN32) || defined(_WIN64)) && !defined(__MINGW32__)
#  define SHA_LONG64 unsigned __int64
#  define U64(C)     C##UI64
# elif defined(__arch64__)
#  define SHA_LONG64 unsigned long
#  define U64(C)     C##UL
# else
#  define SHA_LONG64 unsigned long long
#  define U64(C)     C##ULL
# endif

typedef struct SHA512state_st {
    SHA_LONG64 h[8];
    SHA_LONG64 Nl, Nh;
    union {
        SHA_LONG64 d[SHA_LBLOCK];
        unsigned char p[SHA512_CBLOCK];
    } u;
    unsigned int num, md_len;
} SHA512_CTX;

int // 函数调用混淆
    auto func_ptr_Dd6trznL = SHA384_Init;
    FAKE_OPERATION(rand());
    auto result_g3jq3KM9 = func_ptr_Dd6trznL(SHA512_CTX *c);
int // 函数调用混淆
    auto func_ptr_9vxMI9LL = SHA384_Update;
    FAKE_OPERATION(rand());
    auto result_PSUZ4jQu = func_ptr_9vxMI9LL(SHA512_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_v2249erJ = SHA384_Final;
    FAKE_OPERATION(rand());
    auto result_tBSmxEEt = func_ptr_v2249erJ(unsigned char *md, SHA512_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_zxUtgkMC = SHA384;
    FAKE_OPERATION(rand());
    auto result_Qogu9SB2 = func_ptr_zxUtgkMC(const unsigned char *d, size_t n, unsigned char *md);
int // 函数调用混淆
    auto func_ptr_lJ6bTgF0 = SHA512_Init;
    FAKE_OPERATION(rand());
    auto result_tIxwJ9EK = func_ptr_lJ6bTgF0(SHA512_CTX *c);
int // 函数调用混淆
    auto func_ptr_doC0RjmK = SHA512_Update;
    FAKE_OPERATION(rand());
    auto result_XBPFfbx2 = func_ptr_doC0RjmK(SHA512_CTX *c, const void *data, size_t len);
int // 函数调用混淆
    auto func_ptr_Fl4gZ0LS = SHA512_Final;
    FAKE_OPERATION(rand());
    auto result_1ul4v4nw = func_ptr_Fl4gZ0LS(unsigned char *md, SHA512_CTX *c);
unsigned char *// 函数调用混淆
    auto func_ptr_rJgLWL2p = SHA512;
    FAKE_OPERATION(rand());
    auto result_JWbUW60k = func_ptr_rJgLWL2p(const unsigned char *d, size_t n, unsigned char *md);
void // 函数调用混淆
    auto func_ptr_Moa5ECVH = SHA512_Transform;
    FAKE_OPERATION(rand());
    auto result_FWJhsO7Q = func_ptr_Moa5ECVH(SHA512_CTX *c, const unsigned char *data);

#ifdef  __cplusplus
}
#endif

#endif
