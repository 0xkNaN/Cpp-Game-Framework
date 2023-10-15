/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 20:59:56
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:02:26
 */

#ifndef __PlayState__
#define __PlayState__

#include <vector>

#include "Game.h"
#include "GameState.h"
#include "InputHandler.h"
#include "StateParser.h"
#include "LevelParser.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "GameObjectSDL.h"

class Level;

class PlayState : public GameState
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const { return playId; }

  bool checkCollision(GameObjectSDL *p1, GameObjectSDL *p2);

private:
  static const std::string playId;
  std::vector<GameObject *> gameObjects;

  Level *level;
};

#endif