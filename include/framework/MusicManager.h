#ifndef PING_MUSICMANAGER_H
#define PING_MUSICMANAGER_H

#include "GameObject.h"

/*
  Tetris theme - (Korobeiniki)
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs

                                              Robson Couto, 2019
*/
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define REST 0

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
        //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
        NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
        NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

        NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
        NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

        NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
        NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

        NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
        NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,


        NOTE_E5,2,  NOTE_C5,2,
        NOTE_D5,2,   NOTE_B4,2,
        NOTE_C5,2,   NOTE_A4,2,
        NOTE_GS4,2,  NOTE_B4,4,  REST,8,
        NOTE_E5,2,   NOTE_C5,2,
        NOTE_D5,2,   NOTE_B4,2,
        NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
        NOTE_GS5,2,

};

class MusicManager : public GameObject {
    // change this to make the song slower or faster
    int tempo=144;

    // change this to whichever pin you want to use
    int buzzer = 11;

    // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
    // there are two values per note (pitch and duration), so for each note there are four bytes
    int notes=sizeof(melody)/sizeof(melody[0])/2;

    // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
    int wholenote = (60000 * 4) / tempo;

    int divider = 0, noteDuration = 0;

    bool isPlaying = false;
public:
    explicit MusicManager(RGBmatrixPanel& m);

public:
    void awake() override;
    void update() override;
    void render() override;
public:
    void move(int x, int y) override {};

    void play();
};


#endif //PING_MUSICMANAGER_H
