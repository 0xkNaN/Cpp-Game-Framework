/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 22:13:31
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:57:53
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

  virtual void load(const LoaderParams *params) = 0;

protected:
  GameObject() {}
  virtual ~GameObject() {}
};

#endif