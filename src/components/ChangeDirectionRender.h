#pragma once
#include "../ofApp.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "Transform.h"

class  ChangeDirectionComponent;

using namespace ecs;

class ChangeDirectionRender : public Component {
private:
	Transform* tr = nullptr;
	ChangeDirectionComponent* ch = nullptr;
	// Color
	ofColor color = ofColor(210, 0, 0);
	// Trail
	vector<ofVec2f> trail;
	int trailLength = 50;

public:	
	void initComponent();
	void render();
};