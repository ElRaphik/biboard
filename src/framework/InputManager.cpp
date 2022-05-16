#include "../../include/framework/InputManager.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

InputManager::InputManager(RGBmatrixPanel &panel) : GameObject(0, 0, 0, 0, 0, 0,panel),
    ultrasonic1(triggerPin,echoPinLeft, 5000UL),
    ultrasonic2(triggerPin,echoPinRight, 5000UL) {}

void InputManager::awake() {
    Serial.println("Ultrasonic Sensor HC-SR04 Test");
    Serial.println("with Arduino MEGA 2560");
}

void InputManager::update() {
    // distance
    distanceLeft = ultrasonic1.read(CM);
    distanceRight = ultrasonic2.read(CM);

    Serial.print("Distance left :");
    Serial.print(distanceLeft);
    Serial.print(" cm | Distance right : ");
    Serial.print(distanceRight);
    Serial.println(" cm");

    distanceLeft = distanceLeft < 10 ? 10 : distanceLeft > 50 ? 50 : distanceLeft;
    distanceRight = distanceRight < 10 ? 10 : distanceRight > 50 ? 50 : distanceRight;
}

void InputManager::render() {
}

unsigned int InputManager::getDistanceLeft() const {
    return distanceLeft;
}

unsigned int InputManager::getDistanceRight() const {
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
