#include "main.h"

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  unsigned long current_time = millis();

  time_interval = analogRead(POT_PIN)/2 + 50;

  switch (actuators.current_menu_state)
  {
    case Actuators::MenuState::MAIN_MENU:
      mainMenu();

      break;
    
    case Actuators::MenuState::BRIGHTNESS_MENU:
      brightnessMenu();
      break;

    case Actuators::MenuState::LED_COLOR_MENU:
      ledColorMenu();
      break;
    
    case Actuators::MenuState::THRESHOLD_MENU:
      thresholdMenu();
      break;
    
  }
  if (current_time - previous_time > time_interval)
  {
    previous_time = current_time;
    
  }
  
  
  
}



// put function definitions here:
void mainMenu()
{
  switch (menu_select_state)
  {
    case 0:
      actuators.showInfo("Brightness Menu");
      if (sensors.getSelectButtonState())
      {
        actuators.current_menu_state = Actuators::MenuState::BRIGHTNESS_MENU;
      }
      break;
    case 1:
      actuators.showInfo("LED Color Menu");
      if (sensors.getSelectButtonState())
      {
        actuators.current_menu_state = Actuators::MenuState::LED_COLOR_MENU;
      }
      break;
    case 2:
      actuators.showInfo("Threshold Menu");
      if (sensors.getSelectButtonState())
      {
        actuators.current_menu_state = Actuators::MenuState::THRESHOLD_MENU;
      }
      break;
    
  }
}

void brightnessMenu()
{
  actuators.showInfo("Light brightness:\n" + String(actuators.getLedBrightness()));
}



void ledColorMenu()
{
  switch (menu_select_state)
  {
    case 0:
      actuators.showInfo("Red: \n" + String(actuators.getLedColor().r));
      break;
    case 1:
      actuators.showInfo("Green: \n" + String(actuators.getLedColor().g));
      break;
    case 2:
      actuators.showInfo("Blue: \n" + String(actuators.getLedColor().b));
      break;
  }
}

void thresholdMenu()
{
  switch (menu_select_state)
  {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
  }
}