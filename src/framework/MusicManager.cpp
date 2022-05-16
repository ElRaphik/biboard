#include "../../include/framework/MusicManager.h"

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
/*
  Tetris theme - (Korobeiniki)
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs
                                              Robson Couto, 2019
*/
int tetris[] = {
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

MusicManager::MusicManager(RGBmatrixPanel& m) : GameObject(m), notes() {
    melody = new int[197];
    for (int i = 0; i < 197; ++i) {
        melody[i] = tetris[i];
    }
    notes = 197/sizeof(melody[0])/2;
}

MusicManager::~MusicManager() {
    delete melody;
}

void MusicManager::awake() {
}

void MusicManager::update() {
    if (thisNote < notes * 2) {
        playNote(thisNote);
    } else {
        playNote(thisNote = 0);
    }
    thisNote += 2;
}

void MusicManager::render() {
}

void MusicManager::playNote(int i) {
    // calculates the duration of each note
    divider = melody[i + 1];
    if (divider > 0) {
        // regular note, just proceed
        noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
        // dotted notes are represented with negative durations!!
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[i], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
}
