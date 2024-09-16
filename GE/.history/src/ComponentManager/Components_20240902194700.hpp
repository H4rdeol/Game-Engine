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

namespace ECS::C
{
    class PositionsComponents: public AComponent {
        public:
            PositionsComponents() = default;
            ~PositionsComponents() = default;

            void AddToEntity(const Entity entity, ...) override;
            void RemoveFromEntity(const std::size_t index) override;
        private:
            std::vector<std::pair<double, double>> m_positions;
    };

}
