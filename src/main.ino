
#include <EncButton.h>
#include "globals.h"
#include "serialviewer.h"
#include "statemachine.h"

EncButton<EB_TICK, ENC_S1_PIN, ENC_S2_PIN, ENC_KEY_PIN> enc;

StateMachine *sm = new StateMachine();

void setup()
{
  sm->registerViewer(new SerialViewer());
  Serial.begin(9600);
}

void loop()
{
  enc.tick();

  if (enc.right())
  {
    sm->turnEncRight();
  }
  if (enc.left())
  {
    sm->turnEncLeft();
  }
}