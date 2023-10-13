/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __GAMEOBJECT_SDL__
#define __GAMEOBJECT_SDL__

#include "SDL2/SDL.h"

#include "GameObject.h"
#include "LoaderParams.h"

#include "Vector2D.h"

class GameObjectSDL : public GameObject
{
public:
  GameObjectSDL(const LoaderParams *params);

  virtual void update();
  virtual void draw();
  virtual void clean();

  int getWidth() const { return width; }
  int getHeight() const { return height; }
  Vector2D getPosition() const { return position; }

protected:
  std::string textureId;

  int width;
  int height;

  int currRow;
  int currFrame;

  Vector2D position;
  Vector2D velocity;
  Vector2D acceleration;
};

#endif