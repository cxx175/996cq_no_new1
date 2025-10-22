## Context

卡密验证系统包含三个主要接口：
1. **card_login** - 卡密登录，包含完整的签名验证
2. **card_ping** - 心跳验证，当前缺少签名参数
3. **card_logout** - 退出登录，包含完整的签名验证

问题在于心跳验证接口没有使用签名验证，而服务器端期望所有API请求都包含签名。

## Goals / Non-Goals

### Goals
- 修复心跳验证的签名缺失问题
- 确保所有API请求使用统一的签名生成逻辑
- 保持与现有登录和退出接口的一致性

### Non-Goals
- 不改变现有的签名生成算法
- 不修改服务器端API接口
- 不改变其他功能模块

## Decisions

### Decision: 在心跳验证中添加签名参数
心跳验证请求需要包含以下参数：
- card: 卡密
- software: 软件名称
- needle: 登录标识
- center_id: 开发者ID
- timestamp: 时间戳
- **sign: 请求签名** (新增)

### Decision: 使用与登录相同的签名生成方法
使用 `generateRequestSignature(CARD_API_PASSWORD, timestamp)` 生成签名，确保与登录接口的一致性。

## Risks / Trade-offs

### 风险
- 修改可能影响现有功能
- 签名生成逻辑需要与服务器端保持一致

### 缓解措施
- 使用现有的签名生成函数，确保一致性
- 添加详细的日志记录，便于调试
- 保持向后兼容性

## Migration Plan

1. 修改 `cardHeartbeat` 函数，添加签名生成
2. 在请求参数中包含签名字段
3. 测试验证修复效果
4. 部署到生产环境

## Open Questions

- 是否需要验证服务器端对心跳签名的具体要求？
- 是否需要添加签名验证失败的降级处理？
