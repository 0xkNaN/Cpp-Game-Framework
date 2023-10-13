/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __PlayState__
#define __PlayState__

#include "Game.h"
#include "GameState.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "GameObjectSDL.h"
#include "InputHandler.h"
#include "TextureManager.h"

class PlayState : public GameState
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const { return playId; }

  bool checkCollision(GameObjectSDL *p1, GameObjectSDL *p2);

private:
  static const std::string playId;
  std::vector<GameObject *> gameObjects;
};

#endif