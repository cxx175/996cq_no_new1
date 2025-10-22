import requests,time,random,hashlib,threading

center_id = 812700; #开发者id
api_password = '124600'; #api密码
software = 'QLBT'; #软件名称
card = '4V52UYJRUQ'; #卡密

local_storage = {}

def get_net_timestamp(platform='taobao'):
    if platform == 'taobao':
        try:
            res = requests.get('https://api.m.taobao.com/rest/api3.do?api=mtop.common.getTimestamp', timeout=5)
            obj = res.json()
        except Exception as e:
            obj = None
        if not obj or 'data' not in obj:
            print('获取淘宝时间戳失败，开始获取拼多多时间戳')
            return get_net_timestamp('pdd')
        else:
            print('获取淘宝时间戳成功')
            return int(str(obj['data']['t'])[:10])

    elif platform == 'pdd':
        try:
            res = requests.get('https://api.pinduoduo.com/api/server/_stm', timeout=5)
            obj = res.json()
        except Exception as e:
            obj = None
        if not obj or 'server_time' not in obj:
            print('获取拼多多时间戳失败，开始获取世界时间戳')
            return get_net_timestamp('world')
        else:
            print('获取拼多多时间戳成功')
            return int(str(obj['server_time'])[:10])

    elif platform == 'world':
        try:
            res = requests.get('https://worldtimeapi.org/api/timezone/Asia/Shanghai', timeout=5)
            obj = res.json()
        except Exception as e:
            obj = None
        if not obj or 'unixtime' not in obj:
            print('获取世界时间戳失败，开始获取本地时间戳')
            return get_net_timestamp('local')
        else:
            print('获取世界时间戳成功')
            return int(obj['unixtime'])

    else:
        print('获取本地时间戳')
        return int(time.time())


def hex_md5(s):
    return hashlib.md5(s.encode('utf-8')).hexdigest()

def ql_request(api, param):
    api_list = [
        'https://napi.2cccc.cc/',
        'http://api2.2cccc.cc/',
        'http://api3.2cccc.cc/'
    ]

    connect_server_times = 0
    server_return_json = ''

    # 添加全局参数
    param['center_id'] = center_id
    param['software'] = software

    while True:
        if connect_server_times > 0:
            time.sleep(6)
        if connect_server_times > 20:
            print('连接服务器失败，请检查网络或联系管理员')
            return [False, '连接服务器失败，请检查网络或联系管理员']

        api_complete_path = random.choice(api_list) + api
        connect_server_times += 1
        print(f'尝试第【{connect_server_times}】次连接服务器')

        # 获取时间戳
        timestamp = get_net_timestamp('taobao')
        param['timestamp'] = timestamp
        param['sign'] = hex_md5(api_password + str(timestamp))
        
        # 添加调试输出 - 显示发送的参数
        print(f"\n=== 调试信息 - API请求 ===")
        print(f"API接口: {api}")
        print(f"完整URL: {api_complete_path}")
        print(f"发送参数:")
        for key, value in param.items():
            print(f"  {key}: {value}")
        print(f"========================\n")

        try:
            response = requests.post(api_complete_path, data=param, timeout=10)
            server_return_json = response.text
        except Exception as e:
            server_return_json = ''

        if server_return_json[2:6] == "code":
            break

    try:
        server_return_data = response.json()
    except Exception:
        return [False, '返回数据格式错误']

    if server_return_data.get('code') == 0:
        return [False, server_return_data.get('msg', '未知错误')]

    # 签名校验
    server_sign = server_return_data.get('sign', '')
    server_timestamp = server_return_data.get('timestamp', 0)

    valid_sign = hex_md5(str(server_timestamp) + api_password)
    time_diff = abs(int(timestamp) - int(server_timestamp))

    if server_sign != valid_sign or time_diff > 600:
        return [False, '算法验证错误，请联系管理员']

    return [True, server_return_data.get('data')]

def card_ping():
    while True:
        print("\n--- 开始心跳验证请求 ---")
        ping_result = ql_request('apiv3/card_ping', {
            'card': card,
            'needle': local_storage.get('card_login_needle', '')
        })
        print("--- 心跳验证请求结束 ---\n")

        if ping_result[0]:
            print('最新的卡密到期时间：', ping_result[1]['endtime'])
            print('最新的卡密剩余时间：', ping_result[1]['less_time'])
            heartbeat_sec = int(ping_result[1].get('heartbeat_second', 60))
            time.sleep(heartbeat_sec)
        else:
            print('心跳失败，失败原因是：', ping_result[1])
            break  # 心跳失败后退出循环，线程自然结束

def card_login():
    global card
    print("\n--- 开始登录验证请求 ---")
    result = ql_request('apiv3/card_login', {'card': card})
    print("--- 登录验证请求结束 ---\n")
    
    if result[0]:
        print('卡密到期时间：', result[1]['endtime'])
        print('卡密剩余时间：', result[1]['less_time'])
        print('卡密类型为：', result[1]['type'])

        # 存储 needle 并启动心跳线程
        local_storage['card_login_needle'] = result[1]['needle']
        threading.Thread(target=card_ping, daemon=True).start()
    else:
        print('卡密登录失败，失败原因是：', result[1])

# 执行登录
card_login()

while(True):

    time.sleep(1);

    print('主线程')
