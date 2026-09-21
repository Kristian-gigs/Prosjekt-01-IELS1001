#include <Arduino.h>
#include "FastLED.h"

#define NUM_LEDS 5
#define DATA_PIN 15

CRGB leds[NUM_LEDS];



// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Turn the LED on, then pause
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(500);
  
  // Now turn the LED off, then pause
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
}

// put function definitions here:
