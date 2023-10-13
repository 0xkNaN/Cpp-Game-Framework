/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#include "PauseState.h"

#include "MenuState.h"
#include "MenuButton.h"

const std::string PauseState::pauseId = "PAUSE_MENU";

void PauseState::update()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->update();
  }
}

void PauseState::render()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->draw();
  }
}

bool PauseState::onEnter()
{

  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/main.png", "mainbutton"))
  {
    return false;
  }

  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/menu/resume.png", "resumebutton"))
  {
    return false;
  }

  GameObject *mainButton = new MenuButton(new LoaderParams(260, 80, 200, 80, "mainbutton"), pauseToMain);
  GameObject *resumeButton = new MenuButton(new LoaderParams(260, 230, 200, 80, "resumebutton"), resumePlay);

  gameObjects.push_back(mainButton);
  gameObjects.push_back(resumeButton);

  return true;
}

bool PauseState::onExit()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->clean();
  }

  gameObjects.clear();

  TheTextureManager::Instance()->clearTexture("mainbutton");
  TheTextureManager::Instance()->clearTexture("resumebutton");

  return true;
}

void PauseState::pauseToMain()
{
  TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::resumePlay()
{
  TheGame::Instance()->getStateMachine()->popState();
}