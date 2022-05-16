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
    (doLeft ? leftBar : rightBar).update(inputManager);
    ball.update(inputManager, leftBar);
    doLeft = !doLeft;
}

void PongGameManager::render() {
    musicManager.render();
    inputManager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}
