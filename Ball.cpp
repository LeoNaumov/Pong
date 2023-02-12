#include "Ball.h"

Ball::Ball(SDL_Rect & r):
	player(r)
{
	srand(time(NULL));
	rect.x = 1500 / 2;
	rect.y = 800 / 2;
	rect.w = 20;
	rect.h = 20;
	dirHor = rand() % 2;
	dirVer = rand() % 2;
	vel = 10;
	isOver = false;
}

void Ball::render(SDL_Renderer* r)
{
	if (dirVer == 1) {
		rect.y += vel;
	}
	else {
		rect.y -= vel;
	}
	if (dirHor == 1) {
		rect.x += vel;
	}else {
		rect.x -= vel;
	}


	if (rect.y <= 0) dirVer = 1;
	if (rect.y >= 800) dirVer = 2;
	SDL_Rect temp;
	if (rect.x<player.x && SDL_IntersectRect(&rect, &player, &temp)) dirHor = 2;

	if (rect.x >= 1470) isOver = true;

	if (rect.x <  0) isOver = true;

	SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(r, &rect);
}