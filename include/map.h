#pragma once

#ifndef CHRUSEL_MAP_H
#define CHRUSEL_MAP_H

#include "game.h"
#include <SDL2/SDL.h>

class Map {
public:
    Map();
    ~Map();

    void loadMap(int arr[20][25]);

    void drawMap();

private:
    SDL_Rect m_src;
    SDL_Rect m_dest;
    SDL_Texture* m_dirt;
    SDL_Texture* m_grass;
    SDL_Texture* m_water;

    int m_map[20][25];
};

#endif // #ifndef CHRUSEL_MAP_H

