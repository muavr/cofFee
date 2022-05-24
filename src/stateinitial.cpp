#include <Arduino.h>
#include "stateinitial.h"

InitialState::InitialState(StateMachine *sm) : MachineState(sm)
{
}

void InitialState::turnEncRight()
{
    sm->setOutput("Turn to the right.");
};

void InitialState::turnEncLeft()
{
    sm->setOutput("Turn to the left.");
};