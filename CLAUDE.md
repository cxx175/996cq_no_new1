<!-- OPENSPEC:START -->
# OpenSpec Instructions

These instructions are for AI assistants working in this project.

Always open `@/openspec/AGENTS.md` when the request:
- Mentions planning or proposals (words like proposal, spec, change, plan)
- Introduces new capabilities, breaking changes, architecture shifts, or big performance/security work
- Sounds ambiguous and you need the authoritative spec before coding

Use `@/openspec/AGENTS.md` to learn:
- How to create and apply change proposals
- Spec format and conventions
- Project structure and guidelines

Keep this managed block so 'openspec update' can refresh the instructions.

<!-- OPENSPEC:END -->

# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概览
这是一个Android游戏修改项目，使用C++原生库进行游戏Hook和Lua脚本解密。项目结构包括：
- 主Android应用（gd.game.lib包名）
- C++原生库（game_core）
- Lua脚本系统（游戏逻辑修改）
- 反调试和混淆保护

## 核心架构

### 1. 构建系统
- **Gradle**: Android应用构建，使用AGP 8.10.0
- **CMake**: C++原生库构建，支持Debug/Release配置
- **Python**: 字符串加密和代码混淆工具
- **NDK**: 支持arm64-v8a, armeabi-v7a, x86, x86_64

### 2. 主要模块
- **Hook引擎**: 使用And64InlineHook进行函数Hook
- **Lua解密**: 游戏脚本解密和修改
- **内存操作**: KittyMemory库进行内存读写
- **字符串加密**: Python脚本生成加密字符串
- **混淆保护**: Obfuscator-LLVM集成

### 3. 关键文件结构
```
app/src/main/cpp/
├── native-lib.cpp          # JNI入口
├── hook.cpp               # 主要Hook逻辑
├── lua_decrypt_hook.cpp   # Lua脚本解密
├── And64InlineHook.cpp    # ARM64 Hook实现
├── tool.cpp              # 工具函数
└── hook/                 # Hook相关库
    ├── KittyMemory/      # 内存操作库
    └── Substrate/        # 底层Hook支持
```

## 常用命令

### 构建命令
```bash
# Debug版本（带日志）
./gradlew assembleDebug

# Release版本（带日志）
./gradlew assembleRelease

# Release版本（无日志，优化性能）
./gradlew assembleRelease -DENABLE_RELEASE_LOGS=OFF

# 安装到所有连接设备
./gradlew installReleaseApp

# 安装并查看日志
./gradlew installReleaseWithLogs
```

### 开发命令
```bash
# 清理构建缓存
./gradlew clean

# 设备信息查看
./gradlew deviceInfo

# 卸载应用并清理
./gradlew uninstallReleaseAndClean

# 测试代码混淆
./gradlew testObfuscation

# 编译混淆版本
./gradlew assembleObfuscatedRelease
```

### 字符串加密
```bash
# 重新生成加密头文件
./gradlew encryptHeaderFiles

# 清理加密文件
./gradlew cleanEncryptedHeaders
```

## 开发模式

### Debug模式
- 启用完整日志输出
- 禁用代码混淆
- 保留调试符号
- 使用明文字符串

### Release模式
- 启用代码混淆（BlackObfuscator）
- 字符串加密
- 移除调试符号
- 可选日志控制

## 环境要求
- **Android Studio**: Arctic Fox或更高版本
- **NDK**: r25或更高版本
- **CMake**: 3.18.1+
- **Python**: 3.8+（用于字符串加密）

## 关键配置
- **包名**: gd.game.lib
- **原生库名称**: game_core
- **签名**: 使用debug.keystore（发布需替换）
- **目标SDK**: 31
- **最小SDK**: 21
- **架构**: 支持ARM64/ARM32/x86/x86_64

## 注意事项
- Release构建会自动启用字符串加密
- 混淆配置在BlackObfuscator块中设置
- Lua脚本修改后需要重新构建
- 调试时使用Debug版本避免混淆影响




● 这个tool.cpp文件是项目的核心工具模块，包含了完整的授权验证、网络通信、文件操作和游戏修改功能。主要特点：

  核心功能

  - 授权验证系统：CDK验证、心跳检测、到期时间管理
  - 网络通信：HTTP GET/POST、AES加密通信、域名验证
  - 文件操作：解压缩、AES解密、文件复制、目录操作
  - 反调试保护：签名验证、域名完整性检查

  关键实现

  - 使用OpenSSL进行AES-256-CBC加密
  - 支持多线程心跳验证（30秒间隔）
  - SharedPreferences XML转JSON/Lua格式
  - 完整的错误处理和日志系统

  安全机制

  - 域名验证防止篡改
  - 应用签名异步验证
  - 敏感信息脱敏日志
  - 到期时间本地校验

  该文件是游戏修改项目的核心授权和工具模块，实现了完整的软件授权验证流程。

    1. 核心验证系统升级
  - 从单层AES验证升级为5层验证体系
  - 新增动态密钥生成（设备指纹+SHA256）
  - 实现时间戳防重放攻击机制
  - 添加线程安全的缓存系统

  2. 安全响应增强
  - 详细的安全日志记录
  - 分层错误处理和用户提示
  - 自动缓存清理机制
  - 防篡改检测和响应

  3. 性能优化
  - 验证结果缓存（最多1000条）
  - 并发安全处理
  - 实时参数更新机制

  4. 代码质量提升
  - 完整的异常处理
  - 详细的调试信息
  - 线程安全的数据访问

  🔍 验证系统架构

  新的验证流程：
  域名提取 → 格式验证 → 动态密钥生成 → SHA256完整性 → 时间戳验证 → 组合验证 → 缓存存储

  📊 系统状态

  - 验证层数: 5层完整验证
  - 缓存容量: 1000条验证结果
  - 防重放: 300秒时间窗口
  - 线程安全: ✅ 已启用mutex锁
  - 动态更新: ✅ 支持实时参数更新

  所有优化已按您的要求"实施全部优化"完成。新的域名完整性检查系统现已投入运行，提供更强大、更安全、更高效的验证能力。   