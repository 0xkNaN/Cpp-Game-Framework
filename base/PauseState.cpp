/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 12:10:36
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:30:10
 */

#include "PauseState.h"
#include "MainMenuState.h"
#include "MenuButton.h"

const std::string PauseState::pauseId = "pause";

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

  StateParser stateParser;
  stateParser.parseState("test.xml", pauseId, &textureIdList, &gameObjects);
  callbacks.push_back(0);
  callbacks.push_back(pauseToMain);
  callbacks.push_back(resumePlay);
  setCallbacks(callbacks);

  return true;
}

bool PauseState::onExit()
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

void PauseState::setCallbacks(const std::vector<Callback> &callbacks)
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

void PauseState::pauseToMain()
{
  TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::resumePlay()
{
  TheGame::Instance()->getStateMachine()->popState();
}