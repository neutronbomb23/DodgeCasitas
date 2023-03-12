#pragma once

class Entity;

#include "Manager.h"

class Component {
protected:
	Entity* ent_;
	Manager* mngr_;

public:
	Component() { ent_ = nullptr; mngr_ = nullptr; }
	virtual ~Component() { }
	inline void setContext(Entity* ent, Manager* mngr) {
		ent_ = ent;
		mngr_ = mngr;
	}
	//…
	virtual void initComponent() { }
	virtual void update() { }
	virtual void render() { }
};