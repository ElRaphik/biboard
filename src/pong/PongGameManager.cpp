#include "../../include/pong/PongGameManager.h"

void PongGameManager::awake() {
    manager.awake();
    leftBar.awake();
    rightBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    manager.update(doLeft);
    leftBar.update(manager, true);
    rightBar.update(manager, false);
    ball.update(manager, leftBar, rightBar);
    doLeft = !doLeft;
}

void PongGameManager::render() {
    manager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}

const InputManager& PongGameManager::getInputManager() const {
    return manager;
}
