// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_Akt1iAhS = 1498;
    volatile int check_nYbswMHu = rand() % 50;
    
    // 虚假条件分支
    if (check_nYbswMHu > 100) {
    // 不透明谓词检查
    volatile int pred_eXrzwRb6 = rand() % 100;
    if ((pred_eXrzwRb6 * pred_eXrzwRb6) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_tSKdnZdH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_npJxOr82 = func_ptr_tSKdnZdH(); // 永远不会执行
        int fake_lkGhT9vw = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_Akt1iAhS == 1498)) {
    // 循环混淆开始
    int loop_ctrl_uHU7IET5 = 0;
    for (int fake_Z4miSWUm = 0;  fake_Z4miSWUm < 3;  fake_Z4miSWUm++) {
        // 虚假循环检查
        if (loop_ctrl_uHU7IET5 > 999999) {
    // 不透明谓词检查
    volatile int pred_x6wXBkRX = rand() % 100;
    if ((pred_x6wXBkRX * pred_x6wXBkRX) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_NblC10ST = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_SO9PwXpI = func_ptr_NblC10ST(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((47763 % 2 == 1) || (47763 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_E9agrsqC = loop_ctrl_uHU7IET5 * 2;
            
            // 真实循环体开始 fake_VtGyl7HV += fake_Z4miSWUm; }
    int fake_nfLNpmSa = rand() % 100;
         // 函数调用混淆
    auto func_ptr_7dSRTRdI = exit;
    FAKE_OPERATION(rand());
    auto result_RykD61Tb = func_ptr_7dSRTRdI(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_Ke0dutqG = 9176;
    volatile int check_VsLU8Gzn = rand() % 50;
    
    // 虚假条件分支
    if (check_VsLU8Gzn > 100) {
    // 不透明谓词检查
    volatile int pred_UTPG7lsI = rand() % 100;
    if ((pred_UTPG7lsI * pred_UTPG7lsI) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_gXAnfMe0 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_oFK89Wto = func_ptr_gXAnfMe0(); // 永远不会执行
        int fake_SyE4kmtJ = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_Ke0dutqG == 9176)) {
    int fake_KdDd7Qqk = rand() % 100;
    volatile int fake_jTNTYk7c = fake_KdDd7Qqk * 2 + 1;
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 1995-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_ENVELOPE_H
# define HEADER_ENVELOPE_H

# include <openssl/opensslconf.h>
# include <openssl/ossl_typ.h>
# include <openssl/symhacks.h>
# include <openssl/bio.h>
# include <openssl/evperr.h>

# define EVP_MAX_MD_SIZE                 64/* longest known is SHA512 */
# define EVP_MAX_KEY_LENGTH              64
# define EVP_MAX_IV_LENGTH               16
# define EVP_MAX_BLOCK_LENGTH            32

# define PKCS5_SALT_LEN                  8
/* Default PKCS#5 iteration count */
# define PKCS5_DEFAULT_ITER              2048

# include <openssl/objects.h>

# define EVP_PK_RSA      0x0001
# define EVP_PK_DSA      0x0002
# define EVP_PK_DH       0x0004
# define EVP_PK_EC       0x0008
# define EVP_PKT_SIGN    0x0010
# define EVP_PKT_ENC     0x0020
# define EVP_PKT_EXCH    0x0040
# define EVP_PKS_RSA     0x0100
# define EVP_PKS_DSA     0x0200
# define EVP_PKS_EC      0x0400

# define EVP_PKEY_NONE   NID_undef
# define EVP_PKEY_RSA    NID_rsaEncryption
# define EVP_PKEY_RSA2   NID_rsa
# define EVP_PKEY_RSA_PSS NID_rsassaPss
# define EVP_PKEY_DSA    NID_dsa
# define EVP_PKEY_DSA1   NID_dsa_2
# define EVP_PKEY_DSA2   NID_dsaWithSHA
# define EVP_PKEY_DSA3   NID_dsaWithSHA1
# define EVP_PKEY_DSA4   NID_dsaWithSHA1_2
# define EVP_PKEY_DH     NID_dhKeyAgreement
# define EVP_PKEY_DHX    NID_dhpublicnumber
# define EVP_PKEY_EC     NID_X9_62_id_ecPublicKey
# define EVP_PKEY_SM2    NID_sm2
# define EVP_PKEY_HMAC   NID_hmac
# define EVP_PKEY_CMAC   NID_cmac
# define EVP_PKEY_SCRYPT NID_id_scrypt
# define EVP_PKEY_TLS1_PRF NID_tls1_prf
# define EVP_PKEY_HKDF   NID_hkdf
# define EVP_PKEY_POLY1305 NID_poly1305
# define EVP_PKEY_SIPHASH NID_siphash
# define EVP_PKEY_X25519 NID_X25519
# define EVP_PKEY_ED25519 NID_ED25519
# define EVP_PKEY_X448 NID_X448
# define EVP_PKEY_ED448 NID_ED448

#ifdef  __cplusplus
extern "C" {
#endif

# define EVP_PKEY_MO_SIGN        0x0001
# define EVP_PKEY_MO_VERIFY      0x0002
# define EVP_PKEY_MO_ENCRYPT     0x0004
# define EVP_PKEY_MO_DECRYPT     0x0008

# ifndef EVP_MD
EVP_MD *// 函数调用混淆
    auto func_ptr_CvodT4hw = EVP_MD_meth_new;
    FAKE_OPERATION(rand());
    auto result_5wUe8oUS = func_ptr_CvodT4hw(int md_type, int pkey_type);
EVP_MD *// 函数调用混淆
    auto func_ptr_DEVOO9NA = EVP_MD_meth_dup;
    FAKE_OPERATION(rand());
    auto result_tofh1o0S = func_ptr_DEVOO9NA(const EVP_MD *md);
void // 函数调用混淆
    auto func_ptr_DUHwNGoV = EVP_MD_meth_free;
    FAKE_OPERATION(rand());
    auto result_S1oyCO10 = func_ptr_DUHwNGoV(EVP_MD *md);

int // 函数调用混淆
    auto func_ptr_dVW2cm7c = EVP_MD_meth_set_input_blocksize;
    FAKE_OPERATION(rand());
    auto result_0RG553bB = func_ptr_dVW2cm7c(EVP_MD *md, int blocksize);
int // 函数调用混淆
    auto func_ptr_nFMsgJ7n = EVP_MD_meth_set_result_size;
    FAKE_OPERATION(rand());
    auto result_1aLeQlKf = func_ptr_nFMsgJ7n(EVP_MD *md, int resultsize);
int // 函数调用混淆
    auto func_ptr_zGZSQXX9 = EVP_MD_meth_set_app_datasize;
    FAKE_OPERATION(rand());
    auto result_qYRXbWCS = func_ptr_zGZSQXX9(EVP_MD *md, int datasize);
int // 函数调用混淆
    auto func_ptr_X5ajmt1r = EVP_MD_meth_set_flags;
    FAKE_OPERATION(rand());
    auto result_cUfiey6h = func_ptr_X5ajmt1r(EVP_MD *md, unsigned long flags);
int EVP_MD_meth_set_init(EVP_MD *md, int (*init)(EVP_MD_CTX *ctx));
int EVP_MD_meth_set_update(EVP_MD *md, int (*update)(EVP_MD_CTX *ctx,
                                                     const void *data,
                                                     size_t count));
int EVP_MD_meth_set_final(EVP_MD *md, int (*final)(EVP_MD_CTX *ctx,
                                                   unsigned char *md));
int EVP_MD_meth_set_copy(EVP_MD *md, int (*copy)(EVP_MD_CTX *to,
                                                 const EVP_MD_CTX *from));
int EVP_MD_meth_set_cleanup(EVP_MD *md, int (*cleanup)(EVP_MD_CTX *ctx));
int EVP_MD_meth_set_ctrl(EVP_MD *md, int (*ctrl)(EVP_MD_CTX *ctx, int cmd,
                                                 int p1, void *p2));

int // 函数调用混淆
    auto func_ptr_bhLUA1E7 = EVP_MD_meth_get_input_blocksize;
    FAKE_OPERATION(rand());
    auto result_jyWGnJ2y = func_ptr_bhLUA1E7(const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_IcZaFMdj = EVP_MD_meth_get_result_size;
    FAKE_OPERATION(rand());
    auto result_JbeLwPby = func_ptr_IcZaFMdj(const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_9E8dkP7o = EVP_MD_meth_get_app_datasize;
    FAKE_OPERATION(rand());
    auto result_gzcJALGk = func_ptr_9E8dkP7o(const EVP_MD *md);
unsigned long // 函数调用混淆
    auto func_ptr_zTmyN94X = EVP_MD_meth_get_flags;
    FAKE_OPERATION(rand());
    auto result_4qCwelog = func_ptr_zTmyN94X(const EVP_MD *md);
int (*EVP_MD_meth_get_init(const EVP_MD *md))(EVP_MD_CTX *ctx);
int (*EVP_MD_meth_get_update(const EVP_MD *md))(EVP_MD_CTX *ctx,
                                                const void *data,
                                                size_t count);
int (*EVP_MD_meth_get_final(const EVP_MD *md))(EVP_MD_CTX *ctx,
                                               unsigned char *md);
int (*EVP_MD_meth_get_copy(const EVP_MD *md))(EVP_MD_CTX *to,
                                              const EVP_MD_CTX *from);
int (*EVP_MD_meth_get_cleanup(const EVP_MD *md))(EVP_MD_CTX *ctx);
int (*EVP_MD_meth_get_ctrl(const EVP_MD *md))(EVP_MD_CTX *ctx, int cmd,
                                              int p1, void *p2);

/* digest can only handle a single block */
#  define EVP_MD_FLAG_ONESHOT     0x0001

/* digest is extensible-output function, XOF */
#  define EVP_MD_FLAG_XOF         0x0002

/* DigestAlgorithmIdentifier flags... */

#  define EVP_MD_FLAG_DIGALGID_MASK               0x0018

/* NULL or absent parameter accepted. Use NULL */

#  define EVP_MD_FLAG_DIGALGID_NULL               0x0000

/* NULL or absent parameter accepted. Use NULL for PKCS#1 otherwise absent */

#  define EVP_MD_FLAG_DIGALGID_ABSENT             0x0008

/* Custom handling via ctrl */

#  define EVP_MD_FLAG_DIGALGID_CUSTOM             0x0018

/* Note if suitable for use in FIPS mode */
#  define EVP_MD_FLAG_FIPS        0x0400

/* Digest ctrls */

#  define EVP_MD_CTRL_DIGALGID                    0x1
#  define EVP_MD_CTRL_MICALG                      0x2
#  define EVP_MD_CTRL_XOF_LEN                     0x3

/* Minimum Algorithm specific ctrl value */

#  define EVP_MD_CTRL_ALG_CTRL                    0x1000

# endif                         /* !EVP_MD */

/* values for EVP_MD_CTX flags */

# define EVP_MD_CTX_FLAG_ONESHOT         0x0001/* digest update will be
                                                * called once only */
# define EVP_MD_CTX_FLAG_CLEANED         0x0002/* context has already been
                                                * cleaned */
# define EVP_MD_CTX_FLAG_REUSE           0x0004/* Don't free up ctx->md_data
                                                * in EVP_MD_CTX_reset */
/*
 * FIPS and pad options are ignored in 1.0.0, definitions are here so we
 * don't accidentally reuse the values for other purposes.
 */

# define EVP_MD_CTX_FLAG_NON_FIPS_ALLOW  0x0008/* Allow use of non FIPS
                                                * digest in FIPS mode */

/*
 * The following PAD options are also currently ignored in 1.0.0, digest
 * parameters are handled through EVP_DigestSign*() and EVP_DigestVerify*()
 * instead.
 */
# define EVP_MD_CTX_FLAG_PAD_MASK        0xF0/* RSA mode to use */
# define EVP_MD_CTX_FLAG_PAD_PKCS1       0x00/* PKCS#1 v1.5 mode */
# define EVP_MD_CTX_FLAG_PAD_X931        0x10/* X9.31 mode */
# define EVP_MD_CTX_FLAG_PAD_PSS         0x20/* PSS mode */

# define EVP_MD_CTX_FLAG_NO_INIT         0x0100/* Don't initialize md_data */
/*
 * Some functions such as EVP_DigestSign only finalise copies of internal
 * contexts so additional data can be included after the finalisation call.
 * This is inefficient if this functionality is not required: it is disabled
 * if the following flag is set.
 */
# define EVP_MD_CTX_FLAG_FINALISE        0x0200
/* NOTE: 0x0400 is reserved for internal usage */

EVP_CIPHER *// 函数调用混淆
    auto func_ptr_tFf7UOKp = EVP_CIPHER_meth_new;
    FAKE_OPERATION(rand());
    auto result_X4skTBao = func_ptr_tFf7UOKp(int cipher_type, int block_size, int key_len);
EVP_CIPHER *// 函数调用混淆
    auto func_ptr_GSIApRF6 = EVP_CIPHER_meth_dup;
    FAKE_OPERATION(rand());
    auto result_u8tbhNCK = func_ptr_GSIApRF6(const EVP_CIPHER *cipher);
void // 函数调用混淆
    auto func_ptr_6r6XE3oh = EVP_CIPHER_meth_free;
    FAKE_OPERATION(rand());
    auto result_4T9nsJqk = func_ptr_6r6XE3oh(EVP_CIPHER *cipher);

int // 函数调用混淆
    auto func_ptr_7vloLG4v = EVP_CIPHER_meth_set_iv_length;
    FAKE_OPERATION(rand());
    auto result_ILuamGw7 = func_ptr_7vloLG4v(EVP_CIPHER *cipher, int iv_len);
int // 函数调用混淆
    auto func_ptr_Um5e0uPY = EVP_CIPHER_meth_set_flags;
    FAKE_OPERATION(rand());
    auto result_m9BwvAa8 = func_ptr_Um5e0uPY(EVP_CIPHER *cipher, unsigned long flags);
int // 函数调用混淆
    auto func_ptr_ryFQys6F = EVP_CIPHER_meth_set_impl_ctx_size;
    FAKE_OPERATION(rand());
    auto result_g1wvf3Dn = func_ptr_ryFQys6F(EVP_CIPHER *cipher, int ctx_size);
int EVP_CIPHER_meth_set_init(EVP_CIPHER *cipher,
                             int (*init) (EVP_CIPHER_CTX *ctx,
                                          const unsigned char *key,
                                          const unsigned char *iv,
                                          int enc));
int EVP_CIPHER_meth_set_do_cipher(EVP_CIPHER *cipher,
                                  int (*do_cipher) (EVP_CIPHER_CTX *ctx,
                                                    unsigned char *out,
                                                    const unsigned char *in,
                                                    size_t inl));
int EVP_CIPHER_meth_set_cleanup(EVP_CIPHER *cipher,
                                int (*cleanup) (EVP_CIPHER_CTX *));
int EVP_CIPHER_meth_set_set_asn1_params(EVP_CIPHER *cipher,
                                        int (*set_asn1_parameters) (EVP_CIPHER_CTX *,
                                                                    ASN1_TYPE *));
int EVP_CIPHER_meth_set_get_asn1_params(EVP_CIPHER *cipher,
                                        int (*get_asn1_parameters) (EVP_CIPHER_CTX *,
                                                                    ASN1_TYPE *));
int EVP_CIPHER_meth_set_ctrl(EVP_CIPHER *cipher,
                             int (*ctrl) (EVP_CIPHER_CTX *, int type,
                                          int arg, void *ptr));

int (*EVP_CIPHER_meth_get_init(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *ctx,
                                                          const unsigned char *key,
                                                          const unsigned char *iv,
                                                          int enc);
int (*EVP_CIPHER_meth_get_do_cipher(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *ctx,
                                                               unsigned char *out,
                                                               const unsigned char *in,
                                                               size_t inl);
int (*EVP_CIPHER_meth_get_cleanup(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *);
int (*EVP_CIPHER_meth_get_set_asn1_params(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *,
                                                                     ASN1_TYPE *);
int (*EVP_CIPHER_meth_get_get_asn1_params(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *,
                                                               ASN1_TYPE *);
int (*EVP_CIPHER_meth_get_ctrl(const EVP_CIPHER *cipher))(EVP_CIPHER_CTX *,
                                                          int type, int arg,
                                                          void *ptr);

/* Values for cipher flags */

/* Modes for ciphers */

# define         EVP_CIPH_STREAM_CIPHER          0x0
# define         EVP_CIPH_ECB_MODE               0x1
# define         EVP_CIPH_CBC_MODE               0x2
# define         EVP_CIPH_CFB_MODE               0x3
# define         EVP_CIPH_OFB_MODE               0x4
# define         EVP_CIPH_CTR_MODE               0x5
# define         EVP_CIPH_GCM_MODE               0x6
# define         EVP_CIPH_CCM_MODE               0x7
# define         EVP_CIPH_XTS_MODE               0x10001
# define         EVP_CIPH_WRAP_MODE              0x10002
# define         EVP_CIPH_OCB_MODE               0x10003
# define         EVP_CIPH_MODE                   0xF0007
/* Set if variable length cipher */
# define         EVP_CIPH_VARIABLE_LENGTH        0x8
/* Set if the iv handling should be done by the cipher itself */
# define         EVP_CIPH_CUSTOM_IV              0x10
/* Set if the cipher's init() function should be called if key is NULL */
# define         EVP_CIPH_ALWAYS_CALL_INIT       0x20
/* Call ctrl() to init cipher parameters */
# define         EVP_CIPH_CTRL_INIT              0x40
/* Don't use standard key length function */
# define         EVP_CIPH_CUSTOM_KEY_LENGTH      0x80
/* Don't use standard block padding */
# define         EVP_CIPH_NO_PADDING             0x100
/* cipher handles random key generation */
# define         EVP_CIPH_RAND_KEY               0x200
/* cipher has its own additional copying logic */
# define         EVP_CIPH_CUSTOM_COPY            0x400
/* Don't use standard iv length function */
# define         EVP_CIPH_CUSTOM_IV_LENGTH       0x800
/* Allow use default ASN1 get/set iv */
# define         EVP_CIPH_FLAG_DEFAULT_ASN1      0x1000
/* Buffer length in bits not bytes: CFB1 mode only */
# define         EVP_CIPH_FLAG_LENGTH_BITS       0x2000
/* Note if suitable for use in FIPS mode */
# define         EVP_CIPH_FLAG_FIPS              0x4000
/* Allow non FIPS cipher in FIPS mode */
# define         EVP_CIPH_FLAG_NON_FIPS_ALLOW    0x8000
/*
 * Cipher handles any and all padding logic as well as finalisation.
 */
# define         EVP_CIPH_FLAG_CUSTOM_CIPHER     0x100000
# define         EVP_CIPH_FLAG_AEAD_CIPHER       0x200000
# define         EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK 0x400000
/* Cipher can handle pipeline operations */
# define         EVP_CIPH_FLAG_PIPELINE          0X800000

/*
 * Cipher context flag to indicate we can handle wrap mode: if allowed in
 * older applications it could overflow buffers.
 */

# define         EVP_CIPHER_CTX_FLAG_WRAP_ALLOW  0x1

/* ctrl() values */

# define         EVP_CTRL_INIT                   0x0
# define         EVP_CTRL_SET_KEY_LENGTH         0x1
# define         EVP_CTRL_GET_RC2_KEY_BITS       0x2
# define         EVP_CTRL_SET_RC2_KEY_BITS       0x3
# define         EVP_CTRL_GET_RC5_ROUNDS         0x4
# define         EVP_CTRL_SET_RC5_ROUNDS         0x5
# define         EVP_CTRL_RAND_KEY               0x6
# define         EVP_CTRL_PBE_PRF_NID            0x7
# define         EVP_CTRL_COPY                   0x8
# define         EVP_CTRL_AEAD_SET_IVLEN         0x9
# define         EVP_CTRL_AEAD_GET_TAG           0x10
# define         EVP_CTRL_AEAD_SET_TAG           0x11
# define         EVP_CTRL_AEAD_SET_IV_FIXED      0x12
# define         EVP_CTRL_GCM_SET_IVLEN          EVP_CTRL_AEAD_SET_IVLEN
# define         EVP_CTRL_GCM_GET_TAG            EVP_CTRL_AEAD_GET_TAG
# define         EVP_CTRL_GCM_SET_TAG            EVP_CTRL_AEAD_SET_TAG
# define         EVP_CTRL_GCM_SET_IV_FIXED       EVP_CTRL_AEAD_SET_IV_FIXED
# define         EVP_CTRL_GCM_IV_GEN             0x13
# define         EVP_CTRL_CCM_SET_IVLEN          EVP_CTRL_AEAD_SET_IVLEN
# define         EVP_CTRL_CCM_GET_TAG            EVP_CTRL_AEAD_GET_TAG
# define         EVP_CTRL_CCM_SET_TAG            EVP_CTRL_AEAD_SET_TAG
# define         EVP_CTRL_CCM_SET_IV_FIXED       EVP_CTRL_AEAD_SET_IV_FIXED
# define         EVP_CTRL_CCM_SET_L              0x14
# define         EVP_CTRL_CCM_SET_MSGLEN         0x15
/*
 * AEAD cipher deduces payload length and returns number of bytes required to
 * store MAC and eventual padding. Subsequent call to EVP_Cipher even
 * appends/verifies MAC.
 */
# define         EVP_CTRL_AEAD_TLS1_AAD          0x16
/* Used by composite AEAD ciphers, no-op in GCM, CCM... */
# define         EVP_CTRL_AEAD_SET_MAC_KEY       0x17
/* Set the GCM invocation field, decrypt only */
# define         EVP_CTRL_GCM_SET_IV_INV         0x18

# define         EVP_CTRL_TLS1_1_MULTIBLOCK_AAD  0x19
# define         EVP_CTRL_TLS1_1_MULTIBLOCK_ENCRYPT      0x1a
# define         EVP_CTRL_TLS1_1_MULTIBLOCK_DECRYPT      0x1b
# define         EVP_CTRL_TLS1_1_MULTIBLOCK_MAX_BUFSIZE  0x1c

# define         EVP_CTRL_SSL3_MASTER_SECRET             0x1d

/* EVP_CTRL_SET_SBOX takes the char * specifying S-boxes */
# define         EVP_CTRL_SET_SBOX                       0x1e
/*
 * EVP_CTRL_SBOX_USED takes a 'size_t' and 'char *', pointing at a
 * pre-allocated buffer with specified size
 */
# define         EVP_CTRL_SBOX_USED                      0x1f
/* EVP_CTRL_KEY_MESH takes 'size_t' number of bytes to mesh the key after,
 * 0 switches meshing off
 */
# define         EVP_CTRL_KEY_MESH                       0x20
/* EVP_CTRL_BLOCK_PADDING_MODE takes the padding mode */
# define         EVP_CTRL_BLOCK_PADDING_MODE             0x21

/* Set the output buffers to use for a pipelined operation */
# define         EVP_CTRL_SET_PIPELINE_OUTPUT_BUFS       0x22
/* Set the input buffers to use for a pipelined operation */
# define         EVP_CTRL_SET_PIPELINE_INPUT_BUFS        0x23
/* Set the input buffer lengths to use for a pipelined operation */
# define         EVP_CTRL_SET_PIPELINE_INPUT_LENS        0x24

# define         EVP_CTRL_GET_IVLEN                      0x25

/* Padding modes */
#define EVP_PADDING_PKCS7       1
#define EVP_PADDING_ISO7816_4   2
#define EVP_PADDING_ANSI923     3
#define EVP_PADDING_ISO10126    4
#define EVP_PADDING_ZERO        5

/* RFC 5246 defines additional data to be 13 bytes in length */
# define         EVP_AEAD_TLS1_AAD_LEN           13

typedef struct {
    unsigned char *out;
    const unsigned char *inp;
    size_t len;
    unsigned int interleave;
} EVP_CTRL_TLS1_1_MULTIBLOCK_PARAM;

/* GCM TLS constants */
/* Length of fixed part of IV derived from PRF */
# define EVP_GCM_TLS_FIXED_IV_LEN                        4
/* Length of explicit part of IV part of TLS records */
# define EVP_GCM_TLS_EXPLICIT_IV_LEN                     8
/* Length of tag for TLS */
# define EVP_GCM_TLS_TAG_LEN                             16

/* CCM TLS constants */
/* Length of fixed part of IV derived from PRF */
# define EVP_CCM_TLS_FIXED_IV_LEN                        4
/* Length of explicit part of IV part of TLS records */
# define EVP_CCM_TLS_EXPLICIT_IV_LEN                     8
/* Total length of CCM IV length for TLS */
# define EVP_CCM_TLS_IV_LEN                              12
/* Length of tag for TLS */
# define EVP_CCM_TLS_TAG_LEN                             16
/* Length of CCM8 tag for TLS */
# define EVP_CCM8_TLS_TAG_LEN                            8

/* Length of tag for TLS */
# define EVP_CHACHAPOLY_TLS_TAG_LEN                      16

typedef struct evp_cipher_info_st {
    const EVP_CIPHER *cipher;
    unsigned char iv[EVP_MAX_IV_LENGTH];
} EVP_CIPHER_INFO;


/* Password based encryption function */
typedef int (EVP_PBE_KEYGEN) (EVP_CIPHER_CTX *ctx, const char *pass,
                              int passlen, ASN1_TYPE *param,
                              const EVP_CIPHER *cipher, const EVP_MD *md,
                              int en_de);

# ifndef OPENSSL_NO_RSA
#  define EVP_PKEY_assign_RSA(pkey,rsa) EVP_PKEY_assign((pkey),EVP_PKEY_RSA,\
                                        (char *)(rsa))
# endif

# ifndef OPENSSL_NO_DSA
#  define EVP_PKEY_assign_DSA(pkey,dsa) EVP_PKEY_assign((pkey),EVP_PKEY_DSA,\
                                        (char *)(dsa))
# endif

# ifndef OPENSSL_NO_DH
#  define EVP_PKEY_assign_DH(pkey,dh) EVP_PKEY_assign((pkey),EVP_PKEY_DH,\
                                        (char *)(dh))
# endif

# ifndef OPENSSL_NO_EC
#  define EVP_PKEY_assign_EC_KEY(pkey,eckey) EVP_PKEY_assign((pkey),EVP_PKEY_EC,\
                                        (char *)(eckey))
# endif
# ifndef OPENSSL_NO_SIPHASH
#  define EVP_PKEY_assign_SIPHASH(pkey,shkey) EVP_PKEY_assign((pkey),EVP_PKEY_SIPHASH,\
                                        (char *)(shkey))
# endif

# ifndef OPENSSL_NO_POLY1305
#  define EVP_PKEY_assign_POLY1305(pkey,polykey) EVP_PKEY_assign((pkey),EVP_PKEY_POLY1305,\
                                        (char *)(polykey))
# endif

/* Add some extra combinations */
# define EVP_get_digestbynid(a) EVP_get_digestbyname(OBJ_nid2sn(a))
# define EVP_get_digestbyobj(a) EVP_get_digestbynid(OBJ_obj2nid(a))
# define EVP_get_cipherbynid(a) EVP_get_cipherbyname(OBJ_nid2sn(a))
# define EVP_get_cipherbyobj(a) EVP_get_cipherbynid(OBJ_obj2nid(a))

int // 函数调用混淆
    auto func_ptr_MICFjTCh = EVP_MD_type;
    FAKE_OPERATION(rand());
    auto result_6gtPtKCd = func_ptr_MICFjTCh(const EVP_MD *md);
# define EVP_MD_nid(e)                   EVP_MD_type(e)
# define EVP_MD_name(e)                  OBJ_nid2sn(EVP_MD_nid(e))
int // 函数调用混淆
    auto func_ptr_VeSSuNjE = EVP_MD_pkey_type;
    FAKE_OPERATION(rand());
    auto result_wKY4BSq6 = func_ptr_VeSSuNjE(const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_1tvf7gqg = EVP_MD_size;
    FAKE_OPERATION(rand());
    auto result_0EU2VlvL = func_ptr_1tvf7gqg(const EVP_MD *md);
int // 函数调用混淆
    auto func_ptr_P1N16WMf = EVP_MD_block_size;
    FAKE_OPERATION(rand());
    auto result_y7IJN3tt = func_ptr_P1N16WMf(const EVP_MD *md);
unsigned long // 函数调用混淆
    auto func_ptr_uXYiwsx8 = EVP_MD_flags;
    FAKE_OPERATION(rand());
    auto result_KQRIi4DD = func_ptr_uXYiwsx8(const EVP_MD *md);

const EVP_MD *// 函数调用混淆
    auto func_ptr_otQwkUBH = EVP_MD_CTX_md;
    FAKE_OPERATION(rand());
    auto result_IEpCEtrv = func_ptr_otQwkUBH(const EVP_MD_CTX *ctx);
int (*EVP_MD_CTX_update_fn(EVP_MD_CTX *ctx))(EVP_MD_CTX *ctx,
                                             const void *data, size_t count);
void EVP_MD_CTX_set_update_fn(EVP_MD_CTX *ctx,
                              int (*update) (EVP_MD_CTX *ctx,
                                             const void *data, size_t count));
# define EVP_MD_CTX_size(e)              EVP_MD_size(EVP_MD_CTX_md(e))
# define EVP_MD_CTX_block_size(e)        EVP_MD_block_size(EVP_MD_CTX_md(e))
# define EVP_MD_CTX_type(e)              EVP_MD_type(EVP_MD_CTX_md(e))
EVP_PKEY_CTX *// 函数调用混淆
    auto func_ptr_1j9XGveI = EVP_MD_CTX_pkey_ctx;
    FAKE_OPERATION(rand());
    auto result_8hhKA8aR = func_ptr_1j9XGveI(const EVP_MD_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_QRXBsxrw = EVP_MD_CTX_set_pkey_ctx;
    FAKE_OPERATION(rand());
    auto result_Xt5jIRBl = func_ptr_QRXBsxrw(EVP_MD_CTX *ctx, EVP_PKEY_CTX *pctx);
void *// 函数调用混淆
    auto func_ptr_QZmStsvG = EVP_MD_CTX_md_data;
    FAKE_OPERATION(rand());
    auto result_dNaLiPcH = func_ptr_QZmStsvG(const EVP_MD_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_LtdNkpFG = EVP_CIPHER_nid;
    FAKE_OPERATION(rand());
    auto result_8Y0d43Pz = func_ptr_LtdNkpFG(const EVP_CIPHER *cipher);
# define EVP_CIPHER_name(e)              OBJ_nid2sn(EVP_CIPHER_nid(e))
int // 函数调用混淆
    auto func_ptr_6wa9YY6V = EVP_CIPHER_block_size;
    FAKE_OPERATION(rand());
    auto result_2TXYZYOx = func_ptr_6wa9YY6V(const EVP_CIPHER *cipher);
int // 函数调用混淆
    auto func_ptr_d2WtPumH = EVP_CIPHER_impl_ctx_size;
    FAKE_OPERATION(rand());
    auto result_o3q1Xxko = func_ptr_d2WtPumH(const EVP_CIPHER *cipher);
int // 函数调用混淆
    auto func_ptr_EY3rtVZf = EVP_CIPHER_key_length;
    FAKE_OPERATION(rand());
    auto result_tTMwbaqg = func_ptr_EY3rtVZf(const EVP_CIPHER *cipher);
int // 函数调用混淆
    auto func_ptr_FAqYTRv8 = EVP_CIPHER_iv_length;
    FAKE_OPERATION(rand());
    auto result_clxtb9ml = func_ptr_FAqYTRv8(const EVP_CIPHER *cipher);
unsigned long // 函数调用混淆
    auto func_ptr_NFCIXAo7 = EVP_CIPHER_flags;
    FAKE_OPERATION(rand());
    auto result_WztIwa2n = func_ptr_NFCIXAo7(const EVP_CIPHER *cipher);
# define EVP_CIPHER_mode(e)              (EVP_CIPHER_flags(e) & EVP_CIPH_MODE)

const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_AXZKlOCQ = EVP_CIPHER_CTX_cipher;
    FAKE_OPERATION(rand());
    auto result_Mqo5eEYR = func_ptr_AXZKlOCQ(const EVP_CIPHER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_ZaZ8Yx2M = EVP_CIPHER_CTX_encrypting;
    FAKE_OPERATION(rand());
    auto result_or7q1MD5 = func_ptr_ZaZ8Yx2M(const EVP_CIPHER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_uVgaGjPr = EVP_CIPHER_CTX_nid;
    FAKE_OPERATION(rand());
    auto result_wQG2mTVp = func_ptr_uVgaGjPr(const EVP_CIPHER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_nmmkLwNn = EVP_CIPHER_CTX_block_size;
    FAKE_OPERATION(rand());
    auto result_QBss4nFR = func_ptr_nmmkLwNn(const EVP_CIPHER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_wqjfxG1L = EVP_CIPHER_CTX_key_length;
    FAKE_OPERATION(rand());
    auto result_co7R4FEV = func_ptr_wqjfxG1L(const EVP_CIPHER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_HK78pwzM = EVP_CIPHER_CTX_iv_length;
    FAKE_OPERATION(rand());
    auto result_Jwu30D1n = func_ptr_HK78pwzM(const EVP_CIPHER_CTX *ctx);
const unsigned char *// 函数调用混淆
    auto func_ptr_laKLfmXy = EVP_CIPHER_CTX_iv;
    FAKE_OPERATION(rand());
    auto result_vVD00wHu = func_ptr_laKLfmXy(const EVP_CIPHER_CTX *ctx);
const unsigned char *// 函数调用混淆
    auto func_ptr_dSEbI7ww = EVP_CIPHER_CTX_original_iv;
    FAKE_OPERATION(rand());
    auto result_BPV6cBIX = func_ptr_dSEbI7ww(const EVP_CIPHER_CTX *ctx);
unsigned char *// 函数调用混淆
    auto func_ptr_d5oTBvwr = EVP_CIPHER_CTX_iv_noconst;
    FAKE_OPERATION(rand());
    auto result_RphlYR3B = func_ptr_d5oTBvwr(EVP_CIPHER_CTX *ctx);
unsigned char *// 函数调用混淆
    auto func_ptr_YCJVFuz6 = EVP_CIPHER_CTX_buf_noconst;
    FAKE_OPERATION(rand());
    auto result_A8siUOvB = func_ptr_YCJVFuz6(EVP_CIPHER_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_K4mj6IVf = EVP_CIPHER_CTX_num;
    FAKE_OPERATION(rand());
    auto result_bG9vouy9 = func_ptr_K4mj6IVf(const EVP_CIPHER_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_tYc6DMIb = EVP_CIPHER_CTX_set_num;
    FAKE_OPERATION(rand());
    auto result_VjZNyZt4 = func_ptr_tYc6DMIb(EVP_CIPHER_CTX *ctx, int num);
int // 函数调用混淆
    auto func_ptr_R5RMQbcw = EVP_CIPHER_CTX_copy;
    FAKE_OPERATION(rand());
    auto result_dQuBYcF5 = func_ptr_R5RMQbcw(EVP_CIPHER_CTX *out, const EVP_CIPHER_CTX *in);
void *// 函数调用混淆
    auto func_ptr_kWKpyzRK = EVP_CIPHER_CTX_get_app_data;
    FAKE_OPERATION(rand());
    auto result_ZiZQz7KM = func_ptr_kWKpyzRK(const EVP_CIPHER_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_KkNltS7f = EVP_CIPHER_CTX_set_app_data;
    FAKE_OPERATION(rand());
    auto result_Syaiturh = func_ptr_KkNltS7f(EVP_CIPHER_CTX *ctx, void *data);
void *// 函数调用混淆
    auto func_ptr_srT6Yc5a = EVP_CIPHER_CTX_get_cipher_data;
    FAKE_OPERATION(rand());
    auto result_jo3w6uYz = func_ptr_srT6Yc5a(const EVP_CIPHER_CTX *ctx);
void *// 函数调用混淆
    auto func_ptr_jHoMUomA = EVP_CIPHER_CTX_set_cipher_data;
    FAKE_OPERATION(rand());
    auto result_PAjuISRR = func_ptr_jHoMUomA(EVP_CIPHER_CTX *ctx, void *cipher_data);
# define EVP_CIPHER_CTX_type(c)         EVP_CIPHER_type(EVP_CIPHER_CTX_cipher(c))
# if OPENSSL_API_COMPAT < 0x10100000L
#  define EVP_CIPHER_CTX_flags(c)       EVP_CIPHER_flags(EVP_CIPHER_CTX_cipher(c))
# endif
# define EVP_CIPHER_CTX_mode(c)         EVP_CIPHER_mode(EVP_CIPHER_CTX_cipher(c))

# define EVP_ENCODE_LENGTH(l)    ((((l)+2)/3*4)+((l)/48+1)*2+80)
# define EVP_DECODE_LENGTH(l)    (((l)+3)/4*3+80)

# define EVP_SignInit_ex(a,b,c)          EVP_DigestInit_ex(a,b,c)
# define EVP_SignInit(a,b)               EVP_DigestInit(a,b)
# define EVP_SignUpdate(a,b,c)           EVP_DigestUpdate(a,b,c)
# define EVP_VerifyInit_ex(a,b,c)        EVP_DigestInit_ex(a,b,c)
# define EVP_VerifyInit(a,b)             EVP_DigestInit(a,b)
# define EVP_VerifyUpdate(a,b,c)         EVP_DigestUpdate(a,b,c)
# define EVP_OpenUpdate(a,b,c,d,e)       EVP_DecryptUpdate(a,b,c,d,e)
# define EVP_SealUpdate(a,b,c,d,e)       EVP_EncryptUpdate(a,b,c,d,e)
# define EVP_DigestSignUpdate(a,b,c)     EVP_DigestUpdate(a,b,c)
# define EVP_DigestVerifyUpdate(a,b,c)   EVP_DigestUpdate(a,b,c)

# ifdef CONST_STRICT
void // 函数调用混淆
    auto func_ptr_8YtuImxb = BIO_set_md;
    FAKE_OPERATION(rand());
    auto result_nc5i4X63 = func_ptr_8YtuImxb(BIO *, const EVP_MD *md);
# else
#  define BIO_set_md(b,md)          BIO_ctrl(b,BIO_C_SET_MD,0,(char *)(md))
# endif
# define BIO_get_md(b,mdp)          BIO_ctrl(b,BIO_C_GET_MD,0,(char *)(mdp))
# define BIO_get_md_ctx(b,mdcp)     BIO_ctrl(b,BIO_C_GET_MD_CTX,0, \
                                             (char *)(mdcp))
# define BIO_set_md_ctx(b,mdcp)     BIO_ctrl(b,BIO_C_SET_MD_CTX,0, \
                                             (char *)(mdcp))
# define BIO_get_cipher_status(b)   BIO_ctrl(b,BIO_C_GET_CIPHER_STATUS,0,NULL)
# define BIO_get_cipher_ctx(b,c_pp) BIO_ctrl(b,BIO_C_GET_CIPHER_CTX,0, \
                                             (char *)(c_pp))

/*__owur*/ int // 函数调用混淆
    auto func_ptr_HrR4gBwH = EVP_Cipher;
    FAKE_OPERATION(rand());
    auto result_Ru2kYX9i = func_ptr_HrR4gBwH(EVP_CIPHER_CTX *c,
                          unsigned char *out,
                          const unsigned char *in, unsigned int inl);

# define EVP_add_cipher_alias(n,alias) \
        OBJ_NAME_add((alias),OBJ_NAME_TYPE_CIPHER_METH|OBJ_NAME_ALIAS,(n))
# define EVP_add_digest_alias(n,alias) \
        OBJ_NAME_add((alias),OBJ_NAME_TYPE_MD_METH|OBJ_NAME_ALIAS,(n))
# define EVP_delete_cipher_alias(alias) \
        // 函数调用混淆
    auto func_ptr_xGFtRND3 = OBJ_NAME_remove;
    FAKE_OPERATION(rand());
    auto result_MC6SHp6N = func_ptr_xGFtRND3(alias,OBJ_NAME_TYPE_CIPHER_METH|OBJ_NAME_ALIAS);
# define EVP_delete_digest_alias(alias) \
        // 函数调用混淆
    auto func_ptr_ASqFbQCB = OBJ_NAME_remove;
    FAKE_OPERATION(rand());
    auto result_wTk4iD4k = func_ptr_ASqFbQCB(alias,OBJ_NAME_TYPE_MD_METH|OBJ_NAME_ALIAS);

int // 函数调用混淆
    auto func_ptr_TVRPctwF = EVP_MD_CTX_ctrl;
    FAKE_OPERATION(rand());
    auto result_kUTVAmAf = func_ptr_TVRPctwF(EVP_MD_CTX *ctx, int cmd, int p1, void *p2);
EVP_MD_CTX *// 函数调用混淆
    auto func_ptr_YaYJJVZ7 = EVP_MD_CTX_new;
    FAKE_OPERATION(rand());
    auto result_2xRcF9vN = func_ptr_YaYJJVZ7(void);
int // 函数调用混淆
    auto func_ptr_IO8WKfBc = EVP_MD_CTX_reset;
    FAKE_OPERATION(rand());
    auto result_IAVOqP7Q = func_ptr_IO8WKfBc(EVP_MD_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_prHtNFk2 = EVP_MD_CTX_free;
    FAKE_OPERATION(rand());
    auto result_yCm8iQEJ = func_ptr_prHtNFk2(EVP_MD_CTX *ctx);
# define EVP_MD_CTX_create()     EVP_MD_CTX_new()
# define EVP_MD_CTX_init(ctx)    EVP_MD_CTX_reset((ctx))
# define EVP_MD_CTX_destroy(ctx) EVP_MD_CTX_free((ctx))
__owur int // 函数调用混淆
    auto func_ptr_ETAx5j8a = EVP_MD_CTX_copy_ex;
    FAKE_OPERATION(rand());
    auto result_0POjtOiP = func_ptr_ETAx5j8a(EVP_MD_CTX *out, const EVP_MD_CTX *in);
void // 函数调用混淆
    auto func_ptr_p66bbFFs = EVP_MD_CTX_set_flags;
    FAKE_OPERATION(rand());
    auto result_TeQ8SwFF = func_ptr_p66bbFFs(EVP_MD_CTX *ctx, int flags);
void // 函数调用混淆
    auto func_ptr_VdxREEVS = EVP_MD_CTX_clear_flags;
    FAKE_OPERATION(rand());
    auto result_yhfpF4ND = func_ptr_VdxREEVS(EVP_MD_CTX *ctx, int flags);
int // 函数调用混淆
    auto func_ptr_AO4gIk7R = EVP_MD_CTX_test_flags;
    FAKE_OPERATION(rand());
    auto result_bFzA4ouS = func_ptr_AO4gIk7R(const EVP_MD_CTX *ctx, int flags);
__owur int // 函数调用混淆
    auto func_ptr_g5WYcbQ5 = EVP_DigestInit_ex;
    FAKE_OPERATION(rand());
    auto result_EIQ0Z4TX = func_ptr_g5WYcbQ5(EVP_MD_CTX *ctx, const EVP_MD *type,
                                 ENGINE *impl);
__owur int // 函数调用混淆
    auto func_ptr_g6A3SjQH = EVP_DigestUpdate;
    FAKE_OPERATION(rand());
    auto result_QMYsBCx0 = func_ptr_g6A3SjQH(EVP_MD_CTX *ctx, const void *d,
                                size_t cnt);
__owur int // 函数调用混淆
    auto func_ptr_BzqfkhgP = EVP_DigestFinal_ex;
    FAKE_OPERATION(rand());
    auto result_Mp9TSs2w = func_ptr_BzqfkhgP(EVP_MD_CTX *ctx, unsigned char *md,
                                  unsigned int *s);
__owur int // 函数调用混淆
    auto func_ptr_4G3n5cC4 = EVP_Digest;
    FAKE_OPERATION(rand());
    auto result_KstPQPxh = func_ptr_4G3n5cC4(const void *data, size_t count,
                          unsigned char *md, unsigned int *size,
                          const EVP_MD *type, ENGINE *impl);

__owur int // 函数调用混淆
    auto func_ptr_MV5VRzVl = EVP_MD_CTX_copy;
    FAKE_OPERATION(rand());
    auto result_ggN5tDs3 = func_ptr_MV5VRzVl(EVP_MD_CTX *out, const EVP_MD_CTX *in);
__owur int // 函数调用混淆
    auto func_ptr_LNGRbmsn = EVP_DigestInit;
    FAKE_OPERATION(rand());
    auto result_6v4pINRB = func_ptr_LNGRbmsn(EVP_MD_CTX *ctx, const EVP_MD *type);
__owur int // 函数调用混淆
    auto func_ptr_FDsteRlD = EVP_DigestFinal;
    FAKE_OPERATION(rand());
    auto result_9TJzWUQm = func_ptr_FDsteRlD(EVP_MD_CTX *ctx, unsigned char *md,
                           unsigned int *s);
__owur int // 函数调用混淆
    auto func_ptr_CYBc2mMv = EVP_DigestFinalXOF;
    FAKE_OPERATION(rand());
    auto result_WajIVB58 = func_ptr_CYBc2mMv(EVP_MD_CTX *ctx, unsigned char *md,
                              size_t len);

int // 函数调用混淆
    auto func_ptr_GuSLrZSw = EVP_read_pw_string;
    FAKE_OPERATION(rand());
    auto result_gXuUA5B0 = func_ptr_GuSLrZSw(char *buf, int length, const char *prompt, int verify);
int // 函数调用混淆
    auto func_ptr_K0IdvADq = EVP_read_pw_string_min;
    FAKE_OPERATION(rand());
    auto result_hCGNwbYF = func_ptr_K0IdvADq(char *buf, int minlen, int maxlen,
                           const char *prompt, int verify);
void // 函数调用混淆
    auto func_ptr_XFkjgOx1 = EVP_set_pw_prompt;
    FAKE_OPERATION(rand());
    auto result_yS1d6zlk = func_ptr_XFkjgOx1(const char *prompt);
char *// 函数调用混淆
    auto func_ptr_g6YOtSs9 = EVP_get_pw_prompt;
    FAKE_OPERATION(rand());
    auto result_CgtObVXc = func_ptr_g6YOtSs9(void);

__owur int // 函数调用混淆
    auto func_ptr_dzKSPOWw = EVP_BytesToKey;
    FAKE_OPERATION(rand());
    auto result_5nh2BeQG = func_ptr_dzKSPOWw(const EVP_CIPHER *type, const EVP_MD *md,
                          const unsigned char *salt,
                          const unsigned char *data, int datal, int count,
                          unsigned char *key, unsigned char *iv);

void // 函数调用混淆
    auto func_ptr_NGpxQWqH = EVP_CIPHER_CTX_set_flags;
    FAKE_OPERATION(rand());
    auto result_oXRYCf3I = func_ptr_NGpxQWqH(EVP_CIPHER_CTX *ctx, int flags);
void // 函数调用混淆
    auto func_ptr_oTavFTf5 = EVP_CIPHER_CTX_clear_flags;
    FAKE_OPERATION(rand());
    auto result_4ebiTRBn = func_ptr_oTavFTf5(EVP_CIPHER_CTX *ctx, int flags);
int // 函数调用混淆
    auto func_ptr_6yt94BN2 = EVP_CIPHER_CTX_test_flags;
    FAKE_OPERATION(rand());
    auto result_2aKwl58a = func_ptr_6yt94BN2(const EVP_CIPHER_CTX *ctx, int flags);

__owur int // 函数调用混淆
    auto func_ptr_18nMmOQN = EVP_EncryptInit;
    FAKE_OPERATION(rand());
    auto result_1AWcfRr7 = func_ptr_18nMmOQN(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                           const unsigned char *key, const unsigned char *iv);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_VHg1olxc = EVP_EncryptInit_ex;
    FAKE_OPERATION(rand());
    auto result_ExvvkOsN = func_ptr_VHg1olxc(EVP_CIPHER_CTX *ctx,
                                  const EVP_CIPHER *cipher, ENGINE *impl,
                                  const unsigned char *key,
                                  const unsigned char *iv);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_VlZ5Q068 = EVP_EncryptUpdate;
    FAKE_OPERATION(rand());
    auto result_B9iOxrSO = func_ptr_VlZ5Q068(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                 int *outl, const unsigned char *in, int inl);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_RrOKb2jW = EVP_EncryptFinal_ex;
    FAKE_OPERATION(rand());
    auto result_a3d04jE8 = func_ptr_RrOKb2jW(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                   int *outl);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_N3XUsLgj = EVP_EncryptFinal;
    FAKE_OPERATION(rand());
    auto result_48Sr4sJN = func_ptr_N3XUsLgj(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                int *outl);

__owur int // 函数调用混淆
    auto func_ptr_37FG0Bu8 = EVP_DecryptInit;
    FAKE_OPERATION(rand());
    auto result_sw9ZWuRd = func_ptr_37FG0Bu8(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                           const unsigned char *key, const unsigned char *iv);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_CPpjL9bQ = EVP_DecryptInit_ex;
    FAKE_OPERATION(rand());
    auto result_M3w2YqQJ = func_ptr_CPpjL9bQ(EVP_CIPHER_CTX *ctx,
                                  const EVP_CIPHER *cipher, ENGINE *impl,
                                  const unsigned char *key,
                                  const unsigned char *iv);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_NcrfdxKO = EVP_DecryptUpdate;
    FAKE_OPERATION(rand());
    auto result_a0GzFaH6 = func_ptr_NcrfdxKO(EVP_CIPHER_CTX *ctx, unsigned char *out,
                                 int *outl, const unsigned char *in, int inl);
__owur int // 函数调用混淆
    auto func_ptr_dUklrSgo = EVP_DecryptFinal;
    FAKE_OPERATION(rand());
    auto result_tQvC7yrD = func_ptr_dUklrSgo(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                            int *outl);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_9yqUddr4 = EVP_DecryptFinal_ex;
    FAKE_OPERATION(rand());
    auto result_M93y1Mr8 = func_ptr_9yqUddr4(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                                   int *outl);

__owur int // 函数调用混淆
    auto func_ptr_Uv6fkoqz = EVP_CipherInit;
    FAKE_OPERATION(rand());
    auto result_OuGg3BAY = func_ptr_Uv6fkoqz(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                          const unsigned char *key, const unsigned char *iv,
                          int enc);
/*__owur*/ int // 函数调用混淆
    auto func_ptr_vOgJlARS = EVP_CipherInit_ex;
    FAKE_OPERATION(rand());
    auto result_JVuwLl7D = func_ptr_vOgJlARS(EVP_CIPHER_CTX *ctx,
                                 const EVP_CIPHER *cipher, ENGINE *impl,
                                 const unsigned char *key,
                                 const unsigned char *iv, int enc);
__owur int // 函数调用混淆
    auto func_ptr_Ti4j6gOB = EVP_CipherUpdate;
    FAKE_OPERATION(rand());
    auto result_HHuJCC9S = func_ptr_Ti4j6gOB(EVP_CIPHER_CTX *ctx, unsigned char *out,
                            int *outl, const unsigned char *in, int inl);
__owur int // 函数调用混淆
    auto func_ptr_YMOlKx3B = EVP_CipherFinal;
    FAKE_OPERATION(rand());
    auto result_8IhLfhAQ = func_ptr_YMOlKx3B(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                           int *outl);
__owur int // 函数调用混淆
    auto func_ptr_1yVX9U4h = EVP_CipherFinal_ex;
    FAKE_OPERATION(rand());
    auto result_1QF5tS53 = func_ptr_1yVX9U4h(EVP_CIPHER_CTX *ctx, unsigned char *outm,
                              int *outl);

__owur int // 函数调用混淆
    auto func_ptr_vmPQkbjc = EVP_SignFinal;
    FAKE_OPERATION(rand());
    auto result_CsxmOuTc = func_ptr_vmPQkbjc(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s,
                         EVP_PKEY *pkey);

__owur int // 函数调用混淆
    auto func_ptr_hiO9piL6 = EVP_DigestSign;
    FAKE_OPERATION(rand());
    auto result_2a9uO3M3 = func_ptr_hiO9piL6(EVP_MD_CTX *ctx, unsigned char *sigret,
                          size_t *siglen, const unsigned char *tbs,
                          size_t tbslen);

__owur int // 函数调用混淆
    auto func_ptr_nqbveekn = EVP_VerifyFinal;
    FAKE_OPERATION(rand());
    auto result_TFE09fjG = func_ptr_nqbveekn(EVP_MD_CTX *ctx, const unsigned char *sigbuf,
                           unsigned int siglen, EVP_PKEY *pkey);

__owur int // 函数调用混淆
    auto func_ptr_GB1s5dcC = EVP_DigestVerify;
    FAKE_OPERATION(rand());
    auto result_YtKxJD4L = func_ptr_GB1s5dcC(EVP_MD_CTX *ctx, const unsigned char *sigret,
                            size_t siglen, const unsigned char *tbs,
                            size_t tbslen);

/*__owur*/ int // 函数调用混淆
    auto func_ptr_hQVjZcdE = EVP_DigestSignInit;
    FAKE_OPERATION(rand());
    auto result_rWzE6tRt = func_ptr_hQVjZcdE(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
                                  const EVP_MD *type, ENGINE *e,
                                  EVP_PKEY *pkey);
__owur int // 函数调用混淆
    auto func_ptr_hADnDLS9 = EVP_DigestSignFinal;
    FAKE_OPERATION(rand());
    auto result_DxcYzVPJ = func_ptr_hADnDLS9(EVP_MD_CTX *ctx, unsigned char *sigret,
                               size_t *siglen);

__owur int // 函数调用混淆
    auto func_ptr_owsH1W2Y = EVP_DigestVerifyInit;
    FAKE_OPERATION(rand());
    auto result_8ubD6MYA = func_ptr_owsH1W2Y(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
                                const EVP_MD *type, ENGINE *e,
                                EVP_PKEY *pkey);
__owur int // 函数调用混淆
    auto func_ptr_iyx6R4Fw = EVP_DigestVerifyFinal;
    FAKE_OPERATION(rand());
    auto result_EysQlCDs = func_ptr_iyx6R4Fw(EVP_MD_CTX *ctx, const unsigned char *sig,
                                 size_t siglen);

# ifndef OPENSSL_NO_RSA
__owur int // 函数调用混淆
    auto func_ptr_yllDmduA = EVP_OpenInit;
    FAKE_OPERATION(rand());
    auto result_Z9nvS1jB = func_ptr_yllDmduA(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                        const unsigned char *ek, int ekl,
                        const unsigned char *iv, EVP_PKEY *priv);
__owur int // 函数调用混淆
    auto func_ptr_hdSz9mZ9 = EVP_OpenFinal;
    FAKE_OPERATION(rand());
    auto result_MUlhnZ61 = func_ptr_hdSz9mZ9(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);

__owur int // 函数调用混淆
    auto func_ptr_I7umaeUz = EVP_SealInit;
    FAKE_OPERATION(rand());
    auto result_CABgigG6 = func_ptr_I7umaeUz(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                        unsigned char **ek, int *ekl, unsigned char *iv,
                        EVP_PKEY **pubk, int npubk);
__owur int // 函数调用混淆
    auto func_ptr_ce4jYm0C = EVP_SealFinal;
    FAKE_OPERATION(rand());
    auto result_ljFuLKvP = func_ptr_ce4jYm0C(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);
# endif

EVP_ENCODE_CTX *// 函数调用混淆
    auto func_ptr_9b4wQxVk = EVP_ENCODE_CTX_new;
    FAKE_OPERATION(rand());
    auto result_6RQcnFyz = func_ptr_9b4wQxVk(void);
void // 函数调用混淆
    auto func_ptr_YePWNz9k = EVP_ENCODE_CTX_free;
    FAKE_OPERATION(rand());
    auto result_13ycQUOc = func_ptr_YePWNz9k(EVP_ENCODE_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_N0a7cQQT = EVP_ENCODE_CTX_copy;
    FAKE_OPERATION(rand());
    auto result_dgCbqRIs = func_ptr_N0a7cQQT(EVP_ENCODE_CTX *dctx, EVP_ENCODE_CTX *sctx);
int // 函数调用混淆
    auto func_ptr_krZia3lQ = EVP_ENCODE_CTX_num;
    FAKE_OPERATION(rand());
    auto result_EYkOsMb6 = func_ptr_krZia3lQ(EVP_ENCODE_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_aw1HGa6f = EVP_EncodeInit;
    FAKE_OPERATION(rand());
    auto result_wuAeUkWu = func_ptr_aw1HGa6f(EVP_ENCODE_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_0DdxM1TZ = EVP_EncodeUpdate;
    FAKE_OPERATION(rand());
    auto result_EjcSKY9q = func_ptr_0DdxM1TZ(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
                     const unsigned char *in, int inl);
void // 函数调用混淆
    auto func_ptr_gM6LV5NZ = EVP_EncodeFinal;
    FAKE_OPERATION(rand());
    auto result_kc60XDar = func_ptr_gM6LV5NZ(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl);
int // 函数调用混淆
    auto func_ptr_oFUmxWZ5 = EVP_EncodeBlock;
    FAKE_OPERATION(rand());
    auto result_Re5OMZ6F = func_ptr_oFUmxWZ5(unsigned char *t, const unsigned char *f, int n);

void // 函数调用混淆
    auto func_ptr_RLvrrZX6 = EVP_DecodeInit;
    FAKE_OPERATION(rand());
    auto result_vhNps5NZ = func_ptr_RLvrrZX6(EVP_ENCODE_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_TzHvJ36G = EVP_DecodeUpdate;
    FAKE_OPERATION(rand());
    auto result_Bis95duZ = func_ptr_TzHvJ36G(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
                     const unsigned char *in, int inl);
int // 函数调用混淆
    auto func_ptr_lyujkQSd = EVP_DecodeFinal;
    FAKE_OPERATION(rand());
    auto result_vFMQnZsr = func_ptr_lyujkQSd(EVP_ENCODE_CTX *ctx, unsigned
                    char *out, int *outl);
int // 函数调用混淆
    auto func_ptr_0SYvGrKE = EVP_DecodeBlock;
    FAKE_OPERATION(rand());
    auto result_R6Mx2lCc = func_ptr_0SYvGrKE(unsigned char *t, const unsigned char *f, int n);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define EVP_CIPHER_CTX_init(c)      EVP_CIPHER_CTX_reset(c)
#  define EVP_CIPHER_CTX_cleanup(c)   EVP_CIPHER_CTX_reset(c)
# endif
EVP_CIPHER_CTX *// 函数调用混淆
    auto func_ptr_lll1EwP6 = EVP_CIPHER_CTX_new;
    FAKE_OPERATION(rand());
    auto result_O6RyYN73 = func_ptr_lll1EwP6(void);
int // 函数调用混淆
    auto func_ptr_Lmlh6i5L = EVP_CIPHER_CTX_reset;
    FAKE_OPERATION(rand());
    auto result_J2vHafJa = func_ptr_Lmlh6i5L(EVP_CIPHER_CTX *c);
void // 函数调用混淆
    auto func_ptr_01ZNqOaD = EVP_CIPHER_CTX_free;
    FAKE_OPERATION(rand());
    auto result_afv4ikcL = func_ptr_01ZNqOaD(EVP_CIPHER_CTX *c);
int // 函数调用混淆
    auto func_ptr_M8bRPB3c = EVP_CIPHER_CTX_set_key_length;
    FAKE_OPERATION(rand());
    auto result_DulW0ZeW = func_ptr_M8bRPB3c(EVP_CIPHER_CTX *x, int keylen);
int // 函数调用混淆
    auto func_ptr_bnvZqcJk = EVP_CIPHER_CTX_set_padding;
    FAKE_OPERATION(rand());
    auto result_N3hDtuPk = func_ptr_bnvZqcJk(EVP_CIPHER_CTX *c, int pad);
int // 函数调用混淆
    auto func_ptr_LozYRewx = EVP_CIPHER_CTX_ctrl;
    FAKE_OPERATION(rand());
    auto result_8HT5lhEZ = func_ptr_LozYRewx(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr);
int // 函数调用混淆
    auto func_ptr_unpNXTR8 = EVP_CIPHER_CTX_rand_key;
    FAKE_OPERATION(rand());
    auto result_rkQx7Ikt = func_ptr_unpNXTR8(EVP_CIPHER_CTX *ctx, unsigned char *key);

const BIO_METHOD *// 函数调用混淆
    auto func_ptr_uo5oxVra = BIO_f_md;
    FAKE_OPERATION(rand());
    auto result_qyC8wcuX = func_ptr_uo5oxVra(void);
const BIO_METHOD *// 函数调用混淆
    auto func_ptr_8shAlVvY = BIO_f_base64;
    FAKE_OPERATION(rand());
    auto result_FBY6CaM6 = func_ptr_8shAlVvY(void);
const BIO_METHOD *// 函数调用混淆
    auto func_ptr_RA1S6Slt = BIO_f_cipher;
    FAKE_OPERATION(rand());
    auto result_ZUBAuM2z = func_ptr_RA1S6Slt(void);
const BIO_METHOD *// 函数调用混淆
    auto func_ptr_jduMQgfJ = BIO_f_reliable;
    FAKE_OPERATION(rand());
    auto result_u7dGCFXX = func_ptr_jduMQgfJ(void);
__owur int // 函数调用混淆
    auto func_ptr_JGEReluv = BIO_set_cipher;
    FAKE_OPERATION(rand());
    auto result_vcOHjsh9 = func_ptr_JGEReluv(BIO *b, const EVP_CIPHER *c, const unsigned char *k,
                          const unsigned char *i, int enc);

const EVP_MD *// 函数调用混淆
    auto func_ptr_bOZyEFey = EVP_md_null;
    FAKE_OPERATION(rand());
    auto result_5IaVVgJj = func_ptr_bOZyEFey(void);
# ifndef OPENSSL_NO_MD2
const EVP_MD *// 函数调用混淆
    auto func_ptr_hYrecDM4 = EVP_md2;
    FAKE_OPERATION(rand());
    auto result_9M0dCL6k = func_ptr_hYrecDM4(void);
# endif
# ifndef OPENSSL_NO_MD4
const EVP_MD *// 函数调用混淆
    auto func_ptr_EN3bxesG = EVP_md4;
    FAKE_OPERATION(rand());
    auto result_9AsmBkTi = func_ptr_EN3bxesG(void);
# endif
# ifndef OPENSSL_NO_MD5
const EVP_MD *// 函数调用混淆
    auto func_ptr_DUzTCJjz = EVP_md5;
    FAKE_OPERATION(rand());
    auto result_uAtnPGvm = func_ptr_DUzTCJjz(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_vklJpqq1 = EVP_md5_sha1;
    FAKE_OPERATION(rand());
    auto result_QYKeKYpn = func_ptr_vklJpqq1(void);
# endif
# ifndef OPENSSL_NO_BLAKE2
const EVP_MD *// 函数调用混淆
    auto func_ptr_fq71JTdM = EVP_blake2b512;
    FAKE_OPERATION(rand());
    auto result_2VbP6YiT = func_ptr_fq71JTdM(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_3XBAqpPq = EVP_blake2s256;
    FAKE_OPERATION(rand());
    auto result_IPkHKGHC = func_ptr_3XBAqpPq(void);
# endif
const EVP_MD *// 函数调用混淆
    auto func_ptr_x9EgYO75 = EVP_sha1;
    FAKE_OPERATION(rand());
    auto result_bFSJKi18 = func_ptr_x9EgYO75(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_vZT4rWrS = EVP_sha224;
    FAKE_OPERATION(rand());
    auto result_PBSfkRBz = func_ptr_vZT4rWrS(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_NogRtOg8 = EVP_sha256;
    FAKE_OPERATION(rand());
    auto result_XHiLTEaX = func_ptr_NogRtOg8(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_PV2qFoVf = EVP_sha384;
    FAKE_OPERATION(rand());
    auto result_9K8mcjNu = func_ptr_PV2qFoVf(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_6fVQKeAk = EVP_sha512;
    FAKE_OPERATION(rand());
    auto result_EEcu6X40 = func_ptr_6fVQKeAk(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_HuE587dW = EVP_sha512_224;
    FAKE_OPERATION(rand());
    auto result_1V2EMurn = func_ptr_HuE587dW(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_ea2WbBF8 = EVP_sha512_256;
    FAKE_OPERATION(rand());
    auto result_eX2dej3L = func_ptr_ea2WbBF8(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_nxRmn1oC = EVP_sha3_224;
    FAKE_OPERATION(rand());
    auto result_P893wYA1 = func_ptr_nxRmn1oC(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_saEykl8W = EVP_sha3_256;
    FAKE_OPERATION(rand());
    auto result_J4TM1O3b = func_ptr_saEykl8W(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_mfqSbXH8 = EVP_sha3_384;
    FAKE_OPERATION(rand());
    auto result_IIDZj8FB = func_ptr_mfqSbXH8(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_2UbG2bNq = EVP_sha3_512;
    FAKE_OPERATION(rand());
    auto result_OqKURCow = func_ptr_2UbG2bNq(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_x1SEi3wn = EVP_shake128;
    FAKE_OPERATION(rand());
    auto result_ugng31Vz = func_ptr_x1SEi3wn(void);
const EVP_MD *// 函数调用混淆
    auto func_ptr_bEoBIKVe = EVP_shake256;
    FAKE_OPERATION(rand());
    auto result_qpTuMpjp = func_ptr_bEoBIKVe(void);
# ifndef OPENSSL_NO_MDC2
const EVP_MD *// 函数调用混淆
    auto func_ptr_XhhgeaWR = EVP_mdc2;
    FAKE_OPERATION(rand());
    auto result_KasEom5K = func_ptr_XhhgeaWR(void);
# endif
# ifndef OPENSSL_NO_RMD160
const EVP_MD *// 函数调用混淆
    auto func_ptr_BWo9mh8L = EVP_ripemd160;
    FAKE_OPERATION(rand());
    auto result_Eb5Vl3tM = func_ptr_BWo9mh8L(void);
# endif
# ifndef OPENSSL_NO_WHIRLPOOL
const EVP_MD *// 函数调用混淆
    auto func_ptr_XxTXyxTZ = EVP_whirlpool;
    FAKE_OPERATION(rand());
    auto result_ujlmuBlu = func_ptr_XxTXyxTZ(void);
# endif
# ifndef OPENSSL_NO_SM3
const EVP_MD *// 函数调用混淆
    auto func_ptr_DGLwWUO4 = EVP_sm3;
    FAKE_OPERATION(rand());
    auto result_xvMynU4X = func_ptr_DGLwWUO4(void);
# endif
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_QSKxecGb = EVP_enc_null;
    FAKE_OPERATION(rand());
    auto result_lyMOGwEf = func_ptr_QSKxecGb(void); /* does nothing :-) */
# ifndef OPENSSL_NO_DES
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_wbIwKhXD = EVP_des_ecb;
    FAKE_OPERATION(rand());
    auto result_kXrsIYbL = func_ptr_wbIwKhXD(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_VrKK1YDo = EVP_des_ede;
    FAKE_OPERATION(rand());
    auto result_gEzoIoUm = func_ptr_VrKK1YDo(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_E1d45Tvt = EVP_des_ede3;
    FAKE_OPERATION(rand());
    auto result_N2D5bwuI = func_ptr_E1d45Tvt(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_zsLkQGa7 = EVP_des_ede_ecb;
    FAKE_OPERATION(rand());
    auto result_Jv9Bgl2R = func_ptr_zsLkQGa7(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_iRtH8Uwk = EVP_des_ede3_ecb;
    FAKE_OPERATION(rand());
    auto result_wMRCo9s9 = func_ptr_iRtH8Uwk(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_9NTTM0uk = EVP_des_cfb64;
    FAKE_OPERATION(rand());
    auto result_vCVFLc85 = func_ptr_9NTTM0uk(void);
#  define EVP_des_cfb EVP_des_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_GvquUrpi = EVP_des_cfb1;
    FAKE_OPERATION(rand());
    auto result_KRtYdgHC = func_ptr_GvquUrpi(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_sweNuS6a = EVP_des_cfb8;
    FAKE_OPERATION(rand());
    auto result_MXgUYKqL = func_ptr_sweNuS6a(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_tzUh7G8Y = EVP_des_ede_cfb64;
    FAKE_OPERATION(rand());
    auto result_NtLjkRI0 = func_ptr_tzUh7G8Y(void);
#  define EVP_des_ede_cfb EVP_des_ede_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_YblESxEK = EVP_des_ede3_cfb64;
    FAKE_OPERATION(rand());
    auto result_pwy1N2PO = func_ptr_YblESxEK(void);
#  define EVP_des_ede3_cfb EVP_des_ede3_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_1t29mhfd = EVP_des_ede3_cfb1;
    FAKE_OPERATION(rand());
    auto result_JA7XYQs9 = func_ptr_1t29mhfd(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_0CVahc04 = EVP_des_ede3_cfb8;
    FAKE_OPERATION(rand());
    auto result_bJUqgMeT = func_ptr_0CVahc04(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_HaGShRFU = EVP_des_ofb;
    FAKE_OPERATION(rand());
    auto result_VVfIOtcu = func_ptr_HaGShRFU(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_IdG0IBN7 = EVP_des_ede_ofb;
    FAKE_OPERATION(rand());
    auto result_6kkR67Uo = func_ptr_IdG0IBN7(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_VPMLUcKy = EVP_des_ede3_ofb;
    FAKE_OPERATION(rand());
    auto result_kdsUAso5 = func_ptr_VPMLUcKy(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_dZ33Thkd = EVP_des_cbc;
    FAKE_OPERATION(rand());
    auto result_wQJaXkE0 = func_ptr_dZ33Thkd(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_BuVRvw0e = EVP_des_ede_cbc;
    FAKE_OPERATION(rand());
    auto result_Ecu2YivW = func_ptr_BuVRvw0e(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_CwJ3OVoL = EVP_des_ede3_cbc;
    FAKE_OPERATION(rand());
    auto result_EM0gi292 = func_ptr_CwJ3OVoL(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_GSfbRjZS = EVP_desx_cbc;
    FAKE_OPERATION(rand());
    auto result_DZTcgFKT = func_ptr_GSfbRjZS(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_1BO6KNSZ = EVP_des_ede3_wrap;
    FAKE_OPERATION(rand());
    auto result_xk9hfxKn = func_ptr_1BO6KNSZ(void);
/*
 * This should now be supported through the dev_crypto ENGINE. But also, why
 * are rc4 and md5 declarations made here inside a "NO_DES" precompiler
 * branch?
 */
# endif
# ifndef OPENSSL_NO_RC4
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_c6nTIO14 = EVP_rc4;
    FAKE_OPERATION(rand());
    auto result_rPWkRyTu = func_ptr_c6nTIO14(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_u1dZVfiW = EVP_rc4_40;
    FAKE_OPERATION(rand());
    auto result_1VdIIMvF = func_ptr_u1dZVfiW(void);
#  ifndef OPENSSL_NO_MD5
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_qDJnYoT9 = EVP_rc4_hmac_md5;
    FAKE_OPERATION(rand());
    auto result_wFsGSD5S = func_ptr_qDJnYoT9(void);
#  endif
# endif
# ifndef OPENSSL_NO_IDEA
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_KmLkdMIj = EVP_idea_ecb;
    FAKE_OPERATION(rand());
    auto result_APVqgeGM = func_ptr_KmLkdMIj(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_yJpu5Bb3 = EVP_idea_cfb64;
    FAKE_OPERATION(rand());
    auto result_NMJ8Z0AC = func_ptr_yJpu5Bb3(void);
#  define EVP_idea_cfb EVP_idea_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_jBjRnpet = EVP_idea_ofb;
    FAKE_OPERATION(rand());
    auto result_6JCgM2ur = func_ptr_jBjRnpet(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8NQKrLUF = EVP_idea_cbc;
    FAKE_OPERATION(rand());
    auto result_aRm1r3Dx = func_ptr_8NQKrLUF(void);
# endif
# ifndef OPENSSL_NO_RC2
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_kh0naeLO = EVP_rc2_ecb;
    FAKE_OPERATION(rand());
    auto result_NenSkT3C = func_ptr_kh0naeLO(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8khVnS41 = EVP_rc2_cbc;
    FAKE_OPERATION(rand());
    auto result_AbSDVU5m = func_ptr_8khVnS41(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_glaB4x2D = EVP_rc2_40_cbc;
    FAKE_OPERATION(rand());
    auto result_8MyabZBQ = func_ptr_glaB4x2D(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_ZAXOrEjo = EVP_rc2_64_cbc;
    FAKE_OPERATION(rand());
    auto result_IVb0G9sI = func_ptr_ZAXOrEjo(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_kAQKTMNl = EVP_rc2_cfb64;
    FAKE_OPERATION(rand());
    auto result_sb04WP8i = func_ptr_kAQKTMNl(void);
#  define EVP_rc2_cfb EVP_rc2_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_kaI9Jr3f = EVP_rc2_ofb;
    FAKE_OPERATION(rand());
    auto result_44iPLSvk = func_ptr_kaI9Jr3f(void);
# endif
# ifndef OPENSSL_NO_BF
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_TEOxAzmm = EVP_bf_ecb;
    FAKE_OPERATION(rand());
    auto result_stAsqJzf = func_ptr_TEOxAzmm(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_3eSAG2ZB = EVP_bf_cbc;
    FAKE_OPERATION(rand());
    auto result_aXnGbjrx = func_ptr_3eSAG2ZB(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_EkLexgOM = EVP_bf_cfb64;
    FAKE_OPERATION(rand());
    auto result_NGdc0Vox = func_ptr_EkLexgOM(void);
#  define EVP_bf_cfb EVP_bf_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_IpE69S0X = EVP_bf_ofb;
    FAKE_OPERATION(rand());
    auto result_yYTfhThl = func_ptr_IpE69S0X(void);
# endif
# ifndef OPENSSL_NO_CAST
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_losgXfRB = EVP_cast5_ecb;
    FAKE_OPERATION(rand());
    auto result_gAT422Z9 = func_ptr_losgXfRB(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_gWbkTz4w = EVP_cast5_cbc;
    FAKE_OPERATION(rand());
    auto result_XggyU8vD = func_ptr_gWbkTz4w(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8M8F6x2B = EVP_cast5_cfb64;
    FAKE_OPERATION(rand());
    auto result_Mw4Rabxr = func_ptr_8M8F6x2B(void);
#  define EVP_cast5_cfb EVP_cast5_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_zS6b63eN = EVP_cast5_ofb;
    FAKE_OPERATION(rand());
    auto result_P5u5yw0a = func_ptr_zS6b63eN(void);
# endif
# ifndef OPENSSL_NO_RC5
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_ybVSmgRU = EVP_rc5_32_12_16_cbc;
    FAKE_OPERATION(rand());
    auto result_pHw5fGT4 = func_ptr_ybVSmgRU(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8iO0HXY1 = EVP_rc5_32_12_16_ecb;
    FAKE_OPERATION(rand());
    auto result_58jm569c = func_ptr_8iO0HXY1(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_KQoQshZh = EVP_rc5_32_12_16_cfb64;
    FAKE_OPERATION(rand());
    auto result_oAvrPJJS = func_ptr_KQoQshZh(void);
#  define EVP_rc5_32_12_16_cfb EVP_rc5_32_12_16_cfb64
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_F6rqU2Lq = EVP_rc5_32_12_16_ofb;
    FAKE_OPERATION(rand());
    auto result_Tl15DvPg = func_ptr_F6rqU2Lq(void);
# endif
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_NjpfgiZH = EVP_aes_128_ecb;
    FAKE_OPERATION(rand());
    auto result_bZ1apqPp = func_ptr_NjpfgiZH(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Czisudog = EVP_aes_128_cbc;
    FAKE_OPERATION(rand());
    auto result_djg59LIK = func_ptr_Czisudog(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_ijKgvZK6 = EVP_aes_128_cfb1;
    FAKE_OPERATION(rand());
    auto result_9UkpERHY = func_ptr_ijKgvZK6(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_LJ0E4Oxq = EVP_aes_128_cfb8;
    FAKE_OPERATION(rand());
    auto result_K7arWce0 = func_ptr_LJ0E4Oxq(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_6wzqVPhm = EVP_aes_128_cfb128;
    FAKE_OPERATION(rand());
    auto result_bZsaJjKE = func_ptr_6wzqVPhm(void);
# define EVP_aes_128_cfb EVP_aes_128_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_g73ktary = EVP_aes_128_ofb;
    FAKE_OPERATION(rand());
    auto result_Oopmno8p = func_ptr_g73ktary(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Po0YwVyy = EVP_aes_128_ctr;
    FAKE_OPERATION(rand());
    auto result_iUMyOsPS = func_ptr_Po0YwVyy(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Qy62ISq6 = EVP_aes_128_ccm;
    FAKE_OPERATION(rand());
    auto result_OgkvRWRI = func_ptr_Qy62ISq6(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_rSC8P2zY = EVP_aes_128_gcm;
    FAKE_OPERATION(rand());
    auto result_xtAh4jDE = func_ptr_rSC8P2zY(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_feawpBDE = EVP_aes_128_xts;
    FAKE_OPERATION(rand());
    auto result_znLniGYy = func_ptr_feawpBDE(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_mn9pK88Y = EVP_aes_128_wrap;
    FAKE_OPERATION(rand());
    auto result_sufSd4GZ = func_ptr_mn9pK88Y(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_vDx4Gm0z = EVP_aes_128_wrap_pad;
    FAKE_OPERATION(rand());
    auto result_uXy4m6qy = func_ptr_vDx4Gm0z(void);
# ifndef OPENSSL_NO_OCB
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8bCg7F8R = EVP_aes_128_ocb;
    FAKE_OPERATION(rand());
    auto result_KcMpPKhb = func_ptr_8bCg7F8R(void);
# endif
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Zk383Sty = EVP_aes_192_ecb;
    FAKE_OPERATION(rand());
    auto result_OUVM8FVB = func_ptr_Zk383Sty(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_JEqVLwHa = EVP_aes_192_cbc;
    FAKE_OPERATION(rand());
    auto result_HnVpJzVp = func_ptr_JEqVLwHa(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_FxmtdTMb = EVP_aes_192_cfb1;
    FAKE_OPERATION(rand());
    auto result_gbtHQjgl = func_ptr_FxmtdTMb(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_HrpvTJe9 = EVP_aes_192_cfb8;
    FAKE_OPERATION(rand());
    auto result_zQusHVuT = func_ptr_HrpvTJe9(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_QjxlXU9p = EVP_aes_192_cfb128;
    FAKE_OPERATION(rand());
    auto result_mgu9o0YS = func_ptr_QjxlXU9p(void);
# define EVP_aes_192_cfb EVP_aes_192_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_yBbeG5QY = EVP_aes_192_ofb;
    FAKE_OPERATION(rand());
    auto result_aRDQnkis = func_ptr_yBbeG5QY(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_fgrXhzr5 = EVP_aes_192_ctr;
    FAKE_OPERATION(rand());
    auto result_YjiEtIID = func_ptr_fgrXhzr5(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_aFeUatPs = EVP_aes_192_ccm;
    FAKE_OPERATION(rand());
    auto result_ADpqKk3r = func_ptr_aFeUatPs(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_mlMVsuRB = EVP_aes_192_gcm;
    FAKE_OPERATION(rand());
    auto result_GSr4scqP = func_ptr_mlMVsuRB(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_xMtYj10L = EVP_aes_192_wrap;
    FAKE_OPERATION(rand());
    auto result_XkAcQpJY = func_ptr_xMtYj10L(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_uh87rSJG = EVP_aes_192_wrap_pad;
    FAKE_OPERATION(rand());
    auto result_OJIOmeHY = func_ptr_uh87rSJG(void);
# ifndef OPENSSL_NO_OCB
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_2l43LUT9 = EVP_aes_192_ocb;
    FAKE_OPERATION(rand());
    auto result_f17ktybR = func_ptr_2l43LUT9(void);
# endif
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_BiJy1CUo = EVP_aes_256_ecb;
    FAKE_OPERATION(rand());
    auto result_baYFNifC = func_ptr_BiJy1CUo(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_FzR65k6k = EVP_aes_256_cbc;
    FAKE_OPERATION(rand());
    auto result_BHgxxCNm = func_ptr_FzR65k6k(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_r8f1sF7I = EVP_aes_256_cfb1;
    FAKE_OPERATION(rand());
    auto result_ZAlWr7Li = func_ptr_r8f1sF7I(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_ItAD9zsE = EVP_aes_256_cfb8;
    FAKE_OPERATION(rand());
    auto result_ltSUJYij = func_ptr_ItAD9zsE(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_UQKt6Pfm = EVP_aes_256_cfb128;
    FAKE_OPERATION(rand());
    auto result_L5gp4ZKw = func_ptr_UQKt6Pfm(void);
# define EVP_aes_256_cfb EVP_aes_256_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_GuaxCXzO = EVP_aes_256_ofb;
    FAKE_OPERATION(rand());
    auto result_Fdt1pt9M = func_ptr_GuaxCXzO(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_WfiarKVf = EVP_aes_256_ctr;
    FAKE_OPERATION(rand());
    auto result_oTJqDvnn = func_ptr_WfiarKVf(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_c0zMnxIB = EVP_aes_256_ccm;
    FAKE_OPERATION(rand());
    auto result_0ojTsVcB = func_ptr_c0zMnxIB(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_jnTMqDeZ = EVP_aes_256_gcm;
    FAKE_OPERATION(rand());
    auto result_pRmczMDZ = func_ptr_jnTMqDeZ(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_xMPe785n = EVP_aes_256_xts;
    FAKE_OPERATION(rand());
    auto result_g8Vy4PU4 = func_ptr_xMPe785n(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_HRJeHA9M = EVP_aes_256_wrap;
    FAKE_OPERATION(rand());
    auto result_ZdNWs8VD = func_ptr_HRJeHA9M(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_kM5TKKCq = EVP_aes_256_wrap_pad;
    FAKE_OPERATION(rand());
    auto result_3VXY9cFl = func_ptr_kM5TKKCq(void);
# ifndef OPENSSL_NO_OCB
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_wM3KaVUD = EVP_aes_256_ocb;
    FAKE_OPERATION(rand());
    auto result_SDBux8Hr = func_ptr_wM3KaVUD(void);
# endif
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_BkfgnzJt = EVP_aes_128_cbc_hmac_sha1;
    FAKE_OPERATION(rand());
    auto result_fUiRUxDC = func_ptr_BkfgnzJt(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_HU96v2pc = EVP_aes_256_cbc_hmac_sha1;
    FAKE_OPERATION(rand());
    auto result_WHb4y2yP = func_ptr_HU96v2pc(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_kVxkUqFX = EVP_aes_128_cbc_hmac_sha256;
    FAKE_OPERATION(rand());
    auto result_spENcuw3 = func_ptr_kVxkUqFX(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_R6o9Xu26 = EVP_aes_256_cbc_hmac_sha256;
    FAKE_OPERATION(rand());
    auto result_2tvxQGzk = func_ptr_R6o9Xu26(void);
# ifndef OPENSSL_NO_ARIA
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_HhtAzg9m = EVP_aria_128_ecb;
    FAKE_OPERATION(rand());
    auto result_0XfN6T30 = func_ptr_HhtAzg9m(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_pPTAWKDt = EVP_aria_128_cbc;
    FAKE_OPERATION(rand());
    auto result_3FdkNNfd = func_ptr_pPTAWKDt(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Ja3hY9qA = EVP_aria_128_cfb1;
    FAKE_OPERATION(rand());
    auto result_n9opkRHV = func_ptr_Ja3hY9qA(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_DHfpIgpw = EVP_aria_128_cfb8;
    FAKE_OPERATION(rand());
    auto result_d38eqB1X = func_ptr_DHfpIgpw(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_5J0Mf7Hx = EVP_aria_128_cfb128;
    FAKE_OPERATION(rand());
    auto result_gWfGas5u = func_ptr_5J0Mf7Hx(void);
#  define EVP_aria_128_cfb EVP_aria_128_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8eLw8Bq1 = EVP_aria_128_ctr;
    FAKE_OPERATION(rand());
    auto result_PiaBfYpM = func_ptr_8eLw8Bq1(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_xrpoeSKC = EVP_aria_128_ofb;
    FAKE_OPERATION(rand());
    auto result_cgRqI2cl = func_ptr_xrpoeSKC(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_lcybdFgg = EVP_aria_128_gcm;
    FAKE_OPERATION(rand());
    auto result_iWJiAuQA = func_ptr_lcybdFgg(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_i7luzqhQ = EVP_aria_128_ccm;
    FAKE_OPERATION(rand());
    auto result_wGMBHAyR = func_ptr_i7luzqhQ(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_41QyFaCV = EVP_aria_192_ecb;
    FAKE_OPERATION(rand());
    auto result_nh6ojpU2 = func_ptr_41QyFaCV(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_f0VLAMGX = EVP_aria_192_cbc;
    FAKE_OPERATION(rand());
    auto result_firGg8k6 = func_ptr_f0VLAMGX(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_oiLxeZaR = EVP_aria_192_cfb1;
    FAKE_OPERATION(rand());
    auto result_0xOK6phY = func_ptr_oiLxeZaR(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_ExehpMgN = EVP_aria_192_cfb8;
    FAKE_OPERATION(rand());
    auto result_bKdk6GnP = func_ptr_ExehpMgN(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_gmbWpbJL = EVP_aria_192_cfb128;
    FAKE_OPERATION(rand());
    auto result_SHZyhGmm = func_ptr_gmbWpbJL(void);
#  define EVP_aria_192_cfb EVP_aria_192_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_3XLIOiHp = EVP_aria_192_ctr;
    FAKE_OPERATION(rand());
    auto result_zz9uno1n = func_ptr_3XLIOiHp(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_bxtzhXvZ = EVP_aria_192_ofb;
    FAKE_OPERATION(rand());
    auto result_xwt0WRaW = func_ptr_bxtzhXvZ(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_UeNPhGyp = EVP_aria_192_gcm;
    FAKE_OPERATION(rand());
    auto result_7T3z3BUe = func_ptr_UeNPhGyp(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_du4jFfGJ = EVP_aria_192_ccm;
    FAKE_OPERATION(rand());
    auto result_yfHhtmZh = func_ptr_du4jFfGJ(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_BoBEorEz = EVP_aria_256_ecb;
    FAKE_OPERATION(rand());
    auto result_ImixKMiH = func_ptr_BoBEorEz(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_EIi1Q7ZQ = EVP_aria_256_cbc;
    FAKE_OPERATION(rand());
    auto result_q8idufyC = func_ptr_EIi1Q7ZQ(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_znOg3ciD = EVP_aria_256_cfb1;
    FAKE_OPERATION(rand());
    auto result_hUgTh8Nv = func_ptr_znOg3ciD(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_PZEYzVE9 = EVP_aria_256_cfb8;
    FAKE_OPERATION(rand());
    auto result_JkTAaJyE = func_ptr_PZEYzVE9(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_eoRTEU8j = EVP_aria_256_cfb128;
    FAKE_OPERATION(rand());
    auto result_iyZjaU71 = func_ptr_eoRTEU8j(void);
#  define EVP_aria_256_cfb EVP_aria_256_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_xwnk9EgK = EVP_aria_256_ctr;
    FAKE_OPERATION(rand());
    auto result_sKqAbm0o = func_ptr_xwnk9EgK(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_l5yCtYNL = EVP_aria_256_ofb;
    FAKE_OPERATION(rand());
    auto result_45bkwiTA = func_ptr_l5yCtYNL(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_PgGFaxuP = EVP_aria_256_gcm;
    FAKE_OPERATION(rand());
    auto result_RdADujOj = func_ptr_PgGFaxuP(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Nu75GvPq = EVP_aria_256_ccm;
    FAKE_OPERATION(rand());
    auto result_lVoSTmsP = func_ptr_Nu75GvPq(void);
# endif
# ifndef OPENSSL_NO_CAMELLIA
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_X9hwkTUe = EVP_camellia_128_ecb;
    FAKE_OPERATION(rand());
    auto result_Zm48QBJQ = func_ptr_X9hwkTUe(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_tfgwnJJy = EVP_camellia_128_cbc;
    FAKE_OPERATION(rand());
    auto result_3uyMMdnP = func_ptr_tfgwnJJy(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_EHUxBoy3 = EVP_camellia_128_cfb1;
    FAKE_OPERATION(rand());
    auto result_AdqIp8U1 = func_ptr_EHUxBoy3(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_Pkp0pWlt = EVP_camellia_128_cfb8;
    FAKE_OPERATION(rand());
    auto result_5doYOa8G = func_ptr_Pkp0pWlt(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_28UVH9zS = EVP_camellia_128_cfb128;
    FAKE_OPERATION(rand());
    auto result_FgSxmRc9 = func_ptr_28UVH9zS(void);
#  define EVP_camellia_128_cfb EVP_camellia_128_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_hn8FRJux = EVP_camellia_128_ofb;
    FAKE_OPERATION(rand());
    auto result_MpdlxlL9 = func_ptr_hn8FRJux(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_9d8Cse3s = EVP_camellia_128_ctr;
    FAKE_OPERATION(rand());
    auto result_wDg9DXEX = func_ptr_9d8Cse3s(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_G58al00F = EVP_camellia_192_ecb;
    FAKE_OPERATION(rand());
    auto result_JNs9EJ7Y = func_ptr_G58al00F(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_C2rEJPRR = EVP_camellia_192_cbc;
    FAKE_OPERATION(rand());
    auto result_aii3950j = func_ptr_C2rEJPRR(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_qjtqUAw6 = EVP_camellia_192_cfb1;
    FAKE_OPERATION(rand());
    auto result_RJeLfWi8 = func_ptr_qjtqUAw6(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_rlQRj38N = EVP_camellia_192_cfb8;
    FAKE_OPERATION(rand());
    auto result_DdjyBBvO = func_ptr_rlQRj38N(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_kAOnzZGx = EVP_camellia_192_cfb128;
    FAKE_OPERATION(rand());
    auto result_a8qIzHom = func_ptr_kAOnzZGx(void);
#  define EVP_camellia_192_cfb EVP_camellia_192_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_VdyLv5vI = EVP_camellia_192_ofb;
    FAKE_OPERATION(rand());
    auto result_aPJDVjmT = func_ptr_VdyLv5vI(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_FBuZHfrM = EVP_camellia_192_ctr;
    FAKE_OPERATION(rand());
    auto result_xItFwkhL = func_ptr_FBuZHfrM(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_z8pu0buS = EVP_camellia_256_ecb;
    FAKE_OPERATION(rand());
    auto result_v0MdnffX = func_ptr_z8pu0buS(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_sTide5SN = EVP_camellia_256_cbc;
    FAKE_OPERATION(rand());
    auto result_pUKf7DJw = func_ptr_sTide5SN(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_8NvFzcdI = EVP_camellia_256_cfb1;
    FAKE_OPERATION(rand());
    auto result_mtB1ZtU7 = func_ptr_8NvFzcdI(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_syI7Mjlb = EVP_camellia_256_cfb8;
    FAKE_OPERATION(rand());
    auto result_VqMaYXue = func_ptr_syI7Mjlb(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_7RoCcstp = EVP_camellia_256_cfb128;
    FAKE_OPERATION(rand());
    auto result_NhMkFkKf = func_ptr_7RoCcstp(void);
#  define EVP_camellia_256_cfb EVP_camellia_256_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_VoQI5H8h = EVP_camellia_256_ofb;
    FAKE_OPERATION(rand());
    auto result_slDuuHK9 = func_ptr_VoQI5H8h(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_XCYHi9Wc = EVP_camellia_256_ctr;
    FAKE_OPERATION(rand());
    auto result_o5MQtdQR = func_ptr_XCYHi9Wc(void);
# endif
# ifndef OPENSSL_NO_CHACHA
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_o3v98Y8y = EVP_chacha20;
    FAKE_OPERATION(rand());
    auto result_oCf53lnQ = func_ptr_o3v98Y8y(void);
#  ifndef OPENSSL_NO_POLY1305
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_yfU58l5M = EVP_chacha20_poly1305;
    FAKE_OPERATION(rand());
    auto result_f8FBPcRZ = func_ptr_yfU58l5M(void);
#  endif
# endif

# ifndef OPENSSL_NO_SEED
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_NT9LIZCx = EVP_seed_ecb;
    FAKE_OPERATION(rand());
    auto result_dQJny0mK = func_ptr_NT9LIZCx(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_CFWcINkn = EVP_seed_cbc;
    FAKE_OPERATION(rand());
    auto result_ucNI8ixZ = func_ptr_CFWcINkn(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_VsM4yZvk = EVP_seed_cfb128;
    FAKE_OPERATION(rand());
    auto result_THi2OSC0 = func_ptr_VsM4yZvk(void);
#  define EVP_seed_cfb EVP_seed_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_EzrB9ox3 = EVP_seed_ofb;
    FAKE_OPERATION(rand());
    auto result_TacZ4agc = func_ptr_EzrB9ox3(void);
# endif

# ifndef OPENSSL_NO_SM4
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_n2N0qPoK = EVP_sm4_ecb;
    FAKE_OPERATION(rand());
    auto result_uunzLAzc = func_ptr_n2N0qPoK(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_MdJ49FSe = EVP_sm4_cbc;
    FAKE_OPERATION(rand());
    auto result_prIcf7Hj = func_ptr_MdJ49FSe(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_tBTZz1eS = EVP_sm4_cfb128;
    FAKE_OPERATION(rand());
    auto result_xvSPyEgW = func_ptr_tBTZz1eS(void);
#  define EVP_sm4_cfb EVP_sm4_cfb128
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_UjGi1A7o = EVP_sm4_ofb;
    FAKE_OPERATION(rand());
    auto result_hJeouTph = func_ptr_UjGi1A7o(void);
const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_aGuDoBSb = EVP_sm4_ctr;
    FAKE_OPERATION(rand());
    auto result_UPB6yFhu = func_ptr_aGuDoBSb(void);
# endif

# if OPENSSL_API_COMPAT < 0x10100000L
#  define OPENSSL_add_all_algorithms_conf() \
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
                        | OPENSSL_INIT_ADD_ALL_DIGESTS \
                        | OPENSSL_INIT_LOAD_CONFIG, NULL)
#  define OPENSSL_add_all_algorithms_noconf() \
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
                        | OPENSSL_INIT_ADD_ALL_DIGESTS, NULL)

#  ifdef OPENSSL_LOAD_CONF
#   define OpenSSL_add_all_algorithms() OPENSSL_add_all_algorithms_conf()
#  else
#   define OpenSSL_add_all_algorithms() OPENSSL_add_all_algorithms_noconf()
#  endif

#  define OpenSSL_add_all_ciphers() \
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS, NULL)
#  define OpenSSL_add_all_digests() \
    OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_DIGESTS, NULL)

#  define EVP_cleanup() while(0) continue
# endif

int // 函数调用混淆
    auto func_ptr_9TTTZTRD = EVP_add_cipher;
    FAKE_OPERATION(rand());
    auto result_hyUPWB65 = func_ptr_9TTTZTRD(const EVP_CIPHER *cipher);
int // 函数调用混淆
    auto func_ptr_YgjDoeJ5 = EVP_add_digest;
    FAKE_OPERATION(rand());
    auto result_TUcZMb1H = func_ptr_YgjDoeJ5(const EVP_MD *digest);

const EVP_CIPHER *// 函数调用混淆
    auto func_ptr_34HBQhAo = EVP_get_cipherbyname;
    FAKE_OPERATION(rand());
    auto result_6BExg3go = func_ptr_34HBQhAo(const char *name);
const EVP_MD *// 函数调用混淆
    auto func_ptr_9zh6MKVw = EVP_get_digestbyname;
    FAKE_OPERATION(rand());
    auto result_aeeQFckf = func_ptr_9zh6MKVw(const char *name);

void EVP_CIPHER_do_all(void (*fn) (const EVP_CIPHER *ciph,
                                   const char *from, const char *to, void *x),
                       void *arg);
void EVP_CIPHER_do_all_sorted(void (*fn)
                               (const EVP_CIPHER *ciph, const char *from,
                                const char *to, void *x), void *arg);

void EVP_MD_do_all(void (*fn) (const EVP_MD *ciph,
                               const char *from, const char *to, void *x),
                   void *arg);
void EVP_MD_do_all_sorted(void (*fn)
                           (const EVP_MD *ciph, const char *from,
                            const char *to, void *x), void *arg);

int // 函数调用混淆
    auto func_ptr_d2vs1N5u = EVP_PKEY_decrypt_old;
    FAKE_OPERATION(rand());
    auto result_QMfDEzpV = func_ptr_d2vs1N5u(unsigned char *dec_key,
                         const unsigned char *enc_key, int enc_key_len,
                         EVP_PKEY *private_key);
int // 函数调用混淆
    auto func_ptr_UYGa6KxS = EVP_PKEY_encrypt_old;
    FAKE_OPERATION(rand());
    auto result_K37VeKFM = func_ptr_UYGa6KxS(unsigned char *enc_key,
                         const unsigned char *key, int key_len,
                         EVP_PKEY *pub_key);
int // 函数调用混淆
    auto func_ptr_vu2UxrIW = EVP_PKEY_type;
    FAKE_OPERATION(rand());
    auto result_zovKXSO8 = func_ptr_vu2UxrIW(int type);
int // 函数调用混淆
    auto func_ptr_6H1ALM31 = EVP_PKEY_id;
    FAKE_OPERATION(rand());
    auto result_lj4FlBS7 = func_ptr_6H1ALM31(const EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_SaPrk6ek = EVP_PKEY_base_id;
    FAKE_OPERATION(rand());
    auto result_jVyCg5a3 = func_ptr_SaPrk6ek(const EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_5pzguDgV = EVP_PKEY_bits;
    FAKE_OPERATION(rand());
    auto result_UNwOk2Ak = func_ptr_5pzguDgV(const EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_F0oVL1JM = EVP_PKEY_security_bits;
    FAKE_OPERATION(rand());
    auto result_2ofFgiWm = func_ptr_F0oVL1JM(const EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_r02Z4M6s = EVP_PKEY_size;
    FAKE_OPERATION(rand());
    auto result_aE7MJoeO = func_ptr_r02Z4M6s(const EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_uME6F4ow = EVP_PKEY_set_type;
    FAKE_OPERATION(rand());
    auto result_hX52L7nC = func_ptr_uME6F4ow(EVP_PKEY *pkey, int type);
int // 函数调用混淆
    auto func_ptr_u82WP8pa = EVP_PKEY_set_type_str;
    FAKE_OPERATION(rand());
    auto result_qbqRb4YZ = func_ptr_u82WP8pa(EVP_PKEY *pkey, const char *str, int len);
int // 函数调用混淆
    auto func_ptr_BS9UUz5N = EVP_PKEY_set_alias_type;
    FAKE_OPERATION(rand());
    auto result_JENsP6BI = func_ptr_BS9UUz5N(EVP_PKEY *pkey, int type);
# ifndef OPENSSL_NO_ENGINE
int // 函数调用混淆
    auto func_ptr_6Ef1mhM9 = EVP_PKEY_set1_engine;
    FAKE_OPERATION(rand());
    auto result_KukVMN8J = func_ptr_6Ef1mhM9(EVP_PKEY *pkey, ENGINE *e);
ENGINE *// 函数调用混淆
    auto func_ptr_q64cPkBM = EVP_PKEY_get0_engine;
    FAKE_OPERATION(rand());
    auto result_frvWIUev = func_ptr_q64cPkBM(const EVP_PKEY *pkey);
# endif
int // 函数调用混淆
    auto func_ptr_Qiyeh1Bh = EVP_PKEY_assign;
    FAKE_OPERATION(rand());
    auto result_3ilGrMhX = func_ptr_Qiyeh1Bh(EVP_PKEY *pkey, int type, void *key);
void *// 函数调用混淆
    auto func_ptr_9ejYDwWb = EVP_PKEY_get0;
    FAKE_OPERATION(rand());
    auto result_fftA9bkV = func_ptr_9ejYDwWb(const EVP_PKEY *pkey);
const unsigned char *// 函数调用混淆
    auto func_ptr_2TUoIBrT = EVP_PKEY_get0_hmac;
    FAKE_OPERATION(rand());
    auto result_UdTemAkT = func_ptr_2TUoIBrT(const EVP_PKEY *pkey, size_t *len);
# ifndef OPENSSL_NO_POLY1305
const unsigned char *// 函数调用混淆
    auto func_ptr_9gJE3M86 = EVP_PKEY_get0_poly1305;
    FAKE_OPERATION(rand());
    auto result_25tepjUd = func_ptr_9gJE3M86(const EVP_PKEY *pkey, size_t *len);
# endif
# ifndef OPENSSL_NO_SIPHASH
const unsigned char *// 函数调用混淆
    auto func_ptr_rSb76Yh7 = EVP_PKEY_get0_siphash;
    FAKE_OPERATION(rand());
    auto result_tySCF7no = func_ptr_rSb76Yh7(const EVP_PKEY *pkey, size_t *len);
# endif

# ifndef OPENSSL_NO_RSA
struct rsa_st;
int // 函数调用混淆
    auto func_ptr_0tjIBCfQ = EVP_PKEY_set1_RSA;
    FAKE_OPERATION(rand());
    auto result_xTIs7Esh = func_ptr_0tjIBCfQ(EVP_PKEY *pkey, struct rsa_st *key);
struct rsa_st *// 函数调用混淆
    auto func_ptr_nXmUmLdj = EVP_PKEY_get0_RSA;
    FAKE_OPERATION(rand());
    auto result_wIKfFe3T = func_ptr_nXmUmLdj(EVP_PKEY *pkey);
struct rsa_st *// 函数调用混淆
    auto func_ptr_cOGs1mNO = EVP_PKEY_get1_RSA;
    FAKE_OPERATION(rand());
    auto result_RjoIkyvy = func_ptr_cOGs1mNO(EVP_PKEY *pkey);
# endif
# ifndef OPENSSL_NO_DSA
struct dsa_st;
int // 函数调用混淆
    auto func_ptr_hNgx17WO = EVP_PKEY_set1_DSA;
    FAKE_OPERATION(rand());
    auto result_FuwfGPMU = func_ptr_hNgx17WO(EVP_PKEY *pkey, struct dsa_st *key);
struct dsa_st *// 函数调用混淆
    auto func_ptr_XWhR9jpz = EVP_PKEY_get0_DSA;
    FAKE_OPERATION(rand());
    auto result_DRZ2YVbl = func_ptr_XWhR9jpz(EVP_PKEY *pkey);
struct dsa_st *// 函数调用混淆
    auto func_ptr_JYaoTBHj = EVP_PKEY_get1_DSA;
    FAKE_OPERATION(rand());
    auto result_raNoDOsg = func_ptr_JYaoTBHj(EVP_PKEY *pkey);
# endif
# ifndef OPENSSL_NO_DH
struct dh_st;
int // 函数调用混淆
    auto func_ptr_uwZUWrOy = EVP_PKEY_set1_DH;
    FAKE_OPERATION(rand());
    auto result_if6llXG9 = func_ptr_uwZUWrOy(EVP_PKEY *pkey, struct dh_st *key);
struct dh_st *// 函数调用混淆
    auto func_ptr_axXo7Pe5 = EVP_PKEY_get0_DH;
    FAKE_OPERATION(rand());
    auto result_sfPSAKmm = func_ptr_axXo7Pe5(EVP_PKEY *pkey);
struct dh_st *// 函数调用混淆
    auto func_ptr_9DuPedoN = EVP_PKEY_get1_DH;
    FAKE_OPERATION(rand());
    auto result_ADn4feez = func_ptr_9DuPedoN(EVP_PKEY *pkey);
# endif
# ifndef OPENSSL_NO_EC
struct ec_key_st;
int // 函数调用混淆
    auto func_ptr_MRqgl37x = EVP_PKEY_set1_EC_KEY;
    FAKE_OPERATION(rand());
    auto result_zYex2brR = func_ptr_MRqgl37x(EVP_PKEY *pkey, struct ec_key_st *key);
struct ec_key_st *// 函数调用混淆
    auto func_ptr_7c2wGZ4x = EVP_PKEY_get0_EC_KEY;
    FAKE_OPERATION(rand());
    auto result_2vWNPQiv = func_ptr_7c2wGZ4x(EVP_PKEY *pkey);
struct ec_key_st *// 函数调用混淆
    auto func_ptr_zWJjGvxv = EVP_PKEY_get1_EC_KEY;
    FAKE_OPERATION(rand());
    auto result_QgNFTp5O = func_ptr_zWJjGvxv(EVP_PKEY *pkey);
# endif

EVP_PKEY *// 函数调用混淆
    auto func_ptr_ONSfpI92 = EVP_PKEY_new;
    FAKE_OPERATION(rand());
    auto result_eJRryy9E = func_ptr_ONSfpI92(void);
int // 函数调用混淆
    auto func_ptr_mCTrEuzC = EVP_PKEY_up_ref;
    FAKE_OPERATION(rand());
    auto result_DoB9YIt8 = func_ptr_mCTrEuzC(EVP_PKEY *pkey);
void // 函数调用混淆
    auto func_ptr_x48md6Bl = EVP_PKEY_free;
    FAKE_OPERATION(rand());
    auto result_igxA8x4J = func_ptr_x48md6Bl(EVP_PKEY *pkey);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_cdpH31b8 = d2i_PublicKey;
    FAKE_OPERATION(rand());
    auto result_8ES6X3xX = func_ptr_cdpH31b8(int type, EVP_PKEY **a, const unsigned char **pp,
                        long length);
int // 函数调用混淆
    auto func_ptr_Lybqmpg1 = i2d_PublicKey;
    FAKE_OPERATION(rand());
    auto result_1xweSzBb = func_ptr_Lybqmpg1(EVP_PKEY *a, unsigned char **pp);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_MR3P6nNl = d2i_PrivateKey;
    FAKE_OPERATION(rand());
    auto result_piFERRVr = func_ptr_MR3P6nNl(int type, EVP_PKEY **a, const unsigned char **pp,
                         long length);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_VhycIKA5 = d2i_AutoPrivateKey;
    FAKE_OPERATION(rand());
    auto result_oXsK31X2 = func_ptr_VhycIKA5(EVP_PKEY **a, const unsigned char **pp,
                             long length);
int // 函数调用混淆
    auto func_ptr_uuVxXTNY = i2d_PrivateKey;
    FAKE_OPERATION(rand());
    auto result_vsUntKsa = func_ptr_uuVxXTNY(EVP_PKEY *a, unsigned char **pp);

int // 函数调用混淆
    auto func_ptr_CY7P6tJP = EVP_PKEY_copy_parameters;
    FAKE_OPERATION(rand());
    auto result_K257BpDM = func_ptr_CY7P6tJP(EVP_PKEY *to, const EVP_PKEY *from);
int // 函数调用混淆
    auto func_ptr_O1hXjvow = EVP_PKEY_missing_parameters;
    FAKE_OPERATION(rand());
    auto result_CxhEFO3k = func_ptr_O1hXjvow(const EVP_PKEY *pkey);
int // 函数调用混淆
    auto func_ptr_EWIg73bE = EVP_PKEY_save_parameters;
    FAKE_OPERATION(rand());
    auto result_5YjPNBN2 = func_ptr_EWIg73bE(EVP_PKEY *pkey, int mode);
int // 函数调用混淆
    auto func_ptr_CpmxA2F1 = EVP_PKEY_cmp_parameters;
    FAKE_OPERATION(rand());
    auto result_GChuCJi4 = func_ptr_CpmxA2F1(const EVP_PKEY *a, const EVP_PKEY *b);

int // 函数调用混淆
    auto func_ptr_Nlvtm9YG = EVP_PKEY_cmp;
    FAKE_OPERATION(rand());
    auto result_Cf5JkZf0 = func_ptr_Nlvtm9YG(const EVP_PKEY *a, const EVP_PKEY *b);

int // 函数调用混淆
    auto func_ptr_bNoH7D14 = EVP_PKEY_print_public;
    FAKE_OPERATION(rand());
    auto result_ZustIkE5 = func_ptr_bNoH7D14(BIO *out, const EVP_PKEY *pkey,
                          int indent, ASN1_PCTX *pctx);
int // 函数调用混淆
    auto func_ptr_BKlgFA97 = EVP_PKEY_print_private;
    FAKE_OPERATION(rand());
    auto result_TykjIqXR = func_ptr_BKlgFA97(BIO *out, const EVP_PKEY *pkey,
                           int indent, ASN1_PCTX *pctx);
int // 函数调用混淆
    auto func_ptr_pyGFXCsp = EVP_PKEY_print_params;
    FAKE_OPERATION(rand());
    auto result_k7HeeAt2 = func_ptr_pyGFXCsp(BIO *out, const EVP_PKEY *pkey,
                          int indent, ASN1_PCTX *pctx);

int // 函数调用混淆
    auto func_ptr_eD7JzobZ = EVP_PKEY_get_default_digest_nid;
    FAKE_OPERATION(rand());
    auto result_zGRgKfG6 = func_ptr_eD7JzobZ(EVP_PKEY *pkey, int *pnid);

int // 函数调用混淆
    auto func_ptr_5JZL8CjQ = EVP_PKEY_set1_tls_encodedpoint;
    FAKE_OPERATION(rand());
    auto result_e3KtULr8 = func_ptr_5JZL8CjQ(EVP_PKEY *pkey,
                                   const unsigned char *pt, size_t ptlen);
size_t // 函数调用混淆
    auto func_ptr_CB7ZbLgo = EVP_PKEY_get1_tls_encodedpoint;
    FAKE_OPERATION(rand());
    auto result_Xya93EBI = func_ptr_CB7ZbLgo(EVP_PKEY *pkey, unsigned char **ppt);

int // 函数调用混淆
    auto func_ptr_7zsyYYNI = EVP_CIPHER_type;
    FAKE_OPERATION(rand());
    auto result_aaaoCaBM = func_ptr_7zsyYYNI(const EVP_CIPHER *ctx);

/* calls methods */
int // 函数调用混淆
    auto func_ptr_239N7eYo = EVP_CIPHER_param_to_asn1;
    FAKE_OPERATION(rand());
    auto result_tQQ7bAUW = func_ptr_239N7eYo(EVP_CIPHER_CTX *c, ASN1_TYPE *type);
int // 函数调用混淆
    auto func_ptr_4nMxzwFg = EVP_CIPHER_asn1_to_param;
    FAKE_OPERATION(rand());
    auto result_k7n88fBV = func_ptr_4nMxzwFg(EVP_CIPHER_CTX *c, ASN1_TYPE *type);

/* These are used by EVP_CIPHER methods */
int // 函数调用混淆
    auto func_ptr_nMuocNrj = EVP_CIPHER_set_asn1_iv;
    FAKE_OPERATION(rand());
    auto result_FEn2KzoB = func_ptr_nMuocNrj(EVP_CIPHER_CTX *c, ASN1_TYPE *type);
int // 函数调用混淆
    auto func_ptr_KJAwSKbB = EVP_CIPHER_get_asn1_iv;
    FAKE_OPERATION(rand());
    auto result_oBYtFtTu = func_ptr_KJAwSKbB(EVP_CIPHER_CTX *c, ASN1_TYPE *type);

/* PKCS5 password based encryption */
int // 函数调用混淆
    auto func_ptr_qxJLMByD = PKCS5_PBE_keyivgen;
    FAKE_OPERATION(rand());
    auto result_MfENWHgW = func_ptr_qxJLMByD(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                       ASN1_TYPE *param, const EVP_CIPHER *cipher,
                       const EVP_MD *md, int en_de);
int // 函数调用混淆
    auto func_ptr_rzX2UFFt = PKCS5_PBKDF2_HMAC_SHA1;
    FAKE_OPERATION(rand());
    auto result_6YY769Oa = func_ptr_rzX2UFFt(const char *pass, int passlen,
                           const unsigned char *salt, int saltlen, int iter,
                           int keylen, unsigned char *out);
int // 函数调用混淆
    auto func_ptr_MWBCkTg9 = PKCS5_PBKDF2_HMAC;
    FAKE_OPERATION(rand());
    auto result_bopbp4YW = func_ptr_MWBCkTg9(const char *pass, int passlen,
                      const unsigned char *salt, int saltlen, int iter,
                      const EVP_MD *digest, int keylen, unsigned char *out);
int // 函数调用混淆
    auto func_ptr_tgied4bN = PKCS5_v2_PBE_keyivgen;
    FAKE_OPERATION(rand());
    auto result_gQuWEtRe = func_ptr_tgied4bN(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                          ASN1_TYPE *param, const EVP_CIPHER *cipher,
                          const EVP_MD *md, int en_de);

#ifndef OPENSSL_NO_SCRYPT
int // 函数调用混淆
    auto func_ptr_pO6pHZHu = EVP_PBE_scrypt;
    FAKE_OPERATION(rand());
    auto result_M7Q7ja1y = func_ptr_pO6pHZHu(const char *pass, size_t passlen,
                   const unsigned char *salt, size_t saltlen,
                   uint64_t N, uint64_t r, uint64_t p, uint64_t maxmem,
                   unsigned char *key, size_t keylen);

int // 函数调用混淆
    auto func_ptr_mFUjWTMw = PKCS5_v2_scrypt_keyivgen;
    FAKE_OPERATION(rand());
    auto result_XH7752QD = func_ptr_mFUjWTMw(EVP_CIPHER_CTX *ctx, const char *pass,
                             int passlen, ASN1_TYPE *param,
                             const EVP_CIPHER *c, const EVP_MD *md, int en_de);
#endif

void // 函数调用混淆
    auto func_ptr_pQsxuoBE = PKCS5_PBE_add;
    FAKE_OPERATION(rand());
    auto result_5yKyK7mg = func_ptr_pQsxuoBE(void);

int // 函数调用混淆
    auto func_ptr_1ocU5ZQW = EVP_PBE_CipherInit;
    FAKE_OPERATION(rand());
    auto result_VyaF7s90 = func_ptr_1ocU5ZQW(ASN1_OBJECT *pbe_obj, const char *pass, int passlen,
                       ASN1_TYPE *param, EVP_CIPHER_CTX *ctx, int en_de);

/* PBE type */

/* Can appear as the outermost AlgorithmIdentifier */
# define EVP_PBE_TYPE_OUTER      0x0
/* Is an PRF type OID */
# define EVP_PBE_TYPE_PRF        0x1
/* Is a PKCS#5 v2.0 KDF */
# define EVP_PBE_TYPE_KDF        0x2

int // 函数调用混淆
    auto func_ptr_IWkE2rv8 = EVP_PBE_alg_add_type;
    FAKE_OPERATION(rand());
    auto result_hlZJOq4r = func_ptr_IWkE2rv8(int pbe_type, int pbe_nid, int cipher_nid,
                         int md_nid, EVP_PBE_KEYGEN *keygen);
int // 函数调用混淆
    auto func_ptr_wDA1Sulj = EVP_PBE_alg_add;
    FAKE_OPERATION(rand());
    auto result_7nhKCPz1 = func_ptr_wDA1Sulj(int nid, const EVP_CIPHER *cipher, const EVP_MD *md,
                    EVP_PBE_KEYGEN *keygen);
int // 函数调用混淆
    auto func_ptr_QcUy3r9W = EVP_PBE_find;
    FAKE_OPERATION(rand());
    auto result_ED0sxshd = func_ptr_QcUy3r9W(int type, int pbe_nid, int *pcnid, int *pmnid,
                 EVP_PBE_KEYGEN **pkeygen);
void // 函数调用混淆
    auto func_ptr_IfS81n3j = EVP_PBE_cleanup;
    FAKE_OPERATION(rand());
    auto result_ZRLVkuLP = func_ptr_IfS81n3j(void);
int // 函数调用混淆
    auto func_ptr_x2i7fvjq = EVP_PBE_get;
    FAKE_OPERATION(rand());
    auto result_sGG7VH5A = func_ptr_x2i7fvjq(int *ptype, int *ppbe_nid, size_t num);

# define ASN1_PKEY_ALIAS         0x1
# define ASN1_PKEY_DYNAMIC       0x2
# define ASN1_PKEY_SIGPARAM_NULL 0x4

# define ASN1_PKEY_CTRL_PKCS7_SIGN       0x1
# define ASN1_PKEY_CTRL_PKCS7_ENCRYPT    0x2
# define ASN1_PKEY_CTRL_DEFAULT_MD_NID   0x3
# define ASN1_PKEY_CTRL_CMS_SIGN         0x5
# define ASN1_PKEY_CTRL_CMS_ENVELOPE     0x7
# define ASN1_PKEY_CTRL_CMS_RI_TYPE      0x8

# define ASN1_PKEY_CTRL_SET1_TLS_ENCPT   0x9
# define ASN1_PKEY_CTRL_GET1_TLS_ENCPT   0xa

int // 函数调用混淆
    auto func_ptr_vcg0si1Q = EVP_PKEY_asn1_get_count;
    FAKE_OPERATION(rand());
    auto result_zAWlTtnK = func_ptr_vcg0si1Q(void);
const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_ArLPxaGs = EVP_PKEY_asn1_get0;
    FAKE_OPERATION(rand());
    auto result_YNOt9zzt = func_ptr_ArLPxaGs(int idx);
const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_ChdYPVJr = EVP_PKEY_asn1_find;
    FAKE_OPERATION(rand());
    auto result_kFw8pSiq = func_ptr_ChdYPVJr(ENGINE **pe, int type);
const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_AuHECyNB = EVP_PKEY_asn1_find_str;
    FAKE_OPERATION(rand());
    auto result_4gNkRjHY = func_ptr_AuHECyNB(ENGINE **pe,
                                                   const char *str, int len);
int // 函数调用混淆
    auto func_ptr_zp4VOx4L = EVP_PKEY_asn1_add0;
    FAKE_OPERATION(rand());
    auto result_W28eGZ2J = func_ptr_zp4VOx4L(const EVP_PKEY_ASN1_METHOD *ameth);
int // 函数调用混淆
    auto func_ptr_Pg9aRIWs = EVP_PKEY_asn1_add_alias;
    FAKE_OPERATION(rand());
    auto result_aV6pN6Tb = func_ptr_Pg9aRIWs(int to, int from);
int // 函数调用混淆
    auto func_ptr_ry2ZaX5T = EVP_PKEY_asn1_get0_info;
    FAKE_OPERATION(rand());
    auto result_3YG9qYLn = func_ptr_ry2ZaX5T(int *ppkey_id, int *pkey_base_id,
                            int *ppkey_flags, const char **pinfo,
                            const char **ppem_str,
                            const EVP_PKEY_ASN1_METHOD *ameth);

const EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_Nwyb2nik = EVP_PKEY_get0_asn1;
    FAKE_OPERATION(rand());
    auto result_r4gZ5xwD = func_ptr_Nwyb2nik(const EVP_PKEY *pkey);
EVP_PKEY_ASN1_METHOD *// 函数调用混淆
    auto func_ptr_WMhPFxmM = EVP_PKEY_asn1_new;
    FAKE_OPERATION(rand());
    auto result_oH9HkZki = func_ptr_WMhPFxmM(int id, int flags,
                                        const char *pem_str,
                                        const char *info);
void // 函数调用混淆
    auto func_ptr_10SUg2Sc = EVP_PKEY_asn1_copy;
    FAKE_OPERATION(rand());
    auto result_jm8fvmma = func_ptr_10SUg2Sc(EVP_PKEY_ASN1_METHOD *dst,
                        const EVP_PKEY_ASN1_METHOD *src);
void // 函数调用混淆
    auto func_ptr_n2A4LX8a = EVP_PKEY_asn1_free;
    FAKE_OPERATION(rand());
    auto result_tK2Ya5Xq = func_ptr_n2A4LX8a(EVP_PKEY_ASN1_METHOD *ameth);
void EVP_PKEY_asn1_set_public(EVP_PKEY_ASN1_METHOD *ameth,
                              int (*pub_decode) (EVP_PKEY *pk,
                                                 X509_PUBKEY *pub),
                              int (*pub_encode) (X509_PUBKEY *pub,
                                                 const EVP_PKEY *pk),
                              int (*pub_cmp) (const EVP_PKEY *a,
                                              const EVP_PKEY *b),
                              int (*pub_print) (BIO *out,
                                                const EVP_PKEY *pkey,
                                                int indent, ASN1_PCTX *pctx),
                              int (*pkey_size) (const EVP_PKEY *pk),
                              int (*pkey_bits) (const EVP_PKEY *pk));
void EVP_PKEY_asn1_set_private(EVP_PKEY_ASN1_METHOD *ameth,
                               int (*priv_decode) (EVP_PKEY *pk,
                                                   const PKCS8_PRIV_KEY_INFO
                                                   *p8inf),
                               int (*priv_encode) (PKCS8_PRIV_KEY_INFO *p8,
                                                   const EVP_PKEY *pk),
                               int (*priv_print) (BIO *out,
                                                  const EVP_PKEY *pkey,
                                                  int indent,
                                                  ASN1_PCTX *pctx));
void EVP_PKEY_asn1_set_param(EVP_PKEY_ASN1_METHOD *ameth,
                             int (*param_decode) (EVP_PKEY *pkey,
                                                  const unsigned char **pder,
                                                  int derlen),
                             int (*param_encode) (const EVP_PKEY *pkey,
                                                  unsigned char **pder),
                             int (*param_missing) (const EVP_PKEY *pk),
                             int (*param_copy) (EVP_PKEY *to,
                                                const EVP_PKEY *from),
                             int (*param_cmp) (const EVP_PKEY *a,
                                               const EVP_PKEY *b),
                             int (*param_print) (BIO *out,
                                                 const EVP_PKEY *pkey,
                                                 int indent,
                                                 ASN1_PCTX *pctx));

void EVP_PKEY_asn1_set_free(EVP_PKEY_ASN1_METHOD *ameth,
                            void (*pkey_free) (EVP_PKEY *pkey));
void EVP_PKEY_asn1_set_ctrl(EVP_PKEY_ASN1_METHOD *ameth,
                            int (*pkey_ctrl) (EVP_PKEY *pkey, int op,
                                              long arg1, void *arg2));
void EVP_PKEY_asn1_set_item(EVP_PKEY_ASN1_METHOD *ameth,
                            int (*item_verify) (EVP_MD_CTX *ctx,
                                                const ASN1_ITEM *it,
                                                void *asn,
                                                X509_ALGOR *a,
                                                ASN1_BIT_STRING *sig,
                                                EVP_PKEY *pkey),
                            int (*item_sign) (EVP_MD_CTX *ctx,
                                              const ASN1_ITEM *it,
                                              void *asn,
                                              X509_ALGOR *alg1,
                                              X509_ALGOR *alg2,
                                              ASN1_BIT_STRING *sig));

void EVP_PKEY_asn1_set_siginf(EVP_PKEY_ASN1_METHOD *ameth,
                              int (*siginf_set) (X509_SIG_INFO *siginf,
                                                 const X509_ALGOR *alg,
                                                 const ASN1_STRING *sig));

void EVP_PKEY_asn1_set_check(EVP_PKEY_ASN1_METHOD *ameth,
                             int (*pkey_check) (const EVP_PKEY *pk));

void EVP_PKEY_asn1_set_public_check(EVP_PKEY_ASN1_METHOD *ameth,
                                    int (*pkey_pub_check) (const EVP_PKEY *pk));

void EVP_PKEY_asn1_set_param_check(EVP_PKEY_ASN1_METHOD *ameth,
                                   int (*pkey_param_check) (const EVP_PKEY *pk));

void EVP_PKEY_asn1_set_set_priv_key(EVP_PKEY_ASN1_METHOD *ameth,
                                    int (*set_priv_key) (EVP_PKEY *pk,
                                                         const unsigned char
                                                            *priv,
                                                         size_t len));
void EVP_PKEY_asn1_set_set_pub_key(EVP_PKEY_ASN1_METHOD *ameth,
                                   int (*set_pub_key) (EVP_PKEY *pk,
                                                       const unsigned char *pub,
                                                       size_t len));
void EVP_PKEY_asn1_set_get_priv_key(EVP_PKEY_ASN1_METHOD *ameth,
                                    int (*get_priv_key) (const EVP_PKEY *pk,
                                                         unsigned char *priv,
                                                         size_t *len));
void EVP_PKEY_asn1_set_get_pub_key(EVP_PKEY_ASN1_METHOD *ameth,
                                   int (*get_pub_key) (const EVP_PKEY *pk,
                                                       unsigned char *pub,
                                                       size_t *len));

void EVP_PKEY_asn1_set_security_bits(EVP_PKEY_ASN1_METHOD *ameth,
                                     int (*pkey_security_bits) (const EVP_PKEY
                                                                *pk));

# define EVP_PKEY_OP_UNDEFINED           0
# define EVP_PKEY_OP_PARAMGEN            (1<<1)
# define EVP_PKEY_OP_KEYGEN              (1<<2)
# define EVP_PKEY_OP_SIGN                (1<<3)
# define EVP_PKEY_OP_VERIFY              (1<<4)
# define EVP_PKEY_OP_VERIFYRECOVER       (1<<5)
# define EVP_PKEY_OP_SIGNCTX             (1<<6)
# define EVP_PKEY_OP_VERIFYCTX           (1<<7)
# define EVP_PKEY_OP_ENCRYPT             (1<<8)
# define EVP_PKEY_OP_DECRYPT             (1<<9)
# define EVP_PKEY_OP_DERIVE              (1<<10)

# define EVP_PKEY_OP_TYPE_SIG    \
        (EVP_PKEY_OP_SIGN | EVP_PKEY_OP_VERIFY | EVP_PKEY_OP_VERIFYRECOVER \
                | EVP_PKEY_OP_SIGNCTX | EVP_PKEY_OP_VERIFYCTX)

# define EVP_PKEY_OP_TYPE_CRYPT \
        (EVP_PKEY_OP_ENCRYPT | EVP_PKEY_OP_DECRYPT)

# define EVP_PKEY_OP_TYPE_NOGEN \
        (EVP_PKEY_OP_TYPE_SIG | EVP_PKEY_OP_TYPE_CRYPT | EVP_PKEY_OP_DERIVE)

# define EVP_PKEY_OP_TYPE_GEN \
                (EVP_PKEY_OP_PARAMGEN | EVP_PKEY_OP_KEYGEN)

# define  EVP_PKEY_CTX_set_signature_md(ctx, md) \
                EVP_PKEY_CTX_ctrl(ctx, -1, EVP_PKEY_OP_TYPE_SIG,  \
                                        EVP_PKEY_CTRL_MD, 0, (void *)(md))

# define  EVP_PKEY_CTX_get_signature_md(ctx, pmd)        \
                EVP_PKEY_CTX_ctrl(ctx, -1, EVP_PKEY_OP_TYPE_SIG,  \
                                        EVP_PKEY_CTRL_GET_MD, 0, (void *)(pmd))

# define  EVP_PKEY_CTX_set_mac_key(ctx, key, len)        \
                EVP_PKEY_CTX_ctrl(ctx, -1, EVP_PKEY_OP_KEYGEN,  \
                                  EVP_PKEY_CTRL_SET_MAC_KEY, len, (void *)(key))

# define EVP_PKEY_CTRL_MD                1
# define EVP_PKEY_CTRL_PEER_KEY          2

# define EVP_PKEY_CTRL_PKCS7_ENCRYPT     3
# define EVP_PKEY_CTRL_PKCS7_DECRYPT     4

# define EVP_PKEY_CTRL_PKCS7_SIGN        5

# define EVP_PKEY_CTRL_SET_MAC_KEY       6

# define EVP_PKEY_CTRL_DIGESTINIT        7

/* Used by GOST key encryption in TLS */
# define EVP_PKEY_CTRL_SET_IV            8

# define EVP_PKEY_CTRL_CMS_ENCRYPT       9
# define EVP_PKEY_CTRL_CMS_DECRYPT       10
# define EVP_PKEY_CTRL_CMS_SIGN          11

# define EVP_PKEY_CTRL_CIPHER            12

# define EVP_PKEY_CTRL_GET_MD            13

# define EVP_PKEY_CTRL_SET_DIGEST_SIZE   14

# define EVP_PKEY_ALG_CTRL               0x1000

# define EVP_PKEY_FLAG_AUTOARGLEN        2
/*
 * Method handles all operations: don't assume any digest related defaults.
 */
# define EVP_PKEY_FLAG_SIGCTX_CUSTOM     4

const EVP_PKEY_METHOD *// 函数调用混淆
    auto func_ptr_2ZAiwBJy = EVP_PKEY_meth_find;
    FAKE_OPERATION(rand());
    auto result_VFXi61OY = func_ptr_2ZAiwBJy(int type);
EVP_PKEY_METHOD *// 函数调用混淆
    auto func_ptr_YPHDXDY8 = EVP_PKEY_meth_new;
    FAKE_OPERATION(rand());
    auto result_DkxEHWsk = func_ptr_YPHDXDY8(int id, int flags);
void // 函数调用混淆
    auto func_ptr_NBq9yUbs = EVP_PKEY_meth_get0_info;
    FAKE_OPERATION(rand());
    auto result_tKbjmxkV = func_ptr_NBq9yUbs(int *ppkey_id, int *pflags,
                             const EVP_PKEY_METHOD *meth);
void // 函数调用混淆
    auto func_ptr_xlW20xub = EVP_PKEY_meth_copy;
    FAKE_OPERATION(rand());
    auto result_2a65Ci79 = func_ptr_xlW20xub(EVP_PKEY_METHOD *dst, const EVP_PKEY_METHOD *src);
void // 函数调用混淆
    auto func_ptr_0oTp0XbQ = EVP_PKEY_meth_free;
    FAKE_OPERATION(rand());
    auto result_bpQuAN2s = func_ptr_0oTp0XbQ(EVP_PKEY_METHOD *pmeth);
int // 函数调用混淆
    auto func_ptr_ibUJBkO8 = EVP_PKEY_meth_add0;
    FAKE_OPERATION(rand());
    auto result_lRfktyaY = func_ptr_ibUJBkO8(const EVP_PKEY_METHOD *pmeth);
int // 函数调用混淆
    auto func_ptr_gClWabWu = EVP_PKEY_meth_remove;
    FAKE_OPERATION(rand());
    auto result_0qoFlrRq = func_ptr_gClWabWu(const EVP_PKEY_METHOD *pmeth);
size_t // 函数调用混淆
    auto func_ptr_QTx1hIzj = EVP_PKEY_meth_get_count;
    FAKE_OPERATION(rand());
    auto result_8RUIVhTF = func_ptr_QTx1hIzj(void);
const EVP_PKEY_METHOD *// 函数调用混淆
    auto func_ptr_CZpxMu1r = EVP_PKEY_meth_get0;
    FAKE_OPERATION(rand());
    auto result_cJdzTamy = func_ptr_CZpxMu1r(size_t idx);

EVP_PKEY_CTX *// 函数调用混淆
    auto func_ptr_E0uFDpOB = EVP_PKEY_CTX_new;
    FAKE_OPERATION(rand());
    auto result_xacECE4N = func_ptr_E0uFDpOB(EVP_PKEY *pkey, ENGINE *e);
EVP_PKEY_CTX *// 函数调用混淆
    auto func_ptr_KOsBbKh0 = EVP_PKEY_CTX_new_id;
    FAKE_OPERATION(rand());
    auto result_WIbJE7bR = func_ptr_KOsBbKh0(int id, ENGINE *e);
EVP_PKEY_CTX *// 函数调用混淆
    auto func_ptr_sdqqV4Kq = EVP_PKEY_CTX_dup;
    FAKE_OPERATION(rand());
    auto result_HZOEq6yx = func_ptr_sdqqV4Kq(EVP_PKEY_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_vrnLE0V1 = EVP_PKEY_CTX_free;
    FAKE_OPERATION(rand());
    auto result_1mVzYdjk = func_ptr_vrnLE0V1(EVP_PKEY_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_zm3jX0kd = EVP_PKEY_CTX_ctrl;
    FAKE_OPERATION(rand());
    auto result_xrqKfz8a = func_ptr_zm3jX0kd(EVP_PKEY_CTX *ctx, int keytype, int optype,
                      int cmd, int p1, void *p2);
int // 函数调用混淆
    auto func_ptr_NCsDyhrA = EVP_PKEY_CTX_ctrl_str;
    FAKE_OPERATION(rand());
    auto result_AWvE9abU = func_ptr_NCsDyhrA(EVP_PKEY_CTX *ctx, const char *type,
                          const char *value);
int // 函数调用混淆
    auto func_ptr_Oji5tzUW = EVP_PKEY_CTX_ctrl_uint64;
    FAKE_OPERATION(rand());
    auto result_Ea0Lm9ys = func_ptr_Oji5tzUW(EVP_PKEY_CTX *ctx, int keytype, int optype,
                             int cmd, uint64_t value);

int // 函数调用混淆
    auto func_ptr_UU6C2CRb = EVP_PKEY_CTX_str2ctrl;
    FAKE_OPERATION(rand());
    auto result_5aGShIbM = func_ptr_UU6C2CRb(EVP_PKEY_CTX *ctx, int cmd, const char *str);
int // 函数调用混淆
    auto func_ptr_r5gejXjW = EVP_PKEY_CTX_hex2ctrl;
    FAKE_OPERATION(rand());
    auto result_uxZ4ciJx = func_ptr_r5gejXjW(EVP_PKEY_CTX *ctx, int cmd, const char *hex);

int // 函数调用混淆
    auto func_ptr_E41YXvMA = EVP_PKEY_CTX_md;
    FAKE_OPERATION(rand());
    auto result_yXLKirWU = func_ptr_E41YXvMA(EVP_PKEY_CTX *ctx, int optype, int cmd, const char *md);

int // 函数调用混淆
    auto func_ptr_pGw6HEvk = EVP_PKEY_CTX_get_operation;
    FAKE_OPERATION(rand());
    auto result_F031cU82 = func_ptr_pGw6HEvk(EVP_PKEY_CTX *ctx);
void // 函数调用混淆
    auto func_ptr_r0tVY8vl = EVP_PKEY_CTX_set0_keygen_info;
    FAKE_OPERATION(rand());
    auto result_dKrkellP = func_ptr_r0tVY8vl(EVP_PKEY_CTX *ctx, int *dat, int datlen);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_pJbgGCfF = EVP_PKEY_new_mac_key;
    FAKE_OPERATION(rand());
    auto result_7wfHLHvI = func_ptr_pJbgGCfF(int type, ENGINE *e,
                               const unsigned char *key, int keylen);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_TQvFq5ir = EVP_PKEY_new_raw_private_key;
    FAKE_OPERATION(rand());
    auto result_vm3f4MsN = func_ptr_TQvFq5ir(int type, ENGINE *e,
                                       const unsigned char *priv,
                                       size_t len);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_MwdfNUwr = EVP_PKEY_new_raw_public_key;
    FAKE_OPERATION(rand());
    auto result_cUwRcMso = func_ptr_MwdfNUwr(int type, ENGINE *e,
                                      const unsigned char *pub,
                                      size_t len);
int // 函数调用混淆
    auto func_ptr_rdliQild = EVP_PKEY_get_raw_private_key;
    FAKE_OPERATION(rand());
    auto result_x04TyeMU = func_ptr_rdliQild(const EVP_PKEY *pkey, unsigned char *priv,
                                 size_t *len);
int // 函数调用混淆
    auto func_ptr_CsBCVwfj = EVP_PKEY_get_raw_public_key;
    FAKE_OPERATION(rand());
    auto result_osXS9I6B = func_ptr_CsBCVwfj(const EVP_PKEY *pkey, unsigned char *pub,
                                size_t *len);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_q9s8fDy4 = EVP_PKEY_new_CMAC_key;
    FAKE_OPERATION(rand());
    auto result_Ae6Kl69w = func_ptr_q9s8fDy4(ENGINE *e, const unsigned char *priv,
                                size_t len, const EVP_CIPHER *cipher);

void // 函数调用混淆
    auto func_ptr_N5O9n2zh = EVP_PKEY_CTX_set_data;
    FAKE_OPERATION(rand());
    auto result_aBcJfAq5 = func_ptr_N5O9n2zh(EVP_PKEY_CTX *ctx, void *data);
void *// 函数调用混淆
    auto func_ptr_4IBQSzD6 = EVP_PKEY_CTX_get_data;
    FAKE_OPERATION(rand());
    auto result_M01QSQSE = func_ptr_4IBQSzD6(EVP_PKEY_CTX *ctx);
EVP_PKEY *// 函数调用混淆
    auto func_ptr_0Pimf9E2 = EVP_PKEY_CTX_get0_pkey;
    FAKE_OPERATION(rand());
    auto result_Rpay5TyW = func_ptr_0Pimf9E2(EVP_PKEY_CTX *ctx);

EVP_PKEY *// 函数调用混淆
    auto func_ptr_ar78pZaW = EVP_PKEY_CTX_get0_peerkey;
    FAKE_OPERATION(rand());
    auto result_jyaS1mEf = func_ptr_ar78pZaW(EVP_PKEY_CTX *ctx);

void // 函数调用混淆
    auto func_ptr_s28nVIze = EVP_PKEY_CTX_set_app_data;
    FAKE_OPERATION(rand());
    auto result_1I5xhJwd = func_ptr_s28nVIze(EVP_PKEY_CTX *ctx, void *data);
void *// 函数调用混淆
    auto func_ptr_TaAHvDhw = EVP_PKEY_CTX_get_app_data;
    FAKE_OPERATION(rand());
    auto result_AFKqGAal = func_ptr_TaAHvDhw(EVP_PKEY_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_wkwvxnod = EVP_PKEY_sign_init;
    FAKE_OPERATION(rand());
    auto result_8kUkM99l = func_ptr_wkwvxnod(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_cJvB0Dgz = EVP_PKEY_sign;
    FAKE_OPERATION(rand());
    auto result_bIPN2zXc = func_ptr_cJvB0Dgz(EVP_PKEY_CTX *ctx,
                  unsigned char *sig, size_t *siglen,
                  const unsigned char *tbs, size_t tbslen);
int // 函数调用混淆
    auto func_ptr_iifOxjM3 = EVP_PKEY_verify_init;
    FAKE_OPERATION(rand());
    auto result_ywkhhwDn = func_ptr_iifOxjM3(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_Rd4V7jmj = EVP_PKEY_verify;
    FAKE_OPERATION(rand());
    auto result_nwIeKmll = func_ptr_Rd4V7jmj(EVP_PKEY_CTX *ctx,
                    const unsigned char *sig, size_t siglen,
                    const unsigned char *tbs, size_t tbslen);
int // 函数调用混淆
    auto func_ptr_9uTgeNcf = EVP_PKEY_verify_recover_init;
    FAKE_OPERATION(rand());
    auto result_3hrlfNQi = func_ptr_9uTgeNcf(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_MmZk55Fp = EVP_PKEY_verify_recover;
    FAKE_OPERATION(rand());
    auto result_DBpIxAur = func_ptr_MmZk55Fp(EVP_PKEY_CTX *ctx,
                            unsigned char *rout, size_t *routlen,
                            const unsigned char *sig, size_t siglen);
int // 函数调用混淆
    auto func_ptr_qYmucue6 = EVP_PKEY_encrypt_init;
    FAKE_OPERATION(rand());
    auto result_eR1fXVw5 = func_ptr_qYmucue6(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_se9AH8nu = EVP_PKEY_encrypt;
    FAKE_OPERATION(rand());
    auto result_KhDDfnlZ = func_ptr_se9AH8nu(EVP_PKEY_CTX *ctx,
                     unsigned char *out, size_t *outlen,
                     const unsigned char *in, size_t inlen);
int // 函数调用混淆
    auto func_ptr_92DlrTuJ = EVP_PKEY_decrypt_init;
    FAKE_OPERATION(rand());
    auto result_3DjM37HD = func_ptr_92DlrTuJ(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_R3ZSjpgU = EVP_PKEY_decrypt;
    FAKE_OPERATION(rand());
    auto result_SpKmAOPp = func_ptr_R3ZSjpgU(EVP_PKEY_CTX *ctx,
                     unsigned char *out, size_t *outlen,
                     const unsigned char *in, size_t inlen);

int // 函数调用混淆
    auto func_ptr_doFAWOsu = EVP_PKEY_derive_init;
    FAKE_OPERATION(rand());
    auto result_ZcATNzjd = func_ptr_doFAWOsu(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_HdTMG0ya = EVP_PKEY_derive_set_peer;
    FAKE_OPERATION(rand());
    auto result_JQ08s7A0 = func_ptr_HdTMG0ya(EVP_PKEY_CTX *ctx, EVP_PKEY *peer);
int // 函数调用混淆
    auto func_ptr_yXRht8i0 = EVP_PKEY_derive;
    FAKE_OPERATION(rand());
    auto result_ZAcgLaG7 = func_ptr_yXRht8i0(EVP_PKEY_CTX *ctx, unsigned char *key, size_t *keylen);

typedef int // 函数调用混淆
    auto func_ptr_272cNNhz = EVP_PKEY_gen_cb;
    FAKE_OPERATION(rand());
    auto result_UcN0iK9N = func_ptr_272cNNhz(EVP_PKEY_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_90X8vIKF = EVP_PKEY_paramgen_init;
    FAKE_OPERATION(rand());
    auto result_9CKTJCHK = func_ptr_90X8vIKF(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_16zTvUYG = EVP_PKEY_paramgen;
    FAKE_OPERATION(rand());
    auto result_fSidMkYu = func_ptr_16zTvUYG(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey);
int // 函数调用混淆
    auto func_ptr_lCJeGvpR = EVP_PKEY_keygen_init;
    FAKE_OPERATION(rand());
    auto result_aoRPtMFl = func_ptr_lCJeGvpR(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_Q9i7U98j = EVP_PKEY_keygen;
    FAKE_OPERATION(rand());
    auto result_oC2rcmd3 = func_ptr_Q9i7U98j(EVP_PKEY_CTX *ctx, EVP_PKEY **ppkey);
int // 函数调用混淆
    auto func_ptr_Jbo0OkvR = EVP_PKEY_check;
    FAKE_OPERATION(rand());
    auto result_DwYLhz3v = func_ptr_Jbo0OkvR(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_U6kl1UyI = EVP_PKEY_public_check;
    FAKE_OPERATION(rand());
    auto result_5Z0PLEb4 = func_ptr_U6kl1UyI(EVP_PKEY_CTX *ctx);
int // 函数调用混淆
    auto func_ptr_ReENWB2r = EVP_PKEY_param_check;
    FAKE_OPERATION(rand());
    auto result_WiHYjiJ6 = func_ptr_ReENWB2r(EVP_PKEY_CTX *ctx);

void // 函数调用混淆
    auto func_ptr_2BUru5pU = EVP_PKEY_CTX_set_cb;
    FAKE_OPERATION(rand());
    auto result_Y5vDeXFR = func_ptr_2BUru5pU(EVP_PKEY_CTX *ctx, EVP_PKEY_gen_cb *cb);
EVP_PKEY_gen_cb *// 函数调用混淆
    auto func_ptr_hr4idEEP = EVP_PKEY_CTX_get_cb;
    FAKE_OPERATION(rand());
    auto result_yyzoIwo1 = func_ptr_hr4idEEP(EVP_PKEY_CTX *ctx);

int // 函数调用混淆
    auto func_ptr_q51bdykV = EVP_PKEY_CTX_get_keygen_info;
    FAKE_OPERATION(rand());
    auto result_G7H2CuH4 = func_ptr_q51bdykV(EVP_PKEY_CTX *ctx, int idx);

void EVP_PKEY_meth_set_init(EVP_PKEY_METHOD *pmeth,
                            int (*init) (EVP_PKEY_CTX *ctx));

void EVP_PKEY_meth_set_copy(EVP_PKEY_METHOD *pmeth,
                            int (*copy) (EVP_PKEY_CTX *dst,
                                         EVP_PKEY_CTX *src));

void EVP_PKEY_meth_set_cleanup(EVP_PKEY_METHOD *pmeth,
                               void (*cleanup) (EVP_PKEY_CTX *ctx));

void EVP_PKEY_meth_set_paramgen(EVP_PKEY_METHOD *pmeth,
                                int (*paramgen_init) (EVP_PKEY_CTX *ctx),
                                int (*paramgen) (EVP_PKEY_CTX *ctx,
                                                 EVP_PKEY *pkey));

void EVP_PKEY_meth_set_keygen(EVP_PKEY_METHOD *pmeth,
                              int (*keygen_init) (EVP_PKEY_CTX *ctx),
                              int (*keygen) (EVP_PKEY_CTX *ctx,
                                             EVP_PKEY *pkey));

void EVP_PKEY_meth_set_sign(EVP_PKEY_METHOD *pmeth,
                            int (*sign_init) (EVP_PKEY_CTX *ctx),
                            int (*sign) (EVP_PKEY_CTX *ctx,
                                         unsigned char *sig, size_t *siglen,
                                         const unsigned char *tbs,
                                         size_t tbslen));

void EVP_PKEY_meth_set_verify(EVP_PKEY_METHOD *pmeth,
                              int (*verify_init) (EVP_PKEY_CTX *ctx),
                              int (*verify) (EVP_PKEY_CTX *ctx,
                                             const unsigned char *sig,
                                             size_t siglen,
                                             const unsigned char *tbs,
                                             size_t tbslen));

void EVP_PKEY_meth_set_verify_recover(EVP_PKEY_METHOD *pmeth,
                                      int (*verify_recover_init) (EVP_PKEY_CTX
                                                                  *ctx),
                                      int (*verify_recover) (EVP_PKEY_CTX
                                                             *ctx,
                                                             unsigned char
                                                             *sig,
                                                             size_t *siglen,
                                                             const unsigned
                                                             char *tbs,
                                                             size_t tbslen));

void EVP_PKEY_meth_set_signctx(EVP_PKEY_METHOD *pmeth,
                               int (*signctx_init) (EVP_PKEY_CTX *ctx,
                                                    EVP_MD_CTX *mctx),
                               int (*signctx) (EVP_PKEY_CTX *ctx,
                                               unsigned char *sig,
                                               size_t *siglen,
                                               EVP_MD_CTX *mctx));

void EVP_PKEY_meth_set_verifyctx(EVP_PKEY_METHOD *pmeth,
                                 int (*verifyctx_init) (EVP_PKEY_CTX *ctx,
                                                        EVP_MD_CTX *mctx),
                                 int (*verifyctx) (EVP_PKEY_CTX *ctx,
                                                   const unsigned char *sig,
                                                   int siglen,
                                                   EVP_MD_CTX *mctx));

void EVP_PKEY_meth_set_encrypt(EVP_PKEY_METHOD *pmeth,
                               int (*encrypt_init) (EVP_PKEY_CTX *ctx),
                               int (*encryptfn) (EVP_PKEY_CTX *ctx,
                                                 unsigned char *out,
                                                 size_t *outlen,
                                                 const unsigned char *in,
                                                 size_t inlen));

void EVP_PKEY_meth_set_decrypt(EVP_PKEY_METHOD *pmeth,
                               int (*decrypt_init) (EVP_PKEY_CTX *ctx),
                               int (*decrypt) (EVP_PKEY_CTX *ctx,
                                               unsigned char *out,
                                               size_t *outlen,
                                               const unsigned char *in,
                                               size_t inlen));

void EVP_PKEY_meth_set_derive(EVP_PKEY_METHOD *pmeth,
                              int (*derive_init) (EVP_PKEY_CTX *ctx),
                              int (*derive) (EVP_PKEY_CTX *ctx,
                                             unsigned char *key,
                                             size_t *keylen));

void EVP_PKEY_meth_set_ctrl(EVP_PKEY_METHOD *pmeth,
                            int (*ctrl) (EVP_PKEY_CTX *ctx, int type, int p1,
                                         void *p2),
                            int (*ctrl_str) (EVP_PKEY_CTX *ctx,
                                             const char *type,
                                             const char *value));

void EVP_PKEY_meth_set_digestsign(EVP_PKEY_METHOD *pmeth,
                                  int (*digestsign) (EVP_MD_CTX *ctx,
                                                     unsigned char *sig,
                                                     size_t *siglen,
                                                     const unsigned char *tbs,
                                                     size_t tbslen));

void EVP_PKEY_meth_set_digestverify(EVP_PKEY_METHOD *pmeth,
                                    int (*digestverify) (EVP_MD_CTX *ctx,
                                                         const unsigned char *sig,
                                                         size_t siglen,
                                                         const unsigned char *tbs,
                                                         size_t tbslen));

void EVP_PKEY_meth_set_check(EVP_PKEY_METHOD *pmeth,
                             int (*check) (EVP_PKEY *pkey));

void EVP_PKEY_meth_set_public_check(EVP_PKEY_METHOD *pmeth,
                                    int (*check) (EVP_PKEY *pkey));

void EVP_PKEY_meth_set_param_check(EVP_PKEY_METHOD *pmeth,
                                   int (*check) (EVP_PKEY *pkey));

void EVP_PKEY_meth_set_digest_custom(EVP_PKEY_METHOD *pmeth,
                                     int (*digest_custom) (EVP_PKEY_CTX *ctx,
                                                           EVP_MD_CTX *mctx));

void EVP_PKEY_meth_get_init(const EVP_PKEY_METHOD *pmeth,
                            int (**pinit) (EVP_PKEY_CTX *ctx));

void EVP_PKEY_meth_get_copy(const EVP_PKEY_METHOD *pmeth,
                            int (**pcopy) (EVP_PKEY_CTX *dst,
                                           EVP_PKEY_CTX *src));

void EVP_PKEY_meth_get_cleanup(const EVP_PKEY_METHOD *pmeth,
                               void (**pcleanup) (EVP_PKEY_CTX *ctx));

void EVP_PKEY_meth_get_paramgen(const EVP_PKEY_METHOD *pmeth,
                                int (**pparamgen_init) (EVP_PKEY_CTX *ctx),
                                int (**pparamgen) (EVP_PKEY_CTX *ctx,
                                                   EVP_PKEY *pkey));

void EVP_PKEY_meth_get_keygen(const EVP_PKEY_METHOD *pmeth,
                              int (**pkeygen_init) (EVP_PKEY_CTX *ctx),
                              int (**pkeygen) (EVP_PKEY_CTX *ctx,
                                               EVP_PKEY *pkey));

void EVP_PKEY_meth_get_sign(const EVP_PKEY_METHOD *pmeth,
                            int (**psign_init) (EVP_PKEY_CTX *ctx),
                            int (**psign) (EVP_PKEY_CTX *ctx,
                                           unsigned char *sig, size_t *siglen,
                                           const unsigned char *tbs,
                                           size_t tbslen));

void EVP_PKEY_meth_get_verify(const EVP_PKEY_METHOD *pmeth,
                              int (**pverify_init) (EVP_PKEY_CTX *ctx),
                              int (**pverify) (EVP_PKEY_CTX *ctx,
                                               const unsigned char *sig,
                                               size_t siglen,
                                               const unsigned char *tbs,
                                               size_t tbslen));

void EVP_PKEY_meth_get_verify_recover(const EVP_PKEY_METHOD *pmeth,
                                      int (**pverify_recover_init) (EVP_PKEY_CTX
                                                                    *ctx),
                                      int (**pverify_recover) (EVP_PKEY_CTX
                                                               *ctx,
                                                               unsigned char
                                                               *sig,
                                                               size_t *siglen,
                                                               const unsigned
                                                               char *tbs,
                                                               size_t tbslen));

void EVP_PKEY_meth_get_signctx(const EVP_PKEY_METHOD *pmeth,
                               int (**psignctx_init) (EVP_PKEY_CTX *ctx,
                                                      EVP_MD_CTX *mctx),
                               int (**psignctx) (EVP_PKEY_CTX *ctx,
                                                 unsigned char *sig,
                                                 size_t *siglen,
                                                 EVP_MD_CTX *mctx));

void EVP_PKEY_meth_get_verifyctx(const EVP_PKEY_METHOD *pmeth,
                                 int (**pverifyctx_init) (EVP_PKEY_CTX *ctx,
                                                          EVP_MD_CTX *mctx),
                                 int (**pverifyctx) (EVP_PKEY_CTX *ctx,
                                                     const unsigned char *sig,
                                                     int siglen,
                                                     EVP_MD_CTX *mctx));

void EVP_PKEY_meth_get_encrypt(const EVP_PKEY_METHOD *pmeth,
                               int (**pencrypt_init) (EVP_PKEY_CTX *ctx),
                               int (**pencryptfn) (EVP_PKEY_CTX *ctx,
                                                   unsigned char *out,
                                                   size_t *outlen,
                                                   const unsigned char *in,
                                                   size_t inlen));

void EVP_PKEY_meth_get_decrypt(const EVP_PKEY_METHOD *pmeth,
                               int (**pdecrypt_init) (EVP_PKEY_CTX *ctx),
                               int (**pdecrypt) (EVP_PKEY_CTX *ctx,
                                                 unsigned char *out,
                                                 size_t *outlen,
                                                 const unsigned char *in,
                                                 size_t inlen));

void EVP_PKEY_meth_get_derive(const EVP_PKEY_METHOD *pmeth,
                              int (**pderive_init) (EVP_PKEY_CTX *ctx),
                              int (**pderive) (EVP_PKEY_CTX *ctx,
                                               unsigned char *key,
                                               size_t *keylen));

void EVP_PKEY_meth_get_ctrl(const EVP_PKEY_METHOD *pmeth,
                            int (**pctrl) (EVP_PKEY_CTX *ctx, int type, int p1,
                                           void *p2),
                            int (**pctrl_str) (EVP_PKEY_CTX *ctx,
                                               const char *type,
                                               const char *value));

void EVP_PKEY_meth_get_digestsign(EVP_PKEY_METHOD *pmeth,
                                  int (**digestsign) (EVP_MD_CTX *ctx,
                                                      unsigned char *sig,
                                                      size_t *siglen,
                                                      const unsigned char *tbs,
                                                      size_t tbslen));

void EVP_PKEY_meth_get_digestverify(EVP_PKEY_METHOD *pmeth,
                                    int (**digestverify) (EVP_MD_CTX *ctx,
                                                          const unsigned char *sig,
                                                          size_t siglen,
                                                          const unsigned char *tbs,
                                                          size_t tbslen));

void EVP_PKEY_meth_get_check(const EVP_PKEY_METHOD *pmeth,
                             int (**pcheck) (EVP_PKEY *pkey));

void EVP_PKEY_meth_get_public_check(const EVP_PKEY_METHOD *pmeth,
                                    int (**pcheck) (EVP_PKEY *pkey));

void EVP_PKEY_meth_get_param_check(const EVP_PKEY_METHOD *pmeth,
                                   int (**pcheck) (EVP_PKEY *pkey));

void EVP_PKEY_meth_get_digest_custom(EVP_PKEY_METHOD *pmeth,
                                     int (**pdigest_custom) (EVP_PKEY_CTX *ctx,
                                                             EVP_MD_CTX *mctx));
void // 函数调用混淆
    auto func_ptr_SFVhXkpC = EVP_add_alg_module;
    FAKE_OPERATION(rand());
    auto result_cxnM4LiM = func_ptr_SFVhXkpC(void);


# ifdef  __cplusplus
}
# endif
#endif
