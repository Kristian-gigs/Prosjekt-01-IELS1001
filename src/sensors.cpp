#include "sensors.h"

Sensors::Sensors()
{

}

void Sensors::initSensors()
{
    pinMode(SELECT_BUTTON, INPUT_PULLUP);
    pinMode(BACK_BUTTON, INPUT_PULLUP);
}

int Sensors::getPot()
{
    return analogRead(POT_PIN);
}

bool Sensors::getSelectButtonState()
{
    return !digitalRead(SELECT_BUTTON);
}

bool Sensors::getBackButtonState()
{
    return !digitalRead(BACK_BUTTON);
}
