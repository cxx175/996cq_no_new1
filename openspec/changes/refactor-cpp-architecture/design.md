# C++架构深度重构设计文档

## Context

996CQ项目经过初期开发，C++代码库已达到一定规模（主要文件超过3500行），但缺乏系统化架构设计。当前代码存在高耦合、低内聚、难以维护的问题。本次重构旨在建立现代化C++架构，提升代码质量和性能。

### 当前架构问题
1. **单一大文件**：`tool.cpp`集中了网络、加密、文件、字符串等所有功能
2. **全局状态泛滥**：多个全局变量（`g_extractedDomain`、`g_appName`）
3. **内存管理混乱**：裸指针、手动管理，易出错
4. **缺乏抽象**：具体实现直接暴露，难以替换和测试
5. **性能未优化**：字符串频繁拷贝，无对象池化

### 技术约束
- C++14标准（NDK兼容性）
- Android平台特性（JNI、ABI多架构）
- 现有混淆工具链（Obfuscator-LLVM）
- 不引入大型框架（保持APK体积）

### 利益相关者
- 开发者：更易维护和扩展
- 项目：长期技术债务降低
- 用户：性能提升、稳定性增强

## Goals / Non-Goals

### Goals
✅ **架构层面**
- 建立清晰的四层架构（Core → Service → Utils → JNI）
- 实现模块化设计，单一职责
- 引入依赖注入，降低耦合

✅ **代码质量**
- 统一命名规范（snake_case for functions, PascalCase for classes）
- 完善错误处理（Result<T> 模式）
- 智能指针替代裸指针
- RAII资源管理

✅ **性能优化**
- 减少字符串拷贝（std::string_view, move semantics）
- 加密解密性能提升（缓存、池化）
- 线程池异步处理
- Hook操作优化

✅ **可维护性**
- 完善文档和注释
- 统一日志系统
- 配置集中管理
- 内存安全机制

### Non-Goals
❌ 不引入大型第三方框架（Boost除外的轻量级使用）
❌ 不改变业务逻辑和功能行为
❌ 不增加APK体积超过500KB
❌ 不破坏现有加密混淆机制
❌ 不要求完美的测试覆盖率（实用为主）

## Decisions

### 决策1：四层架构设计

**架构图**：
```
┌─────────────────────────────────────────────┐
│  JNI Layer (jni/)                           │
│  - native_bridge.cpp: JNI入口              │
│  - jni_utils.cpp: JNI辅助工具              │
│  - java_refs.cpp: Java对象引用管理         │
└─────────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────────┐
│  Service Layer (services/)                  │
│  - http_service.cpp: HTTP客户端服务        │
│  - crypto_service.cpp: 加密服务            │
│  - hook_service.cpp: Hook管理服务          │
│  - lua_service.cpp: Lua脚本服务            │
│  - storage_service.cpp: 存储服务           │
│  - thread_pool.cpp: 线程池服务             │
└─────────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────────┐
│  Core Layer (core/)                         │
│  - service_container.cpp: 依赖注入容器     │
│  - result.h: Result<T>错误处理             │
│  - logger.cpp: 统一日志系统                │
│  - config.cpp: 配置管理                    │
│  - memory_pool.cpp: 内存池                 │
└─────────────────────────────────────────────┘
                    ↓
┌─────────────────────────────────────────────┐
│  Utils Layer (utils/)                       │
│  - string_utils.cpp: 字符串工具            │
│  - time_utils.cpp: 时间工具                │
│  - file_utils.cpp: 文件工具                │
│  - crypto_utils.cpp: 加密工具              │
│  - network_utils.cpp: 网络工具             │
└─────────────────────────────────────────────┘
```

**理由**：
- 职责清晰，易于理解和维护
- 层次间依赖单向，降低耦合
- 易于替换实现和单元测试
- 符合SOLID原则

**替代方案**：
- 方案A：扁平化设计 - 拒绝理由：缺乏结构，难以扩展
- 方案B：六边形架构 - 拒绝理由：过于复杂，不适合当前规模

### 决策2：错误处理机制 - Result<T>

**设计**：
```cpp
template<typename T, typename E = std::string>
class Result {
public:
    static Result<T, E> Ok(T value);
    static Result<T, E> Err(E error);
    
    bool is_ok() const;
    bool is_err() const;
    T& unwrap();
    T unwrap_or(T default_value);
    E& error();
};

// 使用示例
Result<std::string> performHttpGet(const std::string& url) {
    if (url.empty()) {
        return Result<std::string>::Err("URL cannot be empty");
    }
    // ... 执行请求
    return Result<std::string>::Ok(response);
}
```

**理由**：
- 明确错误处理，避免异常开销（Android性能考虑）
- 强制调用者处理错误
- 类型安全，编译期检查
- 类似Rust的Result，现代化设计

**替代方案**：
- 方案A：C风格错误码 - 拒绝理由：不安全，易忘记检查
- 方案B：C++异常 - 拒绝理由：性能开销，Android不推荐

### 决策3：智能指针策略

**规则**：
```cpp
// 1. 独占所有权 - unique_ptr
std::unique_ptr<HttpClient> client = std::make_unique<HttpClient>();

// 2. 共享所有权 - shared_ptr
std::shared_ptr<Config> config = std::make_shared<Config>();

// 3. 观察者模式 - weak_ptr
std::weak_ptr<Logger> logger_ref = logger_shared;

// 4. 禁止裸指针（除非必须与C API交互）
// BAD:  char* buffer = new char[1024];
// GOOD: auto buffer = std::make_unique<char[]>(1024);
```

**理由**：
- 自动内存管理，防止泄漏
- 明确所有权语义
- RAII模式，异常安全
- 现代C++最佳实践

### 决策4：依赖注入容器

**设计**：
```cpp
class ServiceContainer {
public:
    template<typename T, typename... Args>
    void register_service(Args&&... args);
    
    template<typename T>
    std::shared_ptr<T> get_service();
    
    void clear_all();
};

// 使用示例
auto container = std::make_shared<ServiceContainer>();
container->register_service<HttpService>(config);
container->register_service<CryptoService>();

auto http = container->get_service<HttpService>();
```

**理由**：
- 解耦服务依赖
- 便于替换实现（测试）
- 集中管理生命周期
- 支持懒加载

### 决策5：字符串性能优化

**策略**：
```cpp
// 1. 使用 string_view 避免拷贝
std::string_view extractDomain(std::string_view url);

// 2. 使用 move 语义
std::string buildData(std::string&& token);

// 3. 预分配空间
std::string result;
result.reserve(estimated_size);

// 4. 字符串池化（常用字符串）
class StringPool {
    std::unordered_set<std::string> pool_;
public:
    std::string_view intern(const std::string& str);
};
```

**理由**：
- 减少内存分配次数
- 降低拷贝开销
- 提升性能30%+
- C++17特性支持

### 决策6：线程池实现

**设计**：
```cpp
class ThreadPool {
public:
    explicit ThreadPool(size_t num_threads = 4);
    ~ThreadPool();
    
    template<typename F, typename... Args>
    auto submit(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;
    
    void wait_all();
    void shutdown();
};

// 使用示例
auto pool = std::make_shared<ThreadPool>(4);
auto future = pool->submit([]() {
    return performHttpGet("https://api.example.com");
});
auto result = future.get();
```

**理由**：
- 避免频繁创建销毁线程
- 控制并发数量
- 异步操作支持
- 性能提升显著

### 决策7：日志系统统一

**设计**：
```cpp
enum class LogLevel {
    DEBUG, INFO, WARN, ERROR
};

class Logger {
public:
    static Logger& instance();
    
    void log(LogLevel level, const char* tag, 
             const char* format, ...);
    
    void set_level(LogLevel level);
    void set_output(std::shared_ptr<LogOutput> output);
};

// 使用宏简化
#define LOG_D(tag, ...) Logger::instance().log(LogLevel::DEBUG, tag, __VA_ARGS__)
#define LOG_I(tag, ...) Logger::instance().log(LogLevel::INFO, tag, __VA_ARGS__)
#define LOG_W(tag, ...) Logger::instance().log(LogLevel::WARN, tag, __VA_ARGS__)
#define LOG_E(tag, ...) Logger::instance().log(LogLevel::ERROR, tag, __VA_ARGS__)
```

**理由**：
- 统一日志接口
- 支持运行时级别调整
- 可扩展输出目标
- 性能监控集成

### 决策8：配置管理中心化

**设计**：
```cpp
class Config {
public:
    static Config& instance();
    
    std::string get_string(const std::string& key, 
                          const std::string& default_value = "");
    int get_int(const std::string& key, int default_value = 0);
    bool get_bool(const std::string& key, bool default_value = false);
    
    void set(const std::string& key, const std::string& value);
    void load_from_file(const std::string& path);
};

// 使用示例
Config::instance().set("http.timeout", "30");
int timeout = Config::instance().get_int("http.timeout", 30);
```

**理由**：
- 配置集中管理
- 避免硬编码
- 支持运行时修改
- 便于测试和调试

## Risks / Trade-offs

### 风险1：大规模重构引入Bug
**缓解措施**：
- 分5个阶段渐进式重构
- 每阶段完成后完整回归测试
- 保留旧代码作为fallback
- 关键路径双写验证

### 风险2：性能回退
**缓解措施**：
- 每阶段进行性能基准测试
- 对比重构前后数据
- 性能热点使用profiler分析
- 必要时保留优化版本

### 风险3：APK体积增大
**缓解措施**：
- 控制模板使用（避免代码膨胀）
- 启用LTO和strip符号
- 监控每阶段体积变化
- 目标增量<500KB

### 风险4：开发周期延长
**缓解措施**：
- 明确每阶段里程碑
- 优先重构核心模块
- 允许新旧代码并存
- 设置4-6周时间窗口

### Trade-off: 抽象 vs 性能
**决策**：适度抽象优先
- 非热点路径：重视可维护性
- 热点路径：保留性能优化版本
- 通过性能测试验证

### Trade-off: 完美 vs 实用
**决策**：实用优先
- 不追求100%测试覆盖
- 不过度设计（YAGNI原则）
- 渐进式优化
- 保持简单可理解

## Migration Plan

### 阶段0：准备阶段（1-2天）
- [ ] 建立性能基准测试
- [ ] 代码备份和分支管理
- [ ] 搭建新架构骨架
- [ ] 配置CI/CD验证

### 阶段1：核心基础设施（1周）
- [ ] 实现Result<T>错误处理
- [ ] 实现Logger日志系统
- [ ] 实现Config配置管理
- [ ] 实现ServiceContainer
- [ ] 建立四层目录结构

### 阶段2：工具层重构（1周）
- [ ] StringUtils（string_view优化）
- [ ] TimeUtils
- [ ] FileUtils（RAII化）
- [ ] CryptoUtils基础
- [ ] NetworkUtils基础

### 阶段3：服务层重构（1.5周）
- [ ] HttpService（线程池集成）
- [ ] CryptoService（性能优化）
- [ ] StorageService
- [ ] ThreadPool实现
- [ ] 依赖注入接入

### 阶段4：业务模块重构（1周）
- [ ] HookService重构
- [ ] LuaService重构
- [ ] 拆分tool.cpp（核心功能迁移）
- [ ] 内存管理优化
- [ ] 性能监控集成

### 阶段5：JNI层适配（0.5周）
- [ ] JNI桥接层重构
- [ ] Java引用管理
- [ ] 错误处理统一
- [ ] API文档完善

### 回滚策略
- 每阶段保持功能等价性
- 通过feature flag切换新旧实现
- 发现严重问题立即回滚
- 保留旧代码至少一个版本

### 验证标准
- [ ] 所有功能测试通过
- [ ] 性能不低于重构前
- [ ] 内存泄漏检测通过
- [ ] APK体积增量<500KB
- [ ] 代码Review通过

## Open Questions

1. **Q**: 是否需要引入协程支持异步编程？
   **A**: 暂不引入，C++20协程NDK支持不完善，使用线程池足够

2. **Q**: Result<T>是否需要支持多错误类型？
   **A**: 第一阶段使用std::string，后续可扩展为ErrorCode枚举

3. **Q**: 是否需要实现对象池？
   **A**: 根据性能测试结果决定，热点对象优先池化

4. **Q**: 日志系统是否需要支持远程上报？
   **A**: 第一阶段本地日志，第二阶段考虑扩展

5. **Q**: 是否需要Mock框架支持单元测试？
   **A**: 暂不引入，通过依赖注入提供测试替身即可

## References

- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Modern C++ Design Patterns](https://refactoring.guru/design-patterns/cpp)
- [Android NDK Best Practices](https://developer.android.com/ndk/guides)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

