//
// Created by asdch on 16/05/2022.
//

#include "PongBar.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

PongBar::PongBar(int x, int y, RGBmatrixPanel& matrix) : GameObject(x, y, x, y, 1, 3, matrix){}

void PongBar::move(int, int yForce) {
    if(y + yForce < 0) {
        y=0;
        return;
    } // set x to 0 to stay in bounds
    if(y + height + yForce > 16) {
        y = 16-height;
        return;
    } // set x to 16-height
    y+=yForce;
}

void PongBar::print() {
    if(y == oldY) return;
    matrix.fillRect(x, oldY, width, height, matrix.Color333(0, 0, 0));
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
    oldY=y;
}

void PongBar::spawn(){
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
}

//PongBar::PongBar(PongBar& pongBar){
//    x = pongBar.x;
//    y = pongBar.y;
//    oldX = pongBar.oldX;
//    oldY = pongBar.oldY;
//    width = pongBar.width;
//    height = pongBar.height;
//    matrix = pongBar.matrix;
//}

PongBar::PongBar(GameObject& gameObject) : GameObject(gameObject){}
