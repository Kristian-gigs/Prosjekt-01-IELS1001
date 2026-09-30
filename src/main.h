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
unsigned long last_significant_activity = millis();
unsigned long last_max_vol_thr_breach;
unsigned long ledHoldTime = 1000*60*10; // Time for the led to stay on after last significant sound in the room.


Actuators actuators;
Sensors sensors;

void mainMenu();
void brightnessMenu();
void ledColorMenu();
void thresholdMenu();
void redMenu();
void greenMenu();
void blueMenu();
void blinkSpeed();
void blinkColor();
void soundMaxThreshold();
