#include "../../include/pong/PongGameManager.h"

void PongGameManager::awake() {
    musicManager.awake();
    inputManager.awake();
    leftBar.awake();
    rightBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    musicManager.update();
    inputManager.update();
    (inputManager.shouldDoLeft() ? leftBar : rightBar).update(inputManager);
//    leftBar.update(inputManager);
//    rightBar.update(inputManager);
    ball.update(inputManager, leftBar, rightBar);
    inputManager.invertShouldDoLeft();
}

void PongGameManager::render() {
    musicManager.render();
    inputManager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}
