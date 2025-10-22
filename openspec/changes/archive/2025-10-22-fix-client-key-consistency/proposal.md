## Why

通过深入分析Lua实现代码，发现了真正的根本问题：

**参数名称不匹配**：
- **Lua使用**：`tmstamp` 参数（第16行：`"&tmstamp=" .. timestamp`）
- **C++使用**：`timestamp` 参数（`HTTP_PARAM_TIMESTAMP=timestamp`）

这解释了为什么Lua能正常工作而C++不能！服务器端期望的是 `tmstamp` 参数，而不是 `timestamp` 参数。之前的client_key一致性分析是错误的，真正的问题是参数名称不匹配。

## What Changes

- **修正时间戳参数名称**：将 `timestamp` 改为 `tmstamp` 以匹配服务器端期望
- **更新常量定义**：修改 `HTTP_PARAM_TIMESTAMP` 的定义
- **确保与Lua实现一致**：所有API调用都使用 `tmstamp` 参数

## Impact

- 受影响的功能：卡密登录、心跳验证、退出登录系统
- 受影响的代码：`app/src/main/cpp/strings.txt` 和所有使用时间戳参数的函数
- 修复后用户将能够正常使用卡密验证功能，与Lua实现完全一致
