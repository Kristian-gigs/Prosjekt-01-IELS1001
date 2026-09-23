#pragma once

#include <Arduino.h>
#include "string.h"

class Actuators {
    public:
        Actuators(int ledPin);
        void setLED(bool state);
        void setLEDColor(int r, int g, int b);
        void setLEDBrightness(int bright);
        void showInfo(String info)
};
