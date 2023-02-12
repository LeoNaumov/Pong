#pragma once
#include "Singletons.h"
struct Ball
{
	SDL_Rect rect;
	SDL_Rect& player;
	int dirVer;
	int dirHor;
	int vel;
	bool isOver;

	Ball(SDL_Rect &);
	void render(SDL_Renderer*);
};

