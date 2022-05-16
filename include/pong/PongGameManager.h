#ifndef PING_PONGGAMEMANAGER_H
#define PING_PONGGAMEMANAGER_H

#include "PongBar.h"
#include "Ball.h"
#include "framework/GameManager.h"

class PongGameManager : public GameManager {
public: // attributes
    PongBar leftBar;
    Ball ball;
    InputManager manager;

public: // constructor
    explicit PongGameManager(RGBmatrixPanel& matrix) : GameManager(matrix), leftBar(0, 0, matrix), ball(matrix.width() / 2, matrix.height() / 2, matrix),
                                              manager(matrix) {
    }
public:
    void awake() override;
    void update();
    void render() override;

public:
    /// \return the input manager used in update
    const InputManager& getInputManager() const override;

private:
    void move(int x, int y) override {}
    void update(const InputManager&) override {}
};


#endif //PING_PONGGAMEMANAGER_H
