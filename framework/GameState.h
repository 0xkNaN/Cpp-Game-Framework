/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 20:39:03
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:21:21
 */

#ifndef __GameState_h__
#define __GameState_h__

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
  GameState() {}

  std::vector<std::string> textureIdList;
};

#endif