#include "texture_manager.h"
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
  SDL_Surface *tmpSurface = IMG_Load(texture);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::s_renderer, tmpSurface);
  if (tex == nullptr) {
    std::cout << "Error: Can't load Texture " << texture << "!" << std::endl;
  }
  SDL_FreeSurface(tmpSurface);

  return tex;
}

 void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
   SDL_RenderCopy(Game::s_renderer, tex, &src, &dest);
 }
