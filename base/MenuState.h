/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __MenuState__
#define __MenuState__

#include <vector>

#include "Game.h"
#include "GameState.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "TextureManager.h"

#include "PlayState.h"
#include "MenuButton.h"

class MenuState : public GameState
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const { return menuId; }

private:
  static const std::string menuId;
  std::vector<GameObject *> gameObjects;

  static void menuToPlay();
  static void exitFromMenu();
};

#endif