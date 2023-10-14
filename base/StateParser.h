/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 21:57:45
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 12:37:49
 */

#ifndef __StateParser__
#define __StateParser__

#include <iostream>
#include <vector>

// #include "../vendor/tinyxml/tinyxml.h"
// #include "tinyxml/tinyxml.h"

#include "include/tinyxml.h"

class GameObject;

class StateParser
{
public:
  StateParser() {}
  ~StateParser() {}

  bool parseState(const char *stateFile, std::string stateId, std::vector<std::string> *textureIds, std::vector<GameObject *> *objects);

private:
  void parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textureIds);
  void parseObjects(TiXmlElement *stateRoot, std::vector<GameObject *> *objects);
};

#endif