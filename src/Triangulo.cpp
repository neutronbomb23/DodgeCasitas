#include "Triangulo.h"

void Triangulo::setup(float posX, float posY, ofColor color) {
    posicion = ofVec2f(posX, posY);
    this->color = color;
}

void Triangulo::update(float velocidad, bool moverArriba) {
    if (moverArriba) {
        invertir = false;
        posicion.y -= velocidad;
    }
    else {
        invertir = true;
        posicion.y += velocidad;
    }
}

void Triangulo::draw() {
    ofPushMatrix();
    ofTranslate(posicion);
    if (invertir) {
        ofRotateXDeg(180);
    }
    ofSetColor(color);
    ofDrawTriangle(0, 0, 20, 40, -20, 40);
    ofPopMatrix();
}
