#include "framework/InputManager.h"

InputManager::InputManager(RGBmatrixPanel &panel) : GameObject(0, 0, 0, 0, 0, 0,panel) {}

void InputManager::awake() {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPinLeft, INPUT);
    pinMode(echoPinRight, INPUT);
    Serial.println("Ultrasonic Sensor HC-SR04 Test");
    Serial.println("with Arduino MEGA 2560");
}

void InputManager::update(const InputManager&) {
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
}

void InputManager::render() {
}
