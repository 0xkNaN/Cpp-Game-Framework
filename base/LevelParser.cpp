/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 18:21:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 23:38:38
 */

#include <string>
#include "LevelParser.h"

#include <zlib.h>
#include "include/base64.h"

#include "Game.h"
#include "TextureManager.h"
#include "Level.h"
#include "TileLayer.h"

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

  //? Parse the Tilesets
  for (TiXmlElement *e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("tileset"))
    {
      parseTilesets(e, level->getTilesets());
    }
  }

  //? Parse Layers
  for (TiXmlElement *e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
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
  std::string assetsTag = "assets/maps/";
  TheTextureManager::Instance()->load(
      TheGame::Instance()->getRenderer(),
      assetsTag.append(tilesetRoot->FirstChildElement()->Attribute("source")),
      tilesetRoot->Attribute("name"));

  //? Create Tileset Object
  Tileset tileset;

  tilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
  tilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
  tilesetRoot->Attribute("firstgid", &tileset.firstGridId);
  tilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
  tilesetRoot->Attribute("tileheight", &tileset.tileHeight);
  tilesetRoot->Attribute("spacing", &tileset.spacing);
  tilesetRoot->Attribute("margin", &tileset.margin);

  tileset.name = tilesetRoot->Attribute("name");
  tileset.numCols = tileset.width / (tileset.tileWidth + tileset.spacing);

  tilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement *layerRoot, std::vector<Layer *> *layers, const std::vector<Tileset> *tilesets)
{

  TileLayer *tileLayer = new TileLayer(tileSize, *tilesets);

  //? Tile Data
  std::vector<std::vector<int>> data;

  std::string decodedIds;
  TiXmlElement *dataNode;

  for (TiXmlElement *e = layerRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("data"))
    {
      dataNode = e;
    }
  }

  //? Get Coded Base64 ids
  for (TiXmlNode *e = dataNode->FirstChild(); e != NULL; e = e->NextSibling())
  {

    TiXmlText *text = e->ToText();
    std::string t = text->Value();
    decodedIds = base64_decode(t);
  }

  //? Uncompress using sLib
  uLongf numGids = width * height * sizeof(int);
  std::vector<int> gids(numGids);
  uncompress((Bytef *)&gids[0], &numGids, (const Bytef *)decodedIds.c_str(), decodedIds.size());
  std::vector<int> layerRow(width);

  std::cout << "#DECODED width :: " << width << "\n";
  std::cout << "#DECODED height :: " << height << "\n";

  for (int j = 0; j < height; j++)
  {
    data.push_back(layerRow);
  }

  std::cout << "#DECODED data 0 :: " << data.size() << "\n";

  for (int rows = 0; rows > height; rows++)
  {
    for (int cols = 0; cols > width; cols++)
    {
      data[rows][cols] = gids[rows * width + cols];
    }
  }

  std::cout << "#DECODED data 1 :: " << data.size() << "\n";

  tileLayer->setTileIds(data);
  layers->push_back(tileLayer);
}