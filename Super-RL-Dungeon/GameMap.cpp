#include "libtcod.hpp"
#include "GameMap.h"
#include <vector>

GameMap::GameMap(int w, int h) : 
    width(w), height(h)
{
    // make map, single array
    tiles = new GameTile[width*height];

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
            TCODConsole::root->setChar(x, y, tiles[x + y * width].image);
            TCODConsole::root->setCharBackground(x, y, TCODColor::grey);
        }
    }
}

bool GameMap::is_passable(int x, int y)
{
    return tiles[x + y*width].passable;
}