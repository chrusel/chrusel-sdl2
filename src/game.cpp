#include "game.h"
#include "texture_manager.h"
#include "game_object.h"
#include "map.h"

#include <SDL2/SDL_image.h>
#include <iostream>

// temp global vars
GameObject* g_player;
GameObject* g_enemy;
Map* g_map;

SDL_Renderer *Game::s_renderer {nullptr};

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
        Game::s_renderer = SDL_CreateRenderer(m_window, -1 ,0);
        if (Game::s_renderer) {
            SDL_SetRenderDrawColor(Game::s_renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        m_isRunning = true;

        g_player = new GameObject("assets/player-frontal-48.png", 0, 0);
        g_enemy = new GameObject("assets/enemy-right-48.png", 40, 40);
        g_map = new Map();
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
    g_player->update();
    g_enemy->update();
}

void Game::render() {
    SDL_RenderClear(Game::s_renderer);

    g_map->drawMap();
    g_player->render();
    g_enemy->render();

    SDL_RenderPresent(Game::s_renderer);
}

void Game::clean() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(Game::s_renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
