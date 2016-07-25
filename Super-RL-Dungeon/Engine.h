#pragma once
#include "entity.h"
#include "libtcod.hpp"
#include "game_map.h"
#include "player.h"

#include "Scene.h"

class Engine
{
public:

    // Global game width in characters
    static const int kGlobalWidth = 50;

    // Global game height in characters
    static const int kGlobalHeight = 20;

    Engine();
    ~Engine();

    void Update();
    void Render();

private:
	Scene scene_;
};

extern Engine engine;