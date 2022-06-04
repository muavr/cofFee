#include <Arduino.h>
#include "state.h"

MachineState::MachineState(StateMachine *_sm) : sm(_sm) {}

uint8_t MachineState::getCode()
{
    return code;
}

void MachineState::clickEnc()
{
    sm->setOutput("Click");
}

void MachineState::turnEnc()
{
    sm->setOutput("Turn");
}

void MachineState::turnPressedEnc()
{
    sm->setOutput("Turn pressed");
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

void MachineState::singleClickEnc()
{
    sm->setOutput("Single click");
}

void MachineState::doubleClickEnc()
{
    sm->setOutput("Double click");
}

void MachineState::tripleClickEnc()
{
    sm->setOutput("Triple click");
}

void MachineState::quadrupleClickEnc()
{
    sm->setOutput("Quadruple click");
}

void MachineState::readRFID(uint8_t *nuid, uint8_t size)
{
    sm->setOutput("Read RFID");
}

void MachineState::readEncPressedRFID(byte *buffer, byte size)
{
    sm->setOutput("Read RFID with pressed encoder");
}
