#include "ofApp.h"

void ofApp::setup() {
    mngr_ = Manager::instance();
    createPlayer1();

    trianguloRojo.setup(ofGetWidth() / 2, 50, ofColor::red);
    trianguloAzul.setup(ofGetWidth() / 2, ofGetHeight() - 50, ofColor::blue);
}

void ofApp::update() {
    bool moverArribaRojo = teclasPulsadas['w'];
    bool moverAbajoRojo = teclasPulsadas['s'];
    bool moverArribaAzul = teclasPulsadas['i'];//PUTO ORTOPÉDICO ESTO
    bool moverAbajoAzul = teclasPulsadas['k']; //PUTO ORTOPÉDICO ESTO

    if (moverArribaRojo && !moverAbajoRojo) {
        trianguloRojo.update(velocidad, true);
    }
    else if (moverAbajoRojo && !moverArribaRojo) {
        trianguloRojo.update(velocidad, false);
    }

    if (moverArribaAzul && !moverAbajoAzul) {
        trianguloAzul.update(velocidad, true);
    }
    else if (moverAbajoAzul && !moverArribaAzul) {
        trianguloAzul.update(velocidad, false);
    }

    mngr_->update();
}

void ofApp::draw() {
    ofBackground(0);
    trianguloRojo.draw();
    trianguloAzul.draw();
    mngr_->render();
    //mngr_
}

void ofApp::keyPressed(int key) {
    teclasPulsadas[key] = true;
}

void ofApp::keyReleased(int key) {
    teclasPulsadas[key] = false;
}

void ofApp::createPlayer1() {
    Entity* player1 = mngr_->addEntity();
    player1->addComponent<Transform>(_TRANSFORM)->setPosY(ofGetHeight() / 4 - 100);
    player1->addComponent<PlayerRender>(_DRAW);
    player1->addComponent<PlayerCtrl>(_CTRL, pair<char, char> {'o', 'l'});
    //Player Renderer
}