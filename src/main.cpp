#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "PongBar.h"
#include "Ball.h"

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// echo

#define echoPinLeft 44
#define echoPinRight 45
#define triggerPin 39

long durationLeft, durationRight;
int distanceLeft, distanceRight;
boolean left;

// matrix

uint16_t black = matrix.Color444(0, 0, 0);
uint16_t white = matrix.Color444(15, 15, 15);
uint16_t yellow = matrix.Color444(15, 15, 0);

int paddleWidth=1;
int paddleHeight=3;

int ballDiameter=1;
int paddleX = 0;
int paddleY = 0;
int oldPaddleY;
int ballDirectionX = 1;
int ballDirectionY = 1;

int ballSpeed = 10; //lower numbers are faster

int ballX, ballY, oldBallX, oldBallY;

boolean inPaddle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight);
void clear();
void moveBall();
void quicker();


PongBar leftBar(0, 0, matrix);
Ball ball(matrix.width()/2, matrix.height()/2, matrix);


void setup() {
    // ultrasonic module stuff

    pinMode(triggerPin, OUTPUT);
    pinMode(echoPinLeft, INPUT);
    pinMode(echoPinRight, INPUT);
    Serial.begin(9600);
    Serial.println("Ultrasonic Sensor HC-SR04 Test");
    Serial.println("with Arduino MEGA 2560");

    // matrix stuff
    matrix.begin();
    clear();

    // game
//    paddleX = 0;
//    paddleY = matrix.height() / 2 - paddleHeight / 2;
    leftBar.spawn();
    ball.spawn();
    ball.firstPush(1, 1);
}

void loop() {
    // distance
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    durationLeft = (long) pulseIn(echoPinLeft, HIGH);
    distanceLeft = (int) ((float) durationLeft * 0.034 / 2);
//    delayMicroseconds(1000);
//    durationRight = static_cast<long>(pulseIn(echoPinRight, HIGH));
//    distanceRight = static_cast<int>((static_cast<double>(durationRight) * 0.034) / 2);

    Serial.print("Distance left :");
    Serial.print(distanceLeft);
//    Serial.print(" cm | Distance right : ");
//    Serial.print(distanceRight);
    Serial.println(" cm");

    // ???
    if (distanceLeft < 25) {
        leftBar.move(0, -1);
//        paddleY--;
        Serial.println("GO Up");
    } else if (distanceLeft > 50) {
        leftBar.move(0, 1);
//        paddleY++;
        Serial.println("GO Down");
    }

//    if (oldPaddleY != paddleY) {
//        matrix.fillRect(paddleX, oldPaddleY, paddleWidth, paddleHeight,black);
//    }
//    matrix.fillRect(paddleX, paddleY, paddleWidth, paddleHeight,white);
//    oldPaddleY = paddleY;

    leftBar.print();

    if (millis() % (ballSpeed/2) < 2) {
//        moveBall();
        ball.move(0, 0);
        ball.print();
    }
}

boolean inPaddle(int x, int y, int rectX, int rectY, int rectWidth, int rectHeight) {
    boolean result = false;

    if ((x >= rectX && x <= (rectX + rectWidth)) &&
        (y >= rectY && y <= (rectY + rectHeight))) {
        result = true;
    }
    return result;
}

void clear() {
    matrix.fillScreen(black);

}

void moveBall() {
    // if the ball goes offscreen, reverse the direction:
    if (ballX > matrix.width()-1 || ballX < 0) {
        ballDirectionX = -ballDirectionX;
        quicker();
    }

    if (ballY > matrix.height()-1 || ballY < 0) {
        ballDirectionY = -ballDirectionY;
        quicker();
    }

    // check if the ball and the paddle occupy the same space on screen
    if (inPaddle(ballX, ballY, paddleX, paddleY, paddleWidth, paddleHeight)) {
        ballDirectionY = -ballDirectionY;
        quicker();
    }

    // update the ball's position
    ballX += ballDirectionX;
    ballY += ballDirectionY;

    // erase the ball's previous position
    if (oldBallX != ballX || oldBallY != ballY) {
        matrix.fillRect(oldBallX, oldBallY, ballDiameter, ballDiameter,black);
    }
//     draw the ball's current position
    matrix.fillRect(ballX, ballY, ballDiameter, ballDiameter,white);

    oldBallX = ballX;
    oldBallY = ballY;
}

void quicker() {
    if (ballSpeed>20) ballSpeed--;
}
