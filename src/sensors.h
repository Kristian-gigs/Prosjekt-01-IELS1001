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
        int getPot4();
        int getPot256();
        int readMicrophone();
        /////////////////////////////////////
    private:
};