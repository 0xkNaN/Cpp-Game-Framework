/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#include "GameOverState.h"

#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"

const std::string GameOverState::gameOverId = "GAME_OVER";

void GameOverState::update()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->update();
  }
}

void GameOverState::render()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->draw();
  }
}

bool GameOverState::onEnter()
{
  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/gameover.png", "gameOverText"))
  {
    return false;
  }
  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/main.png", "mainButton"))
  {
    return false;
  }

  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/restart.png", "restartButton"))
  {
    return false;
  }

  GameObject *gameOverText = new AnimatedGraphic(new LoaderParams(280, 50, 190, 30, "gameOverText"), 2);
  GameObject *mainButton = new MenuButton(new LoaderParams(270, 180, 200, 80, "mainButton"), gameOverToMain);
  GameObject *restartButton = new MenuButton(new LoaderParams(270, 280, 200, 80, "restartButton"), restartPlay);

  gameObjects.push_back(gameOverText);
  gameObjects.push_back(mainButton);
  gameObjects.push_back(restartButton);

  return true;
}

bool GameOverState::onExit()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->clean();
  }

  gameObjects.clear();

  TheTextureManager::Instance()->clearTexture("gameOverText");
  TheTextureManager::Instance()->clearTexture("mainButton");
  TheTextureManager::Instance()->clearTexture("restartButton");

  return true;
}

void GameOverState::gameOverToMain()
{
  TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::restartPlay()
{
  TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}