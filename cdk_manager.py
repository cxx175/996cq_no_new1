#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
CDK管理工具
功能：获取表名、生成注册码、解绑设备、删除注册码
"""

import tkinter as tk
from tkinter import ttk, messagebox, simpledialog
import pymysql
import json
from datetime import datetime, timedelta
import string
import random
import threading

class CDKManager:
    def __init__(self, root):
        self.root = root
        self.root.title("CDK注册码管理工具")
        self.root.geometry("1000x700")
        
        # 数据库连接配置
        self.db_config = {
            'host': 'sql.s1237.vhostgo.com',
            'user': 'cg520',
            'password': 'g0yd8gv1',
            'database': 'cg520',
            'charset': 'utf8mb4',
            'port': 3306
        }
        
        self.connection = None
        self.current_table = None
        
        self.create_widgets()
        self.connect_database()
        
    def create_widgets(self):
        # 主框架
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky="nsew")
        
        # 配置grid权重
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(1, weight=1)
        main_frame.rowconfigure(2, weight=1)
        
        # 数据库配置区域
        config_frame = ttk.LabelFrame(main_frame, text="数据库配置", padding="5")
        config_frame.grid(row=0, column=0, columnspan=2, sticky="ew", pady=(0, 10))
        
        # 数据库配置输入
        ttk.Label(config_frame, text="主机:").grid(row=0, column=0, sticky=tk.W)
        self.host_var = tk.StringVar(value=self.db_config['host'])
        ttk.Entry(config_frame, textvariable=self.host_var, width=15).grid(row=0, column=1, padx=(5, 10))
        
        ttk.Label(config_frame, text="用户名:").grid(row=0, column=2, sticky=tk.W)
        self.user_var = tk.StringVar(value=self.db_config['user'])
        ttk.Entry(config_frame, textvariable=self.user_var, width=15).grid(row=0, column=3, padx=(5, 10))
        
        ttk.Label(config_frame, text="密码:").grid(row=0, column=4, sticky=tk.W)
        self.password_var = tk.StringVar(value=self.db_config['password'])
        ttk.Entry(config_frame, textvariable=self.password_var, width=15, show="*").grid(row=0, column=5, padx=(5, 10))
        
        ttk.Label(config_frame, text="数据库:").grid(row=1, column=0, sticky=tk.W)
        self.database_var = tk.StringVar(value=self.db_config['database'])
        ttk.Entry(config_frame, textvariable=self.database_var, width=15).grid(row=1, column=1, padx=(5, 10))
        
        ttk.Button(config_frame, text="连接数据库", command=self.connect_database).grid(row=1, column=2, padx=(10, 0))
        
        # 表选择区域
        table_frame = ttk.LabelFrame(main_frame, text="表选择", padding="5")
        table_frame.grid(row=1, column=0, columnspan=2, sticky="ew", pady=(0, 10))
        
        ttk.Label(table_frame, text="选择表:").grid(row=0, column=0, sticky=tk.W)
        self.table_var = tk.StringVar()
        self.table_combo = ttk.Combobox(table_frame, textvariable=self.table_var, width=30, state="readonly")
        self.table_combo.grid(row=0, column=1, padx=(5, 10))
        self.table_combo.bind('<<ComboboxSelected>>', self.on_table_select)
        
        ttk.Button(table_frame, text="刷新表列表", command=self.refresh_tables).grid(row=0, column=2, padx=(10, 0))
        ttk.Button(table_frame, text="刷新数据", command=self.refresh_current_data).grid(row=0, column=3, padx=(10, 0))
        
        # 操作区域
        operation_frame = ttk.LabelFrame(main_frame, text="操作", padding="5")
        operation_frame.grid(row=2, column=0, sticky="nsew", padx=(0, 10))
        operation_frame.columnconfigure(0, weight=1)
        
        # 生成注册码
        generate_frame = ttk.Frame(operation_frame)
        generate_frame.grid(row=0, column=0, sticky="ew", pady=(0, 10))
        
        ttk.Label(generate_frame, text="生成注册码 - 时长:").grid(row=0, column=0, sticky=tk.W)
        self.duration_var = tk.StringVar(value="30")
        ttk.Entry(generate_frame, textvariable=self.duration_var, width=10).grid(row=0, column=1, padx=(5, 5))
        
        # 时间单位选择
        self.unit_var = tk.StringVar(value="天")
        unit_combo = ttk.Combobox(generate_frame, textvariable=self.unit_var, width=8, state="readonly")
        unit_combo['values'] = ("天", "小时")
        unit_combo.grid(row=0, column=2, padx=(5, 10))
        
        ttk.Button(generate_frame, text="生成", command=self.generate_cdk).grid(row=0, column=3)
        
        # 批量生成
        batch_frame = ttk.Frame(operation_frame)
        batch_frame.grid(row=1, column=0, sticky="ew", pady=(0, 10))
        
        ttk.Label(batch_frame, text="批量生成 - 数量:").grid(row=0, column=0, sticky=tk.W)
        self.batch_count_var = tk.StringVar(value="10")
        ttk.Entry(batch_frame, textvariable=self.batch_count_var, width=10).grid(row=0, column=1, padx=(5, 10))
        
        ttk.Button(batch_frame, text="批量生成", command=self.batch_generate_cdk).grid(row=0, column=2)
        
        # 解绑设备
        unbind_frame = ttk.Frame(operation_frame)
        unbind_frame.grid(row=2, column=0, sticky="ew", pady=(0, 10))
        
        ttk.Label(unbind_frame, text="解绑设备 - 注册码:").grid(row=0, column=0, sticky=tk.W)
        self.unbind_cdk_var = tk.StringVar()
        ttk.Entry(unbind_frame, textvariable=self.unbind_cdk_var, width=20).grid(row=0, column=1, padx=(5, 10))
        ttk.Button(unbind_frame, text="解绑", command=self.unbind_device).grid(row=0, column=2)
        
        # 删除注册码
        delete_frame = ttk.Frame(operation_frame)
        delete_frame.grid(row=3, column=0, sticky="ew", pady=(0, 10))
        
        ttk.Label(delete_frame, text="删除注册码 - 注册码:").grid(row=0, column=0, sticky=tk.W)
        self.delete_cdk_var = tk.StringVar()
        ttk.Entry(delete_frame, textvariable=self.delete_cdk_var, width=20).grid(row=0, column=1, padx=(5, 10))
        ttk.Button(delete_frame, text="删除", command=self.delete_cdk).grid(row=0, column=2)
        
        # 查询注册码
        query_frame = ttk.Frame(operation_frame)
        query_frame.grid(row=4, column=0, sticky="ew", pady=(0, 10))
        
        ttk.Label(query_frame, text="查询注册码 - 注册码:").grid(row=0, column=0, sticky=tk.W)
        self.query_cdk_var = tk.StringVar()
        ttk.Entry(query_frame, textvariable=self.query_cdk_var, width=20).grid(row=0, column=1, padx=(5, 10))
        ttk.Button(query_frame, text="查询", command=self.query_cdk).grid(row=0, column=2)
        
        # 数据显示区域
        display_frame = ttk.LabelFrame(main_frame, text="数据列表", padding="5")
        display_frame.grid(row=2, column=1, sticky="nsew")
        display_frame.columnconfigure(0, weight=1)
        display_frame.rowconfigure(1, weight=1)
        
        # 添加操作提示
        tip_frame = ttk.Frame(display_frame)
        tip_frame.grid(row=0, column=0, columnspan=2, sticky="ew", pady=(0, 5))
        
        tip_label = ttk.Label(tip_frame, text="操作提示：右键点击行可复制信息 | 双击可复制注册码 | F5或Ctrl+R刷新数据", 
                             font=("Arial", 8), foreground="gray")
        tip_label.grid(row=0, column=0, sticky=tk.W)
        
        # 创建Treeview
        columns = ('ID', '注册码', '到期时间', '绑定设备', 'Token', '最后登录', '状态', '创建时间', '时长')
        self.tree = ttk.Treeview(display_frame, columns=columns, show='headings', height=15)
        
        # 设置列标题
        for col in columns:
            self.tree.heading(col, text=col)
            if col == '注册码':
                self.tree.column(col, width=120)
            elif col == 'Token':
                self.tree.column(col, width=100)
            elif col == '时长':
                self.tree.column(col, width=80)
            else:
                self.tree.column(col, width=100)
        
        # 创建右键菜单
        self.context_menu = tk.Menu(self.root, tearoff=0)
        self.context_menu.add_command(label="复制选中行", command=self.copy_selected_row)
        self.context_menu.add_command(label="复制注册码", command=self.copy_cdk)
        self.context_menu.add_command(label="复制设备号", command=self.copy_imei)
        self.context_menu.add_command(label="复制Token", command=self.copy_token)
        self.context_menu.add_separator()
        self.context_menu.add_command(label="复制所有信息", command=self.copy_all_info)
        
        # 绑定右键点击事件
        self.tree.bind("<Button-3>", self.show_context_menu)
        # 绑定双击事件
        self.tree.bind("<Double-1>", self.on_double_click)
        # 绑定键盘快捷键
        self.tree.bind("<Control-c>", self.copy_selected_row_hotkey)
        self.tree.bind("<Control-r>", self.refresh_data_hotkey)
        
        # 绑定全局快捷键
        self.root.bind("<F5>", self.refresh_data_hotkey)
        self.root.bind("<Control-q>", self.quit_app)
        
        # 滚动条
        scrollbar_y = ttk.Scrollbar(display_frame, orient=tk.VERTICAL, command=self.tree.yview)
        scrollbar_x = ttk.Scrollbar(display_frame, orient=tk.HORIZONTAL, command=self.tree.xview)
        self.tree.configure(yscrollcommand=scrollbar_y.set, xscrollcommand=scrollbar_x.set)
        
        self.tree.grid(row=1, column=0, sticky="nsew")
        scrollbar_y.grid(row=1, column=1, sticky="ns")
        scrollbar_x.grid(row=2, column=0, sticky="ew")
        
        # 状态栏
        self.status_var = tk.StringVar(value="准备就绪")
        status_bar = ttk.Label(main_frame, textvariable=self.status_var, relief=tk.SUNKEN)
        status_bar.grid(row=3, column=0, columnspan=2, sticky="ew", pady=(10, 0))
        
    def connect_database(self):
        """连接数据库"""
        try:
            # 更新配置
            self.db_config['host'] = self.host_var.get()
            self.db_config['user'] = self.user_var.get()
            self.db_config['password'] = self.password_var.get()
            self.db_config['database'] = self.database_var.get()
            
            # 清理旧连接
            if self.connection:
                try:
                    self.connection.close()
                except:
                    pass
                self.connection = None
                
            # 建立新连接
            self.connection = pymysql.connect(
                host=self.db_config['host'],
                user=self.db_config['user'],
                password=self.db_config['password'],
                database=self.db_config['database'],
                charset=self.db_config['charset'],
                autocommit=False,
                connect_timeout=10
            )
            
            self.status_var.set("数据库连接成功")
            self.refresh_tables()
            
        except Exception as e:
            self.connection = None
            error_msg = f"数据库连接失败：{str(e)}"
            messagebox.showerror("连接错误", error_msg)
            self.status_var.set("数据库连接失败")
            
    def refresh_tables(self):
        """刷新表列表"""
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showwarning("警告", "请先连接数据库")
            return
            
        try:
            with self.connection.cursor() as cursor:
                cursor.execute("SHOW TABLES")
                tables = [row[0] for row in cursor.fetchall()]
                
            self.table_combo['values'] = tables
            self.status_var.set(f"找到 {len(tables)} 个表")
            
        except Exception as e:
            messagebox.showerror("错误", f"获取表列表失败：{str(e)}")
            
    def refresh_current_data(self):
        """刷新当前表的数据"""
        if self.current_table:
            # 检查数据库连接状态
            if not self.check_connection():
                self.status_var.set("数据库连接已断开，正在重新连接...")
                self.connect_database()
            
            if not self.connection:
                self.status_var.set("数据库连接失败，无法刷新数据")
                return
                
            self.load_table_data()
            current_time = datetime.now().strftime('%H:%M:%S')
            self.status_var.set(f"已刷新表 {self.current_table} 的数据 - {current_time}")
        else:
            messagebox.showwarning("警告", "请先选择一个表")
            
    def on_table_select(self, event):
        """表选择事件"""
        self.current_table = self.table_var.get()
        self.load_table_data()
        
    def load_table_data(self):
        """加载表数据"""
        if not self.current_table:
            return
            
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showerror("错误", "数据库连接失败")
            return
            
        try:
            # 清空现有数据
            for item in self.tree.get_children():
                self.tree.delete(item)
                
            with self.connection.cursor() as cursor:
                # 检查表结构
                cursor.execute(f"DESCRIBE `{self.current_table}`")
                columns = [row[0] for row in cursor.fetchall()]
                
                # 构建查询语句，兼容没有某些字段的表
                select_fields = ['id', 'cdk', 'data', 'imei']
                
                # 添加Token字段
                if 'Token' in columns:
                    select_fields.append('Token')
                else:
                    select_fields.append('NULL as Token')  # 默认值
                
                # 添加其他字段
                select_fields.append('lasttime')
                
                if 'status' in columns:
                    select_fields.append('status')
                else:
                    select_fields.append('1 as status')  # 默认值
                    
                if 'createtime' in columns:
                    select_fields.append('createtime')
                else:
                    select_fields.append('NULL as createtime')  # 默认值
                
                if 'nunmber' in columns:
                    select_fields.append('nunmber')
                else:
                    select_fields.append('NULL as nunmber')  # 默认值
                
                query = f"SELECT {', '.join(select_fields)} FROM `{self.current_table}` ORDER BY id DESC LIMIT 100"
                cursor.execute(query)
                
                for row in cursor.fetchall():
                    # 处理可能的None值
                    display_row = []
                    for i, value in enumerate(row):
                        if value is None:
                            display_row.append('')
                        elif isinstance(value, datetime):
                            display_row.append(value.strftime('%Y-%m-%d %H:%M:%S'))
                        elif i == len(row) - 1:  # 最后一列是nunmber字段
                            if value is None or value == 0:
                                display_row.append('已激活')
                            elif value > 0:
                                if value >= 1:
                                    display_row.append(f'{value}天(未激活)')
                                else:
                                    display_row.append(f'{value*10}小时(未激活)')
                            else:
                                display_row.append('已激活')
                        else:
                            display_row.append(str(value))
                    
                    self.tree.insert('', 'end', values=display_row)
                    
            self.status_var.set(f"已加载表 {self.current_table} 的数据")
            
        except Exception as e:
            messagebox.showerror("错误", f"加载数据失败：{str(e)}")
            
    def generate_cdk_code(self, length=16):
        """生成注册码 - 固定16位长度"""
        chars = string.ascii_uppercase + string.digits
        return ''.join(random.choice(chars) for _ in range(16))
        
    def generate_cdk(self):
        """生成注册码"""
        if not self.current_table:
            messagebox.showwarning("警告", "请先选择表")
            return
            
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showerror("错误", "数据库连接失败")
            return
            
        try:
            duration = float(self.duration_var.get())
            if duration <= 0:
                messagebox.showerror("错误", "时长必须大于0")
                return
                
            unit = self.unit_var.get()
            
            # 根据单位计算nunmber值
            if unit == "天":
                nunmber_value = duration  # 天数直接存储
            elif unit == "小时":
                if duration > 9:
                    messagebox.showerror("错误", "小时数不能超过9")
                    return
                nunmber_value = duration / 10  # 小时数除以10存储（0.1-0.9）
            else:
                messagebox.showerror("错误", "无效的时间单位")
                return
                
        except ValueError:
            messagebox.showerror("错误", "请输入有效的时长")
            return
            
        try:
            cdk = self.generate_cdk_code()
            
            with self.connection.cursor() as cursor:
                # 检查表结构
                cursor.execute(f"DESCRIBE `{self.current_table}`")
                columns = [row[0] for row in cursor.fetchall()]
                
                # 构建插入语句，生成未激活的注册码
                insert_fields = ['cdk', 'data', 'nunmber']
                insert_values = [cdk, '0000-00-00 00:00:00', nunmber_value]
                
                if 'status' in columns:
                    insert_fields.append('status')
                    insert_values.append(1)
                    
                if 'createtime' in columns:
                    insert_fields.append('createtime')
                    insert_values.append('NOW()')
                    
                # 构建SQL语句
                placeholders = []
                final_values = []
                for i, field in enumerate(insert_fields):
                    if field == 'createtime' and insert_values[i] == 'NOW()':
                        placeholders.append('NOW()')
                    else:
                        placeholders.append('%s')
                        final_values.append(insert_values[i])
                
                query = f"INSERT INTO `{self.current_table}` ({', '.join(insert_fields)}) VALUES ({', '.join(placeholders)})"
                cursor.execute(query, final_values)
                self.connection.commit()
                
            unit_text = "天" if unit == "天" else "小时"
            messagebox.showinfo("成功", f"注册码生成成功：{cdk}\n时长：{duration}{unit_text}\n状态：未激活（首次登录时激活）")
            self.load_table_data()
            
        except Exception as e:
            messagebox.showerror("错误", f"生成注册码失败：{str(e)}")
            
    def batch_generate_cdk(self):
        """批量生成注册码并保存到文件"""
        if not self.current_table:
            messagebox.showwarning("警告", "请先选择表")
            return
            
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showerror("错误", "数据库连接失败")
            return
            
        try:
            # 获取批量生成数量
            batch_count = int(self.batch_count_var.get())
            if batch_count <= 0 or batch_count > 1000:
                messagebox.showerror("错误", "批量数量必须在1-1000之间")
                return
                
            # 获取时长和单位
            duration = float(self.duration_var.get())
            if duration <= 0:
                messagebox.showerror("错误", "时长必须大于0")
                return
                
            unit = self.unit_var.get()
            
            # 根据单位计算nunmber值
            if unit == "天":
                nunmber_value = duration  # 天数直接存储
            elif unit == "小时":
                if duration > 9:
                    messagebox.showerror("错误", "小时数不能超过9")
                    return
                nunmber_value = duration / 10  # 小时数除以10存储（0.1-0.9）
            else:
                messagebox.showerror("错误", "无效的时间单位")
                return
                
        except ValueError:
            messagebox.showerror("错误", "请输入有效的数量和时长")
            return
        
        # 确认批量生成
        if not messagebox.askyesno("确认", f"确定要批量生成 {batch_count} 个注册码吗？"):
            return
            
        try:
            # 生成注册码列表
            generated_cdks = []
            failed_count = 0
            
            # 创建进度窗口
            progress_window = tk.Toplevel(self.root)
            progress_window.title("批量生成进度")
            progress_window.geometry("400x150")
            progress_window.resizable(False, False)
            
            # 进度条
            progress_var = tk.DoubleVar()
            progress_bar = ttk.Progressbar(progress_window, variable=progress_var, maximum=batch_count)
            progress_bar.pack(pady=20, padx=20, fill=tk.X)
            
            # 进度标签
            progress_label = ttk.Label(progress_window, text="准备生成...")
            progress_label.pack(pady=10)
            
            # 更新进度窗口
            progress_window.update()
            
            with self.connection.cursor() as cursor:
                # 检查表结构
                cursor.execute(f"DESCRIBE `{self.current_table}`")
                columns = [row[0] for row in cursor.fetchall()]
                
                # 构建插入语句
                insert_fields = ['cdk', 'data', 'nunmber']
                insert_values_template = ['%s', '\'0000-00-00 00:00:00\'', str(nunmber_value)]
                
                if 'status' in columns:
                    insert_fields.append('status')
                    insert_values_template.append('1')
                    
                if 'createtime' in columns:
                    insert_fields.append('createtime')
                    insert_values_template.append('NOW()')
                
                # 批量插入
                for i in range(batch_count):
                    try:
                        cdk = self.generate_cdk_code()
                        
                        # 检查是否重复
                        cursor.execute(f"SELECT COUNT(*) FROM `{self.current_table}` WHERE cdk = %s", (cdk,))
                        count_result = cursor.fetchone()
                        if count_result and count_result[0] > 0:
                            failed_count += 1
                            continue
                        
                        # 插入数据库
                        query = f"INSERT INTO `{self.current_table}` ({', '.join(insert_fields)}) VALUES ({', '.join(insert_values_template)})"
                        cursor.execute(query, (cdk,))
                        
                        generated_cdks.append({
                            'cdk': cdk,
                            'duration': duration,
                            'unit': unit,
                            'nunmber': nunmber_value,
                            'create_time': datetime.now().strftime('%Y-%m-%d %H:%M:%S')
                        })
                        
                        # 更新进度
                        progress_var.set(i + 1)
                        progress_label.config(text=f"正在生成... {i + 1}/{batch_count}")
                        progress_window.update()
                        
                    except Exception as e:
                        failed_count += 1
                        continue
                
                self.connection.commit()
            
            # 关闭进度窗口
            progress_window.destroy()
            
            # 保存到文件
            if generated_cdks:
                self.save_cdks_to_file(generated_cdks)
                
            success_count = len(generated_cdks)
            message = f"批量生成完成！\n成功生成：{success_count} 个\n失败：{failed_count} 个"
            
            if success_count > 0:
                message += f"\n注册码已保存到文件"
                
            messagebox.showinfo("完成", message)
            self.load_table_data()
            
        except Exception as e:
            messagebox.showerror("错误", f"批量生成失败：{str(e)}")
            
    def save_cdks_to_file(self, cdks_data):
        """保存注册码到文件"""
        try:
            from tkinter import filedialog
            import os
            
            # 选择保存位置
            filename = filedialog.asksaveasfilename(
                title="保存注册码文件",
                defaultextension=".txt",
                filetypes=[("文本文件", "*.txt"), ("CSV文件", "*.csv"), ("所有文件", "*.*")]
            )
            
            if not filename:
                return
                
            # 根据文件扩展名选择格式
            file_ext = os.path.splitext(filename)[1].lower()
            
            with open(filename, 'w', encoding='utf-8') as f:
                if file_ext == '.csv':
                    # CSV格式
                    f.write("注册码,时长,单位,nunmber值,生成时间\n")
                    for cdk_info in cdks_data:
                        f.write(f"{cdk_info['cdk']},{cdk_info['duration']},{cdk_info['unit']},{cdk_info['nunmber']},{cdk_info['create_time']}\n")
                else:
                    # 文本格式
                    f.write(f"注册码批量生成记录\n")
                    f.write(f"生成时间：{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
                    f.write(f"表名：{self.current_table}\n")
                    f.write(f"总数量：{len(cdks_data)}\n")
                    f.write(f"时长设置：{cdks_data[0]['duration']}{cdks_data[0]['unit']}\n")
                    f.write("="*50 + "\n\n")
                    
                    for i, cdk_info in enumerate(cdks_data, 1):
                        f.write(f"{i:4d}. {cdk_info['cdk']}\n")
                        
                    f.write("\n" + "="*50 + "\n")
                    f.write("详细信息：\n")
                    for cdk_info in cdks_data:
                        f.write(f"注册码：{cdk_info['cdk']} | 时长：{cdk_info['duration']}{cdk_info['unit']} | 生成时间：{cdk_info['create_time']}\n")
            
            messagebox.showinfo("成功", f"注册码已保存到文件：\n{filename}")
            
        except Exception as e:
            messagebox.showerror("错误", f"保存文件失败：{str(e)}")
            
    def unbind_device(self):
        """解绑设备"""
        if not self.current_table:
            messagebox.showwarning("警告", "请先选择表")
            return
            
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showerror("错误", "数据库连接失败")
            return
            
        cdk = self.unbind_cdk_var.get().strip()
        if not cdk:
            messagebox.showerror("错误", "请输入注册码")
            return
            
        try:
            with self.connection.cursor() as cursor:
                # 检查表结构，确定需要更新的字段
                cursor.execute(f"DESCRIBE `{self.current_table}`")
                columns = [row[0] for row in cursor.fetchall()]
                
                # 构建更新语句
                update_fields = []
                if 'imei' in columns:
                    update_fields.append('imei = NULL')
                if 'Token' in columns:
                    update_fields.append('Token = NULL')
                
                if not update_fields:
                    messagebox.showwarning("警告", "表中没有找到imei或Token字段")
                    return
                
                # 执行更新
                sql = f"UPDATE `{self.current_table}` SET {', '.join(update_fields)} WHERE cdk = %s"
                cursor.execute(sql, (cdk,))
                affected_rows = cursor.rowcount
                self.connection.commit()
                
            if affected_rows > 0:
                fields_updated = " 和 ".join([field.split(' = ')[0] for field in update_fields])
                messagebox.showinfo("成功", f"设备解绑成功！\n注册码：{cdk}\n已清空字段：{fields_updated}")
                self.load_table_data()
                self.unbind_cdk_var.set("")
            else:
                messagebox.showwarning("警告", "未找到该注册码")
                
        except Exception as e:
            messagebox.showerror("错误", f"解绑失败：{str(e)}")
            
    def delete_cdk(self):
        """删除注册码"""
        if not self.current_table:
            messagebox.showwarning("警告", "请先选择表")
            return
            
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showerror("错误", "数据库连接失败")
            return
            
        cdk = self.delete_cdk_var.get().strip()
        if not cdk:
            messagebox.showerror("错误", "请输入注册码")
            return
            
        # 确认删除
        if not messagebox.askyesno("确认", f"确定要删除注册码 {cdk} 吗？此操作不可恢复！"):
            return
            
        try:
            with self.connection.cursor() as cursor:
                cursor.execute(f"DELETE FROM `{self.current_table}` WHERE cdk = %s", (cdk,))
                affected_rows = cursor.rowcount
                self.connection.commit()
                
            if affected_rows > 0:
                messagebox.showinfo("成功", f"注册码删除成功：{cdk}")
                self.load_table_data()
                self.delete_cdk_var.set("")
            else:
                messagebox.showwarning("警告", "未找到该注册码")
                
        except Exception as e:
            messagebox.showerror("错误", f"删除失败：{str(e)}")
            
    def query_cdk(self):
        """查询注册码信息"""
        if not self.current_table:
            messagebox.showwarning("警告", "请先选择表")
            return
            
        # 检查数据库连接状态
        if not self.check_connection():
            self.connect_database()
            
        if not self.connection:
            messagebox.showerror("错误", "数据库连接失败")
            return
            
        cdk = self.query_cdk_var.get().strip()
        if not cdk:
            messagebox.showerror("错误", "请输入注册码")
            return
            
        try:
            with self.connection.cursor() as cursor:
                # 检查表结构
                cursor.execute(f"DESCRIBE `{self.current_table}`")
                columns = [row[0] for row in cursor.fetchall()]
                
                # 构建查询语句
                select_fields = ['id', 'cdk', 'data', 'imei']
                
                # 添加Token字段
                if 'Token' in columns:
                    select_fields.append('Token')
                else:
                    select_fields.append('NULL as Token')  # 默认值
                
                # 添加其他字段
                select_fields.append('lasttime')
                
                if 'status' in columns:
                    select_fields.append('status')
                else:
                    select_fields.append('1 as status')  # 默认值
                    
                if 'createtime' in columns:
                    select_fields.append('createtime')
                else:
                    select_fields.append('NULL as createtime')  # 默认值
                
                if 'nunmber' in columns:
                    select_fields.append('nunmber')
                else:
                    select_fields.append('NULL as nunmber')  # 默认值
                
                query = f"SELECT {', '.join(select_fields)} FROM `{self.current_table}` WHERE cdk = %s"
                cursor.execute(query, (cdk,))
                result = cursor.fetchone()
                
            if result:
                info = f"注册码信息：\n"
                info += f"ID: {result[0]}\n"
                info += f"注册码: {result[1]}\n"
                info += f"到期时间: {result[2]}\n"
                info += f"绑定设备: {result[3] or '未绑定'}\n"
                info += f"Token: {result[4] or '未绑定'}\n"
                info += f"最后登录: {result[5] or '从未登录'}\n"
                
                field_index = 6
                if 'status' in columns and len(result) > field_index:
                    status_text = "启用" if result[field_index] == 1 else "禁用"
                    info += f"状态: {status_text}\n"
                    field_index += 1
                    
                if 'createtime' in columns and len(result) > field_index:
                    info += f"创建时间: {result[field_index] or '未知'}\n"
                    field_index += 1
                
                if 'nunmber' in columns and len(result) > field_index:
                    nunmber_value = result[field_index]
                    if nunmber_value is None or nunmber_value == 0:
                        info += f"激活状态: 已激活\n"
                    elif nunmber_value > 0:
                        if nunmber_value >= 1:
                            info += f"激活状态: 未激活 ({nunmber_value}天)\n"
                        else:
                            info += f"激活状态: 未激活 ({nunmber_value*10}小时)\n"
                    else:
                        info += f"激活状态: 已激活\n"
                
                messagebox.showinfo("查询结果", info)
            else:
                messagebox.showwarning("警告", "未找到该注册码")
                
        except Exception as e:
            messagebox.showerror("错误", f"查询失败：{str(e)}")

    def show_context_menu(self, event):
        """显示右键菜单"""
        try:
            # 选择右键点击的项目
            item = self.tree.identify_row(event.y)
            if item:
                self.tree.selection_set(item)
                self.context_menu.post(event.x_root, event.y_root)
        except Exception:
            pass

    def copy_selected_row(self):
        """复制选中行的所有信息"""
        try:
            selected_items = self.tree.selection()
            if not selected_items:
                messagebox.showwarning("提示", "请先选择一行数据")
                return
                
            selected_item = selected_items[0]
            row = self.tree.item(selected_item)['values']
            
            # 格式化数据为可读格式
            columns = ['ID', '注册码', '到期时间', '绑定设备', 'Token', '最后登录', '状态', '创建时间', '时长']
            formatted_data = []
            for i, value in enumerate(row):
                if i < len(columns):
                    formatted_data.append(f"{columns[i]}: {value}")
            
            copy_text = '\n'.join(formatted_data)
            self.root.clipboard_clear()
            self.root.clipboard_append(copy_text)
            
            messagebox.showinfo("成功", "已复制选中行信息到剪贴板")
            
        except Exception as e:
            messagebox.showerror("错误", f"复制失败：{str(e)}")

    def copy_cdk(self):
        """复制注册码"""
        try:
            selected_items = self.tree.selection()
            if not selected_items:
                messagebox.showwarning("提示", "请先选择一行数据")
                return
                
            selected_item = selected_items[0]
            row = self.tree.item(selected_item)['values']
            
            if len(row) > 1:
                cdk = str(row[1])  # 注册码在第2列（索引1）
                self.root.clipboard_clear()
                self.root.clipboard_append(cdk)
                messagebox.showinfo("成功", f"已复制注册码：{cdk}")
            else:
                messagebox.showwarning("错误", "无法获取注册码")
                
        except Exception as e:
            messagebox.showerror("错误", f"复制注册码失败：{str(e)}")

    def copy_imei(self):
        """复制设备号"""
        try:
            selected_items = self.tree.selection()
            if not selected_items:
                messagebox.showwarning("提示", "请先选择一行数据")
                return
                
            selected_item = selected_items[0]
            row = self.tree.item(selected_item)['values']
            
            if len(row) > 3:
                imei = str(row[3])  # 设备号在第4列（索引3）
                if imei and imei.strip():
                    self.root.clipboard_clear()
                    self.root.clipboard_append(imei)
                    messagebox.showinfo("成功", f"已复制设备号：{imei}")
                else:
                    messagebox.showwarning("提示", "该注册码未绑定设备")
            else:
                messagebox.showwarning("错误", "无法获取设备号")
                
        except Exception as e:
            messagebox.showerror("错误", f"复制设备号失败：{str(e)}")

    def copy_token(self):
        """复制Token"""
        try:
            selected_items = self.tree.selection()
            if not selected_items:
                messagebox.showwarning("提示", "请先选择一行数据")
                return
                
            selected_item = selected_items[0]
            row = self.tree.item(selected_item)['values']
            
            if len(row) > 4:
                token = str(row[4])  # Token在第5列（索引4）
                if token and token.strip():
                    self.root.clipboard_clear()
                    self.root.clipboard_append(token)
                    messagebox.showinfo("成功", f"已复制Token：{token}")
                else:
                    messagebox.showwarning("提示", "该注册码未绑定Token")
            else:
                messagebox.showwarning("错误", "无法获取Token")
                
        except Exception as e:
            messagebox.showerror("错误", f"复制Token失败：{str(e)}")

    def copy_all_info(self):
        """复制所有可见数据"""
        try:
            all_data = []
            columns = ['ID', '注册码', '到期时间', '绑定设备', 'Token', '最后登录', '状态', '创建时间', '时长']
            
            # 添加表头
            all_data.append('\t'.join(columns))
            
            # 添加所有行数据
            for item in self.tree.get_children():
                row = self.tree.item(item)['values']
                all_data.append('\t'.join(map(str, row)))
            
            copy_text = '\n'.join(all_data)
            self.root.clipboard_clear()
            self.root.clipboard_append(copy_text)
            
            messagebox.showinfo("成功", f"已复制所有数据（{len(all_data)-1}行）到剪贴板")
            
        except Exception as e:
            messagebox.showerror("错误", f"复制所有信息失败：{str(e)}")

    def on_double_click(self, event):
        """双击事件 - 复制注册码"""
        self.copy_cdk()

    def copy_selected_row_hotkey(self, event):
        """复制选中行的所有信息"""
        self.copy_selected_row()

    def refresh_data_hotkey(self, event):
        """刷新数据"""
        self.refresh_current_data()

    def quit_app(self, event):
        """退出应用程序"""
        self.root.quit()

    def check_connection(self):
        """检查数据库连接状态"""
        try:
            if not self.connection:
                return False
                
            # 检查连接是否还活着
            with self.connection.cursor() as cursor:
                cursor.execute("SELECT 1")
                cursor.fetchone()
                
            return True
            
        except Exception as e:
            # 连接出现问题，清理连接对象
            try:
                if self.connection:
                    self.connection.close()
            except:
                pass
            self.connection = None
            return False

def main():
    root = tk.Tk()
    app = CDKManager(root)
    root.mainloop()

if __name__ == "__main__":
    main() 