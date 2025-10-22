package load.tencent.lib;

import android.util.Log;

public class LogUtils {
    private static final String TAG = "LUA-print";
    
    // 根据BuildConfig自动判断是否为debug版本
    private static final boolean DEBUG = BuildConfig.DEBUG;
    
    // 是否启用详细日志（可以通过setVerbose动态控制）
    private static boolean VERBOSE = DEBUG;

    /**
     * Debug级别日志
     */
    public static void d(String tag, String msg) {
        if (DEBUG) {
            Log.d(TAG, "[" + tag + "] " + msg);
        }
    }

    /**
     * Info级别日志
     */
    public static void i(String tag, String msg) {
        if (DEBUG) {
            Log.i(TAG, "[" + tag + "] " + msg);
        }
    }

    /**
     * Warning级别日志
     */
    public static void w(String tag, String msg) {
        if (DEBUG) {
            Log.w(TAG, "[" + tag + "] " + msg);
        }
    }

    /**
     * Error级别日志
     */
    public static void e(String tag, String msg) {
        if (DEBUG) {
            Log.e(TAG, "[" + tag + "] " + msg);
        }
    }

    /**
     * Error级别日志（带异常）
     */
    public static void e(String tag, String msg, Throwable tr) {
        if (DEBUG) {
            Log.e(TAG, "[" + tag + "] " + msg, tr);
        }
    }

    /**
     * Verbose级别日志（更详细的调试信息）
     */
    public static void v(String tag, String msg) {
        if (DEBUG && VERBOSE) {
            Log.v(TAG, "[" + tag + "] " + msg);
        }
    }

    /**
     * 设置是否启用详细日志
     * 注意：只有在DEBUG模式下才有效
     */
    public static void setVerbose(boolean verbose) {
        if (DEBUG) {
            VERBOSE = verbose;
        }
    }

    /**
     * 获取当前是否为Debug模式
     */
    public static boolean isDebug() {
        return DEBUG;
    }

    /**
     * 打印方法调用栈（仅Debug模式）
     */
    public static void printStackTrace(String tag) {
        if (DEBUG) {
            Log.d(TAG, "[" + tag + "] Stack trace:");
            StackTraceElement[] elements = Thread.currentThread().getStackTrace();
            for (int i = 3; i < elements.length && i < 10; i++) { // 跳过前3个系统调用
                Log.d(TAG, "[" + tag + "] \tat " + elements[i].toString());
            }
        }
    }

    /**
     * 兼容旧版本的setDebug方法（已废弃）
     * @deprecated 使用BuildConfig.DEBUG自动判断，无需手动设置
     */
    @Deprecated
    public static void setDebug(boolean debug) {
        // 保留此方法以兼容现有代码，但实际上不做任何操作
        // DEBUG值由BuildConfig.DEBUG决定
        if (DEBUG) {
            Log.w(TAG, "setDebug方法已废弃，DEBUG状态由BuildConfig.DEBUG自动控制");
        }
    }
} 