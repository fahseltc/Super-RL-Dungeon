#pragma once
#include "Entity.h"
#include "Point.h"

class Player : public Entity
{
public:
	Player();
	Player(Point p);

	void update();
	void render();
	void handle_input();

private:
};