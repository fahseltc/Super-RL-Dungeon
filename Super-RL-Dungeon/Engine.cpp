#include "Engine.h"

Engine::Engine() :
	scene(Scene(80,50))
{
    TCODConsole::initRoot(80, 50, "SUPER-RL-DUNGEON", false);

    map = new GameMap(80, 50);
    player = new Player(Point(2, 2), map);
    entities.push(player);    
}

Engine::~Engine()
{
    entities.clearAndDelete();
    delete map;
}

void Engine::update()
{
    for (Entity *e : entities)
    {
        e->update();
    }
}

void Engine::render()
{
    TCODConsole::root->clear();
    map->render();
    for (Entity *e : entities)
    {
        e->render();
    }
}
