/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 18:21:38
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 19:02:16
 */

#ifndef __LEVELPARSER_H__
#define __LEVELPARSER_H__

#include "Game.h"
#include "TextureManager.h"
#include "Level.h"
#include "include/tinyxml.h"


class LevelParser
{
public:
  Level *parseLevel(const char *levelFile);

private:
  void parseTilesets(TiXmlElement *tilesetRoot, std::vector<Tileset> *tilesets);
  void parseTileLayer(TiXmlElement *layerRoot, std::vector<Layer *> *layers, const std::vector<Tileset> *tileset);

  int tileSize;
  int width;
  int height;
};

#endif /* __LEVELPARSER_H__ */
