/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-08 18:18:57
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:59:28
 */

#include "constants.h"
#include "Game.h"
#include "InputHandler.h"
#include "MainMenuState.h"

#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "Player.h"
#include "Enemy.h"

Game *Game::instance = 0;

bool Game::init(const char *title)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "SDL init fail\n";
    return false;
  }

  this->window = SDL_CreateWindow(
      title,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
      0);
  if (!this->window)
  {
    std::cout << "SDL window fail\n";
    return false;
  }

  this->renderer = SDL_CreateRenderer(this->window, -1, 0);
  if (!renderer)
  {
    std::cout << "SDL renderer fail\n";
    return false;
  }
  else
  {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
  }

  //? Register Factories
  TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
  TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
  TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
  TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());

  //? Init GameStateMachine
  gameStateMachine = new GameStateMachine();
  gameStateMachine->changeState(new MainMenuState());

  //? Init InputHandler
  TheInputHandler::Instance()->initJoysticks();

  //? Game Loop
  this->isRunning = true;
  return true;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::update()
{
  gameStateMachine->update();
}

void Game::render()
{
  SDL_RenderClear(this->renderer);

  gameStateMachine->render();

  SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
  TheInputHandler::Instance()->clean();

  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);

  SDL_Quit();
}
