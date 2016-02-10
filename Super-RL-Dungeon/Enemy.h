#pragma once
#include "Entity.h"
#include "GameMap.h"

class Enemy : public Entity
{
public:
	Enemy(Point p, );
	~Enemy();

	void update();
	void render();

private:
	GameMap *map;
};