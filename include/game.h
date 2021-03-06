#pragma once

#ifndef CHRUSEL_GAME_H
#define CHRUSEL_GAME_H

#include <SDL2/SDL.h>

class Game {
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return m_isRunning; };
    static SDL_Renderer* s_renderer;

private:
    bool m_isRunning;
    SDL_Window *m_window;
};

#endif // #ifndef CHRUSEL_GAME_H

