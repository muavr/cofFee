#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

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
    void registerViewer(Viewer *viewer);
    void update(Model model);

    void clickEnc();
    void turnEncRight();
    void turnEncLeft();
    void turnPressedEncRight();
    void turnPressedEncLeft();
    void readRFID();
    void readEncPressedRFID();
};

#endif