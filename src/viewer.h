#ifndef VIEWER_H
#define VIEWER_H

#include "statemachine.h"

class Viewer
{
public:
    Viewer(StateMachine *_sm);
    virtual ~Viewer() = default;
    virtual void update();

protected:
    StateMachine *sm;
};

#endif