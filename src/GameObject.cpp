//
// Created by asdch on 16/05/2022.
//

#include "GameObject.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

GameObject::GameObject(
        int x, int y, int oldX, int oldY, int width, int height, RGBmatrixPanel& matrix
        ) : x(x), y(y), oldX(oldX), oldY(oldY), width(width), height(height), matrix(matrix){}

GameObject::GameObject(GameObject & gameObject) : matrix(gameObject.matrix){
    x = gameObject.x;
    y = gameObject.y;
    oldX = gameObject.oldX;
    oldY = gameObject.oldY;
    width = gameObject.width;
    height = gameObject.height;
}

GameObject::GameObject(RGBmatrixPanel& matrix) : matrix(matrix){
    x = 0;
    y = 0;
    oldX = 0;
    oldY = 0;
    width = 1;
    height = 1;
}

bool GameObject::isColliding(GameObject& gameObject) {
    // TODO implement collisions
    return false;
}











// GETTERS (AUTO-GENERATED)
int GameObject::getX() const {
    return x;
}
int GameObject::getY() const {
    return y;
}
int GameObject::getOldX() const {
    return oldX;
}
int GameObject::getOldY() const {
    return oldY;
}
int GameObject::getWidth() const {
    return width;
}
int GameObject::getHeight() const {
    return height;
}
const RGBmatrixPanel &GameObject::getMatrix() const {
    return matrix;
}


