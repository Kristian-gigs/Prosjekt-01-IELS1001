#include "sensors.h"

Sensors::Sensors()
{

}

void Sensors::initSensors() // Put in setup for init of required pins
{
    pinMode(SELECT_BUTTON, INPUT_PULLUP);
    pinMode(BACK_BUTTON, INPUT_PULLUP);
}

int Sensors::getPot() // Gets analog value from potentiometer
{
    return analogRead(POT_PIN);
}

int Sensors::potMap(int lowestOut, int highestOut) // Gets desired map of analog value from pot.
{
    return map(analogRead(POT_PIN), 0, 1023, lowestOut, highestOut);
}

bool Sensors::getSelectButtonState() // Checks if button is pressed. The button will be registered pressed once due to debouncing with delta time.
{
    bool btnState = !digitalRead(SELECT_BUTTON);

    if (btnState && (millis() - selectBtnLastPrsd> 200))
    {
        selectBtnLastPrsd = millis();
        return true;
    }
    else if (btnState && !(millis() - selectBtnLastPrsd > 200)){
        selectBtnLastPrsd = millis();
        return false;
    }
    else
    {
        return false;
    }
    
}  
bool Sensors::getBackButtonState() // Checks if button is pressed. The button will be registered pressed once due to debouncing with delta time.
{
    bool btnState = !digitalRead(BACK_BUTTON);

    if (btnState && (millis() - backBtnLastPrsd > 200))
    {
        backBtnLastPrsd = millis();
        return true;
    }
    else if (btnState && !(millis() - backBtnLastPrsd > 200)){
        backBtnLastPrsd = millis();
        return false;
    }
    else
    {
        return false;
    }
}
