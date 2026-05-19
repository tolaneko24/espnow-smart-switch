/******************************************************************************
 * @file    gateway_espnow_main.cpp
 * @brief   ESP-NOW Smart Switch Gateway
 * @author  Nhom 2 BTL He Thong Nhung
 * @date    2026
 *
 * @project HỆ THỐNG MẠNG ĐIỀU KHIỂN KHÔNG DÂY THỜI GIAN THỰC
 *          SỬ DỤNG ESP-NOW TRÊN ESP32
 *
 * @description
 * Gateway trung tâm cho hệ thống điều khiển không dây sử dụng ESP-NOW.
 * Chương trình thực hiện:
 *  - Kết nối WiFi và Blynk Cloud
 *  - Khởi tạo ESP-NOW
 *  - Gửi/Nhận lệnh điều khiển relay
 *  - Quản lý ACK và retransmission
 *  - Đồng bộ trạng thái node
 *
 * @hardware
 *  - ESP32 DevKit V1
 *  - Relay Module
 *  - WiFi Router
 *
 * @communication
 *  - ESP-NOW peer-to-peer
 *  - WiFi STA + AP
 *  - MQTT/Blynk (optional)
 *
 * @topology
 *  - Star topology
 *  - Optional multi-hop repeater
 *
 * @features
 *  - Device pairing
 *  - Device addressing
 *  - ACK response
 *  - Retry transmission
 *  - Real-time control
 *  - OTA support (future work)
 *
 * @note
 
 
 *
 * @coding_standard
 *  - Naming convention:
 *      + class      : PascalCase
 *      + function   : camelCase
 *      + variable   : camelCase
 *      + constant   : UPPER_CASE
 *
 *  - Source structure:
 *      + config.h
 *      + ESPNOWModule.cpp/.h
 *      + BlynkModule.cpp/.h
 *      + WiFiModule.cpp/.h
 *      + main.cpp
 *
 * @version 1.0
 ******************************************************************************/
#include "config.h"
#include "WiFiModule.h"
#include "BlynkModule.h"
#include "ESPNOWModule.h"
#include "platform.h"

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;

unsigned long lastReconnectAttempt = 0;

void setup() {
    Serial.begin(115200);
    delay(50);
    Serial.println("\n=========ESPNOW SERVER========\n");

    // Kết nối WiFi
    connectWiFi();
    delay(50);
 

    // Khởi tạo Blynk
    beginBlynk();
    delay(50);

    // Khởi tạo relay và switch
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);

    pinMode(switch1, INPUT_PULLUP);
    pinMode(switch2, INPUT_PULLUP);
    pinMode(switch3, INPUT_PULLUP);

    // Khởi tạo ESP-NOW
    espNow.begin();
    // Thêm peer (Slave)
    espNow.addPeer(slave1MAC);
    espNow.addPeer(slave2MAC);
    // Hiển thị số lượng slave đang kết nối
    Serial.printf("Num Slave Connect AP: %d\n", WiFi.softAPgetStationNum());
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        if (millis() - lastReconnectAttempt > 5000) {
            Serial.println("⚠️ Mất kết nối WiFi. Thử lại...");
            connectWiFi();
            lastReconnectAttempt = millis();
        }
    } else {
        blynkRun();
    }

    checkSwitch(switch1, &lastState1, relay1, VPIN_RELAY1);
    checkSwitch(switch2, &lastState2, relay2, VPIN_RELAY2);
    checkMessage(&newMsg, lastMsg);

}

void checkSwitch(int switchPin, bool *lastState, int relayPin, int vPin) {
    bool currentState = digitalRead(switchPin);

    if (currentState != *lastState) {
        delay(50);
        if (digitalRead(switchPin) == currentState) {
            *lastState = currentState;
            bool newRelayState = !digitalRead(relayPin);
            digitalWrite(relayPin, newRelayState);
            blynkVirtualWrite(vPin, newRelayState);
        }
    }
}
