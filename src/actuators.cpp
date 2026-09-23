#include "actuators.h"

Actuators::Actuators(int ledPin, int SDA, int SCL, int pot, int selecBtn, int backBtn)
    : display(_screenWidth, _screenHeight, &Wire, -1)
{
    
}
void Actuators::setLED(bool On)
{

}

void Actuators::setLEDBrightness(int bright)
{

}

void Actuators::showInfo(String info)
{

}