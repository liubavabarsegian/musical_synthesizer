#include "keyboard.h"
#include "player.h"

const int ROW_PINS[] = {14, 15, 16, 17, 18};
const int COL_PINS[] = {5, 6, 7, 8, 9};

void setup_keyboard() {
    for (int i = 0; i < ROWS_COUNT; i++) {
        pinMode(ROW_PINS[i], OUTPUT);
        digitalWrite(ROW_PINS[i], HIGH);
    }

    for (int i = 0; i < COLS_COUNT; i++) {
        pinMode(COL_PINS[i], INPUT_PULLUP);
    }
}

void go_over_keyboard() {
    for (int row = 0; row < ROWS_COUNT; row++) {
        activate_row(row);

        for (int col = 0; col < COLS_COUNT; col++) {
            if (key_pressed(col)) {
                delay(DEBOUNCE_DELAY);

                if (key_pressed(col)) {
                    play_track(row, col);
                }
            }
        }
        deactivate_row(row);
    }
}

bool no_buttons_pressed() {
    return !button_pressed && last_played_track != -1;
}

void activate_row(int row) {
    digitalWrite(ROW_PINS[row], LOW);
}

void deactivate_row(int row) {
    digitalWrite(ROW_PINS[row], HIGH);
}

bool key_pressed(int col) {
    return digitalRead(COL_PINS[col]) == LOW;
}
