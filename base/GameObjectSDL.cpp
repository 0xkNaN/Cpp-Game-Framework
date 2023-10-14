/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-10 23:06:20
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:58:14
 */

#include "GameObjectSDL.h"

#include "Game.h"
#include "TextureManager.h"

GameObjectSDL::GameObjectSDL() : GameObject()
{
}

void GameObjectSDL::load(const LoaderParams *params)
{
  position = Vector2D(params->getX(), params->getY());
  velocity = Vector2D(0, 0);
  acceleration = Vector2D(0, 0);

  width = params->getWidth();
  height = params->getHeight();

  textureId = params->getTextureId();
  currRow = 1;
  currFrame = 1;
  numFrames = params->getNumFrames();
  animSpeed = params->getAnimSpeed();
}

void GameObjectSDL::update()
{
  velocity += acceleration;
  position += velocity;
}

void GameObjectSDL::draw()
{
  //! TMP Flip Texture to face MousePosition
  if (velocity.getX() > 0)
  {
    TextureManager::Instance()->draw(
        TheGame::Instance()->getRenderer(),
        textureId,
        (int)position.getX(),
        (int)position.getY(),
        width,
        height,
        currRow,
        currFrame,
        SDL_FLIP_HORIZONTAL);
  }
  else
  {
    TextureManager::Instance()->draw(
        TheGame::Instance()->getRenderer(),
        textureId,
        (int)position.getX(),
        (int)position.getY(),
        width,
        height,
        currRow,
        currFrame);
  }
}

void GameObjectSDL::clean()
{
}