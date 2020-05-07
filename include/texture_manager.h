#pragma once

#ifndef CHRUSEL_TEXTURE_MANAGER_H
#define CHRUSEL_TEXTURE_MANAGER_H

#include "game.h"

class TextureManager {
public:
  static SDL_Texture* LoadTexture(const char* filename);
};

#endif // CHRUSEL_TEXTURE_MANAGER_H