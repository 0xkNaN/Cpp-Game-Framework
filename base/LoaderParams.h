/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-10 22:46:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 00:01:29
 */

#ifndef __LOADER_PARAMS__
#define __LOADER_PARAMS__

#include <string>

class LoaderParams
{
public:
  LoaderParams(
      int x,
      int y,
      int width,
      int height,
      std::string textureId,
      int numFrames,
      int animSpeed = 0,
      int callbackId = 0) : x(x),
                            y(y),
                            width(width),
                            height(height),
                            textureId(textureId),
                            numFrames(numFrames),
                            animSpeed(animSpeed),
                            callbackId(callbackId)
  {
  }

  std::string getTextureId() const { return textureId; }

  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
  int getNumFrames() const { return numFrames; }
  int getAnimSpeed() const { return animSpeed; }
  int getCallbackId() const { return callbackId; }

private:
  int x;
  int y;

  int width;
  int height;

  std::string textureId;

  int numFrames;
  int animSpeed;

  int callbackId;
};

#endif