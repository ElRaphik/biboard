#include "../../include/pong/PongGameManager.h"
#include "framework/InputManager.h"

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
    (doLeft ? leftBar : rightBar).update(manager);
    ball.update(manager, leftBar);
    doLeft = !doLeft;
}

void PongGameManager::render() {
    musicManager.render();
    inputManager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}
