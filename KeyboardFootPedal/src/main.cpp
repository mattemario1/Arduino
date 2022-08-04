#include <Arduino.h>

const int F = 2;
const int G = 3;
const int H = 4;
const int J = 5;

void setup() {
	pinMode(F, INPUT);
	pinMode(G, INPUT);
	pinMode(H, INPUT);
	pinMode(J, INPUT);

	Serial.begin(9600);
	delay(10);
}

void loop() {
	while (digitalRead(F) == HIGH)
	{
		Serial.println('f');
		delay(300);
	}
	while (digitalRead(G) == HIGH){
		Serial.println('g');
		delay(300);
	}
	while (digitalRead(H) == HIGH){
		Serial.println('h');
		delay(300);
		}
	while (digitalRead(J) == HIGH){
		Serial.println('j');
		delay(300);
	}

}

