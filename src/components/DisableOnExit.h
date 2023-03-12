#pragma once

#include"../ecs/Entity.h"
#include"../ecs/Component.h"
#include"../sdlutils/SDLUtils.h"
#include "Transform.h"

class DisableOnExit :public Component {
private:
	Transform* tr = nullptr;
	int w = 0, h = 0;
	int WIN_W, WIN_H;

public:
	DisableOnExit(){}

	void initComponent() {
		tr = ent_->getComponent<Transform>(_TRANSFORM);
		w = tr->getW();
		h = tr->getH();
		WIN_W = sdlutils().width();
		WIN_H = sdlutils().height();
	}

	void update() { // Si un objeto con este componente sale de los limites de la ventana se destruye
		int x = tr->getPos().getX();
int y = tr->getPos().getY();
		if ((x < 0 - w) || (x + w > WIN_W) || (y <  0 - h) || (y > WIN_H + h)) {
			ent_->setAlive(false);
		}
	}
};