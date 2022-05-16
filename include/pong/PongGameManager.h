#pragma once
#ifndef PING_PONGGAMEMANAGER_H
#define PING_PONGGAMEMANAGER_H

#include "PongBar.h"
#include "Ball.h"
#include "framework/GameManager.h"
#include "framework/InputManager.h"
#include "framework/MusicManager.h"

class PongGameManager : public GameManager {
public: // attributes
    PongBar leftBar;
    PongBar rightBar;
    Ball ball;
    InputManager inputManager;
    MusicManager musicManager;

public: // constructor
    explicit PongGameManager(RGBmatrixPanel& matrix) : GameManager(matrix), leftBar(0, 0, matrix), rightBar(31, 0, matrix), ball(matrix.width() / 2, matrix.height() / 2, matrix),
                                                       inputManager(matrix), musicManager(matrix) {
    }
public:
    void awake() override;
    void update() override;
    void render() override;

private:
    void move(int x, int y) override {}
    int doesOneHavePoint;
    int leftScore=0;
};


#endif //PING_PONGGAMEMANAGER_H
