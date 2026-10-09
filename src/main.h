#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include "actuators.h"
#include "sensors.h"

uint32_t previous_time = 0;
uint32_t time_interval = 500; // Time interval for blink length.
bool led_on = true;
bool led_override_off = false;
int current_menu_state = 0;
int menu_show_state = 0;
uint32_t last_significant_activity = millis();
 uint32_t ledHoldTime = 600000UL; // Time for the led to stay on after last significant sound in the room.
uint32_t last_breach_max_threshold = 0;

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
