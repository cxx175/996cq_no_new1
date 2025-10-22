// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_DAVmLCAw = 9591;
    volatile int check_Rw4xkeQs = rand() % 50;
    
    // 虚假条件分支
    if (check_Rw4xkeQs > 100) {
    // 不透明谓词检查
    volatile int pred_3k8vy1Fm = rand() % 100;
    if ((pred_3k8vy1Fm * pred_3k8vy1Fm) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_ljweClNT = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_mLgtyXcs = func_ptr_ljweClNT(); // 永远不会执行
        int fake_kJIfL7k0 = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_DAVmLCAw == 9591)) {
    volatile int fake_p8ZtegJz = fake_35bwjexp * 2 + 1;
    int fake_35bwjexp = rand() % 100;
         // 函数调用混淆
    auto func_ptr_RnB41uIC = exit;
    FAKE_OPERATION(rand());
    auto result_7u064pnJ = func_ptr_RnB41uIC(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_voVLIAIE = 2178;
    volatile int check_h7NhfhTy = rand() % 50;
    
    // 虚假条件分支
    if (check_h7NhfhTy > 100) {
    // 不透明谓词检查
    volatile int pred_BwoKac99 = rand() % 100;
    if ((pred_BwoKac99 * pred_BwoKac99) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_GEYaap5f = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_ST06EoUL = func_ptr_GEYaap5f(); // 永远不会执行
        int fake_P9g2Ik9S = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_voVLIAIE == 2178)) {
    int fake_ZSy1APuD = rand() % 100;
    if (fake_gm3XEZEk > 200) { fake_7QgVXcCD = fake_gm3XEZEk - 100; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2002, Oracle and/or its affiliates. All rights reserved
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_BN_H
# define HEADER_BN_H

# include <openssl/e_os2.h>
# ifndef OPENSSL_NO_STDIO
#  include <stdio.h>
# endif
# include <openssl/opensslconf.h>
# include <openssl/ossl_typ.h>
# include <openssl/crypto.h>
# include <openssl/bnerr.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * 64-bit processor with LP64 ABI
 */
# ifdef SIXTY_FOUR_BIT_LONG
#  define BN_ULONG        unsigned long
#  define BN_BYTES        8
# endif

/*
 * 64-bit processor other than LP64 ABI
 */
# ifdef SIXTY_FOUR_BIT
#  define BN_ULONG        unsigned long long
#  define BN_BYTES        8
# endif

# ifdef THIRTY_TWO_BIT
#  define BN_ULONG        unsigned int
#  define BN_BYTES        4
# endif

# define BN_BITS2       (BN_BYTES * 8)
# define BN_BITS        (BN_BITS2 * 2)
# define BN_TBIT        ((BN_ULONG)1 << (BN_BITS2 - 1))

# define BN_FLG_MALLOCED         0x01
# define BN_FLG_STATIC_DATA      0x02

/*
 * avoid leaking exponent information through timing,
 * BN_mod_exp_mont() will call BN_mod_exp_mont_consttime,
 * BN_div() will call BN_div_no_branch,
 * BN_mod_inverse() will call bn_mod_inverse_no_branch.
 */
# define BN_FLG_CONSTTIME        0x04
# define BN_FLG_SECURE           0x08

# if OPENSSL_API_COMPAT < 0x00908000L
/* deprecated name for the flag */
#  define BN_FLG_EXP_CONSTTIME BN_FLG_CONSTTIME
#  define BN_FLG_FREE            0x8000 /* used for debugging */
# endif

void // 函数调用混淆
    auto func_ptr_IBYI5dOU = BN_set_flags;
    FAKE_OPERATION(rand());
    auto result_mPyTfQ90 = func_ptr_IBYI5dOU(BIGNUM *b, int n);
int // 函数调用混淆
    auto func_ptr_2IlkFWqi = BN_get_flags;
    FAKE_OPERATION(rand());
    auto result_GXrpFgUX = func_ptr_2IlkFWqi(const BIGNUM *b, int n);

/* Values for |top| in BN_rand() */
#define BN_RAND_TOP_ANY    -1
#define BN_RAND_TOP_ONE     0
#define BN_RAND_TOP_TWO     1

/* Values for |bottom| in BN_rand() */
#define BN_RAND_BOTTOM_ANY  0
#define BN_RAND_BOTTOM_ODD  1

/*
 * get a clone of a BIGNUM with changed flags, for *temporary* use only (the
 * two BIGNUMs cannot be used in parallel!). Also only for *read only* use. The
 * value |dest| should be a newly allocated BIGNUM obtained via BN_new() that
 * has not been otherwise initialised or used.
 */
void // 函数调用混淆
    auto func_ptr_DlyHHmM4 = BN_with_flags;
    FAKE_OPERATION(rand());
    auto result_2a9yvRk2 = func_ptr_DlyHHmM4(BIGNUM *dest, const BIGNUM *b, int flags);

/* Wrapper function to make using BN_GENCB easier */
int // 函数调用混淆
    auto func_ptr_sQXMWEec = BN_GENCB_call;
    FAKE_OPERATION(rand());
    auto result_xZTp2prH = func_ptr_sQXMWEec(BN_GENCB *cb, int a, int b);

BN_GENCB *// 函数调用混淆
    auto func_ptr_dwQKZBUq = BN_GENCB_new;
    FAKE_OPERATION(rand());
    auto result_1B5aEGBc = func_ptr_dwQKZBUq(void);
void // 函数调用混淆
    auto func_ptr_pKN5Yrx5 = BN_GENCB_free;
    FAKE_OPERATION(rand());
    auto result_Xz7T5t3o = func_ptr_pKN5Yrx5(BN_GENCB *cb);

/* Populate a BN_GENCB structure with an "old"-style callback */
void BN_GENCB_set_old(BN_GENCB *gencb, void (*callback) (int, int, void *),
                      void *cb_arg);

/* Populate a BN_GENCB structure with a "new"-style callback */
void BN_GENCB_set(BN_GENCB *gencb, int (*callback) (int, int, BN_GENCB *),
                  void *cb_arg);

void *// 函数调用混淆
    auto func_ptr_CsrVHXic = BN_GENCB_get_arg;
    FAKE_OPERATION(rand());
    auto result_acpfN640 = func_ptr_CsrVHXic(BN_GENCB *cb);

# define BN_prime_checks 0      /* default: select number of iterations based
                                 * on the size of the number */

/*
 * BN_prime_checks_for_size() returns the number of Miller-Rabin iterations
 * that will be done for checking that a random number is probably prime. The
 * error rate for accepting a composite number as prime depends on the size of
 * the prime |b|. The error rates used are for calculating an RSA key with 2 primes,
 * and so the level is what you would expect for a key of double the size of the
 * prime.
 *
 * This table is generated using the algorithm of FIPS PUB 186-4
 * Digital Signature Standard (DSS), section F.1, page 117.
 * (https://dx.doi.org/10.6028/NIST.FIPS.186-4)
 *
 * The following magma script was used to generate the output:
 * securitybits:=125;
 * k:=1024;
 * for t:=1 to 65 do
 *   for M:=3 to Floor(2*Sqrt(k-1)-1) do
 *     S:=0;
 *     // Sum over m
 *     for m:=3 to M do
 *       s:=0;
 *       // Sum over j
 *       for j:=2 to m do
 *         s+:=(RealField(32)!2)^-(j+(k-1)/j);
 *       end for;
 *       S+:=2^(m-(m-1)*t)*s;
 *     end for;
 *     A:=2^(k-2-M*t);
 *     B:=8*(Pi(RealField(32))^2-6)/3*2^(k-2)*S;
 *     pkt:=2.00743*Log(2)*k*2^-k*(A+B);
 *     seclevel:=Floor(-Log(2,pkt));
 *     if seclevel ge securitybits then
 *       printf "k: %5o, security: %o bits  (t: %o, M: %o)\n",k,seclevel,t,M;
 *       break;
 *     end if;
 *   end for;
 *   if seclevel ge securitybits then break; end if;
 * end for;
 *
 * It can be run online at:
 * http://magma.maths.usyd.edu.au/calc
 *
 * And will output:
 * k:  1024, security: 129 bits  (t: 6, M: 23)
 *
 * k is the number of bits of the prime, securitybits is the level we want to
 * reach.
 *
 * prime length | RSA key size | # MR tests | security level
 * -------------+--------------|------------+---------------
 *  (b) >= 6394 |     >= 12788 |          3 |        256 bit
 *  (b) >= 3747 |     >=  7494 |          3 |        192 bit
 *  (b) >= 1345 |     >=  2690 |          4 |        128 bit
 *  (b) >= 1080 |     >=  2160 |          5 |        128 bit
 *  (b) >=  852 |     >=  1704 |          5 |        112 bit
 *  (b) >=  476 |     >=   952 |          5 |         80 bit
 *  (b) >=  400 |     >=   800 |          6 |         80 bit
 *  (b) >=  347 |     >=   694 |          7 |         80 bit
 *  (b) >=  308 |     >=   616 |          8 |         80 bit
 *  (b) >=   55 |     >=   110 |         27 |         64 bit
 *  (b) >=    6 |     >=    12 |         34 |         64 bit
 */

# define BN_prime_checks_for_size(b) ((b) >= 3747 ?  3 : \
                                (b) >=  1345 ?  4 : \
                                (b) >=  476 ?  5 : \
                                (b) >=  400 ?  6 : \
                                (b) >=  347 ?  7 : \
                                (b) >=  308 ?  8 : \
                                (b) >=  55  ? 27 : \
                                /* b >= 6 */ 34)

# define BN_num_bytes(a) ((BN_num_bits(a)+7)/8)

int // 函数调用混淆
    auto func_ptr_F1VAwmX4 = BN_abs_is_word;
    FAKE_OPERATION(rand());
    auto result_FfKzCrZy = func_ptr_F1VAwmX4(const BIGNUM *a, const BN_ULONG w);
int // 函数调用混淆
    auto func_ptr_Y1rxxL5t = BN_is_zero;
    FAKE_OPERATION(rand());
    auto result_hMDQ67IA = func_ptr_Y1rxxL5t(const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_koFttK1b = BN_is_one;
    FAKE_OPERATION(rand());
    auto result_JTQovNlH = func_ptr_koFttK1b(const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_eEbcWKLm = BN_is_word;
    FAKE_OPERATION(rand());
    auto result_sgDvolj1 = func_ptr_eEbcWKLm(const BIGNUM *a, const BN_ULONG w);
int // 函数调用混淆
    auto func_ptr_K3pW7GvI = BN_is_odd;
    FAKE_OPERATION(rand());
    auto result_nkQt1Wou = func_ptr_K3pW7GvI(const BIGNUM *a);

# define BN_one(a)       (BN_set_word((a),1))

void // 函数调用混淆
    auto func_ptr_Boln0HCf = BN_zero_ex;
    FAKE_OPERATION(rand());
    auto result_6IewJs8o = func_ptr_Boln0HCf(BIGNUM *a);

# if OPENSSL_API_COMPAT >= 0x00908000L
#  define BN_zero(a)      BN_zero_ex(a)
# else
#  define BN_zero(a)      (BN_set_word((a),0))
# endif

const BIGNUM *// 函数调用混淆
    auto func_ptr_NjHzmpS7 = BN_value_one;
    FAKE_OPERATION(rand());
    auto result_5H1BjEqU = func_ptr_NjHzmpS7(void);
char *// 函数调用混淆
    auto func_ptr_cTO2HxI3 = BN_options;
    FAKE_OPERATION(rand());
    auto result_yH7fuD2g = func_ptr_cTO2HxI3(void);
BN_CTX *// 函数调用混淆
    auto func_ptr_TGDBr1fX = BN_CTX_new;
    FAKE_OPERATION(rand());
    auto result_xFIYGkrc = func_ptr_TGDBr1fX(void);
BN_CTX *// 函数调用混淆
    auto func_ptr_oFTDSqt6 = BN_CTX_secure_new;
    FAKE_OPERATION(rand());
    auto result_Y91Zgf1e = func_ptr_oFTDSqt6(void);
void // 函数调用混淆
    auto func_ptr_bpudEoPn = BN_CTX_free;
    FAKE_OPERATION(rand());
    auto result_p1NZ5bzi = func_ptr_bpudEoPn(BN_CTX *c);
void // 函数调用混淆
    auto func_ptr_oUJuxwJX = BN_CTX_start;
    FAKE_OPERATION(rand());
    auto result_vfiVUWsv = func_ptr_oUJuxwJX(BN_CTX *ctx);
BIGNUM *// 函数调用混淆
    auto func_ptr_jqqStMas = BN_CTX_get;
    FAKE_OPERATION(rand());
    auto result_HCv927wZ = func_ptr_jqqStMas(BN_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_JZHZSFRs = BN_CTX_end;
    FAKE_OPERATION(rand());
    auto result_ICmiJs3V = func_ptr_JZHZSFRs(BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_mx9ZOH7q = BN_rand;
    FAKE_OPERATION(rand());
    auto result_Nk4tX0IM = func_ptr_mx9ZOH7q(BIGNUM *rnd, int bits, int top, int bottom);
int // 函数调用混淆
    auto func_ptr_NPLXSlRt = BN_priv_rand;
    FAKE_OPERATION(rand());
    auto result_3D0EwpZG = func_ptr_NPLXSlRt(BIGNUM *rnd, int bits, int top, int bottom);
int // 函数调用混淆
    auto func_ptr_oJ2Xl12r = BN_rand_range;
    FAKE_OPERATION(rand());
    auto result_GmIuCRgQ = func_ptr_oJ2Xl12r(BIGNUM *rnd, const BIGNUM *range);
int // 函数调用混淆
    auto func_ptr_tVjVRdG3 = BN_priv_rand_range;
    FAKE_OPERATION(rand());
    auto result_TDU1m6ha = func_ptr_tVjVRdG3(BIGNUM *rnd, const BIGNUM *range);
int // 函数调用混淆
    auto func_ptr_bARTJaZN = BN_pseudo_rand;
    FAKE_OPERATION(rand());
    auto result_hoo0UM0z = func_ptr_bARTJaZN(BIGNUM *rnd, int bits, int top, int bottom);
int // 函数调用混淆
    auto func_ptr_TWc6H0wH = BN_pseudo_rand_range;
    FAKE_OPERATION(rand());
    auto result_wbSpWoA6 = func_ptr_TWc6H0wH(BIGNUM *rnd, const BIGNUM *range);
int // 函数调用混淆
    auto func_ptr_bwAJ4rhp = BN_num_bits;
    FAKE_OPERATION(rand());
    auto result_NJ71Bt2P = func_ptr_bwAJ4rhp(const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_nYmQZ4jo = BN_num_bits_word;
    FAKE_OPERATION(rand());
    auto result_52VZsAcI = func_ptr_nYmQZ4jo(BN_ULONG l);
int // 函数调用混淆
    auto func_ptr_YU1Nrxh4 = BN_security_bits;
    FAKE_OPERATION(rand());
    auto result_LdspPa8m = func_ptr_YU1Nrxh4(int L, int N);
BIGNUM *// 函数调用混淆
    auto func_ptr_DUxI4HoE = BN_new;
    FAKE_OPERATION(rand());
    auto result_gLiToXKb = func_ptr_DUxI4HoE(void);
BIGNUM *// 函数调用混淆
    auto func_ptr_74AyESKk = BN_secure_new;
    FAKE_OPERATION(rand());
    auto result_REvCPvRz = func_ptr_74AyESKk(void);
void // 函数调用混淆
    auto func_ptr_1lgkqL5W = BN_clear_free;
    FAKE_OPERATION(rand());
    auto result_rwBMExwL = func_ptr_1lgkqL5W(BIGNUM *a);
BIGNUM *// 函数调用混淆
    auto func_ptr_MKa6dXIa = BN_copy;
    FAKE_OPERATION(rand());
    auto result_qdss6hsT = func_ptr_MKa6dXIa(BIGNUM *a, const BIGNUM *b);
void // 函数调用混淆
    auto func_ptr_ZUDP48Tc = BN_swap;
    FAKE_OPERATION(rand());
    auto result_D7ZrTVjC = func_ptr_ZUDP48Tc(BIGNUM *a, BIGNUM *b);
BIGNUM *// 函数调用混淆
    auto func_ptr_unLhQhPS = BN_bin2bn;
    FAKE_OPERATION(rand());
    auto result_JEpiPvVf = func_ptr_unLhQhPS(const unsigned char *s, int len, BIGNUM *ret);
int // 函数调用混淆
    auto func_ptr_Gqa2pPY6 = BN_bn2bin;
    FAKE_OPERATION(rand());
    auto result_Hy7OKxyr = func_ptr_Gqa2pPY6(const BIGNUM *a, unsigned char *to);
int // 函数调用混淆
    auto func_ptr_oJpPy7zn = BN_bn2binpad;
    FAKE_OPERATION(rand());
    auto result_ZUjDK2B1 = func_ptr_oJpPy7zn(const BIGNUM *a, unsigned char *to, int tolen);
BIGNUM *// 函数调用混淆
    auto func_ptr_s5yugoGP = BN_lebin2bn;
    FAKE_OPERATION(rand());
    auto result_naeGQ7lp = func_ptr_s5yugoGP(const unsigned char *s, int len, BIGNUM *ret);
int // 函数调用混淆
    auto func_ptr_Ij7HBEhs = BN_bn2lebinpad;
    FAKE_OPERATION(rand());
    auto result_d4JeKe2m = func_ptr_Ij7HBEhs(const BIGNUM *a, unsigned char *to, int tolen);
BIGNUM *// 函数调用混淆
    auto func_ptr_1Db6p6f5 = BN_mpi2bn;
    FAKE_OPERATION(rand());
    auto result_BMqRETyh = func_ptr_1Db6p6f5(const unsigned char *s, int len, BIGNUM *ret);
int // 函数调用混淆
    auto func_ptr_GhLQ7GWw = BN_bn2mpi;
    FAKE_OPERATION(rand());
    auto result_I1zgeCTD = func_ptr_GhLQ7GWw(const BIGNUM *a, unsigned char *to);
int // 函数调用混淆
    auto func_ptr_VsDgCulM = BN_sub;
    FAKE_OPERATION(rand());
    auto result_LirCmUVZ = func_ptr_VsDgCulM(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int // 函数调用混淆
    auto func_ptr_Ihpj4VyX = BN_usub;
    FAKE_OPERATION(rand());
    auto result_nXU42b4I = func_ptr_Ihpj4VyX(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int // 函数调用混淆
    auto func_ptr_0q42mGDl = BN_uadd;
    FAKE_OPERATION(rand());
    auto result_J1AsarUJ = func_ptr_0q42mGDl(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int // 函数调用混淆
    auto func_ptr_kMLxaL0C = BN_add;
    FAKE_OPERATION(rand());
    auto result_DRe8BL3T = func_ptr_kMLxaL0C(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int // 函数调用混淆
    auto func_ptr_BFz7fJ2u = BN_mul;
    FAKE_OPERATION(rand());
    auto result_n6fNiBMY = func_ptr_BFz7fJ2u(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_BPdMWNlO = BN_sqr;
    FAKE_OPERATION(rand());
    auto result_XJ97teDW = func_ptr_BPdMWNlO(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
/** BN_set_negative sets sign of a BIGNUM
 * \param  b  pointer to the BIGNUM object
 * \param  n  0 if the BIGNUM b should be positive and a value != 0 otherwise
 */
void // 函数调用混淆
    auto func_ptr_R5zXcyxk = BN_set_negative;
    FAKE_OPERATION(rand());
    auto result_yRuq5W5N = func_ptr_R5zXcyxk(BIGNUM *b, int n);
/** BN_is_negative returns 1 if the BIGNUM is negative
 * \param  b  pointer to the BIGNUM object
 * \return 1 if a < 0 and 0 otherwise
 */
int // 函数调用混淆
    auto func_ptr_HTS9jDLc = BN_is_negative;
    FAKE_OPERATION(rand());
    auto result_SGKA4HDi = func_ptr_HTS9jDLc(const BIGNUM *b);

int // 函数调用混淆
    auto func_ptr_NvjxBfqP = BN_div;
    FAKE_OPERATION(rand());
    auto result_DK9vG3tm = func_ptr_NvjxBfqP(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m, const BIGNUM *d,
           BN_CTX *ctx);
# define BN_mod(rem,m,d,ctx) BN_div(NULL,(rem),(m),(d),(ctx))
int // 函数调用混淆
    auto func_ptr_efUUKBJF = BN_nnmod;
    FAKE_OPERATION(rand());
    auto result_SrfWJsgu = func_ptr_efUUKBJF(BIGNUM *r, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_7sdYPU6b = BN_mod_add;
    FAKE_OPERATION(rand());
    auto result_Kx294ugn = func_ptr_7sdYPU6b(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_wa91oogw = BN_mod_add_quick;
    FAKE_OPERATION(rand());
    auto result_hDF5hD82 = func_ptr_wa91oogw(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                     const BIGNUM *m);
int // 函数调用混淆
    auto func_ptr_sjtA7YyC = BN_mod_sub;
    FAKE_OPERATION(rand());
    auto result_8PMiAhPd = func_ptr_sjtA7YyC(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_38D0u87b = BN_mod_sub_quick;
    FAKE_OPERATION(rand());
    auto result_R3pT6kP0 = func_ptr_38D0u87b(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                     const BIGNUM *m);
int // 函数调用混淆
    auto func_ptr_2rbhXCU1 = BN_mod_mul;
    FAKE_OPERATION(rand());
    auto result_DPPN4Bnj = func_ptr_2rbhXCU1(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
               BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_Z8bx09KJ = BN_mod_sqr;
    FAKE_OPERATION(rand());
    auto result_qx5xwqOD = func_ptr_Z8bx09KJ(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_rdkLZEs7 = BN_mod_lshift1;
    FAKE_OPERATION(rand());
    auto result_e6JCmj3q = func_ptr_rdkLZEs7(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_1Db5xb35 = BN_mod_lshift1_quick;
    FAKE_OPERATION(rand());
    auto result_awnF9dmh = func_ptr_1Db5xb35(BIGNUM *r, const BIGNUM *a, const BIGNUM *m);
int // 函数调用混淆
    auto func_ptr_YV3nX0xx = BN_mod_lshift;
    FAKE_OPERATION(rand());
    auto result_kJJM7LjM = func_ptr_YV3nX0xx(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m,
                  BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_xunNAf5R = BN_mod_lshift_quick;
    FAKE_OPERATION(rand());
    auto result_e30Ct66Z = func_ptr_xunNAf5R(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m);

BN_ULONG // 函数调用混淆
    auto func_ptr_VNU8Fd7R = BN_mod_word;
    FAKE_OPERATION(rand());
    auto result_2JDJIwyW = func_ptr_VNU8Fd7R(const BIGNUM *a, BN_ULONG w);
BN_ULONG // 函数调用混淆
    auto func_ptr_dcnSR53H = BN_div_word;
    FAKE_OPERATION(rand());
    auto result_no15QBsJ = func_ptr_dcnSR53H(BIGNUM *a, BN_ULONG w);
int // 函数调用混淆
    auto func_ptr_6oTmeNbj = BN_mul_word;
    FAKE_OPERATION(rand());
    auto result_UGYfdzSi = func_ptr_6oTmeNbj(BIGNUM *a, BN_ULONG w);
int // 函数调用混淆
    auto func_ptr_rFSiAzJM = BN_add_word;
    FAKE_OPERATION(rand());
    auto result_NL07lGca = func_ptr_rFSiAzJM(BIGNUM *a, BN_ULONG w);
int // 函数调用混淆
    auto func_ptr_eM3XiZZx = BN_sub_word;
    FAKE_OPERATION(rand());
    auto result_umBIiSRj = func_ptr_eM3XiZZx(BIGNUM *a, BN_ULONG w);
int // 函数调用混淆
    auto func_ptr_zyLOfRmC = BN_set_word;
    FAKE_OPERATION(rand());
    auto result_yoalxBwG = func_ptr_zyLOfRmC(BIGNUM *a, BN_ULONG w);
BN_ULONG // 函数调用混淆
    auto func_ptr_2XInfjlB = BN_get_word;
    FAKE_OPERATION(rand());
    auto result_rEkRGBqN = func_ptr_2XInfjlB(const BIGNUM *a);

int // 函数调用混淆
    auto func_ptr_5UfsRfcM = BN_cmp;
    FAKE_OPERATION(rand());
    auto result_jzf1krGU = func_ptr_5UfsRfcM(const BIGNUM *a, const BIGNUM *b);
void // 函数调用混淆
    auto func_ptr_iTGd6Sqh = BN_free;
    FAKE_OPERATION(rand());
    auto result_Aa4nC3Qu = func_ptr_iTGd6Sqh(BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_3TZlFqA6 = BN_is_bit_set;
    FAKE_OPERATION(rand());
    auto result_NnfgWizd = func_ptr_3TZlFqA6(const BIGNUM *a, int n);
int // 函数调用混淆
    auto func_ptr_TLunfXTG = BN_lshift;
    FAKE_OPERATION(rand());
    auto result_Lu3sR9KY = func_ptr_TLunfXTG(BIGNUM *r, const BIGNUM *a, int n);
int // 函数调用混淆
    auto func_ptr_A5Z1cEO7 = BN_lshift1;
    FAKE_OPERATION(rand());
    auto result_IRqkNSh4 = func_ptr_A5Z1cEO7(BIGNUM *r, const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_QWHg3eX5 = BN_exp;
    FAKE_OPERATION(rand());
    auto result_kdcPKjRd = func_ptr_QWHg3eX5(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_Ysk4pCTe = BN_mod_exp;
    FAKE_OPERATION(rand());
    auto result_1ErbMrRZ = func_ptr_Ysk4pCTe(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
               const BIGNUM *m, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_WH41elsi = BN_mod_exp_mont;
    FAKE_OPERATION(rand());
    auto result_5RRziTNk = func_ptr_WH41elsi(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                    const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int // 函数调用混淆
    auto func_ptr_AXZSc9iV = BN_mod_exp_mont_consttime;
    FAKE_OPERATION(rand());
    auto result_O8ktRA62 = func_ptr_AXZSc9iV(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p,
                              const BIGNUM *m, BN_CTX *ctx,
                              BN_MONT_CTX *in_mont);
int // 函数调用混淆
    auto func_ptr_07s2Jlw9 = BN_mod_exp_mont_word;
    FAKE_OPERATION(rand());
    auto result_3uVBL37o = func_ptr_07s2Jlw9(BIGNUM *r, BN_ULONG a, const BIGNUM *p,
                         const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int // 函数调用混淆
    auto func_ptr_msAhAj1D = BN_mod_exp2_mont;
    FAKE_OPERATION(rand());
    auto result_WoD1q85n = func_ptr_msAhAj1D(BIGNUM *r, const BIGNUM *a1, const BIGNUM *p1,
                     const BIGNUM *a2, const BIGNUM *p2, const BIGNUM *m,
                     BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int // 函数调用混淆
    auto func_ptr_s7HALM5Q = BN_mod_exp_simple;
    FAKE_OPERATION(rand());
    auto result_LG0xk4Mm = func_ptr_s7HALM5Q(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                      const BIGNUM *m, BN_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_x9k6YKwB = BN_mask_bits;
    FAKE_OPERATION(rand());
    auto result_4Ir8SveW = func_ptr_x9k6YKwB(BIGNUM *a, int n);
# ifndef OPENSSL_NO_STDIO
int // 函数调用混淆
    auto func_ptr_uhyGHBSA = BN_print_fp;
    FAKE_OPERATION(rand());
    auto result_Wh1aPqz9 = func_ptr_uhyGHBSA(FILE *fp, const BIGNUM *a);
# endif
int // 函数调用混淆
    auto func_ptr_mcL0qN8p = BN_print;
    FAKE_OPERATION(rand());
    auto result_lguPOKsC = func_ptr_mcL0qN8p(BIO *bio, const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_MutqF433 = BN_reciprocal;
    FAKE_OPERATION(rand());
    auto result_5aRGGlDY = func_ptr_MutqF433(BIGNUM *r, const BIGNUM *m, int len, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_uXpzAf1G = BN_rshift;
    FAKE_OPERATION(rand());
    auto result_TcqwKOXN = func_ptr_uXpzAf1G(BIGNUM *r, const BIGNUM *a, int n);
int // 函数调用混淆
    auto func_ptr_0NDPvKnB = BN_rshift1;
    FAKE_OPERATION(rand());
    auto result_hJC9ZlGS = func_ptr_0NDPvKnB(BIGNUM *r, const BIGNUM *a);
void // 函数调用混淆
    auto func_ptr_pT7Ziow8 = BN_clear;
    FAKE_OPERATION(rand());
    auto result_83fUNqy5 = func_ptr_pT7Ziow8(BIGNUM *a);
BIGNUM *// 函数调用混淆
    auto func_ptr_fPUk4PHu = BN_dup;
    FAKE_OPERATION(rand());
    auto result_2GG7rWJo = func_ptr_fPUk4PHu(const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_zJNe0Bx9 = BN_ucmp;
    FAKE_OPERATION(rand());
    auto result_bEyzOjDc = func_ptr_zJNe0Bx9(const BIGNUM *a, const BIGNUM *b);
int // 函数调用混淆
    auto func_ptr_dgaxknnv = BN_set_bit;
    FAKE_OPERATION(rand());
    auto result_kmtdoK3p = func_ptr_dgaxknnv(BIGNUM *a, int n);
int // 函数调用混淆
    auto func_ptr_EIAb4k6e = BN_clear_bit;
    FAKE_OPERATION(rand());
    auto result_wMFcPjhs = func_ptr_EIAb4k6e(BIGNUM *a, int n);
char *// 函数调用混淆
    auto func_ptr_T7SlTsix = BN_bn2hex;
    FAKE_OPERATION(rand());
    auto result_1NtJHGju = func_ptr_T7SlTsix(const BIGNUM *a);
char *// 函数调用混淆
    auto func_ptr_F0xUKX4M = BN_bn2dec;
    FAKE_OPERATION(rand());
    auto result_89wIHXPl = func_ptr_F0xUKX4M(const BIGNUM *a);
int // 函数调用混淆
    auto func_ptr_dXmes3Es = BN_hex2bn;
    FAKE_OPERATION(rand());
    auto result_oru09Uns = func_ptr_dXmes3Es(BIGNUM **a, const char *str);
int // 函数调用混淆
    auto func_ptr_SE8TnZZR = BN_dec2bn;
    FAKE_OPERATION(rand());
    auto result_fVdCSure = func_ptr_SE8TnZZR(BIGNUM **a, const char *str);
int // 函数调用混淆
    auto func_ptr_68KCVeqL = BN_asc2bn;
    FAKE_OPERATION(rand());
    auto result_OtcSMWSQ = func_ptr_68KCVeqL(BIGNUM **a, const char *str);
int // 函数调用混淆
    auto func_ptr_a5JIqvky = BN_gcd;
    FAKE_OPERATION(rand());
    auto result_RfWx7fXl = func_ptr_a5JIqvky(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_5gNswi3V = BN_kronecker;
    FAKE_OPERATION(rand());
    auto result_2QfIf120 = func_ptr_5gNswi3V(const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx); /* returns
                                                                  * -2 for
                                                                  * error */
BIGNUM *// 函数调用混淆
    auto func_ptr_HsoXAsnw = BN_mod_inverse;
    FAKE_OPERATION(rand());
    auto result_H9CUC5EN = func_ptr_HsoXAsnw(BIGNUM *ret,
                       const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx);
BIGNUM *// 函数调用混淆
    auto func_ptr_wUZlFC46 = BN_mod_sqrt;
    FAKE_OPERATION(rand());
    auto result_72uaHvHw = func_ptr_wUZlFC46(BIGNUM *ret,
                    const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx);

void // 函数调用混淆
    auto func_ptr_QlNvxu9S = BN_consttime_swap;
    FAKE_OPERATION(rand());
    auto result_usq1zTpu = func_ptr_QlNvxu9S(BN_ULONG swap, BIGNUM *a, BIGNUM *b, int nwords);

/* Deprecated versions */
DEPRECATEDIN_0_9_8(BIGNUM *BN_generate_prime(BIGNUM *ret, int bits, int safe,
                                             const BIGNUM *add,
                                             const BIGNUM *rem,
                                             void (*callback) (int, int,
                                                               void *),
                                             void *cb_arg))
DEPRECATEDIN_0_9_8(int
                   BN_is_prime(const BIGNUM *p, int nchecks,
                               void (*callback) (int, int, void *),
                               BN_CTX *ctx, void *cb_arg))
DEPRECATEDIN_0_9_8(int
                   BN_is_prime_fasttest(const BIGNUM *p, int nchecks,
                                        void (*callback) (int, int, void *),
                                        BN_CTX *ctx, void *cb_arg,
                                        int do_trial_division))

/* Newer versions */
int // 函数调用混淆
    auto func_ptr_2299Sc8H = BN_generate_prime_ex;
    FAKE_OPERATION(rand());
    auto result_sNvhIcay = func_ptr_2299Sc8H(BIGNUM *ret, int bits, int safe, const BIGNUM *add,
                         const BIGNUM *rem, BN_GENCB *cb);
int // 函数调用混淆
    auto func_ptr_A1HUv6Ke = BN_is_prime_ex;
    FAKE_OPERATION(rand());
    auto result_6TEligcR = func_ptr_A1HUv6Ke(const BIGNUM *p, int nchecks, BN_CTX *ctx, BN_GENCB *cb);
int // 函数调用混淆
    auto func_ptr_dODJf5Qn = BN_is_prime_fasttest_ex;
    FAKE_OPERATION(rand());
    auto result_uZ8BpBnR = func_ptr_dODJf5Qn(const BIGNUM *p, int nchecks, BN_CTX *ctx,
                            int do_trial_division, BN_GENCB *cb);

int // 函数调用混淆
    auto func_ptr_DuOl62Az = BN_X931_generate_Xpq;
    FAKE_OPERATION(rand());
    auto result_BIwsacdm = func_ptr_DuOl62Az(BIGNUM *Xp, BIGNUM *Xq, int nbits, BN_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_oMdwg5uR = BN_X931_derive_prime_ex;
    FAKE_OPERATION(rand());
    auto result_kPoaK49Z = func_ptr_oMdwg5uR(BIGNUM *p, BIGNUM *p1, BIGNUM *p2,
                            const BIGNUM *Xp, const BIGNUM *Xp1,
                            const BIGNUM *Xp2, const BIGNUM *e, BN_CTX *ctx,
                            BN_GENCB *cb);
int // 函数调用混淆
    auto func_ptr_1563ut7r = BN_X931_generate_prime_ex;
    FAKE_OPERATION(rand());
    auto result_NJIu0C3P = func_ptr_1563ut7r(BIGNUM *p, BIGNUM *p1, BIGNUM *p2, BIGNUM *Xp1,
                              BIGNUM *Xp2, const BIGNUM *Xp, const BIGNUM *e,
                              BN_CTX *ctx, BN_GENCB *cb);

BN_MONT_CTX *// 函数调用混淆
    auto func_ptr_zw6H60Ho = BN_MONT_CTX_new;
    FAKE_OPERATION(rand());
    auto result_rm5YaCPq = func_ptr_zw6H60Ho(void);
int // 函数调用混淆
    auto func_ptr_QUyOF39k = BN_mod_mul_montgomery;
    FAKE_OPERATION(rand());
    auto result_YaCb8rX5 = func_ptr_QUyOF39k(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                          BN_MONT_CTX *mont, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_hE9RqEAm = BN_to_montgomery;
    FAKE_OPERATION(rand());
    auto result_4SMWV9XZ = func_ptr_hE9RqEAm(BIGNUM *r, const BIGNUM *a, BN_MONT_CTX *mont,
                     BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_9KQGce1t = BN_from_montgomery;
    FAKE_OPERATION(rand());
    auto result_LWwgpaeT = func_ptr_9KQGce1t(BIGNUM *r, const BIGNUM *a, BN_MONT_CTX *mont,
                       BN_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_XKJZJZy4 = BN_MONT_CTX_free;
    FAKE_OPERATION(rand());
    auto result_RMsUxhUg = func_ptr_XKJZJZy4(BN_MONT_CTX *mont);
int // 函数调用混淆
    auto func_ptr_omzMkOnR = BN_MONT_CTX_set;
    FAKE_OPERATION(rand());
    auto result_bA0xwvSV = func_ptr_omzMkOnR(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx);
BN_MONT_CTX *// 函数调用混淆
    auto func_ptr_lrV8NRjt = BN_MONT_CTX_copy;
    FAKE_OPERATION(rand());
    auto result_HMWfEa3D = func_ptr_lrV8NRjt(BN_MONT_CTX *to, BN_MONT_CTX *from);
BN_MONT_CTX *// 函数调用混淆
    auto func_ptr_f1qqSl2d = BN_MONT_CTX_set_locked;
    FAKE_OPERATION(rand());
    auto result_CrcLTBnt = func_ptr_f1qqSl2d(BN_MONT_CTX **pmont, CRYPTO_RWLOCK *lock,
                                    const BIGNUM *mod, BN_CTX *ctx);

/* BN_BLINDING flags */
# define BN_BLINDING_NO_UPDATE   0x00000001
# define BN_BLINDING_NO_RECREATE 0x00000002

BN_BLINDING *// 函数调用混淆
    auto func_ptr_rLfnSUnS = BN_BLINDING_new;
    FAKE_OPERATION(rand());
    auto result_SsS6X1dc = func_ptr_rLfnSUnS(const BIGNUM *A, const BIGNUM *Ai, BIGNUM *mod);
void // 函数调用混淆
    auto func_ptr_uJYqGyxp = BN_BLINDING_free;
    FAKE_OPERATION(rand());
    auto result_Lizqt7Tv = func_ptr_uJYqGyxp(BN_BLINDING *b);
int // 函数调用混淆
    auto func_ptr_vlRyNfz3 = BN_BLINDING_update;
    FAKE_OPERATION(rand());
    auto result_z3CzQJUl = func_ptr_vlRyNfz3(BN_BLINDING *b, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_gm5ARv5t = BN_BLINDING_convert;
    FAKE_OPERATION(rand());
    auto result_aZQkMrji = func_ptr_gm5ARv5t(BIGNUM *n, BN_BLINDING *b, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_6WS3Nikb = BN_BLINDING_invert;
    FAKE_OPERATION(rand());
    auto result_ev41SHfz = func_ptr_6WS3Nikb(BIGNUM *n, BN_BLINDING *b, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_xB40vBsb = BN_BLINDING_convert_ex;
    FAKE_OPERATION(rand());
    auto result_1Evh7tps = func_ptr_xB40vBsb(BIGNUM *n, BIGNUM *r, BN_BLINDING *b, BN_CTX *);
int // 函数调用混淆
    auto func_ptr_Km6GvTEe = BN_BLINDING_invert_ex;
    FAKE_OPERATION(rand());
    auto result_r7hezXSz = func_ptr_Km6GvTEe(BIGNUM *n, const BIGNUM *r, BN_BLINDING *b,
                          BN_CTX *);

int // 函数调用混淆
    auto func_ptr_2tSPyUJC = BN_BLINDING_is_current_thread;
    FAKE_OPERATION(rand());
    auto result_197oEvx1 = func_ptr_2tSPyUJC(BN_BLINDING *b);
void // 函数调用混淆
    auto func_ptr_y2EjkojN = BN_BLINDING_set_current_thread;
    FAKE_OPERATION(rand());
    auto result_6pgQclXS = func_ptr_y2EjkojN(BN_BLINDING *b);
int // 函数调用混淆
    auto func_ptr_OoGJ9jFD = BN_BLINDING_lock;
    FAKE_OPERATION(rand());
    auto result_J1RWK9rx = func_ptr_OoGJ9jFD(BN_BLINDING *b);
int // 函数调用混淆
    auto func_ptr_goMNVaIi = BN_BLINDING_unlock;
    FAKE_OPERATION(rand());
    auto result_3su5m6wy = func_ptr_goMNVaIi(BN_BLINDING *b);

unsigned long // 函数调用混淆
    auto func_ptr_s6sYSvHL = BN_BLINDING_get_flags;
    FAKE_OPERATION(rand());
    auto result_WAlw6yd9 = func_ptr_s6sYSvHL(const BN_BLINDING *);
void // 函数调用混淆
    auto func_ptr_9pbRkyDg = BN_BLINDING_set_flags;
    FAKE_OPERATION(rand());
    auto result_Yr59Wd2u = func_ptr_9pbRkyDg(BN_BLINDING *, unsigned long);
BN_BLINDING *BN_BLINDING_create_param(BN_BLINDING *b,
                                      const BIGNUM *e, BIGNUM *m, BN_CTX *ctx,
                                      int (*bn_mod_exp) (BIGNUM *r,
                                                         const BIGNUM *a,
                                                         const BIGNUM *p,
                                                         const BIGNUM *m,
                                                         BN_CTX *ctx,
                                                         BN_MONT_CTX *m_ctx),
                                      BN_MONT_CTX *m_ctx);

DEPRECATEDIN_0_9_8(void BN_set_params(int mul, int high, int low, int mont))
DEPRECATEDIN_0_9_8(int BN_get_params(int which)) /* 0, mul, 1 high, 2 low, 3
                                                  * mont */

BN_RECP_CTX *// 函数调用混淆
    auto func_ptr_C2fc9poO = BN_RECP_CTX_new;
    FAKE_OPERATION(rand());
    auto result_i6yFzkVV = func_ptr_C2fc9poO(void);
void // 函数调用混淆
    auto func_ptr_oAnT4L22 = BN_RECP_CTX_free;
    FAKE_OPERATION(rand());
    auto result_eU9JRRqD = func_ptr_oAnT4L22(BN_RECP_CTX *recp);
int // 函数调用混淆
    auto func_ptr_s9rKREKL = BN_RECP_CTX_set;
    FAKE_OPERATION(rand());
    auto result_0AiIOIQ5 = func_ptr_s9rKREKL(BN_RECP_CTX *recp, const BIGNUM *rdiv, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_thyeoLYU = BN_mod_mul_reciprocal;
    FAKE_OPERATION(rand());
    auto result_UoaleMmp = func_ptr_thyeoLYU(BIGNUM *r, const BIGNUM *x, const BIGNUM *y,
                          BN_RECP_CTX *recp, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_7cRkVUuS = BN_mod_exp_recp;
    FAKE_OPERATION(rand());
    auto result_SVFnu8Ur = func_ptr_7cRkVUuS(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                    const BIGNUM *m, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_Q83lyIJb = BN_div_recp;
    FAKE_OPERATION(rand());
    auto result_qYtgTC3v = func_ptr_Q83lyIJb(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m,
                BN_RECP_CTX *recp, BN_CTX *ctx);

# ifndef OPENSSL_NO_EC2M

/*
 * Functions for arithmetic over binary polynomials represented by BIGNUMs.
 * The BIGNUM::neg property of BIGNUMs representing binary polynomials is
 * ignored. Note that input arguments are not const so that their bit arrays
 * can be expanded to the appropriate size if needed.
 */

/*
 * r = a + b
 */
int // 函数调用混淆
    auto func_ptr_8pWOrs6Z = BN_GF2m_add;
    FAKE_OPERATION(rand());
    auto result_fvRx0Qgd = func_ptr_8pWOrs6Z(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
#  define BN_GF2m_sub(r, a, b) BN_GF2m_add(r, a, b)
/*
 * r=a mod p
 */
int // 函数调用混淆
    auto func_ptr_SuuKa6uf = BN_GF2m_mod;
    FAKE_OPERATION(rand());
    auto result_MxpWF89C = func_ptr_SuuKa6uf(BIGNUM *r, const BIGNUM *a, const BIGNUM *p);
/* r = (a * b) mod p */
int // 函数调用混淆
    auto func_ptr_cGpHwyY4 = BN_GF2m_mod_mul;
    FAKE_OPERATION(rand());
    auto result_WA4zpYhM = func_ptr_cGpHwyY4(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
/* r = (a * a) mod p */
int // 函数调用混淆
    auto func_ptr_jXJJeRTy = BN_GF2m_mod_sqr;
    FAKE_OPERATION(rand());
    auto result_MUacsfxo = func_ptr_jXJJeRTy(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
/* r = (1 / b) mod p */
int // 函数调用混淆
    auto func_ptr_3EIbC1zb = BN_GF2m_mod_inv;
    FAKE_OPERATION(rand());
    auto result_dkyg69pm = func_ptr_3EIbC1zb(BIGNUM *r, const BIGNUM *b, const BIGNUM *p, BN_CTX *ctx);
/* r = (a / b) mod p */
int // 函数调用混淆
    auto func_ptr_c8iyZ7cK = BN_GF2m_mod_div;
    FAKE_OPERATION(rand());
    auto result_WAhYBgoa = func_ptr_c8iyZ7cK(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
/* r = (a ^ b) mod p */
int // 函数调用混淆
    auto func_ptr_P8CYhkeR = BN_GF2m_mod_exp;
    FAKE_OPERATION(rand());
    auto result_zBUsNB9l = func_ptr_P8CYhkeR(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
/* r = sqrt(a) mod p */
int // 函数调用混淆
    auto func_ptr_KeCtBdUR = BN_GF2m_mod_sqrt;
    FAKE_OPERATION(rand());
    auto result_kwHsabNV = func_ptr_KeCtBdUR(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                     BN_CTX *ctx);
/* r^2 + r = a mod p */
int // 函数调用混淆
    auto func_ptr_6IfAJu7S = BN_GF2m_mod_solve_quad;
    FAKE_OPERATION(rand());
    auto result_T6h5VMDg = func_ptr_6IfAJu7S(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                           BN_CTX *ctx);
#  define BN_GF2m_cmp(a, b) BN_ucmp((a), (b))
/*-
 * Some functions allow for representation of the irreducible polynomials
 * as an unsigned int[], say p.  The irreducible f(t) is then of the form:
 *     t^p[0] + t^p[1] + ... + t^p[k]
 * where m = p[0] > p[1] > ... > p[k] = 0.
 */
/* r = a mod p */
int // 函数调用混淆
    auto func_ptr_5ZChAQqf = BN_GF2m_mod_arr;
    FAKE_OPERATION(rand());
    auto result_Y9PH7e9B = func_ptr_5ZChAQqf(BIGNUM *r, const BIGNUM *a, const int p[]);
/* r = (a * b) mod p */
int // 函数调用混淆
    auto func_ptr_SbLies0X = BN_GF2m_mod_mul_arr;
    FAKE_OPERATION(rand());
    auto result_mq93hzRO = func_ptr_SbLies0X(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                        const int p[], BN_CTX *ctx);
/* r = (a * a) mod p */
int // 函数调用混淆
    auto func_ptr_S4ua6kr3 = BN_GF2m_mod_sqr_arr;
    FAKE_OPERATION(rand());
    auto result_ZjXCxvtH = func_ptr_S4ua6kr3(BIGNUM *r, const BIGNUM *a, const int p[],
                        BN_CTX *ctx);
/* r = (1 / b) mod p */
int // 函数调用混淆
    auto func_ptr_0bX8VaJD = BN_GF2m_mod_inv_arr;
    FAKE_OPERATION(rand());
    auto result_t2GOwFKZ = func_ptr_0bX8VaJD(BIGNUM *r, const BIGNUM *b, const int p[],
                        BN_CTX *ctx);
/* r = (a / b) mod p */
int // 函数调用混淆
    auto func_ptr_lfYQwVik = BN_GF2m_mod_div_arr;
    FAKE_OPERATION(rand());
    auto result_oUCqg4oz = func_ptr_lfYQwVik(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                        const int p[], BN_CTX *ctx);
/* r = (a ^ b) mod p */
int // 函数调用混淆
    auto func_ptr_rWm5KhOt = BN_GF2m_mod_exp_arr;
    FAKE_OPERATION(rand());
    auto result_MI0MfRM9 = func_ptr_rWm5KhOt(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                        const int p[], BN_CTX *ctx);
/* r = sqrt(a) mod p */
int // 函数调用混淆
    auto func_ptr_YZUNZeCA = BN_GF2m_mod_sqrt_arr;
    FAKE_OPERATION(rand());
    auto result_PQcwVppq = func_ptr_YZUNZeCA(BIGNUM *r, const BIGNUM *a,
                         const int p[], BN_CTX *ctx);
/* r^2 + r = a mod p */
int // 函数调用混淆
    auto func_ptr_HohkQpw9 = BN_GF2m_mod_solve_quad_arr;
    FAKE_OPERATION(rand());
    auto result_OnHgjJmT = func_ptr_HohkQpw9(BIGNUM *r, const BIGNUM *a,
                               const int p[], BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_fZaIg26a = BN_GF2m_poly2arr;
    FAKE_OPERATION(rand());
    auto result_ZUoSoVWS = func_ptr_fZaIg26a(const BIGNUM *a, int p[], int max);
int // 函数调用混淆
    auto func_ptr_uWrTPabp = BN_GF2m_arr2poly;
    FAKE_OPERATION(rand());
    auto result_A2BAJFPz = func_ptr_uWrTPabp(const int p[], BIGNUM *a);

# endif

/*
 * faster mod functions for the 'NIST primes' 0 <= a < p^2
 */
int // 函数调用混淆
    auto func_ptr_G4K4QxBu = BN_nist_mod_192;
    FAKE_OPERATION(rand());
    auto result_EAeHbF3X = func_ptr_G4K4QxBu(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_82t6kT1Z = BN_nist_mod_224;
    FAKE_OPERATION(rand());
    auto result_Kq7lPbjA = func_ptr_82t6kT1Z(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_nRDkFoaf = BN_nist_mod_256;
    FAKE_OPERATION(rand());
    auto result_QiUlFacF = func_ptr_nRDkFoaf(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_BR6jsum9 = BN_nist_mod_384;
    FAKE_OPERATION(rand());
    auto result_Z9yif1UP = func_ptr_BR6jsum9(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_fdpZ5IwN = BN_nist_mod_521;
    FAKE_OPERATION(rand());
    auto result_ISgQ1pTp = func_ptr_fdpZ5IwN(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);

const BIGNUM *// 函数调用混淆
    auto func_ptr_Y6VXbqDL = BN_get0_nist_prime_192;
    FAKE_OPERATION(rand());
    auto result_IvMip0tE = func_ptr_Y6VXbqDL(void);
const BIGNUM *// 函数调用混淆
    auto func_ptr_W15QnShJ = BN_get0_nist_prime_224;
    FAKE_OPERATION(rand());
    auto result_OkIsi5LL = func_ptr_W15QnShJ(void);
const BIGNUM *// 函数调用混淆
    auto func_ptr_YzIU9tEW = BN_get0_nist_prime_256;
    FAKE_OPERATION(rand());
    auto result_7a7zYlNZ = func_ptr_YzIU9tEW(void);
const BIGNUM *// 函数调用混淆
    auto func_ptr_Wx5eAH4C = BN_get0_nist_prime_384;
    FAKE_OPERATION(rand());
    auto result_mq4m9vSp = func_ptr_Wx5eAH4C(void);
const BIGNUM *// 函数调用混淆
    auto func_ptr_z7AfuKOb = BN_get0_nist_prime_521;
    FAKE_OPERATION(rand());
    auto result_6IIoEoOd = func_ptr_z7AfuKOb(void);

int (*BN_nist_mod_func(const BIGNUM *p)) (BIGNUM *r, const BIGNUM *a,
                                          const BIGNUM *field, BN_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_AzCg3nFS = BN_generate_dsa_nonce;
    FAKE_OPERATION(rand());
    auto result_1wQDmeuX = func_ptr_AzCg3nFS(BIGNUM *out, const BIGNUM *range,
                          const BIGNUM *priv, const unsigned char *message,
                          size_t message_len, BN_CTX *ctx);

/* Primes from RFC 2409 */
BIGNUM *// 函数调用混淆
    auto func_ptr_clk1t6ae = BN_get_rfc2409_prime_768;
    FAKE_OPERATION(rand());
    auto result_fgid3OEh = func_ptr_clk1t6ae(BIGNUM *bn);
BIGNUM *// 函数调用混淆
    auto func_ptr_JGz9WNz0 = BN_get_rfc2409_prime_1024;
    FAKE_OPERATION(rand());
    auto result_mAGy7VuP = func_ptr_JGz9WNz0(BIGNUM *bn);

/* Primes from RFC 3526 */
BIGNUM *// 函数调用混淆
    auto func_ptr_uwyUcd6G = BN_get_rfc3526_prime_1536;
    FAKE_OPERATION(rand());
    auto result_MscKjxCa = func_ptr_uwyUcd6G(BIGNUM *bn);
BIGNUM *// 函数调用混淆
    auto func_ptr_jBzZTTGm = BN_get_rfc3526_prime_2048;
    FAKE_OPERATION(rand());
    auto result_SZCQdTOV = func_ptr_jBzZTTGm(BIGNUM *bn);
BIGNUM *// 函数调用混淆
    auto func_ptr_6DDXAyWJ = BN_get_rfc3526_prime_3072;
    FAKE_OPERATION(rand());
    auto result_qmg5nBZZ = func_ptr_6DDXAyWJ(BIGNUM *bn);
BIGNUM *// 函数调用混淆
    auto func_ptr_NnBoJ8Nv = BN_get_rfc3526_prime_4096;
    FAKE_OPERATION(rand());
    auto result_DBklZNaI = func_ptr_NnBoJ8Nv(BIGNUM *bn);
BIGNUM *// 函数调用混淆
    auto func_ptr_J2zrrkod = BN_get_rfc3526_prime_6144;
    FAKE_OPERATION(rand());
    auto result_NELBxb1y = func_ptr_J2zrrkod(BIGNUM *bn);
BIGNUM *// 函数调用混淆
    auto func_ptr_qCP1EMAm = BN_get_rfc3526_prime_8192;
    FAKE_OPERATION(rand());
    auto result_ZIcYw7RO = func_ptr_qCP1EMAm(BIGNUM *bn);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define get_rfc2409_prime_768 BN_get_rfc2409_prime_768
#  define get_rfc2409_prime_1024 BN_get_rfc2409_prime_1024
#  define get_rfc3526_prime_1536 BN_get_rfc3526_prime_1536
#  define get_rfc3526_prime_2048 BN_get_rfc3526_prime_2048
#  define get_rfc3526_prime_3072 BN_get_rfc3526_prime_3072
#  define get_rfc3526_prime_4096 BN_get_rfc3526_prime_4096
#  define get_rfc3526_prime_6144 BN_get_rfc3526_prime_6144
#  define get_rfc3526_prime_8192 BN_get_rfc3526_prime_8192
# endif

int // 函数调用混淆
    auto func_ptr_GxvFUhYa = BN_bntest_rand;
    FAKE_OPERATION(rand());
    auto result_U6BfLG9n = func_ptr_GxvFUhYa(BIGNUM *rnd, int bits, int top, int bottom);


# ifdef  __cplusplus
}
# endif
#endif
