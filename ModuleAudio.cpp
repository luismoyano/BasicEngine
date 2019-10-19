#include "ModuleAudio.h"
#include "Globals.h"

ModuleAudio::ModuleAudio()
{
}

ModuleAudio::~ModuleAudio()
{
	for (list<AudioClip*>::iterator it = clips.begin(); it != clips.end(); ++it) delete &it;
	Mix_CloseAudio();
}

bool ModuleAudio::Init()
{
	bool toBeReturned = true;

	int result = SDL_InitSubSystem(SDL_INIT_AUDIO);
	if (result < 0) toBeReturned = false;

	result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
	if (result < 0) toBeReturned = false;

	result = Mix_AllocateChannels(4);
	if (result < 0) toBeReturned = false;

	return toBeReturned;
}

bool ModuleAudio::Start()
{
	AudioClip* clip = new AudioClip("..\\Game\\hiighlands.wav", true, 120);
	clips.push_back(clip);

	clip->play();

	Sleep(1);
	return true;
}
