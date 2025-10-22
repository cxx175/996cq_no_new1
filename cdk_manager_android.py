#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
CDK管理工具 - 安卓版本
基于Kivy框架开发，适配移动设备
"""

import os
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.popup import Popup
from kivy.uix.spinner import Spinner
from kivy.uix.scrollview import ScrollView
from kivy.uix.tabbedpanel import TabbedPanel, TabbedPanelItem
from kivy.uix.accordion import Accordion, AccordionItem
from kivy.clock import Clock
from kivy.metrics import dp
from kivy.uix.progressbar import ProgressBar
from functools import partial
import pymysql
import json
from datetime import datetime, timedelta
import string
import random
import threading

# 设置中文字体支持
def setup_chinese_font():
    """设置中文字体支持"""
    try:
        from kivy.core.text import LabelBase
        
        # Windows系统字体路径
        font_paths = [
            'C:/Windows/Fonts/msyh.ttc',  # 微软雅黑
            'C:/Windows/Fonts/simhei.ttf',  # 黑体
            'C:/Windows/Fonts/simsun.ttc',  # 宋体
        ]
        
        for font_path in font_paths:
            if os.path.exists(font_path):
                # 注册默认字体
                LabelBase.register(name='Roboto', fn_regular=font_path)
                print(f"成功注册中文字体: {font_path}")
                return True
                
        print("未找到合适的中文字体")
        return False
        
    except Exception as e:
        print(f"字体注册失败: {e}")
        return False

class CDKManagerApp(App):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.title = "CDK注册码管理工具"
        
        # 设置中文字体
        setup_chinese_font()
        
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
        self.tables_list = []
        self.current_data = []
        
    def build(self):
        """构建主界面"""
        # 创建主布局
        main_layout = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 创建选项卡面板
        tab_panel = TabbedPanel(do_default_tab=False, tab_width=dp(120))
        
        # 数据库配置选项卡
        db_tab = TabbedPanelItem(text='数据库配置')
        db_tab.content = self.create_database_tab()
        tab_panel.add_widget(db_tab)
        
        # 操作选项卡
        operation_tab = TabbedPanelItem(text='操作管理')
        operation_tab.content = self.create_operation_tab()
        tab_panel.add_widget(operation_tab)
        
        # 数据查看选项卡
        data_tab = TabbedPanelItem(text='数据查看')
        data_tab.content = self.create_data_tab()
        tab_panel.add_widget(data_tab)
        
        main_layout.add_widget(tab_panel)
        
        # 状态栏
        self.status_label = Label(text='准备就绪', size_hint_y=None, height=dp(30))
        main_layout.add_widget(self.status_label)
        
        # 自动连接数据库
        Clock.schedule_once(self.connect_database, 0.5)
        
        return main_layout
    
    def create_database_tab(self):
        """创建数据库配置选项卡"""
        layout = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 数据库配置表单
        config_grid = GridLayout(cols=2, spacing=dp(10), size_hint_y=None)
        config_grid.bind(minimum_height=config_grid.setter('height'))
        
        # 主机
        config_grid.add_widget(Label(text='主机:', size_hint_y=None, height=dp(40)))
        self.host_input = TextInput(text=self.db_config['host'], multiline=False, size_hint_y=None, height=dp(40))
        config_grid.add_widget(self.host_input)
        
        # 用户名
        config_grid.add_widget(Label(text='用户名:', size_hint_y=None, height=dp(40)))
        self.user_input = TextInput(text=self.db_config['user'], multiline=False, size_hint_y=None, height=dp(40))
        config_grid.add_widget(self.user_input)
        
        # 密码
        config_grid.add_widget(Label(text='密码:', size_hint_y=None, height=dp(40)))
        self.password_input = TextInput(text=self.db_config['password'], multiline=False, password=True, size_hint_y=None, height=dp(40))
        config_grid.add_widget(self.password_input)
        
        # 数据库名
        config_grid.add_widget(Label(text='数据库:', size_hint_y=None, height=dp(40)))
        self.database_input = TextInput(text=self.db_config['database'], multiline=False, size_hint_y=None, height=dp(40))
        config_grid.add_widget(self.database_input)
        
        layout.add_widget(config_grid)
        
        # 连接按钮
        connect_btn = Button(text='连接数据库', size_hint_y=None, height=dp(50))
        connect_btn.bind(on_press=self.connect_database)
        layout.add_widget(connect_btn)
        
        # 表选择
        table_layout = BoxLayout(orientation='horizontal', size_hint_y=None, height=dp(50), spacing=dp(10))
        table_layout.add_widget(Label(text='选择表:', size_hint_x=None, width=dp(80)))
        
        self.table_spinner = Spinner(text='请先连接数据库', values=[])
        self.table_spinner.bind(text=self.on_table_select)
        table_layout.add_widget(self.table_spinner)
        
        refresh_btn = Button(text='刷新', size_hint_x=None, width=dp(80))
        refresh_btn.bind(on_press=self.refresh_tables)
        table_layout.add_widget(refresh_btn)
        
        layout.add_widget(table_layout)
        
        return layout
    
    def create_operation_tab(self):
        """创建操作管理选项卡"""
        scroll = ScrollView()
        layout = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10), size_hint_y=None)
        layout.bind(minimum_height=layout.setter('height'))
        
        # 生成注册码区域
        generate_accordion = Accordion(size_hint_y=None, height=dp(320))
        
        # 单个生成
        single_item = AccordionItem(title='生成注册码', min_space=dp(100))
        single_layout = GridLayout(cols=2, spacing=dp(10), padding=dp(10))
        
        single_layout.add_widget(Label(text='时长:'))
        self.duration_input = TextInput(text='30', multiline=False, input_filter='float')
        single_layout.add_widget(self.duration_input)
        
        single_layout.add_widget(Label(text='单位:'))
        self.unit_spinner = Spinner(text='天', values=['天', '小时'])
        single_layout.add_widget(self.unit_spinner)
        
        generate_btn = Button(text='生成注册码', size_hint_y=None, height=dp(50))
        generate_btn.bind(on_press=self.generate_cdk)
        single_layout.add_widget(generate_btn)
        
        single_item.add_widget(single_layout)
        generate_accordion.add_widget(single_item)
        
        # 批量生成
        batch_item = AccordionItem(title='批量生成', min_space=dp(100))
        batch_layout = GridLayout(cols=2, spacing=dp(10), padding=dp(10))
        
        batch_layout.add_widget(Label(text='数量:'))
        self.batch_count_input = TextInput(text='10', multiline=False, input_filter='int')
        batch_layout.add_widget(self.batch_count_input)
        
        batch_btn = Button(text='批量生成', size_hint_y=None, height=dp(50))
        batch_btn.bind(on_press=self.batch_generate_cdk)
        batch_layout.add_widget(batch_btn)
        
        batch_item.add_widget(batch_layout)
        generate_accordion.add_widget(batch_item)
        
        layout.add_widget(generate_accordion)
        
        # 设备管理区域
        device_accordion = Accordion(size_hint_y=None, height=dp(200))
        
        # 解绑设备
        unbind_item = AccordionItem(title='解绑设备', min_space=dp(90))
        unbind_layout = BoxLayout(orientation='vertical', spacing=dp(10), padding=dp(10))
        
        unbind_input_layout = BoxLayout(orientation='horizontal', spacing=dp(10))
        unbind_input_layout.add_widget(Label(text='注册码:', size_hint_x=None, width=dp(80)))
        self.unbind_input = TextInput(multiline=False)
        unbind_input_layout.add_widget(self.unbind_input)
        unbind_layout.add_widget(unbind_input_layout)
        
        unbind_btn = Button(text='解绑设备', size_hint_y=None, height=dp(50))
        unbind_btn.bind(on_press=self.unbind_device)
        unbind_layout.add_widget(unbind_btn)
        
        unbind_item.add_widget(unbind_layout)
        device_accordion.add_widget(unbind_item)
        
        layout.add_widget(device_accordion)
        
        # 删除注册码区域
        delete_accordion = Accordion(size_hint_y=None, height=dp(200))
        
        delete_item = AccordionItem(title='删除注册码', min_space=dp(90))
        delete_layout = BoxLayout(orientation='vertical', spacing=dp(10), padding=dp(10))
        
        delete_input_layout = BoxLayout(orientation='horizontal', spacing=dp(10))
        delete_input_layout.add_widget(Label(text='注册码:', size_hint_x=None, width=dp(80)))
        self.delete_input = TextInput(multiline=False)
        delete_input_layout.add_widget(self.delete_input)
        delete_layout.add_widget(delete_input_layout)
        
        delete_btn = Button(text='删除注册码', size_hint_y=None, height=dp(50))
        delete_btn.bind(on_press=self.delete_cdk)
        delete_layout.add_widget(delete_btn)
        
        delete_item.add_widget(delete_layout)
        delete_accordion.add_widget(delete_item)
        
        layout.add_widget(delete_accordion)
        
        scroll.add_widget(layout)
        return scroll
    
    def create_data_tab(self):
        """创建数据查看选项卡"""
        layout = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 查询区域
        query_layout = BoxLayout(orientation='horizontal', size_hint_y=None, height=dp(50), spacing=dp(10))
        query_layout.add_widget(Label(text='查询:', size_hint_x=None, width=dp(60)))
        self.query_input = TextInput(multiline=False, hint_text='输入注册码查询')
        query_layout.add_widget(self.query_input)
        
        query_btn = Button(text='查询', size_hint_x=None, width=dp(80))
        query_btn.bind(on_press=self.query_cdk)
        query_layout.add_widget(query_btn)
        
        refresh_btn = Button(text='刷新', size_hint_x=None, width=dp(80))
        refresh_btn.bind(on_press=self.refresh_data)
        query_layout.add_widget(refresh_btn)
        
        layout.add_widget(query_layout)
        
        # 数据显示区域
        self.data_scroll = ScrollView()
        self.data_layout = BoxLayout(orientation='vertical', size_hint_y=None, spacing=dp(5))
        self.data_layout.bind(minimum_height=self.data_layout.setter('height'))
        
        self.data_scroll.add_widget(self.data_layout)
        layout.add_widget(self.data_scroll)
        
        return layout
    
    def connect_database(self, dt=None):
        """连接数据库"""
        def _connect():
            try:
                # 更新配置
                self.db_config['host'] = self.host_input.text
                self.db_config['user'] = self.user_input.text
                self.db_config['password'] = self.password_input.text
                self.db_config['database'] = self.database_input.text
                
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
                
                Clock.schedule_once(lambda dt: self.update_status("数据库连接成功"), 0)
                Clock.schedule_once(self.refresh_tables, 0.1)
                
            except Exception as e:
                self.connection = None
                error_msg = f"数据库连接失败：{str(e)}"
                Clock.schedule_once(lambda dt: self.show_popup("连接错误", error_msg), 0)
                Clock.schedule_once(lambda dt: self.update_status("数据库连接失败"), 0)
        
        # 在后台线程中执行连接
        threading.Thread(target=_connect).start()
    
    def refresh_tables(self, dt=None):
        """刷新表列表"""
        def _refresh():
            if not self.check_connection():
                return
                
            try:
                with self.connection.cursor() as cursor:
                    cursor.execute("SHOW TABLES")
                    tables = [row[0] for row in cursor.fetchall()]
                    
                self.tables_list = tables
                Clock.schedule_once(lambda dt: self.update_table_spinner(tables), 0)
                Clock.schedule_once(lambda dt: self.update_status(f"找到 {len(tables)} 个表"), 0)
                
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"获取表列表失败：{str(e)}"), 0)
        
        threading.Thread(target=_refresh).start()
    
    def update_table_spinner(self, tables):
        """更新表选择器"""
        self.table_spinner.values = tables
        if tables:
            self.table_spinner.text = '请选择表'
        else:
            self.table_spinner.text = '无可用表'
    
    def on_table_select(self, spinner, text):
        """表选择事件"""
        if text in self.tables_list:
            self.current_table = text
            self.refresh_data()
    
    def refresh_data(self, dt=None):
        """刷新数据"""
        if not self.current_table:
            self.show_popup("警告", "请先选择一个表")
            return
            
        def _refresh():
            if not self.check_connection():
                return
                
            try:
                with self.connection.cursor() as cursor:
                    # 检查表结构
                    cursor.execute(f"DESCRIBE `{self.current_table}`")
                    columns = [row[0] for row in cursor.fetchall()]
                    
                    # 构建查询语句
                    select_fields = ['id', 'cdk', 'data', 'imei']
                    
                    if 'Token' in columns:
                        select_fields.append('Token')
                    else:
                        select_fields.append('NULL as Token')
                    
                    select_fields.append('lasttime')
                    
                    if 'status' in columns:
                        select_fields.append('status')
                    else:
                        select_fields.append('1 as status')
                        
                    if 'createtime' in columns:
                        select_fields.append('createtime')
                    else:
                        select_fields.append('NULL as createtime')
                    
                    if 'nunmber' in columns:
                        select_fields.append('nunmber')
                    else:
                        select_fields.append('NULL as nunmber')
                    
                    query = f"SELECT {', '.join(select_fields)} FROM `{self.current_table}` ORDER BY id DESC LIMIT 50"
                    cursor.execute(query)
                    
                    data = []
                    for row in cursor.fetchall():
                        display_row = []
                        for i, value in enumerate(row):
                            if value is None:
                                display_row.append('')
                            elif isinstance(value, datetime):
                                display_row.append(value.strftime('%Y-%m-%d %H:%M:%S'))
                            elif i == len(row) - 1:  # nunmber字段
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
                        data.append(display_row)
                    
                    self.current_data = data
                    Clock.schedule_once(lambda dt: self.update_data_display(data), 0)
                    Clock.schedule_once(lambda dt: self.update_status(f"已加载 {len(data)} 条数据"), 0)
                    
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"加载数据失败：{str(e)}"), 0)
        
        threading.Thread(target=_refresh).start()
    
    def update_data_display(self, data):
        """更新数据显示"""
        self.data_layout.clear_widgets()
        
        if not data:
            self.data_layout.add_widget(Label(text='暂无数据', size_hint_y=None, height=dp(40)))
            return
        
        # 添加表头
        header_layout = BoxLayout(orientation='horizontal', size_hint_y=None, height=dp(35))
        headers = ['ID', '注册码', '到期时间', '设备', 'Token', '最后登录', '状态']
        header_widths = [dp(40), dp(120), dp(80), dp(80), dp(80), dp(80), dp(60)]
        
        for i, header in enumerate(headers):
            label = Label(text=header, size_hint_x=None, width=header_widths[i], 
                         bold=True, color=(1, 1, 1, 1))
            header_layout.add_widget(label)
        self.data_layout.add_widget(header_layout)
        
        # 添加数据行
        for row_data in data:
            row_layout = BoxLayout(orientation='horizontal', size_hint_y=None, height=dp(35))
            
            # 显示各列数据
            for i, value in enumerate(row_data[:7]):
                if i == 1:  # 注册码列，可以点击复制
                    display_text = str(value)[:10] + '...' if len(str(value)) > 10 else str(value)
                    btn = Button(text=display_text, size_hint_x=None, width=header_widths[i],
                                font_size=dp(12), background_color=(0.2, 0.2, 0.2, 1))
                    btn.bind(on_press=partial(self.copy_text, str(value)))
                    row_layout.add_widget(btn)
                else:
                    text = str(value)
                    if i == 2:  # 到期时间
                        text = text[:10] if len(text) > 10 else text
                    elif i in [3, 4, 5]:  # 设备、Token、最后登录
                        text = text[:8] + '...' if len(text) > 8 else text
                    elif i == 6:  # 状态
                        text = '启用' if text == '1' else '禁用'
                    
                    label = Label(text=text, size_hint_x=None, width=header_widths[i],
                                 font_size=dp(12), color=(0.9, 0.9, 0.9, 1))
                    row_layout.add_widget(label)
            
            self.data_layout.add_widget(row_layout)
    
    def generate_cdk_code(self, length=16):
        """生成注册码"""
        chars = string.ascii_uppercase + string.digits
        return ''.join(random.choice(chars) for _ in range(16))
    
    def generate_cdk(self, dt=None):
        """生成注册码"""
        if not self.current_table:
            self.show_popup("警告", "请先选择表")
            return
            
        def _generate():
            if not self.check_connection():
                return
                
            try:
                duration = float(self.duration_input.text)
                if duration <= 0:
                    Clock.schedule_once(lambda dt: self.show_popup("错误", "时长必须大于0"), 0)
                    return
                    
                unit = self.unit_spinner.text
                
                # 计算nunmber值
                if unit == "天":
                    nunmber_value = duration
                elif unit == "小时":
                    if duration > 9:
                        Clock.schedule_once(lambda dt: self.show_popup("错误", "小时数不能超过9"), 0)
                        return
                    nunmber_value = duration / 10
                else:
                    Clock.schedule_once(lambda dt: self.show_popup("错误", "无效的时间单位"), 0)
                    return
                    
            except ValueError:
                Clock.schedule_once(lambda dt: self.show_popup("错误", "请输入有效的时长"), 0)
                return
                
            try:
                cdk = self.generate_cdk_code()
                
                with self.connection.cursor() as cursor:
                    # 检查表结构
                    cursor.execute(f"DESCRIBE `{self.current_table}`")
                    columns = [row[0] for row in cursor.fetchall()]
                    
                    # 构建插入语句
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
                message = f"注册码生成成功！\n\n注册码：{cdk}\n时长：{duration}{unit_text}\n状态：未激活"
                Clock.schedule_once(lambda dt: self.show_copyable_popup("注册码生成成功", cdk), 0)
                Clock.schedule_once(self.refresh_data, 0.1)
                
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"生成注册码失败：{str(e)}"), 0)
        
        threading.Thread(target=_generate).start()
    
    def batch_generate_cdk(self, dt=None):
        """批量生成注册码"""
        if not self.current_table:
            self.show_popup("警告", "请先选择表")
            return
            
        def _batch_generate():
            if not self.check_connection():
                return
                
            try:
                batch_count = int(self.batch_count_input.text)
                if batch_count <= 0 or batch_count > 100:
                    Clock.schedule_once(lambda dt: self.show_popup("错误", "批量数量必须在1-100之间"), 0)
                    return
                    
                duration = float(self.duration_input.text)
                if duration <= 0:
                    Clock.schedule_once(lambda dt: self.show_popup("错误", "时长必须大于0"), 0)
                    return
                    
                unit = self.unit_spinner.text
                
                # 计算nunmber值
                if unit == "天":
                    nunmber_value = duration
                elif unit == "小时":
                    if duration > 9:
                        Clock.schedule_once(lambda dt: self.show_popup("错误", "小时数不能超过9"), 0)
                        return
                    nunmber_value = duration / 10
                else:
                    Clock.schedule_once(lambda dt: self.show_popup("错误", "无效的时间单位"), 0)
                    return
                    
            except ValueError:
                Clock.schedule_once(lambda dt: self.show_popup("错误", "请输入有效的数量和时长"), 0)
                return
            
            try:
                generated_cdks = []
                failed_count = 0
                
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
                            
                            generated_cdks.append(cdk)
                            
                        except Exception as e:
                            failed_count += 1
                            continue
                    
                    self.connection.commit()
                
                success_count = len(generated_cdks)
                message = f"批量生成完成！\n成功生成：{success_count} 个\n失败：{failed_count} 个"
                
                if success_count > 0:
                    # 显示生成的注册码
                    cdks_text = '\n'.join(generated_cdks[:10])  # 只显示前10个
                    if len(generated_cdks) > 10:
                        cdks_text += f'\n... 还有{len(generated_cdks)-10}个'
                    message += f"\n\n生成的注册码：\n{cdks_text}"
                    
                Clock.schedule_once(lambda dt: self.show_popup("完成", message), 0)
                Clock.schedule_once(self.refresh_data, 0.1)
                
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"批量生成失败：{str(e)}"), 0)
        
        threading.Thread(target=_batch_generate).start()
    
    def unbind_device(self, dt=None):
        """解绑设备"""
        if not self.current_table:
            self.show_popup("警告", "请先选择表")
            return
            
        cdk = self.unbind_input.text.strip()
        if not cdk:
            self.show_popup("错误", "请输入注册码")
            return
            
        def _unbind():
            if not self.check_connection():
                return
                
            try:
                with self.connection.cursor() as cursor:
                    # 检查表结构
                    cursor.execute(f"DESCRIBE `{self.current_table}`")
                    columns = [row[0] for row in cursor.fetchall()]
                    
                    # 构建更新语句
                    update_fields = []
                    if 'imei' in columns:
                        update_fields.append('imei = NULL')
                    if 'Token' in columns:
                        update_fields.append('Token = NULL')
                    
                    if not update_fields:
                        Clock.schedule_once(lambda dt: self.show_popup("警告", "表中没有找到imei或Token字段"), 0)
                        return
                    
                    # 执行更新
                    sql = f"UPDATE `{self.current_table}` SET {', '.join(update_fields)} WHERE cdk = %s"
                    cursor.execute(sql, (cdk,))
                    affected_rows = cursor.rowcount
                    self.connection.commit()
                    
                if affected_rows > 0:
                    Clock.schedule_once(lambda dt: self.show_popup("成功", f"设备解绑成功！\n注册码：{cdk}"), 0)
                    Clock.schedule_once(self.refresh_data, 0.1)
                    Clock.schedule_once(lambda dt: setattr(self.unbind_input, 'text', ''), 0)
                else:
                    Clock.schedule_once(lambda dt: self.show_popup("警告", "未找到该注册码"), 0)
                    
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"解绑失败：{str(e)}"), 0)
        
        threading.Thread(target=_unbind).start()
    
    def delete_cdk(self, dt=None):
        """删除注册码"""
        if not self.current_table:
            self.show_popup("警告", "请先选择表")
            return
            
        cdk = self.delete_input.text.strip()
        if not cdk:
            self.show_popup("错误", "请输入注册码")
            return
            
        # 创建确认对话框
        self.show_confirm_dialog(f"确定要删除注册码 {cdk} 吗？此操作不可恢复！", 
                                lambda: self._do_delete_cdk(cdk))
    
    def _do_delete_cdk(self, cdk):
        """执行删除注册码"""
        def _delete():
            if not self.check_connection():
                return
                
            try:
                with self.connection.cursor() as cursor:
                    cursor.execute(f"DELETE FROM `{self.current_table}` WHERE cdk = %s", (cdk,))
                    affected_rows = cursor.rowcount
                    self.connection.commit()
                    
                if affected_rows > 0:
                    Clock.schedule_once(lambda dt: self.show_popup("成功", f"注册码删除成功：{cdk}"), 0)
                    Clock.schedule_once(self.refresh_data, 0.1)
                    Clock.schedule_once(lambda dt: setattr(self.delete_input, 'text', ''), 0)
                else:
                    Clock.schedule_once(lambda dt: self.show_popup("警告", "未找到该注册码"), 0)
                    
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"删除失败：{str(e)}"), 0)
        
        threading.Thread(target=_delete).start()
    
    def query_cdk(self, dt=None):
        """查询注册码"""
        if not self.current_table:
            self.show_popup("警告", "请先选择表")
            return
            
        cdk = self.query_input.text.strip()
        if not cdk:
            self.show_popup("错误", "请输入注册码")
            return
            
        def _query():
            if not self.check_connection():
                return
                
            try:
                with self.connection.cursor() as cursor:
                    # 检查表结构
                    cursor.execute(f"DESCRIBE `{self.current_table}`")
                    columns = [row[0] for row in cursor.fetchall()]
                    
                    # 构建查询语句
                    select_fields = ['id', 'cdk', 'data', 'imei']
                    
                    if 'Token' in columns:
                        select_fields.append('Token')
                    else:
                        select_fields.append('NULL as Token')
                    
                    select_fields.append('lasttime')
                    
                    if 'status' in columns:
                        select_fields.append('status')
                    else:
                        select_fields.append('1 as status')
                        
                    if 'createtime' in columns:
                        select_fields.append('createtime')
                    else:
                        select_fields.append('NULL as createtime')
                    
                    if 'nunmber' in columns:
                        select_fields.append('nunmber')
                    else:
                        select_fields.append('NULL as nunmber')
                    
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
                    
                    Clock.schedule_once(lambda dt: self.show_query_result_popup("查询结果", info, result[1]), 0)
                else:
                    Clock.schedule_once(lambda dt: self.show_popup("警告", "未找到该注册码"), 0)
                    
            except Exception as e:
                Clock.schedule_once(lambda dt: self.show_popup("错误", f"查询失败：{str(e)}"), 0)
        
        threading.Thread(target=_query).start()
    
    def copy_text(self, text, dt=None):
        """复制文本到剪贴板"""
        try:
            from kivy.utils import platform
            if platform == 'android':
                from android.runnable import run_on_ui_thread
                from jnius import autoclass
                
                @run_on_ui_thread
                def copy_to_clipboard():
                    PythonActivity = autoclass('org.kivy.android.PythonActivity')
                    ClipboardManager = autoclass('android.content.ClipboardManager')
                    ClipData = autoclass('android.content.ClipData')
                    
                    activity = PythonActivity.mActivity
                    clipboard = activity.getSystemService(activity.CLIPBOARD_SERVICE)
                    clip = ClipData.newPlainText("label", text)
                    clipboard.setPrimaryClip(clip)
                
                copy_to_clipboard()
                self.show_popup("成功", f"已复制到剪贴板：{text}")
            else:
                # 桌面版本的复制功能
                import subprocess
                import sys
                
                success = False
                try:
                    if sys.platform == 'win32':
                        # Windows系统使用clip命令
                        subprocess.run(['clip'], input=text, text=True, check=True)
                        success = True
                    elif sys.platform == 'darwin':
                        # macOS系统使用pbcopy
                        subprocess.run(['pbcopy'], input=text, text=True, check=True)
                        success = True
                    elif sys.platform.startswith('linux'):
                        # Linux系统尝试使用xclip或xsel
                        try:
                            subprocess.run(['xclip', '-selection', 'clipboard'], input=text, text=True, check=True)
                            success = True
                        except (subprocess.CalledProcessError, FileNotFoundError):
                            try:
                                subprocess.run(['xsel', '--clipboard', '--input'], input=text, text=True, check=True)
                                success = True
                            except (subprocess.CalledProcessError, FileNotFoundError):
                                pass
                    
                    if success:
                        self.show_popup("成功", f"已复制到剪贴板：{text}")
                    else:
                        # 如果复制失败，显示可选择的文本
                        self.show_copyable_popup("复制内容", text)
                        
                except Exception as e:
                    print(f"复制失败: {e}")
                    self.show_copyable_popup("复制内容", text)
                    
        except Exception as e:
            print(f"复制功能异常: {e}")
            self.show_copyable_popup("复制内容", text)
    
    def show_copyable_popup(self, title, text):
        """显示可复制文本的弹窗"""
        content = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 说明标签
        info_label = Label(text='请手动复制以下内容：', size_hint_y=None, height=dp(30))
        content.add_widget(info_label)
        
        # 可选择的文本输入框
        text_input = TextInput(text=text, multiline=True, readonly=True, 
                              size_hint_y=None, height=dp(100))
        text_input.select_all()  # 自动选择所有文本
        content.add_widget(text_input)
        
        # 确定按钮
        btn_layout = BoxLayout(size_hint_y=None, height=dp(50))
        ok_btn = Button(text='确定')
        btn_layout.add_widget(ok_btn)
        content.add_widget(btn_layout)
        
        popup = Popup(title=title, content=content, size_hint=(0.8, 0.6))
        ok_btn.bind(on_press=popup.dismiss)
        popup.open()
        
        # 确保文本框获得焦点并选中文本
        def focus_text(dt):
            text_input.focus = True
            text_input.select_all()
        Clock.schedule_once(focus_text, 0.1)
    
    def show_query_result_popup(self, title, message, cdk):
        """显示查询结果弹窗，包含复制注册码功能"""
        content = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 消息标签
        label = Label(text=message, text_size=(dp(350), None), halign='left', valign='middle')
        content.add_widget(label)
        
        # 按钮布局
        btn_layout = BoxLayout(size_hint_y=None, height=dp(50), spacing=dp(10))
        
        # 复制注册码按钮
        copy_btn = Button(text='复制注册码')
        copy_btn.bind(on_press=lambda x: self.copy_text(cdk))
        btn_layout.add_widget(copy_btn)
        
        # 确定按钮
        ok_btn = Button(text='确定')
        btn_layout.add_widget(ok_btn)
        
        content.add_widget(btn_layout)
        
        popup = Popup(title=title, content=content, size_hint=(0.9, 0.7))
        ok_btn.bind(on_press=popup.dismiss)
        popup.open()
    
    def show_popup(self, title, message):
        """显示弹窗"""
        content = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 消息标签
        label = Label(text=message, text_size=(dp(300), None), halign='left', valign='middle')
        content.add_widget(label)
        
        # 确定按钮
        btn_layout = BoxLayout(size_hint_y=None, height=dp(50))
        ok_btn = Button(text='确定')
        btn_layout.add_widget(ok_btn)
        content.add_widget(btn_layout)
        
        popup = Popup(title=title, content=content, size_hint=(0.8, 0.6))
        ok_btn.bind(on_press=popup.dismiss)
        popup.open()
    
    def show_confirm_dialog(self, message, callback):
        """显示确认对话框"""
        content = BoxLayout(orientation='vertical', padding=dp(10), spacing=dp(10))
        
        # 消息标签
        label = Label(text=message, text_size=(dp(300), None), halign='left', valign='middle')
        content.add_widget(label)
        
        # 按钮布局
        btn_layout = BoxLayout(size_hint_y=None, height=dp(50), spacing=dp(10))
        
        cancel_btn = Button(text='取消')
        confirm_btn = Button(text='确定')
        
        btn_layout.add_widget(cancel_btn)
        btn_layout.add_widget(confirm_btn)
        content.add_widget(btn_layout)
        
        popup = Popup(title='确认', content=content, size_hint=(0.8, 0.4))
        
        cancel_btn.bind(on_press=popup.dismiss)
        confirm_btn.bind(on_press=lambda x: (popup.dismiss(), callback()))
        
        popup.open()
    
    def update_status(self, message):
        """更新状态栏"""
        self.status_label.text = message
    
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

if __name__ == '__main__':
    CDKManagerApp().run() 