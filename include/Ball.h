#ifndef PING_BALL_H
#define PING_BALL_H

#include "GameObject.h"
#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "InputManager.h"
#include "PongBar.h"

class Ball : public GameObject {

protected:
    int xForce, yForce;
    int ballSpeed = 10; //lower numbers are faster

    const PongBar* bar;

    // direction
    int ballDirectionX = 1;
    int ballDirectionY = 1;
public:
    Ball(int, int, RGBmatrixPanel&);
    void move(int, int) override;
    void print() override;
    virtual void firstPush(int, int);
    void setBar(const PongBar* b) {
        bar = b;
    }
public:
    void awake() override;
    void update(const InputManager& manager);

    void quicker();
};


#endif //PING_BALL_H
