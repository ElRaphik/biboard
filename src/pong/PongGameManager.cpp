#include "../../include/pong/PongGameManager.h"

void PongGameManager::awake() {
    manager.awake();
    leftBar.awake();
    rightBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    manager.update();
    leftBar.update(manager);
    rightBar.update(manager);
    ball.update(manager, leftBar);
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
