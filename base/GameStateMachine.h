#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <iostream>
#include <vector>

#include "GameState.h"

class GameStateMachine
{

public:
  //? Add New State without removing the old State
  void pushState(GameState *state);

  //? Add new State and remove the old State
  void changeState(GameState *state);

  //? Remove Current state without adding a new State
  void popState();

  void update();
  void render();
  void clean();

  std::vector<GameState *> getGameStates() const { return gameStates; }

private:
  std::vector<GameState *> gameStates;
};

#endif