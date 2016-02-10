#pragma once
#include "Entity.h"
#include "Point.h"
#include "GameMap.h"

class Player : public Entity
{
public:
	Player(Point p, GameMap *map_in);
    GameMap *map;

	void update();
	void render();
	void handle_input();

private:
};