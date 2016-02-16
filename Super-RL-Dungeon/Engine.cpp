#include "engine.h"

const int GLOBAL_WIDTH = 200;
const int GLOBAL_HEIGHT = 100;

Engine::Engine() :
	scene_(Scene(GLOBAL_WIDTH, GLOBAL_HEIGHT))
{
    TCODConsole::initRoot(GLOBAL_WIDTH, GLOBAL_HEIGHT, "SUPER-RL-DUNGEON", false);

    map_ = new GameMap(GLOBAL_WIDTH, GLOBAL_HEIGHT);
    player_ = new Player(Point(2, 2), map_);
    entities_.push(player_);    
}

Engine::~Engine()
{
    entities_.clearAndDelete();
    delete map_;
}

void Engine::update()
{
    for (Entity *e : entities_)
    {
        e->update();
    }
}

void Engine::render()
{
    TCODConsole::root->clear();
    map->render();
    for (Entity *e : entities_)
    {
        e->render();
    }
}
