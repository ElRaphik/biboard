#include "../../include/framework/InputManager.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

InputManager::InputManager(RGBmatrixPanel &panel) : GameObject(0, 0, 0, 0, 0, 0,panel),
    ultrasonic1(triggerPin,echoPinLeft, 20000UL),
    ultrasonic2(triggerPin,echoPinRight, 20000UL) {}

void InputManager::awake() {
    Serial.println("Ultrasonic Sensor HC-SR04 Test");
    Serial.println("with Arduino MEGA 2560");
}

void InputManager::update() {
    // distance
    distanceLeft = ultrasonic1.read(CM);
    distanceRight = ultrasonic2.read(CM);

//    Serial.print("Distance left :");
//    Serial.print(distanceLeft);
//    Serial.print(" cm | Distance right : ");
//    Serial.print(distanceRight);
//    Serial.println(" cm");

    distanceLeft = distanceLeft < 5 ? 5 : distanceLeft > 18 ? 18 : distanceLeft;
    distanceRight = distanceRight < 5 ? 5 : distanceRight > 18 ? 18 : distanceRight;

    posLeft = setPosition((int) distanceLeft);
    posRight = setPosition((int) distanceRight);
}