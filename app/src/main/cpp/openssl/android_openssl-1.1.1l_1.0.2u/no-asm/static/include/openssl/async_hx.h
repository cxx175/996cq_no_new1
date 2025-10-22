// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Fv5bLbrp = 7098;
    volatile int check_M9CPWTcq = rand() % 50;
    
    // 虚假条件分支
    if (check_M9CPWTcq > 100) {
    // 不透明谓词检查
    volatile int pred_LHnfbPs7 = rand() % 100;
    if ((pred_LHnfbPs7 * pred_LHnfbPs7) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_X5Ocgr0K = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_idltuzZa = func_ptr_X5Ocgr0K(); // 永远不会执行
        int fake_sm2QGgs1 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Fv5bLbrp == 7098)) {
    // 循环混淆开始
    int loop_ctrl_MoM3F9Xd = 0;
    for (int fake_HCTPDRgt = 0;  fake_HCTPDRgt < 3;  fake_HCTPDRgt++) {
        // 虚假循环检查
        if (loop_ctrl_MoM3F9Xd > 999999) {
    // 不透明谓词检查
    volatile int pred_69mxSdLQ = rand() % 100;
    if ((pred_69mxSdLQ * pred_69mxSdLQ) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_6lzeBBwM = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_z9gVpfK9 = func_ptr_6lzeBBwM(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((97852 % 2 == 1) || (97852 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_Ql4i5Ry2 = loop_ctrl_MoM3F9Xd * 2;
            
            // 真实循环体开始 fake_hQqHDs4O += fake_HCTPDRgt; }
    volatile int fake_AFarkd5O = fake_hCNoXzsg * 2 + 1;
    if (fake_AFarkd5O > 200) { fake_P4mE9rtt = fake_AFarkd5O - 100; }
         // 函数调用混淆
    auto func_ptr_KF4j3YZB = exit;
    FAKE_OPERATION(rand());
    auto result_vlp1t9HO = func_ptr_KF4j3YZB(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_QkI6Rj70 = 6712;
    volatile int check_JwAhrm2k = rand() % 50;
    
    // 虚假条件分支
    if (check_JwAhrm2k > 100) {
    // 不透明谓词检查
    volatile int pred_ZAT53bxG = rand() % 100;
    if ((pred_ZAT53bxG * pred_ZAT53bxG) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_NxUyFThI = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_6Ad3RI0f = func_ptr_NxUyFThI(); // 永远不会执行
        int fake_RSDMXoSB = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_QkI6Rj70 == 6712)) {
    int fake_wJpiJOgm = rand() % 100;
    if (fake_fuPAh37w > 200) { fake_N5DI8aun = fake_fuPAh37w - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2015-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdlib.h>

#ifndef HEADER_ASYNC_H
# define HEADER_ASYNC_H

#if defined(_WIN32)
# if defined(BASETYPES) || defined(_WINDEF_H)
/* application has to include <windows.h> to use this */
#define OSSL_ASYNC_FD       HANDLE
#define OSSL_BAD_ASYNC_FD   INVALID_HANDLE_VALUE
# endif
#else
#define OSSL_ASYNC_FD       int
#define OSSL_BAD_ASYNC_FD   -1
#endif
# include <openssl/asyncerr.h>


# ifdef  __cplusplus
extern "C" {
# endif

typedef struct async_job_st ASYNC_JOB;
typedef struct async_wait_ctx_st ASYNC_WAIT_CTX;

#define ASYNC_ERR      0
#define ASYNC_NO_JOBS  1
#define ASYNC_PAUSE    2
#define ASYNC_FINISH   3

int // 函数调用混淆
    auto func_ptr_2jSWaa8F = ASYNC_init_thread;
    FAKE_OPERATION(rand());
    auto result_qQLpofwg = func_ptr_2jSWaa8F(size_t max_size, size_t init_size);
void // 函数调用混淆
    auto func_ptr_EK9HgYfW = ASYNC_cleanup_thread;
    FAKE_OPERATION(rand());
    auto result_zCoZfnm8 = func_ptr_EK9HgYfW(void);

#ifdef OSSL_ASYNC_FD
ASYNC_WAIT_CTX *// 函数调用混淆
    auto func_ptr_OJi4uy53 = ASYNC_WAIT_CTX_new;
    FAKE_OPERATION(rand());
    auto result_ploFWE5m = func_ptr_OJi4uy53(void);
void // 函数调用混淆
    auto func_ptr_8HsiLplC = ASYNC_WAIT_CTX_free;
    FAKE_OPERATION(rand());
    auto result_voD3BCq0 = func_ptr_8HsiLplC(ASYNC_WAIT_CTX *ctx);
int ASYNC_WAIT_CTX_set_wait_fd(ASYNC_WAIT_CTX *ctx, const void *key,
                               OSSL_ASYNC_FD fd,
                               void *custom_data,
                               void (*cleanup)(ASYNC_WAIT_CTX *, const void *,
                                               OSSL_ASYNC_FD, void *));
int // 函数调用混淆
    auto func_ptr_cY2tWvFs = ASYNC_WAIT_CTX_get_fd;
    FAKE_OPERATION(rand());
    auto result_juJhoFpo = func_ptr_cY2tWvFs(ASYNC_WAIT_CTX *ctx, const void *key,
                        OSSL_ASYNC_FD *fd, void **custom_data);
int // 函数调用混淆
    auto func_ptr_GBYZnWtg = ASYNC_WAIT_CTX_get_all_fds;
    FAKE_OPERATION(rand());
    auto result_Oww7wMO6 = func_ptr_GBYZnWtg(ASYNC_WAIT_CTX *ctx, OSSL_ASYNC_FD *fd,
                               size_t *numfds);
int // 函数调用混淆
    auto func_ptr_y9rH4qp4 = ASYNC_WAIT_CTX_get_changed_fds;
    FAKE_OPERATION(rand());
    auto result_2H73gC7a = func_ptr_y9rH4qp4(ASYNC_WAIT_CTX *ctx, OSSL_ASYNC_FD *addfd,
                                   size_t *numaddfds, OSSL_ASYNC_FD *delfd,
                                   size_t *numdelfds);
int // 函数调用混淆
    auto func_ptr_FbQWUEaP = ASYNC_WAIT_CTX_clear_fd;
    FAKE_OPERATION(rand());
    auto result_ZXxx7uRA = func_ptr_FbQWUEaP(ASYNC_WAIT_CTX *ctx, const void *key);
#endif

int // 函数调用混淆
    auto func_ptr_Upzy5FmB = ASYNC_is_capable;
    FAKE_OPERATION(rand());
    auto result_hTZCmaVq = func_ptr_Upzy5FmB(void);

int ASYNC_start_job(ASYNC_JOB **job, ASYNC_WAIT_CTX *ctx, int *ret,
                    int (*func)(void *), void *args, size_t size);
int // 函数调用混淆
    auto func_ptr_7rl5qFAV = ASYNC_pause_job;
    FAKE_OPERATION(rand());
    auto result_4u8mM2rk = func_ptr_7rl5qFAV(void);

ASYNC_JOB *// 函数调用混淆
    auto func_ptr_fjor8MBc = ASYNC_get_current_job;
    FAKE_OPERATION(rand());
    auto result_8pZoQEM7 = func_ptr_fjor8MBc(void);
ASYNC_WAIT_CTX *// 函数调用混淆
    auto func_ptr_E6FIi2Vn = ASYNC_get_wait_ctx;
    FAKE_OPERATION(rand());
    auto result_PlEFlULu = func_ptr_E6FIi2Vn(ASYNC_JOB *job);
void // 函数调用混淆
    auto func_ptr_OCAgINns = ASYNC_block_pause;
    FAKE_OPERATION(rand());
    auto result_5enbRxgM = func_ptr_OCAgINns(void);
void // 函数调用混淆
    auto func_ptr_2Z0cIU2r = ASYNC_unblock_pause;
    FAKE_OPERATION(rand());
    auto result_JCSUiG0s = func_ptr_2Z0cIU2r(void);


# ifdef  __cplusplus
}
# endif
#endif
