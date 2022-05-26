#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H

#include "statemachine.h"

class MachineState
{
protected:
    StateMachine *sm;

public:
    MachineState(StateMachine *sm);
    virtual ~MachineState() = default;
    virtual void clickEnc();
    virtual void turnEncRight();
    virtual void turnEncLeft();
    virtual void turnPressedEncRight();
    virtual void turnPressedEncLeft();
    virtual void readRFID(byte *buffer, byte size);
    virtual void readEncPressedRFID(byte *buffer, byte size);
};

#endif