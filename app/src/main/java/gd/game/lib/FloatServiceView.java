package gd.game.lib;

import android.app.Service;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.Build;
import android.os.IBinder;
import android.view.Gravity;
import android.view.WindowManager;

public class FloatServiceView extends Service {
    private static final String TAG = "FloatServiceView";
    private FloatControlView floatControlView;
    private WindowManager.LayoutParams wParams;

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        LogUtils.d(TAG, "悬浮服务视图创建开始");
        initView();
        if (floatControlView != null) {
            LogUtils.d(TAG, "显示控制视图");
            floatControlView.showView();
        }
    }

    private void initView() {
        LogUtils.d(TAG, "悬浮服务视图初始化");
        floatControlView = new FloatControlView(this);

        wParams = new WindowManager.LayoutParams();
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            wParams.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
        } else {
            wParams.type = WindowManager.LayoutParams.TYPE_SYSTEM_ALERT;
        }
        wParams.flags = WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL | 
                       WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | 
                       WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN | 
                       WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS | 
                       WindowManager.LayoutParams.FLAG_FULLSCREEN;
        wParams.gravity = Gravity.TOP | Gravity.LEFT;
        wParams.x = dpToPx(150);
        wParams.y = dpToPx(920);
        wParams.width = WindowManager.LayoutParams.WRAP_CONTENT;
        wParams.height = WindowManager.LayoutParams.WRAP_CONTENT;
        wParams.format = PixelFormat.RGBA_8888;
    }

    private int dpToPx(int dp) {
        return (int) (dp * getResources().getDisplayMetrics().density + 0.5f);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        LogUtils.d(TAG, "悬浮服务视图销毁");
        if (floatControlView != null) {
            LogUtils.d(TAG, "悬浮服务视图清除");
            floatControlView.clearView();
        }
    }
}
