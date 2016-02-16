#include "libtcod.hpp"
#include "GameMap.h"

GameMap::GameMap(int w, int h) : 
    width(w), height(h)
{
    // make map, single array
    tiles = new GameTile[width*height];

	set_noise();

    for (int i = 0; i < height; i++)
    {
        // left wall
        tiles[i * width].image = '#';
        tiles[i * width].passable = false;

        // right wall
        if (i != 0) 
        {
            tiles[(i * width) - 1].image = '#';  
            tiles[(i * width) - 1].passable = false;
        }
    }

    for (int i = 0; i < width; i++)
    {
        // top wall
        tiles[i].image = '#';
        tiles[i].passable = false;
        // bottom wall
        tiles[i + (width *(height - 1))].image = '#';
        tiles[i + (width *(height - 1))].passable = false;
    }   
}

GameMap::~GameMap()
{
    delete tiles;
}

void GameMap::render()
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
			GameTile tile = tiles[x + y * width];
            TCODConsole::root->setChar(x, y, tile.image);
            TCODConsole::root->setCharBackground(x, y, tile.bg_color);
			TCODConsole::root->setCharForeground(x, y, tile.fg_color);
        }
    }
}

bool GameMap::is_passable(int x, int y)
{
    return tiles[x + y*width].passable;
}

void GameMap::set_noise()
{
	TCODNoise* generator = new TCODNoise(2);
	generator->setType(TCOD_NOISE_PERLIN);
	const int div = 10;
	for (int x = 1; x < width - 1; x++)
	{
		for (int y = 1; y < height - 1; y++)
		{			
			float p[2] = { (float)x/div, (float)y/div };
			float result = generator->get(p);
			result += 1;
			// result is from 0-2
			if (result > 1.2f)
			{ // mountain?
				tiles[x + y * width].image = 'M';				
				set_colors(x, y, TCODColor::black, TCODColor::darkerRed);
			}
			else if (result > 0.8)
			{ // rocky?
				tiles[x + y * width].image = '*';
				set_colors(x, y, TCODColor::grey, TCODColor::lighterGreen);
			}
			else if (result > 0.7)
			{ // flat?

				tiles[x + y * width].image = '_';
				set_colors(x, y, TCODColor::blue, TCODColor::darkYellow);
			}
			else
			{
				set_colors(x, y, TCODColor::blue, TCODColor::blue);
			}
		}
	}
}

void GameMap::set_colors(int x, int y, TCODColor fg, TCODColor bg)
{
	GameTile *tile = &tiles[x + y * width];
	tile->fg_color = fg;
	tile->bg_color = bg;
}