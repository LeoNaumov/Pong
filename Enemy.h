#pragma once
#include "Singletons.h"
struct Enemy
{
	SDL_Rect rect;
	Enemy();
	void render(SDL_Renderer*);
};

