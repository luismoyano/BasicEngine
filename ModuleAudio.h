#pragma once
#include "Module.h"
#include "AudioClip.h"
#include "Globals.h"
#include <list>
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )
 
using namespace std;

class ModuleAudio : public Module
{
public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool Start();

private:

	list<AudioClip*> clips;
};
