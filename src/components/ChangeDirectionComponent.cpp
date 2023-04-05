#include "ChangeDirectionComponent.h"

void ChangeDirectionComponent::initComponent() {
	tr = ent_->getComponent<Transform>(_TRANSFORM);
}

void ChangeDirectionComponent::update() {

}