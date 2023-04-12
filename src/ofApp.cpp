#include "ofApp.h"

void ofApp::setup() {
    //ofToggleFullscreen(); // NO PONER PUNTOS DE INTERRUPCION CON ESTO DESCOMENTADO
    mngr_ = Manager::instance();
    createPlayers();
    timeNextSpawn = ofGetCurrentTime().getAsMilliseconds() + delay;

    // Musica fondo
    music.load(ofToDataPath("CaritaEmpapada.mp3"));
    music.setLoop(true);
    music.setVolume(0.8f);
    music.play();
}

void ofApp::update() {
    if (currentState == PLAY) {
        mngr_->update();
        mngr_->refresh();  
        spawnEnemies();
        collision();
        tiempoTranscurridoMs = ofGetElapsedTimeMillis();
        if (tiempoTranscurridoMs >= tiempoTotalMs) {
            tiempoTranscurridoMs = tiempoTotalMs;
            currentState = WIN;
        }
    }
    else if (ofGetKeyPressed(' ')) {
        resetGame();
    }
}

void ofApp::draw() {
    if (currentState == PLAY) {
        //Fondo
        ofBackground(0);
        //Progressbar
        ofSetColor(ofColor::white);
        ofDrawRectangle(ofGetWidth() - 300 - 30, ofGetHeight() - 30, 300, 20);
        ofSetColor(ofColor::yellow);
        ofDrawRectangle(ofGetWidth() - 300 - 30, ofGetHeight() - 30, ofMap(tiempoTranscurridoMs, 0, tiempoTotalMs, 0, 300), 20); // Dibuja un rectángulo que representa el tiempo transcurrido
        //Railes
        renderRails();
        //Entidades
        mngr_->render();
    }
    else if (currentState == LOOSE) {
        ofBackground(ofColor::black);
        ofSetColor(ofColor::white);
        ofDrawBitmapString("Game Over", ofGetWidth() / 2 - 50, ofGetHeight() / 2);
    }
    else if (currentState == WIN) {
        ofBackground(ofColor::black);
        ofSetColor(ofColor::white);
        ofDrawBitmapString("YOU WIN", ofGetWidth() / 2 - 50, ofGetHeight() / 2);
    }
}


void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::renderRails() {
    ofSetColor(255);
    ofDrawLine(0, ofGetHeight() * 0.25, ofGetWidth(), ofGetHeight() * 0.25);
    ofSetColor(255);
    ofDrawLine(0, ofGetHeight() * 0.5, ofGetWidth(), ofGetHeight() * 0.5);
    ofSetColor(255);
    ofDrawLine(0, ofGetHeight() * 0.75, ofGetWidth(), ofGetHeight() * 0.75);
}

void ofApp::createPlayers(Vector2D Position, Vector2D Direction, int Size) {
    Position.setY(Position.getY() + ofGetHeight() / nRows);

    Entity* player1 = mngr_->addEntity(_grp_PLAYERS);
    Transform* tr1 = player1->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    player1->addComponent<PlayerRender>(_DRAW);
    PlayerCtrl* ctrl1 = player1->addComponent<PlayerCtrl>(_CTRL, pair<char, char> {'w', 's'});

    Position.setY(Position.getY() + ofGetHeight() / nRows);

    Entity* player2 = mngr_->addEntity(_grp_PLAYERS);
    Transform* tr2 = player2->addComponent<Transform>(_TRANSFORM, Position, Direction, Size, Size);
    player2->addComponent<PlayerRender>(_DRAW, ofColor(0, 255, 150));
    PlayerCtrl* ctrl2 = player2->addComponent<PlayerCtrl>(_CTRL, pair<char, char> {'o', 'l'});

    ctrl1->setCoopRef(tr2);
    ctrl2->setCoopRef(tr1);
}

void ofApp::spawnEnemies() {
    if (ofGetCurrentTime().getAsMilliseconds() >= timeNextSpawn) { // Tiempo
        int nEnemies = 1 + rand() % 4;  // Numero de enemigos en esta ronda
        bool state = false; // ¿Se ha lanzado algun enemigo que no infrinja daño?
        int row; // Fila en la que va a aparecer el siguiente enemigo
        bool railsFree[nRows] = { true, true, true, true }; // Railes en los que no ha salido ningun enemigo

        for (int i = 0; i < nEnemies; ++i) {
            do { row = rand() % nRows; } while (!railsFree[row]); // Eligue siguiente rail
            railsFree[row] = false; // Marca el rail como no libre

            Vector2D Position = Vector2D(ofGetWidth(), (ofGetHeight() / 8) + row * (ofGetHeight() / nRows)); // Posicion de una fila aleatoria

            if (i > 1) { createEnemyINV(Position); break; } // Si ya han ocupado 2 lineas solo puede ser enemigo de estado 
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
    Entity* enemy = mngr_->addEntity(_grp_ENEMIES_DAMAGE);
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<HorizontalEnemyRender>(_DRAW);
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyD(Vector2D Position, int Speed, int Size) { // Enemigo diagonal
    Vector2D Direction = Vector2D(-1, 0);
    if (rand() % 2) { Direction.setY(1); }
    else { Direction.setY(-1); }

    Entity* enemy = mngr_->addEntity(_grp_ENEMIES_DAMAGE);
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<DiagonalEnemyRender>(_DRAW);
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
    enemy->addComponent<ScreenBounce>(_SCREENBOUNCE);
    enemy->addComponent<RotationComponent>(_ROTATION);
}

void ofApp::createEnemyCD(Vector2D Position, Vector2D Direction, int Speed, int Width, int Height) { // Enemigo cambio de dirección
    Entity* enemy = mngr_->addEntity(_grp_ENEMIES_DAMAGE);
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Width, Height);
    enemy->addComponent<ChangeDirectionComponent>(_CHANGEDIRECTION, nRows);
    enemy->addComponent<ChangeDirectionRender>(_DRAW);
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::createEnemyINV(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo invertir controles
    Entity* enemy = mngr_->addEntity(_grp_ENEMIES_EFFECT);
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<InvertRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
    enemy->addComponent<RotationComponent>(_ROTATION);
}

void ofApp::collision() { // Metodo que gestiona todas las colisiones (menos entre jugadores)
    for (auto player : mngr_->getEntitiesByGroup(_grp_PLAYERS)) { // Para todos los players
        auto playerTr = player->getComponent<Transform>(_TRANSFORM);
        rect playerRect = { playerTr->getPos().getX(), playerTr->getPos().getY(), playerTr->getW(), playerTr->getH() };

        //Enemigos de daño
        for (auto enemy : mngr_->getEntitiesByGroup(_grp_ENEMIES_DAMAGE)) {
            auto enemyTr = enemy->getComponent<Transform>(_TRANSFORM);
            rect enemyRect = { enemyTr->getPos().getX(), enemyTr->getPos().getY(), enemyTr->getW(), enemyTr->getH() };
            if (collides(playerRect, enemyRect)) {// Si algun jugador colisiona con algun enemigo que haga daño se acaba el juego
                deleteAllEnemies();
                currentState = LOOSE;
                music.stop();
            }
        }

        //Enemigos de efecto
        for (auto enemyEffect : mngr_->getEntitiesByGroup(_grp_ENEMIES_EFFECT)) {
            auto enemyTr = enemyEffect->getComponent<Transform>(_TRANSFORM);
            rect enemyRect = { enemyTr->getPos().getX(), enemyTr->getPos().getY(), enemyTr->getW(), enemyTr->getH() };
            if (collides(playerRect, enemyRect)) {  // Si algun jugador colisiona llama a la funcion del efecto correspondiente y se destruye el enemigo
                enemyEffect->setAlive(false);
                player->getComponent<PlayerCtrl>(_CTRL)->invertInput();
            }
        }
    }
}

bool ofApp::collides(rect rect1, rect rect2) { // Colision por superposición de rectangulos
    bool noSuperposicionX = (rect1.x + rect1.w < rect2.x) || (rect2.x + rect2.w < rect1.x);
    bool noSuperposicionY = (rect1.y + rect1.h < rect2.y) || (rect2.y + rect2.h < rect1.y);
    // Si no hay superposición en alguno de los ejes, no hay colisión
    return !(noSuperposicionX || noSuperposicionY);
}

void ofApp::deleteAllEnemies() {
    for (auto enemy : mngr_->getEntitiesByGroup(_grp_ENEMIES_DAMAGE)) {
        enemy->setAlive(false);
    }
    for (auto enemyEff : mngr_->getEntitiesByGroup(_grp_ENEMIES_EFFECT)) {
        enemyEff->setAlive(false);
    }
}

void ofApp::resetGame() {
    for (auto player : mngr_->getEntitiesByGroup(_grp_PLAYERS)) {
        PlayerCtrl* ctrl = player->getComponent<PlayerCtrl>(_CTRL);
        if (ctrl->isInputInverted()) ctrl->invertInput();
    }
    currentState = PLAY;
    tiempoTranscurridoMs = 0;
}