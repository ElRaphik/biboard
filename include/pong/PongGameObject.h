#ifndef PING_PONGGAMEOBJECT_H
#define PING_PONGGAMEOBJECT_H

#include "framework/GameObject.h"
#include "framework/InputManager.h"

class PongGameObject : public GameObject {
public:
    PongGameObject(PongGameObject& o) = default;
    explicit PongGameObject(int x, int y, int oldX, int oldY, int width, int height, RGBmatrixPanel& r) :
        GameObject(x, y, oldX, oldY, width, height, r) {}
public:
    virtual void update(const InputManager& manager) = 0;
private:
    void update() override;
};


#endif //PING_PONGGAMEOBJECT_H
