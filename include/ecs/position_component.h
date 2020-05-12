#pragma once

#include "components.h"

class PositionComponent : public Component
{
public:
  PositionComponent() {
    m_xpos = 0;
    m_ypos = 0;
  }

  PositionComponent(int x, int y) {
    m_xpos = x;
    m_ypos = y;
  }

  void update() override {
    m_xpos++;
    m_ypos++;
  }

  void setPos(int x, int y) {
    m_xpos = x;
    m_ypos = y;
  }

  int x() {
    return m_xpos;
  }

  int y() {
    return m_ypos;
  }

private:
  int m_xpos;
  int m_ypos;
};
