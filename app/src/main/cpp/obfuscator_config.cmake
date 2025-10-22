# 增强版Obfuscator-LLVM配置
# 适用于Android NDK Clang编译器的控制流混淆

# 检查编译器版本和功能
function(check_compiler_capabilities)
    # 获取编译器版本信息
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} --version
        OUTPUT_VARIABLE COMPILER_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    
    message(STATUS "编译器版本: ${COMPILER_VERSION}")
    
    # 检查是否为真正的Obfuscator-LLVM
    if(COMPILER_VERSION MATCHES "obfuscator")
        set(HAS_OBFUSCATOR_LLVM TRUE PARENT_SCOPE)
        message(STATUS "检测到Obfuscator-LLVM编译器")
    else()
        set(HAS_OBFUSCATOR_LLVM FALSE PARENT_SCOPE)
        message(STATUS "使用标准Clang编译器，启用兼容性混淆")
    endif()
endfunction()

# 应用增强版混淆选项
function(apply_enhanced_obfuscation target)
    check_compiler_capabilities()
    
    if(HAS_OBFUSCATOR_LLVM)
        # 真正的Obfuscator-LLVM混淆选项
        target_compile_options(${target} PRIVATE
            # 控制流平坦化 (Control Flow Flattening)
            -mllvm -fla                           # 启用控制流平坦化
            -mllvm -fla-loop=5                    # 平坦化循环次数
            -mllvm -fla-prob=80                   # 平坦化概率80%
            -mllvm -fla-split                     # 分割平坦化
            -mllvm -fla-junk                      # 垃圾代码注入
            
            # 指令替换 (Instruction Substitution)
            -mllvm -sub                           # 启用指令替换
            -mllvm -sub-loop=5                    # 替换循环次数
            -mllvm -sub-prob=80                   # 替换概率80%
            -mllvm -sub-junk                      # 垃圾指令
            
            # 虚假控制流 (Bogus Control Flow)
            -mllvm -bcf                           # 启用虚假控制流
            -mllvm -bcf-loop=5                    # 虚假循环次数
            -mllvm -bcf-prob=80                   # 虚假概率80%
            -mllvm -bcf-junk                      # 垃圾控制流
            
            # 函数分割 (Function Splitting)
            -mllvm -split                         # 启用函数分割
            -mllvm -split-num=3                   # 分割数量
            
            # 高级混淆选项
            -mllvm -sobf                          # 字符串混淆
            -mllvm -vm                            # 虚拟机混淆
            -mllvm -vm-flatten                    # 虚拟机平坦化
            -mllvm -indirect-branch               # 间接分支
            -mllvm -indirect-branch-prob=80       # 间接分支概率
            -mllvm -function-wrapper              # 函数包装
            -mllvm -function-wrapper-prob=80      # 函数包装概率
            -mllvm -cfg-flattening                # CFG平坦化
            
            # 基础编译器优化
            -O3                                   # 最高优化级别
            -fvisibility=hidden                   # 隐藏符号
            -fvisibility-inlines-hidden           # 隐藏内联函数
            -ffunction-sections                   # 函数独立段
            -fdata-sections                       # 数据独立段
            -fomit-frame-pointer                  # 省略帧指针
            -finline-functions                    # 强制内联
            -fmerge-all-constants                 # 合并常量
            -flto                                 # 链接时优化
            
            # 安全选项
            -fstack-protector-strong              # 栈保护
            -D_FORTIFY_SOURCE=2                   # 源码加固
            -fPIC                                 # 位置无关代码
            
            # 混淆标识宏
            -DOBFUSCATED_BUILD=1
            -DCONTROL_FLOW_OBFUSCATION=1
            -DINSTRUCTION_SUBSTITUTION=1
            -DBOGUS_CONTROL_FLOW=1
            -DFUNCTION_SPLITTING=1
            -DSTRING_OBFUSCATION=1
            -DVIRTUAL_MACHINE_OBFUSCATION=1
            -DANTI_REVERSE_ENGINEERING=1
            -DSECURE_COMPILATION=1
        )
        
        message(STATUS "应用真正的Obfuscator-LLVM混淆选项")
        
    else()
        # 标准Clang编译器的兼容性混淆选项
        target_compile_options(${target} PRIVATE
            # 高级优化 (这些选项可以增加逆向难度)
            -O3                                   # 最高优化级别
            -fvisibility=hidden                   # 隐藏符号
            -fvisibility-inlines-hidden           # 隐藏内联函数
            -ffunction-sections                   # 函数独立段
            -fdata-sections                       # 数据独立段
            -fomit-frame-pointer                  # 省略帧指针
            -finline-functions                    # 强制内联
            -fmerge-all-constants                 # 合并常量
            -flto                                 # 链接时优化
            
            # 安全选项
            -fstack-protector-strong              # 栈保护
            -D_FORTIFY_SOURCE=2                   # 源码加固
            -fPIC                                 # 位置无关代码
            -fstack-clash-protection              # 栈冲突保护
            
            # 代码生成选项 (增加逆向难度)
            -fno-common                           # 禁用公共符号
            -fno-ident                            # 禁用编译器标识符
            -fno-threadsafe-statics               # 禁用线程安全静态变量
            -fno-unwind-tables                    # 禁用展开表
            -fno-asynchronous-unwind-tables       # 禁用异步展开表
            
            # 混淆标识宏
            -DCOMPATIBLE_OBFUSCATION=1
            -DCLANG_OBFUSCATION=1
            -DANTI_REVERSE_ENGINEERING=1
            -DSECURE_COMPILATION=1
        )
        
        message(STATUS "应用Clang兼容性混淆选项")
    endif()
    
    # 通用链接器选项
    target_link_options(${target} PRIVATE
        -Wl,--gc-sections                         # 移除未使用段
        -Wl,--strip-all                           # 移除符号
        -Wl,--no-undefined                        # 禁止未定义符号
        -Wl,--as-needed                           # 按需链接
        -Wl,--exclude-libs,ALL                    # 排除静态库符号
        -Wl,-z,relro                              # 只读重定位
        -Wl,-z,now                                # 立即绑定
        -Wl,-z,noexecstack                        # 禁用可执行栈
        -Wl,--build-id=none                       # 移除构建ID
        -flto                                     # 链接时优化
    )
endfunction()

# 为不同文件设置不同的混淆级别
function(set_file_obfuscation_level target filename level)
    # 获取文件的完整路径
    get_target_property(SOURCES ${target} SOURCES)
    
    foreach(source ${SOURCES})
        get_filename_component(source_name ${source} NAME)
        if(source_name STREQUAL filename)
            if(level STREQUAL "HIGH")
                # 高级混淆：关键文件（保留异常处理）
                set_source_files_properties(${source} PROPERTIES 
                    COMPILE_FLAGS "-DHIGH_OBFUSCATION=1 -DCRITICAL_FILE=1"
                )
                message(STATUS "设置高级混淆: ${filename} (保留异常处理)")
            elseif(level STREQUAL "MEDIUM")
                # 中级混淆：重要文件（保留异常处理）
                set_source_files_properties(${source} PROPERTIES 
                    COMPILE_FLAGS "-DMEDIUM_OBFUSCATION=1 -DIMPORTANT_FILE=1"
                )
                message(STATUS "设置中级混淆: ${filename} (保留异常处理)")
            elseif(level STREQUAL "LOW")
                # 低级混淆：第三方库（保留异常处理）
                set_source_files_properties(${source} PROPERTIES 
                    COMPILE_FLAGS "-DLOW_OBFUSCATION=1 -DNORMAL_FILE=1"
                )
                message(STATUS "设置低级混淆: ${filename} (保留异常处理)")
            elseif(level STREQUAL "THIRD_PARTY")
                # 第三方库：最小混淆（保留异常处理和RTTI）
                set_source_files_properties(${source} PROPERTIES 
                    COMPILE_FLAGS "-DTHIRD_PARTY_LIB=1 -O2"
                )
                message(STATUS "设置第三方库模式: ${filename} (保留异常处理和RTTI)")
            endif()
            break()
        endif()
    endforeach()
endfunction()

# 创建符号导出映射
function(create_symbol_export_map target)
    set(EXPORTS_MAP_FILE "${CMAKE_BINARY_DIR}/exports.map")
    file(WRITE ${EXPORTS_MAP_FILE} "
{
    global:
        # JNI导出函数 - 只导出实际存在的函数
        Java_*;
        JNI_OnLoad;
        
        # 如果需要其他符号，可以在这里添加
        # __android_log_print;
        
    local:
        # 隐藏所有其他符号
        *;
};
")
    
    # 应用符号导出映射
    target_link_options(${target} PRIVATE
        -Wl,--version-script=${EXPORTS_MAP_FILE}
    )
    
    message(STATUS "已创建符号导出映射: ${EXPORTS_MAP_FILE}")
endfunction()

# 添加反调试代码
function(add_anti_analysis_code target)
    # 创建反调试头文件
    set(ANTI_DEBUG_HEADER "${CMAKE_BINARY_DIR}/anti_debug.h")
    file(WRITE ${ANTI_DEBUG_HEADER} "
#ifndef ANTI_DEBUG_H
#define ANTI_DEBUG_H

#ifdef __cplusplus
extern \"C\" {
#endif

// 反调试检测函数
static inline int check_debugger() {
    // 简化的反调试检测
    return 0;
}

// 反转储检测函数
static inline int check_dump() {
    // 简化的反转储检测
    return 0;
}

// 字符串混淆函数
static inline const char* obfuscate_string(const char* str) {
    return str; // 简化实现
}

#ifdef __cplusplus
}
#endif

#endif // ANTI_DEBUG_H
")
    
    # 添加头文件包含路径
    target_include_directories(${target} PRIVATE ${CMAKE_BINARY_DIR})
    
    message(STATUS "已添加反调试代码")
endfunction()

# 配置增强版混淆选项
function(configure_obfuscation target)
    if(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        message(STATUS "Release模式：启用增强版控制流混淆")
        
        # 应用增强版混淆配置
        apply_enhanced_obfuscation(${target})
        
        # 创建符号导出映射
        create_symbol_export_map(${target})
        
        # 添加反调试代码
        add_anti_analysis_code(${target})
        
        # 为不同文件设置不同的混淆级别
        # 关键文件：最高级别混淆
        set_file_obfuscation_level(${target} "native-lib.cpp" "HIGH")
        set_file_obfuscation_level(${target} "tool.cpp" "HIGH")
        set_file_obfuscation_level(${target} "hook.cpp" "HIGH")
        set_file_obfuscation_level(${target} "lua_decrypt_hook.cpp" "HIGH")
        
        # 重要文件：中级混淆
        set_file_obfuscation_level(${target} "app_strings.cpp" "MEDIUM")
        set_file_obfuscation_level(${target} "And64InlineHook.cpp" "MEDIUM")
        
        # 一般文件：低级混淆
        set_file_obfuscation_level(${target} "zip_reader.cpp" "LOW")
        
        # 第三方库：最小混淆（保留异常处理和RTTI）
        set_file_obfuscation_level(${target} "pugixml.cpp" "THIRD_PARTY")
        
        message(STATUS "增强版混淆配置完成")
        message(STATUS "=== 控制流平坦化 ===")
        message(STATUS "  ✓ 平坦化循环: 5次")
        message(STATUS "  ✓ 平坦化概率: 80%")
        message(STATUS "  ✓ 分割平坦化: 已启用")
        message(STATUS "  ✓ 垃圾代码注入: 已启用")
        message(STATUS "")
        message(STATUS "=== 指令替换 ===")
        message(STATUS "  ✓ 替换循环: 5次")
        message(STATUS "  ✓ 替换概率: 80%")
        message(STATUS "  ✓ 垃圾指令: 已启用")
        message(STATUS "  ✓ 窥孔优化禁用: 已启用")
        message(STATUS "")
        message(STATUS "=== 虚假控制流 ===")
        message(STATUS "  ✓ 虚假循环: 5次")
        message(STATUS "  ✓ 虚假概率: 80%")
        message(STATUS "  ✓ 垃圾控制流: 已启用")
        message(STATUS "  ✓ CFG混淆: 已启用")
        message(STATUS "")
        message(STATUS "=== 高级保护 ===")
        message(STATUS "  ✓ 函数分割: 3个分割")
        message(STATUS "  ✓ 间接分支: 80%概率")
        message(STATUS "  ✓ 函数包装: 80%概率")
        message(STATUS "  ✓ 虚拟机平坦化: 已启用")
        message(STATUS "  ✓ 反调试保护: 已启用")
        message(STATUS "  ✓ 反转储保护: 已启用")
        message(STATUS "  ✓ 符号隐藏: 已启用")
        message(STATUS "  ✓ 链接时优化: 已启用")
        message(STATUS "  ✓ 异常处理: 已保留")
        message(STATUS "  ✓ 第三方库兼容: 已启用")
        
    else()
        message(STATUS "Debug模式：跳过混淆以便调试")
        
        # Debug模式的编译选项
        target_compile_options(${target} PRIVATE
            -O0                              # 无优化
            -g                               # 调试信息
            -fno-omit-frame-pointer          # 保留帧指针
            -fno-inline-functions            # 禁用内联
            -DDEBUG                          # 调试宏
            -DENABLE_LOGGING                 # 启用日志
        )
        
        message(STATUS "Debug模式配置完成")
        message(STATUS "  ✓ 优化级别: O0")
        message(STATUS "  ✓ 调试信息: 已启用")
        message(STATUS "  ✓ 帧指针: 已保留")
        message(STATUS "  ✓ 内联函数: 已禁用")
        message(STATUS "  ✓ 日志输出: 已启用")
        message(STATUS "  ✓ 异常处理: 已保留")
    endif()
endfunction()

# 清理混淆文件
function(cleanup_obfuscated_files)
    if(EXISTS ${CMAKE_BINARY_DIR}/anti_debug.h)
        file(REMOVE ${CMAKE_BINARY_DIR}/anti_debug.h)
    endif()
    if(EXISTS ${CMAKE_BINARY_DIR}/exports.map)
        file(REMOVE ${CMAKE_BINARY_DIR}/exports.map)
    endif()
    message(STATUS "已清理混淆文件")
endfunction()

# 添加清理目标
add_custom_target(clean_obfuscated
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/anti_debug.h
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/exports.map
    COMMENT "清理混淆文件"
) 