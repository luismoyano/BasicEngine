#pragma once
#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL.h"

typedef unsigned __int8 Uint8;

class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

private:
	const Uint8 *keyboard = NULL;
	SDL_Event events;
};