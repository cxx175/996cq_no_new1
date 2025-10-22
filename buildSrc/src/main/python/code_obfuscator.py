#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
代码混淆工具 - 控制流混淆实现
用于在编译前对C++源码进行混淆处理
作为Obfuscator-LLVM的替代方案
"""

import os
import re
import random
import string
import hashlib
import argparse
from typing import List, Dict, Tuple, Set

class CodeObfuscator:
    """C++代码混淆器"""
    
    def __init__(self):
        self.obfuscated_names = {}
        self.used_names = set()
        self.random_seed = None
        
    def set_seed(self, seed: int):
        """设置随机种子以确保可重复的混淆"""
        self.random_seed = seed
        random.seed(seed)
        
    def generate_random_name(self, prefix: str = "obf") -> str:
        """生成随机的变量/函数名"""
        while True:
            # 生成随机字符串
            chars = string.ascii_letters + string.digits + '_'
            name = prefix + '_' + ''.join(random.choices(chars, k=8))
            
            # 确保不与已使用的名称冲突
            if name not in self.used_names:
                self.used_names.add(name)
                return name
    
    def obfuscate_function_names(self, code: str) -> str:
        """混淆函数名（排除JNI函数）"""
        # 匹配函数定义模式
        pattern = r'\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\('
        
        # 需要保护的函数名（JNI函数等）
        protected_functions = {
            'JNI_OnLoad', 'JNI_OnUnload', 'main', 'printf', 'malloc', 'free',
            'strlen', 'strcmp', 'strcpy', 'strcat', 'memcpy', 'memset',
            '__android_log_print', '__android_log_write'
        }
        
        def replace_func(match):
            func_name = match.group(1)
            
            # 跳过保护的函数名
            if func_name in protected_functions:
                return match.group(0)
            
            # 跳过Java_开头的JNI函数
            if func_name.startswith('Java_'):
                return match.group(0)
            
            # 跳过系统函数
            if func_name.startswith('_') or func_name.isupper():
                return match.group(0)
            
            # 生成混淆名称
            if func_name not in self.obfuscated_names:
                self.obfuscated_names[func_name] = self.generate_random_name('func')
            
            return match.group(0).replace(func_name, self.obfuscated_names[func_name])
        
        return re.sub(pattern, replace_func, code)
    
    def obfuscate_variable_names(self, code: str) -> str:
        """混淆局部变量名"""
        # 匹配变量声明模式
        patterns = [
            r'\b(int|char|bool|float|double|long|short|unsigned)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*[;=]',
            r'\b(std::\w+|string|vector|map)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*[;=]',
            r'\b(auto|const)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*[;=]'
        ]
        
        for pattern in patterns:
            def replace_var(match):
                var_type = match.group(1)
                var_name = match.group(2)
                
                # 跳过常见的系统变量
                if var_name in ['argc', 'argv', 'env', 'result', 'status']:
                    return match.group(0)
                
                # 生成混淆名称
                if var_name not in self.obfuscated_names:
                    self.obfuscated_names[var_name] = self.generate_random_name('var')
                
                return match.group(0).replace(var_name, self.obfuscated_names[var_name])
            
            code = re.sub(pattern, replace_var, code)
        
        return code
    
    def add_dummy_code(self, code: str) -> str:
        """添加虚假代码块"""
        lines = code.split('\n')
        result = []
        
        for i, line in enumerate(lines):
            result.append(line)
            
            # 在函数开始处添加虚假代码
            if '{' in line and ('if' in line or 'for' in line or 'while' in line):
                dummy_var = self.generate_random_name('dummy')
                dummy_code = [
                    f"    volatile int {dummy_var} = {random.randint(1, 100)};",
                    f"    if ({dummy_var} < 0) {{",
                    f"        {dummy_var} = {dummy_var} * 2;",
                    f"    }}"
                ]
                result.extend(dummy_code)
        
        return '\n'.join(result)
    
    def obfuscate_control_flow(self, code: str) -> str:
        """控制流混淆"""
        # 简单的if语句混淆
        def obfuscate_if(match):
            condition = match.group(1)
            
            # 生成混淆的条件
            dummy_var = self.generate_random_name('cond')
            obfuscated = f"""
    volatile bool {dummy_var} = true;
    if ({dummy_var} && ({condition}))"""
            
            return obfuscated
        
        # 混淆if语句
        code = re.sub(r'if\s*\(([^)]+)\)', obfuscate_if, code)
        
        return code
    
    def add_anti_debug(self, code: str) -> str:
        """添加反调试代码"""
        anti_debug_code = '''
// 反调试检测
static bool check_debugger() {
    static volatile int debug_check = 0;
    debug_check++;
    
    // 检测调试器
    #ifdef __ANDROID__
    FILE* status = fopen("/proc/self/status", "r");
    if (status) {
        char line[256];
        while (fgets(line, sizeof(line), status)) {
            if (strstr(line, "TracerPid:") && !strstr(line, "TracerPid:\\t0")) {
                fclose(status);
                return true;
            }
        }
        fclose(status);
    }
    #endif
    
    return false;
}

#define ANTI_DEBUG_CHECK() \\
    do { \\
        if (check_debugger()) { \\
            exit(1); \\
        } \\
    } while(0)
'''
        
        # 在文件开头添加反调试代码
        if '#include' in code:
            include_pos = code.rfind('#include')
            next_line = code.find('\n', include_pos) + 1
            code = code[:next_line] + anti_debug_code + code[next_line:]
        
        return code
    
    def obfuscate_strings(self, code: str) -> str:
        """字符串混淆"""
        def obfuscate_string(match):
            string_content = match.group(1)
            
            # 跳过空字符串和特殊字符串
            if not string_content or string_content in ['', '\\n', '\\t']:
                return match.group(0)
            
            # 简单的XOR混淆
            key = random.randint(1, 255)
            obfuscated_chars = []
            
            for char in string_content:
                if char != '\\':  # 跳过转义字符
                    obfuscated_chars.append(str(ord(char) ^ key))
                else:
                    obfuscated_chars.append(f"'{char}'")
            
            # 生成解密代码
            var_name = self.generate_random_name('str')
            decrypt_code = f'''
    []() {{
        static char {var_name}[] = {{{','.join(obfuscated_chars)}, 0}};
        static bool decoded = false;
        if (!decoded) {{
            for (int i = 0; {var_name}[i]; i++) {{
                {var_name}[i] ^= {key};
            }}
            decoded = true;
        }}
        return {var_name};
    }}()'''
            
            return decrypt_code
        
        # 混淆字符串字面量
        code = re.sub(r'"([^"]*)"', obfuscate_string, code)
        
        return code
    
    def process_file(self, input_file: str, output_file: str, options: Dict[str, bool]):
        """处理单个文件"""
        try:
            with open(input_file, 'r', encoding='utf-8') as f:
                code = f.read()
            
            print(f"正在混淆文件: {input_file}")
            
            # 应用各种混淆技术
            if options.get('obfuscate_functions', True):
                code = self.obfuscate_function_names(code)
                print("  [+] 函数名混淆完成")
            
            if options.get('obfuscate_variables', True):
                code = self.obfuscate_variable_names(code)
                print("  [+] 变量名混淆完成")
            
            if options.get('add_dummy_code', True):
                code = self.add_dummy_code(code)
                print("  [+] 虚假代码添加完成")
            
            if options.get('obfuscate_control_flow', True):
                code = self.obfuscate_control_flow(code)
                print("  [+] 控制流混淆完成")
            
            if options.get('add_anti_debug', True):
                code = self.add_anti_debug(code)
                print("  [+] 反调试代码添加完成")
            
            if options.get('obfuscate_strings', False):  # 默认关闭，可能影响功能
                code = self.obfuscate_strings(code)
                print("  [+] 字符串混淆完成")
            
            # 写入混淆后的代码
            os.makedirs(os.path.dirname(output_file), exist_ok=True)
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write(code)
            
            print(f"  [+] 混淆完成，输出到: {output_file}")
            
        except Exception as e:
            print(f"处理文件 {input_file} 时出错: {e}")
            return False
        
        return True


def main():
    parser = argparse.ArgumentParser(description='C++代码混淆工具')
    parser.add_argument('input_dir', help='输入目录')
    parser.add_argument('output_dir', help='输出目录')
    parser.add_argument('--seed', type=int, default=12345, help='随机种子')
    parser.add_argument('--no-functions', action='store_true', help='禁用函数名混淆')
    parser.add_argument('--no-variables', action='store_true', help='禁用变量名混淆')
    parser.add_argument('--no-dummy', action='store_true', help='禁用虚假代码')
    parser.add_argument('--no-control-flow', action='store_true', help='禁用控制流混淆')
    parser.add_argument('--no-anti-debug', action='store_true', help='禁用反调试')
    parser.add_argument('--enable-strings', action='store_true', help='启用字符串混淆')
    parser.add_argument('--no-strings', action='store_true', help='禁用字符串混淆（默认）')
    
    args = parser.parse_args()
    
    # 创建混淆器
    obfuscator = CodeObfuscator()
    obfuscator.set_seed(args.seed)
    
    # 设置混淆选项
    options = {
        'obfuscate_functions': not args.no_functions,
        'obfuscate_variables': not args.no_variables,
        'add_dummy_code': not args.no_dummy,
        'obfuscate_control_flow': not args.no_control_flow,
        'add_anti_debug': not args.no_anti_debug,
        'obfuscate_strings': args.enable_strings and not args.no_strings
    }
    
    print("开始代码混淆...")
    print(f"输入目录: {args.input_dir}")
    print(f"输出目录: {args.output_dir}")
    print(f"混淆选项: {options}")
    
    # 处理所有C++文件
    cpp_extensions = ['.cpp', '.c', '.cc', '.cxx']
    success_count = 0
    total_count = 0
    
    for root, dirs, files in os.walk(args.input_dir):
        for file in files:
            if any(file.endswith(ext) for ext in cpp_extensions):
                input_file = os.path.join(root, file)
                
                # 计算相对路径
                rel_path = os.path.relpath(input_file, args.input_dir)
                output_file = os.path.join(args.output_dir, rel_path)
                
                total_count += 1
                if obfuscator.process_file(input_file, output_file, options):
                    success_count += 1
    
    print(f"\n混淆完成！")
    print(f"成功处理: {success_count}/{total_count} 个文件")
    
    # 复制头文件和其他文件
    print("\n复制头文件和其他文件...")
    for root, dirs, files in os.walk(args.input_dir):
        for file in files:
            if not any(file.endswith(ext) for ext in cpp_extensions):
                input_file = os.path.join(root, file)
                rel_path = os.path.relpath(input_file, args.input_dir)
                output_file = os.path.join(args.output_dir, rel_path)
                
                os.makedirs(os.path.dirname(output_file), exist_ok=True)
                with open(input_file, 'rb') as src, open(output_file, 'wb') as dst:
                    dst.write(src.read())
    
    print("所有文件处理完成！")


if __name__ == '__main__':
    main() 