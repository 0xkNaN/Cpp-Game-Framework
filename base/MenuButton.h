#ifndef __MenuButton__
#define __MenuButton__

#include "GameObjectSDL.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Vector2D.h"

enum button_state
{
  MOUSE_OUT = 0,
  MOUSE_OVER = 1,
  CLICKED = 2
};

class MenuButton : public GameObjectSDL
{
public:
  MenuButton(const LoaderParams *params, void (*callback)());
  ~MenuButton();

  virtual void draw();
  virtual void update();
  virtual void clean();

private:
  void (*callback)();
  bool isReleased;
};

#endif