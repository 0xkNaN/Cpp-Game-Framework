/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 17:57:33
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 23:27:02
 */

#ifndef __TileLayer_h__
#define __TileLayer_h__

#include <iostream>
#include <vector>

#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

class TileLayer : public Layer
{
public:
  TileLayer(int tileSize, const std::vector<Tileset> &tilesets);
  virtual ~TileLayer();

  virtual void update();
  virtual void render();

  void setTileIds(const std::vector<std::vector<int>> &data) { tileIds = data; }
  void setTileSize(int tilesize) { tileSize = tilesize; }
  void setTileWidth(int mapwidth) { mapWidth = mapwidth; }

  int getTileSize() { return tileSize; }

  const std::vector<std::vector<int>> &getTileIds() { return tileIds; }

  Tileset getTilesetById(int tileId);

  const Vector2D getPosition() { return position; }

private:
  int numCols;
  int numRows;
  int tileSize;

  int mapWidth;

  Vector2D position;
  Vector2D velocity;

  const std::vector<Tileset> &tilesets;
  std::vector<std::vector<int>> tileIds;
};

#endif