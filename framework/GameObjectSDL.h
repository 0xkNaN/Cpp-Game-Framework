/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-10 23:01:48
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:36:42
 */

#ifndef __GameObjectSDL_h__
#define __GameObjectSDL_h__

#include "SDL2/SDL.h"

#include "GameObject.h"
#include "Vector2D.h"
#include "LoaderParams.h"

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