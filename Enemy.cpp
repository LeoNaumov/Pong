#include "Enemy.h"

Enemy::Enemy()
{
	rect.x = 100;
	rect.y = 350;
	rect.w = 30;
	rect.h = 150;
}

void Enemy::render(SDL_Renderer *r)
{


	SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(r, &rect);
}