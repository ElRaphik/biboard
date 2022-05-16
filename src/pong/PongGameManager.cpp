#include "../../include/pong/PongGameManager.h"

void PongGameManager::awake() {
    musicManager.awake();
    inputManager.awake();
    leftBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    musicManager.update();
    inputManager.update();
    leftBar.update(inputManager);
    ball.update(inputManager, leftBar);
}

void PongGameManager::render() {
    musicManager.render();
    inputManager.render();
    leftBar.render();
    ball.render();
}
