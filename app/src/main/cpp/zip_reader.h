#ifndef ZIP_READER_H
#define ZIP_READER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cstdint>

// ZIP 文件格式相关常量
#define ZIP_LOCAL_FILE_HEADER_SIGNATURE 0x04034b50
#define ZIP_CENTRAL_DIRECTORY_SIGNATURE 0x02014b50
#define ZIP_END_OF_CENTRAL_DIR_SIGNATURE 0x06054b50

// ZIP 压缩方法
#define ZIP_STORED 0    // 无压缩
#define ZIP_DEFLATE 8   // DEFLATE压缩

// ZIP 文件条目信息
struct ZipEntry {
    std::string filename;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint32_t crc32;
    uint16_t compressionMethod;
    uint32_t localHeaderOffset;
    bool isDirectory;
    
    ZipEntry() : compressedSize(0), uncompressedSize(0), crc32(0), 
                 compressionMethod(0), localHeaderOffset(0), isDirectory(false) {}
};

// ZIP 本地文件头结构
#pragma pack(push, 1)
struct ZipLocalFileHeader {
    uint32_t signature;
    uint16_t version;
    uint16_t flags;
    uint16_t compressionMethod;
    uint16_t modTime;
    uint16_t modDate;
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint16_t filenameLength;
    uint16_t extraFieldLength;
};

// ZIP 中央目录记录结构
struct ZipCentralDirHeader {
    uint32_t signature;
    uint16_t versionMadeBy;
    uint16_t versionNeeded;
    uint16_t flags;
    uint16_t compressionMethod;
    uint16_t modTime;
    uint16_t modDate;
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint16_t filenameLength;
    uint16_t extraFieldLength;
    uint16_t commentLength;
    uint16_t diskNumber;
    uint16_t internalFileAttr;
    uint32_t externalFileAttr;
    uint32_t localHeaderOffset;
};

// ZIP 目录结束记录结构
struct ZipEndOfCentralDir {
    uint32_t signature;
    uint16_t diskNumber;
    uint16_t centralDirStartDisk;
    uint16_t numEntriesOnDisk;
    uint16_t totalEntries;
    uint32_t centralDirSize;
    uint32_t centralDirOffset;
    uint16_t commentLength;
};
#pragma pack(pop)

// ZIP 文件读取器类
class ZipReader {
private:
    std::vector<uint8_t> data_;
    std::map<std::string, ZipEntry> entries_;
    std::string password_;
    
    bool parseZipFile();
    bool findEndOfCentralDir(ZipEndOfCentralDir& eocd);
    bool parseCentralDirectory(const ZipEndOfCentralDir& eocd);
    bool parseLocalFileHeader(uint32_t offset, ZipLocalFileHeader& header, std::string& filename);
    
    // 密码相关函数
    bool isPasswordProtected(const ZipEntry& entry) const;
    std::vector<uint8_t> decryptTraditionalZip(const std::vector<uint8_t>& encryptedData, const std::string& password);
    
    // 解压缩函数
    std::vector<uint8_t> decompressData(const std::vector<uint8_t>& compressedData, uint32_t uncompressedSize, uint16_t method);
    std::vector<uint8_t> inflateData(const std::vector<uint8_t>& compressedData, uint32_t uncompressedSize);
    
    // CRC32 校验
    uint32_t calculateCRC32(const std::vector<uint8_t>& data);
    
    // 工具函数
    uint16_t readUint16(size_t offset) const;
    uint32_t readUint32(size_t offset) const;
    
public:
    ZipReader();
    ~ZipReader();
    
    // 从文件加载 ZIP
    bool loadFromFile(const std::string& filename);
    
    // 从内存加载 ZIP
    bool loadFromMemory(const uint8_t* data, size_t size);
    
    // 设置密码
    void setPassword(const std::string& password);
    
    // 获取所有条目
    std::vector<std::string> getEntryNames() const;
    
    // 检查条目是否存在
    bool hasEntry(const std::string& filename) const;
    
    // 获取条目信息
    bool getEntryInfo(const std::string& filename, ZipEntry& entry) const;
    
    // 提取文件数据
    bool extractEntry(const std::string& filename, std::vector<uint8_t>& data);
    
    // 提取文件数据为字符串
    bool extractEntryAsString(const std::string& filename, std::string& content);
    
    // 检查是否为加密的 ZIP
    bool isEncrypted() const;
    
    // 清理资源
    void clear();
};

#endif // ZIP_READER_H 