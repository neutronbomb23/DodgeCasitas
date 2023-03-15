#include "ofApp.h"

void ofApp::setup() {
    mngr_ = Manager::instance();
    createPlayer1();
    createEnemyH();
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
    player1->addComponent<Transform>(_TRANSFORM)->setPosY(ofGetHeight() / 4 - 100);
    player1->addComponent<PlayerRender>(_DRAW);
    player1->addComponent<PlayerCtrl>(_CTRL, pair<char, char> {'w', 's'});
    //Player Renderer
}

void ofApp::createEnemyH() { // Enemigo horizontal
    double Size = 150;
    double Speed = 2;
    Vector2D Position = Vector2D(ofGetWidth(), ofGetHeight() / 2);
    Vector2D Direction = Vector2D(-1, 0) * Speed;

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}