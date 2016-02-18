#include "scene.h"
#include <iostream>

Scene::Scene(int w, int h)
{
    map_ = new GameMap(w, h);
    player_ = new Player(Point(2, 2), map_); // get rid of this map
    entities_.push(player_);

    // need data structure that stores the position and pointer of each entity
    // on the map

}

Scene::~Scene()
{
    entities_.clearAndDelete();
    delete map_;
}

void Scene::HandleInput()
{
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

    int future_x = player_->position_.x;
    int future_y = player_->position_.y;

    switch (key.vk)
    {
    case TCODK_UP: future_y--; break;
    case TCODK_DOWN: future_y++; break;
    case TCODK_LEFT: future_x--; break;
    case TCODK_RIGHT: future_x++; break;
    }

    // check if we can move to future x,y
    if (map_->is_passable(future_x, future_y))
    {
        player_->position_.x = future_x;
        player_->position_.y = future_y;
    }
}

void Scene::Update()
{
    HandleInput();

    for (Entity *e : entities_)
    {
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
    // TODO make this work
    return true;
}

Entity* Scene::GetEntity(int x, int y)
{
    return player_; // temp
}