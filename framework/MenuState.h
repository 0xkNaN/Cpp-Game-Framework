/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-12 20:54:17
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 09:39:49
 */

#ifndef __MenuState_h__
#define __MenuState_h__

#include <vector>

#include "GameState.h"

class MenuState : public GameState
{
protected:
  typedef void (*Callback)();
  virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;

  std::vector<Callback> callbacks;
};

#endif