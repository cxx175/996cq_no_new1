## MODIFIED Requirements

### Requirement: 卡密心跳验证
卡密心跳验证SHALL使用正确的参数名称，确保与Lua参考实现完全一致。

#### Scenario: 心跳验证成功
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL包含所有必需参数（card, software, needle, center_id, tmstamp, sign, client_key）
- **AND** 时间戳参数名称SHALL为 `tmstamp` 而不是 `timestamp`
- **AND** 服务器SHALL返回成功响应

#### Scenario: 参数名称一致性
- **WHEN** 构建API请求参数
- **THEN** 时间戳参数名称SHALL为 `tmstamp`
- **AND** 与Lua实现保持完全一致
- **AND** 服务器端能够正确识别参数

#### Scenario: 签名生成一致性
- **WHEN** 生成API请求签名
- **THEN** 签名生成方法SHALL与Lua实现保持一致
- **AND** 使用算法 MD5(api_password + client_key + timestamp)
- **AND** 签名格式SHALL为32位MD5哈希值
