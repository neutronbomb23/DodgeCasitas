
#pragma once
#include "../ecs/ecs.h"
#include "../ofApp.h"
#include "PlayerRender.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "Transform.h"

using namespace ecs;
class PlayerCtrl : public Component {
private:
	Transform* tr = nullptr;
	bool up; bool down;
	pair<char, char> keys;
	bool* keysPressed;
	PlayerRender* pR = nullptr;

public:
	
	PlayerCtrl(){}
	PlayerCtrl(pair<char, char> Keys, bool* KeysPressed);
	~PlayerCtrl() {}
	void initComponent();
	void update();
};