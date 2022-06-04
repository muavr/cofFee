#include "globals.h"
#include "waiting_state.h"
#include "statemachine.h"

WaitingState::WaitingState(StateMachine *_sm) : MachineState(_sm)
{
    code = STATE_USR_ACTION_WAITING;
}
