/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __GameOverState__
#define __GameOverState__

#include <iostream>
#include <vector>

#include "Game.h"
#include "GameState.h"
#include "TextureManager.h"
#include "GameObject.h"

class GameOverState : public GameState
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const { return gameOverId; }

private:
  static const std::string gameOverId;
  std::vector<GameObject *> gameObjects;

  static void gameOverToMain();
  static void restartPlay();
};

#endif