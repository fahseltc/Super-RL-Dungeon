#pragma once
#include "libtcod.hpp"
#include <vector>

struct GameTile
{
	bool passable;
	char image;
	TCODColor fg_color;
	TCODColor bg_color;
	GameTile() : 
		passable(true), 
		image('.'), 
		bg_color(TCODColor::grey),
		fg_color(TCODColor::white)
	{}	
};

class GameMap
{
public:
	GameMap(int w, int h);
	~GameMap();

	int width;
	int height;

	void render();
    bool is_passable(int x, int y);

protected:
	GameTile *tiles;

private:
	void set_noise();
};