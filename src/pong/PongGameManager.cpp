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
    doesOneHavePoint = ball.update(inputManager, leftBar, rightBar);
    if(doesOneHavePoint != 0) {
        doesOneHavePoint==1?leftScore++:rightScore++;
        screen.writeScores(leftScore, rightScore);
        doesOneHavePoint=0;
    }
    inputManager.invertShouldDoLeft();

}

void PongGameManager::render() {
    musicManager.render();
    inputManager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}

void PongGameManager::reset() {

}
