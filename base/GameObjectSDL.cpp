#include "GameObjectSDL.h"

#include "Game.h"
#include "TextureManager.h"

GameObjectSDL::GameObjectSDL(const LoaderParams *params) : GameObject(params), position(params->getX(), params->getY()), velocity(0, 0), acceleration(0, 0)
{
  textureId = params->getTextureId();

  width = params->getWidth();
  height = params->getHeight();

  currRow = 1;
  currFrame = 1;
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