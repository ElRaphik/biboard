#ifndef PING_BALL_H
#define PING_BALL_H

#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "pong/PongGameObject.h"
#include "framework/InputManager.h"
#include "PongBar.h"

class Ball : public PongGameObject {

protected:
    int xForce, yForce;
    int ballSpeed = 10; //lower numbers are faster

    // direction
    int ballDirectionX = 1;
    int ballDirectionY = 1;
public:
    Ball(int, int, RGBmatrixPanel&);
public:
    void awake() override;
    void update(const InputManager& manager) override;
    void render() override;
public:
    void move(int x, int y) override;
    void firstPush(int, int);
};


#endif //PING_BALL_H
