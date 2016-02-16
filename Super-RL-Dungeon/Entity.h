#pragma once
#include "point.h"
class Entity
{
public:
	Point position_;
	char icon_;
	
	Entity();
	Entity(Point);

	virtual void Update();
	virtual void Render();

	void set_icon(char c);
};