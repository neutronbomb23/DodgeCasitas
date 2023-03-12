#include "PlayerCtrl.h"

PlayerCtrl::PlayerCtrl(pair<char, char> Keys, bool* KeysPressed) {
    up = false; down = false;
    keys = Keys;
    keysPressed = KeysPressed;
}

void PlayerCtrl::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
    pR = ent_->getComponent<PlayerRender>(_DRAW);
}

void PlayerCtrl::update() {

    if (ofGetKeyPressed(keys.first) && !ofGetKeyPressed(keys.second)) {
        tr->setVel(Vector2D(0, -1));
        pR->dirUp();
        
    }
    else if (ofGetKeyPressed(keys.second) && !ofGetKeyPressed(keys.first)) {
        tr->setVel(Vector2D(0, 1));
        pR->dirDown();
    }
    else(tr->setVel(Vector2D(0, 0)));
}