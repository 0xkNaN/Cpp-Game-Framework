#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams *params, void (*callback)()) : GameObjectSDL(params), callback(callback)
{
  currFrame = MOUSE_OUT;
}

MenuButton::~MenuButton()
{
}

void MenuButton::draw()
{
  GameObjectSDL::draw();
}

void MenuButton::update()
{
  Vector2D *mousePos = TheInputHandler::Instance()->getMousePosition();

  if (
      mousePos->getX() < (position.getX() + width) &&
      mousePos->getX() > position.getX() &&
      mousePos->getY() < (position.getY() + height) &&
      mousePos->getY() > position.getY())
  {

    if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && isReleased)
    {
      currFrame = CLICKED;
      callback();
      isReleased = false;
    }
    else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
      isReleased = true;
      currFrame = MOUSE_OVER;
    }
  }
  else
  {
    currFrame = MOUSE_OUT;
  }
}

void MenuButton::clean()
{
  GameObjectSDL::clean();
}