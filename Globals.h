#pragma once
#include <windows.h>
#include <stdio.h>

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Configuration -----------
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FULLSCREEN false
#define RESIZABLE false
#define BORDERLESS false
#define FULLSCREEN_DESKTOP false
#define VSYNC true
#define TITLE "Super Awesome Game"
#define CLIP_FORMAT AUDIO_S16LSB
#define CLIP_FREQUENCY 48000
#define CHANNELS 2
#define SAMPLES 4096
#define MAX_SOUNDS 10
#define SDL_AUDIO_ALLOW_CHANGES SDL_AUDIO_ALLOW_ANY_CHANGE