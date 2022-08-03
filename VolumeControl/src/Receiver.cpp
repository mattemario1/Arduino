#include <Arduino.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include "Servo.h"

	RF24 radio(9, 10); // CE, CSN
	const byte addresses[][6] = {"00001", "00002"};
	Servo myServo;
void setup() {
	Serial.begin(9600);

	myServo.attach(5);
	radio.begin();
	radio.openWritingPipe(addresses[0]); // 00001
	radio.openReadingPipe(1, addresses[1]); // 00002
	radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      int angleV = 0;
      radio.read(&angleV, sizeof(angleV));
      myServo.write(angleV);
      Serial.println(angleV);
    }
    delay(5);
    radio.stopListening();
  }
}