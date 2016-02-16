#pragma once
#include "point.h"
class Entity
{
public:
	Point m_position;
	char m_icon;
	
	Entity();
	Entity(Point);

	virtual void update();
	virtual void render();

	void set_icon(char c);
};