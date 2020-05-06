#include "game.h"
#include <SDL2/SDL_image.h>
#include <iostream>

// temp global vars
SDL_Texture* g_playerTex {};
SDL_Rect g_srcR {} , g_destR {};
int g_cnt = {0};

Game::Game() {
}

Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags {0};
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL2 Subsystems initialized!" << std::endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_window) {
            std::cout << "Window created!" << std::endl;
        }
        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if (m_renderer) {
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        m_isRunning = true;

        SDL_Surface* tmpSurface = IMG_Load("/data/chrusel-sdl2/assets/player-frontal-48.png");
        g_playerTex = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
        SDL_FreeSurface(tmpSurface);

    } else {
        m_isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    g_cnt++;
    g_destR.x = g_cnt % 800;
    if (g_destR.x == 0)
        g_destR.y = ++g_destR.y % 600;
    g_destR.h = 48;
    g_destR.w = 48;
//    std::cout << m_cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, g_playerTex, NULL, &g_destR);
    SDL_RenderPresent(m_renderer);
}

void Game::clean() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}