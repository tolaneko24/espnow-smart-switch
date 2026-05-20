#ifndef CONFIG_H
#define CONFIG_H

// --- Slave identity ---
#define ID 1

// --- Gateway (phải trùng softAP trên Server) ---
#define GATEWAY_AP_SSID   "ESP_SERVER"
#define GATEWAY_AP_PASS   "quyquyquy"

// --- Địa chỉ MAC của Server ---
//#define SERVER_MAC_INIT {0x24, 0x4C, 0xAB, 0x56, 0x23, 0x79}// cua esp8266 cũ
#define SERVER_MAC_INIT {0x26, 0x4C, 0xAB, 0x56, 0x23, 0x79}

//#define SERVER_MAC_INIT {0xEC, 0xE3, 0x34, 0xDA, 0x85, 0x44} //esp32

// --- GPIO ---
#define relay1 5   // D1
#define relay2 0   // D3
#define relay3 12  // D6
#define relay4 15  // D8

#define switch1 4   // D2
#define switch2 14  // D5
#define switch3 13  // D7

// --- Timing ---
#define SERIAL_BAUD              115200
#define WIFI_RECONNECT_INTERVAL_MS 5000
#define SWITCH_DEBOUNCE_MS       50
#define WIFI_CONNECT_MAX_ATTEMPTS 20
#define WIFI_CONNECT_RETRY_MS    500

#endif
