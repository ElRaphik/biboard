#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "PongBar.h"
#include "Ball.h"
#include "InputManager.h"

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

PongBar leftBar(0, 0, matrix);
Ball ball(matrix.width() / 2, matrix.height() / 2, matrix);
InputManager manager(matrix);

void setup() {
    // ultrasonic module stuff
    Serial.begin(9600);

    manager.awake();

    // clear
    matrix.begin();
    matrix.fillScreen(matrix.Color444(0, 0, 0));

    // game
    leftBar.awake();
    ball.awake();
    ball.setBar(&leftBar);
}

void loop() {
    manager.update();
    leftBar.update(manager);
    ball.update(manager);
}