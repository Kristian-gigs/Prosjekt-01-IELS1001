#include "actuators.h"
#include "HardwareSerial.h" // Debug
#include "sensors.h"

Actuators::Actuators()
{
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

//Funksjon for å skrive til ledstripe
void Actuators::writeLED(bool On) 
{
    if(On)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = ledColor;
        }
        ledstate = true;
    }
    else
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = 0; 
        }
    }
    FastLED.show();
    
}

// Funksjon for å sette lysstyrke på ledstripe
void Actuators::setLEDBrightness(int bright)
{
    FastLED.setBrightness(bright);
}

int Actuators::getLedBrightness()
{
    return FastLED.getBrightness();
}


void Actuators::setLedColor(int r, int g, int b)
{
    ledColor.setRGB(r, g, b);
}

CRGB Actuators::getLedColor()
{
    return ledColor;
}

void Actuators::setBlinkColor(int r, int g, int b)
{
    blinkColor.setRGB(r, g, b);
}

CRGB Actuators::getBlinkColor()
{
    return blinkColor;
}

// Funksjon for å skrive ting på displayet
void Actuators::showInfo(String info)
{
    if (info == lastInfo)
    {
        return;
    }

    lastInfo = info;
    display.clear();
    display.setCursor(4, 30);
    display.set2X();
    display.println(info);
    Serial.println(info); // Debug
}