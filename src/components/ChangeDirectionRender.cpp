#include "ChangeDirectionRender.h"
#include "ChangeDirectionComponent.h"

void ChangeDirectionRender::initComponent() {
    tr = ent_->getComponent<Transform>(_TRANSFORM);
    ch = ent_->getComponent<ChangeDirectionComponent>(_CHANGEDIRECTION);
}

void ChangeDirectionRender::render() {
    ofTranslate(tr->getPos().getX(), tr->getPos().getY());
    ofRotateDeg(tr->getR(), 0, 0, 1);
    ofTranslate(-tr->getW() / 2, -tr->getH() / 2);
    // Dibujar el cuerpo de la flecha
    ofSetColor(0, 255, 0);
    ofDrawTriangle(
        tr->getW() * 0.1, tr->getH() / 2, // Punto izquierdo
        tr->getW() * 0.9, tr->getH() / 4, // Punto superior
        tr->getW() * 0.9, tr->getH() * 0.75); // Punto inferior
    // Dibujar la punta de la flecha
    ofSetColor(255, 0, 0);
    ofDrawTriangle(
        tr->getW() * 0.9, tr->getH() * 0.25, // Punto superior
        tr->getW() * 0.9, tr->getH() * 0.75, // Punto inferior
        tr->getW(), tr->getH() / 2); // Punto derecho


    if (ch->getDir() == -1) { // Punta hacia arriba
        ofDrawTriangle(
            tr->getW() * 0.25, tr->getH() * 0.9, // Punto izquierdo
            tr->getW() * 0.75, tr->getH() * 0.9, // Punto derecho
            tr->getW() / 2, tr->getH() * 0.75); // Punto inferior
        
    }
    if (ch->getDir() == 1) { // Punta hacia abajo
        ofDrawTriangle(
            tr->getW() * 0.25, tr->getH() * 0.1, // Punto izquierdo
            tr->getW() * 0.75, tr->getH() * 0.1, // Punto derecho
            tr->getW() / 2, tr->getH() * 0.25); // Punto superior
    }
}