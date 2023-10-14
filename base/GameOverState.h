/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 13:18:28
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:28:04
 */

#ifndef __GameOverState__
#define __GameOverState__

#include <iostream>
#include <vector>

#include "MenuState.h"
#include "GameObject.h"
#include "TextureManager.h"

class GameOverState : public MenuState
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

  virtual void setCallbacks(const std::vector<Callback> &callbacks);

  static void gameOverToMain();
  static void restartPlay();
};

#endif