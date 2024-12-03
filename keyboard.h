#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>

#define ROWS_COUNT 5
#define COLS_COUNT 5

extern const int ROW_PINS[];
extern const int COL_PINS[];

void setup_keyboard();
void go_over_keyboard();
bool no_buttons_pressed();
void activate_row(int row);
void deactivate_row(int row);
bool key_pressed(int col);

#endif
