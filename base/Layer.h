/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 13:34:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:23:36
 */

#ifndef __Layer_h__
#define __Layer_h__

class Level;

class Layer
{
public:
  virtual ~Layer() {}

  virtual void update() = 0;
  virtual void render() = 0;
};

#endif