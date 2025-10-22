package gd.game.lib;

import android.Manifest;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.provider.Settings;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.util.ArrayList;
import java.util.List;

public class PermissionManager {
    private static final String TAG = "PermissionManager";
    private final Activity activity;
    private static final int PERMISSION_REQUEST_CODE = 1001;
    public static final int OVERLAY_PERMISSION_REQUEST_CODE = 1002;
    public static final int MANAGE_STORAGE_PERMISSION_REQUEST_CODE = 1003;

    // 需要请求的权限列表
    private static final String[] REQUIRED_PERMISSIONS = {
            Manifest.permission.READ_PHONE_STATE,
            Manifest.permission.READ_EXTERNAL_STORAGE,
            Manifest.permission.WRITE_EXTERNAL_STORAGE,
            Manifest.permission.INTERNET,
            Manifest.permission.ACCESS_NETWORK_STATE
    };

    public PermissionManager(Activity activity) {
        this.activity = activity;
        LogUtils.d(TAG, "权限管理器初始化");
    }

    public void checkAndRequestPermissions() {
        LogUtils.d(TAG, "开始检查权限");
        
        // 首先展示权限请求说明对话框
        showPermissionExplanationDialog();
    }
    
    private void showPermissionExplanationDialog() {
        new AlertDialog.Builder(activity)
                .setTitle(appStrings.PERMISSION_REQUEST_TITLE)
                .setMessage(appStrings.PERMISSION_REQUEST_MESSAGE)
                .setPositiveButton(appStrings.PERMISSION_START_AUTH, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        startPermissionRequest();
                    }
                })
                .setCancelable(false)
                .show();
    }
    
    private void startPermissionRequest() {
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.M) {
            LogUtils.d(TAG, "无需动态权限检查");
            return;
        }

        // 首先检查存储权限
        if (!hasStoragePermission()) {
            requestStoragePermission();
            return;
        }

        List<String> permissionsToRequest = new ArrayList<>();
        for (String permission : REQUIRED_PERMISSIONS) {
            if (ContextCompat.checkSelfPermission(activity, permission) 
                    != PackageManager.PERMISSION_GRANTED) {
                permissionsToRequest.add(permission);
            }
        }

        if (!permissionsToRequest.isEmpty()) {
            LogUtils.d(TAG, "需要请求权限: " + permissionsToRequest);
            ActivityCompat.requestPermissions(
                    activity,
                    permissionsToRequest.toArray(new String[0]),
                    PERMISSION_REQUEST_CODE
            );
        } else {
            LogUtils.d(TAG, "已拥有所有权限");
            checkOverlayPermission();
        }
    }

    /**
     * 请求存储权限
     */
    public void requestStoragePermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            // Android 11及以上使用MANAGE_EXTERNAL_STORAGE权限
            if (!Environment.isExternalStorageManager()) {
                try {
                    showStoragePermissionDialog();
                    Intent intent = new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION);
                    intent.addCategory(appStrings.ANDROID_CATEGORY_DEFAULT);
                    intent.setData(Uri.parse(String.format("package:%s", activity.getPackageName())));
                    activity.startActivityForResult(intent, MANAGE_STORAGE_PERMISSION_REQUEST_CODE);
                } catch (Exception e) {
                    LogUtils.e(TAG, "请求存储权限失败: " + e.getMessage());
                    // 如果上面的方式失败，尝试使用通用的设置页面
                    try {
                        Intent intent = new Intent(Settings.ACTION_MANAGE_ALL_FILES_ACCESS_PERMISSION);
                        activity.startActivityForResult(intent, MANAGE_STORAGE_PERMISSION_REQUEST_CODE);
                    } catch (Exception ex) {
                        showStoragePermissionDeniedDialog();
                    }
                }
            } else {
                // 已有存储权限，继续请求其他权限
                startPermissionRequest();
            }
        } else {
            // Android 10及以下使用WRITE_EXTERNAL_STORAGE权限
            if (activity.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) 
                    != PackageManager.PERMISSION_GRANTED) {
                showStoragePermissionDialog();
                ActivityCompat.requestPermissions(
                    activity,
                    new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                    PERMISSION_REQUEST_CODE
                );
            } else {
                // 已有存储权限，继续请求其他权限
                startPermissionRequest();
            }
        }
    }

    private void showStoragePermissionDialog() {
        new AlertDialog.Builder(activity)
                .setTitle(appStrings.STORAGE_PERMISSION_TITLE)
                .setMessage(appStrings.STORAGE_PERMISSION_MESSAGE)
                .setPositiveButton(appStrings.BUTTON_CONFIRM, null)
                .show();
    }

    private void showStoragePermissionDeniedDialog() {
        new AlertDialog.Builder(activity)
                .setTitle(appStrings.STORAGE_PERMISSION_TITLE)
                .setMessage(appStrings.STORAGE_PERMISSION_DENIED)
                .setPositiveButton(appStrings.BUTTON_GO_SETTINGS, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent = new Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
                        intent.setData(Uri.parse(appStrings.PACKAGE_URI_PREFIX + activity.getPackageName()));
                        activity.startActivity(intent);
                    }
                })
                .setNegativeButton(appStrings.BUTTON_RETRY, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        requestStoragePermission();
                    }
                })
                .setCancelable(false)
                .show();
    }

    public void checkOverlayPermission() {
        LogUtils.d(TAG, "检查悬浮窗权限");
        
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if (!Settings.canDrawOverlays(activity)) {
                LogUtils.d(TAG, "需要悬浮窗权限");
                showOverlayPermissionDialog();
            } else {
                LogUtils.d(TAG, "已有悬浮窗权限" + ": 已有悬浮窗权限");
                // 如果已有权限，不需要启动悬浮窗服务，这由MainActivity控制
            }
        } else {
            // 低于Android 6.0的系统不需要动态请求悬浮窗权限
            // 由MainActivity控制启动悬浮窗服务
            LogUtils.d(TAG, "Android版本低于6.0，无需请求悬浮窗权限");
        }
    }

    private void showOverlayPermissionDialog() {
        new AlertDialog.Builder(activity)
                .setTitle(appStrings.OVERLAY_PERMISSION_TITLE)
                .setMessage(appStrings.OVERLAY_PERMISSION_MESSAGE)
                .setPositiveButton(appStrings.BUTTON_GO_SETTINGS, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent = new Intent(
                                Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                                Uri.parse(appStrings.PACKAGE_URI_PREFIX + activity.getPackageName())
                        );
                        activity.startActivityForResult(intent, OVERLAY_PERMISSION_REQUEST_CODE);
                    }
                })
                .setNegativeButton(appStrings.BUTTON_CANCEL, null)
                .setCancelable(false)
                .show();
    }

    private void startFloatService() {
        LogUtils.d(TAG, "开始悬浮窗权限流程");
        Intent serviceIntent = new Intent(activity, FloatServiceView.class);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            activity.startForegroundService(serviceIntent);
        } else {
            activity.startService(serviceIntent);
        }
    }

    public void handlePermissionsResult(int requestCode, @NonNull String[] permissions, 
            @NonNull int[] grantResults) {
        if (requestCode == PERMISSION_REQUEST_CODE) {
            boolean allGranted = true;
            for (int result : grantResults) {
                if (result != PackageManager.PERMISSION_GRANTED) {
                    allGranted = false;
                    break;
                }
            }

            if (allGranted) {
                LogUtils.d(TAG, "所有权限已授予");
                // 获得所有基本权限后，检查悬浮窗权限但不启动服务
                checkOverlayPermission();
            } else {
                LogUtils.e(TAG, "部分权限被拒绝");
                showPermissionDeniedDialog();
            }
        } else if (requestCode == OVERLAY_PERMISSION_REQUEST_CODE) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                if (Settings.canDrawOverlays(activity)) {
                    LogUtils.d(TAG, "悬浮窗权限已授予");
                    // 悬浮窗服务由MainActivity控制启动
                } else {
                    LogUtils.e(TAG, "悬浮窗权限被拒绝");
                    showOverlayPermissionDeniedDialog();
                }
            }
        } else if (requestCode == MANAGE_STORAGE_PERMISSION_REQUEST_CODE) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                if (Environment.isExternalStorageManager()) {
                    LogUtils.d(TAG, "存储权限已授予");
                    startPermissionRequest(); // 继续请求其他权限
                } else {
                    LogUtils.e(TAG, "存储权限被拒绝");
                    showStoragePermissionDeniedDialog();
                }
            }
        }
    }

    private void showPermissionDeniedDialog() {
        new AlertDialog.Builder(activity)
                .setTitle(appStrings.GENERAL_PERMISSION_TITLE)
                .setMessage(appStrings.GENERAL_PERMISSION_MESSAGE)
                .setPositiveButton(appStrings.BUTTON_GO_SETTINGS, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent = new Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
                        intent.setData(Uri.parse(appStrings.PACKAGE_URI_PREFIX + activity.getPackageName()));
                        activity.startActivity(intent);
                    }
                })
                .setNegativeButton(appStrings.BUTTON_RETRY, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        checkAndRequestPermissions();
                    }
                })
                .setCancelable(false)
                .show();
    }

    private void showOverlayPermissionDeniedDialog() {
        new AlertDialog.Builder(activity)
                .setTitle(appStrings.OVERLAY_PERMISSION_TITLE)
                .setMessage(appStrings.OVERLAY_PERMISSION_DENIED)
                .setPositiveButton(appStrings.BUTTON_GO_SETTINGS, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent = new Intent(
                                Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                                Uri.parse(appStrings.PACKAGE_URI_PREFIX + activity.getPackageName())
                        );
                        activity.startActivity(intent);
                    }
                })
                .setNegativeButton(appStrings.BUTTON_RETRY, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        checkOverlayPermission();
                    }
                })
                .setCancelable(false)
                .show();
    }

    public boolean hasAllRequiredPermissions() {
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.M) {
            return true;
        }

        // 检查存储权限
        if (!hasStoragePermission()) {
            return false;
        }
        
        // 检查常规权限
        for (String permission : REQUIRED_PERMISSIONS) {
            if (ContextCompat.checkSelfPermission(activity, permission) 
                    != PackageManager.PERMISSION_GRANTED) {
                return false;
            }
        }

        // 检查悬浮窗权限不作为必要条件
        // 悬浮窗权限将在登录成功后单独检查和请求

        return true;
    }

    /**
     * 检查存储权限（适配Android 10+）
     */
    public boolean hasStoragePermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            boolean hasPermission = Environment.isExternalStorageManager();
            LogUtils.d(TAG, "存储权限检查: " + (hasPermission ? "有" : "无") + "存储权限(Android 11+)");
            return hasPermission;
        } else {
            boolean hasPermission = activity.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED;
            LogUtils.d(TAG, "存储权限检查: " + (hasPermission ? "有" : "无") + "存储权限(Android 10-)");
            return hasPermission;
        }
    }

    // 检查悬浮窗权限
    public boolean hasOverlayPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            boolean hasPermission = Settings.canDrawOverlays(activity);
            LogUtils.d(TAG, "检查悬浮窗权限: " +
                    (hasPermission ? ": 有悬浮窗权限" : ": 无悬浮窗权限"));
            return hasPermission;
        }
        return true;
    }
}
