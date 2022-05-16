#ifndef PING_GAMEMANAGER_H
#define PING_GAMEMANAGER_H

#include "InputManager.h"

class GameManager : GameObject {
public:
    explicit GameManager(RGBmatrixPanel& m) : GameObject(m) {}
public:
    virtual const InputManager& getInputManager() const = 0;
};

#endif //PING_GAMEMANAGER_H
