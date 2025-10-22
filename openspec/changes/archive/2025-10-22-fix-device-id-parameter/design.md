## Context

通过对比Lua参考代码和C++实现，发现了关键的实现差异：

### Lua实现（正确的实现）
```lua
client_key = getDeviceId(); -- 获取设备ID
client_key = MD5( api_password .. client_key .. timestamp ); -- 加密处理
api_password = api_password .. client_key;
sign = MD5(api_password .. timestamp);
common_params = "center_id=" .. center_id .. "&tmstamp=" .. timestamp .. "&sign=" .. sign .. "&client_key=" .. client_key;
```

### C++实现（当前错误的实现）
```cpp
std::string deviceId = getDeviceId(); // 直接使用原始设备ID
std::string sign = generateRequestSignature(CARD_API_PASSWORD, timestamp); // 没有使用加密后的设备ID
params = {HTTP_PARAM_DEVICE_ID, deviceId}; // 使用错误的参数名
```

## Goals / Non-Goals

### Goals
- 修正设备ID参数名称从 `deviceId` 到 `client_key`
- 添加设备ID的MD5加密处理
- 修正签名生成算法以包含加密后的client_key
- 确保与Lua实现完全一致

### Non-Goals
- 不改变现有的设备ID获取方法
- 不修改服务器端API接口
- 不改变其他功能模块

## Decisions

### Decision: 使用正确的参数名称
心跳验证请求需要使用 `client_key` 参数而不是 `deviceId` 参数。

### Decision: 添加设备ID加密处理
设备ID需要进行MD5加密：`MD5(api_password + deviceId + timestamp)`

### Decision: 修正签名生成算法
签名生成需要包含加密后的client_key：`MD5(api_password + client_key + timestamp)`

## Risks / Trade-offs

### 风险
- 修改可能影响现有功能
- 需要确保与Lua实现完全一致

### 缓解措施
- 严格按照Lua参考代码实现
- 添加详细的日志记录，便于调试
- 保持向后兼容性

## Migration Plan

1. 修改 `cardHeartbeat` 函数，添加设备ID加密处理
2. 修正参数名称从 `deviceId` 到 `client_key`
3. 修正签名生成算法
4. 测试验证修复效果

## Open Questions

- 是否需要验证服务器端对client_key的具体要求？
- 是否需要添加client_key验证失败的降级处理？
