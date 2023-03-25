#include "PlayerRender.h"

void PlayerRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
   
}

void PlayerRender::render() {
    ofPushMatrix();
    ofSetColor(color);
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    if (dir == -1) { ofRotateXDeg(180); }
    ofDrawTriangle(0, 0, tr->getW() / 2, tr->getH(), -tr->getW() / 2, tr->getH());
    ofPopMatrix();
}
