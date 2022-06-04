#ifndef MODEL_H
#define MODEL_H

#include <Arduino.h>

struct Model
{
    uint8_t stateCode;
    char* output;
    byte nuid[4];
};

#endif