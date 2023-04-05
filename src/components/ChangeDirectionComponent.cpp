#include "ChangeDirectionComponent.h"

void ChangeDirectionComponent::initComponent() {
	tr = ent_->getComponent<Transform>(_TRANSFORM);
}

void ChangeDirectionComponent::update() {
	if (!activated && tr->getPos().getX() < ofGetWidth() * changeLine) {
		cout << "NEVERGONNAGIVEYOUUP" << nLineas << endl;
		// CAMBIO DE LINEA
		activated = true;
	}
}