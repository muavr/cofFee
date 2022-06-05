#include "globals.h"
#include "state_waiting.h"
#include "statemachine.h"

WaitingState::WaitingState(StateMachine *_sm) : MachineState(_sm)
{
    code = STATE_USR_ACTION_WAITING;
}

void WaitingState::tripleClickEnc()
{
    sm->setState(sm->getPriceEnteringState());
}
