#include "main.h"
#include "actuators.h"
#include "sensors.h"
#include <Arduino.h>
#include "FastLED.h"

#if defined(ARDUINO_ARCH_AVR)
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

unsigned long previous_time = 0;
unsigned long time_interval = 500;
bool led_on = false;
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  unsigned long current_time = millis();

  time_interval = analogRead(POT_PIN)/2 + 50;

  if (current_time - previous_time > time_interval)
  {
    previous_time = current_time;
    if (!led_on)
    {
      // Turn the LED on, and set led_on to true
      for (int i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Red;
      }
      FastLED.show();
      led_on = true;
      
    }
    
  else
  {
    // Now turn the LED off and set led_on to false
    for (int i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Black;
      }
    FastLED.show();
    led_on = false;
  }
  }
  
  
}

// put function definitions here:
