#include "../../include/pong/PongGameManager.h"

void PongGameManager::awake() {
    manager.awake();
    leftBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    manager.update(manager);
    leftBar.update(manager);
    ball.update(manager);
}

void PongGameManager::render() {
    manager.render();
    leftBar.render();
    ball.render();
}

const InputManager& PongGameManager::getInputManager() const {
    return manager;
}
