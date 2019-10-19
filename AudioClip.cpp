#include "AudioClip.h"


AudioClip::AudioClip()
{
	Init(nullptr, false, 1);
}

AudioClip::AudioClip(const char * path, bool loop, Uint8 volume)
{
	Init(path, loop, volume);
}


AudioClip::~AudioClip()
{
	delete path;
	Mix_FreeChunk(clip);
}

void AudioClip::Init(const char * path, bool loop, Uint8 vol)
{
	this->path = path;
	this->isLoopable = loop;

	clip = Mix_LoadWAV(path);
	clip->volume = vol;
}

void AudioClip::setPath(const char * path)
{
	this->path = path;
}

void AudioClip::play()
{
	if (path != NULL)
	{
		Mix_PlayChannel(-1, clip, isLoopable ? -1 : 1);
	}
}

