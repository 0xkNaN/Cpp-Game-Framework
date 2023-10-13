/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#include "PlayState.h"

#include <iostream>

#include "PauseState.h"
#include "GameOverState.h"

#include "Player.h"
#include "Enemy.h"

const std::string PlayState::playId = "PLAY_LEVEL_1";

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
  if (checkCollision(
          dynamic_cast<GameObjectSDL *>(gameObjects[0]),
          dynamic_cast<GameObjectSDL *>(gameObjects[1])))
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
  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/helicopter.png", "helicopter"))
  {
    return false;
  }

  if (!TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), "assets/helicopter2.png", "helicopterEnemy"))
  {
    return false;
  }

  GameObject *player = new Player(new LoaderParams(400, 50, 128, 55, "helicopter"));
  gameObjects.push_back(player);

  GameObject *enemy = new Enemy(new LoaderParams(50, 50, 128, 55, "helicopterEnemy"));
  gameObjects.push_back(enemy);

  return true;
}

bool PlayState::onExit()
{
  for (int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->clean();
  }

  gameObjects.clear();

  TheTextureManager::Instance()->clearTexture("helicopter");

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