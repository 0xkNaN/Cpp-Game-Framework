/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 20:54:17
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:50:49
 */

#ifndef __MainMenuState__
#define __MainMenuState__

#include <vector>

#include "Game.h"
#include "MenuState.h"
#include "StateParser.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "MenuButton.h"

class MainMenuState : public MenuState
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

  virtual void setCallbacks(const std::vector<Callback> &callbacks);

  static void menuToPlay();
  static void exitFromMenu();
};

#endif