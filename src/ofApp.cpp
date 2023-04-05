#include "ofApp.h"

void ofApp::setup() {
    //ofToggleFullscreen(); // NO PONER PUNTOS DE INTERRUPCION CON ESTO DESCOMENTADO
    mngr_ = Manager::instance();
    createPlayer1();
    timeNextSpawn = ofGetCurrentTime().getAsMilliseconds() + delay;
}

void ofApp::update() {
    mngr_->update();
    mngr_->refresh();
    spawnEnemies();
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

void ofApp::spawnEnemies() {
    if (ofGetCurrentTime().getAsMilliseconds() >= timeNextSpawn) { // Tiempo
        // Numero de enemigos
        int nDamageEnemies = 1; 
        if (rand()%4 <= 2) ++nDamageEnemies;

        for (int i = 0; i < nDamageEnemies; ++i) {
            Vector2D Position = Vector2D(ofGetWidth(), (ofGetHeight() / 8) + rand() % 4 * (ofGetHeight() / 4)); // Posicion de una fila aleatoria
            
            int type = rand() % 4;
            switch (type) { // Eligue tipo de enemigo
                case 0:
                    createEnemyH(Position);
                    break;

                case 1:
                    createEnemyD(Position);
                    break;

                case 2:
                    createEnemyCD(Position);
                    break;

                case 3:
                    createEnemyINV(Position);
                    break;
            }
        }
        timeNextSpawn = ofGetCurrentTime().getAsMilliseconds() + delay; // Actualiza timer
        if (delay > minDelay) delay -= 50; // Actualiza tiempo entre spawns de enemigos
    }
}

void ofApp::createEnemyH(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo horizontal
    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<HorizontalEnemyRender>(_DRAW); 
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyD(Vector2D Position, int Speed, int Size) { // Enemigo diagonal
    Vector2D Direction = Vector2D(-1, 0);
    if (rand() % 2) { Direction.setY(1); }
    else { Direction.setY(-1); }

    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<DiagonalEnemyRender>(_DRAW);
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
    enemy->addComponent<ScreenBounce>(_SCREENBOUNCE);
    enemy->addComponent<RotationComponent>(_ROTATION);
}

void ofApp::createEnemyCD(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo cambio de dirección
    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyINV(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo invertir controles
    Entity* enemy = mngr_->addEntity();
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}