#include "libtcod.hpp"
#include <vector>

struct GameTile
{
	bool passable;
	char image;
	GameTile() : passable(true), image('.') {}	
};

class GameMap
{
public:
	GameMap(int w, int h);
	~GameMap();

	int width;
	int height;

	void render();

protected:
	GameTile *tiles;
};