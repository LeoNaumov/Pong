#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Player.h"
#include "Ball.h"
#include "Enemy.h"
struct TestScene : public GameState
{
	void logic();
	void render();
	void handleInput(SDL_Event& e);

	TestScene(SDL_Renderer** r, GameStateManager& GSM);
	~TestScene();

	SDL_Renderer** renderer;
	GameStateManager& GSM;

	Player player;
	Ball ball;
	Enemy enemy;
};

