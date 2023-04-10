#pragma once
#include "../ofApp.h"
#include "../ecs/ecs.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "Transform.h"

class PlayerRender;

using namespace ecs;

class PlayerCtrl : public Component {
private:
	Transform* tr = nullptr;
	Transform* coopTr = nullptr;
	PlayerRender* im = nullptr;

	pair<char, char> keys;
	double movementDistance;
	// Input
	int timeBetweenInputs = 200; 
	int timeNextInput;
	bool keyPressed = false;
	// InputInvertido
	bool invertedInput = false;
	int timeUntilNormalInput;
	int timeEffect = 4000;

public:
	PlayerCtrl(){}
	PlayerCtrl(pair<char, char> Keys);
	~PlayerCtrl() {}
	void initComponent();
	void update();
	void invertInput();
	void setCoopRef(Transform* COOP);
};