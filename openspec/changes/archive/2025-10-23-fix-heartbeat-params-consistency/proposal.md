## Why

根据日志分析和Lua参考实现对比，发现登录验证参数基本一致，但心跳验证参数与Lua实现不一致，导致服务器返回"卡密异地登录"错误。Lua实现中心跳验证只使用通用参数(center_id, tmstamp, sign, client_key)加上特定参数(software, card, needle)，而C++实现错误地添加了deviceId参数。

## What Changes

- **修复心跳验证参数构建逻辑**：使C++实现与Lua参考实现完全一致
- **移除心跳验证中的deviceId参数**：Lua实现中心跳验证不包含deviceId参数
- **确保心跳验证参数与Lua实现一致**：只使用通用参数 + software + card + needle
- **保持登录验证参数不变**：登录验证参数已经与Lua实现一致

## Impact

- 受影响的功能：卡密心跳验证系统
- 受影响的代码：`app/src/main/cpp/tool.cpp` 中的 `cardHeartbeat` 函数
- 修复后心跳验证将能够正常工作，避免因参数不一致导致的验证失败
