#pragma once
#include "../ecs/ecs.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "../ofApp.h"
#include "Transform.h"

using namespace ecs;

class PlayerRender : public Component {
private:
	ofColor color;
	Transform* tr = nullptr;
	int dir = 0; // -1  abajo, 0 centro, 1 arriba

public:
	PlayerRender(ofColor Color = ofColor(150, 0, 255)) { color = Color; }
	~PlayerRender(){}
	void initComponent();
	void update() {}
	void render();
	void dirUp() { dir = 1; }
	void dirDown() { dir = -1; }
	void setColor(ofColor newColor) { color = newColor; }
};