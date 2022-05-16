//
// Created by asdch on 16/05/2022.
//

#ifndef PING_SCREEN_H
#define PING_SCREEN_H

#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library


class Screen {

    RGBmatrixPanel matrix;
public:
    explicit Screen(RGBmatrixPanel& matrix) : matrix(matrix){};
    void writeScores(int, int);
    void writeWinner(bool);
    void(* resetFunc) (void) = 0;
};


#endif //PING_SCREEN_H
