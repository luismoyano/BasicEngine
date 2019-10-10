#include "ModuleExplorer.h"



ModuleExplorer::ModuleExplorer()
{
}


ModuleExplorer::~ModuleExplorer()
{
}

void ModuleExplorer::GetAllFilesInPath(std::string path)
{
	HANDLE hFind;
	WIN32_FIND_DATA data;

	hFind = FindFirstFile("c:\\*.*", &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			printf("%s\n", data.cFileName);
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}
}
