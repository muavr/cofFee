#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define MAX_PERSONS 30

// encoder pins
#define ENC_KEY_PIN 4
#define ENC_S1_PIN 3
#define ENC_S2_PIN 2

// rfid pins
#define SS_PIN 10
#define RST_PIN 9

// beeper pin
#define BEEPER_PIN 1

#define RESET_TIMEOUT 15000

const char ALPHABET_LOW[] PROGMEM = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                     'u', 'v', 'w', 'x', 'w', 'z', '1', '2', '3', '4',
                                     '5', '6', '7', '8', '9', '0', '_'};

const char ALPHABET_UP[] PROGMEM = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                    'U', 'V', 'W', 'X', 'W', 'Z'};

#define CLICK_SINGLE 1
#define CLICK_DOUBLE 2
#define CLICK_TRIPLE 3
#define CLICK_QUADRUPLE 4

#define STATE_INITIAL 0
#define STATE_COAST_ENTERING 1
#define STATE_USR_ACTION_WAITING 2
#define STATE_USR_COUNTER_RESET 3
#define STATE_USR_NAME_ENTERING 4
#define STATE_USR_REMOVING 5

#define LED_INITIAL A0
#define LED_COAST_ENTERING A1
#define LED_USR_ACTION_WAITING A2
#define LED_USR_COUNTER_RESET A3
#define LED_USR_NAME_ENTERING A4
#define LED_USR_REMOVING A5

#define MAX_VIEWER_LEDS 6
#define MAX_PRICE 100

#endif
