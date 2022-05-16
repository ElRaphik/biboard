#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "pong/PongGameManager.h"

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// Game
PongGameManager pong(matrix);

void setup() {
    // ultrasonic module stuff
    Serial.begin(9600);

    // clear
    matrix.begin();
    matrix.fillScreen(matrix.Color444(0, 0, 0));

    // game
    pong.awake();
}

void loop() {
    pong.update();
    pong.render();
    delay(75);
}