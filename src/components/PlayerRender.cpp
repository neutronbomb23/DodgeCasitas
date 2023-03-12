#include "PlayerRender.h"

void PlayerRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
   
}

void PlayerRender::render() {
    ofPushMatrix();
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    if (dir == -1) {
        ofRotateXDeg(180);
    }
    ofSetColor(color);
    ofDrawTriangle(0, 0, 20, 40, -20, 40);
    ofPopMatrix();
}
