/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 19:51:57
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:58:02
 */

#include "GameObjectFactory.h"

GameObjectFactory *GameObjectFactory::instance = 0;

bool GameObjectFactory::registerType(std::string typeId, BaseCreator *creator)
{
  std::map<std::string, BaseCreator *>::iterator i = creators.find(typeId);

  //? If the typs is already registered, return
  if (i != creators.end())
  {
    delete creator;
    return false;
  }

  creators[typeId] = creator;
  return true;
}

GameObject *GameObjectFactory::create(std::string typeId)
{
  std::map<std::string, BaseCreator *>::iterator i = creators.find(typeId);

  //? If the typs is already registered, return
  if (i == creators.end())
  {
    std::cout << "Could not find type: " << typeId << "\n";
    return NULL;
  }

  BaseCreator *creator = (*i).second;
  return creator->createGameObject();
}