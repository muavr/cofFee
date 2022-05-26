#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>
#include "model.h"

class MachineState;
class InitialState;
class Viewer;

class StateMachine
{
private:
    InitialState *initialState;
    MachineState *state;
    Viewer *viewers[3];
    Model model;
    short registered;

public:
    StateMachine();
    MachineState *getInitialState();

    void setState(MachineState *state);
    void setOutput(const char *output);
    void setNUID(byte *buffer, byte bufferSize);
    void initModel();
    void registerViewer(Viewer *viewer);
    void update();

    void clickEnc();
    void turnEncRight();
    void turnEncLeft();
    void turnPressedEncRight();
    void turnPressedEncLeft();
    void readRFID(byte *buffer, byte size);
    void readEncPressedRFID(byte *buffer, byte size);
};

#endif