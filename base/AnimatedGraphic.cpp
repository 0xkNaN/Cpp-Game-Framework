/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-13 13:10:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 21:06:10
 */

#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic() : GameObjectSDL()
{
}

void AnimatedGraphic::load(const LoaderParams *params)
{
  GameObjectSDL::load(params);
  animSpeed = params->getAnimSpeed();
}

void AnimatedGraphic::update()
{
  currFrame = int((SDL_GetTicks() / (1000 / animSpeed)) % numFrames);
}

void AnimatedGraphic::draw()
{
  GameObjectSDL::draw();
}

void AnimatedGraphic::clean()
{
  GameObjectSDL::clean();
}