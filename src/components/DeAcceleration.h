#pragma once
#include "../ecs/ecs.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "Transform.h"

using namespace ecs;

class DeAcceleration : public Component{
private:
	Transform* tr = nullptr;
	float deaccelerationFactor;
	float limit;
public:
	DeAcceleration(float DeacelerationFactor = 0.995f, float Limit = 0.005);
	~DeAcceleration();
	void initComponent();
	void update();
};