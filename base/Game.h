#ifndef __Game__
#define __Game__

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameStateMachine.h"
#include "GameObject.h"

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

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  GameStateMachine *gameStateMachine;

  std::vector<GameObject *> gameObjects;

  bool isRunning;

  static Game *instance;
};

typedef Game TheGame;
#endif