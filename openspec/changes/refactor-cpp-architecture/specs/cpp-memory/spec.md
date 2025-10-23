# C++内存管理规范

## ADDED Requirements

### Requirement: 智能指针使用规范

系统SHALL使用智能指针替代裸指针，自动管理内存生命周期。

#### Scenario: unique_ptr独占所有权
- **WHEN** 对象只有一个所有者
- **THEN** 使用std::unique_ptr
- **AND** 使用std::make_unique创建
- **AND** 通过std::move转移所有权
- **AND** 禁止拷贝

#### Scenario: shared_ptr共享所有权
- **WHEN** 对象有多个所有者
- **THEN** 使用std::shared_ptr
- **AND** 使用std::make_shared创建
- **AND** 引用计数自动管理
- **AND** 最后一个引用释放时销毁对象

#### Scenario: weak_ptr观察者模式
- **WHEN** 需要观察对象但不拥有
- **THEN** 使用std::weak_ptr
- **AND** 通过lock()获取shared_ptr
- **AND** 检查对象是否still alive
- **AND** 避免循环引用

#### Scenario: 裸指针使用限制
- **WHEN** 编写新代码
- **THEN** 禁止使用new/delete
- **AND** 仅在与C API交互时使用裸指针
- **AND** 使用unique_ptr配合release()和reset()
- **AND** Code Review必须审查裸指针使用

### Requirement: RAII资源管理

系统SHALL使用RAII模式管理所有资源，确保异常安全。

#### Scenario: 文件句柄管理
- **WHEN** 打开文件
- **THEN** 使用RAII包装类（FileHandle）
- **AND** 构造函数打开文件
- **AND** 析构函数自动关闭文件
- **AND** 即使异常也能正确释放

#### Scenario: 互斥锁管理
- **WHEN** 使用互斥锁
- **THEN** 使用std::lock_guard或std::unique_lock
- **AND** 自动加锁和解锁
- **AND** 避免忘记解锁
- **AND** 异常安全

#### Scenario: 内存缓冲区管理
- **WHEN** 需要动态缓冲区
- **THEN** 使用std::vector或std::unique_ptr<T[]>
- **AND** 自动管理内存
- **AND** 提供size()和capacity()
- **AND** 支持动态扩容

#### Scenario: JNI引用管理
- **WHEN** 持有JNI引用
- **THEN** 使用GlobalRef或LocalRef包装类
- **AND** 构造时创建引用
- **AND** 析构时删除引用
- **AND** 防止JNI内存泄漏

### Requirement: 内存池化优化

系统SHALL对频繁分配的对象使用内存池，提升性能。

#### Scenario: 对象池实现
- **WHEN** 对象频繁创建和销毁（>100次/秒）
- **THEN** 使用MemoryPool<T>对象池
- **AND** 预分配固定数量对象
- **AND** 获取对象时从池中取出
- **AND** 释放对象时归还到池

#### Scenario: 池化对象标识
- **WHEN** 标识哪些对象需要池化
- **THEN** 通过性能分析工具识别热点
- **AND** 优先池化小对象（<1KB）
- **AND** 优先池化频繁分配对象
- **AND** 测试池化前后性能提升

#### Scenario: 线程安全池
- **WHEN** 多线程共享对象池
- **THEN** 使用线程安全的MemoryPool实现
- **AND** 使用无锁队列或细粒度锁
- **AND** 避免锁竞争
- **AND** 提供per-thread池选项

### Requirement: 内存泄漏检测

系统SHALL集成内存泄漏检测工具，确保无泄漏。

#### Scenario: Debug模式检测
- **WHEN** Debug构建运行
- **THEN** 启用AddressSanitizer（ASan）
- **AND** 自动检测内存泄漏
- **AND** 报告泄漏堆栈信息
- **AND** 构建失败如果发现泄漏

#### Scenario: 定期泄漏审计
- **WHEN** 每次Release前
- **THEN** 运行完整的泄漏检测
- **AND** 使用Valgrind或类似工具
- **AND** 检查所有测试用例
- **AND** 修复所有发现的泄漏

#### Scenario: JNI泄漏检测
- **WHEN** 使用JNI
- **THEN** 检查GlobalRef是否释放
- **AND** 检查LocalRef是否超限
- **AND** 使用CheckJNI模式
- **AND** 记录所有引用创建和删除

### Requirement: 内存清理机制

系统SHALL实现敏感数据的内存清理，防止信息泄露。

#### Scenario: 敏感数据标识
- **WHEN** 处理敏感数据（密钥、密码等）
- **THEN** 使用SecureBuffer包装类
- **AND** 构造时锁定内存（mlock）
- **AND** 析构时清零内存（explicit_bzero）
- **AND** 防止swap到磁盘

#### Scenario: 字符串清理
- **WHEN** 字符串包含敏感信息
- **THEN** 使用secure_string类型
- **AND** 重载析构函数清零内存
- **AND** 禁止拷贝（或拷贝后清零原数据）
- **AND** 使用加密存储

#### Scenario: 加密密钥管理
- **WHEN** 使用加密密钥
- **THEN** 密钥存储在SecureBuffer
- **AND** 使用完立即清零
- **AND** 不写入日志
- **AND** 不序列化到磁盘（或加密后存储）

### Requirement: 内存对齐优化

系统SHALL正确处理内存对齐，提升性能和兼容性。

#### Scenario: 结构体对齐
- **WHEN** 定义数据结构
- **THEN** 使用alignas指定对齐
- **AND** 避免padding浪费
- **AND** 考虑缓存行对齐（64字节）
- **AND** 热数据结构优先对齐

#### Scenario: SIMD对齐
- **WHEN** 使用SIMD指令
- **THEN** 数据必须16字节或32字节对齐
- **AND** 使用aligned_alloc分配
- **AND** 检查对齐后再使用SIMD
- **AND** 提供未对齐的fallback

#### Scenario: 跨平台对齐
- **WHEN** 代码跨平台运行
- **THEN** 考虑不同平台对齐差异
- **AND** ARM和x86对齐要求不同
- **AND** 使用static_assert检查假设
- **AND** 避免依赖特定平台行为

### Requirement: 内存使用监控

系统SHALL监控内存使用情况，及时发现异常。

#### Scenario: 内存统计
- **WHEN** 应用运行时
- **THEN** 定期收集内存统计信息
- **AND** 记录当前使用量
- **AND** 记录峰值使用量
- **AND** 记录分配次数

#### Scenario: 内存告警
- **WHEN** 内存使用超过阈值
- **THEN** 输出警告日志
- **AND** 记录内存分配热点
- **AND** 触发GC或缓存清理
- **AND** 通知上层处理

#### Scenario: 内存Profiling
- **WHEN** 需要分析内存问题
- **THEN** 使用内存profiler工具
- **AND** 生成内存分配报告
- **AND** 识别内存热点
- **AND** 优化内存使用

### Requirement: 容器使用规范

系统SHALL正确使用STL容器，避免性能陷阱。

#### Scenario: 容器选择
- **WHEN** 选择容器类型
- **THEN** 根据使用场景选择：
  - 顺序访问：std::vector
  - 频繁插入删除：std::list或std::deque
  - 键值查找：std::unordered_map
  - 有序查找：std::map
  - 去重集合：std::unordered_set

#### Scenario: 预分配空间
- **WHEN** 已知容器大小
- **THEN** 使用reserve()预分配空间
- **AND** 避免频繁重新分配
- **AND** 减少内存拷贝
- **AND** 提升性能

#### Scenario: 移动语义
- **WHEN** 向容器添加元素
- **THEN** 优先使用emplace_back而非push_back
- **AND** 使用std::move避免拷贝
- **AND** 右值引用传递大对象
- **AND** 返回值优化（RVO）

#### Scenario: 迭代器失效
- **WHEN** 修改容器时
- **THEN** 注意迭代器失效问题
- **AND** vector插入删除导致失效
- **AND** map/set删除不影响其他迭代器
- **AND** 使用返回的新迭代器

