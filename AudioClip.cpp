#include "AudioClip.h"



AudioClip::AudioClip()
{
	init();
}

AudioClip::AudioClip(const char * path, Uint8 * pos, Uint32 len, bool loopable)
{
	this->path = path;
	position = pos;
	length = len;
	isLoopable = loopable;

	init();
}


AudioClip::~AudioClip()
{
}

void AudioClip::init()
{
	isLoaded = false;
	isPlaying = false;
	isPaused = false;
	isStopped = true;
}

bool AudioClip::load()
{
	isLoaded = SDL_LoadWAV(path, &wavSpec, &position, &length) != NULL;
	return isLoaded;
}

void AudioClip::play()
{
	if (isPaused || isStopped)
	{
		//Lalalala
		isPlaying = true;
		isPaused = false;
		isStopped = false;
	}
}

void AudioClip::pause()
{
	if (isPlaying)
	{
		SDL_PauseAudio(0);

		isPlaying = false;
		isPaused = true;
		isStopped = false;
	}
}

void AudioClip::stop()
{
	if (isPaused || isPlaying)
	{
		//Lalalala
		isPlaying = false;
		isPaused = false;
		isStopped = true;
	}
}

void AudioClip::callback(void * userdata, Uint8 * stream, int len)
{
	if (length == 0) return;

	len = (len > length ? length : len);
	SDL_MixAudio(stream, position, len, SDL_MIX_MAXVOLUME);

	position += len;
	position -= len;
}
