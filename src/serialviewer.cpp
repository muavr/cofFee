#include "serialviewer.h"

SerialViewer::SerialViewer() : Viewer()
{
    Serial.begin(9600);
}

void SerialViewer::update(Model model)
{
    Serial.print("OUTPUT: ");
    Serial.println(model.output);
    Serial.print("NUID: ");
    printDec(model.nuid, sizeof(model.nuid));
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