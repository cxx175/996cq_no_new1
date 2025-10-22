cmake_minimum_required(VERSION 3.18.1)

# 设置项目名称
project("996cq_native")

# =====================================
# 📝 日志输出控制说明
# =====================================
# 
# 🎯 支持三种日志模式：
# 
# 1. Debug模式：
#    - 编译命令：正常Debug构建
#    - 日志状态：完全启用
#    - 宏定义：DEBUG_MODE=1
# 
# 2. Release模式（带日志）：
#    - 编译命令：Release构建（默认）
#    - 日志状态：完全启用（方便调试）
#    - 宏定义：RELEASE_MODE=1
#    - 说明：默认启用，方便发布前调试
# 
# 3. Release模式（无日志）：
#    - 编译命令：Release构建 + -DENABLE_RELEASE_LOGS=OFF
#    - 日志状态：完全禁用（最优性能）
#    - 宏定义：NDEBUG
#    - 说明：最终发布版本，优化性能
# 
# 💡 使用示例：
# 
# # Release模式（带日志 - 默认）
# ./gradlew assembleRelease
# 
# # Release模式（无日志 - 优化）
# ./gradlew assembleRelease -DENABLE_RELEASE_LOGS=OFF
# 
# =====================================

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件加密配置
set(PLAIN_HEADER "${CMAKE_SOURCE_DIR}/app_strings.h")
set(PLAIN_SOURCE "${CMAKE_SOURCE_DIR}/app_strings.cpp")
set(STRINGS_TXT "${CMAKE_SOURCE_DIR}/strings.txt")
set(ENCRYPT_SCRIPT "C:/Users/Administrator/Desktop/Androidproject/996cq_no/buildSrc/src/main/python/encrypt_header.py")
set(PYTHON_EXECUTABLE "C:/Python/Python311/python.exe")

# 创建主要的native库
add_library(996cq_native SHARED
    native-lib.cpp
    tool.cpp
    app_strings.cpp
    hook.cpp
    And64InlineHook.cpp
    lua_decrypt_hook.cpp
    zip_reader.cpp
    hook/KittyMemory/KittyMemory.cpp
    hook/KittyMemory/KittyUtils.cpp
    hook/KittyMemory/MemoryPatch.cpp
    hook/KittyMemory/MemoryBackup.cpp
    pugixml.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    message(STATUS "Release构建 - 生成加密头文件和源文件")
    if(EXISTS ${PYTHON_EXECUTABLE})
        add_custom_command(
            OUTPUT ${PLAIN_HEADER} ${PLAIN_SOURCE}
            COMMAND ${PYTHON_EXECUTABLE} ${ENCRYPT_SCRIPT} --strings ${STRINGS_TXT} --output ${PLAIN_HEADER} --mode release
            DEPENDS ${STRINGS_TXT} ${ENCRYPT_SCRIPT}
            COMMENT "生成加密头文件和源文件: ${STRINGS_TXT} -> ${PLAIN_HEADER}, ${PLAIN_SOURCE}"
            VERBATIM
        )
        add_custom_target(encrypt_headers ALL DEPENDS ${PLAIN_HEADER} ${PLAIN_SOURCE})
        message(STATUS "将使用加密头文件和源文件: ${PLAIN_HEADER}, ${PLAIN_SOURCE}")
    else()
        message(WARNING "未找到Python解释器，无法生成加密头文件和源文件")
    endif()
else()
    message(STATUS "Debug构建 - 生成明文头文件和源文件")
    if(EXISTS ${PYTHON_EXECUTABLE})
        add_custom_command(
            OUTPUT ${PLAIN_HEADER} ${PLAIN_SOURCE}
            COMMAND ${PYTHON_EXECUTABLE} ${ENCRYPT_SCRIPT} --strings ${STRINGS_TXT} --output ${PLAIN_HEADER} --mode debug
            DEPENDS ${STRINGS_TXT} ${ENCRYPT_SCRIPT}
            COMMENT "生成明文头文件和源文件: ${STRINGS_TXT} -> ${PLAIN_HEADER}, ${PLAIN_SOURCE}"
            VERBATIM
        )
        add_custom_target(decrypt_headers ALL DEPENDS ${PLAIN_HEADER} ${PLAIN_SOURCE})
        message(STATUS "将使用明文头文件和源文件: ${PLAIN_HEADER}, ${PLAIN_SOURCE}")
    else()
        message(WARNING "未找到Python解释器，无法生成明文头文件和源文件")
    endif()
endif()

# 添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/curl)
include_directories(${CMAKE_SOURCE_DIR}/hook)
include_directories(${CMAKE_SOURCE_DIR}/app/src/main/cpp/include)

# 集成OpenSSL
if (ANDROID)
    # 添加OpenSSL头文件目录
    include_directories(${CMAKE_SOURCE_DIR}/openssl/android_openssl-1.1.1l_1.0.2u/no-asm/static/include)
endif()

# 查找预编译的libcurl库
find_library(curl-lib
    curl
    PATHS ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}
    NO_CMAKE_FIND_ROOT_PATH)

# 配置OpenSSL库
if (ANDROID)
    # 映射Android ABI到OpenSSL目录名
    if(ANDROID_ABI STREQUAL "arm64-v8a")
        set(OPENSSL_ABI_DIR "arm64")
    elseif(ANDROID_ABI STREQUAL "armeabi-v7a")
        set(OPENSSL_ABI_DIR "arm")
    elseif(ANDROID_ABI STREQUAL "x86")
        set(OPENSSL_ABI_DIR "x86")
    elseif(ANDROID_ABI STREQUAL "x86_64")
        set(OPENSSL_ABI_DIR "x86_64")
    else()
        message(FATAL_ERROR "Unsupported Android ABI: ${ANDROID_ABI}")
    endif()
    
    # 直接指定静态库路径
    set(OPENSSL_LIB_DIR ${CMAKE_SOURCE_DIR}/openssl/android_openssl-1.1.1l_1.0.2u/no-asm/static/lib/${OPENSSL_ABI_DIR})
    set(ssl-lib ${OPENSSL_LIB_DIR}/libssl.a)
    set(crypto-lib ${OPENSSL_LIB_DIR}/libcrypto.a)
endif()

# 查找系统库
find_library(log-lib log)
find_library(android-lib android)
find_library(z-lib z)
find_library(jnigraphics-lib jnigraphics)
find_library(dl-lib dl)

# 链接库 - 使用 And64InlineHook 替代 ByteHook
target_link_libraries(996cq_native
    ${curl-lib}
    ${ssl-lib}
    ${crypto-lib}
    ${z-lib}
    ${log-lib}
    ${android-lib}
    ${jnigraphics-lib}
    ${dl-lib})

message(STATUS "使用 And64InlineHook 进行 Hook 功能")

# 如果libcurl库不存在，则定义NO_CURL宏
if(NOT curl-lib)
    target_compile_definitions(996cq_native PRIVATE NO_CURL)
    message(WARNING "libcurl not found, compiling without curl support")
else()
    message(STATUS "Found libcurl: ${curl-lib}")
endif()

# 检查OpenSSL库
if(ANDROID)
    if(NOT ssl-lib OR NOT crypto-lib)
        target_compile_definitions(996cq_native PRIVATE NO_OPENSSL)
        message(WARNING "OpenSSL libraries not found, compiling without OpenSSL support")
    else()
        message(STATUS "Found OpenSSL SSL: ${ssl-lib}")
        message(STATUS "Found OpenSSL Crypto: ${crypto-lib}")
        target_compile_definitions(996cq_native PRIVATE HAVE_OPENSSL)
    endif()
endif()

# 包含增强版Obfuscator-LLVM混淆配置
include(${CMAKE_CURRENT_SOURCE_DIR}/obfuscator_config.cmake)

# 日志输出控制选项 - 修复默认值处理
option(ENABLE_RELEASE_LOGS "Enable logging in Release mode" OFF)

# 设置增强版混淆选项
if(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    message(STATUS "Release模式：启用增强版Obfuscator-LLVM控制流混淆")
    
    # 应用增强版混淆配置 (包含控制流平坦化和指令替换)
    configure_obfuscation(996cq_native)
    
    # Release模式日志控制 - 修复逻辑
    if(ENABLE_RELEASE_LOGS)
        target_compile_definitions(996cq_native PRIVATE RELEASE_MODE=1)
        message(STATUS "Release模式 - 日志输出已启用 (方便调试)")
        message(STATUS "编译标志: RELEASE_MODE=1")
    else()
        target_compile_definitions(996cq_native PRIVATE NDEBUG)
        message(STATUS "Release模式 - 日志输出已禁用 (优化性能)")
        message(STATUS "编译标志: NDEBUG")
        message(STATUS "所有LOGD/LOGI/LOGW/LOGE宏将被禁用")
    endif()
    
else()
    message(STATUS "Debug模式：禁用混淆以便调试")
    
    # 应用Debug模式配置
    configure_obfuscation(996cq_native)
    
    # Debug模式启用日志
    target_compile_definitions(996cq_native PRIVATE DEBUG_MODE=1)
    message(STATUS "Debug模式 - 日志输出已启用")
endif()

if(TARGET encrypt_headers)
    add_dependencies(996cq_native encrypt_headers)
endif()
if(TARGET decrypt_headers)
    add_dependencies(996cq_native decrypt_headers)
endif()

set_source_files_properties(${PLAIN_SOURCE} PROPERTIES GENERATED TRUE)