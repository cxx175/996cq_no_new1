package gd.game.lib;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.PorterDuff;
import android.graphics.Typeface;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.os.Handler;
import android.util.DisplayMetrics;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.view.animation.AlphaAnimation;
import android.widget.CompoundButton;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class FloatContentView extends PopupWindow {
    // 日志标签
    private static final String TAG = "FloatContentView";

    Context mContext;
    Handler handler;
    ArrayList<Switch> switchs = new ArrayList<Switch>();
    AlphaAnimation anim;

    LinearLayout main;
    GradientDrawable mainBackground;
    LinearLayout mainLayout;
    LinearLayout titleLayout;
    TextView title;
    LinearLayout titleLayout1;
    TextView title1;
    LinearLayout textTitleLayout;
    TextView button0;
    TextView tip1;
    ScrollView scroll;
    LinearLayout layout;

    Toast toast;
    LinearLayout toastlayout;
    TextView toastText;

    Typeface typeface2;
    Typeface typeface3;
    Typeface typefaceXS;

    // 添加标志位防止开关重复触发
    private boolean isExecutingDDMZ = false;
    private boolean isExecutingSKCD = false;

    // 使用新的悬浮下线按钮模块
//    private FloatingOfflineButton offlineButton;

    public FloatContentView(Context context) {
        super(context);
        this.mContext = context;
        LogUtils.d(TAG, "悬浮内容视图初始化");
        
        // 初始化悬浮下线按钮模块
//        offlineButton = new FloatingOfflineButton(context);
        
        initView();
    }

    void initView() {
        LogUtils.d(TAG, "悬浮内容视图初始化开始");
        // 使用安全的SharedPreferences获取方法
        SharedPreferences sharedPre = MainActivity.getSafeSharedPreferences(mContext, appStrings.PREF_NAME, Context.MODE_PRIVATE);

        try {
            // 使用AppStrings中的字体文件路径常量
            typeface2 = Typeface.createFromAsset(mContext.getAssets(), appStrings.FONT_ZT2);
            typeface3 = Typeface.createFromAsset(mContext.getAssets(), appStrings.FONT_ZT3);
            typefaceXS = Typeface.createFromAsset(mContext.getAssets(), appStrings.FONT_XS);
            LogUtils.d(TAG, "字体加载成功");
        } catch (Exception e) {
            LogUtils.e(TAG, "字体加载失败", e);
        }

        anim = new AlphaAnimation(0f, 1f);
        anim.setDuration(500);
        handler = new Handler();

        setOutsideTouchable(true);
        setFocusable(true);
        setBackgroundDrawable(new ColorDrawable(0));
        setOnDismissListener(new OnDismissListener() {
            @Override
            public void onDismiss() {
                LogUtils.d(TAG, "悬浮内容视图关闭");
                // 注释掉清理悬浮按钮的代码，让下线按钮独立存在
                // hideFloatingButton();
            }
        });

        setupMainLayout();
        setupTitleLayout();
        setupScrollView();
        setupSeekBars();
        setupSwitches();
        setupWindowLayout();


        LogUtils.d(TAG, "悬浮内容视图初始化完成");
    }

    private void setupMainLayout() {
        LogUtils.d(TAG, "设置主布局");
        main = new LinearLayout(mContext);
        LinearLayout.LayoutParams mainParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT);
        main.setLayoutParams(mainParams);

        mainBackground = new GradientDrawable();
        mainBackground.setColor(0xD3000000);
        mainBackground.setCornerRadius(30);
        mainBackground.setStroke(0, 0xFF3C3D3F);

        main.setBackgroundDrawable(mainBackground);

        mainLayout = new LinearLayout(mContext);
        LinearLayout.LayoutParams mainLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT);
        mainLayout.setLayoutParams(mainLayoutParams);
        mainLayout.setOrientation(LinearLayout.VERTICAL);
        main.addView(mainLayout);
    }

    private void setupTitleLayout() {
        LogUtils.d(TAG, "设置标题布局");
        titleLayout = new LinearLayout(mContext);
        LinearLayout.LayoutParams titleLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        titleLayout.setLayoutParams(titleLayoutParams);
        titleLayout.setGravity(Gravity.CENTER);
        titleLayout.setPadding(20, 20, 20, 20);
        titleLayout.setBackgroundColor(0x00000000);
        mainLayout.addView(titleLayout);

        title = new TextView(mContext);
        LinearLayout.LayoutParams titleParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        title.setLayoutParams(titleParams);
        title.setText(appStrings.FLOAT_MENU_TITLE);
        title.setTextSize(15);
        title.setTextColor(0xFFFFFFFF);
        title.setTypeface(typeface2);
        titleLayout.addView(title);

        titleLayout1 = new LinearLayout(mContext);
        LinearLayout.LayoutParams titleLayoutParams1 = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        titleLayout1.setLayoutParams(titleLayoutParams1);
        titleLayout1.setGravity(Gravity.CENTER);
        titleLayout1.setPadding(0, 0, 0, 0);
        titleLayout1.setBackgroundColor(0x60FFFFFF);
        mainLayout.addView(titleLayout1);

        title1 = new TextView(mContext);
        LinearLayout.LayoutParams titleParams1 = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        title1.setLayoutParams(titleParams1);
        title1.setText("");//QQ3077947864
        title1.setTextSize(8);
        title1.setTextColor(0xFFFFFFFF);
        title1.setTypeface(typeface3);
        titleLayout1.addView(title1);
    }

    private void setupScrollView() {
        LogUtils.d(TAG, "设置滚动视图");
        scroll = new ScrollView(mContext);
        ScrollView.LayoutParams scrollParams = new ScrollView.LayoutParams(ScrollView.LayoutParams.MATCH_PARENT, ScrollView.LayoutParams.WRAP_CONTENT);
        scrollParams.bottomMargin = 10;
        scroll.setLayoutParams(scrollParams);
        mainLayout.addView(scroll);

        layout = new LinearLayout(mContext);
        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        layout.setLayoutParams(layoutParams);
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setPadding(5, 5, 5, 5);
        scroll.addView(layout);
    }


    private void setupAttackSpeedSeekBar(SharedPreferences sharedPre) {
        LogUtils.d(TAG, "设置攻击速度滑块");
        TextView progressText = new TextView(mContext);
        // 使用AppStrings中的SharedPreferences键值常量
        int savedProgress = sharedPre.getInt(appStrings.PREF_KEY_ATTACK_SPEED, 0);
        if (savedProgress == 0) {
            // 使用AppStrings中的攻击速度标签和关闭状态常量
            progressText.setText(appStrings.ATTACK_SPEED_LABEL + appStrings.SPEED_CLOSED + appStrings.SPEED_UNIT);
        } else {
            // 使用AppStrings中的攻击速度标签和单位常量
            progressText.setText(appStrings.ATTACK_SPEED_LABEL + savedProgress + appStrings.SPEED_UNIT);
        }
        progressText.setTextColor(0xFFFFFFFF);    // 白色文字
        LinearLayout.LayoutParams textViewLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        progressText.setLayoutParams(textViewLayoutParams);
        layout.addView(progressText);

        // 说明文字
        TextView descriptionText = new TextView(mContext);
        // 使用AppStrings中的攻击速度描述常量
        descriptionText.setText(appStrings.ATTACK_SPEED_DESC);
        descriptionText.setTextSize(10);
        descriptionText.setTextColor(0xFFAAAAAA);  // 灰色文字
        LinearLayout.LayoutParams descTextParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        descriptionText.setLayoutParams(descTextParams);
        layout.addView(descriptionText);

        SeekBar seekBar = new SeekBar(mContext);
        LinearLayout.LayoutParams seekBarLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        seekBar.setLayoutParams(seekBarLayoutParams);
        seekBar.setMax(100);
        seekBar.setProgress(savedProgress);
        layout.addView(seekBar);

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (progress == 0) {
                    // 使用AppStrings中的攻击速度标签和关闭状态常量
                    progressText.setText(appStrings.ATTACK_SPEED_LABEL + appStrings.SPEED_CLOSED + appStrings.SPEED_UNIT);
                } else {
                    // 使用AppStrings中的攻击速度标签和单位常量
                    progressText.setText(appStrings.ATTACK_SPEED_LABEL + progress + appStrings.SPEED_UNIT);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                LogUtils.d(TAG, "攻击速度开始设置");
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // 域名完整性验证
                if (!performDomainVerification("攻击速度SeekBar拖动结束")) {
                    return;
                }
                
                int finalAttackSpeed = seekBar.getProgress();
                SharedPreferences.Editor editor = sharedPre.edit();
                // 使用AppStrings中的SharedPreferences键值常量
                editor.putInt(appStrings.PREF_KEY_ATTACK_SPEED, finalAttackSpeed);

                editor.apply();
                LogUtils.d(TAG, "攻击速度设置完成：" + finalAttackSpeed);

                // 显示设置完成提示
                if (finalAttackSpeed > 0) {
                    // 使用AppStrings中的攻击速度设置提示常量
                    Util.showui(mContext, appStrings.ATTACK_SPEED_SET + finalAttackSpeed + appStrings.SPEED_EFFECT);
                } else {
                    // 使用AppStrings中的攻击速度关闭提示常量
                    Util.showui(mContext, appStrings.ATTACK_SPEED_OFF);
                }
            }
        });
    }

    private void setupMoveSpeedSeekBar(SharedPreferences sharedPre) {
        LogUtils.d(TAG, "设置移动速度滑块");
        TextView ydprogressText = new TextView(mContext);
        // 使用AppStrings中的SharedPreferences键值常量
        int ydsavedProgress = sharedPre.getInt(appStrings.PREF_KEY_MOVE_SPEED, 0);
        if (ydsavedProgress == 0) {
            // 使用AppStrings中的移动速度标签和关闭状态常量
            ydprogressText.setText(appStrings.MOVE_SPEED_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
        } else {
            ydprogressText.setText(
                    appStrings.MOVE_SPEED_LABEL +   // 使用AppStrings中的移动速度标签常量
                            ydsavedProgress +
                            appStrings.SPEED_UNIT     // 使用AppStrings中的单位常量
            );
        }
        ydprogressText.setTextColor(0xFFFFFFFF); // 白色文字
        LinearLayout.LayoutParams ydtextViewLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        ydprogressText.setLayoutParams(ydtextViewLayoutParams);
        layout.addView(ydprogressText);

        // 说明文字
        TextView descriptionText = new TextView(mContext);
        // 使用AppStrings中的移动速度描述常量
        descriptionText.setText(appStrings.MOVE_SPEED_DESC);
        descriptionText.setTextSize(10);
        descriptionText.setTextColor(0xFFAAAAAA);  // 灰色文字
        LinearLayout.LayoutParams descTextParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        descriptionText.setLayoutParams(descTextParams);
        layout.addView(descriptionText);

        SeekBar ydseekBar = new SeekBar(mContext);
        LinearLayout.LayoutParams ydseekBarLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        ydseekBar.setLayoutParams(ydseekBarLayoutParams);
        ydseekBar.setMax(100);
        ydseekBar.setProgress(ydsavedProgress);
        layout.addView(ydseekBar);

        ydseekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (progress == 0) {
                    // 使用AppStrings中的移动速度标签和关闭状态常量
                    ydprogressText.setText(appStrings.MOVE_SPEED_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
                } else {
                    // 使用AppStrings中的移动速度标签和单位常量
                    ydprogressText.setText(appStrings.MOVE_SPEED_LABEL + progress + appStrings.SPEED_UNIT);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                LogUtils.d(TAG, "移动速度开始设置");
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // 域名完整性验证
                if (!performDomainVerification("移动速度SeekBar拖动结束")) {
                    return;
                }
                
                int finalMoveSpeed = seekBar.getProgress();
                SharedPreferences.Editor editor = sharedPre.edit();
                // 使用AppStrings中的SharedPreferences键值常量
                editor.putInt(appStrings.PREF_KEY_MOVE_SPEED, finalMoveSpeed);

                editor.apply();
                LogUtils.d(TAG, "移动速度设置完成：" + finalMoveSpeed);

                // 显示设置完成提示
                if (finalMoveSpeed > 0) {
                    // 使用AppStrings中的移动速度设置提示常量
                    Util.showui(mContext, appStrings.MOVE_SPEED_SET + finalMoveSpeed + appStrings.SPEED_EFFECT);
                } else {
                    // 使用AppStrings中的移动速度关闭提示常量
                    Util.showui(mContext, appStrings.MOVE_SPEED_OFF);
                }
            }
        });
    }

    private void setupWildSpeedSeekBar(SharedPreferences sharedPre) {
        LogUtils.d(TAG, "设置野蛮速度滑块");
        // 使用AppStrings中的SharedPreferences键值常量
        int ymsavedProgress = sharedPre.getInt(appStrings.PREF_KEY_WILD_SPEED, 0);
        TextView ymprogressText = new TextView(mContext);
        if (ymsavedProgress == 0) {
            // 使用AppStrings中的野蛮速度标签和关闭状态常量
            ymprogressText.setText(appStrings.WILD_SPEED_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
        } else {
            ymprogressText.setText(
                    appStrings.WILD_SPEED_LABEL +   // 使用AppStrings中的野蛮速度标签常量
                            ymsavedProgress +
                            appStrings.SPEED_UNIT      // 使用AppStrings中的单位常量
            );
        }
        ymprogressText.setTextColor(0xFFFFFFFF); // 白色文字
        LinearLayout.LayoutParams ymtextViewLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        ymprogressText.setLayoutParams(ymtextViewLayoutParams);
        layout.addView(ymprogressText);

        // 说明文字
        TextView descriptionText = new TextView(mContext);
        // 使用AppStrings中的野蛮速度描述常量
        descriptionText.setText(appStrings.WILD_SPEED_DESC);
        descriptionText.setTextSize(10);
        descriptionText.setTextColor(0xFFAAAAAA);  // 灰色文字
        LinearLayout.LayoutParams descTextParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        descriptionText.setLayoutParams(descTextParams);
        layout.addView(descriptionText);

        SeekBar ymseekBar = new SeekBar(mContext);
        LinearLayout.LayoutParams ymseekBarLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        ymseekBar.setLayoutParams(ymseekBarLayoutParams);
        ymseekBar.setMax(100);
        ymseekBar.setProgress(ymsavedProgress);
        layout.addView(ymseekBar);

        ymseekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (progress == 0) {
                    // 使用AppStrings中的野蛮速度标签和关闭状态常量
                    ymprogressText.setText(appStrings.WILD_SPEED_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
                } else {
                    // 使用AppStrings中的野蛮速度标签和单位常量
                    ymprogressText.setText(appStrings.WILD_SPEED_LABEL + progress + appStrings.SPEED_UNIT);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                LogUtils.d(TAG, "野蛮速度开始设置");
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // 域名完整性验证
                if (!performDomainVerification("野蛮速度SeekBar拖动结束")) {
                    return;
                }
                
                int finalWildSpeed = seekBar.getProgress();
                SharedPreferences.Editor editor = sharedPre.edit();
                // 使用AppStrings中的SharedPreferences键值常量
                editor.putInt(appStrings.PREF_KEY_WILD_SPEED, seekBar.getProgress());
                editor.apply();
                LogUtils.d(TAG, "野蛮速度设置完成：" + finalWildSpeed);

                // 显示设置完成提示
                if (finalWildSpeed > 0) {
                    // 使用AppStrings中的野蛮速度设置提示常量
                    Util.showui(mContext, appStrings.WILD_SPEED_SET + finalWildSpeed + appStrings.SPEED_EFFECT);
                } else {
                    // 使用AppStrings中的野蛮速度关闭提示常量
                    Util.showui(mContext, appStrings.WILD_SPEED_OFF);
                }
            }
        });
    }
    //低血小退
    private void setupHpSeekBar(SharedPreferences sharedPre) {
        LogUtils.d(TAG, "设置血量滑块");
        TextView progressText = new TextView(mContext);
        // 使用AppStrings中的SharedPreferences键值常量
        int savedProgress = sharedPre.getInt(appStrings.PREF_KEY_HP_THRESHOLD, 30);
        if (savedProgress == 0) {
            // 使用AppStrings中的血量标签和关闭状态常量
            progressText.setText(appStrings.HP_THRESHOLD_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
        } else {
            progressText.setText(
                    appStrings.HP_THRESHOLD_LABEL +  // 使用AppStrings中的血量标签常量
                            savedProgress +
                            appStrings.SPEED_UNIT     // 使用AppStrings中的单位常量
            );
        }
        progressText.setTextColor(0xFFFFFFFF);    // 白色文字
        LinearLayout.LayoutParams textViewLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        progressText.setLayoutParams(textViewLayoutParams);
        layout.addView(progressText);

        // 说明文字
        TextView descriptionText = new TextView(mContext);
        // 使用AppStrings中的血量阈值描述常量
        descriptionText.setText(appStrings.HP_THRESHOLD_DESC);
        descriptionText.setTextSize(10);
        descriptionText.setTextColor(0xFFAAAAAA);  // 灰色文字
        LinearLayout.LayoutParams descTextParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        descriptionText.setLayoutParams(descTextParams);
        layout.addView(descriptionText);

        SeekBar seekBar = new SeekBar(mContext);
        LinearLayout.LayoutParams seekBarLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        seekBar.setLayoutParams(seekBarLayoutParams);
        seekBar.setMax(100);
        seekBar.setProgress(savedProgress);
        layout.addView(seekBar);

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (progress == 0) {
                    // 使用AppStrings中的血量标签和关闭状态常量
                    progressText.setText(appStrings.HP_THRESHOLD_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
                } else {
                    // 使用AppStrings中的血量标签和单位常量
                    progressText.setText(appStrings.HP_THRESHOLD_LABEL + progress + appStrings.SPEED_UNIT);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                LogUtils.d(TAG, "血量设置开始");
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // 域名完整性验证
                if (!performDomainVerification("血量阈值SeekBar拖动结束")) {
                    return;
                }
                
                int finalHpThreshold = seekBar.getProgress();
                SharedPreferences.Editor editor = sharedPre.edit();
                // 使用AppStrings中的SharedPreferences键值常量
                editor.putInt(appStrings.PREF_KEY_HP_THRESHOLD, finalHpThreshold);
                editor.apply();
                LogUtils.d(TAG, "血量设置完成：" + finalHpThreshold);

                // 显示设置完成提示
                if (finalHpThreshold > 0) {
                    // 使用AppStrings中的血量阈值设置提示常量
                    Util.showui(mContext, appStrings.HP_THRESHOLD_SET + finalHpThreshold + appStrings.HP_THRESHOLD_EFFECT);
                } else {
                    // 使用AppStrings中的血量阈值关闭提示常量
                    Util.showui(mContext, appStrings.HP_THRESHOLD_OFF);
                }
            }
        });
    }
    //微加速回血
    private void setupHpRecoverySpeedSeekBar(SharedPreferences sharedPre) {
        TextView progressText = new TextView(mContext);
        // 使用AppStrings中的SharedPreferences键值常量
        int savedProgress = sharedPre.getInt(appStrings.PREF_KEY_HP_RECOVERY_SPEED, 0);
        if (savedProgress == 0) {
            // 使用AppStrings中的回血标签和关闭状态常量
            progressText.setText(appStrings.HP_RECOVERY_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
        } else {
            // 使用AppStrings中的回血标签和单位常量
            progressText.setText(appStrings.HP_RECOVERY_LABEL + savedProgress + appStrings.SPEED_UNIT);
        }
        progressText.setTextColor(0xFFFFFFFF);    // 白色文字
        LinearLayout.LayoutParams textViewLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        progressText.setLayoutParams(textViewLayoutParams);
        layout.addView(progressText);

        // 说明文字
        TextView descriptionText = new TextView(mContext);
        // 使用AppStrings中的回血描述常量
        descriptionText.setText(appStrings.HP_RECOVERY_DESC);
        descriptionText.setTextSize(10);
        descriptionText.setTextColor(0xFFAAAAAA);  // 灰色文字
        LinearLayout.LayoutParams descTextParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        descriptionText.setLayoutParams(descTextParams);
        layout.addView(descriptionText);

        SeekBar seekBar = new SeekBar(mContext);
        LinearLayout.LayoutParams seekBarLayoutParams = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        seekBar.setLayoutParams(seekBarLayoutParams);
        seekBar.setMax(100);
        seekBar.setProgress(savedProgress);
        layout.addView(seekBar);

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (progress == 0) {
                    // 使用AppStrings中的回血标签和关闭状态常量
                    progressText.setText(appStrings.HP_RECOVERY_LABEL + appStrings.SPEED_CLOSED_WITH_ZERO + appStrings.SPEED_UNIT);
                } else {
                    // 使用AppStrings中的回血标签和单位常量
                    progressText.setText(appStrings.HP_RECOVERY_LABEL + progress + appStrings.SPEED_UNIT);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                // 域名完整性验证
                if (!performDomainVerification("血量恢复速度SeekBar拖动结束")) {
                    return;
                }
                
                int finalRecoverySpeed = seekBar.getProgress();
                SharedPreferences.Editor editor = sharedPre.edit();
                // 使用AppStrings中的SharedPreferences键值常量
                editor.putInt(appStrings.PREF_KEY_HP_RECOVERY_SPEED, finalRecoverySpeed);
                editor.apply();
                LogUtils.d(TAG, "回血速度设置完成：" + finalRecoverySpeed);

                // 显示设置完成提示
                if (finalRecoverySpeed > 0) {
                    // 使用AppStrings中的回血设置提示常量
                    Util.showui(mContext, appStrings.HP_RECOVERY_SET + finalRecoverySpeed + appStrings.SPEED_EFFECT);
                } else {
                    // 使用AppStrings中的回血关闭提示常量
                    Util.showui(mContext, appStrings.HP_RECOVERY_OFF);
                }
            }
        });
    }

    private void setupSeekBars() {
        LogUtils.d(TAG, "设置滑块组件");
        // 使用安全的SharedPreferences获取方法
        SharedPreferences sharedPre = MainActivity.getSafeSharedPreferences(mContext, appStrings.PREF_NAME, Context.MODE_PRIVATE);

        // 检查是否是首次加载
        boolean isFirstLoad = !sharedPre.contains(
                appStrings.PREF_KEY_ATTACK_SPEED  // 使用AppStrings中的攻击速度键值常量
        ) && !sharedPre.contains(
                appStrings.PREF_KEY_MOVE_SPEED    // 使用AppStrings中的移动速度键值常量
        ) && !sharedPre.contains(
                appStrings.PREF_KEY_WILD_SPEED    // 使用AppStrings中的野蛮人速度键值常量
        ) && !sharedPre.contains(
                appStrings.PREF_KEY_HP_THRESHOLD      // 使用AppStrings中的血量键值常量
        ) && !sharedPre.contains(
                appStrings.PREF_KEY_HP_RECOVERY_SPEED // 使用AppStrings中的回血速度键值常量
        );

        if (isFirstLoad) {
            LogUtils.d(TAG, "首次加载，初始化默认值");
            SharedPreferences.Editor editor = sharedPre.edit();
            // 使用AppStrings中的SharedPreferences键值常量初始化默认值
            editor.putInt(appStrings.PREF_KEY_ATTACK_SPEED, 0);  // 初始化攻击速度为0
            editor.putInt(appStrings.PREF_KEY_MOVE_SPEED, 0);    // 初始化移动速度为0
            editor.putInt(appStrings.PREF_KEY_WILD_SPEED, 0);    // 初始化野蛮速度为0
            editor.putInt(appStrings.PREF_KEY_HP_THRESHOLD, 0);     // 初始化小退血量0
            editor.putInt(appStrings.PREF_KEY_HP_RECOVERY_SPEED, 0); // 初始化回血的阈值为0
            editor.apply();
        }

        setupAttackSpeedSeekBar(sharedPre);//攻击速度
        setupMoveSpeedSeekBar(sharedPre);//移动速度
        setupWildSpeedSeekBar(sharedPre);//野蛮速度
        setupHpRecoverySpeedSeekBar(sharedPre);//加速回血
//        ------------------------------------------------------------------
        // setupHpSeekBar(sharedPre);//低血功能1_根据生命值下线
    }
    /**
     * 设置开关按钮
     * 添加各种功能的开关按钮并设置点击监听
     */
    private void setupSwitches() {
        LogUtils.d(TAG, "设置开关组件");
        // 使用安全的SharedPreferences获取方法
        SharedPreferences sharedPre = MainActivity.getSafeSharedPreferences(mContext, appStrings.PREF_NAME, Context.MODE_PRIVATE);

        // 添加各种功能开关，使用AppStrings中的功能设置常量
        addSwitch(appStrings.SETTING_BARBARIC_SPEED, 14, 0xFFFFFFFF, typefaceXS);  // 智能野蛮
        addSwitch(appStrings.SETTING_CHUDAO_YM, 14, 0xFFFFFFFF, typefaceXS);  // 出刀野蛮
        addSwitch(appStrings.SETTING_SKILL_CD, 14, 0xFFFFFFFF, typefaceXS);        // 无技能公共CD常量
        addSwitch(appStrings.NOCD, 14, 0xFFFFFFFF, typefaceXS);     // 技能0.5秒CD
        addSwitch(appStrings.DDMZ, 14, 0xFFFFFFFF, typefaceXS);     // 刀刀命中
        addSwitch(appStrings.SETTING_AUTO_PICKUP, 14, 0xFFFFFFFF, typefaceXS);     // 自动拾取
        addSwitch(appStrings.dashnotime, 14, 0xFFFFFFFF, typefaceXS);     // 野蛮不卡位
        addSwitch(appStrings.booldoffline, 14, 0xFFFFFFFF, typefaceXS);     // 用户按钮点击下线
        addSwitch(appStrings.SETTING_FORCE_SBYS, 14, 0xFFFFFFFF, typefaceXS);      // 十步一杀
//        --------------------------------------------------------------------------------------------------
        // addSwitch(appStrings.SETTING_FORCE_BSYY, 14, 0xFFFFFFFF, typefaceXS);      // 冰霜群雨 
        // addSwitch(appStrings.SETTING_FORCE_SWZY, 14, 0xFFFFFFFF, typefaceXS);      // 死亡之眼
        addSwitch(appStrings.SBYS_AND_YM, 14, 0xFFFFFFFF, typefaceXS);      // 十步一杀+野蛮
        // addSwitch(appStrings.JFPBTNUI, 14, 0xFFFFFFFF, typefaceXS);      // 飓风破
        addSwitch(appStrings.SETTING_QUICK_SKILL, 14, 0xFFFFFFFF, typefaceXS);     // 快速使用高级技能
        // addSwitch(appStrings.SETTING_FORCE_ASSASSINATION, 14, 0xFFFFFFFF, typefaceXS);     // 强制移动刺杀
        // addSwitch(appStrings.DoubleFire, 14, 0xFFFFFFFF, typefaceXS);     // 双烈火 
        // addSwitch(appStrings.SETTING_CHUDAO_JGDY, 14, 0xFFFFFFFF, typefaceXS);     // 疾光电影 
        // addSwitch(appStrings.DDLH, 14, 0xFFFFFFFF, typefaceXS);     // 刀刀烈火
        addSwitch(appStrings.quickBOOK, 14, 0xFFFFFFFF, typefaceXS);     // 快速切换武穆遗书按钮
        addSwitch(appStrings.exit_buff, 14, 0xFFFFFFFF, typefaceXS);     // 变羊玄武
        // 为所有开关设置状态改变监听器
        for (int i = 0; i < switchs.size(); i++) {
            final int index = i;
            // 从SharedPreferences中读取开关状态
            boolean savedState = sharedPre.getBoolean(switchs.get(index).getText().toString(), false);
            switchs.get(index).setChecked(savedState);

            setupSwitchListener(switchs.get(index));
        }
    }

    /**
     * 为单个开关设置监听器的辅助方法
     * @param switchButton 要设置监听器的开关
     */
    private void setupSwitchListener(Switch switchButton) {
        LogUtils.d(TAG, "设置开关监听器");
        // 使用安全的SharedPreferences获取方法
        SharedPreferences sharedPre = MainActivity.getSafeSharedPreferences(mContext, appStrings.PREF_NAME, Context.MODE_PRIVATE);

        // 找到开关在列表中的索引
        int index = switchs.indexOf(switchButton);
        if (index == -1) {
            LogUtils.e(TAG, "无法找到开关在列表中的索引");
            return;
        }

        switchButton.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // 域名完整性验证
                if (!performDomainVerification("Switch状态变更")) {
                    // 验证失败，恢复开关状态
                    switchButton.setOnCheckedChangeListener(null);
                    switchButton.setChecked(!isChecked);
                    switchButton.setOnCheckedChangeListener(this);
                    return;
                }
                
                // 获取当前开关的名称
                String switchName = switchs.get(index).getText().toString();
                // 记录开关状态变化的日志
                LogUtils.d(TAG, "开关状态变化：" + switchName + " - " + (isChecked ? "开启" : "关闭"));

                // 根据开关名称执行相应的操作
                // 处理智能野蛮开关
                if (switchName.equals(appStrings.SETTING_BARBARIC_SPEED)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理出刀野蛮开关
                else if (switchName.equals(appStrings.SETTING_CHUDAO_YM)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理技能CD开关
                else if (switchName.equals(appStrings.SETTING_SKILL_CD)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 刀刀烈火
                else if (switchName.equals(appStrings.DDLH)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.DDLHtip);
                }
                // 处理技能CD开关
                else if (switchName.equals(appStrings.NOCD)) {
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理十步一杀开关
                else if (switchName.equals(appStrings.SETTING_FORCE_SBYS)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理冰霜群雨开关
                else if (switchName.equals(appStrings.SETTING_FORCE_BSYY)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理死亡之眼开关
                else if (switchName.equals(appStrings.SETTING_FORCE_SWZY)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理飓风破开关
                else if (switchName.equals(appStrings.JFPBTNUI)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理疾光电影开关
                else if (switchName.equals(appStrings.SETTING_CHUDAO_JGDY)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理自动拾取开关
                else if (switchName.equals(appStrings.SETTING_AUTO_PICKUP)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理快速使用高级技能开关
                else if (switchName.equals(appStrings.SETTING_QUICK_SKILL)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                // 处理强制刺杀位开关
                else if (switchName.equals(appStrings.SETTING_FORCE_ASSASSINATION)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                //双烈火
                else if (switchName.equals(appStrings.DoubleFire)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                //野蛮不卡位
                else if (switchName.equals(appStrings.dashnotime)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                //刀刀命中
                else if (switchName.equals(appStrings.DDMZ)) {
                    changeSwitch(isChecked, switchs.get(index), appStrings.DDMZ_FUNCTION_TIP);
                }
                // 低血下线_强攻
                else if (switchName.equals(appStrings.booldoffline)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                //快速切换武穆遗书按钮
                else if (switchName.equals(appStrings.quickBOOK)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.QUICK_BOOK_TIP);
                }
                //变羊玄武
                else if (switchName.equals(appStrings.exit_buff)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
                //十步+野蛮
                else if (switchName.equals(appStrings.SBYS_AND_YM)) {
                    // 使用AppStrings中的通用描述常量
                    changeSwitch(isChecked, switchs.get(index), appStrings.UTIL_DESCRIPTION);
                }
            }
        });
    }

    private void setupWindowLayout() {
        LogUtils.d(TAG, "设置悬浮窗口布局");
        WindowManager windowManager = (WindowManager) mContext.getSystemService(Context.WINDOW_SERVICE);
        DisplayMetrics metrics = new DisplayMetrics();
        windowManager.getDefaultDisplay().getRealMetrics(metrics);
        int metricsWidth = metrics.widthPixels;
        int metricsHeight = metrics.heightPixels;

        setWidth(metricsWidth > metricsHeight ? metricsHeight / 2 : metricsWidth / 2);
        setHeight(metricsHeight > metricsWidth ? metricsWidth - 200 : metricsHeight - 200);
        setContentView(main);
        setBackgroundDrawable(new ColorDrawable(0));
        setOutsideTouchable(true);
        setFocusable(true);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            setWindowLayoutType(WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY);
        } else {
            setWindowLayoutType(WindowManager.LayoutParams.TYPE_SYSTEM_ALERT);
        }
    }

    public void showView() {
        LogUtils.d(TAG, "显示悬浮视图");
        main.startAnimation(anim);
        this.showAtLocation(this.getContentView(), Gravity.LEFT, 20, 0);
    }

    void addSwitch(String text, int textSize, int textColor, Typeface typeface) {
        LogUtils.d(TAG, "添加开关：" + text);
        LinearLayout layout1 = new LinearLayout(mContext);
        LinearLayout.LayoutParams layoutParams1 = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        layout1.setLayoutParams(layoutParams1);
        layout1.setPadding(30, 5, 5, 5);
        layout.addView(layout1);
        Switch button1 = new Switch(mContext);
        LinearLayout.LayoutParams buttonParams1 = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        button1.setLayoutParams(buttonParams1);
        button1.setText(text);
        button1.setTextSize(textSize);
        button1.setTextColor(textColor);
        button1.setTypeface(typeface);
        setButtonColor(button1, 0xCEC0C0C0, 0xCE808080);  // 修改默认颜色为灰色
        layout1.addView(button1);
        switchs.add(button1);
    }

    void changeSwitch(boolean isChecked, Switch switchButton, String toast) {
        // 域名完整性验证
        if (!performDomainVerification("开关状态改变")) {
            return;
        }
        
        LogUtils.d(TAG, "开关状态变更：" + switchButton.getText() +
                " - " +  // " - "
                (isChecked ? appStrings.STATUS_ENABLED : appStrings.STATUS_DISABLED));  // 使用AppStrings中的状态常量
        Util.showui(mContext, switchButton.getText().toString() +
                (isChecked ? appStrings.STATUS_ENABLED_SUCCESS : appStrings.STATUS_DISABLED_SUCCESS) +  // 使用AppStrings中的成功状态常量
                appStrings.NOTICE_PREFIX + toast);  // 使用AppStrings中的提示前缀常量

        // 设置开关颜色
        if (isChecked) {
            setButtonColor(switchButton, 0xCE00BA00, 0xCEBA0000);  // 开启状态颜色：绿色
        } else {
            setButtonColor(switchButton, 0xCEC0C0C0, 0xCE808080);  // 关闭状态颜色：灰色
        }

        // 保存开关状态，使用安全的SharedPreferences获取方法
        SharedPreferences sharedPre = MainActivity.getSafeSharedPreferences(mContext, appStrings.PREF_NAME, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPre.edit();
        editor.putBoolean(switchButton.getText().toString(), isChecked);
        editor.apply();
    }

    void setButtonColor(Switch button, int thumbColor, int trackColor) {
        if (button.getThumbDrawable() != null && button.getTrackDrawable() != null) {
            // 设置开关按钮的滑块和轨道颜色
            button.getThumbDrawable().setColorFilter(thumbColor, PorterDuff.Mode.MULTIPLY);
            button.getTrackDrawable().setColorFilter(trackColor, PorterDuff.Mode.MULTIPLY);
        } else {
            LogUtils.e(TAG, "开关按钮组件为空");  // "开关按钮组件为空"
        }
    }
    
    // 域名验证相关JNI方法
    public native boolean verifyDomainIntegrityNative();
    
    // 域名验证辅助方法
    private boolean performDomainVerification(String action) {
        boolean isDomainValid = verifyDomainIntegrityNative();
        if (isDomainValid) {
            LogUtils.d(TAG, "域名验证成功 - 触发事件: " + action);
            return true;
        }else {
            LogUtils.e(TAG, "域名验证失败 - 触发事件: " + action);
            return false;
        }

    }

}