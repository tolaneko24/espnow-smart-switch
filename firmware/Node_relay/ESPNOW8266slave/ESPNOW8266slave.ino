#include "ESPNOW_Slave.h"

bool lastState1 = HIGH;
bool lastState2 = HIGH;

unsigned long lastReconnectAttempt = 0;

void setup() {
    Serial.begin(115200);
    delay(50);
    Serial.printf("\n =========ESPNOW SLAVE %d======== \n", ID);

    // Khởi tạo các relay và switch
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    pinMode(switch1, INPUT_PULLUP);
    pinMode(switch2, INPUT_PULLUP);

    // Tắt relay ban đầu
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);

    // Kết nối WiFi Gateway
    espSlave.connectWiFi();
    yield();  // cho hệ thống WiFi thở
    delay(50);

    // Bật ESP-NOW
    espSlave.begin();
    // Thêm peer (Server)
    espSlave.addPeer(serverMAC);
}

// Kiểm tra trạng thái của switch và đồng bộ trạng thái relay và server
void checkSwitch(int switchPin, bool *lastState, int relayPin, uint8_t relay) {
    bool currentState = digitalRead(switchPin);

    if (currentState != *lastState) {
        delay(50);
        if (digitalRead(switchPin) == currentState) {
            *lastState = currentState;

            // Đảo trạng thái relay
            bool newRelayState = !digitalRead(relayPin);
            digitalWrite(relayPin, newRelayState);
            Serial.printf("Switch%d -> %d ", relay, newRelayState);
            espSlave.sendServerState(relay, newRelayState);
        }
    }
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        if (millis() - lastReconnectAttempt > 5000) {
            Serial.println("⚠️ Mất kết nối WiFi. Thử lại...");
            espSlave.connectWiFi();
            lastReconnectAttempt = millis();
        }
    }

    checkSwitch(switch1, &lastState1, relay1, 1);
    checkSwitch(switch2, &lastState2, relay2, 2);
}
