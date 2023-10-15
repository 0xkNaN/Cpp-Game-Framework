/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-07 22:34:21
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-14 00:01:23
 */

#include "constants.h"
#include "Game.h"

int main(int argc, char *argv[])
{
  Uint32 frameStart, frameTime;

  //? Init
  if (TheGame::Instance()->init("Chapter 0"))
  {
    std::cout << "__GAME__INI__\n";

    //? Game loop
    while (TheGame::Instance()->running())
    {
      frameStart = SDL_GetTicks();

      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();

      frameTime = SDL_GetTicks() - frameStart;

      if (frameTime < FRAME_RATE)
      {
        SDL_Delay((int)(FRAME_RATE - frameTime));
      }
    }
  }
  else
  {
    std::cout << "game init failure - " << SDL_GetError() << "\n";
    return -1;
  }

  //? Cleanup
  TheGame::Instance()->clean();
  std::cout << "__GAME__OUT__\n";
  return 0;
}