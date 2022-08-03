#include <Arduino.h>
#include "Actions.h"

Servo armServo;
Servo lidServo;

void servoSetup(){
	armServo.attach(3); // arm servo on pin 3
	lidServo.attach(5); // lid servo on pin 5

	// Servo Starting Position
	armServo.write(50);
	lidServo.write(50);
}


//The Following are actions that are chosen chronologically

void action1() {
  lidServo.write(20);
  delay(1000);
  armServo.write(177);
  delay(500); 
  armServo.write(50);
  delay(1000);
  lidServo.write(90);
  delay(1000);
}

void action2() {
  lidServo.write(50);
  delay(100);
  armServo.write(177);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
}

void action3() {
    for(int servoPos = 90; servoPos > 20; servoPos -=1)
  {
    lidServo.write(servoPos);
    delay(50);
  }
  armServo.write(177);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
}

void action4() {
  delay(250);
  lidServo.write(50);
  delay(100);
  armServo.write(177);
  delay(2500);
for(int servoPos = 177; servoPos > 90; servoPos -=1)
  {
    armServo.write(servoPos);
    delay(50);
  }
  lidServo.write(90);
  armServo.write(50);
}

void action5() {
  lidServo.write(50);
  delay(500);
  lidServo.write(90);
  delay(500);
  lidServo.write(50);
  delay(500);
  lidServo.write(90);
  delay(500);
  lidServo.write(50);
  delay(500);
  lidServo.write(90);
  delay(2500);
  lidServo.write(50);
  delay(100);
  armServo.write(177);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
}

void action6() {
  lidServo.write(50);
  delay(100);
  armServo.write(155);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
  delay(250);
  lidServo.write(50);
  delay(100);
  armServo.write(155);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
  delay(250);
  lidServo.write(50);
  delay(100);
  armServo.write(155);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
  delay(250);  
  lidServo.write(50);
  delay(100);
  armServo.write(177);
  delay(250);
  armServo.write(50);
  delay(100);
  lidServo.write(90);
}

void action7() {
    for(int servoPos = 90; servoPos > 20; servoPos -=2)
  {
    lidServo.write(servoPos);
    delay(50);
  }
for(int servoPos = 50; servoPos < 145; servoPos +=2)
  {
    armServo.write(servoPos);
    delay(100);
  }
  armServo.write(177);
for(int servoPos = 177; servoPos > 50; servoPos -=2)
  {
    armServo.write(servoPos);
    delay(100);
  }
for(int servoPos = 20; servoPos < 90; servoPos +=2)
  {
    lidServo.write(servoPos);
    delay(50);
  }
  lidServo.write(90);
}