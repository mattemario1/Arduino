#include <Arduino.h>
#include <Servo.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3

void setup() {
  pinMode(IR_RECEIVE_PIN, OUTPUT);
  Serial.begin(115200);

  // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
  IrSender.begin(IR_RECEIVE_PIN);

  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
}

uint16_t sAddress = 0x0102;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 1;

/*
 * Send NEC IR protocol
 */
void send_ir_data() {
  // clip repeats at 4
  if (sRepeats > 4) {
      sRepeats = 4;
  }
  uint8_t rawData[] = { 25,8, 25,9, 8,26, 8,25, 9,25, 8,26, 8,25, 9,25, 8,26, 24,9, 8,25, 9};
    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    // IrSender.sendNEC(sAddress, sCommand, sRepeats);

  IrSender.sendRaw(rawData, sizeof(rawData), NEC_KHZ);
}

void loop() {
  send_ir_data();
  IrReceiver.restartAfterSend(); // Is a NOP if sending does not require a timer.
  
  // Prepare data for next loop
  // sAddress += 0x0101;
  sCommand += 0x11;
  sRepeats++;

  delay(2000); // Loop delay
}
