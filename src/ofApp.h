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
#include "./components/ChangeDirectionComponent.h"
#include "ofSoundPlayer.h"

struct rect {
    float x, y, w, h;
};

class ofApp : public ofBaseApp {
private:
    Manager* mngr_ = nullptr;
    // Info
    const static int nRows = 4;
    bool end = false;
    // Generación de enemigos
    int timeNextSpawn;
    int delay = 5000;
    int minDelay = 3000;

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void spawnEnemies();
    void createPlayer1(Vector2D Position = Vector2D(100, ofGetHeight() / (2*nRows)), Vector2D Direction = Vector2D(0, 0), int Size = 50);
    void createEnemyH(Vector2D Position, Vector2D Direction = Vector2D(-1, 0), int Speed = 3, int Size = 50);
    void createEnemyD(Vector2D Position, int Speed = 4, int Size = 80);
    void createEnemyCD(Vector2D Position, Vector2D Direction = Vector2D(-1, 0), int Speed = 3, int Size = 50);
    void createEnemyINV(Vector2D Position, Vector2D Direction = Vector2D(-1, 0), int Speed = 3, int Size = 50);

    void collision();
    bool collides(rect obj1, rect obj2);
    void deleteAllEnemies();
};