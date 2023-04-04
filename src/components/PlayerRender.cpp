#include "PlayerRender.h"

void PlayerRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
   
}

void PlayerRender::render() {
    ofPushMatrix();
    ofSetColor(color);

    if (dir == -1) { tr->setR(180); }
    else { tr->setR(0); }

    //Transformaciones
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotateDeg(tr->getR(), 0, 0, 1);
    ofTranslate(-tr->getH() / 2, -tr->getW() / 2);

    ofDrawTriangle(0, 0, tr->getW() / 2, tr->getH(), tr->getW(), 0);
    ofPopMatrix();
}
