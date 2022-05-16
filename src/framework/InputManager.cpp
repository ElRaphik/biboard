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

}

void InputManager::render() {
}

void InputManager::update(bool left) {
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

/*
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
        distanceLeft = distance < 10 ? 10 : distance > 37 ? 37 : distance;
    else
        distanceRight = distance < 10 ? 10 : distance > 37 ? 37 : distance;

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
 */

bool InputManager::shouldDoLeft() const {
    return doLeft;
}

void InputManager::invertShouldDoLeft() {
    // FU*K YOU CLION, HOPE YOU HAPPY MF
    if (doLeft) doLeft = false;
    else doLeft = true;
}
