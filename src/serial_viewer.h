#ifndef SERIAL_VIEWER_H
#define SERIAL_VIEWER_H

#include "viewer.h"
#include "statemachine.h"


class SerialViewer : public Viewer
{
private:
    void printDec(byte *buffer, byte bufferSize);

public:
    SerialViewer(StateMachine *sm);
    virtual ~SerialViewer() = default;
    virtual void update();
};

#endif
