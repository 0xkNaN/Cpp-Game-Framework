/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 17:57:33
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 18:15:26
 */

#ifndef __TILELAYER__
#define __TILELAYER__

#include <iostream>
#include <vector>

#include "Vector2D.h"
#include "Level.h"
#include "Layer.h"

class TileLayer : public Layer
{
public:
  TileLayer(int tileSize, const std::vector<Tileset> &tilesets);
  virtual ~TileLayer();

  virtual void update(Level *level);
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

#endif /* __TILELAYER_H__ */
