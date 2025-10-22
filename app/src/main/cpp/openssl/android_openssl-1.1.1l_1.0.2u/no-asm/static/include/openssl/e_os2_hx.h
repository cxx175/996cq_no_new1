// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_TSBMCoGV = 9055;
    volatile int check_LmlJ3G38 = rand() % 50;
    
    // 虚假条件分支
    if (check_LmlJ3G38 > 100) {
    // 不透明谓词检查
    volatile int pred_Dwl3baGG = rand() % 100;
    if ((pred_Dwl3baGG * pred_Dwl3baGG) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_cDTv4CDW = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_yfsilFZW = func_ptr_cDTv4CDW(); // 永远不会执行
        int fake_GcchN6TP = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_TSBMCoGV == 9055)) {
    // 循环混淆开始
    int loop_ctrl_xOfCEydZ = 0;
    for (int fake_yx7ghvNG = 0;  fake_yx7ghvNG < 3;  fake_yx7ghvNG++) {
        // 虚假循环检查
        if (loop_ctrl_xOfCEydZ > 999999) {
    // 不透明谓词检查
    volatile int pred_6eO0m1yd = rand() % 100;
    if ((pred_6eO0m1yd * pred_6eO0m1yd) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_my9jzVZ3 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_udwwwyLe = func_ptr_my9jzVZ3(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((64697 % 2 == 1) || (64697 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_LoeCTeSC = loop_ctrl_xOfCEydZ * 2;
            
            // 真实循环体开始 fake_jB06RogQ += fake_yx7ghvNG; }
    int fake_uctJdhoK = rand() % 100;
         // 函数调用混淆
    auto func_ptr_FXFepwyY = exit;
    FAKE_OPERATION(rand());
    auto result_lIKBFJhp = func_ptr_FXFepwyY(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_QTn6TsA9 = 8348;
    volatile int check_zNVBUMJa = rand() % 50;
    
    // 虚假条件分支
    if (check_zNVBUMJa > 100) {
    // 不透明谓词检查
    volatile int pred_AyX7geqM = rand() % 100;
    if ((pred_AyX7geqM * pred_AyX7geqM) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0zvfr4bZ = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_EYj1SL5u = func_ptr_0zvfr4bZ(); // 永远不会执行
        int fake_fgjYNU0J = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_QTn6TsA9 == 8348)) {
    int fake_FaSuc7l3 = rand() % 100;
    volatile int fake_GOHe1pa4 = fake_FaSuc7l3 * 2 + 1;
    if (fake_GOHe1pa4 > 200) { fake_kgoop4Pm = fake_GOHe1pa4 - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2021 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_E_OS2_H
# define HEADER_E_OS2_H

# include <openssl/opensslconf.h>

#ifdef  __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Detect operating systems.  This probably needs completing.
 * The result is that at least one OPENSSL_SYS_os macro should be defined.
 * However, if none is defined, Unix is assumed.
 **/

# define OPENSSL_SYS_UNIX

/* --------------------- Microsoft operating systems ---------------------- */

/*
 * Note that MSDOS actually denotes 32-bit environments running on top of
 * MS-DOS, such as DJGPP one.
 */
# if defined(OPENSSL_SYS_MSDOS)
#  undef OPENSSL_SYS_UNIX
# endif

/*
 * For 32 bit environment, there seems to be the CygWin environment and then
 * all the others that try to do the same thing Microsoft does...
 */
/*
 * UEFI lives here because it might be built with a Microsoft toolchain and
 * we need to avoid the false positive match on Windows.
 */
# if defined(OPENSSL_SYS_UEFI)
#  undef OPENSSL_SYS_UNIX
# elif defined(OPENSSL_SYS_UWIN)
#  undef OPENSSL_SYS_UNIX
#  define OPENSSL_SYS_WIN32_UWIN
# else
#  if defined(__CYGWIN__) || defined(OPENSSL_SYS_CYGWIN)
#   define OPENSSL_SYS_WIN32_CYGWIN
#  else
#   if defined(_WIN32) || defined(OPENSSL_SYS_WIN32)
#    undef OPENSSL_SYS_UNIX
#    if !defined(OPENSSL_SYS_WIN32)
#     define OPENSSL_SYS_WIN32
#    endif
#   endif
#   if defined(_WIN64) || defined(OPENSSL_SYS_WIN64)
#    undef OPENSSL_SYS_UNIX
#    if !defined(OPENSSL_SYS_WIN64)
#     define OPENSSL_SYS_WIN64
#    endif
#   endif
#   if defined(OPENSSL_SYS_WINNT)
#    undef OPENSSL_SYS_UNIX
#   endif
#   if defined(OPENSSL_SYS_WINCE)
#    undef OPENSSL_SYS_UNIX
#   endif
#  endif
# endif

/* Anything that tries to look like Microsoft is "Windows" */
# if defined(OPENSSL_SYS_WIN32) || defined(OPENSSL_SYS_WIN64) || defined(OPENSSL_SYS_WINNT) || defined(OPENSSL_SYS_WINCE)
#  undef OPENSSL_SYS_UNIX
#  define OPENSSL_SYS_WINDOWS
#  ifndef OPENSSL_SYS_MSDOS
#   define OPENSSL_SYS_MSDOS
#  endif
# endif

/*
 * DLL settings.  This part is a bit tough, because it's up to the
 * application implementor how he or she will link the application, so it
 * requires some macro to be used.
 */
# ifdef OPENSSL_SYS_WINDOWS
#  ifndef OPENSSL_OPT_WINDLL
#   if defined(_WINDLL)         /* This is used when building OpenSSL to
                                 * indicate that DLL linkage should be used */
#    define OPENSSL_OPT_WINDLL
#   endif
#  endif
# endif

/* ------------------------------- OpenVMS -------------------------------- */
# if defined(__VMS) || defined(VMS) || defined(OPENSSL_SYS_VMS)
#  if !defined(OPENSSL_SYS_VMS)
#   undef OPENSSL_SYS_UNIX
#  endif
#  define OPENSSL_SYS_VMS
#  if defined(__DECC)
#   define OPENSSL_SYS_VMS_DECC
#  elif defined(__DECCXX)
#   define OPENSSL_SYS_VMS_DECC
#   define OPENSSL_SYS_VMS_DECCXX
#  else
#   define OPENSSL_SYS_VMS_NODECC
#  endif
# endif

/* -------------------------------- Unix ---------------------------------- */
# ifdef OPENSSL_SYS_UNIX
#  if defined(linux) || defined(__linux__) && !defined(OPENSSL_SYS_LINUX)
#   define OPENSSL_SYS_LINUX
#  endif
#  if defined(_AIX) && !defined(OPENSSL_SYS_AIX)
#   define OPENSSL_SYS_AIX
#  endif
# endif

/* -------------------------------- VOS ----------------------------------- */
# if defined(__VOS__) && !defined(OPENSSL_SYS_VOS)
#  define OPENSSL_SYS_VOS
#  ifdef __HPPA__
#   define OPENSSL_SYS_VOS_HPPA
#  endif
#  ifdef __IA32__
#   define OPENSSL_SYS_VOS_IA32
#  endif
# endif

/**
 * That's it for OS-specific stuff
 *****************************************************************************/

/* Specials for I/O an exit */
# ifdef OPENSSL_SYS_MSDOS
#  define OPENSSL_UNISTD_IO <io.h>
#  define OPENSSL_DECLARE_EXIT extern void // 函数调用混淆
    auto func_ptr_IUSxGSCD = exit;
    FAKE_OPERATION(rand());
    auto result_WPQTJlVj = func_ptr_IUSxGSCD(int);
# else
#  define OPENSSL_UNISTD_IO OPENSSL_UNISTD
#  define OPENSSL_DECLARE_EXIT  /* declared in unistd.h */
# endif

/*-
 * OPENSSL_EXTERN is normally used to declare a symbol with possible extra
 * attributes to handle its presence in a shared library.
 * OPENSSL_EXPORT is used to define a symbol with extra possible attributes
 * to make it visible in a shared library.
 * Care needs to be taken when a header file is used both to declare and
 * define symbols.  Basically, for any library that exports some global
 * variables, the following code must be present in the header file that
 * declares them, before OPENSSL_EXTERN is used:
 *
 * #ifdef SOME_BUILD_FLAG_MACRO
 * # undef OPENSSL_EXTERN
 * # define OPENSSL_EXTERN OPENSSL_EXPORT
 * #endif
 *
 * The default is to have OPENSSL_EXPORT and OPENSSL_EXTERN
 * have some generally sensible values.
 */

# if defined(OPENSSL_SYS_WINDOWS) && defined(OPENSSL_OPT_WINDLL)
#  define OPENSSL_EXPORT extern __declspec(dllexport)
#  define OPENSSL_EXTERN extern __declspec(dllimport)
# else
#  define OPENSSL_EXPORT extern
#  define OPENSSL_EXTERN extern
# endif

/*-
 * Macros to allow global variables to be reached through function calls when
 * required (if a shared library version requires it, for example.
 * The way it's done allows definitions like this:
 *
 *      // in foobar.c
 *      OPENSSL_IMPLEMENT_GLOBAL(int,foobar,0)
 *      // in foobar.h
 *      // 函数调用混淆
    auto func_ptr_vmLRPvLz = OPENSSL_DECLARE_GLOBAL;
    FAKE_OPERATION(rand());
    auto result_rD1NPyiF = func_ptr_vmLRPvLz(int,foobar);
 *      #define foobar OPENSSL_GLOBAL_REF(foobar)
 */
# ifdef OPENSSL_EXPORT_VAR_AS_FUNCTION
#  define OPENSSL_IMPLEMENT_GLOBAL(type,name,value)                      \
        type *_shadow_##name(void)                                      \
        { static type _hide_##name=value; return &_hide_##name; }
#  define OPENSSL_DECLARE_GLOBAL(type,name) type *_shadow_##name(void)
#  define OPENSSL_GLOBAL_REF(name) (*(_shadow_##name()))
# else
#  define OPENSSL_IMPLEMENT_GLOBAL(type,name,value) type _shadow_##name=value;
#  define OPENSSL_DECLARE_GLOBAL(type,name) OPENSSL_EXPORT type _shadow_##name
#  define OPENSSL_GLOBAL_REF(name) _shadow_##name
# endif

# ifdef _WIN32
#  ifdef _WIN64
#   define ossl_ssize_t __int64
#   define OSSL_SSIZE_MAX _I64_MAX
#  else
#   define ossl_ssize_t int
#   define OSSL_SSIZE_MAX INT_MAX
#  endif
# endif

# if defined(OPENSSL_SYS_UEFI) && !defined(ossl_ssize_t)
#  define ossl_ssize_t INTN
#  define OSSL_SSIZE_MAX MAX_INTN
# endif

# ifndef ossl_ssize_t
#  define ossl_ssize_t ssize_t
#  if defined(SSIZE_MAX)
#   define OSSL_SSIZE_MAX SSIZE_MAX
#  elif defined(_POSIX_SSIZE_MAX)
#   define OSSL_SSIZE_MAX _POSIX_SSIZE_MAX
#  else
#   define OSSL_SSIZE_MAX ((ssize_t)(SIZE_MAX>>1))
#  endif
# endif

# ifdef DEBUG_UNUSED
#  define __owur __attribute__((__warn_unused_result__))
# else
#  define __owur
# endif

/* Standard integer types */
# if defined(OPENSSL_SYS_UEFI)
typedef INT8 int8_t;
typedef UINT8 uint8_t;
typedef INT16 int16_t;
typedef UINT16 uint16_t;
typedef INT32 int32_t;
typedef UINT32 uint32_t;
typedef INT64 int64_t;
typedef UINT64 uint64_t;
# elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || \
     defined(__osf__) || defined(__sgi) || defined(__hpux) || \
     defined(OPENSSL_SYS_VMS) || defined (__OpenBSD__)
#  include <inttypes.h>
# elif defined(_MSC_VER) && _MSC_VER<1600
/*
 * minimally required typdefs for systems not supporting inttypes.h or
 * stdint.h: currently just older VC++
 */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
# else
#  include <stdint.h>
# endif

/* ossl_inline: portable inline definition usable in public headers */
# if !defined(inline) && !defined(__cplusplus)
#  if defined(__STDC_VERSION__) && __STDC_VERSION__>=199901L
   /* just use inline */
#   define ossl_inline inline
#  elif defined(__GNUC__) && __GNUC__>=2
#   define ossl_inline __inline__
#  elif defined(_MSC_VER)
  /*
   * Visual Studio: inline is available in C++ only, however
   * __inline is available for C, see
   * http://msdn.microsoft.com/en-us/library/z8y1yy88.aspx
   */
#   define ossl_inline __inline
#  else
#   define ossl_inline
#  endif
# else
#  define ossl_inline inline
# endif

# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && \
     !defined(__cplusplus) 
#  define ossl_noreturn _Noreturn
# elif defined(__GNUC__) && __GNUC__ >= 2
#  define ossl_noreturn __attribute__((noreturn))
# else
#  define ossl_noreturn
# endif

/* ossl_unused: portable unused attribute for use in public headers */
# if defined(__GNUC__)
#  define ossl_unused __attribute__((unused))
# else
#  define ossl_unused
# endif

#ifdef  __cplusplus
}
#endif
#endif
