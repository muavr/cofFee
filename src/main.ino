#include <SPI.h>
#include <MFRC522.h>
#include <EncButton.h>
#include "globals.h"
#include "serialviewer.h"
#include "statemachine.h"

MFRC522 rfid(SS_PIN, RST_PIN);

EncButton<EB_TICK, ENC_S1_PIN, ENC_S2_PIN, ENC_KEY_PIN> enc;

StateMachine *sm = new StateMachine();

bool encPressed = false;

void setup()
{
  sm->registerViewer(new SerialViewer());

  SPI.begin();
  rfid.PCD_Init();

  attachInterrupt(0, isr, CHANGE);
  attachInterrupt(1, isr, CHANGE);
}

void loop()
{
  if (enc.tick())
  {
    if (enc.right())
    {
      sm->turnEncRight();
      return;
    }
    if (enc.left())
    {
      sm->turnEncLeft();
      return;
    }
    if (enc.press())
    {
      encPressed = true;
    }
    enc.resetState();
  }

  // release event value is not returned by tick()
  // so it has to be checked outside condition scope if (tick()) {...}
  if (enc.release())
  {
    encPressed = false;
  }

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial())
  {
    if (encPressed)
    {
      sm->readEncPressedRFID(rfid.uid.uidByte, rfid.uid.size);
    }
    else
    {
      sm->readRFID(rfid.uid.uidByte, rfid.uid.size);
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void isr()
{
  enc.tickISR();
}