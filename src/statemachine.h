#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>
#include "model.h"

#define MAX_VIEWERS 3
#define MAX_NICK_LENGTH 14
#define MAX_USERS 30
#define MAX_KEY_LENGTH 8

class MachineState;
class InitialState;
class Viewer;

struct Person
{
    uint8_t nuid[MAX_KEY_LENGTH] = {0};
    uint16_t cups;
    uint16_t totalCups;
    uint16_t sum;
    char nick[MAX_NICK_LENGTH];
};

class Storage
{
public:
    uint16_t price;
    uint8_t registered;
    uint8_t states[MAX_USERS];
    Person tmpUser;
    Person users[MAX_USERS];
    Person *searchUser(uint8_t nuid[], uint8_t size);
    uint8_t saveUser(uint8_t nuid[], uint8_t nuid_size, char nick[]);

    uint16_t getPrice();
    void setPrice(uint16_t _price);
};

class StateMachine
{
private:
    MachineState *initialState;
    MachineState *usrActionWaitingState;
    MachineState *priceEnteringState;
    MachineState *state;
    Viewer *viewers[MAX_VIEWERS];
    Model model;

public:
    StateMachine();

    uint8_t getStateCode();
    MachineState *getState();

    // storage
    Storage storage;
    Storage *getStorage();
    void loadStorage();

    // states
    MachineState *getInitialState();
    MachineState *getUsrActionWaitingState();
    MachineState *getPriceEnteringState();
    void setState(MachineState *state);

    // observe state
    void update();
    void registerViewer(Viewer *viewer);

    // actions
    void clickEnc();
    void turnEncRight();
    void turnEncLeft();
    void turnPressedEncRight();
    void turnPressedEncLeft();
    void singleClickEnc();
    void doubleClickEnc();
    void tripleClickEnc();
    void quadrupleClickEnc();
    void readRFID(uint8_t *nuid, uint8_t size);
    void readEncPressedRFID(byte *buffer, byte size);

    // deprecated methods and fields
    short registered;
    void setOutput(const char *output);
    void initModel();
    void setNUID(byte *buffer, byte bufferSize);
};

#endif