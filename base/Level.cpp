/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 13:34:07
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 13:50:15
 */

#include "Level.h"

Level::Level()
{
}

void Level::update()
{
  for (int i = 0; i < layers.size(); i++)
  {
    layers[i]->update();
  }
}

void Level::render()
{
  for (int i = 0; i < layers.size(); i++)
  {
    layers[i]->render();
  }
}
