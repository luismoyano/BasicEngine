#pragma once
#include "Module.h"
#include "AudioClip.h"
#include<list>

using namespace std;

struct AudioDevice
{
	SDL_AudioDeviceID device;
	SDL_AudioSpec wavSpec;
	bool isAudioEnabled;
};

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool Start();

	AudioClip* createAudioClip(const char * filename, bool isLoopable, int volume);
	void playAudio(const char* path, AudioClip* audio, bool isLoopable, int volume);
	void freeAudio(AudioClip* audio);
	void playSound(const char* path, int volume);
	void playMusic(const char* path, int volume);
	void stopAll(void);
	void pauseAudio(void);
	void unpauseAudio(void);
private:

	bool isLoaded;
	AudioDevice* device;
	Uint32 amountOfSounds;
	list<AudioClip> clips;
};