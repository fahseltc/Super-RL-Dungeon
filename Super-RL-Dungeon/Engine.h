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

	Scene scene_;

    TCODList<Entity *> entities_;
    Player *player_;
    GameMap *map_;

};

extern Engine engine;