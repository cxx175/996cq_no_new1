# C++性能优化规范

## ADDED Requirements

### Requirement: 字符串性能优化

系统SHALL优化字符串操作，减少不必要的拷贝和分配。

#### Scenario: string_view只读引用
- **WHEN** 函数只读取字符串不修改
- **THEN** 参数类型使用std::string_view
- **AND** 避免std::string拷贝
- **AND** 支持C字符串和std::string
- **AND** 不持有所有权

#### Scenario: 移动语义传递
- **WHEN** 函数需要获取字符串所有权
- **THEN** 参数类型使用std::string&&
- **AND** 使用std::move转移所有权
- **AND** 避免深拷贝
- **AND** 调用者使用std::move(str)传递

#### Scenario: 字符串拼接优化
- **WHEN** 拼接多个字符串
- **THEN** 预分配足够空间：
  ```cpp
  std::string result;
  result.reserve(str1.size() + str2.size() + str3.size());
  result += str1;
  result += str2;
  result += str3;
  ```
- **AND** 避免频繁重新分配
- **AND** 或使用ostringstream

#### Scenario: 字符串池化
- **WHEN** 大量重复字符串
- **THEN** 使用StringPool池化
- **AND** 只存储一份数据
- **AND** 返回string_view引用
- **AND** 减少内存占用

### Requirement: 加密解密性能优化

系统SHALL优化加密解密操作，提升吞吐量。

#### Scenario: 加密结果缓存
- **WHEN** 相同数据多次加密
- **THEN** 缓存加密结果
- **AND** 使用LRU淘汰策略
- **AND** 命中率监控
- **AND** 缓存大小可配置

#### Scenario: 批量加密
- **WHEN** 需要加密多个数据
- **THEN** 使用批量接口：
  ```cpp
  std::vector<std::string> encrypt_batch(
      const std::vector<std::string>& data
  );
  ```
- **AND** 减少OpenSSL初始化开销
- **AND** 提升吞吐量

#### Scenario: 硬件加速
- **WHEN** 设备支持AES-NI
- **THEN** 使用硬件加速指令
- **AND** 检测CPU特性（CPUID）
- **AND** 提供软件fallback
- **AND** 性能提升5-10倍

#### Scenario: 密钥复用
- **WHEN** 多次使用同一密钥
- **THEN** 复用EVP_CIPHER_CTX
- **AND** 避免重复初始化
- **AND** 线程本地存储
- **AND** 使用完释放

### Requirement: Hook性能优化

系统SHALL优化Hook操作，降低性能开销。

#### Scenario: Hook批量安装
- **WHEN** 安装多个Hook
- **THEN** 批量安装减少开销
- **AND** 一次性修改内存权限
- **AND** 减少系统调用
- **AND** 提供rollback机制

#### Scenario: 快速路径优化
- **WHEN** Hook函数被频繁调用
- **THEN** 优化Hook处理逻辑
- **AND** 减少栈帧大小
- **AND** 避免不必要的日志
- **AND** 内联热路径代码

#### Scenario: Hook状态缓存
- **WHEN** 检查Hook状态
- **THEN** 缓存状态避免重复查询
- **AND** 使用原子变量（atomic）
- **AND** 无锁读取
- **AND** 状态变化时更新

#### Scenario: 异步Hook操作
- **WHEN** Hook操作耗时较长
- **THEN** 使用线程池异步执行
- **AND** 不阻塞主线程
- **AND** 通过future获取结果
- **AND** 提供进度回调

### Requirement: 线程池与并发

系统SHALL使用线程池处理并发任务，提升响应速度。

#### Scenario: 线程池初始化
- **WHEN** 应用启动时
- **THEN** 创建固定大小线程池（如4线程）
- **AND** 根据CPU核心数调整
- **AND** 线程预创建，避免运行时开销
- **AND** 设置线程名称便于调试

#### Scenario: 任务提交
- **WHEN** 提交异步任务
- **THEN** 使用submit方法：
  ```cpp
  auto future = thread_pool->submit([](){ return task(); });
  auto result = future.get();
  ```
- **AND** 返回std::future
- **AND** 支持带参数的任务
- **AND** 支持任务优先级

#### Scenario: 任务队列管理
- **WHEN** 任务队列积压
- **THEN** 监控队列长度
- **AND** 超过阈值拒绝新任务
- **AND** 提供back-pressure机制
- **AND** 记录拒绝次数

#### Scenario: 线程池关闭
- **WHEN** 应用退出时
- **THEN** 等待所有任务完成（或超时）
- **AND** 清理工作线程
- **AND** 释放资源
- **AND** 确保无泄漏

### Requirement: 网络请求性能优化

系统SHALL优化HTTP请求性能，降低延迟。

#### Scenario: 连接池复用
- **WHEN** 发起HTTP请求
- **THEN** 复用TCP连接
- **AND** 启用Keep-Alive
- **AND** 连接池大小可配置
- **AND** 空闲连接超时清理

#### Scenario: 并发请求
- **WHEN** 需要请求多个URL
- **THEN** 使用线程池并发请求
- **AND** 限制最大并发数
- **AND** 避免DDo自己
- **AND** 汇总结果返回

#### Scenario: 请求超时控制
- **WHEN** 设置请求超时
- **THEN** 连接超时和读取超时分别设置
- **AND** 连接超时5秒
- **AND** 读取超时30秒
- **AND** 超时自动取消请求

#### Scenario: DNS缓存
- **WHEN** 解析域名
- **THEN** 缓存DNS结果
- **AND** TTL遵循DNS记录
- **AND** 减少DNS查询延迟
- **AND** 提供手动刷新接口

### Requirement: 内存分配优化

系统SHALL优化内存分配，减少碎片和开销。

#### Scenario: 小对象池化
- **WHEN** 频繁分配小对象（<256字节）
- **THEN** 使用对象池
- **AND** 按大小分级（16/32/64/128/256）
- **AND** 线程本地池避免竞争
- **AND** 性能提升30%+

#### Scenario: 大对象直接分配
- **WHEN** 分配大对象（>4KB）
- **THEN** 直接使用malloc/new
- **AND** 不使用对象池
- **AND** 避免内存浪费
- **AND** 考虑使用mmap

#### Scenario: 内存对齐分配
- **WHEN** 需要对齐内存
- **THEN** 使用aligned_alloc或posix_memalign
- **AND** 指定对齐大小（16/32/64字节）
- **AND** SIMD操作需要对齐
- **AND** 检查对齐后使用

### Requirement: 性能监控与分析

系统SHALL提供性能监控工具，识别性能瓶颈。

#### Scenario: 函数耗时统计
- **WHEN** 需要测量函数耗时
- **THEN** 使用PERF_LOG宏：
  ```cpp
  PERF_LOG("my_function") {
      // 函数实现
  }
  ```
- **AND** 自动记录开始和结束时间
- **AND** 超过阈值输出警告
- **AND** 统计平均耗时和峰值

#### Scenario: 内存使用监控
- **WHEN** 监控内存使用
- **THEN** 定期采样内存统计
- **AND** 记录当前使用量和峰值
- **AND** 检测内存泄漏
- **AND** 生成内存报告

#### Scenario: CPU使用监控
- **WHEN** 监控CPU使用
- **THEN** 采样线程CPU时间
- **AND** 识别CPU密集型函数
- **AND** 检测死循环和hang
- **AND** 记录CPU占用率

#### Scenario: 性能报告生成
- **WHEN** 需要性能分析
- **THEN** 生成性能报告
- **AND** 包含耗时Top10函数
- **AND** 包含内存使用趋势
- **AND** 包含并发统计
- **AND** 支持JSON和文本格式

### Requirement: 编译优化选项

系统SHALL使用合适的编译优化选项，提升运行时性能。

#### Scenario: Release优化级别
- **WHEN** Release构建
- **THEN** 使用-O3优化级别
- **AND** 启用LTO链接时优化
- **AND** 启用函数内联
- **AND** 禁用调试符号（strip）

#### Scenario: SIMD指令集
- **WHEN** 目标平台支持SIMD
- **THEN** 启用NEON（ARM）或SSE（x86）
- **AND** 使用编译器内置函数
- **AND** 提供标量fallback
- **AND** 运行时检测CPU特性

#### Scenario: PGO性能引导优化
- **WHEN** 性能极度重要
- **THEN** 考虑使用PGO优化
- **AND** 收集运行时profile数据
- **AND** 重新编译使用profile
- **AND** 性能提升10-20%

#### Scenario: 死代码消除
- **WHEN** Release构建
- **THEN** 启用-ffunction-sections和-fdata-sections
- **AND** 链接时使用--gc-sections
- **AND** 移除未使用的函数和数据
- **AND** 减小二进制体积

