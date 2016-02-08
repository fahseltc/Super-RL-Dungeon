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

}

void Player::render()
{
	TCODConsole::root->putChar(m_position.x, m_position.y, m_icon);
}