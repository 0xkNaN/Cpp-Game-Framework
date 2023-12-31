/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 21:09:04
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:21:47
 */

#ifndef __GameStateMachine_h__
#define __GameStateMachine_h__

#include <iostream>
#include <vector>

#include "GameState.h"

class GameStateMachine
{

public:
  void update();
  void render();
  void clean();

  //? Add New State without removing the old State
  void pushState(GameState *state);

  //? Add new State and remove the old State
  void changeState(GameState *state);

  //? Remove Current state without adding a new State
  void popState();

  std::vector<GameState *> getGameStates() const { return gameStates; }

private:
  std::vector<GameState *> gameStates;
};

#endif