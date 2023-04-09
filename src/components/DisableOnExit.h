#pragma once

#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../ofApp.h"
#include "Transform.h"

class DisableOnExit :public Component {
private:
	Transform* tr = nullptr;
	int w = 0;
	int offset = 100; // espacio extra para que desaparezcan los trails de pantalla

public:
	DisableOnExit(){}

	void initComponent() {
		tr = ent_->getComponent<Transform>(_TRANSFORM);
		w = tr->getW();
	}

	void update() { // Si un objeto con este componente sale de los limites de la ventana se destruye
		if (tr->getPos().getX() < 0 - w - offset) {
			ent_->setAlive(false);
		}
	}
};