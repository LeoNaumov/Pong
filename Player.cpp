#include "Player.h"

Player::Player()
{
	rect.x = 1400;
	rect.y = 350;
	rect.w = 30;
	rect.h = 150;
    vel = 15;
    velY = 0;
}

void Player::handleInput(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP: velY -= vel; break;
        case SDLK_DOWN: velY += vel; break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP: velY = 0; break;
        case SDLK_DOWN: velY = 0; break;
        }
    }
}

void Player::render(SDL_Renderer* r)
{
	rect.y += velY;

    if (rect.y <= 0) rect.y = 0;
    if (rect.y + rect.h > 800) rect.y = 800 - rect.h;

	SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(r, &rect);
}