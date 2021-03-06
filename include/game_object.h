#pragma once

#ifndef CHRUSEL_GAME_OBJECT_H
#define CHRUSEL_GAME_OBJECT_H

#include "game.h"
#include <SDL2/SDL.h>

class GameObject {
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void update();
    void render();

private:
    int m_xpos;
    int m_ypos;
    SDL_Texture* m_objTexure;
    SDL_Rect m_srcRect;
    SDL_Rect m_destRect;
};

#endif // #ifndef CHRUSEL_GAME_OBJECT_H

