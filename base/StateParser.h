/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 21:57:45
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:59:51
 */

#ifndef __StateParser__
#define __StateParser__

#include <iostream>
#include <vector>

#include "vendor/tinyxml/tinyxml.h"

#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

class GameObject;

class StateParser
{
public:
  bool parseState(const char *stateFile, std::string stateId, std::vector<std::string> *textureIds, std::vector<GameObject *> *objects);

private:
  void parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textureIds);
  void parseObjects(TiXmlElement *stateRoot, std::vector<GameObject *> *objects);
};

#endif