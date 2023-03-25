#include "ofApp.h"

void ofApp::setup() {
    mngr_ = Manager::instance();
    createPlayer1();
    createEnemyH();
    createEnemyD();
}

void ofApp::update() {
    mngr_->update();
    mngr_->refresh();
}

void ofApp::draw() {
    ofBackground(0);
    mngr_->render();
}

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::createPlayer1() {
    Entity* player1 = mngr_->addEntity();
    Vector2D Position = Vector2D(100, 100);
    Vector2D Direction = Vector2D(0, 0);
    int Size = 50;
    player1->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    player1->addComponent<PlayerRender>(_DRAW);
    player1->addComponent<PlayerCtrl>(_CTRL, pair<char, char> {'w', 's'});
    //Player Renderer
}

void ofApp::createEnemyH() { // Enemigo horizontal
    double Size = 50;
    double Speed = 2;
    Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 2);
    Vector2D Direction = Vector2D(-1, 0) * Speed;

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyD() { // Enemigo diagonal
    double Size = 50;
    double Speed = 2;
    Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 3);
    Vector2D Direction = Vector2D(-1, 0);
    if (ofRandom(2)) { Direction.setY(1); }
    else { Direction.setY(-1); }

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction * Speed, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
    enemy->addComponent<ScreenBounce>(_SCREENBOUNCE);
}

void ofApp::createEnemyCD() { // Enemigo cambio de dirección
    double Size = 50;
    double Speed = 2;
    Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 4);
    Vector2D Direction = Vector2D(-1, 0) * Speed;

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
   // enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyINV() { // Enemigo invertir controles
    double Size = 50;
    double Speed = 2;
    Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 5);
    Vector2D Direction = Vector2D(-1, 0) * Speed;

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
   // enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}