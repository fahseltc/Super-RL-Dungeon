#include "stdafx.h"
#include "GameMap.h"

int main()
{
	TCODConsole::initRoot(80, 50, "SUPER-RL-DUNGEON", false);

	GameMap map = GameMap(80, 50);

	while (!TCODConsole::isWindowClosed()) 
	{		
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, NULL, NULL);
		TCODConsole::root->clear();

		map.render();
		TCODConsole::root->putChar(40, 45, '@');

		TCODConsole::flush();
	}
}

