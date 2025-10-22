function request(api,param)

    center_id = "xxxx";--[===[这个是开发者id，在权朗网络网站上或者app里都能看到，5位数]===]
    api_password = "xxxxxx";--[===[这个是api密码，在权朗后台或者app的设置里面能看到]===]
    client_key = getDeviceId();--[===[这里是防破解专用的，这里默认是取了设备ID，如果觉得这个不靠谱可以被伪造，那么可以自行修改这个方法，只要能获取到设备的一个唯一标识就可以]===]
    net_reconnect_times = 30;--[===[这里是网络连接失败的重连次数，一般不用动。如果大批量用户经常出现连接服务器失败，那么可以把这个数值加大]===]
    timestamp = get_net_timestamp(0);--[===[这一行代码的意思是获取网络时间戳，如果淘宝的你觉得不适用，那么可以自行写一个函数去获取时间戳，不管是用什么网络时间戳或者本地方法，只要能获取到当前的时间戳就行]===]
    --[===[以下内容一般不要动,涉及加密算法，看不懂不要轻易动]===]
    api_list = {"https://napi.2cccc.cc/","http://api2.2cccc.cc/","http://api3.2cccc.cc/"};--[===[这里是服务器列表，如果你没有开独立服务器，那么不用动这里]===]
    client_key = MD5( api_password .. client_key .. timestamp );

    api_password = api_password .. client_key;

    sign = MD5(api_password .. timestamp);

    common_params = "center_id=" .. center_id .. "&tmstamp=" .. timestamp .. "&sign=" .. sign .. "&client_key=" .. client_key;

    connect_times = 0;

    response = "";

    while( string.sub(response,3,6) ~= "code" )
    do

        connect_times = connect_times + 1;

        host = api_list[ math.random(1, #api_list ) ];

        response = httpPost(host .. api,common_params .. "&" .. param);

        if string.sub(response,3,6) ~= "code" then

            print("连接登陆服务器失败，尝试重连");

            sleep(10000);

        end

        if connect_times > net_reconnect_times then

            print("连接登陆服务器失败，请检查您的网络")
            exitScript()

        end

    end

    result = jsonLib.decode( response );

    if result.code ~= "1" then

        return result;

    end

    if string.upper( result.sign ) ~= string.upper( MD5( string.sub(tostring(result.timestamp),0,10) .. api_password ) ) or math.abs(result.timestamp - timestamp) > 600 then

        table = {}

        table["code"] = "0";

        table["msg"] = "验证签名错误，请检查api密码是否正确";

        return table

    end

    return result;

end
--[===[这里是获取网络时间戳的函数，使用的是淘宝，如果你觉得淘宝的不靠谱或者不适用，那么自行修改这个函数即可，只要返回值是当前10位数实时时间戳就行，用什么方法都可以]===]
function get_net_timestamp(times)

    if times == 0 then

        timestamp_json = httpGet("https://api.m.taobao.com/rest/api3.do?api=mtop.common.getTimestamp");

        if string.sub(timestamp_json,0,2) == '{"' then

            print("获取淘宝时间戳成功")

            timestamp_table = jsonLib.decode(timestamp_json);

            return string.sub(timestamp_table.data.t,0,10);

            else

                print("获取淘宝时间戳失败，开始获取拼多多时间戳")

                return get_net_timestamp(times+1)

        end

    end

    if times == 1 then

        timestamp_json = httpGet("https://api.pinduoduo.com/api/server/_stm");

        if string.sub(timestamp_json,0,2) == '{"' then

            print("获取拼多多时间戳成功")

            timestamp_table = jsonLib.decode(timestamp_json);

            return string.sub(timestamp_table.server_time,0,10);

            else

                print("获取拼多多时间戳失败，开始获取世界时间戳")

                return get_net_timestamp(times+1)

        end

    end

    if times == 2 then

        timestamp_json = httpGet("https://worldtimeapi.org/api/timezone/Asia/Shanghai");

        if string.sub(timestamp_json,0,2) == '{"' then

            print("获取世界时间戳成功")

            timestamp_table = jsonLib.decode(timestamp_json);

            return string.sub(timestamp_table.unixtime,0,10);

            else

                print("获取世界时间戳失败，开始获取本地时间戳")

                return get_net_timestamp(times+1)

        end

    end

    if times == 3 then

        print("获取本地时间戳")

        return os.time()

    end

    taobao_timestamp_json = "";

    connect_times = 0;

    while(string.sub(taobao_timestamp_json,3,5) ~= "api")

    do

        connect_times = connect_times + 1

        taobao_timestamp_json = httpGet("https://api.m.taobao.com/rest/api3.do?api=mtop.common.getTimestamp");

        if string.sub(taobao_timestamp_json,3,5) ~= "api" then
            print("连接淘宝时间服务器失败，尝试重连");
            sleep(6000);
        end

        if connect_times > 10 then

            print("连接淘宝时间服务器失败，请检查您的网络")
            exitScript()

        end

    end

    taobao_timestamp_table = jsonLib.decode(taobao_timestamp_json);

    return string.sub(taobao_timestamp_table.data.t,0,10);


end
