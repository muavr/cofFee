#ifndef STATE_INITIAL_H
#define STATE_INITIAL_H

#include "state.h"
#include "statemachine.h"

class InitialState : public MachineState
{
public:
    InitialState(StateMachine *sm);
    void readRFID(byte *buffer, byte size);
    void readEncPressedRFID(byte *buffer, byte size);
};

#endif