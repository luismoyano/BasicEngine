#include "ModuleAudio.h"
#include "Globals.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL/include/SDL.h"

using namespace std;

static inline void audioCallback(void * userdata, uint8_t * stream, int len);


ModuleAudio::ModuleAudio()
{
}


ModuleAudio::~ModuleAudio()
{
	for (list<AudioClip>::iterator it = clips.begin(); it != clips.end(); ++it) delete &it;
	SDL_CloseAudio();

	stopAll();
}

bool ModuleAudio::Init()
{
	bool toBeReturned = true;

	AudioClip* global;
	device = new AudioDevice();
	amountOfSounds = 0;

	device->isAudioEnabled = false;

	SDL_InitSubSystem(SDL_INIT_AUDIO);

	device->wavSpec.freq = CLIP_FREQUENCY;
	device->wavSpec.format = CLIP_FORMAT;
	device->wavSpec.channels = CHANNELS;
	device->wavSpec.samples = SAMPLES;
	device->wavSpec.callback = audioCallback;
	device->wavSpec.userdata = new AudioClip();

	global = (AudioClip*)device->wavSpec.userdata;
	global->buffer = NULL;


	if (device->device = SDL_OpenAudioDevice(NULL, 0, &device->wavSpec, NULL, SDL_AUDIO_ALLOW_CHANGES) == 0)
	{
		toBeReturned = false;
	}
	else
	{
		device->isAudioEnabled = true;
		unpauseAudio();
	}

	return toBeReturned;
}

bool ModuleAudio::Start()
{
	return true;
}

void ModuleAudio::playSound(const char * filename, int volume)
{
	playAudio(filename, NULL, false, volume);
}

void ModuleAudio::playMusic(const char * filename, int volume)
{
	playAudio(filename, NULL, true, volume);
}

void ModuleAudio::stopAll()
{
	if (device->isAudioEnabled)
	{
		pauseAudio();
		freeAudio((AudioClip*)device->wavSpec.userdata);

		SDL_CloseAudioDevice(device->device);
	}

	delete device;
}

void ModuleAudio::pauseAudio()
{
	if (device->isAudioEnabled)
	{
		SDL_PauseAudioDevice(device->device, 1);
	}
}

void ModuleAudio::unpauseAudio()
{
	if (device->isAudioEnabled)
	{
		SDL_PauseAudioDevice(device->device, 0);
	}
}

void ModuleAudio::freeAudio(AudioClip* audio)
{
	if (audio->shouldFree)
	{
		SDL_FreeWAV(audio->bufferTrue);
	}
}

AudioClip* ModuleAudio::createAudioClip(const char * filename, bool isLoopable, int volume)
{
	AudioClip* newClip = new AudioClip();

	newClip->isLoopable = isLoopable;
	newClip->shouldFree = true;
	newClip->volume = volume;

	if (SDL_LoadWAV(filename, &(newClip->audio), &(newClip->bufferTrue), &(newClip->lengthTrue)) == NULL)
	{
		delete newClip;
		return NULL;
	}

	newClip->buffer = newClip->bufferTrue;
	newClip->length = newClip->lengthTrue;
	newClip->audio.callback = NULL;
	newClip->audio.userdata = NULL;

	return newClip;
}

void ModuleAudio::playAudio(const char* path, AudioClip* audio, bool isLoopable, int volume)
{
	AudioClip* newClip;

	if (!device->isAudioEnabled) return;

	if (!isLoopable)
	{
		if (amountOfSounds >= MAX_SOUNDS)return;
		amountOfSounds++;
	}

	if (path != NULL) newClip = createAudioClip(path, isLoopable, volume);
	
	else if (audio != NULL)
	{
		newClip = new AudioClip();

		newClip->volume = volume;
		newClip->isLoopable = isLoopable;
		newClip->shouldFree = true;
	}

	/* Lock callback function */
	SDL_LockAudioDevice(device->device);
	
	clips.push_back(*newClip);

	SDL_UnlockAudioDevice(device->device);

}

static inline void audioCallback(void * userdata, uint8_t * stream, int len)
{
	AudioClip* clip = (AudioClip*)userdata;
	int tempLength;
	uint8_t music = 0;

	while (clip != NULL)
	{
		if (clip->length > 0)
		{

			if (music && clip->isLoopable)
			{
				tempLength = 0;
			}
			else
			{
				tempLength = ((uint32_t)len > clip->length) ? clip->length : (uint32_t)len;
			}

			SDL_MixAudioFormat(stream, clip->buffer, CLIP_FORMAT, tempLength, clip->volume);

			clip->buffer += tempLength;
			clip->length -= tempLength;
		}
		else if (clip->isLoopable)
		{
			clip->buffer = clip->bufferTrue;
			clip->length = clip->lengthTrue;
		}
		else
		{
			delete clip;
		}
	}
}