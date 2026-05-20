#ifndef CONFIG_H
#define CONFIG_H

// --- WiFi router (STA) ---
//const char* ssid = "nợ e một nàng dâu";
//const char* pass = "12345678";
//#define WIFI_ROUTER_SSID  "Tra My"
//#define WIFI_ROUTER_PASS  "tramy2013"

#define WIFI_ROUTER_SSID  "Tro T4"
#define WIFI_ROUTER_PASS  "123456789"

// --- SoftAP (ESP-NOW gateway) ---
#define GATEWAY_AP_SSID   "ESP_SERVER"
#define GATEWAY_AP_PASS   "quyquyquy"

// --- Blynk ---
/*#define BLYNK_TEMPLATE_ID "TMPL6nd9r6hO-"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "CRGfe2KmZLDV_KLCcwj0q-0y4Vt01eeA"*/
#define BLYNK_TEMPLATE_ID   "TMPL6u0DcNYuR"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN    "x_nPkL_Ufq9CuAQpJQxtP0A4Ivw7C5ia" // quytramy

// --- Server MAC ---
//[ESP-NOW] Device Server MAC: EC:E3:34:DA:85:44


// --- Slave MAC ---
//uint8_t slaveMAC3[] = {0xC8, 0xC9, 0xA3, 0x25, 0x68, 0x25};
//uint8_t slaveMAC4[] = {0xC8, 0xC9, 0xA3, 0x25, 0x68, 0x25};
#define SLAVE1_MAC_INIT {0xC8, 0xC9, 0xA3, 0x25, 0x68, 0x25}
//#define SLAVE1_MAC_INIT {0x24, 0x4C, 0xAB, 0x56, 0x23, 0x79}
#define SLAVE2_MAC_INIT {0xC9, 0xC9, 0xA3, 0x25, 0x68, 0x25}

#define NUM_SLAVES 2

// --- GPIO (ESP32 DevKit — chỉnh theo board thực tế) ---
#define relay1 26
#define relay2 27
#define relay3 14
#define relay4 12

#define switch1 32
#define switch2 33
#define switch3 25
#define switch4 22

// --- Blynk virtual pins (local relay + switch sync) ---
#define VPIN_LED_CONNECT 0
#define VPIN_RELAY1 1
#define VPIN_RELAY2 2
#define VPIN_RELAY3 3
#define VPIN_RELAY4 4

// --- Timing ---
#define SERIAL_BAUD                115200
#define WIFI_RECONNECT_INTERVAL_MS 5000
#define SWITCH_DEBOUNCE_MS         50
#define WIFI_CONNECT_TIMEOUT_SEC   20
#define WIFI_CONNECT_RETRY_MS      500
#define SETUP_DELAY_MS             50

#endif
