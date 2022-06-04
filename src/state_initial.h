#ifndef INITIAL_STATE_H
#define INITIAL_STATE_H

#include "state.h"
#include "statemachine.h"

class InitialState : public MachineState
{
public:
    InitialState(StateMachine *_sm);
};

#endif