#pragma once
#include "../ecs/ecs.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "../ofApp.h"
#include "Transform.h"

using namespace ecs;

class InvertPutoRender : public Component {
private:
	ofColor color = ofColor(50, 10, 200);
	Transform* tr = nullptr;
public:
	InvertPutoRender() {}
	~InvertPutoRender() {}
	void initComponent();
	void update() {}
	void render();
};