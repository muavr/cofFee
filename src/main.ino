#include <SPI.h>
#include <MFRC522.h>
#include <EncButton.h>
#include "globals.h"
#include "serialviewer.h"
#include "statemachine.h"

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

EncButton<EB_TICK, ENC_S1_PIN, ENC_S2_PIN, ENC_KEY_PIN> enc;

StateMachine *sm = new StateMachine();

void setup()
{
  sm->registerViewer(new SerialViewer());
  SPI.begin();     // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
}

bool encHeld = false;

void loop()
{
  enc.tick();

  if (enc.right())
  {
    sm->turnEncRight();
    return;
  }
  else if (enc.left())
  {
    sm->turnEncLeft();
    return;
  }
  else if (enc.held())
  {
    encHeld = true;
    return;
  }
  else if (enc.release())
  {
    encHeld = false;
    return;
  }

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial())
  {
    if (encHeld)
    {
      sm->readEncPressedRFID(rfid.uid.uidByte, rfid.uid.size);
    }
    else
    {
      sm->readRFID(rfid.uid.uidByte, rfid.uid.size);
    }
  }

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}