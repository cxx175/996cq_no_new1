#ifndef TOOL_H
#define TOOL_H

#include <jni.h>
#include <string>
#include <android/log.h>
#include <vector>
#include "hook.h"  // 包含Hook系统头文件

#ifndef NO_CURL
#include <curl/curl.h>
#endif

#ifndef NO_OPENSSL
#include <openssl/ssl.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/rand.h>
#endif

// 日志宏定义
#define LOG_TAG "LUA-print"

// 灵活的日志控制：支持Debug模式、Release模式（带日志）、Release模式（无日志）
#if defined(DEBUG_MODE) || defined(RELEASE_MODE)
// Debug模式或Release模式（启用日志） - 启用日志
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#elif defined(NDEBUG)
// Release模式（NDEBUG定义）- 禁用所有日志
#define LOGI(...) ((void)0)
#define LOGE(...) ((void)0)
#define LOGD(...) ((void)0)
#define LOGW(...) ((void)0)
#else
// 默认情况（开发环境） - 启用日志
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#endif

// 文件路径常量
extern const std::string DEVICE_ID_FILE_PATH;
extern const std::string DEVICE_ID_FILE_NAME;
extern const std::string STORAGE_PATH_DOCUMENTS;
extern const std::string DEVICE_ID_FILE_TXT;

// JNI相关函数
JavaVM* getGlobalJavaVM();

// 域名相关
extern std::string g_extractedDomain;
std::string extractDomainFromUrl(const std::string& url);
std::string getCurrentDomain();

// 应用名称相关
extern std::string g_appName;
void setAppName(const std::string& appName);
std::string getAppName();
void autoInitAppName(JNIEnv* env, jobject context);  // 自动初始化应用名称

// 包名相关函数
std::string getCurrentPackageName();  // 获取当前程序包名（不依赖Java层）

#ifndef NO_OPENSSL
// OpenSSL加密相关函数
std::string encryptDomainWithAES(const std::string& domain);
std::string encryptPostDataWithAES(const std::string& postData);
std::string decryptPostDataWithAES(const std::string& encryptedData);
std::string generateRandomString(int length);
#endif

#ifndef NO_CURL
// HTTP相关函数
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) __attribute__((unused));
std::string performHttpGet(const std::string& url);
std::string performHttpPost(const std::string& url, const std::string& postData);
#endif

// 字符串处理函数
std::string decodeUnicodeEscapes(const std::string& str);
std::string extractLoginFromJson(const std::string& jsonStr);
std::string extractExpiryTime(const std::string& loginValue);
std::string buildFormData(const std::string& token, const std::string& licenseKey, 
                         const std::string& deviceId, const std::string& canshu);

// 时间和UUID相关函数
std::string generateTimestampHash();
std::string generateUUID();

// 新增：时间处理和比较函数
void saveExpiryTime(const std::string& expiryTime);
std::string getSavedExpiryTime();
std::time_t parseTimeString(const std::string& timeStr);
bool isExpiredByLocalTime();
std::string formatTimeDifference(std::time_t currentTime, std::time_t expiryTime);

// 文件操作函数
bool createDirectory(const std::string& path);
bool createDirectoryWithJNI(JNIEnv* env, const std::string& path);  // JNI环境创建目录
std::string readDeviceIdFromFile(const std::string& filePath);
bool saveDeviceIdToFile(const std::string& deviceId);
bool directoryExists(const std::string& path);
bool copyFile(const std::string& sourcePath, const std::string& targetPath);
bool copyDirectory(const std::string& sourcePath, const std::string& targetPath);

// 设备相关函数
std::string getDeviceId();
// 应用签名相关函数
std::string getAppSignatureInfo();
// 授权验证函数
std::string verifyLicense(const std::string& inputToken, const std::string& licenseKey, const std::string& inputDeviceId);
std::string sendHeartbeat(const std::string& token, const std::string& licenseKey, const std::string& deviceId);

// 新增：登录验证并自动启动心跳的统一接口

// 域名验证相关函数
std::string getCurrentDomain();
bool verifyDomainIntegrity();


// 多线程心跳验证相关函数
void startContinuousHeartbeat(const std::string& token, const std::string& licenseKey, const std::string& deviceId, int intervalSeconds = 300);
void stopContinuousHeartbeat();
bool isHeartbeatRunning();
std::string verifyLicenseWithContinuousHeartbeat(const std::string& licenseKey);

// 新增：基于PHP后端验证逻辑的参数验证函数
namespace ValidationUtils {
    bool validateTableName(const std::string& tableName);
    bool validateCDK(const std::string& cdk);
    bool validateIMEI(const std::string& deviceId);
    bool validateParameters(const std::string& table, const std::string& cdk, 
                          const std::string& deviceId, const std::string& token);
    std::string filterSensitiveData(const std::string& cdk, const std::string& deviceId);
    bool validateCanshu(const std::string& canshu);
}

// 应用退出清理函数
void cleanupOnAppExit();

// 解压缩数据存储相关函数
void saveUnzippedFileData(const std::string& filePath, const jbyte* data, jsize dataLength);
std::string getUnzippedFileData(const std::string& filePath);
bool hasUnzippedFileData(const std::string& filePath);
std::vector<std::string> getUnzippedFileList();
void logAllUnzippedFileData();

// 数据完整性验证函数
uint32_t calculateChecksum(const std::string& data);
bool verifyDataIntegrity(const std::string& originalData, const std::string& processedData, const std::string& stage);

// 字符串搜索函数
std::vector<std::string> searchStringInUnzippedFiles(const std::string& searchString, bool caseSensitive = false);
std::vector<std::string> searchMultipleStringsInUnzippedFiles(const std::vector<std::string>& searchStrings, bool caseSensitive = false);

// 文件信息获取函数
std::string getFileDataInfo(const std::string& filePath);

// 异步签名验证
void asyncSignatureCheckThread();

// 签名验证相关函数
bool verifyAppSignature();
std::string getExpectedSignature();
bool compareSignatures(const std::string& currentSig, const std::string& expectedSig);

// 初始化应用签名验证
void initAppSignatureCheck();

// 新增：JNI参数版本的授权验证与心跳
std::string verifyLicenseWithContinuousHeartbeat(JNIEnv* env, jobject context, const std::string& licenseKey);
// 新增：导出SharedPreferences为JSON
void demoConvertPrefsToJson(JNIEnv* env, jobject context);
// 新增：获取SharedPreferences XML路径
std::string getSharedPrefsXmlPath(JNIEnv* env, jobject context, const std::string& prefName);

// 新增：多线程定时导出UI.json控制函数
void startDemoConvertPrefsToJsonLoop(JNIEnv* env, jobject context);
void stopDemoConvertPrefsToJsonLoop(JNIEnv* env);

#endif // TOOL_H