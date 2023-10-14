/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 19:51:22
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:58:08
 */

#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include "map"
#include "string"
#include <iostream>
#include "GameObject.h"

class BaseCreator
{
public:
  virtual ~BaseCreator() {}
  virtual GameObject *createGameObject() const = 0;
};

class GameObjectFactory
{
public:
  static GameObjectFactory *Instance()
  {
    if (instance == 0)
      instance = new GameObjectFactory();
    return instance;
  }

  bool registerType(std::string typeId, BaseCreator *creator);

  GameObject *create(std::string typeId);

private:
  GameObjectFactory() {}
  ~GameObjectFactory() {}
  static GameObjectFactory *instance;

  std::map<std::string, BaseCreator *> creators;
};

typedef GameObjectFactory TheGameObjectFactory;
#endif