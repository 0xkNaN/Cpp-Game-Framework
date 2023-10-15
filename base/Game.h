/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-08 17:39:26
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:12:33
 */

#ifndef __Game_h__
#define __Game_h__

#include <iostream>
#include <SDL2/SDL.h>

#include "GameStateMachine.h"

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

  int getGameWidth() { return gameWidth; }
  int getGameHeight() { return gameHeight; }

  SDL_Renderer *getRenderer() const { return renderer; }
  GameStateMachine *getStateMachine() const { return gameStateMachine; }

private:
  Game() {}

  static Game *instance;
  bool isRunning;
  int gameWidth, gameHeight;

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  GameStateMachine *gameStateMachine;
};

typedef Game TheGame;
#endif