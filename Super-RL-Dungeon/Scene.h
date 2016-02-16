#pragma once
#include "entity.h"
#include "game_map.h"
#include "player.h"
#include <vector>

class Scene
{
public:
	Scene(int w, int h);
	~Scene();	

	void Update();
	void Render();

	void UpdateEntity(Entity*, int x, int y);
	bool EntityExistsAt(int x, int y);
	Entity* GetEntity(int x, int y);

private:
	TCODList<Entity *> entities_;
	GameMap *map_;
	Player *player_;
	std::vector< std::vector<Entity*> > position_entity_map_;
};