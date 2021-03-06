#include "pong/Ball.h"

Ball::Ball(int x, int y, RGBmatrixPanel &matrix) : PongGameObject(x, y, x, y, 1, 1, matrix) {
    xForce = 0;
    yForce = 0;
}

void Ball::awake() {
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
    firstPush(1, 1);
}



void Ball::update(const InputManager& manager) {
    move(0, 0);
}

int Ball::update(const InputManager &manager, const PongBar &bar, const PongBar &bar2) {
    int rtr = 0;
    if(isColliding(bar) || isColliding(bar2))
        xForce = - xForce;
    if(x+xForce == 0) rtr=2;
    else if(x+xForce==32) rtr=1;
    update(manager);
    return rtr;
}

void Ball::render() {
    if (y == oldY && x == oldX) return;
    matrix.fillRect(oldX, oldY, width, height, matrix.Color333(0, 0, 0));
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
    oldX = x;
    oldY = y;
}

void Ball::move(int, int) {
    if (x + xForce < 0 || x + xForce > matrix.width() - 1) xForce = -xForce;
    if (y + yForce < 0 || y + yForce > matrix.height() - 1) yForce = -yForce;
    x += xForce;
    y += yForce;
}

//void Ball::update(const InputManager &inputManager) {
//    if (millis() % (ballSpeed / 2) < 2) {
//
//        // if the ball goes offscreen, reverse the direction:
//        if (x > matrix.width() - 1 || x < 0) {
//            ballDirectionX = -ballDirectionX;
//            quicker();
//        }
//
//        if (y > matrix.height() - 1 || y < 0) {
//            ballDirectionY = -ballDirectionY;
//            quicker();
//        }
//
//        // check if the ball and the paddle occupy the same space on screen
//        if (isColliding(*bar)) {
//            ballDirectionY = -ballDirectionY;
//            quicker();
//        }
//
//        // update the ball's position
//        x += ballDirectionX;
//        y += ballDirectionY;
//
//        move(x, y);
//        print();
//    }
//}

// utils

void Ball::firstPush(int xFr, int yFr) {
    xForce = xFr;
    yForce = yFr;
}

void Ball::quicker() {

}

void Ball::reset(bool left) {
    if(left) {
        x = matrix.width()/4;
        xForce=1;
        yForce=-1;
    } else {
        x = 3 * matrix.width()/4;
        xForce=-1;
        yForce=1;
    }
    y = matrix.height()*2/3;
    oldX=x;
    oldY=y;
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
}

//void Ball::quicker() {
//    if (ballSpeed > 20) ballSpeed--;
//}