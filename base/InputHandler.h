/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __InputHandler__
#define __InputHandler__

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "Vector2D.h"

enum mouse_buttons
{
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

class InputHandler
{
public:
  static InputHandler *Instance()
  {
    if (instance == 0)
      instance = new InputHandler();
    return instance;
  }

  void update();
  void reset();
  void clean();

  //? Joystick Events
  void initJoysticks();
  bool joysticksInit() const { return isJoysticksInit; }
  int getAxisX(int joy, int stick) const;
  int getAxisY(int joy, int stick) const;
  bool getButtonState(int joy, int buttonNumber) const;

  //? Mouse Events
  bool getMouseButtonState(int buttonNumber) const;
  Vector2D *getMousePosition() const;

  //? Keybord Events
  bool isKeyDown(SDL_Scancode key) const;

private:
  InputHandler();
  ~InputHandler();

  //? Joystick
  static const int joystickDeadZone = 10000;
  std::vector<SDL_Joystick *> joysticks;
  std::vector<std::pair<Vector2D *, Vector2D *>> joystickValues;
  std::vector<std::vector<bool>> buttonStates;
  bool isJoysticksInit;
  // ...
  void onJoystickAxisMove(SDL_Event &event);
  void onJoystickButtonDown(SDL_Event &event);
  void onJoystickButtonUp(SDL_Event &event);

  //? Mouse
  std::vector<bool> mouseButtonStates;
  Vector2D *mousePosition;
  // ...
  void onMouseMove(SDL_Event &event);
  void onMouseButtonDown(SDL_Event &event);
  void onMouseButtonUp(SDL_Event &event);

  //? Keybord
  const Uint8 *keyStates;
  // ...
  void onKeyDown();
  void onKeyUp();

  //? Singleton
  static InputHandler *instance;
};

typedef InputHandler TheInputHandler;

#endif /* defined(__InputHandler__) */