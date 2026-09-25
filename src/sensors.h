#pragma once

#include <Arduino.h>

#define POT_PIN A0
#define MIC_PIN A1
#define SELECT_BUTTON 4
#define BACK_BUTTON 5

class Sensors {
    private:
        // Member vars ////////////////////////
        int volumeMaxThreshold = 400; // Default threshold for safe volume at the working place
        int volumeLedOnThreshold = 100; // Threshold for sound in the room for the room to be considered in use, so the light will be on.
        int backBtnLastPrsd = millis(); // For software debouncing of btn
        int selectBtnLastPrsd = millis(); // same as above
        ///////////////////////////////////////
    public:

        // Member funcs //////////////////////
        Sensors(); // constructor
        void initSensors(); // Set pinModes for input pins
        int getPot(); // Get value from pot
        int potMap(int lowestOut, int highestOut);
        bool getSelectButtonState(); // Get state of select btn. Includes debounce
        bool getBackButtonState(); // Get state of back btn. Includes debounce
        int getVolumeMaxThreshold(); // Get threshold for volume
        void setVolumeMaxThreshold(int newThreshold); // Set threshold for volume
        int readMicrophone(); // Get analog mic.
        /////////////////////////////////////
    private:
};