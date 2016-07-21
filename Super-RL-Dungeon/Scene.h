#pragma once
#include "entity.h"
#include "game_map.h"
#include "player.h"
#include <vector>
#include <unordered_map>
#include "GUI.h"

// This class holds entities and the game map, and acts as a bridge between the 
// two of them. This allows us to have a broader look at where the entities 
// are, and gives them a single place to look for collisions and positions of 
// other entities.

class Scene
{
public:
    Scene(int w, int h);
    ~Scene();	

    // Iterates over the entity list and updates everything
    void Update();

    // Iterates over the entity list and map to draw them on the screen.
    void Render();

    // Updates the position_entity_map for a single entity
    void UpdateEntity(Entity*, int x, int y);

    // Checks if an entity exists at a given Point
    bool EntityExistsAt(int x, int y);

    // Returns an entity from a Point. Used with above to ensure one exists.
    Entity* GetEntity(int x, int y);

private:
    //
    // VARIABLES
    //
    TCODList<Entity *> entities_;
    GameMap *map_;
    Player *player_;
    GUI *gui;


    //
    // METHODS
    //

    void HandleInput();

};