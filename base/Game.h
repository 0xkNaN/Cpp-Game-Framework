/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-08 17:39:26
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:57:47
 */

#ifndef __Game__
#define __Game__

#include <iostream>
#include <SDL2/SDL.h>

#include "GameStateMachine.h"
#include "GameObjectFactory.h"

class Game
{
public:
  static Game *Instance()
  {
    if (instance == 0)
      instance = new Game();
    return instance;
  }

  bool init(const char *title);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; }
  void quit() { isRunning = false; }

  SDL_Renderer *getRenderer() const { return renderer; }
  GameStateMachine *getStateMachine() const { return gameStateMachine; }

private:
  Game() {}

  static Game *instance;
  bool isRunning;

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  GameStateMachine *gameStateMachine;
};

typedef Game TheGame;
#endif