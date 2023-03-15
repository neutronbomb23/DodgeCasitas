#pragma once

#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../ofApp.h"
#include "Transform.h"

class DisableOnExit :public Component {
private:
	Transform* tr = nullptr;
	int w = 0;

public:
	DisableOnExit(){}

	void initComponent() {
		tr = ent_->getComponent<Transform>(_TRANSFORM);
		w = tr->getW();
	}

	void update() { // Si un objeto con este componente sale de los limites de la ventana se destruye
		int x = tr->getPos().getX();
		if (x < 0 - w) {
			ent_->setAlive(false);
			cout << "delete";
		}
	}
};