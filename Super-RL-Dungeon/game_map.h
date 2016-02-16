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
	GameMap(int, int);
	~GameMap();

	int width_;
	int height_;

	void Render();
    bool is_passable(int, int);

protected:
	GameTile *tiles_;

private:
	void set_noise();
	void set_colors(int, int, TCODColor, TCODColor);
};