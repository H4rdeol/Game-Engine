/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Systems.hpp"

namespace ECS {
    SystemsManager::SystemsManager()
    {
        _systems[(std::size_t)SystemType::POSITION] = nullptr;
        _systems[(std::size_t)SystemType::SPRITE] = std::make_unique<DrawSystem>();
    }

    void DrawSystem::Update(float deltaTime)
    {

    }
} // ECS