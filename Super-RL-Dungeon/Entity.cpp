#include "Entity.h"
#include "Point.h"

Entity::Entity()
{
	m_position = Point();
}

Entity::Entity(Point p)
{
	m_position = p;
}

void Entity::update() {};
void Entity::render() {};

void Entity::set_icon(char c)
{
	m_icon = c;
}