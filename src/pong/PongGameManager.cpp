#include "../../include/pong/PongGameManager.h"

void PongGameManager::awake() {
    manager.awake();
    leftBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    manager.update();
    leftBar.update(manager);
    ball.update(manager, leftBar);
}

void PongGameManager::render() {
    manager.render();
    leftBar.render();
    ball.render();
}
