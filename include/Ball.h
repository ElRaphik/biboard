#ifndef PING_BALL_H
#define PING_BALL_H

#include "GameObject.h"
#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library

class Ball : public GameObject {

protected:
    int xForce, yForce;

public:
    Ball(int, int, RGBmatrixPanel&);
    void move(int, int) override;
    void print() override;
    virtual void spawn();
    virtual void firstPush(int, int);
};


#endif //PING_BALL_H
