#include "player.h"
#include "keyboard.h"
#include "interrupts.h"

void setup() {
    setup_player();
    setup_keyboard();
    setup_interrupts();

    Serial.println("Синтезатор готов! Нажмите кнопку, чтобы воспроизвести ноту.");
}

void loop() {
    button_pressed = false;
    go_over_keyboard();

    if (no_buttons_pressed()) {
        stop_playing();
    }
}
