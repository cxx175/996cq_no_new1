## Why

根据卡密心跳接口官方文档，心跳请求只需要三个必需参数：card、software和needle。但当前实现中包含了额外的参数（center_id、tmstamp、sign、client_key），这些参数不在官方文档中定义，可能导致服务器拒绝请求并返回"卡密异地登录"错误。

## What Changes

- **移除心跳请求中的多余参数**：删除center_id、tmstamp、sign、client_key等非文档定义的参数
- **简化心跳请求参数**：只保留文档中定义的三个必需参数：card、software、needle
- **确保与官方API文档一致**：严格按照官方文档实现心跳接口

## Impact

- 受影响的功能：卡密心跳验证系统
- 受影响的代码：`app/src/main/cpp/tool.cpp` 中的 `cardHeartbeat` 函数
- 修复后用户将能够正常使用卡密验证功能，避免因参数不匹配导致的请求失败
