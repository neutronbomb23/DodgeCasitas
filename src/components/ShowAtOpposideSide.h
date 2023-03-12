#pragma once

#include "../ecs/Entity.h"
#include "../ofApp.h"
#include "../ecs/Component.h"
#include "Transform.h"

class ShowAtOppositeSide : public Component {
private: 
	Transform* tr = nullptr;
	float W_WIDTH;
	float W_HEIGHT;
	float w;
	float h;

public:
	ShowAtOppositeSide();
	void initComponent();

	void update();
};
