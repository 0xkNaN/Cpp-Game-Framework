/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-10 23:01:48
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:58:24
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
  GameObjectSDL();

  virtual void update();
  virtual void draw();
  virtual void clean();

  virtual void load(const LoaderParams *params);

  int getWidth() const { return width; }
  int getHeight() const { return height; }
  Vector2D getPosition() const { return position; } //! &

protected:
  Vector2D position;
  Vector2D velocity;
  Vector2D acceleration;

  int width;
  int height;

  std::string textureId;

  int currRow;
  int currFrame;
  int numFrames;
  int animSpeed;
};

#endif