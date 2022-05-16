#include "../../include/framework/InputManager.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

InputManager::InputManager(RGBmatrixPanel &panel) : GameObject(0, 0, 0, 0, 0, 0,panel) {}

void InputManager::awake() {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPinLeft, INPUT);
    pinMode(echoPinRight, INPUT);
    Serial.println("Ultrasonic Sensor HC-SR04 Test");
    Serial.println("with Arduino MEGA 2560");
}

void InputManager::update() {
    // distance
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    if(shouldDoLeft()) {
        durationLeft = (long) pulseIn(echoPinLeft, HIGH);
        distanceLeft = (int) ((double) durationLeft * 0.034 / 2);
    } else {
        durationRight = (long) pulseIn(echoPinRight, HIGH);
        distanceRight = (int) ((double) durationRight * 0.034 / 2);
    }
//    delayMicroseconds(1000);

//    Serial.print("Distance left :");
//    Serial.print(distanceLeft);
//    Serial.print(" cm | Distance right : ");
//    Serial.print(distanceRight);
//    Serial.println(" cm");
    distanceLeft = distanceLeft < 10 ? 10 : distanceLeft > 50 ? 50 : distanceLeft;
    distanceRight = distanceRight < 10 ? 10 : distanceRight > 50 ? 50 : distanceRight;
}

void InputManager::render() {
}

int InputManager::getDistanceLeft() const {
    return distanceLeft;
}

int InputManager::getDistanceRight() const {
    return distanceRight;
}

bool InputManager::shouldDoLeft() const {
    return doLeft;
}

void InputManager::invertShouldDoLeft() {
    // FU*K YOU CLION, HOPE YOU HAPPY MF
    if (doLeft) doLeft = false;
    else doLeft = true;
}
