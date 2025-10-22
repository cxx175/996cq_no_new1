# Implementation Tasks

## 1. 更新CMake配置
- [ ] 1.1 更新CMakeLists.txt中的project()名称为"game_core"
- [ ] 1.2 更新CMakeLists.txt中的add_library()库名称为game_core
- [ ] 1.3 更新CMakeLists.txt中的target_link_libraries()引用
- [ ] 1.4 更新CMakeLists.txt中的target_compile_definitions()引用
- [ ] 1.5 更新CMakeLists.txt中的add_dependencies()引用

## 2. 更新Java代码
- [ ] 2.1 更新MainActivity.java中的System.loadLibrary()调用
- [ ] 2.2 更新appStrings.java中的System.loadLibrary()调用

## 3. 更新字符串常量
- [ ] 3.1 更新strings.txt中的Sative字符串值
- [ ] 3.2 重新生成app_strings.h（通过构建系统自动完成）
- [ ] 3.3 重新生成app_strings.cpp（通过构建系统自动完成）

## 4. 更新构建配置
- [ ] 4.1 更新build.gradle中的SO文件路径引用（lib996cq_native.so -> libgame_core.so）

## 5. 更新文档
- [ ] 5.1 更新CLAUDE.md中的库名称说明

## 6. 验证和测试
- [ ] 6.1 清理构建缓存（./gradlew clean）
- [ ] 6.2 执行Debug构建验证（./gradlew assembleDebug）
- [ ] 6.3 验证SO文件生成（检查libgame_core.so是否生成）
- [ ] 6.4 安装测试应用，确保库加载成功
- [ ] 6.5 执行Release构建验证（./gradlew assembleRelease）
- [ ] 6.6 验证所有架构的SO文件（arm64-v8a, armeabi-v7a, x86, x86_64）

