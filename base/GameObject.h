/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

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