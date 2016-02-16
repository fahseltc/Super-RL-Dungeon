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
    
    void Update();
    void Render();

private:
	Scene scene_;
};

extern Engine engine;