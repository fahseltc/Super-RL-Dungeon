#include "entity.h"

Entity::Entity()
{
    position_ = Point();
}

Entity::Entity(Point p)
{
    position_ = p;
}

void Entity::Update() {};
void Entity::Render() {};

void Entity::set_icon(char c){ icon_ = c; }