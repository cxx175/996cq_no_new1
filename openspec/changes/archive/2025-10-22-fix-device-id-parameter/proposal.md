## Why

根据日志分析和Lua参考代码对比，发现C++实现与Lua实现存在关键差异：
1. **参数名称不匹配**：Lua使用 `client_key` 参数，C++使用 `deviceId` 参数
2. **设备ID加密处理缺失**：Lua对设备ID进行了MD5加密处理，C++直接使用原始设备ID
3. **签名生成算法不一致**：Lua在签名生成中使用了加密后的client_key，C++没有

## What Changes

- **修正设备ID参数名称**：将 `deviceId` 改为 `client_key` 以匹配服务器端期望
- **添加设备ID加密处理**：对设备ID进行MD5加密，与Lua实现保持一致
- **修正签名生成算法**：在签名生成中使用加密后的client_key

## Impact

- 受影响的功能：卡密心跳验证系统
- 受影响的代码：`app/src/main/cpp/tool.cpp` 中的 `cardHeartbeat` 函数
- 修复后用户将能够正常使用卡密验证功能，避免因参数不匹配而导致的异地登录错误
