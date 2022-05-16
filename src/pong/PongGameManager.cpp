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
    leftBar.update(inputManager, true);
    rightBar.update(inputManager, false);
    doesOneHavePoint = ball.update(inputManager, leftBar, rightBar);
    if(doesOneHavePoint != 0) {
        doesOneHavePoint==1?leftScore++:rightScore++;
        if(leftScore==10 || rightScore==10)
            screen.writeWinner(leftScore==10);
        screen.writeScores(leftScore, rightScore);
        reset();
        doesOneHavePoint=0;
    }

}

void PongGameManager::render() {
    musicManager.render();
    inputManager.render();
    leftBar.render();
    rightBar.render();
    ball.render();
}

void PongGameManager::reset() {
    ball.reset(doesOneHavePoint==1);
    leftBar.reset(true);
    rightBar.reset(false);
}
