#include "Engine.h"

Engine engine;

int main()
{
    while (!TCODConsole::isWindowClosed())
    {
        engine.Update();
        engine.Render();
        TCODConsole::flush();
    }
    return 0;
}

