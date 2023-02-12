#pragma once
#include "Singletons.h"
struct Player
{
	SDL_Rect rect;
	int vel;
	int velY;

	Player();
	void handleInput(SDL_Event &e);
	void render(SDL_Renderer* r);
};

