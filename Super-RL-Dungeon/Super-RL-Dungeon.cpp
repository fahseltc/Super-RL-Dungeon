#include "stdafx.h"
#include "GameMap.h"
#include "Player.h"
#include "Point.h"

int main()
{
	TCODConsole::initRoot(80, 50, "SUPER-RL-DUNGEON", false);

	GameMap map = GameMap(80, 50);
	Player player = Player(Point(2,2));

	while (!TCODConsole::isWindowClosed()) 
	{		
		//TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, NULL, NULL);
		TCODConsole::root->clear();
		player.update();
		map.render();
		player.render();		

		TCODConsole::flush();
	}
}

