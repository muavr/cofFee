#include "serial_viewer.h"

SerialViewer::SerialViewer(StateMachine *_sm) : Viewer(_sm)
{
    Serial.begin(9600);
}

void SerialViewer::update()
{
    Serial.print("STATE: ");
    Serial.println(sm->getStateCode());
}

void SerialViewer::printDec(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
   Serial.println("");
}