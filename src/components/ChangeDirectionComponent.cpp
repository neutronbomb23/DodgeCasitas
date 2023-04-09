#include "ChangeDirectionComponent.h"

void ChangeDirectionComponent::initComponent() {
	tr = ent_->getComponent<Transform>(_TRANSFORM);
	movementDistance = ofGetHeight() / nLineas;
	if (tr->getPos().getY() < movementDistance * 2) dir = 1;
	else if (tr->getPos().getY() > movementDistance * (nLineas - 1)) dir = -1;
	else if (rand() % 2) { dir = -1; }
	else { dir = 1; }
}

void ChangeDirectionComponent::update() {
	if (!activated && tr->getPos().getX() < ofGetWidth() * changeLine) {
		tr->setPos(Vector2D(tr->getPos().getX(), tr->getPos().getY() + movementDistance * dir)); // Desplaza
		activated = true;
	}
}