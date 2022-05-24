#include <Arduino.h>
#include "serialviewer.h"

SerialViewer::SerialViewer() : Viewer() {}

void SerialViewer::update(Model model)
{
    Serial.println(model.output);
}