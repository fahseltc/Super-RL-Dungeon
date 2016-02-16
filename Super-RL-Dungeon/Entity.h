#pragma once
#include "point.h"
class Entity
{
public:
	Point position_;
	char icon_;
	
	Entity();
	Entity(Point);

	virtual void update();
	virtual void render();

	void set_icon(char c);
};