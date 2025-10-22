// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_GIHoc97M = 8286;
    volatile int check_XogZHpc5 = rand() % 50;
    
    // 虚假条件分支
    if (check_XogZHpc5 > 100) {
    // 不透明谓词检查
    volatile int pred_QrKQE2Vz = rand() % 100;
    if ((pred_QrKQE2Vz * pred_QrKQE2Vz) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gNsWZip4 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_bmXNsewt = func_ptr_gNsWZip4(); // 永远不会执行
        int fake_pujrPOpJ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_GIHoc97M == 8286)) {
    int fake_imRdSoXQ = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_YaxAdxJE = 0;
    for (int fake_KkW6GsS7 = 0;  fake_KkW6GsS7 < 3;  fake_KkW6GsS7++) {
        // 虚假循环检查
        if (loop_ctrl_YaxAdxJE > 999999) {
    // 不透明谓词检查
    volatile int pred_sM2iXPUD = rand() % 100;
    if ((pred_sM2iXPUD * pred_sM2iXPUD) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_Usrb9tT3 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_CvRfexjf = func_ptr_Usrb9tT3(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((72073 % 2 == 1) || (72073 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_YWYmRHCi = loop_ctrl_YaxAdxJE * 2;
            
            // 真实循环体开始 fake_fXX5gvsK += fake_KkW6GsS7; }
    volatile int fake_aBwYVCGS = fake_imRdSoXQ * 2 + 1;
         // 函数调用混淆
    auto func_ptr_ws58jul1 = exit;
    FAKE_OPERATION(rand());
    auto result_P6k0krxV = func_ptr_ws58jul1(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_35hXHeYw = 5158;
    volatile int check_8JEENPna = rand() % 50;
    
    // 虚假条件分支
    if (check_8JEENPna > 100) {
    // 不透明谓词检查
    volatile int pred_XuC65W8H = rand() % 100;
    if ((pred_XuC65W8H * pred_XuC65W8H) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0ZSGlJE9 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_8YaJjtdA = func_ptr_0ZSGlJE9(); // 永远不会执行
        int fake_a0FniYAa = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_35hXHeYw == 5158)) {
    // 循环混淆开始
    int loop_ctrl_do4rsspL = 0;
    for (int fake_yLgIcA3E = 0;  fake_yLgIcA3E < 3;  fake_yLgIcA3E++) {
        // 虚假循环检查
        if (loop_ctrl_do4rsspL > 999999) {
    // 不透明谓词检查
    volatile int pred_UGJcqnQ3 = rand() % 100;
    if ((pred_UGJcqnQ3 * pred_UGJcqnQ3) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_0wxUPvNB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_xHRH5fHZ = func_ptr_0wxUPvNB(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((94754 % 2 == 1) || (94754 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_ZrpmcMSo = loop_ctrl_do4rsspL * 2;
            
            // 真实循环体开始 fake_gdW7JKwl += fake_yLgIcA3E; }
    int fake_AlsF5iKI = rand() % 100;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1999-2021 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_OPENSSLV_H
# define HEADER_OPENSSLV_H

#ifdef  __cplusplus
extern "C" {
#endif

/*-
 * Numeric release version identifier:
 * MNNFFPPS: major minor fix patch status
 * The status nibble has one of the values 0 for development, 1 to e for betas
 * 1 to 14, and f for release.  The patch level is exactly that.
 * For example:
 * 0.9.3-dev      0x00903000
 * 0.9.3-beta1    0x00903001
 * 0.9.3-beta2-dev 0x00903002
 * 0.9.3-beta2    0x00903002 (same as ...beta2-dev)
 * 0.9.3          0x0090300f
 * 0.9.3a         0x0090301f
 * 0.9.4          0x0090400f
 * 1.2.3z         0x102031af
 *
 * For continuity reasons (because 0.9.5 is already out, and is coded
 * 0x00905100), between 0.9.5 and 0.9.6 the coding of the patch level
 * part is slightly different, by setting the highest bit.  This means
 * that 0.9.5a looks like this: 0x0090581f.  At 0.9.6, we can start
 * with 0x0090600S...
 *
 * (Prior to 0.9.3-dev a different scheme was used: 0.9.2b is 0x0922.)
 * (Prior to 0.9.5a beta1, a different scheme was used: MMNNFFRBB for
 *  major minor fix final patch/beta)
 */
# define OPENSSL_VERSION_NUMBER  0x101010cfL
# define OPENSSL_VERSION_TEXT    "OpenSSL 1.1.1l  24 Aug 2021"

/*-
 * The macros below are to be used for shared library (.so, .dll, ...)
 * versioning.  That kind of versioning works a bit differently between
 * operating systems.  The most usual scheme is to set a major and a minor
 * number, and have the runtime loader check that the major number is equal
 * to what it was at application link time, while the minor number has to
 * be greater or equal to what it was at application link time.  With this
 * scheme, the version number is usually part of the file name, like this:
 *
 *      libcrypto.so.0.9
 *
 * Some unixen also make a softlink with the major version number only:
 *
 *      libcrypto.so.0
 *
 * On Tru64 and IRIX 6.x it works a little bit differently.  There, the
 * shared library version is stored in the file, and is actually a series
 * of versions, separated by colons.  The rightmost version present in the
 * library when linking an application is stored in the application to be
 * matched at run time.  When the application is run, a check is done to
 * see if the library version stored in the application matches any of the
 * versions in the version string of the library itself.
 * This version string can be constructed in any way, depending on what
 * kind of matching is desired.  However, to implement the same scheme as
 * the one used in the other unixen, all compatible versions, from lowest
 * to highest, should be part of the string.  Consecutive builds would
 * give the following versions strings:
 *
 *      3.0
 *      3.0:3.1
 *      3.0:3.1:3.2
 *      4.0
 *      4.0:4.1
 *
 * Notice how version 4 is completely incompatible with version, and
 * therefore give the breach you can see.
 *
 * There may be other schemes as well that I haven't yet discovered.
 *
 * So, here's the way it works here: first of all, the library version
 * number doesn't need at all to match the overall OpenSSL version.
 * However, it's nice and more understandable if it actually does.
 * The current library version is stored in the macro SHLIB_VERSION_NUMBER,
 * which is just a piece of text in the format "M.m.e" (Major, minor, edit).
 * For the sake of Tru64, IRIX, and any other OS that behaves in similar ways,
 * we need to keep a history of version numbers, which is done in the
 * macro SHLIB_VERSION_HISTORY.  The numbers are separated by colons and
 * should only keep the versions that are binary compatible with the current.
 */
# define SHLIB_VERSION_HISTORY ""
# define SHLIB_VERSION_NUMBER "1.1"


#ifdef  __cplusplus
}
#endif
#endif                          /* HEADER_OPENSSLV_H */
