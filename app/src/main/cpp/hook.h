#ifndef HOOK_H
#define HOOK_H

#include <string>
#include <atomic>
#include <thread>

/**
 * 安装Hook函数 - 基于符号名（推荐方式）
 * @param moduleName 目标模块名称 (例如: "libMyGame.so")
 * @param symbolName 目标符号名称 (例如: "luaL_loadbuffer")
 * @return 是否安装成功
 */
bool installHookBySymbol(const std::string& moduleName, const std::string& symbolName);

/**
 * 安装Hook函数 - 基于偏移地址（兼容接口）
 * @param moduleName 目标模块名称 (例如: "libnative-lib.so")
 * @param offset 偏移地址 (例如: 0x865d)
 * @return 是否安装成功
 */
bool installHook(const std::string& moduleName, long offset);

/**
 * 多线程持续安装Hook函数，直到成功为止
 * @param moduleName 目标模块名称
 * @param offset 偏移地址
 * @param retryIntervalMs 重试间隔（毫秒）
 * @return 是否启动成功
 */
bool startContinuousHookInstall(const std::string& moduleName, long offset, int retryIntervalMs = 1000);

/**
 * 停止持续安装Hook的线程
 * @param moduleName 目标模块名称
 * @param offset 偏移地址
 */
void stopContinuousHookInstall(const std::string& moduleName, long offset);

/**
 * 停止所有持续安装Hook的线程
 */
void stopAllContinuousHookInstall();

/**
 * 检查是否有持续安装线程在运行
 * @param moduleName 目标模块名称
 * @param offset 偏移地址
 * @return 是否在运行
 */
bool isContinuousHookInstallRunning(const std::string& moduleName, long offset);

/**
 * 自动初始化Hook系统
 * 启动预定义的Hook任务
 */
void autoInitializeHooks();

/**
 * 应用退出时的清理函数
 * 停止所有持续Hook线程
 */
void cleanupHooksOnExit();

/**
 * 卸载Hook函数
 * @param moduleName 目标模块名称
 * @param offset 偏移地址
 * @return 是否卸载成功
 */
bool uninstallHook(const std::string& moduleName, long offset);

/**
 * 检查Hook状态
 * @param moduleName 目标模块名称
 * @param offset 偏移地址
 * @return Hook是否处于活动状态
 */
bool isHookActive(const std::string& moduleName, long offset);

/**
 * 获取当前Hook数量
 * @return 活动Hook的数量
 */
int getActiveHookCount();

/**
 * 列出所有Hook状态（用于调试）
 */
void listAllHooks();

#endif // HOOK_H 