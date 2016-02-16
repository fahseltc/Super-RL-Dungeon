#include "scene.h"

Scene::Scene(int w, int h)
{
	map = new GameMap(w, h);
	player = new Player(Point(2, 2), map); // get rid of this map
	entities.push(player);

	// need data structure that stores the position and pointer of each entity on the map
	std::vector< std::vector<Entity> > position_entity_map(w, std::vector<Entity>(h));
	position_entity_map[player->m_position.x][player->m_position.y] = *player;
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
		// need to update position_entity_map in here.
		// Maybe find the entity, then update it, then afterwards update the map.
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

bool Scene::entity_at(int x, int y)
{
	// todo make this work
	return true;
}

Entity* Scene::get_entity(int x, int y)
{
	return position_entity_map[x][y];
}