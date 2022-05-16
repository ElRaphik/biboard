//
// Created by asdch on 16/05/2022.
//

#include "pong/Screen.h"
#include <Arduino.h>

void Screen::writeScores(int leftScore, int rightScore) {
    matrix.fillScreen(matrix.Color333(0,0,0));
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color333(7, 7, 7));
    matrix.setCursor(4,4);
    matrix.print(leftScore);
    matrix.setCursor(12, 4);
    matrix.print(rightScore);
    matrix.setCursor(0,0);
    delay(2000);
    matrix.fillScreen(matrix.Color333(0,0,0));
}
