#ifndef PING_PONGBAR_H
#define PING_PONGBAR_H

#include "Adafruit_GFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "pong/PongGameObject.h"
#include "framework/InputManager.h"

class PongBar : public PongGameObject {

public:
    PongBar(int, int, RGBmatrixPanel&);
public:
    void awake() override;
    void update(const InputManager& manager) override;
    void update(const InputManager& manager, bool);
    void render() override;
private:
    void move(int, int) override;
};


#endif //PING_PONGBAR_H
