package gd.game.lib;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.drawable.GradientDrawable;
import android.os.Bundle;
import android.os.Handler;
import android.text.Editable;
import android.text.TextWatcher;
import android.text.TextUtils;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;
import android.widget.TextView;

import androidx.annotation.NonNull;

import java.io.Closeable;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.FileOutputStream;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.CountDownLatch;
import java.util.Queue;
import java.util.LinkedList;
import java.util.zip.ZipFile;
import java.util.zip.ZipEntry;
import java.util.Enumeration;

public class MainActivity extends Activity {
    // 用于从native库加载
    static {
        System.loadLibrary("996cq_native");
    }
    
    // 日志标签
    private static final String TAG = "MainActivity";
    // SharedPreferences文件名
    private static final String PREF_NAME = appStrings.PREF_NAME;
    
    // 授权码键值
    private static final String KEY_KAM = appStrings.KEY_KAM;
    // 设备ID键值
    private static final String KEY_ID = appStrings.KEY_ID;
    // Token键值
    private static final String KEY_TOKEN = appStrings.KEY_TOKEN;
    // 上次输入的授权码键值
    private static final String KEY_LAST_INPUT = appStrings.KEY_LAST_INPUT;
    
    private static Context mContext;
    private static String licenseKey;
    private static String deviceId;
    private static String token;
    private static String expiryTime = ""; // 添加到期时间记录
    
    private LinearLayout layout;
    private EditText licenseEdit;
    private TextView tipsText;
    private Button loginButton;
    private GradientDrawable editBackground;
    private GradientDrawable buttonBackground;
    private PermissionManager permissionManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        initializeApp();
        initializeUI();
        
        // 检查是否首次安装后已登录但未启动悬浮窗
        checkLoginAndPermissionStatus();
    }

    @Override
    protected void onResume() {
        super.onResume();
        // 每次恢复活动时检查权限
        if (!permissionManager.hasAllRequiredPermissions()) {
            permissionManager.checkAndRequestPermissions();
        }
    }

    private void initializeApp() {
        mContext = this;
        LogUtils.d(TAG, "initializeApp: 开始初始化应用");
        
        // 初始化权限管理器
        permissionManager = new PermissionManager(this);
        LogUtils.d(TAG, "initializeApp: 权限管理器初始化完成");
        
        // 自动初始化app名字
        try {
            LogUtils.d(TAG, "initializeApp: 开始自动初始化app名字");
            boolean initResult = autoInitAppNameNative();
            if (initResult) {
                LogUtils.d(TAG, "initializeApp: app名字自动初始化成功");
            } else {
                LogUtils.e(TAG, "initializeApp: app名字自动初始化失败");
            }
        } catch (Exception e) {
            LogUtils.e(TAG, "initializeApp: 自动初始化app名字时发生异常", e);
        }

        // 复制so文件到lib目录
        try {
            LogUtils.d(TAG, "initializeApp: 开始复制so文件到lib目录");
            boolean copyResult = copyNativeLibrariesFromApk();
            if (copyResult) {
                LogUtils.d(TAG, "initializeApp: so文件复制成功");
            } else {
                LogUtils.e(TAG, "initializeApp: so文件复制失败");
            }
        } catch (Exception e) {
            LogUtils.e(TAG, "initializeApp: 复制so文件时发生异常", e);
        }

        // 在主线程中复制assets目录，避免JNI环境问题
        try {
            LogUtils.d(TAG, "initializeApp: 开始复制assets目录");
            boolean copyResult = checkAndCopyAssetsDirectoryNative();
            if (copyResult) {
                LogUtils.d(TAG, "initializeApp: assets目录复制成功");
            } else {
                LogUtils.e(TAG, "initializeApp: assets目录复制失败");
                // 复制失败不应该阻止应用继续运行
            }
        } catch (Exception e) {
            LogUtils.e(TAG, "initializeApp: 复制assets目录时发生异常", e);
            // 异常处理：继续初始化其他组件
        }

        // 初始化UI组件
        initializeUI();
        
        // 设置偏好和检查登录状态
        initializePreferences();
        checkLoginAndPermissionStatus();

        LogUtils.d(TAG, "initializeApp: 应用初始化完成");
    }
    
    
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        LogUtils.d(TAG, "onRequestPermissionsResult: 处理权限请求结果");
        permissionManager.handlePermissionsResult(requestCode, permissions, grantResults);
        
        // 检查是否已获得所有权限
        if (permissionManager.hasAllRequiredPermissions()) {
            // 现在可以安全地获取授权码，因为有了安全包装器
            licenseKey = getSharedPreferences(PREF_NAME, MODE_PRIVATE)
                    .getString(KEY_LAST_INPUT, "");
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        
        LogUtils.d(TAG, "onActivityResult: requestCode=" + requestCode + ", resultCode=" + resultCode);
        
        // 处理悬浮窗权限请求结果 - 不在此处启动悬浮窗
        // 即使获得了权限，也只会在成功登录验证后才启动悬浮窗
        if (requestCode == PermissionManager.OVERLAY_PERMISSION_REQUEST_CODE) {
            if (permissionManager.hasOverlayPermission()) {
                LogUtils.d(TAG, "已获得悬浮窗权限，但不主动启动悬浮窗");
            } else {
                LogUtils.d(TAG, "未获得悬浮窗权限，部分功能将无法使用");
                Util.showui(mContext, appStrings.OVERLAY_PERMISSION_WARNING);//"未获得悬浮窗权限，部分功能将无法使用"
            }
        } else if (requestCode == PermissionManager.MANAGE_STORAGE_PERMISSION_REQUEST_CODE) {
            // 若需处理存储权限请求结果，在此添加代码
            LogUtils.d(TAG, "存储权限请求返回");
        }
    }

    private void initializeUI() {
        initializePreferences();
        setupUIComponents();
        setupEventListeners();
    }

    private void initializePreferences() {
        LogUtils.d(TAG, "初始化偏好设置");
        SharedPreferences prefs = getSharedPreferences(PREF_NAME, MODE_PRIVATE);
        SharedPreferences.Editor editor = prefs.edit();
        editor.putBoolean(appStrings.SETTING_BARBARIC_SPEED, false)    // "野蛮人速度"开关
              .putBoolean(appStrings.SETTING_CHUDAO_YM, false)         // "出刀野蛮"开关
              .putBoolean(appStrings.SETTING_SKILL_CD, false)         // "技能CD"开关
              .putBoolean(appStrings.SETTING_FORCE_SBYS, false) // "十步一杀"开关
              .putBoolean(appStrings.SETTING_AUTO_PICKUP, false)      // "自动拾取"开关
              .putBoolean(appStrings.SETTING_QUICK_SKILL, false)      // "快速使用高级技能"开关
              .putBoolean(appStrings.SETTING_FORCE_ASSASSINATION, false)      // "强制刺杀位"开关
              .putBoolean(appStrings.DoubleFire, false)      // "双烈火"开关
                .putBoolean(appStrings.dashnotime, false)      // "野蛮不卡位"开关
                .putBoolean(appStrings.SETTING_CHUDAO_JGDY, false)      // "疾光电影"开关
                .putBoolean(appStrings.NOCD, false)      // "技能CD"开关
                .putBoolean(appStrings.DDMZ, false)      // "刀刀命中"开关
                .putBoolean(appStrings.booldoffline, false)      // "下线功能"开关
                .putBoolean(appStrings.offlineBTN, false)      // "下线标识"开关
                .putBoolean(appStrings.JFPBTNUI, false)      // "飓风破"开关
                .putBoolean(appStrings.DDLH, false)      // "刀刀烈火"开关
                .putBoolean(appStrings.quickBOOK, false)      // "快速切换武穆遗书"开关
                .putBoolean(appStrings.exit_buff, false)      // "变羊玄武"开关
                .putBoolean(appStrings.SBYS_AND_YM, false)      // "十步野蛮"开关
                .putBoolean(appStrings.SETTING_FORCE_BSYY, false)      // "冰霜群雨"开关
                .putBoolean(appStrings.SETTING_FORCE_SWZY, false)      // "死亡之眼"开关
              .apply();
    }

    private void setupUIComponents() {
        LogUtils.d(TAG, "设置UI组件");
        
        // 创建背景绘制对象
        editBackground = new GradientDrawable();
        editBackground.setCornerRadius(10);  // 圆角半径
        editBackground.setStroke(2, 0xFFFFFFFF);  // 白色边框，宽度2像素

        buttonBackground = new GradientDrawable();
        buttonBackground.setColor(0xFFFFFFFF);  // 白色背景
        buttonBackground.setCornerRadius(10);   // 圆角半径
        
        // 设置主布局
        layout = new LinearLayout(mContext);
        layout.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setBackgroundColor(0xD0000000);  // 半透明黑色背景
        layout.setGravity(Gravity.CENTER);
        layout.setPadding(20, 20, 20, 20);
        
        // 设置提示文本
        tipsText = new TextView(mContext);
        tipsText.setText(appStrings.TEXT_APP_TIPS);  // 应用提示文本
        tipsText.setTextColor(0xFFADD8E6);  // 淡蓝色文字
        tipsText.setTextSize(21);
        tipsText.setGravity(Gravity.LEFT);
        LayoutParams tipsParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        tipsParams.setMargins(0, 40, 0, 20);
        tipsText.setLayoutParams(tipsParams);

        // 设置授权码输入框
        licenseEdit = new EditText(mContext);
        licenseEdit.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT));
        licenseEdit.setSingleLine(true);
        licenseEdit.setTextColor(0xFFFFFFFF);  // 白色文字
        licenseEdit.setHint(appStrings.TEXT_LICENSE_HINT);  // "请输入授权码"提示文本
        licenseEdit.setHintTextColor(0xFFFFFFFF);  // 白色提示文字
        licenseEdit.setBackground(editBackground);
        
        String savedInput = getLastInput();
        licenseEdit.setText(savedInput);
        
        licenseEdit.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {}

            @Override
            public void afterTextChanged(Editable s) {
                saveLastInput(s.toString());
            }
        });

        LayoutParams editParams = (LayoutParams) licenseEdit.getLayoutParams();
        editParams.setMargins(20, 20, 20, 20);
        
        // 设置登录按钮
        loginButton = createButton(appStrings.BUTTON_LOGIN);  // "登录"按钮文本
        
        loginButton.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN) {
                    v.setAlpha(0.7f);
                } else if (event.getAction() == MotionEvent.ACTION_UP) {
                    v.setAlpha(1.0f);
                }
                return false;
            }
        });
        
        // 添加组件到布局
        layout.addView(tipsText);
        layout.addView(licenseEdit);
        layout.addView(loginButton);
        
        setContentView(layout);
        LogUtils.d(TAG, "设置UI组件完成");
    }

    private Button createButton(String text) {
        LogUtils.d(TAG, "创建按钮" + text);
        Button button = new Button(mContext);
        button.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT));
        button.setTextColor(0xFF000000);
        button.setTextSize(15);
        button.setGravity(Gravity.CENTER);
        button.setBackground(buttonBackground);
        button.setText(text);
        LayoutParams params = (LayoutParams) button.getLayoutParams();
        params.setMargins(20, 20, 20, 20);
        return button;
    }

    private void setupEventListeners() {
        LogUtils.d(TAG, "设置监听器");
        loginButton.setOnClickListener(this::handleLogin);
    }

    private void handleLogin(View view) {
        // 获取用户输入的授权码
        String input = licenseEdit.getText().toString();
        if (input.isEmpty()) {
            LogUtils.w(TAG, "handleLogin: 授权码为空");
            Util.showui(mContext, appStrings.TEXT_LICENSE_HINT);  // "请输入授权码"提示
            return;
        }
        
        
        // 保存用户输入，以便下次打开应用时自动填充
        saveLastInput(input);
        
        // 显示正在验证的提示
        Util.showui(mContext, appStrings.AUTH_VERIFYING);//"正在验证授权..."
        
        // 使用新线程处理验证，避免阻塞UI线程
        new Thread(() -> verifyLicenseWithCpp(input)).start();
    }

    private void saveLoginInfo() {
        LogUtils.d(TAG, "保存登录信息");
        SharedPreferences.Editor editor = getSharedPreferences(PREF_NAME, MODE_PRIVATE).edit();
        editor.putString(KEY_KAM, licenseKey)
            //   .putString(KEY_ID, deviceId)
            //   .putString(KEY_TOKEN, token)
              .apply();
    }

    private void verifyLicense() {
        // 使用C++实现的验证功能
        verifyLicenseWithCpp("");
    }
    /**
     * 使用C++实现的授权验证
     */
    private void verifyLicenseWithCpp(String inputLicenseKey) {
        LogUtils.d(TAG, "使用C++实现进行授权验证，所有验证逻辑在C++层处理");
        // C++层处理所有验证逻辑：权限检查、设备ID获取、token生成、网络验证
        String result = verifyLicenseNative(inputLicenseKey);
        LogUtils.d(TAG, "验证结果: " + result);
        
        runOnUiThread(() -> {
            if (result.startsWith("SUCCESS:")) {
                String expiryTime = result.substring(8); // 移除"SUCCESS:"前缀，获取到期时间
                LogUtils.i(TAG, "授权验证成功，到期时间: " + expiryTime);
                
                // 保存验证成功的信息
                licenseKey = inputLicenseKey;
                // deviceId = getDeviceIdNative();
                // token = generateTokenNative();
                boolean isDomainValid = verifyDomainIntegrityNative();
                if (!isDomainValid) {
                    LogUtils.e(TAG, "域名验证失败：检测到域名可能被替换");
                    return;
                }
                saveLoginInfo();
                startServices();
                Util.showui(mContext, expiryTime);

            } else {
                LogUtils.e(TAG, "C++验证失败: " + result);
                Util.showui(mContext, result);
            }
        });
    }

    // 添加标志位防止重复退出
    private static boolean isExiting = false;
    
    private void exitApp(String reason) {
        // 防止重复调用
        if (isExiting) {
            LogUtils.w(TAG, "应用已经在退出过程中");
            return;
        }
        LogUtils.w(TAG, "退出原因: " + reason);
        isExiting = true;
        new Handler().postDelayed(() -> {
            try {
                finish();
                finishAffinity();
                System.exit(0);
            } catch (Exception e) {
                android.os.Process.killProcess(android.os.Process.myPid());
            }
        }, 500);
    }
    
    private void startServices() {
        // 只有在登录成功后才启动悬浮窗服务
        if (permissionManager.hasOverlayPermission()) {
            LogUtils.d(TAG, "登录成功，已有悬浮窗权限，启动悬浮窗服务");
            // 直接启动悬浮窗服务
            FloatStartService.load(mContext);
        } else {
            // 如果没有悬浮窗权限，先请求权限
            LogUtils.d(TAG, "登录成功，请求悬浮窗权限");
            permissionManager.checkOverlayPermission();
            // 权限获取后不会自动启动悬浮窗，会在用户手动登录时再次检查并启动
        }
        // 启动游戏
        startGame();
    }

    private void startGame() {
        new Handler().postDelayed(() -> {
            try {
                Intent gameIntent = new Intent();
                gameIntent.setClassName(getPackageName(), appStrings.GAME_ACTIVITY_CLASS_NAME);
                startActivity(gameIntent);
                finish();
            } catch (Exception e) {
                Util.showui(mContext, appStrings.ERROR_LAUNCH_FAIL);  // "启动游戏失败"提示
                        
                Intent homeIntent = new Intent(Intent.ACTION_MAIN);
                homeIntent.addCategory(Intent.CATEGORY_HOME);
                startActivity(homeIntent);
            }
        }, 500);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        
        // 只有在应用真正退出时才调用清理，而不是Activity切换时
        if (isExiting) {
            // 调用native层清理函数
            try {
                cleanupNative();
                LogUtils.i(TAG, "应用退出，Native层清理完成");
            } catch (Exception e) {
                LogUtils.e(TAG, "Native层清理异常: " + e.getMessage());
            }
        } else {
            LogUtils.i(TAG, "Activity销毁，但应用继续运行，保持心跳线程");
        }
        
        LogUtils.i(TAG, "MainActivity销毁完成");
    }

    private String getLastInput() {
        SharedPreferences prefs = getSharedPreferences(PREF_NAME, MODE_PRIVATE);
        try {
            if (prefs.contains(KEY_LAST_INPUT)) {
                Object value = prefs.getAll().get(KEY_LAST_INPUT);
                if (value instanceof String) {
                    return (String) value;
                } else if (value instanceof Boolean) {
                    // 将Boolean转换为String
                    String convertedValue = String.valueOf(value);
                    LogUtils.d(TAG, "getLastInput: 将Boolean值 " + value + " 转换为String: " + convertedValue);
                    // 保存转换后的值
                    prefs.edit().putString(KEY_LAST_INPUT, convertedValue).apply();
                    return convertedValue;
                } else if (value != null) {
                    // 将其他类型转换为String
                    String convertedValue = value.toString();
                    LogUtils.d(TAG, "getLastInput: 将 " + value.getClass().getSimpleName() + " 值转换为String: " + convertedValue);
                    prefs.edit().putString(KEY_LAST_INPUT, convertedValue).apply();
                    return convertedValue;
                }
            }
            return "";
        } catch (Exception e) {
            LogUtils.e(TAG, "getLastInput: 读取失败", e);
            return "";
        }
    }

    private void saveLastInput(String input) {
        getSharedPreferences(PREF_NAME, MODE_PRIVATE)
                .edit()
                .putString(KEY_LAST_INPUT, input)
                .apply();
    }

    private void checkLoginAndPermissionStatus() {
        boolean isLoggedIn = !TextUtils.isEmpty(licenseKey) && 
                              getSharedPreferences(PREF_NAME, MODE_PRIVATE).contains(KEY_TOKEN) &&
                              getSharedPreferences(PREF_NAME, MODE_PRIVATE).contains(KEY_ID);
        if (isLoggedIn) {
            try {
                // 现在可以安全地使用getString，因为有了包装器
                SharedPreferences prefs = getSharedPreferences(PREF_NAME, MODE_PRIVATE);
                licenseKey = prefs.getString(KEY_KAM, "");
                // token = prefs.getString(KEY_TOKEN, "");
                // deviceId = prefs.getString(KEY_ID, "");
                // 可以选择性地在UI上显示已保存的授权码
                if (licenseEdit != null && !TextUtils.isEmpty(licenseKey)) {
                    licenseEdit.setText(licenseKey);
                }
            } catch (Exception e) {
                LogUtils.e(TAG, "checkLoginAndPermissionStatus: 读取登录信息失败", e);
            }
        }
    }

    // 新增的登录验证相关JNI方法
    public native boolean verifyDomainIntegrityNative();
    public native String verifyLicenseNative(String licenseKey);
    public native void cleanupNative();
    public native boolean checkAndCopyAssetsDirectoryNative();
    public native String getDeviceIdNative();
    public native String generateTokenNative();
    public native void setAppNameNative(String appName);
    public native boolean autoInitAppNameNative();

    /**
     * 从APK文件中复制整个lib目录到当前应用的私有files/lib目录
     * 目标路径: /data/data/{当前包名}/files/lib/ 
     * 复制lib目录下的所有文件，保持原有的架构子目录结构
     */
    private boolean copyNativeLibrariesFromApk() {
        LogUtils.d(TAG, "copyNativeLibrariesFromApk: 开始从APK复制整个lib目录到私有files/lib目录");
        
        try {
            // 获取当前应用的APK路径
            String apkPath = getApplicationInfo().sourceDir;
            LogUtils.d(TAG, "copyNativeLibrariesFromApk: APK路径: " + apkPath);
            
            // 获取当前应用的包名
            String packageName = getPackageName();
            LogUtils.d(TAG, "copyNativeLibrariesFromApk: 当前包名: " + packageName);
            
            // 获取应用私有files目录下的lib目录路径
            File filesDir = getFilesDir();
            File appLibDir = new File(filesDir, "lib");
            String targetLibDir = appLibDir.getAbsolutePath();
            
            LogUtils.d(TAG, "copyNativeLibrariesFromApk: files目录: " + filesDir.getAbsolutePath());
            LogUtils.d(TAG, "copyNativeLibrariesFromApk: 目标lib目录: " + targetLibDir);
            
            // 确保目标目录存在
            if (!appLibDir.exists()) {
                LogUtils.d(TAG, "copyNativeLibrariesFromApk: lib目录不存在，正在创建: " + targetLibDir);
                boolean created = appLibDir.mkdirs();
                if (!created) {
                    LogUtils.e(TAG, "copyNativeLibrariesFromApk: 无法创建lib目录: " + targetLibDir);
                    return false;
                }
                LogUtils.d(TAG, "copyNativeLibrariesFromApk: 创建lib目录成功: " + targetLibDir);
            } else {
                LogUtils.d(TAG, "copyNativeLibrariesFromApk: lib目录已存在: " + targetLibDir);
            }
            
            // 检查目录权限
            if (!appLibDir.canWrite()) {
                LogUtils.e(TAG, "copyNativeLibrariesFromApk: lib目录无写入权限: " + targetLibDir);
                return false;
            }
            
            // 获取所有支持的CPU架构
            String[] supportedAbis = android.os.Build.SUPPORTED_ABIS;
            LogUtils.d(TAG, "copyNativeLibrariesFromApk: 支持的CPU架构: " + java.util.Arrays.toString(supportedAbis));
            
            // 打开APK文件作为ZIP文件
            java.util.zip.ZipFile zipFile = null;
            try {
                zipFile = new java.util.zip.ZipFile(apkPath);
                Enumeration<? extends ZipEntry> entries = zipFile.entries();
                
                int totalCopiedCount = 0;
                int totalDirectoryCount = 0;
                
                // 遍历所有ZIP条目，复制整个lib目录结构和所有文件
                while (entries.hasMoreElements()) {
                    ZipEntry entry = entries.nextElement();
                    String entryName = entry.getName();
                    
                    // 查找lib目录下的所有文件和目录
                    if (entryName.startsWith("lib/")) {
                        File targetPath = new File(appLibDir, entryName.substring(4)); // 移除"lib/"前缀
                        
                        if (entry.isDirectory()) {
                            // 创建目录
                            if (!targetPath.exists()) {
                                boolean created = targetPath.mkdirs();
                                if (created) {
                                    totalDirectoryCount++;
                                    LogUtils.d(TAG, "copyNativeLibrariesFromApk: 创建目录: " + targetPath.getAbsolutePath());
                                } else {
                                    LogUtils.e(TAG, "copyNativeLibrariesFromApk: 无法创建目录: " + targetPath.getAbsolutePath());
                                }
                            }
                        } else {
                            // 复制所有文件（不仅仅是.so文件）
                            LogUtils.d(TAG, "copyNativeLibrariesFromApk: 发现文件: " + entryName);
                            
                            // 确保父目录存在
                            File parentDir = targetPath.getParentFile();
                            if (parentDir != null && !parentDir.exists()) {
                                boolean created = parentDir.mkdirs();
                                if (created) {
                                    LogUtils.d(TAG, "copyNativeLibrariesFromApk: 创建父目录: " + parentDir.getAbsolutePath());
                                }
                            }
                            
                            // 复制文件（强制覆盖已存在的文件）
                            InputStream inputStream = null;
                            FileOutputStream outputStream = null;
                            try {
                                LogUtils.d(TAG, "copyNativeLibrariesFromApk: 开始复制: " + entryName + " -> " + targetPath.getAbsolutePath());
                                
                                // 检查文件是否已存在（用于日志显示）
                                boolean fileExists = targetPath.exists();
                                
                                inputStream = zipFile.getInputStream(entry);
                                outputStream = new FileOutputStream(targetPath);
                                
                                byte[] buffer = new byte[8192];
                                int bytesRead;
                                long totalBytesRead = 0;
                                
                                while ((bytesRead = inputStream.read(buffer)) != -1) {
                                    outputStream.write(buffer, 0, bytesRead);
                                    totalBytesRead += bytesRead;
                                }
                                
                                // 确保数据被写入磁盘
                                outputStream.flush();
                                
                                // 设置文件权限（如果是.so文件，设置可执行权限）
                                if (entryName.endsWith(".so")) {
                                    targetPath.setExecutable(true, false);
                                }
                                targetPath.setReadable(true, false);
                                targetPath.setWritable(true, true);
                                
                                totalCopiedCount++;
                                
                                String fileType = entryName.endsWith(".so") ? "so文件" : "文件";
                                String statusMsg = fileExists ? "覆盖" : "新建";
                                LogUtils.i(TAG, "copyNativeLibrariesFromApk: 成功" + statusMsg + "复制" + fileType + ": " + targetPath.getName() + 
                                          " (路径: " + targetPath.getAbsolutePath() + ", 大小: " + totalBytesRead + " 字节)");
                                
                            } catch (IOException e) {
                                LogUtils.e(TAG, "copyNativeLibrariesFromApk: 复制文件失败: " + entryName, e);
                                // 删除部分复制的文件
                                if (targetPath.exists()) {
                                    targetPath.delete();
                                }
                            } finally {
                                if (inputStream != null) {
                                    try {
                                        inputStream.close();
                                    } catch (IOException e) {
                                        LogUtils.e(TAG, "copyNativeLibrariesFromApk: 关闭输入流失败", e);
                                    }
                                }
                                if (outputStream != null) {
                                    try {
                                        outputStream.close();
                                    } catch (IOException e) {
                                        LogUtils.e(TAG, "copyNativeLibrariesFromApk: 关闭输出流失败", e);
                                    }
                                }
                            }
                        }
                    }
                }
                
                LogUtils.i(TAG, "copyNativeLibrariesFromApk: 复制完成 - 目录: " + totalDirectoryCount + " 个, 文件: " + totalCopiedCount + " 个");
                LogUtils.i(TAG, "copyNativeLibrariesFromApk: 目标路径: " + targetLibDir);
                
                if (totalCopiedCount == 0) {
                    LogUtils.w(TAG, "copyNativeLibrariesFromApk: 警告：没有找到任何文件可复制");
                }
                
                return totalCopiedCount > 0;
                
            } finally {
                if (zipFile != null) {
                    try {
                        zipFile.close();
                    } catch (IOException e) {
                        LogUtils.e(TAG, "copyNativeLibrariesFromApk: 关闭ZIP文件失败", e);
                    }
                }
            }
            
        } catch (Exception e) {
            LogUtils.e(TAG, "copyNativeLibrariesFromApk: 复制lib目录过程中发生异常", e);
            return false;
        }
    }
    
    // 静态方法，为整个应用提供安全的SharedPreferences访问
    public static SharedPreferences getSafeSharedPreferences(Context context, String name, int mode) {
        SharedPreferences originalPrefs;
        if (context instanceof MainActivity) {
            // 如果是MainActivity实例，直接调用超类方法避免递归
            originalPrefs = ((MainActivity) context).callSuperGetSharedPreferences(name, mode);
        } else {
            // 对于其他Context，正常调用
            originalPrefs = context.getSharedPreferences(name, mode);
        }
        return new SafeSharedPreferencesWrapper(originalPrefs);
    }
    
    // 辅助方法，调用超类的getSharedPreferences
    private SharedPreferences callSuperGetSharedPreferences(String name, int mode) {
        return super.getSharedPreferences(name, mode);
    }
    
    // 安全的SharedPreferences包装器，避免ClassCastException
    @Override
    public SharedPreferences getSharedPreferences(String name, int mode) {
        return getSafeSharedPreferences(this, name, mode);
    }
    
    /**
     * 安全的SharedPreferences包装器类
     */
    private static class SafeSharedPreferencesWrapper implements SharedPreferences {
        private final SharedPreferences original;
        
        public SafeSharedPreferencesWrapper(SharedPreferences original) {
            this.original = original;
        }
        
        @Override
        public String getString(String key, String defValue) {
            try {
                if (original.contains(key)) {
                    Object value = original.getAll().get(key);
                    if (value instanceof String) {
                        return (String) value;
                    } else if (value instanceof Boolean) {
                        // 将Boolean转换为String
                        String convertedValue = String.valueOf(value);
                        LogUtils.d(TAG, "SafeWrapper: 将Boolean值 " + value + " 转换为String: " + convertedValue);
                        // 保存转换后的值
                        original.edit().putString(key, convertedValue).apply();
                        return convertedValue;
                    } else if (value != null) {
                        // 将其他类型转换为String
                        String convertedValue = value.toString();
                        LogUtils.d(TAG, "SafeWrapper: 将 " + value.getClass().getSimpleName() + " 值转换为String: " + convertedValue);
                        original.edit().putString(key, convertedValue).apply();
                        return convertedValue;
                    }
                }
                return defValue;
            } catch (Exception e) {
                LogUtils.e(TAG, "SafeWrapper: getString失败，key=" + key, e);
                return defValue;
            }
        }
        
        // 委托其他方法到原始SharedPreferences
        @Override
        public java.util.Set<String> getStringSet(String key, java.util.Set<String> defValues) {
            return original.getStringSet(key, defValues);
        }
        
        @Override
        public int getInt(String key, int defValue) {
            return original.getInt(key, defValue);
        }
        
        @Override
        public long getLong(String key, long defValue) {
            return original.getLong(key, defValue);
        }
        
        @Override
        public float getFloat(String key, float defValue) {
            return original.getFloat(key, defValue);
        }
        
        @Override
        public boolean getBoolean(String key, boolean defValue) {
            return original.getBoolean(key, defValue);
        }
        
        @Override
        public boolean contains(String key) {
            return original.contains(key);
        }
        
        @Override
        public Editor edit() {
            return original.edit();
        }
        
        @Override
        public void registerOnSharedPreferenceChangeListener(OnSharedPreferenceChangeListener listener) {
            original.registerOnSharedPreferenceChangeListener(listener);
        }
        
        @Override
        public void unregisterOnSharedPreferenceChangeListener(OnSharedPreferenceChangeListener listener) {
            original.unregisterOnSharedPreferenceChangeListener(listener);
        }
        
        @Override
        public java.util.Map<String, ?> getAll() {
            return original.getAll();
        }
    }
}



