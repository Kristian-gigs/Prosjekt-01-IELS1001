#pragma once

#include <Arduino.h>
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "FastLED.h"
#include "string.h"

#define NO_ADAFRUIT_SSD1306_COLOR_COMPATIBILITY


#define DATA_PIN 3
#define OLED_SDA A4
#define OLED_SCL A5
#define NUM_LEDS 5

class Actuators {
    private:
        const int _screenWidth = 128;
        const int _screenHeight = 64;
        bool ledstate = 0;
        Adafruit_SSD1306 display;
        CRGB leds[NUM_LEDS];
        CRGB ledColor;
        
    public:
        Actuators();
        void writeLED(bool On);
        void setLED(bool On);
        void setLEDColor(int r, int g, int b);
        void setLEDBrightness(int bright);
        int getLedBrightness();
        void setLedState();
        void setLedColor(int r, int g, int b);
        CRGB getLedColor();
        void showInfo(String info);
        enum MenuState
        {
          MAIN_MENU,
          BRIGHTNESS_MENU,
          LED_COLOR_MENU,
          THRESHOLD_MENU
        };
        MenuState current_menu_state = MAIN_MENU;
};
