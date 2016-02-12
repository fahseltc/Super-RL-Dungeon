#pragma once
#include "Entity.h"
#include "GameMap.h"
#include "Player.h"

class Scene
{
public:
	Scene(int w, int h);
	~Scene();	

	void update();
	void render();

	void update_entity(Entity*, int x, int y);

private:
	TCODList<Entity *> entities;
	GameMap *map;
	Player *player;
};