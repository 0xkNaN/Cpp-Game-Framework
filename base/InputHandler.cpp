/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#include "InputHandler.h"
#include "Game.h"

InputHandler *InputHandler::instance = 0;

InputHandler::InputHandler() : isJoysticksInit(false), mousePosition(new Vector2D(0, 0)), keyStates(0)
{
  for (int i = 0; i < 3; i++)
  {
    mouseButtonStates.push_back(false);
  }
}

InputHandler::~InputHandler()
{
  delete mousePosition;
  delete keyStates;

  joystickValues.clear();
  joysticks.clear();
  buttonStates.clear();
  mouseButtonStates.clear();
}

void InputHandler::update()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      TheGame::Instance()->quit();
    }

    switch (event.type)
    {
    case SDL_JOYAXISMOTION:
      onJoystickAxisMove(event);
      break;
    case SDL_JOYBUTTONDOWN:
      onJoystickButtonDown(event);
      break;
    case SDL_JOYBUTTONUP:
      onJoystickButtonUp(event);
      break;

    case SDL_MOUSEBUTTONDOWN:
      onMouseButtonDown(event);
      break;
    case SDL_MOUSEBUTTONUP:
      onMouseButtonUp(event);
      break;
    case SDL_MOUSEMOTION:
      onMouseMove(event);
      break;

    case SDL_KEYDOWN:
      onKeyDown();
      break;
    case SDL_KEYUP:
      onKeyUp();
      break;

    default:
      break;
    }
  }
}

void InputHandler::clean()
{
  if (isJoysticksInit)
  {
    for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
    {
      SDL_JoystickClose(joysticks[i]);
    }
  }
}

//? Joystick
void InputHandler::initJoysticks()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
  {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  }

  if (SDL_NumJoysticks() > 0)
  {
    for (int i = 0; i < SDL_NumJoysticks(); i++)
    {
      SDL_Joystick *joy = SDL_JoystickOpen(i);

      if (joy)
      {
        joysticks.push_back(joy);
        joystickValues.push_back(
            std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

        std::vector<bool> tmpButtons;
        for (int j = 0; SDL_JoystickNumButtons(joy); j++)
        {
          tmpButtons.push_back(false);
        }

        buttonStates.push_back(tmpButtons);
      }
      else
      {
        std::cout << SDL_GetError();
      }
    }

    //?
    SDL_JoystickEventState(SDL_ENABLE);
    isJoysticksInit = true;

    std::cout << "Initialised " << joysticks.size() << "joystick(s)\n";
  }
  else
  {
    isJoysticksInit = false;

    std::cout << "Initialised 0 joystick(s)\n";
  }
}

int InputHandler::getAxisX(int joy, int stick) const
{
  if (joystickValues.size() > 0)
  {
    if (stick == 1)
    {
      return joystickValues[joy].first->getX();
    }
    else if (stick == 2)
    {
      return joystickValues[joy].second->getX();
    }
  }

  return 0;
}

int InputHandler::getAxisY(int joy, int stick) const
{
  if (joystickValues.size() > 0)
  {
    if (stick == 1)
    {
      return joystickValues[joy].first->getY();
    }
    else if (stick == 2)
    {
      return joystickValues[joy].second->getY();
    }
  }

  return 0;
}

bool InputHandler::getButtonState(int joy, int buttonNumber) const
{
  return buttonStates[joy][buttonNumber];
}

//? Joystick Events
void InputHandler::onJoystickAxisMove(SDL_Event &event)
{
  int witchOne = event.jaxis.which;

  //? Left Stick move left or right
  if (event.jaxis.axis == 0)
  {
    if (event.jaxis.value > joystickDeadZone)
    {
      joystickValues[witchOne].first->setX(1);
    }
    else if (event.jaxis.value < joystickDeadZone)
    {
      joystickValues[witchOne].first->setX(-1);
    }
    else
    {
      joystickValues[witchOne].first->setX(0);
    }
  }

  //? Left Stick move up or down
  if (event.jaxis.axis == 1)
  {
    if (event.jaxis.value > joystickDeadZone)
    {
      joystickValues[witchOne].first->setY(1);
    }
    else if (event.jaxis.value < joystickDeadZone)
    {
      joystickValues[witchOne].first->setY(-1);
    }
    else
    {
      joystickValues[witchOne].first->setY(0);
    }
  }

  //? Right Stick move left or right
  if (event.jaxis.axis == 3)
  {
    if (event.jaxis.value > joystickDeadZone)
    {
      joystickValues[witchOne].second->setX(1);
    }
    else if (event.jaxis.value < joystickDeadZone)
    {
      joystickValues[witchOne].second->setX(-1);
    }
    else
    {
      joystickValues[witchOne].second->setX(0);
    }
  }

  //? Right Stick move up or down
  if (event.jaxis.axis == 4)
  {
    if (event.jaxis.value > joystickDeadZone)
    {
      joystickValues[witchOne].second->setY(1);
    }
    else if (event.jaxis.value < joystickDeadZone)
    {
      joystickValues[witchOne].second->setY(-1);
    }
    else
    {
      joystickValues[witchOne].second->setY(0);
    }
  }
}

void InputHandler::onJoystickButtonDown(SDL_Event &event)
{
  int whichOne = event.jaxis.which;
  buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event &event)
{
  int whichOne = event.jaxis.which;
  buttonStates[whichOne][event.jbutton.button] = false;
}

//? Mouse
bool InputHandler::getMouseButtonState(int buttonNumber) const
{
  return mouseButtonStates[buttonNumber];
}

Vector2D *InputHandler::getMousePosition() const
{
  return mousePosition;
}

//? Mouse Events
void InputHandler::onMouseButtonDown(SDL_Event &event)
{
  if (event.button.button == SDL_BUTTON_LEFT)
  {
    mouseButtonStates[LEFT] = true;
  }
  if (event.button.button == SDL_BUTTON_MIDDLE)
  {
    mouseButtonStates[MIDDLE] = true;
  }
  if (event.button.button == SDL_BUTTON_RIGHT)
  {
    mouseButtonStates[RIGHT] = true;
  }
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
  if (event.button.button == SDL_BUTTON_LEFT)
  {
    mouseButtonStates[LEFT] = false;
  }
  if (event.button.button == SDL_BUTTON_MIDDLE)
  {
    mouseButtonStates[MIDDLE] = false;
  }
  if (event.button.button == SDL_BUTTON_RIGHT)
  {
    mouseButtonStates[RIGHT] = false;
  }
}

void InputHandler::onMouseMove(SDL_Event &event)
{
  mousePosition->setX(event.motion.x);
  mousePosition->setY(event.motion.y);
}

//? Keyboard
bool InputHandler::isKeyDown(SDL_Scancode key) const
{
  if (keyStates != 0)
  {
    return keyStates[key] == 1;
  }

  return false;
}

//? Keybord Events
void InputHandler::onKeyDown()
{
  keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
  keyStates = SDL_GetKeyboardState(0);
}