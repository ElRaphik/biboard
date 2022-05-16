#pragma once
#ifndef PING_MUSICMANAGER_H
#define PING_MUSICMANAGER_H

#include "GameObject.h"

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

class MusicManager : public GameObject {
    // change this to make the song slower or faster
    int tempo=144;

    // change this to whichever pin you want to use
    int buzzer = 3;

    // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
    // there are two values per note (pitch and duration), so for each note there are four bytes
    int notes;

    // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
    int wholenote = (60000 * 4) / tempo;

    int divider = 0, noteDuration = 0;

    int thisNote;

    int* melody;
public:
    explicit MusicManager(RGBmatrixPanel& m);
    ~MusicManager();

public:
    void awake() override;
    void update() override;
    void render() override;
public:
    void move(int x, int y) override {};

    void play();

    void playNote(int i);
};


#endif //PING_MUSICMANAGER_H
