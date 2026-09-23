#pragma once

#include <Arduino.h>
#include "Wire.h"
#include "string.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

class Actuators {
    private:
        const int _screenWidth = 128;
        const int _screenHeight = 64;
        Adafruit_SSD1306 display;


    public:
        Actuators(int ledPin, int SDA, int SCL, int pot, int selecBtn, int backBtn);
        void setLED(bool On);
        void setLEDColor(int r, int g, int b);
        void setLEDBrightness(int bright);
        void showInfo(String info);
        

};
