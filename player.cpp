#include "player.h"

SoftwareSerial mySerial(10, 11); // RX, TX для DFPlayer
DFRobotDFPlayerMini myDFPlayer;
int last_played_track = -1;
bool button_pressed = false;

void setup_player() {
    Serial.begin(9600);
    mySerial.begin(9600);
    myDFPlayer.begin(mySerial);

    myDFPlayer.volume(VOLUME);
}

void stop_playing() {
    myDFPlayer.stop();
    last_played_track = -1;
    Serial.println("Воспроизведение остановлено");
}

void play_track(int row, int col) {
    int track_number = get_track_number(row, col);

    if (track_number != last_played_track) {
        myDFPlayer.stop();
        delay(DEBOUNCE_DELAY);
        myDFPlayer.play(track_number);
        last_played_track = track_number;

        log_key_pressed(row, col, track_number);
    }
    button_pressed = true;
}

void log_key_pressed(int row, int col, int track_number) {
    Serial.println("Клавиша нажата: Строка " + String(row) + ", Столбец " + String(col) + ", Трек " + String(track_number));
}

int get_track_number(int row, int col) {
    return (piano_flag ? 0 : 25) + row * 5 + col + 1;
}
