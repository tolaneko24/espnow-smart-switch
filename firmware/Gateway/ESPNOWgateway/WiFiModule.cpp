#include "WiFiModule.h"
#include "config.h"
#include <WiFi.h>
#include <esp_now.h>

const char* ssid = WIFI_ROUTER_SSID;
const char* pass = WIFI_ROUTER_PASS;

void connectWiFi() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
  if (checkWiFi(WIFI_CONNECT_TIMEOUT_SEC)) {
    Serial.println("✅ Kết nối WiFi Rounter thành công!");
    Serial.printf("[WiFiRounter] Channel: %d, Status: %d\n", WiFi.channel(), WiFi.status());
    return;
  }
  Serial.println("🚨 Không thể kết nối WiFi , Status: ");
   printWiFiStatus();
}

void printWiFiStatus() {
    switch (WiFi.status()) {
        case WL_IDLE_STATUS: Serial.println("WiFi đang khởi động..."); break;
        case WL_NO_SSID_AVAIL: Serial.println("Không tìm thấy SSID!"); break;
        case WL_CONNECTED: Serial.println("✅ Đã kết nối WiFi!"); break;
        case WL_CONNECT_FAILED: Serial.println("❌ Kết nối thất bại!"); break;
        case WL_CONNECTION_LOST: Serial.println("⚠️ Mất kết nối!"); break;
        case WL_DISCONNECTED: Serial.println("📴 Đã ngắt kết nối!"); break;
        default: Serial.println("Không rõ trạng thái."); break;
    }
}

bool checkWiFi(int timeout) {
  int count = 0;
  while (WiFi.status() != WL_CONNECTED && count < timeout * 2) {
    delay(WIFI_CONNECT_RETRY_MS);
    Serial.print(".");
    count++;
  }
  Serial.println();
  return WiFi.status() == WL_CONNECTED;
}

