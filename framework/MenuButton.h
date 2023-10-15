/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 22:03:58
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 00:01:10
 */

#ifndef __MenuButton__
#define __MenuButton__

#include "GameObjectSDL.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "GameObjectFactory.h"

enum button_state
{
  MOUSE_OUT = 0,
  MOUSE_OVER = 1,
  CLICKED = 2
};

class MenuButton : public GameObjectSDL
{
public:
  MenuButton();
  ~MenuButton() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

  void setCallback(void (*callbackP)()) { callback = callbackP; }
  int getCallbackId() { return callbackId; }

private:
  bool isReleased;

  int callbackId;
  void (*callback)();
};

class MenuButtonCreator : public BaseCreator
{
  GameObject *createGameObject() const
  {
    return new MenuButton();
  }
};

#endif