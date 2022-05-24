#ifndef VIEWER_H
#define VIEWER_H

#include "model.h"

class Viewer
{
public:
    Viewer();
    virtual ~Viewer() = default;
    virtual void update(Model model);
};

#endif