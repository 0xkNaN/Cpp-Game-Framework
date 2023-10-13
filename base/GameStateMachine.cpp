#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *state)
{
  gameStates.push_back(state);
  gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState *state)
{
  if (!gameStates.empty())
  {
    if (gameStates.back()->getStateId() == state->getStateId())
    {
      return;
    }

    //? Delete previous state
    gameStates.back()->onExit();
    gameStates.pop_back();
  }

  //? Add and Ini the new state
  gameStates.push_back(state);
  gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
  if (!gameStates.empty())
  {
    gameStates.back()->onExit();
    gameStates.pop_back();
  }
}

void GameStateMachine::update()
{
  if (!gameStates.empty())
  {
    gameStates.back()->update();
  }
}

void GameStateMachine::render()
{
  if (!gameStates.empty())
  {
    gameStates.back()->render();
  }
}

void GameStateMachine::clean()
{
  if (!gameStates.empty())
  {
    gameStates.back()->onExit();
    delete gameStates.back();
    gameStates.clear();
  }
}
