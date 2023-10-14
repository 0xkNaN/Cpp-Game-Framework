/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 18:21:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 19:39:51
 */

#include "LevelParser.h"

Level *LevelParser::parseLevel(const char *levelFile)
{
  TiXmlDocument xmlDOC;
  if (!xmlDOC.LoadFile(levelFile))
  {
    std::cout << "XML PARSER ERROR\n";
    return NULL;
  }

  //? Create Level
  Level *level = new Level();
  TiXmlElement *root = xmlDOC.RootElement();
  root->Attribute("tilewidth", &tileSize);
  root->Attribute("width", &width);
  root->Attribute("height", &height);

  //? Parse the Tilesets/Layers
  for (TiXmlElement *e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("tileset"))
    {
      parseTilesets(e, level->getTilesets());
    }

    if (e->Value() == std::string("layer"))
    {
      parseTileLayer(e, level->getLayers(), level->getTilesets());
    }
  }

  return level;
}

void LevelParser::parseTilesets(TiXmlElement *tilesetRoot, std::vector<Tileset> *tilesets)
{
  //? Add tileset to TextureManager
  TheTextureManager::Instance()->load(
      TheGame::Instance()->getRenderer(),
      tilesetRoot->FirstChildElement()->Attribute("source"),
      tilesetRoot->Attribute("name"));

  //? Create Tileset Object
  Tileset tileset;

  tileset.name = tilesetRoot->Attribute("name");
  tilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
  tilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
  tilesetRoot->Attribute("firstgid", &tileset.firstGridId);
  tilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
  tilesetRoot->Attribute("tileheight", &tileset.tileHeight);
  tilesetRoot->Attribute("spacing", &tileset.spacing);
  tilesetRoot->Attribute("margin", &tileset.margin);
  tileset.numCols = tileset.width / (tileset.tileWidth + tileset.spacing);

  tilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement *layerRoot, std::vector<Layer *> *layers, const std::vector<Tileset> *tileset)
{
}