#pragma once
#include "ofApp.h"
#include "../ecs/Entity.h"
#include "../ecs/Component.h"
#include "Transform.h"

class ScreenBounce : public Component {
private:
	Transform* tr = nullptr;
	Vector2D collisionVector;

public:
	ScreenBounce(){}

	void initComponent() {
		tr = ent_->getComponent<Transform>(_TRANSFORM);
	}

	void update() {
		if (tr->getPos().getY() >= ofGetHeight() - tr->getH()) { collisionVector = Vector2D(0, -1); }
		else if (tr->getPos().getY() <= 0) { collisionVector = Vector2D(0, 1); }
		else { collisionVector = Vector2D(0, 0); }
		tr->setVel(tr->getVel() - (collisionVector * ((tr->getVel() * collisionVector) * 2)));
		cout << tr->getPos().getX() << " " << tr->getPos().getY() << endl;
	}
};