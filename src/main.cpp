#include "main.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Debug
  Serial.println("Hello=)"); // Debug
  Wire.begin();
  Wire.setClock(400000L);
  actuators.display.begin(&Adafruit128x64, 0x3C);
  actuators.display.setFont(Adafruit5x7);
  sensors.initSensors(); // Runs pinMode on required sensor pins
  actuators.setLEDBrightness(50);
}

void loop() {
  unsigned long current_time = millis(); // checks time at beginning of loop for delta time for non-blocking code.

  FastLED.setBrightness(actuators.getLedBrightness()); // Sets the brightness of the led at the beginning of each iteration of loop, based on the value set in the brightness menu.

  if (!led_override_off)
  {
    actuators.writeLED(led_on); // Writes current value to the led at the beginning of each iteration of loop, the selected color or black based on the state of led_on
  }
  else
  {
    actuators.writeLED(false); // Turns the light off permanently if the back button was held for a given time.
  }
  

  
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
      actuators.showInfo("Brightness");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 1;
      }
      break;

    case 301 ... 600:
      actuators.showInfo("LED Color");
      if (sensors.getSelectButtonState())
      {
        current_menu_state = 2;
      }
      break;

    case 601 ... 1024:
      actuators.showInfo("Threshold");
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

  
  if (sensors.readMicrophone() > sensors.getVolumeMaxThreshold() || current_time - last_breach_max_threshold < 2000)
  {
    actuators.setLedColor(actuators.getBlinkColor().r, actuators.getBlinkColor().g, actuators.getBlinkColor().b); // Sets the color of the led to the selected blink color when max threshold of volume is reached.
    
    if (sensors.readMicrophone() > sensors.getVolumeMaxThreshold())
    {
      last_breach_max_threshold = millis();
    }
    // Code for led to blink when over max vol threshold
    if (current_time - previous_time > time_interval)
    {
      led_on = !led_on;
      previous_time = current_time;
    }

  }
  else if (current_time - last_significant_activity > ledHoldTime && current_time - last_breach_max_threshold > 2000)
  {
    led_on = true;
    actuators.setLedColor(actuators.getUserLedColor().r, actuators.getUserLedColor().g, actuators.getUserLedColor().b);
  }
  else
  {
    led_on = false;
  }
  

  if(sensors.checkBackBtnHeld()) // If back button has been held for a given time, then toggle the led_override_off variable, which will turn the led off permanently until the back button is held again.
  {
    led_override_off = !led_override_off;
  }
  else
  {
    Serial.println("getBackBtnHoldTime less than 10 000: " + String(sensors.getBackBtnHoldTime())); // Debug
  }
  
  
}



// Auxiliary functions mainly for the menu system. ///////////////////////////////////////////////////////
void mainMenu() // Menu for selecting which mainmenu submenu to show when mainmenu is selected.
{
  menu_show_state = sensors.getPot(); // Shows brightness, LED color, and threshold menus.
}

void brightnessMenu() // Menu for setting brigthness of ledstrip.
{
  menu_show_state = 5000;
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }
  actuators.showInfo("Light brightness:\n" + String(actuators.getLedBrightness()));
  actuators.setLEDBrightness(sensors.potMap(0, 255));

}



void ledColorMenu() // Menu for selecting which ledcolor submenu to show when ledcolor is selected.
{
  menu_show_state = sensors.getPot()+1200; // Shows the red, green, and blue options.
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }

}
void redMenu()  // menu screen for changing green value of led strip.
{
  menu_show_state = 5000;
  actuators.setUserLedColor(sensors.getPot()/4, actuators.getUserLedColor().g, actuators.getUserLedColor().b);
  actuators.showInfo("Red: \n" + String(actuators.getUserLedColor().r));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void greenMenu() // menu screen for changing green value of led strip.
{
  menu_show_state = 5000;
  actuators.setUserLedColor(actuators.getUserLedColor().r, sensors.getPot()/4, actuators.getUserLedColor().b);
  actuators.showInfo("Green: \n" + String(actuators.getUserLedColor().g));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void blueMenu()  // menu screen for changing blue value of led strip.
{
  menu_show_state = 5000;
  actuators.setUserLedColor(actuators.getUserLedColor().r, actuators.getUserLedColor().g, sensors.getPot()/4);
  actuators.showInfo("Blue: \n" + String(actuators.getUserLedColor().b));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 2;
  }
}

void thresholdMenu() // Menu for selecting which threshold submenu to show when thresholdmenu was selected.
// This menu controls the settings for when the sound is above the safe threshold, like the blinkspeed, color and how loud the room has to be to activate the blink.
{
  menu_show_state = sensors.getPot()+2*1200; // Shows the blink speed, blink color, and sound threshold options.
  if (sensors.getBackButtonState())
  {
    current_menu_state = 0;
  }
}

void blinkSpeed() // Menu for setting the blink speed when room is loud.
{
  menu_show_state = 5000;
  actuators.showInfo("Interval time: \n" + String(sensors.potMap(100, 1000)));
  time_interval = sensors.potMap(100, 1000);
  if (sensors.getBackButtonState())
  {
    current_menu_state = 3;
  }
}

void blinkColor() // Menu for setting the led color when room is loud
{
  menu_show_state = 5000;
  actuators.showInfo("Blink color: \nRed(0), Green(1), Blue(2)\n" + String(sensors.potMap(0, 2)));
  actuators.setBlinkColor(255*(sensors.potMap(0, 2) == 0), 255*(sensors.potMap(0, 2) == 1), 255*(sensors.potMap(0, 2) == 2)); // If ex. potMap == 2, then it becomes 255*1, 255*0 and 255*0. Thus the color will be decided by the potMap value

  if (sensors.getBackButtonState())
  {
    current_menu_state = 3;
  }
}

void soundMaxThreshold() // // Menu for setting the max volume before the room is too loud.
{
  menu_show_state = 5000;
  actuators.showInfo("Safe vol.Thr: \n" + String(sensors.potMap(100, 200)));
  sensors.setVolumeMaxThreshold(sensors.potMap(100, 200));
  if (sensors.getBackButtonState())
  {
    current_menu_state = 3;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
