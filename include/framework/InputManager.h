#pragma once
#ifndef PING_INPUTMANAGER_H
#define PING_INPUTMANAGER_H

#include "GameObject.h"
#include <Ultrasonic.h>

/// A class handling the input of the user
/// \class InputManager
class InputManager : public GameObject {
private:
    const int echoPinLeft = 44;
    const int echoPinRight = 45;
    const int triggerPin = 39;

    Ultrasonic ultrasonic1;
    Ultrasonic ultrasonic2;

    unsigned int distanceLeft = 0, distanceRight = 0;

    bool doLeft = true;
public:
    unsigned int getDistanceLeft() const;
    unsigned int getDistanceRight() const;
    bool shouldDoLeft() const;

    void invertShouldDoLeft();

public:
    explicit InputManager(RGBmatrixPanel &panel);

public:
    void awake() override;
    void update() override;
//    void update(PongGameManager&);
    void render() override;

public:
    bool isLeftC1() const {
        return distanceLeft < 25;
    }

    bool isRightC1() const {
        return distanceLeft > 50;
    }

    bool isLeftC2() const {
        return distanceRight < 25;
    }

    bool isRightC2() const {
        return distanceRight > 50;
    }
private:
    void move(int, int) override {};
//    void update() override {};
};

#endif
