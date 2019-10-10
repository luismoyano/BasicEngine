#pragma once
#include "Module.h"
#include <string>
#include <iostream>
#include <filesystem>



class ModuleExplorer :
	public Module
{
public:
	ModuleExplorer();
	~ModuleExplorer();

	void GetAllFilesInPath(std::string path);
};

