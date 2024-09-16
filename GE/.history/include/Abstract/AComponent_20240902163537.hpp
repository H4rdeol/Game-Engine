/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** AComponent.cpp
*/

#pragma once

#include "IComponent.hpp"

namespace ECS
{
    class AComponent : public IComponent {
        public:
            AComponent() = default;
            ~AComponent() = default;

            std::size_t AddToEntity(const EntityId entity, ...) override = 0;
            void RemoveFromEntity(const std::size_t index) override = 0;
    };
}
