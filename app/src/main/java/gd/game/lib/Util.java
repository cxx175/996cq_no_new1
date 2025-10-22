// DeviceInfoUtils.java - 设备信息相关工具
package gd.game.lib;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.PixelFormat;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.Base64;
import android.view.Gravity;
import android.view.WindowManager;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.io.FileWriter;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Util {
    private static final String TAG = "Util";
    public boolean isAvilible(Context context, String packageName) {
        LogUtils.d(TAG, "检查应用可用性: " + packageName);
        PackageManager packageManager = context.getPackageManager();
        List<PackageInfo> pinfo = packageManager.getInstalledPackages(0);
        List<String> pName = new ArrayList<String>();
        if (pinfo != null) {
            for (int i = 0; i < pinfo.size(); i++) {
                String pn = pinfo.get(i).packageName;
                pName.add(pn);
            }
        }
        boolean result = pName.contains(packageName);
        LogUtils.d(TAG, "检查应用可用性: " + (result ? "开启" : "关闭"));
        return result;
    }

    //调用事件S,运行二进制，等shell
    public static void RunShell(String shell) {
        LogUtils.d(TAG, "执行Shell命令: " + shell);
        String s = shell;
        try {
            Runtime.getRuntime().exec(s, null, null);//执行
            LogUtils.d(TAG, "执行Shell命令: " + "命令执行完成");
        } catch (Exception e) {
            LogUtils.e(TAG, "执行Shell命令失败", e);
        }
    }

    private static final int TOAST_MARGIN = 10; // Toast 之间的间距
    // 使用ArrayList替代Queue，便于按索引访问
    private static ArrayList<CustomToastView> toastList = new ArrayList<>();
    private static int toastCount = 0;
    private static WindowManager windowManager;

    public static void showui(Context context, String message) {
        LogUtils.d(TAG, "显示UI消息: " + message);
        
        // 检查是否有悬浮窗权限，如果没有则请求
        if (!Settings.canDrawOverlays(context)) {
            LogUtils.d(TAG, "检查悬浮窗权限");
            checkOverlayPermission(context);
        }
        
        // 检查是否有悬浮窗权限
        if (Settings.canDrawOverlays(context)) {
            // 有悬浮窗权限，使用自定义Toast
            if (windowManager == null) {
                windowManager = (WindowManager) context.getSystemService(Context.WINDOW_SERVICE);
            }

            // 创建自定义 Toast 视图
            CustomToastView customToastView = new CustomToastView(context, message);

            // 添加到列表并显示
            toastList.add(customToastView);
            toastCount++;
            updateToastPositions();

            // 设置定时器在一段时间后移除该 Toast
            new Handler().postDelayed(() -> {
                removeToast(customToastView);
            }, 3000); // 显示 3 秒
            LogUtils.d(TAG, "显示UI消息: " + "Toast显示完成");
        } else {
            // 没有悬浮窗权限，使用普通Toast
            LogUtils.d(TAG, "显示UI消息: " + "无悬浮窗权限");
            show(context, message);
        }
    }

    /**
     * 检查并请求悬浮窗权限
     * @param context 上下文
     * @return 是否有悬浮窗权限
     */
    public static boolean checkOverlayPermission(Context context) {
        LogUtils.d(TAG, "检查悬浮窗权限");
        if (!Settings.canDrawOverlays(context)) {
            LogUtils.d(TAG, "检查悬浮窗权限" + "无权限，跳转设置");
            try {
                // 跳转到设置页面，让用户手动授权
                android.content.Intent intent = new android.content.Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION);
                intent.setData(android.net.Uri.parse(appStrings.PACKAGE_URI_PREFIX + context.getPackageName()));
                intent.addFlags(android.content.Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(intent);
                show(context, appStrings.UTIL_DESCRIPTION);
                return false;
            } catch (Exception e) {
                LogUtils.e(TAG, "检查悬浮窗权限失败", e);
                return false;
            }
        }
        LogUtils.d(TAG, "检查悬浮窗权限" + "已有权限");
        return true;
    }

    private static void updateToastPositions() {
        int yPosition = 0;
        
        // 从列表的最后一个(最新的)开始布局，一直到第一个(最旧的)
        for (int i = toastList.size() - 1; i >= 0; i--) {
            CustomToastView toast = toastList.get(i);
            WindowManager.LayoutParams params = (WindowManager.LayoutParams) toast.getLayoutParams();
            
            // 设置Y坐标，最新的在底部，旧消息在上方
            params.y = yPosition;
            
            try {
                windowManager.updateViewLayout(toast, params);
            } catch (Exception e) {
                LogUtils.e(TAG, "更新Toast位置失败: " + e.getMessage());
            }
            
            // 下一个Toast的Y位置 = 当前Toast的Y位置 + 当前Toast的高度 + 间距
            yPosition += toast.getViewHeight() + TOAST_MARGIN;
        }
    }

    private static void removeToast(CustomToastView toast) {
        if (toastList.remove(toast)) {
            toastCount--;
            try {
                windowManager.removeViewImmediate(toast);
            } catch (Exception e) {
                LogUtils.e(TAG, "移除Toast视图失败: " + e.getMessage());
            }
            updateToastPositions();
        }
    }

    private static class CustomToastView extends LinearLayout {
        private int viewHeight = 0;

        public CustomToastView(Context context, String message) {
            super(context);

            setOrientation(VERTICAL);
            setBackground(createBackground());

            TextView textView = new TextView(context);
            textView.setText(message);
            textView.setTextColor(0xFFFFFFFF); // 文字颜色
            textView.setPadding(20, 20, 20, 20); // 内边距
            textView.setGravity(Gravity.CENTER);

            addView(textView);
            
            // 测量视图以获取高度
            int widthMeasureSpec = MeasureSpec.makeMeasureSpec(0, MeasureSpec.UNSPECIFIED);
            int heightMeasureSpec = MeasureSpec.makeMeasureSpec(0, MeasureSpec.UNSPECIFIED);
            measure(widthMeasureSpec, heightMeasureSpec);
            viewHeight = getMeasuredHeight();

            try {
                WindowManager.LayoutParams params = new WindowManager.LayoutParams(
                        WindowManager.LayoutParams.WRAP_CONTENT,
                        WindowManager.LayoutParams.WRAP_CONTENT,
                        WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY,
                        WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN,
                        PixelFormat.TRANSLUCENT);
                params.gravity = Gravity.BOTTOM | Gravity.END; // 修改为右下角
                params.x = 16;
                params.y = 16; // 距离底部的初始距离

                windowManager.addView(this, params);
                
                // 添加后立即更新所有Toast位置
                post(() -> updateToastPositions());
            } catch (Exception e) {
                LogUtils.e(TAG, "显示Toast失败", e);
                // 发生异常时移除该Toast避免内存泄漏
                if (toastList.contains(this)) {
                    toastList.remove(this);
                    toastCount--;
                }
            }
        }
        
        public int getViewHeight() {
            if (viewHeight > 0) {
                return viewHeight;
            }
            return getMeasuredHeight();
        }

        private GradientDrawable createBackground() {
            GradientDrawable drawable = new GradientDrawable();
            drawable.setColor(0xCEFF8A00); // 背景颜色
            drawable.setCornerRadius(40); // 圆角幅度
            drawable.setStroke(3, 0xFF000000); // 边框厚度与颜色
            return drawable;
        }
    }
    
    public static void show(final Context context, final String str) {
        LogUtils.d(TAG, "显示UI消息: " + str);
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                Toast.makeText(context, str, Toast.LENGTH_SHORT).show();
                LogUtils.d(TAG, "显示UI消息: " + "Toast显示完成");
            }
        });
    }

    //获取ass文件夹图像的方法
    public static Drawable getAssetsDraw(Context context, String drawFileName) {
        LogUtils.d(TAG, "获取Assets资源开始: " + drawFileName);
        try {
            InputStream is = context.getAssets().open(drawFileName);
            Drawable drawable = Drawable.createFromStream(is, null);
            LogUtils.d(TAG, "获取Assets资源完成");
            return drawable;
        } catch (IOException e) {
            LogUtils.e(TAG, "获取Assets资源失败", e);
            return null;
        }
    }

    //用于Base64图像解码 并返回解出的位图 通常设置base64编码的图片用到
    public static Bitmap getImageBase64Jie(String base64) {
        LogUtils.d(TAG, "Base64编码开始");
        try {
            byte[] decodedBytes = Base64.decode(base64, Base64.DEFAULT);
            Bitmap bitmap = BitmapFactory.decodeByteArray(decodedBytes, 0, decodedBytes.length);
            LogUtils.d(TAG, "Base64编码完成");
            return bitmap;
        } catch (Exception e) {
            LogUtils.e(TAG, "Base64编码失败", e);
            return null;
        }
    }
    public static String generateTimestampHash() {
        try {
            long timestamp = System.currentTimeMillis();
            double randomSalt = Math.random() * 1000000;
            String input = timestamp + "-" + randomSalt;
            
            MessageDigest md = MessageDigest.getInstance(appStrings.SHA_256_ALGORITHM);
            byte[] hashBytes = md.digest(input.getBytes());
            
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) {
                    hexString.append('0');
                }
                hexString.append(hex);
            }
            
            String result = hexString.toString();
            // 确保结果长度至少为16位
            if (result.length() >= 16) {
                return result.substring(0, 16);
            } else {
                // 如果长度不足，用0填充到16位
                return String.format("%-16s", result).replace(' ', '0');
            }
        } catch (NoSuchAlgorithmException e) {
            LogUtils.e(TAG, "Failed to generate timestamp hash: " + e.getMessage());
            // 返回一个安全的默认值，避免StringIndexOutOfBoundsException
            long timestamp = System.currentTimeMillis();
            String fallback = String.valueOf(timestamp);
            // 确保返回16位字符串
            if (fallback.length() >= 16) {
                return fallback.substring(0, 16);
            } else {
                return String.format("%-16s", fallback).replace(' ', '0');
            }
        } catch (Exception e) {
            LogUtils.e(TAG, "Unexpected error in generateTimestampHash: " + e.getMessage());
            // 最终的安全回退值
            return appStrings.DEFAULT_HASH_VALUE; // 16个0
        }
    }

    /**
     * 解析日期字符串为毫秒时间戳
     * @param dateString 日期字符串，格式为yyyy-MM-dd HH:mm:ss
     * @return 毫秒时间戳，如果解析失败则返回0
     */
    public static long parseExpiryDate(String dateString) {
        if (TextUtils.isEmpty(dateString)) {
            LogUtils.e(TAG, "解析到期时间失败: 日期字符串为空");
            return 0;
        }
        
        // 预处理日期字符串，去除前缀和不需要的字符
        String cleanDateString = dateString;
        String expiryPrefix = appStrings.EXPIRY_TIME_TEXT;
        
        // 去除"到期时间:"前缀
        if (cleanDateString.contains(expiryPrefix)) {
            cleanDateString = cleanDateString.replace(expiryPrefix, "").trim();
        }
        
        // 移除可能存在的引号和冒号前缀，例如 ":2025-05-17 07:41:16"
        if (cleanDateString.startsWith("\":") || cleanDateString.startsWith(":")) {
            // 找到日期格式开始的位置（第一个数字）
            int startIndex = -1;
            for (int i = 0; i < cleanDateString.length(); i++) {
                if (Character.isDigit(cleanDateString.charAt(i))) {
                    startIndex = i;
                    break;
                }
            }
            
            if (startIndex > 0) {
                cleanDateString = cleanDateString.substring(startIndex).trim();
            }
        }
        
        // 移除可能存在的结尾引号
        if (cleanDateString.endsWith("\"")) {
            cleanDateString = cleanDateString.substring(0, cleanDateString.length() - 1).trim();
        }
        
        LogUtils.d(TAG, "解析到期时间: 清理后的日期字符串 = [" + cleanDateString + "]");
        
        try {
            // 尝试使用SimpleDateFormat解析，更可靠
            java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat(appStrings.DATE_FORMAT_PATTERN, java.util.Locale.getDefault());
            java.util.Date date = sdf.parse(cleanDateString);
            if (date != null) {
                LogUtils.d(TAG, "解析到期时间成功: " + sdf.format(date) + " -> " + date.getTime());
                return date.getTime();
            }
            
            // 如果SimpleDateFormat解析失败，使用手动解析方式作为备用
            String[] parts = cleanDateString.split(" ");
            if (parts.length >= 2) {
                String[] dateParts = parts[0].split("-");
                String[] timeParts = parts[1].split(":");
                
                if (dateParts.length >= 3 && timeParts.length >= 3) {
                    int year = Integer.parseInt(dateParts[0]);
                    int month = Integer.parseInt(dateParts[1]) - 1; // 月份从0开始
                    int day = Integer.parseInt(dateParts[2]);
                    
                    int hour = Integer.parseInt(timeParts[0]);
                    int minute = Integer.parseInt(timeParts[1]);
                    int second = Integer.parseInt(timeParts[2]);
                    
                    java.util.Calendar calendar = java.util.Calendar.getInstance();
                    calendar.set(year, month, day, hour, minute, second);
                    long time = calendar.getTimeInMillis();
                    LogUtils.d(TAG, "手动解析到期时间成功: " + year + "-" + (month+1) + "-" + day + " " +
                             hour + ":" + minute + ":" + second + " -> " + time);
                    return time;
                }
            }
            
            LogUtils.e(TAG, "解析到期时间失败: 格式不正确 - " + cleanDateString);
            return 0;
        } catch (Exception e) {
            LogUtils.e(TAG, "解析到期时间失败: " + e.getMessage() + " - 原始字符串: [" + dateString + "], 清理后: [" + cleanDateString + "]");
            return 0;
        }
    }
    
    /**
     * 检查授权是否过期
     * @param expiryDateString 到期时间字符串
     * @return 是否已过期
     */
    public static boolean isAuthExpired(String expiryDateString) {
        if (TextUtils.isEmpty(expiryDateString)) {
            return true;
        }
        
        long expiryTime = parseExpiryDate(expiryDateString);
        if (expiryTime <= 0) {
            LogUtils.e(TAG, "检查授权状态失败: 无法解析到期时间");
            return true; // 解析失败视为过期
        }
        
        long currentTime = System.currentTimeMillis();
        boolean isExpired = currentTime > expiryTime;
        
        if (isExpired) {
            LogUtils.w(TAG, "授权已过期! 当前时间: " + formatDate(currentTime) + ", 到期时间: " + formatDate(expiryTime));
        } else {
            LogUtils.d(TAG, "授权有效. 当前时间: " + formatDate(currentTime) + ", 到期时间: " + formatDate(expiryTime));
        }
        
        return isExpired;
    }
    
    /**
     * 将时间戳格式化为日期字符串
     * @param timestamp 时间戳（毫秒）
     * @return 格式化的日期字符串
     */
    private static String formatDate(long timestamp) {
        java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat(appStrings.DATE_FORMAT_PATTERN, java.util.Locale.getDefault());
        return sdf.format(new java.util.Date(timestamp));
    }

}


