# 卡密心跳验证错误分析报告

## 问题概述

根据日志分析，卡密心跳验证失败，服务器返回错误：`{"code":"0","msg":"center_id参数错误"}`

## 错误分析

### 1. 问题现象
- 卡密登录成功：`{"code":"1","data":{"type":"月","endtime_timestamp":1763738055,"endtime":"2025-11-21 23:14:15","less_time":"【29】天【23】小时【32】分钟【4】秒","needle":"tvZP1eNF5T","is_card_actived":1,"id":12866622},"timestamp":1761147731,"sign":"bde6d52f2a6e9fdf08c67e12d5069e47"}`
- 心跳验证失败：`{"code":"0","msg":"center_id参数错误"}`

### 2. 根本原因
通过代码分析发现，在`cardHeartbeat`函数（第3323-3346行）中，构建请求参数时缺少了`center_id`参数：

```cpp
std::map<std::string, std::string> params = {
    {HTTP_PARAM_CARD, card},
    {HTTP_PARAM_SOFTWARE, CARD_API_SOFTWARE},
    {HTTP_PARAM_NEEDLE, needle}
    // 缺少 center_id 参数
};
```

### 3. 对比分析
在`cardLogin`函数中，请求参数包含了`center_id`：
```cpp
std::map<std::string, std::string> params = {
    {HTTP_PARAM_CARD, card},
    {HTTP_PARAM_SOFTWARE, CARD_API_SOFTWARE},
    {HTTP_PARAM_CENTER_ID, CARD_API_CENTER_ID},  // 包含center_id
    {HTTP_PARAM_TIMESTAMP, timestamp},
    {HTTP_PARAM_SIGN, sign}
};
```

但在`cardHeartbeat`函数中缺少了`center_id`参数。

## 修复方案

### 1. 立即修复
在`cardHeartbeat`函数的请求参数中添加`center_id`参数：

```cpp
std::map<std::string, std::string> params = {
    {HTTP_PARAM_CARD, card},
    {HTTP_PARAM_SOFTWARE, CARD_API_SOFTWARE},
    {HTTP_PARAM_NEEDLE, needle},
    {HTTP_PARAM_CENTER_ID, CARD_API_CENTER_ID}  // 添加center_id参数
};
```

### 2. 验证修复
修复后需要验证：
1. 心跳验证请求包含所有必需参数
2. 服务器正确响应心跳验证
3. 持续心跳验证正常工作

## 影响范围

- **直接影响**：心跳验证失败导致应用退出
- **用户体验**：用户无法正常使用应用
- **业务影响**：授权验证机制失效

## 优先级

**高优先级** - 这是导致应用无法正常使用的关键错误，需要立即修复。

## 测试建议

1. 修复后重新测试卡密登录和心跳验证流程
2. 验证持续心跳验证是否正常工作
3. 确认应用不会因为心跳验证失败而退出
