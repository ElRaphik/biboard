//
// Created by asdch on 16/05/2022.
//

#include "../include/Ball.h"

Ball::Ball(int x, int y, RGBmatrixPanel &matrix) : GameObject(x, y, x, y, 1, 1, matrix) {
    xForce = 0;
    yForce = 0;
}

void Ball::move(int, int) {
    if (x + xForce < 0 || x + xForce > matrix.width() - 1) xForce = -xForce;
    if (y + yForce < 0 || y + yForce > matrix.height() - 1) yForce = -yForce;
    x += xForce;
    y += yForce;
}

void Ball::print() {
    if (y == oldY && x == oldX) return;
    matrix.fillRect(oldX, oldY, width, height, matrix.Color333(0, 0, 0));
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
    oldX = x;
    oldY = y;
}

void Ball::spawn() {
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
}

void Ball::firstPush(int xFr, int yFr) {
    xForce = xFr;
    yForce = yFr;
}


