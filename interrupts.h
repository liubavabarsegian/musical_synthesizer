#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <Arduino.h>

extern volatile bool piano_flag;

#define PIANO_PIN 2
#define VIOLIN_PIN 3

void setup_interrupts();
void set_piano_flag();
void clear_piano_flag();

#endif
