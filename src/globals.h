#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define MAX_PERSONS 30

// encoder pins
#define ENC_S1_PIN 4
#define ENC_S2_PIN 3
#define ENC_KEY_PIN 2

#define BTN_MODE_PIN 4
#define BTN_PERSON_PIN 9

// led panel pins
#define LED_LISTENING_PIN A1
#define LED_REGISTRATION_PIN A2
#define LED_EDITING_PIN A3
#define LED_ZEROING_PIN A4
#define LED_REMOVING_PIN A5

// beeper pin
#define BEEPER_PIN 1

const char ALPHABET_LOW[37] PROGMEM = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                       'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                       'u', 'v', 'w', 'x', 'w', 'z','1', '2', '3', '4',
                                       '5', '6', '7', '8', '9', '0', '_', };

const char ALPHABET_UP[] PROGMEM = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                    'U', 'V', 'W', 'X', 'W', 'Z'};


#endif

