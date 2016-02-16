#include "scene.h"

Scene::Scene(int w, int h)
{
	map_ = new GameMap(w, h);
	player_ = new Player(Point(2, 2), map_); // get rid of this map
	entities_.push(player_);

	// need data structure that stores the position and pointer of each entity
	// on the map
	std::vector< std::vector<Entity> > 
		position_entity_map(w, std::vector<Entity>(h));
	position_entity_map[player_->position_.x][player_->position_.y] = *player_;
}

Scene::~Scene()
{
	entities_.clearAndDelete();
	delete map_;
}

void Scene::Update()
{
	for (Entity *e : entities_)
	{
		// need to update position_entity_map in here.
		// Maybe find the entity, then update it, then afterwards update the 
		// map.
		e->Update();
	}
}

void Scene::Render()
{
	TCODConsole::root->clear();
	map_->Render();
	for (Entity *e : entities_)
	{
		e->Render();
	}
}

void Scene::UpdateEntity(Entity *e, int x, int y)
{
	// find entity, either by (x,y) or in the list of entities.
	// std::find ??
}

bool Scene::EntityExistsAt(int x, int y)
{
	// todo make this work
	return true;
}

Entity* Scene::GetEntity(int x, int y)
{
	return position_entity_map_[x][y];
}