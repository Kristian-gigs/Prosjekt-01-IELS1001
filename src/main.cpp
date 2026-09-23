#include "main.h"

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  unsigned long current_time = millis();

  time_interval = analogRead(POT_PIN)/2 + 50;
  switch (menu_state)
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

}

void brightnessMenu()
{

}

void ledColorMenu()
{

}

void thresholdMenu()
{

}