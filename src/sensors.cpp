#include "sensors.h"

Sensors::Sensors()
{

}

void Sensors::initSensors() // Put in setup for init of required pins
{
    pinMode(SELECT_BUTTON, INPUT_PULLUP);
    pinMode(BACK_BUTTON, INPUT_PULLUP);
}

int Sensors::getPot() 
{
    return analogRead(POT_PIN);
}

bool Sensors::getSelectButtonState() // Checks if button is pressed. The button will be registered pressed once due to debouncing with delta time.
{
    bool btnState = digitalRead(BACK_BUTTON);

    if (btnState && millis() - backBtnLastPrsd > 200)
    {
        return !digitalRead(BACK_BUTTON);
        backBtnLastPrsd = millis();
    }
    else
    {
        return false;
    }
    
}  
bool Sensors::getBackButtonState() // Checks if button is pressed. The button will be registered pressed once due to debouncing with delta time.
{
    bool btnState = digitalRead(BACK_BUTTON);

    if (btnState && millis() - backBtnLastPrsd > 200)
    {
        return !digitalRead(BACK_BUTTON);
        backBtnLastPrsd = millis();
    }
    else
    {
        return false;
    }
}
