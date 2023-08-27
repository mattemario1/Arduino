#include <Arduino.h>
#include <Servo.h>
#include <IRremote.hpp>

#define IR_SEND_PIN 3

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_SEND_PIN); // Start with IR_SEND_PIN as send pin and enable feedback LED at default feedback LED pin
  
  // infos for receive
  Serial.print(RECORD_GAP_MICROS);
  Serial.println(F(" us is the (minimum) gap, after which the start of a new IR packet is assumed"));
  Serial.print(MARK_EXCESS_MICROS);
  Serial.println(F(" us are subtracted from all marks and added to all spaces for decoding"));
}


void receive_ir_data() {
  if (IrReceiver.decode()) {
    Serial.print(F("Decoded protocol: "));
    Serial.print(getProtocolString(IrReceiver.decodedIRData.protocol));
    Serial.print(F(", decoded raw data: "));
    Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.print(F(", decoded address: "));
    Serial.print(IrReceiver.decodedIRData.address, HEX);
    Serial.print(F(", decoded command: "));
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume();
  }
}

uint16_t sAddress = 0x0102;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 1;

void loop() {
  /*
    * Print loop values
    */
  // Serial.println();
  // Serial.print(F("address=0x"));
  // Serial.print(sAddress, HEX);
  // Serial.print(F(" command=0x"));
  // Serial.print(sCommand, HEX);
  // Serial.print(F(" repeats="));
  // Serial.println(sRepeats);
  // Serial.flush();

  receive_ir_data();

  // delay(1000);
}
