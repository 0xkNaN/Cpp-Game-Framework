/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 12:10:29
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:22:43
 */

#ifndef __PauseState__
#define __PauseState__

#include <iostream>
#include <vector>

#include "MenuState.h"
#include "StateParser.h"
#include "GameObject.h"
#include "TextureManager.h"

class PauseState : public MenuState
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

  virtual void setCallbacks(const std::vector<Callback> &callbacks);

  static void pauseToMain();
  static void resumePlay();
};

#endif