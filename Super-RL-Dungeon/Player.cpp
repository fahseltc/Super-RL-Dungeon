#include "Player.h"
#include "Point.h"
#include "Entity.h"
#include "libtcod.hpp"

Player::Player(Point p, GameMap *map_in) :
	Entity(p)
{
	// constructor with position
	set_icon('@');
    map = map_in;
}

void Player::update()
{
	handle_input();
}

void Player::handle_input()
{
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

    int future_x = m_position.x;
    int future_y = m_position.y;
	switch (key.vk)
	{
	case TCODK_UP: future_y--; break;
	case TCODK_DOWN: future_y++; break;
	case TCODK_LEFT: future_x--; break;
	case TCODK_RIGHT: future_x++; break;
	}

    // check if we can move to future x,y
    if (map->is_passable(future_x, future_y))
    {
        m_position.x = future_x;
        m_position.y = future_y;
    }
}

void Player::render()
{
	TCODConsole::root->putChar(m_position.x, m_position.y, m_icon);
    TCODConsole::root->setCharForeground(m_position.x, m_position.y, TCODColor::yellow);
}