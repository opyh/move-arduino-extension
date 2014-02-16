#include "Wire_new.h"

#define BUFFER_SIZE 8
static volatile unsigned char lastInstruction = 0xff;
static unsigned char i2c_buffer[BUFFER_SIZE];

void setup()
{
  delay(3000);
  WireSpecialEdition.begin(0x50);
  WireSpecialEdition.onReceive(readFromMaster);
  WireSpecialEdition.onRequest(transmitToMaster);
}


void loop()
{

}

void writeInitializationSequence() {
    byte initializationData [256] = {
      0x80, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0xA0, 0x02, 0x01, 0x01, 0x02, 0xA0, 0x03, 0x01, 0x01, 0x04, 0xA0, 0x04, 0x01, 0x01, 0x03, 0xA0,
      0x05, 0x01, 0x01, 0x05, 0xA0, 0x06, 0x01, 0x01, 0x01, 0xA0, 0x07, 0x01, 0x04, 0x2B, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    WireSpecialEdition.write(initializationData, 256);
}


void readFromMaster(int numBytes)
{
  lastInstruction = WireSpecialEdition.read();
}


void transmitToMaster()
{
  switch (lastInstruction) {
    case 0: writeInitializationSequence(); break;
    case 2: WireSpecialEdition.write((uint8_t) 0); break;
    case 3: WireSpecialEdition.write((uint8_t) 0); break;
    case 4: WireSpecialEdition.write((uint8_t) 0); break;
    case 5: WireSpecialEdition.write((uint8_t) 0); break;
    case 6: WireSpecialEdition.write((uint8_t) 0x10); break;
    case 7: WireSpecialEdition.write((uint8_t) 0); break;
  }
}
