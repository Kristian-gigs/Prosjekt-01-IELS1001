#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include "actuators.h"
#include "sensors.h"

#define NUM_LEDS 5

unsigned long previous_time = 0;
unsigned long time_interval = 500;
bool led_on = false;
int menu_select_state = 0;

Actuators actuators;
Sensors sensors;

void mainMenu();
void brightnessMenu();
void ledColorMenu();
void thresholdMenu();
