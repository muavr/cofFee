#include "serial_viewer.h"

SerialViewer::SerialViewer(StateMachine *_sm) : Viewer(_sm)
{
    Serial.begin(9600);
}

void SerialViewer::update()
{
    Serial.println("");
    Serial.println("---------------------");
    Serial.print("STATE: ");
    Serial.println(sm->getStateCode());
    Serial.print("PRICE: ");
    Serial.println(sm->getStorage()->getPrice());
    Serial.println("---------------------");
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