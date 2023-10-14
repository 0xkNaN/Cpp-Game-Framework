/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 22:05:53
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 11:08:55
 */

#include "StateParser.h"

#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

bool StateParser::parseState(const char *stateFile, std::string stateId, std::vector<std::string> *textureIds, std::vector<GameObject *> *objects)
{
  //? Create the XML Document
  TiXmlDocument xmlDOC;

  //? Load the state file
  if (!xmlDOC.LoadFile(stateFile))
  {
    // std::cout << xmlDOC.ErrorDesc() << "\n";
    std::cout << "XML PARSER ERROR\n";
    return false;
  }

  //? Get the ROOT element -> <states>
  TiXmlElement *root = xmlDOC.RootElement();

  //? Get State Root -> <stateId>
  TiXmlElement *stateRoot = 0;
  for (TiXmlElement *e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == stateId)
    {
      stateRoot = e;
    }
  }

  //? Get State -> <textures>
  TiXmlElement *textureRoot = 0;
  for (TiXmlElement *e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("textures"))
    {
      textureRoot = e;
      break;
    }
  }
  // ...
  parseTextures(textureRoot, textureIds);

  //? Get State -> <objects>
  TiXmlElement *objectRoot = 0;
  for (TiXmlElement *e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("objects"))
    {
      objectRoot = e;
      break;
    }
  }
  // ...
  parseObjects(objectRoot, objects);

  return true;
}

void StateParser::parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textureIds)
{
  for (TiXmlElement *e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    std::string filename = e->Attribute("filename");
    std::string textureId = e->Attribute("id");

    textureIds->push_back(textureId);
    TheTextureManager::Instance()->load(TheGame::Instance()->getRenderer(), filename, textureId);
  }
}

void StateParser::parseObjects(TiXmlElement *stateRoot, std::vector<GameObject *> *objects)
{
  for (TiXmlElement *e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    std::string type, textureId;
    int x, y, width, height, numFrames, animSpeed, callbackId;

    type = e->Attribute("type");

    e->Attribute("x", &x);
    e->Attribute("y", &y);
    e->Attribute("width", &width);
    e->Attribute("height", &height);
    e->Attribute("numFrames", &numFrames);
    e->Attribute("animSpeed", &animSpeed);
    e->Attribute("callbackId", &callbackId);

    textureId = e->Attribute("textureId");

    GameObject *gameObject = TheGameObjectFactory::Instance()->create(type);
    gameObject->load(new LoaderParams(x, y, width, height, textureId, numFrames, animSpeed, callbackId));

    objects->push_back(gameObject);
  }
}
