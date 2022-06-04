#ifndef LED_VIEWER_H
#define LED_VIEWER_H

#include "viewer.h"
#include "globals.h"
#include "statemachine.h"

class LedViewer : public Viewer
{
private:
    uint8_t states[MAX_VIEWER_LEDS] = {0};
    uint8_t pins[MAX_VIEWER_LEDS] = {0};
    uint8_t registeredCount = 0;

public:
    LedViewer(StateMachine *_sm);
    ~LedViewer() = default;
    void setLed(uint8_t _pin, uint8_t _code);
    void unsetLed(uint8_t _code);
    void turnOffLeds();
    void turnOnLed(uint8_t ledNumber);
    void update();
};

#endif