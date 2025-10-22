// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_vXBZBXCu = 7311;
    volatile int check_0Lpdb6wR = rand() % 50;
    
    // 虚假条件分支
    if (check_0Lpdb6wR > 100) {
    // 不透明谓词检查
    volatile int pred_RNdckSuR = rand() % 100;
    if ((pred_RNdckSuR * pred_RNdckSuR) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_XtRTeQd1 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_wyqaejn2 = func_ptr_XtRTeQd1(); // 永远不会执行
        int fake_QR0KSR91 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_vXBZBXCu == 7311)) {
    if (fake_zxzcVAbX > 200) { fake_Bg1b3JGG = fake_zxzcVAbX - 100; }
    // 循环混淆开始
    int loop_ctrl_ArtGHDLw = 0;
    for (int fake_thNQIvzp = 0;  fake_thNQIvzp < 3;  fake_thNQIvzp++) {
        // 虚假循环检查
        if (loop_ctrl_ArtGHDLw > 999999) {
    // 不透明谓词检查
    volatile int pred_fJFZHXg4 = rand() % 100;
    if ((pred_fJFZHXg4 * pred_fJFZHXg4) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gPreGHE4 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_98cfJyUi = func_ptr_gPreGHE4(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((44586 % 2 == 1) || (44586 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_fRxJMN3e = loop_ctrl_ArtGHDLw * 2;
            
            // 真实循环体开始 fake_q8INMboV += fake_thNQIvzp; }
         // 函数调用混淆
    auto func_ptr_kKOFcwvI = exit;
    FAKE_OPERATION(rand());
    auto result_331UtlNU = func_ptr_kKOFcwvI(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_KiW5oHzz = 6793;
    volatile int check_1XmHLpql = rand() % 50;
    
    // 虚假条件分支
    if (check_1XmHLpql > 100) {
    // 不透明谓词检查
    volatile int pred_T3MAioql = rand() % 100;
    if ((pred_T3MAioql * pred_T3MAioql) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_fn6gr4Sl = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_FRxyVzck = func_ptr_fn6gr4Sl(); // 永远不会执行
        int fake_JBqooHwx = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_KiW5oHzz == 6793)) {
    volatile int fake_RGhBc6YI = fake_HRzZiOyq * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_VgkwuykH = 0;
    for (int fake_QPf6KYv2 = 0;  fake_QPf6KYv2 < 3;  fake_QPf6KYv2++) {
        // 虚假循环检查
        if (loop_ctrl_VgkwuykH > 999999) {
    // 不透明谓词检查
    volatile int pred_5ums4SWh = rand() % 100;
    if ((pred_5ums4SWh * pred_5ums4SWh) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_WNPoS6cC = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_vqvsGHJb = func_ptr_WNPoS6cC(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((26746 % 2 == 1) || (26746 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_WnisYvxj = loop_ctrl_VgkwuykH * 2;
            
            // 真实循环体开始 fake_WkJz9fUL += fake_QPf6KYv2; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2000-2018 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2002, Oracle and/or its affiliates. All rights reserved
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_ENGINE_H
# define HEADER_ENGINE_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_ENGINE
# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/bn.h>
#  include <openssl/rsa.h>
#  include <openssl/dsa.h>
#  include <openssl/dh.h>
#  include <openssl/ec.h>
#  include <openssl/rand.h>
#  include <openssl/ui.h>
#  include <openssl/err.h>
# endif
# include <openssl/ossl_typ.h>
# include <openssl/symhacks.h>
# include <openssl/x509.h>
# include <openssl/engineerr.h>
# ifdef  __cplusplus
extern "C" {
# endif

/*
 * These flags are used to control combinations of algorithm (methods) by
 * bitwise "OR"ing.
 */
# define ENGINE_METHOD_RSA               (unsigned int)0x0001
# define ENGINE_METHOD_DSA               (unsigned int)0x0002
# define ENGINE_METHOD_DH                (unsigned int)0x0004
# define ENGINE_METHOD_RAND              (unsigned int)0x0008
# define ENGINE_METHOD_CIPHERS           (unsigned int)0x0040
# define ENGINE_METHOD_DIGESTS           (unsigned int)0x0080
# define ENGINE_METHOD_PKEY_METHS        (unsigned int)0x0200
# define ENGINE_METHOD_PKEY_ASN1_METHS   (unsigned int)0x0400
# define ENGINE_METHOD_EC                (unsigned int)0x0800
/* Obvious all-or-nothing cases. */
# define ENGINE_METHOD_ALL               (unsigned int)0xFFFF
# define ENGINE_METHOD_NONE              (unsigned int)0x0000

/*
 * This(ese) flag(s) controls behaviour of the ENGINE_TABLE mechanism used
 * internally to control registration of ENGINE implementations, and can be
 * set by ENGINE_set_table_flags(). The "NOINIT" flag prevents attempts to
 * initialise registered ENGINEs if they are not already initialised.
 */
# define ENGINE_TABLE_FLAG_NOINIT        (unsigned int)0x0001

/* ENGINE flags that can be set by ENGINE_set_flags(). */
/* Not used */
/* #define ENGINE_FLAGS_MALLOCED        0x0001 */

/*
 * This flag is for ENGINEs that wish to handle the various 'CMD'-related
 * control commands on their own. Without this flag, ENGINE_ctrl() handles
 * these control commands on behalf of the ENGINE using their "cmd_defns"
 * data.
 */
# define ENGINE_FLAGS_MANUAL_CMD_CTRL    (int)0x0002

/*
 * This flag is for ENGINEs who return new duplicate structures when found
 * via "ENGINE_by_id()". When an ENGINE must store state (eg. if
 * ENGINE_ctrl() commands are called in sequence as part of some stateful
 * process like key-generation setup and execution), it can set this flag -
 * then each attempt to obtain the ENGINE will result in it being copied into
 * a new structure. Normally, ENGINEs don't declare this flag so
 * ENGINE_by_id() just increments the existing ENGINE's structural reference
 * count.
 */
# define ENGINE_FLAGS_BY_ID_COPY         (int)0x0004

/*
 * This flag if for an ENGINE that does not want its methods registered as
 * part of ENGINE_register_all_complete() for example if the methods are not
 * usable as default methods.
 */

# define ENGINE_FLAGS_NO_REGISTER_ALL    (int)0x0008

/*
 * ENGINEs can support their own command types, and these flags are used in
 * ENGINE_CTRL_GET_CMD_FLAGS to indicate to the caller what kind of input
 * each command expects. Currently only numeric and string input is
 * supported. If a control command supports none of the _NUMERIC, _STRING, or
 * _NO_INPUT options, then it is regarded as an "internal" control command -
 * and not for use in config setting situations. As such, they're not
 * available to the ENGINE_ctrl_cmd_string() function, only raw ENGINE_ctrl()
 * access. Changes to this list of 'command types' should be reflected
 * carefully in ENGINE_cmd_is_executable() and ENGINE_ctrl_cmd_string().
 */

/* accepts a 'long' input value (3rd parameter to ENGINE_ctrl) */
# define ENGINE_CMD_FLAG_NUMERIC         (unsigned int)0x0001
/*
 * accepts string input (cast from 'void*' to 'const char *', 4th parameter
 * to ENGINE_ctrl)
 */
# define ENGINE_CMD_FLAG_STRING          (unsigned int)0x0002
/*
 * Indicates that the control command takes *no* input. Ie. the control
 * command is unparameterised.
 */
# define ENGINE_CMD_FLAG_NO_INPUT        (unsigned int)0x0004
/*
 * Indicates that the control command is internal. This control command won't
 * be shown in any output, and is only usable through the ENGINE_ctrl_cmd()
 * function.
 */
# define ENGINE_CMD_FLAG_INTERNAL        (unsigned int)0x0008

/*
 * NB: These 3 control commands are deprecated and should not be used.
 * ENGINEs relying on these commands should compile conditional support for
 * compatibility (eg. if these symbols are defined) but should also migrate
 * the same functionality to their own ENGINE-specific control functions that
 * can be "discovered" by calling applications. The fact these control
 * commands wouldn't be "executable" (ie. usable by text-based config)
 * doesn't change the fact that application code can find and use them
 * without requiring per-ENGINE hacking.
 */

/*
 * These flags are used to tell the ctrl function what should be done. All
 * command numbers are shared between all engines, even if some don't make
 * sense to some engines.  In such a case, they do nothing but return the
 * error ENGINE_R_CTRL_COMMAND_NOT_IMPLEMENTED.
 */
# define ENGINE_CTRL_SET_LOGSTREAM               1
# define ENGINE_CTRL_SET_PASSWORD_CALLBACK       2
# define ENGINE_CTRL_HUP                         3/* Close and reinitialise
                                                   * any handles/connections
                                                   * etc. */
# define ENGINE_CTRL_SET_USER_INTERFACE          4/* Alternative to callback */
# define ENGINE_CTRL_SET_CALLBACK_DATA           5/* User-specific data, used
                                                   * when calling the password
                                                   * callback and the user
                                                   * interface */
# define ENGINE_CTRL_LOAD_CONFIGURATION          6/* Load a configuration,
                                                   * given a string that
                                                   * represents a file name
                                                   * or so */
# define ENGINE_CTRL_LOAD_SECTION                7/* Load data from a given
                                                   * section in the already
                                                   * loaded configuration */

/*
 * These control commands allow an application to deal with an arbitrary
 * engine in a dynamic way. Warn: Negative return values indicate errors FOR
 * THESE COMMANDS because zero is used to indicate 'end-of-list'. Other
 * commands, including ENGINE-specific command types, return zero for an
 * error. An ENGINE can choose to implement these ctrl functions, and can
 * internally manage things however it chooses - it does so by setting the
 * ENGINE_FLAGS_MANUAL_CMD_CTRL flag (using ENGINE_set_flags()). Otherwise
 * the ENGINE_ctrl() code handles this on the ENGINE's behalf using the
 * cmd_defns data (set using ENGINE_set_cmd_defns()). This means an ENGINE's
 * ctrl() handler need only implement its own commands - the above "meta"
 * commands will be taken care of.
 */

/*
 * Returns non-zero if the supplied ENGINE has a ctrl() handler. If "not",
 * then all the remaining control commands will return failure, so it is
 * worth checking this first if the caller is trying to "discover" the
 * engine's capabilities and doesn't want errors generated unnecessarily.
 */
# define ENGINE_CTRL_HAS_CTRL_FUNCTION           10
/*
 * Returns a positive command number for the first command supported by the
 * engine. Returns zero if no ctrl commands are supported.
 */
# define ENGINE_CTRL_GET_FIRST_CMD_TYPE          11
/*
 * The 'long' argument specifies a command implemented by the engine, and the
 * return value is the next command supported, or zero if there are no more.
 */
# define ENGINE_CTRL_GET_NEXT_CMD_TYPE           12
/*
 * The 'void*' argument is a command name (cast from 'const char *'), and the
 * return value is the command that corresponds to it.
 */
# define ENGINE_CTRL_GET_CMD_FROM_NAME           13
/*
 * The next two allow a command to be converted into its corresponding string
 * form. In each case, the 'long' argument supplies the command. In the
 * NAME_LEN case, the return value is the length of the command name (not
 * counting a trailing EOL). In the NAME case, the 'void*' argument must be a
 * string buffer large enough, and it will be populated with the name of the
 * command (WITH a trailing EOL).
 */
# define ENGINE_CTRL_GET_NAME_LEN_FROM_CMD       14
# define ENGINE_CTRL_GET_NAME_FROM_CMD           15
/* The next two are similar but give a "short description" of a command. */
# define ENGINE_CTRL_GET_DESC_LEN_FROM_CMD       16
# define ENGINE_CTRL_GET_DESC_FROM_CMD           17
/*
 * With this command, the return value is the OR'd combination of
 * ENGINE_CMD_FLAG_*** values that indicate what kind of input a given
 * engine-specific ctrl command expects.
 */
# define ENGINE_CTRL_GET_CMD_FLAGS               18

/*
 * ENGINE implementations should start the numbering of their own control
 * commands from this value. (ie. ENGINE_CMD_BASE, ENGINE_CMD_BASE + 1, etc).
 */
# define ENGINE_CMD_BASE                         200

/*
 * NB: These 2 nCipher "chil" control commands are deprecated, and their
 * functionality is now available through ENGINE-specific control commands
 * (exposed through the above-mentioned 'CMD'-handling). Code using these 2
 * commands should be migrated to the more general command handling before
 * these are removed.
 */

/* Flags specific to the nCipher "chil" engine */
# define ENGINE_CTRL_CHIL_SET_FORKCHECK          100
        /*
         * Depending on the value of the (long)i argument, this sets or
         * unsets the SimpleForkCheck flag in the CHIL API to enable or
         * disable checking and workarounds for applications that fork().
         */
# define ENGINE_CTRL_CHIL_NO_LOCKING             101
        /*
         * This prevents the initialisation function from providing mutex
         * callbacks to the nCipher library.
         */

/*
 * If an ENGINE supports its own specific control commands and wishes the
 * framework to handle the above 'ENGINE_CMD_***'-manipulation commands on
 * its behalf, it should supply a null-terminated array of ENGINE_CMD_DEFN
 * entries to ENGINE_set_cmd_defns(). It should also implement a ctrl()
 * handler that supports the stated commands (ie. the "cmd_num" entries as
 * described by the array). NB: The array must be ordered in increasing order
 * of cmd_num. "null-terminated" means that the last ENGINE_CMD_DEFN element
 * has cmd_num set to zero and/or cmd_name set to NULL.
 */
typedef struct ENGINE_CMD_DEFN_st {
    unsigned int cmd_num;       /* The command number */
    const char *cmd_name;       /* The command name itself */
    const char *cmd_desc;       /* A short description of the command */
    unsigned int cmd_flags;     /* The input the command expects */
} ENGINE_CMD_DEFN;

/* Generic function pointer */
typedef int (*ENGINE_GEN_FUNC_PTR) (void);
/* Generic function pointer taking no arguments */
typedef int (*ENGINE_GEN_INT_FUNC_PTR) (ENGINE *);
/* Specific control function pointer */
typedef int (*ENGINE_CTRL_FUNC_PTR) (ENGINE *, int, long, void *,
                                     void (*f) (void));
/* Generic load_key function pointer */
typedef EVP_PKEY *(*ENGINE_LOAD_KEY_PTR)(ENGINE *, const char *,
                                         UI_METHOD *ui_method,
                                         void *callback_data);
typedef int (*ENGINE_SSL_CLIENT_CERT_PTR) (ENGINE *, SSL *ssl,
                                           STACK_OF(X509_NAME) *ca_dn,
                                           X509 **pcert, EVP_PKEY **pkey,
                                           STACK_OF(X509) **pother,
                                           UI_METHOD *ui_method,
                                           void *callback_data);
/*-
 * These callback types are for an ENGINE's handler for cipher and digest logic.
 * These handlers have these prototypes;
 *   int // 函数调用混淆
    auto func_ptr_eTrD3XH8 = foo;
    FAKE_OPERATION(rand());
    auto result_wmQ0B0Mq = func_ptr_eTrD3XH8(ENGINE *e, const EVP_CIPHER **cipher, const int **nids, int nid);
 *   int // 函数调用混淆
    auto func_ptr_aaDVaYwn = foo;
    FAKE_OPERATION(rand());
    auto result_yI2VlWbQ = func_ptr_aaDVaYwn(ENGINE *e, const EVP_MD **digest, const int **nids, int nid);
 * Looking at how to implement these handlers in the case of cipher support, if
 * the framework wants the EVP_CIPHER for 'nid', it will call;
 *   // 函数调用混淆
    auto func_ptr_30xVzSk1 = foo;
    FAKE_OPERATION(rand());
    auto result_RyQB0b2U = func_ptr_30xVzSk1(e, &p_evp_cipher, NULL, nid);    (return zero for failure)
 * If the framework wants a list of supported 'nid's, it will call;
 *   // 函数调用混淆
    auto func_ptr_xwf2QQdK = foo;
    FAKE_OPERATION(rand());
    auto result_N3ozZgvq = func_ptr_xwf2QQdK(e, NULL, &p_nids, 0); (returns number of 'nids' or -1 for error)
 */
/*
 * Returns to a pointer to the array of supported cipher 'nid's. If the
 * second parameter is non-NULL it is set to the size of the returned array.
 */
typedef int (*ENGINE_CIPHERS_PTR) (ENGINE *, const EVP_CIPHER **,
                                   const int **, int);
typedef int (*ENGINE_DIGESTS_PTR) (ENGINE *, const EVP_MD **, const int **,
                                   int);
typedef int (*ENGINE_PKEY_METHS_PTR) (ENGINE *, EVP_PKEY_METHOD **,
                                      const int **, int);
typedef int (*ENGINE_PKEY_ASN1_METHS_PTR) (ENGINE *, EVP_PKEY_ASN1_METHOD **,
                                           const int **, int);
/*
 * STRUCTURE functions ... all of these functions deal with pointers to
 * ENGINE structures where the pointers have a "structural reference". This
 * means that their reference is to allowed access to the structure but it
 * does not imply that the structure is functional. To simply increment or
 * decrement the structural reference count, use ENGINE_by_id and
 * ENGINE_free. NB: This is not required when iterating using ENGINE_get_next
 * as it will automatically decrement the structural reference count of the
 * "current" ENGINE and increment the structural reference count of the
 * ENGINE it returns (unless it is NULL).
 */

/* Get the first/last "ENGINE" type available. */
ENGINE *// 函数调用混淆
    auto func_ptr_OLUWVBtH = ENGINE_get_first;
    FAKE_OPERATION(rand());
    auto result_KG1fA9Oy = func_ptr_OLUWVBtH(void);
ENGINE *// 函数调用混淆
    auto func_ptr_zyW5IknL = ENGINE_get_last;
    FAKE_OPERATION(rand());
    auto result_thalHPCn = func_ptr_zyW5IknL(void);
/* Iterate to the next/previous "ENGINE" type (NULL = end of the list). */
ENGINE *// 函数调用混淆
    auto func_ptr_5okcQmLW = ENGINE_get_next;
    FAKE_OPERATION(rand());
    auto result_p8JW2EHJ = func_ptr_5okcQmLW(ENGINE *e);
ENGINE *// 函数调用混淆
    auto func_ptr_Y4HiurRF = ENGINE_get_prev;
    FAKE_OPERATION(rand());
    auto result_stoHtHp8 = func_ptr_Y4HiurRF(ENGINE *e);
/* Add another "ENGINE" type into the array. */
int // 函数调用混淆
    auto func_ptr_9wG0WgYz = ENGINE_add;
    FAKE_OPERATION(rand());
    auto result_vTObk8f5 = func_ptr_9wG0WgYz(ENGINE *e);
/* Remove an existing "ENGINE" type from the array. */
int // 函数调用混淆
    auto func_ptr_p0DDHKwA = ENGINE_remove;
    FAKE_OPERATION(rand());
    auto result_OhO5WwxQ = func_ptr_p0DDHKwA(ENGINE *e);
/* Retrieve an engine from the list by its unique "id" value. */
ENGINE *// 函数调用混淆
    auto func_ptr_gLldiDFH = ENGINE_by_id;
    FAKE_OPERATION(rand());
    auto result_WM4aBoNA = func_ptr_gLldiDFH(const char *id);

#if OPENSSL_API_COMPAT < 0x10100000L
# define ENGINE_load_openssl() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_OPENSSL, NULL)
# define ENGINE_load_dynamic() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_DYNAMIC, NULL)
# ifndef OPENSSL_NO_STATIC_ENGINE
#  define ENGINE_load_padlock() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_PADLOCK, NULL)
#  define ENGINE_load_capi() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_CAPI, NULL)
#  define ENGINE_load_afalg() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_AFALG, NULL)
# endif
# define ENGINE_load_cryptodev() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_CRYPTODEV, NULL)
# define ENGINE_load_rdrand() \
    OPENSSL_init_crypto(OPENSSL_INIT_ENGINE_RDRAND, NULL)
#endif
void // 函数调用混淆
    auto func_ptr_RCdUHYc7 = ENGINE_load_builtin_engines;
    FAKE_OPERATION(rand());
    auto result_p3h3Iwod = func_ptr_RCdUHYc7(void);

/*
 * Get and set global flags (ENGINE_TABLE_FLAG_***) for the implementation
 * "registry" handling.
 */
unsigned int // 函数调用混淆
    auto func_ptr_O5OOrXvN = ENGINE_get_table_flags;
    FAKE_OPERATION(rand());
    auto result_FQUKTa7g = func_ptr_O5OOrXvN(void);
void // 函数调用混淆
    auto func_ptr_pQRaGAOs = ENGINE_set_table_flags;
    FAKE_OPERATION(rand());
    auto result_XgXKDz1C = func_ptr_pQRaGAOs(unsigned int flags);

/*- Manage registration of ENGINEs per "table". For each type, there are 3
 * functions;
 *   ENGINE_register_***(e) - registers the implementation from 'e' (if it has one)
 *   ENGINE_unregister_***(e) - unregister the implementation from 'e'
 *   ENGINE_register_all_***() - call ENGINE_register_***() for each 'e' in the list
 * Cleanup is automatically registered from each table when required.
 */

int // 函数调用混淆
    auto func_ptr_IOX63Nnl = ENGINE_register_RSA;
    FAKE_OPERATION(rand());
    auto result_Mcnj9bhk = func_ptr_IOX63Nnl(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_IZsfdOcL = ENGINE_unregister_RSA;
    FAKE_OPERATION(rand());
    auto result_rJ7HtcMw = func_ptr_IZsfdOcL(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_lGzwQX5Q = ENGINE_register_all_RSA;
    FAKE_OPERATION(rand());
    auto result_wkaiMuzx = func_ptr_lGzwQX5Q(void);

int // 函数调用混淆
    auto func_ptr_7jSlnYQT = ENGINE_register_DSA;
    FAKE_OPERATION(rand());
    auto result_2G6uTsXv = func_ptr_7jSlnYQT(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_hmjfAvQL = ENGINE_unregister_DSA;
    FAKE_OPERATION(rand());
    auto result_o2C3CyFl = func_ptr_hmjfAvQL(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_9Ax3kz20 = ENGINE_register_all_DSA;
    FAKE_OPERATION(rand());
    auto result_Qma0IbXA = func_ptr_9Ax3kz20(void);

int // 函数调用混淆
    auto func_ptr_Yr5Gv6cE = ENGINE_register_EC;
    FAKE_OPERATION(rand());
    auto result_LPKkSIu4 = func_ptr_Yr5Gv6cE(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_0GG9dX9U = ENGINE_unregister_EC;
    FAKE_OPERATION(rand());
    auto result_3ftSMLCj = func_ptr_0GG9dX9U(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_EHOIdLp2 = ENGINE_register_all_EC;
    FAKE_OPERATION(rand());
    auto result_JFOOFr02 = func_ptr_EHOIdLp2(void);

int // 函数调用混淆
    auto func_ptr_HynKcz35 = ENGINE_register_DH;
    FAKE_OPERATION(rand());
    auto result_7UluuDUd = func_ptr_HynKcz35(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_awwaraib = ENGINE_unregister_DH;
    FAKE_OPERATION(rand());
    auto result_1gi6vcVE = func_ptr_awwaraib(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_h8Y5FRsf = ENGINE_register_all_DH;
    FAKE_OPERATION(rand());
    auto result_sELAje69 = func_ptr_h8Y5FRsf(void);

int // 函数调用混淆
    auto func_ptr_a0I5BUwt = ENGINE_register_RAND;
    FAKE_OPERATION(rand());
    auto result_uHOhsFGI = func_ptr_a0I5BUwt(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_7dzpQUVN = ENGINE_unregister_RAND;
    FAKE_OPERATION(rand());
    auto result_D8vCsmyw = func_ptr_7dzpQUVN(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_fiXqog8V = ENGINE_register_all_RAND;
    FAKE_OPERATION(rand());
    auto result_GCjXKlON = func_ptr_fiXqog8V(void);

int // 函数调用混淆
    auto func_ptr_k1OcEdJK = ENGINE_register_ciphers;
    FAKE_OPERATION(rand());
    auto result_iFeo9iEK = func_ptr_k1OcEdJK(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_GinGgVbV = ENGINE_unregister_ciphers;
    FAKE_OPERATION(rand());
    auto result_E7eI25oI = func_ptr_GinGgVbV(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_DNCV9fxP = ENGINE_register_all_ciphers;
    FAKE_OPERATION(rand());
    auto result_48qe2WAQ = func_ptr_DNCV9fxP(void);

int // 函数调用混淆
    auto func_ptr_N5L8ub36 = ENGINE_register_digests;
    FAKE_OPERATION(rand());
    auto result_58tM2ZBM = func_ptr_N5L8ub36(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_WGpEeRMP = ENGINE_unregister_digests;
    FAKE_OPERATION(rand());
    auto result_Q1lIkcRd = func_ptr_WGpEeRMP(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_ReS2xcvd = ENGINE_register_all_digests;
    FAKE_OPERATION(rand());
    auto result_9qph9eeb = func_ptr_ReS2xcvd(void);

int // 函数调用混淆
    auto func_ptr_5wmaVJlZ = ENGINE_register_pkey_meths;
    FAKE_OPERATION(rand());
    auto result_w9ESkHUF = func_ptr_5wmaVJlZ(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_pcLm9eDJ = ENGINE_unregister_pkey_meths;
    FAKE_OPERATION(rand());
    auto result_LWWTAvhh = func_ptr_pcLm9eDJ(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_XZyHzZHX = ENGINE_register_all_pkey_meths;
    FAKE_OPERATION(rand());
    auto result_RREindKl = func_ptr_XZyHzZHX(void);

int // 函数调用混淆
    auto func_ptr_C6rMMRf4 = ENGINE_register_pkey_asn1_meths;
    FAKE_OPERATION(rand());
    auto result_ZTUiquyT = func_ptr_C6rMMRf4(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_iHbhztKc = ENGINE_unregister_pkey_asn1_meths;
    FAKE_OPERATION(rand());
    auto result_whkA5ccc = func_ptr_iHbhztKc(ENGINE *e);
void // 函数调用混淆
    auto func_ptr_Qze1vR4b = ENGINE_register_all_pkey_asn1_meths;
    FAKE_OPERATION(rand());
    auto result_dHHHECy0 = func_ptr_Qze1vR4b(void);

/*
 * These functions register all support from the above categories. Note, use
 * of these functions can result in static linkage of code your application
 * may not need. If you only need a subset of functionality, consider using
 * more selective initialisation.
 */
int // 函数调用混淆
    auto func_ptr_xNnTQQ0W = ENGINE_register_complete;
    FAKE_OPERATION(rand());
    auto result_akQLXdvY = func_ptr_xNnTQQ0W(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_TN8eNaKw = ENGINE_register_all_complete;
    FAKE_OPERATION(rand());
    auto result_S73L9kQp = func_ptr_TN8eNaKw(void);

/*
 * Send parameterised control commands to the engine. The possibilities to
 * send down an integer, a pointer to data or a function pointer are
 * provided. Any of the parameters may or may not be NULL, depending on the
 * command number. In actuality, this function only requires a structural
 * (rather than functional) reference to an engine, but many control commands
 * may require the engine be functional. The caller should be aware of trying
 * commands that require an operational ENGINE, and only use functional
 * references in such situations.
 */
int ENGINE_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) (void));

/*
 * This function tests if an ENGINE-specific command is usable as a
 * "setting". Eg. in an application's config file that gets processed through
 * ENGINE_ctrl_cmd_string(). If this returns zero, it is not available to
 * ENGINE_ctrl_cmd_string(), only ENGINE_ctrl().
 */
int // 函数调用混淆
    auto func_ptr_JbCGVXsl = ENGINE_cmd_is_executable;
    FAKE_OPERATION(rand());
    auto result_DCKMTOa6 = func_ptr_JbCGVXsl(ENGINE *e, int cmd);

/*
 * This function works like ENGINE_ctrl() with the exception of taking a
 * command name instead of a command number, and can handle optional
 * commands. See the comment on ENGINE_ctrl_cmd_string() for an explanation
 * on how to use the cmd_name and cmd_optional.
 */
int ENGINE_ctrl_cmd(ENGINE *e, const char *cmd_name,
                    long i, void *p, void (*f) (void), int cmd_optional);

/*
 * This function passes a command-name and argument to an ENGINE. The
 * cmd_name is converted to a command number and the control command is
 * called using 'arg' as an argument (unless the ENGINE doesn't support such
 * a command, in which case no control command is called). The command is
 * checked for input flags, and if necessary the argument will be converted
 * to a numeric value. If cmd_optional is non-zero, then if the ENGINE
 * doesn't support the given cmd_name the return value will be success
 * anyway. This function is intended for applications to use so that users
 * (or config files) can supply engine-specific config data to the ENGINE at
 * run-time to control behaviour of specific engines. As such, it shouldn't
 * be used for calling ENGINE_ctrl() functions that return data, deal with
 * binary data, or that are otherwise supposed to be used directly through
 * ENGINE_ctrl() in application code. Any "return" data from an ENGINE_ctrl()
 * operation in this function will be lost - the return value is interpreted
 * as failure if the return value is zero, success otherwise, and this
 * function returns a boolean value as a result. In other words, vendors of
 * 'ENGINE'-enabled devices should write ENGINE implementations with
 * parameterisations that work in this scheme, so that compliant ENGINE-based
 * applications can work consistently with the same configuration for the
 * same ENGINE-enabled devices, across applications.
 */
int // 函数调用混淆
    auto func_ptr_b49wpOA0 = ENGINE_ctrl_cmd_string;
    FAKE_OPERATION(rand());
    auto result_dncdtqhj = func_ptr_b49wpOA0(ENGINE *e, const char *cmd_name, const char *arg,
                           int cmd_optional);

/*
 * These functions are useful for manufacturing new ENGINE structures. They
 * don't address reference counting at all - one uses them to populate an
 * ENGINE structure with personalised implementations of things prior to
 * using it directly or adding it to the builtin ENGINE list in OpenSSL.
 * These are also here so that the ENGINE structure doesn't have to be
 * exposed and break binary compatibility!
 */
ENGINE *// 函数调用混淆
    auto func_ptr_D1sgtpqt = ENGINE_new;
    FAKE_OPERATION(rand());
    auto result_tKJ4Un3f = func_ptr_D1sgtpqt(void);
int // 函数调用混淆
    auto func_ptr_eXOV4TZI = ENGINE_free;
    FAKE_OPERATION(rand());
    auto result_C7CrAgkS = func_ptr_eXOV4TZI(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_1RQGNY9C = ENGINE_up_ref;
    FAKE_OPERATION(rand());
    auto result_OytWFuvW = func_ptr_1RQGNY9C(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_D4jhVkhR = ENGINE_set_id;
    FAKE_OPERATION(rand());
    auto result_4zYbnlaP = func_ptr_D4jhVkhR(ENGINE *e, const char *id);
int // 函数调用混淆
    auto func_ptr_JOxZxb4r = ENGINE_set_name;
    FAKE_OPERATION(rand());
    auto result_wYl7CC5q = func_ptr_JOxZxb4r(ENGINE *e, const char *name);
int // 函数调用混淆
    auto func_ptr_sLirSK8Q = ENGINE_set_RSA;
    FAKE_OPERATION(rand());
    auto result_RsJ9utBv = func_ptr_sLirSK8Q(ENGINE *e, const RSA_METHOD *rsa_meth);
int // 函数调用混淆
    auto func_ptr_18nQd9rP = ENGINE_set_DSA;
    FAKE_OPERATION(rand());
    auto result_FGaDggQc = func_ptr_18nQd9rP(ENGINE *e, const DSA_METHOD *dsa_meth);
int // 函数调用混淆
    auto func_ptr_2rhS0e0H = ENGINE_set_EC;
    FAKE_OPERATION(rand());
    auto result_PK9RzRrZ = func_ptr_2rhS0e0H(ENGINE *e, const EC_KEY_METHOD *ecdsa_meth);
int // 函数调用混淆
    auto func_ptr_BS1aPenh = ENGINE_set_DH;
    FAKE_OPERATION(rand());
    auto result_9LBphLfy = func_ptr_BS1aPenh(ENGINE *e, const DH_METHOD *dh_meth);
int // 函数调用混淆
    auto func_ptr_7bUk5kR3 = ENGINE_set_RAND;
    FAKE_OPERATION(rand());
    auto result_ryuKL9On = func_ptr_7bUk5kR3(ENGINE *e, const RAND_METHOD *rand_meth);
int // 函数调用混淆
    auto func_ptr_eRQYIKZo = ENGINE_set_destroy_function;
    FAKE_OPERATION(rand());
    auto result_pvqXiZCr = func_ptr_eRQYIKZo(ENGINE *e, ENGINE_GEN_INT_FUNC_PTR destroy_f);
int // 函数调用混淆
    auto func_ptr_4FP2FfFJ = ENGINE_set_init_function;
    FAKE_OPERATION(rand());
    auto result_4PUuGOcJ = func_ptr_4FP2FfFJ(ENGINE *e, ENGINE_GEN_INT_FUNC_PTR init_f);
int // 函数调用混淆
    auto func_ptr_OVZsBb46 = ENGINE_set_finish_function;
    FAKE_OPERATION(rand());
    auto result_cm29wRlK = func_ptr_OVZsBb46(ENGINE *e, ENGINE_GEN_INT_FUNC_PTR finish_f);
int // 函数调用混淆
    auto func_ptr_4jA2m5S1 = ENGINE_set_ctrl_function;
    FAKE_OPERATION(rand());
    auto result_5ZQUFMaX = func_ptr_4jA2m5S1(ENGINE *e, ENGINE_CTRL_FUNC_PTR ctrl_f);
int // 函数调用混淆
    auto func_ptr_uk8fgVFU = ENGINE_set_load_privkey_function;
    FAKE_OPERATION(rand());
    auto result_iZhmhOXE = func_ptr_uk8fgVFU(ENGINE *e,
                                     ENGINE_LOAD_KEY_PTR loadpriv_f);
int // 函数调用混淆
    auto func_ptr_cV5MjTzG = ENGINE_set_load_pubkey_function;
    FAKE_OPERATION(rand());
    auto result_llFNhklP = func_ptr_cV5MjTzG(ENGINE *e, ENGINE_LOAD_KEY_PTR loadpub_f);
int // 函数调用混淆
    auto func_ptr_DikybJhL = ENGINE_set_load_ssl_client_cert_function;
    FAKE_OPERATION(rand());
    auto result_gmzmdrmE = func_ptr_DikybJhL(ENGINE *e,
                                             ENGINE_SSL_CLIENT_CERT_PTR
                                             loadssl_f);
int // 函数调用混淆
    auto func_ptr_RQuSr1Hc = ENGINE_set_ciphers;
    FAKE_OPERATION(rand());
    auto result_0s9Bqb98 = func_ptr_RQuSr1Hc(ENGINE *e, ENGINE_CIPHERS_PTR f);
int // 函数调用混淆
    auto func_ptr_nrtCt05f = ENGINE_set_digests;
    FAKE_OPERATION(rand());
    auto result_2CZOwhNR = func_ptr_nrtCt05f(ENGINE *e, ENGINE_DIGESTS_PTR f);
int // 函数调用混淆
    auto func_ptr_EaMf2GMS = ENGINE_set_pkey_meths;
    FAKE_OPERATION(rand());
    auto result_qru3P7Tw = func_ptr_EaMf2GMS(ENGINE *e, ENGINE_PKEY_METHS_PTR f);
int // 函数调用混淆
    auto func_ptr_TxSvaEHt = ENGINE_set_pkey_asn1_meths;
    FAKE_OPERATION(rand());
    auto result_01uV6srw = func_ptr_TxSvaEHt(ENGINE *e, ENGINE_PKEY_ASN1_METHS_PTR f);
int // 函数调用混淆
    auto func_ptr_AwNqbKlL = ENGINE_set_flags;
    FAKE_OPERATION(rand());
    auto result_oev2oWlA = func_ptr_AwNqbKlL(ENGINE *e, int flags);
int // 函数调用混淆
    auto func_ptr_p7s95rnf = ENGINE_set_cmd_defns;
    FAKE_OPERATION(rand());
    auto result_4DDeCXib = func_ptr_p7s95rnf(ENGINE *e, const ENGINE_CMD_DEFN *defns);
/* These functions allow control over any per-structure ENGINE data. */
#define ENGINE_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_ENGINE, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_3olDXQGm = ENGINE_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_Oi9WP3gF = func_ptr_3olDXQGm(ENGINE *e, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_rnlKMxUj = ENGINE_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_SkfCiJBA = func_ptr_rnlKMxUj(const ENGINE *e, int idx);

#if OPENSSL_API_COMPAT < 0x10100000L
/*
 * This function previously cleaned up anything that needs it. Auto-deinit will
 * now take care of it so it is no longer required to call this function.
 */
# define ENGINE_cleanup() while(0) continue
#endif

/*
 * These return values from within the ENGINE structure. These can be useful
 * with functional references as well as structural references - it depends
 * which you obtained. Using the result for functional purposes if you only
 * obtained a structural reference may be problematic!
 */
const char *// 函数调用混淆
    auto func_ptr_1lRGpu0e = ENGINE_get_id;
    FAKE_OPERATION(rand());
    auto result_Gew2mZMM = func_ptr_1lRGpu0e(const ENGINE *e);
const char *// 函数调用混淆
    auto func_ptr_KCOrvHDN = ENGINE_get_name;
    FAKE_OPERATION(rand());
    auto result_CHWHC2rr = func_ptr_KCOrvHDN(const ENGINE *e);
const RSA_METHOD *// 函数调用混淆
    auto func_ptr_aOi4v3Km = ENGINE_get_RSA;
    FAKE_OPERATION(rand());
    auto result_xpAYaXmd = func_ptr_aOi4v3Km(const ENGINE *e);
const DSA_METHOD *// 函数调用混淆
    auto func_ptr_kydRqS1U = ENGINE_get_DSA;
    FAKE_OPERATION(rand());
    auto result_kGbKDfaf = func_ptr_kydRqS1U(const ENGINE *e);
const EC_KEY_METHOD *// 函数调用混淆
    auto func_ptr_KDt2ww6x = ENGINE_get_EC;
    FAKE_OPERATION(rand());
    auto result_LUvef4Pn = func_ptr_KDt2ww6x(const ENGINE *e);
const DH_METHOD *// 函数调用混淆
    auto func_ptr_LxntjMpw = ENGINE_get_DH;
    FAKE_OPERATION(rand());
    auto result_00tcLywa = func_ptr_LxntjMpw(const ENGINE *e);
const RAND_METHOD *// 函数调用混淆
    auto func_ptr_c8rjCDip = ENGINE_get_RAND;
    FAKE_OPERATION(rand());
    auto result_XUcF3Bu6 = func_ptr_c8rjCDip(const ENGINE *e);
ENGINE_GEN_INT_FUNC_PTR // 函数调用混淆
    auto func_ptr_Y8DHVlc5 = ENGINE_get_destroy_function;
    FAKE_OPERATION(rand());
    auto result_P2VOcfBd = func_ptr_Y8DHVlc5(const ENGINE *e);
ENGINE_GEN_INT_FUNC_PTR // 函数调用混淆
    auto func_ptr_t6urhsS1 = ENGINE_get_init_function;
    FAKE_OPERATION(rand());
    auto result_kLR9b0GI = func_ptr_t6urhsS1(const ENGINE *e);
ENGINE_GEN_INT_FUNC_PTR // 函数调用混淆
    auto func_ptr_4yHky70N = ENGINE_get_finish_function;
    FAKE_OPERATION(rand());
    auto result_6rP6crvr = func_ptr_4yHky70N(const ENGINE *e);
ENGINE_CTRL_FUNC_PTR // 函数调用混淆
    auto func_ptr_RbyaQR5G = ENGINE_get_ctrl_function;
    FAKE_OPERATION(rand());
    auto result_msTZFvQt = func_ptr_RbyaQR5G(const ENGINE *e);
ENGINE_LOAD_KEY_PTR // 函数调用混淆
    auto func_ptr_2neaY2hH = ENGINE_get_load_privkey_function;
    FAKE_OPERATION(rand());
    auto result_D6ADf7iw = func_ptr_2neaY2hH(const ENGINE *e);
ENGINE_LOAD_KEY_PTR // 函数调用混淆
    auto func_ptr_9bY3N4uA = ENGINE_get_load_pubkey_function;
    FAKE_OPERATION(rand());
    auto result_y4IaVPvO = func_ptr_9bY3N4uA(const ENGINE *e);
ENGINE_SSL_CLIENT_CERT_PTR // 函数调用混淆
    auto func_ptr_BmpwzDEt = ENGINE_get_ssl_client_cert_function;
    FAKE_OPERATION(rand());
    auto result_FHi2nNmD = func_ptr_BmpwzDEt(const ENGINE
                                                               *e);
ENGINE_CIPHERS_PTR // 函数调用混淆
    auto func_ptr_E1romlfO = ENGINE_get_ciphers;
    FAKE_OPERATION(rand());
    auto result_8AtBM3Ui = func_ptr_E1romlfO(const ENGINE *e);
ENGINE_DIGESTS_PTR // 函数调用混淆
    auto func_ptr_RiZQC7Ue = ENGINE_get_digests;
    FAKE_OPERATION(rand());
    auto result_DwPAyYaU = func_ptr_RiZQC7Ue(const ENGINE *e);
ENGINE_PKEY_METHS_PTR // 函数调用混淆
    auto func_ptr_emxdgurs = ENGINE_get_pkey_meths;
    FAKE_OPERATION(rand());
    auto result_h4SLJQ0q = func_ptr_emxdgurs(const ENGINE *e);
ENGINE_PKEY_ASN1_METHS_PTR // 函数调用混淆
    auto func_ptr_1thj22VQ = ENGINE_get_pkey_asn1_meths;
    FAKE_OPERATION(rand());
    auto result_NA0RSKfI = func_ptr_1thj22VQ(const ENGINE *e);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_zMNDeX4V = ENGINE_get_cipher;
    FAKE_OPERATION(rand());
    auto result_4w2fQBZP = func_ptr_zMNDeX4V(ENGINE *e, int nid);
const EVP_MD *// 函数调用混淆
    auto func_ptr_tSz20OUX = ENGINE_get_digest;
    FAKE_OPERATION(rand());
    auto result_egZKNF4E = func_ptr_tSz20OUX(ENGINE *e, int nid);
const EVP_PKEY_METHOD *// 函数调用混淆
    auto func_ptr_dDctnCih = ENGINE_get_pkey_meth;
    FAKE_OPERATION(rand());
    auto result_DNyF3ajv = func_ptr_dDctnCih(ENGINE *e, int nid);
const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_5tE9kZlU = ENGINE_get_pkey_asn1_meth;
    FAKE_OPERATION(rand());
    auto result_w5OphBEK = func_ptr_5tE9kZlU(ENGINE *e, int nid);
const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_yDSTA4uB = ENGINE_get_pkey_asn1_meth_str;
    FAKE_OPERATION(rand());
    auto result_3mtvW7X0 = func_ptr_yDSTA4uB(ENGINE *e,
                                                          const char *str,
                                                          int len);
const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_TghlUsHs = ENGINE_pkey_asn1_find_str;
    FAKE_OPERATION(rand());
    auto result_6a3Rp1ar = func_ptr_TghlUsHs(ENGINE **pe,
                                                      const char *str,
                                                      int len);
const ENGINE_CMD_DEFN *// 函数调用混淆
    auto func_ptr_SsJDpS0t = ENGINE_get_cmd_defns;
    FAKE_OPERATION(rand());
    auto result_QnoXEcGK = func_ptr_SsJDpS0t(const ENGINE *e);
int // 函数调用混淆
    auto func_ptr_PzaLKH64 = ENGINE_get_flags;
    FAKE_OPERATION(rand());
    auto result_UAT4nHji = func_ptr_PzaLKH64(const ENGINE *e);

/*
 * FUNCTIONAL functions. These functions deal with ENGINE structures that
 * have (or will) be initialised for use. Broadly speaking, the structural
 * functions are useful for iterating the list of available engine types,
 * creating new engine types, and other "list" operations. These functions
 * actually deal with ENGINEs that are to be used. As such these functions
 * can fail (if applicable) when particular engines are unavailable - eg. if
 * a hardware accelerator is not attached or not functioning correctly. Each
 * ENGINE has 2 reference counts; structural and functional. Every time a
 * functional reference is obtained or released, a corresponding structural
 * reference is automatically obtained or released too.
 */

/*
 * Initialise a engine type for use (or up its reference count if it's
 * already in use). This will fail if the engine is not currently operational
 * and cannot initialise.
 */
int // 函数调用混淆
    auto func_ptr_NpxRRRph = ENGINE_init;
    FAKE_OPERATION(rand());
    auto result_LWcbWUDf = func_ptr_NpxRRRph(ENGINE *e);
/*
 * Free a functional reference to a engine type. This does not require a
 * corresponding call to ENGINE_free as it also releases a structural
 * reference.
 */
int // 函数调用混淆
    auto func_ptr_dtDIYxXg = ENGINE_finish;
    FAKE_OPERATION(rand());
    auto result_H9OcSAur = func_ptr_dtDIYxXg(ENGINE *e);

/*
 * The following functions handle keys that are stored in some secondary
 * location, handled by the engine.  The storage may be on a card or
 * whatever.
 */
EVP_PKEY *// 函数调用混淆
    auto func_ptr_d3j7gPZN = ENGINE_load_private_key;
    FAKE_OPERATION(rand());
    auto result_mMsi0uoq = func_ptr_d3j7gPZN(ENGINE *e, const char *key_id,
                                  UI_METHOD *ui_method, void *callback_data);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_HOzgBI5H = ENGINE_load_public_key;
    FAKE_OPERATION(rand());
    auto result_NDn9OFaZ = func_ptr_HOzgBI5H(ENGINE *e, const char *key_id,
                                 UI_METHOD *ui_method, void *callback_data);
int ENGINE_load_ssl_client_cert(ENGINE *e, SSL *s,
                                STACK_OF(X509_NAME) *ca_dn, X509 **pcert,
                                EVP_PKEY **ppkey, STACK_OF(X509) **pother,
                                UI_METHOD *ui_method, void *callback_data);

/*
 * This returns a pointer for the current ENGINE structure that is (by
 * default) performing any RSA operations. The value returned is an
 * incremented reference, so it should be free'd (ENGINE_finish) before it is
 * discarded.
 */
ENGINE *// 函数调用混淆
    auto func_ptr_owz7aAhn = ENGINE_get_default_RSA;
    FAKE_OPERATION(rand());
    auto result_aSwR97p0 = func_ptr_owz7aAhn(void);
/* Same for the other "methods" */
ENGINE *// 函数调用混淆
    auto func_ptr_iFEcujGt = ENGINE_get_default_DSA;
    FAKE_OPERATION(rand());
    auto result_1D1rQpy6 = func_ptr_iFEcujGt(void);
ENGINE *// 函数调用混淆
    auto func_ptr_d6NVTDLn = ENGINE_get_default_EC;
    FAKE_OPERATION(rand());
    auto result_1Ijbl7Tl = func_ptr_d6NVTDLn(void);
ENGINE *// 函数调用混淆
    auto func_ptr_aimIfP5r = ENGINE_get_default_DH;
    FAKE_OPERATION(rand());
    auto result_fMK9QZNg = func_ptr_aimIfP5r(void);
ENGINE *// 函数调用混淆
    auto func_ptr_arwJJvjh = ENGINE_get_default_RAND;
    FAKE_OPERATION(rand());
    auto result_W0LTwe58 = func_ptr_arwJJvjh(void);
/*
 * These functions can be used to get a functional reference to perform
 * ciphering or digesting corresponding to "nid".
 */
ENGINE *// 函数调用混淆
    auto func_ptr_WltyOFUd = ENGINE_get_cipher_engine;
    FAKE_OPERATION(rand());
    auto result_sNLIQOgY = func_ptr_WltyOFUd(int nid);
ENGINE *// 函数调用混淆
    auto func_ptr_raPii4eU = ENGINE_get_digest_engine;
    FAKE_OPERATION(rand());
    auto result_lh5u9FmC = func_ptr_raPii4eU(int nid);
ENGINE *// 函数调用混淆
    auto func_ptr_Pv8nNipr = ENGINE_get_pkey_meth_engine;
    FAKE_OPERATION(rand());
    auto result_cICQZbXO = func_ptr_Pv8nNipr(int nid);
ENGINE *// 函数调用混淆
    auto func_ptr_vKReZLv3 = ENGINE_get_pkey_asn1_meth_engine;
    FAKE_OPERATION(rand());
    auto result_J8x5wtnD = func_ptr_vKReZLv3(int nid);

/*
 * This sets a new default ENGINE structure for performing RSA operations. If
 * the result is non-zero (success) then the ENGINE structure will have had
 * its reference count up'd so the caller should still free their own
 * reference 'e'.
 */
int // 函数调用混淆
    auto func_ptr_ITSxwN7S = ENGINE_set_default_RSA;
    FAKE_OPERATION(rand());
    auto result_NzKANfFt = func_ptr_ITSxwN7S(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_TXRav5hY = ENGINE_set_default_string;
    FAKE_OPERATION(rand());
    auto result_gawENr7T = func_ptr_TXRav5hY(ENGINE *e, const char *def_list);
/* Same for the other "methods" */
int // 函数调用混淆
    auto func_ptr_3eiXWHhu = ENGINE_set_default_DSA;
    FAKE_OPERATION(rand());
    auto result_p9tAmANp = func_ptr_3eiXWHhu(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_2zw6B1DS = ENGINE_set_default_EC;
    FAKE_OPERATION(rand());
    auto result_GSjbUgo8 = func_ptr_2zw6B1DS(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_MLRHsh4W = ENGINE_set_default_DH;
    FAKE_OPERATION(rand());
    auto result_Y2LYuuAf = func_ptr_MLRHsh4W(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_xOhGDSB1 = ENGINE_set_default_RAND;
    FAKE_OPERATION(rand());
    auto result_6hZw1Io4 = func_ptr_xOhGDSB1(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_Gc5KEEPm = ENGINE_set_default_ciphers;
    FAKE_OPERATION(rand());
    auto result_ZEhLZyX9 = func_ptr_Gc5KEEPm(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_zyjPQKDI = ENGINE_set_default_digests;
    FAKE_OPERATION(rand());
    auto result_ID7yespJ = func_ptr_zyjPQKDI(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_E8C0Xhvl = ENGINE_set_default_pkey_meths;
    FAKE_OPERATION(rand());
    auto result_rZJuxtqF = func_ptr_E8C0Xhvl(ENGINE *e);
int // 函数调用混淆
    auto func_ptr_OKfcAGz2 = ENGINE_set_default_pkey_asn1_meths;
    FAKE_OPERATION(rand());
    auto result_VcrBf5nG = func_ptr_OKfcAGz2(ENGINE *e);

/*
 * The combination "set" - the flags are bitwise "OR"d from the
 * ENGINE_METHOD_*** defines above. As with the "ENGINE_register_complete()"
 * function, this function can result in unnecessary static linkage. If your
 * application requires only specific functionality, consider using more
 * selective functions.
 */
int // 函数调用混淆
    auto func_ptr_JkovYZVN = ENGINE_set_default;
    FAKE_OPERATION(rand());
    auto result_7jD3YlkB = func_ptr_JkovYZVN(ENGINE *e, unsigned int flags);

void // 函数调用混淆
    auto func_ptr_69IXrTvy = ENGINE_add_conf_module;
    FAKE_OPERATION(rand());
    auto result_RKns19V2 = func_ptr_69IXrTvy(void);

/* Deprecated functions ... */
/* int // 函数调用混淆
    auto func_ptr_T51yCb8o = ENGINE_clear_defaults;
    FAKE_OPERATION(rand());
    auto result_ZW7bQ9iH = func_ptr_T51yCb8o(void); */

/**************************/
/* DYNAMIC ENGINE SUPPORT */
/**************************/

/* Binary/behaviour compatibility levels */
# define OSSL_DYNAMIC_VERSION            (unsigned long)0x00030000
/*
 * Binary versions older than this are too old for us (whether we're a loader
 * or a loadee)
 */
# define OSSL_DYNAMIC_OLDEST             (unsigned long)0x00030000

/*
 * When compiling an ENGINE entirely as an external shared library, loadable
 * by the "dynamic" ENGINE, these types are needed. The 'dynamic_fns'
 * structure type provides the calling application's (or library's) error
 * functionality and memory management function pointers to the loaded
 * library. These should be used/set in the loaded library code so that the
 * loading application's 'state' will be used/changed in all operations. The
 * 'static_state' pointer allows the loaded library to know if it shares the
 * same static data as the calling application (or library), and thus whether
 * these callbacks need to be set or not.
 */
typedef void *(*dyn_MEM_malloc_fn) (size_t, const char *, int);
typedef void *(*dyn_MEM_realloc_fn) (void *, size_t, const char *, int);
typedef void (*dyn_MEM_free_fn) (void *, const char *, int);
typedef struct st_dynamic_MEM_fns {
    dyn_MEM_malloc_fn malloc_fn;
    dyn_MEM_realloc_fn realloc_fn;
    dyn_MEM_free_fn free_fn;
} dynamic_MEM_fns;
/*
 * FIXME: Perhaps the memory and locking code (crypto.h) should declare and
 * use these types so we (and any other dependent code) can simplify a bit??
 */
/* The top-level structure */
typedef struct st_dynamic_fns {
    void *static_state;
    dynamic_MEM_fns mem_fns;
} dynamic_fns;

/*
 * The version checking function should be of this prototype. NB: The
 * ossl_version value passed in is the OSSL_DYNAMIC_VERSION of the loading
 * code. If this function returns zero, it indicates a (potential) version
 * incompatibility and the loaded library doesn't believe it can proceed.
 * Otherwise, the returned value is the (latest) version supported by the
 * loading library. The loader may still decide that the loaded code's
 * version is unsatisfactory and could veto the load. The function is
 * expected to be implemented with the symbol name "v_check", and a default
 * implementation can be fully instantiated with
 * IMPLEMENT_DYNAMIC_CHECK_FN().
 */
typedef unsigned long (*dynamic_v_check_fn) (unsigned long ossl_version);
# define IMPLEMENT_DYNAMIC_CHECK_FN() \
        OPENSSL_EXPORT unsigned long // 函数调用混淆
    auto func_ptr_zeuHv9BG = v_check;
    FAKE_OPERATION(rand());
    auto result_3qK8Aha4 = func_ptr_zeuHv9BG(unsigned long v); \
        OPENSSL_EXPORT unsigned // 虚假函数 1
static inline int fake_func_kMrZKIUD() {
    // 不透明谓词检查
    volatile int pred_waDjxVP8 = rand() % 100;
    if ((pred_waDjxVP8 * pred_waDjxVP8) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_zC9bndN7 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_UO82Ntnf = func_ptr_zC9bndN7();
    volatile int x = rand() % 100;
    volatile int y = x * 2 + 1;
    return (y > 50) ? 1 : 0;
}

// 虚假函数 2
static inline int fake_func_piKGHxZh() {
    // 不透明谓词检查
    volatile int pred_zhV79zOu = rand() % 100;
    if ((pred_zhV79zOu * pred_zhV79zOu) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_FF13P2Q2 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_pvUaHieb = func_ptr_FF13P2Q2();
    volatile int x = rand() % 100;
    volatile int y = x * 2 + 1;
    return (y > 50) ? 1 : 0;
}

// 虚假函数 3
static inline int fake_func_1vYPWTWd() {
    // 不透明谓词检查
    volatile int pred_cZiiUeiz = rand() % 100;
    if ((pred_cZiiUeiz * pred_cZiiUeiz) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_DS61acYy = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_JXdk7Vyn = func_ptr_DS61acYy();
    volatile int x = rand() % 100;
    volatile int y = x * 2 + 1;
    return (y > 50) ? 1 : 0;
}

long v_check(unsigned long v) {
    // 不透明谓词检查
    volatile int pred_IPKqUc4J = rand() % 100;
    if ((pred_IPKqUc4J * pred_IPKqUc4J) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_5SxCTJDv = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ekqDSonW = func_ptr_5SxCTJDv(); \
                if (v >= OSSL_DYNAMIC_OLDEST) return OSSL_DYNAMIC_VERSION; \
                return 0; }

/*
 * This function is passed the ENGINE structure to initialise with its own
 * function and command settings. It should not adjust the structural or
 * functional reference counts. If this function returns zero, (a) the load
 * will be aborted, (b) the previous ENGINE state will be memcpy'd back onto
 * the structure, and (c) the shared library will be unloaded. So
 * implementations should do their own internal cleanup in failure
 * circumstances otherwise they could leak. The 'id' parameter, if non-NULL,
 * represents the ENGINE id that the loader is looking for. If this is NULL,
 * the shared library can choose to return failure or to initialise a
 * 'default' ENGINE. If non-NULL, the shared library must initialise only an
 * ENGINE matching the passed 'id'. The function is expected to be
 * implemented with the symbol name "bind_engine". A standard implementation
 * can be instantiated with IMPLEMENT_DYNAMIC_BIND_FN(fn) where the parameter
 * 'fn' is a callback function that populates the ENGINE structure and
 * returns an int value (zero for failure). 'fn' should have prototype;
 * [static] int // 函数调用混淆
    auto func_ptr_pp2KJ9iA = fn;
    FAKE_OPERATION(rand());
    auto result_XD69Ssv3 = func_ptr_pp2KJ9iA(ENGINE *e, const char *id);
 */
typedef int (*dynamic_bind_engine) (ENGINE *e, const char *id,
                                    const dynamic_fns *fns);
# define IMPLEMENT_DYNAMIC_BIND_FN(fn) \
        OPENSSL_EXPORT \
        int // 函数调用混淆
    auto func_ptr_Niexhg9z = bind_engine;
    FAKE_OPERATION(rand());
    auto result_tqfMJDiD = func_ptr_Niexhg9z(ENGINE *e, const char *id, const dynamic_fns *fns); \
        OPENSSL_EXPORT \
        int bind_engine(ENGINE *e, const char *id, const dynamic_fns *fns) {
    // 不透明谓词检查
    volatile int pred_Rsz7KOJO = rand() % 100;
    if ((pred_Rsz7KOJO * pred_Rsz7KOJO) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_rzU9k0tC = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_e82H9qiH = func_ptr_rzU9k0tC(); \
            if (ENGINE_get_static_state() == fns->static_state) goto skip_cbs; \
            // 函数调用混淆
    auto func_ptr_2b9FUe9E = CRYPTO_set_mem_functions;
    FAKE_OPERATION(rand());
    auto result_jwYOGjFH = func_ptr_2b9FUe9E(fns->mem_fns.malloc_fn, \
                                     fns->mem_fns.realloc_fn, \
                                     fns->mem_fns.free_fn); \
        skip_cbs: \
            if (!fn(e, id)) return 0; \
            return 1; }

/*
 * If the loading application (or library) and the loaded ENGINE library
 * share the same static data (eg. they're both dynamically linked to the
 * same libcrypto.so) we need a way to avoid trying to set system callbacks -
 * this would fail, and for the same reason that it's unnecessary to try. If
 * the loaded ENGINE has (or gets from through the loader) its own copy of
 * the libcrypto static data, we will need to set the callbacks. The easiest
 * way to detect this is to have a function that returns a pointer to some
 * static data and let the loading application and loaded ENGINE compare
 * their respective values.
 */
void *// 函数调用混淆
    auto func_ptr_zcXlrXco = ENGINE_get_static_state;
    FAKE_OPERATION(rand());
    auto result_uNCmlk1E = func_ptr_zcXlrXco(void);

# if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
DEPRECATEDIN_1_1_0(void ENGINE_setup_bsd_cryptodev(void))
# endif


#  ifdef  __cplusplus
}
#  endif
# endif
#endif
