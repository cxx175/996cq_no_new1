## Context

通过深入分析Lua实现代码，发现了真正的根本问题：

### 关键发现
**参数名称不匹配**：
- **Lua使用**：`tmstamp` 参数（第16行：`"&tmstamp=" .. timestamp`）
- **C++使用**：`timestamp` 参数（`HTTP_PARAM_TIMESTAMP=timestamp`）

### 问题现象
- **Lua能正常工作**：因为使用了服务器端期望的 `tmstamp` 参数
- **C++出现异地登录错误**：因为使用了错误的 `timestamp` 参数名
- **服务器端验证失败**：服务器端期望 `tmstamp` 但收到了 `timestamp`

### Lua实现分析
```lua
-- Lua实现（正确的）
common_params = "center_id=" .. center_id .. "&tmstamp=" .. timestamp .. "&sign=" .. sign .. "&client_key=" .. client_key;
```

### C++实现分析
```cpp
// C++实现（当前错误的）
{HTTP_PARAM_TIMESTAMP, timestamp}  // HTTP_PARAM_TIMESTAMP=timestamp
```

## Goals / Non-Goals

### Goals
- 修正时间戳参数名称从 `timestamp` 到 `tmstamp`
- 确保与Lua实现完全一致
- 修复所有API调用中的参数名称

### Non-Goals
- 不改变时间戳获取逻辑
- 不修改服务器端API接口
- 不改变其他功能模块

## Decisions

### Decision: 使用正确的参数名称
所有API调用都需要使用 `tmstamp` 参数而不是 `timestamp` 参数。

### Decision: 更新常量定义
修改 `HTTP_PARAM_TIMESTAMP` 的定义为 `tmstamp`。

### Decision: 保持其他逻辑不变
只修改参数名称，不改变其他逻辑。

## Risks / Trade-offs

### 风险
- 修改可能影响现有功能
- 需要确保client_key的正确保存和复用

### 缓解措施
- 添加详细的日志记录，便于调试
- 确保client_key保存的可靠性
- 保持向后兼容性

## Migration Plan

1. 修改 `HTTP_PARAM_TIMESTAMP` 的定义为 `tmstamp`
2. 验证所有API调用都使用正确的参数名称
3. 测试验证修复效果

## Open Questions

- 是否需要验证服务器端对tmstamp参数的具体要求？
- 是否需要添加参数名称验证？
