# Project Context

## Purpose
996cq_no_new1 是一个Android游戏辅助工具项目，主要功能是为传奇类游戏提供自动化辅助功能。该项目通过JNI技术结合Java和C++实现，包含Lua脚本引擎用于游戏逻辑处理，提供悬浮窗界面进行用户交互，并实现了多种游戏辅助功能如自动战斗、技能冷却、自动拾取等。

项目采用授权验证模式，包含完整的CDK验证系统、心跳检测机制和网络安全通信模块，确保软件的合法使用和版本控制。

## Tech Stack

### 核心开发框架
- **Android开发**: Java (Android SDK 31), Gradle 8.10.0, AGP 8.10.0
- **原生开发**: C++14, CMake 3.18.1, NDK r25+
- **脚本引擎**: Lua 5.1.5 (支持脚本解密和热更新)
- **包名**: load.tencent.lib

### 网络与通信
- **HTTP客户端**: OkHttp3, libcurl
- **加密通信**: AES-256-CBC加密, SHA256完整性验证
- **网络安全**: 域名验证、时间戳防重放、动态密钥生成

### 安全与保护
- **加密库**: OpenSSL (AES加密、哈希计算)
- **代码混淆**: BlackObfuscator (Java), Obfuscator-LLVM (C++)
- **Hook技术**: And64InlineHook (ARM64), Dobby, Substrate
- **反调试**: 签名验证、进程完整性检查

### 内存与操作
- **内存操作**: KittyMemory库 (内存读写、修改)
- **Hook引擎**: And64InlineHook, Dobby (函数Hook)
- **数据格式**: SharedPreferences XML转JSON/Lua

### UI与交互
- **UI框架**: Android原生UI系统
- **悬浮窗**: 自定义前台服务实现
- **用户交互**: 触摸事件、按键监听

### 构建与部署
- **构建系统**: Gradle (Android), CMake (C++)
- **自动化脚本**: Python 3.8+ (字符串加密、代码混淆)
- **架构支持**: arm64-v8a, armeabi-v7a, x86, x86_64
- **调试工具**: 日志系统、内存监控

## Project Conventions

### Code Style
- **Java**: 遵循Android官方代码规范，使用驼峰命名法
  - 类名首字母大写 (PascalCase)
  - 方法和变量使用驼峰命名法 (camelCase)
  - 常量使用全大写加下划线 (UPPER_SNAKE_CASE)

- **C++**: 使用C++14标准，遵循Google C++代码规范
  - 函数和变量使用下划线命名法 (snake_case)
  - 类名使用PascalCase
  - 常量使用kSnakeCase或全大写
  - 智能指针优先于原始指针

- **Lua**: 遵循Lua社区通用规范，使用驼峰命名法
  - 全局变量使用g前缀 (gGlobalVar)
  - 局部变量使用驼峰命名法

- **文件组织**:
  - 按功能模块划分目录 (hook/, lua/, utils/)
  - assets目录按mod组织 (mod_fgcq/, mod_launcher/)
  - 头文件(.h)和源文件(.cpp)分离

- **注释规范**:
  - 关键函数和复杂逻辑必须添加中文注释
  - 使用Doxygen风格的文档注释
  - Hook点注释必须说明原函数作用和修改目的

### Architecture Patterns
- **整体架构**: 采用MVC模式，结合JNI桥接Java和C++
  - Model: 数据层 (游戏状态、配置信息)
  - View: UI层 (悬浮窗、设置界面)
  - Controller: 控制层 (Hook逻辑、脚本执行)

- **模块化设计**:
  - 核心功能分为独立模块 (mod_fgcq游戏功能, mod_launcher启动器)
  - 每个模块包含Java接口、C++实现、Lua脚本
  - 模块间通过定义的接口通信

- **Hook系统**:
  - 使用函数Hook技术实现游戏功能修改
  - Hook点集中管理，支持动态开启/关闭
  - Hook失败时有完整的回滚机制

- **脚本系统**:
  - Lua脚本实现游戏逻辑，支持热更新
  - 脚本加密存储，运行时解密
  - 提供安全的Lua API接口

- **权限管理**: 集中管理Android权限请求
  - 悬浮窗权限 (SYSTEM_ALERT_WINDOW)
  - 存储权限 (READ/WRITE_EXTERNAL_STORAGE)
  - 无障碍权限 (AccessibilityService)

- **服务架构**:
  - 前台服务实现悬浮窗功能
  - 多线程处理避免阻塞主线程
  - 服务保活机制防止被系统杀死

### 构建配置
- **Debug模式**:
  - 启用完整日志输出 (LOGLEVEL=DEBUG)
  - 禁用代码混淆便于调试
  - 保留调试符号和源码映射
  - 使用明文字符串

- **Release模式**:
  - 启用代码混淆 (BlackObfuscator)
  - 字符串自动加密
  - 移除调试符号减小体积
  - 可选日志控制 (ENABLE_RELEASE_LOGS)

### Testing Strategy
- **单元测试**:
  - 对核心功能模块进行单元测试
  - 覆盖加密解密、网络通信、文件操作
  - 使用Google Test框架进行C++测试

- **集成测试**:
  - 测试Java与C++之间的JNI交互
  - 验证Hook功能在不同游戏版本中的表现
  - 测试Lua脚本的正确执行

- **功能测试**:
  - 在真实游戏环境中验证辅助功能
  - 测试各个功能的独立性和兼容性
  - 验证悬浮窗操作的响应性

- **性能测试**:
  - 监控内存使用 (目标<100MB)
  - CPU占用率测试 (目标<10%)
  - 长时间运行稳定性测试 (24小时+)

- **兼容性测试**:
  - 不同Android版本 (API 21-31)
  - 不同设备架构 (ARM64/ARM32/x86/x86_64)
  - 不同游戏版本兼容性验证

### Git Workflow
- **分支策略**:
  - main: 稳定发布分支
  - develop: 开发集成分支
  - feature/*: 功能开发分支
  - hotfix/*: 紧急修复分支

- **提交规范**:
  - 使用中文提交信息
  - 格式: "类型: 简短描述"
  - 类型: feat(新功能), fix(修复), docs(文档), style(格式), refactor(重构), test(测试), chore(构建)

- **代码审查**:
  - 所有代码合并前必须经过审查
  - 检查代码规范、安全性、性能
  - 必须通过所有自动化测试

- **版本管理**:
  - 使用语义化版本号 (major.minor.patch)
  - 标记重要里程碑和发布节点
  - 自动化构建和发布流程

## Domain Context
该项目专注于传奇类游戏的辅助功能开发，主要涉及以下领域知识：

### 游戏领域
- **游戏机制**: 深入理解传奇类游戏的战斗系统、技能系统、物品系统
- **游戏协议**: 网络通信协议分析、数据包结构解析
- **游戏逻辑**: 游戏状态管理、事件触发机制
- **游戏安全**: 理解游戏的反作弊机制和检测手段

### 技术领域
- **内存操作**: 游戏内存读取、修改和Hook技术
- **Android系统**: 深入理解Android权限系统、服务机制、进程通信
- **逆向工程**: 游戏客户端逆向分析和协议分析
- **网络安全**: HTTP/HTTPS通信、数据加密传输
- **系统编程**: 底层API调用、系统服务交互

### 业务领域
- **用户体验**: 悬浮窗交互设计、功能易用性
- **软件授权**: CDK验证、在线激活、到期管理
- **版本控制**: 软件更新机制、兼容性管理
- **合规要求**: 遵守相关法律法规，用户协议

## Important Constraints

### 系统约束
- **兼容性**: 必须支持Android 5.0以上系统 (API 21+)
- **架构支持**: arm64-v8a, armeabi-v7a, x86, x86_64
- **目标SDK**: Android 12 (API 31)
- **最低SDK**: Android 5.0 (API 21)

### 性能约束
- **内存占用**: 不超过100MB长期使用
- **CPU占用**: 空闲时<5%，使用时<10%
- **电池消耗**: 最小化后台运行功耗
- **网络流量**: 心跳检测每次<1KB
- **启动时间**: 冷启动<3秒，热启动<1秒

### 稳定性约束
- **连续运行**: 24小时无崩溃
- **错误恢复**: 网络异常、游戏崩溃时自动恢复
- **内存泄漏**: 无内存泄漏，长时间运行稳定
- **异常处理**: 完整的异常捕获和处理机制

### 安全性约束
- **反检测**: 防止被游戏检测系统识别
- **代码保护**: 多层代码混淆和加密
- **通信安全**: 网络通信全程加密
- **数据保护**: 用户数据本地加密存储
- **权限最小化**: 仅请求必要的系统权限

### 合规性约束
- **法律合规**: 遵守相关法律法规
- **游戏协议**: 不违反游戏用户协议
- **数据隐私**: 不收集用户敏感信息
- **使用范围**: 明确软件使用边界和限制

## External Dependencies

### 核心依赖
- **Android SDK**: 提供Android系统API访问
  - minSdkVersion: 21
  - targetSdkVersion: 31
  - compileSdkVersion: 31

- **Android NDK**: 原生开发支持
  - 版本: r25+
  - 支持架构: arm64-v8a, armeabi-v7a, x86, x86_64

### 构建工具
- **Gradle**: 8.10.0 (Android构建系统)
- **CMake**: 3.18.1+ (C++构建系统)
- **Python**: 3.8+ (自动化脚本)
- **JDK**: 11+ (Java开发环境)

### 第三方库
- **OpenSSL 1.1.1+**: 提供加密功能支持
  - AES-256-CBC加密
  - SHA256哈希计算
  - 随机数生成

- **libcurl 7.78+**: 提供HTTP/HTTPS网络请求功能
  - 支持HTTPS/TLS
  - 自定义User-Agent
  - 超时和重试机制

- **Lua 5.1.5**: 提供脚本执行环境
  - 轻量级脚本引擎
  - 支持热更新
  - 安全的API接口

- **KittyMemory**: 内存操作库
  - 跨进程内存读写
  - 内存地址搜索
  - 内存修改和保护

### Hook框架
- **And64InlineHook**: ARM64架构函数Hook
- **Dobby**: 通用Hook框架 (多架构支持)
- **Substrate**: 底层Hook支持库
- **PLT Hook**: 动态库函数Hook

### 混淆工具
- **BlackObfuscator**: Java代码混淆
  - 字符串加密
  - 控制流混淆
  - 类和方法混淆

- **Obfuscator-LLVM**: C++代码混淆
  - 函数混淆
  - 控制流平坦化
  - 指令替换

### 开发工具
- **Android Studio**: Arctic Fox+
- **ADB**: Android调试桥
- **GDB**: 原生代码调试
- **Memory Profiler**: 内存分析工具
- **CPU Profiler**: 性能分析工具

### 许可证
- 大部分依赖使用开源许可证 (MIT, Apache 2.0, BSD)
- 商业组件需要相应的授权许可
- 遵守所有第三方库的许可证要求

## 开发环境要求

### 硬件要求
- **内存**: 最少8GB RAM (推荐16GB)
- **存储**: 至少10GB可用空间
- **CPU**: 支持虚拟化技术的64位处理器

### 软件环境
- **操作系统**: Windows 10/11, macOS 10.15+, Ubuntu 18.04+
- **IDE**: Android Studio Arctic Fox或更高版本
- **Git**: 版本控制管理
- **ADB**: Android调试工具

### 配置要求
- **Java**: JDK 11+ (建议使用JDK 17)
- **Python**: 3.8+ (用于字符串加密脚本)
- **CMake**: 3.18.1+ (C++构建)
- **Gradle**: 8.10.0 (项目构建)

## 项目结构

### 主要目录结构
```
996cq_no_new1/
├── app/                          # Android应用主目录
│   ├── src/main/
│   │   ├── java/                 # Java源代码
│   │   ├── cpp/                  # C++源代码
│   │   │   ├── hook/            # Hook相关代码
│   │   │   ├── lua/             # Lua脚本处理
│   │   │   ├── utils/           # 工具函数
│   │   │   └── *.cpp            # 主要源文件
│   │   ├── assets/              # 资源文件
│   │   │   ├── mod_fgcq/        # 游戏功能模块
│   │   │   └── mod_launcher/    # 启动器模块
│   │   └── res/                 # Android资源
│   ├── build.gradle             # 应用构建配置
│   └── CMakeLists.txt           # C++构建配置
├── openspec/                     # 项目规范文档
│   ├── specs/                   # 功能规格说明
│   ├── changes/                 # 变更记录
│   └── project.md               # 项目上下文 (本文件)
├── scripts/                      # 自动化脚本
│   ├── encrypt_strings.py       # 字符串加密
│   └── obfuscate.py             # 代码混淆
└── tools/                        # 开发工具
    └── string_encryptor/        # 字符串加密工具
```

### 核心文件说明
- **native-lib.cpp**: JNI入口点，Java与C++桥接
- **hook.cpp**: 主要Hook逻辑实现
- **lua_decrypt_hook.cpp**: Lua脚本解密处理
- **tool.cpp**: 工具函数集合 (加密、网络、文件操作)
- **app_strings.h/cpp**: 加密字符串管理
- **And64InlineHook.cpp**: ARM64架构Hook实现

## 常用开发命令

### 构建命令
```bash
# Debug版本 (带完整日志)
./gradlew assembleDebug

# Release版本 (标准配置，带日志)
./gradlew assembleRelease

# Release版本 (无日志，性能优化)
./gradlew assembleRelease -DENABLE_RELEASE_LOGS=OFF

# 混淆版本 (最高安全级别)
./gradlew assembleObfuscatedRelease

# 清理构建缓存
./gradlew clean
```

### 安装和调试
```bash
# 安装到所有连接设备
./gradlew installReleaseApp

# 安装并查看实时日志
./gradlew installReleaseWithLogs

# 设备信息查看
./gradlew deviceInfo

# 卸载应用并清理数据
./gradlew uninstallReleaseAndClean
```

### 字符串加密
```bash
# 重新生成加密头文件
./gradlew encryptHeaderFiles

# 清理加密文件缓存
./gradlew cleanEncryptedHeaders

# 测试代码混淆效果
./gradlew testObfuscation
```

## 发布流程

### 版本准备
1. 更新版本号 (build.gradle)
2. 更新变更日志 (CHANGELOG.md)
3. 运行完整测试套件
4. 执行代码混淆和字符串加密

### 构建发布
1. 清理项目 (`./gradlew clean`)
2. 构建Release版本 (`./gradlew assembleRelease`)
3. 运行最终测试
4. 生成签名APK

### 质量检查
- [ ] 所有单元测试通过
- [ ] 集成测试验证
- [ ] 性能指标达标
- [ ] 安全扫描通过
- [ ] 兼容性测试完成
- [ ] 文档更新完整

---

*本文档随项目发展持续更新，最后更新时间：2025年10月*
