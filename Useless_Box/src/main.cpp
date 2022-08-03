#include <Arduino.h>
#include "Actions.h"

int SWITCH_PIN = 4;

int action = 1;

void setup() 
{
  pinMode(SWITCH_PIN,INPUT);
  servoSetup();
}

void loop() 
{
  if (digitalRead(SWITCH_PIN) == LOW)
  {
    switch (action)
    {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
    case 5:
      action5();
      break;
    case 6:
      action6();
      break;
    case 7:
      action7();
      break;
    case 8:
      action2();
      break;
    default:
      break;
    }

    action++;
    if (action > 8)
      action = 1;
  }
}

