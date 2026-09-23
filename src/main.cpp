#include "main.h"

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  Actuators actuator(leds, display);
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
