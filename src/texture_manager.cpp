#include "texture_manager.h"
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
  SDL_Surface *tmpSurface = IMG_Load(texture);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::s_renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);

  return tex;
}
