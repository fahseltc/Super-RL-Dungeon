#pragma once
#include "entity.h"
#include "libtcod.hpp"
#include "game_map.h"
#include "player.h"

#include "Scene.h"

class Engine
{
public:
    Engine();
    ~Engine();
    
    void update();
    void render();

private:

	Scene scene;

    TCODList<Entity *> entities;
    Player *player;
    GameMap *map;

};

extern Engine engine;