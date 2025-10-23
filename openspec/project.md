# Project Context

## Purpose
996CQ是一个Android游戏辅助工具项目，提供游戏内悬浮窗UI、Lua脚本执行、动态Hook和反调试等功能。项目的核心目标是：
- 提供稳定的游戏辅助框架
- 实现高安全性的代码保护（字符串加密、代码混淆）
- 支持Lua脚本动态执行和解密
- 提供友好的悬浮窗交互界面

## Tech Stack

### 前端层
- **Java (Android SDK 21-31)**: 主要应用层代码
  - Activity、Service架构
  - 悬浮窗UI实现 (FloatContentView, FloatControlView)
  - 权限管理 (PermissionManager)
  
### 原生层
- **C++14**: 核心功能实现
  - CMake 3.22.1 构建系统
  - NDK支持: arm64-v8a, armeabi-v7a, x86, x86_64
  - And64InlineHook: 内联Hook框架
  - KittyMemory: 内存操作库
  - PugiXML: XML解析

### 第三方库
- **OkHttp 4.8.1**: HTTP网络请求
- **zip4j 2.11.5**: 密码保护的zip文件操作
- **OpenSSL 1.1.1l/1.0.2u**: 加密解密功能
- **libcurl**: HTTP客户端（静态链接）

### 构建工具
- **Gradle 8.10.0**: 构建系统
- **BlackObfuscator 3.9**: Java代码混淆插件
- **Obfuscator-LLVM**: C++代码混淆（控制流平坦化、指令替换）
- **Python 3.11**: 字符串加密脚本、代码混淆工具

### 混淆与安全
- 字符串加密（运行时XOR解密）
- Java层BlackObfuscator混淆
- C++层LLVM混淆（Release模式）
- 反调试保护机制

## Project Conventions

### Code Style

#### Java代码规范
- 包名：`gd.game.lib`
- 命名约定：
  - 类名：大驼峰 (PascalCase)，如 `FloatContentView`
  - 方法名：小驼峰 (camelCase)，如 `requestPermissions`
  - 常量：全大写下划线分隔，如 `ENABLE_LOGGING`
- 日志工具：使用 `LogUtils` 统一管理
- 字符串资源：通过 `appStrings.java` 集中管理（支持加密）

#### C++代码规范
- 头文件：使用 `#pragma once`
- 命名约定：
  - 函数：snake_case，如 `decrypt_lua_file`
  - 类名：PascalCase，如 `ZipReader`
  - 宏：全大写，如 `DEBUG_MODE`
- 日志宏：
  - `LOGD()`: Debug日志
  - `LOGI()`: Info日志
  - `LOGW()`: Warning日志
  - `LOGE()`: Error日志
- 字符串加密：
  - 敏感字符串存储在 `strings.txt`
  - Release模式自动加密为 `app_strings.h/cpp`
  - Debug模式使用明文以便调试

### Architecture Patterns

#### 分层架构
```
┌─────────────────────────────────────┐
│   Java UI Layer (FloatContentView)  │
│         悬浮窗UI、权限管理           │
├─────────────────────────────────────┤
│   JNI Bridge Layer (native-lib.cpp) │
│         Java与C++交互接口            │
├─────────────────────────────────────┤
│   C++ Core Layer                     │
│   - Lua解密与执行 (lua_decrypt)     │
│   - Hook功能 (And64InlineHook)      │
│   - 内存操作 (KittyMemory)          │
│   - Zip解压 (zip_reader)            │
│   - 反调试 (anti_debug)              │
└─────────────────────────────────────┘
```

#### 关键模式
1. **JNI桥接模式**: Java通过JNI调用C++核心功能
2. **悬浮窗服务**: `FloatServiceView` (Service) + `FloatContentView` (View)
3. **Hook注入**: 使用And64InlineHook进行函数Hook
4. **加密解密管道**: strings.txt → Python脚本 → app_strings.cpp → 运行时解密

### Testing Strategy

#### 构建变体
- **Debug版本**:
  - 包名后缀：`.debug`
  - 日志：完全启用 (`DEBUG_MODE=1`)
  - 混淆：禁用
  - 符号：保留 (`debugSymbolLevel FULL`)
  
- **Release版本**:
  - 默认：日志启用 (`RELEASE_MODE=1`)
  - 无日志：使用 `-DENABLE_RELEASE_LOGS=OFF`
  - 混淆：完全启用 (Java + C++)
  - ProGuard：启用资源压缩和代码优化

#### 自定义任务
- `installReleaseApp`: 构建并安装Release到所有设备
- `installReleaseWithLogs`: 安装后查看日志
- `uninstallReleaseAndClean`: 卸载并清理缓存
- `deviceInfo`: 查看设备详细信息
- `testObfuscation`: 测试代码混淆
- `analyzeObfuscation`: 分析混淆效果

### Git Workflow
- 主分支：使用语义化版本管理
- 提交信息：简体中文描述
- 不提交生成文件：
  - `app/build/`
  - `*.apk`
  - `app_strings.h/cpp` (自动生成)
  - `.gradle/`

## Domain Context

### 游戏辅助领域知识
- **Lua脚本执行**: 项目支持从assets加载加密Lua脚本并在运行时解密执行
- **内存Hook**: 使用And64InlineHook对目标进程函数进行拦截和替换
- **反检测机制**: 
  - 反调试 (ptrace检测、TracerPid检测)
  - 反虚拟机 (特征文件检测)
  - 反模拟器 (系统属性检测)
- **悬浮窗权限**: Android 6.0+需要动态申请 `SYSTEM_ALERT_WINDOW` 权限

### 关键文件说明
- `tool.cpp` (3543行): 核心工具函数集合
- `FloatContentView.java` (901行): 主悬浮窗UI实现
- `CMakeLists.txt`: 原生库构建配置（包含混淆配置）
- `strings.txt`: 敏感字符串源文件
- `proguard-rules.pro`: Java混淆规则

## Important Constraints

### 技术约束
1. **最低SDK**: Android 5.0 (API 21)
2. **目标SDK**: Android 12 (API 31)
3. **架构支持**: arm64-v8a, armeabi-v7a, x86, x86_64
4. **C++标准**: C++14 (必须兼容NDK r21+)
5. **CMake版本**: 3.22.1
6. **Python版本**: 3.11 (用于构建时脚本)

### 性能约束
- Release APK大小控制（启用资源压缩）
- SO文件需strip调试符号
- 启用LTO (Link Time Optimization)

### 安全约束
- 所有敏感字符串必须加密
- Release版本必须启用混淆
- 禁止硬编码密钥（使用运行时生成）
- ProGuard字典混淆 (`proguard-dict.txt`)

### 构建约束
- 签名配置：Debug使用 `debug.keystore`，Release需独立签名
- Python脚本路径：`C:/Python/Python311/python.exe` (Windows)
- 加密脚本路径：`buildSrc/src/main/python/encrypt_header.py`

## External Dependencies

### 网络依赖
- Maven仓库：阿里云镜像 (maven.aliyun.com)
- JitPack：GitHub项目依赖 (jitpack.io)
- Google Maven：Android组件

### 原生库依赖
- OpenSSL静态库：`openssl/android_openssl-1.1.1l_1.0.2u/no-asm/static/`
- libcurl静态库：`app/src/main/cpp/libs/${ANDROID_ABI}/libcurl.a`

### 构建依赖
- Android Gradle插件：8.10.0
- BlackObfuscator插件：3.9 (com.github.CodingGay)

### 资产文件
- `app/src/main/assets/`: 包含1664个文件
  - 1617个 `.lua` 文件（Lua脚本）
  - 37个 `.png` 图片资源
  - 5个 `.ttf` 字体文件

## Development Guidelines

### 添加新的敏感字符串
1. 编辑 `app/src/main/cpp/strings.txt`
2. 运行 `./gradlew encryptHeaderFiles`
3. 在C++代码中使用 `AppStrings::get("key")`

### 添加新的Hook功能
1. 在 `hook.cpp` 中定义Hook函数
2. 使用 `A64HookFunction()` 进行Hook
3. 在 `native-lib.cpp` 的 `JNI_OnLoad` 中初始化

### 修改悬浮窗UI
1. 编辑 `FloatContentView.java`
2. 布局代码在 `initView()` 方法中
3. 事件处理在对应的 `OnClickListener` 中

### 调试技巧
- Debug日志：`./gradlew assembleDebug && adb logcat -s 996CQ_DEBUG`
- Release日志：`./gradlew assembleRelease && adb logcat -s 996CQ_RELEASE`
- 查看设备：`./gradlew deviceInfo`
- 分析混淆：`./gradlew analyzeObfuscation`
