#include "TextureManager.h"

TextureManager *TextureManager::instance = 0;

bool TextureManager::load(SDL_Renderer *renderer, std::string name, std::string id)
{
  SDL_Surface *tmpSurface = IMG_Load(name.c_str());
  if (tmpSurface == 0)
    return false;

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);

  if (texture == 0)
    return false;

  this->textureMap[id] = texture;
  return true;
}

void TextureManager::draw(SDL_Renderer *renderer, std::string id, int x, int y, int w, int h, int currRow, int currFrame, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.w = desRect.w = w;
  srcRect.h = desRect.h = h;
  srcRect.x = w * currFrame;
  srcRect.y = h * (currRow - 1); //? Rows starts at 1;
  desRect.x = x;
  desRect.y = y;

  SDL_RenderCopyEx(renderer, this->textureMap[id], &srcRect, &desRect, 0, 0, flip);
}

void TextureManager::clearTexture(std::string textureId)
{
  textureMap.erase(textureId);
}