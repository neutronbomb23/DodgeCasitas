#pragma once

#include <vector>
#include "../utils/Singleton.h"

using namespace std;

class Entity;

class Manager : public Singleton <Manager> { 	
private:
	vector<Entity*> ents_;
public:
	Manager();
	virtual ~Manager();

	Entity* addEntity();

	inline const auto& getEntities() { return ents_; }

	void refresh();
	void update();
	void render();
};