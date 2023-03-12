#include "ShowAtOpposideSide.h"

ShowAtOppositeSide::ShowAtOppositeSide() : Component() {

}

void ShowAtOppositeSide::initComponent() {
	tr = ent_->getComponent<Transform>(_TRANSFORM);
	W_WIDTH = ofGetScreenWidth();
	W_HEIGHT = ofGetScreenHeight();
	w = tr->getW();
	h = tr->getH();
	
}

void ShowAtOppositeSide::update() { // Si la entidad se sale de los limites de la ventana aparece por el lado opuesto
	Vector2D pos = tr->getPos();

	// Comprueba eje X
	if (pos.getX() > W_WIDTH) { tr->setPosX(0 - w); }
	else if (pos.getX() < 0 - w) { tr->setPosX(W_WIDTH); }

	// Comprueba eje Y
	if (pos.getY() > W_HEIGHT) { tr->setPosY(0 - h); }
	else if(pos.getY() < 0 - h) { tr->setPosY(W_HEIGHT); }
}