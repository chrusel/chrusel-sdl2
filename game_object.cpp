#include "game_object.h"
#include "texture_manager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y) {
  m_renderer = renderer;
  m_objTexure = TextureManager::LoadTexture(textureSheet, renderer);
  m_xpos = x;
  m_ypos = y;
}

GameObject::~GameObject() {

}

void GameObject::update() {
  m_xpos++;
  m_ypos++;

  m_srcRect.h = 48;
  m_srcRect.w = 48;
  m_srcRect.x = 0;
  m_srcRect.y = 0;

  m_destRect.x = m_xpos % 800;
  m_destRect.y = m_ypos % 600;
  m_destRect.w = m_srcRect.w * 2;
  m_destRect.h = m_srcRect.h * 2;
}

void GameObject::render() {
    SDL_RenderCopy(m_renderer, m_objTexure, &m_srcRect, &m_destRect);
}
