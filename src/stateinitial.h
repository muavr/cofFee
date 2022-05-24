#ifndef STATE_INITIAL_H
#define STATE_INITIAL_H

#include "state.h"
#include "statemachine.h"

class InitialState : public MachineState
{
public:
    InitialState(StateMachine *sm);
    void turnEncRight();
    void turnEncLeft();
};

#endif