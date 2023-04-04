#include "HorizontalEnemyRender.h"

void HorizontalEnemyRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);

}

void HorizontalEnemyRender::render() {
    ofPushMatrix();
    ofSetColor(color);

    //Transformaciones
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotateDeg(tr->getR(), 0, 0, 1);
    ofTranslate(-tr->getH() / 2, -tr->getW() / 2);

    ofDrawRectangle(0, 0, tr->getW(), tr->getH());
    ofPopMatrix();
}
