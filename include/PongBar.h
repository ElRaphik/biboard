#ifndef PING_PONGBAR_H
#define PING_PONGBAR_H

#include "GameObject.h"
#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "InputManager.h"

class PongBar : public GameObject{

public:
    PongBar(int, int, RGBmatrixPanel&);
public:
    void move(int, int) override;
    void print() override;
public:
    void awake() override;
    void update(const InputManager& manager);
};


#endif //PING_PONGBAR_H
