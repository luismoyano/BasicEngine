#include "ModuleAudio.h"
#include "Globals.h"

#include "SDL/include/SDL.h"


using namespace std;



ModuleAudio::ModuleAudio()
{
}


ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{	
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleAudio::Start()
{
	return false;
}

bool ModuleAudio::LoadAudio(const char* path, bool isLoopable)
{

	SDL_LoadWAV(path, &wav_spec, &wav_buffer, &wav_length);// == NULL
	return true;
}

void ModuleAudio::playAudio(float volume)
{

}