#pragma once

#ifndef CHRUSEL_ECS_H
#define CHRUSEL_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentId = std::size_t;

inline ComponentId getComponentTypeId() {
  static ComponentId lastId = 0;
  return lastId++;
}

template <typename T> inline ComponentId getComponentTypeId() noexcept {
  static ComponentId typeId = getComponentTypeId();
  return typeId;
}

constexpr std::size_t maxComponents { 32 };

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
  Entity* m_entity;

  virtual void init() {}
  virtual void update() {}
  virtual void draw() {}

  virtual ~Component() {}
};

class Entity
{
private:
  bool m_active { true };
  std::vector<std::unique_ptr<Component>> m_components;

  ComponentArray m_componentArray;
  ComponentBitSet m_componentBitSet;

public:
  void update() {
    for (auto& c : m_components) c->update();
  }

  void draw() {
    for (auto& c : m_components) c->draw();
  }

  bool isActive() const {
    return m_active;
  }

  void destroy() {
    m_active = false;
  }

  template <typename T>
  bool hasComponent() const {
    return m_componentBitSet[getComponentTypeId<T>()];
  }

  template <typename T, typename... TArgs>
  T& addComponent(TArgs&&... mArgs)
  {
    T* c(new T(std::forward<TArgs>(mArgs)...));
    c->m_entity = this;
    std::unique_ptr<Component> uPtr{ c };
    m_components.emplace_back(std::move(uPtr));

    m_componentArray[getComponentTypeId<T>()] = c;
    m_componentBitSet[getComponentTypeId<T>()] = true;

    c->init();
    return *c;
  }

  template <typename T>
  T& getComponent() const {
    auto ptr(m_componentArray[getComponentTypeId<T>()]);
    return *static_cast<T*>(ptr);
  }
};

class Manager
{
private:
  std::vector<std::unique_ptr<Entity>> m_entities;

public:
  void update() {
    for (auto& e : m_entities) e->update();
  }

  void draw() {
    for (auto& e : m_entities) e->draw();
  }

  void refresh() {
    m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities), [] (const std::unique_ptr<Entity> &entity) {
      return !entity->isActive();
    }), std::end(m_entities));
  }

  Entity& addEntity() {
    Entity* e = new Entity();
    std::unique_ptr<Entity> uPtr{e};
    m_entities.emplace_back(std::move(uPtr));

    return *e;
  }
};

#endif  // #ifndef CHRUSEL_ECS_H