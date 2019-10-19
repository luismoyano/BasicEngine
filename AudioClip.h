#pragma once
#include "SDL/include/SDL.h"

using namespace std;

class AudioClip
{
public:
	AudioClip();
	~AudioClip();

	Uint32 length;
	Uint32 lengthTrue;
	Uint8* bufferTrue;
	Uint8* buffer;
	bool isLoopable;
	bool shouldFree;
	Uint8 volume;

	SDL_AudioSpec audio;
};

