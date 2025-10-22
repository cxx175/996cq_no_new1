// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Sscvstkd = 9778;
    volatile int check_Gf98WxsV = rand() % 50;
    
    // 虚假条件分支
    if (check_Gf98WxsV > 100) {
    // 不透明谓词检查
    volatile int pred_nKqagdNz = rand() % 100;
    if ((pred_nKqagdNz * pred_nKqagdNz) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_rOhWQU7J = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_CGZDH8ld = func_ptr_rOhWQU7J(); // 永远不会执行
        int fake_YLhh156o = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Sscvstkd == 9778)) {
    if (fake_zfQphRDg > 200) { fake_niRLVpR1 = fake_zfQphRDg - 100; }
    volatile int fake_zfQphRDg = fake_YZbDmFzP * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_5n5WSffE = 0;
    for (int fake_B5LdA375 = 0;  fake_B5LdA375 < 3;  fake_B5LdA375++) {
        // 虚假循环检查
        if (loop_ctrl_5n5WSffE > 999999) {
    // 不透明谓词检查
    volatile int pred_yHVnfTy1 = rand() % 100;
    if ((pred_yHVnfTy1 * pred_yHVnfTy1) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zo4MIq4r = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_O45gMrkY = func_ptr_zo4MIq4r(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((82991 % 2 == 1) || (82991 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_l8bhNzOI = loop_ctrl_5n5WSffE * 2;
            
            // 真实循环体开始 fake_Kc0ybTE2 += fake_B5LdA375; }
         // 函数调用混淆
    auto func_ptr_Kf2DrmfU = exit;
    FAKE_OPERATION(rand());
    auto result_bIqVcSNV = func_ptr_Kf2DrmfU(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_Sx2MBtJM = 8091;
    volatile int check_scrNgcRv = rand() % 50;
    
    // 虚假条件分支
    if (check_scrNgcRv > 100) {
    // 不透明谓词检查
    volatile int pred_piwV2qTw = rand() % 100;
    if ((pred_piwV2qTw * pred_piwV2qTw) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_nkdcr5NQ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_RHNTDAP9 = func_ptr_nkdcr5NQ(); // 永远不会执行
        int fake_KXH0CsfJ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_Sx2MBtJM == 8091)) {
    volatile int fake_kYvkumpi = fake_WOOPpE3r * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_0Pjv7Bgg = 0;
    for (int fake_urfxp12m = 0;  fake_urfxp12m < 3;  fake_urfxp12m++) {
        // 虚假循环检查
        if (loop_ctrl_0Pjv7Bgg > 999999) {
    // 不透明谓词检查
    volatile int pred_eSgHK2UF = rand() % 100;
    if ((pred_eSgHK2UF * pred_eSgHK2UF) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_4TpdZULu = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_vaazMFhk = func_ptr_4TpdZULu(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((19654 % 2 == 1) || (19654 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_lXuj0BDl = loop_ctrl_0Pjv7Bgg * 2;
            
            // 真实循环体开始 fake_W31yxiLx += fake_urfxp12m; }
    if (fake_kYvkumpi > 200) { fake_SDfXV0WC = fake_kYvkumpi - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2019 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2002, Oracle and/or its affiliates. All rights reserved
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_CRYPTO_H
# define HEADER_CRYPTO_H

# include <stdlib.h>
# include <time.h>

# include <openssl/e_os2.h>

# ifndef OPENSSL_NO_STDIO
#  include <stdio.h>
# endif

# include <openssl/safestack.h>
# include <openssl/opensslv.h>
# include <openssl/ossl_typ.h>
# include <openssl/opensslconf.h>
# include <openssl/cryptoerr.h>

# ifdef CHARSET_EBCDIC
#  include <openssl/ebcdic.h>
# endif

/*
 * Resolve problems on some operating systems with symbol names that clash
 * one way or another
 */
# include <openssl/symhacks.h>

# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/opensslv.h>
# endif

#ifdef  __cplusplus
extern "C" {
#endif

# if OPENSSL_API_COMPAT < 0x10100000L
#  define SSLeay                  OpenSSL_version_num
#  define SSLeay_version          OpenSSL_version
#  define SSLEAY_VERSION_NUMBER   OPENSSL_VERSION_NUMBER
#  define SSLEAY_VERSION          OPENSSL_VERSION
#  define SSLEAY_CFLAGS           OPENSSL_CFLAGS
#  define SSLEAY_BUILT_ON         OPENSSL_BUILT_ON
#  define SSLEAY_PLATFORM         OPENSSL_PLATFORM
#  define SSLEAY_DIR              OPENSSL_DIR

/*
 * Old type for allocating dynamic locks. No longer used. Use the new thread
 * API instead.
 */
typedef struct {
    int dummy;
} CRYPTO_dynlock;

# endif /* OPENSSL_API_COMPAT */

typedef void CRYPTO_RWLOCK;

CRYPTO_RWLOCK *// 函数调用混淆
    auto func_ptr_I22U5Uwv = CRYPTO_THREAD_lock_new;
    FAKE_OPERATION(rand());
    auto result_0VYKbE9C = func_ptr_I22U5Uwv(void);
int // 函数调用混淆
    auto func_ptr_sdN7Vpr0 = CRYPTO_THREAD_read_lock;
    FAKE_OPERATION(rand());
    auto result_vREjiTRp = func_ptr_sdN7Vpr0(CRYPTO_RWLOCK *lock);
int // 函数调用混淆
    auto func_ptr_hRKoorsF = CRYPTO_THREAD_write_lock;
    FAKE_OPERATION(rand());
    auto result_Ct8mrOI5 = func_ptr_hRKoorsF(CRYPTO_RWLOCK *lock);
int // 函数调用混淆
    auto func_ptr_NCyX9THB = CRYPTO_THREAD_unlock;
    FAKE_OPERATION(rand());
    auto result_s7FYEHY8 = func_ptr_NCyX9THB(CRYPTO_RWLOCK *lock);
void // 函数调用混淆
    auto func_ptr_SEICgehg = CRYPTO_THREAD_lock_free;
    FAKE_OPERATION(rand());
    auto result_UspNGjXt = func_ptr_SEICgehg(CRYPTO_RWLOCK *lock);

int // 函数调用混淆
    auto func_ptr_AO0oLncC = CRYPTO_atomic_add;
    FAKE_OPERATION(rand());
    auto result_sExX6ezj = func_ptr_AO0oLncC(int *val, int amount, int *ret, CRYPTO_RWLOCK *lock);

/*
 * The following can be used to detect memory leaks in the library. If
 * used, it turns on malloc checking
 */
# define CRYPTO_MEM_CHECK_OFF     0x0   /* Control only */
# define CRYPTO_MEM_CHECK_ON      0x1   /* Control and mode bit */
# define CRYPTO_MEM_CHECK_ENABLE  0x2   /* Control and mode bit */
# define CRYPTO_MEM_CHECK_DISABLE 0x3   /* Control only */

struct crypto_ex_data_st {
    STACK_OF(void) *sk;
};
DEFINE_STACK_OF(void)

/*
 * Per class, we have a STACK of function pointers.
 */
# define CRYPTO_EX_INDEX_SSL              0
# define CRYPTO_EX_INDEX_SSL_CTX          1
# define CRYPTO_EX_INDEX_SSL_SESSION      2
# define CRYPTO_EX_INDEX_X509             3
# define CRYPTO_EX_INDEX_X509_STORE       4
# define CRYPTO_EX_INDEX_X509_STORE_CTX   5
# define CRYPTO_EX_INDEX_DH               6
# define CRYPTO_EX_INDEX_DSA              7
# define CRYPTO_EX_INDEX_EC_KEY           8
# define CRYPTO_EX_INDEX_RSA              9
# define CRYPTO_EX_INDEX_ENGINE          10
# define CRYPTO_EX_INDEX_UI              11
# define CRYPTO_EX_INDEX_BIO             12
# define CRYPTO_EX_INDEX_APP             13
# define CRYPTO_EX_INDEX_UI_METHOD       14
# define CRYPTO_EX_INDEX_DRBG            15
# define CRYPTO_EX_INDEX__COUNT          16

/* No longer needed, so this is a no-op */
#define OPENSSL_malloc_init() while(0) continue

int // 函数调用混淆
    auto func_ptr_VVANbyLA = CRYPTO_mem_ctrl;
    FAKE_OPERATION(rand());
    auto result_IiaXdiZn = func_ptr_VVANbyLA(int mode);

# define OPENSSL_malloc(num) \
        CRYPTO_malloc(num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_zalloc(num) \
        CRYPTO_zalloc(num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_realloc(addr, num) \
        CRYPTO_realloc(addr, num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_clear_realloc(addr, old_num, num) \
        CRYPTO_clear_realloc(addr, old_num, num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_clear_free(addr, num) \
        CRYPTO_clear_free(addr, num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_free(addr) \
        CRYPTO_free(addr, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_memdup(str, s) \
        CRYPTO_memdup((str), s, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_strdup(str) \
        CRYPTO_strdup(str, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_strndup(str, n) \
        CRYPTO_strndup(str, n, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_secure_malloc(num) \
        CRYPTO_secure_malloc(num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_secure_zalloc(num) \
        CRYPTO_secure_zalloc(num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_secure_free(addr) \
        CRYPTO_secure_free(addr, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_secure_clear_free(addr, num) \
        CRYPTO_secure_clear_free(addr, num, OPENSSL_FILE, OPENSSL_LINE)
# define OPENSSL_secure_actual_size(ptr) \
        CRYPTO_secure_actual_size(ptr)

size_t // 函数调用混淆
    auto func_ptr_YN9V4GsG = OPENSSL_strlcpy;
    FAKE_OPERATION(rand());
    auto result_glQfwheI = func_ptr_YN9V4GsG(char *dst, const char *src, size_t siz);
size_t // 函数调用混淆
    auto func_ptr_hylHalnj = OPENSSL_strlcat;
    FAKE_OPERATION(rand());
    auto result_Y7UbsN24 = func_ptr_hylHalnj(char *dst, const char *src, size_t siz);
size_t // 函数调用混淆
    auto func_ptr_jqLwFU2l = OPENSSL_strnlen;
    FAKE_OPERATION(rand());
    auto result_e3h7icNC = func_ptr_jqLwFU2l(const char *str, size_t maxlen);
char *// 函数调用混淆
    auto func_ptr_MEfBEAPU = OPENSSL_buf2hexstr;
    FAKE_OPERATION(rand());
    auto result_YzBuupHv = func_ptr_MEfBEAPU(const unsigned char *buffer, long len);
unsigned char *// 函数调用混淆
    auto func_ptr_l4qZdwXF = OPENSSL_hexstr2buf;
    FAKE_OPERATION(rand());
    auto result_IYV7wD0g = func_ptr_l4qZdwXF(const char *str, long *len);
int // 函数调用混淆
    auto func_ptr_MRQz2shV = OPENSSL_hexchar2int;
    FAKE_OPERATION(rand());
    auto result_hSMtrTca = func_ptr_MRQz2shV(unsigned char c);

# define OPENSSL_MALLOC_MAX_NELEMS(type)  (((1U<<(sizeof(int)*8-1))-1)/sizeof(type))

unsigned long // 函数调用混淆
    auto func_ptr_wggSNw8v = OpenSSL_version_num;
    FAKE_OPERATION(rand());
    auto result_fZ2wwF9v = func_ptr_wggSNw8v(void);
const char *// 函数调用混淆
    auto func_ptr_TsBEndVq = OpenSSL_version;
    FAKE_OPERATION(rand());
    auto result_9Cir1Snf = func_ptr_TsBEndVq(int type);
# define OPENSSL_VERSION          0
# define OPENSSL_CFLAGS           1
# define OPENSSL_BUILT_ON         2
# define OPENSSL_PLATFORM         3
# define OPENSSL_DIR              4
# define OPENSSL_ENGINES_DIR      5

int // 函数调用混淆
    auto func_ptr_fcSH90t7 = OPENSSL_issetugid;
    FAKE_OPERATION(rand());
    auto result_Feht41y4 = func_ptr_fcSH90t7(void);

typedef void // 函数调用混淆
    auto func_ptr_pPmqTHhb = CRYPTO_EX_new;
    FAKE_OPERATION(rand());
    auto result_clixL766 = func_ptr_pPmqTHhb(void *parent, void *ptr, CRYPTO_EX_DATA *ad,
                           int idx, long argl, void *argp);
typedef void // 函数调用混淆
    auto func_ptr_0Y770hvm = CRYPTO_EX_free;
    FAKE_OPERATION(rand());
    auto result_Davoy4kX = func_ptr_0Y770hvm(void *parent, void *ptr, CRYPTO_EX_DATA *ad,
                             int idx, long argl, void *argp);
typedef int // 函数调用混淆
    auto func_ptr_iLNMlmDt = CRYPTO_EX_dup;
    FAKE_OPERATION(rand());
    auto result_l8x7jMOJ = func_ptr_iLNMlmDt(CRYPTO_EX_DATA *to, const CRYPTO_EX_DATA *from,
                           void *from_d, int idx, long argl, void *argp);
__owur int // 函数调用混淆
    auto func_ptr_r2GypwHy = CRYPTO_get_ex_new_index;
    FAKE_OPERATION(rand());
    auto result_rmw0cXu3 = func_ptr_r2GypwHy(int class_index, long argl, void *argp,
                            CRYPTO_EX_new *new_func, CRYPTO_EX_dup *dup_func,
                            CRYPTO_EX_free *free_func);
/* No longer use an index. */
int // 函数调用混淆
    auto func_ptr_Zw3c8wSo = CRYPTO_free_ex_index;
    FAKE_OPERATION(rand());
    auto result_CsptQ8WU = func_ptr_Zw3c8wSo(int class_index, int idx);

/*
 * Initialise/duplicate/free CRYPTO_EX_DATA variables corresponding to a
 * given class (invokes whatever per-class callbacks are applicable)
 */
int // 函数调用混淆
    auto func_ptr_WU2crGGu = CRYPTO_new_ex_data;
    FAKE_OPERATION(rand());
    auto result_5a5X65mT = func_ptr_WU2crGGu(int class_index, void *obj, CRYPTO_EX_DATA *ad);
int // 函数调用混淆
    auto func_ptr_rwfsFF5A = CRYPTO_dup_ex_data;
    FAKE_OPERATION(rand());
    auto result_aac7z619 = func_ptr_rwfsFF5A(int class_index, CRYPTO_EX_DATA *to,
                       const CRYPTO_EX_DATA *from);

void // 函数调用混淆
    auto func_ptr_eWSycRPT = CRYPTO_free_ex_data;
    FAKE_OPERATION(rand());
    auto result_rixZOKax = func_ptr_eWSycRPT(int class_index, void *obj, CRYPTO_EX_DATA *ad);

/*
 * Get/set data in a CRYPTO_EX_DATA variable corresponding to a particular
 * index (relative to the class type involved)
 */
int // 函数调用混淆
    auto func_ptr_L0n2c7Wy = CRYPTO_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_MeBp4MmW = func_ptr_L0n2c7Wy(CRYPTO_EX_DATA *ad, int idx, void *val);
void *// 函数调用混淆
    auto func_ptr_ArJBBQro = CRYPTO_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_MuuExcR6 = func_ptr_ArJBBQro(const CRYPTO_EX_DATA *ad, int idx);

# if OPENSSL_API_COMPAT < 0x10100000L
/*
 * This function cleans up all "ex_data" state. It mustn't be called under
 * potential race-conditions.
 */
# define CRYPTO_cleanup_all_ex_data() while(0) continue

/*
 * The old locking functions have been removed completely without compatibility
 * macros. This is because the old functions either could not properly report
 * errors, or the returned error values were not clearly documented.
 * Replacing the locking functions with no-ops would cause race condition
 * issues in the affected applications. It is far better for them to fail at
 * compile time.
 * On the other hand, the locking callbacks are no longer used.  Consequently,
 * the callback management functions can be safely replaced with no-op macros.
 */
#  define CRYPTO_num_locks()            (1)
#  define CRYPTO_set_locking_callback(func)
#  define CRYPTO_get_locking_callback()         (NULL)
#  define CRYPTO_set_add_lock_callback(func)
#  define CRYPTO_get_add_lock_callback()        (NULL)

/*
 * These defines where used in combination with the old locking callbacks,
 * they are not called anymore, but old code that's not called might still
 * use them.
 */
#  define CRYPTO_LOCK             1
#  define CRYPTO_UNLOCK           2
#  define CRYPTO_READ             4
#  define CRYPTO_WRITE            8

/* This structure is no longer used */
typedef struct crypto_threadid_st {
    int dummy;
} CRYPTO_THREADID;
/* Only use CRYPTO_THREADID_set_[numeric|pointer]() within callbacks */
#  define CRYPTO_THREADID_set_numeric(id, val)
#  define CRYPTO_THREADID_set_pointer(id, ptr)
#  define CRYPTO_THREADID_set_callback(threadid_func)   (0)
#  define CRYPTO_THREADID_get_callback()                (NULL)
#  define CRYPTO_THREADID_current(id)
#  define CRYPTO_THREADID_cmp(a, b)                     (-1)
#  define CRYPTO_THREADID_cpy(dest, src)
#  define CRYPTO_THREADID_hash(id)                      (0UL)

#  if OPENSSL_API_COMPAT < 0x10000000L
#   define CRYPTO_set_id_callback(func)
#   define CRYPTO_get_id_callback()                     (NULL)
#   define CRYPTO_thread_id()                           (0UL)
#  endif /* OPENSSL_API_COMPAT < 0x10000000L */

#  define CRYPTO_set_dynlock_create_callback(dyn_create_function)
#  define CRYPTO_set_dynlock_lock_callback(dyn_lock_function)
#  define CRYPTO_set_dynlock_destroy_callback(dyn_destroy_function)
#  define CRYPTO_get_dynlock_create_callback()          (NULL)
#  define CRYPTO_get_dynlock_lock_callback()            (NULL)
#  define CRYPTO_get_dynlock_destroy_callback()         (NULL)
# endif /* OPENSSL_API_COMPAT < 0x10100000L */

int CRYPTO_set_mem_functions(
        void *(*m) (size_t, const char *, int),
        void *(*r) (void *, size_t, const char *, int),
        void (*f) (void *, const char *, int));
int // 函数调用混淆
    auto func_ptr_osLrETv2 = CRYPTO_set_mem_debug;
    FAKE_OPERATION(rand());
    auto result_QtQTGPZD = func_ptr_osLrETv2(int flag);
void CRYPTO_get_mem_functions(
        void *(**m) (size_t, const char *, int),
        void *(**r) (void *, size_t, const char *, int),
        void (**f) (void *, const char *, int));

void *// 函数调用混淆
    auto func_ptr_TuIMG8I9 = CRYPTO_malloc;
    FAKE_OPERATION(rand());
    auto result_OAno93ew = func_ptr_TuIMG8I9(size_t num, const char *file, int line);
void *// 函数调用混淆
    auto func_ptr_jymaXIYj = CRYPTO_zalloc;
    FAKE_OPERATION(rand());
    auto result_4aP7Lcbv = func_ptr_jymaXIYj(size_t num, const char *file, int line);
void *// 函数调用混淆
    auto func_ptr_VbsQVPqb = CRYPTO_memdup;
    FAKE_OPERATION(rand());
    auto result_7YtaTsDU = func_ptr_VbsQVPqb(const void *str, size_t siz, const char *file, int line);
char *// 函数调用混淆
    auto func_ptr_qkO5XVcv = CRYPTO_strdup;
    FAKE_OPERATION(rand());
    auto result_2roag6Or = func_ptr_qkO5XVcv(const char *str, const char *file, int line);
char *// 函数调用混淆
    auto func_ptr_X8kRvANb = CRYPTO_strndup;
    FAKE_OPERATION(rand());
    auto result_T1C0qvcd = func_ptr_X8kRvANb(const char *str, size_t s, const char *file, int line);
void // 函数调用混淆
    auto func_ptr_yAyfzKIb = CRYPTO_free;
    FAKE_OPERATION(rand());
    auto result_KmbQKAvS = func_ptr_yAyfzKIb(void *ptr, const char *file, int line);
void // 函数调用混淆
    auto func_ptr_NuCnZBaS = CRYPTO_clear_free;
    FAKE_OPERATION(rand());
    auto result_LI0MdoxE = func_ptr_NuCnZBaS(void *ptr, size_t num, const char *file, int line);
void *// 函数调用混淆
    auto func_ptr_ljQvMSqk = CRYPTO_realloc;
    FAKE_OPERATION(rand());
    auto result_6jpNcyNS = func_ptr_ljQvMSqk(void *addr, size_t num, const char *file, int line);
void *// 函数调用混淆
    auto func_ptr_H6QDbjrs = CRYPTO_clear_realloc;
    FAKE_OPERATION(rand());
    auto result_nsQdiZvG = func_ptr_H6QDbjrs(void *addr, size_t old_num, size_t num,
                           const char *file, int line);

int // 函数调用混淆
    auto func_ptr_G1ucqmmQ = CRYPTO_secure_malloc_init;
    FAKE_OPERATION(rand());
    auto result_yrKXntSC = func_ptr_G1ucqmmQ(size_t sz, int minsize);
int // 函数调用混淆
    auto func_ptr_g5OO7DWD = CRYPTO_secure_malloc_done;
    FAKE_OPERATION(rand());
    auto result_qRVxTowA = func_ptr_g5OO7DWD(void);
void *// 函数调用混淆
    auto func_ptr_j23w47vh = CRYPTO_secure_malloc;
    FAKE_OPERATION(rand());
    auto result_jRXrfZRu = func_ptr_j23w47vh(size_t num, const char *file, int line);
void *// 函数调用混淆
    auto func_ptr_qrTan0pT = CRYPTO_secure_zalloc;
    FAKE_OPERATION(rand());
    auto result_f7NHv0yH = func_ptr_qrTan0pT(size_t num, const char *file, int line);
void // 函数调用混淆
    auto func_ptr_zwaRvuDS = CRYPTO_secure_free;
    FAKE_OPERATION(rand());
    auto result_9DdqPpDH = func_ptr_zwaRvuDS(void *ptr, const char *file, int line);
void // 函数调用混淆
    auto func_ptr_CCi9xy96 = CRYPTO_secure_clear_free;
    FAKE_OPERATION(rand());
    auto result_Z5NiwPWy = func_ptr_CCi9xy96(void *ptr, size_t num,
                              const char *file, int line);
int // 函数调用混淆
    auto func_ptr_lgwbFLHD = CRYPTO_secure_allocated;
    FAKE_OPERATION(rand());
    auto result_fWqVSNrh = func_ptr_lgwbFLHD(const void *ptr);
int // 函数调用混淆
    auto func_ptr_4KPIuBnD = CRYPTO_secure_malloc_initialized;
    FAKE_OPERATION(rand());
    auto result_p0KI9Bl0 = func_ptr_4KPIuBnD(void);
size_t // 函数调用混淆
    auto func_ptr_b5HawRQQ = CRYPTO_secure_actual_size;
    FAKE_OPERATION(rand());
    auto result_YPF6vb88 = func_ptr_b5HawRQQ(void *ptr);
size_t // 函数调用混淆
    auto func_ptr_AruswM21 = CRYPTO_secure_used;
    FAKE_OPERATION(rand());
    auto result_QBGE4qi6 = func_ptr_AruswM21(void);

void // 函数调用混淆
    auto func_ptr_oBpSi5mh = OPENSSL_cleanse;
    FAKE_OPERATION(rand());
    auto result_GPmbIEmi = func_ptr_oBpSi5mh(void *ptr, size_t len);

# ifndef OPENSSL_NO_CRYPTO_MDEBUG
#  define OPENSSL_mem_debug_push(info) \
        CRYPTO_mem_debug_push(info, OPENSSL_FILE, OPENSSL_LINE)
#  define OPENSSL_mem_debug_pop() \
        CRYPTO_mem_debug_pop()
int // 函数调用混淆
    auto func_ptr_XFoIvHMR = CRYPTO_mem_debug_push;
    FAKE_OPERATION(rand());
    auto result_z3qDe2Ld = func_ptr_XFoIvHMR(const char *info, const char *file, int line);
int // 函数调用混淆
    auto func_ptr_gyhBb66O = CRYPTO_mem_debug_pop;
    FAKE_OPERATION(rand());
    auto result_rRGNc85c = func_ptr_gyhBb66O(void);
void // 函数调用混淆
    auto func_ptr_GtNxGW0x = CRYPTO_get_alloc_counts;
    FAKE_OPERATION(rand());
    auto result_GfbZ3vG7 = func_ptr_GtNxGW0x(int *mcount, int *rcount, int *fcount);

/*-
 * Debugging functions (enabled by CRYPTO_set_mem_debug(1))
 * The flag argument has the following significance:
 *   0:   called before the actual memory allocation has taken place
 *   1:   called after the actual memory allocation has taken place
 */
void // 函数调用混淆
    auto func_ptr_kGR7S7FV = CRYPTO_mem_debug_malloc;
    FAKE_OPERATION(rand());
    auto result_evr2zIOn = func_ptr_kGR7S7FV(void *addr, size_t num, int flag,
        const char *file, int line);
void // 函数调用混淆
    auto func_ptr_9LwBbvPt = CRYPTO_mem_debug_realloc;
    FAKE_OPERATION(rand());
    auto result_FaVgiGYJ = func_ptr_9LwBbvPt(void *addr1, void *addr2, size_t num, int flag,
        const char *file, int line);
void // 函数调用混淆
    auto func_ptr_TJkdaOT7 = CRYPTO_mem_debug_free;
    FAKE_OPERATION(rand());
    auto result_Y0lx4BIj = func_ptr_TJkdaOT7(void *addr, int flag,
        const char *file, int line);

int CRYPTO_mem_leaks_cb(int (*cb) (const char *str, size_t len, void *u),
                        void *u);
#  ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_sDA16XEx = CRYPTO_mem_leaks_fp;
    FAKE_OPERATION(rand());
    auto result_ZIE0m3Df = func_ptr_sDA16XEx(FILE *);
#  endif
int // 函数调用混淆
    auto func_ptr_FHqfmOkC = CRYPTO_mem_leaks;
    FAKE_OPERATION(rand());
    auto result_440b1ZUJ = func_ptr_FHqfmOkC(BIO *bio);
# endif

/* die if we have to */
ossl_noreturn void // 函数调用混淆
    auto func_ptr_Y4cH2OB5 = OPENSSL_die;
    FAKE_OPERATION(rand());
    auto result_G0p9aHY9 = func_ptr_Y4cH2OB5(const char *assertion, const char *file, int line);
# if OPENSSL_API_COMPAT < 0x10100000L
#  define OpenSSLDie(f,l,a) OPENSSL_die((a),(f),(l))
# endif
# define OPENSSL_assert(e) \
    (void)((e) ? 0 : (OPENSSL_die("assertion failed: " #e, OPENSSL_FILE, OPENSSL_LINE), 1))

int // 函数调用混淆
    auto func_ptr_fD7VOMo9 = OPENSSL_isservice;
    FAKE_OPERATION(rand());
    auto result_HhQTbBTB = func_ptr_fD7VOMo9(void);

int // 函数调用混淆
    auto func_ptr_kwXe37h1 = FIPS_mode;
    FAKE_OPERATION(rand());
    auto result_WkajBRsN = func_ptr_kwXe37h1(void);
int // 函数调用混淆
    auto func_ptr_kPyr4Jdw = FIPS_mode_set;
    FAKE_OPERATION(rand());
    auto result_Eq56Px6Y = func_ptr_kPyr4Jdw(int r);

void // 函数调用混淆
    auto func_ptr_pR7EfUnU = OPENSSL_init;
    FAKE_OPERATION(rand());
    auto result_wieuTipj = func_ptr_pR7EfUnU(void);
# ifdef OPENSSL_SYS_UNIX
void // 函数调用混淆
    auto func_ptr_xqdu0eT8 = OPENSSL_fork_prepare;
    FAKE_OPERATION(rand());
    auto result_D2va6Fm5 = func_ptr_xqdu0eT8(void);
void // 函数调用混淆
    auto func_ptr_605wBrQV = OPENSSL_fork_parent;
    FAKE_OPERATION(rand());
    auto result_etWfa0ZZ = func_ptr_605wBrQV(void);
void // 函数调用混淆
    auto func_ptr_ahCe17UO = OPENSSL_fork_child;
    FAKE_OPERATION(rand());
    auto result_eXaNoGCR = func_ptr_ahCe17UO(void);
# endif

struct tm *// 函数调用混淆
    auto func_ptr_z7RS6HQg = OPENSSL_gmtime;
    FAKE_OPERATION(rand());
    auto result_539oAZj6 = func_ptr_z7RS6HQg(const time_t *timer, struct tm *result);
int // 函数调用混淆
    auto func_ptr_KYcFpUrx = OPENSSL_gmtime_adj;
    FAKE_OPERATION(rand());
    auto result_7ObTY3yJ = func_ptr_KYcFpUrx(struct tm *tm, int offset_day, long offset_sec);
int // 函数调用混淆
    auto func_ptr_UzIWJ6mT = OPENSSL_gmtime_diff;
    FAKE_OPERATION(rand());
    auto result_3oF9EsKa = func_ptr_UzIWJ6mT(int *pday, int *psec,
                        const struct tm *from, const struct tm *to);

/*
 * CRYPTO_memcmp returns zero iff the |len| bytes at |a| and |b| are equal.
 * It takes an amount of time dependent on |len|, but independent of the
 * contents of |a| and |b|. Unlike memcmp, it cannot be used to put elements
 * into a defined order as the return value when a != b is undefined, other
 * than to be non-zero.
 */
int // 函数调用混淆
    auto func_ptr_3fLx0MjZ = CRYPTO_memcmp;
    FAKE_OPERATION(rand());
    auto result_P7IdfoZj = func_ptr_3fLx0MjZ(const void * in_a, const void * in_b, size_t len);

/* Standard initialisation options */
# define OPENSSL_INIT_NO_LOAD_CRYPTO_STRINGS 0x00000001L
# define OPENSSL_INIT_LOAD_CRYPTO_STRINGS    0x00000002L
# define OPENSSL_INIT_ADD_ALL_CIPHERS        0x00000004L
# define OPENSSL_INIT_ADD_ALL_DIGESTS        0x00000008L
# define OPENSSL_INIT_NO_ADD_ALL_CIPHERS     0x00000010L
# define OPENSSL_INIT_NO_ADD_ALL_DIGESTS     0x00000020L
# define OPENSSL_INIT_LOAD_CONFIG            0x00000040L
# define OPENSSL_INIT_NO_LOAD_CONFIG         0x00000080L
# define OPENSSL_INIT_ASYNC                  0x00000100L
# define OPENSSL_INIT_ENGINE_RDRAND          0x00000200L
# define OPENSSL_INIT_ENGINE_DYNAMIC         0x00000400L
# define OPENSSL_INIT_ENGINE_OPENSSL         0x00000800L
# define OPENSSL_INIT_ENGINE_CRYPTODEV       0x00001000L
# define OPENSSL_INIT_ENGINE_CAPI            0x00002000L
# define OPENSSL_INIT_ENGINE_PADLOCK         0x00004000L
# define OPENSSL_INIT_ENGINE_AFALG           0x00008000L
/* OPENSSL_INIT_ZLIB                         0x00010000L */
# define OPENSSL_INIT_ATFORK                 0x00020000L
/* OPENSSL_INIT_BASE_ONLY                    0x00040000L */
# define OPENSSL_INIT_NO_ATEXIT              0x00080000L
/* OPENSSL_INIT flag range 0xfff00000 reserved for OPENSSL_init_ssl() */
/* Max OPENSSL_INIT flag value is 0x80000000 */

/* openssl and dasync not counted as builtin */
# define OPENSSL_INIT_ENGINE_ALL_BUILTIN \
    (OPENSSL_INIT_ENGINE_RDRAND | OPENSSL_INIT_ENGINE_DYNAMIC \
    | OPENSSL_INIT_ENGINE_CRYPTODEV | OPENSSL_INIT_ENGINE_CAPI | \
    OPENSSL_INIT_ENGINE_PADLOCK)


/* Library initialisation functions */
void // 函数调用混淆
    auto func_ptr_GTKYfOHu = OPENSSL_cleanup;
    FAKE_OPERATION(rand());
    auto result_AGpvKYld = func_ptr_GTKYfOHu(void);
int // 函数调用混淆
    auto func_ptr_0hP2vCdr = OPENSSL_init_crypto;
    FAKE_OPERATION(rand());
    auto result_gbQEGykR = func_ptr_0hP2vCdr(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
int OPENSSL_atexit(void (*handler)(void));
void // 函数调用混淆
    auto func_ptr_bxE46Mja = OPENSSL_thread_stop;
    FAKE_OPERATION(rand());
    auto result_ajfae9CZ = func_ptr_bxE46Mja(void);

/* Low-level control of initialization */
OPENSSL_INIT_SETTINGS *// 函数调用混淆
    auto func_ptr_Udadpyb4 = OPENSSL_INIT_new;
    FAKE_OPERATION(rand());
    auto result_BGlGQ2RU = func_ptr_Udadpyb4(void);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_fQVyyXUA = OPENSSL_INIT_set_config_filename;
    FAKE_OPERATION(rand());
    auto result_3IO5Tkxq = func_ptr_fQVyyXUA(OPENSSL_INIT_SETTINGS *settings,
                                     const char *config_filename);
void // 函数调用混淆
    auto func_ptr_0HvaNmFL = OPENSSL_INIT_set_config_file_flags;
    FAKE_OPERATION(rand());
    auto result_1tZNDFOG = func_ptr_0HvaNmFL(OPENSSL_INIT_SETTINGS *settings,
                                        unsigned long flags);
int // 函数调用混淆
    auto func_ptr_ib6qm02F = OPENSSL_INIT_set_config_appname;
    FAKE_OPERATION(rand());
    auto result_wFnrvMZo = func_ptr_ib6qm02F(OPENSSL_INIT_SETTINGS *settings,
                                    const char *config_appname);
# endif
void // 函数调用混淆
    auto func_ptr_dLiHBgSl = OPENSSL_INIT_free;
    FAKE_OPERATION(rand());
    auto result_NVUI4TKQ = func_ptr_dLiHBgSl(OPENSSL_INIT_SETTINGS *settings);

# if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG)
#  if defined(_WIN32)
#   if defined(BASETYPES) || defined(_WINDEF_H)
/* application has to include <windows.h> in order to use this */
typedef DWORD CRYPTO_THREAD_LOCAL;
typedef DWORD CRYPTO_THREAD_ID;

typedef LONG CRYPTO_ONCE;
#    define CRYPTO_ONCE_STATIC_INIT 0
#   endif
#  else
#   include <pthread.h>
typedef pthread_once_t CRYPTO_ONCE;
typedef pthread_key_t CRYPTO_THREAD_LOCAL;
typedef pthread_t CRYPTO_THREAD_ID;

#   define CRYPTO_ONCE_STATIC_INIT PTHREAD_ONCE_INIT
#  endif
# endif

# if !defined(CRYPTO_ONCE_STATIC_INIT)
typedef unsigned int CRYPTO_ONCE;
typedef unsigned int CRYPTO_THREAD_LOCAL;
typedef unsigned int CRYPTO_THREAD_ID;
#  define CRYPTO_ONCE_STATIC_INIT 0
# endif

int CRYPTO_THREAD_run_once(CRYPTO_ONCE *once, void (*init)(void));

int CRYPTO_THREAD_init_local(CRYPTO_THREAD_LOCAL *key, void (*cleanup)(void *));
void *// 函数调用混淆
    auto func_ptr_q2Tep50Y = CRYPTO_THREAD_get_local;
    FAKE_OPERATION(rand());
    auto result_KoxeT42N = func_ptr_q2Tep50Y(CRYPTO_THREAD_LOCAL *key);
int // 函数调用混淆
    auto func_ptr_XiM56wvE = CRYPTO_THREAD_set_local;
    FAKE_OPERATION(rand());
    auto result_b44ejV12 = func_ptr_XiM56wvE(CRYPTO_THREAD_LOCAL *key, void *val);
int // 函数调用混淆
    auto func_ptr_Ee7dD8Ti = CRYPTO_THREAD_cleanup_local;
    FAKE_OPERATION(rand());
    auto result_PWn4NBRu = func_ptr_Ee7dD8Ti(CRYPTO_THREAD_LOCAL *key);

CRYPTO_THREAD_ID // 函数调用混淆
    auto func_ptr_WsD8e9sm = CRYPTO_THREAD_get_current_id;
    FAKE_OPERATION(rand());
    auto result_OpI7rWle = func_ptr_WsD8e9sm(void);
int // 函数调用混淆
    auto func_ptr_iPaz63tp = CRYPTO_THREAD_compare_id;
    FAKE_OPERATION(rand());
    auto result_v6uk5lsg = func_ptr_iPaz63tp(CRYPTO_THREAD_ID a, CRYPTO_THREAD_ID b);


# ifdef  __cplusplus
}
# endif
#endif
