//
//  KittyMemory.cpp
//
//  Created by MJ (Ruit) on 1/1/19.
//

#include <Includes/obfuscate.h>
#include "KittyMemory.h"

using KittyMemory::Memory_Status;
using KittyMemory::ProcMap;


struct mapsCache {
    std::string identifier;
    ProcMap map;
};

static std::vector<mapsCache> __mapsCache;
static ProcMap findMapInCache(std::string id){
    ProcMap ret;
    for(int i = 0; i < __mapsCache.size(); i++){
        if(__mapsCache[i].identifier.compare(id) == 0){
            ret = __mapsCache[i].map;
            break;
        }
    }
    return ret;
}


bool KittyMemory::ProtectAddr(void *addr, size_t length, int protection) {
   uintptr_t pageStart = _PAGE_START_OF_(addr);
   uintptr_t pageLen   = _PAGE_LEN_OF_(addr, length);
   return (
     mprotect(reinterpret_cast<void *>(pageStart), pageLen, protection) != -1
 );
}


Memory_Status KittyMemory::memWrite(void *addr, const void *buffer, size_t len) {
    if (addr == NULL)
        return INV_ADDR;

    if (buffer == NULL)
        return INV_BUF;

    if (len < 1 || len > INT_MAX)
        return INV_LEN;

    if (!ProtectAddr(addr, len, _PROT_RWX_))
        return INV_PROT;

    if (memcpy(addr, buffer, len) != NULL && ProtectAddr(addr, len, _PROT_RX_))
        return SUCCESS;

    return FAILED;
}


Memory_Status KittyMemory::memRead(void *buffer, const void *addr, size_t len) {
    if (addr == NULL)
        return INV_ADDR;

    if (buffer == NULL)
        return INV_BUF;

    if (len < 1 || len > INT_MAX)
        return INV_LEN;

    if (memcpy(buffer, addr, len) != NULL)
        return SUCCESS;

    return FAILED;
}


std::string KittyMemory::read2HexStr(const void *addr, size_t len) {
    char temp[len];
    memset(temp, 0, len);

    const size_t bufferLen = len * 2 + 1;
    char buffer[bufferLen];
    memset(buffer, 0, bufferLen);

    std::string ret;

    if (memRead(temp, addr, len) != SUCCESS)
        return ret;

    for (int i = 0; i < len; i++) {
        sprintf(&buffer[i * 2], "%02X", (unsigned char) temp[i]);
    }

    ret += buffer;
    return ret;
}

ProcMap KittyMemory::getLibraryMap(const char *libraryName) {
    ProcMap retMap;
    char line[512] = {0};

    FILE *fp = fopen(OBFUSCATE("/proc/self/maps"), OBFUSCATE("rt"));
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, libraryName)) {
                char tmpPerms[5] = {0}, tmpDev[12] = {0}, tmpPathname[444] = {0};
                
                // 🚨 Houdini兼容性修复：安全的sscanf调用
                // 清空所有变量避免未初始化的内存
                memset(&retMap, 0, sizeof(retMap));
                memset(tmpPerms, 0, sizeof(tmpPerms));
                memset(tmpDev, 0, sizeof(tmpDev));
                memset(tmpPathname, 0, sizeof(tmpPathname));
                
                // 验证输入行的长度和格式
                size_t line_len = strlen(line);
                if (line_len < 20 || line_len > sizeof(line) - 1) {
                    continue; // 跳过格式异常的行
                }
                
                // 🛡️ 使用更安全的方式解析maps文件
                // 分步解析，避免在Houdini中触发sscanf崩溃
                char *saveptr = NULL;
                char *token = strtok_r(line, " ", &saveptr);
                int field_count = 0;
                
                while (token != NULL && field_count < 7) {
                    switch (field_count) {
                        case 0: // 地址范围 startAddr-endAddr
                            {
                                char *dash_pos = strchr(token, '-');
                                if (dash_pos) {
                                    *dash_pos = '\0';
                                    // 使用更安全的转换方式
                                    retMap.startAddr = (void*)strtoull(token, NULL, 16);
                                    retMap.endAddr = (void*)strtoull(dash_pos + 1, NULL, 16);
                                }
                            }
                            break;
                        case 1: // 权限 perms
                            strncpy(tmpPerms, token, sizeof(tmpPerms) - 1);
                            break;
                        case 2: // 偏移 offset
                            retMap.offset = strtol(token, NULL, 16);
                            break;
                        case 3: // 设备 dev
                            strncpy(tmpDev, token, sizeof(tmpDev) - 1);
                            break;
                        case 4: // inode
                            retMap.inode = atoi(token);
                            break;
                        case 5: // pathname (可能包含空格)
                            {
                                // 获取剩余的所有内容作为路径名
                                char *remaining = token;
                                if (remaining) {
                                    // 移除末尾的换行符
                                    char *newline = strchr(remaining, '\n');
                                    if (newline) *newline = '\0';
                                    strncpy(tmpPathname, remaining, sizeof(tmpPathname) - 1);
                                }
                            }
                            break;
                    }
                    
                    if (field_count == 5) break; // 已获取所有需要的字段
                    token = strtok_r(NULL, " ", &saveptr);
                    field_count++;
                }
                
                // 验证解析结果的有效性
                if (retMap.startAddr != 0 && retMap.endAddr != 0 && retMap.endAddr > retMap.startAddr) {
                    retMap.length = (uintptr_t) retMap.endAddr - (uintptr_t) retMap.startAddr;
                    retMap.perms = tmpPerms;
                    retMap.dev = tmpDev;
                    retMap.pathname = tmpPathname;

                    break;
                }
            }
        }
        fclose(fp);
    }
    return retMap;
}

uintptr_t KittyMemory::getAbsoluteAddress(const char *libraryName, uintptr_t relativeAddr, bool useCache) {
    ProcMap libMap;

    if(useCache){
        libMap = findMapInCache(libraryName);
        if(libMap.isValid())
        return (reinterpret_cast<uintptr_t>(libMap.startAddr) + relativeAddr);
    }

    libMap = getLibraryMap(libraryName);
    if (!libMap.isValid())
        return 0;

    if(useCache){
        mapsCache cachedMap;
        cachedMap.identifier = libraryName;
        cachedMap.map        = libMap;
        __mapsCache.push_back(cachedMap);
    }

    return (reinterpret_cast<uintptr_t>(libMap.startAddr) + relativeAddr);
}
