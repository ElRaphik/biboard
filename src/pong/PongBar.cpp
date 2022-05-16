#include "pong/PongBar.h"
#include "framework/InputManager.h"
#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library

PongBar::PongBar(int x, int y, RGBmatrixPanel &matrix) : PongGameObject(x, y, x, y, 1, 3, matrix) {}

// Impl

void PongBar::awake() {
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
}

void PongBar::update(const InputManager& manager) {
    if (manager.isLeftC1()) {
        move(0, -1);
        Serial.println("PongBar go up");
    } else if (manager.isRightC1()) {
        move(0, 1);
        Serial.println("PongBar go down");
    }
}

void PongBar::render() {
    if (y == oldY) return;
    // clear
    matrix.fillRect(x, oldY, width, height, matrix.Color333(0, 0, 0));
    // draw
    matrix.fillRect(x, y, width, height, matrix.Color333(7, 7, 7));
    oldY = y;
}

void PongBar::move(int, int yForce) {
    if (y + yForce < 0) {
        y = 0;
        return;
    } // set x to 0 to stay in bounds
    if (y + height + yForce > 16) {
        y = 16 - height;
        return;
    } // set x to 16-height
    y += yForce;
}