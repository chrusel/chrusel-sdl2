#include "game.h"
#include <iostream>

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
            SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        m_isRunning = true;
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

}

void Game::render() {
    SDL_RenderClear(m_renderer);
    // this is where we would add stuff to render
    SDL_RenderPresent(m_renderer);
}

void Game::clean() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}