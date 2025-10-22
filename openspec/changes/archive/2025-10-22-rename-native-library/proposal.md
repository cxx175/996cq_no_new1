# Rename Native Library Proposal

## Why
当前原生库名称 `996cq_native` 包含敏感数字且不够专业，需要更改为更加通用和专业的名称 `game_core`，以提升代码的可维护性和专业性。

## What Changes
- 将原生库名称从 `996cq_native` 重命名为 `game_core`
- 更新CMakeLists.txt中的项目名称和库名称定义
- 更新Java代码中的System.loadLibrary()调用
- 更新app_strings.h/cpp中的字符串常量定义
- 更新build.gradle中的SO文件路径引用
- 更新CLAUDE.md文档中的库名称说明

## Impact
- 影响的规格: app
- 影响的代码:
  - `app/src/main/cpp/CMakeLists.txt` - 项目名称和库定义
  - `app/src/main/java/gd/game/lib/MainActivity.java` - 库加载
  - `app/src/main/java/gd/game/lib/appStrings.java` - 库加载
  - `app/src/main/cpp/app_strings.h` - 字符串常量
  - `app/src/main/cpp/app_strings.cpp` - 字符串常量
  - `app/src/main/cpp/strings.txt` - 明文字符串定义
  - `app/build.gradle` - SO文件路径
  - `CLAUDE.md` - 文档说明

## Scope
本次重命名仅针对原生库名称（native library name），不包括：
- 应用显示名称和菜单标题（如"996CQ菜单"）
- 日志标签（如"996CQ"）
- 加密密钥名称（如"996cq_domain_encryption_key_32"）
- 其他业务相关的标识符

这些保持不变，以确保向后兼容性和用户体验的连续性。

## Breaking Changes
无破坏性变更 - 这是一个内部重命名，不影响外部API或用户数据。

