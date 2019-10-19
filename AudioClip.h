#pragma once
#include "SDL/include/SDL.h"


using namespace std;

class AudioClip
{
public:
	AudioClip();
	AudioClip(const char* path, Uint8* pos, Uint32 length, bool loopable);
	~AudioClip();

	void init();

	const char* path;
	Uint8* position; 
	Uint32 length;
	bool isLoopable;

	bool load();

	void play();
	void pause();
	void stop();

private:

	bool isPlaying;
	bool isPaused;
	bool isStopped;
	bool isLoaded;

	SDL_AudioSpec wavSpec;
	void callback(void* userdata, Uint8* stream, int len);
};

