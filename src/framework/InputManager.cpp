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

}

void InputManager::render() {
}

void InputManager::update(bool left) {
    long duration;
    int distance;
    // distance
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    duration = (long) pulseIn(left ? echoPinLeft : echoPinRight, HIGH);
    distance = (int) ((float) duration * 0.034 / 2);

//    left ? distanceLeft : distanceRight = distance < 10 ? 10 : distance > 50 ? 50 : distance;
    if(left)
        distanceLeft = distance < 10 ? 10 : distance > 38 ? 38 : distance;
    else
        distanceRight = distance < 10 ? 10 : distance > 38 ? 38 : distance;

    posLeft = setPosition(distanceLeft);
    posRight = setPosition(distanceRight);

//    durationLeft = (long) pulseIn(echoPinLeft, HIGH);
//    distanceLeft = (int) ((float) durationLeft * 0.034 / 2);
//    delayMicroseconds(1000);
//    durationRight = static_cast<long>(pulseIn(echoPinRight, HIGH));
//    distanceRight = static_cast<int>((static_cast<double>(durationRight) * 0.034) / 2);
//    Serial.print(distance);
//    Serial.print("Distance left :");
//    Serial.print(distanceLeft);
//    Serial.print(" cm | Distance right : ");
//    Serial.print(distanceRight);
//    Serial.println(" cm");
}
