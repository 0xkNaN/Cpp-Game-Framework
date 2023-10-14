/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 23:48:09
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:57:26
 */

#include "Enemy.h"

Enemy::Enemy() : GameObjectSDL()
{
  //? Random Movement
  velocity.setX(1);
  velocity.setY(2);
}

void Enemy::load(const LoaderParams *params)
{
  GameObjectSDL::load(params);
}

void Enemy::update()
{
  currFrame = int((SDL_GetTicks() / 100) % 4);

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

  GameObjectSDL::update();
}

void Enemy::draw()
{
  GameObjectSDL::draw();
}

void Enemy::clean()
{
  GameObjectSDL::clean();
}