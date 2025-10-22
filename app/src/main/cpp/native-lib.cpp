#include <jni.h>
#include <string>
#include <functional>
#include <unistd.h>
#include <android/log.h>
#include "tool.h"
#include "app_strings.h"
#include "zip_reader.h"

#ifndef NO_CURL
#include <curl/curl.h>
#endif

// 全局JavaVM指针
static JavaVM* g_jvm = nullptr;

// Hook系统函数外部声明
extern void setAppExiting(bool exiting);
extern void setHookSystemEnabled(bool enabled);
extern bool isAppExitingNow();
extern bool isHookSystemEnabled();
extern void cleanupHooksOnExit();

// 声明LuaDecryptHook命名空间函数
namespace LuaDecryptHook {
    void lua_decrypt_hook_cleanup();
}

// JNI_OnLoad函数，在动态库加载时调用
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    g_jvm = vm;
    
    LOGI("动态库加载完成，JavaVM已保存");
    
#ifndef NO_CURL
    // 初始化curl全局状态，这对于长时间运行的应用很重要
    CURLcode curlResult = curl_global_init(CURL_GLOBAL_DEFAULT);
    if (curlResult != CURLE_OK) {
        LOGE("curl全局初始化失败: %s", curl_easy_strerror(curlResult));
    } else {
        LOGI("curl全局初始化成功");
    }
#endif
    
    // 初始化应用签名验证
    initAppSignatureCheck();
    
    LOGI("动态库初始化完成");
    return JNI_VERSION_1_6;
}

// JNI_OnUnload函数，在动态库卸载时调用
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    
    LOGI("动态库开始卸载，执行清理");
    
    // 1. 立即设置退出标志，阻止新的操作
    setAppExiting(true);
    
    // 2. 清理Hook系统（包括线程池）
    try {
        cleanupHooksOnExit();
        LOGI("✅ Hook系统清理完成");
    } catch (const std::exception& e) {
        LOGE("❌ Hook系统清理失败: %s", e.what());
    } catch (...) {
        LOGE("❌ Hook系统清理发生未知异常");
    }
    
    // 3. 清理Lua解密Hook系统（包括跳板内存）
    try {
        LuaDecryptHook::lua_decrypt_hook_cleanup();
        LOGI("✅ Lua解密Hook系统清理完成");
    } catch (const std::exception& e) {
        LOGE("❌ Lua解密Hook清理失败: %s", e.what());
    } catch (...) {
        LOGE("❌ Lua解密Hook清理发生未知异常");
    }
    
    // 4. 等待一小段时间确保所有线程退出
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

#ifndef NO_CURL
    // 5. 清理curl全局状态
    try {
        curl_global_cleanup();
        LOGI("✅ curl全局清理完成");
    } catch (...) {
        LOGE("❌ curl清理发生异常");
    }
#endif
    
    // 6. 清理全局JavaVM指针
    g_jvm = nullptr;
    
    LOGI("✅ 动态库卸载完成");
}

// 获取全局JavaVM指针的函数
JavaVM* getGlobalJavaVM() {
    return g_jvm;
}

// 所有工具函数已移动到tool.cpp中

// 函数声明
bool copyAssetsDirectory(JNIEnv* env, jobject assetManager, const std::string& assetsPath, const std::string& targetPath);
bool copyAssetFile(JNIEnv* env, jobject inputStream, const std::string& targetPath);
// 新增 window.json 复制和解压封装函数声明
void copyAndUnzipWindowJson(JNIEnv* env, jobject assetManager, jmethodID openMethod, const char* filesDirPathStr, const char* fileName);

// JNI接口：原有的verifyLicenseNative函数，现在调用统一的验证接口
extern "C" JNIEXPORT jstring JNICALL
Java_load_tencent_lib_MainActivity_verifyLicenseNative(JNIEnv *env, jobject thiz, jstring licenseKey) {
    // 获取传入的许可证密钥
    const char *licenseKeyStr = env->GetStringUTFChars(licenseKey, 0);
    // 调用新的verifyLicenseWithContinuousHeartbeat函数启动持续心跳验证
    // token和deviceId在C++层内部自动生成
    std::string result = verifyLicenseWithContinuousHeartbeat(env, thiz, std::string(licenseKeyStr));
    env->ReleaseStringUTFChars(licenseKey, licenseKeyStr);
    return env->NewStringUTF(result.c_str());
}

// JNI接口：获取字符串常量（用于MainActivity）
extern "C" JNIEXPORT jstring JNICALL
Java_load_tencent_lib_MainActivity_getAppStringNative(JNIEnv *env, jobject /* this */, jstring key) {
    if (!env || !key) {
        return env ? env->NewStringUTF("") : nullptr;
    }
    
    const char *keyStr = nullptr;
    try {
        keyStr = env->GetStringUTFChars(key, 0);
        if (!keyStr) {
            return env->NewStringUTF("");
        }
        
        std::string resultStr = getAppString(keyStr);
        const char *result = resultStr.c_str();
        
        env->ReleaseStringUTFChars(key, keyStr);
        return env->NewStringUTF(result ? result : "");
    } catch (...) {
        if (keyStr) {
            env->ReleaseStringUTFChars(key, keyStr);
        }
        return env->NewStringUTF("");
    }
}

// JNI接口：获取字符串常量（用于appStrings类）
extern "C" JNIEXPORT jstring JNICALL
Java_load_tencent_lib_appStrings_getAppStringNative(JNIEnv *env, jclass /* clazz */, jstring key) {
    if (!env || !key) {
        return env ? env->NewStringUTF("") : nullptr;
    }
    
    const char *keyStr = nullptr;
    try {
        keyStr = env->GetStringUTFChars(key, 0);
        if (!keyStr) {
            return env->NewStringUTF("");
        }
        
        std::string resultStr = getAppString(keyStr);
        const char *result = resultStr.c_str();
        
        env->ReleaseStringUTFChars(key, keyStr);
        return env->NewStringUTF(result ? result : "");
    } catch (...) {
        if (keyStr) {
            env->ReleaseStringUTFChars(key, keyStr);
        }
        return env->NewStringUTF("");
    }
}

// JNI接口：应用退出清理
extern "C" JNIEXPORT void JNICALL
Java_load_tencent_lib_MainActivity_cleanupNative(JNIEnv *env, jobject /* this */) {
    (void)env;
    cleanupOnAppExit();
}


// 递归复制 assets 目录的函数
bool copyAssetsDirectory(JNIEnv* env, jobject assetManager, const std::string& assetsPath, const std::string& targetPath) {
    // LOGD("copyAssetsDirectory: 开始复制assets目录从 %s 到 %s", assetsPath.c_str(), targetPath.c_str());
    
    // 获取AssetManager类
    jclass assetManagerClass = env->FindClass("android/content/res/AssetManager");
    if (assetManagerClass == nullptr) {
        LOGE("copyAssetsDirectory: 无法找到AssetManager类");
        return false;
    }
    
    // 获取list方法来列出assets目录内容
    jmethodID listMethod = env->GetMethodID(assetManagerClass, "list", "(Ljava/lang/String;)[Ljava/lang/String;");
    if (listMethod == nullptr) {
        LOGE("copyAssetsDirectory: 无法找到AssetManager.list方法");
        env->DeleteLocalRef(assetManagerClass);
        return false;
    }
    
    // 获取open方法
    jmethodID openMethod = env->GetMethodID(assetManagerClass, "open", "(Ljava/lang/String;)Ljava/io/InputStream;");
    if (openMethod == nullptr) {
        LOGE("copyAssetsDirectory: 无法找到AssetManager.open方法");
        env->DeleteLocalRef(assetManagerClass);
        return false;
    }
    
    // 列出assets目录内容
    jstring assetsPathJStr = env->NewStringUTF(assetsPath.c_str());
    if (assetsPathJStr == nullptr) {
        LOGE("copyAssetsDirectory: 无法创建assets路径字符串");
        env->DeleteLocalRef(assetManagerClass);
        return false;
    }
    
    jobjectArray assetsList = (jobjectArray)env->CallObjectMethod(assetManager, listMethod, assetsPathJStr);
    if (assetsList == nullptr) {
        LOGE("copyAssetsDirectory: 无法列出assets目录内容: %s", assetsPath.c_str());
        // 检查是否有JNI异常
        if (env->ExceptionCheck()) {
            LOGE("copyAssetsDirectory: JNI异常发生在列出assets目录时");
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        env->DeleteLocalRef(assetsPathJStr);
        env->DeleteLocalRef(assetManagerClass);
        return false;
    }
    
    // 创建目标目录
    if (!createDirectoryWithJNI(env, targetPath)) {
        LOGE("copyAssetsDirectory: 无法创建目标目录: %s", targetPath.c_str());
        env->DeleteLocalRef(assetsList);
        env->DeleteLocalRef(assetsPathJStr);
        env->DeleteLocalRef(assetManagerClass);
        return false;
    }
    
    // 获取数组长度
    jsize arrayLength = env->GetArrayLength(assetsList);
    // LOGD("copyAssetsDirectory: assets目录 %s 包含 %d 个项目", assetsPath.c_str(), arrayLength);
   
    bool success = true;
    
    // 遍历assets目录中的每个项目
    for (jsize i = 0; i < arrayLength && success; i++) {
        jstring itemName = (jstring)env->GetObjectArrayElement(assetsList, i);
        if (itemName == nullptr) {
            continue;
        }
        
        const char* itemNameStr = env->GetStringUTFChars(itemName, nullptr);
        if (itemNameStr == nullptr) {
            env->DeleteLocalRef(itemName);
            continue;
        }
        
        std::string itemAssetsPath = assetsPath.empty() ? itemNameStr : assetsPath + "/" + itemNameStr;
        std::string itemTargetPath = targetPath + "/" + itemNameStr;
        
        // LOGD("copyAssetsDirectory: 处理项目: %s", itemNameStr);
        
        // 尝试打开作为文件
        jstring itemAssetsPathJStr = env->NewStringUTF(itemAssetsPath.c_str());
        if (itemAssetsPathJStr != nullptr) {
            jobject inputStream = env->CallObjectMethod(assetManager, openMethod, itemAssetsPathJStr);
            
            if (inputStream != nullptr) {
                // 这是一个文件，复制它
                // LOGD("copyAssetsDirectory: 复制文件: %s", itemAssetsPath.c_str());
                success = copyAssetFile(env, inputStream, itemTargetPath);
                
                // 关闭输入流
                jclass inputStreamClass = env->FindClass("java/io/InputStream");
                if (inputStreamClass != nullptr) {
                    jmethodID closeMethod = env->GetMethodID(inputStreamClass, "close", "()V");
                    if (closeMethod != nullptr) {
                        env->CallVoidMethod(inputStream, closeMethod);
                    }
                    env->DeleteLocalRef(inputStreamClass);
                }
                
                env->DeleteLocalRef(inputStream);
            } else {
                // 清除可能的异常
                if (env->ExceptionCheck()) {
                    env->ExceptionClear();
                }
                
                // 这可能是一个目录，递归复制
                // LOGD("copyAssetsDirectory: 递归复制目录: %s", itemAssetsPath.c_str());
                success = copyAssetsDirectory(env, assetManager, itemAssetsPath, itemTargetPath);
            }
            
            env->DeleteLocalRef(itemAssetsPathJStr);
        }
        
        env->ReleaseStringUTFChars(itemName, itemNameStr);
        env->DeleteLocalRef(itemName);
    }
    
    // 清理资源
    env->DeleteLocalRef(assetsList);
    env->DeleteLocalRef(assetsPathJStr);
    env->DeleteLocalRef(assetManagerClass);
    
    if (success) {
        // LOGD("copyAssetsDirectory: 成功复制assets目录: %s", assetsPath.c_str());
    } else {
        LOGE("copyAssetsDirectory: 复制assets目录失败: %s", assetsPath.c_str());
    }
    
    return success;
}

// 复制单个 asset 文件的函数
bool copyAssetFile(JNIEnv* env, jobject inputStream, const std::string& targetPath) {
    // LOGD("copyAssetFile: 开始复制文件到: %s", targetPath.c_str());
    
    // 确保目标目录存在
    std::string targetDir = targetPath.substr(0, targetPath.find_last_of('/'));
    if (!createDirectoryWithJNI(env, targetDir)) {
        LOGE("copyAssetFile: 无法创建目标目录: %s", targetDir.c_str());
        return false;
    }
    
    // 创建FileOutputStream
    jclass fileOutputStreamClass = env->FindClass("java/io/FileOutputStream");
    if (fileOutputStreamClass == nullptr) {
        LOGE("copyAssetFile: 无法找到FileOutputStream类");
        return false;
    }
    
    jmethodID fileOutputStreamConstructor = env->GetMethodID(fileOutputStreamClass, "<init>", "(Ljava/lang/String;)V");
    if (fileOutputStreamConstructor == nullptr) {
        LOGE("copyAssetFile: 无法找到FileOutputStream构造函数");
        env->DeleteLocalRef(fileOutputStreamClass);
        return false;
    }
    
    jstring targetPathJStr = env->NewStringUTF(targetPath.c_str());
    if (targetPathJStr == nullptr) {
        LOGE("copyAssetFile: 无法创建目标路径字符串");
        env->DeleteLocalRef(fileOutputStreamClass);
        return false;
    }
    
    jobject outputStream = env->NewObject(fileOutputStreamClass, fileOutputStreamConstructor, targetPathJStr);
    if (outputStream == nullptr) {
        LOGE("copyAssetFile: 无法创建FileOutputStream");
        env->DeleteLocalRef(targetPathJStr);
        env->DeleteLocalRef(fileOutputStreamClass);
        return false;
    }
    
    // 获取输入流和输出流的方法
    jclass inputStreamClass = env->FindClass("java/io/InputStream");
    jclass outputStreamClass = env->FindClass("java/io/OutputStream");
    
    if (inputStreamClass == nullptr || outputStreamClass == nullptr) {
        LOGE("copyAssetFile: 无法找到流类");
        env->DeleteLocalRef(outputStream);
        env->DeleteLocalRef(targetPathJStr);
        env->DeleteLocalRef(fileOutputStreamClass);
        if (inputStreamClass) env->DeleteLocalRef(inputStreamClass);
        if (outputStreamClass) env->DeleteLocalRef(outputStreamClass);
        return false;
    }
    
    jmethodID readMethod = env->GetMethodID(inputStreamClass, "read", "([B)I");
    jmethodID writeMethod = env->GetMethodID(outputStreamClass, "write", "([BII)V");
    jmethodID closeOutputMethod = env->GetMethodID(outputStreamClass, "close", "()V");
    
    if (readMethod == nullptr || writeMethod == nullptr || closeOutputMethod == nullptr) {
        LOGE("copyAssetFile: 无法找到流方法");
        env->DeleteLocalRef(outputStream);
        env->DeleteLocalRef(targetPathJStr);
        env->DeleteLocalRef(fileOutputStreamClass);
        env->DeleteLocalRef(inputStreamClass);
        env->DeleteLocalRef(outputStreamClass);
        return false;
    }
    
    // 创建缓冲区
    jbyteArray buffer = env->NewByteArray(16384); // 16KB缓冲区
    if (buffer == nullptr) {
        LOGE("copyAssetFile: 无法创建缓冲区");
        env->DeleteLocalRef(outputStream);
        env->DeleteLocalRef(targetPathJStr);
        env->DeleteLocalRef(fileOutputStreamClass);
        env->DeleteLocalRef(inputStreamClass);
        env->DeleteLocalRef(outputStreamClass);
        return false;
    }
    
    // 复制文件内容
    int bytesRead;
    long totalBytes = 0;
    bool copySuccess = true;
    
    while ((bytesRead = env->CallIntMethod(inputStream, readMethod, buffer)) > 0) {
        env->CallVoidMethod(outputStream, writeMethod, buffer, 0, bytesRead);
        totalBytes += bytesRead;
        
        // 检查JNI异常
        if (env->ExceptionCheck()) {
            LOGE("copyAssetFile: 文件复制过程中发生异常");
            env->ExceptionClear();
            copySuccess = false;
            break;
        }
    }
    
    // 关闭输出流
    env->CallVoidMethod(outputStream, closeOutputMethod);
    
    // 清理资源
    env->DeleteLocalRef(buffer);
    env->DeleteLocalRef(outputStream);
    env->DeleteLocalRef(targetPathJStr);
    env->DeleteLocalRef(fileOutputStreamClass);
    env->DeleteLocalRef(inputStreamClass);
    env->DeleteLocalRef(outputStreamClass);
    
    if (copySuccess) {
        // LOGD("copyAssetFile: 文件复制成功 (总字节数: %ld)", totalBytes);
    } else {
        LOGE("copyAssetFile: 文件复制失败");
    }
    
    return copySuccess;
}

// JNI接口：检查assets目录是否存在并复制文件到指定目录
extern "C" JNIEXPORT jboolean JNICALL
Java_load_tencent_lib_MainActivity_checkAndCopyAssetsDirectoryNative(JNIEnv *env, jobject thiz) {
    if (env == nullptr) {
        return JNI_FALSE;
    }
    
    bool result = true;
    
    try {
        // 获取Context类
        jclass contextClass = env->FindClass("android/content/Context");
        if (contextClass == nullptr) {
            LOGE("复制assets目录: 无法找到Context类");
            return JNI_FALSE;
        }
        
        // 获取getFilesDir方法
        jmethodID getFilesDirMethod = env->GetMethodID(contextClass, "getFilesDir", "()Ljava/io/File;");
        if (getFilesDirMethod == nullptr) {
            LOGE("复制assets目录: 无法找到getFilesDir方法");
            env->DeleteLocalRef(contextClass);
            return JNI_FALSE;
        }
        
        // 调用getFilesDir获取文件目录
        jobject filesDir = env->CallObjectMethod(thiz, getFilesDirMethod);
        if (filesDir == nullptr) {
            LOGE("复制assets目录: 无法获取文件目录");
            env->DeleteLocalRef(contextClass);
            return JNI_FALSE;
        }
        
        // 获取File类和getAbsolutePath方法
        jclass fileClass = env->FindClass("java/io/File");
        if (fileClass == nullptr) {
            LOGE("复制assets目录: 无法找到File类");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(filesDir);
            return JNI_FALSE;
        }
        
        jmethodID getAbsolutePathMethod = env->GetMethodID(fileClass, "getAbsolutePath", "()Ljava/lang/String;");
        if (getAbsolutePathMethod == nullptr) {
            LOGE("复制assets目录: 无法找到getAbsolutePath方法");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(filesDir);
            env->DeleteLocalRef(fileClass);
            return JNI_FALSE;
        }
        
        // 获取文件目录路径
        jstring filesDirPath = (jstring)env->CallObjectMethod(filesDir, getAbsolutePathMethod);
        if (filesDirPath == nullptr) {
            LOGE("复制assets目录: 无法获取文件目录路径");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(filesDir);
            env->DeleteLocalRef(fileClass);
            return JNI_FALSE;
        }
        
        const char* filesDirPathStr = env->GetStringUTFChars(filesDirPath, nullptr);
        if (filesDirPathStr == nullptr) {
            LOGE("复制assets目录: 无法获取文件目录路径字符串");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(filesDir);
            env->DeleteLocalRef(fileClass);
            env->DeleteLocalRef(filesDirPath);
            return JNI_FALSE;
        }
        
        LOGD("复制assets目录: 应用文件目录: %s", filesDirPathStr);
        
        // 获取AssetManager类
        jmethodID getAssetsMethod = env->GetMethodID(contextClass, "getAssets", "()Landroid/content/res/AssetManager;");
        if (getAssetsMethod == nullptr) {
            LOGE("复制assets目录: 无法找到getAssets方法");
            result = false;
        } else {
        jobject assetManager = env->CallObjectMethod(thiz, getAssetsMethod);
        if (assetManager == nullptr) {
            LOGE("复制assets目录: 无法获取AssetManager");
                result = false;
            } else {
        jclass assetManagerClass = env->FindClass("android/content/res/AssetManager");
        if (assetManagerClass == nullptr) {
            LOGE("复制assets目录: 无法找到AssetManager类");
                    result = false;
                } else {
                    jmethodID openMethod = env->GetMethodID(assetManagerClass, "open", "(Ljava/lang/String;)Ljava/io/InputStream;");
                    if (openMethod == nullptr) {
                        LOGE("复制assets目录: 无法找到AssetManager.open方法");
                        result = false;
                    } else {
                        // 构建目标路径
                        std::string targetPathStr = std::string(filesDirPathStr) + "/" + RESOURCE_SCRIPTS_PATH;
                        std::string targetPathStr1 = std::string(filesDirPathStr) + "/" + RESOURCE_GUILayout_PATH;
                        LOGD("复制assets目录: 源路径: %s", RESOURCE_SCRIPTS_PATH);
                        LOGD("复制assets目录: 目标路径: %s", targetPathStr.c_str());
                        LOGD("复制assets目录: 源路径: %s", RESOURCE_GUILayout_PATH);
                        LOGD("复制assets目录: 目标路径: %s", targetPathStr1.c_str());

                        // 检查assets目录是否存在
                        jmethodID listMethod = env->GetMethodID(assetManagerClass, "list", "(Ljava/lang/String;)[Ljava/lang/String;");
                        if (listMethod != nullptr) {
                            // 检查第一个目录
                            jstring checkPath1 = env->NewStringUTF(RESOURCE_SCRIPTS_PATH);
                            jobjectArray checkList1 = (jobjectArray)env->CallObjectMethod(assetManager, listMethod, checkPath1);
                            if (checkList1 == nullptr) {
                                LOGE("复制assets目录: 源目录不存在或无法访问: %s", RESOURCE_SCRIPTS_PATH);
                            } else {
                                jsize len1 = env->GetArrayLength(checkList1);
                                LOGD("复制assets目录: 源目录 %s 包含 %d 个项目", RESOURCE_SCRIPTS_PATH, len1);
                                env->DeleteLocalRef(checkList1);
                            }
                            env->DeleteLocalRef(checkPath1);
                        }
                        
                        // 开始递归复制 - 使用 assets 复制逻辑
                        bool result1 = copyAssetsDirectory(env, assetManager, RESOURCE_SCRIPTS_PATH, targetPathStr);
                        LOGD("复制assets目录: RESOURCE_SCRIPTS_PATH复制完成，结果: %s", result1 ? "成功" : "失败");
                        
                        bool result2 = copyAssetsDirectory(env, assetManager, RESOURCE_GUILayout_PATH, targetPathStr1);
                        LOGD("复制assets目录: RESOURCE_GUILayout_PATH复制完成，结果: %s", result2 ? "成功" : "失败");
                        
                        // 只有两个复制操作都成功时才返回成功
                        result = result1 && result2;
                        
                        
                        // 调用封装函数（当前为注释实现）
                        // copyAndUnzipWindowJson(env, assetManager, openMethod, filesDirPathStr,"window.json");
                    }
                    
                    env->DeleteLocalRef(assetManagerClass);
                }
                
                env->DeleteLocalRef(assetManager);
            }
        }
        
        // 释放资源
        env->ReleaseStringUTFChars(filesDirPath, filesDirPathStr);
        env->DeleteLocalRef(filesDirPath);
        env->DeleteLocalRef(fileClass);
        env->DeleteLocalRef(filesDir);
        env->DeleteLocalRef(contextClass);
        
    } catch (const std::exception& e) {
        LOGE("复制assets目录: 发生C++异常: %s", e.what());
        result = false;
    } catch (...) {
        LOGE("复制assets目录: 发生未知异常");
        result = false;
    }
    
    LOGD("复制assets目录总体结果: %s (RESOURCE_SCRIPTS_PATH 和 RESOURCE_GUILayout_PATH)", result ? "成功" : "失败");
    return result ? JNI_TRUE : JNI_FALSE;
}

// JNI接口：验证域名完整性(MainActivity)
extern "C" JNIEXPORT jboolean JNICALL
Java_load_tencent_lib_MainActivity_verifyDomainIntegrityNative(JNIEnv *env, jobject /* this */) {
    (void)env; // 消除未使用参数警告
    bool isValid = verifyDomainIntegrity();
    return isValid ? JNI_TRUE : JNI_FALSE;
}

// JNI接口：验证域名完整性（用于FloatContentView）
extern "C" JNIEXPORT jboolean JNICALL
Java_load_tencent_lib_FloatContentView_verifyDomainIntegrityNative(JNIEnv *env, jobject /* this */) {
    (void)env; // 消除未使用参数警告
    bool isValid = verifyDomainIntegrity();
    return isValid ? JNI_TRUE : JNI_FALSE;
}

// JNI接口：获取设备ID
// extern "C" JNIEXPORT jstring JNICALL
// Java_load_tencent_lib_MainActivity_getDeviceIdNative(JNIEnv *env, jobject /* this */) {
//     std::string deviceId = getDeviceId();
//     return env->NewStringUTF(deviceId.c_str());
// }

// JNI接口：生成token
// extern "C" JNIEXPORT jstring JNICALL
// Java_load_tencent_lib_MainActivity_generateTokenNative(JNIEnv *env, jobject /* this */) {
//     std::string token = generateTimestampHash();
//     return env->NewStringUTF(token.c_str());
// }

// 使用JNI创建目录的辅助函数
bool createDirectoryWithJNI(JNIEnv* env, const std::string& path) {
    if (env == nullptr || path.empty()) {
        return false;
    }
    
    try {
        // 获取File类
        jclass fileClass = env->FindClass("java/io/File");
        if (fileClass == nullptr) {
            LOGE("createDirectoryWithJNI: 无法找到File类");
            return false;
        }
        
        // 获取File构造函数
        jmethodID constructor = env->GetMethodID(fileClass, "<init>", "(Ljava/lang/String;)V");
        if (constructor == nullptr) {
            LOGE("createDirectoryWithJNI: 无法找到File构造函数");
            env->DeleteLocalRef(fileClass);
            return false;
        }
        
        // 创建File对象
        jstring pathStr = env->NewStringUTF(path.c_str());
        if (pathStr == nullptr) {
            LOGE("createDirectoryWithJNI: 无法创建路径字符串");
            env->DeleteLocalRef(fileClass);
            return false;
        }
        
        jobject fileObj = env->NewObject(fileClass, constructor, pathStr);
        if (fileObj == nullptr) {
            LOGE("createDirectoryWithJNI: 无法创建File对象");
            env->DeleteLocalRef(fileClass);
            env->DeleteLocalRef(pathStr);
            return false;
        }
        
        // 检查目录是否已存在
        jmethodID existsMethod = env->GetMethodID(fileClass, "exists", "()Z");
        if (existsMethod == nullptr) {
            LOGE("createDirectoryWithJNI: 无法找到exists方法");
            env->DeleteLocalRef(fileClass);
            env->DeleteLocalRef(pathStr);
            env->DeleteLocalRef(fileObj);
            return false;
        }
        
        jboolean exists = env->CallBooleanMethod(fileObj, existsMethod);
        if (exists) {
            // LOGD("createDirectoryWithJNI: 目录已存在: %s", path.c_str());
            env->DeleteLocalRef(fileClass);
            env->DeleteLocalRef(pathStr);
            env->DeleteLocalRef(fileObj);
            return true;
        }
        
        // 获取mkdirs方法
        jmethodID mkdirsMethod = env->GetMethodID(fileClass, "mkdirs", "()Z");
        if (mkdirsMethod == nullptr) {
            LOGE("createDirectoryWithJNI: 无法找到mkdirs方法");
            env->DeleteLocalRef(fileClass);
            env->DeleteLocalRef(pathStr);
            env->DeleteLocalRef(fileObj);
            return false;
        }
        
        // 调用mkdirs方法
        jboolean result = env->CallBooleanMethod(fileObj, mkdirsMethod);
        
        // 清理JNI引用
        env->DeleteLocalRef(fileClass);
        env->DeleteLocalRef(pathStr);
        env->DeleteLocalRef(fileObj);
        
        LOGD("createDirectoryWithJNI: 目录创建结果: %s -> %s", path.c_str(), result ? "成功" : "失败");
        return result == JNI_TRUE;
        
    } catch (...) {
        LOGE("createDirectoryWithJNI: 发生异常");
        return false;
    }
}

// 新增JNI函数：遍历输出解压缩数据
extern "C" JNIEXPORT void JNICALL
Java_load_tencent_lib_MainActivity_logUnzippedDataNative(JNIEnv *env, jobject /* this */) {
    LOGD("JNI调用: 开始遍历输出解压缩数据");
    logAllUnzippedFileData();
    LOGD("JNI调用: 遍历输出解压缩数据完成");
}

// ====== 新增：window.json复制和解压封装函数 ======
void copyAndUnzipWindowJson(JNIEnv* env, jobject assetManager, jmethodID openMethod, const char* filesDirPathStr, const char* fileName) {

    LOGD("复制assets目录: 开始复制ascftrll文件");
    const char* ascftrllFileName = fileName;
    std::string ascftrllTargetPath = std::string(filesDirPathStr) + "/" + ascftrllFileName;
    // 尝试打开ascftrll文件
    jstring ascftrllPathJStr = env->NewStringUTF(ascftrllFileName);
    if (ascftrllPathJStr != nullptr) {
        jobject ascftrllInputStream = env->CallObjectMethod(assetManager, openMethod, ascftrllPathJStr);
        if (ascftrllInputStream != nullptr) {
            jclass fileOutputStreamClass = env->FindClass("java/io/FileOutputStream");
            if (fileOutputStreamClass != nullptr) {
                jmethodID fileOutputStreamConstructor = env->GetMethodID(fileOutputStreamClass, "<init>", "(Ljava/lang/String;)V");
                if (fileOutputStreamConstructor != nullptr) {
                    jstring ascftrllTargetPathJStr = env->NewStringUTF(ascftrllTargetPath.c_str());
                    if (ascftrllTargetPathJStr != nullptr) {
                        jobject ascftrllOutputStream = env->NewObject(fileOutputStreamClass, fileOutputStreamConstructor, ascftrllTargetPathJStr);
                        if (ascftrllOutputStream != nullptr) {
                            jclass inputStreamClass = env->FindClass("java/io/InputStream");
                            jclass outputStreamClass = env->FindClass("java/io/OutputStream");
                            if (inputStreamClass != nullptr && outputStreamClass != nullptr) {
                                jmethodID readMethod = env->GetMethodID(inputStreamClass, "read", "([B)I");
                                jmethodID writeMethod = env->GetMethodID(outputStreamClass, "write", "([BII)V");
                                jmethodID closeInputMethod = env->GetMethodID(inputStreamClass, "close", "()V");
                                jmethodID closeOutputMethod = env->GetMethodID(outputStreamClass, "close", "()V");
                                if (readMethod != nullptr && writeMethod != nullptr && closeInputMethod != nullptr && closeOutputMethod != nullptr) {
                                    jbyteArray buffer = env->NewByteArray(16384); // 16KB缓冲区
                                    if (buffer != nullptr) {
                                        int bytesRead;
                                        long totalBytes = 0;
                                        bool copySuccess = true;
                                        while ((bytesRead = env->CallIntMethod(ascftrllInputStream, readMethod, buffer)) > 0) {
                                            env->CallVoidMethod(ascftrllOutputStream, writeMethod, buffer, 0, bytesRead);
                                            totalBytes += bytesRead;
                                            if (env->ExceptionCheck()) {
                                                LOGE("复制assets目录: ascftrll文件复制过程中发生异常");
                                                env->ExceptionClear();
                                                copySuccess = false;
                                                break;
                                            }
                                        }
                                        env->CallVoidMethod(ascftrllInputStream, closeInputMethod);
                                        env->CallVoidMethod(ascftrllOutputStream, closeOutputMethod);
                                        if (copySuccess) {
                                            jclass fileVerifyClass = env->FindClass("java/io/File");
                                            if (fileVerifyClass != nullptr) {
                                                jmethodID fileConstructor = env->GetMethodID(fileVerifyClass, "<init>", "(Ljava/lang/String;)V");
                                                jmethodID existsMethod = env->GetMethodID(fileVerifyClass, "exists", "()Z");
                                                jmethodID lengthMethod = env->GetMethodID(fileVerifyClass, "length", "()J");
                                                if (fileConstructor != nullptr && existsMethod != nullptr && lengthMethod != nullptr) {
                                                    jobject verifyFile = env->NewObject(fileVerifyClass, fileConstructor, ascftrllTargetPathJStr);
                                                    if (verifyFile != nullptr) {
                                                        jboolean fileExists = env->CallBooleanMethod(verifyFile, existsMethod);
                                                        jlong fileLength = env->CallLongMethod(verifyFile, lengthMethod);
                                                        if (fileExists && fileLength == totalBytes) {
                                                            ZipReader zipReader;
                                                            const char* password = "j__ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_jjRKS4_";
                                                            zipReader.setPassword(std::string(password));
                                                            if (zipReader.loadFromFile(ascftrllTargetPath)) {
                                                                std::vector<std::string> entryNames = zipReader.getEntryNames();
                                                                for (const std::string& entryName : entryNames) {
                                                                    if (entryName.back() == '/') continue;
                                                                    std::vector<uint8_t> fileData;
                                                                    if (zipReader.extractEntry(entryName, fileData)) {
                                                                        if (!fileData.empty()) {
                                                                            saveUnzippedFileData(entryName, reinterpret_cast<const jbyte*>(fileData.data()), fileData.size());
                                                                        }
                                                                    }
                                                                }
                                                                logAllUnzippedFileData();
                                                            } else {
                                                                LOGE("解压缩ascftrll: 加载ZIP文件失败");
                                                            }
                                                        } else {
                                                            LOGE("复制assets目录: ascftrll文件验证失败 (存在: %s, 预期大小: %ld, 实际大小: %ld)", fileExists ? "是" : "否", totalBytes, (long)fileLength);
                                                        }
                                                        env->DeleteLocalRef(verifyFile);
                                                    }
                                                }
                                                env->DeleteLocalRef(fileVerifyClass);
                                            }
                                        } else {
                                            LOGE("复制assets目录: ascftrll文件复制失败");
                                        }
                                        env->DeleteLocalRef(buffer);
                                    } else {
                                        LOGE("复制assets目录: 无法创建ascftrll缓冲区");
                                    }
                                }
                                env->DeleteLocalRef(inputStreamClass);
                                env->DeleteLocalRef(outputStreamClass);
                            }
                            env->DeleteLocalRef(ascftrllOutputStream);
                        }
                        env->DeleteLocalRef(ascftrllTargetPathJStr);
                    }
                }
                env->DeleteLocalRef(fileOutputStreamClass);
            }
            env->DeleteLocalRef(ascftrllInputStream);
        } else {
            LOGW("复制assets目录: ascftrll文件不存在于assets中，跳过复制");
        }
        env->DeleteLocalRef(ascftrllPathJStr);
    }
    
}

// 获取SharedPreferences XML文件完整路径（通过JNI反射Context）
std::string getSharedPrefsXmlPath(JNIEnv* env, jobject context, const std::string& prefName) {
    jclass contextClass = env->GetObjectClass(context);
    jmethodID getAppInfo = env->GetMethodID(contextClass, "getApplicationInfo", "()Landroid/content/pm/ApplicationInfo;");
    jobject appInfo = env->CallObjectMethod(context, getAppInfo);

    jclass appInfoClass = env->GetObjectClass(appInfo);
    jfieldID dataDirField = env->GetFieldID(appInfoClass, "dataDir", "Ljava/lang/String;");
    jstring dataDirJStr = (jstring)env->GetObjectField(appInfo, dataDirField);

    const char* dataDirCStr = env->GetStringUTFChars(dataDirJStr, nullptr);
    std::string path = std::string(dataDirCStr) + "/shared_prefs/" + prefName + ".xml";
    env->ReleaseStringUTFChars(dataDirJStr, dataDirCStr);

    env->DeleteLocalRef(dataDirJStr);
    env->DeleteLocalRef(appInfoClass);
    env->DeleteLocalRef(appInfo);
    env->DeleteLocalRef(contextClass);

    return path;
}

// JNI接口：设置应用名称
extern "C" JNIEXPORT void JNICALL
Java_load_tencent_lib_MainActivity_setAppNameNative(JNIEnv *env, jobject /* this */, jstring appName) {
    if (appName == nullptr) {
        LOGE("setAppNameNative: appName参数为空");
        return;
    }
    
    const char* appNameStr = env->GetStringUTFChars(appName, nullptr);
    if (appNameStr == nullptr) {
        LOGE("setAppNameNative: 无法获取appName字符串");
        return;
    }
    
    setAppName(std::string(appNameStr));
    env->ReleaseStringUTFChars(appName, appNameStr);
}

// JNI接口：获取当前设置的应用名称
extern "C" JNIEXPORT jstring JNICALL
Java_load_tencent_lib_MainActivity_getAppNameNative(JNIEnv *env, jobject /* this */) {
    std::string appName = getAppName();
    return env->NewStringUTF(appName.c_str());
}

// JNI接口：获取Android系统中的真实应用名称
extern "C" JNIEXPORT jstring JNICALL
Java_load_tencent_lib_MainActivity_getRealAppNameNative(JNIEnv *env, jobject thiz) {
    try {
        // 获取Context
        jclass contextClass = env->FindClass("android/content/Context");
        if (contextClass == nullptr) {
            LOGE("getRealAppNameNative: 无法找到Context类");
            return env->NewStringUTF("Unknown");
        }
        
        // 获取PackageManager
        jmethodID getPackageManagerMethod = env->GetMethodID(contextClass, "getPackageManager", "()Landroid/content/pm/PackageManager;");
        if (getPackageManagerMethod == nullptr) {
            LOGE("getRealAppNameNative: 无法找到getPackageManager方法");
            env->DeleteLocalRef(contextClass);
            return env->NewStringUTF("Unknown");
        }
        
        jobject packageManager = env->CallObjectMethod(thiz, getPackageManagerMethod);
        if (packageManager == nullptr) {
            LOGE("getRealAppNameNative: 无法获取PackageManager");
            env->DeleteLocalRef(contextClass);
            return env->NewStringUTF("Unknown");
        }
        
        // 获取包名
        jmethodID getPackageNameMethod = env->GetMethodID(contextClass, "getPackageName", "()Ljava/lang/String;");
        if (getPackageNameMethod == nullptr) {
            LOGE("getRealAppNameNative: 无法找到getPackageName方法");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            return env->NewStringUTF("Unknown");
        }
        
        jstring packageName = (jstring)env->CallObjectMethod(thiz, getPackageNameMethod);
        if (packageName == nullptr) {
            LOGE("getRealAppNameNative: 无法获取包名");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            return env->NewStringUTF("Unknown");
        }
        
        // 获取ApplicationInfo
        jclass packageManagerClass = env->FindClass("android/content/pm/PackageManager");
        if (packageManagerClass == nullptr) {
            LOGE("getRealAppNameNative: 无法找到PackageManager类");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            return env->NewStringUTF("Unknown");
        }
        
        jmethodID getApplicationInfoMethod = env->GetMethodID(packageManagerClass, 
            "getApplicationInfo", "(Ljava/lang/String;I)Landroid/content/pm/ApplicationInfo;");
        if (getApplicationInfoMethod == nullptr) {
            LOGE("getRealAppNameNative: 无法找到getApplicationInfo方法");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            env->DeleteLocalRef(packageManagerClass);
            return env->NewStringUTF("Unknown");
        }
        
        jobject appInfo = env->CallObjectMethod(packageManager, getApplicationInfoMethod, packageName, 0);
        if (appInfo == nullptr) {
            LOGE("getRealAppNameNative: 无法获取ApplicationInfo");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            env->DeleteLocalRef(packageManagerClass);
            return env->NewStringUTF("Unknown");
        }
        
        // 获取应用标签（显示名称）
        jmethodID loadLabelMethod = env->GetMethodID(packageManagerClass, 
            "getApplicationLabel", "(Landroid/content/pm/ApplicationInfo;)Ljava/lang/CharSequence;");
        if (loadLabelMethod == nullptr) {
            LOGE("getRealAppNameNative: 无法找到getApplicationLabel方法");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            env->DeleteLocalRef(packageManagerClass);
            env->DeleteLocalRef(appInfo);
            return env->NewStringUTF("Unknown");
        }
        
        jobject appLabel = env->CallObjectMethod(packageManager, loadLabelMethod, appInfo);
        if (appLabel == nullptr) {
            LOGE("getRealAppNameNative: 无法获取应用标签");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            env->DeleteLocalRef(packageManagerClass);
            env->DeleteLocalRef(appInfo);
            return env->NewStringUTF("Unknown");
        }
        
        // 将CharSequence转换为String
        jclass charSequenceClass = env->FindClass("java/lang/CharSequence");
        if (charSequenceClass == nullptr) {
            LOGE("getRealAppNameNative: 无法找到CharSequence类");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            env->DeleteLocalRef(packageManagerClass);
            env->DeleteLocalRef(appInfo);
            env->DeleteLocalRef(appLabel);
            return env->NewStringUTF("Unknown");
        }
        
        jmethodID toStringMethod = env->GetMethodID(charSequenceClass, "toString", "()Ljava/lang/String;");
        if (toStringMethod == nullptr) {
            LOGE("getRealAppNameNative: 无法找到toString方法");
            env->DeleteLocalRef(contextClass);
            env->DeleteLocalRef(packageManager);
            env->DeleteLocalRef(packageName);
            env->DeleteLocalRef(packageManagerClass);
            env->DeleteLocalRef(appInfo);
            env->DeleteLocalRef(appLabel);
            env->DeleteLocalRef(charSequenceClass);
            return env->NewStringUTF("Unknown");
        }
        
        jstring appNameString = (jstring)env->CallObjectMethod(appLabel, toStringMethod);
        
        // 清理资源
        env->DeleteLocalRef(contextClass);
        env->DeleteLocalRef(packageManager);
        env->DeleteLocalRef(packageName);
        env->DeleteLocalRef(packageManagerClass);
        env->DeleteLocalRef(appInfo);
        env->DeleteLocalRef(appLabel);
        env->DeleteLocalRef(charSequenceClass);
        
        if (appNameString != nullptr) {
            const char* appNameStr = env->GetStringUTFChars(appNameString, nullptr);
            LOGI("getRealAppNameNative: 获取到应用名称: %s", appNameStr);
            
            // 自动设置到全局变量
            setAppName(std::string(appNameStr));
            env->ReleaseStringUTFChars(appNameString, appNameStr);
            
            return appNameString;
        }
        
    } catch (const std::exception& e) {
        LOGE("getRealAppNameNative: C++异常: %s", e.what());
    } catch (...) {
        LOGE("getRealAppNameNative: 未知异常");
    }
    
    return env->NewStringUTF("Unknown");
}

// JNI接口：获取应用包名
extern "C" JNIEXPORT jstring JNICALL
Java_load_tencent_lib_MainActivity_getPackageNameNative(JNIEnv *env, jobject thiz) {
    try {
        // 获取Context类
        jclass contextClass = env->FindClass("android/content/Context");
        if (contextClass == nullptr) {
            LOGE("getPackageNameNative: 无法找到Context类");
            return env->NewStringUTF("Unknown");
        }
        
        // 获取getPackageName方法
        jmethodID getPackageNameMethod = env->GetMethodID(contextClass, "getPackageName", "()Ljava/lang/String;");
        if (getPackageNameMethod == nullptr) {
            LOGE("getPackageNameNative: 无法找到getPackageName方法");
            env->DeleteLocalRef(contextClass);
            return env->NewStringUTF("Unknown");
        }
        
        // 调用getPackageName方法
        jstring packageName = (jstring)env->CallObjectMethod(thiz, getPackageNameMethod);
        
        env->DeleteLocalRef(contextClass);
        
        if (packageName != nullptr) {
            const char* packageNameStr = env->GetStringUTFChars(packageName, nullptr);
            LOGI("getPackageNameNative: 获取到包名: %s", packageNameStr);
            env->ReleaseStringUTFChars(packageName, packageNameStr);
            return packageName;
        }
        
    } catch (const std::exception& e) {
        LOGE("getPackageNameNative: C++异常: %s", e.what());
    } catch (...) {
        LOGE("getPackageNameNative: 未知异常");
    }
    
    return env->NewStringUTF("Unknown");
}

// JNI接口：app启动时自动初始化应用名称
extern "C" JNIEXPORT jboolean JNICALL
Java_load_tencent_lib_MainActivity_autoInitAppNameNative(JNIEnv *env, jobject thiz) {
    try {
        LOGI("🚀 app启动自动初始化名称开始...");
        autoInitAppName(env, thiz);
        LOGI("✅ app启动自动初始化名称完成");
        return JNI_TRUE;
    } catch (const std::exception& e) {
        LOGE("❌ app启动自动初始化名称失败 - C++异常: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("❌ app启动自动初始化名称失败 - 未知异常");
        return JNI_FALSE;
    }
}


