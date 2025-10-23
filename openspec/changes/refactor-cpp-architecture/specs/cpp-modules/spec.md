# C++模块化设计规范

## ADDED Requirements

### Requirement: Core层模块定义

Core层SHALL提供应用的核心基础设施，不依赖业务逻辑。

#### Scenario: Result错误处理模板
- **WHEN** 函数可能失败需要返回错误
- **THEN** 使用core/result.h提供的Result<T, E>模板类
- **AND** 支持Ok和Err两种状态
- **AND** 提供is_ok()、is_err()、unwrap()等方法
- **AND** 禁止返回裸指针或错误码

#### Scenario: Logger日志系统
- **WHEN** 需要输出日志信息
- **THEN** 使用core/logger.h提供的Logger单例
- **AND** 通过LOG_D/LOG_I/LOG_W/LOG_E宏输出
- **AND** 支持运行时日志级别调整
- **AND** 自动添加时间戳和线程ID

#### Scenario: Config配置管理
- **WHEN** 需要读取或修改配置
- **THEN** 使用core/config.h提供的Config单例
- **AND** 支持get_string/get_int/get_bool方法
- **AND** 支持set方法动态修改
- **AND** 配置自动持久化

#### Scenario: ServiceContainer依赖注入
- **WHEN** 需要管理服务生命周期
- **THEN** 使用core/service_container.h
- **AND** 通过register_service注册服务
- **AND** 通过get_service获取服务实例
- **AND** 容器自动管理依赖关系

#### Scenario: MemoryPool内存池
- **WHEN** 需要频繁分配固定大小对象
- **THEN** 使用core/memory_pool.h提供的内存池
- **AND** 减少内存分配开销
- **AND** 支持线程安全选项
- **AND** 自动回收释放的对象

### Requirement: Services层模块定义

Services层SHALL提供业务服务，封装核心功能逻辑。

#### Scenario: HttpService HTTP客户端
- **WHEN** 需要发起HTTP请求
- **THEN** 使用services/http_service.h
- **AND** 提供get/post方法，返回Result<Response>
- **AND** 支持异步请求（基于线程池）
- **AND** 支持请求重试和超时控制
- **AND** 支持连接池和Keep-Alive

#### Scenario: CryptoService加密服务
- **WHEN** 需要进行加密解密操作
- **THEN** 使用services/crypto_service.h
- **AND** 提供AES加密/解密方法
- **AND** 提供哈希计算（MD5/SHA256）
- **AND** 支持加密缓存优化性能
- **AND** 密钥通过安全存储管理

#### Scenario: HookService Hook管理
- **WHEN** 需要执行Hook操作
- **THEN** 使用services/hook_service.h
- **AND** 提供hook/unhook方法
- **AND** 管理Hook状态（已安装/未安装）
- **AND** 支持异步Hook（避免阻塞）
- **AND** 集成性能监控

#### Scenario: LuaService Lua脚本管理
- **WHEN** 需要执行Lua脚本
- **THEN** 使用services/lua_service.h
- **AND** 提供load_script/execute_script方法
- **AND** 自动解密加密脚本
- **AND** 支持脚本缓存
- **AND** 集成错误处理

#### Scenario: StorageService存储服务
- **WHEN** 需要持久化数据
- **THEN** 使用services/storage_service.h
- **AND** 提供键值对存储接口
- **AND** 支持文件存储和内存缓存
- **AND** 可选加密存储
- **AND** 支持LRU缓存策略

#### Scenario: ThreadPool线程池
- **WHEN** 需要异步执行任务
- **THEN** 使用services/thread_pool.h
- **AND** 通过submit方法提交任务
- **AND** 返回std::future获取结果
- **AND** 支持wait_all等待所有任务
- **AND** 自动管理线程生命周期

### Requirement: Utils层模块定义

Utils层SHALL提供无状态的工具函数，不依赖其他层。

#### Scenario: StringUtils字符串工具
- **WHEN** 需要处理字符串
- **THEN** 使用utils/string_utils.h
- **AND** 提供基于string_view的函数（避免拷贝）
- **AND** 提供split/join/trim/format等方法
- **AND** 提供Unicode转换（UTF-8/UTF-16）
- **AND** 提供字符串池化功能

#### Scenario: TimeUtils时间工具
- **WHEN** 需要处理时间
- **THEN** 使用utils/time_utils.h
- **AND** 提供时间戳生成和解析
- **AND** 提供时间格式化（ISO8601等）
- **AND** 提供时间比较和计算
- **AND** 提供StopWatch性能计时器

#### Scenario: FileUtils文件工具
- **WHEN** 需要操作文件
- **THEN** 使用utils/file_utils.h
- **AND** 提供RAII文件句柄
- **AND** 提供read_file/write_file方法（返回Result）
- **AND** 提供路径拼接和规范化
- **AND** 提供目录操作（创建/删除/遍历）

#### Scenario: CryptoUtils加密工具基础
- **WHEN** 需要基础加密功能
- **THEN** 使用utils/crypto_utils.h
- **AND** 提供Base64编解码
- **AND** 提供哈希计算辅助函数
- **AND** 提供随机数生成
- **AND** 不依赖OpenSSL（使用系统API）

#### Scenario: NetworkUtils网络工具
- **WHEN** 需要网络相关工具
- **THEN** 使用utils/network_utils.h
- **AND** 提供URL解析和验证
- **AND** 提供域名提取
- **AND** 提供HTTP头部解析
- **AND** 提供JSON辅助函数

### Requirement: JNI层模块定义

JNI层SHALL提供Java与C++的桥接，隔离JNI细节。

#### Scenario: NativeBridge JNI入口
- **WHEN** Java层调用native方法
- **THEN** 通过jni/native_bridge.cpp实现
- **AND** 统一处理JNI签名和类型转换
- **AND** 统一错误处理（Result → Java Exception）
- **AND** 自动管理JavaVM引用

#### Scenario: JniUtils JNI辅助工具
- **WHEN** 需要JNI类型转换
- **THEN** 使用jni/jni_utils.h
- **AND** 提供jstring ↔ std::string转换
- **AND** 提供jobject引用管理
- **AND** 提供Java方法调用辅助
- **AND** 提供异常检查和抛出

#### Scenario: JavaRefs Java对象引用管理
- **WHEN** 需要持有Java对象引用
- **THEN** 使用jni/java_refs.h
- **AND** 提供GlobalRef和LocalRef RAII包装
- **AND** 自动管理引用计数
- **AND** 防止内存泄漏
- **AND** 线程安全

### Requirement: 模块间通信规范

模块间通信SHALL遵循明确的接口契约，避免实现依赖。

#### Scenario: 接口依赖
- **WHEN** 一个模块需要使用另一个模块
- **THEN** 只依赖头文件中的接口定义
- **AND** 不依赖实现细节
- **AND** 通过依赖注入获取实例
- **AND** 使用智能指针管理生命周期

#### Scenario: 回调机制
- **WHEN** 需要异步通知
- **THEN** 使用std::function作为回调类型
- **AND** 明确回调线程（调用者线程或工作线程）
- **AND** 回调函数不抛出异常
- **AND** 提供取消回调的机制

#### Scenario: 事件传递
- **WHEN** 需要跨模块传递事件
- **THEN** 使用Event对象封装
- **AND** 事件类型使用枚举定义
- **AND** 事件数据使用智能指针传递
- **AND** 避免循环依赖

### Requirement: 模块测试规范

每个模块SHALL提供单元测试，确保功能正确性。

#### Scenario: 单元测试要求
- **WHEN** 实现新模块
- **THEN** 必须提供对应的单元测试
- **AND** 测试覆盖率>80%
- **AND** 测试独立运行（不依赖其他模块）
- **AND** 使用Mock替代外部依赖

#### Scenario: 测试目录结构
- **WHEN** 编写测试代码
- **THEN** 测试文件放在tests/目录
- **AND** 测试文件命名为xxx_test.cpp
- **AND** 每个模块对应一个测试文件
- **AND** 使用Google Test框架

#### Scenario: 集成测试
- **WHEN** 多个模块协作
- **THEN** 提供集成测试验证交互
- **AND** 测试真实场景
- **AND** 验证错误处理
- **AND** 验证性能指标

