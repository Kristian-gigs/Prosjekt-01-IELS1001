#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include "actuators.h"
#include "sensors.h"

#if defined(ARDUINO_ARCH_AVR) //Pin definitions for Arduino Uno
  #define DATA_PIN 3
  #define POT_PIN A0
  #define MIC_PIN A1
  #define OLED_SDA A4
  #define OLED_SCL A5
  #define SELECT_BUTTON 4
  #define BACK_BUTTON 5
#elif defined(ARDUINO_ARCH_ESP32)
  #define DATA_PIN 13 // Labeled D13
  #define POT_PIN 36 // Labeled as VP on the ESP-WROOM-32
#endif

#define NUM_LEDS 5

CRGB leds[NUM_LEDS];
Adafruit_SSD1306 display;

unsigned long previous_time = 0;
unsigned long time_interval = 500;
bool led_on = false;