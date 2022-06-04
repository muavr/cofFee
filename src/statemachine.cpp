#include "statemachine.h"
#include <Arduino.h>
#include "state.h"
#include "state_initial.h"
#include "waiting_state.h"
#include "viewer.h"

Person *Storage::searchUser(uint8_t *nuid, uint8_t size)
{
  for (int8_t i = 0; i < min(registered, MAX_USERS); ++i)
  {
    for (uint8_t j = 0; j < min(8, size); ++j)
    {
      if (nuid[j] != users[i].nuid[j])
        return NULL;
    }
    return &users[i];
  }
}

StateMachine::StateMachine()
{
  registered = 0;
  initialState = new InitialState(this);
  usrActionWaitingState = new WaitingState(this);
  setState(initialState);
  initModel();
  loadStorage();
}

void StateMachine::loadStorage()
{
  storage.price = 0;
  storage.registered = 0;
}

void StateMachine::setOutput(const char *str)
{
  free(model.output);
  model.output = (char *)malloc(strlen(str) * sizeof(char) + 1);

  if (model.output != NULL)
  {
    strcpy(model.output, str);
  }
}

void StateMachine::setNUID(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    model.nuid[i] = 0;
  }

  for (byte i = 0; i < min(bufferSize, sizeof(model.nuid)); i++)
  {
    model.nuid[i] = buffer[i];
  }
}

void StateMachine::initModel()
{
  model.output = (char *)malloc(sizeof(char));
  strcpy(model.output, "");
}

void StateMachine::turnEncRight()
{
  state->turnEncRight();
}

void StateMachine::turnEncLeft()
{
  state->turnEncLeft();
}

void StateMachine::turnPressedEncRight()
{
  state->turnPressedEncRight();
}

void StateMachine::turnPressedEncLeft()
{
  state->turnPressedEncLeft();
  
}

void StateMachine::singleClickEnc()
{
    state->singleClickEnc();
}

void StateMachine::doubleClickEnc()
{
    state->doubleClickEnc();
}

void StateMachine::tripleClickEnc()
{
    state->tripleClickEnc();
}

void StateMachine::quadrupleClickEnc()
{
    state->quadrupleClickEnc();
}

void StateMachine::readRFID(uint8_t *nuid, uint8_t size)
{
  state->readRFID(nuid, size);
}

void StateMachine::readEncPressedRFID(byte *buffer, byte size)
{
  state->readEncPressedRFID(buffer, size);
}

void StateMachine::setState(MachineState *_state)
{
  state = _state;
  update();
}

MachineState *StateMachine::getState()
{
  return state;
}

MachineState *StateMachine::getInitialState()
{
  return initialState;
}

MachineState *StateMachine::getUsrActionWaitingState()
{
  return usrActionWaitingState;
}

void StateMachine::registerViewer(Viewer *viewer)
{
  if (this->registered < 3)
  {
    viewers[registered] = viewer;
    registered++;
  }
}

void StateMachine::update()
{
  for (int i = 0; i < registered; ++i)
  {
    Viewer *viewer = viewers[i];
    if (viewer != NULL)
    {
      viewer->update();
    }
  }
}

uint8_t StateMachine::getStateCode()
{
  return state->getCode();
}
