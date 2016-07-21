#include "scene.h"
#include <iostream>

Scene::Scene(int w, int h)
{
    map_ = new GameMap(w, h - 3);
    gui = new GUI();
    player_ = new Player(Point(5, 5), map_); // get rid of this map
    entities_.push(player_);
    entities_.push(new Player(Point(7, 7), map_));

    // need data structure that stores the position and pointer of each entity
    // on the map

}

Scene::~Scene()
{
    entities_.clearAndDelete();
    delete map_;
    delete gui;
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
    case TCODK_ESCAPE: exit(0);
    }

    if (key.c == 'w') { future_y--; }
    if (key.c == 's') { future_y++; }
    if (key.c == 'a') { future_x--; }
    if (key.c == 'd') { future_x++; }

    // check if we can move to future x,y
    if (future_x == player_->position_.x && future_y == player_->position_.y)
    {
        // we arent moving
        return;
    }

    if (EntityExistsAt(future_x, future_y))
    {
        std::cout << "THERE IS SOMETHING THERE AT: (" << future_x << ", " << future_y << ").\n";
        return;
    }

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
    gui->render();
}

void Scene::UpdateEntity(Entity *e, int x, int y)
{
    // find entity, either by (x,y) or in the list of entities.
    // std::find ??
}

bool Scene::EntityExistsAt(int x, int y)
{
    for (Entity *e : entities_)
    {
        if (e->position_.x == x && e->position_.y == y) { return true; }
    }
    return false;
}

Entity* Scene::GetEntity(int x, int y)
{
    if (EntityExistsAt(x, y))
    {
        for (Entity *e : entities_)
        {
            if (e->position_.x == x && e->position_.y == y) { return e; }
        }
    }
    else { return nullptr; }
}