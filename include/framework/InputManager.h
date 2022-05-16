#ifndef PING_INPUTMANAGER_H
#define PING_INPUTMANAGER_H

#include "GameObject.h"

/// A class handling the input of the user
/// \class InputManager
class InputManager : public GameObject {
private:
    const int echoPinLeft = 44;
    const int echoPinRight = 45;
    const int triggerPin = 39;

    long durationLeft = 0, durationRight = 0;
    int distanceLeft = 0, distanceRight = 0;
public:
    explicit InputManager(RGBmatrixPanel &panel);

public:
    void awake() override;
    void update() override;
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
    void move(int, int) override {}
};

#endif
