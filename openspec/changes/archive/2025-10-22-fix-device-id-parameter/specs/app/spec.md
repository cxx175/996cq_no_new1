## MODIFIED Requirements

### Requirement: 卡密心跳验证
卡密心跳验证SHALL使用正确的参数名称和加密处理机制，确保与Lua参考实现完全一致。

#### Scenario: 心跳验证成功
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL包含所有必需参数（card, software, needle, center_id, timestamp, sign, client_key）
- **AND** client_keySHALL为设备ID的MD5加密结果
- **AND** 签名SHALL使用包含client_key的算法生成
- **AND** 服务器SHALL返回成功响应

#### Scenario: 设备ID加密处理
- **WHEN** 获取心跳验证设备ID
- **THEN** 设备IDSHALL进行MD5加密处理
- **AND** 加密算法SHALL为 MD5(api_password + deviceId + timestamp)
- **AND** 加密结果SHALL作为client_key参数发送

#### Scenario: 签名生成一致性
- **WHEN** 生成心跳验证签名
- **THEN** 签名生成方法SHALL与Lua实现保持一致
- **AND** 使用算法 MD5(api_password + client_key + timestamp)
- **AND** 签名格式SHALL为32位MD5哈希值
