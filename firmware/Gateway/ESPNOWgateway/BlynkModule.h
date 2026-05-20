#ifndef BLYNKMODULE_H
#define BLYNKMODULE_H

#include "ESPNOWModule.h"

void beginBlynk();
void blynkRun();
void blynkVirtualWrite(int vPin, int value);
void checkMessage(bool *newMsg, message msg);

#endif
