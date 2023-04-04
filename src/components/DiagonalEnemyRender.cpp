#include "DiagonalEnemyRender.h"

void DiagonalEnemyRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);

}

void DiagonalEnemyRender::render() {
    ofPushMatrix();
    ofSetColor(color);

    //Transformaciones
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotateDeg(tr->getR(), 0, 0, 1);
    ofTranslate(-tr->getW() / 2, -tr->getH() / 2);
    
    int nLados = 12;
    float radio = tr->getW()/2;
    float angulo = 360.0 / nLados;

    // Iniciamos el dibujo del polígono
    ofBeginShape();
    for (int i = 0; i < nLados; i++) {
        // Calculamos la posición del vértice
        float x = cos(ofDegToRad(angulo * i)) * radio;
        float y = sin(ofDegToRad(angulo * i)) * radio;
        // Añadimos el vértice al polígono
        x += tr->getW() / 2;
        y += tr->getH() / 2;

        // Añadimos el vértice al polígono
        ofVertex(x, y);
    }
    ofEndShape();

    ofPopMatrix();
}
