# 应用卡密验证系统重构规范

## ADDED Requirements

### 1. 权朗网络API3.0集成支持
#### Scenario: 集成标准卡密验证API
- **Given** 应用需要验证用户卡密
- **When** 用户输入卡密进行登录
- **Then** 系统SHALL获取服务器时间戳 (`GET 域名/time`)
- **And** 系统SHALL生成请求签名 (`MD5(apipassword + timestamp)`)
- **And** 系统SHALL调用权朗网络API3.0的`/apiv3/card_login`接口
- **And** 系统SHALL传递公共参数 (`center_id`, `timestamp`, `sign`) 和业务参数 (`card`, `software`)
- **And** 系统SHALL验证响应签名 (`MD5(timestamp + apipassword)`)
- **And** 系统SHALL解析标准JSON响应格式

### 2. 卡密登录功能
#### Scenario: 用户使用卡密登录
- **Given** 用户拥有有效的卡密
- **When** 用户输入卡密并点击登录
- **Then** 系统SHALL验证卡密有效性
- **And** 系统SHALL返回卡密类型、到期时间、剩余时间等信息
- **And** 系统SHALL生成并保存`needle`标识用于后续操作

### 3. 卡密心跳验证
#### Scenario: 定期验证卡密状态
- **Given** 用户已成功登录
- **When** 系统执行定期心跳验证
- **Then** 应使用保存的`needle`标识调用`/apiv3/card_heartbeat`接口
- **And** 系统SHALL检查卡密是否仍然有效
- **And** 系统SHALL更新剩余时间信息

### 4. 卡密退出登录
#### Scenario: 用户主动退出登录
- **Given** 用户已登录系统
- **When** 用户选择退出登录
- **Then** 系统SHALL调用`/apiv3/card_logout`接口
- **And** 系统SHALL传递`needle`标识
- **And** 系统SHALL清理本地登录状态

## MODIFIED Requirements

### 5. 网络请求格式更新
#### Scenario: 更新HTTP请求参数格式
- **Given** 系统需要发送网络请求
- **When** 构建请求参数
- **Then** 应使用新的参数格式：`card`、`software`、`needle`
- **And** 系统SHALL移除旧的参数：`tb`、`cdk`、`imei`、`tok`、`canshu`
- **And** 系统SHALL保持请求头和安全设置

### 6. JSON响应解析重构
#### Scenario: 解析新的API响应格式
- **Given** 系统接收到API响应
- **When** 解析JSON数据
- **Then** 应提取`data`对象中的字段
- **And** 系统SHALL解析`type`、`endtime_timestamp`、`endtime`、`less_time`、`needle`字段
- **And** 系统SHALL验证`sign`签名字段

### 7. 错误处理机制更新
#### Scenario: 处理新的错误响应格式
- **Given** API返回错误响应
- **When** 系统处理错误
- **Then** 应解析标准错误码和消息
- **And** 系统SHALL提供用户友好的错误提示
- **And** 系统SHALL记录详细的错误日志

### 8. 状态管理重构
#### Scenario: 管理新的登录状态
- **Given** 用户登录成功
- **When** 系统保存登录状态
- **Then** 应保存`needle`标识
- **And** 系统SHALL保存卡密类型和到期时间
- **And** 系统SHALL实现状态持久化

## REMOVED Requirements

### 9. 旧API接口移除
#### Scenario: 移除旧的验证接口
- **Given** 新的API接口已实现
- **When** 系统完成迁移
- **Then** 应移除对`http://gmcdk.top/sql/TongYongcdk/index.php`的调用
- **And** 系统SHALL移除旧的参数构建逻辑
- **And** 系统SHALL清理相关的废弃代码

### 10. 旧响应格式支持移除
#### Scenario: 移除旧响应格式解析
- **Given** 新的响应解析已实现
- **When** 系统完成迁移
- **Then** 应移除旧的JSON解析逻辑
- **And** 系统SHALL移除旧的错误处理代码
- **And** 系统SHALL清理相关的废弃函数

## 技术实现要求

### API端点配置
- **时间戳获取**: `GET https://域名/time`
- **卡密登录**: `POST 域名/apiv3/card_login`
- **卡密心跳**: `POST 域名/apiv3/card_heartbeat`
- **卡密退出**: `POST 域名/apiv3/card_logout`

### 多服务器支持
- **主服务器**: `https://napi.2cccc.cc`
- **备用服务器1**: `http://api2.2cccc.cc`
- **备用服务器2**: `http://api3.2cccc.cc`
- **故障转移**: 随机选择服务器，JSON验证失败时自动切换
- **重试机制**: 最多20次重试，防止DDOS攻击影响

### 签名验证要求
```cpp
// 请求签名生成
std::string generateRequestSignature(const std::string& apiPassword, const std::string& timestamp) {
    return md5Hash(apiPassword + timestamp);  // API密码在前，时间戳在后
}

// 响应签名验证
bool verifyResponseSignature(const std::string& timestamp, const std::string& apiPassword, const std::string& receivedSign) {
    std::string expectedSign = md5Hash(timestamp + apiPassword);  // 时间戳在前，API密码在后
    return expectedSign == receivedSign;
}

// 时间戳验证（60秒内有效）
bool validateTimestamp(const std::string& timestamp) {
    long serverTime = std::stol(timestamp);
    long currentTime = std::time(nullptr);
    return (currentTime - serverTime) <= 60;
}

// JSON响应验证
bool isValidJsonResponse(const std::string& response) {
    // 检查响应是否为空
    if (response.empty()) return false;
    
    // 检查是否包含JSON结构
    if (response.find("{") == std::string::npos || 
        response.find("}") == std::string::npos) return false;
    
    // 检查是否包含必要的字段
    if (response.find("\"code\"") == std::string::npos) return false;
    
    return true;
}

// 多服务器故障转移
std::string performRequestWithFailover(const std::string& endpoint, 
                                      const std::map<std::string, std::string>& params,
                                      int maxRetries = 20) {
    std::vector<std::string> servers = {
        "https://napi.2cccc.cc",
        "http://api2.2cccc.cc", 
        "http://api3.2cccc.cc"
    };
    
    for (int attempt = 0; attempt < maxRetries; attempt++) {
        // 随机选择服务器
        std::string server = servers[rand() % servers.size()];
        std::string url = server + endpoint;
        
        // 执行请求
        std::string response = performPostRequest(url, params);
        
        // 验证JSON响应
        if (isValidJsonResponse(response)) {
            return response;
        }
        
        // 如果不是有效JSON，继续尝试下一个服务器
        LOGW("服务器 %s 响应无效，尝试下一个服务器", server.c_str());
    }
    
    return "Error: 所有服务器均不可用";
}
```

### 请求参数规范
```cpp
// 开发者配置常量
const std::string CENTER_ID = "812700";
const std::string API_PASSWORD = "124600";
const std::string SOFTWARE_NAME = "QLBT";

// 卡密登录参数
struct CardLoginParams {
    std::string card;        // 卡密内容 (必填)
    std::string software;    // 软件名 (必填，使用QLBT)
    std::string center_id;   // 开发者ID (必填，使用812700)
    std::string timestamp;   // 时间戳 (必填)
    std::string sign;        // 签名 (必填)
};

// 卡密心跳参数
struct CardHeartbeatParams {
    std::string needle;      // 登录标识 (必填)
};

// 卡密退出参数
struct CardLogoutParams {
    std::string needle;      // 登录标识 (必填)
};
```

### 响应数据结构
```cpp
// 标准API响应
struct ApiResponse {
    std::string code;        // 响应码
    CardData data;          // 数据对象
    long time;             // 时间戳
    std::string sign;       // 签名
};

// 卡密数据
struct CardData {
    std::string type;                    // 卡密类型
    long endtime_timestamp;             // 到期时间戳
    std::string endtime;                 // 到期时间字符串
    std::string less_time;              // 剩余时间
    std::string needle;                  // 登录标识
};
```

### 错误处理规范
```cpp
// 错误码定义
enum class CardApiError {
    SUCCESS = 0,
    INVALID_CARD = 1001,
    CARD_EXPIRED = 1002,
    NETWORK_ERROR = 1003,
    PARAMETER_ERROR = 1004,
    SYSTEM_ERROR = 1005
};

// 错误处理函数
std::string handleCardApiError(CardApiError error, const std::string& message);
```

## 兼容性要求

### JNI接口保持
- 保持现有`verifyLicenseNative`函数签名不变
- 保持现有参数格式不变
- 保持现有返回值格式不变

### 渐进式迁移
- 支持新旧API并存
- 实现自动切换机制
- 提供配置开关

### 向后兼容
- 保持现有功能不受影响
- 实现平滑升级
- 提供回滚方案

## 性能要求

### 网络性能
- 请求响应时间 < 3秒
- 支持请求重试机制
- 实现连接池复用

### 内存使用
- 内存占用增长 < 10%
- 及时释放临时对象
- 避免内存泄漏

### 并发处理
- 支持多线程安全
- 避免阻塞主线程
- 实现异步处理

## 安全要求

### 参数安全
- 敏感参数加密传输
- 实现参数签名验证
- 防止参数篡改

### 通信安全
- 使用HTTPS协议
- 验证服务器证书
- 防止中间人攻击

### 状态安全
- 安全存储登录状态
- 实现状态验证
- 防止状态伪造
