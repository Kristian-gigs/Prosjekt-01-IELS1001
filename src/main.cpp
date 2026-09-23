#include "main.h"

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  unsigned long current_time = millis();

  time_interval = analogRead(POT_PIN)/2 + 50;
  
  // Maps values for the menu states. The current menu is for selecting whether one is inside the mainmenu, or inside the other menus.
  // The menu_select_state is for choosing which menu is visible, though it is not selected yet.
  if (sensors.getSelectButtonState() && current_menu_state)
  {
    current_menu_state = map(sensors.getPot(), 0, 1023, 0, 3);
  }
  else if (sensors.getSelectButtonState())
  {
    menu_select_state = map(sensors.getPot(), 0, 1023, 0, 2);
  }
  
  switch (current_menu_state)
  {
    case 0:
      mainMenu();

      break;
    
    case 1:
      brightnessMenu();
      break;

    case 2:
      ledColorMenu();
      break;
    
    case 3:
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
        current_menu_state = 1;
      }
      break;
    case 1:
      actuators.showInfo("LED Color Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 2;
      }
      break;
    case 2:
      actuators.showInfo("Threshold Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 3;
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