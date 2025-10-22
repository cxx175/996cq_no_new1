/*
 *  @date   : 2018/04/18
 *  @author : Rprop (r_prop@outlook.com)
 *  https://github.com/Rprop/And64InlineHook
 */

#pragma once

#include <cstdint>

// Function to hook ARM64 functions
#ifdef __cplusplus
extern "C" {
#endif

void A64HookFunction(void *const symbol, void *const replace, void **result);

#ifdef __cplusplus
}
#endif 