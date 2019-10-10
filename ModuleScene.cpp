#include "Application.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleScene.h"



ModuleScene::ModuleScene()
{
}


ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init()
{
	return true;
}

bool ModuleScene::Start()
{
	LoadScene();
	return true;
}

update_status ModuleScene::PreUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{
	SDL_RenderCopy(App->renderer->renderer, texture, NULL, NULL);
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool ModuleScene::LoadScene()
{
	texture = App->textures->Load("..\\Game\\sprites.png");
	return true;
}
