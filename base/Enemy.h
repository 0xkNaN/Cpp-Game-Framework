/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 23:46:04
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:57:33
 */

#ifndef __ENEMY__
#define __ENEMY__

#include "GameObjectSDL.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

class Enemy : public GameObjectSDL
{
public:
  Enemy();

  virtual void load(const LoaderParams *params);

  virtual void update();
  virtual void draw();
  virtual void clean();
};

class EnemyCreator : public BaseCreator
{
  GameObject *createGameObject() const
  {
    return new Enemy();
  }
};

#endif