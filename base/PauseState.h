#ifndef __PauseState__
#define __PauseState__

#include <iostream>
#include <vector>

#include "Game.h"
#include "TextureManager.h"
#include "GameState.h"
#include "GameObject.h"
#include "LoaderParams.h"

class PauseState : public GameState
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const { return pauseId; }

private:
  static const std::string pauseId;
  std::vector<GameObject *> gameObjects;

  static void pauseToMain();
  static void resumePlay();
};

#endif