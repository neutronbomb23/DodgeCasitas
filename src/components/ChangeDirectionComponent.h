#pragma once
#include "../ofApp.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "Transform.h"

class ChangeDirectionComponent : public Component {
private:
	Transform* tr;
	bool activated = false;
	int nLineas;
	float changeLine = 0.375; // Porcentaje/100 de la linea que tiene que quedar para que cambie
	float movementDistance;
	int dir;

public:
	ChangeDirectionComponent(int NLINEAS) :nLineas(NLINEAS) {}
	void initComponent();
	void update();
	int getDir() { return dir; }
};