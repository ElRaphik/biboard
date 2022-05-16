#include "framework/GameObject.h"
#include "RGBmatrixPanel.h" // Hardware-specific library

GameObject::GameObject(
        int x, int y, int oldX, int oldY, int width, int height, RGBmatrixPanel &matrix
) : x(x), y(y), oldX(oldX), oldY(oldY), width(width), height(height), matrix(matrix) {}

GameObject::GameObject(GameObject &gameObject) : matrix(gameObject.matrix) {
    x = gameObject.x;
    y = gameObject.y;
    oldX = gameObject.oldX;
    oldY = gameObject.oldY;
    width = gameObject.width;
    height = gameObject.height;
}

GameObject::GameObject(RGBmatrixPanel &m) : matrix(m) {
    x = 0;
    y = 0;
    oldX = 0;
    oldY = 0;
    width = 1;
    height = 1;
}

bool GameObject::isColliding(const GameObject& o) const {
    return (x >= o.getX() && x <= (o.getX() + o.getWidth())) &&
           (y >= o.getY() && y <= (o.getY() + o.getHeight()));
}
