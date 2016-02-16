#include "engine.h"

const int kGlobalWidth = 200;
const int kGlobalHeight = 100;

Engine::Engine() :
	scene_(Scene(kGlobalWidth, kGlobalHeight))
{
    TCODConsole::initRoot(kGlobalWidth, kGlobalHeight, "SUPER-RL-DUNGEON", false); 
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
