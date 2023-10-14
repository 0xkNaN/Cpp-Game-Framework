/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 13:10:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-13 23:57:08
 */

#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic() : GameObjectSDL()
{
}

void AnimatedGraphic::load(const LoaderParams *params)
{
  GameObjectSDL::load(params);
}

void AnimatedGraphic::update()
{
  currFrame = int((SDL_GetTicks() / (1000 / animSpeed)) % 4);
}

void AnimatedGraphic::draw()
{
  GameObjectSDL::draw();
}

void AnimatedGraphic::clean()
{
  GameObjectSDL::clean();
}