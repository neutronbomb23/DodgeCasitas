#pragma once
#include <array>
#include <vector>
#include "../utils/Singleton.h"
#include "../ecs/ecs.h"

using namespace ecs;
using namespace std;

class Entity;

class Manager : public Singleton <Manager> { 	
private:
	array<vector<Entity*>, maxGroupId> entsByGroup_;
public:
	Manager();
	virtual ~Manager();

	Entity* addEntity(grpId_type gId = _grp_GENERAL);

	inline const auto& getEntitiesByGroup(grpId_type gId) {
		return entsByGroup_[gId];
	}

	void refresh();
	void update();
	void render();
};