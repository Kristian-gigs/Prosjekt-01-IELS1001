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
