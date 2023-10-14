/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 13:18:38
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 11:17:32
 */

#include "GameOverState.h"

#include "MainMenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"

const std::string GameOverState::gameOverId = "over";

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
  //? Parse State from Data File
  StateParser stateParser;
  stateParser.parseState("test.xml", gameOverId, &textureIdList, &gameObjects);

  //? Set Callbaks
  callbacks.push_back(0); //? empty
  callbacks.push_back(gameOverToMain);
  callbacks.push_back(restartPlay);
  // ...
  setCallbacks(callbacks);

  return true;
}

bool GameOverState::onExit()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->clean();
  }

  gameObjects.clear();

  for (int i = 0; i < textureIdList.size(); i++)
  {
    TheTextureManager::Instance()->clearTexture(textureIdList[i]);
  }

  return true;
}

void GameOverState::setCallbacks(const std::vector<Callback> &callbacks)
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    if (dynamic_cast<MenuButton *>(gameObjects[i]))
    {
      MenuButton *button = dynamic_cast<MenuButton *>(gameObjects[i]);
      button->setCallback(callbacks[button->getCallbackId()]);
    }
  }
}

void GameOverState::gameOverToMain()
{
  TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::restartPlay()
{
  TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}