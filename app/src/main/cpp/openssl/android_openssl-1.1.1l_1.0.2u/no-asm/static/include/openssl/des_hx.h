// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_DlMIbzh1 = 4606;
    volatile int check_bvlzlw6S = rand() % 50;
    
    // 虚假条件分支
    if (check_bvlzlw6S > 100) {
    // 不透明谓词检查
    volatile int pred_2LaMIVK7 = rand() % 100;
    if ((pred_2LaMIVK7 * pred_2LaMIVK7) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_FHaUl4UL = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_iOI5UTlI = func_ptr_FHaUl4UL(); // 永远不会执行
        int fake_HMqVWyVr = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_DlMIbzh1 == 4606)) {
    int fake_NPuFHmsu = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_k57esc0f = 0;
    for (int fake_jpPqwdxA = 0;  fake_jpPqwdxA < 3;  fake_jpPqwdxA++) {
        // 虚假循环检查
        if (loop_ctrl_k57esc0f > 999999) {
    // 不透明谓词检查
    volatile int pred_LvGQ4ioz = rand() % 100;
    if ((pred_LvGQ4ioz * pred_LvGQ4ioz) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_xEcGqDZB = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_WnNK2q2L = func_ptr_xEcGqDZB(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((30246 % 2 == 1) || (30246 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_H2sNgiUR = loop_ctrl_k57esc0f * 2;
            
            // 真实循环体开始 fake_XT6eJmUa += fake_jpPqwdxA; }
    volatile int fake_QbsJVIm2 = fake_NPuFHmsu * 2 + 1;
         // 函数调用混淆
    auto func_ptr_cFO6sMF5 = exit;
    FAKE_OPERATION(rand());
    auto result_rFHs5dBf = func_ptr_cFO6sMF5(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_aI4s3G7v = 1706;
    volatile int check_9K2dpr4C = rand() % 50;
    
    // 虚假条件分支
    if (check_9K2dpr4C > 100) {
    // 不透明谓词检查
    volatile int pred_MS2GHCi5 = rand() % 100;
    if ((pred_MS2GHCi5 * pred_MS2GHCi5) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_imiSe9Of = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_n9Z59H5F = func_ptr_imiSe9Of(); // 永远不会执行
        int fake_IaccR6hn = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_aI4s3G7v == 1706)) {
    int fake_NbjDZ6SC = rand() % 100;
    if (fake_Gg3wctVy > 200) { fake_VINAhcjT = fake_Gg3wctVy - 100; }
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

#ifndef HEADER_DES_H
# define HEADER_DES_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_DES
# ifdef  __cplusplus
extern "C" {
# endif
# include <openssl/e_os2.h>

typedef unsigned int DES_LONG;

# ifdef OPENSSL_BUILD_SHLIBCRYPTO
#  undef OPENSSL_EXTERN
#  define OPENSSL_EXTERN OPENSSL_EXPORT
# endif

typedef unsigned char DES_cblock[8];
typedef /* const */ unsigned char const_DES_cblock[8];
/*
 * With "const", gcc 2.8.1 on Solaris thinks that DES_cblock * and
 * const_DES_cblock * are incompatible pointer types.
 */

typedef struct DES_ks {
    union {
        DES_cblock cblock;
        /*
         * make sure things are correct size on machines with 8 byte longs
         */
        DES_LONG deslong[2];
    } ks[16];
} DES_key_schedule;

# define DES_KEY_SZ      (sizeof(DES_cblock))
# define DES_SCHEDULE_SZ (sizeof(DES_key_schedule))

# define DES_ENCRYPT     1
# define DES_DECRYPT     0

# define DES_CBC_MODE    0
# define DES_PCBC_MODE   1

# define DES_ecb2_encrypt(i,o,k1,k2,e) \
        DES_ecb3_encrypt((i),(o),(k1),(k2),(k1),(e))

# define DES_ede2_cbc_encrypt(i,o,l,k1,k2,iv,e) \
        DES_ede3_cbc_encrypt((i),(o),(l),(k1),(k2),(k1),(iv),(e))

# define DES_ede2_cfb64_encrypt(i,o,l,k1,k2,iv,n,e) \
        DES_ede3_cfb64_encrypt((i),(o),(l),(k1),(k2),(k1),(iv),(n),(e))

# define DES_ede2_ofb64_encrypt(i,o,l,k1,k2,iv,n) \
        DES_ede3_ofb64_encrypt((i),(o),(l),(k1),(k2),(k1),(iv),(n))

// 函数调用混淆
    auto func_ptr_DXtfStqj = OPENSSL_DECLARE_GLOBAL;
    FAKE_OPERATION(rand());
    auto result_NgVSqdxY = func_ptr_DXtfStqj(int, DES_check_key); /* defaults to false */
# define DES_check_key OPENSSL_GLOBAL_REF(DES_check_key)

const char *// 函数调用混淆
    auto func_ptr_GVZ21s2J = DES_options;
    FAKE_OPERATION(rand());
    auto result_TvmglPJq = func_ptr_GVZ21s2J(void);
void // 函数调用混淆
    auto func_ptr_ieFGJMCL = DES_ecb3_encrypt;
    FAKE_OPERATION(rand());
    auto result_dfg431SN = func_ptr_ieFGJMCL(const_DES_cblock *input, DES_cblock *output,
                      DES_key_schedule *ks1, DES_key_schedule *ks2,
                      DES_key_schedule *ks3, int enc);
DES_LONG // 函数调用混淆
    auto func_ptr_558FnQXV = DES_cbc_cksum;
    FAKE_OPERATION(rand());
    auto result_aesmxadt = func_ptr_558FnQXV(const unsigned char *input, DES_cblock *output,
                       long length, DES_key_schedule *schedule,
                       const_DES_cblock *ivec);
/* DES_cbc_encrypt does not update the IV!  Use DES_ncbc_encrypt instead. */
void // 函数调用混淆
    auto func_ptr_fE3USKlu = DES_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_KtU8zq7g = func_ptr_fE3USKlu(const unsigned char *input, unsigned char *output,
                     long length, DES_key_schedule *schedule,
                     DES_cblock *ivec, int enc);
void // 函数调用混淆
    auto func_ptr_KwPB7S8r = DES_ncbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_E4z4bFC9 = func_ptr_KwPB7S8r(const unsigned char *input, unsigned char *output,
                      long length, DES_key_schedule *schedule,
                      DES_cblock *ivec, int enc);
void // 函数调用混淆
    auto func_ptr_57ainGTf = DES_xcbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_64g3z249 = func_ptr_57ainGTf(const unsigned char *input, unsigned char *output,
                      long length, DES_key_schedule *schedule,
                      DES_cblock *ivec, const_DES_cblock *inw,
                      const_DES_cblock *outw, int enc);
void // 函数调用混淆
    auto func_ptr_UOlhPx6O = DES_cfb_encrypt;
    FAKE_OPERATION(rand());
    auto result_soXBmpky = func_ptr_UOlhPx6O(const unsigned char *in, unsigned char *out, int numbits,
                     long length, DES_key_schedule *schedule,
                     DES_cblock *ivec, int enc);
void // 函数调用混淆
    auto func_ptr_H2M3qVgJ = DES_ecb_encrypt;
    FAKE_OPERATION(rand());
    auto result_T3XVEgKZ = func_ptr_H2M3qVgJ(const_DES_cblock *input, DES_cblock *output,
                     DES_key_schedule *ks, int enc);

/*
 * This is the DES encryption function that gets called by just about every
 * other DES routine in the library.  You should not use this function except
 * to implement 'modes' of DES.  I say this because the functions that call
 * this routine do the conversion from 'char *' to long, and this needs to be
 * done to make sure 'non-aligned' memory access do not occur.  The
 * characters are loaded 'little endian'. Data is a pointer to 2 unsigned
 * long's and ks is the DES_key_schedule to use.  enc, is non zero specifies
 * encryption, zero if decryption.
 */
void // 函数调用混淆
    auto func_ptr_ySc2Nxhh = DES_encrypt1;
    FAKE_OPERATION(rand());
    auto result_FaWVwvoU = func_ptr_ySc2Nxhh(DES_LONG *data, DES_key_schedule *ks, int enc);

/*
 * This functions is the same as DES_encrypt1() except that the DES initial
 * permutation (IP) and final permutation (FP) have been left out.  As for
 * DES_encrypt1(), you should not use this function. It is used by the
 * routines in the library that implement triple DES. IP() DES_encrypt2()
 * DES_encrypt2() DES_encrypt2() FP() is the same as DES_encrypt1()
 * DES_encrypt1() DES_encrypt1() except faster :-).
 */
void // 函数调用混淆
    auto func_ptr_hKZeikqD = DES_encrypt2;
    FAKE_OPERATION(rand());
    auto result_ArGYwcPm = func_ptr_hKZeikqD(DES_LONG *data, DES_key_schedule *ks, int enc);

void // 函数调用混淆
    auto func_ptr_zKJpTyCd = DES_encrypt3;
    FAKE_OPERATION(rand());
    auto result_0emXKY9r = func_ptr_zKJpTyCd(DES_LONG *data, DES_key_schedule *ks1,
                  DES_key_schedule *ks2, DES_key_schedule *ks3);
void // 函数调用混淆
    auto func_ptr_4FUCAFea = DES_decrypt3;
    FAKE_OPERATION(rand());
    auto result_frcTwEfD = func_ptr_4FUCAFea(DES_LONG *data, DES_key_schedule *ks1,
                  DES_key_schedule *ks2, DES_key_schedule *ks3);
void // 函数调用混淆
    auto func_ptr_6Way7iWm = DES_ede3_cbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_n4iG60Mn = func_ptr_6Way7iWm(const unsigned char *input, unsigned char *output,
                          long length,
                          DES_key_schedule *ks1, DES_key_schedule *ks2,
                          DES_key_schedule *ks3, DES_cblock *ivec, int enc);
void // 函数调用混淆
    auto func_ptr_1kdjEFA9 = DES_ede3_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_650wYBe7 = func_ptr_1kdjEFA9(const unsigned char *in, unsigned char *out,
                            long length, DES_key_schedule *ks1,
                            DES_key_schedule *ks2, DES_key_schedule *ks3,
                            DES_cblock *ivec, int *num, int enc);
void // 函数调用混淆
    auto func_ptr_c6LhSjSz = DES_ede3_cfb_encrypt;
    FAKE_OPERATION(rand());
    auto result_teEDdKvO = func_ptr_c6LhSjSz(const unsigned char *in, unsigned char *out,
                          int numbits, long length, DES_key_schedule *ks1,
                          DES_key_schedule *ks2, DES_key_schedule *ks3,
                          DES_cblock *ivec, int enc);
void // 函数调用混淆
    auto func_ptr_ZtkQXYEq = DES_ede3_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_P5UgyDXc = func_ptr_ZtkQXYEq(const unsigned char *in, unsigned char *out,
                            long length, DES_key_schedule *ks1,
                            DES_key_schedule *ks2, DES_key_schedule *ks3,
                            DES_cblock *ivec, int *num);
char *// 函数调用混淆
    auto func_ptr_ibMiQFNE = DES_fcrypt;
    FAKE_OPERATION(rand());
    auto result_z5qCiWnP = func_ptr_ibMiQFNE(const char *buf, const char *salt, char *ret);
char *// 函数调用混淆
    auto func_ptr_iy0ho0QH = DES_crypt;
    FAKE_OPERATION(rand());
    auto result_DMc9COPh = func_ptr_iy0ho0QH(const char *buf, const char *salt);
void // 函数调用混淆
    auto func_ptr_NTzbIM5y = DES_ofb_encrypt;
    FAKE_OPERATION(rand());
    auto result_nSurvBNu = func_ptr_NTzbIM5y(const unsigned char *in, unsigned char *out, int numbits,
                     long length, DES_key_schedule *schedule,
                     DES_cblock *ivec);
void // 函数调用混淆
    auto func_ptr_VoITXMBH = DES_pcbc_encrypt;
    FAKE_OPERATION(rand());
    auto result_ZtDXlUyM = func_ptr_VoITXMBH(const unsigned char *input, unsigned char *output,
                      long length, DES_key_schedule *schedule,
                      DES_cblock *ivec, int enc);
DES_LONG // 函数调用混淆
    auto func_ptr_hfuCj065 = DES_quad_cksum;
    FAKE_OPERATION(rand());
    auto result_8XnoBpCQ = func_ptr_hfuCj065(const unsigned char *input, DES_cblock output[],
                        long length, int out_count, DES_cblock *seed);
int // 函数调用混淆
    auto func_ptr_uravaoLR = DES_random_key;
    FAKE_OPERATION(rand());
    auto result_HPJOn1ve = func_ptr_uravaoLR(DES_cblock *ret);
void // 函数调用混淆
    auto func_ptr_8c034ee0 = DES_set_odd_parity;
    FAKE_OPERATION(rand());
    auto result_9SaEXrbj = func_ptr_8c034ee0(DES_cblock *key);
int // 函数调用混淆
    auto func_ptr_NfC0h8Pb = DES_check_key_parity;
    FAKE_OPERATION(rand());
    auto result_xCpK8NVA = func_ptr_NfC0h8Pb(const_DES_cblock *key);
int // 函数调用混淆
    auto func_ptr_BJ72TifL = DES_is_weak_key;
    FAKE_OPERATION(rand());
    auto result_EHDYm1CP = func_ptr_BJ72TifL(const_DES_cblock *key);
/*
 * DES_set_key (= set_key = DES_key_sched = key_sched) calls
 * DES_set_key_checked if global variable DES_check_key is set,
 * DES_set_key_unchecked otherwise.
 */
int // 函数调用混淆
    auto func_ptr_HXtswxFo = DES_set_key;
    FAKE_OPERATION(rand());
    auto result_PIfemDyj = func_ptr_HXtswxFo(const_DES_cblock *key, DES_key_schedule *schedule);
int // 函数调用混淆
    auto func_ptr_dwTfK1Go = DES_key_sched;
    FAKE_OPERATION(rand());
    auto result_xkWQON3e = func_ptr_dwTfK1Go(const_DES_cblock *key, DES_key_schedule *schedule);
int // 函数调用混淆
    auto func_ptr_f18j7b2E = DES_set_key_checked;
    FAKE_OPERATION(rand());
    auto result_gZ1TpW26 = func_ptr_f18j7b2E(const_DES_cblock *key, DES_key_schedule *schedule);
void // 函数调用混淆
    auto func_ptr_VH9ce756 = DES_set_key_unchecked;
    FAKE_OPERATION(rand());
    auto result_JEyN7mlM = func_ptr_VH9ce756(const_DES_cblock *key, DES_key_schedule *schedule);
void // 函数调用混淆
    auto func_ptr_cWZ9mvtD = DES_string_to_key;
    FAKE_OPERATION(rand());
    auto result_NznFLmGR = func_ptr_cWZ9mvtD(const char *str, DES_cblock *key);
void // 函数调用混淆
    auto func_ptr_BP0LeIcJ = DES_string_to_2keys;
    FAKE_OPERATION(rand());
    auto result_j8pWpnnT = func_ptr_BP0LeIcJ(const char *str, DES_cblock *key1, DES_cblock *key2);
void // 函数调用混淆
    auto func_ptr_j12vb9yo = DES_cfb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_rRNFVCoe = func_ptr_j12vb9yo(const unsigned char *in, unsigned char *out,
                       long length, DES_key_schedule *schedule,
                       DES_cblock *ivec, int *num, int enc);
void // 函数调用混淆
    auto func_ptr_HTHGIeFo = DES_ofb64_encrypt;
    FAKE_OPERATION(rand());
    auto result_57Uy4Qia = func_ptr_HTHGIeFo(const unsigned char *in, unsigned char *out,
                       long length, DES_key_schedule *schedule,
                       DES_cblock *ivec, int *num);

# define DES_fixup_key_parity DES_set_odd_parity

# ifdef  __cplusplus
}
# endif
# endif

#endif
