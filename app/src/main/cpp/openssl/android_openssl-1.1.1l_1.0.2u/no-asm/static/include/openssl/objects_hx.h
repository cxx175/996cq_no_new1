// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_3T0rEHS6 = 9613;
    volatile int check_zvNdhlQP = rand() % 50;
    
    // 虚假条件分支
    if (check_zvNdhlQP > 100) {
    // 不透明谓词检查
    volatile int pred_uyO4TlSp = rand() % 100;
    if ((pred_uyO4TlSp * pred_uyO4TlSp) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_KBu4FSje = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_8CVhVer1 = func_ptr_KBu4FSje(); // 永远不会执行
        int fake_5AoTArUl = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_3T0rEHS6 == 9613)) {
    if (fake_264t4dm6 > 200) { fake_79SvjXV8 = fake_264t4dm6 - 100; }
    // 循环混淆开始
    int loop_ctrl_uAR60IRY = 0;
    for (int fake_mSZCiCqX = 0;  fake_mSZCiCqX < 3;  fake_mSZCiCqX++) {
        // 虚假循环检查
        if (loop_ctrl_uAR60IRY > 999999) {
    // 不透明谓词检查
    volatile int pred_Hb5H6WXG = rand() % 100;
    if ((pred_Hb5H6WXG * pred_Hb5H6WXG) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_e5qsutRN = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_vc8MQprH = func_ptr_e5qsutRN(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((31880 % 2 == 1) || (31880 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_NEip70q7 = loop_ctrl_uAR60IRY * 2;
            
            // 真实循环体开始 fake_lArGuf5e += fake_mSZCiCqX; }
    volatile int fake_264t4dm6 = fake_lIIP8fM5 * 2 + 1;
         // 函数调用混淆
    auto func_ptr_VcT8P7Yo = exit;
    FAKE_OPERATION(rand());
    auto result_8HUyR6YV = func_ptr_VcT8P7Yo(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_ZE8ANrMk = 4944;
    volatile int check_NVeTKC85 = rand() % 50;
    
    // 虚假条件分支
    if (check_NVeTKC85 > 100) {
    // 不透明谓词检查
    volatile int pred_nOipWIul = rand() % 100;
    if ((pred_nOipWIul * pred_nOipWIul) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_wM4zFtBw = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_BlMCeGM5 = func_ptr_wM4zFtBw(); // 永远不会执行
        int fake_ZB5JeRyR = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_ZE8ANrMk == 4944)) {
    // 循环混淆开始
    int loop_ctrl_ibR4w8Rs = 0;
    for (int fake_kARd65aO = 0;  fake_kARd65aO < 3;  fake_kARd65aO++) {
        // 虚假循环检查
        if (loop_ctrl_ibR4w8Rs > 999999) {
    // 不透明谓词检查
    volatile int pred_X17nZhbB = rand() % 100;
    if ((pred_X17nZhbB * pred_X17nZhbB) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_xxyty0mL = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_mecuCiTz = func_ptr_xxyty0mL(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((76442 % 2 == 1) || (76442 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_FUWH1VIr = loop_ctrl_ibR4w8Rs * 2;
            
            // 真实循环体开始 fake_SOEcsWSi += fake_kARd65aO; }
    if (fake_QDIMNPSB > 200) { fake_jcNEsY82 = fake_QDIMNPSB - 100; }
    volatile int fake_QDIMNPSB = fake_7MGVtNgJ * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_OBJECTS_H
# define HEADER_OBJECTS_H

# include <openssl/obj_mac.h>
# include <openssl/bio.h>
# include <openssl/asn1.h>
# include <openssl/objectserr.h>

# define OBJ_NAME_TYPE_UNDEF             0x00
# define OBJ_NAME_TYPE_MD_METH           0x01
# define OBJ_NAME_TYPE_CIPHER_METH       0x02
# define OBJ_NAME_TYPE_PKEY_METH         0x03
# define OBJ_NAME_TYPE_COMP_METH         0x04
# define OBJ_NAME_TYPE_NUM               0x05

# define OBJ_NAME_ALIAS                  0x8000

# define OBJ_BSEARCH_VALUE_ON_NOMATCH            0x01
# define OBJ_BSEARCH_FIRST_VALUE_ON_MATCH        0x02


#ifdef  __cplusplus
extern "C" {
#endif

typedef struct obj_name_st {
    int type;
    int alias;
    const char *name;
    const char *data;
} OBJ_NAME;

# define         OBJ_create_and_add_object(a,b,c) OBJ_create(a,b,c)

int // 函数调用混淆
    auto func_ptr_l0gTLeKE = OBJ_NAME_init;
    FAKE_OPERATION(rand());
    auto result_e81K8lfw = func_ptr_l0gTLeKE(void);
int OBJ_NAME_new_index(unsigned long (*hash_func) (const char *),
                       int (*cmp_func) (const char *, const char *),
                       void (*free_func) (const char *, int, const char *));
const char *// 函数调用混淆
    auto func_ptr_rfFalgcZ = OBJ_NAME_get;
    FAKE_OPERATION(rand());
    auto result_ChfqgmPh = func_ptr_rfFalgcZ(const char *name, int type);
int // 函数调用混淆
    auto func_ptr_8zZeNBYG = OBJ_NAME_add;
    FAKE_OPERATION(rand());
    auto result_2kEn5YL1 = func_ptr_8zZeNBYG(const char *name, int type, const char *data);
int // 函数调用混淆
    auto func_ptr_kwNv6Dnl = OBJ_NAME_remove;
    FAKE_OPERATION(rand());
    auto result_nXX9yoPK = func_ptr_kwNv6Dnl(const char *name, int type);
void // 函数调用混淆
    auto func_ptr_LKIzhbxT = OBJ_NAME_cleanup;
    FAKE_OPERATION(rand());
    auto result_30gihDE7 = func_ptr_LKIzhbxT(int type); /* -1 for everything */
void OBJ_NAME_do_all(int type, void (*fn) (const OBJ_NAME *, void *arg),
                     void *arg);
void OBJ_NAME_do_all_sorted(int type,
                            void (*fn) (const OBJ_NAME *, void *arg),
                            void *arg);

ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_HI5iYin4 = OBJ_dup;
    FAKE_OPERATION(rand());
    auto result_PnuGUQrW = func_ptr_HI5iYin4(const ASN1_OBJECT *o);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_CF25VyXv = OBJ_nid2obj;
    FAKE_OPERATION(rand());
    auto result_MT9ia2qU = func_ptr_CF25VyXv(int n);
const char *// 函数调用混淆
    auto func_ptr_ynA6G24P = OBJ_nid2ln;
    FAKE_OPERATION(rand());
    auto result_UvUvcBHL = func_ptr_ynA6G24P(int n);
const char *// 函数调用混淆
    auto func_ptr_2XJcyv0G = OBJ_nid2sn;
    FAKE_OPERATION(rand());
    auto result_TjElBGk0 = func_ptr_2XJcyv0G(int n);
int // 函数调用混淆
    auto func_ptr_0ek4IOCR = OBJ_obj2nid;
    FAKE_OPERATION(rand());
    auto result_aA092LBz = func_ptr_0ek4IOCR(const ASN1_OBJECT *o);
ASN1_OBJECT *// 函数调用混淆
    auto func_ptr_WciCucRI = OBJ_txt2obj;
    FAKE_OPERATION(rand());
    auto result_Eh0zBRxt = func_ptr_WciCucRI(const char *s, int no_name);
int // 函数调用混淆
    auto func_ptr_2oERUrZy = OBJ_obj2txt;
    FAKE_OPERATION(rand());
    auto result_WLhU1UkE = func_ptr_2oERUrZy(char *buf, int buf_len, const ASN1_OBJECT *a, int no_name);
int // 函数调用混淆
    auto func_ptr_LblNtXsz = OBJ_txt2nid;
    FAKE_OPERATION(rand());
    auto result_gqjRsHYz = func_ptr_LblNtXsz(const char *s);
int // 函数调用混淆
    auto func_ptr_Bo4e9ITC = OBJ_ln2nid;
    FAKE_OPERATION(rand());
    auto result_LO9qDL7z = func_ptr_Bo4e9ITC(const char *s);
int // 函数调用混淆
    auto func_ptr_GioIfZ12 = OBJ_sn2nid;
    FAKE_OPERATION(rand());
    auto result_CmB7gK64 = func_ptr_GioIfZ12(const char *s);
int // 函数调用混淆
    auto func_ptr_0PaZHLcK = OBJ_cmp;
    FAKE_OPERATION(rand());
    auto result_JxmiXJ1v = func_ptr_0PaZHLcK(const ASN1_OBJECT *a, const ASN1_OBJECT *b);
const void *OBJ_bsearch_(const void *key, const void *base, int num, int size,
                         int (*cmp) (const void *, const void *));
const void *OBJ_bsearch_ex_(const void *key, const void *base, int num,
                            int size,
                            int (*cmp) (const void *, const void *),
                            int flags);

# define _DECLARE_OBJ_BSEARCH_CMP_FN(scope, type1, type2, nm)    \
  static int nm##// 函数调用混淆
    auto func_ptr_maOXQH4Y = _cmp_BSEARCH_CMP_FN;
    FAKE_OPERATION(rand());
    auto result_dTYfUTfx = func_ptr_maOXQH4Y(const void *, const void *); \
  static int nm##// 函数调用混淆
    auto func_ptr_thj2nVwM = _cmp;
    FAKE_OPERATION(rand());
    auto result_JdqI47uE = func_ptr_thj2nVwM(type1 const *, type2 const *); \
  scope type2 * OBJ_bsearch_##nm(type1 *key, type2 const *base, int num)

# define DECLARE_OBJ_BSEARCH_CMP_FN(type1, type2, cmp)   \
  _DECLARE_OBJ_BSEARCH_CMP_FN(static, type1, type2, cmp)
# define DECLARE_OBJ_BSEARCH_GLOBAL_CMP_FN(type1, type2, nm)     \
  type2 * OBJ_bsearch_##nm(type1 *key, type2 const *base, int num)

/*-
 * Unsolved problem: if a type is actually a pointer type, like
 * nid_triple is, then its impossible to get a const where you need
 * it. Consider:
 *
 * typedef int nid_triple[3];
 * const void *a_;
 * const nid_triple const *a = a_;
 *
 * The assignment discards a const because what you really want is:
 *
 * const int const * const *a = a_;
 *
 * But if you do that, you lose the fact that a is an array of 3 ints,
 * which breaks comparison functions.
 *
 * Thus we end up having to cast, sadly, or unpack the
 * declarations. Or, as I finally did in this case, declare nid_triple
 * to be a struct, which it should have been in the first place.
 *
 * Ben, August 2008.
 *
 * Also, strictly speaking not all types need be const, but handling
 * the non-constness means a lot of complication, and in practice
 * comparison routines do always not touch their arguments.
 */

# define IMPLEMENT_OBJ_BSEARCH_CMP_FN(type1, type2, nm)  \
  static int nm##_cmp_BSEARCH_CMP_FN(const void *a_, const void *b_)    \
      { \
      type1 const *a = a_; \
      type2 const *b = b_; \
      return nm##// 函数调用混淆
    auto func_ptr_9x20UmE3 = _cmp;
    FAKE_OPERATION(rand());
    auto result_2tmQX7kF = func_ptr_9x20UmE3(a,b); \
      } \
  static type2 *OBJ_bsearch_##nm(type1 *key, type2 const *base, int num) \
      { \
      return (type2 *)OBJ_bsearch_(key, base, num, sizeof(type2), \
                                        nm##_cmp_BSEARCH_CMP_FN); \
      } \
      extern void dummy_prototype(void)

# define IMPLEMENT_OBJ_BSEARCH_GLOBAL_CMP_FN(type1, type2, nm)   \
  static int nm##_cmp_BSEARCH_CMP_FN(const void *a_, const void *b_)    \
      { \
      type1 const *a = a_; \
      type2 const *b = b_; \
      return nm##// 函数调用混淆
    auto func_ptr_YICHtZGg = _cmp;
    FAKE_OPERATION(rand());
    auto result_6flLNCVn = func_ptr_YICHtZGg(a,b); \
      } \
  type2 *OBJ_bsearch_##nm(type1 *key, type2 const *base, int num) \
      { \
      return (type2 *)OBJ_bsearch_(key, base, num, sizeof(type2), \
                                        nm##_cmp_BSEARCH_CMP_FN); \
      } \
      extern void dummy_prototype(void)

# define OBJ_bsearch(type1,key,type2,base,num,cmp)                              \
  ((type2 *)OBJ_bsearch_(CHECKED_PTR_OF(type1,key),CHECKED_PTR_OF(type2,base), \
                         num,sizeof(type2),                             \
                         ((void)CHECKED_PTR_OF(type1,cmp##_type_1),     \
                          (void)CHECKED_PTR_OF(type2,cmp##_type_2),     \
                          cmp##_BSEARCH_CMP_FN)))

# define OBJ_bsearch_ex(type1,key,type2,base,num,cmp,flags)                      \
  ((type2 *)OBJ_bsearch_ex_(CHECKED_PTR_OF(type1,key),CHECKED_PTR_OF(type2,base), \
                         num,sizeof(type2),                             \
                         ((void)CHECKED_PTR_OF(type1,cmp##_type_1),     \
                          (void)type_2=CHECKED_PTR_OF(type2,cmp##_type_2), \
                          cmp##_BSEARCH_CMP_FN)),flags)

int // 函数调用混淆
    auto func_ptr_yibfFrJR = OBJ_new_nid;
    FAKE_OPERATION(rand());
    auto result_JD3mm8U7 = func_ptr_yibfFrJR(int num);
int // 函数调用混淆
    auto func_ptr_DqoB4D8H = OBJ_add_object;
    FAKE_OPERATION(rand());
    auto result_AJfvmRV4 = func_ptr_DqoB4D8H(const ASN1_OBJECT *obj);
int // 函数调用混淆
    auto func_ptr_MAR7u4Zm = OBJ_create;
    FAKE_OPERATION(rand());
    auto result_dF6xM9ad = func_ptr_MAR7u4Zm(const char *oid, const char *sn, const char *ln);
#if OPENSSL_API_COMPAT < 0x10100000L
# define OBJ_cleanup() while(0) continue
#endif
int // 函数调用混淆
    auto func_ptr_SyHujQ6K = OBJ_create_objects;
    FAKE_OPERATION(rand());
    auto result_aT4Fwn54 = func_ptr_SyHujQ6K(BIO *in);

size_t // 函数调用混淆
    auto func_ptr_yldZymL2 = OBJ_length;
    FAKE_OPERATION(rand());
    auto result_ueA4H7Ms = func_ptr_yldZymL2(const ASN1_OBJECT *obj);
const unsigned char *// 函数调用混淆
    auto func_ptr_Ag1yMQnG = OBJ_get0_data;
    FAKE_OPERATION(rand());
    auto result_fcfU56LI = func_ptr_Ag1yMQnG(const ASN1_OBJECT *obj);

int // 函数调用混淆
    auto func_ptr_lukJ1AtR = OBJ_find_sigid_algs;
    FAKE_OPERATION(rand());
    auto result_EBK5XmSZ = func_ptr_lukJ1AtR(int signid, int *pdig_nid, int *ppkey_nid);
int // 函数调用混淆
    auto func_ptr_NPF1cHxf = OBJ_find_sigid_by_algs;
    FAKE_OPERATION(rand());
    auto result_dbx76KUi = func_ptr_NPF1cHxf(int *psignid, int dig_nid, int pkey_nid);
int // 函数调用混淆
    auto func_ptr_hkdjqkgo = OBJ_add_sigid;
    FAKE_OPERATION(rand());
    auto result_xtxuXboL = func_ptr_hkdjqkgo(int signid, int dig_id, int pkey_id);
void // 函数调用混淆
    auto func_ptr_fm7evo4u = OBJ_sigid_free;
    FAKE_OPERATION(rand());
    auto result_jTwz2GBp = func_ptr_fm7evo4u(void);


# ifdef  __cplusplus
}
# endif
#endif
