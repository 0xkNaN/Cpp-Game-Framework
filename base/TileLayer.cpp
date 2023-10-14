/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 18:16:55
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 18:20:58
 */

#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets) : tileSize(tileSize), tilesets(tilesets)
{
}

TileLayer::~TileLayer()
{
}

void TileLayer::update(Level *level)
{
}

void TileLayer::render()
{
}

Tileset TileLayer::getTilesetById(int tileId)
{
}