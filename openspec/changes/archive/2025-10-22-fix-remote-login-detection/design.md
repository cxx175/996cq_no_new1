## Context

卡密验证系统包含三个主要接口，都需要设备ID来防止异地登录：
1. **card_login** - 卡密登录，包含设备ID参数
2. **card_ping** - 心跳验证，当前缺少设备ID参数
3. **card_logout** - 退出登录，包含设备ID参数

问题在于心跳验证接口没有使用设备ID参数，而服务器端期望所有API请求都包含设备ID来验证设备一致性。

## Goals / Non-Goals

### Goals
- 修复心跳验证的设备ID缺失问题
- 确保所有API请求使用统一的设备ID管理
- 保持与现有登录和退出接口的一致性

### Non-Goals
- 不改变现有的设备ID生成算法
- 不修改服务器端API接口
- 不改变其他功能模块

## Decisions

### Decision: 在心跳验证中添加设备ID参数
心跳验证请求需要包含以下参数：
- card: 卡密
- software: 软件名称
- needle: 登录标识
- center_id: 开发者ID
- timestamp: 时间戳
- sign: 请求签名
- **device_id: 设备ID** (新增)

### Decision: 使用与登录相同的设备ID获取方法
使用 `getDeviceId()` 函数获取设备ID，确保与登录接口的一致性。

## Risks / Trade-offs

### 风险
- 修改可能影响现有功能
- 设备ID管理需要与服务器端保持一致

### 缓解措施
- 使用现有的设备ID获取函数，确保一致性
- 添加详细的日志记录，便于调试
- 保持向后兼容性

## Migration Plan

1. 修改 `cardHeartbeat` 函数，添加设备ID获取
2. 在请求参数中包含设备ID字段
3. 测试验证修复效果
4. 部署到生产环境

## Open Questions

- 是否需要验证服务器端对心跳设备ID的具体要求？
- 是否需要添加设备ID验证失败的降级处理？
