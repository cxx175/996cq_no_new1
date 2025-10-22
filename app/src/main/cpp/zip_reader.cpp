#include "zip_reader.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <zlib.h>
#include <android/log.h>

#define LOG_TAG "LUA-print"

// 灵活的日志控制：支持Debug模式、Release模式（带日志）、Release模式（无日志）
#if defined(DEBUG_MODE) || defined(RELEASE_MODE)
// Debug模式或Release模式（启用日志） - 启用日志
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#elif defined(NDEBUG)
// Release模式（NDEBUG定义）- 禁用所有日志
#define LOGD(...) ((void)0)
#define LOGE(...) ((void)0)
#define LOGI(...) ((void)0)
#define LOGW(...) ((void)0)
#else
// 默认情况（开发环境） - 启用日志
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#endif

// CRC32 查找表
static const uint32_t crc32_table[256] = {
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
    0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
    0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
    0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
    0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
    0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
    0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
    0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
    0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
    0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
    0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
    0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
    0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
    0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
    0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
    0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
    0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
    0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
    0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
    0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
    0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
    0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

ZipReader::ZipReader() {
}

ZipReader::~ZipReader() {
    clear();
}

bool ZipReader::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        LOGE("无法打开文件: %s", filename.c_str());
        return false;
    }
    
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    data_.resize(size);
    if (!file.read(reinterpret_cast<char*>(data_.data()), size)) {
        LOGE("读取文件失败: %s", filename.c_str());
        return false;
    }
    
    return parseZipFile();
}

bool ZipReader::loadFromMemory(const uint8_t* data, size_t size) {
    if (!data || size == 0) {
        LOGE("无效的内存数据");
        return false;
    }
    
    data_.assign(data, data + size);
    return parseZipFile();
}

void ZipReader::setPassword(const std::string& password) {
    password_ = password;
}

bool ZipReader::parseZipFile() {
    if (data_.size() < sizeof(ZipEndOfCentralDir)) {
        LOGE("文件太小，不是有效的ZIP文件");
        return false;
    }
    
    ZipEndOfCentralDir eocd;
    if (!findEndOfCentralDir(eocd)) {
        LOGE("未找到中央目录结束记录");
        return false;
    }
    
    LOGD("找到中央目录: 条目数=%d, 偏移=%d, 大小=%d", 
         eocd.totalEntries, eocd.centralDirOffset, eocd.centralDirSize);
    
    if (!parseCentralDirectory(eocd)) {
        LOGE("解析中央目录失败");
        return false;
    }
    
    LOGD("成功解析ZIP文件, 共 %zu 个条目", entries_.size());
    return true;
}

bool ZipReader::findEndOfCentralDir(ZipEndOfCentralDir& eocd) {
    // 从文件末尾开始搜索
    size_t searchStart = data_.size() >= 65536 ? data_.size() - 65536 : 0;
    
    for (size_t i = data_.size() - sizeof(ZipEndOfCentralDir); i >= searchStart; --i) {
        uint32_t signature = readUint32(i);
        if (signature == ZIP_END_OF_CENTRAL_DIR_SIGNATURE) {
            std::memcpy(&eocd, data_.data() + i, sizeof(ZipEndOfCentralDir));
            LOGD("找到EOCD在偏移 %zu", i);
            return true;
        }
        if (i == 0) break; // 防止无符号下溢
    }
    
    return false;
}

bool ZipReader::parseCentralDirectory(const ZipEndOfCentralDir& eocd) {
    size_t offset = eocd.centralDirOffset;
    
    for (uint16_t i = 0; i < eocd.totalEntries; ++i) {
        if (offset + sizeof(ZipCentralDirHeader) > data_.size()) {
            LOGE("中央目录条目 %d 超出文件范围", i);
            return false;
        }
        
        ZipCentralDirHeader header;
        std::memcpy(&header, data_.data() + offset, sizeof(ZipCentralDirHeader));
        
        if (header.signature != ZIP_CENTRAL_DIRECTORY_SIGNATURE) {
            LOGE("无效的中央目录签名在条目 %d", i);
            return false;
        }
        
        offset += sizeof(ZipCentralDirHeader);
        
        // 读取文件名
        if (offset + header.filenameLength > data_.size()) {
            LOGE("文件名超出范围在条目 %d", i);
            return false;
        }
        
        std::string filename(reinterpret_cast<const char*>(data_.data() + offset), header.filenameLength);
        offset += header.filenameLength;
        
        // 跳过额外字段和注释
        offset += header.extraFieldLength + header.commentLength;
        
        // 创建条目
        ZipEntry entry;
        entry.filename = filename;
        entry.compressedSize = header.compressedSize;
        entry.uncompressedSize = header.uncompressedSize;
        entry.crc32 = header.crc32;
        entry.compressionMethod = header.compressionMethod;
        entry.localHeaderOffset = header.localHeaderOffset;
        entry.isDirectory = (filename.back() == '/');
        
        entries_[filename] = entry;
        
        // LOGD("解析条目: %s (压缩:%d, 原始:%d, 方法:%d)", 
            //  filename.c_str(), entry.compressedSize, entry.uncompressedSize, entry.compressionMethod);
    }
    
    return true;
}

bool ZipReader::parseLocalFileHeader(uint32_t offset, ZipLocalFileHeader& header, std::string& filename) {
    if (offset + sizeof(ZipLocalFileHeader) > data_.size()) {
        return false;
    }
    
    std::memcpy(&header, data_.data() + offset, sizeof(ZipLocalFileHeader));
    
    if (header.signature != ZIP_LOCAL_FILE_HEADER_SIGNATURE) {
        return false;
    }
    
    offset += sizeof(ZipLocalFileHeader);
    
    if (offset + header.filenameLength > data_.size()) {
        return false;
    }
    
    filename.assign(reinterpret_cast<const char*>(data_.data() + offset), header.filenameLength);
    
    return true;
}

std::vector<std::string> ZipReader::getEntryNames() const {
    std::vector<std::string> names;
    names.reserve(entries_.size());
    
    for (const auto& pair : entries_) {
        names.push_back(pair.first);
    }
    
    return names;
}

bool ZipReader::hasEntry(const std::string& filename) const {
    return entries_.find(filename) != entries_.end();
}

bool ZipReader::getEntryInfo(const std::string& filename, ZipEntry& entry) const {
    auto it = entries_.find(filename);
    if (it == entries_.end()) {
        return false;
    }
    
    entry = it->second;
    return true;
}

bool ZipReader::extractEntry(const std::string& filename, std::vector<uint8_t>& data) {
    auto it = entries_.find(filename);
    if (it == entries_.end()) {
        LOGE("条目不存在: %s", filename.c_str());
        return false;
    }
    
    const ZipEntry& entry = it->second;
    
    if (entry.isDirectory) {
        LOGE("不能提取目录: %s", filename.c_str());
        return false;
    }
    
    // 解析本地文件头
    ZipLocalFileHeader localHeader;
    std::string localFilename;
    if (!parseLocalFileHeader(entry.localHeaderOffset, localHeader, localFilename)) {
        LOGE("解析本地文件头失败: %s", filename.c_str());
        return false;
    }
    
    // 计算数据偏移
    size_t dataOffset = entry.localHeaderOffset + sizeof(ZipLocalFileHeader) + 
                       localHeader.filenameLength + localHeader.extraFieldLength;
    
    if (dataOffset + entry.compressedSize > data_.size()) {
        LOGE("文件数据超出范围: %s", filename.c_str());
        return false;
    }
    
    // 提取压缩数据
    std::vector<uint8_t> compressedData(data_.begin() + dataOffset, 
                                       data_.begin() + dataOffset + entry.compressedSize);
    
    // 检查是否加密
    if ((localHeader.flags & 0x1) != 0) {
        if (password_.empty()) {
            LOGE("文件已加密但未提供密码: %s", filename.c_str());
            return false;
        }
        
        // 解密数据（传统ZIP加密）
        compressedData = decryptTraditionalZip(compressedData, password_);
        if (compressedData.empty()) {
            LOGE("解密失败: %s", filename.c_str());
            return false;
        }
    }
    
    // 解压缩数据
    data = decompressData(compressedData, entry.uncompressedSize, entry.compressionMethod);
    
    if (data.empty()) {
        LOGE("解压缩失败: %s", filename.c_str());
        return false;
    }
    
    // 验证CRC32
    uint32_t calculatedCRC = calculateCRC32(data);
    if (calculatedCRC != entry.crc32) {
        LOGE("CRC32校验失败: %s (期望:%08x, 实际:%08x)", 
             filename.c_str(), entry.crc32, calculatedCRC);
        return false;
    }
    
    // LOGD("成功提取文件: %s (%zu 字节)", filename.c_str(), data.size());
    return true;
}

bool ZipReader::extractEntryAsString(const std::string& filename, std::string& content) {
    std::vector<uint8_t> data;
    if (!extractEntry(filename, data)) {
        return false;
    }
    
    content.assign(reinterpret_cast<const char*>(data.data()), data.size());
    return true;
}

std::vector<uint8_t> ZipReader::decompressData(const std::vector<uint8_t>& compressedData, 
                                               uint32_t uncompressedSize, uint16_t method) {
    switch (method) {
        case ZIP_STORED:
            return compressedData; // 无压缩，直接返回
            
        case ZIP_DEFLATE:
            return inflateData(compressedData, uncompressedSize);
            
        default:
            LOGE("不支持的压缩方法: %d", method);
            return std::vector<uint8_t>();
    }
}

std::vector<uint8_t> ZipReader::inflateData(const std::vector<uint8_t>& compressedData, uint32_t uncompressedSize) {
    std::vector<uint8_t> result(uncompressedSize);
    
    z_stream stream = {};
    stream.next_in = const_cast<Bytef*>(compressedData.data());
    stream.avail_in = compressedData.size();
    stream.next_out = result.data();
    stream.avail_out = uncompressedSize;
    
    // 使用原始DEFLATE格式（ZIP使用的格式）
    int ret = inflateInit2(&stream, -MAX_WBITS);
    if (ret != Z_OK) {
        LOGE("inflateInit2 失败: %d", ret);
        return std::vector<uint8_t>();
    }
    
    ret = inflate(&stream, Z_FINISH);
    inflateEnd(&stream);
    
    if (ret != Z_STREAM_END) {
        LOGE("inflate 失败: %d", ret);
        return std::vector<uint8_t>();
    }
    
    if (stream.total_out != uncompressedSize) {
        LOGE("解压缩大小不匹配: 期望 %d, 实际 %lu", uncompressedSize, stream.total_out);
        return std::vector<uint8_t>();
    }
    
    return result;
}

uint32_t ZipReader::calculateCRC32(const std::vector<uint8_t>& data) {
    uint32_t crc = 0xFFFFFFFF;
    
    for (uint8_t byte : data) {
        crc = crc32_table[(crc ^ byte) & 0xFF] ^ (crc >> 8);
    }
    
    return crc ^ 0xFFFFFFFF;
}

std::vector<uint8_t> ZipReader::decryptTraditionalZip(const std::vector<uint8_t>& encryptedData, const std::string& password) {
    // 传统ZIP加密的正确实现
    
    if (encryptedData.size() < 12) {
        LOGE("加密数据太短: %zu 字节", encryptedData.size());
        return std::vector<uint8_t>();
    }
    
    // LOGD("开始解密ZIP数据，大小: %zu 字节", encryptedData.size());
    
    // 初始化密钥 - 使用标准的传统ZIP加密初始值
    uint32_t key0 = 0x12345678;
    uint32_t key1 = 0x23456789;
    uint32_t key2 = 0x34567890;
    
    // 密钥更新函数
    auto updateKeys = [&](uint8_t c) {
        key0 = crc32_table[(key0 ^ c) & 0xFF] ^ (key0 >> 8);
        key1 = (key1 + (key0 & 0xFF)) * 134775813 + 1;
        key2 = crc32_table[(key2 ^ (key1 >> 24)) & 0xFF] ^ (key2 >> 8);
    };
    
    // 解密字节函数
    auto decryptByte = [&]() {
        uint16_t temp = (key2 | 2);
        return (uint8_t)((temp * (temp ^ 1)) >> 8);
    };
    
    // 使用密码初始化密钥
    for (size_t i = 0; i < password.length(); ++i) {
        updateKeys(static_cast<uint8_t>(password[i]));
    }
    
    // LOGD("密钥初始化完成: key0=%08x, key1=%08x, key2=%08x", key0, key1, key2);
    
    // 解密前12字节的加密头
    std::vector<uint8_t> decryptedHeader;
    for (int i = 0; i < 12; ++i) {
        uint8_t decrypted = encryptedData[i] ^ decryptByte();
        decryptedHeader.push_back(decrypted);
        updateKeys(decrypted);
    }
    
    // 验证解密头部的正确性
    // 在传统ZIP加密中，最后一个字节或倒数第二个字节应该匹配CRC32的高字节
    // 这里我们简单检查解密是否产生了合理的数据
    // LOGD("解密头部: %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x", 
    //      decryptedHeader[0], decryptedHeader[1], decryptedHeader[2], decryptedHeader[3],
    //      decryptedHeader[4], decryptedHeader[5], decryptedHeader[6], decryptedHeader[7],
    //      decryptedHeader[8], decryptedHeader[9], decryptedHeader[10], decryptedHeader[11]);
    
    // 解密实际数据
    std::vector<uint8_t> result;
    result.reserve(encryptedData.size() - 12);
    
    for (size_t i = 12; i < encryptedData.size(); ++i) {
        uint8_t decrypted = encryptedData[i] ^ decryptByte();
        result.push_back(decrypted);
        updateKeys(decrypted);
    }
    
    // LOGD("解密完成，解密数据大小: %zu 字节", result.size());
    
    // 输出前几个字节以便调试
    // if (result.size() >= 10) {
    //     LOGD("解密数据前10字节: %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x", 
    //          result[0], result[1], result[2], result[3], result[4],
    //          result[5], result[6], result[7], result[8], result[9]);
    // }
    
    return result;
}

bool ZipReader::isPasswordProtected(const ZipEntry& entry) const {
    ZipLocalFileHeader localHeader;
    std::string localFilename;
    if (!const_cast<ZipReader*>(this)->parseLocalFileHeader(entry.localHeaderOffset, localHeader, localFilename)) {
        return false;
    }
    
    return (localHeader.flags & 0x1) != 0;
}

bool ZipReader::isEncrypted() const {
    for (const auto& pair : entries_) {
        if (isPasswordProtected(pair.second)) {
            return true;
        }
    }
    return false;
}

uint16_t ZipReader::readUint16(size_t offset) const {
    if (offset + 1 >= data_.size()) {
        return 0;
    }
    return data_[offset] | (data_[offset + 1] << 8);
}

uint32_t ZipReader::readUint32(size_t offset) const {
    if (offset + 3 >= data_.size()) {
        return 0;
    }
    return data_[offset] | (data_[offset + 1] << 8) | 
           (data_[offset + 2] << 16) | (data_[offset + 3] << 24);
}

void ZipReader::clear() {
    data_.clear();
    entries_.clear();
    password_.clear();
} 