#pragma once
#include "Entity.h"
#include "libtcod.hpp"
#include "GameMap.h"
#include "Player.h"

class Engine
{
public:
    Engine();
    ~Engine();
    
    void update();
    void render();

private:
    TCODList<Entity *> entities;
    Player *player;
    GameMap *map;

};

extern Engine engine;