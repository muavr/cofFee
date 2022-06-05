#ifndef PRICE_ENTERING_STATE_H
#define PRICE_ENTERING_STATE_H

#include "state.h"
#include "statemachine.h"

class PriceEnteringState : public MachineState
{
private:
    void increasePrice(uint8_t step);
    void decreasePrice(uint8_t step);

public:
    PriceEnteringState(StateMachine *_sm);

    void singleClickEnc();
    void turnEncRight();
    void turnEncLeft();
    void turnPressedEncRight();
    void turnPressedEncLeft();
};

#endif