#include <SDL2/SDL.h>
#include "game.h"

int main()
{
  constexpr uint32_t FPS {60};
  constexpr uint32_t frameDelay {1000/FPS};

  Game *game = new Game();
  game->init("sdl2game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);


  while (game->running()) {
    uint32_t frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    // limit frame rate:
    int32_t frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < frameDelay) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();

  return 0;
}
