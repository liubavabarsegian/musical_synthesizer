#ifndef PLAYER_H
#define PLAYER_H

#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"
#include "interrupts.h"

#define DEBOUNCE_DELAY 30
#define VOLUME 70

extern DFRobotDFPlayerMini myDFPlayer;
extern int last_played_track;
extern bool button_pressed;

void setup_player();
void stop_playing();
void play_track(int row, int col);
int get_track_number(int row, int col);
void log_key_pressed(int row, int col, int track_number);

#endif
