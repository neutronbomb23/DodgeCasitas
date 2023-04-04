#pragma once
#include "../ofApp.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "Transform.h"

class RotationComponent : public Component {
private:
	Transform* tr;
	int delayTime = 25;
	int timeNextUpdate = delayTime;
public:
	void initComponent();
	void update();
};