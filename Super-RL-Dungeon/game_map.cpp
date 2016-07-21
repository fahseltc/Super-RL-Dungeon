#include "libtcod.hpp"
#include "game_map.h"
#include "engine.h"

GameMap::GameMap(int w, int h) : 
    width_(w), height_(h)
{
    con = new TCODConsole(w, h);

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
    con->setDefaultBackground(TCODColor::black);
    con->clear();

    for (int x = 0; x < width_; x++)
    {
        for (int y = 0; y < height_; y++)
        {
			GameTile tile = tiles_[x + y * width_];
            con->setChar(x, y, tile.image);
            con->setCharBackground(x, y, tile.bg_color);
            con->setCharForeground(x, y, tile.fg_color);
        }
    }
    // blit the GUI console on the root console
    TCODConsole::blit(con, 0, 0, width_, height_,
        TCODConsole::root, 0, 3);
}

bool GameMap::is_passable(int x, int y) 
{ 
	return tiles_[x + (y-3) *width_].passable; 
}

void GameMap::set_noise()
{
	TCODNoise* generator = new TCODNoise(2);
	generator->setType(TCOD_NOISE_PERLIN);
    TCODRandom* rand = TCODRandom::getInstance();
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
				set_colors(x, y, TCODColor::black, TCODColor::lightestYellow);
			}
			else if (result > 0.8)
			{ // rocky?
                int period_or_not = rand->getInt(0, 10, 0);
                if(period_or_not > 9)
				    tiles_[x + y * width_].image = '.';

				set_colors(x, y, TCODColor::grey, TCODColor::lightestYellow);
			}
			else if (result > 0.7)
			{ // flat?

				tiles_[x + y * width_].image = ',';
				set_colors(x, y, TCODColor::blue, TCODColor::lightestYellow);
			}
			else
			{
                tiles_[x + y * width_].image = '~';
				set_colors(x, y, TCODColor::blue, TCODColor::desaturatedCyan);
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