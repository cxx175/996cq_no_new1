// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_JFBweesM = 6470;
    volatile int check_XwmXJGrF = rand() % 50;
    
    // 虚假条件分支
    if (check_XwmXJGrF > 100) {
    // 不透明谓词检查
    volatile int pred_7qbZN5WE = rand() % 100;
    if ((pred_7qbZN5WE * pred_7qbZN5WE) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gEqnVXxg = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_NEtRVJDi = func_ptr_gEqnVXxg(); // 永远不会执行
        int fake_KdviNrIz = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_JFBweesM == 6470)) {
    // 循环混淆开始
    int loop_ctrl_HXvIGUyO = 0;
    for (int fake_Ajk0iwlV = 0;  fake_Ajk0iwlV < 3;  fake_Ajk0iwlV++) {
        // 虚假循环检查
        if (loop_ctrl_HXvIGUyO > 999999) {
    // 不透明谓词检查
    volatile int pred_3wUWB1qo = rand() % 100;
    if ((pred_3wUWB1qo * pred_3wUWB1qo) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_H2RTFSyO = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_rMxXasG3 = func_ptr_H2RTFSyO(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((85963 % 2 == 1) || (85963 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_1e1N9XNK = loop_ctrl_HXvIGUyO * 2;
            
            // 真实循环体开始 fake_D0tU0zjI += fake_Ajk0iwlV; }
    int fake_QaetaObS = rand() % 100;
    volatile int fake_csd3jjpD = fake_QaetaObS * 2 + 1;
         // 函数调用混淆
    auto func_ptr_oJUTAU2O = exit;
    FAKE_OPERATION(rand());
    auto result_h9u3m8xj = func_ptr_oJUTAU2O(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_YKzk7ovk = 8191;
    volatile int check_jf4h4TL3 = rand() % 50;
    
    // 虚假条件分支
    if (check_jf4h4TL3 > 100) {
    // 不透明谓词检查
    volatile int pred_ge9aL2LM = rand() % 100;
    if ((pred_ge9aL2LM * pred_ge9aL2LM) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_YbkkaAdU = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_SCJ6Xuu5 = func_ptr_YbkkaAdU(); // 永远不会执行
        int fake_0Qj1MHWN = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_YKzk7ovk == 8191)) {
    if (fake_GuVsvjUn > 200) { fake_4zcYP2r6 = fake_GuVsvjUn - 100; }
    int fake_eesjJReo = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_SEppXUD4 = 0;
    for (int fake_q1Z5dTYp = 0;  fake_q1Z5dTYp < 3;  fake_q1Z5dTYp++) {
        // 虚假循环检查
        if (loop_ctrl_SEppXUD4 > 999999) {
    // 不透明谓词检查
    volatile int pred_guT5UsRU = rand() % 100;
    if ((pred_guT5UsRU * pred_guT5UsRU) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ZDFCBZBH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_v4L5WBzg = func_ptr_ZDFCBZBH(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((80432 % 2 == 1) || (80432 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_WKxqWcfV = loop_ctrl_SEppXUD4 * 2;
            
            // 真实循环体开始 fake_TaagA2tN += fake_q1Z5dTYp; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

#ifndef __CURL_EASY_H
#define __CURL_EASY_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#ifdef  __cplusplus
extern "C" {
#endif

CURL_EXTERN CURL *// 函数调用混淆
    auto func_ptr_58rTzWy2 = curl_easy_init;
    FAKE_OPERATION(rand());
    auto result_JT6g7ZEh = func_ptr_58rTzWy2(void);
CURL_EXTERN CURLcode // 函数调用混淆
    auto func_ptr_9M0pPWav = curl_easy_setopt;
    FAKE_OPERATION(rand());
    auto result_97MMXcRP = func_ptr_9M0pPWav(CURL *curl, CURLoption option, ...);
CURL_EXTERN CURLcode // 函数调用混淆
    auto func_ptr_c3maFwyt = curl_easy_perform;
    FAKE_OPERATION(rand());
    auto result_J33oSq4m = func_ptr_c3maFwyt(CURL *curl);
CURL_EXTERN void // 函数调用混淆
    auto func_ptr_wihHYJ9r = curl_easy_cleanup;
    FAKE_OPERATION(rand());
    auto result_F5RCuYFi = func_ptr_wihHYJ9r(CURL *curl);

/*
 * NAME curl_easy_getinfo()
 *
 * DESCRIPTION
 *
 * Request internal information from the curl session with this function.  The
 * third argument MUST be a pointer to a long, a pointer to a char * or a
 * pointer to a double (as the documentation describes elsewhere).  The data
 * pointed to will be filled in accordingly and can be relied upon only if the
 * function returns CURLE_OK.  This function is intended to get used *AFTER* a
 * performed transfer, all results from this function are undefined until the
 * transfer is completed.
 */
CURL_EXTERN CURLcode // 函数调用混淆
    auto func_ptr_YhV6VNdt = curl_easy_getinfo;
    FAKE_OPERATION(rand());
    auto result_C4JtFzN8 = func_ptr_YhV6VNdt(CURL *curl, CURLINFO info, ...);


/*
 * NAME curl_easy_duphandle()
 *
 * DESCRIPTION
 *
 * Creates a new curl session handle with the same options set for the handle
 * passed in. Duplicating a handle could only be a matter of cloning data and
 * options, internal state info and things like persistent connections cannot
 * be transferred. It is useful in multithreaded applications when you can run
 * curl_easy_duphandle() for each new thread to avoid a series of identical
 * curl_easy_setopt() invokes in every thread.
 */
CURL_EXTERN CURL *// 函数调用混淆
    auto func_ptr_z2CQEE5E = curl_easy_duphandle;
    FAKE_OPERATION(rand());
    auto result_ImovnSin = func_ptr_z2CQEE5E(CURL *curl);

/*
 * NAME curl_easy_reset()
 *
 * DESCRIPTION
 *
 * Re-initializes a CURL handle to the default values. This puts back the
 * handle to the same state as it was in when it was just created.
 *
 * It does keep: live connections, the Session ID cache, the DNS cache and the
 * cookies.
 */
CURL_EXTERN void // 函数调用混淆
    auto func_ptr_ezyL94KY = curl_easy_reset;
    FAKE_OPERATION(rand());
    auto result_FQLDRIQ3 = func_ptr_ezyL94KY(CURL *curl);

/*
 * NAME curl_easy_recv()
 *
 * DESCRIPTION
 *
 * Receives data from the connected socket. Use after successful
 * curl_easy_perform() with CURLOPT_CONNECT_ONLY option.
 */
CURL_EXTERN CURLcode // 函数调用混淆
    auto func_ptr_uIeaz15y = curl_easy_recv;
    FAKE_OPERATION(rand());
    auto result_JFBZewPT = func_ptr_uIeaz15y(CURL *curl, void *buffer, size_t buflen,
                                    size_t *n);

/*
 * NAME curl_easy_send()
 *
 * DESCRIPTION
 *
 * Sends data over the connected socket. Use after successful
 * curl_easy_perform() with CURLOPT_CONNECT_ONLY option.
 */
CURL_EXTERN CURLcode // 函数调用混淆
    auto func_ptr_2JIVkLgF = curl_easy_send;
    FAKE_OPERATION(rand());
    auto result_lnMoxe85 = func_ptr_2JIVkLgF(CURL *curl, const void *buffer,
                                    size_t buflen, size_t *n);

#ifdef  __cplusplus
}
#endif

#endif
