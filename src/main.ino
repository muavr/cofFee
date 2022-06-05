#include <SPI.h>
#include <MFRC522.h>
#include <EncButton.h>
#include "globals.h"
#include "serial_viewer.h"
#include "statemachine.h"
#include "state.h"
#include "led_viewer.h"

MFRC522 rfid(SS_PIN, RST_PIN);

EncButton<EB_TICK, ENC_S1_PIN, ENC_S2_PIN, ENC_KEY_PIN> enc;

StateMachine *sm = new StateMachine();

MachineState *currentState;
MachineState *desiredState;

bool encPressed = false;

volatile uint32_t startTime = millis();

void setup()
{

  LedViewer *ledViewer = new LedViewer(sm);
  ledViewer->setLed(LED_INITIAL, STATE_INITIAL);
  ledViewer->setLed(LED_USR_ACTION_WAITING, STATE_USR_ACTION_WAITING);
  
  sm->registerViewer(new SerialViewer(sm));
  sm->registerViewer(ledViewer);
  sm->update();

  SPI.begin();
  rfid.PCD_Init();

  attachInterrupt(0, isr, CHANGE);
  attachInterrupt(1, isr, CHANGE);

  sm->setState(sm->getUsrActionWaitingState());
}

void loop()
{
  currentState = sm->getState();
  desiredState = sm->getUsrActionWaitingState();
  if (millis() - startTime > RESET_TIMEOUT && currentState->getCode() != desiredState->getCode())
  {
    sm->setState(sm->getUsrActionWaitingState());
    return;
  }

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
    if (enc.rightH())
    {
      sm->turnPressedEncRight();
      return;
    }
    if (enc.leftH())
    {
      sm->turnPressedEncLeft();
      return;
    }
    if (enc.press())
    {
      encPressed = true;
    }
    enc.resetState();
    resetIdleTimeout();
  }

  // following button events value is not returned by tick()
  // so it has to be checked outside condition scope if (tick()) {...}
  if (enc.hasClicks(CLICK_SINGLE))
  {
    sm->singleClickEnc();
    return;
  }
  if (enc.hasClicks(CLICK_DOUBLE))
  {
    sm->doubleClickEnc();
    return;
  }
  if (enc.hasClicks(CLICK_TRIPLE))
  {
    sm->tripleClickEnc();
    return;
  }
  if (enc.hasClicks(CLICK_QUADRUPLE))
  {
    sm->quadrupleClickEnc();
    return;
  }
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
    resetIdleTimeout();
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void resetIdleTimeout()
{
  startTime = millis();
}

void isr()
{
  enc.tickISR();
  resetIdleTimeout();
}
