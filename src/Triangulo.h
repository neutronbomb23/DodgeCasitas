#pragma once

#include "ofMain.h"

class Triangulo {
public:
    void setup(float posX, float posY, ofColor color);
    void update(float velocidad, bool moverArriba);
    void draw();

    ofVec2f posicion;

private:
    ofColor color;
    bool invertir = false;
};
