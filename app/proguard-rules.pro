# OkHttp 相关规则 - 完全不混淆
-keep class okhttp3.** { *; }
-keep interface okhttp3.** { *; }
-keep class okio.** { *; }
-keep interface okio.** { *; }

# 不混淆OkHttp相关的所有内容
-dontwarn okhttp3.**
-dontwarn okio.**
-dontwarn org.conscrypt.**
-dontwarn org.bouncycastle.**
-dontwarn org.openjsse.**

# zip4j 相关规则 - 完全不混淆
-keep class net.lingala.zip4j.** { *; }
-keep interface net.lingala.zip4j.** { *; }
-dontwarn net.lingala.zip4j.**

# 确保所有zip4j相关的方法签名都被保留
-keepclassmembers class net.lingala.zip4j.ZipFile {
    public <methods>;
}
-keepclassmembers class net.lingala.zip4j.model.FileHeader {
    public <methods>;
}

# 保留所有用于反射调用的类和方法
-keepattributes Signature
-keepattributes *Annotation*
-keepattributes EnclosingMethod

# 字符串混淆规则 - 使用更安全的配置
-allowaccessmodification
-repackageclasses ''
-renamesourcefileattribute SourceFile
-keepattributes SourceFile,LineNumberTable,*Annotation*

# 启用字典混淆，使用更强的混淆方式
-obfuscationdictionary proguard-dict.txt
-classobfuscationdictionary proguard-dict.txt
-packageobfuscationdictionary proguard-dict.txt

# 添加更安全的混淆规则
-keepclassmembers class * {
    public <init>(...);
}

# 保留所有Activity类
-keep public class * extends android.app.Activity
-keep public class * extends android.app.Application
-keep public class * extends android.app.Service
-keep public class * extends android.content.BroadcastReceiver
-keep public class * extends android.content.ContentProvider

# 保留View相关类的构造函数
-keepclasseswithmembers class * {
    public <init>(android.content.Context, android.util.AttributeSet);
}
-keepclasseswithmembers class * {
    public <init>(android.content.Context, android.util.AttributeSet, int);
}

# ==================== Android View 接口保护规则 ====================
# 保护View相关的接口，防止过度混淆导致IncompatibleClassChangeError
-keep interface android.view.View$OnClickListener
-keep interface android.view.View$OnTouchListener
-keep interface android.view.View$OnLongClickListener
-keep interface android.view.View$OnFocusChangeListener
-keep interface android.text.TextWatcher
-keep interface android.widget.AdapterView$OnItemClickListener
-keep interface android.widget.SeekBar$OnSeekBarChangeListener
-keep interface android.widget.CompoundButton$OnCheckedChangeListener
-keep interface android.widget.PopupWindow$OnDismissListener

# 保护View接口的实现类
-keepclassmembers class * implements android.view.View$OnClickListener {
    public void onClick(android.view.View);
}
-keepclassmembers class * implements android.view.View$OnTouchListener {
    public boolean onTouch(android.view.View, android.view.MotionEvent);
}
-keepclassmembers class * implements android.text.TextWatcher {
    public void beforeTextChanged(java.lang.CharSequence, int, int, int);
    public void onTextChanged(java.lang.CharSequence, int, int, int);
    public void afterTextChanged(android.text.Editable);
}
-keepclassmembers class * implements android.widget.SeekBar$OnSeekBarChangeListener {
    public void onProgressChanged(android.widget.SeekBar, int, boolean);
    public void onStartTrackingTouch(android.widget.SeekBar);
    public void onStopTrackingTouch(android.widget.SeekBar);
}
-keepclassmembers class * implements android.widget.CompoundButton$OnCheckedChangeListener {
    public void onCheckedChanged(android.widget.CompoundButton, boolean);
}

# 保护lambda表达式和匿名内部类
-keepclassmembers class * {
    synthetic <methods>;
}

# 保护所有匿名内部类
-keep class **$* { *; }

# 保护lambda表达式生成的合成方法
-keepclassmembers class * {
    private static synthetic *** lambda$*(...);
}

# ==================== 激进的日志代码移除规则 ====================
# 移除Android系统日志调用（Release版本）
-assumenosideeffects class android.util.Log {
    public static boolean isLoggable(java.lang.String, int);
    public static int v(...);
    public static int d(...);
    public static int i(...);
    public static int w(...);
    public static int e(...);
    public static int wtf(...);
    public static int println(...);
}

# 移除自定义LogUtils类的所有调用（包括空实现版本）
-assumenosideeffects class load.tencent.lib.LogUtils {
    public static void d(...);
    public static void i(...);
    public static void w(...);
    public static void e(...);
    public static void v(...);
    public static void printStackTrace(...);
    public static void setVerbose(...);
    public static void setDebug(...);
    public static boolean isDebug();
}

# 移除System.out和System.err相关调用
-assumenosideeffects class java.io.PrintStream {
    public void println(...);
    public void print(...);
    public void printf(...);
    public void format(...);
}

# 移除Exception的printStackTrace调用
-assumenosideeffects class java.lang.Throwable {
    public void printStackTrace();
    public void printStackTrace(java.io.PrintStream);
    public void printStackTrace(java.io.PrintWriter);
}

# 不使用大小写混合
-dontusemixedcaseclassnames

# ==================== 加密字符串保护规则 ====================
# 保护加密字符串类 - 只保留公开接口，内部实现完全混淆
-keep class load.tencent.lib.AppStrings {
    public static final java.lang.String *;
}

# 混淆加密字符串类的内部实现
-keepclassmembers class load.tencent.lib.AppStrings {
    private static final java.lang.String ALGORITHM;
    private static final java.lang.String TRANSFORMATION;
    private static final java.lang.String SECRET_KEY;
    private static java.lang.String decrypt(java.lang.String);
    private static final java.lang.String ENCRYPTED_*;
}

# 完全隐藏原始appStrings类（如果存在）
-dontwarn load.tencent.lib.appStrings
-dontnote load.tencent.lib.appStrings



# 处理字符串生成器类（仅开发时使用）
-dontwarn load.tencent.lib.StringGenerator
-dontnote load.tencent.lib.StringGenerator

# ==================== 高级字符串保护规则 ====================
# 混淆所有字符串常量（除了保留的类）
-adaptclassstrings
-adaptresourcefilenames
-adaptresourcefilecontents

# 移除调试信息中的字符串引用
-keepattributes !LocalVariableTable,!LocalVariableTypeTable

# 重命名源文件属性以隐藏原始文件名
-renamesourcefileattribute ""

# ==================== 优化规则 ====================
# 启用优化
-optimizations !code/simplification/arithmetic,!code/simplification/cast,!field/*,!class/merging/*
-optimizationpasses 7

# 移除未使用的资源引用
-dontwarn **

# 保留异常信息
-keepattributes Exceptions

# 保留内部类信息
-keepattributes InnerClasses

# 保留泛型信息
-keepattributes Signature

# ==================== 反调试和反逆向规则 ====================
# 移除调试相关的方法调用
-assumenosideeffects class java.lang.Thread {
    public static void dumpStack();
}

# 移除反射相关的调试信息
-keepattributes !*Annotation*,Signature,InnerClasses,EnclosingMethod

# 增强代码混淆强度
-overloadaggressively
-allowaccessmodification
-mergeinterfacesaggressively

# 字符串加密增强规则
-adaptclassstrings !load.tencent.lib.AppStrings