#include "engine.h"

const int GLOBAL_WIDTH = 200;
const int GLOBAL_HEIGHT = 100;

Engine::Engine() :
	scene(Scene(GLOBAL_WIDTH, GLOBAL_HEIGHT))
{
    TCODConsole::initRoot(GLOBAL_WIDTH, GLOBAL_HEIGHT, "SUPER-RL-DUNGEON", false);

    map = new GameMap(GLOBAL_WIDTH, GLOBAL_HEIGHT);
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
