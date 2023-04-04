#include "RotationComponent.h"

void RotationComponent::initComponent() {
	tr = ent_->getComponent<Transform>(_TRANSFORM);
}

void RotationComponent::update() {
	if (ofGetCurrentTime().getAsMilliseconds() >= timeNextUpdate) {
		tr->setR(tr->getR() + 1);
		timeNextUpdate = ofGetCurrentTime().getAsMilliseconds() + delayTime;
	}
}