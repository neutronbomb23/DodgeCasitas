#pragma once
#include "../ecs/ecs.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "../ofApp.h"
#include "Transform.h"

using namespace ecs;

class HorizontalEnemyRender : public Component {
private:
	ofColor color = ofColor(210, 0, 0);
	Transform* tr = nullptr;
public:
	HorizontalEnemyRender() {}
	~HorizontalEnemyRender() {}
	void initComponent();
	void update() {}
	void render();
};