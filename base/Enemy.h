/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 23:46:04
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:36:14
 */

#ifndef __Enemy_h__
#define __Enemy_h__

#include "GameObjectSDL.h"
#include "GameObjectFactory.h"
#include "LoaderParams.h"

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