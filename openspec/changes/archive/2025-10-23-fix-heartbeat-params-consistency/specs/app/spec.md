## MODIFIED Requirements

### Requirement: 卡密心跳验证参数一致性
卡密心跳验证SHALL与Lua参考实现保持完全一致的参数构建逻辑，确保服务器能够正确识别和处理请求。

#### Scenario: 心跳验证参数与Lua实现一致
- **WHEN** 构建心跳验证请求参数
- **THEN** 参数构建逻辑SHALL与Lua参考实现完全一致
- **AND** 参数顺序SHALL按照Lua实现的顺序
- **AND** 参数名称SHALL与Lua实现保持一致

#### Scenario: 心跳验证参数完整性
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL包含Lua实现中的所有必需参数
- **AND** 不包含Lua实现中未使用的参数（如deviceId）
- **AND** 服务器SHALL返回成功响应

#### Scenario: 参数构建逻辑统一
- **WHEN** 构建任何API请求参数
- **THEN** 参数构建方法SHALL与Lua实现保持一致
- **AND** 使用相同的参数名称和格式
- **AND** 确保参数顺序的正确性

#### Scenario: 服务器兼容性
- **WHEN** 心跳验证参数与Lua实现一致
- **THEN** 服务器SHALL能够正确识别和处理请求
- **AND** 避免因参数不一致导致的验证失败
- **AND** 异地登录检测SHALL基于正确的参数进行判断
