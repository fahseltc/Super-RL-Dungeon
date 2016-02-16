#include "player.h"
#include "libtcod.hpp"

Player::Player(Point p, GameMap *map_in) :
	Entity(p)
{
	// constructor with position
	set_icon('@');
    map_ = map_in;
}

void Player::Update()
{
	HandleInput();
}

void Player::HandleInput()
{
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

    int future_x = position_.x;
    int future_y = position_.y;

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
        position_.x = future_x;
        position_.y = future_y;
    }
}

void Player::Render()
{
	TCODConsole::root->putChar(position_.x, position_.y, icon_);
    TCODConsole::root->setCharForeground(position_.x, position_.y, TCODColor::yellow);
}