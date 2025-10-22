## MODIFIED Requirements

### Requirement: 卡密心跳验证
卡密心跳验证SHALL包含完整的设备ID验证机制，确保与服务器端API规范一致，防止异地登录。

#### Scenario: 心跳验证成功
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL包含所有必需参数（card, software, needle, center_id, timestamp, sign, device_id）
- **AND** 设备IDSHALL使用与登录相同的获取方法
- **AND** 服务器SHALL返回成功响应

#### Scenario: 异地登录检测处理
- **WHEN** 心跳验证设备ID与登录时不一致
- **THEN** 系统SHALL记录详细的错误信息
- **AND** 系统SHALL提供明确的异地登录提示
- **AND** 系统SHALL支持设备ID重新验证机制

#### Scenario: 设备ID获取一致性
- **WHEN** 获取心跳验证设备ID
- **THEN** 设备ID获取方法SHALL与登录接口保持一致
- **AND** 使用相同的设备ID生成和存储机制
- **AND** 设备ID格式SHALL为有效的UUID或IMEI格式
