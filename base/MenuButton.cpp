/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 22:04:10
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 00:01:17
 */

#include "MenuButton.h"

MenuButton::MenuButton() : GameObjectSDL()
{
  currFrame = MOUSE_OUT;
}

void MenuButton::load(const LoaderParams *params)
{
  GameObjectSDL::load(params);
  callbackId = params->getCallbackId();
  currFrame = MOUSE_OUT;
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