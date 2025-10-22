## Context

`tool.cpp` 是项目的核心工具文件，包含 3543 行代码，涵盖了加密解密、网络通信、文件操作、数据验证等多个功能。当前存在严重的代码重复和结构混乱问题，需要进行全面重构。

## Goals / Non-Goals

### Goals
- 将 3543 行的单一文件拆分为多个功能模块（每个模块 < 500 行）
- 消除重复的 AES 加密/解密代码，创建统一的加密接口
- 统一字符串处理逻辑，减少重复代码
- 优化内存使用，减少不必要的字符串拷贝
- 保持现有 API 的向后兼容性
- 提高代码可读性和可维护性

### Non-Goals
- 不改变现有的公共 API 接口
- 不修改 JNI 接口定义
- 不改变现有的日志格式和级别
- 不修改现有的错误处理策略

## Decisions

### 决策 1: 模块化拆分策略
**选择**: 按功能域拆分为独立模块
- `CryptoUtils` - 加密解密相关功能
- `StringUtils` - 字符串处理工具
- `FileUtils` - 文件操作功能  
- `NetworkUtils` - 网络通信功能
- `ValidationUtils` - 数据验证功能

**替代方案**: 按层次拆分（数据层、业务层、工具层）
**理由**: 按功能域拆分更符合单一职责原则，便于维护和测试

### 决策 2: 加密接口统一
**选择**: 创建 `CryptoManager` 类，提供统一的加密接口
```cpp
class CryptoManager {
public:
    static std::string encryptAES(const std::string& data, const std::string& key, const std::string& iv);
    static std::string decryptAES(const std::string& encrypted, const std::string& key, const std::string& iv);
    static std::string generateRandomKey(size_t length);
};
```

**替代方案**: 保持现有函数，仅优化内部实现
**理由**: 统一接口可以消除重复代码，提供更好的错误处理

### 决策 3: 字符串处理优化
**选择**: 使用 `std::string_view` 和移动语义减少拷贝
```cpp
class StringUtils {
public:
    static std::string hexToBinary(std::string_view hexStr);
    static std::string binaryToHex(std::string_view binaryStr);
    static bool isHexString(std::string_view str);
};
```

**替代方案**: 保持现有字符串处理方式
**理由**: 使用现代 C++ 特性可以显著提升性能

### 决策 4: 错误处理策略
**选择**: 使用统一的错误码和异常处理机制
```cpp
enum class ToolError {
    SUCCESS = 0,
    INVALID_PARAMETER,
    ENCRYPTION_FAILED,
    FILE_OPERATION_FAILED,
    NETWORK_ERROR
};
```

**替代方案**: 保持现有的布尔返回值方式
**理由**: 统一的错误处理可以提供更好的错误信息和调试支持

## Risks / Trade-offs

### 风险 1: 重构过程中引入 Bug
**缓解措施**: 
- 保持现有 API 不变，仅重构内部实现
- 分阶段重构，每个模块独立测试
- 保留原始文件作为备份

### 风险 2: 性能回归
**缓解措施**:
- 使用性能测试验证重构前后性能
- 优化热点路径，使用移动语义
- 监控内存使用情况

### 风险 3: 编译时间增加
**缓解措施**:
- 使用前向声明减少头文件依赖
- 合理使用 PIMPL 模式
- 考虑预编译头文件

## Migration Plan

### 阶段 1: 准备工作
1. 创建备份文件 `tool.cpp.backup`
2. 分析现有函数依赖关系
3. 设计新的模块结构

### 阶段 2: 模块化重构
1. 创建 `CryptoUtils` 模块，重构加密相关函数
2. 创建 `StringUtils` 模块，重构字符串处理函数
3. 创建 `FileUtils` 模块，重构文件操作函数
4. 创建 `NetworkUtils` 模块，重构网络通信函数
5. 创建 `ValidationUtils` 模块，重构验证函数

### 阶段 3: 集成测试
1. 更新 `tool.h` 头文件
2. 修改 `tool.cpp` 使用新的模块
3. 运行完整测试套件
4. 性能基准测试

### 阶段 4: 清理和优化
1. 移除重复代码
2. 优化内存使用
3. 更新文档和注释

## Open Questions

1. **是否需要保持所有现有函数的完全兼容性？**
   - 某些内部函数可能可以简化参数
   - 建议保持公共 API 不变

2. **如何处理全局变量和静态变量？**
   - 考虑使用单例模式或依赖注入
   - 确保线程安全性

3. **是否需要添加单元测试？**
   - 建议为每个模块添加单元测试
   - 使用 Google Test 框架

4. **重构的优先级如何确定？**
   - 建议按使用频率和复杂度排序
   - 先重构最常用的功能
