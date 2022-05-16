#include "pong/Ball.h"

Ball::Ball(int x, int y, RGBmatrixPanel &matrix) : PongGameObject(x, y, x, y, 1, 1, matrix) {
    xForce = 1;
    yForce = 1;
}

void Ball::awake() {
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
//    firstPush(1, 1);
}

void Ball::update(const InputManager& manager, const PongBar &bar) {
    if (millis() % (ballSpeed / 2) < 2) {

        // if the ball goes offscreen, reverse the direction:
        if (x > matrix.width() - 1 || x < 0) {
            ballDirectionX = -ballDirectionX;
            quicker();
        }

        if (y > matrix.height() - 1 || y < 0) {
            ballDirectionY = -ballDirectionY;
            quicker();
        }

        // check if the ball and the paddle occupy the same space on screen
        if (isColliding(bar)) {
            ballDirectionY = -ballDirectionY;
            quicker();
        }

        // update the ball's position
        x += ballDirectionX;
        y += ballDirectionY;

        move(x, y);
    }
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

void Ball::quicker() {
    if (ballSpeed > 20) ballSpeed--;
}
