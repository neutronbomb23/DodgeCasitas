#include "ofApp.h"

void ofApp::setup() {
    //ofToggleFullscreen(); // NO PONER PUNTOS DE INTERRUPCION CON ESTO DESCOMENTADO
    mngr_ = Manager::instance();
    createPlayer1();
    timeNextSpawn = ofGetCurrentTime().getAsMilliseconds() + delay;

    // Musica fondo
    music.load("./CaritaEmpapada.mp3");
}

void ofApp::update() {
    mngr_->update();
    mngr_->refresh();
    spawnEnemies();
    collision();
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
    Entity* player1 = mngr_->addEntity(_grp_PLAYERS);
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

void ofApp::createEnemyCD(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo cambio de dirección
    Entity* enemy = mngr_->addEntity(_grp_ENEMIES_DAMAGE);
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
    enemy->addComponent<ChangeDirectionComponent>(_CHANGEDIRECTION, nRows);
}

void ofApp::createEnemyINV(Vector2D Position, Vector2D Direction, int Speed, int Size) { // Enemigo invertir controles
    Entity* enemy = mngr_->addEntity(_grp_ENEMIES_EFFECT);
    enemy->addComponent<Transform>(_TRANSFORM, Position, Direction.normalize() * Speed, Size, Size);
    enemy->addComponent<PlayerRender>(_DRAW); // TEMP PARA PRUEBA
    enemy->addComponent<DisableOnExit>(_DISABLEONEXIT);
}

void ofApp::collision() { // Metodo que gestiona todas las colisiones (menos entre jugadores)
    for (auto player : mngr_->getEntitiesByGroup(_grp_PLAYERS)) { // Para todos los players
        auto playerTr = player->getComponent<Transform>(_TRANSFORM);
        rect playerRect = { playerTr->getPos().getX(), playerTr->getPos().getY(), playerTr->getW(), playerTr->getH() };
    
        //Enemigos de daño
        for (auto enemy: mngr_->getEntitiesByGroup(_grp_ENEMIES_DAMAGE)){
            auto enemyTr = enemy->getComponent<Transform>(_TRANSFORM);
            rect enemyRect = { enemyTr->getPos().getX(), enemyTr->getPos().getY(), enemyTr->getW(), enemyTr->getH() };
            if (collides(playerRect, enemyRect)) {// Si algun jugador colisiona con algun enemigo que haga daño se acaba el juego
                deleteAllEnemies();
                cout << "GAME OVER!" << endl;
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
    bool noSuperposicionX = (rect1.x + rect1.w< rect2.x) || (rect2.x + rect2.w < rect1.x);
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