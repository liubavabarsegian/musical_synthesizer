#include "interrupts.h"

volatile bool piano_flag = true;

void setup_interrupts() {
    pinMode(PIANO_PIN, INPUT_PULLUP);
    pinMode(VIOLIN_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(PIANO_PIN), set_piano_flag, FALLING);
    attachInterrupt(digitalPinToInterrupt(VIOLIN_PIN), clear_piano_flag, FALLING);
}

void set_piano_flag() {
    piano_flag = true;
}

void clear_piano_flag() {
    piano_flag = false;
}
