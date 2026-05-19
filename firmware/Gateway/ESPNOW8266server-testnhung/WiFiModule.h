#ifndef WIFIMODULE_H
#define WIFIMODULE_H

extern const char* ssid;
extern const char* pass;

void connectWiFi();
bool checkWiFi(int timeout);

#endif
