#include "PlayerCtrl.h"
#include "PlayerRender.h"

PlayerCtrl::PlayerCtrl(pair<char, char> Keys) {
    up = false; down = false;
    keys = Keys;
}

void PlayerCtrl::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
    im = ent_->getComponent<PlayerRender>(_DRAW);
    timeNextInput = 0;
}

void PlayerCtrl::update() {
    movementDistance = ofGetHeight() / 4;
    
    if (ofGetKeyPressed(keys.first)) { // Tecla correspondiente pulsada
        up = true;
    }
    else if (ofGetKeyPressed(keys.second)) { // Tecla correspondiente pulsada
        down = true;
    }

    if (ofGetCurrentTime().getAsMilliseconds() >= timeNextInput) {
        if (up) {
            if (tr->getPos().getY() - movementDistance > 0) { // No se sale de los limites
                tr->setPos(Vector2D(tr->getPos().getX(), tr->getPos().getY() - movementDistance)); // Desplaza
                im->dirUp(); // Cambia la direccion (Para renderizar)
            }
            up = false;
        }
    else if (down) {
        if (tr->getPos().getY() + movementDistance < ofGetHeight()) { // No se sale de los limites
            tr->setPos(Vector2D(tr->getPos().getX(), tr->getPos().getY() + movementDistance)); // Desplaza
            im->dirDown(); // Cambia la direccion (Para renderizar)
        }
        down = false;
    }
    timeNextInput = ofGetCurrentTime().getAsMilliseconds() + timeBetweenInputs;
    }
}