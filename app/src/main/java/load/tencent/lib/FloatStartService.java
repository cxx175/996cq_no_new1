package load.tencent.lib;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.provider.Settings;

public class FloatStartService {
    private static final String TAG = "FloatStartService";

    public static void load(Context context) {
        LogUtils.d(TAG, "悬浮服务加载开始");
        
        if (!hasOverlayPermission(context)) {
            LogUtils.d(TAG, "请求悬浮窗权限");
            applyOverlayPermission(context);
            return;
        }
        
        LogUtils.d(TAG, "悬浮服务启动");
        context.startService(new Intent(context, FloatServiceView.class));
        
        if (context instanceof Activity) {
            LogUtils.d(TAG, "请求存储权限");
            requestStoragePermission((Activity) context);
        }
    }

    public static void requestStoragePermission(Activity activity) {
        LogUtils.d(TAG, "检查存储权限");
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            String[] permissions = {
                    Manifest.permission.READ_EXTERNAL_STORAGE,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE
            };
            if (activity.checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED ||
                    activity.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                LogUtils.d(TAG, "请求存储权限");
                activity.requestPermissions(permissions, 102);
            } else {
                LogUtils.d(TAG, "已有存储权限");
            }
        }
    }

    private static boolean hasOverlayPermission(Context context) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            boolean hasPermission = Settings.canDrawOverlays(context);
            LogUtils.d(TAG, "检查悬浮窗权限: " + (hasPermission ? "已有悬浮窗权限" : "无悬浮窗权限"));
            return hasPermission;
        }
        return true;
    }

    private static void applyOverlayPermission(Context context) {
        LogUtils.d(TAG, "打开设置页面");
        if (context instanceof Activity) {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                    Uri.parse(appStrings.PACKAGE_URI_PREFIX + context.getPackageName()));
            ((Activity) context).startActivityForResult(intent, PermissionManager.OVERLAY_PERMISSION_REQUEST_CODE);
        } else {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                    Uri.parse(appStrings.PACKAGE_URI_PREFIX + context.getPackageName()));
            intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            context.startActivity(intent);
        }
    }
}
