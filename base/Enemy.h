/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __ENEMY__
#define __ENEMY__

#include "GameObjectSDL.h"
#include "LoaderParams.h"

#include "Player.h"

class Enemy : public GameObjectSDL
{
public:
  Enemy(const LoaderParams *params);

  virtual void update();
  virtual void draw();
  virtual void clean();

private:
  Player *player = nullptr;
};

#endif