#pragma once
#include "entity.h"
#include "point.h"
#include "game_map.h"

class Player : public Entity
{
public:
    Player(Point p, GameMap *map_in);
    GameMap *map_;

    void Update();
    void Render();

private:
};