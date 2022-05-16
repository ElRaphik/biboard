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

//    long durationLeft = 0, durationRight = 0;
    int distanceLeft = 0, distanceRight = 0;
    int posLeft = 0, posRight = 0;
public:
    explicit InputManager(RGBmatrixPanel &panel);

    int getPosLeft() const {
        return posLeft;
    }

    int getPosRight() const {
        return posRight;
    }

public:
    void awake() override;
    void update() override;
    void render() override;

    void update(bool=true);

private:
    void move(int, int) override {}
    static int setPosition(int dist) {
        int res = dist - 10;
        res = res/2;
        return res;
    }
};

#endif
