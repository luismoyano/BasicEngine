#include "Module.h"


class ModuleAudio :
	public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool Start();
};

