/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __TEXTURE_MANAGER__
#define __TEXTURE_MANAGER__

#include <iostream>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
  static TextureManager *Instance()
  {
    if (instance == 0)
      instance = new TextureManager();
    return instance;
  }

  bool load(SDL_Renderer *renderer, std::string name, std::string id);
  void draw(SDL_Renderer *renderer, std::string id, int x, int y, int w, int h, int currRow, int currFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void clearTexture(std::string textureId);

private:
  TextureManager() {}
  ~TextureManager() {}

  std::map<std::string, SDL_Texture *> textureMap;

  static TextureManager *instance;
};

typedef TextureManager TheTextureManager;
#endif