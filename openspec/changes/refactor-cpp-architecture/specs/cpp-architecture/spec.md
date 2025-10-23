# C++架构设计规范

## ADDED Requirements

### Requirement: 四层架构设计

系统SHALL采用清晰的四层架构设计，从下到上依次为：Utils层、Core层、Service层和JNI层。

#### Scenario: 架构层次依赖
- **WHEN** 开发者添加新功能代码
- **THEN** 必须遵循层次依赖规则：JNI → Service → Core → Utils
- **AND** 不允许跨层依赖（如JNI直接依赖Utils）
- **AND** 不允许反向依赖（如Utils依赖Core）

#### Scenario: 模块目录结构
- **WHEN** 开发者查看cpp目录结构
- **THEN** 应看到以下目录组织：
  - `app/src/main/cpp/core/` - 核心基础设施
  - `app/src/main/cpp/services/` - 业务服务层
  - `app/src/main/cpp/utils/` - 工具类库
  - `app/src/main/cpp/jni/` - JNI桥接层

#### Scenario: 命名空间组织
- **WHEN** 编写C++代码
- **THEN** 必须使用对应的命名空间：
  - Utils层代码在 `namespace utils {}`
  - Core层代码在 `namespace core {}`
  - Service层代码在 `namespace services {}`
  - JNI层代码在 `namespace jni {}`

### Requirement: 模块化设计原则

系统SHALL按照功能职责划分为独立模块，每个模块具有单一职责。

#### Scenario: 模块独立性
- **WHEN** 修改某个模块的实现
- **THEN** 不应影响其他模块的功能
- **AND** 通过接口依赖而非实现依赖
- **AND** 模块间通过依赖注入解耦

#### Scenario: 核心模块划分
- **WHEN** 查看Services层
- **THEN** 应包含以下独立服务模块：
  - HttpService - HTTP客户端服务
  - CryptoService - 加密服务
  - HookService - Hook管理服务
  - LuaService - Lua脚本服务
  - StorageService - 存储服务
  - ThreadPool - 线程池服务

#### Scenario: 工具模块划分
- **WHEN** 查看Utils层
- **THEN** 应包含以下工具模块：
  - StringUtils - 字符串工具
  - TimeUtils - 时间工具
  - FileUtils - 文件工具
  - CryptoUtils - 加密工具基础
  - NetworkUtils - 网络工具基础

### Requirement: 依赖注入容器

系统SHALL提供统一的依赖注入容器，管理服务的创建和生命周期。

#### Scenario: 服务注册
- **WHEN** 应用初始化时
- **THEN** 所有服务必须注册到ServiceContainer
- **AND** 服务可以声明依赖其他服务
- **AND** 容器自动解析依赖关系

#### Scenario: 服务获取
- **WHEN** 代码需要使用某个服务
- **THEN** 通过容器的get_service<T>()方法获取
- **AND** 返回智能指针（shared_ptr）
- **AND** 服务为单例（同一类型返回同一实例）

#### Scenario: 服务生命周期
- **WHEN** 应用退出时
- **THEN** 容器自动释放所有服务
- **AND** 服务按照依赖关系逆序销毁
- **AND** 确保资源正确释放

### Requirement: 统一错误处理机制

系统SHALL使用Result<T, E>模板类进行错误处理，替代传统的返回码或异常。

#### Scenario: Result返回值
- **WHEN** 函数可能失败时
- **THEN** 返回类型必须为Result<T>
- **AND** 成功时返回Result<T>::Ok(value)
- **AND** 失败时返回Result<T>::Err(error_message)

#### Scenario: 错误检查
- **WHEN** 调用返回Result的函数
- **THEN** 调用者必须检查结果：
  ```cpp
  auto result = someFunction();
  if (result.is_err()) {
      LOG_E("Error: %s", result.error().c_str());
      return;
  }
  auto value = result.unwrap();
  ```

#### Scenario: 错误传播
- **WHEN** 函数内部调用其他返回Result的函数
- **THEN** 可以使用宏简化错误传播：
  ```cpp
  auto result = RESULT_TRY(innerFunction());
  ```
- **AND** 失败时自动返回错误

### Requirement: 统一日志系统

系统SHALL提供统一的Logger类，替代分散的日志宏。

#### Scenario: 日志级别控制
- **WHEN** 使用日志系统
- **THEN** 支持四种级别：DEBUG, INFO, WARN, ERROR
- **AND** 可以运行时切换日志级别
- **AND** Release模式默认级别为INFO

#### Scenario: 日志输出格式
- **WHEN** 输出日志
- **THEN** 格式为：`[时间戳][线程ID][级别][标签] 消息`
- **AND** 自动添加文件名和行号（DEBUG模式）
- **AND** 支持格式化字符串（printf风格）

#### Scenario: 性能日志
- **WHEN** 需要测量函数耗时
- **THEN** 使用PERF_LOG宏：
  ```cpp
  PERF_LOG("functionName") {
      // 函数实现
  }
  ```
- **AND** 自动记录执行时间
- **AND** 超过阈值时输出警告

### Requirement: 配置管理中心化

系统SHALL提供Config单例类，集中管理所有配置项。

#### Scenario: 配置读取
- **WHEN** 代码需要获取配置
- **THEN** 使用Config::instance().get_xxx()方法
- **AND** 支持默认值
- **AND** 类型安全（int/string/bool）

#### Scenario: 配置修改
- **WHEN** 需要修改配置
- **THEN** 使用Config::instance().set()方法
- **AND** 运行时生效
- **AND** 支持监听配置变化

#### Scenario: 配置持久化
- **WHEN** 修改重要配置
- **THEN** 自动持久化到文件
- **AND** 应用重启后加载
- **AND** 支持配置文件导入导出

### Requirement: 命名规范统一

系统SHALL采用统一的命名规范，提升代码可读性。

#### Scenario: 函数命名
- **WHEN** 定义函数
- **THEN** 使用snake_case命名：`get_user_name()`
- **AND** 使用动词开头表达行为
- **AND** 参数命名清晰表达用途

#### Scenario: 类命名
- **WHEN** 定义类
- **THEN** 使用PascalCase命名：`HttpService`
- **AND** 名词表示实体
- **AND** 避免缩写（除非广为人知）

#### Scenario: 常量命名
- **WHEN** 定义常量
- **THEN** 使用UPPER_SNAKE_CASE：`MAX_RETRY_COUNT`
- **AND** 使用constexpr而非#define
- **AND** 添加类型前缀（如k开头）：`kDefaultTimeout`

#### Scenario: 文件命名
- **WHEN** 创建新文件
- **THEN** 使用snake_case：`http_service.cpp`
- **AND** 头文件和源文件同名
- **AND** 头文件使用.h后缀，源文件使用.cpp后缀

### Requirement: 注释和文档规范

系统SHALL为所有公共API提供完整的注释和文档。

#### Scenario: 类文档
- **WHEN** 定义公共类
- **THEN** 在类定义前添加Doxygen风格注释：
  ```cpp
  /**
   * @brief HTTP客户端服务
   * 
   * 提供HTTP GET/POST请求功能，支持异步操作和连接池。
   * 
   * @thread_safe 是
   */
  class HttpService { ... };
  ```

#### Scenario: 函数文档
- **WHEN** 定义公共函数
- **THEN** 注释包括：功能说明、参数说明、返回值说明、异常说明
  ```cpp
  /**
   * @brief 执行HTTP GET请求
   * 
   * @param url 请求URL
   * @param timeout 超时时间（秒）
   * @return Result<std::string> 成功返回响应内容，失败返回错误信息
   */
  Result<std::string> performGet(const std::string& url, int timeout);
  ```

#### Scenario: 复杂逻辑注释
- **WHEN** 编写复杂逻辑
- **THEN** 添加必要的行内注释解释原因
- **AND** 注释说明"为什么"而非"是什么"
- **AND** 使用TODO/FIXME标记待办事项

