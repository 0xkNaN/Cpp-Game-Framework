/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 13:10:03
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:39:48
 */

#ifndef __AnimatedGraphic_h__
#define __AnimatedGraphic_h__

#include <iostream>

#include "GameObjectSDL.h"
#include "GameObjectFactory.h"
#include "LoaderParams.h"

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