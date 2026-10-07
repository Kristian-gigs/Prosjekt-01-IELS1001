#pragma once

#include <Arduino.h>

#define POT_PIN A0
#define MIC_PIN A1
#define SELECT_BUTTON 4
#define BACK_BUTTON 5

class Sensors {
    private:
        // Member vars ////////////////////////
        unsigned long backBtnLastPrsd = millis(); // For software debouncing of btn
        unsigned long selectBtnLastPrsd = millis(); // same as above4
        bool backBtnIsTiming = false; // For checking if back button is being held
        bool backHoldTriggered = false; // For checking if back button has been held for a given time.
        unsigned long backBtnHoldStartTime = 0; // For checking how long back button has been held.
        int volumeMaxThreshold = 120; //max set amplitude. Default threshold for safe volume at the working place.
        int mic; //reading of mic
        const int mic_baseline = 337; // baseline of the mic. mic runs on 3.3v. so 1.65v = center so 1.65 /5*1023 =337
        int amplitude; // difference between mic and mic_baseline
        ///////////////////////////////////////
    public:
        // public vars ////////////////////////////////////////////////////////////////////////////////////////
        int volumeLedOnThreshold = 40; // Threshold for sound in the room for the room to be considered in use, so the light will be on.
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        // Member funcs //////////////////////
        Sensors(); // constructor
        void initSensors(); // Set pinModes for input pins
        int getPot(); // Get value from pot
        int potMap(int lowestOut, int highestOut);
        bool getSelectButtonState(); // Get state of select btn. Includes debounce
        bool getBackButtonState(); // Get state of back btn. Includes debounce
        int getBackBtnHoldTime();  // return time which back button has been held. For use in hold func of button.
        bool checkBackBtnHeld(); // Check if back button has been held for a given time. Returns true if held for given time, else false.
        int getVolumeMaxThreshold(); // Get threshold for volume
        void setVolumeMaxThreshold(int newThreshold); // Set threshold for volume
        int readMicrophone(); // Get analog mic.
        int getVolumeLedOnThreshold(); // Get sound threshold for led to be on
        /////////////////////////////////////

};