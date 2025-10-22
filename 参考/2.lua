software_name = "";--[===[这里是软件名，权朗后台可以看到，是英文名不是中文名注意]===]
card = ""--[===[这里是卡密内容，注意如果有多个软件，要和软件对应上 ]===]

card_login = request("apiv3/card_login","software=".. software_name .."&card=" .. card);

if card_login.code == "0" then

    print("卡密登陆失败，失败原因是：" ..card_login.msg);
    exitScript()

end

print("登陆成功，卡密剩余时间是：" .. card_login.data.less_time );
print("登陆成功，卡密到期时间是：" .. card_login.data.endtime );

card_login_needle = card_login.data.needle;--[===[这个是卡密本次登陆的标识，退出登陆时候要用，一般不用写退出登陆代码的，不需要动 ]===]

function card_ping()

    card_ping_result = request("apiv3/card_ping","software=".. software_name  .."&card=".. card  .."&needle=" .. card_login_needle);

    if card_ping_result.code ~= "1" then

        print("卡密心跳失败，失败原因是：" .. card_ping_result.msg);

        setTimer(test_timer,100)

    end

    print("心跳成功，卡密剩余时间是：" .. card_ping_result.data.less_time );
    print("心跳成功，卡密到期时间是：" .. card_ping_result.data.endtime );

    sleep( card_ping_result.data.heartbeat_second * 1000 );--[===[这里是心跳间隔，是读取后台设置的，一般不要动就行了]===]

    card_ping();

end

function exit_script()
    exitScript()
end

beginThread( card_ping );--[===[这里是启动一个线程去不断执行心跳，这个不能丢，不然无法实时监测卡密状态]===]

--[===[这里往下就是写你自己的代码了，这里用一个while循环做例子，这个while可以去掉不要]===]

while(true)
do
    print("主线程")
    sleep(1000)
end
