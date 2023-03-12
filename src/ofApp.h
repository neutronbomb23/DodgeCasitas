#pragma once

#include "ofMain.h"
#include "./ecs/Entity.h"
#include "./ecs/Manager.h"
#include "./components/Transform.h"
#include "./components/PlayerCtrl.h"
#include "../src/components/PlayerRender.h"
#include "Triangulo.h"


class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void createPlayer1();

private:
    Triangulo trianguloRojo;
    Triangulo trianguloAzul;
    float velocidad = 5;
    bool teclasPulsadas[256] = { false };
    Manager* mngr_ = nullptr;
};