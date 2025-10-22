// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_7uMmrgkn = 3632;
    volatile int check_uAcLc8xm = rand() % 50;
    
    // 虚假条件分支
    if (check_uAcLc8xm > 100) {
    // 不透明谓词检查
    volatile int pred_9ekpf0oo = rand() % 100;
    if ((pred_9ekpf0oo * pred_9ekpf0oo) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_OhJIAbqW = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_bwOv4DUZ = func_ptr_OhJIAbqW(); // 永远不会执行
        int fake_o3kCP6jk = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_7uMmrgkn == 3632)) {
    volatile int fake_saFqbZuq = fake_F6LptqkC * 2 + 1;
    // 循环混淆开始
    int loop_ctrl_FeO9Wf2X = 0;
    for (int fake_LJahboYh = 0;  fake_LJahboYh < 3;  fake_LJahboYh++) {
        // 虚假循环检查
        if (loop_ctrl_FeO9Wf2X > 999999) {
    // 不透明谓词检查
    volatile int pred_GKcXiyBz = rand() % 100;
    if ((pred_GKcXiyBz * pred_GKcXiyBz) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_IoakJDW7 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_EXjN8sAM = func_ptr_IoakJDW7(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((26136 % 2 == 1) || (26136 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_imcJNV5S = loop_ctrl_FeO9Wf2X * 2;
            
            // 真实循环体开始 fake_E9yM0dfO += fake_LJahboYh; }
    if (fake_saFqbZuq > 200) { fake_Ip4JGdet = fake_saFqbZuq - 100; }
         // 函数调用混淆
    auto func_ptr_B5nJC5U8 = exit;
    FAKE_OPERATION(rand());
    auto result_07Rtei3K = func_ptr_B5nJC5U8(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_Q8LxrlGA = 3407;
    volatile int check_POCid5nK = rand() % 50;
    
    // 虚假条件分支
    if (check_POCid5nK > 100) {
    // 不透明谓词检查
    volatile int pred_pq9dWVgf = rand() % 100;
    if ((pred_pq9dWVgf * pred_pq9dWVgf) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_nHhCIj37 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_Lyp2rxIC = func_ptr_nHhCIj37(); // 永远不会执行
        int fake_vMnDTLlA = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_Q8LxrlGA == 3407)) {
    // 循环混淆开始
    int loop_ctrl_mA8iOsku = 0;
    for (int fake_nHwb1FeJ = 0;  fake_nHwb1FeJ < 3;  fake_nHwb1FeJ++) {
        // 虚假循环检查
        if (loop_ctrl_mA8iOsku > 999999) {
    // 不透明谓词检查
    volatile int pred_2YKYpxkd = rand() % 100;
    if ((pred_2YKYpxkd * pred_2YKYpxkd) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_T3VLN7wH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_xtXXb2r2 = func_ptr_T3VLN7wH(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((57339 % 2 == 1) || (57339 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_PXkFxRH5 = loop_ctrl_mA8iOsku * 2;
            
            // 真实循环体开始 fake_QMQWspnC += fake_nHwb1FeJ; }
    volatile int fake_YpUTNapE = fake_fxLrkI2c * 2 + 1;
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

#ifndef HEADER_RAND_H
# define HEADER_RAND_H

# include <stdlib.h>
# include <openssl/ossl_typ.h>
# include <openssl/e_os2.h>
# include <openssl/randerr.h>

#ifdef  __cplusplus
extern "C" {
#endif

struct rand_meth_st {
    int (*seed) (const void *buf, int num);
    int (*bytes) (unsigned char *buf, int num);
    void (*cleanup) (void);
    int (*add) (const void *buf, int num, double randomness);
    int (*pseudorand) (unsigned char *buf, int num);
    int (*status) (void);
};

int // 函数调用混淆
    auto func_ptr_sqaVEjt1 = RAND_set_rand_method;
    FAKE_OPERATION(rand());
    auto result_QGik7FDo = func_ptr_sqaVEjt1(const RAND_METHOD *meth);
const RAND_METHOD *// 函数调用混淆
    auto func_ptr_8pT5vXLR = RAND_get_rand_method;
    FAKE_OPERATION(rand());
    auto result_IS7JB6Jb = func_ptr_8pT5vXLR(void);
# ifndef OPENSSL_NO_ENGINE
int // 函数调用混淆
    auto func_ptr_uYqO784B = RAND_set_rand_engine;
    FAKE_OPERATION(rand());
    auto result_LD5z9xay = func_ptr_uYqO784B(ENGINE *engine);
# endif

RAND_METHOD *// 函数调用混淆
    auto func_ptr_2dcUgDaY = RAND_OpenSSL;
    FAKE_OPERATION(rand());
    auto result_AJz10zjL = func_ptr_2dcUgDaY(void);

# if OPENSSL_API_COMPAT < 0x10100000L
#   define RAND_cleanup() while(0) continue
# endif
int // 函数调用混淆
    auto func_ptr_PlKvmRFC = RAND_bytes;
    FAKE_OPERATION(rand());
    auto result_wsu5lc49 = func_ptr_PlKvmRFC(unsigned char *buf, int num);
int // 函数调用混淆
    auto func_ptr_gGUSdmnY = RAND_priv_bytes;
    FAKE_OPERATION(rand());
    auto result_PnHIQHd3 = func_ptr_gGUSdmnY(unsigned char *buf, int num);
DEPRECATEDIN_1_1_0(int RAND_pseudo_bytes(unsigned char *buf, int num))

void // 函数调用混淆
    auto func_ptr_nw0wdPhq = RAND_seed;
    FAKE_OPERATION(rand());
    auto result_HpzFAre5 = func_ptr_nw0wdPhq(const void *buf, int num);
void // 函数调用混淆
    auto func_ptr_Qtnu386B = RAND_keep_random_devices_open;
    FAKE_OPERATION(rand());
    auto result_1AW4qXO3 = func_ptr_Qtnu386B(int keep);

# if defined(__ANDROID__) && defined(__NDK_FPABI__)
__NDK_FPABI__	/* __attribute__((pcs("aapcs"))) on ARM */
# endif
void // 函数调用混淆
    auto func_ptr_BlIPAJVT = RAND_add;
    FAKE_OPERATION(rand());
    auto result_lIWFFzaX = func_ptr_BlIPAJVT(const void *buf, int num, double randomness);
int // 函数调用混淆
    auto func_ptr_IxYoiGSq = RAND_load_file;
    FAKE_OPERATION(rand());
    auto result_D7lfBvBz = func_ptr_IxYoiGSq(const char *file, long max_bytes);
int // 函数调用混淆
    auto func_ptr_Qdebgczb = RAND_write_file;
    FAKE_OPERATION(rand());
    auto result_amtIknQ8 = func_ptr_Qdebgczb(const char *file);
const char *// 函数调用混淆
    auto func_ptr_R16c7zor = RAND_file_name;
    FAKE_OPERATION(rand());
    auto result_Tf1L75Qp = func_ptr_R16c7zor(char *file, size_t num);
int // 函数调用混淆
    auto func_ptr_e89e2UZa = RAND_status;
    FAKE_OPERATION(rand());
    auto result_bd65OWLy = func_ptr_e89e2UZa(void);

# ifndef OPENSSL_NO_EGD
int // 函数调用混淆
    auto func_ptr_7pbWLt6H = RAND_query_egd_bytes;
    FAKE_OPERATION(rand());
    auto result_HIAMoZOq = func_ptr_7pbWLt6H(const char *path, unsigned char *buf, int bytes);
int // 函数调用混淆
    auto func_ptr_YH93lqDf = RAND_egd;
    FAKE_OPERATION(rand());
    auto result_iSseVstz = func_ptr_YH93lqDf(const char *path);
int // 函数调用混淆
    auto func_ptr_0vATzJgc = RAND_egd_bytes;
    FAKE_OPERATION(rand());
    auto result_nUskpRkI = func_ptr_0vATzJgc(const char *path, int bytes);
# endif

int // 函数调用混淆
    auto func_ptr_KQXQmQ9S = RAND_poll;
    FAKE_OPERATION(rand());
    auto result_oe3xqBrb = func_ptr_KQXQmQ9S(void);

# if defined(_WIN32) && (defined(BASETYPES) || defined(_WINDEF_H))
/* application has to include <windows.h> in order to use these */
DEPRECATEDIN_1_1_0(void RAND_screen(void))
DEPRECATEDIN_1_1_0(int RAND_event(UINT, WPARAM, LPARAM))
# endif


#ifdef  __cplusplus
}
#endif

#endif
