#ifndef WAITING_STATE_H
#define WAITING_STATE_H

#include "state.h"
#include "statemachine.h"

class WaitingState : public MachineState
{
public:
    WaitingState(StateMachine *_sm);
};

#endif