#pragma once

#include <Arduino.h>

#define POT_PIN A0
#define MIC_PIN A1
#define SELECT_BUTTON 4
#define BACK_BUTTON 5

class Sensors {
    private:
        // Member vars ////////////////////////
        int volumeThreshold = 200; // Default threshold for safe volume at the working place
        int backBtnLastPrsd = millis(); // For software debouncing of btn
        int selectBtnLastPrsd = millis(); // same as above
        ///////////////////////////////////////
    public:

        // Member funcs //////////////////////
        Sensors(); // constructor
        void initSensors(); // Set pinModes for input pins
        int getPot(); // Get value from pot
        bool getSelectButtonState(); // Get state of select btn. Includes
        bool getBackButtonState();
        int readMicrophone();
        /////////////////////////////////////
    private:
};