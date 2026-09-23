#include "main.h"
void mainMenu();
void brightnessMenu();
void thresholdMenu();
void ledColorMenu();


void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  unsigned long current_time = millis();

  time_interval = analogRead(POT_PIN)/2 + 50;
  switch (menu_state)
  {
    case 0:
      break;
    
    case 1:
      break;

    case 2:
      break;
    
    case 3:
      break;
    
  }
  if (current_time - previous_time > time_interval)
  {
    previous_time = current_time;
    
  }
  
  
  
}

// put function definitions here:
