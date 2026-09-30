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
  
  
  // Checks which menu we are currently in, and then runs the command to show said menuscreen. Checks current menu state every iteration.
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
  // Checks which menu option to show based on which menu/submenu we are in. The reason we are using ranges is rounding
  // errors from the map function, because of the value of the pot being high, and the corresponding values to map are so few.
  // Thus, the ranges have been manually mapped with low precision here.
  switch (menu_show_state)
  {
    case 0 ... 300:
      actuators.showInfo("Brightness Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 1;
      }
      break;

    case 301 ... 600:
      actuators.showInfo("LED Color Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 2;
      }
      break;

    case 601 ... 1024:
      actuators.showInfo("Threshold Menu");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 3;
      }
      break;
    
    case 0+1200 ... 300+1200:
        actuators.showInfo("Red: \n");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = 4;
      }
        break;

    case 301+1200 ... 600+1200:
        actuators.showInfo("Green: \n");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = 5;
      }
        break;

    case 601+1200 ... 1024+1200:
        actuators.showInfo("Blue: \n");
        if (sensors.getSelectButtonState())
        {
          current_menu_state = 6;
        }
        break;
      
    case 0+2*1200 ... 300+2*1200:
        actuators.showInfo("Blink speed");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = 7;
      }
        break;

    case 301+2*1200 ... 600+2*1200:
        actuators.showInfo("Blink color");
        if (sensors.getSelectButtonState())
      {
        current_menu_state = 8;
      }
        break;

    case 601+2*1200 ... 1024+2*1200:
        actuators.showInfo("Sound max threshold");
        if (sensors.getSelectButtonState())
        {
          current_menu_state = 9;
        }
        break;
    case 5000:
        break; // When you are inside a menu with no submenus, this case will be used to make sure the menu_show_state does not change when you turn the pot, otherwise it will show 2 menus at once.
  }

  // Checks for volume thresholds deciding if there is significant activity at the current time
  // in terms of volum 
  if (sensors.readMicrophone() > sensors.volumeLedOnThreshold)
  {
    last_significant_activity = millis();
  }
  // Code for led to blink when over max vol threshold
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



// Auxiliary functions mainly for the menu system. ///////////////////////////////////////////////////////
void mainMenu()
{
  menu_show_state = sensors.getPot(); // Shows brightness, LED color, and threshold menus.
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
  menu_show_state = sensors.getPot()+1200; // Shows the red, green, and blue options.
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }

}
void redMenu()
{
  menu_show_state = 10;
  actuators.setLedColor(sensors.getPot()/4, actuators.getLedColor().g, actuators.getLedColor().b);
  actuators.showInfo("Red: \n" + String(actuators.getLedColor().r));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void greenMenu()
{
  menu_show_state = 10;
  actuators.setLedColor(actuators.getLedColor().r, sensors.getPot()/4, actuators.getLedColor().b);
  actuators.showInfo("Green: \n" + String(actuators.getLedColor().g));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void blueMenu()
{
  menu_show_state = 10;
  actuators.setLedColor(actuators.getLedColor().r, actuators.getLedColor().g, sensors.getPot()/4);
  actuators.showInfo("Blue: \n" + String(actuators.getLedColor().b));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void thresholdMenu()
{
  menu_show_state = sensors.getPot()+2*1200; // Shows the blink speed, blink color, and sound threshold options.
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
/////////////////////////////////////////////////////////////////////////////////////////////////
