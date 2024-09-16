/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.hpp
*/

#pragma once

#include <cstdarg>
#include <vector>

#include "AComponent.hpp"

namespace ECS::Components
{
    class PositionsComponents: public AComponent {
        public:
            PositionsComponents() = default;
            ~PositionsComponents() = default;

            void AddToEntity(Entity &entity, va_list args, ...) override;
            void RemoveFromEntity(const Entity &entity) override;
        private:
            std::vector<std::pair<double, double>> m_positions;
    };

}
