/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.hpp
*/

#pragma once

#include <cstdarg>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <glm/gtx/quaternion.hpp>

#include "AComponent.hpp"

namespace ECS::Components
{
    class PositionsComponents: public AComponent {
        public:
            PositionsComponents() = default;
            ~PositionsComponents() override = default;

            void AddToEntity(Entity &entity, va_list args, ...) override;
            void RemoveFromEntity(Entity &entity) override;
        public:
            std::vector<std::pair<double, double>> m_positions;
    };

    class SpriteComponents: public AComponent {
        public:
            SpriteComponents() = default;
            ~SpriteComponents() override = default;

            void AddToEntity(Entity &entity, va_list args, ...) override;
            void RemoveFromEntity(Entity &entity) override;
        public:
            std::vector<sf::VertexArray> m_vertexArray;
            std::vector<std::pair<sf::Texture, std::size_t>> m_texture;
        private:
            std::vector<std::pair<std::string, std::size_t>> _alreadyLoaded;
    };

    class TransformComponents: public AComponent {
        public:
            TransformComponents() = default;
            ~TransformComponents() override = default;

            void AddToEntity(Entity &entity, va_list args, ...) override;
            void RemoveFromEntity(Entity &entity) override;
        public:
            std::vector<glm::vec2> m_positions;
            std::vector<float> m_scales;
            std::vector<glm::quat> m_transforms;
    };

}
