## MODIFIED Requirements

### Requirement: 卡密心跳验证
卡密心跳验证SHALL包含完整的设备ID参数，确保与服务器端API规范一致，防止异地登录检测失败。

#### Scenario: 心跳验证参数完整性
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL包含所有必需参数（card, software, needle, center_id, tmstamp, sign, client_key, device_id）
- **AND** device_id参数SHALL使用与登录相同的设备ID值
- **AND** 服务器SHALL返回成功响应

#### Scenario: 设备ID参数传递
- **WHEN** 构建心跳验证请求参数
- **THEN** 参数映射SHALL包含device_id字段
- **AND** device_id值SHALL为有效的设备标识符
- **AND** 设备ID获取方法SHALL与登录接口保持一致

#### Scenario: 异地登录检测准确性
- **WHEN** 心跳验证包含正确的device_id参数
- **THEN** 服务器SHALL能够准确识别设备身份
- **AND** 系统SHALL避免因参数缺失导致的误报
- **AND** 异地登录检测SHALL基于完整的设备信息进行判断
