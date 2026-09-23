#pragma once

#include <Arduino.h>

#define POT_PIN A0
#define MIC_PIN A1
#define SELECT_BUTTON 4
#define BACK_BUTTON 5

class Sensors {
    private:
        // Member vars ////////////////////////
        int volumeThreshold = 200;
        int backBtnLastPrsd = millis();
        int selectBtnLastPrsd = millis();
        ///////////////////////////////////////
    public:

        // Member funcs //////////////////////
        Sensors();
        void initSensors();
        int getPot();
        bool getSelectButtonState();
        bool getBackButtonState();
        int readMicrophone();
        /////////////////////////////////////
    private:
};