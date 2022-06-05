#include "led_viewer.h"

LedViewer::LedViewer(StateMachine *_sm) : Viewer(_sm)
{
  registeredCount = 0;
}

void LedViewer::update()
{
  turnOffLeds();
  turnOnLed(sm->getStateCode());
}

void LedViewer::setLed(uint8_t _pin, uint8_t _code)
{
  if (_code < MAX_VIEWER_LEDS && states[_code] == 0)
  {
    pins[_code] = _pin;
    states[_code] = 1;
    pinMode(_pin, OUTPUT);
    registeredCount++;
  }
}

void LedViewer::unsetLed(uint8_t _code)
{
  if (_code < MAX_VIEWER_LEDS && states[_code] == 1)
  {
    pins[_code] = 0;
    states[_code] = 0;
    registeredCount--;
  }
}

void LedViewer::turnOffLeds()
{
  for (uint8_t i = 0; i < MAX_VIEWER_LEDS; ++i)
  {
    if (states[i] == 1)
    {
      digitalWrite(pins[i], LOW);
    }
  }
}

void LedViewer::turnOnLed(uint8_t ledNumber)
{
  if (ledNumber < MAX_VIEWER_LEDS and states[ledNumber] == 1)
  {
    digitalWrite(pins[ledNumber], HIGH);
  }
}
