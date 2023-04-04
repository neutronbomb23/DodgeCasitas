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

void ofApp::createPlayer1(Vector2D Position, Vector2D Direction, int Size) {
    Entity* player1 = mngr_->addEntity();
    player1->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    player1->addComponent<PlayerRender>(_DRAW);
    player1->addComponent<PlayerCtrl>(_CTRL, pair<char, char> {'w', 's'});
}

void ofApp::createEnemyH(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo horizontal
    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<HorizontalEnemyRender>(_DRAW); 
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyD(Vector2D Position, int Speed, int Size) { // Enemigo diagonal
    Vector2D Direction = Vector2D(-1, 0);
    if (ofRandom(2)) { Direction.setY(1); }
    else { Direction.setY(-1); }

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<DiagonalEnemyRender>(_DRAW);
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
    enemy->addComponent<ScreenBounce>(_SCREENBOUNCE);
    enemy->addComponent<RotationComponent>(_ROTATION);
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