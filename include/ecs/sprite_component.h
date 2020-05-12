#pragma once

#include "components.h"
#include <SDL.h>

class SpriteComponent : public Component
{
public:
  SpriteComponent() = default;

  SpriteComponent(const char* path) {
    m_texture = TextureManager::LoadTexture(path);
  }

  void init() override {
    m_position = &m_entity->getComponent<PositionComponent>();

    m_srcRect.x = 0;
    m_srcRect.y = 0;
    m_srcRect.h = 48;
    m_srcRect.w = 48;
    m_destRect.w = 64;
    m_destRect.h = 64;
  }

  void update() override {
    m_destRect.x = m_position->x() % 800;
    m_destRect.y = m_position->y() % 640;
  }

  void draw() override {
    TextureManager::draw(m_texture, m_srcRect, m_destRect);
  }

private:
  PositionComponent *m_position;
  SDL_Texture *m_texture;
  SDL_Rect m_srcRect, m_destRect;
};