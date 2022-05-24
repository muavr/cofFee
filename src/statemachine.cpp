#include <Arduino.h>

#include "statemachine.h"
#include "state.h"
#include "stateinitial.h"
#include "viewer.h"

StateMachine::StateMachine()
{
  registered = 0;
  initialState = new InitialState(this);
  setState(initialState);
}

void StateMachine::setOutput(const char *str)
{
  free(model.output);
  
  model.output = (char *) malloc(strlen(str) * sizeof(char) + 1);
  strcpy(model.output, str);

  update(model);
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

void StateMachine::readRFID()
{
  state->readRFID();
}

void StateMachine::readEncPressedRFID()
{
  state->readEncPressedRFID();
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

void StateMachine::update(Model model)
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
