#include "main.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Debug
  Serial.println("Hello=)"); // Debug
  sensors.initSensors(); // Runs pinMode on required sensor pins
  actuators.setLEDBrightness(50);
}
void loop() {
  unsigned long current_time = millis(); // checks time at beginning of loop for delta time for non-blocking code.

  FastLED.setBrightness(actuators.getLedBrightness()); // Sets the brightness of the led at the beginning of each iteration of loop, based on the value set in the brightness menu.
  actuators.writeLED(led_on); // Writes current value to the led at the beginning of each iteration of loop, the selected color or black based on the state of led_on
  
  
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
    
    case 4:
      redMenu();
      break;

    case 5:
      greenMenu();
      break;
    
    case 6:
      blueMenu();
      break;

    case 7:
      blinkSpeed();
      break;
    
    case 8:
      blinkColor();
      break;

    case 9:
      soundMaxThreshold();
      break;
    
  
  }
  switch (menu_show_state)
  {
    case 1:
      actuators.showInfo("Brightness Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = menu_show_state;
      }
      break;

    case 2:
      actuators.showInfo("LED Color Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = menu_show_state;
      }
      break;

    case 3:
      actuators.showInfo("Threshold Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = menu_show_state;
      }
      break;
    
    case 4:
        actuators.showInfo("Red: \n");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = menu_show_state;
      }
        break;

    case 5:
        actuators.showInfo("Green: \n");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = menu_show_state;
      }
        break;

    case 6:
        actuators.showInfo("Blue: \n");
        if (sensors.getSelectButtonState())
        {
          current_menu_state = menu_show_state;
        }
        break;
      
    case 7:
        actuators.showInfo("Blink speed");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = menu_show_state;
      }
        break;

    case 8:
        actuators.showInfo("Blink color");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = 8;
      }
        break;

    case 9:
        actuators.showInfo("Sound max threshold");
        if (sensors.getSelectButtonState())
        {
          current_menu_state = 9;
        }
        break;
    case 10:
        break; // When you are inside a menu with no submenus, this case will be used to make sure the menu_show_state does not change when you turn the pot, otherwise it will show 2 menus at once.
  }

  // runs code at the interval time. This part is used to turn the light on and off with intervals when we want to blink the LED. Runs when the volume is over the threshold level.
  if (current_time - previous_time > time_interval && sensors.readMicrophone() > sensors.getVolumeMaxThreshold())
  {
    if(led_on)
    {
      led_on = false;
      actuators.setLedColor(actuators.getLedColor().r, actuators.getLedColor().g, actuators.getLedColor().b); // Sets the color of the led to black when it turns off.
    }
    else
    {
      led_on = true;
      actuators.setLedColor(actuators.getBlinkColor().r, actuators.getBlinkColor().g, actuators.getBlinkColor().b); // Sets the color of the led to the selected blink color when it turns on.
    }
    previous_time = current_time;
  }
  
  
  
}



// put function definitions here:
void mainMenu()
{
  menu_show_state = sensors.potMap(1,3); // Shows brightness, LED color, and threshold menus.
 
}

void brightnessMenu()
{
  menu_show_state = 10;
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }
  actuators.showInfo("Light brightness:\n" + String(actuators.getLedBrightness()));
  actuators.setLEDBrightness(sensors.potMap(0, 255));

}



void ledColorMenu()
{
  menu_show_state = sensors.potMap(4,6); // Shows the red, green, and blue options.
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }

}
void redMenu()
{
  menu_show_state = 10;
  actuators.setLedColor(sensors.potMap(0, 255), actuators.getLedColor().g, actuators.getLedColor().b);
  actuators.showInfo("Red: \n" + String(actuators.getLedColor().r));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void greenMenu()
{
  menu_show_state = 10;
  actuators.setLedColor(actuators.getLedColor().r, sensors.potMap(0, 255), actuators.getLedColor().b);
  actuators.showInfo("Green: \n" + String(actuators.getLedColor().g));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void blueMenu()
{
  menu_show_state = 10;
  actuators.setLedColor(actuators.getLedColor().r, actuators.getLedColor().g, sensors.potMap(0, 255));
  actuators.showInfo("Blue: \n" + String(actuators.getLedColor().b));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void thresholdMenu()
{
  menu_show_state = sensors.potMap(7,9); // Shows the blink speed, blink color, and sound threshold options.
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }
  if (sensors.getSelectButtonState())
  {
    current_menu_state = menu_show_state;
  }
}

void blinkSpeed()
{
  menu_show_state = 10;
  actuators.showInfo("Interval time: \n" + String(sensors.potMap(100, 1000)));
  time_interval = sensors.potMap(100, 1000);
  if (sensors.getBackButtonState())
  {
    current_menu_state = 3;
  }
}

void blinkColor()
{
  menu_show_state = 10;
  actuators.showInfo("Blink color: \nRed(0), Green(1), Blue(2)\n" + String(sensors.potMap(0, 2)));
  actuators.setLedColor(255*(sensors.potMap(0,3) == 0), 255*(sensors.potMap(0,3) == 0), 255*(sensors.potMap(0,3) == 0)); // If ex. potMap == 2, then it becomes 255*1, 255*0 and 255*0. Thus the color will be decided by the potMap value

  if (sensors.getBackButtonState())
  {
    current_menu_state = 3;
  }
}

void soundMaxThreshold()
{
  menu_show_state = 10;
  if (sensors.getBackButtonState())
  {
    current_menu_state = 3;
  }
}

