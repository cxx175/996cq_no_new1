package load.tencent.lib;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Build;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Base64;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

public class Miscellaneous {
    private static final String TAG = "Miscellaneous";

    /*写出assets资源文件
     *例子:
    	写出assets资源文件(this,getFilesDir() + "/assets", "文件名");//这里写要写出的二进制文件
     */
    public static boolean writeAssetsResource(Context context, String outPath, String fileName) {
        LogUtils.d(TAG, "写入Assets文件: " + fileName + " 到 " + outPath);
        File dir = new File(outPath);
        if (!dir.exists() && !dir.mkdirs()) {
            LogUtils.e(TAG, "创建目录失败: " + dir.getAbsolutePath());
            return false;
        }

        File outFile = new File(dir, fileName);
        try (InputStream inputStream = context.getAssets().open(fileName);
             OutputStream outputStream = new FileOutputStream(outFile)) {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                outputStream.write(buffer, 0, bytesRead);
            }
            LogUtils.d(TAG, "写入文件成功");
            return true;
        } catch (IOException e) {
            LogUtils.e(TAG, "写入文件失败", e);
            return false;
        }
    }

    /**
     * 执行Shell命令的工具方法
     * 
     * 使用示例:
     * 1. 基本Shell命令执行:
     *    runShell("ls -l");
     * 
     * 2. 需要root权限的命令:
     *    // 申请root权限
     *    runShell("su");
     *    // 修改文件权限
     *    runShell("chmod 777 " + context.getFilesDir() + "/assets/executable");
     *    // 执行二进制文件
     *    runShell("su -c " + context.getFilesDir() + "/assets/executable");
     * 
     * @param shellCommand 要执行的Shell命令
     * @return 命令执行成功返回true，失败返回false
     */
    public static boolean runShell(String shellCommand) {
        LogUtils.d(TAG, "执行Shell命令开始: " + shellCommand);
        try {
            Process process = Runtime.getRuntime().exec(shellCommand);
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                LogUtils.d(TAG, "Shell命令输出: " + line);
            }
            int exitCode = process.waitFor();
            LogUtils.d(TAG, "Shell命令执行完成，退出码: " + exitCode);
            return exitCode == 0;
        } catch (IOException | InterruptedException e) {
            LogUtils.e(TAG, "Shell命令执行失败", e);
            return false;
        }
    }


    //点击返回桌面事件
    public static void 返回桌面(Context context) {
        LogUtils.d(TAG, "获取Home目录开始");
        Intent intent = new Intent(Intent.ACTION_MAIN);
        intent.addCategory(Intent.CATEGORY_HOME);
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        context.startActivity(intent);
        LogUtils.d(TAG, "获取Home目录完成");
    }

    //打开隐藏MIUI性能模式
    public static void 打开MIUI性能模式(Context context) {
        LogUtils.d(TAG, "检查MIUI系统开始");
        try {
            Intent intent = new Intent();
            intent.setComponent(new ComponentName("com.miui.powerkeeper", "com.miui.powerkeeper.ui.HiddenAppsConfigActivity"));
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            context.startActivity(intent);
            LogUtils.d(TAG, "检查MIUI系统完成");
        } catch (Exception e) {
            LogUtils.e(TAG, "检查MIUI系统失败", e);
        }
    }

    // 网络连接判断
    public static boolean 网络检测(Context context) {
        LogUtils.d(TAG, "检查网络状态开始");
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();
        boolean isConnected = networkInfo != null && networkInfo.isConnected();
        LogUtils.d(TAG, "网络状态: " + (isConnected ? "已连接" : "未连接"));
        return isConnected;
    }

    public static void StatusNavigationColor(Activity activity, int colorResId) {
        LogUtils.d(TAG, "检查系统状态开始");
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            Window window = activity.getWindow();
            window.addFlags(WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS);
            window.setStatusBarColor(activity.getResources().getColor(colorResId));
            window.setNavigationBarColor(activity.getResources().getColor(colorResId));
            LogUtils.d(TAG, "检查系统状态完成");
        } else {
            LogUtils.w(TAG, "系统版本过低");
        }
    }
}
