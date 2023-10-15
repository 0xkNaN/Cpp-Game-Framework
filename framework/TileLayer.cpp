/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 18:16:55
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 23:29:07
 */

#include "TileLayer.h"

#include "Game.h"
#include "TextureManager.h"

TileLayer::TileLayer(
    int tileSize,
    const std::vector<Tileset> &tilesets) : tileSize(tileSize),
                                            tilesets(tilesets),
                                            position(0, 0),
                                            velocity(0, 0)
{
  numCols = (TheGame::Instance()->getGameWidth() / tileSize);
  numRows = (TheGame::Instance()->getGameHeight() / tileSize);
}

TileLayer::~TileLayer()
{
}

void TileLayer::update()
{
  position += velocity;
}

void TileLayer::render()
{
  int x, y, x2, y2 = 0;

  x = position.getX() / tileSize;
  y = position.getY() / tileSize;

  x2 = int(position.getX()) % tileSize;
  y2 = int(position.getY()) % tileSize;

  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      int id = tileIds[i + y][j + x];

      if (id == 0)
        continue;

      Tileset tileset = getTilesetById(id);

      id--;

      std::cout << "Texture :: " << tileset.name << "\n";

      TheTextureManager::Instance()->drawTile(
          TheGame::Instance()->getRenderer(),
          tileset.name,
          tileset.margin,
          tileset.spacing,
          (j * tileSize) - x2,
          (i * tileSize) - y2,
          tileSize,
          tileSize,
          (id - (tileset.firstGridId - 1)) / tileset.numCols,
          (id - (tileset.firstGridId - 1)) % tileset.numCols);
    }
  }
}

Tileset TileLayer::getTilesetById(int tileId)
{
  for (int i = 0; i < tilesets.size(); i++)
  {
    if (i + 1 <= tilesets.size() - 1)
    {

      if (tileId >= tilesets[i].firstGridId && tileId < tilesets[i + 1].firstGridId)
      {
        return tilesets[i];
      }
    }
    else
    {
      return tilesets[i];
    }
  }

  std::cout << "did not find tileset, returning empty tileset\n";
  Tileset t;
  return t;
}