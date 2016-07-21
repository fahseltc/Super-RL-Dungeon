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

}


void Player::Render()
{
    TCODConsole::root->putChar(position_.x, position_.y, icon_);
    TCODConsole::root->setCharForeground(
        position_.x,
        position_.y,
        TCODColor::lightBlue);
    //TCODConsole::root->setCharBackground(
    //    position_.x,
    //    position_.y,
    //    TCODColor::black);
}