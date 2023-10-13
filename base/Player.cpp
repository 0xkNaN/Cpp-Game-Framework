/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#include "Player.h"

#include "InputHandler.h"

Player::Player(const LoaderParams *params) : GameObjectSDL(params)
{
}

void Player::update()
{
  velocity.setX(0);
  velocity.setY(0);

  handleInputs();

  currFrame = int((SDL_GetTicks() / 100) % 4);

  GameObjectSDL::update();
}

void Player::draw()
{
  GameObjectSDL::draw();
}

void Player::clean()
{
  GameObjectSDL::clean();
}

void Player::handleInputs()
{
  //? Follow Mouse when click
  Vector2D *target = TheInputHandler::Instance()->getMousePosition();
  velocity = *target - position;
  velocity /= 50;

  //? Joystick Controller
  if (TheInputHandler::Instance()->joysticksInit())
  {
    //? Left Stick Left/Right
    if (TheInputHandler::Instance()->getAxisX(0, 1) > 0 || TheInputHandler::Instance()->getAxisX(0, 1) < 0)
    {
      velocity.setX(1 * TheInputHandler::Instance()->getAxisX(0, 1));
    }

    //? Left Stick Up/Down
    if (TheInputHandler::Instance()->getAxisY(0, 1) > 0 || TheInputHandler::Instance()->getAxisY(0, 1) < 0)
    {
      velocity.setY(1 * TheInputHandler::Instance()->getAxisY(0, 1));
    }

    //? Right Stick Left/Right
    if (TheInputHandler::Instance()->getAxisX(0, 2) > 0 || TheInputHandler::Instance()->getAxisX(0, 2) < 0)
    {
      velocity.setX(1 * TheInputHandler::Instance()->getAxisX(0, 2));
    }

    //? Right Stick Up/Down
    if (TheInputHandler::Instance()->getAxisY(0, 2) > 0 || TheInputHandler::Instance()->getAxisY(0, 2) < 0)
    {
      velocity.setY(1 * TheInputHandler::Instance()->getAxisY(0, 2));
    }

    //? Button Pressed
    if (TheInputHandler::Instance()->getButtonState(0, 3))
    {
      velocity.setX(1);
    }
  }

  //? Mouse Controller -- Left Button
  if (TheInputHandler::Instance()->getMouseButtonState(0))
  {
    // velocity.setX(5);
  }

  //? Mouse Controller -- Left Middle
  if (TheInputHandler::Instance()->getMouseButtonState(1))
  {
    // velocity.setX(1);
  }

  //? Mouse Controller -- Left Right
  if (TheInputHandler::Instance()->getMouseButtonState(2))
  {
    // velocity.setX(-5);
  }

  //? Keybord Controller
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
  {
    velocity.setY(-3);
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
  {
    velocity.setY(3);
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  {
    velocity.setX(-3);
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
  {
    velocity.setX(3);
  }
}