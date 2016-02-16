#include "libtcod.hpp"
#include "game_map.h"

GameMap::GameMap(int w, int h) : 
    width_(w), height_(h)
{
    // make map, single array
    tiles_ = new GameTile[width_*height_];

	set_noise();

    for (int i = 0; i < height_; i++)
    {
        // left wall
        tiles_[i * width_].image = '#';
        tiles_[i * width_].passable = false;

        // right wall
        if (i != 0) 
        {
            tiles_[(i * width_) - 1].image = '#';  
            tiles_[(i * width_) - 1].passable = false;
        }
    }

    for (int i = 0; i < width_; i++)
    {
        // top wall
        tiles_[i].image = '#';
        tiles_[i].passable = false;
        // bottom wall
        tiles_[i + (width_ *(height_ - 1))].image = '#';
        tiles_[i + (width_ *(height_ - 1))].passable = false;
    }   
}

GameMap::~GameMap()
{
    delete tiles_;
}

void GameMap::Render()
{
    for (int x = 0; x < width_; x++)
    {
        for (int y = 0; y < height_; y++)
        {
			GameTile tile = tiles_[x + y * width_];
            TCODConsole::root->setChar(x, y, tile.image);
            TCODConsole::root->setCharBackground(x, y, tile.bg_color);
			TCODConsole::root->setCharForeground(x, y, tile.fg_color);
        }
    }
}

bool GameMap::is_passable(int x, int y) { return tiles_[x + y*width_].passable; }

void GameMap::set_noise()
{
	TCODNoise* generator = new TCODNoise(2);
	generator->setType(TCOD_NOISE_PERLIN);
	const int div = 10;
	for (int x = 1; x < width_ - 1; x++)
	{
		for (int y = 1; y < height_ - 1; y++)
		{			
			float p[2] = { (float)x/div, (float)y/div };
			float result = generator->get(p);
			result += 1;
			// result is from 0-2
			if (result > 1.2f)
			{ // mountain?
				tiles_[x + y * width_].image = 'M';				
				set_colors(x, y, TCODColor::black, TCODColor::darkerRed);
			}
			else if (result > 0.8)
			{ // rocky?
				tiles_[x + y * width_].image = '*';
				set_colors(x, y, TCODColor::grey, TCODColor::lighterGreen);
			}
			else if (result > 0.7)
			{ // flat?

				tiles_[x + y * width_].image = '_';
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
	GameTile *tile = &tiles_[x + y * width_];
	tile->fg_color = fg;
	tile->bg_color = bg;
}