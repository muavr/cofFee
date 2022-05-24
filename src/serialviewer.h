#ifndef SERIAL_VIEWER_H
#define SERIAL_VIEWER_H

#include "viewer.h"
#include "model.h"

class SerialViewer : public Viewer
{
public:
    SerialViewer();
    virtual ~SerialViewer() = default;
    virtual void update(Model model);
};

#endif