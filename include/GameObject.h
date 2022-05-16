#ifndef PING_GAMEOBJECT_H
#define PING_GAMEOBJECT_H
#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library


class GameObject {

protected:
    int x, y, oldX, oldY, width, height;
    RGBmatrixPanel& matrix;

public: // members
    int getX() const { return x; }
    int getY() const { return y; }
    int getOldX() const { return oldX; }
    int getOldY() const { return oldY; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const RGBmatrixPanel &getMatrix() const { return matrix; }

public: // constructors
    GameObject(GameObject&);
    GameObject(int, int, int, int, int, int, RGBmatrixPanel&);

public: // methods
    bool isColliding(GameObject&);
    virtual void move(int, int) = 0;
    virtual void print() = 0;
};


#endif //PING_GAMEOBJECT_H
