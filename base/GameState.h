/*
 * @Author: Hassen Rmili
 * @Date: 2023-10-13 15:29:08
 */

#ifndef __GameState__
#define __GameState__

#include <iostream>
#include <string>
#include <vector>

class GameState
{
public:
  virtual ~GameState() {}

  virtual void update() = 0;
  virtual void render() = 0;

  virtual bool onEnter() = 0;
  virtual bool onExit() = 0;

  virtual std::string getStateId() const = 0;

protected:
  GameState() : loadingComplete(false), exiting(false) {}

  bool loadingComplete;
  bool exiting;

  std::vector<std::string> textureIdList;
};

#endif