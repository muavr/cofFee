#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H

#include "statemachine.h"

class MachineState
{
protected:
    StateMachine *sm;
    uint8_t code;

public:
    MachineState(StateMachine *_sm);
    virtual ~MachineState() = default;
    uint8_t getCode();

    virtual void clickEnc();
    virtual void turnEnc();
    virtual void turnPressedEnc();
    virtual void turnEncRight();
    virtual void turnEncLeft();
    virtual void turnPressedEncRight();
    virtual void turnPressedEncLeft();

    virtual void singleClickEnc();
    virtual void doubleClickEnc();
    virtual void tripleClickEnc();
    virtual void quadrupleClickEnc();

    virtual void readRFID(uint8_t *nuid, uint8_t size);;
    virtual void readEncPressedRFID(byte *buffer, byte size);
};

#endif