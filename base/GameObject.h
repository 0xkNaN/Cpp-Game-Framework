/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-09 22:13:31
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:36:35
 */

#ifndef __GameObject_h__
#define __GameObject_h__
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