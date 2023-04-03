#pragma once
#include "../ecs/ecs.h"
#include "../ofApp.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "Transform.h"

class PlayerRender;

using namespace ecs;

class PlayerCtrl : public Component {
private:
	Transform* tr = nullptr;
	PlayerRender* im = nullptr;

	pair<char, char> keys;
	double movementDistance;
	// Input
	int timeBetweenInputs = 500; 
	int timeNextInput;
	bool up = false; bool down = false;

public:
	PlayerCtrl(){}
	PlayerCtrl(pair<char, char> Keys);
	~PlayerCtrl() {}
	void initComponent();
	void update();
};