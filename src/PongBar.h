//
// Created by asdch on 16/05/2022.
//

#ifndef PING_PONGBAR_H
#define PING_PONGBAR_H
#include "GameObject.h"
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

class PongBar : public GameObject{

public:
    PongBar(int, int, RGBmatrixPanel&);
//    PongBar(PongBar&);
    explicit PongBar(GameObject&);
    void move(int, int) override;
    void print() override;
    void spawn();
};


#endif //PING_PONGBAR_H
