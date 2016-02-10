#include "Engine.h"

Engine::Engine()
{
    TCODConsole::initRoot(80, 50, "SUPER-RL-DUNGEON", false);
    player = new Player(Point(2, 2));
    entities.push(player);
    map = new GameMap(80, 50);
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
