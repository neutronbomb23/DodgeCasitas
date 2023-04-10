#include "InvertRender.h"

void InvertRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
}

void InvertRender::render() {
    ofPushMatrix();
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotateDeg(tr->getR(), 0, 0, 1);
    ofTranslate(-tr->getW() / 2, -tr->getH() / 2);

    // Dibujar el círculo amarillo
    ofSetColor(255, 255, 0);
    ofDrawCircle(tr->getW() / 2, tr->getH() / 2, tr->getW() / 2);

    // Dibujar los ojos
    ofSetColor(0);
    ofDrawCircle(tr->getW() / 2 - tr->getW() / 6, tr->getH() / 2 - tr->getW() / 6, tr->getW() / 10); // Ojo izquierdo
    ofDrawCircle(tr->getW() / 2 + tr->getW() / 6, tr->getH() / 2 - tr->getW() / 6, tr->getW() / 10); // Ojo derecho

    ofDrawCurve(tr->getW() / 2 - tr->getW() / 6, tr->getH() / 2 + tr->getW() / 6,
        tr->getW() / 2 - tr->getW() / 12, tr->getH() / 2 + tr->getW() / 3,
        tr->getW() / 2 + tr->getW() / 12, tr->getH() / 2 + tr->getW() / 3,
        tr->getW() / 2 + tr->getW() / 6, tr->getH() / 2 + tr->getW() / 6);
    ofPopMatrix();
}