# 卡密验证系统重构设计文档

## 架构设计

### 当前架构问题
1. **非标准API**: 使用自定义的验证接口，缺乏标准化
2. **参数格式不统一**: 使用传统的表单参数，缺乏现代API设计
3. **响应解析复杂**: 自定义的响应格式，难以维护
4. **安全性不足**: 缺乏标准的签名验证机制

### 新架构设计

#### 1. API层重构
```
旧架构: http://gmcdk.top/sql/TongYongcdk/index.php
新架构: 域名/apiv3/card_login, /apiv3/card_heartbeat, /apiv3/card_logout
```

#### 2. 参数标准化
```cpp
// 旧参数格式
tb=软件名&cdk=卡密&imei=设备ID&tok=令牌&canshu=操作类型

// 新参数格式  
card=卡密内容&software=软件名&needle=登录标识(心跳/退出时)
```

#### 3. 响应格式统一
```json
{
  "code": "1",
  "data": {
    "type": "年",
    "endtime_timestamp": 1558022400,
    "endtime": "2019-05-17 00:00:00",
    "less_time": "【111】天【22】小时【40】分钟【57】秒", 
    "needle": "iWG1We92sK"
  },
  "time": 1548350343,
  "sign": "b6da39d4b1fc336cddc15bd041ea9cb5"
}
```

## 核心组件设计

### 1. 时间戳获取模块 (TimestampModule)

```cpp
class TimestampModule {
public:
    // 获取服务器时间戳
    static std::string getServerTimestamp(const std::string& baseUrl);
    
    // 验证时间戳有效性（60秒内）
    static bool validateTimestamp(const std::string& timestamp);
    
    // 计算时间戳差值
    static long getTimestampDifference(const std::string& serverTimestamp);
    
    // 多服务器时间戳获取（带故障转移）
    static std::string getServerTimestampWithFailover();
};
```

### 配置常量
```cpp
// 开发者配置
const std::string CENTER_ID = "812700";
const std::string API_PASSWORD = "124600";
const std::string SOFTWARE_NAME = "QLBT";

// 服务器列表
const std::vector<std::string> API_SERVERS = {
    "https://napi.2cccc.cc",
    "http://api2.2cccc.cc",
    "http://api3.2cccc.cc"
};
```

### 2. 签名验证模块 (SignatureModule)

```cpp
class SignatureModule {
public:
    // 生成请求签名: MD5(apipassword + timestamp)
    static std::string generateRequestSignature(const std::string& apiPassword, const std::string& timestamp);
    
    // 验证响应签名: MD5(timestamp + apipassword)
    static bool verifyResponseSignature(const std::string& timestamp, const std::string& apiPassword, const std::string& receivedSign);
    
    // MD5加密函数
    static std::string md5Hash(const std::string& input);
};
```

### 3. 卡密登录模块 (CardLoginModule)

```cpp
class CardLoginModule {
public:
    // 卡密登录
    static std::string cardLogin(const std::string& card, const std::string& software);
    
    // 解析登录响应
    static CardLoginResponse parseLoginResponse(const std::string& jsonResponse);
    
    // 验证登录结果
    static bool validateLoginResult(const CardLoginResponse& response);
};
```

**数据结构**:
```cpp
struct CardLoginResponse {
    std::string type;           // 卡密类型
    long endtime_timestamp;    // 到期时间戳
    std::string endtime;        // 到期时间字符串
    std::string less_time;      // 剩余时间
    std::string needle;         // 登录标识
    std::string sign;           // 签名
    bool success;              // 是否成功
};
```

### 2. 卡密心跳模块 (CardHeartbeatModule)

```cpp
class CardHeartbeatModule {
public:
    // 发送心跳
    static std::string sendHeartbeat(const std::string& needle);
    
    // 解析心跳响应
    static CardHeartbeatResponse parseHeartbeatResponse(const std::string& jsonResponse);
    
    // 验证心跳结果
    static bool validateHeartbeatResult(const CardHeartbeatResponse& response);
};
```

**数据结构**:
```cpp
struct CardHeartbeatResponse {
    std::string status;         // 心跳状态
    std::string message;        // 状态消息
    long endtime_timestamp;     // 到期时间戳
    std::string less_time;      // 剩余时间
    std::string sign;           // 签名
    bool success;              // 是否成功
};
```

### 3. 卡密退出模块 (CardLogoutModule)

```cpp
class CardLogoutModule {
public:
    // 退出登录
    static std::string cardLogout(const std::string& needle);
    
    // 解析退出响应
    static CardLogoutResponse parseLogoutResponse(const std::string& jsonResponse);
    
    // 清理本地状态
    static void cleanupLocalState();
};
```

### 4. 多服务器管理模块 (ServerManagerModule)

```cpp
class ServerManagerModule {
public:
    // 获取可用服务器列表
    static std::vector<std::string> getAvailableServers();
    
    // 随机选择服务器
    static std::string selectRandomServer();
    
    // 验证响应是否为有效JSON
    static bool isValidJsonResponse(const std::string& response);
    
    // 执行带故障转移的请求
    static std::string performRequestWithFailover(const std::string& endpoint, 
                                                  const std::map<std::string, std::string>& params,
                                                  int maxRetries = 20);
};
```

### 5. 统一网络请求模块 (NetworkRequestModule)

```cpp
class NetworkRequestModule {
public:
    // 执行POST请求
    static std::string performPostRequest(const std::string& url, 
                                         const std::map<std::string, std::string>& params);
    
    // 构建请求参数
    static std::string buildRequestParams(const std::map<std::string, std::string>& params);
    
    // 处理HTTP响应
    static std::string processHttpResponse(const std::string& response, long responseCode);
    
    // 验证JSON响应格式
    static bool validateJsonResponse(const std::string& response);
};
```

## 数据流设计

### 1. 卡密登录流程
```
用户输入卡密 -> 参数验证 -> 构建请求 -> 发送POST请求 -> 解析响应 -> 提取needle -> 保存状态
```

### 2. 心跳验证流程  
```
定时器触发 -> 获取needle -> 构建心跳请求 -> 发送POST请求 -> 解析响应 -> 更新状态
```

### 3. 退出登录流程
```
用户退出 -> 获取needle -> 构建退出请求 -> 发送POST请求 -> 清理本地状态
```

## 错误处理设计

### 1. 错误分类
- **网络错误**: 连接超时、DNS解析失败等
- **参数错误**: 卡密格式错误、软件名无效等  
- **业务错误**: 卡密过期、无效卡密等
- **系统错误**: JSON解析失败、内存不足等

### 2. 错误处理策略
```cpp
enum class CardVerificationError {
    NETWORK_ERROR = 1001,
    PARAMETER_ERROR = 1002, 
    BUSINESS_ERROR = 1003,
    SYSTEM_ERROR = 1004
};

class ErrorHandler {
public:
    static std::string getErrorMessage(CardVerificationError error);
    static void logError(CardVerificationError error, const std::string& details);
    static bool shouldRetry(CardVerificationError error);
};
```

## 安全设计

### 1. 参数加密
- 使用AES加密敏感参数
- 实现参数签名验证
- 防止参数篡改

### 2. 通信安全
- 使用HTTPS协议
- 实现证书验证
- 防止中间人攻击

### 3. 状态安全
- 安全存储needle标识
- 实现状态验证
- 防止状态伪造

## 性能优化

### 1. 网络优化
- 实现连接池复用
- 设置合理的超时时间
- 实现请求重试机制

### 2. 内存优化
- 及时释放JSON解析对象
- 避免内存泄漏
- 优化字符串操作

### 3. 并发优化
- 使用线程安全的数据结构
- 实现异步请求处理
- 避免阻塞主线程

## 兼容性设计

### 1. 向后兼容
- 保持现有JNI接口不变
- 实现参数格式转换
- 提供迁移工具

### 2. 渐进式迁移
- 支持新旧API并存
- 实现自动切换机制
- 提供回滚方案

### 3. 配置管理
- 支持API端点配置
- 实现功能开关
- 提供调试模式

## 测试策略

### 1. 单元测试
- 测试每个模块的独立功能
- 模拟网络请求和响应
- 验证错误处理逻辑

### 2. 集成测试
- 测试完整的验证流程
- 验证模块间协作
- 测试异常场景

### 3. 性能测试
- 测试网络请求性能
- 验证内存使用情况
- 测试并发处理能力

### 4. 安全测试
- 测试参数加密
- 验证签名机制
- 测试防篡改能力
