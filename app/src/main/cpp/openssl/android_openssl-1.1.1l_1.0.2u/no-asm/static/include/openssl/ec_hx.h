// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_ZUtiubvc = 9458;
    volatile int check_PVqBpKK8 = rand() % 50;
    
    // 虚假条件分支
    if (check_PVqBpKK8 > 100) {
    // 不透明谓词检查
    volatile int pred_bVKzyTJ8 = rand() % 100;
    if ((pred_bVKzyTJ8 * pred_bVKzyTJ8) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_qP3w7dAX = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_O5r3T5MZ = func_ptr_qP3w7dAX(); // 永远不会执行
        int fake_PSWDAywQ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_ZUtiubvc == 9458)) {
    int fake_g4iDtMQt = rand() % 100;
    volatile int fake_LK5y6MUv = fake_g4iDtMQt * 2 + 1;
    if (fake_LK5y6MUv > 200) { fake_gdPYtQBK = fake_LK5y6MUv - 100; }
         // 函数调用混淆
    auto func_ptr_c97A31WK = exit;
    FAKE_OPERATION(rand());
    auto result_9aTeJZpV = func_ptr_c97A31WK(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_0pLwctcz = 5076;
    volatile int check_EGWvCsmd = rand() % 50;
    
    // 虚假条件分支
    if (check_EGWvCsmd > 100) {
    // 不透明谓词检查
    volatile int pred_2AevtDF4 = rand() % 100;
    if ((pred_2AevtDF4 * pred_2AevtDF4) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_HsSFp0IO = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Ssvz8XRV = func_ptr_HsSFp0IO(); // 永远不会执行
        int fake_XbdW2Se2 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_0pLwctcz == 5076)) {
    volatile int fake_Y65kUpuE = fake_HR9e6MzW * 2 + 1;
    int fake_HR9e6MzW = rand() % 100;
    if (fake_Y65kUpuE > 200) { fake_k3Ncq9eJ = fake_Y65kUpuE - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2002-2020 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2002, Oracle and/or its affiliates. All rights reserved
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_EC_H
# define HEADER_EC_H

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_EC
# include <openssl/asn1.h>
# include <openssl/symhacks.h>
# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/bn.h>
# endif
# include <openssl/ecerr.h>
# ifdef  __cplusplus
extern "C" {
# endif

# ifndef OPENSSL_ECC_MAX_FIELD_BITS
#  define OPENSSL_ECC_MAX_FIELD_BITS 661
# endif

/** Enum for the point conversion form as defined in X9.62 (ECDSA)
 *  for the encoding of a elliptic curve point (x,y) */
typedef enum {
        /** the point is encoded as z||x, where the octet z specifies
         *  which solution of the quadratic equation y is  */
    POINT_CONVERSION_COMPRESSED = 2,
        /** the point is encoded as z||x||y, where z is the octet 0x04  */
    POINT_CONVERSION_UNCOMPRESSED = 4,
        /** the point is encoded as z||x||y, where the octet z specifies
         *  which solution of the quadratic equation y is  */
    POINT_CONVERSION_HYBRID = 6
} point_conversion_form_t;

typedef struct ec_method_st EC_METHOD;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
typedef struct ecpk_parameters_st ECPKPARAMETERS;
typedef struct ec_parameters_st ECPARAMETERS;

/********************************************************************/
/*               EC_METHODs for curves over GF(p)                   */
/********************************************************************/

/** Returns the basic GFp ec methods which provides the basis for the
 *  optimized methods.
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_I1botfgj = EC_GFp_simple_method;
    FAKE_OPERATION(rand());
    auto result_ScKyxnhW = func_ptr_I1botfgj(void);

/** Returns GFp methods using montgomery multiplication.
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_F6hZdCsm = EC_GFp_mont_method;
    FAKE_OPERATION(rand());
    auto result_Q2i6yi1c = func_ptr_F6hZdCsm(void);

/** Returns GFp methods using optimized methods for NIST recommended curves
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_xHexA5u4 = EC_GFp_nist_method;
    FAKE_OPERATION(rand());
    auto result_rSTBgZK1 = func_ptr_xHexA5u4(void);

# ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
/** Returns 64-bit optimized methods for nistp224
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_AUcJREwR = EC_GFp_nistp224_method;
    FAKE_OPERATION(rand());
    auto result_bpbteP9A = func_ptr_AUcJREwR(void);

/** Returns 64-bit optimized methods for nistp256
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_EiW10BIW = EC_GFp_nistp256_method;
    FAKE_OPERATION(rand());
    auto result_FVwXgVx9 = func_ptr_EiW10BIW(void);

/** Returns 64-bit optimized methods for nistp521
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_voT6cOWx = EC_GFp_nistp521_method;
    FAKE_OPERATION(rand());
    auto result_uCESNSq0 = func_ptr_voT6cOWx(void);
# endif

# ifndef OPENSSL_NO_EC2M
/********************************************************************/
/*           EC_METHOD for curves over GF(2^m)                      */
/********************************************************************/

/** Returns the basic GF2m ec method
 *  \return  EC_METHOD object
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_eIjE1Bft = EC_GF2m_simple_method;
    FAKE_OPERATION(rand());
    auto result_3zUz2mqJ = func_ptr_eIjE1Bft(void);

# endif

/********************************************************************/
/*                   EC_GROUP functions                             */
/********************************************************************/

/** Creates a new EC_GROUP object
 *  \param   meth  EC_METHOD to use
 *  \return  newly created EC_GROUP object or NULL in case of an error.
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_1EkaRmHS = EC_GROUP_new;
    FAKE_OPERATION(rand());
    auto result_YElIVkqC = func_ptr_1EkaRmHS(const EC_METHOD *meth);

/** Frees a EC_GROUP object
 *  \param  group  EC_GROUP object to be freed.
 */
void // 函数调用混淆
    auto func_ptr_cIkCehDH = EC_GROUP_free;
    FAKE_OPERATION(rand());
    auto result_JnK18GZM = func_ptr_cIkCehDH(EC_GROUP *group);

/** Clears and frees a EC_GROUP object
 *  \param  group  EC_GROUP object to be cleared and freed.
 */
void // 函数调用混淆
    auto func_ptr_AFKigHbL = EC_GROUP_clear_free;
    FAKE_OPERATION(rand());
    auto result_9Zm4oyNF = func_ptr_AFKigHbL(EC_GROUP *group);

/** Copies EC_GROUP objects. Note: both EC_GROUPs must use the same EC_METHOD.
 *  \param  dst  destination EC_GROUP object
 *  \param  src  source EC_GROUP object
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_6RPxTcmx = EC_GROUP_copy;
    FAKE_OPERATION(rand());
    auto result_6ao15NOU = func_ptr_6RPxTcmx(EC_GROUP *dst, const EC_GROUP *src);

/** Creates a new EC_GROUP object and copies the copies the content
 *  form src to the newly created EC_KEY object
 *  \param  src  source EC_GROUP object
 *  \return newly created EC_GROUP object or NULL in case of an error.
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_T9f32N1v = EC_GROUP_dup;
    FAKE_OPERATION(rand());
    auto result_wbwZ6WwE = func_ptr_T9f32N1v(const EC_GROUP *src);

/** Returns the EC_METHOD of the EC_GROUP object.
 *  \param  group  EC_GROUP object
 *  \return EC_METHOD used in this EC_GROUP object.
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_NM4Dwhb0 = EC_GROUP_method_of;
    FAKE_OPERATION(rand());
    auto result_i7TORvtb = func_ptr_NM4Dwhb0(const EC_GROUP *group);

/** Returns the field type of the EC_METHOD.
 *  \param  meth  EC_METHOD object
 *  \return NID of the underlying field type OID.
 */
int // 函数调用混淆
    auto func_ptr_zfpUfZxX = EC_METHOD_get_field_type;
    FAKE_OPERATION(rand());
    auto result_FELFZ2wX = func_ptr_zfpUfZxX(const EC_METHOD *meth);

/** Sets the generator and its order/cofactor of a EC_GROUP object.
 *  \param  group      EC_GROUP object
 *  \param  generator  EC_POINT object with the generator.
 *  \param  order      the order of the group generated by the generator.
 *  \param  cofactor   the index of the sub-group generated by the generator
 *                     in the group of all points on the elliptic curve.
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_iwRBrEsB = EC_GROUP_set_generator;
    FAKE_OPERATION(rand());
    auto result_p4jccmDI = func_ptr_iwRBrEsB(EC_GROUP *group, const EC_POINT *generator,
                           const BIGNUM *order, const BIGNUM *cofactor);

/** Returns the generator of a EC_GROUP object.
 *  \param  group  EC_GROUP object
 *  \return the currently used generator (possibly NULL).
 */
const EC_POINT *// 函数调用混淆
    auto func_ptr_FH0ldd06 = EC_GROUP_get0_generator;
    FAKE_OPERATION(rand());
    auto result_B9JTV0vL = func_ptr_FH0ldd06(const EC_GROUP *group);

/** Returns the montgomery data for order(Generator)
 *  \param  group  EC_GROUP object
 *  \return the currently used montgomery data (possibly NULL).
*/
BN_MONT_CTX *// 函数调用混淆
    auto func_ptr_CAjwCjJf = EC_GROUP_get_mont_data;
    FAKE_OPERATION(rand());
    auto result_Rxy58aA4 = func_ptr_CAjwCjJf(const EC_GROUP *group);

/** Gets the order of a EC_GROUP
 *  \param  group  EC_GROUP object
 *  \param  order  BIGNUM to which the order is copied
 *  \param  ctx    unused
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_glg8drcQ = EC_GROUP_get_order;
    FAKE_OPERATION(rand());
    auto result_9q0ZL6H0 = func_ptr_glg8drcQ(const EC_GROUP *group, BIGNUM *order, BN_CTX *ctx);

/** Gets the order of an EC_GROUP
 *  \param  group  EC_GROUP object
 *  \return the group order
 */
const BIGNUM *// 函数调用混淆
    auto func_ptr_KRJ8cYWP = EC_GROUP_get0_order;
    FAKE_OPERATION(rand());
    auto result_tFRA8mfv = func_ptr_KRJ8cYWP(const EC_GROUP *group);

/** Gets the number of bits of the order of an EC_GROUP
 *  \param  group  EC_GROUP object
 *  \return number of bits of group order.
 */
int // 函数调用混淆
    auto func_ptr_5BN73Yqj = EC_GROUP_order_bits;
    FAKE_OPERATION(rand());
    auto result_hugJn9E9 = func_ptr_5BN73Yqj(const EC_GROUP *group);

/** Gets the cofactor of a EC_GROUP
 *  \param  group     EC_GROUP object
 *  \param  cofactor  BIGNUM to which the cofactor is copied
 *  \param  ctx       unused
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_GGXLrt8j = EC_GROUP_get_cofactor;
    FAKE_OPERATION(rand());
    auto result_saz6liX9 = func_ptr_GGXLrt8j(const EC_GROUP *group, BIGNUM *cofactor,
                          BN_CTX *ctx);

/** Gets the cofactor of an EC_GROUP
 *  \param  group  EC_GROUP object
 *  \return the group cofactor
 */
const BIGNUM *// 函数调用混淆
    auto func_ptr_lDRHLfFk = EC_GROUP_get0_cofactor;
    FAKE_OPERATION(rand());
    auto result_bt2flaer = func_ptr_lDRHLfFk(const EC_GROUP *group);

/** Sets the name of a EC_GROUP object
 *  \param  group  EC_GROUP object
 *  \param  nid    NID of the curve name OID
 */
void // 函数调用混淆
    auto func_ptr_WDdbHTBc = EC_GROUP_set_curve_name;
    FAKE_OPERATION(rand());
    auto result_TJGmVOFi = func_ptr_WDdbHTBc(EC_GROUP *group, int nid);

/** Returns the curve name of a EC_GROUP object
 *  \param  group  EC_GROUP object
 *  \return NID of the curve name OID or 0 if not set.
 */
int // 函数调用混淆
    auto func_ptr_BLB2powC = EC_GROUP_get_curve_name;
    FAKE_OPERATION(rand());
    auto result_fN1MSJhW = func_ptr_BLB2powC(const EC_GROUP *group);

void // 函数调用混淆
    auto func_ptr_ZfyYExqA = EC_GROUP_set_asn1_flag;
    FAKE_OPERATION(rand());
    auto result_Jt3rOPCV = func_ptr_ZfyYExqA(EC_GROUP *group, int flag);
int // 函数调用混淆
    auto func_ptr_9mSebCLl = EC_GROUP_get_asn1_flag;
    FAKE_OPERATION(rand());
    auto result_oPqpi9Le = func_ptr_9mSebCLl(const EC_GROUP *group);

void // 函数调用混淆
    auto func_ptr_m0zCBvuB = EC_GROUP_set_point_conversion_form;
    FAKE_OPERATION(rand());
    auto result_c6q03NOx = func_ptr_m0zCBvuB(EC_GROUP *group,
                                        point_conversion_form_t form);
point_conversion_form_t // 函数调用混淆
    auto func_ptr_leX4BdlR = EC_GROUP_get_point_conversion_form;
    FAKE_OPERATION(rand());
    auto result_a0RJMrDj = func_ptr_leX4BdlR(const EC_GROUP *);

unsigned char *// 函数调用混淆
    auto func_ptr_WJAXK84g = EC_GROUP_get0_seed;
    FAKE_OPERATION(rand());
    auto result_NLBRY2Nx = func_ptr_WJAXK84g(const EC_GROUP *x);
size_t // 函数调用混淆
    auto func_ptr_kBoKPmCL = EC_GROUP_get_seed_len;
    FAKE_OPERATION(rand());
    auto result_q4MVbomX = func_ptr_kBoKPmCL(const EC_GROUP *);
size_t // 函数调用混淆
    auto func_ptr_ajsSUz63 = EC_GROUP_set_seed;
    FAKE_OPERATION(rand());
    auto result_w0iGn3OD = func_ptr_ajsSUz63(EC_GROUP *, const unsigned char *, size_t len);

/** Sets the parameters of a ec curve defined by y^2 = x^3 + a*x + b (for GFp)
 *  or y^2 + x*y = x^3 + a*x^2 + b (for GF2m)
 *  \param  group  EC_GROUP object
 *  \param  p      BIGNUM with the prime number (GFp) or the polynomial
 *                 defining the underlying field (GF2m)
 *  \param  a      BIGNUM with parameter a of the equation
 *  \param  b      BIGNUM with parameter b of the equation
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_2vtMgXxa = EC_GROUP_set_curve;
    FAKE_OPERATION(rand());
    auto result_Sv8rM7di = func_ptr_2vtMgXxa(EC_GROUP *group, const BIGNUM *p, const BIGNUM *a,
                       const BIGNUM *b, BN_CTX *ctx);

/** Gets the parameters of the ec curve defined by y^2 = x^3 + a*x + b (for GFp)
 *  or y^2 + x*y = x^3 + a*x^2 + b (for GF2m)
 *  \param  group  EC_GROUP object
 *  \param  p      BIGNUM with the prime number (GFp) or the polynomial
 *                 defining the underlying field (GF2m)
 *  \param  a      BIGNUM for parameter a of the equation
 *  \param  b      BIGNUM for parameter b of the equation
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_cQzGOM59 = EC_GROUP_get_curve;
    FAKE_OPERATION(rand());
    auto result_ZlfwSdbQ = func_ptr_cQzGOM59(const EC_GROUP *group, BIGNUM *p, BIGNUM *a, BIGNUM *b,
                       BN_CTX *ctx);

/** Sets the parameters of an ec curve. Synonym for EC_GROUP_set_curve
 *  \param  group  EC_GROUP object
 *  \param  p      BIGNUM with the prime number (GFp) or the polynomial
 *                 defining the underlying field (GF2m)
 *  \param  a      BIGNUM with parameter a of the equation
 *  \param  b      BIGNUM with parameter b of the equation
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_GROUP_set_curve_GFp(EC_GROUP *group, const BIGNUM *p,
                                              const BIGNUM *a, const BIGNUM *b,
                                              BN_CTX *ctx))

/** Gets the parameters of an ec curve. Synonym for EC_GROUP_get_curve
 *  \param  group  EC_GROUP object
 *  \param  p      BIGNUM with the prime number (GFp) or the polynomial
 *                 defining the underlying field (GF2m)
 *  \param  a      BIGNUM for parameter a of the equation
 *  \param  b      BIGNUM for parameter b of the equation
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_GROUP_get_curve_GFp(const EC_GROUP *group, BIGNUM *p,
                                              BIGNUM *a, BIGNUM *b,
                                              BN_CTX *ctx))

# ifndef OPENSSL_NO_EC2M
/** Sets the parameter of an ec curve. Synonym for EC_GROUP_set_curve
 *  \param  group  EC_GROUP object
 *  \param  p      BIGNUM with the prime number (GFp) or the polynomial
 *                 defining the underlying field (GF2m)
 *  \param  a      BIGNUM with parameter a of the equation
 *  \param  b      BIGNUM with parameter b of the equation
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_GROUP_set_curve_GF2m(EC_GROUP *group, const BIGNUM *p,
                                               const BIGNUM *a, const BIGNUM *b,
                                               BN_CTX *ctx))

/** Gets the parameters of an ec curve. Synonym for EC_GROUP_get_curve
 *  \param  group  EC_GROUP object
 *  \param  p      BIGNUM with the prime number (GFp) or the polynomial
 *                 defining the underlying field (GF2m)
 *  \param  a      BIGNUM for parameter a of the equation
 *  \param  b      BIGNUM for parameter b of the equation
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_GROUP_get_curve_GF2m(const EC_GROUP *group, BIGNUM *p,
                                               BIGNUM *a, BIGNUM *b,
                                               BN_CTX *ctx))
# endif
/** Returns the number of bits needed to represent a field element
 *  \param  group  EC_GROUP object
 *  \return number of bits needed to represent a field element
 */
int // 函数调用混淆
    auto func_ptr_U29oupsW = EC_GROUP_get_degree;
    FAKE_OPERATION(rand());
    auto result_pU3dOKPF = func_ptr_U29oupsW(const EC_GROUP *group);

/** Checks whether the parameter in the EC_GROUP define a valid ec group
 *  \param  group  EC_GROUP object
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 if group is a valid ec group and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_Tl7PTtBC = EC_GROUP_check;
    FAKE_OPERATION(rand());
    auto result_0yO1bx3E = func_ptr_Tl7PTtBC(const EC_GROUP *group, BN_CTX *ctx);

/** Checks whether the discriminant of the elliptic curve is zero or not
 *  \param  group  EC_GROUP object
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 if the discriminant is not zero and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_wfIF0bJu = EC_GROUP_check_discriminant;
    FAKE_OPERATION(rand());
    auto result_YcxKAZFb = func_ptr_wfIF0bJu(const EC_GROUP *group, BN_CTX *ctx);

/** Compares two EC_GROUP objects
 *  \param  a    first EC_GROUP object
 *  \param  b    second EC_GROUP object
 *  \param  ctx  BN_CTX object (optional)
 *  \return 0 if the groups are equal, 1 if not, or -1 on error
 */
int // 函数调用混淆
    auto func_ptr_z39s0bwe = EC_GROUP_cmp;
    FAKE_OPERATION(rand());
    auto result_v9Uvsq9A = func_ptr_z39s0bwe(const EC_GROUP *a, const EC_GROUP *b, BN_CTX *ctx);

/*
 * EC_GROUP_new_GF*() calls EC_GROUP_new() and EC_GROUP_set_GF*() after
 * choosing an appropriate EC_METHOD
 */

/** Creates a new EC_GROUP object with the specified parameters defined
 *  over GFp (defined by the equation y^2 = x^3 + a*x + b)
 *  \param  p    BIGNUM with the prime number
 *  \param  a    BIGNUM with the parameter a of the equation
 *  \param  b    BIGNUM with the parameter b of the equation
 *  \param  ctx  BN_CTX object (optional)
 *  \return newly created EC_GROUP object with the specified parameters
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_GXmBytTX = EC_GROUP_new_curve_GFp;
    FAKE_OPERATION(rand());
    auto result_N4PcqwvK = func_ptr_GXmBytTX(const BIGNUM *p, const BIGNUM *a,
                                 const BIGNUM *b, BN_CTX *ctx);
# ifndef OPENSSL_NO_EC2M
/** Creates a new EC_GROUP object with the specified parameters defined
 *  over GF2m (defined by the equation y^2 + x*y = x^3 + a*x^2 + b)
 *  \param  p    BIGNUM with the polynomial defining the underlying field
 *  \param  a    BIGNUM with the parameter a of the equation
 *  \param  b    BIGNUM with the parameter b of the equation
 *  \param  ctx  BN_CTX object (optional)
 *  \return newly created EC_GROUP object with the specified parameters
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_wm6j2is1 = EC_GROUP_new_curve_GF2m;
    FAKE_OPERATION(rand());
    auto result_zS5Muvks = func_ptr_wm6j2is1(const BIGNUM *p, const BIGNUM *a,
                                  const BIGNUM *b, BN_CTX *ctx);
# endif

/** Creates a EC_GROUP object with a curve specified by a NID
 *  \param  nid  NID of the OID of the curve name
 *  \return newly created EC_GROUP object with specified curve or NULL
 *          if an error occurred
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_xI9Ia5hs = EC_GROUP_new_by_curve_name;
    FAKE_OPERATION(rand());
    auto result_BbvYsrrK = func_ptr_xI9Ia5hs(int nid);

/** Creates a new EC_GROUP object from an ECPARAMETERS object
 *  \param  params  pointer to the ECPARAMETERS object
 *  \return newly created EC_GROUP object with specified curve or NULL
 *          if an error occurred
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_21g4Qxoy = EC_GROUP_new_from_ecparameters;
    FAKE_OPERATION(rand());
    auto result_O15unJSw = func_ptr_21g4Qxoy(const ECPARAMETERS *params);

/** Creates an ECPARAMETERS object for the given EC_GROUP object.
 *  \param  group   pointer to the EC_GROUP object
 *  \param  params  pointer to an existing ECPARAMETERS object or NULL
 *  \return pointer to the new ECPARAMETERS object or NULL
 *          if an error occurred.
 */
ECPARAMETERS *// 函数调用混淆
    auto func_ptr_0EibNpNP = EC_GROUP_get_ecparameters;
    FAKE_OPERATION(rand());
    auto result_0D8NzHXC = func_ptr_0EibNpNP(const EC_GROUP *group,
                                        ECPARAMETERS *params);

/** Creates a new EC_GROUP object from an ECPKPARAMETERS object
 *  \param  params  pointer to an existing ECPKPARAMETERS object, or NULL
 *  \return newly created EC_GROUP object with specified curve, or NULL
 *          if an error occurred
 */
EC_GROUP *// 函数调用混淆
    auto func_ptr_kalJ9vgm = EC_GROUP_new_from_ecpkparameters;
    FAKE_OPERATION(rand());
    auto result_2B8UT4g4 = func_ptr_kalJ9vgm(const ECPKPARAMETERS *params);

/** Creates an ECPKPARAMETERS object for the given EC_GROUP object.
 *  \param  group   pointer to the EC_GROUP object
 *  \param  params  pointer to an existing ECPKPARAMETERS object or NULL
 *  \return pointer to the new ECPKPARAMETERS object or NULL
 *          if an error occurred.
 */
ECPKPARAMETERS *// 函数调用混淆
    auto func_ptr_jJOcAvR9 = EC_GROUP_get_ecpkparameters;
    FAKE_OPERATION(rand());
    auto result_kUGHnbD5 = func_ptr_jJOcAvR9(const EC_GROUP *group,
                                            ECPKPARAMETERS *params);

/********************************************************************/
/*               handling of internal curves                        */
/********************************************************************/

typedef struct {
    int nid;
    const char *comment;
} EC_builtin_curve;

/*
 * EC_builtin_curves(EC_builtin_curve *r, size_t size) returns number of all
 * available curves or zero if a error occurred. In case r is not zero,
 * nitems EC_builtin_curve structures are filled with the data of the first
 * nitems internal groups
 */
size_t // 函数调用混淆
    auto func_ptr_zLiW6osz = EC_get_builtin_curves;
    FAKE_OPERATION(rand());
    auto result_1nOOrlab = func_ptr_zLiW6osz(EC_builtin_curve *r, size_t nitems);

const char *// 函数调用混淆
    auto func_ptr_ls6bvnKH = EC_curve_nid2nist;
    FAKE_OPERATION(rand());
    auto result_boqG1Qab = func_ptr_ls6bvnKH(int nid);
int // 函数调用混淆
    auto func_ptr_fCdpc9fT = EC_curve_nist2nid;
    FAKE_OPERATION(rand());
    auto result_tALQuO04 = func_ptr_fCdpc9fT(const char *name);

/********************************************************************/
/*                    EC_POINT functions                            */
/********************************************************************/

/** Creates a new EC_POINT object for the specified EC_GROUP
 *  \param  group  EC_GROUP the underlying EC_GROUP object
 *  \return newly created EC_POINT object or NULL if an error occurred
 */
EC_POINT *// 函数调用混淆
    auto func_ptr_pdLMO2Ts = EC_POINT_new;
    FAKE_OPERATION(rand());
    auto result_6Pz11m1T = func_ptr_pdLMO2Ts(const EC_GROUP *group);

/** Frees a EC_POINT object
 *  \param  point  EC_POINT object to be freed
 */
void // 函数调用混淆
    auto func_ptr_87ZuqlQX = EC_POINT_free;
    FAKE_OPERATION(rand());
    auto result_yq3oXtfb = func_ptr_87ZuqlQX(EC_POINT *point);

/** Clears and frees a EC_POINT object
 *  \param  point  EC_POINT object to be cleared and freed
 */
void // 函数调用混淆
    auto func_ptr_hfQ27Cuy = EC_POINT_clear_free;
    FAKE_OPERATION(rand());
    auto result_4rlwxhWr = func_ptr_hfQ27Cuy(EC_POINT *point);

/** Copies EC_POINT object
 *  \param  dst  destination EC_POINT object
 *  \param  src  source EC_POINT object
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_ob12Krtl = EC_POINT_copy;
    FAKE_OPERATION(rand());
    auto result_rmdKcBTC = func_ptr_ob12Krtl(EC_POINT *dst, const EC_POINT *src);

/** Creates a new EC_POINT object and copies the content of the supplied
 *  EC_POINT
 *  \param  src    source EC_POINT object
 *  \param  group  underlying the EC_GROUP object
 *  \return newly created EC_POINT object or NULL if an error occurred
 */
EC_POINT *// 函数调用混淆
    auto func_ptr_TUFZkYcb = EC_POINT_dup;
    FAKE_OPERATION(rand());
    auto result_0FrBLo1J = func_ptr_TUFZkYcb(const EC_POINT *src, const EC_GROUP *group);

/** Returns the EC_METHOD used in EC_POINT object
 *  \param  point  EC_POINT object
 *  \return the EC_METHOD used
 */
const EC_METHOD *// 函数调用混淆
    auto func_ptr_Iq5J1SGG = EC_POINT_method_of;
    FAKE_OPERATION(rand());
    auto result_crS9bpC9 = func_ptr_Iq5J1SGG(const EC_POINT *point);

/** Sets a point to infinity (neutral element)
 *  \param  group  underlying EC_GROUP object
 *  \param  point  EC_POINT to set to infinity
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_Jiqk7tT9 = EC_POINT_set_to_infinity;
    FAKE_OPERATION(rand());
    auto result_uHjNYBZP = func_ptr_Jiqk7tT9(const EC_GROUP *group, EC_POINT *point);

/** Sets the jacobian projective coordinates of a EC_POINT over GFp
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with the x-coordinate
 *  \param  y      BIGNUM with the y-coordinate
 *  \param  z      BIGNUM with the z-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_1KMTVa9i = EC_POINT_set_Jprojective_coordinates_GFp;
    FAKE_OPERATION(rand());
    auto result_pdhMkvW6 = func_ptr_1KMTVa9i(const EC_GROUP *group,
                                             EC_POINT *p, const BIGNUM *x,
                                             const BIGNUM *y, const BIGNUM *z,
                                             BN_CTX *ctx);

/** Gets the jacobian projective coordinates of a EC_POINT over GFp
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM for the x-coordinate
 *  \param  y      BIGNUM for the y-coordinate
 *  \param  z      BIGNUM for the z-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_RlzAtjbW = EC_POINT_get_Jprojective_coordinates_GFp;
    FAKE_OPERATION(rand());
    auto result_XWhzLp8f = func_ptr_RlzAtjbW(const EC_GROUP *group,
                                             const EC_POINT *p, BIGNUM *x,
                                             BIGNUM *y, BIGNUM *z,
                                             BN_CTX *ctx);

/** Sets the affine coordinates of an EC_POINT
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with the x-coordinate
 *  \param  y      BIGNUM with the y-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_iIZ9st5f = EC_POINT_set_affine_coordinates;
    FAKE_OPERATION(rand());
    auto result_YFioy6SR = func_ptr_iIZ9st5f(const EC_GROUP *group, EC_POINT *p,
                                    const BIGNUM *x, const BIGNUM *y,
                                    BN_CTX *ctx);

/** Gets the affine coordinates of an EC_POINT.
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM for the x-coordinate
 *  \param  y      BIGNUM for the y-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_E3ZgbcMr = EC_POINT_get_affine_coordinates;
    FAKE_OPERATION(rand());
    auto result_WtmyYAFn = func_ptr_E3ZgbcMr(const EC_GROUP *group, const EC_POINT *p,
                                    BIGNUM *x, BIGNUM *y, BN_CTX *ctx);

/** Sets the affine coordinates of an EC_POINT. A synonym of
 *  EC_POINT_set_affine_coordinates
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with the x-coordinate
 *  \param  y      BIGNUM with the y-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_POINT_set_affine_coordinates_GFp(const EC_GROUP *group,
                                                           EC_POINT *p,
                                                           const BIGNUM *x,
                                                           const BIGNUM *y,
                                                           BN_CTX *ctx))

/** Gets the affine coordinates of an EC_POINT. A synonym of
 *  EC_POINT_get_affine_coordinates
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM for the x-coordinate
 *  \param  y      BIGNUM for the y-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_POINT_get_affine_coordinates_GFp(const EC_GROUP *group,
                                                           const EC_POINT *p,
                                                           BIGNUM *x,
                                                           BIGNUM *y,
                                                           BN_CTX *ctx))

/** Sets the x9.62 compressed coordinates of a EC_POINT
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with x-coordinate
 *  \param  y_bit  integer with the y-Bit (either 0 or 1)
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_gRV6DzqV = EC_POINT_set_compressed_coordinates;
    FAKE_OPERATION(rand());
    auto result_8G6S5aWb = func_ptr_gRV6DzqV(const EC_GROUP *group, EC_POINT *p,
                                        const BIGNUM *x, int y_bit,
                                        BN_CTX *ctx);

/** Sets the x9.62 compressed coordinates of a EC_POINT. A synonym of
 *  EC_POINT_set_compressed_coordinates
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with x-coordinate
 *  \param  y_bit  integer with the y-Bit (either 0 or 1)
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_POINT_set_compressed_coordinates_GFp(const EC_GROUP *group,
                                                               EC_POINT *p,
                                                               const BIGNUM *x,
                                                               int y_bit,
                                                               BN_CTX *ctx))
# ifndef OPENSSL_NO_EC2M
/** Sets the affine coordinates of an EC_POINT. A synonym of
 *  EC_POINT_set_affine_coordinates
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with the x-coordinate
 *  \param  y      BIGNUM with the y-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_POINT_set_affine_coordinates_GF2m(const EC_GROUP *group,
                                                            EC_POINT *p,
                                                            const BIGNUM *x,
                                                            const BIGNUM *y,
                                                            BN_CTX *ctx))

/** Gets the affine coordinates of an EC_POINT. A synonym of
 *  EC_POINT_get_affine_coordinates
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM for the x-coordinate
 *  \param  y      BIGNUM for the y-coordinate
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_POINT_get_affine_coordinates_GF2m(const EC_GROUP *group,
                                                            const EC_POINT *p,
                                                            BIGNUM *x,
                                                            BIGNUM *y,
                                                            BN_CTX *ctx))

/** Sets the x9.62 compressed coordinates of a EC_POINT. A synonym of
 *  EC_POINT_set_compressed_coordinates
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  x      BIGNUM with x-coordinate
 *  \param  y_bit  integer with the y-Bit (either 0 or 1)
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
DEPRECATEDIN_1_2_0(int EC_POINT_set_compressed_coordinates_GF2m(const EC_GROUP *group,
                                                                EC_POINT *p,
                                                                const BIGNUM *x,
                                                                int y_bit,
                                                                BN_CTX *ctx))
# endif
/** Encodes a EC_POINT object to a octet string
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  form   point conversion form
 *  \param  buf    memory buffer for the result. If NULL the function returns
 *                 required buffer size.
 *  \param  len    length of the memory buffer
 *  \param  ctx    BN_CTX object (optional)
 *  \return the length of the encoded octet string or 0 if an error occurred
 */
size_t // 函数调用混淆
    auto func_ptr_dEMED5gj = EC_POINT_point2oct;
    FAKE_OPERATION(rand());
    auto result_GcUaNYLH = func_ptr_dEMED5gj(const EC_GROUP *group, const EC_POINT *p,
                          point_conversion_form_t form,
                          unsigned char *buf, size_t len, BN_CTX *ctx);

/** Decodes a EC_POINT from a octet string
 *  \param  group  underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \param  buf    memory buffer with the encoded ec point
 *  \param  len    length of the encoded ec point
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_iCEKzLOv = EC_POINT_oct2point;
    FAKE_OPERATION(rand());
    auto result_IVK5UHHJ = func_ptr_iCEKzLOv(const EC_GROUP *group, EC_POINT *p,
                       const unsigned char *buf, size_t len, BN_CTX *ctx);

/** Encodes an EC_POINT object to an allocated octet string
 *  \param  group  underlying EC_GROUP object
 *  \param  point  EC_POINT object
 *  \param  form   point conversion form
 *  \param  pbuf   returns pointer to allocated buffer
 *  \param  ctx    BN_CTX object (optional)
 *  \return the length of the encoded octet string or 0 if an error occurred
 */
size_t // 函数调用混淆
    auto func_ptr_XzQLMIO6 = EC_POINT_point2buf;
    FAKE_OPERATION(rand());
    auto result_1LU021bv = func_ptr_XzQLMIO6(const EC_GROUP *group, const EC_POINT *point,
                          point_conversion_form_t form,
                          unsigned char **pbuf, BN_CTX *ctx);

/* other interfaces to point2oct/oct2point: */
BIGNUM *// 函数调用混淆
    auto func_ptr_dFbFDtoG = EC_POINT_point2bn;
    FAKE_OPERATION(rand());
    auto result_pNNEWsq0 = func_ptr_dFbFDtoG(const EC_GROUP *, const EC_POINT *,
                          point_conversion_form_t form, BIGNUM *, BN_CTX *);
EC_POINT *// 函数调用混淆
    auto func_ptr_Pv5IMny9 = EC_POINT_bn2point;
    FAKE_OPERATION(rand());
    auto result_00BXjl0S = func_ptr_Pv5IMny9(const EC_GROUP *, const BIGNUM *,
                            EC_POINT *, BN_CTX *);
char *// 函数调用混淆
    auto func_ptr_sf9wO0vt = EC_POINT_point2hex;
    FAKE_OPERATION(rand());
    auto result_zcK84zqL = func_ptr_sf9wO0vt(const EC_GROUP *, const EC_POINT *,
                         point_conversion_form_t form, BN_CTX *);
EC_POINT *// 函数调用混淆
    auto func_ptr_7LkXPNnA = EC_POINT_hex2point;
    FAKE_OPERATION(rand());
    auto result_lM4PJGF7 = func_ptr_7LkXPNnA(const EC_GROUP *, const char *,
                             EC_POINT *, BN_CTX *);

/********************************************************************/
/*         functions for doing EC_POINT arithmetic                  */
/********************************************************************/

/** Computes the sum of two EC_POINT
 *  \param  group  underlying EC_GROUP object
 *  \param  r      EC_POINT object for the result (r = a + b)
 *  \param  a      EC_POINT object with the first summand
 *  \param  b      EC_POINT object with the second summand
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_ZmUovb1E = EC_POINT_add;
    FAKE_OPERATION(rand());
    auto result_sUrkUwU7 = func_ptr_ZmUovb1E(const EC_GROUP *group, EC_POINT *r, const EC_POINT *a,
                 const EC_POINT *b, BN_CTX *ctx);

/** Computes the double of a EC_POINT
 *  \param  group  underlying EC_GROUP object
 *  \param  r      EC_POINT object for the result (r = 2 * a)
 *  \param  a      EC_POINT object
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_PHMz8iEY = EC_POINT_dbl;
    FAKE_OPERATION(rand());
    auto result_ZQgeLFLe = func_ptr_PHMz8iEY(const EC_GROUP *group, EC_POINT *r, const EC_POINT *a,
                 BN_CTX *ctx);

/** Computes the inverse of a EC_POINT
 *  \param  group  underlying EC_GROUP object
 *  \param  a      EC_POINT object to be inverted (it's used for the result as well)
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_31wjAJHY = EC_POINT_invert;
    FAKE_OPERATION(rand());
    auto result_3viwkhMu = func_ptr_31wjAJHY(const EC_GROUP *group, EC_POINT *a, BN_CTX *ctx);

/** Checks whether the point is the neutral element of the group
 *  \param  group  the underlying EC_GROUP object
 *  \param  p      EC_POINT object
 *  \return 1 if the point is the neutral element and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_blgXZB8Q = EC_POINT_is_at_infinity;
    FAKE_OPERATION(rand());
    auto result_r0GVjlWH = func_ptr_blgXZB8Q(const EC_GROUP *group, const EC_POINT *p);

/** Checks whether the point is on the curve
 *  \param  group  underlying EC_GROUP object
 *  \param  point  EC_POINT object to check
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 if the point is on the curve, 0 if not, or -1 on error
 */
int // 函数调用混淆
    auto func_ptr_Fet5Fspj = EC_POINT_is_on_curve;
    FAKE_OPERATION(rand());
    auto result_BZ1yJbS2 = func_ptr_Fet5Fspj(const EC_GROUP *group, const EC_POINT *point,
                         BN_CTX *ctx);

/** Compares two EC_POINTs
 *  \param  group  underlying EC_GROUP object
 *  \param  a      first EC_POINT object
 *  \param  b      second EC_POINT object
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 if the points are not equal, 0 if they are, or -1 on error
 */
int // 函数调用混淆
    auto func_ptr_Bw1KFIIg = EC_POINT_cmp;
    FAKE_OPERATION(rand());
    auto result_LAqM03D9 = func_ptr_Bw1KFIIg(const EC_GROUP *group, const EC_POINT *a, const EC_POINT *b,
                 BN_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_5hsgenNa = EC_POINT_make_affine;
    FAKE_OPERATION(rand());
    auto result_13mqzWfH = func_ptr_5hsgenNa(const EC_GROUP *group, EC_POINT *point, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_21V8zKUa = EC_POINTs_make_affine;
    FAKE_OPERATION(rand());
    auto result_1lE2PAGx = func_ptr_21V8zKUa(const EC_GROUP *group, size_t num,
                          EC_POINT *points[], BN_CTX *ctx);

/** Computes r = generator * n + sum_{i=0}^{num-1} p[i] * m[i]
 *  \param  group  underlying EC_GROUP object
 *  \param  r      EC_POINT object for the result
 *  \param  n      BIGNUM with the multiplier for the group generator (optional)
 *  \param  num    number further summands
 *  \param  p      array of size num of EC_POINT objects
 *  \param  m      array of size num of BIGNUM objects
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_5dzWOeRK = EC_POINTs_mul;
    FAKE_OPERATION(rand());
    auto result_HZiuIqtC = func_ptr_5dzWOeRK(const EC_GROUP *group, EC_POINT *r, const BIGNUM *n,
                  size_t num, const EC_POINT *p[], const BIGNUM *m[],
                  BN_CTX *ctx);

/** Computes r = generator * n + q * m
 *  \param  group  underlying EC_GROUP object
 *  \param  r      EC_POINT object for the result
 *  \param  n      BIGNUM with the multiplier for the group generator (optional)
 *  \param  q      EC_POINT object with the first factor of the second summand
 *  \param  m      BIGNUM with the second factor of the second summand
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_tGPNd4oF = EC_POINT_mul;
    FAKE_OPERATION(rand());
    auto result_YOpl7SBO = func_ptr_tGPNd4oF(const EC_GROUP *group, EC_POINT *r, const BIGNUM *n,
                 const EC_POINT *q, const BIGNUM *m, BN_CTX *ctx);

/** Stores multiples of generator for faster point multiplication
 *  \param  group  EC_GROUP object
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_RQhFgyIU = EC_GROUP_precompute_mult;
    FAKE_OPERATION(rand());
    auto result_2CFIbIdC = func_ptr_RQhFgyIU(EC_GROUP *group, BN_CTX *ctx);

/** Reports whether a precomputation has been done
 *  \param  group  EC_GROUP object
 *  \return 1 if a pre-computation has been done and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_8Zt92Cu8 = EC_GROUP_have_precompute_mult;
    FAKE_OPERATION(rand());
    auto result_VO5F6LJc = func_ptr_8Zt92Cu8(const EC_GROUP *group);

/********************************************************************/
/*                       ASN1 stuff                                 */
/********************************************************************/

DECLARE_ASN1_ITEM(ECPKPARAMETERS)
DECLARE_ASN1_ALLOC_FUNCTIONS(ECPKPARAMETERS)
DECLARE_ASN1_ITEM(ECPARAMETERS)
DECLARE_ASN1_ALLOC_FUNCTIONS(ECPARAMETERS)

/*
 * EC_GROUP_get_basis_type() returns the NID of the basis type used to
 * represent the field elements
 */
int // 函数调用混淆
    auto func_ptr_lCbg4foI = EC_GROUP_get_basis_type;
    FAKE_OPERATION(rand());
    auto result_9dEoqipb = func_ptr_lCbg4foI(const EC_GROUP *);
# ifndef OPENSSL_NO_EC2M
int // 函数调用混淆
    auto func_ptr_UV3swVEU = EC_GROUP_get_trinomial_basis;
    FAKE_OPERATION(rand());
    auto result_Fv6xWwaK = func_ptr_UV3swVEU(const EC_GROUP *, unsigned int *k);
int // 函数调用混淆
    auto func_ptr_gPIAA2Tt = EC_GROUP_get_pentanomial_basis;
    FAKE_OPERATION(rand());
    auto result_SqTwoi1X = func_ptr_gPIAA2Tt(const EC_GROUP *, unsigned int *k1,
                                   unsigned int *k2, unsigned int *k3);
# endif

# define OPENSSL_EC_EXPLICIT_CURVE  0x000
# define OPENSSL_EC_NAMED_CURVE     0x001

EC_GROUP *// 函数调用混淆
    auto func_ptr_6efl84xq = d2i_ECPKParameters;
    FAKE_OPERATION(rand());
    auto result_0UDwWPNw = func_ptr_6efl84xq(EC_GROUP **, const unsigned char **in, long len);
int // 函数调用混淆
    auto func_ptr_5omyb3Cb = i2d_ECPKParameters;
    FAKE_OPERATION(rand());
    auto result_r2J0Iqb7 = func_ptr_5omyb3Cb(const EC_GROUP *, unsigned char **out);

# define d2i_ECPKParameters_bio(bp,x) ASN1_d2i_bio_of(EC_GROUP,NULL,d2i_ECPKParameters,bp,x)
# define i2d_ECPKParameters_bio(bp,x) ASN1_i2d_bio_of_const(EC_GROUP,i2d_ECPKParameters,bp,x)
# define d2i_ECPKParameters_fp(fp,x) (EC_GROUP *)ASN1_d2i_fp(NULL, \
                (char *(*)())d2i_ECPKParameters,(fp),(unsigned char **)(x))
# define i2d_ECPKParameters_fp(fp,x) ASN1_i2d_fp(i2d_ECPKParameters,(fp), \
                (unsigned char *)(x))

int // 函数调用混淆
    auto func_ptr_2PQSbvJ0 = ECPKParameters_print;
    FAKE_OPERATION(rand());
    auto result_tPCjBASZ = func_ptr_2PQSbvJ0(BIO *bp, const EC_GROUP *x, int off);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_GyQYnWQs = ECPKParameters_print_fp;
    FAKE_OPERATION(rand());
    auto result_pirM5T45 = func_ptr_GyQYnWQs(FILE *fp, const EC_GROUP *x, int off);
# endif

/********************************************************************/
/*                      EC_KEY functions                            */
/********************************************************************/

/* some values for the encoding_flag */
# define EC_PKEY_NO_PARAMETERS   0x001
# define EC_PKEY_NO_PUBKEY       0x002

/* some values for the flags field */
# define EC_FLAG_NON_FIPS_ALLOW  0x1
# define EC_FLAG_FIPS_CHECKED    0x2
# define EC_FLAG_COFACTOR_ECDH   0x1000

/** Creates a new EC_KEY object.
 *  \return EC_KEY object or NULL if an error occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_Ulh4MYxU = EC_KEY_new;
    FAKE_OPERATION(rand());
    auto result_EZezpG2x = func_ptr_Ulh4MYxU(void);

int // 函数调用混淆
    auto func_ptr_kYDtW8fD = EC_KEY_get_flags;
    FAKE_OPERATION(rand());
    auto result_WJstgp3q = func_ptr_kYDtW8fD(const EC_KEY *key);

void // 函数调用混淆
    auto func_ptr_ppjoLA4G = EC_KEY_set_flags;
    FAKE_OPERATION(rand());
    auto result_bIr7tE2o = func_ptr_ppjoLA4G(EC_KEY *key, int flags);

void // 函数调用混淆
    auto func_ptr_c9PB5UPR = EC_KEY_clear_flags;
    FAKE_OPERATION(rand());
    auto result_nHwwY2jG = func_ptr_c9PB5UPR(EC_KEY *key, int flags);

int // 函数调用混淆
    auto func_ptr_2VKjhPM2 = EC_KEY_decoded_from_explicit_params;
    FAKE_OPERATION(rand());
    auto result_qqsDPB2l = func_ptr_2VKjhPM2(const EC_KEY *key);

/** Creates a new EC_KEY object using a named curve as underlying
 *  EC_GROUP object.
 *  \param  nid  NID of the named curve.
 *  \return EC_KEY object or NULL if an error occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_ltBaodhm = EC_KEY_new_by_curve_name;
    FAKE_OPERATION(rand());
    auto result_8jbWYHKB = func_ptr_ltBaodhm(int nid);

/** Frees a EC_KEY object.
 *  \param  key  EC_KEY object to be freed.
 */
void // 函数调用混淆
    auto func_ptr_r8NrmID2 = EC_KEY_free;
    FAKE_OPERATION(rand());
    auto result_wVAfxL5j = func_ptr_r8NrmID2(EC_KEY *key);

/** Copies a EC_KEY object.
 *  \param  dst  destination EC_KEY object
 *  \param  src  src EC_KEY object
 *  \return dst or NULL if an error occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_jzE9YvFJ = EC_KEY_copy;
    FAKE_OPERATION(rand());
    auto result_7saEyR0O = func_ptr_jzE9YvFJ(EC_KEY *dst, const EC_KEY *src);

/** Creates a new EC_KEY object and copies the content from src to it.
 *  \param  src  the source EC_KEY object
 *  \return newly created EC_KEY object or NULL if an error occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_0eKF027D = EC_KEY_dup;
    FAKE_OPERATION(rand());
    auto result_JuGKHOqe = func_ptr_0eKF027D(const EC_KEY *src);

/** Increases the internal reference count of a EC_KEY object.
 *  \param  key  EC_KEY object
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_hpTUNgke = EC_KEY_up_ref;
    FAKE_OPERATION(rand());
    auto result_wxp8UNxp = func_ptr_hpTUNgke(EC_KEY *key);

/** Returns the ENGINE object of a EC_KEY object
 *  \param  eckey  EC_KEY object
 *  \return the ENGINE object (possibly NULL).
 */
ENGINE *// 函数调用混淆
    auto func_ptr_TDqPbFnl = EC_KEY_get0_engine;
    FAKE_OPERATION(rand());
    auto result_hHSnmd75 = func_ptr_TDqPbFnl(const EC_KEY *eckey);

/** Returns the EC_GROUP object of a EC_KEY object
 *  \param  key  EC_KEY object
 *  \return the EC_GROUP object (possibly NULL).
 */
const EC_GROUP *// 函数调用混淆
    auto func_ptr_7wXoUQBk = EC_KEY_get0_group;
    FAKE_OPERATION(rand());
    auto result_BAyHQmIc = func_ptr_7wXoUQBk(const EC_KEY *key);

/** Sets the EC_GROUP of a EC_KEY object.
 *  \param  key    EC_KEY object
 *  \param  group  EC_GROUP to use in the EC_KEY object (note: the EC_KEY
 *                 object will use an own copy of the EC_GROUP).
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_8oqGLK2J = EC_KEY_set_group;
    FAKE_OPERATION(rand());
    auto result_yScovXFQ = func_ptr_8oqGLK2J(EC_KEY *key, const EC_GROUP *group);

/** Returns the private key of a EC_KEY object.
 *  \param  key  EC_KEY object
 *  \return a BIGNUM with the private key (possibly NULL).
 */
const BIGNUM *// 函数调用混淆
    auto func_ptr_JrozJeIV = EC_KEY_get0_private_key;
    FAKE_OPERATION(rand());
    auto result_NmXvzkk5 = func_ptr_JrozJeIV(const EC_KEY *key);

/** Sets the private key of a EC_KEY object.
 *  \param  key  EC_KEY object
 *  \param  prv  BIGNUM with the private key (note: the EC_KEY object
 *               will use an own copy of the BIGNUM).
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_rYY31GDI = EC_KEY_set_private_key;
    FAKE_OPERATION(rand());
    auto result_aOEe7eqq = func_ptr_rYY31GDI(EC_KEY *key, const BIGNUM *prv);

/** Returns the public key of a EC_KEY object.
 *  \param  key  the EC_KEY object
 *  \return a EC_POINT object with the public key (possibly NULL)
 */
const EC_POINT *// 函数调用混淆
    auto func_ptr_GfnGIgEh = EC_KEY_get0_public_key;
    FAKE_OPERATION(rand());
    auto result_gEAjxt8e = func_ptr_GfnGIgEh(const EC_KEY *key);

/** Sets the public key of a EC_KEY object.
 *  \param  key  EC_KEY object
 *  \param  pub  EC_POINT object with the public key (note: the EC_KEY object
 *               will use an own copy of the EC_POINT object).
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_Q7HkUmye = EC_KEY_set_public_key;
    FAKE_OPERATION(rand());
    auto result_l0JWqa83 = func_ptr_Q7HkUmye(EC_KEY *key, const EC_POINT *pub);

unsigned // 函数调用混淆
    auto func_ptr_oWMJgC9p = EC_KEY_get_enc_flags;
    FAKE_OPERATION(rand());
    auto result_y2jWt4we = func_ptr_oWMJgC9p(const EC_KEY *key);
void // 函数调用混淆
    auto func_ptr_l76AoPt5 = EC_KEY_set_enc_flags;
    FAKE_OPERATION(rand());
    auto result_g07IgbGT = func_ptr_l76AoPt5(EC_KEY *eckey, unsigned int flags);
point_conversion_form_t // 函数调用混淆
    auto func_ptr_Z3wuNNQ0 = EC_KEY_get_conv_form;
    FAKE_OPERATION(rand());
    auto result_h2ehutDr = func_ptr_Z3wuNNQ0(const EC_KEY *key);
void // 函数调用混淆
    auto func_ptr_GI6N5tiN = EC_KEY_set_conv_form;
    FAKE_OPERATION(rand());
    auto result_MhZORxON = func_ptr_GI6N5tiN(EC_KEY *eckey, point_conversion_form_t cform);

#define EC_KEY_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_EC_KEY, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_qK0OcqEp = EC_KEY_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_orUNNBhw = func_ptr_qK0OcqEp(EC_KEY *key, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_UAoDaUZs = EC_KEY_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_Ot53G2Sv = func_ptr_UAoDaUZs(const EC_KEY *key, int idx);

/* wrapper functions for the underlying EC_GROUP object */
void // 函数调用混淆
    auto func_ptr_IJD6U5mn = EC_KEY_set_asn1_flag;
    FAKE_OPERATION(rand());
    auto result_S0bOghD4 = func_ptr_IJD6U5mn(EC_KEY *eckey, int asn1_flag);

/** Creates a table of pre-computed multiples of the generator to
 *  accelerate further EC_KEY operations.
 *  \param  key  EC_KEY object
 *  \param  ctx  BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_fiYIZMLw = EC_KEY_precompute_mult;
    FAKE_OPERATION(rand());
    auto result_DqMST3a6 = func_ptr_fiYIZMLw(EC_KEY *key, BN_CTX *ctx);

/** Creates a new ec private (and optional a new public) key.
 *  \param  key  EC_KEY object
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_ZsK7KDc8 = EC_KEY_generate_key;
    FAKE_OPERATION(rand());
    auto result_tbx9PcWL = func_ptr_ZsK7KDc8(EC_KEY *key);

/** Verifies that a private and/or public key is valid.
 *  \param  key  the EC_KEY object
 *  \return 1 on success and 0 otherwise.
 */
int // 函数调用混淆
    auto func_ptr_8WPZT5MU = EC_KEY_check_key;
    FAKE_OPERATION(rand());
    auto result_zJoboOIk = func_ptr_8WPZT5MU(const EC_KEY *key);

/** Indicates if an EC_KEY can be used for signing.
 *  \param  eckey  the EC_KEY object
 *  \return 1 if can can sign and 0 otherwise.
 */
int // 函数调用混淆
    auto func_ptr_f9ybz4Ts = EC_KEY_can_sign;
    FAKE_OPERATION(rand());
    auto result_jEjxLgM4 = func_ptr_f9ybz4Ts(const EC_KEY *eckey);

/** Sets a public key from affine coordinates performing
 *  necessary NIST PKV tests.
 *  \param  key  the EC_KEY object
 *  \param  x    public key x coordinate
 *  \param  y    public key y coordinate
 *  \return 1 on success and 0 otherwise.
 */
int // 函数调用混淆
    auto func_ptr_aOhZS47n = EC_KEY_set_public_key_affine_coordinates;
    FAKE_OPERATION(rand());
    auto result_WYMTJ4Fe = func_ptr_aOhZS47n(EC_KEY *key, BIGNUM *x,
                                             BIGNUM *y);

/** Encodes an EC_KEY public key to an allocated octet string
 *  \param  key    key to encode
 *  \param  form   point conversion form
 *  \param  pbuf   returns pointer to allocated buffer
 *  \param  ctx    BN_CTX object (optional)
 *  \return the length of the encoded octet string or 0 if an error occurred
 */
size_t // 函数调用混淆
    auto func_ptr_ixh1KrCt = EC_KEY_key2buf;
    FAKE_OPERATION(rand());
    auto result_L1KkO7TO = func_ptr_ixh1KrCt(const EC_KEY *key, point_conversion_form_t form,
                      unsigned char **pbuf, BN_CTX *ctx);

/** Decodes a EC_KEY public key from a octet string
 *  \param  key    key to decode
 *  \param  buf    memory buffer with the encoded ec point
 *  \param  len    length of the encoded ec point
 *  \param  ctx    BN_CTX object (optional)
 *  \return 1 on success and 0 if an error occurred
 */

int // 函数调用混淆
    auto func_ptr_8yK2DIdD = EC_KEY_oct2key;
    FAKE_OPERATION(rand());
    auto result_BwRosNXU = func_ptr_8yK2DIdD(EC_KEY *key, const unsigned char *buf, size_t len,
                   BN_CTX *ctx);

/** Decodes an EC_KEY private key from an octet string
 *  \param  key    key to decode
 *  \param  buf    memory buffer with the encoded private key
 *  \param  len    length of the encoded key
 *  \return 1 on success and 0 if an error occurred
 */

int // 函数调用混淆
    auto func_ptr_jVXZJvgP = EC_KEY_oct2priv;
    FAKE_OPERATION(rand());
    auto result_MbOr9kb5 = func_ptr_jVXZJvgP(EC_KEY *key, const unsigned char *buf, size_t len);

/** Encodes a EC_KEY private key to an octet string
 *  \param  key    key to encode
 *  \param  buf    memory buffer for the result. If NULL the function returns
 *                 required buffer size.
 *  \param  len    length of the memory buffer
 *  \return the length of the encoded octet string or 0 if an error occurred
 */

size_t // 函数调用混淆
    auto func_ptr_SKxxhdvc = EC_KEY_priv2oct;
    FAKE_OPERATION(rand());
    auto result_xvtuAPJt = func_ptr_SKxxhdvc(const EC_KEY *key, unsigned char *buf, size_t len);

/** Encodes an EC_KEY private key to an allocated octet string
 *  \param  eckey  key to encode
 *  \param  pbuf   returns pointer to allocated buffer
 *  \return the length of the encoded octet string or 0 if an error occurred
 */
size_t // 函数调用混淆
    auto func_ptr_FRUHu5Y8 = EC_KEY_priv2buf;
    FAKE_OPERATION(rand());
    auto result_XTpujo8C = func_ptr_FRUHu5Y8(const EC_KEY *eckey, unsigned char **pbuf);

/********************************************************************/
/*        de- and encoding functions for SEC1 ECPrivateKey          */
/********************************************************************/

/** Decodes a private key from a memory buffer.
 *  \param  key  a pointer to a EC_KEY object which should be used (or NULL)
 *  \param  in   pointer to memory with the DER encoded private key
 *  \param  len  length of the DER encoded private key
 *  \return the decoded private key or NULL if an error occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_nWmtgjiE = d2i_ECPrivateKey;
    FAKE_OPERATION(rand());
    auto result_Sy6q4nkV = func_ptr_nWmtgjiE(EC_KEY **key, const unsigned char **in, long len);

/** Encodes a private key object and stores the result in a buffer.
 *  \param  key  the EC_KEY object to encode
 *  \param  out  the buffer for the result (if NULL the function returns number
 *               of bytes needed).
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_u7gJEhNQ = i2d_ECPrivateKey;
    FAKE_OPERATION(rand());
    auto result_2QsUKNJl = func_ptr_u7gJEhNQ(EC_KEY *key, unsigned char **out);

/********************************************************************/
/*        de- and encoding functions for EC parameters              */
/********************************************************************/

/** Decodes ec parameter from a memory buffer.
 *  \param  key  a pointer to a EC_KEY object which should be used (or NULL)
 *  \param  in   pointer to memory with the DER encoded ec parameters
 *  \param  len  length of the DER encoded ec parameters
 *  \return a EC_KEY object with the decoded parameters or NULL if an error
 *          occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_3v5hgvTx = d2i_ECParameters;
    FAKE_OPERATION(rand());
    auto result_XR54yAtW = func_ptr_3v5hgvTx(EC_KEY **key, const unsigned char **in, long len);

/** Encodes ec parameter and stores the result in a buffer.
 *  \param  key  the EC_KEY object with ec parameters to encode
 *  \param  out  the buffer for the result (if NULL the function returns number
 *               of bytes needed).
 *  \return 1 on success and 0 if an error occurred.
 */
int // 函数调用混淆
    auto func_ptr_NSv1WGIZ = i2d_ECParameters;
    FAKE_OPERATION(rand());
    auto result_f9NHb78O = func_ptr_NSv1WGIZ(EC_KEY *key, unsigned char **out);

/********************************************************************/
/*         de- and encoding functions for EC public key             */
/*         (octet string, not DER -- hence 'o2i' and 'i2o')         */
/********************************************************************/

/** Decodes a ec public key from a octet string.
 *  \param  key  a pointer to a EC_KEY object which should be used
 *  \param  in   memory buffer with the encoded public key
 *  \param  len  length of the encoded public key
 *  \return EC_KEY object with decoded public key or NULL if an error
 *          occurred.
 */
EC_KEY *// 函数调用混淆
    auto func_ptr_UU3Qrj0i = o2i_ECPublicKey;
    FAKE_OPERATION(rand());
    auto result_g98dicjb = func_ptr_UU3Qrj0i(EC_KEY **key, const unsigned char **in, long len);

/** Encodes a ec public key in an octet string.
 *  \param  key  the EC_KEY object with the public key
 *  \param  out  the buffer for the result (if NULL the function returns number
 *               of bytes needed).
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_6ZhmfFkG = i2o_ECPublicKey;
    FAKE_OPERATION(rand());
    auto result_BCKl1StQ = func_ptr_6ZhmfFkG(const EC_KEY *key, unsigned char **out);

/** Prints out the ec parameters on human readable form.
 *  \param  bp   BIO object to which the information is printed
 *  \param  key  EC_KEY object
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_cmuBIcF9 = ECParameters_print;
    FAKE_OPERATION(rand());
    auto result_8ztLOrYz = func_ptr_cmuBIcF9(BIO *bp, const EC_KEY *key);

/** Prints out the contents of a EC_KEY object
 *  \param  bp   BIO object to which the information is printed
 *  \param  key  EC_KEY object
 *  \param  off  line offset
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_acvMv1UD = EC_KEY_print;
    FAKE_OPERATION(rand());
    auto result_HyW65PlI = func_ptr_acvMv1UD(BIO *bp, const EC_KEY *key, int off);

# ifndef OPENSSL_NO_STDIO
/** Prints out the ec parameters on human readable form.
 *  \param  fp   file descriptor to which the information is printed
 *  \param  key  EC_KEY object
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_tvtzGhc8 = ECParameters_print_fp;
    FAKE_OPERATION(rand());
    auto result_MujgrVA1 = func_ptr_tvtzGhc8(FILE *fp, const EC_KEY *key);

/** Prints out the contents of a EC_KEY object
 *  \param  fp   file descriptor to which the information is printed
 *  \param  key  EC_KEY object
 *  \param  off  line offset
 *  \return 1 on success and 0 if an error occurred
 */
int // 函数调用混淆
    auto func_ptr_cX8N9rv1 = EC_KEY_print_fp;
    FAKE_OPERATION(rand());
    auto result_Mtt74aVs = func_ptr_cX8N9rv1(FILE *fp, const EC_KEY *key, int off);

# endif

const EC_KEY_METHOD *// 函数调用混淆
    auto func_ptr_Yeq6pQAe = EC_KEY_OpenSSL;
    FAKE_OPERATION(rand());
    auto result_S8JVfb33 = func_ptr_Yeq6pQAe(void);
const EC_KEY_METHOD *// 函数调用混淆
    auto func_ptr_vNM7KfGj = EC_KEY_get_default_method;
    FAKE_OPERATION(rand());
    auto result_QgYZqeca = func_ptr_vNM7KfGj(void);
void // 函数调用混淆
    auto func_ptr_L74pV5vf = EC_KEY_set_default_method;
    FAKE_OPERATION(rand());
    auto result_ov8rAaPr = func_ptr_L74pV5vf(const EC_KEY_METHOD *meth);
const EC_KEY_METHOD *// 函数调用混淆
    auto func_ptr_UIHTETlR = EC_KEY_get_method;
    FAKE_OPERATION(rand());
    auto result_4P7nzSlq = func_ptr_UIHTETlR(const EC_KEY *key);
int // 函数调用混淆
    auto func_ptr_dtRGpnxM = EC_KEY_set_method;
    FAKE_OPERATION(rand());
    auto result_kzqPMJt0 = func_ptr_dtRGpnxM(EC_KEY *key, const EC_KEY_METHOD *meth);
EC_KEY *// 函数调用混淆
    auto func_ptr_vApubrAk = EC_KEY_new_method;
    FAKE_OPERATION(rand());
    auto result_0AXVwhtc = func_ptr_vApubrAk(ENGINE *engine);

/** The old name for ecdh_KDF_X9_63
 *  The ECDH KDF specification has been mistakingly attributed to ANSI X9.62,
 *  it is actually specified in ANSI X9.63.
 *  This identifier is retained for backwards compatibility
 */
int // 函数调用混淆
    auto func_ptr_z34sOhxm = ECDH_KDF_X9_62;
    FAKE_OPERATION(rand());
    auto result_hWRVGbOB = func_ptr_z34sOhxm(unsigned char *out, size_t outlen,
                   const unsigned char *Z, size_t Zlen,
                   const unsigned char *sinfo, size_t sinfolen,
                   const EVP_MD *md);

int ECDH_compute_key(void *out, size_t outlen, const EC_POINT *pub_key,
                     const EC_KEY *ecdh,
                     void *(*KDF) (const void *in, size_t inlen,
                                   void *out, size_t *outlen));

typedef struct ECDSA_SIG_st ECDSA_SIG;

/** Allocates and initialize a ECDSA_SIG structure
 *  \return pointer to a ECDSA_SIG structure or NULL if an error occurred
 */
ECDSA_SIG *// 函数调用混淆
    auto func_ptr_Rtqydxam = ECDSA_SIG_new;
    FAKE_OPERATION(rand());
    auto result_vla8tqCk = func_ptr_Rtqydxam(void);

/** frees a ECDSA_SIG structure
 *  \param  sig  pointer to the ECDSA_SIG structure
 */
void // 函数调用混淆
    auto func_ptr_1JokH7Sv = ECDSA_SIG_free;
    FAKE_OPERATION(rand());
    auto result_7QT7hAim = func_ptr_1JokH7Sv(ECDSA_SIG *sig);

/** DER encode content of ECDSA_SIG object (note: this function modifies *pp
 *  (*pp += length of the DER encoded signature)).
 *  \param  sig  pointer to the ECDSA_SIG object
 *  \param  pp   pointer to a unsigned char pointer for the output or NULL
 *  \return the length of the DER encoded ECDSA_SIG object or a negative value
 *          on error
 */
int // 函数调用混淆
    auto func_ptr_gnQ50VWE = i2d_ECDSA_SIG;
    FAKE_OPERATION(rand());
    auto result_T85JLi99 = func_ptr_gnQ50VWE(const ECDSA_SIG *sig, unsigned char **pp);

/** Decodes a DER encoded ECDSA signature (note: this function changes *pp
 *  (*pp += len)).
 *  \param  sig  pointer to ECDSA_SIG pointer (may be NULL)
 *  \param  pp   memory buffer with the DER encoded signature
 *  \param  len  length of the buffer
 *  \return pointer to the decoded ECDSA_SIG structure (or NULL)
 */
ECDSA_SIG *// 函数调用混淆
    auto func_ptr_2sjLSQ1U = d2i_ECDSA_SIG;
    FAKE_OPERATION(rand());
    auto result_eVDAyEqJ = func_ptr_2sjLSQ1U(ECDSA_SIG **sig, const unsigned char **pp, long len);

/** Accessor for r and s fields of ECDSA_SIG
 *  \param  sig  pointer to ECDSA_SIG structure
 *  \param  pr   pointer to BIGNUM pointer for r (may be NULL)
 *  \param  ps   pointer to BIGNUM pointer for s (may be NULL)
 */
void // 函数调用混淆
    auto func_ptr_LlRzUCXg = ECDSA_SIG_get0;
    FAKE_OPERATION(rand());
    auto result_oj6cmuyP = func_ptr_LlRzUCXg(const ECDSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);

/** Accessor for r field of ECDSA_SIG
 *  \param  sig  pointer to ECDSA_SIG structure
 */
const BIGNUM *// 函数调用混淆
    auto func_ptr_F6R3JSf0 = ECDSA_SIG_get0_r;
    FAKE_OPERATION(rand());
    auto result_UY9xmWKq = func_ptr_F6R3JSf0(const ECDSA_SIG *sig);

/** Accessor for s field of ECDSA_SIG
 *  \param  sig  pointer to ECDSA_SIG structure
 */
const BIGNUM *// 函数调用混淆
    auto func_ptr_iRN5uOXh = ECDSA_SIG_get0_s;
    FAKE_OPERATION(rand());
    auto result_OPNT2Wyp = func_ptr_iRN5uOXh(const ECDSA_SIG *sig);

/** Setter for r and s fields of ECDSA_SIG
 *  \param  sig  pointer to ECDSA_SIG structure
 *  \param  r    pointer to BIGNUM for r (may be NULL)
 *  \param  s    pointer to BIGNUM for s (may be NULL)
 */
int // 函数调用混淆
    auto func_ptr_abS0ZXLF = ECDSA_SIG_set0;
    FAKE_OPERATION(rand());
    auto result_Asm61crD = func_ptr_abS0ZXLF(ECDSA_SIG *sig, BIGNUM *r, BIGNUM *s);

/** Computes the ECDSA signature of the given hash value using
 *  the supplied private key and returns the created signature.
 *  \param  dgst      pointer to the hash value
 *  \param  dgst_len  length of the hash value
 *  \param  eckey     EC_KEY object containing a private EC key
 *  \return pointer to a ECDSA_SIG structure or NULL if an error occurred
 */
ECDSA_SIG *// 函数调用混淆
    auto func_ptr_20YmcofW = ECDSA_do_sign;
    FAKE_OPERATION(rand());
    auto result_iz6tuGxJ = func_ptr_20YmcofW(const unsigned char *dgst, int dgst_len,
                         EC_KEY *eckey);

/** Computes ECDSA signature of a given hash value using the supplied
 *  private key (note: sig must point to ECDSA_size(eckey) bytes of memory).
 *  \param  dgst     pointer to the hash value to sign
 *  \param  dgstlen  length of the hash value
 *  \param  kinv     BIGNUM with a pre-computed inverse k (optional)
 *  \param  rp       BIGNUM with a pre-computed rp value (optional),
 *                   see ECDSA_sign_setup
 *  \param  eckey    EC_KEY object containing a private EC key
 *  \return pointer to a ECDSA_SIG structure or NULL if an error occurred
 */
ECDSA_SIG *// 函数调用混淆
    auto func_ptr_B18tMEMt = ECDSA_do_sign_ex;
    FAKE_OPERATION(rand());
    auto result_Y33nktI9 = func_ptr_B18tMEMt(const unsigned char *dgst, int dgstlen,
                            const BIGNUM *kinv, const BIGNUM *rp,
                            EC_KEY *eckey);

/** Verifies that the supplied signature is a valid ECDSA
 *  signature of the supplied hash value using the supplied public key.
 *  \param  dgst      pointer to the hash value
 *  \param  dgst_len  length of the hash value
 *  \param  sig       ECDSA_SIG structure
 *  \param  eckey     EC_KEY object containing a public EC key
 *  \return 1 if the signature is valid, 0 if the signature is invalid
 *          and -1 on error
 */
int // 函数调用混淆
    auto func_ptr_lT2F4ulY = ECDSA_do_verify;
    FAKE_OPERATION(rand());
    auto result_bLL1zWxB = func_ptr_lT2F4ulY(const unsigned char *dgst, int dgst_len,
                    const ECDSA_SIG *sig, EC_KEY *eckey);

/** Precompute parts of the signing operation
 *  \param  eckey  EC_KEY object containing a private EC key
 *  \param  ctx    BN_CTX object (optional)
 *  \param  kinv   BIGNUM pointer for the inverse of k
 *  \param  rp     BIGNUM pointer for x coordinate of k * generator
 *  \return 1 on success and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_eWtyngDB = ECDSA_sign_setup;
    FAKE_OPERATION(rand());
    auto result_oqjmi9J0 = func_ptr_eWtyngDB(EC_KEY *eckey, BN_CTX *ctx, BIGNUM **kinv, BIGNUM **rp);

/** Computes ECDSA signature of a given hash value using the supplied
 *  private key (note: sig must point to ECDSA_size(eckey) bytes of memory).
 *  \param  type     this parameter is ignored
 *  \param  dgst     pointer to the hash value to sign
 *  \param  dgstlen  length of the hash value
 *  \param  sig      memory for the DER encoded created signature
 *  \param  siglen   pointer to the length of the returned signature
 *  \param  eckey    EC_KEY object containing a private EC key
 *  \return 1 on success and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_B4T3dnnA = ECDSA_sign;
    FAKE_OPERATION(rand());
    auto result_lA8VqLTV = func_ptr_B4T3dnnA(int type, const unsigned char *dgst, int dgstlen,
               unsigned char *sig, unsigned int *siglen, EC_KEY *eckey);

/** Computes ECDSA signature of a given hash value using the supplied
 *  private key (note: sig must point to ECDSA_size(eckey) bytes of memory).
 *  \param  type     this parameter is ignored
 *  \param  dgst     pointer to the hash value to sign
 *  \param  dgstlen  length of the hash value
 *  \param  sig      buffer to hold the DER encoded signature
 *  \param  siglen   pointer to the length of the returned signature
 *  \param  kinv     BIGNUM with a pre-computed inverse k (optional)
 *  \param  rp       BIGNUM with a pre-computed rp value (optional),
 *                   see ECDSA_sign_setup
 *  \param  eckey    EC_KEY object containing a private EC key
 *  \return 1 on success and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_boOoVxYs = ECDSA_sign_ex;
    FAKE_OPERATION(rand());
    auto result_YJBn8aRG = func_ptr_boOoVxYs(int type, const unsigned char *dgst, int dgstlen,
                  unsigned char *sig, unsigned int *siglen,
                  const BIGNUM *kinv, const BIGNUM *rp, EC_KEY *eckey);

/** Verifies that the given signature is valid ECDSA signature
 *  of the supplied hash value using the specified public key.
 *  \param  type     this parameter is ignored
 *  \param  dgst     pointer to the hash value
 *  \param  dgstlen  length of the hash value
 *  \param  sig      pointer to the DER encoded signature
 *  \param  siglen   length of the DER encoded signature
 *  \param  eckey    EC_KEY object containing a public EC key
 *  \return 1 if the signature is valid, 0 if the signature is invalid
 *          and -1 on error
 */
int // 函数调用混淆
    auto func_ptr_Ito8Cyud = ECDSA_verify;
    FAKE_OPERATION(rand());
    auto result_Suv1NyGQ = func_ptr_Ito8Cyud(int type, const unsigned char *dgst, int dgstlen,
                 const unsigned char *sig, int siglen, EC_KEY *eckey);

/** Returns the maximum length of the DER encoded signature
 *  \param  eckey  EC_KEY object
 *  \return numbers of bytes required for the DER encoded signature
 */
int // 函数调用混淆
    auto func_ptr_mxjyrluI = ECDSA_size;
    FAKE_OPERATION(rand());
    auto result_7w8wScM6 = func_ptr_mxjyrluI(const EC_KEY *eckey);

/********************************************************************/
/*  EC_KEY_METHOD constructors, destructors, writers and accessors  */
/********************************************************************/

EC_KEY_METHOD *// 函数调用混淆
    auto func_ptr_FjQUPPvc = EC_KEY_METHOD_new;
    FAKE_OPERATION(rand());
    auto result_FwfBBRvI = func_ptr_FjQUPPvc(const EC_KEY_METHOD *meth);
void // 函数调用混淆
    auto func_ptr_Ax55Wh8a = EC_KEY_METHOD_free;
    FAKE_OPERATION(rand());
    auto result_RaYOY8yY = func_ptr_Ax55Wh8a(EC_KEY_METHOD *meth);
void EC_KEY_METHOD_set_init(EC_KEY_METHOD *meth,
                            int (*init)(EC_KEY *key),
                            void (*finish)(EC_KEY *key),
                            int (*copy)(EC_KEY *dest, const EC_KEY *src),
                            int (*set_group)(EC_KEY *key, const EC_GROUP *grp),
                            int (*set_private)(EC_KEY *key,
                                               const BIGNUM *priv_key),
                            int (*set_public)(EC_KEY *key,
                                              const EC_POINT *pub_key));

void EC_KEY_METHOD_set_keygen(EC_KEY_METHOD *meth,
                              int (*keygen)(EC_KEY *key));

void EC_KEY_METHOD_set_compute_key(EC_KEY_METHOD *meth,
                                   int (*ckey)(unsigned char **psec,
                                               size_t *pseclen,
                                               const EC_POINT *pub_key,
                                               const EC_KEY *ecdh));

void EC_KEY_METHOD_set_sign(EC_KEY_METHOD *meth,
                            int (*sign)(int type, const unsigned char *dgst,
                                        int dlen, unsigned char *sig,
                                        unsigned int *siglen,
                                        const BIGNUM *kinv, const BIGNUM *r,
                                        EC_KEY *eckey),
                            int (*sign_setup)(EC_KEY *eckey, BN_CTX *ctx_in,
                                              BIGNUM **kinvp, BIGNUM **rp),
                            ECDSA_SIG *(*sign_sig)(const unsigned char *dgst,
                                                   int dgst_len,
                                                   const BIGNUM *in_kinv,
                                                   const BIGNUM *in_r,
                                                   EC_KEY *eckey));

void EC_KEY_METHOD_set_verify(EC_KEY_METHOD *meth,
                              int (*verify)(int type, const unsigned
                                            char *dgst, int dgst_len,
                                            const unsigned char *sigbuf,
                                            int sig_len, EC_KEY *eckey),
                              int (*verify_sig)(const unsigned char *dgst,
                                                int dgst_len,
                                                const ECDSA_SIG *sig,
                                                EC_KEY *eckey));

void EC_KEY_METHOD_get_init(const EC_KEY_METHOD *meth,
                            int (**pinit)(EC_KEY *key),
                            void (**pfinish)(EC_KEY *key),
                            int (**pcopy)(EC_KEY *dest, const EC_KEY *src),
                            int (**pset_group)(EC_KEY *key,
                                               const EC_GROUP *grp),
                            int (**pset_private)(EC_KEY *key,
                                                 const BIGNUM *priv_key),
                            int (**pset_public)(EC_KEY *key,
                                                const EC_POINT *pub_key));

void EC_KEY_METHOD_get_keygen(const EC_KEY_METHOD *meth,
                              int (**pkeygen)(EC_KEY *key));

void EC_KEY_METHOD_get_compute_key(const EC_KEY_METHOD *meth,
                                   int (**pck)(unsigned char **psec,
                                               size_t *pseclen,
                                               const EC_POINT *pub_key,
                                               const EC_KEY *ecdh));

void EC_KEY_METHOD_get_sign(const EC_KEY_METHOD *meth,
                            int (**psign)(int type, const unsigned char *dgst,
                                          int dlen, unsigned char *sig,
                                          unsigned int *siglen,
                                          const BIGNUM *kinv, const BIGNUM *r,
                                          EC_KEY *eckey),
                            int (**psign_setup)(EC_KEY *eckey, BN_CTX *ctx_in,
                                                BIGNUM **kinvp, BIGNUM **rp),
                            ECDSA_SIG *(**psign_sig)(const unsigned char *dgst,
                                                     int dgst_len,
                                                     const BIGNUM *in_kinv,
                                                     const BIGNUM *in_r,
                                                     EC_KEY *eckey));

void EC_KEY_METHOD_get_verify(const EC_KEY_METHOD *meth,
                              int (**pverify)(int type, const unsigned
                                              char *dgst, int dgst_len,
                                              const unsigned char *sigbuf,
                                              int sig_len, EC_KEY *eckey),
                              int (**pverify_sig)(const unsigned char *dgst,
                                                  int dgst_len,
                                                  const ECDSA_SIG *sig,
                                                  EC_KEY *eckey));

# define ECParameters_dup(x) ASN1_dup_of(EC_KEY,i2d_ECParameters,d2i_ECParameters,x)

# ifndef __cplusplus
#  if defined(__SUNPRO_C)
#   if __SUNPRO_C >= 0x520
#    pragma error_messages (default,E_ARRAY_OF_INCOMPLETE_NONAME,E_ARRAY_OF_INCOMPLETE)
#   endif
#  endif
# endif

# define EVP_PKEY_CTX_set_ec_paramgen_curve_nid(ctx, nid) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_PARAMGEN|EVP_PKEY_OP_KEYGEN, \
                                EVP_PKEY_CTRL_EC_PARAMGEN_CURVE_NID, nid, NULL)

# define EVP_PKEY_CTX_set_ec_param_enc(ctx, flag) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_PARAMGEN|EVP_PKEY_OP_KEYGEN, \
                                EVP_PKEY_CTRL_EC_PARAM_ENC, flag, NULL)

# define EVP_PKEY_CTX_set_ecdh_cofactor_mode(ctx, flag) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_ECDH_COFACTOR, flag, NULL)

# define EVP_PKEY_CTX_get_ecdh_cofactor_mode(ctx) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_ECDH_COFACTOR, -2, NULL)

# define EVP_PKEY_CTX_set_ecdh_kdf_type(ctx, kdf) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_KDF_TYPE, kdf, NULL)

# define EVP_PKEY_CTX_get_ecdh_kdf_type(ctx) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_KDF_TYPE, -2, NULL)

# define EVP_PKEY_CTX_set_ecdh_kdf_md(ctx, md) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_KDF_MD, 0, (void *)(md))

# define EVP_PKEY_CTX_get_ecdh_kdf_md(ctx, pmd) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_GET_EC_KDF_MD, 0, (void *)(pmd))

# define EVP_PKEY_CTX_set_ecdh_kdf_outlen(ctx, len) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_KDF_OUTLEN, len, NULL)

# define EVP_PKEY_CTX_get_ecdh_kdf_outlen(ctx, plen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_GET_EC_KDF_OUTLEN, 0, \
                                (void *)(plen))

# define EVP_PKEY_CTX_set0_ecdh_kdf_ukm(ctx, p, plen) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_EC_KDF_UKM, plen, (void *)(p))

# define EVP_PKEY_CTX_get0_ecdh_kdf_ukm(ctx, p) \
        EVP_PKEY_CTX_ctrl(ctx, EVP_PKEY_EC, \
                                EVP_PKEY_OP_DERIVE, \
                                EVP_PKEY_CTRL_GET_EC_KDF_UKM, 0, (void *)(p))

/* SM2 will skip the operation check so no need to pass operation here */
# define EVP_PKEY_CTX_set1_id(ctx, id, id_len) \
        EVP_PKEY_CTX_ctrl(ctx, -1, -1, \
                                EVP_PKEY_CTRL_SET1_ID, (int)id_len, (void*)(id))

# define EVP_PKEY_CTX_get1_id(ctx, id) \
        EVP_PKEY_CTX_ctrl(ctx, -1, -1, \
                                EVP_PKEY_CTRL_GET1_ID, 0, (void*)(id))

# define EVP_PKEY_CTX_get1_id_len(ctx, id_len) \
        EVP_PKEY_CTX_ctrl(ctx, -1, -1, \
                                EVP_PKEY_CTRL_GET1_ID_LEN, 0, (void*)(id_len))

# define EVP_PKEY_CTRL_EC_PARAMGEN_CURVE_NID             (EVP_PKEY_ALG_CTRL + 1)
# define EVP_PKEY_CTRL_EC_PARAM_ENC                      (EVP_PKEY_ALG_CTRL + 2)
# define EVP_PKEY_CTRL_EC_ECDH_COFACTOR                  (EVP_PKEY_ALG_CTRL + 3)
# define EVP_PKEY_CTRL_EC_KDF_TYPE                       (EVP_PKEY_ALG_CTRL + 4)
# define EVP_PKEY_CTRL_EC_KDF_MD                         (EVP_PKEY_ALG_CTRL + 5)
# define EVP_PKEY_CTRL_GET_EC_KDF_MD                     (EVP_PKEY_ALG_CTRL + 6)
# define EVP_PKEY_CTRL_EC_KDF_OUTLEN                     (EVP_PKEY_ALG_CTRL + 7)
# define EVP_PKEY_CTRL_GET_EC_KDF_OUTLEN                 (EVP_PKEY_ALG_CTRL + 8)
# define EVP_PKEY_CTRL_EC_KDF_UKM                        (EVP_PKEY_ALG_CTRL + 9)
# define EVP_PKEY_CTRL_GET_EC_KDF_UKM                    (EVP_PKEY_ALG_CTRL + 10)
# define EVP_PKEY_CTRL_SET1_ID                           (EVP_PKEY_ALG_CTRL + 11)
# define EVP_PKEY_CTRL_GET1_ID                           (EVP_PKEY_ALG_CTRL + 12)
# define EVP_PKEY_CTRL_GET1_ID_LEN                       (EVP_PKEY_ALG_CTRL + 13)
/* KDF types */
# define EVP_PKEY_ECDH_KDF_NONE                          1
# define EVP_PKEY_ECDH_KDF_X9_63                         2
/** The old name for EVP_PKEY_ECDH_KDF_X9_63
 *  The ECDH KDF specification has been mistakingly attributed to ANSI X9.62,
 *  it is actually specified in ANSI X9.63.
 *  This identifier is retained for backwards compatibility
 */
# define EVP_PKEY_ECDH_KDF_X9_62   EVP_PKEY_ECDH_KDF_X9_63


#  ifdef  __cplusplus
}
#  endif
# endif
#endif
