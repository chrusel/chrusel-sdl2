#pragma once

#ifndef CHRUSEL_TEXTURE_MANAGER_H
#define CHRUSEL_TEXTURE_MANAGER_H

#include "game.h"

class TextureManager {
public:
  static SDL_Texture* LoadTexture(const char* filename);
  static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif // CHRUSEL_TEXTURE_MANAGER_H