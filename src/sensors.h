#pragma once

#include <Arduino.h>

class Sensors {
    public:
        Sensors(int potPin, int micPin);
        int getPot(int states);
        int getPot4();
        int getPot256();
        int readMicrophone();
}