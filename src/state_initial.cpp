#include "state_initial.h"
#include "statemachine.h"
#include "globals.h"

InitialState::InitialState(StateMachine *_sm) : MachineState(_sm)
{
    code = STATE_INITIAL;
}