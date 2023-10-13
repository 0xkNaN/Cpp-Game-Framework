#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include "LoaderParams.h"

class GameObject
{
public:
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual void clean() = 0;

protected:
  GameObject(const LoaderParams *params) {}
  virtual ~GameObject() {}
};

#endif