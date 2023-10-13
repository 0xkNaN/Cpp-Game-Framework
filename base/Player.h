#ifndef __PLAYER__
#define __PLAYER__

#include "GameObjectSDL.h"
#include "LoaderParams.h"

class Player : public GameObjectSDL
{
public:
  Player(const LoaderParams *params);

  virtual void update();
  virtual void draw();
  virtual void clean();

private:
  void handleInputs();
};

#endif