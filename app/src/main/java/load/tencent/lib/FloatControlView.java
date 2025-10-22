package load.tencent.lib;

import android.content.Context;
import android.graphics.PixelFormat;
import android.os.Build;
import android.os.Handler;
import android.util.DisplayMetrics;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.ImageView;
import android.widget.LinearLayout;

public class FloatControlView extends LinearLayout {
    private static final String TAG = "FloatControlView";
    private Context mContext;
    public static ImageView controlView;
    private WindowManager wManager;
    private WindowManager.LayoutParams wParams;
    private FloatContentView floatContentView;
    private int signX;
    private int signY;
    private float downX;
    private float downY;
    private float moveX;
    private float moveY;
    private boolean isView;
    long lastClickTime = System.currentTimeMillis();
    boolean isTransparent = false;
    Handler handler;
    Runnable transparentTask;

    public FloatControlView(Context context) {
        super(context);
        mContext = context;
        LogUtils.d(TAG, "悬浮控制视图初始化");
        initView();
    }

    private void initView() {
        LogUtils.d(TAG, "悬浮控制视图初始化开始");
        setupControlView();
        setupWindowManager();
        setupFloatContentView();
        setupTouchListener();
        setupTransparentTask();
        LogUtils.d(TAG, "悬浮控制视图初始化完成");
    }

    private void setupControlView() {
        LogUtils.d(TAG, "设置悬浮控制视图");
        controlView = new ImageView(mContext);
        LinearLayout.LayoutParams ball_params = new LinearLayout.LayoutParams(80, 80);
        controlView.setLayoutParams(ball_params);
        controlView.setImageBitmap(Util.getImageBase64Jie(Pic.base64_Icon));
        controlView.setAlpha(1.0f);
        addView(controlView);
    }

    private void setupWindowManager() {
        LogUtils.d(TAG, "设置悬浮控制窗口");
        wManager = (WindowManager) mContext.getSystemService(Context.WINDOW_SERVICE);
        DisplayMetrics metrics = new DisplayMetrics();
        wManager.getDefaultDisplay().getRealMetrics(metrics);

        wParams = new WindowManager.LayoutParams();
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            wParams.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
        } else {
            wParams.type = WindowManager.LayoutParams.TYPE_SYSTEM_ALERT;
        }
        wParams.flags = WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE;
        wParams.gravity = Gravity.TOP | Gravity.LEFT;
        wParams.x = 0;
        wParams.y = 0;
        wParams.width = WindowManager.LayoutParams.WRAP_CONTENT;
        wParams.height = WindowManager.LayoutParams.WRAP_CONTENT;
        wParams.format = PixelFormat.RGBA_8888;
    }

    private void setupFloatContentView() {
        LogUtils.d(TAG, "设置悬浮控制内容");
        floatContentView = new FloatContentView(mContext);
    }

    private void setupTouchListener() {
        LogUtils.d(TAG, "设置悬浮控制触摸");
        controlView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LogUtils.d(TAG, "悬浮控制点击");
                isTransparent = false;
                controlView.setAlpha(1.0f);
                floatContentView.showView();
                lastClickTime = System.currentTimeMillis();
            }
        });

        controlView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent event) {
                switch (event.getActionMasked()) {
                    case MotionEvent.ACTION_DOWN:
                        LogUtils.d(TAG, "悬浮控制触摸按下");
                        signX = wParams.x;
                        signY = wParams.y;
                        downX = event.getRawX();
                        downY = event.getRawY();
                        break;
                    case MotionEvent.ACTION_MOVE:
                        moveX = event.getRawX();
                        moveY = event.getRawY();
                        wParams.x = signX + (int) (moveX - downX);
                        wParams.y = signY + (int) (moveY - downY);
                        updateView();
                        break;
                    case MotionEvent.ACTION_UP:
                        LogUtils.d(TAG, "悬浮控制触摸抬起");
                        break;
                }
                return false;
            }
        });
    }

    private void setupTransparentTask() {
        LogUtils.d(TAG, "设置悬浮控制透明");
        handler = new Handler();
        transparentTask = new Runnable() {
            @Override
            public void run() {
                long currentTime = System.currentTimeMillis();
                long timePassed = currentTime - lastClickTime;

                if (timePassed >= 5000 && !isTransparent) {
                    LogUtils.d(TAG, "设置悬浮控制透明状态");
                    controlView.setAlpha(0.5f);
                    isTransparent = true;
                } else if (timePassed < 5000 && isTransparent) {
                    LogUtils.d(TAG, "设置悬浮控制不透明状态");
                    controlView.setAlpha(1.0f);
                    isTransparent = false;
                }

                handler.postDelayed(transparentTask, 1000);
            }
        };

        handler.postDelayed(transparentTask, 1000);
    }

    public void showView() {
        LogUtils.d(TAG, "显示悬浮控制");
        if (!isView) {
            isView = true;
            wManager.addView(this, wParams);
        }
    }

    public void updateView() {
        LogUtils.d(TAG, "更新悬浮控制");
        wManager.updateViewLayout(this, wParams);
    }

    public void clearView() {
        LogUtils.d(TAG, "清除悬浮控制");
        if (isView) {
            isView = false;
            wManager.removeView(this);
        }
    }
}
