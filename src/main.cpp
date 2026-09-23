#include "main.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Debug
  Serial.println("Hello=)"); // Debug
  sensors.initSensors(); // Runs pinMode on required sensor pins
}
void loop() {
  unsigned long current_time = millis(); // checks time at beginning of loop for delta time for non-blocking code.

  actuators.writeLED(led_on); // Writes current value to the led at the beginning of each iteration of loop, the selected color or black based on the state of led_on
  actuators.setLEDBrightness(50);


  // Maps values for the menu states. The current menu is for selecting whether one is inside the mainmenu, or inside the other menus.
  // The menu_select_state is for choosing which menu is visible, though it is not selected yet. So it scrolls across menus, letting you choose which one with the select button.
  if ((sensors.getSelectButtonState() && current_menu_state == 0) || current_menu_state == 1)
  {
    menu_select_state = map(sensors.getPot(), 0, 1023, 0, 2);
  }
  else if (sensors.getSelectButtonState())
  {
    current_menu_state = map(sensors.getPot(), 0, 1023, 0, 3);
  }
  
  // Checks which menu we are currently in, and then runs the command to show said screen. Checks current menu state every iteration.
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

  // runs code at the interval time. This part is used to turn the light on and off with intervals when we want to blink the LED. Runs when the volume is over the threshold level.
  if (current_time - previous_time > time_interval)
  {
    previous_time = current_time;
    // led_on = false;
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
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }
  actuators.showInfo("Light brightness:\n" + String(actuators.getLedBrightness()));

}



void ledColorMenu()
{
  
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }
    switch (menu_select_state)
    {
      case 0:
        actuators.setLedColor(sensors.getPot(), actuators.getLedColor().g, actuators.getLedColor().b); 
        actuators.showInfo("Red: \n" + String(actuators.getLedColor().r));
        break;
      case 1:
        actuators.setLedColor(actuators.getLedColor().r, sensors.getPot(), actuators.getLedColor().b);
        actuators.showInfo("Green: \n" + String(actuators.getLedColor().g));
        break;
      case 2:
        actuators.setLedColor(actuators.getLedColor().r, actuators.getLedColor().g, sensors.getPot());
        actuators.showInfo("Blue: \n" + String(actuators.getLedColor().b));
        break;
    }
  

}

void thresholdMenu()
{
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }

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