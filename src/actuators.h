#pragma once

#include <Arduino.h>
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "FastLED.h"
#include "string.h"

#define NO_ADAFRUIT_SSD1306_COLOR_COMPATIBILITY // The screen has half screen yellow, other half blue. No way to choose.


#define DATA_PIN 3 // DOUT for LED
#define OLED_SDA A4
#define OLED_SCL A5
#define NUM_LEDS 5 // Number of leds in WS2812 strip.

// Clas for containing actuators and functions relating to them.
class Actuators {
    private:
        const int _screenWidth = 128; // Sizing of OLED screen
        const int _screenHeight = 64;
        bool ledstate = 0; // Led on/off
        Adafruit_SSD1306 display;
        CRGB leds[NUM_LEDS]; // Container for leds elements
        CRGB ledColor = CRGB::White; // Container for led color
        
    public:
        Actuators();
        void writeLED(bool On); // Turn LED on or off.
        void setLEDBrightness(int bright); // Set brightness of led 0-100%
        int getLedBrightness(); // Get brightness val of led
        void setLedState(); // Redundant?
        void setLedColor(int r, int g, int b); // Set color of led in RGB.
        CRGB getLedColor(); // Get color of led as rgb obj
        void showInfo(String info); // Print strings to OLED
};
