/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 13:25:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 19:21:44
 */

#ifndef __LEVEL__
#define __LEVEL__

#include <iostream>
#include <vector>

#include "LevelParser.h"
#include "Layer.h"

struct Tileset
{
  int firstGridId;
  int tileWidth;
  int tileHeight;
  int spacing;
  int margin;
  int width;
  int height;
  int numCols;
  std::string name;
};

class Level
{
public:
  ~Level() {}

  void update();
  void render();

  std::vector<Tileset> *getTilesets() { return &tilesets; };
  std::vector<Layer *> *getLayers() { return &layers; }

private:
  Level();
  friend class LevelParser;

  std::vector<Tileset> tilesets;
  std::vector<Layer *> layers;
};

#endif /* __LEVEL__ */
