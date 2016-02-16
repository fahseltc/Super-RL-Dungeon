#pragma once
#include "entity.h"
#include "point.h"
#include "game_map.h"

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