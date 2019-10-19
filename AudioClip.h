#pragma once
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"

using namespace std;

class AudioClip
{
public:
	AudioClip();
	AudioClip(const char* path, bool loop, Uint8 volume);
	~AudioClip();

	void Init(const char* path, bool loop, Uint8 vol);
	void setPath(const char* path);

	void play();

private:

	const char* path;
	bool isLoopable;

	Mix_Chunk* clip;
};

