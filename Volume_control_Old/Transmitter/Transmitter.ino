
#include <SPI.h>

#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(9, 10);

const byte address[6] = "AABBA";

void setup() 
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() 
{
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
