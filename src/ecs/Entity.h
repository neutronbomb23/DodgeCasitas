#pragma once

#include <array>
#include <vector>
#include <bitset>
#include "Component.h"
#include "Manager.h"
#include "ecs.h"


using namespace ecs;
using namespace std;

class Entity {
private:
	bool alive_;
	Manager* mngr_;
	vector<Component*> currCmps_;
	array<Component*, ecs::maxComponentId> cmps_;
	bitset<maxGroupId> groups_;

public:
	Entity() : mngr_(nullptr), cmps_(), currCmps_(), alive_() {
		currCmps_.reserve(ecs::maxComponentId);
	}

	virtual ~Entity() {
		for (auto it = currCmps_.begin(); it != currCmps_.end(); ++it) {
			delete (*it);
		}
	}

	inline void setContext(Manager* mngr) { mngr_ = mngr; }
	inline bool isAlive() { return alive_; }
	inline void setAlive(bool alive) { alive_ = alive; }

	template<typename T, typename ...Ts>
	inline T* addComponent(cmpId_type cId, Ts&... args) {
		T* c = new T(forward<Ts>(args)...);
		removeComponent(cId);
		currCmps_.push_back(c);
		cmps_[cId] = c;
		c->setContext(this, mngr_);
		c->initComponent();
		return c;
	}

	inline void removeComponent(ecs::cmpId_type cId) {
		if (cmps_[cId] != nullptr) {
			auto it = std::find(currCmps_.begin(), currCmps_.end(), cmps_[cId]);
			currCmps_.erase(it);
			delete cmps_[cId];
			cmps_[cId] = nullptr;
		}
	}

	template<typename T>
	inline T* getComponent(ecs::cmpId_type cId) {
		return static_cast<T*>(cmps_[cId]);
	}

	inline bool hasComponent(ecs::cmpId_type cId) {
		return cmps_[cId] != nullptr;
	}

	inline void addToGroup(grpId_type gId) {
		if (!groups_[gId]) groups_[gId] = true;
	}
	inline void removeFromGroup(grpId_type gId) {
		if (groups_[gId]) groups_[gId] = false;
	}
	inline bool hasGroup(grpId_type gId) {
		return groups_[gId];
	}

	inline void update() {
		int n = currCmps_.size();
		for (int i = 0; i < n; i++)
			currCmps_[i]->update();
	}

	inline void render() {
		int n = currCmps_.size();
		for (int i = 0; i < n; i++)
			currCmps_[i]->render();
	}
};