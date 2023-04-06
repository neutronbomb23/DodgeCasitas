#include "HorizontalEnemyRender.h"

void HorizontalEnemyRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);

}

void HorizontalEnemyRender::update() {
    // Añade la posición actual de la figura a la lista de puntos
    trail.push_back(ofVec2f(tr->getPos().getX(), tr->getPos().getY()));

    // Si la lista de puntos es más larga que la longitud del rastro deseado, elimina el punto más antiguo
    if (trail.size() > trailLength) {
        trail.erase(trail.begin());
    }
}

void HorizontalEnemyRender::render() {
    for (int i = 0; i < trail.size(); i++) { // Trail
        float size = 0 + (tr->getH() / trailLength) * i;
        float spacing = size / 3;
        color.a = 0 + (255 / trailLength) * i;
        ofSetColor(color);
  
        ofPushMatrix();
        // Transformaciones
        ofTranslate(trail[i]);
        ofRotate(45);
        ofTranslate(-size / 2, -size / 2);
        //Pintado
        ofDrawRectangle(0, 0, size, size);
        ofPopMatrix();
    }
    color.a = 255;
    ofSetColor(color);

    // Figura
    ofPushMatrix();
    // Transformaciones
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotateDeg(45, 0, 0, 1);
    ofTranslate(-tr->getW() / 2, -tr->getH() / 2);  
    //Pintado
    ofDrawRectangle(0, 0, tr->getW(), tr->getH());
    ofPopMatrix();
}