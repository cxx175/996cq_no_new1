#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
头文件字符串加密工具
用于在编译时加密app_strings.h中的字符串常量

🔒 线程安全性改进 v2.0
====================

### 🚨 原始问题
之前的解密函数存在严重的线程安全问题：
1. 全局共享的静态内存池 `static char string_pool[65536]`
2. 全局共享的偏移量 `static int pool_offset = 0`
3. 全局的volatile标志 `static volatile bool decryption_initialized`

这导致了以下风险：
- 数据竞争：多个线程同时修改pool_offset
- 内存覆盖：线程A复制字符串时，线程B可能修改偏移量
- 返回无效指针：内存池可能被后续调用覆盖

### ✅ 解决方案
使用C++11的thread_local存储类说明符实现线程安全：

```cpp
// 每个线程独立的内存池和状态
thread_local static char string_pool[65536];
thread_local static int pool_offset = 0;
thread_local static bool pool_initialized = false;
thread_local static bool decryption_initialized = false;
```

### 🎯 改进效果
1. **完全线程安全**：每个线程拥有独立的内存池
2. **零性能开销**：无需互斥锁或原子操作
3. **内存循环使用**：内存池满时自动重置
4. **向后兼容**：API保持不变

### 🧪 测试方法
运行线程安全测试：
```bash
python encrypt_header.py --strings strings.txt --output app_strings.h --mode release --test-thread-safety
```

### 📋 技术要求
- C++11或更高版本编译器
- 支持thread_local关键字
- 多线程环境下的应用程序
"""

import os
import sys
import re
import base64
import hashlib
from typing import Dict, List, Tuple
import argparse
import errno

class HeaderEncryptor:
    def __init__(self, key: str = "996CQ_ENCRYPT_KEY_2024"):
        self.key = key.encode('utf-8')
        self.encrypted_strings: Dict[str, str] = {}
        
    def simple_xor_encrypt(self, text: str) -> str:
        """简单XOR加密"""
        if not text:
            return ""
            
        # 将文本转换为字节
        text_bytes = text.encode('utf-8')
        key_bytes = self.key
        
        # XOR加密
        encrypted = bytearray()
        for i, byte in enumerate(text_bytes):
            key_byte = key_bytes[i % len(key_bytes)]
            encrypted.append(byte ^ key_byte)
            
        # 转换为base64字符串
        return base64.b64encode(encrypted).decode('ascii')
    
    def generate_decrypt_function(self) -> str:
        """生成解密函数"""
        key_array = ', '.join([f'0x{b:02x}' for b in self.key])
        
        decrypt_func = f'''// 解密函数
static const unsigned char DECRYPT_KEY[] = {{{key_array}}};
static const int DECRYPT_KEY_LEN = {len(self.key)};

// 安全的内存分配函数
static void* safe_malloc(size_t size) {{
    if (size == 0 || size > 1024 * 1024) {{  // 限制最大1MB
        return nullptr;
    }}
    try {{
        return malloc(size);
    }} catch (...) {{
        return nullptr;
    }}
}}

// 处理转义字符的函数
static char* process_escape_sequences(const char* input) {{
    if (!input) return nullptr;
    
    int len = strlen(input);
    char* output = (char*)safe_malloc(len + 1);
    if (!output) return nullptr;
    
    int i = 0, j = 0;
    while (i < len) {{
        if (input[i] == '\\\\' && i + 1 < len) {{
            // 处理转义字符
            switch (input[i + 1]) {{
                case 'n':
                    output[j++] = '\\n';  // 换行符
                    i += 2;
                    break;
                case 't':
                    output[j++] = '\\t';  // 制表符
                    i += 2;
                    break;
                case 'r':
                    output[j++] = '\\r';  // 回车符
                    i += 2;
                    break;
                case '\\\\':
                    output[j++] = '\\\\';  // 反斜杠
                    i += 2;
                    break;
                case '"':
                    output[j++] = '"';   // 双引号
                    i += 2;
                    break;
                case '\\\'':
                    output[j++] = '\\\''; // 单引号
                    i += 2;
                    break;
                default:
                    // 不是已知的转义字符，保持原样
                    output[j++] = input[i++];
                    break;
            }}
        }} else {{
            output[j++] = input[i++];
        }}
    }}
    output[j] = '\\0';
    return output;
}}

static char* decrypt_string(const char* encrypted_base64) {{
    if (!encrypted_base64) {{
        return nullptr;
    }}
    
    // 🚨 线程安全修复：使用线程局部存储替代全局volatile标志
    thread_local static bool decryption_initialized = false;
    
    // 简单的初始化检查（每个线程独立初始化）
    if (!decryption_initialized) {{
        decryption_initialized = true;
    }}
    
    // Base64解码
    int len = strlen(encrypted_base64);
    if (len == 0 || len > 10240) {{  // 限制输入长度
        return nullptr;
    }}
    
    // 检查长度是否合理（Base64字符串长度应该是4的倍数）
    if (len % 4 != 0) {{
        return nullptr;
    }}
    
    // 计算填充字符数量
    int padding = 0;
    if (len >= 2) {{
        if (encrypted_base64[len-1] == '=') padding++;
        if (encrypted_base64[len-2] == '=') padding++;
    }}
    
    // 计算解码后的长度
    int decoded_len = (len * 3) / 4 - padding;
    
    // 安全检查：确保解码长度合理
    if (decoded_len <= 0 || decoded_len > 8192) {{  // 限制最大8KB
        return nullptr;
    }}
    
    unsigned char* decoded = (unsigned char*)safe_malloc(decoded_len + 1);
    if (!decoded) {{
        return nullptr;
    }}
    
    // 初始化内存
    memset(decoded, 0, decoded_len + 1);
    
    // Base64字符表
    const char* base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    int i = 0, j = 0;
    int decoded_pos = 0;
    unsigned char char_array_4[4], char_array_3[3];
    
    // 初始化数组
    memset(char_array_4, 0, sizeof(char_array_4));
    memset(char_array_3, 0, sizeof(char_array_3));
    
    while (i < len && encrypted_base64[i] != '=' && decoded_pos < decoded_len) {{
        const char* pos = strchr(base64_chars, encrypted_base64[i]);
        if (!pos) {{
            free(decoded);
            return nullptr;
        }}
        char_array_4[j++] = pos - base64_chars;
        i++;
        
        if (j == 4) {{
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
            
            for (int k = 0; k < 3 && decoded_pos < decoded_len; k++) {{
                decoded[decoded_pos++] = char_array_3[k];
            }}
            j = 0;
        }}
    }}
    
    // 处理剩余的字符
    if (j > 0 && decoded_pos < decoded_len) {{
        for (int k = j; k < 4; k++) {{
            char_array_4[k] = 0;
        }}
        
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
        
        for (int k = 0; k < j - 1 && decoded_pos < decoded_len; k++) {{
            decoded[decoded_pos++] = char_array_3[k];
        }}
    }}
    
    // XOR解密
    try {{
        for (int k = 0; k < decoded_pos; k++) {{
            decoded[k] ^= DECRYPT_KEY[k % DECRYPT_KEY_LEN];
        }}
    }} catch (...) {{
        free(decoded);
        return nullptr;
    }}
    
    decoded[decoded_pos] = '\\0';
    
    // 处理转义字符
    char* processed = process_escape_sequences((char*)decoded);
    free(decoded);
    
    return processed;
}}

// 简化的解密函数，使用线程安全的实现
static const char* get_decrypted_string(const char* encrypted_base64) {{
    // 添加空指针检查
    if (!encrypted_base64) {{
        return "";
    }}
    
    // 🚨 线程安全修复：使用线程局部存储
    thread_local static char string_pool[65536];  // 每个线程独立的内存池
    thread_local static int pool_offset = 0;      // 每个线程独立的偏移量
    thread_local static bool pool_initialized = false;
    
    // 线程局部初始化
    if (!pool_initialized) {{
        memset(string_pool, 0, sizeof(string_pool));
        pool_offset = 0;
        pool_initialized = true;
    }}
    
    // 直接解密
    char* decrypted = decrypt_string(encrypted_base64);
    if (decrypted) {{
        int len = strlen(decrypted);
        
        // 检查内存池空间，如果不足则重置（循环使用）
        if (pool_offset + len + 1 >= sizeof(string_pool)) {{
            pool_offset = 0;  // 重置偏移量，循环使用内存池
        }}
        
        // 安全复制字符串
        if (pool_offset + len + 1 < sizeof(string_pool)) {{
            char* result = string_pool + pool_offset;
            strcpy(result, decrypted);
            pool_offset += len + 1;
            free(decrypted);
            return result;
        }}
        
        free(decrypted);
    }}
    
    return "";
}}'''
        
        return decrypt_func
    
    def process_header_file(self, input_file: str, output_file: str) -> bool:
        """处理头文件，加密字符串常量"""
        try:
            with open(input_file, 'r', encoding='utf-8') as f:
                content = f.read()
                
            # 查找所有#define字符串常量
            define_pattern = r'#define\s+(\w+)\s+"([^"]*?)"'
            matches = re.findall(define_pattern, content)
            
            print(f"找到 {len(matches)} 个字符串常量需要加密")
            
            # 生成加密后的内容
            encrypted_content = self.generate_encrypted_header(content, matches)
            
            # 确保输出目录存在
            os.makedirs(os.path.dirname(output_file), exist_ok=True)
            
            # 写入加密后的文件
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write(encrypted_content)
                
            print(f"加密头文件已生成: {output_file}")
            return True
            
        except Exception as e:
            print(f"处理头文件时出错: {e}")
            return False
    
    def generate_encrypted_header(self, original_content: str, string_defines: List[Tuple[str, str]]) -> str:
        """生成加密后的头文件内容"""
        lines = original_content.split('\n')
        encrypted_lines = []
        
        # 添加必要的头文件
        encrypted_lines.extend([
            "#ifndef APP_STRINGS_ENCRYPTED_H",
            "#define APP_STRINGS_ENCRYPTED_H",
            "",
            "#include <cstring>",
            "#include <cstdlib>",
            "",
            "#ifdef __cplusplus",
            "#include <string>",
            "#endif",
            ""
        ])
        
        # 添加解密函数
        encrypted_lines.append(self.generate_decrypt_function())
        encrypted_lines.append("")
        
        # 条件编译：加密分支
        encrypted_lines.append("#ifdef USE_ENCRYPTED_STRINGS")
        for line in lines:
            line = line.strip()
            # 跳过原始的头文件保护和包含
            if (line.startswith('#ifndef APP_STRINGS_H') or 
                line.startswith('#define APP_STRINGS_H') or
                line.startswith('#include') or
                line.startswith('#ifdef __cplusplus') or
                line.startswith('extern "C"') or
                line.startswith('#endif // APP_STRINGS_H') or
                line.startswith('std::string getAppString') or
                line.startswith('const char* getAppString') or
                line.startswith('// 声明获取字符串的函数')):
                continue
            define_match = re.match(r'#define\s+(\w+)\s+"([^"]*?)"', line)
            if define_match:
                const_name = define_match.group(1)
                const_value = define_match.group(2)
                # 加密字符串
                encrypted_value = self.simple_xor_encrypt(const_value)
                self.encrypted_strings[const_name] = encrypted_value
                # 生成加密常量定义
                encrypted_lines.append(f'#define ENCRYPTED_{const_name} "{encrypted_value}"')
                encrypted_lines.append(f'#define {const_name} get_decrypted_string(ENCRYPTED_{const_name})')
                print(f"  加密: {const_name} = \"{const_value}\" -> {encrypted_value[:20]}...")
        # 明文分支
        encrypted_lines.append("#else")
        for line in lines:
            line = line.strip()
            define_match = re.match(r'#define\s+(\w+)\s+"([^"]*?)"', line)
            if define_match:
                const_name = define_match.group(1)
                const_value = define_match.group(2)
                encrypted_lines.append(f'#define {const_name} "{const_value}"')
        encrypted_lines.append("#endif")
        
        # C接口声明
        encrypted_lines.extend([
            "",
            "#ifdef __cplusplus",
            "extern \"C\" {",
            "#endif",
            "// 字符串获取函数声明 (C接口)",
            "const char* getAppString(const char* key);",
            "#ifdef __cplusplus",
            "}",
            "#endif",
            ""
        ])
        
        # C++专用声明
        encrypted_lines.extend([
            "#ifdef __cplusplus",
            "// 声明获取字符串的函数 (C++接口)",
            "std::string getAppString(const std::string& key);",
            "#endif",
            ""
        ])
        
        # 头文件结尾
        encrypted_lines.append("#endif // APP_STRINGS_ENCRYPTED_H")
        
        return '\n'.join(encrypted_lines)

    def read_strings_file(self, strings_file: str) -> List[Tuple[str, str]]:
        result = []
        with open(strings_file, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith('#'):
                    continue
                if '=' in line:
                    key, value = line.split('=', 1)
                    result.append((key.strip(), value.strip()))
        return result

    def generate_plain_header(self, string_defines: List[Tuple[str, str]]) -> str:
        lines = [
            "#ifndef APP_STRINGS_H",
            "#define APP_STRINGS_H",
            "",
            "#ifdef __cplusplus",
            "#include <string>",
            "#endif",
            ""
        ]
        for key, value in string_defines:
            lines.append(f'#define {key} "{value}"')
        lines.append("")
        # 添加C/C++声明，与加密分支一致
        lines.extend([
            "#ifdef __cplusplus",
            "extern \"C\" {",
            "#endif",
            "// 字符串获取函数声明 (C接口)",
            "const char* getAppString(const char* key);",
            "#ifdef __cplusplus",
            "}",
            "#endif",
            ""
        ])
        lines.extend([
            "#ifdef __cplusplus",
            "// 声明获取字符串的函数 (C++接口)",
            "std::string getAppString(const std::string& key);",
            "#endif",
            ""
        ])
        lines.append("#endif // APP_STRINGS_H")
        return '\n'.join(lines)

    def generate_encrypted_header_from_list(self, string_defines: List[Tuple[str, str]]) -> str:
        lines = [
            "#ifndef APP_STRINGS_H",
            "#define APP_STRINGS_H",
            "",
            "#include <cstring>",
            "#include <cstdlib>",
            "",
            "#ifdef __cplusplus",
            "#include <string>",
            "#endif",
            ""
        ]
        lines.append(self.generate_decrypt_function())
        lines.append("")
        # 只生成加密分支
        for const_name, const_value in string_defines:
            encrypted_value = self.simple_xor_encrypt(const_value)
            self.encrypted_strings[const_name] = encrypted_value
            lines.append(f'#define ENCRYPTED_{const_name} "{encrypted_value}"')
            lines.append(f'#define {const_name} get_decrypted_string(ENCRYPTED_{const_name})')
        lines.append("")
        lines.extend([
            "#ifdef __cplusplus",
            "extern \"C\" {",
            "#endif",
            "// 字符串获取函数声明 (C接口)",
            "const char* getAppString(const char* key);",
            "#ifdef __cplusplus",
            "}",
            "#endif",
            ""
        ])
        lines.extend([
            "#ifdef __cplusplus",
            "// 声明获取字符串的函数 (C++接口)",
            "std::string getAppString(const std::string& key);",
            "#endif",
            ""
        ])
        lines.append("#endif // APP_STRINGS_H")
        return '\n'.join(lines)

    def test_encrypt_decrypt(self, test_string: str) -> bool:
        """测试加密解密过程"""
        print(f"测试字符串: '{test_string}'")
        
        # 加密
        encrypted = self.simple_xor_encrypt(test_string)
        print(f"加密后: {encrypted}")
        
        # 手动解密验证（Python版本）
        try:
            import base64
            decoded_bytes = base64.b64decode(encrypted)
            decrypted_bytes = bytearray()
            for i, byte in enumerate(decoded_bytes):
                key_byte = self.key[i % len(self.key)]
                decrypted_bytes.append(byte ^ key_byte)
            decrypted = decrypted_bytes.decode('utf-8')
            print(f"解密后: '{decrypted}'")
            
            if decrypted == test_string:
                print("[OK] 加密解密测试通过")
                return True
            else:
                print("[FAIL] 加密解密测试失败")
                return False
        except Exception as e:
            print(f"[ERROR] 测试过程出错: {e}")
            return False

def main():
    parser = argparse.ArgumentParser(description="头文件字符串加密工具")
    parser.add_argument('--strings', required=True, help='字符串数据文件')
    parser.add_argument('--output', required=True, help='输出头文件')
    parser.add_argument('--mode', choices=['debug', 'release'], required=True, help='生成模式')
    parser.add_argument('--test', action='store_true', help='运行加密解密测试')
    parser.add_argument('--test-thread-safety', action='store_true', help='测试线程安全性（需要C++编译器）')
    args = parser.parse_args()

    if not os.path.exists(args.strings):
        print(f"错误: 字符串数据文件不存在: {args.strings}")
        sys.exit(1)

    strings = HeaderEncryptor().read_strings_file(args.strings)
    encryptor = HeaderEncryptor()
    
    # 运行测试
    if args.test:
        print("=== 运行加密解密测试 ===")
        test_cases = [
            "Hello World",
            "测试中文字符串",
            "Special chars: !@#$%^&*()",
            "",
            "A",
            "Very long string with many characters to test the encryption and decryption process thoroughly"
        ]
        
        all_passed = True
        for test_case in test_cases:
            if not encryptor.test_encrypt_decrypt(test_case):
                all_passed = False
            print()
        
        if all_passed:
            print("[OK] 所有测试通过")
        else:
            print("[FAIL] 部分测试失败")
            sys.exit(1)
    
    # 运行线程安全测试
    if args.test_thread_safety:
        print("=== 运行线程安全测试 ===")
        print("生成线程安全测试代码...")
        
        # 生成一个简单的C++测试程序
        test_code = '''
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <atomic>

''' + encryptor.generate_decrypt_function() + '''

// 测试函数
void test_thread_safety(int thread_id, std::atomic<int>& success_count, std::atomic<int>& fail_count) {
    const char* test_strings[] = {
        "dEBmMTQ5",  // 测试字符串1
        "Ulhb",      // 测试字符串2
        "UF0=",      // 测试字符串3
        "TVZdJj8=",  // 测试字符串4
        "VVhFNw42Kz42Jg==" // 测试字符串5
    };
    
    for (int i = 0; i < 1000; ++i) {
        for (const char* test_str : test_strings) {
            const char* result = get_decrypted_string(test_str);
            if (result && strlen(result) > 0) {
                success_count.fetch_add(1);
            } else {
                fail_count.fetch_add(1);
                std::cout << "Thread " << thread_id << " failed on iteration " << i << std::endl;
            }
        }
    }
}

int main() {
    const int num_threads = 8;
    const int iterations_per_thread = 1000;
    const int num_test_strings = 5;
    
    std::atomic<int> success_count{0};
    std::atomic<int> fail_count{0};
    
    std::vector<std::thread> threads;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    
    // 启动多个线程
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(test_thread_safety, i, std::ref(success_count), std::ref(fail_count));
    }
    
    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    int total_operations = num_threads * iterations_per_thread * num_test_strings;
    
    std::cout << "=== 线程安全测试结果 ===" << std::endl;
    std::cout << "线程数量: " << num_threads << std::endl;
    std::cout << "每线程迭代: " << iterations_per_thread << std::endl;
    std::cout << "总操作数: " << total_operations << std::endl;
    std::cout << "成功操作: " << success_count.load() << std::endl;
    std::cout << "失败操作: " << fail_count.load() << std::endl;
    std::cout << "成功率: " << (100.0 * success_count.load() / total_operations) << "%" << std::endl;
    std::cout << "执行时间: " << duration.count() << "ms" << std::endl;
    
    if (fail_count.load() == 0) {
        std::cout << "[SUCCESS] 线程安全测试通过！" << std::endl;
        return 0;
    } else {
        std::cout << "[FAILED] 线程安全测试失败！" << std::endl;
        return 1;
    }
}
'''
        
        # 保存测试代码
        test_file = "thread_safety_test.cpp"
        with open(test_file, 'w') as f:
            f.write(test_code)
        
        print(f"测试代码已生成: {test_file}")
        print("编译并运行测试:")
        print(f"g++ -std=c++11 -pthread -O2 {test_file} -o thread_safety_test && ./thread_safety_test")
        
        # 尝试自动编译和运行（如果有编译器）
        import subprocess
        try:
            # 编译
            compile_result = subprocess.run(['g++', '-std=c++11', '-pthread', '-O2', test_file, '-o', 'thread_safety_test'], 
                                          capture_output=True, text=True, timeout=30)
            if compile_result.returncode == 0:
                print("✅ 编译成功")
                
                # 运行测试
                run_result = subprocess.run(['./thread_safety_test'], 
                                          capture_output=True, text=True, timeout=60)
                print("测试输出:")
                print(run_result.stdout)
                if run_result.stderr:
                    print("错误输出:")
                    print(run_result.stderr)
                
                if run_result.returncode == 0:
                    print("✅ 线程安全测试通过")
                else:
                    print("❌ 线程安全测试失败")
                    
            else:
                print("❌ 编译失败:")
                print(compile_result.stderr)
                print("请手动编译和运行测试")
                
        except subprocess.TimeoutExpired:
            print("⏰ 测试超时")
        except FileNotFoundError:
            print("📝 未找到g++编译器，请手动编译和运行测试")
        except Exception as e:
            print(f"🚫 测试执行出错: {e}")
    
    print(f"=== 生成模式: {args.mode} ===")
    print(f"找到 {len(strings)} 个字符串常量")

    if args.mode == 'debug':
        header_content = encryptor.generate_plain_header(strings)
        # 生成app_strings.cpp（明文查找）
        cpp_lines = [
            '#include "app_strings.h"',
            '#include <string>',
            '#include <cstring>',
            '',
            'const char* getAppString(const char* key) {',
            '    if (!key) return "";',
            '    #define STR_CMP(k, v) if (strcmp(key, #k) == 0) return v;',
        ]
        for key, value in strings:
            cpp_lines.append(f'    STR_CMP({key}, {key});')
        cpp_lines.append('    #undef STR_CMP')
        cpp_lines.append('    return "";')
        cpp_lines.append('}')
        cpp_lines.append('')
        cpp_lines.append('std::string getAppString(const std::string& key) {')
        cpp_lines.append('    return std::string(getAppString(key.c_str()));')
        cpp_lines.append('}')
        cpp_content = '\n'.join(cpp_lines)
    else:
        # Release模式：测试加密过程
        print("=== 测试字符串加密过程 ===")
        for key, value in strings[:3]:  # 只测试前3个字符串
            print(f"测试: {key} = '{value}'")
            if not encryptor.test_encrypt_decrypt(value):
                print(f"[ERROR] 字符串 '{value}' 加密测试失败")
                sys.exit(1)
        
        header_content = encryptor.generate_encrypted_header_from_list(strings)
        # 生成app_strings.cpp（自动解密查找）
        cpp_lines = [
            '#include "app_strings.h"',
            '#include <string>',
            '#include <cstring>',
            '',
            'const char* getAppString(const char* key) {',
            '    if (!key) return "";',
            '    #define STR_CMP(k, v) if (strcmp(key, #k) == 0) return v;',
        ]
        for key, value in strings:
            cpp_lines.append(f'    STR_CMP({key}, {key});')
        cpp_lines.append('    #undef STR_CMP')
        cpp_lines.append('    return "";')
        cpp_lines.append('}')
        cpp_lines.append('')
        cpp_lines.append('std::string getAppString(const std::string& key) {')
        cpp_lines.append('    return std::string(getAppString(key.c_str()));')
        cpp_lines.append('}')
        cpp_content = '\n'.join(cpp_lines)

    os.makedirs(os.path.dirname(args.output), exist_ok=True)
    # 生成前先删除旧的app_strings.h
    if os.path.exists(args.output):
        try:
            os.remove(args.output)
            print(f"已删除旧头文件: {args.output}")
        except OSError as e:
            print(f"删除头文件失败: {args.output}，错误: {e.strerror}")
            sys.exit(1)
    with open(args.output, 'w', encoding='utf-8') as f:
        f.write(header_content)
    print(f"[OK] 头文件已生成: {args.output}")

    # 生成app_strings.cpp
    cpp_path = os.path.join(os.path.dirname(args.output), 'app_strings.cpp')
    if os.path.exists(cpp_path):
        try:
            os.remove(cpp_path)
            print(f"已删除旧源文件: {cpp_path}")
        except OSError as e:
            print(f"删除源文件失败: {cpp_path}，错误: {e.strerror}")
            sys.exit(1)
    with open(cpp_path, 'w', encoding='utf-8') as f:
        f.write(cpp_content)
    print(f"[OK] 源文件已生成: {cpp_path}")

if __name__ == '__main__':
    main()