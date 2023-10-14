/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 21:00:09
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 10:17:38
 */

#include "PlayState.h"

#include <iostream>

#include "PauseState.h"
#include "GameOverState.h"

#include "Player.h"
#include "Enemy.h"

const std::string PlayState::playId = "play";

void PlayState::update()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->update();
  }

  //? Change State to MenuSate when ESC is pressed
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
  {
    TheGame::Instance()->getStateMachine()->pushState(new PauseState());
  }

  //? Change State to GameOverState when Collession
  GameObjectSDL *player = dynamic_cast<GameObjectSDL *>(gameObjects[0]);
  GameObjectSDL *enemy1 = dynamic_cast<GameObjectSDL *>(gameObjects[1]);
  GameObjectSDL *enemy2 = dynamic_cast<GameObjectSDL *>(gameObjects[2]);

  if (checkCollision(player, enemy1) || checkCollision(player, enemy2))
  {
    TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
  }
}

void PlayState::render()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->draw();
  }
}

bool PlayState::onEnter()
{
  //? Parse State from Data File
  StateParser stateParser;
  stateParser.parseState("test.xml", playId, &textureIdList, &gameObjects);

  return true;
}

bool PlayState::onExit()
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

bool PlayState::checkCollision(GameObjectSDL *p1, GameObjectSDL *p2)
{
  //? Using SDL_IntersectRect
  SDL_Rect rectP1, rectP2, rectRes;

  rectP1.x = p1->getPosition().getX();
  rectP1.y = p1->getPosition().getY();
  rectP1.w = p1->getWidth();
  rectP1.h = p1->getHeight();

  rectP2.x = p2->getPosition().getX();
  rectP2.y = p2->getPosition().getY();
  rectP2.w = p2->getWidth();
  rectP2.h = p2->getHeight();

  return SDL_IntersectRect(&rectP1, &rectP2, &rectRes);

  //? TheBook Solution
  // int topA, leftA, rightA, bottomA;
  // int topB, leftB, rightB, bottomB;

  // topA = p1->getPosition().getY();
  // leftA = p1->getPosition().getX();
  // rightA = p1->getPosition().getX() + p1->getWidth();
  // bottomA = p1->getPosition().getY() + p1->getHeight();

  // topB = p2->getPosition().getY();
  // leftB = p2->getPosition().getX();
  // rightB = p2->getPosition().getX() + p2->getWidth();
  // bottomB = p2->getPosition().getY() + p2->getHeight();

  // if (bottomA <= topB)
  //   return false;
  // if (topA >= bottomB)
  //   return false;
  // if (rightA <= leftB)
  //   return false;
  // if (leftA >= rightB)
  //   return false;

  // return true;
}