#include "Player.h"
#include "Point.h"
#include "Entity.h"
#include "libtcod.hpp"

Player::Player() :
	Entity()
{
	// default constructor
	set_icon('@');
}

Player::Player(Point p) :
	Entity(p)
{
	// constructor with position
	set_icon('@');
}

void Player::update()
{
	handle_input();
}

void Player::handle_input()
{
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
	switch (key.vk)
	{
	case TCODK_UP: m_position.y--; break;
	case TCODK_DOWN: m_position.y++; break;
	case TCODK_LEFT: m_position.x--; break;
	case TCODK_RIGHT: m_position.x++; break;	
	}
}

void Player::render()
{
	TCODConsole::root->putChar(m_position.x, m_position.y, m_icon);
}