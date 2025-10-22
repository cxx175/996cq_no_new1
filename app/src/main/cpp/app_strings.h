#ifndef APP_STRINGS_H
#define APP_STRINGS_H

#include <cstring>
#include <cstdlib>

#ifdef __cplusplus
#include <string>
#endif

// 解密函数
static const unsigned char DECRYPT_KEY[] = {0x39, 0x39, 0x36, 0x43, 0x51, 0x5f, 0x45, 0x4e, 0x43, 0x52, 0x59, 0x50, 0x54, 0x5f, 0x4b, 0x45, 0x59, 0x5f, 0x32, 0x30, 0x32, 0x34};
static const int DECRYPT_KEY_LEN = 22;

// 安全的内存分配函数
static void* safe_malloc(size_t size) {
    if (size == 0 || size > 1024 * 1024) {  // 限制最大1MB
        return nullptr;
    }
    try {
        return malloc(size);
    } catch (...) {
        return nullptr;
    }
}

// 处理转义字符的函数
static char* process_escape_sequences(const char* input) {
    if (!input) return nullptr;
    
    int len = strlen(input);
    char* output = (char*)safe_malloc(len + 1);
    if (!output) return nullptr;
    
    int i = 0, j = 0;
    while (i < len) {
        if (input[i] == '\\' && i + 1 < len) {
            // 处理转义字符
            switch (input[i + 1]) {
                case 'n':
                    output[j++] = '\n';  // 换行符
                    i += 2;
                    break;
                case 't':
                    output[j++] = '\t';  // 制表符
                    i += 2;
                    break;
                case 'r':
                    output[j++] = '\r';  // 回车符
                    i += 2;
                    break;
                case '\\':
                    output[j++] = '\\';  // 反斜杠
                    i += 2;
                    break;
                case '"':
                    output[j++] = '"';   // 双引号
                    i += 2;
                    break;
                case '\'':
                    output[j++] = '\''; // 单引号
                    i += 2;
                    break;
                default:
                    // 不是已知的转义字符，保持原样
                    output[j++] = input[i++];
                    break;
            }
        } else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
    return output;
}

static char* decrypt_string(const char* encrypted_base64) {
    if (!encrypted_base64) {
        return nullptr;
    }
    
    // 🚨 线程安全修复：使用线程局部存储替代全局volatile标志
    thread_local static bool decryption_initialized = false;
    
    // 简单的初始化检查（每个线程独立初始化）
    if (!decryption_initialized) {
        decryption_initialized = true;
    }
    
    // Base64解码
    int len = strlen(encrypted_base64);
    if (len == 0 || len > 10240) {  // 限制输入长度
        return nullptr;
    }
    
    // 检查长度是否合理（Base64字符串长度应该是4的倍数）
    if (len % 4 != 0) {
        return nullptr;
    }
    
    // 计算填充字符数量
    int padding = 0;
    if (len >= 2) {
        if (encrypted_base64[len-1] == '=') padding++;
        if (encrypted_base64[len-2] == '=') padding++;
    }
    
    // 计算解码后的长度
    int decoded_len = (len * 3) / 4 - padding;
    
    // 安全检查：确保解码长度合理
    if (decoded_len <= 0 || decoded_len > 8192) {  // 限制最大8KB
        return nullptr;
    }
    
    unsigned char* decoded = (unsigned char*)safe_malloc(decoded_len + 1);
    if (!decoded) {
        return nullptr;
    }
    
    // 初始化内存
    memset(decoded, 0, decoded_len + 1);
    
    // Base64字符表
    const char* base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    int i = 0, j = 0;
    int decoded_pos = 0;
    unsigned char char_array_4[4], char_array_3[3];
    
    // 初始化数组
    memset(char_array_4, 0, sizeof(char_array_4));
    memset(char_array_3, 0, sizeof(char_array_3));
    
    while (i < len && encrypted_base64[i] != '=' && decoded_pos < decoded_len) {
        const char* pos = strchr(base64_chars, encrypted_base64[i]);
        if (!pos) {
            free(decoded);
            return nullptr;
        }
        char_array_4[j++] = pos - base64_chars;
        i++;
        
        if (j == 4) {
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
            
            for (int k = 0; k < 3 && decoded_pos < decoded_len; k++) {
                decoded[decoded_pos++] = char_array_3[k];
            }
            j = 0;
        }
    }
    
    // 处理剩余的字符
    if (j > 0 && decoded_pos < decoded_len) {
        for (int k = j; k < 4; k++) {
            char_array_4[k] = 0;
        }
        
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
        
        for (int k = 0; k < j - 1 && decoded_pos < decoded_len; k++) {
            decoded[decoded_pos++] = char_array_3[k];
        }
    }
    
    // XOR解密
    try {
        for (int k = 0; k < decoded_pos; k++) {
            decoded[k] ^= DECRYPT_KEY[k % DECRYPT_KEY_LEN];
        }
    } catch (...) {
        free(decoded);
        return nullptr;
    }
    
    decoded[decoded_pos] = '\0';
    
    // 处理转义字符
    char* processed = process_escape_sequences((char*)decoded);
    free(decoded);
    
    return processed;
}

// 简化的解密函数，使用线程安全的实现
static const char* get_decrypted_string(const char* encrypted_base64) {
    // 添加空指针检查
    if (!encrypted_base64) {
        return "";
    }
    
    // 🚨 线程安全修复：使用线程局部存储
    thread_local static char string_pool[65536];  // 每个线程独立的内存池
    thread_local static int pool_offset = 0;      // 每个线程独立的偏移量
    thread_local static bool pool_initialized = false;
    
    // 线程局部初始化
    if (!pool_initialized) {
        memset(string_pool, 0, sizeof(string_pool));
        pool_offset = 0;
        pool_initialized = true;
    }
    
    // 直接解密
    char* decrypted = decrypt_string(encrypted_base64);
    if (decrypted) {
        int len = strlen(decrypted);
        
        // 检查内存池空间，如果不足则重置（循环使用）
        if (pool_offset + len + 1 >= sizeof(string_pool)) {
            pool_offset = 0;  // 重置偏移量，循环使用内存池
        }
        
        // 安全复制字符串
        if (pool_offset + len + 1 < sizeof(string_pool)) {
            char* result = string_pool + pool_offset;
            strcpy(result, decrypted);
            pool_offset += len + 1;
            free(decrypted);
            return result;
        }
        
        free(decrypted);
    }
    
    return "";
}

#define ENCRYPTED_PREF_NAME "dEBmMTQ5"
#define PREF_NAME get_decrypted_string(ENCRYPTED_PREF_NAME)
#define ENCRYPTED_KEY_KAM "Ulhb"
#define KEY_KAM get_decrypted_string(ENCRYPTED_KEY_KAM)
#define ENCRYPTED_KEY_ID "UF0="
#define KEY_ID get_decrypted_string(ENCRYPTED_KEY_ID)
#define ENCRYPTED_KEY_TOKEN "TVZdJj8="
#define KEY_TOKEN get_decrypted_string(ENCRYPTED_KEY_TOKEN)
#define ENCRYPTED_KEY_LAST_INPUT "VVhFNw42Kz42Jg=="
#define KEY_LAST_INPUT get_decrypted_string(ENCRYPTED_KEY_LAST_INPUT)
#define ENCRYPTED_TEXT_LICENSE_HINT "0ZaBq+/MoMvmtObQsuvwovne"
#define TEXT_LICENSE_HINT get_decrypted_string(ENCRYPTED_TEXT_LICENSE_HINT)
#define ENCRYPTED_TEXT_LICENSE_EMPTY "37e+pczcou7CtuHdvNz2oeHl1ZmI"
#define TEXT_LICENSE_EMPTY get_decrypted_string(ENCRYPTED_TEXT_LICENSE_EMPTY)
#define ENCRYPTED_TEXT_APP_TIPS "CBff5ce56e+r7cK10fqt/eG5ur8e0qKN0NXhutXApu3cufXkosLUuqKf1IyB377MDTF3YKXf+7jg+a7K7rm6ptqTq9G/8bTgwKfi6bz087bLxbzXtda/lg=="
#define TEXT_APP_TIPS get_decrypted_string(ENCRYPTED_TEXT_APP_TIPS)
#define ENCRYPTED_BUTTON_LOGIN "3qCNpuzK"
#define BUTTON_LOGIN get_decrypted_string(ENCRYPTED_BUTTON_LOGIN)
#define ENCRYPTED_ERROR_VERIFICATION_FORMAT "0JO6q/7erfHXt8LOsv/3oOXQ14yw0YGB"
#define ERROR_VERIFICATION_FORMAT get_decrypted_string(ENCRYPTED_ERROR_VERIFICATION_FORMAT)
#define ENCRYPTED_ERROR_LAUNCH_FAIL "3KmZptv3oOryuu31eLr897zErNW6hN+YuqrM/Q=="
#define ERROR_LAUNCH_FAIL get_decrypted_string(ENCRYPTED_ERROR_LAUNCH_FAIL)
#define ENCRYPTED_EXPIRY_TIME_TEXT "3LGGpc3Ao9n1u87k"
#define EXPIRY_TIME_TEXT get_decrypted_string(ENCRYPTED_EXPIRY_TIME_TEXT)
#define ENCRYPTED_OFFLINE_TRIGGERED "3IW2ptTsrenlt9bB"
#define OFFLINE_TRIGGERED get_decrypted_string(ENCRYPTED_OFFLINE_TRIGGERED)
#define ENCRYPTED_FLOAT_MENU_TITLE "AAAAAAC3ytKm38w="
#define FLOAT_MENU_TITLE get_decrypted_string(ENCRYPTED_FLOAT_MENU_TITLE)
#define ENCRYPTED_ATTACK_SPEED_LABEL "362NptbkrM7ct+P2u+PR"
#define ATTACK_SPEED_LABEL get_decrypted_string(ENCRYPTED_ATTACK_SPEED_LABEL)
#define ENCRYPTED_MOVE_SPEED_LABEL "3p6Nptv3rM7ct+P2u+PR"
#define MOVE_SPEED_LABEL get_decrypted_string(ENCRYPTED_MOVE_SPEED_LABEL)
#define ENCRYPTED_WILD_SPEED_LABEL "0L64q8rxrM7ct+P2u+PR"
#define WILD_SPEED_LABEL get_decrypted_string(ENCRYPTED_WILD_SPEED_LABEL)
#define ENCRYPTED_HP_THRESHOLD_LABEL "0Zi2qtbQofPNtuPeu+PR"
#define HP_THRESHOLD_LABEL get_decrypted_string(ENCRYPTED_HP_THRESHOLD_LABEL)
#define ENCRYPTED_HP_RECOVERY_LABEL "3LOWqtHAoNXduvjQu+PR"
#define HP_RECOVERY_LABEL get_decrypted_string(ENCRYPTED_HP_RECOVERY_LABEL)
#define ENCRYPTED_SPEED_CLOSED "3LyFqsby"
#define SPEED_CLOSED get_decrypted_string(ENCRYPTED_SPEED_CLOSED)
#define ENCRYPTED_SPEED_CLOSED_WITH_ZERO "CRHTxuK20uNq"
#define SPEED_CLOSED_WITH_ZERO get_decrypted_string(ENCRYPTED_SPEED_CLOSED_WITH_ZERO)
#define ENCRYPTED_SPEED_UNIT "FggGcw=="
#define SPEED_UNIT get_decrypted_string(ENCRYPTED_SPEED_UNIT)
#define ENCRYPTED_STATUS_ENABLED "3IW2psHw"
#define STATUS_ENABLED get_decrypted_string(ENCRYPTED_STATUS_ENABLED)
#define ENCRYPTED_STATUS_DISABLED "3LyFqsby"
#define STATUS_DISABLED get_decrypted_string(ENCRYPTED_STATUS_DISABLED)
#define ENCRYPTED_STATUS_ENABLED_SUCCESS "3IW2psHwo8bTt9PPdAQEDgQ="
#define STATUS_ENABLED_SUCCESS get_decrypted_string(ENCRYPTED_STATUS_ENABLED_SUCCESS)
#define ENCRYPTED_STATUS_DISABLED_SUCCESS "3LyFqsbyo8bTt9PPdAQEAx8C"
#define STATUS_DISABLED_SUCCESS get_decrypted_string(ENCRYPTED_STATUS_DISABLED_SUCCESS)
#define ENCRYPTED_NOTICE_PREFIX "34qepdXQfw=="
#define NOTICE_PREFIX get_decrypted_string(ENCRYPTED_NOTICE_PREFIX)
#define ENCRYPTED_FUNCTION_NO_DESCRIPTION "366Wq/7ro9bN"
#define FUNCTION_NO_DESCRIPTION get_decrypted_string(ENCRYPTED_FUNCTION_NO_DESCRIPTION)
#define ENCRYPTED_DDMZ_FUNCTION_TIP "3IW2psHwoMbDt9HQsc72oeHy26yy3J+40v7uuNHmqsjWtsjlZ6PRydqwt92+tN78yrrZ/qbJ57bd0q/5w7muudShsd+o3w=="
#define DDMZ_FUNCTION_TIP get_decrypted_string(ENCRYPTED_DDMZ_FUNCTION_TIP)
#define ENCRYPTED_DDMZ_FUNCTION_PROCESSING "35SVps33"
#define DDMZ_FUNCTION_PROCESSING get_decrypted_string(ENCRYPTED_DDMZ_FUNCTION_PROCESSING)
#define ENCRYPTED_DDMZ_FUNCTION_NAME "3LG2ptnfoN/+tuH9sdXUrdriHB4c"
#define DDMZ_FUNCTION_NAME get_decrypted_string(ENCRYPTED_DDMZ_FUNCTION_NAME)
#define ENCRYPTED_HTTP_VALIDATION_EFFECTIVE "36W/pcTX"
#define HTTP_VALIDATION_EFFECTIVE get_decrypted_string(ENCRYPTED_HTTP_VALIDATION_EFFECTIVE)
#define ENCRYPTED_HTTP_VALIDATION_INVALID "366WpcTX"
#define HTTP_VALIDATION_INVALID get_decrypted_string(ENCRYPTED_HTTP_VALIDATION_INVALID)
#define ENCRYPTED_HTTP_VALIDATION_FAILED_PREFIX "0JO6q/7eo9Lpu9nKvODMfw=="
#define HTTP_VALIDATION_FAILED_PREFIX get_decrypted_string(ENCRYPTED_HTTP_VALIDATION_FAILED_PREFIX)
#define ENCRYPTED_HTTP_VALIDATION_FAILED_GENERAL "0JO6q/7eoOryuu31u+PR"
#define HTTP_VALIDATION_FAILED_GENERAL get_decrypted_string(ENCRYPTED_HTTP_VALIDATION_FAILED_GENERAL)
#define ENCRYPTED_HTTP_RESPONSE_PARSE_FAILED "0Z6Vpc/PoN3Ot+PEssr7o9Tx15SD3I2cDA=="
#define HTTP_RESPONSE_PARSE_FAILED get_decrypted_string(ENCRYPTED_HTTP_RESPONSE_PARSE_FAILED)
#define ENCRYPTED_HTTP_RESPONSE_ORIGINAL "3LeppvbUoN3Ot+PEbg=="
#define HTTP_RESPONSE_ORIGINAL get_decrypted_string(ENCRYPTED_HTTP_RESPONSE_ORIGINAL)
#define ENCRYPTED_HTTP_HEARTBEAT_FAILED "3Ia1q+bsrOTPuvbRsfv6re36CA=="
#define HTTP_HEARTBEAT_FAILED get_decrypted_string(ENCRYPTED_HTTP_HEARTBEAT_FAILED)
#define ENCRYPTED_HTTP_HEARTBEAT_EXPIRED "3Ia1q+bsrOTPuvbRssf1ov3l1L660qS60/Tjt/rJpc7Gag=="
#define HTTP_HEARTBEAT_EXPIRED get_decrypted_string(ENCRYPTED_HTTP_HEARTBEAT_EXPIRED)
#define ENCRYPTED_HTTP_HEARTBEAT_UNKNOWN "3Ia1q+bsrOTPuvbRvODfoMLB1KyY06ac0cnnucXPeQ=="
#define HTTP_HEARTBEAT_UNKNOWN get_decrypted_string(ENCRYPTED_HTTP_HEARTBEAT_UNKNOWN)
#define ENCRYPTED_HTTP_HEARTBEAT_PARSE_ERROR "0JO6q/7eoOryuu31bn+j4vq5rKDXp7TcjNe3yvWozvy81+6239y2477YnYPfmralzvqi89K14sy84NWj1/o="
#define HTTP_HEARTBEAT_PARSE_ERROR get_decrypted_string(ENCRYPTED_HTTP_HEARTBEAT_PARSE_ERROR)
#define ENCRYPTED_HTTP_ERROR_CODE_EXCEPTION "0K2vq/7wou7Ct+XSsefz"
#define HTTP_ERROR_CODE_EXCEPTION get_decrypted_string(ENCRYPTED_HTTP_ERROR_CODE_EXCEPTION)
#define ENCRYPTED_HTTP_AUTH_EXPIRED "37e+pczcoPnxt9HgssPU"
#define HTTP_AUTH_EXPIRED get_decrypted_string(ENCRYPTED_HTTP_AUTH_EXPIRED)
#define ENCRYPTED_HTTP_OTHER_UNKNOWN_REASON "3LyAp+rJo9Lptcb1sdHUoML/CA=="
#define HTTP_OTHER_UNKNOWN_REASON get_decrypted_string(ENCRYPTED_HTTP_OTHER_UNKNOWN_REASON)
#define ENCRYPTED_PERMISSION_REQUEST_TITLE "36S1qsjPotrwuvbn"
#define PERMISSION_REQUEST_TITLE get_decrypted_string(ENCRYPTED_PERMISSION_REQUEST_TITLE)
#define ENCRYPTED_PERMISSION_REQUEST_MESSAGE "3IOipMX3rNLDuv/RsOTuoeHU1K2x3aCp0Mrct8bzpf/6tezno/rJt5O8CGhXZVih0f1lq+7KvNL8udbGsMaiChLTrZHS+d+7+tOm/8G169qj49i4qLTUor7djfUNMafO4XK+xOG35Ni+1YTWsrUDGdHX+bv/wKvc7rXbyaPr57qWt9aLmN+37A0xp87hcr7txbjw2b/CsdmrpAMZ0df5u//Aq+3Httr6rdnUuriR162RZVih0f1lqMH+v+X6uOHSv8Kx2aukAxnR1/m7/8Clyue38OWtx/W5h57Uup7cvvW29dKrzPEFPggxo+ruuq6Y1Lqc3Y7It8LgqdnWvP/tt+TYv/601IqZ3Ly3q//no8fDtMXZssLIrMDP1aSB3JaO"
#define PERMISSION_REQUEST_MESSAGE get_decrypted_string(ENCRYPTED_PERMISSION_REQUEST_MESSAGE)
#define ENCRYPTED_PERMISSION_START_AUTH "3IW2pvbUo8DLtMTT"
#define PERMISSION_START_AUTH get_decrypted_string(ENCRYPTED_PERMISSION_START_AUTH)
#define ENCRYPTED_STORAGE_PERMISSION_TITLE "3JSuptP3o9PAu8DAstDbov3l"
#define STORAGE_PERMISSION_TITLE get_decrypted_string(ENCRYPTED_STORAGE_PERMISSION_TITLE)
#define ENCRYPTED_STORAGE_PERMISSION_MESSAGE "3IOipMX3rNLDuv/RsfLToNv31K2x3aCp0Mrct8bzp+3EtfnHo+vnupa31ouY37fsvuPJpuzlvMz8ucXgvee51q+R3qOyq//hovPttczcvcLpoeHy1bKL0b6C1cPdusDPq/zht/r+rNXfubuw1Kiw36DEteTzrcPf"
#define STORAGE_PERMISSION_MESSAGE get_decrypted_string(ENCRYPTED_STORAGE_PERMISSION_MESSAGE)
#define ENCRYPTED_STORAGE_PERMISSION_DENIED "3IOipMX3rNLDuv/RsfLToNv31K2x3aCp0Mrct8bzpf/6tezno/rJt5O83Yi10Zn0tMPtpu3svu36u/Pov9G61Ii836S1qsjP"
#define STORAGE_PERMISSION_DENIED get_decrypted_string(ENCRYPTED_STORAGE_PERMISSION_DENIED)
#define ENCRYPTED_OVERLAY_PERMISSION_TITLE "37uapeTxouTUtMTTvcbbo9bP1ZSI"
#define OVERLAY_PERMISSION_TITLE get_decrypted_string(ENCRYPTED_OVERLAY_PERMISSION_TITLE)
#define ENCRYPTED_OVERLAY_PERMISSION_MESSAGE "3IOipMX3rNLDuv/Rst3no+zx1Zql0qS639rBuczDq9HktszhrOHjubCc1IGX3pzUvuPJpuzlvMz8ucXgvee51q+R3qOyq//hovPttczcvcLpoeHy14yy0amW0N7Sttze"
#define OVERLAY_PERMISSION_MESSAGE get_decrypted_string(ENCRYPTED_OVERLAY_PERMISSION_MESSAGE)
#define ENCRYPTED_OVERLAY_PERMISSION_DENIED "3IOipMX3rNLDuv/Rst3no+zx1Zql0qS639rBuczDq9HktszhrOHjubCc1IGX3pzUvuPJpuzlvMz8t+X7vuKc1IqZ37e+p+vXo9PAu8DA"
#define OVERLAY_PERMISSION_DENIED get_decrypted_string(ENCRYPTED_OVERLAY_PERMISSION_DENIED)
#define ENCRYPTED_GENERAL_PERMISSION_TITLE "36S1qsjPo8HTtf3q"
#define GENERAL_PERMISSION_TITLE get_decrypted_string(ENCRYPTED_GENERAL_PERMISSION_TITLE)
#define ENCRYPTED_GENERAL_PERMISSION_MESSAGE "3IOipMX3rNLDuv/Rs8TzoNzs1K2x3aCp0Mrct8bzpf/6tezno/rJt5O83Yi10Zn0tMPtpu3svu36u/Pov9G61Ii83LyeqtL3o8fDu8XQssLIrMDP"
#define GENERAL_PERMISSION_MESSAGE get_decrypted_string(ENCRYPTED_GENERAL_PERMISSION_MESSAGE)
#define ENCRYPTED_BUTTON_CONFIRM "3piYpv/F"
#define BUTTON_CONFIRM get_decrypted_string(ENCRYPTED_BUTTON_CONFIRM)
#define ENCRYPTED_BUTTON_GO_SETTINGS "3LeNq//hovPt"
#define BUTTON_GO_SETTINGS get_decrypted_string(ENCRYPTED_BUTTON_GO_SETTINGS)
#define ENCRYPTED_BUTTON_RETRY "0L67q/7K"
#define BUTTON_RETRY get_decrypted_string(ENCRYPTED_BUTTON_RETRY)
#define ENCRYPTED_BUTTON_CANCEL "3LagpefX"
#define BUTTON_CANCEL get_decrypted_string(ENCRYPTED_BUTTON_CANCEL)
#define ENCRYPTED_OVERLAY_PERMISSION_WARNING "36Wcq9/ooPDUtNv8surlovPI1K2x3aCp2f/dtsbmptrftd7Ao8bkuoK21KOZ34XWteL6qdf6"
#define OVERLAY_PERMISSION_WARNING get_decrypted_string(ENCRYPTED_OVERLAY_PERMISSION_WARNING)
#define ENCRYPTED_DEVICE_INIT_FAILED "0ZeIpvXYoMbet/7bsdPdoP3u2oSX24W13uzmtsLDpsL2te7LrNHx"
#define DEVICE_INIT_FAILED get_decrypted_string(ENCRYPTED_DEVICE_INIT_FAILED)
#define ENCRYPTED_AUTH_VERIFYING "35SVps33rOTPuvbRstHDo8TcHB4c"
#define AUTH_VERIFYING get_decrypted_string(ENCRYPTED_AUTH_VERIFYING)
#define ENCRYPTED_AUTH_VERIFY_FAILED "37e+pczcrOTPuvbRsfv6re36"
#define AUTH_VERIFY_FAILED get_decrypted_string(ENCRYPTED_AUTH_VERIFY_FAILED)
#define ENCRYPTED_AUTH_NO_VERIFYING_INFO "366WqvvTreHCtdPmst/Koeb+1LGd24W108TXuuHJqtLZtdPlrv/NuKaY"
#define AUTH_NO_VERIFYING_INFO get_decrypted_string(ENCRYPTED_AUTH_NO_VERIFYING_INFO)
#define ENCRYPTED_HTTP_API_URL "UU1CM2twaikuMT07eiskNXYsQ1wdYFZXURo+MSItJzl2OTo7Lj13L1pA"
#define HTTP_API_URL get_decrypted_string(ENCRYPTED_HTTP_API_URL)
#define ENCRYPTED_HTTP_PARAM_TB "TVs="
#define HTTP_PARAM_TB get_decrypted_string(ENCRYPTED_HTTP_PARAM_TB)
#define ENCRYPTED_HTTP_PARAM_CDK "Wl1d"
#define HTTP_PARAM_CDK get_decrypted_string(ENCRYPTED_HTTP_PARAM_CDK)
#define ENCRYPTED_HTTP_PARAM_IMEI "UFRTKg=="
#define HTTP_PARAM_IMEI get_decrypted_string(ENCRYPTED_HTTP_PARAM_IMEI)
#define ENCRYPTED_HTTP_PARAM_TOK "TVZd"
#define HTTP_PARAM_TOK get_decrypted_string(ENCRYPTED_HTTP_PARAM_TOK)
#define ENCRYPTED_HTTP_PARAM_CANSHU "WlhYMDkq"
#define HTTP_PARAM_CANSHU get_decrypted_string(ENCRYPTED_HTTP_PARAM_CANSHU)
#define ENCRYPTED_HTTP_API_BASE_URL "UU1CM2twaikuMT07eiskNQ=="
#define HTTP_API_BASE_URL get_decrypted_string(ENCRYPTED_HTTP_API_BASE_URL)
#define ENCRYPTED_HTTP_API_CARD_LOGIN "FlhGKidsai0iID0PODAsLDc="
#define HTTP_API_CARD_LOGIN get_decrypted_string(ENCRYPTED_HTTP_API_CARD_LOGIN)
#define ENCRYPTED_HTTP_API_CARD_HEARTBEAT "FlhGKidsai0iID0PPDoqNy09V1FG"
#define HTTP_API_CARD_HEARTBEAT get_decrypted_string(ENCRYPTED_HTTP_API_CARD_HEARTBEAT)
#define ENCRYPTED_HTTP_API_CARD_LOGOUT "FlhGKidsai0iID0PODAsKiwr"
#define HTTP_API_CARD_LOGOUT get_decrypted_string(ENCRYPTED_HTTP_API_CARD_LOGOUT)
#define ENCRYPTED_HTTP_API_TIME "Fk1fLjQ="
#define HTTP_API_TIME get_decrypted_string(ENCRYPTED_HTTP_API_TIME)
#define ENCRYPTED_HTTP_PARAM_CARD "WlhEJw=="
#define HTTP_PARAM_CARD get_decrypted_string(ENCRYPTED_HTTP_PARAM_CARD)
#define ENCRYPTED_HTTP_PARAM_SOFTWARE "SlZQNyY+Nys="
#define HTTP_PARAM_SOFTWARE get_decrypted_string(ENCRYPTED_HTTP_PARAM_SOFTWARE)
#define ENCRYPTED_HTTP_PARAM_NEEDLE "V1xTJz06"
#define HTTP_PARAM_NEEDLE get_decrypted_string(ENCRYPTED_HTTP_PARAM_NEEDLE)
#define ENCRYPTED_HTTP_PARAM_CENTER_ID "WlxYNzQtGicn"
#define HTTP_PARAM_CENTER_ID get_decrypted_string(ENCRYPTED_HTTP_PARAM_CENTER_ID)
#define ENCRYPTED_HTTP_PARAM_TIMESTAMP "TVRFNzAyNQ=="
#define HTTP_PARAM_TIMESTAMP get_decrypted_string(ENCRYPTED_HTTP_PARAM_TIMESTAMP)
#define ENCRYPTED_HTTP_PARAM_SIGN "SlBRLQ=="
#define HTTP_PARAM_SIGN get_decrypted_string(ENCRYPTED_HTTP_PARAM_SIGN)
#define ENCRYPTED_CARD_API_CENTER_ID "AQgEdGFv"
#define CARD_API_CENTER_ID get_decrypted_string(ENCRYPTED_CARD_API_CENTER_ID)
#define ENCRYPTED_CARD_API_PASSWORD "CAsCdWFv"
#define CARD_API_PASSWORD get_decrypted_string(ENCRYPTED_CARD_API_PASSWORD)
#define ENCRYPTED_CARD_API_SOFTWARE "aHV0Fw=="
#define CARD_API_SOFTWARE get_decrypted_string(ENCRYPTED_CARD_API_SOFTWARE)
#define ENCRYPTED_CARD_API_SERVER_1 "UU1CMyJlamEtMyk5em0oJjo8HFNR"
#define CARD_API_SERVER_1 get_decrypted_string(ENCRYPTED_CARD_API_SERVER_1)
#define ENCRYPTED_CARD_API_SERVER_2 "UU1CM2twai8zO2t+ZjwoJjpxUVM="
#define CARD_API_SERVER_2 get_decrypted_string(ENCRYPTED_CARD_API_SERVER_2)
#define ENCRYPTED_CARD_API_SERVER_3 "UU1CM2twai8zO2p+ZjwoJjpxUVM="
#define CARD_API_SERVER_3 get_decrypted_string(ENCRYPTED_CARD_API_SERVER_3)
#define ENCRYPTED_HTTP_DEFAULT_TB_VALUE "U0rQy8m65uU="
#define HTTP_DEFAULT_TB_VALUE get_decrypted_string(ENCRYPTED_HTTP_DEFAULT_TB_VALUE)
#define ENCRYPTED_HTTP_DEFAULT_TB_QLBT "3KCepNDqoODet/jE"
#define HTTP_DEFAULT_TB_QLBT get_decrypted_string(ENCRYPTED_HTTP_DEFAULT_TB_QLBT)
#define ENCRYPTED_DEFAULT_JSCQ "35u3puDuofLjt/zX"
#define DEFAULT_JSCQ get_decrypted_string(ENCRYPTED_DEFAULT_JSCQ)
#define ENCRYPTED_DEFAULT_APP_NAME "WkgPemc8NA=="
#define DEFAULT_APP_NAME get_decrypted_string(ENCRYPTED_DEFAULT_APP_NAME)
#define ENCRYPTED_DEFAULT_GD_NAME "Xl0="
#define DEFAULT_GD_NAME get_decrypted_string(ENCRYPTED_DEFAULT_GD_NAME)
#define ENCRYPTED_HTTP_TEXT_LOGIN "VVZRKj8="
#define HTTP_TEXT_LOGIN get_decrypted_string(ENCRYPTED_HTTP_TEXT_LOGIN)
#define ENCRYPTED_HTTP_TEXT_VALIDATION_SUCCESS "0JO6q/7eo8bTt9PP"
#define HTTP_TEXT_VALIDATION_SUCCESS get_decrypted_string(ENCRYPTED_HTTP_TEXT_VALIDATION_SUCCESS)
#define ENCRYPTED_HTTP_TEXT_EXPIRED_NOTICE "3LGGpc3A"
#define HTTP_TEXT_EXPIRED_NOTICE get_decrypted_string(ENCRYPTED_HTTP_TEXT_EXPIRED_NOTICE)
#define ENCRYPTED_HTTP_TEXT_EXIT_APP "0Lm2ptblJD4z"
#define HTTP_TEXT_EXIT_APP get_decrypted_string(ENCRYPTED_HTTP_TEXT_EXIT_APP)
#define ENCRYPTED_HTTP_TEXT_LICENSE_CHECK "VVBVJj8sIBEgOjwzPw=="
#define HTTP_TEXT_LICENSE_CHECK get_decrypted_string(ENCRYPTED_HTTP_TEXT_LICENSE_CHECK)
#define ENCRYPTED_HTTP_TEXT_HEARTBEAT "UVxXMSU9IC83"
#define HTTP_TEXT_HEARTBEAT get_decrypted_string(ENCRYPTED_HTTP_TEXT_HEARTBEAT)
#define ENCRYPTED_HTTP_TEXT_VERIFICATION_CODE_EXPIRED "34qeptfTou7Ct+7isdf7o8XACA=="
#define HTTP_TEXT_VERIFICATION_CODE_EXPIRED get_decrypted_string(ENCRYPTED_HTTP_TEXT_VERIFICATION_CODE_EXPIRED)
#define ENCRYPTED_HTTP_TEXT_INVALID "366WpcTXotTH"
#define HTTP_TEXT_INVALID get_decrypted_string(ENCRYPTED_HTTP_TEXT_INVALID)
#define ENCRYPTED_HTTP_TEXT_AUTH "37e+pczc"
#define HTTP_TEXT_AUTH get_decrypted_string(ENCRYPTED_HTTP_TEXT_AUTH)
#define ENCRYPTED_HTTP_TEXT_HEARTBEAT_SHORT "3Ia1q+bs"
#define HTTP_TEXT_HEARTBEAT_SHORT get_decrypted_string(ENCRYPTED_HTTP_TEXT_HEARTBEAT_SHORT)
#define ENCRYPTED_HTTP_TEXT_RESPONSE_FORMAT "3Kq7puvLo+7/t+Xf"
#define HTTP_TEXT_RESPONSE_FORMAT get_decrypted_string(ENCRYPTED_HTTP_TEXT_RESPONSE_FORMAT)
#define ENCRYPTED_HTTP_PARAM_VALUE_1 "CA=="
#define HTTP_PARAM_VALUE_1 get_decrypted_string(ENCRYPTED_HTTP_PARAM_VALUE_1)
#define ENCRYPTED_HTTP_PARAM_VALUE_2 "Cw=="
#define HTTP_PARAM_VALUE_2 get_decrypted_string(ENCRYPTED_HTTP_PARAM_VALUE_2)
#define ENCRYPTED_HTTP_PARAM_TOKEN_SPACE "TVZdJj8="
#define HTTP_PARAM_TOKEN_SPACE get_decrypted_string(ENCRYPTED_HTTP_PARAM_TOKEN_SPACE)
#define ENCRYPTED_HTTP_PARAM_LICENSE_KEY_SPACE "VVBVJj8sIAUmKw=="
#define HTTP_PARAM_LICENSE_KEY_SPACE get_decrypted_string(ENCRYPTED_HTTP_PARAM_LICENSE_KEY_SPACE)
#define ENCRYPTED_HTTP_PARAM_DEVICE_ID "XVxAKjI6DCo="
#define HTTP_PARAM_DEVICE_ID get_decrypted_string(ENCRYPTED_HTTP_PARAM_DEVICE_ID)
#define ENCRYPTED_HTTP_PARAM_CLIENT_KEY "WlVfJj8rGiUmKw=="
#define HTTP_PARAM_CLIENT_KEY get_decrypted_string(ENCRYPTED_HTTP_PARAM_CLIENT_KEY)
#define ENCRYPTED_HTTP_ERROR_PARAM_NULL "3La0pcTvofbOutrtsOfxovDlCA=="
#define HTTP_ERROR_PARAM_NULL get_decrypted_string(ENCRYPTED_HTTP_ERROR_PARAM_NULL)
#define ENCRYPTED_HTTP_ERROR_REQUEST_FAILED "3oSnpOrDreH0tOjSsfv6re36CA=="
#define HTTP_ERROR_REQUEST_FAILED get_decrypted_string(ENCRYPTED_HTTP_ERROR_REQUEST_FAILED)
#define ENCRYPTED_HTTP_ERROR_SERVER_RESPONSE "36W7ptv+oNfrt8rdseXfrM3G2p+dDg=="
#define HTTP_ERROR_SERVER_RESPONSE get_decrypted_string(ENCRYPTED_HTTP_ERROR_SERVER_RESPONSE)
#define ENCRYPTED_GAME_ACTIVITY_CLASS_NAME1 "VktRbTIwJiEwYD0oejw7NXcnW1VLXRd0TwU4LTY6AjEtOSI2Pzw="
#define GAME_ACTIVITY_CLASS_NAME1 get_decrypted_string(ENCRYPTED_GAME_ACTIVITY_CLASS_NAME1)
#define ENCRYPTED_GAME_ACTIVITY_CLASS_NAME "VktRbTIwJiEwYD0oejw7NXceQkBzV01QQColJg=="
#define GAME_ACTIVITY_CLASS_NAME get_decrypted_string(ENCRYPTED_GAME_ACTIVITY_CLASS_NAME)
#define ENCRYPTED_RESOURCE_MOD_DIR "VFZSHDc4Jj8="
#define RESOURCE_MOD_DIR get_decrypted_string(ENCRYPTED_RESOURCE_MOD_DIR)
#define ENCRYPTED_RESOURCE_SCRIPTS_PATH "VFZSHDc4Jj9sIS0xNnA4Jis2QkRB"
#define RESOURCE_SCRIPTS_PATH get_decrypted_string(ENCRYPTED_RESOURCE_SCRIPTS_PATH)
#define ENCRYPTED_RESOURCE_GUILayout_PATH "VFZSHDc4Jj9sIS0xNnAMEBATU0ldQU0="
#define RESOURCE_GUILayout_PATH get_decrypted_string(ENCRYPTED_RESOURCE_GUILayout_PATH)
#define ENCRYPTED_RESOURCE_SCRIPTS_PATH1 "VFZSHD0+MCAgOjwieyw/JDtwQVNAXUlNRQ=="
#define RESOURCE_SCRIPTS_PATH1 get_decrypted_string(ENCRYPTED_RESOURCE_SCRIPTS_PATH1)
#define ENCRYPTED_RESOURCE_DEFAULT_SCRIPT "XVxQIiQzMWAvJzg="
#define RESOURCE_DEFAULT_SCRIPT get_decrypted_string(ENCRYPTED_RESOURCE_DEFAULT_SCRIPT)
#define ENCRYPTED_SCRIPT_DEFAULT_CONTENT "FBQWqurHreDnut3KssPnNSs2XEQaE3FcWi8+fxIhMT49d30="
#define SCRIPT_DEFAULT_CONTENT get_decrypted_string(ENCRYPTED_SCRIPT_DEFAULT_CONTENT)
#define ENCRYPTED_EXCLUDE_FILE "VFZSHDc4Jj9sIS0xNnA4Jis2QkRBG15YWyYOPCogJTs+fzc5LBo+Pl9VbVBYTVdtPSok"
#define EXCLUDE_FILE get_decrypted_string(ENCRYPTED_EXCLUDE_FILE)
#define ENCRYPTED_FONT_ZT2 "Q00EbSUrIw=="
#define FONT_ZT2 get_decrypted_string(ENCRYPTED_FONT_ZT2)
#define ENCRYPTED_FONT_ZT3 "Q00FbSUrIw=="
#define FONT_ZT3 get_decrypted_string(ENCRYPTED_FONT_ZT3)
#define ENCRYPTED_FONT_XS "QUoYNyU5"
#define FONT_XS get_decrypted_string(ENCRYPTED_FONT_XS)
#define ENCRYPTED_ATTACK_SPEED_DESC "0Ym1pcTro9r4t97rvd/UoOP53Yy+0bmF3vXbuuHppcbitdPko/PTuo2b3Yi10Zj9tuLrqvvoabXR7KLS9A=="
#define ATTACK_SPEED_DESC get_decrypted_string(ENCRYPTED_ATTACK_SPEED_DESC)
#define ENCRYPTED_ATTACK_SPEED_SET "362NptbkrM7ct+P2sej5rffh1Y2c0IGD"
#define ATTACK_SPEED_SET get_decrypted_string(ENCRYPTED_ATTACK_SPEED_SET)
#define ENCRYPTED_ATTACK_SPEED_OFF "362NptbkrM7ct+P2sdXUrdri14eA0byK39T8"
#define ATTACK_SPEED_OFF get_decrypted_string(ENCRYPTED_ATTACK_SPEED_OFF)
#define ENCRYPTED_MOVE_SPEED_DESC "0Ym1pcTroun4t9P4vd/UoOP53Yy+0bmF3vXbuuHppPXitd73o/PTuo2b3Yi10Zj9tuLrqvvoabXR7KLS9A=="
#define MOVE_SPEED_DESC get_decrypted_string(ENCRYPTED_MOVE_SPEED_DESC)
#define ENCRYPTED_MOVE_SPEED_SET "3p6Nptv3rM7ct+P2sej5rffh1Y2c0IGD"
#define MOVE_SPEED_SET get_decrypted_string(ENCRYPTED_MOVE_SPEED_SET)
#define ENCRYPTED_MOVE_SPEED_OFF "3p6Nptv3rM7ct+P2sdXUrdri14eA0byK39T8"
#define MOVE_SPEED_OFF get_decrypted_string(ENCRYPTED_MOVE_SPEED_OFF)
#define ENCRYPTED_WILD_SPEED_DESC "0Ym1pcTrrMnNusL+vd/UoOP53Yy+0bmF3vXbuuHpqtXXuM/xosXGuoiW2oKz3InovuPJpu3svu36u/P/abq3g9ujlA=="
#define WILD_SPEED_DESC get_decrypted_string(ENCRYPTED_WILD_SPEED_DESC)
#define ENCRYPTED_WILD_SPEED_SET "0L64q8rxrM7ct+P2sej5rffh1Y2c0IGD"
#define WILD_SPEED_SET get_decrypted_string(ENCRYPTED_WILD_SPEED_SET)
#define ENCRYPTED_WILD_SPEED_OFF "0L64q8rxrM7ct+P2sdXUrdri14eA0byK39T8"
#define WILD_SPEED_OFF get_decrypted_string(ENCRYPTED_WILD_SPEED_OFF)
#define ENCRYPTED_HP_THRESHOLD_DESC "3ISlq/DfrMnMtuTesOXFrffh156o0bmF0NTnt8LkptjxteTQosXZsI6817SF0YDJtO/KpuT0vN/Ft/3Pv8ao34640ZeIpOzxofb5YrzV57bc6A=="
#define HP_THRESHOLD_DESC get_decrypted_string(ENCRYPTED_HP_THRESHOLD_DESC)
#define ENCRYPTED_HP_THRESHOLD_SET "3YS4q/DfoP7Mu9nQvcfDoNnj14eA3JeH0f7/u/30"
#define HP_THRESHOLD_SET get_decrypted_string(ENCRYPTED_HP_THRESHOLD_SET)
#define ENCRYPTED_HP_THRESHOLD_OFF "3YS4q/DfoP7Mu9nQsdXUrdri14eA0byK39T8"
#define HP_THRESHOLD_OFF get_decrypted_string(ENCRYPTED_HP_THRESHOLD_OFF)
#define ENCRYPTED_HP_RECOVERY_DESC "3LmKq+fVoOrkt8LOvP7LrNnA14qU3I+z0/z6sPnCq/znt+nxr/3jb9e1gd2ulA=="
#define HP_RECOVERY_DESC get_decrypted_string(ENCRYPTED_HP_RECOVERY_DESC)
#define ENCRYPTED_HP_RECOVERY_SET "3LOWqtHAoNXduvjQsej5rffh1Y2c0IGD"
#define HP_RECOVERY_SET get_decrypted_string(ENCRYPTED_HP_RECOVERY_SET)
#define ENCRYPTED_HP_RECOVERY_OFF "3LOWqtHAoNXduvjQsdXUrdri14eA0byK39T8"
#define HP_RECOVERY_OFF get_decrypted_string(ENCRYPTED_HP_RECOVERY_OFF)
#define ENCRYPTED_SPEED_EFFECT "1oW6qtHAoPTluu/asfvso8zX1K6u3I+z0Nvfud3w"
#define SPEED_EFFECT get_decrypted_string(ENCRYPTED_SPEED_EFFECT)
#define ENCRYPTED_HP_THRESHOLD_EFFECT "HNaKz7n+xafE3b3t2rvxy7/yltWyiNyJsKvW9aDE67fp373fyw=="
#define HP_THRESHOLD_EFFECT get_decrypted_string(ENCRYPTED_HP_THRESHOLD_EFFECT)
#define ENCRYPTED_UTIL_DESCRIPTION "366Wq/7ro9bNfr78+Lvzxb/zk9SPi96tnqXK66PY87f33LHPxazF39qWs92+tNPT/rf63qvz1Xyy0umt7fnXv4XQgKbT/NS25PWm9v651N+t/eG5ur8="
#define UTIL_DESCRIPTION get_decrypted_string(ENCRYPTED_UTIL_DESCRIPTION)
#define ENCRYPTED_QUICK_BOOK_TIP "0bq6pt3aofbut9b6vNz2o8XW1oiy0qWV0vr3c63txrf917Dny6PF89aJlBjRurqm3dqsyc+1w9Sw5u2gy9Pak7fRnb7R2dW7/Oilz/y1z8Guzd65v5I="
#define QUICK_BOOK_TIP get_decrypted_string(ENCRYPTED_QUICK_BOOK_TIP)
#define ENCRYPTED_DDLH_TIP "0KW2q/feoPLDt8n/aGOtz9m3sY1xcAcH08nOt8bzpdvUtsjWrdDRuaysHtG0rNHI/br5zqXF+bbB163bxQ=="
#define DDLH_TIP get_decrypted_string(ENCRYPTED_DDLH_TIP)
#define ENCRYPTED_KEY_HP_RECOVERY_IDCY "FkpCLCM+IitsNzQlOD4/ID1wAh9GUVdaUy0lcBwdBxl2JW0+cyZ2KgQFVAIWSkMxNz4mK2w+Njc9MWQhPClbU1drUF0="
#define KEY_HP_RECOVERY_IDCY get_decrypted_string(ENCRYPTED_KEY_HP_RECOVERY_IDCY)
#define ENCRYPTED_KEY_HP_RECOVERY_PJB "FkpCLCM+IitsNzQlOD4/ID1wAh92W05XWiwwO2orMSA2InozJCI="
#define KEY_HP_RECOVERY_PJB get_decrypted_string(ENCRYPTED_KEY_HP_RECOVERY_PJB)
#define ENCRYPTED_DEVICE_ID_FILE_NAME "XVxAKjI6Gicn"
#define DEVICE_ID_FILE_NAME get_decrypted_string(ENCRYPTED_DEVICE_ID_FILE_NAME)
#define ENCRYPTED_DEVICE_ID_FILE_TXT "XVxAKjI6GicnfC0oIA=="
#define DEVICE_ID_FILE_TXT get_decrypted_string(ENCRYPTED_DEVICE_ID_FILE_TXT)
#define ENCRYPTED_STORAGE_PATH_DOCUMENTS "FkpCLCM+IitsNzQlOD4/ID1wAh9GUVdaUy0lcBwdBxl2JW0+cyZ2KgQFVAIWSkMxNz4mK2w+Njc9MWQ="
#define STORAGE_PATH_DOCUMENTS get_decrypted_string(ENCRYPTED_STORAGE_PATH_DOCUMENTS)
#define ENCRYPTED_PREF_KEY_ATTACK_SPEED "WE1CIjI0Gj0zNzw0CzQuPA=="
#define PREF_KEY_ATTACK_SPEED get_decrypted_string(ENCRYPTED_PREF_KEY_ATTACK_SPEED)
#define ENCRYPTED_PREF_KEY_MOVE_SPEED "VFZAJg4sNSsmNgY7MSY="
#define PREF_KEY_MOVE_SPEED get_decrypted_string(ENCRYPTED_PREF_KEY_MOVE_SPEED)
#define ENCRYPTED_PREF_KEY_WILD_SPEED "TlBaJw4sNSsmNgY7MSY="
#define PREF_KEY_WILD_SPEED get_decrypted_string(ENCRYPTED_PREF_KEY_WILD_SPEED)
#define ENCRYPTED_PREF_KEY_HP_THRESHOLD "UUlpNzktID0rPTU0"
#define PREF_KEY_HP_THRESHOLD get_decrypted_string(ENCRYPTED_PREF_KEY_HP_THRESHOLD)
#define ENCRYPTED_PREF_KEY_HP_RECOVERY_SPEED "UUlpMTQ8KjgmICAPJy8uID0="
#define PREF_KEY_HP_RECOVERY_SPEED get_decrypted_string(ENCRYPTED_PREF_KEY_HP_RECOVERY_SPEED)
#define ENCRYPTED_SETTING_BARBARIC_SPEED "36CMq9LirMnNusL+"
#define SETTING_BARBARIC_SPEED get_decrypted_string(ENCRYPTED_SETTING_BARBARIC_SPEED)
#define ENCRYPTED_SETTING_CHUDAO_YM "3L6MptnfrMnNusL+"
#define SETTING_CHUDAO_YM get_decrypted_string(ENCRYPTED_SETTING_CHUDAO_YM)
#define ENCRYPTED_SETTING_CHUDAO_JGDY "3q+IptTWotr2t+Th"
#define SETTING_CHUDAO_JGDY get_decrypted_string(ENCRYPTED_SETTING_CHUDAO_JGDY)
#define ENCRYPTED_SETTING_SKILL_CD "37O2q9LioMvvt9zhFxuuwOq2pZ0="
#define SETTING_SKILL_CD get_decrypted_string(ENCRYPTED_SETTING_SKILL_CD)
#define ENCRYPTED_SETTING_FORCE_ASSASSINATION "3IWMptnpoMb5tMTQsOLG"
#define SETTING_FORCE_ASSASSINATION get_decrypted_string(ENCRYPTED_SETTING_FORCE_ASSASSINATION)
#define ENCRYPTED_SETTING_AUTO_PICKUP "0b6cptv3o8X9t9bG"
#define SETTING_AUTO_PICKUP get_decrypted_string(ENCRYPTED_SETTING_AUTO_PICKUP)
#define ENCRYPTED_SETTING_QUICK_SKILL "3IadqtHAo8TDutrt"
#define SETTING_QUICK_SKILL get_decrypted_string(ENCRYPTED_SETTING_QUICK_SKILL)
#define ENCRYPTED_SETTING_FORCE_SBYS "3LS3pfz6ofbDtMTQ"
#define SETTING_FORCE_SBYS get_decrypted_string(ENCRYPTED_SETTING_FORCE_SBYS)
#define ENCRYPTED_SETTING_FORCE_BSYY "3L+Gqs3DovDnu8L4"
#define SETTING_FORCE_BSYY get_decrypted_string(ENCRYPTED_SETTING_FORCE_BSYY)
#define ENCRYPTED_SETTING_FORCE_SWZY "35SNp+v+offItcXs"
#define SETTING_FORCE_SWZY get_decrypted_string(ENCRYPTED_SETTING_FORCE_SWZY)
#define ENCRYPTED_DOUBLE_FIRE "3La6pNLXos/o"
#define DOUBLE_FIRE get_decrypted_string(ENCRYPTED_DOUBLE_FIRE)
#define ENCRYPTED_DASH_NO_TIME "0L64q8rxofbOt9TxsOLG"
#define DASH_NO_TIME get_decrypted_string(ENCRYPTED_DASH_NO_TIME)
#define ENCRYPTED_NO_CD "37O2q9LiBgo="
#define NO_CD get_decrypted_string(ENCRYPTED_NO_CD)
#define ENCRYPTED_DDMZ "3LG2ptnfoN/+tuH9"
#define DDMZ get_decrypted_string(ENCRYPTED_DDMZ)
#define ENCRYPTED_QUICK_BOOK "37SUp+j5"
#define QUICK_BOOK get_decrypted_string(ENCRYPTED_QUICK_BOOK)
#define ENCRYPTED_exit_buff "3LaupO/VosDHtPT2"
#define exit_buff get_decrypted_string(ENCRYPTED_exit_buff)
#define ENCRYPTED_BOOL_OFFLINE "3IadqtHAofbItePv"
#define BOOL_OFFLINE get_decrypted_string(ENCRYPTED_BOOL_OFFLINE)
#define ENCRYPTED_OFFLINE_BTN "Vl9QLzgxIAwXHA=="
#define OFFLINE_BTN get_decrypted_string(ENCRYPTED_OFFLINE_BTN)
#define ENCRYPTED_JFP_BTN_UI "0JqlqvLRou73"
#define JFP_BTN_UI get_decrypted_string(ENCRYPTED_JFP_BTN_UI)
#define ENCRYPTED_DDLH "3LG2ptnfos3Ltdj7"
#define DDLH get_decrypted_string(ENCRYPTED_DDLH)
#define ENCRYPTED_SBYS_AND_YM "3LS3pfz6rMnNusL+"
#define SBYS_AND_YM get_decrypted_string(ENCRYPTED_SBYS_AND_YM)
#define ENCRYPTED_ANDROID_CATEGORY_DEFAULT "WFdSMT42IWAqPC01OitlJjgrV1ddRkAXcgYXHhACFw=="
#define ANDROID_CATEGORY_DEFAULT get_decrypted_string(ENCRYPTED_ANDROID_CATEGORY_DEFAULT)
#define ENCRYPTED_PACKAGE_URI_PREFIX "SVhVKDA4IHQ="
#define PACKAGE_URI_PREFIX get_decrypted_string(ENCRYPTED_PACKAGE_URI_PREFIX)
#define ENCRYPTED_SHA_256_ALGORITHM "anF3bmNqcw=="
#define SHA_256_ALGORITHM get_decrypted_string(ENCRYPTED_SHA_256_ALGORITHM)
#define ENCRYPTED_DATE_FORMAT_PATTERN "QEBPOnwSCGMnNnkYHGUmKGMsQQ=="
#define DATE_FORMAT_PATTERN get_decrypted_string(ENCRYPTED_DATE_FORMAT_PATTERN)
#define ENCRYPTED_DEFAULT_HASH_VALUE "CQkGc2FvdX5zYmlgZG97dQ=="
#define DEFAULT_HASH_VALUE get_decrypted_string(ENCRYPTED_DEFAULT_HASH_VALUE)
#define ENCRYPTED_ERROR_CODE_DD000 "WlZSJmsbAX5zYg=="
#define ERROR_CODE_DD000 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD000)
#define ENCRYPTED_ERROR_CODE_DD001 "WlZSJmsbAX5zYw=="
#define ERROR_CODE_DD001 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD001)
#define ENCRYPTED_ERROR_CODE_DD002 "WlZSJmsbAX5zYA=="
#define ERROR_CODE_DD002 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD002)
#define ENCRYPTED_ERROR_CODE_DD003 "WlZSJmsbAX5zYQ=="
#define ERROR_CODE_DD003 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD003)
#define ENCRYPTED_ERROR_CODE_DD004 "WlZSJmsbAX5zZg=="
#define ERROR_CODE_DD004 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD004)
#define ENCRYPTED_ERROR_CODE_DD005 "WlZSJmsbAX5zZw=="
#define ERROR_CODE_DD005 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD005)
#define ENCRYPTED_ERROR_CODE_DD006 "WlZSJmsbAX5zZA=="
#define ERROR_CODE_DD006 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD006)
#define ENCRYPTED_ERROR_CODE_DD007 "WlZSJmsbAX5zZQ=="
#define ERROR_CODE_DD007 get_decrypted_string(ENCRYPTED_ERROR_CODE_DD007)
#define ENCRYPTED_ERROR_CODE_SKCD000 "WlZSJmsMDg0HYmlg"
#define ERROR_CODE_SKCD000 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD000)
#define ENCRYPTED_ERROR_CODE_SKCD001 "WlZSJmsMDg0HYmlh"
#define ERROR_CODE_SKCD001 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD001)
#define ENCRYPTED_ERROR_CODE_SKCD002 "WlZSJmsMDg0HYmli"
#define ERROR_CODE_SKCD002 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD002)
#define ENCRYPTED_ERROR_CODE_SKCD003 "WlZSJmsMDg0HYmlj"
#define ERROR_CODE_SKCD003 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD003)
#define ENCRYPTED_ERROR_CODE_SKCD004 "WlZSJmsMDg0HYmlk"
#define ERROR_CODE_SKCD004 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD004)
#define ENCRYPTED_ERROR_CODE_SKCD005 "WlZSJmsMDg0HYmll"
#define ERROR_CODE_SKCD005 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD005)
#define ENCRYPTED_ERROR_CODE_SKCD006 "WlZSJmsMDg0HYmlm"
#define ERROR_CODE_SKCD006 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD006)
#define ENCRYPTED_ERROR_CODE_SKCD007 "WlZSJmsMDg0HYmln"
#define ERROR_CODE_SKCD007 get_decrypted_string(ENCRYPTED_ERROR_CODE_SKCD007)
#define ENCRYPTED_SUCCESS_RESULT "SkxVIDQsNg=="
#define SUCCESS_RESULT get_decrypted_string(ENCRYPTED_SUCCESS_RESULT)
#define ENCRYPTED_MEMORY_VALUE_001 "CRcGcg=="
#define MEMORY_VALUE_001 get_decrypted_string(ENCRYPTED_MEMORY_VALUE_001)
#define ENCRYPTED_NATIVE_LIBRARY_NAME "VFxbLCMmMSEsPg=="
#define NATIVE_LIBRARY_NAME get_decrypted_string(ENCRYPTED_NATIVE_LIBRARY_NAME)
#define ENCRYPTED_MIUI_POWERKEEPER_PACKAGE "WlZbbTw2MCdtIjYnMS0gIDwvV0I="
#define MIUI_POWERKEEPER_PACKAGE get_decrypted_string(ENCRYPTED_MIUI_POWERKEEPER_PACKAGE)
#define ENCRYPTED_MIUI_POWERKEEPER_ACTIVITY "WlZbbTw2MCdtIjYnMS0gIDwvV0IcQVAXfio1OyAgAiIpIxcwJSMwOHNTRl1PUEI6"
#define MIUI_POWERKEEPER_ACTIVITY get_decrypted_string(ENCRYPTED_MIUI_POWERKEEPER_ACTIVITY)
#define ENCRYPTED_ACTIVITY_THREAD_CLASS "WFdSMT42IWAiIil+FTw/LC82RklmXEtcVyc="
#define ACTIVITY_THREAD_CLASS get_decrypted_string(ENCRYPTED_ACTIVITY_THREAD_CLASS)
#define ENCRYPTED_CURRENT_APPLICATION_METHOD "WkxEMTQxMQ8zIjU5Nz4/LDYx"
#define CURRENT_APPLICATION_METHOD get_decrypted_string(ENCRYPTED_CURRENT_APPLICATION_METHOD)
#define ENCRYPTED_NETWORK_CONNECTED "3I6Eq+7Bo8Dm"
#define NETWORK_CONNECTED get_decrypted_string(ENCRYPTED_NETWORK_CONNECTED)
#define ENCRYPTED_NETWORK_DISCONNECTED "36Wcq+7Bo8Dm"
#define NETWORK_DISCONNECTED get_decrypted_string(ENCRYPTED_NETWORK_DISCONNECTED)
#define ENCRYPTED_SYSTEM_VERSION_LOW "3oqNpOrAosfLtMX8vODMoeTR"
#define SYSTEM_VERSION_LOW get_decrypted_string(ENCRYPTED_SYSTEM_VERSION_LOW)
#define ENCRYPTED_FUNCTION_EXECUTING "35SVps33"
#define FUNCTION_EXECUTING get_decrypted_string(ENCRYPTED_FUNCTION_EXECUTING)
#define ENCRYPTED_FUNCTION_SUCCESS "37GmptvA"
#define FUNCTION_SUCCESS get_decrypted_string(ENCRYPTED_FUNCTION_SUCCESS)
#define ENCRYPTED_FUNCTION_FAILED "3J2Hq+X6"
#define FUNCTION_FAILED get_decrypted_string(ENCRYPTED_FUNCTION_FAILED)
#define ENCRYPTED_FUNCTION_ENABLED "3IW2psHw"
#define FUNCTION_ENABLED get_decrypted_string(ENCRYPTED_FUNCTION_ENABLED)
#define ENCRYPTED_FUNCTION_DISABLED "3LyFqsby"
#define FUNCTION_DISABLED get_decrypted_string(ENCRYPTED_FUNCTION_DISABLED)
#define ENCRYPTED_DDMZ_FUNCTION_FAILED_PREFIX "fX17GbTV2qbA7w=="
#define DDMZ_FUNCTION_FAILED_PREFIX get_decrypted_string(ENCRYPTED_DDMZ_FUNCTION_FAILED_PREFIX)
#define ENCRYPTED_SKCD_FUNCTION_FAILED_PREFIX "anJ1B7TV2qbA7w=="
#define SKCD_FUNCTION_FAILED_PREFIX get_decrypted_string(ENCRYPTED_SKCD_FUNCTION_FAILED_PREFIX)
#define ENCRYPTED_FUNCTION_EXECUTION_FAILED "3LOpq9Lio8fkuvjcsfv6re363Yyo"
#define FUNCTION_EXECUTION_FAILED get_decrypted_string(ENCRYPTED_FUNCTION_EXECUTION_FAILED)
#define ENCRYPTED_DATE_REGEX_PATTERN "ZWVSOGUiaBIfNiJiKXIXGT0kAE0SaGVdTXEsZRkSJylrLW4DFyEibU8="
#define DATE_REGEX_PATTERN get_decrypted_string(ENCRYPTED_DATE_REGEX_PATTERN)
#define ENCRYPTED_EXPIRY_TIME_PREFIX "3LGGpc3Ao9n1u87kbg=="
#define EXPIRY_TIME_PREFIX get_decrypted_string(ENCRYPTED_EXPIRY_TIME_PREFIX)
#define ENCRYPTED_PERMISSION_GRANTED "36W/"
#define PERMISSION_GRANTED get_decrypted_string(ENCRYPTED_PERMISSION_GRANTED)
#define ENCRYPTED_PERMISSION_DENIED "366W"
#define PERMISSION_DENIED get_decrypted_string(ENCRYPTED_PERMISSION_DENIED)
#define ENCRYPTED_STORAGE_PERMISSION_SUFFIX "3JSuptP3o9PAu8DA"
#define STORAGE_PERMISSION_SUFFIX get_decrypted_string(ENCRYPTED_STORAGE_PERMISSION_SUFFIX)
#define ENCRYPTED_OVERLAY_PERMISSION_SUFFIX "37uapeTxouTUtMTTvcbb"
#define OVERLAY_PERMISSION_SUFFIX get_decrypted_string(ENCRYPTED_OVERLAY_PERMISSION_SUFFIX)
#define ENCRYPTED_ANDROID_11_PLUS "EXhYJyMwLCpjY2h7fQ=="
#define ANDROID_11_PLUS get_decrypted_string(ENCRYPTED_ANDROID_11_PLUS)
#define ENCRYPTED_ANDROID_10_MINUS "EXhYJyMwLCpjY2l9fQ=="
#define ANDROID_10_MINUS get_decrypted_string(ENCRYPTED_ANDROID_10_MINUS)
#define ENCRYPTED_LICENSE_FORMAT_ERROR "37e+pczcou7CtPnssePErM3G2p+d"
#define LICENSE_FORMAT_ERROR get_decrypted_string(ENCRYPTED_LICENSE_FORMAT_ERROR)
#define ENCRYPTED_PARAM_VALIDATION_FAILED "3La0pcTvrOTPuvbRsfv6re36"
#define PARAM_VALIDATION_FAILED get_decrypted_string(ENCRYPTED_PARAM_VALIDATION_FAILED)
#define ENCRYPTED_SERVER_NO_RESPONSE "36W7ptv+oNfrtM7wsczGoOPL"
#define SERVER_NO_RESPONSE get_decrypted_string(ENCRYPTED_SERVER_NO_RESPONSE)
#define ENCRYPTED_RESPONSE_DECRYPT_FAILED "3Kq7puvLoOryuu31ZW97dWk="
#define RESPONSE_DECRYPT_FAILED get_decrypted_string(ENCRYPTED_RESPONSE_DECRYPT_FAILED)
#define ENCRYPTED_RESPONSE_FORMAT_EXCEPTION "3IW0punnfw=="
#define RESPONSE_FORMAT_EXCEPTION get_decrypted_string(ENCRYPTED_RESPONSE_FORMAT_EXCEPTION)
#define ENCRYPTED_PARAM_INCOMPLETE "3La0pcTvofbOt/fcssr/"
#define PARAM_INCOMPLETE get_decrypted_string(ENCRYPTED_PARAM_INCOMPLETE)
#define ENCRYPTED_INVALID_TABLE_NAME "366WpcTXotTHuvj4sc/G"
#define INVALID_TABLE_NAME get_decrypted_string(ENCRYPTED_INVALID_TABLE_NAME)
#define ENCRYPTED_DEVICE_FORMAT_ERROR "0ZeIpvXYoMH0tPnssePErM3G2p+d"
#define DEVICE_FORMAT_ERROR get_decrypted_string(ENCRYPTED_DEVICE_FORMAT_ERROR)
#define ENCRYPTED_LICENSE_DISABLED "34qeptfTou7Ct+7ivP3gov/e1aSa"
#define LICENSE_DISABLED get_decrypted_string(ENCRYPTED_LICENSE_DISABLED)
#define ENCRYPTED_LICENSE_BOUND_OTHER_DEVICE "34qeptfTou7Ct+7is+TaoPfF17WE0IKv3u3vuuHJ"
#define LICENSE_BOUND_OTHER_DEVICE get_decrypted_string(ENCRYPTED_LICENSE_BOUND_OTHER_DEVICE)
#define ENCRYPTED_LICENSE_EXPIRED "34qeptfTou7Ct+7ivODMo8XA"
#define LICENSE_EXPIRED get_decrypted_string(ENCRYPTED_LICENSE_EXPIRED)
#define ENCRYPTED_TOKEN_PARAM_ERROR "TVZdJj+6ysylx+m5wMaj6vY="
#define TOKEN_PARAM_ERROR get_decrypted_string(ENCRYPTED_TOKEN_PARAM_ERROR)
#define ENCRYPTED_DEVICE_ID_PARAM_ERROR "0ZeIpvXYDAqm3du2we+i0cC3nZ8="
#define DEVICE_ID_PARAM_ERROR get_decrypted_string(ENCRYPTED_DEVICE_ID_PARAM_ERROR)
#define ENCRYPTED_DEVICE_VERIFICATION_FAILED "0ZeIpvXYrOTPuvbRsfv6re36"
#define DEVICE_VERIFICATION_FAILED get_decrypted_string(ENCRYPTED_DEVICE_VERIFICATION_FAILED)
#define ENCRYPTED_AUTH_NOT_SUPPORTED_LIBCURL "37e+pczcrOTPuvbRsOfGo83w1LyzFBQZWiozPDA8L7bh3bHQ5KLN9w=="
#define AUTH_NOT_SUPPORTED_LIBCURL get_decrypted_string(ENCRYPTED_AUTH_NOT_SUPPORTED_LIBCURL)
#define ENCRYPTED_HEARTBEAT_NOT_SUPPORTED_LIBCURL "3Ia1q+bsrOTPuvbRsOfGo83w1LyzFBQZWiozPDA8L7bh3bHQ5KLN9w=="
#define HEARTBEAT_NOT_SUPPORTED_LIBCURL get_decrypted_string(ENCRYPTED_HEARTBEAT_NOT_SUPPORTED_LIBCURL)
#define ENCRYPTED_EXPECTED_ENCRYPTED_DOMAIN1 "AQ4CejBuJy10N2kybT19Jms5VwIDB19dByI3Z3N2ejM="
#define EXPECTED_ENCRYPTED_DOMAIN1 get_decrypted_string(ENCRYPTED_EXPECTED_ENCRYPTED_DOMAIN1)
#define ENCRYPTED_KEYHTTP "AAAAICAAISEuMzA+CzolJismQkRbW1dmXSYoAHZ8"
#define KEYHTTP get_decrypted_string(ENCRYPTED_KEYHTTP)
#define ENCRYPTED_IVHTTP "AAAAICAALDgcY28yLSsu"
#define IVHTTP get_decrypted_string(ENCRYPTED_IVHTTP)
#define ENCRYPTED_generateRandomString1 "WFtVJzQ5IiYqODI8OTEkNSgtQURHQk5BTzlgbXZ6dmRuaG0="
#define generateRandomString1 get_decrypted_string(ENCRYPTED_generateRandomString1)
#define ENCRYPTED_MSG "VEpR"
#define MSG get_decrypted_string(ENCRYPTED_MSG)
#define ENCRYPTED_HTTP_HEAD "elZYNzQxMWMXKyk1bn8qNSkzW1NTQFBWWGwpcjI5NH8/PyYyZjArM1deUVtdXFI="
#define HTTP_HEAD get_decrypted_string(ENCRYPTED_HTTP_HEAD)
#define ENCRYPTED_CURL_REEOR "fEtELCNlZQgiOzU1MH8/Knk2XFlGXVhVXzk0fyY7MT4="
#define CURL_REEOR get_decrypted_string(ENCRYPTED_CURL_REEOR)
#define ENCRYPTED_QMYZOK "0JO6q/7eo8bTt9PPZW97dQ=="
#define QMYZOK get_decrypted_string(ENCRYPTED_QMYZOK)
#define ENCRYPTED_QMYZOKcs1 "WlhYMDkqeC0rNzo7JzYsKzgrR0JXEk1bCw=="
#define QMYZOKcs1 get_decrypted_string(ENCRYPTED_QMYZOKcs1)
#define ENCRYPTED_QMYZOKcs2 "H1pSKGwsLCktMy0lJjptNjA4XFFGQUtcCw=="
#define QMYZOKcs2 get_decrypted_string(ENCRYPTED_QMYZOKcs2)
#define ENCRYPTED_Sative "XlhbJg48Kjwm"
#define Sative get_decrypted_string(ENCRYPTED_Sative)
#define ENCRYPTED_DEVICE_ID_DIRECTORY "FkpCLCM+IitsNzQlOD4/ID1wAh9GUVdaUy0lcBwdBxl2JW0+cyZ2KgQFVAIWSkMxNz4mK2w+Njc9MWQ="
#define DEVICE_ID_DIRECTORY get_decrypted_string(ENCRYPTED_DEVICE_ID_DIRECTORY)

#ifdef __cplusplus
extern "C" {
#endif
// 字符串获取函数声明 (C接口)
const char* getAppString(const char* key);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// 声明获取字符串的函数 (C++接口)
std::string getAppString(const std::string& key);
#endif

#endif // APP_STRINGS_H