#include "../../include/pong/PongGameManager.h"
#include "framework/InputManager.h"

void PongGameManager::awake() {
    manager.awake();
    leftBar.awake();
    rightBar.awake();
    ball.awake();
}

void PongGameManager::update() {
    manager.update();
    (doLeft ? leftBar : rightBar).update(manager);
    ball.update(manager, leftBar);
    doLeft = !doLeft;
}

void PongGameManager::render() {
    manager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}
