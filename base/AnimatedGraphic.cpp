#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams *params, int animSpeed) : GameObjectSDL(params), animSpeed(animSpeed)
{
}

AnimatedGraphic::~AnimatedGraphic()
{
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