#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include "actuators.h"
#include "sensors.h"

#define NUM_LEDS 5

unsigned long previous_time = 0;
unsigned long time_interval = 500;
bool led_on = true;
int current_menu_state = 0;
int menu_show_state = 0;

Actuators actuators;
Sensors sensors;

void mainMenu();
void brightnessMenu();
void ledColorMenu();
void thresholdMenu();
