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

void InitialState::readRFID(byte *buffer, byte size)
{
    sm->setOutput("Read RFID.");
    sm->setNUID(buffer, size);
    sm->update();
}

void InitialState::readEncPressedRFID(byte *buffer, byte size)
{
    sm->setOutput("Read RFID with pressed encoder.");
    sm->setNUID(buffer, size);
    sm->update();
}