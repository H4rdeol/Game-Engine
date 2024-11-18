/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Systems.hpp"
#include "ComponentManager/ComponentManager.hpp"
#include "ComponentManager/Components.hpp"
#include "ECS/ECS.hpp"

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
                auto &spriteComponent = ECS::GetInstance().getComponentsMapper()->GetComponent<Components::SpriteComponents>();
                auto &positionComponent = ECS::GetInstance().getComponentsMapper()->GetComponent<Components::PositionsComponents>();

                for (auto &[entityId, texture] : spriteComponent.m_texture) {
                    auto &vertexArray = spriteComponent.m_vertexArray[texture];
                    auto &texturePair = spriteComponent.m_texture[texture];
                    auto &position = positionComponent.m_positions[positionComponent.IdToIndex_p[entity.id]];

                    vertexArray[0].position = sf::Vector2f(position.first, position.second);
                    vertexArray[1].position = sf::Vector2f(position.first + texturePair.first.getSize().x, position.second);
                    vertexArray[2].position = sf::Vector2f(position.first + texturePair.first.getSize().x, position.second + texturePair.first.getSize().y);
                    vertexArray[3].position = sf::Vector2f(position.first, position.second + texturePair.first.getSize().y);

                    vertexArray[0].texCoords = sf::Vector2f(0, 0);
                    vertexArray[1].texCoords = sf::Vector2f(texturePair.first.getSize().x, 0);
                    vertexArray[2].texCoords = sf::Vector2f(texturePair.first.getSize().x, texturePair.first.getSize().y);
                    vertexArray[3].texCoords = sf::Vector2f(0, texturePair.first.getSize().y);
                }
                ECS::GetInstance().App->getWindow().draw(spriteComponent.m_vertexArray[0], &spriteComponent.m_texture[0].first);
            }
        }
    }
} // ECS
