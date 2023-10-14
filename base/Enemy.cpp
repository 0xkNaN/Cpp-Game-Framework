/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 23:48:09
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 11:31:18
 */

#include "Enemy.h"

Enemy::Enemy() : GameObjectSDL()
{
}

void Enemy::load(const LoaderParams *params)
{
  GameObjectSDL::load(params);

  velocity.setX(1);
  velocity.setY(2);
}

void Enemy::update()
{
  GameObjectSDL::update();

  currFrame = int((SDL_GetTicks() / 100) % numFrames);

  if (position.getY() < 10)
  {
    velocity.setY(2);
  }
  else if (position.getY() > 360)
  {
    velocity.setY(-2);
  }

  if (position.getX() < 10)
  {
    velocity.setX(1);
  }
  else if (position.getX() > 600)
  {
    velocity.setX(-1);
  }
}

void Enemy::draw()
{
  GameObjectSDL::draw();
}

void Enemy::clean()
{
  GameObjectSDL::clean();
}