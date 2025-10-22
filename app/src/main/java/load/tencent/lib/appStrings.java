package load.tencent.lib;

/**
 * 统一管理应用中所有加密字符串的类
 * 通过JNI从C层获取所有字符串常量
 */
public class appStrings {
    
    // 加载native库
    static {
        System.loadLibrary("996cq_native");
    }
    
    // 直接调用JNI方法
    private static native String getAppStringNative(String key);
    
    // 从C层获取字符串的辅助方法
    private static String getString(String key) {
        try {
            return getAppStringNative(key);
        } catch (Exception e) {
            e.printStackTrace();
            return "";
        }
    }
    
    // 基础配置常量
    public static final String PREF_NAME = getString("PREF_NAME");
    public static final String KEY_KAM = getString("KEY_KAM");
    public static final String KEY_ID = getString("KEY_ID");
    public static final String KEY_TOKEN = getString("KEY_TOKEN");
    public static final String KEY_LAST_INPUT = getString("KEY_LAST_INPUT");
    
    // UI文本常量
    public static final String TEXT_LICENSE_HINT = getString("TEXT_LICENSE_HINT");
    public static final String TEXT_LICENSE_EMPTY = getString("TEXT_LICENSE_EMPTY");
    public static final String TEXT_APP_TIPS = getString("TEXT_APP_TIPS");
    public static final String BUTTON_LOGIN = getString("BUTTON_LOGIN");
    public static final String ERROR_VERIFICATION_FORMAT = getString("ERROR_VERIFICATION_FORMAT");
    public static final String ERROR_LAUNCH_FAIL = getString("ERROR_LAUNCH_FAIL");
    public static final String EXPIRY_TIME_TEXT = getString("EXPIRY_TIME_TEXT");
    public static final String OFFLINE_TRIGGERED = getString("OFFLINE_TRIGGERED");
    
    public static final String Sative = getString("Sative");
    // 悬浮窗UI常量
    public static final String FLOAT_MENU_TITLE = getString("FLOAT_MENU_TITLE");
    public static final String ATTACK_SPEED_LABEL = getString("ATTACK_SPEED_LABEL");
    public static final String MOVE_SPEED_LABEL = getString("MOVE_SPEED_LABEL");
    public static final String WILD_SPEED_LABEL = getString("WILD_SPEED_LABEL");
    public static final String HP_THRESHOLD_LABEL = getString("HP_THRESHOLD_LABEL");
    public static final String HP_RECOVERY_LABEL = getString("HP_RECOVERY_LABEL");
    public static final String SPEED_CLOSED = getString("SPEED_CLOSED");
    public static final String SPEED_CLOSED_WITH_ZERO = getString("SPEED_CLOSED_WITH_ZERO");
    public static final String SPEED_UNIT = getString("SPEED_UNIT");
    public static final String STATUS_ENABLED = getString("STATUS_ENABLED");
    public static final String STATUS_DISABLED = getString("STATUS_DISABLED");
    public static final String STATUS_ENABLED_SUCCESS = getString("STATUS_ENABLED_SUCCESS");
    public static final String STATUS_DISABLED_SUCCESS = getString("STATUS_DISABLED_SUCCESS");
    public static final String NOTICE_PREFIX = getString("NOTICE_PREFIX");
    
    // 功能提示常量
    public static final String FUNCTION_NO_DESCRIPTION = getString("FUNCTION_NO_DESCRIPTION");
    public static final String DDMZ_FUNCTION_TIP = getString("DDMZ_FUNCTION_TIP");
    public static final String DDMZ_FUNCTION_PROCESSING = getString("DDMZ_FUNCTION_PROCESSING");
    public static final String DDMZ_FUNCTION_NAME = getString("DDMZ_FUNCTION_NAME");
    
    // HTTP验证相关常量
    public static final String HTTP_VALIDATION_EFFECTIVE = getString("HTTP_VALIDATION_EFFECTIVE");
    public static final String HTTP_VALIDATION_INVALID = getString("HTTP_VALIDATION_INVALID");
    public static final String HTTP_VALIDATION_FAILED_PREFIX = getString("HTTP_VALIDATION_FAILED_PREFIX");
    public static final String HTTP_VALIDATION_FAILED_GENERAL = getString("HTTP_VALIDATION_FAILED_GENERAL");
    public static final String HTTP_RESPONSE_PARSE_FAILED = getString("HTTP_RESPONSE_PARSE_FAILED");
    public static final String HTTP_RESPONSE_ORIGINAL = getString("HTTP_RESPONSE_ORIGINAL");
    public static final String HTTP_HEARTBEAT_FAILED = getString("HTTP_HEARTBEAT_FAILED");
    public static final String HTTP_HEARTBEAT_EXPIRED = getString("HTTP_HEARTBEAT_EXPIRED");
    public static final String HTTP_HEARTBEAT_UNKNOWN = getString("HTTP_HEARTBEAT_UNKNOWN");
    public static final String HTTP_HEARTBEAT_PARSE_ERROR = getString("HTTP_HEARTBEAT_PARSE_ERROR");
    public static final String HTTP_ERROR_CODE_EXCEPTION = getString("HTTP_ERROR_CODE_EXCEPTION");
    public static final String HTTP_AUTH_EXPIRED = getString("HTTP_AUTH_EXPIRED");
    public static final String HTTP_OTHER_UNKNOWN_REASON = getString("HTTP_OTHER_UNKNOWN_REASON");
    
    // 权限相关常量
    public static final String PERMISSION_REQUEST_TITLE = getString("PERMISSION_REQUEST_TITLE");
    public static final String PERMISSION_REQUEST_MESSAGE = getString("PERMISSION_REQUEST_MESSAGE");
    public static final String PERMISSION_START_AUTH = getString("PERMISSION_START_AUTH");
    public static final String STORAGE_PERMISSION_TITLE = getString("STORAGE_PERMISSION_TITLE");
    public static final String STORAGE_PERMISSION_MESSAGE = getString("STORAGE_PERMISSION_MESSAGE");
    public static final String STORAGE_PERMISSION_DENIED = getString("STORAGE_PERMISSION_DENIED");
    public static final String OVERLAY_PERMISSION_TITLE = getString("OVERLAY_PERMISSION_TITLE");
    public static final String OVERLAY_PERMISSION_MESSAGE = getString("OVERLAY_PERMISSION_MESSAGE");
    public static final String OVERLAY_PERMISSION_DENIED = getString("OVERLAY_PERMISSION_DENIED");
    public static final String GENERAL_PERMISSION_TITLE = getString("GENERAL_PERMISSION_TITLE");
    public static final String GENERAL_PERMISSION_MESSAGE = getString("GENERAL_PERMISSION_MESSAGE");
    public static final String BUTTON_CONFIRM = getString("BUTTON_CONFIRM");
    public static final String BUTTON_GO_SETTINGS = getString("BUTTON_GO_SETTINGS");
    public static final String BUTTON_RETRY = getString("BUTTON_RETRY");
    public static final String BUTTON_CANCEL = getString("BUTTON_CANCEL");
    
    // 应用状态提示常量
    public static final String OVERLAY_PERMISSION_WARNING = getString("OVERLAY_PERMISSION_WARNING");
    public static final String DEVICE_INIT_FAILED = getString("DEVICE_INIT_FAILED");
    public static final String AUTH_VERIFYING = getString("AUTH_VERIFYING");
    public static final String AUTH_VERIFY_FAILED = getString("AUTH_VERIFY_FAILED");
    public static final String AUTH_NO_VERIFYING_INFO = getString("AUTH_NO_VERIFYING_INFO");
    
    // HTTP相关常量
    public static final String HTTP_API_URL = getString("HTTP_API_URL");
    public static final String HTTP_PARAM_TB = getString("HTTP_PARAM_TB");
    public static final String HTTP_PARAM_CDK = getString("HTTP_PARAM_CDK");
    public static final String HTTP_PARAM_IMEI = getString("HTTP_PARAM_IMEI");
    public static final String HTTP_PARAM_TOK = getString("HTTP_PARAM_TOK");
    public static final String HTTP_PARAM_CANSHU = getString("HTTP_PARAM_CANSHU");
    public static final String HTTP_DEFAULT_TB_VALUE = getString("HTTP_DEFAULT_TB_VALUE");
    public static final String HTTP_TEXT_LOGIN = getString("HTTP_TEXT_LOGIN");
    public static final String HTTP_TEXT_VALIDATION_SUCCESS = getString("HTTP_TEXT_VALIDATION_SUCCESS");
    public static final String HTTP_TEXT_EXPIRED_NOTICE = getString("HTTP_TEXT_EXPIRED_NOTICE");
    public static final String HTTP_TEXT_EXIT_APP = getString("HTTP_TEXT_EXIT_APP");
    public static final String HTTP_TEXT_LICENSE_CHECK = getString("HTTP_TEXT_LICENSE_CHECK");
    public static final String HTTP_TEXT_HEARTBEAT = getString("HTTP_TEXT_HEARTBEAT");
    public static final String HTTP_TEXT_VERIFICATION_CODE_EXPIRED = getString("HTTP_TEXT_VERIFICATION_CODE_EXPIRED");
    public static final String HTTP_TEXT_INVALID = getString("HTTP_TEXT_INVALID");
    public static final String HTTP_TEXT_AUTH = getString("HTTP_TEXT_AUTH");
    public static final String HTTP_TEXT_HEARTBEAT_SHORT = getString("HTTP_TEXT_HEARTBEAT_SHORT");
    public static final String HTTP_TEXT_RESPONSE_FORMAT = getString("HTTP_TEXT_RESPONSE_FORMAT");
    public static final String HTTP_PARAM_VALUE_1 = getString("HTTP_PARAM_VALUE_1");
    public static final String HTTP_PARAM_VALUE_2 = getString("HTTP_PARAM_VALUE_2");
    public static final String HTTP_PARAM_TOKEN_SPACE = getString("HTTP_PARAM_TOKEN_SPACE");
    public static final String HTTP_PARAM_LICENSE_KEY_SPACE = getString("HTTP_PARAM_LICENSE_KEY_SPACE");
    public static final String HTTP_PARAM_DEVICE_ID = getString("HTTP_PARAM_DEVICE_ID");
    
    // HTTP错误提示常量
    public static final String HTTP_ERROR_PARAM_NULL = getString("HTTP_ERROR_PARAM_NULL");
    public static final String HTTP_ERROR_REQUEST_FAILED = getString("HTTP_ERROR_REQUEST_FAILED");
    public static final String HTTP_ERROR_SERVER_RESPONSE = getString("HTTP_ERROR_SERVER_RESPONSE");
    
    // 资源路径常量
    public static final String GAME_ACTIVITY_CLASS_NAME1 = getString("GAME_ACTIVITY_CLASS_NAME1");
    public static final String GAME_ACTIVITY_CLASS_NAME = getString("GAME_ACTIVITY_CLASS_NAME");
    public static final String RESOURCE_MOD_DIR = getString("RESOURCE_MOD_DIR");
    public static final String RESOURCE_SCRIPTS_PATH = getString("RESOURCE_SCRIPTS_PATH");
    public static final String RESOURCE_DEFAULT_SCRIPT = getString("RESOURCE_DEFAULT_SCRIPT");
    public static final String SCRIPT_DEFAULT_CONTENT = getString("SCRIPT_DEFAULT_CONTENT");
    public static final String EXCLUDE_FILE = getString("EXCLUDE_FILE");
    
    // 字体文件常量
    public static final String FONT_ZT2 = getString("FONT_ZT2");
    public static final String FONT_ZT3 = getString("FONT_ZT3");
    public static final String FONT_XS = getString("FONT_XS");
    
    // 功能描述常量
    public static final String ATTACK_SPEED_DESC = getString("ATTACK_SPEED_DESC");
    public static final String ATTACK_SPEED_SET = getString("ATTACK_SPEED_SET");
    public static final String ATTACK_SPEED_OFF = getString("ATTACK_SPEED_OFF");
    public static final String MOVE_SPEED_DESC = getString("MOVE_SPEED_DESC");
    public static final String MOVE_SPEED_SET = getString("MOVE_SPEED_SET");
    public static final String MOVE_SPEED_OFF = getString("MOVE_SPEED_OFF");
    public static final String WILD_SPEED_DESC = getString("WILD_SPEED_DESC");
    public static final String WILD_SPEED_SET = getString("WILD_SPEED_SET");
    public static final String WILD_SPEED_OFF = getString("WILD_SPEED_OFF");
    public static final String HP_THRESHOLD_DESC = getString("HP_THRESHOLD_DESC");
    public static final String HP_THRESHOLD_SET = getString("HP_THRESHOLD_SET");
    public static final String HP_THRESHOLD_OFF = getString("HP_THRESHOLD_OFF");
    public static final String HP_RECOVERY_DESC = getString("HP_RECOVERY_DESC");
    public static final String HP_RECOVERY_SET = getString("HP_RECOVERY_SET");
    public static final String HP_RECOVERY_OFF = getString("HP_RECOVERY_OFF");
    public static final String SPEED_EFFECT = getString("SPEED_EFFECT");
    public static final String HP_THRESHOLD_EFFECT = getString("HP_THRESHOLD_EFFECT");
    public static final String UTIL_DESCRIPTION = getString("UTIL_DESCRIPTION");
    public static final String DDLHtip = getString("DDLH_TIP");
    
    // 文件路径常量
    public static final String KEY_HP_RECOVERY_IDCY = getString("KEY_HP_RECOVERY_IDCY");
    public static final String DEVICE_ID_FILE_NAME = getString("DEVICE_ID_FILE_NAME");
    public static final String DEVICE_ID_FILE_TXT = getString("DEVICE_ID_FILE_TXT");
    public static final String STORAGE_PATH_DOCUMENTS = getString("STORAGE_PATH_DOCUMENTS");
    
    // SharedPreferences键值常量
    public static final String PREF_KEY_ATTACK_SPEED = getString("PREF_KEY_ATTACK_SPEED");
    public static final String PREF_KEY_MOVE_SPEED = getString("PREF_KEY_MOVE_SPEED");
    public static final String PREF_KEY_WILD_SPEED = getString("PREF_KEY_WILD_SPEED");
    public static final String PREF_KEY_HP_THRESHOLD = getString("PREF_KEY_HP_THRESHOLD");
    public static final String PREF_KEY_HP_RECOVERY_SPEED = getString("PREF_KEY_HP_RECOVERY_SPEED");
    
    // 功能设置常量
    public static final String SETTING_BARBARIC_SPEED = getString("SETTING_BARBARIC_SPEED");
    public static final String SETTING_SKILL_CD = getString("SETTING_SKILL_CD");
    public static final String SETTING_FORCE_ASSASSINATION = getString("SETTING_FORCE_ASSASSINATION");
    public static final String SETTING_AUTO_PICKUP = getString("SETTING_AUTO_PICKUP");
    public static final String SETTING_QUICK_SKILL = getString("SETTING_QUICK_SKILL");
    public static final String SETTING_FORCE_SBYS = getString("SETTING_FORCE_SBYS");
    public static final String DoubleFire = getString("DOUBLE_FIRE");
    public static final String dashnotime = getString("DASH_NO_TIME");
    public static final String NOCD = getString("NO_CD");
    public static final String DDMZ = getString("DDMZ");
    public static final String booldoffline = getString("BOOL_OFFLINE");
    public static final String offlineBTN = getString("OFFLINE_BTN");
    public static final String JFPBTNUI = getString("JFP_BTN_UI");
    public static final String DDLH = getString("DDLH");
    public static final String quickBOOK = getString("QUICK_BOOK");
    public static final String exit_buff = getString("exit_buff");
    public static final String SETTING_CHUDAO_YM = getString("SETTING_CHUDAO_YM");
    public static final String SETTING_CHUDAO_JGDY = getString("SETTING_CHUDAO_JGDY");
    public static final String QUICK_BOOK_TIP = getString("QUICK_BOOK_TIP");
    public static final String SBYS_AND_YM = getString("SBYS_AND_YM");
    public static final String SETTING_FORCE_BSYY = getString("SETTING_FORCE_BSYY");
    public static final String SETTING_FORCE_SWZY = getString("SETTING_FORCE_SWZY");
    // 系统相关常量
    public static final String ANDROID_CATEGORY_DEFAULT = getString("ANDROID_CATEGORY_DEFAULT");
    public static final String PACKAGE_URI_PREFIX = getString("PACKAGE_URI_PREFIX");
    public static final String SHA_256_ALGORITHM = getString("SHA_256_ALGORITHM");
    public static final String DATE_FORMAT_PATTERN = getString("DATE_FORMAT_PATTERN");
    public static final String DEFAULT_HASH_VALUE = getString("DEFAULT_HASH_VALUE");
    
    // 错误代码常量
    public static final String ERROR_CODE_DD000 = getString("ERROR_CODE_DD000");
    public static final String ERROR_CODE_DD001 = getString("ERROR_CODE_DD001");
    public static final String ERROR_CODE_DD002 = getString("ERROR_CODE_DD002");
    public static final String ERROR_CODE_DD003 = getString("ERROR_CODE_DD003");
    public static final String ERROR_CODE_DD004 = getString("ERROR_CODE_DD004");
    public static final String ERROR_CODE_DD005 = getString("ERROR_CODE_DD005");
    public static final String ERROR_CODE_DD006 = getString("ERROR_CODE_DD006");
    public static final String ERROR_CODE_DD007 = getString("ERROR_CODE_DD007");
    public static final String ERROR_CODE_SKCD000 = getString("ERROR_CODE_SKCD000");
    public static final String ERROR_CODE_SKCD001 = getString("ERROR_CODE_SKCD001");
    public static final String ERROR_CODE_SKCD002 = getString("ERROR_CODE_SKCD002");
    public static final String ERROR_CODE_SKCD003 = getString("ERROR_CODE_SKCD003");
    public static final String ERROR_CODE_SKCD004 = getString("ERROR_CODE_SKCD004");
    public static final String ERROR_CODE_SKCD005 = getString("ERROR_CODE_SKCD005");
    public static final String ERROR_CODE_SKCD006 = getString("ERROR_CODE_SKCD006");
    public static final String ERROR_CODE_SKCD007 = getString("ERROR_CODE_SKCD007");
    public static final String SUCCESS_RESULT = getString("SUCCESS_RESULT");
    
    // 内存操作相关常量
    public static final String MEMORY_VALUE_001 = getString("MEMORY_VALUE_001");
    public static final String NATIVE_LIBRARY_NAME = getString("NATIVE_LIBRARY_NAME");
    
    // 系统组件常量
    public static final String MIUI_POWERKEEPER_PACKAGE = getString("MIUI_POWERKEEPER_PACKAGE");
    public static final String MIUI_POWERKEEPER_ACTIVITY = getString("MIUI_POWERKEEPER_ACTIVITY");
    public static final String ACTIVITY_THREAD_CLASS = getString("ACTIVITY_THREAD_CLASS");
    public static final String CURRENT_APPLICATION_METHOD = getString("CURRENT_APPLICATION_METHOD");
    
    // 网络状态常量
    public static final String NETWORK_CONNECTED = getString("NETWORK_CONNECTED");
    public static final String NETWORK_DISCONNECTED = getString("NETWORK_DISCONNECTED");
    public static final String SYSTEM_VERSION_LOW = getString("SYSTEM_VERSION_LOW");
    
    // 功能执行状态常量
    public static final String FUNCTION_EXECUTING = getString("FUNCTION_EXECUTING");
    public static final String FUNCTION_SUCCESS = getString("FUNCTION_SUCCESS");
    public static final String FUNCTION_FAILED = getString("FUNCTION_FAILED");
    public static final String FUNCTION_ENABLED = getString("FUNCTION_ENABLED");
    public static final String FUNCTION_DISABLED = getString("FUNCTION_DISABLED");
    public static final String DDMZ_FUNCTION_FAILED_PREFIX = getString("DDMZ_FUNCTION_FAILED_PREFIX");
    public static final String SKCD_FUNCTION_FAILED_PREFIX = getString("SKCD_FUNCTION_FAILED_PREFIX");
    public static final String FUNCTION_EXECUTION_FAILED = getString("FUNCTION_EXECUTION_FAILED");
    
    // 日期时间格式常量
    public static final String DATE_REGEX_PATTERN = getString("DATE_REGEX_PATTERN");
    public static final String EXPIRY_TIME_PREFIX = getString("EXPIRY_TIME_PREFIX");
    
    // 权限检查相关常量
    public static final String PERMISSION_GRANTED = getString("PERMISSION_GRANTED");
    public static final String PERMISSION_DENIED = getString("PERMISSION_DENIED");
    public static final String STORAGE_PERMISSION_SUFFIX = getString("STORAGE_PERMISSION_SUFFIX");
    public static final String OVERLAY_PERMISSION_SUFFIX = getString("OVERLAY_PERMISSION_SUFFIX");
    public static final String ANDROID_11_PLUS = getString("ANDROID_11_PLUS");
    public static final String ANDROID_10_MINUS = getString("ANDROID_10_MINUS");
}