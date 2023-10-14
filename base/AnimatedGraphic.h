/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 13:10:03
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:20:22
 */

#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include <iostream>

#include "GameObjectSDL.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public GameObjectSDL
{
public:
  AnimatedGraphic();
  ~AnimatedGraphic() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

private:
  int animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator
{
  GameObject *createGameObject() const
  {
    return new AnimatedGraphic();
  }
};

#endif