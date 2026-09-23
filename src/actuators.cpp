#include "actuators.h"

Actuators::Actuators()
{
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    Adafruit_SSD1306 display(_screenWidth, _screenHeight, &Wire, -1);
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

}

// Funksjon for å sette variabelen ledState
void Actuators::setLedState()
{

}

void Actuators::setLedColor(int r, int g, int b)
{
    ledColor.setRGB(r, g, b);
}

// Funksjon for å skrive ting på displayet
void Actuators::showInfo(String info)
{
    
}