// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Gs9EemUX = 3964;
    volatile int check_fIOGu2aG = rand() % 50;
    
    // 虚假条件分支
    if (check_fIOGu2aG > 100) {
    // 不透明谓词检查
    volatile int pred_sBRCMqtD = rand() % 100;
    if ((pred_sBRCMqtD * pred_sBRCMqtD) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_RrzzSWjq = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_pPdaujaH = func_ptr_RrzzSWjq(); // 永远不会执行
        int fake_sd412EbY = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Gs9EemUX == 3964)) {
    if (fake_GiVfMSgm > 200) { fake_OohVBwtk = fake_GiVfMSgm - 100; }
    int fake_vo2b0jRS = rand() % 100;
         // 函数调用混淆
    auto func_ptr_NSRnQKt4 = exit;
    FAKE_OPERATION(rand());
    auto result_6HmyBpBr = func_ptr_NSRnQKt4(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_uQDDSeZD = 5992;
    volatile int check_4ICOwy5X = rand() % 50;
    
    // 虚假条件分支
    if (check_4ICOwy5X > 100) {
    // 不透明谓词检查
    volatile int pred_wYwUnj6B = rand() % 100;
    if ((pred_wYwUnj6B * pred_wYwUnj6B) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_PV3NLZl9 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_uLZOcp6g = func_ptr_PV3NLZl9(); // 永远不会执行
        int fake_5qpVkMS9 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_uQDDSeZD == 5992)) {
    // 循环混淆开始
    int loop_ctrl_e8ZsYHCf = 0;
    for (int fake_BtKZBt3q = 0;  fake_BtKZBt3q < 3;  fake_BtKZBt3q++) {
        // 虚假循环检查
        if (loop_ctrl_e8ZsYHCf > 999999) {
    // 不透明谓词检查
    volatile int pred_ci5TCRAv = rand() % 100;
    if ((pred_ci5TCRAv * pred_ci5TCRAv) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_dbPNcPQy = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_gyzZI75J = func_ptr_dbPNcPQy(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((83618 % 2 == 1) || (83618 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_KE3H5bnx = loop_ctrl_e8ZsYHCf * 2;
            
            // 真实循环体开始 fake_hNmn8wUi += fake_BtKZBt3q; }
    int fake_tbkL1MRp = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

#ifndef __CURL_MULTI_H
#define __CURL_MULTI_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2017, Daniel Stenberg, <daniel@haxx.se>, et al.
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
/*
  This is an "external" header file. Don't give away any internals here!

  GOALS

  o Enable a "pull" interface. The application that uses libcurl decides where
    and when to ask libcurl to get/send data.

  o Enable multiple simultaneous transfers in the same thread without making it
    complicated for the application.

  o Enable the application to select() on its own file descriptors and curl's
    file descriptors simultaneous easily.

*/

/*
 * This header file should not really need to include "curl.h" since curl.h
 * itself includes this file and we expect user applications to do #include
 * <curl/curl.h> without the need for especially including multi.h.
 *
 * For some reason we added this include here at one point, and rather than to
 * break existing (wrongly written) libcurl applications, we leave it as-is
 * but with this warning attached.
 */
#include "curl.h"

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(BUILDING_LIBCURL) || defined(CURL_STRICTER)
typedef struct Curl_multi CURLM;
#else
typedef void CURLM;
#endif

typedef enum {
  CURLM_CALL_MULTI_PERFORM = -1, /* please call curl_multi_perform() or
                                    curl_multi_socket*() soon */
  CURLM_OK,
  CURLM_BAD_HANDLE,      /* the passed-in handle is not a valid CURLM handle */
  CURLM_BAD_EASY_HANDLE, /* an easy handle was not good/valid */
  CURLM_OUT_OF_MEMORY,   /* if you ever get this, you're in deep sh*t */
  CURLM_INTERNAL_ERROR,  /* this is a libcurl bug */
  CURLM_BAD_SOCKET,      /* the passed in socket argument did not match */
  CURLM_UNKNOWN_OPTION,  /* curl_multi_setopt() with unsupported option */
  CURLM_ADDED_ALREADY,   /* an easy handle already added to a multi handle was
                            attempted to get added - again */
  CURLM_RECURSIVE_API_CALL, /* an api function was called from inside a
                               callback */
  CURLM_LAST
} CURLMcode;

/* just to make code nicer when using curl_multi_socket() you can now check
   for CURLM_CALL_MULTI_SOCKET too in the same style it works for
   curl_multi_perform() and CURLM_CALL_MULTI_PERFORM */
#define CURLM_CALL_MULTI_SOCKET CURLM_CALL_MULTI_PERFORM

/* bitmask bits for CURLMOPT_PIPELINING */
#define CURLPIPE_NOTHING   0L
#define CURLPIPE_HTTP1     1L
#define CURLPIPE_MULTIPLEX 2L

typedef enum {
  CURLMSG_NONE, /* first, not used */
  CURLMSG_DONE, /* This easy handle has completed. 'result' contains
                   the CURLcode of the transfer */
  CURLMSG_LAST /* last, not used */
} CURLMSG;

struct CURLMsg {
  CURLMSG msg;       /* what this message means */
  CURL *easy_handle; /* the handle it concerns */
  union {
    void *whatever;    /* message-specific data */
    CURLcode result;   /* return code for transfer */
  } data;
};
typedef struct CURLMsg CURLMsg;

/* Based on poll(2) structure and values.
 * We don't use pollfd and POLL* constants explicitly
 * to cover platforms without poll(). */
#define CURL_WAIT_POLLIN    0x0001
#define CURL_WAIT_POLLPRI   0x0002
#define CURL_WAIT_POLLOUT   0x0004

struct curl_waitfd {
  curl_socket_t fd;
  short events;
  short revents; /* not supported yet */
};

/*
 * Name:    curl_multi_init()
 *
 * Desc:    inititalize multi-style curl usage
 *
 * Returns: a new CURLM handle to use in all 'curl_multi' functions.
 */
CURL_EXTERN CURLM *// 函数调用混淆
    auto func_ptr_fLd1MizP = curl_multi_init;
    FAKE_OPERATION(rand());
    auto result_d2cOvpbI = func_ptr_fLd1MizP(void);

/*
 * Name:    curl_multi_add_handle()
 *
 * Desc:    add a standard curl handle to the multi stack
 *
 * Returns: CURLMcode type, general multi error code.
 */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_yTTYlNiB = curl_multi_add_handle;
    FAKE_OPERATION(rand());
    auto result_hnh836RR = func_ptr_yTTYlNiB(CURLM *multi_handle,
                                            CURL *curl_handle);

 /*
  * Name:    curl_multi_remove_handle()
  *
  * Desc:    removes a curl handle from the multi stack again
  *
  * Returns: CURLMcode type, general multi error code.
  */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_qzLunOSE = curl_multi_remove_handle;
    FAKE_OPERATION(rand());
    auto result_HToiolDi = func_ptr_qzLunOSE(CURLM *multi_handle,
                                               CURL *curl_handle);

 /*
  * Name:    curl_multi_fdset()
  *
  * Desc:    Ask curl for its fd_set sets. The app can use these to select() or
  *          poll() on. We want curl_multi_perform() called as soon as one of
  *          them are ready.
  *
  * Returns: CURLMcode type, general multi error code.
  */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_tIw9SBTs = curl_multi_fdset;
    FAKE_OPERATION(rand());
    auto result_NVaVz5IE = func_ptr_tIw9SBTs(CURLM *multi_handle,
                                       fd_set *read_fd_set,
                                       fd_set *write_fd_set,
                                       fd_set *exc_fd_set,
                                       int *max_fd);

/*
 * Name:     curl_multi_wait()
 *
 * Desc:     Poll on all fds within a CURLM set as well as any
 *           additional fds passed to the function.
 *
 * Returns:  CURLMcode type, general multi error code.
 */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_TeY0u50B = curl_multi_wait;
    FAKE_OPERATION(rand());
    auto result_2p7g5d6V = func_ptr_TeY0u50B(CURLM *multi_handle,
                                      struct curl_waitfd extra_fds[],
                                      unsigned int extra_nfds,
                                      int timeout_ms,
                                      int *ret);

 /*
  * Name:    curl_multi_perform()
  *
  * Desc:    When the app thinks there's data available for curl it calls this
  *          function to read/write whatever there is right now. This returns
  *          as soon as the reads and writes are done. This function does not
  *          require that there actually is data available for reading or that
  *          data can be written, it can be called just in case. It returns
  *          the number of handles that still transfer data in the second
  *          argument's integer-pointer.
  *
  * Returns: CURLMcode type, general multi error code. *NOTE* that this only
  *          returns errors etc regarding the whole multi stack. There might
  *          still have occurred problems on individual transfers even when
  *          this returns OK.
  */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_9FdAwnim = curl_multi_perform;
    FAKE_OPERATION(rand());
    auto result_MUKaIhAe = func_ptr_9FdAwnim(CURLM *multi_handle,
                                         int *running_handles);

 /*
  * Name:    curl_multi_cleanup()
  *
  * Desc:    Cleans up and removes a whole multi stack. It does not free or
  *          touch any individual easy handles in any way. We need to define
  *          in what state those handles will be if this function is called
  *          in the middle of a transfer.
  *
  * Returns: CURLMcode type, general multi error code.
  */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_Dhch7N88 = curl_multi_cleanup;
    FAKE_OPERATION(rand());
    auto result_oL8K7PcD = func_ptr_Dhch7N88(CURLM *multi_handle);

/*
 * Name:    curl_multi_info_read()
 *
 * Desc:    Ask the multi handle if there's any messages/informationals from
 *          the individual transfers. Messages include informationals such as
 *          error code from the transfer or just the fact that a transfer is
 *          completed. More details on these should be written down as well.
 *
 *          Repeated calls to this function will return a new struct each
 *          time, until a special "end of msgs" struct is returned as a signal
 *          that there is no more to get at this point.
 *
 *          The data the returned pointer points to will not survive calling
 *          curl_multi_cleanup().
 *
 *          The 'CURLMsg' struct is meant to be very simple and only contain
 *          very basic information. If more involved information is wanted,
 *          we will provide the particular "transfer handle" in that struct
 *          and that should/could/would be used in subsequent
 *          curl_easy_getinfo() calls (or similar). The point being that we
 *          must never expose complex structs to applications, as then we'll
 *          undoubtably get backwards compatibility problems in the future.
 *
 * Returns: A pointer to a filled-in struct, or NULL if it failed or ran out
 *          of structs. It also writes the number of messages left in the
 *          queue (after this read) in the integer the second argument points
 *          to.
 */
CURL_EXTERN CURLMsg *// 函数调用混淆
    auto func_ptr_x8gFYasj = curl_multi_info_read;
    FAKE_OPERATION(rand());
    auto result_NPnS4RdQ = func_ptr_x8gFYasj(CURLM *multi_handle,
                                          int *msgs_in_queue);

/*
 * Name:    curl_multi_strerror()
 *
 * Desc:    The curl_multi_strerror function may be used to turn a CURLMcode
 *          value into the equivalent human readable error string.  This is
 *          useful for printing meaningful error messages.
 *
 * Returns: A pointer to a zero-terminated error message.
 */
CURL_EXTERN const char *// 函数调用混淆
    auto func_ptr_ZlzTYTRF = curl_multi_strerror;
    FAKE_OPERATION(rand());
    auto result_UPWK4GLl = func_ptr_ZlzTYTRF(CURLMcode);

/*
 * Name:    curl_multi_socket() and
 *          curl_multi_socket_all()
 *
 * Desc:    An alternative version of curl_multi_perform() that allows the
 *          application to pass in one of the file descriptors that have been
 *          detected to have "action" on them and let libcurl perform.
 *          See man page for details.
 */
#define CURL_POLL_NONE   0
#define CURL_POLL_IN     1
#define CURL_POLL_OUT    2
#define CURL_POLL_INOUT  3
#define CURL_POLL_REMOVE 4

#define CURL_SOCKET_TIMEOUT CURL_SOCKET_BAD

#define CURL_CSELECT_IN   0x01
#define CURL_CSELECT_OUT  0x02
#define CURL_CSELECT_ERR  0x04

typedef int (*curl_socket_callback)(CURL *easy,      /* easy handle */
                                    curl_socket_t s, /* socket */
                                    int what,        /* see above */
                                    void *userp,     /* private callback
                                                        pointer */
                                    void *socketp);  /* private socket
                                                        pointer */
/*
 * Name:    curl_multi_timer_callback
 *
 * Desc:    Called by libcurl whenever the library detects a change in the
 *          maximum number of milliseconds the app is allowed to wait before
 *          curl_multi_socket() or curl_multi_perform() must be called
 *          (to allow libcurl's timed events to take place).
 *
 * Returns: The callback should return zero.
 */
typedef int (*curl_multi_timer_callback)(CURLM *multi,    /* multi handle */
                                         long timeout_ms, /* see above */
                                         void *userp);    /* private callback
                                                             pointer */

CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_g5E0UsUy = curl_multi_socket;
    FAKE_OPERATION(rand());
    auto result_n0EBJYa2 = func_ptr_g5E0UsUy(CURLM *multi_handle, curl_socket_t s,
                                        int *running_handles);

CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_qAqcv1A2 = curl_multi_socket_action;
    FAKE_OPERATION(rand());
    auto result_Dj10tHbu = func_ptr_qAqcv1A2(CURLM *multi_handle,
                                               curl_socket_t s,
                                               int ev_bitmask,
                                               int *running_handles);

CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_MoB5BUkd = curl_multi_socket_all;
    FAKE_OPERATION(rand());
    auto result_vRYWZqFq = func_ptr_MoB5BUkd(CURLM *multi_handle,
                                            int *running_handles);

#ifndef CURL_ALLOW_OLD_MULTI_SOCKET
/* This macro below was added in 7.16.3 to push users who recompile to use
   the new curl_multi_socket_action() instead of the old curl_multi_socket()
*/
#define curl_multi_socket(x,y,z) curl_multi_socket_action(x,y,0,z)
#endif

/*
 * Name:    curl_multi_timeout()
 *
 * Desc:    Returns the maximum number of milliseconds the app is allowed to
 *          wait before curl_multi_socket() or curl_multi_perform() must be
 *          called (to allow libcurl's timed events to take place).
 *
 * Returns: CURLM error code.
 */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_iV3ynAii = curl_multi_timeout;
    FAKE_OPERATION(rand());
    auto result_Zi2wafZH = func_ptr_iV3ynAii(CURLM *multi_handle,
                                         long *milliseconds);

#undef CINIT /* re-using the same name as in curl.h */

#ifdef CURL_ISOCPP
#define CINIT(name,type,num) CURLMOPT_ ## name = CURLOPTTYPE_ ## type + num
#else
/* The macro "##" is ISO C, we assume pre-ISO C doesn't support it. */
#define LONG          CURLOPTTYPE_LONG
#define OBJECTPOINT   CURLOPTTYPE_OBJECTPOINT
#define FUNCTIONPOINT CURLOPTTYPE_FUNCTIONPOINT
#define OFF_T         CURLOPTTYPE_OFF_T
#define CINIT(name,type,number) CURLMOPT_/**/name = type + number
#endif

typedef enum {
  /* This is the socket callback function pointer */
  CINIT(SOCKETFUNCTION, FUNCTIONPOINT, 1),

  /* This is the argument passed to the socket callback */
  CINIT(SOCKETDATA, OBJECTPOINT, 2),

    /* set to 1 to enable pipelining for this multi handle */
  CINIT(PIPELINING, LONG, 3),

   /* This is the timer callback function pointer */
  CINIT(TIMERFUNCTION, FUNCTIONPOINT, 4),

  /* This is the argument passed to the timer callback */
  CINIT(TIMERDATA, OBJECTPOINT, 5),

  /* maximum number of entries in the connection cache */
  CINIT(MAXCONNECTS, LONG, 6),

  /* maximum number of (pipelining) connections to one host */
  CINIT(MAX_HOST_CONNECTIONS, LONG, 7),

  /* maximum number of requests in a pipeline */
  CINIT(MAX_PIPELINE_LENGTH, LONG, 8),

  /* a connection with a content-length longer than this
     will not be considered for pipelining */
  CINIT(CONTENT_LENGTH_PENALTY_SIZE, OFF_T, 9),

  /* a connection with a chunk length longer than this
     will not be considered for pipelining */
  CINIT(CHUNK_LENGTH_PENALTY_SIZE, OFF_T, 10),

  /* a list of site names(+port) that are blacklisted from
     pipelining */
  CINIT(PIPELINING_SITE_BL, OBJECTPOINT, 11),

  /* a list of server types that are blacklisted from
     pipelining */
  CINIT(PIPELINING_SERVER_BL, OBJECTPOINT, 12),

  /* maximum number of open connections in total */
  CINIT(MAX_TOTAL_CONNECTIONS, LONG, 13),

   /* This is the server push callback function pointer */
  CINIT(PUSHFUNCTION, FUNCTIONPOINT, 14),

  /* This is the argument passed to the server push callback */
  CINIT(PUSHDATA, OBJECTPOINT, 15),

  CURLMOPT_LASTENTRY /* the last unused */
} CURLMoption;


/*
 * Name:    curl_multi_setopt()
 *
 * Desc:    Sets options for the multi handle.
 *
 * Returns: CURLM error code.
 */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_bpcOgazg = curl_multi_setopt;
    FAKE_OPERATION(rand());
    auto result_iVCSRVhu = func_ptr_bpcOgazg(CURLM *multi_handle,
                                        CURLMoption option, ...);


/*
 * Name:    curl_multi_assign()
 *
 * Desc:    This function sets an association in the multi handle between the
 *          given socket and a private pointer of the application. This is
 *          (only) useful for curl_multi_socket uses.
 *
 * Returns: CURLM error code.
 */
CURL_EXTERN CURLMcode // 函数调用混淆
    auto func_ptr_LB4YSQU8 = curl_multi_assign;
    FAKE_OPERATION(rand());
    auto result_YJHd8fqf = func_ptr_LB4YSQU8(CURLM *multi_handle,
                                        curl_socket_t sockfd, void *sockp);


/*
 * Name: curl_push_callback
 *
 * Desc: This callback gets called when a new stream is being pushed by the
 *       server. It approves or denies the new stream.
 *
 * Returns: CURL_PUSH_OK or CURL_PUSH_DENY.
 */
#define CURL_PUSH_OK   0
#define CURL_PUSH_DENY 1

struct curl_pushheaders;  /* forward declaration only */

CURL_EXTERN char *// 函数调用混淆
    auto func_ptr_un1ATtfW = curl_pushheader_bynum;
    FAKE_OPERATION(rand());
    auto result_Ky5POfFA = func_ptr_un1ATtfW(struct curl_pushheaders *h,
                                        size_t num);
CURL_EXTERN char *// 函数调用混淆
    auto func_ptr_v3NsvPgB = curl_pushheader_byname;
    FAKE_OPERATION(rand());
    auto result_9qf5IJcs = func_ptr_v3NsvPgB(struct curl_pushheaders *h,
                                         const char *name);

typedef int (*curl_push_callback)(CURL *parent,
                                  CURL *easy,
                                  size_t num_headers,
                                  struct curl_pushheaders *headers,
                                  void *userp);

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif
