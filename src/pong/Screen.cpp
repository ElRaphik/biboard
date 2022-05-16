//
// Created by asdch on 16/05/2022.
//

#include "pong/Screen.h"
#include <Arduino.h>

void Screen::writeScores(int leftScore, int rightScore) {
    matrix.fillScreen(matrix.Color333(0,0,0));
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color333(7, 7, 7));
    matrix.setCursor(1,4);
    matrix.print(leftScore);
    matrix.print(" ");
    matrix.print(rightScore);
    matrix.setCursor(0,0);
    delay(2000);
    matrix.fillScreen(matrix.Color333(0,0,0));
}

void Screen::writeWinner(bool left) {
    matrix.fillScreen(matrix.Color333(0,0,0));
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color333(7,7,7));
    if(left) {
        matrix.setCursor(matrix.width()/10, 0);
        matrix.print('L');
        matrix.print('E');
        matrix.print('F');
        matrix.print('T');
    } else {
        matrix.setCursor(0, 0);
        matrix.print('R');
        matrix.print('I');
        matrix.print('G');
        matrix.print('H');
        matrix.print('T');
    }
    matrix.setCursor(matrix.width()/8, 9);
    matrix.print('W');
    matrix.print('O');
    matrix.print('N');
    delay(5000);
    resetFunc();
}
