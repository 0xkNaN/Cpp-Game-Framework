/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-14 13:34:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 13:35:41
 */

#ifndef __LAYER__
#define __LAYER__

class Layer
{
public:
  virtual void update() = 0;
  virtual void render() = 0;

protected:
  virtual ~Layer() {}
};

#endif /* __LAYER__ */
