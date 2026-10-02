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
    Serial.println(analogRead(POT_PIN)); // DEBUG
    return map(analogRead(POT_PIN), 0, 1024, lowestOut, highestOut + 1); // The highest in is +1 and highest out is +1 due to highestout only mapping to the highest in value, not equally distrib. This fixes that.
}

bool Sensors::getSelectButtonState() // Checks if button is pressed. The button will be registered pressed once due to debouncing with delta time.
{
    Serial.println(digitalRead(SELECT_BUTTON)); // DEBUG
    bool btnState = !digitalRead(SELECT_BUTTON);

    if (btnState && (millis() - selectBtnLastPrsd > 200))
    {
        selectBtnLastPrsd = millis();
        Serial.println(selectBtnLastPrsd); // DEBUG
        return true;
    }
    else if (btnState && !(millis() - selectBtnLastPrsd > 200)){
        selectBtnLastPrsd = millis();
        Serial.println(selectBtnLastPrsd); // DEBUG
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

int Sensors::getVolumeMaxThreshold()
{
    return volumeMaxThreshold;
}

void Sensors::setVolumeMaxThreshold(int newThreshold)
{
    volumeMaxThreshold = newThreshold;
}

int Sensors::readMicrophone()
{
    mic= analogRead(MIC_PIN);
    amplitude=abs(mic - mic_baseline);
    return amplitude;
}