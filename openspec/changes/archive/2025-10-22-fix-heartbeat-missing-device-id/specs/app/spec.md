## MODIFIED Requirements
### Requirement: 卡密心跳验证
卡密心跳验证SHALL严格按照官方API文档实现，只包含文档中定义的必需参数，避免因参数不匹配导致服务器拒绝请求。

#### Scenario: 心跳验证参数一致性
- **WHEN** 用户已成功登录并启动心跳验证
- **THEN** 心跳请求SHALL只包含文档中定义的三个必需参数（card, software, needle）
- **AND** 请求SHALL不包含任何未在文档中定义的额外参数
- **AND** 服务器SHALL返回成功响应

#### Scenario: API文档遵循
- **WHEN** 实现心跳验证请求
- **THEN** 参数列表SHALL与官方API文档完全一致
- **AND** 参数名称和值SHALL符合文档规范
- **AND** 实现SHALL严格遵循文档定义

#### Scenario: 请求参数简化
- **WHEN** 构建心跳验证请求参数
- **THEN** 系统SHALL移除所有非文档定义的参数
- **AND** 只保留card、software和needle三个必需参数
- **AND** 确保请求格式符合服务器期望
