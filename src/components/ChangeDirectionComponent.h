#pragma once
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "Transform.h"

class ChangeDirectionComponent : public Component {
private:
	Transform* tr;
public:
	void initComponent();
	void update();
};