#include "stdafx.h"

int main()
{
	TCODConsole::initRoot(80, 50, "SUPER-RL-DUNGEON", false);

	while (!TCODConsole::isWindowClosed()) 
	{
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, NULL, NULL);
		TCODConsole::root->clear();
		TCODConsole::root->putChar(40, 25, '@');
		TCODConsole::flush();
	}
}

