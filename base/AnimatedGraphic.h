/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include <iostream>

#include "GameObjectSDL.h"
#include "LoaderParams.h"

class AnimatedGraphic : public GameObjectSDL
{
public:
  AnimatedGraphic(const LoaderParams *params, int animSpeed);
  ~AnimatedGraphic();

  virtual void draw();
  virtual void update();
  virtual void clean();

private:
  int animSpeed;
};

#endif