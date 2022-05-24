#include <Arduino.h>
#include "state.h"

MachineState::MachineState(StateMachine *sm) : sm(sm) {}

void MachineState::clickEnc()
{
    sm->setOutput("Click");
}

void MachineState::turnEncRight()
{
    sm->setOutput("Turn right");
}

void MachineState::turnEncLeft()
{
    sm->setOutput("Turn left");
}

void MachineState::turnPressedEncRight()
{
    sm->setOutput("Turn right pressed encoder");
}

void MachineState::turnPressedEncLeft()
{
    sm->setOutput("Turn left pressed encoder");
}

void MachineState::readRFID()
{
    sm->setOutput("Read RFID");
}

void MachineState::readEncPressedRFID()
{
    sm->setOutput("Read RFID with pressed encoder");
}
