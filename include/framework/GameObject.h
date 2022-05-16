#ifndef PING_GAMEOBJECT_H
#define PING_GAMEOBJECT_H

#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "InputManager.h"

class GameObject {

protected:
    int x, y, oldX, oldY, width, height;
    RGBmatrixPanel& matrix;

public: // members
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

public: // constructors
    GameObject(GameObject&);
    explicit GameObject(RGBmatrixPanel&);
    explicit GameObject(int, int, int, int, int, int, RGBmatrixPanel&);

public: // base
    virtual void awake() = 0;
    virtual void update(const InputManager&) = 0;
    virtual void render() = 0;
public: // utils
    bool isColliding(const GameObject&) const;
    virtual void move(int x, int y) = 0;
};


#endif //PING_GAMEOBJECT_H
