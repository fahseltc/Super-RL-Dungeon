#include "Scene.h"

Scene::Scene(int w, int h)
{
	map = new GameMap(w, h);
	player = new Player(Point(2, 2), map); // get rid of this map
	entities.push(player);

	// need data structure that stores the position and pointer of each entity on the map
}

Scene::~Scene()
{
	entities.clearAndDelete();
	delete map;
}

void Scene::update()
{
	for (Entity *e : entities)
	{
		e->update();
	}
}

void Scene::render()
{
	TCODConsole::root->clear();
	map->render();
	for (Entity *e : entities)
	{
		e->render();
	}
}

void Scene::update_entity(Entity *e, int x, int y)
{
	// find entity, either by (x,y) or in the list of entities.
	// std::find ??
}
