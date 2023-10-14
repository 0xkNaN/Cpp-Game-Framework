/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 20:54:19
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:12:42
 */

#include "MainMenuState.h"

#include <iostream>

// #include "PlayState.h"
#include "MenuButton.h"

const std::string MainMenuState::menuId = "menu";

void MainMenuState::update()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->update();
  }
}

void MainMenuState::render()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->draw();
  }
}

bool MainMenuState::onEnter()
{

  //? Parse State from Data File
  StateParser stateParser;
  stateParser.parseState("test.xml", menuId, &textureIdList, &gameObjects);

  //? Set Callbaks
  callbacks.push_back(0); //? empty
  callbacks.push_back(menuToPlay);
  callbacks.push_back(exitFromMenu);
  // ...
  setCallbacks(callbacks);

  return true;

  //? OLD
  // if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/button.png", "playbutton"))
  // {
  //   return false;
  // }

  // if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/exit.png", "exitbutton"))
  // {
  //   return false;
  // }

  // //? Init Menu Buttons
  // GameObject *playButton = new MenuButton(new LoaderParams(160, 80, 400, 100, "playbutton"), menuToPlay);
  // GameObject *exitButton = new MenuButton(new LoaderParams(160, 230, 400, 100, "exitbutton"), exitFromMenu);

  // //? Push to the list
  // gameObjects.push_back(playButton);
  // gameObjects.push_back(exitButton);

  // return true;
}

bool MainMenuState::onExit()
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

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks)
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

void MainMenuState::menuToPlay()
{
  // TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::exitFromMenu()
{
  TheGame::Instance()->quit();
}