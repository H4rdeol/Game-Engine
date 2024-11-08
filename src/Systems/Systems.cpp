/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Systems.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "ComponentManager/Components.hpp"

#include <iostream>

namespace ECS {
    SystemsManager::SystemsManager()
    {
        _systems[(std::size_t)SystemType::POSITION] = nullptr;
        _systems[(std::size_t)SystemType::SPRITE] = std::make_unique<DrawSystem>();
    }

    void SystemsManager::Update(float deltaTime)
    {
        std::size_t i = 0;

        for (auto &system : _systems) {
            if (system)
                system->Update(deltaTime);
            i++;
        }
    }

    std::unique_ptr<ASystems> &SystemsManager::operator[](SystemsManager::SystemType type)
    {
        return _systems[(std::size_t)type];
    }

    void DrawSystem::Update(UNUSED float deltaTime)
    {
        for (auto &entity : _entities) {
            if (ECS::GetInstance().getComponentsMapper()->HasComponent<Components::SpriteComponents>(entity)) {
                auto &spriteComponent = dynamic_cast<Components::SpriteComponents&>(*(ECS::GetInstance().getComponentsMapper()->GetComponent<Components::SpriteComponents>(entity)));
                auto &positionComponent = dynamic_cast<Components::PositionsComponents&>(*(ECS::GetInstance().getComponentsMapper()->GetComponent<Components::PositionsComponents>(entity)));

                for (std::size_t i = 0; i < spriteComponent.m_sprite.size(); i++) {
                    spriteComponent.m_sprite[i].setPosition((float)positionComponent.m_positions[i].first, (float)positionComponent.m_positions[i].second);
                    ECS::GetInstance().App->getWindow().draw(spriteComponent.m_sprite[i]);
                }
            }
        }
    }
} // ECS
