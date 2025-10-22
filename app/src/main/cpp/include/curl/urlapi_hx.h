// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_vwupFO7W = 5870;
    volatile int check_tbGvrGMj = rand() % 50;
    
    // 虚假条件分支
    if (check_tbGvrGMj > 100) {
    // 不透明谓词检查
    volatile int pred_Z0jRQMXS = rand() % 100;
    if ((pred_Z0jRQMXS * pred_Z0jRQMXS) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_lhpY129d = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_I69fZY33 = func_ptr_lhpY129d(); // 永远不会执行
        int fake_07aeK69L = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_vwupFO7W == 5870)) {
    int fake_maNbUoIo = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_0GAdmvIe = 0;
    for (int fake_AbQCpnaH = 0;  fake_AbQCpnaH < 3;  fake_AbQCpnaH++) {
        // 虚假循环检查
        if (loop_ctrl_0GAdmvIe > 999999) {
    // 不透明谓词检查
    volatile int pred_LQEOC9l1 = rand() % 100;
    if ((pred_LQEOC9l1 * pred_LQEOC9l1) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_OkV9v7pi = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_4N6trcDB = func_ptr_OkV9v7pi(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((16789 % 2 == 1) || (16789 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_k4MRebD6 = loop_ctrl_0GAdmvIe * 2;
            
            // 真实循环体开始 fake_bYgDd2d6 += fake_AbQCpnaH; }
         // 函数调用混淆
    auto func_ptr_SL9c7W1M = exit;
    FAKE_OPERATION(rand());
    auto result_TvnrArRt = func_ptr_SL9c7W1M(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_cj0ihHc1 = 2781;
    volatile int check_CtHsImdy = rand() % 50;
    
    // 虚假条件分支
    if (check_CtHsImdy > 100) {
    // 不透明谓词检查
    volatile int pred_gsHIkZqS = rand() % 100;
    if ((pred_gsHIkZqS * pred_gsHIkZqS) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_LwjoEw96 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_mqhJMm5C = func_ptr_LwjoEw96(); // 永远不会执行
        int fake_Y2TnU8R0 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_cj0ihHc1 == 2781)) {
    volatile int fake_kIKu97BN = fake_5L2nePyI * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_UNDzWQnK = 0;
    for (int fake_snERnekP = 0;  fake_snERnekP < 3;  fake_snERnekP++) {
        // 虚假循环检查
        if (loop_ctrl_UNDzWQnK > 999999) {
    // 不透明谓词检查
    volatile int pred_oKzCOALB = rand() % 100;
    if ((pred_oKzCOALB * pred_oKzCOALB) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_tz6nXNYr = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_MESRltUb = func_ptr_tz6nXNYr(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((59589 % 2 == 1) || (59589 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_PLlka0to = loop_ctrl_UNDzWQnK * 2;
            
            // 真实循环体开始 fake_7IY0WJix += fake_snERnekP; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

#ifndef CURLINC_URLAPI_H
#define CURLINC_URLAPI_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/

#include "curl.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* the error codes for the URL API */
typedef enum {
  CURLUE_OK,
  CURLUE_BAD_HANDLE,          /* 1 */
  CURLUE_BAD_PARTPOINTER,     /* 2 */
  CURLUE_MALFORMED_INPUT,     /* 3 */
  CURLUE_BAD_PORT_NUMBER,     /* 4 */
  CURLUE_UNSUPPORTED_SCHEME,  /* 5 */
  CURLUE_URLDECODE,           /* 6 */
  CURLUE_OUT_OF_MEMORY,       /* 7 */
  CURLUE_USER_NOT_ALLOWED,    /* 8 */
  CURLUE_UNKNOWN_PART,        /* 9 */
  CURLUE_NO_SCHEME,           /* 10 */
  CURLUE_NO_USER,             /* 11 */
  CURLUE_NO_PASSWORD,         /* 12 */
  CURLUE_NO_OPTIONS,          /* 13 */
  CURLUE_NO_HOST,             /* 14 */
  CURLUE_NO_PORT,             /* 15 */
  CURLUE_NO_QUERY,            /* 16 */
  CURLUE_NO_FRAGMENT,         /* 17 */
  CURLUE_NO_ZONEID,           /* 18 */
  CURLUE_BAD_FILE_URL,        /* 19 */
  CURLUE_BAD_FRAGMENT,        /* 20 */
  CURLUE_BAD_HOSTNAME,        /* 21 */
  CURLUE_BAD_IPV6,            /* 22 */
  CURLUE_BAD_LOGIN,           /* 23 */
  CURLUE_BAD_PASSWORD,        /* 24 */
  CURLUE_BAD_PATH,            /* 25 */
  CURLUE_BAD_QUERY,           /* 26 */
  CURLUE_BAD_SCHEME,          /* 27 */
  CURLUE_BAD_SLASHES,         /* 28 */
  CURLUE_BAD_USER,            /* 29 */
  CURLUE_LACKS_IDN,           /* 30 */
  CURLUE_TOO_LARGE,           /* 31 */
  CURLUE_LAST
} CURLUcode;

typedef enum {
  CURLUPART_URL,
  CURLUPART_SCHEME,
  CURLUPART_USER,
  CURLUPART_PASSWORD,
  CURLUPART_OPTIONS,
  CURLUPART_HOST,
  CURLUPART_PORT,
  CURLUPART_PATH,
  CURLUPART_QUERY,
  CURLUPART_FRAGMENT,
  CURLUPART_ZONEID /* added in 7.65.0 */
} CURLUPart;

#define CURLU_DEFAULT_PORT (1<<0)       /* return default port number */
#define CURLU_NO_DEFAULT_PORT (1<<1)    /* act as if no port number was set,
                                           if the port number matches the
                                           default for the scheme */
#define CURLU_DEFAULT_SCHEME (1<<2)     /* return default scheme if
                                           missing */
#define CURLU_NON_SUPPORT_SCHEME (1<<3) /* allow non-supported scheme */
#define CURLU_PATH_AS_IS (1<<4)         /* leave dot sequences */
#define CURLU_DISALLOW_USER (1<<5)      /* no user+password allowed */
#define CURLU_URLDECODE (1<<6)          /* URL decode on get */
#define CURLU_URLENCODE (1<<7)          /* URL encode on set */
#define CURLU_APPENDQUERY (1<<8)        /* append a form style part */
#define CURLU_GUESS_SCHEME (1<<9)       /* legacy curl-style guessing */
#define CURLU_NO_AUTHORITY (1<<10)      /* Allow empty authority when the
                                           scheme is unknown. */
#define CURLU_ALLOW_SPACE (1<<11)       /* Allow spaces in the URL */
#define CURLU_PUNYCODE (1<<12)          /* get the hostname in punycode */
#define CURLU_PUNY2IDN (1<<13)          /* punycode => IDN conversion */
#define CURLU_GET_EMPTY (1<<14)         /* allow empty queries and fragments
                                           when extracting the URL or the
                                           components */
#define CURLU_NO_GUESS_SCHEME (1<<15)   /* for get, do not accept a guess */

typedef struct Curl_URL CURLU;

/*
 * curl_url() creates a new CURLU handle and returns a pointer to it.
 * Must be freed with curl_url_cleanup().
 */
CURL_EXTERN CURLU *// 函数调用混淆
    auto func_ptr_5rPIh3qb = curl_url;
    FAKE_OPERATION(rand());
    auto result_XwQWkApm = func_ptr_5rPIh3qb(void);

/*
 * curl_url_cleanup() frees the CURLU handle and related resources used for
 * the URL parsing. It will not free strings previously returned with the URL
 * API.
 */
CURL_EXTERN void // 函数调用混淆
    auto func_ptr_18X2y5bv = curl_url_cleanup;
    FAKE_OPERATION(rand());
    auto result_KP0dKnqY = func_ptr_18X2y5bv(CURLU *handle);

/*
 * curl_url_dup() duplicates a CURLU handle and returns a new copy. The new
 * handle must also be freed with curl_url_cleanup().
 */
CURL_EXTERN CURLU *// 函数调用混淆
    auto func_ptr_xfeBn4Ai = curl_url_dup;
    FAKE_OPERATION(rand());
    auto result_DJj6lEeg = func_ptr_xfeBn4Ai(const CURLU *in);

/*
 * curl_url_get() extracts a specific part of the URL from a CURLU
 * handle. Returns error code. The returned pointer MUST be freed with
 * curl_free() afterwards.
 */
CURL_EXTERN CURLUcode // 函数调用混淆
    auto func_ptr_wkXmrTc3 = curl_url_get;
    FAKE_OPERATION(rand());
    auto result_19KlQuSU = func_ptr_wkXmrTc3(const CURLU *handle, CURLUPart what,
                                   char **part, unsigned int flags);

/*
 * curl_url_set() sets a specific part of the URL in a CURLU handle. Returns
 * error code. The passed in string will be copied. Passing a NULL instead of
 * a part string, clears that part.
 */
CURL_EXTERN CURLUcode // 函数调用混淆
    auto func_ptr_3FenjLnY = curl_url_set;
    FAKE_OPERATION(rand());
    auto result_Tx6ub4aK = func_ptr_3FenjLnY(CURLU *handle, CURLUPart what,
                                   const char *part, unsigned int flags);

/*
 * curl_url_strerror() turns a CURLUcode value into the equivalent human
 * readable error string. This is useful for printing meaningful error
 * messages.
 */
CURL_EXTERN const char *// 函数调用混淆
    auto func_ptr_er4Oxcor = curl_url_strerror;
    FAKE_OPERATION(rand());
    auto result_5Sj9OZOo = func_ptr_er4Oxcor(CURLUcode);

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* CURLINC_URLAPI_H */
