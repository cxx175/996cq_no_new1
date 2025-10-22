## ADDED Requirements

### Requirement: 卡密心跳验证
卡密心跳验证SHALL包含完整的签名验证机制，确保与服务器端API规范一致。

#### Scenario: 心跳验证成功
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL包含所有必需参数（card, software, needle, center_id, timestamp, sign）
- **AND** 签名SHALL使用与登录相同的生成方法
- **AND** 服务器SHALL返回成功响应

#### Scenario: 签名验证失败处理
- **WHEN** 心跳验证签名不正确
- **THEN** 系统SHALL记录详细的错误信息
- **AND** 系统SHALL提供明确的错误提示
- **AND** 系统SHALL支持重试机制

#### Scenario: 签名生成一致性
- **WHEN** 生成心跳验证签名
- **THEN** 签名生成方法SHALL与登录接口保持一致
- **AND** 使用相同的API密码和时间戳
- **AND** 签名格式SHALL为32位MD5哈希值
