#include "state_price_entering.h"
#include "statemachine.h"
#include "globals.h"

PriceEnteringState::PriceEnteringState(StateMachine *_sm) : MachineState(_sm)
{
    code = STATE_COAST_ENTERING;
}

void PriceEnteringState::singleClickEnc()
{
    sm->setState(sm->getUsrActionWaitingState());
}
void PriceEnteringState::turnEncRight()
{
    increasePrice(1);
    
}
void PriceEnteringState::turnEncLeft()
{
    decreasePrice(1);
}

void PriceEnteringState::turnPressedEncRight()
{
    increasePrice(5);
}

void PriceEnteringState::turnPressedEncLeft()
{
    decreasePrice(5);
}

void PriceEnteringState::increasePrice(uint8_t step)
{
    Storage *storage = sm->getStorage();
    uint16_t price = storage->getPrice();
    if (price < MAX_PRICE - step)
    {
        storage->setPrice(price + step);
    }
    else {
        storage->setPrice(MAX_PRICE);
    }
    sm->update();
}

void PriceEnteringState::decreasePrice(uint8_t step)
{
    Storage *storage = sm->getStorage();
    uint16_t price = storage->getPrice();
    if (price > 0 + step)
    {
        storage->setPrice(price - step);
    }
    else {
        storage->setPrice(0);
    }
    sm->update();
}