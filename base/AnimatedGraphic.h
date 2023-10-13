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