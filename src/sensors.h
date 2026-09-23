#pragma once

#include <Arduino.h>

class Sensors {
    private:
        // Member vars ////////////////////////
        int volumeThreshold = 200;
        ///////////////////////////////////////
    public:

        // Member funcs //////////////////////
        Sensors(int potPin, int micPin);
        int getPot(int states);
        int getMainMenuState();
        int getSubMenuState();
        bool getSelectButtonState();
        bool getBackButtonState();
        int readMicrophone();
        /////////////////////////////////////
    private:
};