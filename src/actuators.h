#pragma once

#include <Arduino.h>
#include "Wire.h"
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "FastLED.h"
#include "string.h"

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
        String lastInfo;
        CRGB leds[NUM_LEDS]; // Container for leds elements
        CRGB ledColor = CRGB::White; // Container for led color
        CRGB blinkColor = CRGB::Red; // Container for blink color
        
    public:
        SSD1306AsciiWire display;
        Actuators();
        void writeLED(bool On); // Turn LED on or off.
        void setLEDBrightness(int bright); // Set brightness of led 0-100%
        int getLedBrightness(); // Get brightness val of led
        void setLedState(); // Redundant?
        void setLedColor(int r, int g, int b); // Set color of led in RGB.
        CRGB getLedColor(); // Get color of led as rgb obj
        CRGB getBlinkColor(); // Get color of blink as rgb obj
        void setBlinkColor(int r, int g, int b); // Set color of blink
        void showInfo(String info); // Print strings to OLED
};
