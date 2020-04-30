#include <SDL2/SDL.h>

int main()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow("Red Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 0, 0 , 255);  // red
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(4000);
  
  return 0;
}
