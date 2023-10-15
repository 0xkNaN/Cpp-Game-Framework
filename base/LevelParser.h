/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 18:21:38
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:27:52
 */

#ifndef __LevelParser_h__
#define __LevelParser_h__

#include <iostream>
#include <vector>
#include "include/tinyxml.h"

class Level;
struct Tileset;
class Layer;
class TileLayer;

class LevelParser
{
public:
  Level *parseLevel(const char *levelFile);

private:
  void parseTilesets(TiXmlElement *tilesetRoot, std::vector<Tileset> *tilesets);
  void parseTileLayer(TiXmlElement *layerRoot, std::vector<Layer *> *layers, const std::vector<Tileset> *tilesets);

  int tileSize;
  int width;
  int height;
};

#endif