#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleInput::Start()
{
	return true;
}

update_status ModuleInput::PreUpdate()
{
	update_status toReturn = UPDATE_CONTINUE;
	return toReturn;
}


// Called every draw update
update_status ModuleInput::Update()
{
	update_status toReturn = UPDATE_CONTINUE;
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&events);

	// TODO 1: Make the application properly close when ESC is pressed (do not use exit()) --- DONE
	if(keyboard[SDL_SCANCODE_ESCAPE] || events.type == SDL_QUIT) toReturn = UPDATE_STOP;

	// Homework: Make the application close up when pressing “X” button of the window --- DONE
	
			
	

	return toReturn;
}

update_status ModuleInput::PostUpdate()
{
	update_status toReturn = UPDATE_CONTINUE;
	return toReturn;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}