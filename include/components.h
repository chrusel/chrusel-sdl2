#pragma once

#include "ecs.h"

class PositionComponent : public Component
{
public:
  int x() {
    return m_xpos;
  }

  int y() {
    return m_ypos;
  }

  void init() override {
    m_xpos = 0;
    m_ypos = 0;
  }

  void update() override {
    m_xpos++;
    m_ypos++;
  }

  void setPos(int x, int y) {
    m_xpos = x;
    m_ypos = y;
  }

private:
  int m_xpos;
  int m_ypos;
};