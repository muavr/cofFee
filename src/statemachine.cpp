#include "statemachine.h"
#include <Arduino.h>
#include "state.h"
#include "stateinitial.h"
#include "viewer.h"

StateMachine::StateMachine()
{
  registered = 0;
  initialState = new InitialState(this);
  setState(initialState);
  initModel();
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

void StateMachine::readRFID(byte *buffer, byte size)
{
  state->readRFID(buffer, size);
}

void StateMachine::readEncPressedRFID(byte *buffer, byte size)
{
  state->readEncPressedRFID(buffer, size);
}

void StateMachine::setState(MachineState *_state)
{
  state = _state;
}

MachineState *StateMachine::getInitialState()
{
  return initialState;
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
      viewer->update(model);
    }
  }
}
