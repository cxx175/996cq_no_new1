# App Specification Delta

## ADDED Requirements

### Requirement: 原生库命名规范
原生库名称SHALL采用专业、通用的命名方式，避免使用敏感字符或数字，确保代码的可维护性和专业性。

#### Scenario: 原生库名称使用专业命名
- **WHEN** 定义原生库名称
- **THEN** 库名称SHALL使用`game_core`
- **AND** 名称SHALL遵循下划线命名规范（snake_case）
- **AND** 名称SHALL清晰表达库的功能和用途

#### Scenario: CMake项目配置
- **WHEN** 配置CMake项目
- **THEN** project()函数SHALL使用"game_core"作为项目名称
- **AND** add_library()函数SHALL使用game_core作为库名称
- **AND** 所有目标引用SHALL使用game_core

#### Scenario: Java层库加载
- **WHEN** Java代码需要加载原生库
- **THEN** System.loadLibrary()SHALL使用"game_core"作为参数
- **AND** 库加载SHALL在static块中执行
- **AND** MainActivity和appStrings类SHALL都正确加载该库

#### Scenario: 字符串常量定义
- **WHEN** 定义原生库名称字符串常量
- **THEN** strings.txt中SHALL定义Sative=game_core
- **AND** app_strings.h中SHALL通过加密生成对应的宏定义
- **AND** 字符串常量SHALL用于运行时验证和日志记录

#### Scenario: 构建产物命名
- **WHEN** 构建系统生成SO文件
- **THEN** SO文件名称SHALL为libgame_core.so
- **AND** 所有架构（arm64-v8a, armeabi-v7a, x86, x86_64）SHALL生成对应的SO文件
- **AND** build.gradle中的文件路径引用SHALL正确指向新的SO文件名

#### Scenario: 多架构支持
- **WHEN** 为不同架构构建原生库
- **THEN** 每个架构目录下SHALL包含libgame_core.so文件
- **AND** 文件名格式SHALL保持一致
- **AND** Android系统SHALL能够根据设备架构自动加载正确的SO文件

