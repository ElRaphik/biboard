#ifndef PING_PONGBAR_H
#define PING_PONGBAR_H

#include "GameObject.h"
#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library

class PongBar : public GameObject{

public:
    PongBar(int, int, RGBmatrixPanel&);
    void move(int, int) override;
    void print() override;
    void spawn();
};


#endif //PING_PONGBAR_H
