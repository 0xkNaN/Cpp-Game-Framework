/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 22:20:33
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 00:00:19
 */

#ifndef __PLAYER__
#define __PLAYER__

#include "GameObjectSDL.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

class Player : public GameObjectSDL
{
public:
  Player();

  virtual void update();
  virtual void draw();
  virtual void clean();

  virtual void load(const LoaderParams *params);

private:
  void handleInputs();
};

class PlayerCreator : public BaseCreator
{
  GameObject *createGameObject() const
  {
    return new Player();
  }
};

#endif