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

        // right wall
        if (i != 0) 
            tiles[(i * width) - 1].image = '#';       
    }

    for (int i = 0; i < width; i++)
    {
        // top wall
        tiles[i].image = '#';
        // bottom wall
        tiles[i + (width *(height-1))].image = '#';
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
        }
    }
}