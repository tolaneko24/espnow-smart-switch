#include "WiFiModule.h"
#include "config.h"
#include "platform.h"

const char* ssid = WIFI_ROUTER_SSID;
const char* pass = WIFI_ROUTER_PASS;

void connectWiFi() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
  if (checkWiFi(20)) {
    Serial.println("✅ Kết nối WiFi Rounter thành công!");
    Serial.printf("[WiFiRounter] Channel: %d, Status: %d\n", WiFi.channel(), WiFi.status());
    return;
  }
  Serial.println("🚨 Không thể kết nối WiFi.");

}

bool checkWiFi(int timeout) {
  int count = 0;
  while (WiFi.status() != WL_CONNECTED && count < timeout * 2) {
    delay(500);
    Serial.print(".");
    count++;
  }
  Serial.println();
  return WiFi.status() == WL_CONNECTED;
}
