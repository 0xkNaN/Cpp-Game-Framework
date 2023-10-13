#ifndef __LOADER_PARAMS__
#define __LOADER_PARAMS__

#include <iostream>

class LoaderParams
{
public:
  LoaderParams(int x, int y, int w, int h, std::string textureId) : x(x), y(y), width(w), height(h), textureId(textureId)
  {
  }

  std::string getTextureId() const { return textureId; }

  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }

private:
  std::string textureId;

  int width;
  int height;

  int x;
  int y;
};

#endif