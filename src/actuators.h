#pragma once

#include <Arduino.h>
#include "Wire.h"
#include "string.h"
#define NO_ADAFRUIT_SSD1306_COLOR_COMPATIBILITY
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "FastLED.h"

class Actuators {
    private:
        const int _screenWidth = 128;
        const int _screenHeight = 64;
        int _NUM_LEDS;
        int _DATA_PIN;
        Adafruit_SSD1306 display;

    public:
        Actuators(CRGB *leds[], Adafruit_SSD1306 *display);
        void setLED(bool On);
        void setLEDColor(int r, int g, int b);
        void setLEDBrightness(int bright);
        void showInfo(String info);
        

};
