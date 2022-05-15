//
// Created by asdch on 16/05/2022.
//

#ifndef PING_GAMEOBJECT_H
#define PING_GAMEOBJECT_H
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library


class GameObject {

protected:
    int x, y, oldX, oldY, width, height;
    RGBmatrixPanel& matrix;

public: // members
    int getX() const;
    int getY() const;
    int getOldX() const;
    int getOldY() const;
    int getWidth() const;
    int getHeight() const;
    const RGBmatrixPanel &getMatrix() const;

public: // constructors
    GameObject(GameObject&);
    explicit GameObject(RGBmatrixPanel&);
    GameObject(int, int, int, int, int, int, RGBmatrixPanel&);

public: // methods
    bool isColliding(GameObject&);
    virtual void move(int, int) = 0;
    virtual void print() = 0;
};


#endif //PING_GAMEOBJECT_H
