#pragma once

#include "ofMain.h"
#include "./ecs/Entity.h"
#include "./ecs/Manager.h"
#include "./components/Transform.h"
#include "./components/PlayerCtrl.h"
#include "./components/PlayerRender.h"
#include "./components/DisableOnExit.h"
#include "./components/ScreenBounce.h"
#include "Triangulo.h"


class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void createPlayer1();
    void createEnemyH();
    void createEnemyD();
    void createEnemyCD();
    void createEnemyINV();

private:
    Manager* mngr_ = nullptr;
};