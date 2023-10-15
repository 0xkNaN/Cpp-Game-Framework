/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-08 21:44:18
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 20:40:02
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
  void drawTile(SDL_Renderer *renderer, std::string id, int margin, int spacing, int x, int y, int w, int h, int currRow, int currFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void clearTexture(std::string textureId);

private:
  TextureManager() {}
  ~TextureManager() {}

  std::map<std::string, SDL_Texture *> textureMap;

  static TextureManager *instance;
};

typedef TextureManager TheTextureManager;
#endif