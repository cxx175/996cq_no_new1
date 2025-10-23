# C++安全编码规范

## ADDED Requirements

### Requirement: 内存安全

系统SHALL防止内存相关的安全漏洞（缓冲区溢出、UAF、内存泄漏等）。

#### Scenario: 缓冲区边界检查
- **WHEN** 访问数组或缓冲区
- **THEN** 必须检查边界
- **AND** 使用std::vector代替C数组
- **AND** 使用at()而非[]（有边界检查）
- **AND** 禁止使用strcpy/sprintf等不安全函数

#### Scenario: Use-After-Free防护
- **WHEN** 释放对象后
- **THEN** 立即置空指针
- **AND** 使用智能指针自动管理
- **AND** 避免悬挂引用
- **AND** Code Review重点检查

#### Scenario: 双重释放防护
- **WHEN** 释放内存
- **THEN** 使用RAII和智能指针
- **AND** 避免手动delete
- **AND** 检查指针是否为空
- **AND** 释放后置空

#### Scenario: 整数溢出检查
- **WHEN** 进行数值计算
- **THEN** 检查溢出风险
- **AND** 使用SafeInt库或自实现
- **AND** 敏感计算使用更大类型
- **AND** 断言检查合法范围

### Requirement: 字符串混淆优化

系统SHALL加强字符串混淆机制，防止静态分析。

#### Scenario: 敏感字符串加密
- **WHEN** 代码包含敏感字符串（URL、密钥等）
- **THEN** 使用XOR或AES加密
- **AND** 密钥在运行时生成
- **AND** 字符串存储在加密后的形式
- **AND** 使用时解密到栈变量

#### Scenario: 字符串分割存储
- **WHEN** 字符串较长
- **THEN** 分割为多段存储
- **AND** 运行时拼接
- **AND** 增加静态分析难度
- **AND** 结合混淆工具

#### Scenario: 字符串动态构造
- **WHEN** 构造字符串
- **THEN** 从字符数组动态组装
- **AND** 使用算法变换
- **AND** 避免明文存储
- **AND** 使用完立即清零

#### Scenario: 字符串使用后清理
- **WHEN** 使用完敏感字符串
- **THEN** 调用explicit_bzero清零
- **AND** 或使用secure_string类型
- **AND** 防止内存dump泄露
- **AND** 即使编译器优化也清零

### Requirement: 密钥管理安全

系统SHALL安全管理加密密钥，防止泄露。

#### Scenario: 密钥生成
- **WHEN** 生成加密密钥
- **THEN** 使用密码学安全随机数生成器
- **AND** 基于设备特征派生
- **AND** 每个设备密钥唯一
- **AND** 不硬编码密钥

#### Scenario: 密钥存储
- **WHEN** 存储密钥
- **THEN** 使用Android KeyStore
- **AND** 或使用加密后存储
- **AND** 权限限制仅应用可读
- **AND** 定期轮换密钥

#### Scenario: 密钥使用
- **WHEN** 使用密钥加密解密
- **THEN** 密钥只在内存停留最短时间
- **AND** 使用后立即清零
- **AND** 锁定内存页防止swap
- **AND** 不写入日志

#### Scenario: 密钥销毁
- **WHEN** 不再需要密钥
- **THEN** 多次覆写密钥内存
- **AND** 使用secure_bzero
- **AND** 从KeyStore删除
- **AND** 验证销毁完成

### Requirement: 反调试机制

系统SHALL实现反调试保护，防止动态分析。

#### Scenario: ptrace检测
- **WHEN** 应用启动时
- **THEN** 检查是否被调试器附加
- **AND** 读取/proc/self/status中的TracerPid
- **AND** 非零表示被调试
- **AND** 检测到则退出或混淆行为

#### Scenario: 调试器检测
- **WHEN** 运行时定期检查
- **THEN** 检测调试器特征
- **AND** 检查/proc/self/maps中的调试库
- **AND** 检查调试器端口占用
- **AND** 时间差检测（单步执行慢）

#### Scenario: 完整性检查
- **WHEN** 运行时
- **THEN** 检查代码段完整性
- **AND** 计算.so文件哈希
- **AND** 对比预期哈希值
- **AND** 不匹配则退出或报告

#### Scenario: 模拟器检测
- **WHEN** 应用启动时
- **THEN** 检测是否在模拟器
- **AND** 检查系统属性（ro.product.model等）
- **AND** 检查传感器数据
- **AND** 检查特征文件（/dev/socket/qemud等）

### Requirement: 代码混淆增强

系统SHALL配合混淆工具加强代码保护。

#### Scenario: 函数名混淆
- **WHEN** Release构建
- **THEN** 启用符号混淆
- **AND** 使用BlackObfuscator混淆Java层
- **AND** 使用Obfuscator-LLVM混淆C++层
- **AND** 混淆深度≥4

#### Scenario: 控制流平坦化
- **WHEN** Release构建C++代码
- **THEN** 启用控制流平坦化
- **AND** 将if-else转换为switch-case
- **AND** 增加分析难度
- **AND** 性能开销可接受（<20%）

#### Scenario: 指令替换
- **WHEN** Release构建
- **THEN** 启用指令替换混淆
- **AND** 简单指令替换为复杂等价指令
- **AND** 增加逆向难度
- **AND** 不影响功能正确性

#### Scenario: 虚假控制流
- **WHEN** 关键函数混淆
- **THEN** 插入永不执行的代码路径
- **AND** 干扰反编译工具
- **AND** 不影响实际执行
- **AND** 静态分析识别困难

### Requirement: 输入验证

系统SHALL严格验证所有外部输入，防止注入攻击。

#### Scenario: JNI输入验证
- **WHEN** JNI函数接收Java参数
- **THEN** 验证参数类型和值
- **AND** 检查字符串是否为null
- **AND** 检查数值范围
- **AND** 拒绝非法输入

#### Scenario: HTTP响应验证
- **WHEN** 接收HTTP响应
- **THEN** 验证响应格式
- **AND** 检查JSON结构
- **AND** 验证字段类型
- **AND** 防止注入攻击

#### Scenario: 文件路径验证
- **WHEN** 处理文件路径
- **THEN** 规范化路径
- **AND** 检查路径遍历（../）
- **AND** 验证在允许目录内
- **AND** 拒绝符号链接

#### Scenario: 大小限制检查
- **WHEN** 分配内存或缓冲区
- **THEN** 检查大小合法性
- **AND** 设置最大限制
- **AND** 防止资源耗尽攻击
- **AND** 记录异常大小请求

### Requirement: 安全日志记录

系统SHALL安全记录日志，避免敏感信息泄露。

#### Scenario: 敏感信息过滤
- **WHEN** 记录日志
- **THEN** 过滤敏感信息
- **AND** 不记录密码、密钥
- **AND** 脱敏身份信息
- **AND** 使用***替换

#### Scenario: 日志级别控制
- **WHEN** Release模式
- **THEN** 默认日志级别为INFO或更高
- **AND** 不输出DEBUG日志
- **AND** 可通过配置动态调整
- **AND** 敏感操作不记录详细日志

#### Scenario: 日志加密存储
- **WHEN** 日志持久化
- **THEN** 加密后存储
- **AND** 使用设备密钥加密
- **AND** 权限限制仅应用可读
- **AND** 定期清理旧日志

### Requirement: 时间安全

系统SHALL防止时间相关的安全问题。

#### Scenario: 时间比较安全
- **WHEN** 比较时间戳验证有效期
- **THEN** 使用constant-time比较
- **AND** 防止时序攻击
- **AND** 不泄露时间信息

#### Scenario: 时钟篡改检测
- **WHEN** 验证时间相关逻辑
- **THEN** 检测系统时钟篡改
- **AND** 对比网络时间
- **AND** 检测时间跳跃
- **AND** 异常时拒绝操作

#### Scenario: 重放攻击防护
- **WHEN** 处理时间敏感请求
- **THEN** 使用nonce和timestamp
- **AND** 验证时间窗口（如5分钟）
- **AND** 记录已使用的nonce
- **AND** 拒绝重放请求

### Requirement: 并发安全

系统SHALL防止并发相关的安全问题。

#### Scenario: 竞态条件防护
- **WHEN** 多线程访问共享状态
- **THEN** 使用互斥锁保护
- **AND** 最小化临界区
- **AND** 避免嵌套锁
- **AND** Code Review检查竞态

#### Scenario: 原子操作
- **WHEN** 简单状态更新
- **THEN** 使用std::atomic
- **AND** 无锁编程
- **AND** 指定内存序
- **AND** 性能更好

#### Scenario: 死锁防护
- **WHEN** 使用多个锁
- **THEN** 按固定顺序获取锁
- **AND** 使用lock_guard自动释放
- **AND** 设置锁超时
- **AND** 检测死锁并恢复

#### Scenario: 线程安全文档
- **WHEN** 实现并发代码
- **THEN** 在注释标注线程安全性
- **AND** @thread_safe或@not_thread_safe
- **AND** 说明同步机制
- **AND** 说明调用约束

### Requirement: 第三方库安全

系统SHALL安全使用第三方库，定期更新和审计。

#### Scenario: 库版本管理
- **WHEN** 使用第三方库
- **THEN** 记录版本号
- **AND** 定期检查安全更新
- **AND** 及时升级修复漏洞
- **AND** 评估升级风险

#### Scenario: 最小权限原则
- **WHEN** 配置库权限
- **THEN** 只授予必需权限
- **AND** 限制网络访问
- **AND** 限制文件访问
- **AND** 沙箱隔离

#### Scenario: 安全审计
- **WHEN** 引入新库
- **THEN** 安全审计库代码
- **AND** 检查已知漏洞（CVE）
- **AND** 评估维护活跃度
- **AND** 考虑替代方案

