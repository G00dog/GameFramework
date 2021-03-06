#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  HandleInput();
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  SDLGameObject::update();
}

void Enemy::HandleInput()
{
  if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
  {
    printf("shoot \n");
  }
  Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;
}

void Enemy::clean() {}