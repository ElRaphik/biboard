#ifndef PING_PONGGAMEMANAGER_H
#define PING_PONGGAMEMANAGER_H

#include "PongBar.h"
#include "Ball.h"
#include "framework/GameManager.h"

class PongGameManager : public GameManager {
public: // attributes
    PongBar leftBar;
    PongBar rightBar;
    Ball ball;
    InputManager manager;
    bool doLeft;

public: // constructor
    explicit PongGameManager(RGBmatrixPanel& matrix) : GameManager(matrix), leftBar(0, 0, matrix), rightBar(31, 0, matrix), ball(matrix.width() / 2, matrix.height() / 2, matrix),
                                              manager(matrix), doLeft(true) {
    }
public:
    void awake() override;
    void update() override;
    void render() override;

public:
    /// \return the input manager used in update
    const InputManager& getInputManager() const override;

private:
    void move(int x, int y) override {}
};


#endif //PING_PONGGAMEMANAGER_H
