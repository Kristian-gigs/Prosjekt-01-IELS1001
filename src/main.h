#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include "actuators.h"
#include "sensors.h"


#define POT_PIN A0
#define MIC_PIN A1
#define SELECT_BUTTON 4
#define BACK_BUTTON 5

#define NUM_LEDS 5

unsigned long previous_time = 0;
unsigned long time_interval = 500;
bool led_on = false;
int menu_state = 0;
