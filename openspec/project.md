# Project Context

## Purpose
996cq_no_new1 是一个Android游戏辅助工具项目，主要功能是为传奇类游戏提供自动化辅助功能。该项目通过JNI技术结合Java和C++实现，包含Lua脚本引擎用于游戏逻辑处理，提供悬浮窗界面进行用户交互，并实现了多种游戏辅助功能如自动战斗、技能冷却、自动拾取等。

## Tech Stack
- **Android开发**: Java (Android SDK 31), Gradle 8.10.0
- **原生开发**: C++14, CMake 3.18.1, NDK
- **脚本引擎**: Lua 5.1.5
- **网络通信**: OkHttp3, libcurl
- **加密安全**: OpenSSL, BlackObfuscator (代码混淆)
- **Hook技术**: And64InlineHook, Dobby, Substrate
- **UI框架**: Android原生UI, 自定义悬浮窗
- **构建工具**: Gradle, CMake, Python脚本 (用于代码混淆和字符串加密)
- **架构支持**: arm64-v8a, armeabi-v7a, x86, x86_64

## Project Conventions

### Code Style
- **Java**: 遵循Android官方代码规范，使用驼峰命名法
- **C++**: 使用C++14标准，遵循Google C++代码规范，使用下划线命名法
- **Lua**: 遵循Lua社区通用规范，使用驼峰命名法
- **文件组织**: 按功能模块划分目录，assets目录按mod组织
- **注释**: 关键函数和复杂逻辑必须添加中文注释

### Architecture Patterns
- **整体架构**: 采用MVC模式，结合JNI桥接Java和C++
- **模块化设计**: 核心功能分为多个模块(mod_fgcq, mod_launcher)
- **Hook系统**: 使用函数Hook技术实现游戏功能修改
- **脚本系统**: Lua脚本实现游戏逻辑，支持热更新
- **权限管理**: 集中管理Android权限请求
- **服务架构**: 前台服务实现悬浮窗功能

### Testing Strategy
- **单元测试**: 对核心功能模块进行单元测试
- **集成测试**: 测试Java与C++之间的JNI交互
- **功能测试**: 在真实游戏环境中验证辅助功能
- **性能测试**: 监控内存使用和CPU占用
- **兼容性测试**: 在不同Android版本和设备上测试

### Git Workflow
- **分支策略**: GitFlow工作流，main为稳定分支，develop为开发分支
- **提交规范**: 使用中文提交信息，格式为"类型: 简短描述"
- **代码审查**: 所有代码合并前必须经过审查
- **版本管理**: 使用语义化版本号，标记重要里程碑

## Domain Context
该项目专注于传奇类游戏的辅助功能开发，主要涉及以下领域知识：
- **游戏机制**: 理解传奇类游戏的战斗系统、技能系统、物品系统
- **内存操作**: 游戏内存读取、修改和Hook技术
- **Android系统**: 深入理解Android权限系统、服务机制、进程通信
- **逆向工程**: 游戏客户端逆向分析和协议分析
- **安全防护**: 代码混淆、反调试、签名验证等技术

## Important Constraints
- **兼容性**: 必须支持Android 5.0以上系统 (API 21+)
- **性能**: 内存占用不超过100MB，CPU占用不超过10%
- **稳定性**: 连续运行24小时无崩溃
- **安全性**: 防止被游戏检测系统识别
- **权限**: 最小化权限请求，仅请求必要权限
- **合规性**: 遵守相关法律法规，不涉及游戏数据篡改

## External Dependencies
- **Android SDK**: 提供Android系统API访问
- **OpenSSL**: 提供加密功能支持
- **libcurl**: 提供HTTP/HTTPS网络请求功能
- **Lua引擎**: 提供脚本执行环境
- **Dobby/And64InlineHook**: 提供函数Hook功能
- **BlackObfuscator**: 提供Java代码混淆功能
- **Obfuscator-LLVM**: 提供C++代码混淆功能
