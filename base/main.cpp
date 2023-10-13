#include "Game.h"
#include "constants.h"

int main(int argc, char *argv[])
{
  Uint32 frameStart, frameTime;

  //? Init
  if (TheGame::Instance()->init("Chapter 0"))
  {
    std::cout << "game init success!\n";

    //? Game loop
    while (TheGame::Instance()->running())
    {
      frameStart = SDL_GetTicks();

      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();

      frameTime = SDL_GetTicks() - frameStart;

      if (frameTime < FRAME_TIME)
      {
        SDL_Delay((int)(FRAME_TIME - frameTime));
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
  return 0;
}