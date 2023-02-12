#include "TestScene.h"
#include <cassert>
TestScene::TestScene(SDL_Renderer** r, GameStateManager& GSM)
    :
    GSM(GSM),
    renderer(r),
    ball(player.rect),
    enemy()
{
    assert(r!=NULL);
}

void TestScene::logic()
{
    if (ball.isOver) {
        GSM.changeState(new TestScene(renderer, GSM));
        return;
    }
    if (ball.rect.y < enemy.rect.y) {
        enemy.rect.y -= 10;
    }
    else if (ball.rect.y > enemy.rect.y + enemy.rect.h) {
        enemy.rect.y += 10;
    }
    SDL_Rect temp;
    if (ball.rect.x > enemy.rect.x && SDL_IntersectRect(&ball.rect, &enemy.rect, &temp)) ball.dirHor = 1;
}

void TestScene::render()
{
    player.render(*renderer);
    ball.render(*renderer);
    enemy.render(*renderer);
}

void TestScene::handleInput(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_p: GSM.changeState(new TestScene(renderer,GSM)); break;
        }
    }
    player.handleInput(e);
}


TestScene::~TestScene()
{
    

}