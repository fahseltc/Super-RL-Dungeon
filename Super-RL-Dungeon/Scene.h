#pragma once
#include "Entity.h"
#include "GameMap.h"
#include "Player.h"
#include <vector>

class Scene
{
public:
	Scene(int w, int h);
	~Scene();	

	void update();
	void render();

	void update_entity(Entity*, int x, int y);
	bool entity_at(int x, int y);
	Entity* get_entity(int x, int y);

private:
	TCODList<Entity *> entities;
	GameMap *map;
	Player *player;
	std::vector< std::vector<Entity*> > position_entity_map;
};