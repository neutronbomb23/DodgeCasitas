#include "ChangeDirectionRender.h"

void ChangeDirectionRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
}

void ChangeDirectionRender::render() {
    ofPushMatrix();
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotate(tr->getR());
    ofTranslate(-tr->getW() / 2, -tr->getH() / 2);

    // Dibujar el cuerpo de la flecha
    ofSetColor(0, 255, 0);
    ofDrawTriangle(0, 0, tr->getW() / 2, tr->getH(), tr->getW(), 0);
    ofPopMatrix();
}