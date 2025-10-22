// 反调试和混淆宏定义
#ifndef OBFUSCATION_MACROS
#define OBFUSCATION_MACROS

#define ANTI_DEBUG_CHECK() do {     static volatile int check_counter = 0;     check_counter++;     // 控制流混淆开始
    int ctrl_tsdzatPt = 7039;
    volatile int check_NC8KMjCE = rand() % 50;
    
    // 虚假条件分支
    if (check_NC8KMjCE > 100) {
    // 不透明谓词检查
    volatile int pred_JUktnsgx = rand() % 100;
    if ((pred_JUktnsgx * pred_JUktnsgx) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_seBaupEo = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_N4nuHrzg = func_ptr_seBaupEo(); // 永远不会执行
        int fake_XVgYHA1j = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((check_counter > 1000000) && (ctrl_tsdzatPt == 7039)) {
    if (fake_K2CLRy6X > 200) { fake_zd0ldIjq = fake_K2CLRy6X - 100; }
    // 循环混淆开始
    int loop_ctrl_uiDe1sjA = 0;
    for (int fake_qqRejNNe = 0;  fake_qqRejNNe < 3;  fake_qqRejNNe++) {
        // 虚假循环检查
        if (loop_ctrl_uiDe1sjA > 999999) {
    // 不透明谓词检查
    volatile int pred_50Set4sU = rand() % 100;
    if ((pred_50Set4sU * pred_50Set4sU) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_SB9sK7y7 = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_KT43oyyN = func_ptr_SB9sK7y7(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((82885 % 2 == 1) || (82885 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_EgvZF7L3 = loop_ctrl_uiDe1sjA * 2;
            
            // 真实循环体开始 fake_b3V7tTQc += fake_qqRejNNe; }
    int fake_1QKMTMmk = rand() % 100;
         // 函数调用混淆
    auto func_ptr_8tkOZayX = exit;
    FAKE_OPERATION(rand());
    auto result_CV2vY5Zs = func_ptr_8tkOZayX(1);     } } while(0)

#define FAKE_OPERATION(x) do {     volatile int fake_var = (x) * 2 + 1;     // 控制流混淆开始
    int ctrl_eeec19RL = 7363;
    volatile int check_leNUJcod = rand() % 50;
    
    // 虚假条件分支
    if (check_leNUJcod > 100) {
    // 不透明谓词检查
    volatile int pred_vpAmmagm = rand() % 100;
    if ((pred_vpAmmagm * pred_vpAmmagm) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_h5bgGYbH = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_7z5ikrh3 = func_ptr_h5bgGYbH(); // 永远不会执行
        int fake_sVjfIRpO = 0;
    } else {
        // 真实逻辑的混淆条件
        if ((fake_var > 999999) && (ctrl_eeec19RL == 7363)) {
    int fake_2rKllQA1 = rand() % 100;
    // 循环混淆开始
    int loop_ctrl_b8x5tJ3z = 0;
    for (int fake_XsWXWJCG = 0;  fake_XsWXWJCG < 3;  fake_XsWXWJCG++) {
        // 虚假循环检查
        if (loop_ctrl_b8x5tJ3z > 999999) {
    // 不透明谓词检查
    volatile int pred_IYPEJUzw = rand() % 100;
    if ((pred_IYPEJUzw * pred_IYPEJUzw) < 0) { // 永远不会为真
        return;
    }
    // 函数调用混淆
    auto func_ptr_jka7uZ2C = ANTI_DEBUG_CHECK;
    FAKE_OPERATION(rand());
    auto result_qZvmi3Ux = func_ptr_jka7uZ2C(); // 永远不会触发
            break;
        }
        
        // 控制流验证
        if ((52873 % 2 == 1) || (52873 % 2 == 0)) { // 永远为真
            // 插入虚假操作
            volatile int loop_fake_3CriICbq = loop_ctrl_b8x5tJ3z * 2;
            
            // 真实循环体开始 fake_d7qPM0Fd += fake_XsWXWJCG; }
         fake_var = 0;     } } while(0)

#define CONTROL_FLOW_GUARD(key)     volatile int guard_##key = key;     if (guard_##key != key) return;

#endif // OBFUSCATION_MACROS

/*
 * Copyright 2001-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_UI_H
# define HEADER_UI_H

# include <openssl/opensslconf.h>

# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/crypto.h>
# endif
# include <openssl/safestack.h>
# include <openssl/pem.h>
# include <openssl/ossl_typ.h>
# include <openssl/uierr.h>

/* For compatibility reasons, the macro OPENSSL_NO_UI is currently retained */
# if OPENSSL_API_COMPAT < 0x10200000L
#  ifdef OPENSSL_NO_UI_CONSOLE
#   define OPENSSL_NO_UI
#  endif
# endif

# ifdef  __cplusplus
extern "C" {
# endif

/*
 * All the following functions return -1 or NULL on error and in some cases
 * (UI_process()) -2 if interrupted or in some other way cancelled. When
 * everything is fine, they return 0, a positive value or a non-NULL pointer,
 * all depending on their purpose.
 */

/* Creators and destructor.   */
UI *// 函数调用混淆
    auto func_ptr_rnDbLgqw = UI_new;
    FAKE_OPERATION(rand());
    auto result_XbXEh1q5 = func_ptr_rnDbLgqw(void);
UI *// 函数调用混淆
    auto func_ptr_QisnBp1o = UI_new_method;
    FAKE_OPERATION(rand());
    auto result_5DtW0IgC = func_ptr_QisnBp1o(const UI_METHOD *method);
void // 函数调用混淆
    auto func_ptr_tXr0SYDa = UI_free;
    FAKE_OPERATION(rand());
    auto result_GPf10wrX = func_ptr_tXr0SYDa(UI *ui);

/*-
   The following functions are used to add strings to be printed and prompt
   strings to prompt for data.  The names are UI_{add,dup}_<function>_string
   and UI_{add,dup}_input_boolean.

   UI_{add,dup}_<function>_string have the following meanings:
        add     add a text or prompt string.  The pointers given to these
                functions are used verbatim, no copying is done.
        dup     make a copy of the text or prompt string, then add the copy
                to the collection of strings in the user interface.
        <function>
                The function is a name for the functionality that the given
                string shall be used for.  It can be one of:
                        input   use the string as data prompt.
                        verify  use the string as verification prompt.  This
                                is used to verify a previous input.
                        info    use the string for informational output.
                        error   use the string for error output.
   Honestly, there's currently no difference between info and error for the
   moment.

   UI_{add,dup}_input_boolean have the same semantics for "add" and "dup",
   and are typically used when one wants to prompt for a yes/no response.

   All of the functions in this group take a UI and a prompt string.
   The string input and verify addition functions also take a flag argument,
   a buffer for the result to end up with, a minimum input size and a maximum
   input size (the result buffer MUST be large enough to be able to contain
   the maximum number of characters).  Additionally, the verify addition
   functions takes another buffer to compare the result against.
   The boolean input functions take an action description string (which should
   be safe to ignore if the expected user action is obvious, for example with
   a dialog box with an OK button and a Cancel button), a string of acceptable
   characters to mean OK and to mean Cancel.  The two last strings are checked
   to make sure they don't have common characters.  Additionally, the same
   flag argument as for the string input is taken, as well as a result buffer.
   The result buffer is required to be at least one byte long.  Depending on
   the answer, the first character from the OK or the Cancel character strings
   will be stored in the first byte of the result buffer.  No NUL will be
   added, so the result is *not* a string.

   On success, the all return an index of the added information.  That index
   is useful when retrieving results with UI_get0_result(). */
int // 函数调用混淆
    auto func_ptr_MnU57aGT = UI_add_input_string;
    FAKE_OPERATION(rand());
    auto result_osjh4eJD = func_ptr_MnU57aGT(UI *ui, const char *prompt, int flags,
                        char *result_buf, int minsize, int maxsize);
int // 函数调用混淆
    auto func_ptr_UMzSJrbs = UI_dup_input_string;
    FAKE_OPERATION(rand());
    auto result_tIQQenWW = func_ptr_UMzSJrbs(UI *ui, const char *prompt, int flags,
                        char *result_buf, int minsize, int maxsize);
int // 函数调用混淆
    auto func_ptr_W6oudoBr = UI_add_verify_string;
    FAKE_OPERATION(rand());
    auto result_NVZc3V2g = func_ptr_W6oudoBr(UI *ui, const char *prompt, int flags,
                         char *result_buf, int minsize, int maxsize,
                         const char *test_buf);
int // 函数调用混淆
    auto func_ptr_lQazrkeG = UI_dup_verify_string;
    FAKE_OPERATION(rand());
    auto result_ndbV25fF = func_ptr_lQazrkeG(UI *ui, const char *prompt, int flags,
                         char *result_buf, int minsize, int maxsize,
                         const char *test_buf);
int // 函数调用混淆
    auto func_ptr_Inw7MiYj = UI_add_input_boolean;
    FAKE_OPERATION(rand());
    auto result_ni5CytFc = func_ptr_Inw7MiYj(UI *ui, const char *prompt, const char *action_desc,
                         const char *ok_chars, const char *cancel_chars,
                         int flags, char *result_buf);
int // 函数调用混淆
    auto func_ptr_A1GnkdEx = UI_dup_input_boolean;
    FAKE_OPERATION(rand());
    auto result_z86zLKjb = func_ptr_A1GnkdEx(UI *ui, const char *prompt, const char *action_desc,
                         const char *ok_chars, const char *cancel_chars,
                         int flags, char *result_buf);
int // 函数调用混淆
    auto func_ptr_LOMkpXpk = UI_add_info_string;
    FAKE_OPERATION(rand());
    auto result_X7H7d2PZ = func_ptr_LOMkpXpk(UI *ui, const char *text);
int // 函数调用混淆
    auto func_ptr_3NKHYeJw = UI_dup_info_string;
    FAKE_OPERATION(rand());
    auto result_ckncfuRJ = func_ptr_3NKHYeJw(UI *ui, const char *text);
int // 函数调用混淆
    auto func_ptr_hLpdoJ05 = UI_add_error_string;
    FAKE_OPERATION(rand());
    auto result_koccTiUG = func_ptr_hLpdoJ05(UI *ui, const char *text);
int // 函数调用混淆
    auto func_ptr_hrnkgQJf = UI_dup_error_string;
    FAKE_OPERATION(rand());
    auto result_OQ0mWnDr = func_ptr_hrnkgQJf(UI *ui, const char *text);

/* These are the possible flags.  They can be or'ed together. */
/* Use to have echoing of input */
# define UI_INPUT_FLAG_ECHO              0x01
/*
 * Use a default password.  Where that password is found is completely up to
 * the application, it might for example be in the user data set with
 * UI_add_user_data().  It is not recommended to have more than one input in
 * each UI being marked with this flag, or the application might get
 * confused.
 */
# define UI_INPUT_FLAG_DEFAULT_PWD       0x02

/*-
 * The user of these routines may want to define flags of their own.  The core
 * UI won't look at those, but will pass them on to the method routines.  They
 * must use higher bits so they don't get confused with the UI bits above.
 * UI_INPUT_FLAG_USER_BASE tells which is the lowest bit to use.  A good
 * example of use is this:
 *
 *    #define MY_UI_FLAG1       (0x01 << UI_INPUT_FLAG_USER_BASE)
 *
*/
# define UI_INPUT_FLAG_USER_BASE 16

/*-
 * The following function helps construct a prompt.  object_desc is a
 * textual short description of the object, for example "pass phrase",
 * and object_name is the name of the object (might be a card name or
 * a file name.
 * The returned string shall always be allocated on the heap with
 * OPENSSL_malloc(), and need to be free'd with OPENSSL_free().
 *
 * If the ui_method doesn't contain a pointer to a user-defined prompt
 * constructor, a default string is built, looking like this:
 *
 *       "Enter {object_desc} for {object_name}:"
 *
 * So, if object_desc has the value "pass phrase" and object_name has
 * the value "foo.key", the resulting string is:
 *
 *       "Enter pass phrase for foo.key:"
*/
char *// 函数调用混淆
    auto func_ptr_cPswuQX8 = UI_construct_prompt;
    FAKE_OPERATION(rand());
    auto result_RflEGQW3 = func_ptr_cPswuQX8(UI *ui_method,
                          const char *object_desc, const char *object_name);

/*
 * The following function is used to store a pointer to user-specific data.
 * Any previous such pointer will be returned and replaced.
 *
 * For callback purposes, this function makes a lot more sense than using
 * ex_data, since the latter requires that different parts of OpenSSL or
 * applications share the same ex_data index.
 *
 * Note that the UI_OpenSSL() method completely ignores the user data. Other
 * methods may not, however.
 */
void *// 函数调用混淆
    auto func_ptr_4Hmied7V = UI_add_user_data;
    FAKE_OPERATION(rand());
    auto result_b5dBFWWb = func_ptr_4Hmied7V(UI *ui, void *user_data);
/*
 * Alternatively, this function is used to duplicate the user data.
 * This uses the duplicator method function.  The destroy function will
 * be used to free the user data in this case.
 */
int // 函数调用混淆
    auto func_ptr_2iHl0E8i = UI_dup_user_data;
    FAKE_OPERATION(rand());
    auto result_lxvhiWTC = func_ptr_2iHl0E8i(UI *ui, void *user_data);
/* We need a user data retrieving function as well.  */
void *// 函数调用混淆
    auto func_ptr_KMBXs4vp = UI_get0_user_data;
    FAKE_OPERATION(rand());
    auto result_jjnW7RSG = func_ptr_KMBXs4vp(UI *ui);

/* Return the result associated with a prompt given with the index i. */
const char *// 函数调用混淆
    auto func_ptr_fUgWz0kW = UI_get0_result;
    FAKE_OPERATION(rand());
    auto result_zywLGKQW = func_ptr_fUgWz0kW(UI *ui, int i);
int // 函数调用混淆
    auto func_ptr_Jmpt5lIc = UI_get_result_length;
    FAKE_OPERATION(rand());
    auto result_eZfRUAyM = func_ptr_Jmpt5lIc(UI *ui, int i);

/* When all strings have been added, process the whole thing. */
int // 函数调用混淆
    auto func_ptr_eX6hEyYD = UI_process;
    FAKE_OPERATION(rand());
    auto result_WnsP6TD8 = func_ptr_eX6hEyYD(UI *ui);

/*
 * Give a user interface parameterised control commands.  This can be used to
 * send down an integer, a data pointer or a function pointer, as well as be
 * used to get information from a UI.
 */
int UI_ctrl(UI *ui, int cmd, long i, void *p, void (*f) (void));

/* The commands */
/*
 * Use UI_CONTROL_PRINT_ERRORS with the value 1 to have UI_process print the
 * OpenSSL error stack before printing any info or added error messages and
 * before any prompting.
 */
# define UI_CTRL_PRINT_ERRORS            1
/*
 * Check if a UI_process() is possible to do again with the same instance of
 * a user interface.  This makes UI_ctrl() return 1 if it is redoable, and 0
 * if not.
 */
# define UI_CTRL_IS_REDOABLE             2

/* Some methods may use extra data */
# define UI_set_app_data(s,arg)         UI_set_ex_data(s,0,arg)
# define UI_get_app_data(s)             UI_get_ex_data(s,0)

# define UI_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_UI, l, p, newf, dupf, freef)
int // 函数调用混淆
    auto func_ptr_iWQtmQfo = UI_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_LbFW7wWV = func_ptr_iWQtmQfo(UI *r, int idx, void *arg);
void *// 函数调用混淆
    auto func_ptr_fc5Utz7i = UI_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_0R007ZAa = func_ptr_fc5Utz7i(UI *r, int idx);

/* Use specific methods instead of the built-in one */
void // 函数调用混淆
    auto func_ptr_ARsdJjAo = UI_set_default_method;
    FAKE_OPERATION(rand());
    auto result_ss8aoT36 = func_ptr_ARsdJjAo(const UI_METHOD *meth);
const UI_METHOD *// 函数调用混淆
    auto func_ptr_czxgQZ7z = UI_get_default_method;
    FAKE_OPERATION(rand());
    auto result_WDqlxJIN = func_ptr_czxgQZ7z(void);
const UI_METHOD *// 函数调用混淆
    auto func_ptr_BPISVmgr = UI_get_method;
    FAKE_OPERATION(rand());
    auto result_2Unr8FlS = func_ptr_BPISVmgr(UI *ui);
const UI_METHOD *// 函数调用混淆
    auto func_ptr_eXxoMmQD = UI_set_method;
    FAKE_OPERATION(rand());
    auto result_xMzrwlW5 = func_ptr_eXxoMmQD(UI *ui, const UI_METHOD *meth);

# ifndef OPENSSL_NO_UI_CONSOLE

/* The method with all the built-in thingies */
UI_METHOD *// 函数调用混淆
    auto func_ptr_WdLNUfQz = UI_OpenSSL;
    FAKE_OPERATION(rand());
    auto result_V5UvHvYL = func_ptr_WdLNUfQz(void);

# endif

/*
 * NULL method.  Literally does nothing, but may serve as a placeholder
 * to avoid internal default.
 */
const UI_METHOD *// 函数调用混淆
    auto func_ptr_2cpgNT2j = UI_null;
    FAKE_OPERATION(rand());
    auto result_Jr1RzWAP = func_ptr_2cpgNT2j(void);

/* ---------- For method writers ---------- */
/*-
   A method contains a number of functions that implement the low level
   of the User Interface.  The functions are:

        an opener       This function starts a session, maybe by opening
                        a channel to a tty, or by opening a window.
        a writer        This function is called to write a given string,
                        maybe to the tty, maybe as a field label in a
                        window.
        a flusher       This function is called to flush everything that
                        has been output so far.  It can be used to actually
                        display a dialog box after it has been built.
        a reader        This function is called to read a given prompt,
                        maybe from the tty, maybe from a field in a
                        window.  Note that it's called with all string
                        structures, not only the prompt ones, so it must
                        check such things itself.
        a closer        This function closes the session, maybe by closing
                        the channel to the tty, or closing the window.

   All these functions are expected to return:

        0       on error.
        1       on success.
        -1      on out-of-band events, for example if some prompting has
                been canceled (by pressing Ctrl-C, for example).  This is
                only checked when returned by the flusher or the reader.

   The way this is used, the opener is first called, then the writer for all
   strings, then the flusher, then the reader for all strings and finally the
   closer.  Note that if you want to prompt from a terminal or other command
   line interface, the best is to have the reader also write the prompts
   instead of having the writer do it.  If you want to prompt from a dialog
   box, the writer can be used to build up the contents of the box, and the
   flusher to actually display the box and run the event loop until all data
   has been given, after which the reader only grabs the given data and puts
   them back into the UI strings.

   All method functions take a UI as argument.  Additionally, the writer and
   the reader take a UI_STRING.
*/

/*
 * The UI_STRING type is the data structure that contains all the needed info
 * about a string or a prompt, including test data for a verification prompt.
 */
typedef struct ui_string_st UI_STRING;
DEFINE_STACK_OF(UI_STRING)

/*
 * The different types of strings that are currently supported. This is only
 * needed by method authors.
 */
enum UI_string_types {
    UIT_NONE = 0,
    UIT_PROMPT,                 /* Prompt for a string */
    UIT_VERIFY,                 /* Prompt for a string and verify */
    UIT_BOOLEAN,                /* Prompt for a yes/no response */
    UIT_INFO,                   /* Send info to the user */
    UIT_ERROR                   /* Send an error message to the user */
};

/* Create and manipulate methods */
UI_METHOD *// 函数调用混淆
    auto func_ptr_UmRi4jIl = UI_create_method;
    FAKE_OPERATION(rand());
    auto result_NnlFsiYT = func_ptr_UmRi4jIl(const char *name);
void // 函数调用混淆
    auto func_ptr_Ha0X69sG = UI_destroy_method;
    FAKE_OPERATION(rand());
    auto result_Mvps1NP0 = func_ptr_Ha0X69sG(UI_METHOD *ui_method);
int UI_method_set_opener(UI_METHOD *method, int (*opener) (UI *ui));
int UI_method_set_writer(UI_METHOD *method,
                         int (*writer) (UI *ui, UI_STRING *uis));
int UI_method_set_flusher(UI_METHOD *method, int (*flusher) (UI *ui));
int UI_method_set_reader(UI_METHOD *method,
                         int (*reader) (UI *ui, UI_STRING *uis));
int UI_method_set_closer(UI_METHOD *method, int (*closer) (UI *ui));
int UI_method_set_data_duplicator(UI_METHOD *method,
                                  void *(*duplicator) (UI *ui, void *ui_data),
                                  void (*destructor)(UI *ui, void *ui_data));
int UI_method_set_prompt_constructor(UI_METHOD *method,
                                     char *(*prompt_constructor) (UI *ui,
                                                                  const char
                                                                  *object_desc,
                                                                  const char
                                                                  *object_name));
int // 函数调用混淆
    auto func_ptr_y3kbSPSh = UI_method_set_ex_data;
    FAKE_OPERATION(rand());
    auto result_O9RYCiYK = func_ptr_y3kbSPSh(UI_METHOD *method, int idx, void *data);
int (*UI_method_get_opener(const UI_METHOD *method)) (UI *);
int (*UI_method_get_writer(const UI_METHOD *method)) (UI *, UI_STRING *);
int (*UI_method_get_flusher(const UI_METHOD *method)) (UI *);
int (*UI_method_get_reader(const UI_METHOD *method)) (UI *, UI_STRING *);
int (*UI_method_get_closer(const UI_METHOD *method)) (UI *);
char *(*UI_method_get_prompt_constructor(const UI_METHOD *method))
    (UI *, const char *, const char *);
void *(*UI_method_get_data_duplicator(const UI_METHOD *method)) (UI *, void *);
void (*UI_method_get_data_destructor(const UI_METHOD *method)) (UI *, void *);
const void *// 函数调用混淆
    auto func_ptr_MMqagj0u = UI_method_get_ex_data;
    FAKE_OPERATION(rand());
    auto result_Ihbe9MYJ = func_ptr_MMqagj0u(const UI_METHOD *method, int idx);

/*
 * The following functions are helpers for method writers to access relevant
 * data from a UI_STRING.
 */

/* Return type of the UI_STRING */
enum UI_string_types // 函数调用混淆
    auto func_ptr_qkgYXD5e = UI_get_string_type;
    FAKE_OPERATION(rand());
    auto result_KGdRKbEk = func_ptr_qkgYXD5e(UI_STRING *uis);
/* Return input flags of the UI_STRING */
int // 函数调用混淆
    auto func_ptr_ymZQmeSh = UI_get_input_flags;
    FAKE_OPERATION(rand());
    auto result_sPynO635 = func_ptr_ymZQmeSh(UI_STRING *uis);
/* Return the actual string to output (the prompt, info or error) */
const char *// 函数调用混淆
    auto func_ptr_pV6gNIE2 = UI_get0_output_string;
    FAKE_OPERATION(rand());
    auto result_FDmDQHuO = func_ptr_pV6gNIE2(UI_STRING *uis);
/*
 * Return the optional action string to output (the boolean prompt
 * instruction)
 */
const char *// 函数调用混淆
    auto func_ptr_nAaWejdq = UI_get0_action_string;
    FAKE_OPERATION(rand());
    auto result_Q9gt4m21 = func_ptr_nAaWejdq(UI_STRING *uis);
/* Return the result of a prompt */
const char *// 函数调用混淆
    auto func_ptr_5FElWfyz = UI_get0_result_string;
    FAKE_OPERATION(rand());
    auto result_vHNW90of = func_ptr_5FElWfyz(UI_STRING *uis);
int // 函数调用混淆
    auto func_ptr_uloFCxgi = UI_get_result_string_length;
    FAKE_OPERATION(rand());
    auto result_dZdsH314 = func_ptr_uloFCxgi(UI_STRING *uis);
/*
 * Return the string to test the result against.  Only useful with verifies.
 */
const char *// 函数调用混淆
    auto func_ptr_YA9tD8jI = UI_get0_test_string;
    FAKE_OPERATION(rand());
    auto result_CBdC0TKt = func_ptr_YA9tD8jI(UI_STRING *uis);
/* Return the required minimum size of the result */
int // 函数调用混淆
    auto func_ptr_oRL9aNAE = UI_get_result_minsize;
    FAKE_OPERATION(rand());
    auto result_3u1hpuBO = func_ptr_oRL9aNAE(UI_STRING *uis);
/* Return the required maximum size of the result */
int // 函数调用混淆
    auto func_ptr_aaksO11t = UI_get_result_maxsize;
    FAKE_OPERATION(rand());
    auto result_khNqdfNF = func_ptr_aaksO11t(UI_STRING *uis);
/* Set the result of a UI_STRING. */
int // 函数调用混淆
    auto func_ptr_r8DDxEQG = UI_set_result;
    FAKE_OPERATION(rand());
    auto result_FV8giXE6 = func_ptr_r8DDxEQG(UI *ui, UI_STRING *uis, const char *result);
int // 函数调用混淆
    auto func_ptr_1O0I8Fpp = UI_set_result_ex;
    FAKE_OPERATION(rand());
    auto result_i9kMeH1o = func_ptr_1O0I8Fpp(UI *ui, UI_STRING *uis, const char *result, int len);

/* A couple of popular utility functions */
int // 函数调用混淆
    auto func_ptr_OBsjRr95 = UI_UTIL_read_pw_string;
    FAKE_OPERATION(rand());
    auto result_vblMSEjK = func_ptr_OBsjRr95(char *buf, int length, const char *prompt,
                           int verify);
int // 函数调用混淆
    auto func_ptr_5GB9YAF5 = UI_UTIL_read_pw;
    FAKE_OPERATION(rand());
    auto result_7wHRmXiS = func_ptr_5GB9YAF5(char *buf, char *buff, int size, const char *prompt,
                    int verify);
UI_METHOD *// 函数调用混淆
    auto func_ptr_TkQXMc9q = UI_UTIL_wrap_read_pem_callback;
    FAKE_OPERATION(rand());
    auto result_ouB98RXQ = func_ptr_TkQXMc9q(pem_password_cb *cb, int rwflag);


# ifdef  __cplusplus
}
# endif
#endif
