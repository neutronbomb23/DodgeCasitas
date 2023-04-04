#pragma once

#include "ofMain.h"
#include "./ecs/Entity.h"
#include "./ecs/Manager.h"
#include "./components/Transform.h"
#include "./components/PlayerCtrl.h"
#include "./components/PlayerRender.h"
#include "./components/DisableOnExit.h"
#include "./components/ScreenBounce.h"
#include "./components/RotationComponent.h"
#include "./components/HorizontalEnemyRender.h"
#include "./components/DiagonalEnemyRender.h"
#include "Triangulo.h"


class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void createPlayer1(Vector2D Position = Vector2D(100, 100), Vector2D Direction = Vector2D(0, 0), int Size = 50);
    void createEnemyH(Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 2), Vector2D Direction = Vector2D(-1, 0), int Speed = 2, int Size = 50);
    void createEnemyD(Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 2), int Speed = 2, int Size = 80);
    void createEnemyCD();
    void createEnemyINV();

private:
    Manager* mngr_ = nullptr;
};