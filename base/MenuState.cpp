#include "MenuState.h"

#include <iostream>

const std::string MenuState::menuId = "MENU";

void MenuState::update()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->update();
  }
}

void MenuState::render()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->draw();
  }
}

bool MenuState::onEnter()
{

  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/button.png", "playbutton"))
  {
    return false;
  }

  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/exit.png", "exitbutton"))
  {
    return false;
  }

  //? Init Menu Buttons
  GameObject *playButton = new MenuButton(new LoaderParams(160, 80, 400, 100, "playbutton"), menuToPlay);
  GameObject *exitButton = new MenuButton(new LoaderParams(160, 230, 400, 100, "exitbutton"), exitFromMenu);

  //? Push to the list
  gameObjects.push_back(playButton);
  gameObjects.push_back(exitButton);

  return true;
}

bool MenuState::onExit()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->clean();
  }

  gameObjects.clear();

  TheTextureManager::Instance()->clearTexture("playbutton");
  TheTextureManager::Instance()->clearTexture("exitbutton");

  return true;
}

void MenuState::menuToPlay()
{
  TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromMenu()
{
  TheGame::Instance()->quit();
}