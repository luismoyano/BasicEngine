#pragma once
#include "Module.h"
#include "AudioClip.h"
#include<list>


using namespace std;

class ModuleAudio :
	public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool Start();

	bool LoadAudio(const char* path, bool isLoopable);
	void playAudio(float volume);

private:

	list<AudioClip*> clips;
};