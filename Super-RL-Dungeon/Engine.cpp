#include "engine.h"





Engine::Engine() :
    scene_(Scene(kGlobalWidth, kGlobalHeight))
{
    TCODConsole::setCustomFont("bigtiles.bmp");
    TCODConsole::initRoot(
        kGlobalWidth, 
        kGlobalHeight, 
        "SUPER-RL-DUNGEON", 
        false); 
}

Engine::~Engine()
{
}

void Engine::Update()
{
    scene_.Update();
}

void Engine::Render()
{
    scene_.Render();
}
