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
	Transform* tr = nullptr;
	ofColor color = ofColor(210, 0, 0);
	//Trail
	vector<ofVec2f> trail;
	int trailLength = 50;
public:
	HorizontalEnemyRender() {}
	~HorizontalEnemyRender() {}
	void initComponent();
	void update();
	void render();
};